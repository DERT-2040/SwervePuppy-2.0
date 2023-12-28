// This file has been auto generated from a Matlab script
// Do not manually edit since changes will be lost
#include "include/SimulinkSmartDashboardInterface.h"
 
void SimulinkSmartDashboardInterface::InitSmartDashboardInterface() {
    nt::NetworkTableInstance NTinst = nt::NetworkTableInstance::GetDefault();
    auto NTtable_Tune = NTinst.GetTable("Simulink Tunable Params");
    auto NTtable_Inport = NTinst.GetTable("Simulink Top Level Ports");
    auto NTtable_Outport = NTinst.GetTable("Simulink Top Level Ports");
    auto NTtable_TPoint = NTinst.GetTable("Simulink Test Points");
 
    __Boost_Trigger_Decreasing_Limit__Entry = NTtable_Tune->GetEntry("Boost_Trigger_Decreasing_Limit");
    NTinst.AddListener(__Boost_Trigger_Decreasing_Limit__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Boost_Trigger_Decreasing_Limit = event.GetValueEventData()->value.GetDouble();});
    __Boost_Trigger_Decreasing_Limit__Entry.SetDouble(-0.044444);
 
    __Boost_Trigger_High_Speed__Entry = NTtable_Tune->GetEntry("Boost_Trigger_High_Speed");
    NTinst.AddListener(__Boost_Trigger_High_Speed__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Boost_Trigger_High_Speed = event.GetValueEventData()->value.GetDouble();});
    __Boost_Trigger_High_Speed__Entry.SetDouble(3.658);
 
    __Boost_Trigger_Increasing_Limit__Entry = NTtable_Tune->GetEntry("Boost_Trigger_Increasing_Limit");
    NTinst.AddListener(__Boost_Trigger_Increasing_Limit__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Boost_Trigger_Increasing_Limit = event.GetValueEventData()->value.GetDouble();});
    __Boost_Trigger_Increasing_Limit__Entry.SetDouble(0.04);
 
    __Boost_Trigger_Low_Speed__Entry = NTtable_Tune->GetEntry("Boost_Trigger_Low_Speed");
    NTinst.AddListener(__Boost_Trigger_Low_Speed__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Boost_Trigger_Low_Speed = event.GetValueEventData()->value.GetDouble();});
    __Boost_Trigger_Low_Speed__Entry.SetDouble(1.5);
 
    __Drive_Motor_Control_D__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_D");
    NTinst.AddListener(__Drive_Motor_Control_D__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_D = event.GetValueEventData()->value.GetDouble();});
    __Drive_Motor_Control_D__Entry.SetDouble(0.0001);
 
    __Drive_Motor_Control_D_FilterCoeff__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_D_FilterCoeff");
    NTinst.AddListener(__Drive_Motor_Control_D_FilterCoeff__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_D_FilterCoeff = event.GetValueEventData()->value.GetDouble();});
    __Drive_Motor_Control_D_FilterCoeff__Entry.SetDouble(0.22223);
 
    __Drive_Motor_Control_D_LL__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_D_LL");
    NTinst.AddListener(__Drive_Motor_Control_D_LL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_D_LL = event.GetValueEventData()->value.GetDouble();});
    __Drive_Motor_Control_D_LL__Entry.SetDouble(-0.2);
 
    __Drive_Motor_Control_D_UL__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_D_UL");
    NTinst.AddListener(__Drive_Motor_Control_D_UL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_D_UL = event.GetValueEventData()->value.GetDouble();});
    __Drive_Motor_Control_D_UL__Entry.SetDouble(0.2);
 
    __Drive_Motor_Control_FF__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_FF");
    NTinst.AddListener(__Drive_Motor_Control_FF__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_FF = event.GetValueEventData()->value.GetDouble();});
    __Drive_Motor_Control_FF__Entry.SetDouble(0.00018182);
 
    __Drive_Motor_Control_I__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_I");
    NTinst.AddListener(__Drive_Motor_Control_I__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_I = event.GetValueEventData()->value.GetDouble();});
    __Drive_Motor_Control_I__Entry.SetDouble(0);
 
    __Drive_Motor_Control_I_LL__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_I_LL");
    NTinst.AddListener(__Drive_Motor_Control_I_LL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_I_LL = event.GetValueEventData()->value.GetDouble();});
    __Drive_Motor_Control_I_LL__Entry.SetDouble(0);
 
    __Drive_Motor_Control_I_UL__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_I_UL");
    NTinst.AddListener(__Drive_Motor_Control_I_UL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_I_UL = event.GetValueEventData()->value.GetDouble();});
    __Drive_Motor_Control_I_UL__Entry.SetDouble(0);
 
    __Drive_Motor_Control_P__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_P");
    NTinst.AddListener(__Drive_Motor_Control_P__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_P = event.GetValueEventData()->value.GetDouble();});
    __Drive_Motor_Control_P__Entry.SetDouble(5e-06);
 
    __Drive_Motor_Control_Sign_Change_Deadband__Entry = NTtable_Tune->GetEntry("Drive_Motor_Control_Sign_Change_Deadband");
    NTinst.AddListener(__Drive_Motor_Control_Sign_Change_Deadband__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Drive_Motor_Control_Sign_Change_Deadband = event.GetValueEventData()->value.GetDouble();});
    __Drive_Motor_Control_Sign_Change_Deadband__Entry.SetDouble(1500);
 
    __Odometry_Desired_X__Entry = NTtable_Tune->GetEntry("Odometry_Desired_X");
    NTinst.AddListener(__Odometry_Desired_X__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Odometry_Desired_X = event.GetValueEventData()->value.GetDouble();});
    __Odometry_Desired_X__Entry.SetDouble(0);
 
    __Odometry_Desired_Y__Entry = NTtable_Tune->GetEntry("Odometry_Desired_Y");
    NTinst.AddListener(__Odometry_Desired_Y__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Odometry_Desired_Y = event.GetValueEventData()->value.GetDouble();});
    __Odometry_Desired_Y__Entry.SetDouble(0);
 
    __Odometry_X_Y_TEAR__Entry = NTtable_Tune->GetEntry("Odometry_X_Y_TEAR");
    NTinst.AddListener(__Odometry_X_Y_TEAR__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Odometry_X_Y_TEAR = event.GetValueEventData()->value.GetDouble();});
    __Odometry_X_Y_TEAR__Entry.SetDouble(0);
 
    __Spline_Capture_Radius__Entry = NTtable_Tune->GetEntry("Spline_Capture_Radius");
    NTinst.AddListener(__Spline_Capture_Radius__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Spline_Capture_Radius = event.GetValueEventData()->value.GetDouble();});
    __Spline_Capture_Radius__Entry.SetDouble(0.1);
 
    __Spline_Last_Pose_Distance_to_Velocity_Gain__Entry = NTtable_Tune->GetEntry("Spline_Last_Pose_Distance_to_Velocity_Gain");
    NTinst.AddListener(__Spline_Last_Pose_Distance_to_Velocity_Gain__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Spline_Last_Pose_Distance_to_Velocity_Gain = event.GetValueEventData()->value.GetDouble();});
    __Spline_Last_Pose_Distance_to_Velocity_Gain__Entry.SetDouble(2);
 
    __Spline_Lookahead_Dist__Entry = NTtable_Tune->GetEntry("Spline_Lookahead_Dist");
    NTinst.AddListener(__Spline_Lookahead_Dist__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Spline_Lookahead_Dist = event.GetValueEventData()->value.GetDouble();});
    __Spline_Lookahead_Dist__Entry.SetDouble(0.2);
 
    __Spline_Max_Centripital_Acceleration__Entry = NTtable_Tune->GetEntry("Spline_Max_Centripital_Acceleration");
    NTinst.AddListener(__Spline_Max_Centripital_Acceleration__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Spline_Max_Centripital_Acceleration = event.GetValueEventData()->value.GetDouble();});
    __Spline_Max_Centripital_Acceleration__Entry.SetDouble(2);
 
    __Spline_Pose_Num_Before_End_Reduce_Speed__Entry = NTtable_Tune->GetEntry("Spline_Pose_Num_Before_End_Reduce_Speed");
    NTinst.AddListener(__Spline_Pose_Num_Before_End_Reduce_Speed__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Spline_Pose_Num_Before_End_Reduce_Speed = event.GetValueEventData()->value.GetDouble();});
    __Spline_Pose_Num_Before_End_Reduce_Speed__Entry.SetDouble(2);
 
    __Steering_Abs_Deadband_Range__Entry = NTtable_Tune->GetEntry("Steering_Abs_Deadband_Range");
    NTinst.AddListener(__Steering_Abs_Deadband_Range__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Abs_Deadband_Range = event.GetValueEventData()->value.GetDouble();});
    __Steering_Abs_Deadband_Range__Entry.SetDouble(0.7);
 
    __Steering_Heading_Control_D__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_D");
    NTinst.AddListener(__Steering_Heading_Control_D__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_D = event.GetValueEventData()->value.GetDouble();});
    __Steering_Heading_Control_D__Entry.SetDouble(0);
 
    __Steering_Heading_Control_D_FilterCoeff__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_D_FilterCoeff");
    NTinst.AddListener(__Steering_Heading_Control_D_FilterCoeff__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_D_FilterCoeff = event.GetValueEventData()->value.GetDouble();});
    __Steering_Heading_Control_D_FilterCoeff__Entry.SetDouble(0.22223);
 
    __Steering_Heading_Control_D_LL__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_D_LL");
    NTinst.AddListener(__Steering_Heading_Control_D_LL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_D_LL = event.GetValueEventData()->value.GetDouble();});
    __Steering_Heading_Control_D_LL__Entry.SetDouble(0);
 
    __Steering_Heading_Control_D_UL__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_D_UL");
    NTinst.AddListener(__Steering_Heading_Control_D_UL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_D_UL = event.GetValueEventData()->value.GetDouble();});
    __Steering_Heading_Control_D_UL__Entry.SetDouble(0);
 
    __Steering_Heading_Control_Deadzone__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_Deadzone");
    NTinst.AddListener(__Steering_Heading_Control_Deadzone__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_Deadzone = event.GetValueEventData()->value.GetDouble();});
    __Steering_Heading_Control_Deadzone__Entry.SetDouble(0.1);
 
    __Steering_Heading_Control_I__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_I");
    NTinst.AddListener(__Steering_Heading_Control_I__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_I = event.GetValueEventData()->value.GetDouble();});
    __Steering_Heading_Control_I__Entry.SetDouble(0);
 
    __Steering_Heading_Control_I_LL__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_I_LL");
    NTinst.AddListener(__Steering_Heading_Control_I_LL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_I_LL = event.GetValueEventData()->value.GetDouble();});
    __Steering_Heading_Control_I_LL__Entry.SetDouble(-0.1);
 
    __Steering_Heading_Control_I_UL__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_I_UL");
    NTinst.AddListener(__Steering_Heading_Control_I_UL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_I_UL = event.GetValueEventData()->value.GetDouble();});
    __Steering_Heading_Control_I_UL__Entry.SetDouble(0.1);
 
    __Steering_Heading_Control_P__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_P");
    NTinst.AddListener(__Steering_Heading_Control_P__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_P = event.GetValueEventData()->value.GetDouble();});
    __Steering_Heading_Control_P__Entry.SetDouble(1.5);
 
    __Steering_Heading_Control_Total_LL__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_Total_LL");
    NTinst.AddListener(__Steering_Heading_Control_Total_LL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_Total_LL = event.GetValueEventData()->value.GetDouble();});
    __Steering_Heading_Control_Total_LL__Entry.SetDouble(-1.3);
 
    __Steering_Heading_Control_Total_UL__Entry = NTtable_Tune->GetEntry("Steering_Heading_Control_Total_UL");
    NTinst.AddListener(__Steering_Heading_Control_Total_UL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Heading_Control_Total_UL = event.GetValueEventData()->value.GetDouble();});
    __Steering_Heading_Control_Total_UL__Entry.SetDouble(1.3);
 
    __Steering_Localized_Cmd_Approach_Zero_Error_Thresh__Entry = NTtable_Tune->GetEntry("Steering_Localized_Cmd_Approach_Zero_Error_Thresh");
    NTinst.AddListener(__Steering_Localized_Cmd_Approach_Zero_Error_Thresh__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Localized_Cmd_Approach_Zero_Error_Thresh = event.GetValueEventData()->value.GetDouble();});
    __Steering_Localized_Cmd_Approach_Zero_Error_Thresh__Entry.SetDouble(0.2);
 
    __Steering_Localized_Cmd_Approach_Zero_Final_Thresh__Entry = NTtable_Tune->GetEntry("Steering_Localized_Cmd_Approach_Zero_Final_Thresh");
    NTinst.AddListener(__Steering_Localized_Cmd_Approach_Zero_Final_Thresh__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Localized_Cmd_Approach_Zero_Final_Thresh = event.GetValueEventData()->value.GetDouble();});
    __Steering_Localized_Cmd_Approach_Zero_Final_Thresh__Entry.SetDouble(0.01);
 
    __Steering_Localized_Cmd_NonZero_Error_Thresh__Entry = NTtable_Tune->GetEntry("Steering_Localized_Cmd_NonZero_Error_Thresh");
    NTinst.AddListener(__Steering_Localized_Cmd_NonZero_Error_Thresh__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Localized_Cmd_NonZero_Error_Thresh = event.GetValueEventData()->value.GetDouble();});
    __Steering_Localized_Cmd_NonZero_Error_Thresh__Entry.SetDouble(0.2);
 
    __Steering_Localized_Cmd_NonZero_Final_Scale_Factor__Entry = NTtable_Tune->GetEntry("Steering_Localized_Cmd_NonZero_Final_Scale_Factor");
    NTinst.AddListener(__Steering_Localized_Cmd_NonZero_Final_Scale_Factor__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Localized_Cmd_NonZero_Final_Scale_Factor = event.GetValueEventData()->value.GetDouble();});
    __Steering_Localized_Cmd_NonZero_Final_Scale_Factor__Entry.SetDouble(0.1);
 
    __Steering_Localized_Cmd_Rate_Limit_Dec__Entry = NTtable_Tune->GetEntry("Steering_Localized_Cmd_Rate_Limit_Dec");
    NTinst.AddListener(__Steering_Localized_Cmd_Rate_Limit_Dec__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Localized_Cmd_Rate_Limit_Dec = event.GetValueEventData()->value.GetDouble();});
    __Steering_Localized_Cmd_Rate_Limit_Dec__Entry.SetDouble(-1);
 
    __Steering_Localized_Cmd_Rate_Limit_Inc__Entry = NTtable_Tune->GetEntry("Steering_Localized_Cmd_Rate_Limit_Inc");
    NTinst.AddListener(__Steering_Localized_Cmd_Rate_Limit_Inc__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Localized_Cmd_Rate_Limit_Inc = event.GetValueEventData()->value.GetDouble();});
    __Steering_Localized_Cmd_Rate_Limit_Inc__Entry.SetDouble(1);
 
    __Steering_Motor_Control_D__Entry = NTtable_Tune->GetEntry("Steering_Motor_Control_D");
    NTinst.AddListener(__Steering_Motor_Control_D__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Motor_Control_D = event.GetValueEventData()->value.GetDouble();});
    __Steering_Motor_Control_D__Entry.SetDouble(0.5);
 
    __Steering_Motor_Control_D_FilterCoeff__Entry = NTtable_Tune->GetEntry("Steering_Motor_Control_D_FilterCoeff");
    NTinst.AddListener(__Steering_Motor_Control_D_FilterCoeff__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Motor_Control_D_FilterCoeff = event.GetValueEventData()->value.GetDouble();});
    __Steering_Motor_Control_D_FilterCoeff__Entry.SetDouble(0.22223);
 
    __Steering_Motor_Control_D_LL__Entry = NTtable_Tune->GetEntry("Steering_Motor_Control_D_LL");
    NTinst.AddListener(__Steering_Motor_Control_D_LL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Motor_Control_D_LL = event.GetValueEventData()->value.GetDouble();});
    __Steering_Motor_Control_D_LL__Entry.SetDouble(-0.2);
 
    __Steering_Motor_Control_D_UL__Entry = NTtable_Tune->GetEntry("Steering_Motor_Control_D_UL");
    NTinst.AddListener(__Steering_Motor_Control_D_UL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Motor_Control_D_UL = event.GetValueEventData()->value.GetDouble();});
    __Steering_Motor_Control_D_UL__Entry.SetDouble(0.2);
 
    __Steering_Motor_Control_I__Entry = NTtable_Tune->GetEntry("Steering_Motor_Control_I");
    NTinst.AddListener(__Steering_Motor_Control_I__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Motor_Control_I = event.GetValueEventData()->value.GetDouble();});
    __Steering_Motor_Control_I__Entry.SetDouble(0.005);
 
    __Steering_Motor_Control_I_LL__Entry = NTtable_Tune->GetEntry("Steering_Motor_Control_I_LL");
    NTinst.AddListener(__Steering_Motor_Control_I_LL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Motor_Control_I_LL = event.GetValueEventData()->value.GetDouble();});
    __Steering_Motor_Control_I_LL__Entry.SetDouble(-0.005);
 
    __Steering_Motor_Control_I_UL__Entry = NTtable_Tune->GetEntry("Steering_Motor_Control_I_UL");
    NTinst.AddListener(__Steering_Motor_Control_I_UL__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Motor_Control_I_UL = event.GetValueEventData()->value.GetDouble();});
    __Steering_Motor_Control_I_UL__Entry.SetDouble(0.005);
 
    __Steering_Motor_Control_P__Entry = NTtable_Tune->GetEntry("Steering_Motor_Control_P");
    NTinst.AddListener(__Steering_Motor_Control_P__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Motor_Control_P = event.GetValueEventData()->value.GetDouble();});
    __Steering_Motor_Control_P__Entry.SetDouble(0.15);
 
    __Steering_Relative_Gain__Entry = NTtable_Tune->GetEntry("Steering_Relative_Gain");
    NTinst.AddListener(__Steering_Relative_Gain__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Steering_Relative_Gain = event.GetValueEventData()->value.GetDouble();});
    __Steering_Relative_Gain__Entry.SetDouble(1.3);
 
    __Translation_Speed_Approach_Zero_Error_Thresh__Entry = NTtable_Tune->GetEntry("Translation_Speed_Approach_Zero_Error_Thresh");
    NTinst.AddListener(__Translation_Speed_Approach_Zero_Error_Thresh__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Translation_Speed_Approach_Zero_Error_Thresh = event.GetValueEventData()->value.GetDouble();});
    __Translation_Speed_Approach_Zero_Error_Thresh__Entry.SetDouble(0.2);
 
    __Translation_Speed_Approach_Zero_Final_Thresh__Entry = NTtable_Tune->GetEntry("Translation_Speed_Approach_Zero_Final_Thresh");
    NTinst.AddListener(__Translation_Speed_Approach_Zero_Final_Thresh__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Translation_Speed_Approach_Zero_Final_Thresh = event.GetValueEventData()->value.GetDouble();});
    __Translation_Speed_Approach_Zero_Final_Thresh__Entry.SetDouble(0.01);
 
    __Translation_Speed_NonZero_Error_Thresh__Entry = NTtable_Tune->GetEntry("Translation_Speed_NonZero_Error_Thresh");
    NTinst.AddListener(__Translation_Speed_NonZero_Error_Thresh__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Translation_Speed_NonZero_Error_Thresh = event.GetValueEventData()->value.GetDouble();});
    __Translation_Speed_NonZero_Error_Thresh__Entry.SetDouble(0.15);
 
    __Translation_Speed_NonZero_Final_Scale_Factor__Entry = NTtable_Tune->GetEntry("Translation_Speed_NonZero_Final_Scale_Factor");
    NTinst.AddListener(__Translation_Speed_NonZero_Final_Scale_Factor__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Translation_Speed_NonZero_Final_Scale_Factor = event.GetValueEventData()->value.GetDouble();});
    __Translation_Speed_NonZero_Final_Scale_Factor__Entry.SetDouble(0.05);
 
    __Translation_Speed_Rate_Limit_Inc__Entry = NTtable_Tune->GetEntry("Translation_Speed_Rate_Limit_Inc");
    NTinst.AddListener(__Translation_Speed_Rate_Limit_Inc__Entry, nt::EventFlags::kValueAll, [] (const nt::Event& event) {Translation_Speed_Rate_Limit_Inc = event.GetValueEventData()->value.GetDouble();});
    __Translation_Speed_Rate_Limit_Inc__Entry.SetDouble(0.085714);
 
