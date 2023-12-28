#include <include/PhotonVisionInterface.h>

PhotonVisionInterface::PhotonVisionInterface() {
}

void PhotonVisionInterface::PreStep() {
    updatePhotonVision();
}

void PhotonVisionInterface::PostStep() {
}

void PhotonVisionInterface::SmartDashboardCallback() {
    if (yaws.size() == 1) {
        frc::SmartDashboard::PutNumber(("yaw 1"), yaws.at(0));
    } else {
        frc::SmartDashboard::PutNumber(("yaw 1"), 0);
    }
    if (yaws.size() == 1) {
        frc::SmartDashboard::PutNumber(("yaw 2"), yaws.at(1));
    } else {
        frc::SmartDashboard::PutNumber(("yaw 2"), 0);
    }
    if (yaws.size() == 1) {
        frc::SmartDashboard::PutNumber(("yaw 3"), yaws.at(2));
    } else {
        frc::SmartDashboard::PutNumber(("yaw 3"), 0);
    }
    if (yaws.size() == 1) {
        frc::SmartDashboard::PutNumber(("yaw 4"), yaws.at(3));
    } else {
        frc::SmartDashboard::PutNumber(("yaw 4"), 0);
    }
    if (yaws.size() == 1) {
        frc::SmartDashboard::PutNumber(("yaw 5"), yaws.at(4));
    } else {
        frc::SmartDashboard::PutNumber(("yaw 5"), 0);
    }
    if (yaws.size() == 1) {
        frc::SmartDashboard::PutNumber(("yaw 6"), yaws.at(5));
    } else {
        frc::SmartDashboard::PutNumber(("yaw 6"), 0);
    }
    if (yaws.size() == 1) {
        frc::SmartDashboard::PutNumber(("yaw 7"), yaws.at(6));
    } else {
        frc::SmartDashboard::PutNumber(("yaw 7"), 0);
    }
    if (yaws.size() == 1) {
        frc::SmartDashboard::PutNumber(("yaw 8"), yaws.at(7));
    } else {
        frc::SmartDashboard::PutNumber(("yaw 8"), 0);
    }   
    frc::SmartDashboard::PutNumber("Robot X", estPose.X());
    frc::SmartDashBoard::PutNumber("Robot Y", estPose.Y());
}

const std::vector<double>& PhotonVisionInterface::getYaws() const {
    return yaws;
}

const std::vector<double>& PhotonVisionInterface::getPitches() const {
    return pitches;
}

const std::vector<int>& PhotonVisionInterface::getFiducialIds() const {
    return fiducialIds;
}

const std::vector<double>& PhotonVisionInterface::getPoseAmbiguities() const {
    return poseAmbiguities;
}

void PhotonVisionInterface::updatePhotonVision() {
    auto visionEst = vision.GetEstimatedGlobalPose();
    if (visionEst.has_value()) {
        auto est = visionEst.value();
        auto estPose = est.estimatedPose.ToPose2d();
        auto estStdDevs = vision.GetEstimationStdDevs(estPose);
        drivetrain.AddVisionMeasurement(est.estimatedPose.ToPose2d(), est.timestamp,
                                        estStdDevs);
    }
    photonlib::PhotonPipelineResult latestPipelineResult = photonEstimator.GetCamera().GetLatestResult();
    bool hasTargets = latestPipelineResult.HasTargets();

    // Clear the vectors to avoid double initialization
    yaws.clear();
    pitches.clear();
    fiducialIds.clear();
    poseAmbiguities.clear();

    if (hasTargets) {
        const auto& photonVisionTrackedTargets = latestPipelineResult.GetTargets();

        // Populate the vectors with data from each detected target
        for (const auto& target : photonVisionTrackedTargets) {
            yaws.push_back(static_cast<double>(target.GetYaw()));
            pitches.push_back(static_cast<double>(target.GetPitch()));
            fiducialIds.push_back(static_cast<int>(target.GetFiducialId()));
            poseAmbiguities.push_back(static_cast<double>(target.GetPoseAmbiguity()));
        }
    }
}