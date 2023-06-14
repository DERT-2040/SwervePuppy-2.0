// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

//local
#include "Code_Gen_Model_ert_rtw\Code_Gen_Model.h"
#include "include/HIDs.h"
#include "include/Sensors.h"
#include "include/SwerveDrive.h"
//frc
#include <frc/TimedRobot.h>
#include <frc/event/EventLoop.h>
#include <frc/event/BooleanEvent.h>

class Robot : public frc::TimedRobot {
 public:
  Robot();
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
  
  void BindEvents();

  HIDs m_HIDs;
  Sensors m_Sensors;
  SwerveDrive m_SwerveDrive;
  frc::EventLoop m_EventLoop;
};
