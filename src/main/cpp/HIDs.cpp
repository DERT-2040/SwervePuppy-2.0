//local
#include "include\HIDs.h"
#include "Code_Gen_Model_ert_rtw\Code_Gen_Model.h"
//FRC
#include <frc/event/BooleanEvent.h>

void HIDs::PreStep() {
    // Steer and Drive Joysticks
    Code_Gen_Model_U.Drive_Joystick_X = -m_Drive_Joystick.GetY();
    Code_Gen_Model_U.Drive_Joystick_Y = -m_Drive_Joystick.GetX();
    Code_Gen_Model_U.Steer_Joystick_X = -m_Steer_Joystick.GetY();
    Code_Gen_Model_U.Steer_Joystick_Y = -m_Steer_Joystick.GetX();

    // XBOX Controller
    // Code_Gen_Model_U.Drive_Joystick_X = -m_XboxGamepad.GetLeftY();
    // Code_Gen_Model_U.Drive_Joystick_Y = -m_XboxGamepad.GetLeftX();
    // Code_Gen_Model_U.Steer_Joystick_X = -m_XboxGamepad.GetRightY();
    // Code_Gen_Model_U.Steer_Joystick_Y = -m_XboxGamepad.GetRightX();

    // Trigger
    Code_Gen_Model_U.Is_Boost_Trigger_Pulled = m_Drive_Joystick.GetRawButton(Constants::k_Boost_Trigger_Button);
}
void HIDs::PostStep() {}