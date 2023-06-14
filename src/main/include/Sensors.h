#pragma once

//AHRS
#include <AHRS.h>

class Sensors {
public:
    void PreStep();
    void PostStep();
private:
    AHRS m_AHRS{frc::SPI::Port::kMXP};
};