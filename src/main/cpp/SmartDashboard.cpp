//local
#include "include/SmartDashboard.h"
#include "Code_Gen_Model_ert_rtw\Code_Gen_Model.h"

void SmartDashboard::UpdateSDValues(){       
        frc::SmartDashboard::UpdateValues();
}
void SmartDashboard::PollSDValues() {
        // VARIABLE = frc::SmartDashboard::GetNumber("VARIABLE", SAFEDEFAULT_VALUE);
}
void SmartDashboard::InitPolledSDValues() {
        // frc::SmartDashboard::PutNumber("VARIABLE", VARIABLE);
}