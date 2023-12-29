#pragma once

//local
#include <include/Constants.h>
//crte
#include <ctre/phoenix6/Pigeon2.hpp>
//Simulink
#include "Code_Gen_Model_ert_rtw/Code_Gen_Model.h"


class IMU {
public:
    IMU();

    /**
     * See PreStep documentation in Robot.h
     */
    void PreStep();

    /**
     * See PostStep documentation in Robot.h
     */
    void PostStep();

    /**
     * Resets yaw zero
     */
    void Reset();
private:
    /**
     * Pigeon 2 IMU from CRTE
    */
    ctre::phoenix6::hardware::Pigeon2 m_Pigeon2{Constants::k_Pigeon2_Device_ID, static_cast<std::string>(Constants::k_Pigeon2_Device_Name)};
};