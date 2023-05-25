// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include "Code_Gen_Model_ert_rtw\Code_Gen_Model.h"
#include <rev/CANSparkMax.h>
#include <frc/XboxController.h>
#include <frc/GenericHID.h>
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

  rev::CANSparkMax m_SparkMax;
  frc::XboxController m_Controller;
};
