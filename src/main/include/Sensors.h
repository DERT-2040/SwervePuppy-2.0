#pragma once

//AHRS
#include <AHRS.h>

class Sensors {
public:
    Sensors();
    void PreStep();
    void PostStep();
private:
    AHRS m_AHRS{frc::SPI::Port::kMXP};
};