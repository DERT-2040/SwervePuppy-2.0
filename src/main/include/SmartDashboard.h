//frc
#include <frc/smartdashboard/SmartDashboard.h>

class SmartDashboard {
public:
    SmartDashboard() {}

    /**
     * update all smartdashboard values
     */
    void UpdateSDValues();

    /**
     * Retrive data from smartdashboard and put those values into simulink
     */
    void PollSDValues();

    /**
     * Create tunable values on smartdashboard
     */
    void InitPolledSDValues();
};