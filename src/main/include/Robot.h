// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

//local
#include "Code_Gen_Model_ert_rtw\Code_Gen_Model.h"
#include "include/HIDs.h"
#include "include/IMU.h"
#include "include/SwerveDrive.h"
#include "include/SmartDashboard.h"
//frc
#include <frc/TimedRobot.h>
#include <frc/event/EventLoop.h>
#include <frc/event/BooleanEvent.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  void SimulationInit() override;
  void SimulationPeriodic() override;

private:
  void PreStep();
  void PostStep();
  
  /**
   * @brief BindEvents binds all events to the event loop.
   * This is all sensors or HIDs that need to be polled
   */
  void BindEvents();

  /*
   * Below are the instances of the subsystems used by the robot
   * Everything here should be direct hardware control, only
   * functions that manipulate global variables declared by Simulink
   * are exceptions to this rule.
   */
  HIDs m_HIDs;
  IMU m_IMU;
  SwerveDrive m_SwerveDrive;
  frc::EventLoop m_EventLoop;
  SmartDashboard m_SmartDashboard;
};