// Inports
    __GameState__Entry = NTtable_Inport->GetEntry("GameState");
    __Steer_Joystick_X__Entry = NTtable_Inport->GetEntry("Steer_Joystick_X");
    __Steer_Joystick_Y__Entry = NTtable_Inport->GetEntry("Steer_Joystick_Y");
    __Drive_Joystick_X__Entry = NTtable_Inport->GetEntry("Drive_Joystick_X");
    __Drive_Joystick_Y__Entry = NTtable_Inport->GetEntry("Drive_Joystick_Y");
    __Is_Boost_Trigger_Pulled__Entry = NTtable_Inport->GetEntry("Is_Boost_Trigger_Pulled");
    __Gyro_Angle__Entry = NTtable_Inport->GetEntry("Gyro_Angle");
    __FrontLeft_Drive_Motor_Speed__Entry = NTtable_Inport->GetEntry("FrontLeft_Drive_Motor_Speed");
    __FrontRight_Drive_Motor_Speed__Entry = NTtable_Inport->GetEntry("FrontRight_Drive_Motor_Speed");
    __BackLeft_Drive_Motor_Speed__Entry = NTtable_Inport->GetEntry("BackLeft_Drive_Motor_Speed");
    __BackRight_Drive_Motor_Speed__Entry = NTtable_Inport->GetEntry("BackRight_Drive_Motor_Speed");
    __FrontLeft_Steer_Rev__Entry = NTtable_Inport->GetEntry("FrontLeft_Steer_Rev");
    __FrontRight_Steer_Rev__Entry = NTtable_Inport->GetEntry("FrontRight_Steer_Rev");
    __BackLeft_Steer_Rev__Entry = NTtable_Inport->GetEntry("BackLeft_Steer_Rev");
    __BackRight_Steer_Rev__Entry = NTtable_Inport->GetEntry("BackRight_Steer_Rev");
    __FrontLeft_Turn_Offset__Entry = NTtable_Inport->GetEntry("FrontLeft_Turn_Offset");
    __FrontRight_Turn_Offset__Entry = NTtable_Inport->GetEntry("FrontRight_Turn_Offset");
    __BackLeft_Turn_Offset__Entry = NTtable_Inport->GetEntry("BackLeft_Turn_Offset");
    __BackRight_Turn_Offset__Entry = NTtable_Inport->GetEntry("BackRight_Turn_Offset");
    __Is_Absolute_Steering__Entry = NTtable_Inport->GetEntry("Is_Absolute_Steering");
    __Is_Absolute_Translation__Entry = NTtable_Inport->GetEntry("Is_Absolute_Translation");
    __FrontLeft_Drive_Motor_Rev__Entry = NTtable_Inport->GetEntry("FrontLeft_Drive_Motor_Rev");
    __FrontRight_Drive_Motor_Rev__Entry = NTtable_Inport->GetEntry("FrontRight_Drive_Motor_Rev");
    __BackLeft_Drive_Motor_Rev__Entry = NTtable_Inport->GetEntry("BackLeft_Drive_Motor_Rev");
    __BackRight_Drive_Motor_Rev__Entry = NTtable_Inport->GetEntry("BackRight_Drive_Motor_Rev");
 
