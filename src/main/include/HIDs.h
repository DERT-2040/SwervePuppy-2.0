#pragma once

//local
#include "include/Constants.h"
#include "Code_Gen_Model_ert_rtw\Code_Gen_Model.h"
//frc
#include <frc/Joystick.h>
#include <frc/GenericHID.h>
// #include <frc/XboxController.h>


class HIDs {
public:
    /**
     * See PreStep documentation in Robot.h
     */
    void PreStep();

    /**
     * See PostStep documentation in Robot.h
     */
    void PostStep();

    /**
     * returns a reference to the m_Gamepad Object
    */
    frc::GenericHID& Get_Gamepad() { return m_Gamepad; }

    /**
     * returns a reference to the m_XboxGamepad Object
    */
    // frc::GenericHID& Get_XboxGamepad() { return m_XboxGamepad; }

    /**
     * returns a reference to the m_Drive_Joystick Object
    */
    frc::GenericHID& Get_Drive_Joystick() { return m_Drive_Joystick; }

    /**
     * returns a reference to the m_Steer_Joystick Object
    */
    frc::GenericHID& Get_Steer_Joystick() { return m_Steer_Joystick; }
private:
    /**
     * The gamepad used for robot implements.
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

    /*
     * XBOX Controller
     */
    // frc::XboxController m_XboxGamepad{Constants::k_Gamepad_Port};

    /**
     * Joystick that is on the index of k_Drive_Joystick_Port
     */
    frc::Joystick m_Drive_Joystick{Constants::k_Drive_Joystick_Port};

    /**
     * Joystick that is on the index of k_Steer_Joystick_Port
     */
    frc::Joystick m_Steer_Joystick{Constants::k_Steer_Joystick_Port};
};
