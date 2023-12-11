//frc
#include <vector>
#include <frc/smartdashboard/SmartDashboard.h>
#include "Code_Gen_Model_ert_rtw\Code_Gen_Model.h"
#include "include\PhotonVisionInterface.h"
#include <vector>
#include <functional>

class SmartDashboard {
public:
    SmartDashboard() {}

    /**
     * update all smartdashboard values
     */
    void UpdateSDValues();

    void BindSmartDashboardCallback(std::function<void()> callback);

private:
    std::vector<std::function<void()>> vectorOfCallbacks;
};
