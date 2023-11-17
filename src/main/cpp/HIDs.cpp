//local
#include "include\HIDs.h"
#include "Code_Gen_Model_ert_rtw\Code_Gen_Model.h"
//FRC
#include <frc/event/BooleanEvent.h>

void HIDs::PreStep() {
    Code_Gen_Model_U.Drive_Joystick_X = m_Drive_Joystick.GetX();
    Code_Gen_Model_U.Drive_Joystick_Y = -m_Drive_Joystick.GetY();
    Code_Gen_Model_U.Steer_Joystick_X = m_Steer_Joystick.GetX();
    Code_Gen_Model_U.Steer_Joystick_Y = -m_Steer_Joystick.GetY();
}

void HIDs::PostStep() {

}