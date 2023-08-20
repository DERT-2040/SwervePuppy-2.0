//frc
#include <frc/smartdashboard/SmartDashboard.h>

class SmartDashboard {
public:
    SmartDashboard() {}
    void UpdateSDValues();
    void PollSDValues();
    void InitPolledSDValues();
private:
};