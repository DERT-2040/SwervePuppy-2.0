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

    void PreStep();
    void PostStep();

    void BreakMode();
    void CoastMode();

    void Toggle_Absolute_Translation();
    void Toggle_Absolute_Steering();

    void Initalize_Wheel_Offset();
    void Reset_Wheel_Offset();
    void Set_Wheel_Offset();
    
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
};