// Outports
    __FrontLeft_Drive_DutyCycle__Entry = NTtable_Outport->GetEntry("FrontLeft_Drive_DutyCycle");
    __FrontLeft_Steer_DutyCycle__Entry = NTtable_Outport->GetEntry("FrontLeft_Steer_DutyCycle");
    __FrontRight_Drive_DutyCycle__Entry = NTtable_Outport->GetEntry("FrontRight_Drive_DutyCycle");
    __FrontRight_Steer_DutyCycle__Entry = NTtable_Outport->GetEntry("FrontRight_Steer_DutyCycle");
    __BackLeft_Drive_DutyCycle__Entry = NTtable_Outport->GetEntry("BackLeft_Drive_DutyCycle");
    __BackLeft_Steer_DutyCycle__Entry = NTtable_Outport->GetEntry("BackLeft_Steer_DutyCycle");
    __BackRight_Drive_DutyCycle__Entry = NTtable_Outport->GetEntry("BackRight_Drive_DutyCycle");
    __BackRight_Steer_DutyCycle__Entry = NTtable_Outport->GetEntry("BackRight_Steer_DutyCycle");
 
// Test Points
    __FL_Steer_Module_Angle__Entry = NTtable_TPoint->GetEntry("FL_Steer_Module_Angle");
    __FR_Steer_Module_Angle__Entry = NTtable_TPoint->GetEntry("FR_Steer_Module_Angle");
    __BL_Steer_Module_Angle__Entry = NTtable_TPoint->GetEntry("BL_Steer_Module_Angle");
    __BR_Steer_Module_Angle__Entry = NTtable_TPoint->GetEntry("BR_Steer_Module_Angle");
    __Odom_Position_X_global__Entry = NTtable_TPoint->GetEntry("Odom_Position_X_global");
    __Odom_Position_Y_global__Entry = NTtable_TPoint->GetEntry("Odom_Position_Y_global");
    __Spline_Num_Poses__Entry = NTtable_TPoint->GetEntry("Spline_Num_Poses");
    __Steering_Abs_Cmd__Entry = NTtable_TPoint->GetEntry("Steering_Abs_Cmd");
    __Steering_Rel_Cmd__Entry = NTtable_TPoint->GetEntry("Steering_Rel_Cmd");
    __Translation_Speed__Entry = NTtable_TPoint->GetEntry("Translation_Speed");
    __Translation_Angle__Entry = NTtable_TPoint->GetEntry("Translation_Angle");
    __Translation_Speed_SPF__Entry = NTtable_TPoint->GetEntry("Translation_Speed_SPF");
    __Translation_Speed_RL__Entry = NTtable_TPoint->GetEntry("Translation_Speed_RL");
    __Translation_Angle_SPF__Entry = NTtable_TPoint->GetEntry("Translation_Angle_SPF");
    __Translation_Steering_Cmd__Entry = NTtable_TPoint->GetEntry("Translation_Steering_Cmd");
    __Steering_Rel_Cmd_SPF__Entry = NTtable_TPoint->GetEntry("Steering_Rel_Cmd_SPF");
    __Steering_Abs_Cmd_SPF__Entry = NTtable_TPoint->GetEntry("Steering_Abs_Cmd_SPF");
    __Gyro_Angle_Adjustment_SPF__Entry = NTtable_TPoint->GetEntry("Gyro_Angle_Adjustment_SPF");
    __Steering_Localized_PID__Entry = NTtable_TPoint->GetEntry("Steering_Localized_PID");
    __Steering_Localized_Cmd__Entry = NTtable_TPoint->GetEntry("Steering_Localized_Cmd");
    __Switch1__Entry = NTtable_TPoint->GetEntry("Switch1");
    __Switch1_m__Entry = NTtable_TPoint->GetEntry("Switch1_m");
    __Switch1_o__Entry = NTtable_TPoint->GetEntry("Switch1_o");
    __Switch1_p__Entry = NTtable_TPoint->GetEntry("Switch1_p");
    __BR_Desired_Wheel_Speed__Entry = NTtable_TPoint->GetEntry("BR_Desired_Wheel_Speed");
    __BR_Desired_Module_Angle__Entry = NTtable_TPoint->GetEntry("BR_Desired_Module_Angle");
    __FL_Desired_Wheel_Speed__Entry = NTtable_TPoint->GetEntry("FL_Desired_Wheel_Speed");
    __FL_Desired_Module_Angle__Entry = NTtable_TPoint->GetEntry("FL_Desired_Module_Angle");
    __FR_Desired_Wheel_Speed__Entry = NTtable_TPoint->GetEntry("FR_Desired_Wheel_Speed");
    __FR_Desired_Module_Angle__Entry = NTtable_TPoint->GetEntry("FR_Desired_Module_Angle");
    __BL_Desired_Wheel_Speed__Entry = NTtable_TPoint->GetEntry("BL_Desired_Wheel_Speed");
    __BL_Desired_Module_Angle__Entry = NTtable_TPoint->GetEntry("BL_Desired_Module_Angle");
    __Odometry_Y_global_est_ft__Entry = NTtable_TPoint->GetEntry("Odometry_Y_global_est_ft");
    __Odometry_Y_global_TEAR_ft__Entry = NTtable_TPoint->GetEntry("Odometry_Y_global_TEAR_ft");
    __Odometry_X_global_est_ft__Entry = NTtable_TPoint->GetEntry("Odometry_X_global_est_ft");
    __Odometry_X_global_TEAR_ft__Entry = NTtable_TPoint->GetEntry("Odometry_X_global_TEAR_ft");
    __Spline_Index__Entry = NTtable_TPoint->GetEntry("Spline_Index");
    __Spline_Target_Y__Entry = NTtable_TPoint->GetEntry("Spline_Target_Y");
    __Spline_Target_X__Entry = NTtable_TPoint->GetEntry("Spline_Target_X");
    __WhileIterator__Entry = NTtable_TPoint->GetEntry("WhileIterator");
    __Spline_Enable__Entry = NTtable_TPoint->GetEntry("Spline_Enable");
    __Is_Absolute_Translation_SPF__Entry = NTtable_TPoint->GetEntry("Is_Absolute_Translation_SPF");
    __Is_Absolute_Steering_SPF__Entry = NTtable_TPoint->GetEntry("Is_Absolute_Steering_SPF");
    __Robot_Reached_Destination__Entry = NTtable_TPoint->GetEntry("Robot_Reached_Destination");
    __Spline_Out_Of_Bounds__Entry = NTtable_TPoint->GetEntry("Spline_Out_Of_Bounds");
}
 
