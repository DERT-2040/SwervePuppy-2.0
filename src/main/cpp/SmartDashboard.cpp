//local
#include "include/SmartDashboard.h"
#include "Code_Gen_Model_ert_rtw\Code_Gen_Model.h"

void SmartDashboard::UpdateSDValues(){
        frc::SmartDashboard::PutNumber("FL_Steer_Encoder", Code_Gen_Model_U.FrontLeft_Steer_Encoder);
        frc::SmartDashboard::PutNumber("FR_Steer_Encoder", Code_Gen_Model_U.FrontRight_Steer_Encoder);
        frc::SmartDashboard::PutNumber("BL_Steer_Encoder", Code_Gen_Model_U.BackLeft_Steer_Encoder);
        frc::SmartDashboard::PutNumber("BR_Steer_Encoder", Code_Gen_Model_U.BackRight_Steer_Encoder);
        frc::SmartDashboard::PutNumber("FL_Steer_DC", Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle);
        frc::SmartDashboard::PutNumber("FR_Steer_DC", Code_Gen_Model_Y.FrontRight_Steer_DutyCycle);
        frc::SmartDashboard::PutNumber("BL_Steer_DC", Code_Gen_Model_Y.BackLeft_Steer_DutyCycle);
        frc::SmartDashboard::PutNumber("BR_Steer_DC", Code_Gen_Model_Y.BackRight_Steer_DutyCycle);
        frc::SmartDashboard::PutNumber("Optimized_Module_Angle", Code_Gen_Model_B.Optimized_Module_Angle);
        frc::SmartDashboard::PutNumber("Translation_Angle", Code_Gen_Model_B.Translation_Angle);
        frc::SmartDashboard::PutNumber("FL_Module_Angle", Code_Gen_Model_B.Desired_Module_Angle);
        frc::SmartDashboard::PutNumber("Steering_Localized_Cmd", Code_Gen_Model_B.Steering_Localized_Cmd);
        frc::SmartDashboard::PutNumber("Translation_Steering_Cmd", Code_Gen_Model_B.Translation_Steering_Cmd);
        frc::SmartDashboard::PutBoolean("Is_Absolute_Translation", Code_Gen_Model_U.Is_Absolute_Translation);
        frc::SmartDashboard::PutBoolean("Is_Absolute_Steering", Code_Gen_Model_U.Is_Absolute_Steering);
        frc::SmartDashboard::UpdateValues();
}
void SmartDashboard::PollSDValues() {
        // VARIABLE = frc::SmartDashboard::GetNumber("VARIABLE", VARIABLE);
        Steering_Heading_Control_P = frc::SmartDashboard::GetNumber("Steering_Heading_Control_P", 0);
        Steering_Heading_Control_I = frc::SmartDashboard::GetNumber("Steering_Heading_Control_I", 0);
        Steering_Heading_Control_I_UL = frc::SmartDashboard::GetNumber("Steering_Heading_Control_I_UL", 0);
        Steering_Heading_Control_D = frc::SmartDashboard::GetNumber("Steering_Heading_Control_D", 0);
        Steering_Heading_Control_D_UL = frc::SmartDashboard::GetNumber("Steering_Heading_Control_D_UL", 0);
        Steering_Heading_Control_Total_UL = frc::SmartDashboard::GetNumber("Steering_Heading_Control_Total_UL", 0);
        Steering_Heading_Control_Deadzone_Pos = frc::SmartDashboard::GetNumber("Steering_Heading_Control_Deadzone_Pos", 0);
        Steering_Heading_Control_I_LL = frc::SmartDashboard::GetNumber("Steering_Heading_Control_I_LL", 0);
        Steering_Heading_Control_D_LL = frc::SmartDashboard::GetNumber("Steering_Heading_Control_D_LL", 0);
        Steering_Heading_Control_Total_LL = frc::SmartDashboard::GetNumber("Steering_Heading_Control_Total_LL", 0);
        Steering_Heading_Control_Deadzone_Neg = frc::SmartDashboard::GetNumber("Steering_Heading_Control_Deadzone_Neg", 0);
}
void SmartDashboard::InitPolledSDValues() {
        // frc::SmartDashboard::PutNumber("VARIABLE", VARIABLE);
        frc::SmartDashboard::PutNumber("Steering_Heading_Control_P", Steering_Heading_Control_P);
        frc::SmartDashboard::PutNumber("Steering_Heading_Control_I", Steering_Heading_Control_I);
        frc::SmartDashboard::PutNumber("Steering_Heading_Control_I_UL", Steering_Heading_Control_I_UL);
        frc::SmartDashboard::PutNumber("Steering_Heading_Control_D", Steering_Heading_Control_D);
        frc::SmartDashboard::PutNumber("Steering_Heading_Control_D_UL", Steering_Heading_Control_D_UL);
        frc::SmartDashboard::PutNumber("Steering_Heading_Control_Total_UL", Steering_Heading_Control_Total_UL);
        frc::SmartDashboard::PutNumber("Steering_Heading_Control_Deadzone_Pos", Steering_Heading_Control_Deadzone_Pos);
        frc::SmartDashboard::PutNumber("Steering_Heading_Control_I_LL", Steering_Heading_Control_I_LL);
        frc::SmartDashboard::PutNumber("Steering_Heading_Control_D_LL", Steering_Heading_Control_D_LL);
        frc::SmartDashboard::PutNumber("Steering_Heading_Control_Total_LL", Steering_Heading_Control_Total_LL);
        frc::SmartDashboard::PutNumber("Steering_Heading_Control_Deadzone_Neg", Steering_Heading_Control_Deadzone_Neg);
}