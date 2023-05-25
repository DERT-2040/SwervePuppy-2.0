// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "include/Robot.h"

void Robot::RobotInit() {
  Code_Gen_Model_initialize(); //code gen model init
}
void Robot::RobotPeriodic() {
  PreStep();
  Code_Gen_Model_step();
  PostStep();
}

void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}

void Robot::PreStep() {
  Code_Gen_Model_U.A_Button = m_Controller.GetRawButton(1);
}

void Robot::PostStep() {
  m_SparkMax.Set(Code_Gen_Model_Y.m_Motor);
}

Robot::Robot() :
  m_SparkMax(30, rev::CANSparkMaxLowLevel::MotorType::kBrushless),
  m_Controller(0)
{}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
