#pragma once

//local
#include "include/Constants.h"
//frc
#include <frc/DutyCycleEncoder.h>
#include <frc/Preferences.h>
//rev
#include <rev/CANSparkMax.h>
#include <rev/SparkMaxRelativeEncoder.h>

class SwerveDrive {
public:
    SwerveDrive();
    /**
     * See GameInitValues documentation in Robot.h
     */
    void GameInitValues();

    /**
     * See PreStep documentation in Robot.h
     */
    void PreStep();

    /**
     * See PostStep documentation in Robot.h
     */
    void PostStep();

    /**
     * Sets all motors in swerve drive to Brake mode
     * @warning do not use frequently, takes a lot of time and can overrun loop
    */
    void BrakeMode();

    /**
     * Sets all motors in swerve drive to coast mode
     * @warning do not use frequently, takes a lot of time and can overrun loop
    */
    void CoastMode();

    /**
     * Toggles the robot's driving controls from relative to field oriented and vise versa
     */
    void Toggle_Absolute_Translation();

    /**
     * Toggles the robot's steering controls from relative to field oriented and vise versa
     */
    void Toggle_Absolute_Steering();

    /**
     * Creates the wheel offset preferences if they have not been created
     */
    void Initalize_Wheel_Offset();

    /**
     * Sets the wheel offset preferences to whatever the sensors read are when the function is called
     */
    void Reset_Wheel_Offset();

    /**
     * Sets the simulink variables for wheel offsets to what is in the robot preferences
     */
    void Set_Wheel_Offset();

    /**
     * Enables commands to be able to go to the wheel motors
     */
    void WheelsOn();

    /**
     * Disables commands from being able to go to the wheel motors
     */
    void WheelsOff();
private:
  //Drive Motors
    rev::CANSparkMax m_FrontLeft_Drive{Constants::k_FrontLeft_Drive_CANID, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_FrontRight_Drive{Constants::k_FrontRight_Drive_CANID, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_BackLeft_Drive{Constants::k_BackLeft_Drive_CANID, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_BackRight_Drive{Constants::k_BackRight_Drive_CANID, rev::CANSparkMax::MotorType::kBrushless};
  //Steer Motors
    rev::CANSparkMax m_FrontLeft_Steer{Constants::k_FrontLeft_Steer_CANID, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_FrontRight_Steer{Constants::k_FrontRight_Steer_CANID, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_BackLeft_Steer{Constants::k_BackLeft_Steer_CANID, rev::CANSparkMax::MotorType::kBrushless};
    rev::CANSparkMax m_BackRight_Steer{Constants::k_BackRight_Steer_CANID, rev::CANSparkMax::MotorType::kBrushless};
  //Drive Encoders
    rev::SparkMaxRelativeEncoder m_FrontLeft_Drive_Encoder{m_FrontLeft_Drive.GetEncoder()};
    rev::SparkMaxRelativeEncoder m_FrontRight_Drive_Encoder{m_FrontRight_Drive.GetEncoder()};
    rev::SparkMaxRelativeEncoder m_BackLeft_Drive_Encoder{m_BackLeft_Drive.GetEncoder()};
    rev::SparkMaxRelativeEncoder m_BackRight_Drive_Encoder{m_BackRight_Drive.GetEncoder()};
  //Steer Encoders
    frc::DutyCycleEncoder m_FrontLeft_Steer_Encoder{Constants::k_FrontLeft_Steer_Encoder_Port};
    frc::DutyCycleEncoder m_FrontRight_Steer_Encoder{Constants::k_FrontRight_Steer_Encoder_Port};
    frc::DutyCycleEncoder m_BackLeft_Steer_Encoder{Constants::k_BackLeft_Steer_Encoder_Port};
    frc::DutyCycleEncoder m_BackRight_Steer_Encoder{Constants::k_BackRight_Steer_Encoder_Port};
  //Motor States
    /**
     * if true, commands can not be sent to the wheel motors
     * edited by:
     *  * WheelsOn()
     *  * WheelsOff()
     */
    bool AreMotorsDisabled = false;
};