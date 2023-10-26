

% distances between swerve modules
BackFront = 0.3746;
LeftRight = 0.3746;

% swerve module distances from center to x and y coordinates
r1x = BackFront/2;
r1y = LeftRight/2;

r2x = BackFront/2;
r2y = -LeftRight/2;

r3x = -BackFront/2;
r3y = LeftRight/2;

r4x = -BackFront/2;
r4y = -LeftRight/2;

% robot rotation matrix to obtain Vx and Vy for each module from the
% robot center Vx, Vy, and Omega.
Rotation_Local =  [1 0 -r1y;
                   0 1  r1x;
                   1 0 -r2y;
                   0 1  r2x;
                   1 0 -r3y;
                   0 1  r3x;
                   1 0 -r4y;
                   0 1  r4x];

% pseudo inverse of the rotation matrix
temp = pinv(Rotation_Local);
% only keep first two rows since we don't need to estimate Omega
Rotation_Local_Inv = temp(1:2,:);
clear temp

% Wheel Gear Ratio
gear_ratio = 8.14;
wheel_diameter = 0.101600203;
Wheel_Speed_to_Motor_Speed = 60*gear_ratio/(wheel_diameter*pi);
Motor_Rev_to_Wheel_Distance = wheel_diameter*pi/gear_ratio;
clear gear_ratio wheel_diameter