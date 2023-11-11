#pragma once

//local
#include <include/Constants.h>
//crte
#include <ctre/phoenix6/Pigeon2.hpp>

class IMU {
public:
    IMU();
    void PreStep();
    void PostStep();
private:
    ctre::phoenix6::hardware::Pigeon2 m_Pigeon2{Constants::k_Pigeon2_Device_ID, static_cast<std::string>(Constants::k_Pigeon2_Device_Name)};
};