% sample time model
t_sample = .02;


%% Joystick Command Profiling

% Absolute Steering Circular Deadband
Steering_Abs_Deadband_Range = 0.7;

% modulation curve 
temp_x = [0.3 0.35  0.4 0.45 0.5  0.6  0.7  0.8 0.9  1.0];
temp_y = [0.0 0.01 0.04 0.06 0.09 0.14 0.18 0.31 0.58 1.0];
%figure(1), clf, plot(temp_x,temp_y,'-o'), grid on
% figure(2), clf, plot([-fliplr(temp_x) 0 temp_x],[-fliplr(temp_y) 0 temp_y],'-o'), grid on

Steering_Mod_Drv_in = [-fliplr(temp_x) 0 temp_x];
Steering_Mod_Drv_out = [-fliplr(temp_y) 0 temp_y];

temp_x = [0.2 0.25  0.3 0.4 0.5  0.6  0.7  0.8 0.9  1.0];
temp_y = [0.0 0.01 0.04 0.10 0.17 0.27 0.40 0.55 0.75 1.0];
% figure(1), clf, plot(temp_x,temp_y,'-o'), grid on
% figure(2), clf, plot([-fliplr(temp_x) 0 temp_x],[-fliplr(temp_y) 0 temp_y],'-o'), grid on

Steering_Mod_Str_Rel_in = [-fliplr(temp_x) 0 temp_x];
Steering_Mod_Str_Rel_out = [-fliplr(temp_y) 0 temp_y];

clear temp_x temp_y

Steering_Relative_Gain = 1.3;

Boost_Trigger_High_Speed = 3.658; % m/s
Boost_Trigger_Low_Speed = 1.5; % m/s

Boost_Trigger_Increasing_Limit = 2/1*0.02;
% EXTERN('Boost_Trigger_Increasing_Limit', 'double', '2/1*0.02');
Boost_Trigger_Decreasing_Limit = -2/0.9*0.02;
% EXTERN('Boost_Trigger_Decreasing_Limit', 'double', '-2/0.9*0.02');

%% Wheel Gear Ratio
gear_ratio = 8.14;
wheel_diameter = 0.101600203;
Wheel_Speed_to_Motor_Speed = 60*gear_ratio/(wheel_diameter*pi);

Motor_Rev_to_Wheel_Distance = wheel_diameter*pi/gear_ratio;

clear gear_ratio wheel_diameter

%% Wheel Locations from Center of Rotation
% distances between swerve modules
FrontBack = 0.37465;
LeftRight = 0.37465;

% swerve module distances from center to x and y coordinates
% Front Left
Distance_FL_x = FrontBack/2;
Distance_FL_y = LeftRight/2;

% Front Right
Distance_FR_x = FrontBack/2;
Distance_FR_y = -LeftRight/2;

% Back Left
Distance_BL_x = -FrontBack/2;
Distance_BL_y = LeftRight/2;

% Back Right
Distance_BR_x = -FrontBack/2;
Distance_BR_y = -LeftRight/2;

clear FrontBack LeftRight

%% Odometry rotation matrix
% robot rotation matrix to obtain: 
%   Vx and Vy for each module from the robot center Vx, Vy, and Omega
%   Dx and Dy for each module from the robot center Dx, Dy, and Theta
Rotation_Local =  [1 0 -Distance_FL_y;
                   0 1  Distance_FL_x;
                   1 0 -Distance_FR_y;
                   0 1  Distance_FR_x;
                   1 0 -Distance_BL_y;
                   0 1  Distance_BL_x;
                   1 0 -Distance_BR_y;
                   0 1  Distance_BR_x];

% pseudo inverse of the rotation matrix
temp = pinv(Rotation_Local);

% only keep first two rows since we don't need to estimate Theta
Rotation_Local_Inv = temp(1:2,:);

clear temp

%% Drive Motor PID
Drive_Motor_Control_FF= 1/5500;  % 1 DC / Max Speed RPM;
Drive_Motor_Control_P = 0.000005;

Drive_Motor_Control_I = 0.0000002*0;

Drive_Motor_Control_I_UL = 0; % 0.1
Drive_Motor_Control_I_LL = -Drive_Motor_Control_I_UL;

Drive_Motor_Control_D = 0.000002/t_sample;

Derivative_low_pass_filter_freq = 2; % Hz
Drive_Motor_Control_D_FilterCoeff = 1-exp(-2*pi*Derivative_low_pass_filter_freq*t_sample);
Drive_Motor_Control_D_UL = 0.2;
Drive_Motor_Control_D_LL = -Drive_Motor_Control_D_UL;

Drive_Motor_Control_Sign_Change_Deadband = 1500;
% EXTERN('Drive_Motor_Control_Sign_Change_Deadband', 'double', '1500');

Drive_Motor_Control_Module_Angle_Error = [0 45]*pi/180;
Drive_Motor_Control_Scale_Factor = [1 0.05];

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
Steering_Heading_Control_P = 1.5;

Steering_Heading_Control_I = 0.015*0;  % set to 0 to stop gyro drift
Steering_Heading_Control_I_UL = 0.1;
Steering_Heading_Control_I_LL = -Steering_Heading_Control_I_UL;
Steering_Heading_Control_D = 0;
Derivative_low_pass_filter_freq = 2; % Hz
Steering_Heading_Control_D_FilterCoeff = 1-exp(-2*pi*Derivative_low_pass_filter_freq*t_sample);
Steering_Heading_Control_D_UL = 0;
Steering_Heading_Control_D_LL = -Steering_Heading_Control_D_UL;

Steering_Heading_Control_Total_UL = 1.3;  % m/sec
Steering_Heading_Control_Total_LL = -Steering_Heading_Control_Total_UL;

Steering_Heading_Control_Deadzone = 0.1;

%% Translation Speed Rate Limit
Translation_Speed_Rate_Limit_Inc =  3/0.7*0.02;
% EXTERN('Translation_Speed_Rate_Limit_Inc','double', '3/0.7*0.02');
Translation_Speed_Rate_Limit_Dec = -2/0.2*0.02;
% EXTERN('Translation_Speed_Rate_Limit_Dec', 'double', '-2/0.2*0.02');
Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
Translation_Speed_NonZero_Error_Thresh = 0.15;
Translation_Speed_NonZero_Final_Scale_Factor = 0.05;

%% Steering Localized Cmd Rate Limit
Steering_Localized_Cmd_Rate_Limit_Inc = 1/0.25*0.02*0+1;
Steering_Localized_Cmd_Rate_Limit_Dec = -1/0.25*0.02*0-1;
Steering_Localized_Cmd_Approach_Zero_Error_Thresh = 0.2;
Steering_Localized_Cmd_Approach_Zero_Final_Thresh = 0.01;
Steering_Localized_Cmd_NonZero_Error_Thresh = 0.2;
Steering_Localized_Cmd_NonZero_Final_Scale_Factor = 0.1;

%% Occupency Map
Occupency_Matrix = LoadBinaryPNG('TestMap1.png');