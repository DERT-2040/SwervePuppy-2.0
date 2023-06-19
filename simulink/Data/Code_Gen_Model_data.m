% sample time model
t_sample = .02;


% modulation curve 
temp_x = [0.1 0.2  0.3 0.4 0.5  0.6  0.7  0.8 0.9  1.0];
temp_y = [0.0 0.04 0.1 0.2 0.31 0.43 0.55 0.7 0.85 1.0];
% figure(1), clf, plot(temp_x,temp_y,'-o'), grid on
% figure(2), clf, plot([-fliplr(temp_x) 0 temp_x],[-fliplr(temp_y) 0 temp_y],'-o'), grid on

Steering_Mod_Drv_in = [-fliplr(temp_x) 0 temp_x];
Steering_Mod_Drv_out = [-fliplr(temp_y) 0 temp_y];

Steering_Mod_Str_Abs_in = [-fliplr(temp_x) 0 temp_x];
Steering_Mod_Str_Abs_out = [-fliplr(temp_y) 0 temp_y];

Steering_Mod_Str_Rel_in = [-fliplr(temp_x) 0 temp_x];
Steering_Mod_Str_Rel_out = [-fliplr(temp_y) 0 temp_y];

Steering_PID_prop = 1;
Steering_PID_int = 0.02;
Steering_PID_der = 0.0025;

RIO_Offset = pi/2;

translation_Acceleration = 0.9;