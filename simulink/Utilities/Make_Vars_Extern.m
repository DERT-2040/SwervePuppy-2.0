T = whos;
Names = {T.name};
DataTypes = {T.class};
Values = cellfun(@eval, Names, 'UniformOutput',false);
overrideNames = ['t_sample','fillertext'];
for i = 1:length(Names)
    temp_name = Names{i};
    temp_value = Values{i};
    temp_datatypes = DataTypes{i};

    if or(ismember(temp_name, overrideNames), not(any(evalin('base',strcat('isa(', string(temp_name), ', ''numeric'')')),...
                                                      evalin('base',strcat('isa(', string(temp_name), ', ''logical'')')),...
                                                      evalin('base',strcat('isa(', string(temp_name), ', ''string'') ')) )) )
        continue
    end
    
    evalin('base',strcat(string(temp_name),' = Simulink.Parameter;'));
    evalin('base',strcat(string(temp_name),'.Value = ',mat2str(temp_value),';'));
    evalin('base',strcat(string(temp_name),'.DataType = ''',string(temp_datatypes),''';'));
    evalin('base',strcat(string(temp_name),'.CoderInfo.StorageClass = ''ExportedGlobal'';'));


end
clear Names DataTypes Values temp_datatypes temp_name temp_value T overrideNames i