//local
#include "include/IMU.h"

void IMU::PreStep() {
    Code_Gen_Model_U.Gyro_Angle = m_Pigeon2.GetYaw().GetValue().value();
}

void IMU::PostStep() {}
void IMU::Reset() {
    m_Pigeon2.Reset();
}
IMU::IMU() {}