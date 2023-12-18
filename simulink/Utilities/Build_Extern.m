% Created by Janelyn Anderson (student) with help from Randy Anderson (mentor)
% November 2023

% clear workspace and load data needed for code generation
clear
evalin('base', 'Code_Gen_Model_data');

% Create a structure 'T' with contents from the workspace
T = whos;

% Create lists of the names, dataypes, and values from the workspace data
Names = {T.name};
DataTypes = {T.class};
Values = cellfun(@eval, Names, 'UniformOutput',false);

% Create Simulink.Parameter structures for:
%    numeric data types
%       does not work for logical/boolean data types (make these double in Simulink)
%       type 'doc isa' at the workspace to see a list of numeric data types
%    scalars (not vectors or matrices)
%    parameters not in the 'Not_Tunable_List' list (created in 'Code_Gen_Model_data')
% Set the storage class to ExportedGlobal to make them tunable
for i = 1:length(Names)
    temp_name = Names{i};
    temp_value = Values{i};
    temp_datatypes = DataTypes{i};

    if not(evalin('base',strcat('isa(', string(temp_name), ', ''numeric'')')) )
        continue
    elseif not(evalin('base', strcat('all(size(',string(temp_name),') == 1)')))
        continue
    elseif ismember(temp_name, Not_Tunable_List)
        continue
    end
    
    evalin('base',strcat(string(temp_name),' = Simulink.Parameter;'));
    evalin('base',strcat(string(temp_name),'.Value = ',string(temp_value),';'));
    evalin('base',strcat(string(temp_name),'.DataType = ''',string(temp_datatypes),''';'));
    evalin('base',strcat(string(temp_name),'.CoderInfo.StorageClass = ''ExportedGlobal'';'));
end

% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
% --- --- --- --- --- -- Scan Model For Names -- --- --- --- --- --- --- --
% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
% Created by Janelyn Anderson (student) without any help
% December 2023

mdl = 'Code_Gen_Model';
load_system(mdl);

Top_Level_Blocks = find_system(mdl, 'FindAll', 'on', 'LookInsideSubsystemReference', 'off', 'Type','Block');
ListOfPorts = {};
for i = (1:size(Top_Level_Blocks, 1))
    try
        get_param(ListOfPorts(i), 'Port');
        str = strsplit(get_param(ListOfPorts(i), "Name"));
        ListOfPorts = [ListOfPorts; string(str(1))];
    catch
        continue;
    end
end

All_Lines = find_system(mdl, 'FindAll', 'on', 'FollowLinks', 'on', 'LookInsideSubsystemReference', 'on', 'LookUnderMasks', 'all', 'Type', 'line');

TF = get(All_Lines, 'TestPoint');
TestLines=All_Lines(logical(cell2mat(TF)));
ListOfTestPoints = get(TestLines,'Name');

% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
% --- --- --- --- --- --- --Write to file-- --- --- --- --- --- --- --- ---
% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
% Created by Janelyn Anderson (student) without any help
% November 2023

% Janelyn Anderson
% Edited December 2023 to make code that displays all model ports in
% Network Tables as well as all test points

CPPFileID = fopen('..\src\main\cpp\SimulinkSmartDashboardInterface.cpp', 'w');
HFileID = fopen('..\src\main\include\SimulinkSmartDashboardInterface.h', 'w');
if CPPFileID == -1
    error('Could not open .cpp file for writing');
end
if HFileID == -1
    error('Could not open .h file for writing');
end

% H File
HFileContents = {...
    '// This file has been auto generated from a Matlab script',...
    '// Do not manually edit since changes will be lost',...
    '#include <frc/smartdashboard/SmartDashboard.h>',...
    '#include <networktables/NetworkTable.h>',...
    '#include <networktables/RawTopic.h>',...
    '#include <networktables/NetworkTableInstance.h>',...
    '#include "Code_Gen_Model_ert_rtw\Code_Gen_Model.h"',...
    ' ',...
    'class SimulinkSmartDashboardInterface {',...
    '    public:',...
    '        void InitSmartDashboardInterface();',...
    '        void SmartDashboardCallback();',...
    '    private:',...
    };
% Parameters
    HFileContents{end + 1} = '        // Parameters';
    for i = 1:length(Names)
        if not(evalin('base',strcat('strcmp(class(', string(Names{i}), '), ''Simulink.Parameter'')')) )
            continue
        end
        HFileContents{end + 1} = append('        nt::NetworkTableEntry __', Names{i} ,'__Entry;');
    end
% Top Level Ports
    HFileContents{end + 1} = ' ';
    HFileContents{end + 1} = '        // Top Level Ports';
    for i = 1:length(ListOfPorts)
        HFileContents{end + 1} = append('        nt::NetworkTableEntry __', ListOfPorts{i} ,'__Entry;');
    end
% Test Points
    HFileContents{end + 1} = ' ';
    HFileContents{end + 1} = '        // Test Points';
    for i = 1:length(ListOfTestPoints)
        HFileContents{end + 1} = append('        nt::NetworkTableEntry __', ListOfTestPoints{i} ,'__Entry;');
    end

    HFileContents{end + 1} = '};';
% CPP File
CPPFileContents = {...
    '// This file has been auto generated from a Matlab script',...
    '// Do not manually edit since changes will be lost',...
    '#include "include/SimulinkSmartDashboardInterface.h"',...
    ' ',...
    'void SimulinkSmartDashboardInterface::InitSmartDashboardInterface() {',...
    '    nt::NetworkTableInstance NTinst = nt::NetworkTableInstance::GetDefault();',...
    '    auto NTtable_Tune = NTinst.GetTable("Simulink_Tunable_Params");',...
    '    auto NTtable_Port = NTinst.GetTable("Simulink_Top_Level_Ports");',...
    '    auto NTtable_TPoint = NTinst.GetTable("Simulink_Test_Points");'...
    };
% Parameters
for i = 1:length(Names)
    if not(evalin('base',strcat('strcmp(class(', string(Names{i}), '), ''Simulink.Parameter'')')) )
        continue
    end
    CPPFileContents{end + 1} = ' ';
    CPPFileContents{end + 1} = append('    __', Names{i}, '__Entry = NTtable_Tune->GetEntry("', Names{i}, '");');
    CPPFileContents{end + 1} = append('    NTinst.AddListener(__', Names{i} ,'__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {', Names{i}, ' = event.GetValueEventData()->value.GetDouble();});');
    CPPFileContents{end + 1} = append('    __', Names{i}, '__Entry.SetDouble(', string(Values{i}), ');');
end
for i = 1:length(ListOfPorts)
    CPPFileContents{end + 1} = append('    __', string(ListOfPorts(i)), '__Entry = NTtable_Port->GetEntry("', string(ListOfPorts(i)),'");');
end

CPPFileContents{end + 1} = '}';
CPPFileContents{end + 1} = ' ';
CPPFileContents{end + 1} = 'void SimulinkSmartDashboardInterface::SmartDashboardCallback() {';
CPPFileContents{end + 1} = '    // Ports';
for i = 1:length(ListOfPorts)
    CPPFileContents{end + 1} = append('    __', string(ListOfPorts(i)), '__Entry.SetDouble(', string(ListOfPorts(i)), ');');
end
CPPFileContents{end + 1} = '    // Test Points';
for i = 1:length(ListOfTestPoints)
    CPPFileContents{end + 1} = append('    __', string(ListOfTestPoints(i)), '__Entry.SetDouble(', string(ListOfTestPoints(i)), ');');
end

CPPFileContents{end + 1} = '}';

    % make file contents 
for i = 1:length(CPPFileContents)
    fprintf(CPPFileID, '%s\n', CPPFileContents{i});
end

for i = 1:length(HFileContents)
    fprintf(HFileID, '%s\n', HFileContents{i});
end

% Close the files
fclose(CPPFileID);
fclose(HFileID);

clear Names DataTypes Values temp_datatypes temp_name temp_value T...
    Not_Tunable_List i CPPFileID HFileID CPPFileContents HFileContents...
    ans

% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
% --- --- --- --- --- --- --- --Build Code-- --- --- --- --- --- --- --- --
% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

generate_controller_code;