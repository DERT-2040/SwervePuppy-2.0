// local
#include "include/Sensors.h"
#include "Code_Gen_Model_ert_rtw/Code_Gen_Model.h"

void Sensors::PreStep() {
    Code_Gen_Model_U.Gyro_Angle = m_AHRS.GetAngle();
}
void Sensors::PostStep() {
    
}
Sensors::Sensors() {}