% Find all in and out port names for top level model
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

clear str ListOfPorts i ListOfPorts mdl All_Lines TF ListOfTestPoints TestLines
