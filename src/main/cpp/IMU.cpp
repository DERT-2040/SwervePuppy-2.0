//local
#include "include/IMU.h"
#include "Code_Gen_Model_ert_rtw/Code_Gen_Model.h"
#include "include/Constants.h"

//frc
#include <frc/Preferences.h>

//std
#include <iostream>
#include <iomanip>

void IMU::PreStep() {
    Accumulated_Gyro_Error -= Gyro_Drift;
    Gyro_Drift_Calibrate();
    // Code_Gen_Model_U.Gyro_Angle = Get_Gyro_Angle();
    Code_Gen_Model_U.Gyro_Angle = m_AHRS.GetAngle();
}

void IMU::PostStep() {}

void IMU::Start_Gyro_Calibration() {
    std::cout << "Gyro Drift Calibration Started" << std::endl;
    Is_Sampling = true;
    Num_Samples = 0;
    Last_Sample = m_AHRS.GetAngle();
    Sum_Of_Deltas = 0;
}

void IMU::Gyro_Drift_Calibrate() {
    if(Is_Sampling) {
        Current_Sample = m_AHRS.GetAngle();
        Delta = Current_Sample - Last_Sample;
        Last_Sample = Current_Sample;
        Sum_Of_Deltas += Delta;
        Num_Samples++;
        if(Num_Samples >= Constants::k_IMU_Calibration_Sample_Count) {
            Is_Sampling = false;
            Gyro_Drift = Sum_Of_Deltas / Num_Samples;
            frc::Preferences::SetDouble(Constants::k_Gyro_Drift_Offset_Key, Gyro_Drift);
            std::cout << "Gyro Drift Done Calibrating, total = " << Sum_Of_Deltas << std::endl;
        }
    }
}

double IMU::Get_Gyro_Angle() {
    return m_AHRS.GetAngle() + Accumulated_Gyro_Error;
}

IMU::IMU() {
    if(!frc::Preferences::ContainsKey(Constants::k_Gyro_Drift_Offset_Key))
        frc::Preferences::SetDouble(Constants::k_Gyro_Drift_Offset_Key, 0.0);
    Gyro_Drift = frc::Preferences::GetDouble(Constants::k_Gyro_Drift_Offset_Key, 0.0);
    std::cout << std::setprecision(15) << Gyro_Drift  << std::endl;
}