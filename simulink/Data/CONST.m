function CONST(n,v)
    evalin('base',strcat(n,' = Simulink.Parameter(',v, ');'));
    evalin('base',strcat(n,'.StorageClass = ''Define'';'));
    % n = Simulink.Parameter(v);
    % n.StorageClass = 'Define';
end