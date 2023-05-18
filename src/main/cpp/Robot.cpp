// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "include/Robot.h"

#include <rev/CANSparkMax.h>

#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>

//simulink include
#include <code_gen_model_ert_rtw/code_gen_model.h>

#include <frc/GenericHID.h>
#include <frc/XboxController.h>

#include <iostream>

//vars
static code_gen_model simulinkModel; //initalizes the object for simulink code

static constexpr int positiveAxisIndex = 3; //right trigger controller axis input
static constexpr int negitiveAxisIndex = 2; //left trigger controller axis input

static frc::XboxController controller(0); //controller object

//static rev::CANSparkMax motor(30, rev::CANSparkMaxLowLevel::MotorType::kBrushless); //only motor object

static code_gen_model::ExtU_code_gen_model_T in; //input struct for code_gen_model

int Game_State;


void Robot::RobotInit() {
  Game_State = -1; //disabled game state
  simulinkModel.initialize();

//init led
  m_led.SetLength(kLength);
  m_led.SetData(m_ledBuffer);
  m_led.Start();
//chooser
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  UniversalStep();
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  Game_State = 0; // auto game state
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  UniversalStep();
}

void Robot::TeleopInit() {
  Game_State = -1;//FIX
}

void Robot::TeleopPeriodic() {
  UniversalStep();
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

void Robot::UniversalStep() {
  //inputs
  in.Game_State = Game_State;
  in.Trigger_val_p = controller.GetRawAxis(positiveAxisIndex);
  in.Trigger_val_n = controller.GetRawAxis(negitiveAxisIndex);
  simulinkModel.setExternalInputs(&in);
  for(int i = 0; i < kLength; i++)
    m_ledBuffer[i].SetHSV(simulinkModel.getExternalOutputs().LED_Array[i], 255, 127);
  m_led.SetData(m_ledBuffer);
  //step
  simulinkModel.step();
  //outputs
  //motor.Set(simulinkModel.getExternalOutputs().Motor_speed);
}
#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
