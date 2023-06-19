//local
#include "include/SwerveDrive.h"
#include "Code_Gen_Model_ert_rtw/Code_Gen_Model.h"

void SwerveDrive::PreStep() {
  //Drive Encoders
  Code_Gen_Model_U.FrontLeft_Drive_Encoder = m_FrontLeft_Drive_Encoder.GetVelocity();
  Code_Gen_Model_U.FrontRight_Drive_Encoder = m_FrontRight_Drive_Encoder.GetVelocity();
  Code_Gen_Model_U.BackLeft_Drive_Encoder = m_BackLeft_Drive_Encoder.GetVelocity();
  Code_Gen_Model_U.BackRight_Drive_Encoder = m_BackRight_Drive_Encoder.GetVelocity();
  //Steer Encoders
  Code_Gen_Model_U.FrontLeft_Steer_Encoder = m_FrontLeft_Steer_Encoder.GetAbsolutePosition();
  Code_Gen_Model_U.FrontRight_Steer_Encoder = m_FrontRight_Steer_Encoder.GetAbsolutePosition();
  Code_Gen_Model_U.BackLeft_Steer_Encoder = m_BackLeft_Steer_Encoder.GetAbsolutePosition();
  Code_Gen_Model_U.BackRight_Steer_Encoder = m_BackRight_Steer_Encoder.GetAbsolutePosition();
}
void SwerveDrive::PostStep() {
  //Drive Motors
    m_FrontLeft_Drive.Set(Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle);
    m_FrontRight_Drive.Set(Code_Gen_Model_Y.FrontRight_Drive_DutyCycle);
    m_BackLeft_Drive.Set(Code_Gen_Model_Y.BackLeft_Drive_DutyCycle);
    m_BackRight_Drive.Set(Code_Gen_Model_Y.BackRight_Drive_DutyCycle);
  //Steer Motors
    m_FrontLeft_Steer.Set(Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle);
    m_FrontRight_Steer.Set(Code_Gen_Model_Y.FrontRight_Steer_DutyCycle);
    m_BackLeft_Steer.Set(Code_Gen_Model_Y.BackLeft_Steer_DutyCycle);
    m_BackRight_Steer.Set(Code_Gen_Model_Y.BackRight_Steer_DutyCycle);
}
SwerveDrive::SwerveDrive() {
  //Drive Motors
    //Front Left
      m_FrontLeft_Drive.RestoreFactoryDefaults();
      m_FrontLeft_Drive.SetInverted(false);
      m_FrontLeft_Drive.SetSmartCurrentLimit(Constants::k_Drive_Motor_Smart_Current_Limit);
      m_FrontLeft_Drive.SetSecondaryCurrentLimit(Constants::k_Drive_Motor_Secondary_Current_Limit);
      m_FrontLeft_Drive.SetOpenLoopRampRate(Constants::k_Drive_Motor_Open_Loop_Ramp_Rate);
    //Front Right
      m_FrontRight_Drive.RestoreFactoryDefaults();
      m_FrontRight_Drive.SetInverted(false);
      m_FrontRight_Drive.SetSmartCurrentLimit(Constants::k_Drive_Motor_Smart_Current_Limit);
      m_FrontRight_Drive.SetSecondaryCurrentLimit(Constants::k_Drive_Motor_Secondary_Current_Limit);
      m_FrontRight_Drive.SetOpenLoopRampRate(Constants::k_Drive_Motor_Open_Loop_Ramp_Rate);
    //Back Left
      m_BackLeft_Drive.RestoreFactoryDefaults();
      m_BackLeft_Drive.SetInverted(false);
      m_BackLeft_Drive.SetSmartCurrentLimit(Constants::k_Drive_Motor_Smart_Current_Limit);
      m_BackLeft_Drive.SetSecondaryCurrentLimit(Constants::k_Drive_Motor_Secondary_Current_Limit);
      m_BackLeft_Drive.SetOpenLoopRampRate(Constants::k_Drive_Motor_Open_Loop_Ramp_Rate);
    //Back Right
      m_BackRight_Drive.RestoreFactoryDefaults();
      m_BackRight_Drive.SetInverted(false);
      m_BackRight_Drive.SetSmartCurrentLimit(Constants::k_Drive_Motor_Smart_Current_Limit);
      m_BackRight_Drive.SetSecondaryCurrentLimit(Constants::k_Drive_Motor_Secondary_Current_Limit);
      m_BackRight_Drive.SetOpenLoopRampRate(Constants::k_Drive_Motor_Open_Loop_Ramp_Rate);
  //Steer Motors
    //Front Left
      m_FrontLeft_Steer.RestoreFactoryDefaults();
      m_FrontLeft_Steer.SetInverted(false);
      m_FrontLeft_Steer.SetSmartCurrentLimit(Constants::k_Steer_Motor_Smart_Current_Limit);
      m_FrontLeft_Steer.SetSecondaryCurrentLimit(Constants::k_Steer_Motor_Secondary_Current_Limit);
      m_FrontLeft_Steer.SetOpenLoopRampRate(Constants::k_Steer_Motor_Open_Loop_Ramp_Rate);
    //Front Right
      m_FrontRight_Steer.RestoreFactoryDefaults();
      m_FrontRight_Steer.SetInverted(false);
      m_FrontRight_Steer.SetSmartCurrentLimit(Constants::k_Steer_Motor_Smart_Current_Limit);
      m_FrontRight_Steer.SetSecondaryCurrentLimit(Constants::k_Steer_Motor_Secondary_Current_Limit);
      m_FrontRight_Steer.SetOpenLoopRampRate(Constants::k_Steer_Motor_Open_Loop_Ramp_Rate);
    //Back Left
      m_BackLeft_Steer.RestoreFactoryDefaults();
      m_BackLeft_Steer.SetInverted(false);
      m_BackLeft_Steer.SetSmartCurrentLimit(Constants::k_Steer_Motor_Smart_Current_Limit);
      m_BackLeft_Steer.SetSecondaryCurrentLimit(Constants::k_Steer_Motor_Secondary_Current_Limit);
      m_BackLeft_Steer.SetOpenLoopRampRate(Constants::k_Steer_Motor_Open_Loop_Ramp_Rate);
    //Back Right
      m_BackRight_Steer.RestoreFactoryDefaults();
      m_BackRight_Steer.SetInverted(false);
      m_BackRight_Steer.SetSmartCurrentLimit(Constants::k_Steer_Motor_Smart_Current_Limit);
      m_BackRight_Steer.SetSecondaryCurrentLimit(Constants::k_Steer_Motor_Secondary_Current_Limit);
      m_BackRight_Steer.SetOpenLoopRampRate(Constants::k_Steer_Motor_Open_Loop_Ramp_Rate);
  //States
    Code_Gen_Model_U.Is_Absolute_Steering = false;
    Code_Gen_Model_U.Is_Absolute_Translation = true;
  //Wheel Offset
    SwerveDrive::Initalize_Wheel_Offset();
}
void SwerveDrive::BreakMode() {
  //Drive Motors
  m_FrontLeft_Drive.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_FrontRight_Drive.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_BackLeft_Drive.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_BackRight_Drive.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  //Steer Motors
  m_FrontLeft_Steer.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_FrontRight_Steer.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_BackLeft_Steer.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
  m_BackRight_Steer.SetIdleMode(rev::CANSparkMax::IdleMode::kBrake);
}

