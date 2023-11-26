% Created by Janelyn Anderson (student) without any help
% November 2023

% clear workspace and load data needed for code generation
clear
evalin('base', 'Code_Gen_Model_data');

% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
% --- --- --- --- --- --- --Write to file-- --- --- --- --- --- --- --- ---
% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
% Created by Janelyn Anderson (student) without any help
% November 2023

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
    '// This file has been auto generated from a Matlab script',...
    '// Do not manually edit since changes will be lost',...
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
    '};'
    };

% CPP File
CPPFileContents = {...
    '// This file has been auto generated from a Matlab script',...
    '// Do not manually edit since changes will be lost',...
    '#include "include/SimulinkSmartDashboard.h"',...
    ' ',...
    'void SimulinkSmartDashboard::InitTunableSmartDashboard() {}',...
    };

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

clear HFileID HFileContents CPPFileID CPPFileContents

% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
% --- --- --- --- --- --- --- --Build Code-- --- --- --- --- --- --- --- --
% XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

generate_controller_code;