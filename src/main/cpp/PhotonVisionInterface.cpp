#include "include/PhotonVisionInterface.h"

void PhotonVisionInterface::PreStep() {
    auto globalPose = photonEstimator.Update();
    if (globalPose.has_value()) {
        robot2dPose = globalPose->estimatedPose.ToPose2d();
        frc::SmartDashboard::PutNumber("RobotX", static_cast<double>(robot2dPose.X()));
        frc::SmartDashboard::PutNumber("RobotY", static_cast<double>(robot2dPose.Y()));
    }
}

void PhotonVisionInterface::PostStep() {

}

void PhotonVisionInterface::SmartDashboardCallback() {
}

frc::Pose2d PhotonVisionInterface::GetEstimatedGlobalPose() {
    return robot2dPose;
}

 PhotonVisionInterface::PhotonVisionInterface() {
    photonEstimator.SetMultiTagFallbackStrategy(photonlib::PoseStrategy::LOWEST_AMBIGUITY);
}