void SwerveDrive::CoastMode() {
  //Drive Motors
  m_FrontLeft_Drive.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_FrontRight_Drive.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_BackLeft_Drive.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_BackRight_Drive.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  //Steer Motors
  m_FrontLeft_Steer.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_FrontRight_Steer.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_BackLeft_Steer.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
  m_BackRight_Steer.SetIdleMode(rev::CANSparkMax::IdleMode::kCoast);
}

void SwerveDrive::Toggle_Absolute_Translation() {
  Code_Gen_Model_U.Is_Absolute_Translation = !Code_Gen_Model_U.Is_Absolute_Translation;
}

void SwerveDrive::Toggle_Absolute_Steering() {
  Code_Gen_Model_U.Is_Absolute_Steering = !Code_Gen_Model_U.Is_Absolute_Steering;
}

void SwerveDrive::Initalize_Wheel_Offset() {
  if(!frc::Preferences::ContainsKey(Constants::k_FrontLeft_Wheel_Offset_Key))
    frc::Preferences::SetDouble(Constants::k_FrontLeft_Wheel_Offset_Key, 0.0);
  if(!frc::Preferences::ContainsKey(Constants::k_FrontRight_Wheel_Offset_Key))
    frc::Preferences::SetDouble(Constants::k_FrontRight_Wheel_Offset_Key, 0.0);
  if(!frc::Preferences::ContainsKey(Constants::k_BackLeft_Wheel_Offset_Key))
    frc::Preferences::SetDouble(Constants::k_BackLeft_Wheel_Offset_Key, 0.0);
  if(!frc::Preferences::ContainsKey(Constants::k_BackRight_Wheel_Offset_Key))
    frc::Preferences::SetDouble(Constants::k_BackRight_Wheel_Offset_Key, 0.0);
  SwerveDrive::Set_Wheel_Offset();
}

void SwerveDrive::Reset_Wheel_Offset() {
  frc::Preferences::SetDouble(Constants::k_FrontLeft_Wheel_Offset_Key, m_FrontLeft_Steer.GetEncoder().GetPosition());
  frc::Preferences::SetDouble(Constants::k_FrontRight_Wheel_Offset_Key, m_FrontRight_Steer.GetEncoder().GetPosition());
  frc::Preferences::SetDouble(Constants::k_BackLeft_Wheel_Offset_Key, m_BackLeft_Steer.GetEncoder().GetPosition());
  frc::Preferences::SetDouble(Constants::k_BackRight_Wheel_Offset_Key, m_BackRight_Steer.GetEncoder().GetPosition());
  SwerveDrive::Set_Wheel_Offset();
}

void SwerveDrive::Set_Wheel_Offset() {
  Code_Gen_Model_U.BackLeft_Turn_Offset = frc::Preferences::GetDouble(Constants::k_BackLeft_Wheel_Offset_Key, 0.0);
  Code_Gen_Model_U.BackRight_Turn_Offset = frc::Preferences::GetDouble(Constants::k_BackRight_Wheel_Offset_Key, 0.0);
  Code_Gen_Model_U.FrontLeft_Turn_Offset = frc::Preferences::GetDouble(Constants::k_FrontLeft_Wheel_Offset_Key, 0.0);
  Code_Gen_Model_U.FrontRight_Turn_Offset = frc::Preferences::GetDouble(Constants::k_FrontRight_Wheel_Offset_Key, 0.0);
}