#pragma once

//local
#include "include/Constants.h"
//frc
#include <frc/Joystick.h>
#include <frc/GenericHID.h>

class HIDs {
public:
    void PreStep();
    void PostStep();

    frc::GenericHID& Get_Gamepad() { return m_Gamepad; }
    frc::Joystick& Get_Drive_Joystick() { return m_Drive_Joystick; }
    frc::Joystick& Get_Steer_Joystick() { return m_Steer_Joystick; }
private:
  //HID Devices
    /**
     * @brief The gamepad used for robot implements.
     * Axis:
     *    0: Left X
     *    1: Left Y
     *    2: Left Trigger
     *    3: Right Trigger
     *    4: Right X
     *    5: Right Y
     * Buttons:
     *    1: A
     *    2: B
     *    3: X
     *    4: Y
     *    5: Left Bumper
     *    6: Right Bumper
     *    7: Back
     *    8: Start
     *    9: Left Joystick
     *    10: Right Joystick
     */
    frc::GenericHID m_Gamepad{Constants::k_Gamepad_Port};
    frc::Joystick m_Drive_Joystick{Constants::k_Drive_Joystick_Port};
    frc::Joystick m_Steer_Joystick{Constants::k_Steer_Joystick_Port};
};
