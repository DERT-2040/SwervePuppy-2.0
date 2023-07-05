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



%% Drive motor controller
Drive_Motor_Control_FF= 1/5500;  % 1 DC / Max Speed RPM;

Drive_Motor_Control_P = 0.0001;

Drive_Motor_Control_I = 0.00002;
Drive_Motor_Control_I_UL = 0.1;
Drive_Motor_Control_I_LL = -Drive_Motor_Control_I_UL;

Drive_Motor_Control_D = 0.00001/t_sample;
Derivative_low_pass_filter_freq = 2; % Hz
Drive_Motor_Control_D_FilterCoeff = 1-exp(-2*pi*Derivative_low_pass_filter_freq*t_sample);
Drive_Motor_Control_D_UL = 0.2;
Drive_Motor_Control_D_LL = -Drive_Motor_Control_D_UL;



%% Steering motor controller
Steering_Motor_Control_P = 0.15;

Steering_Motor_Control_I = 0.005;
Steering_Motor_Control_I_UL = 0.005;
Steering_Motor_Control_I_LL = -Steering_Motor_Control_I_UL;

Steering_Motor_Control_D = 0.01/t_sample;
Derivative_low_pass_filter_freq = 2; % Hz
Steering_Motor_Control_D_FilterCoeff = 1-exp(-2*pi*Derivative_low_pass_filter_freq*t_sample);
Steering_Motor_Control_D_UL = 0.2;
Steering_Motor_Control_D_LL = -Drive_Motor_Control_D_UL;


%% Occupency Map
Occupency_Matrix = LoadBinaryPNG('TestMap1.png');