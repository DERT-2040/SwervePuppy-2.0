#include "include/PhotonVisionInterface.h"

void PhotonVisionInterface::PreStep() {
    auto globalPose = PhotonVisionInterface::GetEstimatedGlobalPose();
    if (globalPose.has_value()) {
        robot2dPose = globalPose->estimatedPose.ToPose2d();
    }
}

void  PhotonVisionInterface::PostStep() {

}

void  PhotonVisionInterface::SmartDashboardCallback() {
    frc::SmartDashboard::PutNumber("Robot X", static_cast<double>(robot2dPose.X()));
    frc::SmartDashboard::PutNumber("Robot X", static_cast<double>(robot2dPose.Y()));
}

std::optional<photonlib::EstimatedRobotPose> PhotonVisionInterface::GetEstimatedGlobalPose() {
    auto visionEst = photonEstimator.Update();
    units::second_t latestTimestamp = camera.GetLatestResult().GetTimestamp();
    bool newResult =
    units::math::abs(latestTimestamp - lastEstTimestamp) > 1e-5_s;
    if (newResult) {
      lastEstTimestamp = latestTimestamp;
    }
    return visionEst;
}

 PhotonVisionInterface::PhotonVisionInterface() {
    photonEstimator.SetMultiTagFallbackStrategy(photonlib::PoseStrategy::LOWEST_AMBIGUITY);
}