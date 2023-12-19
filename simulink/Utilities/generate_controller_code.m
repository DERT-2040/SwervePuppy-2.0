function generate_controller_code()
% generate_controller_code

controllerModel = 'Code_Gen_Model';

if(~bdIsLoaded(controllerModel))
    open_system(controllerModel);
end

% generate code, but do not build
slbuild(controllerModel,'GenerateCodeOnly',true);

% coder.report.generate(controllerModel);

end