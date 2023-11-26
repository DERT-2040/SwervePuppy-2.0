clear
evalin('base', 'Code_Gen_Model_data');





T = whos;
Names = {T.name};
DataTypes = {T.class};
Values = cellfun(@eval, Names, 'UniformOutput',false);
overrideNames = ['t_sample'];
for i = 1:length(Names)
    temp_name = Names{i};
    temp_value = Values{i};
    temp_datatypes = DataTypes{i};

    if not(evalin('base',strcat('isa(', string(temp_name), ', ''numeric'')')) )
        continue
    elseif not(evalin('base', strcat('all(size(',string(temp_name),') == 1)')))
        continue
    elseif ismember(temp_name, overrideNames)
        continue
    end
    
    evalin('base',strcat(string(temp_name),' = Simulink.Parameter;'));
    evalin('base',strcat(string(temp_name),'.Value = ',string(temp_value),';'));
    evalin('base',strcat(string(temp_name),'.DataType = ''',string(temp_datatypes),''';'));
    evalin('base',strcat(string(temp_name),'.CoderInfo.StorageClass = ''ExportedGlobal'';'));


end


% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
% --- --- --- --- --- --- --Write to file-- --- --- --- --- --- --- --- ---
% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX


CPPFileID = fopen('..\src\main\cpp\SimulinkSmartDashboard.cpp', 'w');
HFileID = fopen('..\src\main\include\SimulinkSmartDashboard.h', 'w');
if CPPFileID == -1
    error('Could not open .cpp file for writing');
end
if HFileID == -1
    error('Could not open .h file for writing');
end


% H File
HFileContents = {...
    '#include <frc/smartdashboard/SmartDashboard.h>',...
    '#include <networktables/NetworkTable.h>',...
    '#include <networktables/RawTopic.h>',...
    '#include <networktables/NetworkTableInstance.h>',...
    '#include "Code_Gen_Model_ert_rtw\Code_Gen_Model.h"',...
    ' ',...
    'class SimulinkSmartDashboard {',...
    '    public:',...
    '        void InitTunableSmartDashboard();',...
    '    private:',...
    };
    for i = 1:length(Names)
        if not(evalin('base',strcat('strcmp(class(', string(Names{i}), '), ''Simulink.Parameter'')')) )
            continue
        end
        HFileContents{end + 1} = append('        nt::NetworkTableEntry __', Names{i} ,'__Entry;');
    end
    HFileContents{end + 1} = '};';

CPPFileContents = {...
    '#include "include/SimulinkSmartDashboard.h"',...
    ' ',...
    'void SimulinkSmartDashboard::InitTunableSmartDashboard() {',...
    '    nt::NetworkTableInstance NTinst = nt::NetworkTableInstance::GetDefault();',...
    '    auto NTtable = NTinst.GetTable("Simulink_Tunable_Params");',...
    };
for i = 1:length(Names)
    if not(evalin('base',strcat('strcmp(class(', string(Names{i}), '), ''Simulink.Parameter'')')) )
        continue
    end
    CPPFileContents{end + 1} = ' ';
    CPPFileContents{end + 1} = append('    __', Names{i}, '__Entry = NTtable->GetEntry("', Names{i}, '");');
    CPPFileContents{end + 1} = append('    NTinst.AddListener(__', Names{i} ,'__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {', Names{i}, ' = event.GetValueEventData()->value.GetDouble();});');
    CPPFileContents{end + 1} = append('    __', Names{i}, '__Entry.SetDouble(', string(Values{i}), ');');
end
CPPFileContents{end + 1} = '}';

% make file contents 
for i = 1:length(CPPFileContents)
    fprintf(CPPFileID, '%s\n', CPPFileContents{i});
end

for i = 1:length(HFileContents)
    fprintf(HFileID, '%s\n', HFileContents{i});
end
% Close the file
fclose(CPPFileID);
fclose(HFileID);
clear Names DataTypes Values temp_datatypes temp_name temp_value T overrideNames i CPPFileID HFileID CPPFileContents HFileContents ans

% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
% --- --- --- --- --- --- --- --Build Code-- --- --- --- --- --- --- --- --
% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

generate_controller_code;