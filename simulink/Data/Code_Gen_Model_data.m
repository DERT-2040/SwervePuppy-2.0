% sample time model
t_sample = .02;


%% Joystick Command Profiling

% Absolute Steering Circular Deadband
Steering_Abs_Deadband_Range = 0.7;

% modulation curve 
temp_x = [0.2 0.25  0.3 0.4 0.5  0.6  0.7  0.8 0.9  1.0];
temp_y = [0.0 0.01 0.04 0.10 0.17 0.27 0.40 0.55 0.75 1.0];
% figure(1), clf, plot(temp_x,temp_y,'-o'), grid on
% figure(2), clf, plot([-fliplr(temp_x) 0 temp_x],[-fliplr(temp_y) 0 temp_y],'-o'), grid on

Steering_Mod_Drv_in = [-fliplr(temp_x) 0 temp_x];
Steering_Mod_Drv_out = [-fliplr(temp_y) 0 temp_y];

temp_x = [0.2 0.25  0.3 0.4 0.5  0.6  0.7  0.8 0.9  1.0];
temp_y = [0.0 0.01 0.04 0.10 0.17 0.27 0.40 0.55 0.75 1.0];
% figure(1), clf, plot(temp_x,temp_y,'-o'), grid on
% figure(2), clf, plot([-fliplr(temp_x) 0 temp_x],[-fliplr(temp_y) 0 temp_y],'-o'), grid on

Steering_Mod_Str_Rel_in = [-fliplr(temp_x) 0 temp_x];
Steering_Mod_Str_Rel_out = [-fliplr(temp_y) 0 temp_y];

Steering_Relative_Gain = 0.75;

Translation_Limit_Acceleration = 0.9;
Translation_Limit_Deceleration = -1000;

%% Wheel Gear Ratio
gear_ratio = 8.14;
wheel_diameter = 0.101600203;
Wheel_Speed_to_Motor_Speed = 60*gear_ratio/(wheel_diameter*pi);
clear gear_ratio wheel_diameter

%% Drive Motor PID
Drive_Motor_Control_FF= 1/5500;  % 1 DC / Max Speed RPM;
Drive_Motor_Control_P = 0.000005;

Drive_Motor_Control_I = 0.0000002;

Drive_Motor_Control_I_UL = 0.1;
Drive_Motor_Control_I_LL = -Drive_Motor_Control_I_UL;

Drive_Motor_Control_D = 0.000002/t_sample;

Derivative_low_pass_filter_freq = 2; % Hz
Drive_Motor_Control_D_FilterCoeff = 1-exp(-2*pi*Derivative_low_pass_filter_freq*t_sample);
Drive_Motor_Control_D_UL = 0.2;
Drive_Motor_Control_D_LL = -Drive_Motor_Control_D_UL;


%% Steering Motor PID
Steering_Motor_Control_P = 0.15;

Steering_Motor_Control_I = 0.005;
Steering_Motor_Control_I_UL = 0.005;
Steering_Motor_Control_I_LL = -Steering_Motor_Control_I_UL;

Steering_Motor_Control_D = 0.01/t_sample;
Derivative_low_pass_filter_freq = 2; % Hz
Steering_Motor_Control_D_FilterCoeff = 1-exp(-2*pi*Derivative_low_pass_filter_freq*t_sample);
Steering_Motor_Control_D_UL = 0.2;
Steering_Motor_Control_D_LL = -Drive_Motor_Control_D_UL;


%% Steering Heading PID
% Steering_Heading_Control_P = 0.75;
EXTERN('Steering_Heading_Control_P', 'double', '0.75');

% Steering_Heading_Control_I = 0.0009;
EXTERN('Steering_Heading_Control_I', 'double', '0.0009');
% Steering_Heading_Control_I_UL = 0.08;
EXTERN('Steering_Heading_Control_I_UL', 'double', '0.08');
Steering_Heading_Control_I_LL = -Steering_Heading_Control_I_UL;

% Steering_Heading_Control_D = 0.02/t_sample;
EXTERN('Steering_Heading_Control_D', 'double', '0.02/0.02');
Derivative_low_pass_filter_freq = 2; % Hz
Steering_Heading_Control_D_FilterCoeff = 1-exp(-2*pi*Derivative_low_pass_filter_freq*t_sample);
% Steering_Heading_Control_D_UL = 1000;
EXTERN('Steering_Heading_Control_D_UL', 'double', '1000');
Steering_Heading_Control_D_LL = -Steering_Heading_Control_D_UL;

% Steering_Heading_Control_Total_UL = 1;  % m/sec
EXTERN('Steering_Heading_Control_Total_UL', 'double', '1');
Steering_Heading_Control_Total_LL = -Steering_Heading_Control_Total_UL;

% Steering_Heading_Control_Deadzone_Pos = 0.01;
EXTERN('Steering_Heading_Control_Deadzone_Pos', 'double', '0.01');
Steering_Heading_Control_Deadzone_Neg = -Steering_Heading_Control_Deadzone_Pos;

%% Translation Speed Rate Limit
Translation_Speed_Rate_Limit_Inc = 1;
Translation_Speed_Rate_Limit_Dec = -1/0.50*0.02;
Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
Translation_Speed_NonZero_Error_Thresh = 0.2;
Translation_Speed_NonZero_Final_Scale_Factor = 0.1;

%% Steering Localized Cmd Rate Limit
Steering_Localized_Cmd_Rate_Limit_Inc = 1/0.25*0.02*0+1;
Steering_Localized_Cmd_Rate_Limit_Dec = -1/0.25*0.02*0-1;
Steering_Localized_Cmd_Approach_Zero_Error_Thresh = 0.2;
Steering_Localized_Cmd_Approach_Zero_Final_Thresh = 0.01;
Steering_Localized_Cmd_NonZero_Error_Thresh = 0.2;
Steering_Localized_Cmd_NonZero_Final_Scale_Factor = 0.1;

%% Occupency Map
Occupency_Matrix = LoadBinaryPNG('TestMap1.png');