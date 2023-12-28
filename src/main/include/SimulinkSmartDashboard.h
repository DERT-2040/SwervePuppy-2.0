// This file has been auto generated from a Matlab script
// Do not manually edit since changes will be lost
#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/NetworkTable.h>
#include <networktables/RawTopic.h>
#include <networktables/NetworkTableInstance.h>
#include "Code_Gen_Model_ert_rtw\Code_Gen_Model.h"
 
class SimulinkSmartDashboard {
    public:
        void InitTunableSmartDashboard();
    private:
        nt::NetworkTableEntry __Boost_Trigger_Decreasing_Limit__Entry;
        nt::NetworkTableEntry __Boost_Trigger_High_Speed__Entry;
        nt::NetworkTableEntry __Boost_Trigger_Increasing_Limit__Entry;
        nt::NetworkTableEntry __Boost_Trigger_Low_Speed__Entry;
        nt::NetworkTableEntry __Drive_Motor_Control_D__Entry;
        nt::NetworkTableEntry __Drive_Motor_Control_D_FilterCoeff__Entry;
        nt::NetworkTableEntry __Drive_Motor_Control_D_LL__Entry;
        nt::NetworkTableEntry __Drive_Motor_Control_D_UL__Entry;
        nt::NetworkTableEntry __Drive_Motor_Control_FF__Entry;
        nt::NetworkTableEntry __Drive_Motor_Control_I__Entry;
        nt::NetworkTableEntry __Drive_Motor_Control_I_LL__Entry;
        nt::NetworkTableEntry __Drive_Motor_Control_I_UL__Entry;
        nt::NetworkTableEntry __Drive_Motor_Control_P__Entry;
        nt::NetworkTableEntry __Drive_Motor_Control_Sign_Change_Deadband__Entry;
        nt::NetworkTableEntry __Odometry_Desired_X__Entry;
        nt::NetworkTableEntry __Odometry_Desired_Y__Entry;
        nt::NetworkTableEntry __Odometry_X_Y_TEAR__Entry;
        nt::NetworkTableEntry __Spline_Capture_Radius__Entry;
        nt::NetworkTableEntry __Spline_Last_Pose_Distance_to_Velocity_Gain__Entry;
        nt::NetworkTableEntry __Spline_Lookahead_Dist__Entry;
        nt::NetworkTableEntry __Spline_Max_Centripital_Acceleration__Entry;
        nt::NetworkTableEntry __Spline_Pose_Num_Before_End_Reduce_Speed__Entry;
        nt::NetworkTableEntry __Steering_Abs_Deadband_Range__Entry;
        nt::NetworkTableEntry __Steering_Heading_Control_D__Entry;
        nt::NetworkTableEntry __Steering_Heading_Control_D_FilterCoeff__Entry;
        nt::NetworkTableEntry __Steering_Heading_Control_D_LL__Entry;
        nt::NetworkTableEntry __Steering_Heading_Control_D_UL__Entry;
        nt::NetworkTableEntry __Steering_Heading_Control_Deadzone__Entry;
        nt::NetworkTableEntry __Steering_Heading_Control_I__Entry;
        nt::NetworkTableEntry __Steering_Heading_Control_I_LL__Entry;
        nt::NetworkTableEntry __Steering_Heading_Control_I_UL__Entry;
        nt::NetworkTableEntry __Steering_Heading_Control_P__Entry;
        nt::NetworkTableEntry __Steering_Heading_Control_Total_LL__Entry;
        nt::NetworkTableEntry __Steering_Heading_Control_Total_UL__Entry;
        nt::NetworkTableEntry __Steering_Localized_Cmd_Approach_Zero_Error_Thresh__Entry;
        nt::NetworkTableEntry __Steering_Localized_Cmd_Approach_Zero_Final_Thresh__Entry;
        nt::NetworkTableEntry __Steering_Localized_Cmd_NonZero_Error_Thresh__Entry;
        nt::NetworkTableEntry __Steering_Localized_Cmd_NonZero_Final_Scale_Factor__Entry;
        nt::NetworkTableEntry __Steering_Localized_Cmd_Rate_Limit_Dec__Entry;
        nt::NetworkTableEntry __Steering_Localized_Cmd_Rate_Limit_Inc__Entry;
        nt::NetworkTableEntry __Steering_Motor_Control_D__Entry;
        nt::NetworkTableEntry __Steering_Motor_Control_D_FilterCoeff__Entry;
        nt::NetworkTableEntry __Steering_Motor_Control_D_LL__Entry;
        nt::NetworkTableEntry __Steering_Motor_Control_D_UL__Entry;
        nt::NetworkTableEntry __Steering_Motor_Control_I__Entry;
        nt::NetworkTableEntry __Steering_Motor_Control_I_LL__Entry;
        nt::NetworkTableEntry __Steering_Motor_Control_I_UL__Entry;
        nt::NetworkTableEntry __Steering_Motor_Control_P__Entry;
        nt::NetworkTableEntry __Steering_Relative_Gain__Entry;
        nt::NetworkTableEntry __Translation_Speed_Approach_Zero_Error_Thresh__Entry;
        nt::NetworkTableEntry __Translation_Speed_Approach_Zero_Final_Thresh__Entry;
        nt::NetworkTableEntry __Translation_Speed_NonZero_Error_Thresh__Entry;
        nt::NetworkTableEntry __Translation_Speed_NonZero_Final_Scale_Factor__Entry;
        nt::NetworkTableEntry __Translation_Speed_Rate_Limit_Inc__Entry;
};
