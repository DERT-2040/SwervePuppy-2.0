//local
#include "include/SmartDashboard.h"
#include "Code_Gen_Model_ert_rtw\Code_Gen_Model.h"

void SmartDashboard::UpdateSDValues(){
        frc::SmartDashboard::PutNumber("Raw_Gyro", Code_Gen_Model_U.Gyro_Angle);
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
        frc::SmartDashboard::PutBoolean("Is_Boost_Trigger_Pulled", Code_Gen_Model_U.Is_Boost_Trigger_Pulled);
        frc::SmartDashboard::UpdateValues();
}
void SmartDashboard::PollSDValues() {
        // VARIABLE = frc::SmartDashboard::GetNumber("VARIABLE", SAFEDEFAULT_VALUE);
        Boost_Trigger_Increasing_Limit = frc::SmartDashboard::GetNumber("Boost_Trigger_Increasing_Limit", 0);
        Boost_Trigger_Decreasing_Limit = frc::SmartDashboard::GetNumber("Boost_Trigger_Decreasing_Limit", 0);
        Translation_Speed_Rate_Limit_Inc = frc::SmartDashboard::GetNumber("Translation_Speed_Rate_Limit_Inc", 0);
        Translation_Speed_Rate_Limit_Dec = frc::SmartDashboard::GetNumber("Translation_Speed_Rate_Limit_Dec", 0);

}
void SmartDashboard::InitPolledSDValues() {
        // frc::SmartDashboard::PutNumber("VARIABLE", VARIABLE);
     frc::SmartDashboard::PutNumber("Boost_Trigger_Increasing_Limit", Boost_Trigger_Increasing_Limit);
     frc::SmartDashboard::PutNumber("Boost_Trigger_Decreasing_Limit", Boost_Trigger_Decreasing_Limit);
     frc::SmartDashboard::PutNumber("Translation_Speed_Rate_Limit_Inc", Translation_Speed_Rate_Limit_Inc);
     frc::SmartDashboard::PutNumber("Translation_Speed_Rate_Limit_Dec", Translation_Speed_Rate_Limit_Dec);
}