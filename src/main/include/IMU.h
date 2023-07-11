#pragma once

//AHRS
#include <AHRS.h>

class IMU {
public:
    IMU();
    void PreStep();
    void PostStep();
    void Start_Gyro_Calibration();
private:
    AHRS m_AHRS{frc::SPI::Port::kMXP};
    void Gyro_Drift_Calibrate();
    double Get_Gyro_Angle();
    void Initialize();

    double Accumulated_Gyro_Error = 0;

    int Num_Samples = 0;
    double Last_Sample = -1;
    double Sum_Of_Deltas = 0;
    bool Is_Sampling = false;
    double Gyro_Drift = 0;
    double Current_Sample = 0;
    double Delta = 0;
};