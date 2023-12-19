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
    Code_Gen_Model_U.Gyro_Angle = m_Pigeon2.GetYaw().GetValue().value();
}

void IMU::PostStep() {}
void IMU::Reset() {
    m_Pigeon2.Reset();
}
IMU::IMU() {}