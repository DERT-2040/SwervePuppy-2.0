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
% --- --- --- --- --- --- --- --Build Code-- --- --- --- --- --- --- --- --
% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

generate_controller_code;


% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
% --- --- --- --- --- -- Scan Model For Names -- --- --- --- --- --- --- --
% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
% Created by Janelyn Anderson (student) without any help
% December 2023

mdl = 'Code_Gen_Model';
load_system(mdl);

Top_Level_Blocks = find_system(mdl, 'FindAll', 'on', 'LookInsideSubsystemReference', 'off', 'Type','Block');
% TF = get(Top_Level_Blocks, 'Port');
% Port_Blocks = Top_Level_Blocks(logical(cell2mat(TF)));
% ListOfPorts = get(Port_Blocks,'Name');
ListOfInPorts = {};
ListOfOutPorts = {};
for i = (1:size(Top_Level_Blocks, 1))
    try
        get_param(Top_Level_Blocks(i), 'Port');
        str = strsplit(get_param(Top_Level_Blocks(i), "Name"));
        if strcmp(get(Top_Level_Blocks(i), 'BlockType'),'Inport')
           ListOfInPorts = [ListOfInPorts; string(str(1))];
        else
           ListOfOutPorts = [ListOfOutPorts; string(str(1))];
        end
    catch
        continue;
    end
end


ProjectRoot = currentProject().RootFolder;
C_File = fileread(append(ProjectRoot,'/../src/main/Code_Gen_Model_ert_rtw/Code_Gen_Model.h'));
C_File_Split = split(C_File, newline);
C_File_Trimmed = cellfun(@strtrim, C_File_Split, 'UniformOutput',false);
TF = contains(C_File_Trimmed, '/* Block signals (default storage) */');
TF_Indexes = find(TF);
try
    for i = 1 : TF_Indexes
        if strcmp(C_File_Trimmed(1 + TF_Indexes(i)),'typedef struct {');
            StartIndex = 2 + TF_Indexes(i);
            break;
        end
    end
    EndIndex = find(contains(C_File_Trimmed, '} B_Code_Gen_Model_T;')) - 1;
    Variable_Lines = C_File_Trimmed(StartIndex:EndIndex);
    Split_Variable_Lines = cellfun(@strsplit, Variable_Lines, 'UniformOutput',false);
    ListOfTestPoints_w_semicolen = cellfun(@(a) a(1,2), Split_Variable_Lines);
    ListOfTestPoints = cell(length(ListOfTestPoints_w_semicolen), 1);
    for i = 1:length(ListOfTestPoints_w_semicolen)
        str = ListOfTestPoints_w_semicolen{i};
        indices_of_Semicolens = strfind(str, ';');
        ListOfTestPoints{i} = str(1:indices_of_Semicolens(1)-1);
    end

    for i = 1:length(ListOfTestPoints)
        if contains(ListOfTestPoints{i}, '[')
            ListOfTestPoints{i} = [];
        end
    end
    ListOfTestPoints = ListOfTestPoints(~cellfun('isempty', ListOfTestPoints));

catch
    ListOfTestPoints = cell(0,0);
end

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
    HFileContents{end + 1} = '        // Inports';

    for i = 1:length(ListOfInPorts)
        HFileContents{end + 1} = append('        nt::NetworkTableEntry __', ListOfInPorts{i} ,'__Entry;');
    end
    HFileContents{end + 1} = '        // Outports';
    for i = 1:length(ListOfOutPorts)
        HFileContents{end + 1} = append('        nt::NetworkTableEntry __', ListOfOutPorts{i} ,'__Entry;');
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
    '    auto NTtable_Tune = NTinst.GetTable("Simulink Tunable Params");',...
    '    auto NTtable_Inport = NTinst.GetTable("Simulink Top Level Ports");',...
    '    auto NTtable_Outport = NTinst.GetTable("Simulink Top Level Ports");',...
    '    auto NTtable_TPoint = NTinst.GetTable("Simulink Test Points");'...
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
CPPFileContents{end + 1} = ' ';
CPPFileContents{end + 1} = '// Inports';
% Inports
for i = 1:length(ListOfInPorts)
    CPPFileContents{end + 1} = append('    __', string(ListOfInPorts(i)), '__Entry = NTtable_Inport->GetEntry("', string(ListOfInPorts(i)),'");');
end
% Outports
CPPFileContents{end + 1} = ' ';
CPPFileContents{end + 1} = '// Outports';
for i = 1:length(ListOfOutPorts)
    CPPFileContents{end + 1} = append('    __', string(ListOfOutPorts(i)), '__Entry = NTtable_Outport->GetEntry("', string(ListOfOutPorts(i)),'");');
end
% Test Points
CPPFileContents{end + 1} = ' ';
CPPFileContents{end + 1} = '// Test Points';
for i = 1:length(ListOfTestPoints)
    CPPFileContents{end + 1} = append('    __', string(ListOfTestPoints(i)), '__Entry = NTtable_TPoint->GetEntry("', string(ListOfTestPoints(i)),'");');
end




CPPFileContents{end + 1} = '}';
CPPFileContents{end + 1} = ' ';
CPPFileContents{end + 1} = 'void SimulinkSmartDashboardInterface::SmartDashboardCallback() {';
CPPFileContents{end + 1} = '    // Inports';
for i = 1:length(ListOfInPorts)
    CPPFileContents{end + 1} = append('    __', string(ListOfInPorts(i)), '__Entry.SetDouble(Code_Gen_Model_U.', string(ListOfInPorts(i)), ');');
end
CPPFileContents{end + 1} = '    // Outports';
for i = 1:length(ListOfOutPorts)
    CPPFileContents{end + 1} = append('    __', string(ListOfOutPorts(i)), '__Entry.SetDouble(Code_Gen_Model_Y.', string(ListOfOutPorts(i)), ');');
end

CPPFileContents{end + 1} = '    // Test Points';
for i = 1:length(ListOfTestPoints)
    CPPFileContents{end + 1} = append('    __', string(ListOfTestPoints(i)), '__Entry.SetDouble(Code_Gen_Model_B.', string(ListOfTestPoints(i)), ');');
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
disp('------- Build Done -------');