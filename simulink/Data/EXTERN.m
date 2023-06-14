function EXTERN(n, d, v)
    evalin('base',strcat(n,' = Simulink.Parameter(',v, ');'));
    evalin('base',strcat(n,'.StorageClass = ''ExportedGlobal'';'));
    evalin('base',strcat(n,'.DataType = ''',d,''';'));
    % n = Simulink.Parameter(v);
    % n.StorageClass = 'Define';
end