void SimulinkSmartDashboardInterface::SmartDashboardCallback() {
    // Inports
    __GameState__Entry.SetDouble(Code_Gen_Model_U.GameState);
    __Steer_Joystick_X__Entry.SetDouble(Code_Gen_Model_U.Steer_Joystick_X);
    __Steer_Joystick_Y__Entry.SetDouble(Code_Gen_Model_U.Steer_Joystick_Y);
    __Drive_Joystick_X__Entry.SetDouble(Code_Gen_Model_U.Drive_Joystick_X);
    __Drive_Joystick_Y__Entry.SetDouble(Code_Gen_Model_U.Drive_Joystick_Y);
    __Is_Boost_Trigger_Pulled__Entry.SetDouble(Code_Gen_Model_U.Is_Boost_Trigger_Pulled);
    __Gyro_Angle__Entry.SetDouble(Code_Gen_Model_U.Gyro_Angle);
    __FrontLeft_Drive_Motor_Speed__Entry.SetDouble(Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed);
    __FrontRight_Drive_Motor_Speed__Entry.SetDouble(Code_Gen_Model_U.FrontRight_Drive_Motor_Speed);
    __BackLeft_Drive_Motor_Speed__Entry.SetDouble(Code_Gen_Model_U.BackLeft_Drive_Motor_Speed);
    __BackRight_Drive_Motor_Speed__Entry.SetDouble(Code_Gen_Model_U.BackRight_Drive_Motor_Speed);
    __FrontLeft_Steer_Rev__Entry.SetDouble(Code_Gen_Model_U.FrontLeft_Steer_Rev);
    __FrontRight_Steer_Rev__Entry.SetDouble(Code_Gen_Model_U.FrontRight_Steer_Rev);
    __BackLeft_Steer_Rev__Entry.SetDouble(Code_Gen_Model_U.BackLeft_Steer_Rev);
    __BackRight_Steer_Rev__Entry.SetDouble(Code_Gen_Model_U.BackRight_Steer_Rev);
    __FrontLeft_Turn_Offset__Entry.SetDouble(Code_Gen_Model_U.FrontLeft_Turn_Offset);
    __FrontRight_Turn_Offset__Entry.SetDouble(Code_Gen_Model_U.FrontRight_Turn_Offset);
    __BackLeft_Turn_Offset__Entry.SetDouble(Code_Gen_Model_U.BackLeft_Turn_Offset);
    __BackRight_Turn_Offset__Entry.SetDouble(Code_Gen_Model_U.BackRight_Turn_Offset);
    __Is_Absolute_Steering__Entry.SetDouble(Code_Gen_Model_U.Is_Absolute_Steering);
    __Is_Absolute_Translation__Entry.SetDouble(Code_Gen_Model_U.Is_Absolute_Translation);
    __FrontLeft_Drive_Motor_Rev__Entry.SetDouble(Code_Gen_Model_U.FrontLeft_Drive_Motor_Rev);
    __FrontRight_Drive_Motor_Rev__Entry.SetDouble(Code_Gen_Model_U.FrontRight_Drive_Motor_Rev);
    __BackLeft_Drive_Motor_Rev__Entry.SetDouble(Code_Gen_Model_U.BackLeft_Drive_Motor_Rev);
    __BackRight_Drive_Motor_Rev__Entry.SetDouble(Code_Gen_Model_U.BackRight_Drive_Motor_Rev);
    // Outports
    __FrontLeft_Drive_DutyCycle__Entry.SetDouble(Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle);
    __FrontLeft_Steer_DutyCycle__Entry.SetDouble(Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle);
    __FrontRight_Drive_DutyCycle__Entry.SetDouble(Code_Gen_Model_Y.FrontRight_Drive_DutyCycle);
    __FrontRight_Steer_DutyCycle__Entry.SetDouble(Code_Gen_Model_Y.FrontRight_Steer_DutyCycle);
    __BackLeft_Drive_DutyCycle__Entry.SetDouble(Code_Gen_Model_Y.BackLeft_Drive_DutyCycle);
    __BackLeft_Steer_DutyCycle__Entry.SetDouble(Code_Gen_Model_Y.BackLeft_Steer_DutyCycle);
    __BackRight_Drive_DutyCycle__Entry.SetDouble(Code_Gen_Model_Y.BackRight_Drive_DutyCycle);
    __BackRight_Steer_DutyCycle__Entry.SetDouble(Code_Gen_Model_Y.BackRight_Steer_DutyCycle);
    // Test Points
    __FL_Steer_Module_Angle__Entry.SetDouble(Code_Gen_Model_B.FL_Steer_Module_Angle);
    __FR_Steer_Module_Angle__Entry.SetDouble(Code_Gen_Model_B.FR_Steer_Module_Angle);
    __BL_Steer_Module_Angle__Entry.SetDouble(Code_Gen_Model_B.BL_Steer_Module_Angle);
    __BR_Steer_Module_Angle__Entry.SetDouble(Code_Gen_Model_B.BR_Steer_Module_Angle);
    __Odom_Position_X_global__Entry.SetDouble(Code_Gen_Model_B.Odom_Position_X_global);
    __Odom_Position_Y_global__Entry.SetDouble(Code_Gen_Model_B.Odom_Position_Y_global);
    __Spline_Num_Poses__Entry.SetDouble(Code_Gen_Model_B.Spline_Num_Poses);
    __Steering_Abs_Cmd__Entry.SetDouble(Code_Gen_Model_B.Steering_Abs_Cmd);
    __Steering_Rel_Cmd__Entry.SetDouble(Code_Gen_Model_B.Steering_Rel_Cmd);
    __Translation_Speed__Entry.SetDouble(Code_Gen_Model_B.Translation_Speed);
    __Translation_Angle__Entry.SetDouble(Code_Gen_Model_B.Translation_Angle);
    __Translation_Speed_SPF__Entry.SetDouble(Code_Gen_Model_B.Translation_Speed_SPF);
    __Translation_Speed_RL__Entry.SetDouble(Code_Gen_Model_B.Translation_Speed_RL);
    __Translation_Angle_SPF__Entry.SetDouble(Code_Gen_Model_B.Translation_Angle_SPF);
    __Translation_Steering_Cmd__Entry.SetDouble(Code_Gen_Model_B.Translation_Steering_Cmd);
    __Steering_Rel_Cmd_SPF__Entry.SetDouble(Code_Gen_Model_B.Steering_Rel_Cmd_SPF);
    __Steering_Abs_Cmd_SPF__Entry.SetDouble(Code_Gen_Model_B.Steering_Abs_Cmd_SPF);
    __Gyro_Angle_Adjustment_SPF__Entry.SetDouble(Code_Gen_Model_B.Gyro_Angle_Adjustment_SPF);
    __Steering_Localized_PID__Entry.SetDouble(Code_Gen_Model_B.Steering_Localized_PID);
    __Steering_Localized_Cmd__Entry.SetDouble(Code_Gen_Model_B.Steering_Localized_Cmd);
    __Switch1__Entry.SetDouble(Code_Gen_Model_B.Switch1);
    __Switch1_m__Entry.SetDouble(Code_Gen_Model_B.Switch1_m);
    __Switch1_o__Entry.SetDouble(Code_Gen_Model_B.Switch1_o);
    __Switch1_p__Entry.SetDouble(Code_Gen_Model_B.Switch1_p);
    __BR_Desired_Wheel_Speed__Entry.SetDouble(Code_Gen_Model_B.BR_Desired_Wheel_Speed);
    __BR_Desired_Module_Angle__Entry.SetDouble(Code_Gen_Model_B.BR_Desired_Module_Angle);
    __FL_Desired_Wheel_Speed__Entry.SetDouble(Code_Gen_Model_B.FL_Desired_Wheel_Speed);
    __FL_Desired_Module_Angle__Entry.SetDouble(Code_Gen_Model_B.FL_Desired_Module_Angle);
    __FR_Desired_Wheel_Speed__Entry.SetDouble(Code_Gen_Model_B.FR_Desired_Wheel_Speed);
    __FR_Desired_Module_Angle__Entry.SetDouble(Code_Gen_Model_B.FR_Desired_Module_Angle);
    __BL_Desired_Wheel_Speed__Entry.SetDouble(Code_Gen_Model_B.BL_Desired_Wheel_Speed);
    __BL_Desired_Module_Angle__Entry.SetDouble(Code_Gen_Model_B.BL_Desired_Module_Angle);
    __Odometry_Y_global_est_ft__Entry.SetDouble(Code_Gen_Model_B.Odometry_Y_global_est_ft);
    __Odometry_Y_global_TEAR_ft__Entry.SetDouble(Code_Gen_Model_B.Odometry_Y_global_TEAR_ft);
    __Odometry_X_global_est_ft__Entry.SetDouble(Code_Gen_Model_B.Odometry_X_global_est_ft);
    __Odometry_X_global_TEAR_ft__Entry.SetDouble(Code_Gen_Model_B.Odometry_X_global_TEAR_ft);
    __Spline_Index__Entry.SetDouble(Code_Gen_Model_B.Spline_Index);
    __Spline_Target_Y__Entry.SetDouble(Code_Gen_Model_B.Spline_Target_Y);
    __Spline_Target_X__Entry.SetDouble(Code_Gen_Model_B.Spline_Target_X);
    __WhileIterator__Entry.SetDouble(Code_Gen_Model_B.WhileIterator);
    __Spline_Enable__Entry.SetDouble(Code_Gen_Model_B.Spline_Enable);
    __Is_Absolute_Translation_SPF__Entry.SetDouble(Code_Gen_Model_B.Is_Absolute_Translation_SPF);
    __Is_Absolute_Steering_SPF__Entry.SetDouble(Code_Gen_Model_B.Is_Absolute_Steering_SPF);
    __Robot_Reached_Destination__Entry.SetDouble(Code_Gen_Model_B.Robot_Reached_Destination);
    __Spline_Out_Of_Bounds__Entry.SetDouble(Code_Gen_Model_B.Spline_Out_Of_Bounds);
}
