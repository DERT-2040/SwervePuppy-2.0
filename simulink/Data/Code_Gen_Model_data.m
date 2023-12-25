% Parameters to exclude from being tunable.
% This is used in the 'Build_Extern.m' file
Not_Tunable_List = ['t_sample',...
    'Distance_FL_x','DistancAe_FL_y','Distance_FR_x','Distance_FR_y',...
    'Distance_BL_x','Distance_BL_y','Distance_BR_x','Distance_BR_y',...
    'Wheel_Speed_to_Motor_Speed','Motor_Rev_to_Wheel_Distance'];

% sample time model
t_sample = 0.02;

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
Boost_Trigger_Decreasing_Limit = -2/0.9*0.02;

%% Wheel Gear Ratio
gear_ratio = 8.14;
wheel_diameter = 0.101600203;
Wheel_Speed_to_Motor_Speed = 60*gear_ratio/(wheel_diameter*pi);

% Ran a test without the adjustment factor with the following results
%   physical measurement = 177.33 feet
%   odometry estimate    = 186.44 feet
adjustment_factor = 0.951;  % 177.33/186.44

Motor_Rev_to_Wheel_Distance = wheel_diameter*pi/gear_ratio*adjustment_factor;

clear gear_ratio wheel_diameter adjustment_factor

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

% only used for validation testing
% set to 1 to tear the X and Y measurement
% set to 0 to let the X and Y measurements accumulate since the last tear
Odometry_X_Y_TEAR = 0;

% Coordinates for testing
Odometry_Desired_X = 0;
Odometry_Desired_Y = 0;

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

Drive_Motor_Control_Module_Angle_Error = [0 45]*pi/180;
Drive_Motor_Control_Scale_Factor = [1 0.05];

clear Derivative_low_pass_filter_freq

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

clear Derivative_low_pass_filter_freq

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

clear Derivative_low_pass_filter_freq

%% Translation Speed Rate Limit
Translation_Speed_Rate_Limit_Inc =  3/0.7*0.02;
Translation_Speed_Rate_Limit_Dec = -2/0.2*0.02;
Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
Translation_Speed_NonZero_Error_Thresh = 0.15;
Translation_Speed_NonZero_Final_Scale_Factor = 0.05;

%% Steering Localized Cmd Rate Limit
Steering_Localized_Cmd_Rate_Limit_Inc = 1/0.25*0.02*0 + 1;
Steering_Localized_Cmd_Rate_Limit_Dec = -1/0.25*0.02*0 - 1;
Steering_Localized_Cmd_Approach_Zero_Error_Thresh = 0.2;
Steering_Localized_Cmd_Approach_Zero_Final_Thresh = 0.01;
Steering_Localized_Cmd_NonZero_Error_Thresh = 0.2;
Steering_Localized_Cmd_NonZero_Final_Scale_Factor = 0.1;

%% Spline Creation Constants
Spline_Num_Samples = 50;
Spline_Num_Samples_x3 = Spline_Num_Samples*3;

Spline_Max_Num_RefPoses = 19;

Spline_Tension = 0.5;

Spline_Capture_Radius = 0.1;
Spline_Stop_Radius = 0.05;

Spline_Samples_Per_Pass = 10; % must be an even number

Spline_Lookahead_Dist = 0.2;

Spline_Pose_Num_Before_End_Reduce_Speed = 2;
Spline_Translation_Speed = 1.0;

Spline_Ref_Poses_default = zeros(Spline_Max_Num_RefPoses,2);
Spline_Num_Poses_default = 2.0;

Spline_Enable_auto = 1;
Spline_Ref_Poses_auto = 1*[
    0 0
    0.3*cos(2*22.5*pi/180)  0.3*sin(2*22.5*pi/180)
    0.7*cos(2*22.5*pi/180)  0.7*sin(2*22.5*pi/180)
    cos(2*22.5*pi/180)  sin(2*22.5*pi/180)
    cos(3*22.5*pi/180)  sin(3*22.5*pi/180)
    cos(4*22.5*pi/180)  sin(4*22.5*pi/180) 
    cos(5*22.5*pi/180)  sin(5*22.5*pi/180)
    cos(6*22.5*pi/180)  sin(6*22.5*pi/180)
    cos(7*22.5*pi/180)  sin(7*22.5*pi/180)   
    cos(8*22.5*pi/180)  sin(8*22.5*pi/180) 
    cos(9*22.5*pi/180)  sin(9*22.5*pi/180)
    cos(10*22.5*pi/180) sin(10*22.5*pi/180)
    cos(11*22.5*pi/180) sin(11*22.5*pi/180)
    cos(12*22.5*pi/180) sin(12*22.5*pi/180)
    cos(13*22.5*pi/180) sin(13*22.5*pi/180)
    cos(14*22.5*pi/180) sin(14*22.5*pi/180)
    0.7*cos(14*22.5*pi/180) 0.7*sin(14*22.5*pi/180)
    0.3*cos(14*22.5*pi/180) 0.3*sin(14*22.5*pi/180)    
    0 0];
    % 4 0
    % 0 0];
Spline_Num_Poses_auto = Spline_Max_Num_RefPoses;