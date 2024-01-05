//local
#include "include\HIDs.h"

void HIDs::PreStep() {
    // Steer and Drive Joysticks
    Code_Gen_Model_U.Drive_Joystick_X = -m_Drive_Joystick.GetY();
    Code_Gen_Model_U.Drive_Joystick_Y = -m_Drive_Joystick.GetX();
    Code_Gen_Model_U.Steer_Joystick_X = -m_Steer_Joystick.GetY();
    Code_Gen_Model_U.Steer_Joystick_Y = -m_Steer_Joystick.GetX();

    // Gamepad Controller
    // Code_Gen_Model_U.Drive_Joystick_X = -m_Gamepad.GetRawAxis(1);
    // Code_Gen_Model_U.Drive_Joystick_Y = -m_Gamepad.GetRawAxis(0);
    // Code_Gen_Model_U.Steer_Joystick_X = -m_Gamepad.GetRawAxis(5);
    // Code_Gen_Model_U.Steer_Joystick_Y = -m_Gamepad.GetRawAxis(4);


    // Trigger
    Code_Gen_Model_U.Is_Boost_Trigger_Pulled = m_Drive_Joystick.GetRawButton(Constants::k_Boost_Trigger_Button);
}
void HIDs::PostStep() {}