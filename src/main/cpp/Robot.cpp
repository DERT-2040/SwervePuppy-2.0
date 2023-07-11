// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

//local
#include "include/Robot.h"
#include "Code_Gen_Model_ert_rtw\Code_Gen_Model.h"
//std
#include <iostream>

void Robot::RobotInit() {
  Code_Gen_Model_U.GameState = -1;
  Code_Gen_Model_initialize(); //code gen model init
  m_SwerveDrive.CoastMode(); //set all motors to coast mode
  m_SmartDashboard.InitPolledSDValues(); //init polled smart dashboard values
}
void Robot::RobotPeriodic() {
  if(Robot::m_HIDs.Get_Gamepad().GetRawButtonPressed(Constants::k_Reset_Wheel_Offset_Button)){
    m_SwerveDrive.Reset_Wheel_Offset();
    std::cout << "Wheel Offsets Reset" << std::endl;
  }
  
  if(Robot::m_HIDs.Get_Drive_Joystick().GetRawButtonPressed(Constants::k_Toggle_Absolute_Translation_Button)){
    m_SwerveDrive.Toggle_Absolute_Translation();
    std::cout << "Translation Method Toggled" << std::endl;
  }
  if(Robot::m_HIDs.Get_Steer_Joystick().GetRawButtonPressed(Constants::k_Toggle_Absolute_Steering_Button)){
    m_SwerveDrive.Toggle_Absolute_Steering();
    std::cout << "Steering Method Toggled" << std::endl;
  }
  PreStep(); //Robot wide PreStep
  Code_Gen_Model_step(); //Step the model
  PostStep(); //Robot wide PostStep
  m_SmartDashboard.PollSDValues(); //Poll Smart Dashboard Values

  if(Robot::m_HIDs.Get_Gamepad().GetRawButtonPressed(2)){
    m_IMU.Start_Gyro_Calibration();
  }
}

void Robot::AutonomousInit() { Code_Gen_Model_U.GameState = 1; }
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  Code_Gen_Model_U.GameState = 2;
  }
void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {
  Code_Gen_Model_U.GameState = 0;
  }
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {
  Code_Gen_Model_U.GameState = 3;
  }
void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}

void Robot::PreStep() {
  m_HIDs.PreStep();
  m_IMU.PreStep();
  m_SwerveDrive.PreStep();
}

void Robot::PostStep() {
  m_HIDs.PostStep();
  m_IMU.PostStep();
  m_SwerveDrive.PostStep();
  m_SmartDashboard.UpdateSDValues();
}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
