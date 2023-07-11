#pragma once
//std
#include <string>
class Constants {
public:
//HID Ports
    static constexpr int k_Gamepad_Port = 0;
    static constexpr int k_Drive_Joystick_Port = 1;
    static constexpr int k_Steer_Joystick_Port = 2;
//Swerve Drive
    //Drive Motor CAN IDs
        static constexpr int k_FrontLeft_Drive_CANID = 10;
        static constexpr int k_FrontRight_Drive_CANID = 20;
        static constexpr int k_BackLeft_Drive_CANID = 30;
        static constexpr int k_BackRight_Drive_CANID = 40;
    //Steer Motor CAN IDs
        static constexpr int k_FrontLeft_Steer_CANID = 11;
        static constexpr int k_FrontRight_Steer_CANID = 21;
        static constexpr int k_BackLeft_Steer_CANID = 31;
        static constexpr int k_BackRight_Steer_CANID = 41;
    //Steer Encoder Ports
        static constexpr int k_FrontLeft_Steer_Encoder_Port = 9;
        static constexpr int k_FrontRight_Steer_Encoder_Port = 7;
        static constexpr int k_BackLeft_Steer_Encoder_Port = 8;
        static constexpr int k_BackRight_Steer_Encoder_Port = 6;
    //Drive Motor Properties
        static constexpr double k_Drive_Motor_Open_Loop_Ramp_Rate = 0.00000001;
        static constexpr double k_Drive_Motor_Smart_Current_Limit = 40;
        static constexpr double k_Drive_Motor_Secondary_Current_Limit = 40;
    //Steer Motor Properties
        static constexpr double k_Steer_Motor_Open_Loop_Ramp_Rate = 0.1;
        static constexpr double k_Steer_Motor_Smart_Current_Limit = 20;
        static constexpr double k_Steer_Motor_Secondary_Current_Limit = 20;
    //Wheel Offset Keys
        static constexpr std::string_view k_FrontLeft_Wheel_Offset_Key = "FrontLeftWheelOffset";
        static constexpr std::string_view k_FrontRight_Wheel_Offset_Key = "FrontRightWheelOffset";
        static constexpr std::string_view k_BackLeft_Wheel_Offset_Key = "BackLeftWheelOffset";
        static constexpr std::string_view k_BackRight_Wheel_Offset_Key = "BackRightWheelOffset";
  //Buttons
    static constexpr int k_Reset_Wheel_Offset_Button = 7;
    static constexpr int k_Calibrate_Gyro_Button = 2;
    static constexpr int k_Toggle_Absolute_Translation_Button = 3;
    static constexpr int k_Toggle_Absolute_Steering_Button = 3;
//IMU
    //Total Number of Samples when Calibrating
        static constexpr int k_IMU_Calibration_Sample_Count = 10000;
    //Gryo Drift Offset Key
        static constexpr std::string_view k_Gyro_Drift_Offset_Key = "GyroDrift";
};