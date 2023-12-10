#include <include/PhotonVisionInterface.h>

PhotonVisionInterface::PhotonVisionInterface() {
}

void PhotonVisionInterface::PreStep() {
    updatePhotonVision();
}

void PhotonVisionInterface::PostStep() {
    printFiducialIds();
}

const std::vector<double>& PhotonVisionInterface::getDistances() const{
    return distances;
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

const void PhotonVisionInterface::printFiducialIds() const {
    if (fiducialIds.size() > 0) {
        for(const auto& target : fiducialIds) {
            std::cout << target << std::endl;
        }
    }
}

const units::time::second_t PhotonVisionInterface::getCameraTimestamp() const {
    return timestamp;
}

const std::vector<double> PhotonVisionInterface::get3dTranslation() const {
    std::vector<double> translation{static_cast<double>(estimatedPose.X()), static_cast<double>(estimatedPose.Y()), static_cast<double>(estimatedPose.Z())};
    return translation;
}

const std::vector<double> PhotonVisionInterface::getRobotRotation() const {
    std::vector<double> rotation{static_cast<double>(estimatedPose.Rotation().X()), static_cast<double>(estimatedPose.Rotation().Y()), static_cast<double>(estimatedPose.Rotation().Z())};
    return rotation;
}

const std::vector<int> PhotonVisionInterface::getPoseTargetsFiducialIds() const {
    std::vector<int> listOfIds;
    for (const auto& target : poseTargets) {
        listOfIds.push_back(target.GetFiducialId());
    }
    return listOfIds;
}


void PhotonVisionInterface::updatePhotonVision() {
    photonlib::PhotonPipelineResult latestPipelineResult = poseEstimator.GetCamera().GetLatestResult();
    bool hasTargets = latestPipelineResult.HasTargets();

    // Clear the vectors to avoid double initialization
    distances.clear();
    yaws.clear();
    pitches.clear();
    fiducialIds.clear();
    poseAmbiguities.clear();

    if (hasTargets) {
        
        auto estimatedRobotPose = poseEstimator.Update(latestPipelineResult);
        if (estimatedRobotPose.has_value()) {
            estimatedPose = estimatedRobotPose.value().estimatedPose;
            timestamp = estimatedRobotPose.value().timestamp;
            poseTargets = estimatedRobotPose.value().targetsUsed;
        }
        const auto& photonVisionTrackedTargets = latestPipelineResult.GetTargets();

        // Populate the vectors with data from each detected target
        for (const auto& target : photonVisionTrackedTargets) {
            distances.push_back(static_cast<double>(photonlib::PhotonUtils::CalculateDistanceToTarget(
                CAMERA_HEIGHT, 
                targetHeight[static_cast<int>(target.GetFiducialId())], 
                CAMERA_PITCH, 
                units::degree_t{target.GetPitch()})));
            yaws.push_back(static_cast<double>(target.GetYaw()));
            pitches.push_back(static_cast<double>(target.GetPitch()));
            fiducialIds.push_back(static_cast<int>(target.GetFiducialId()));
            poseAmbiguities.push_back(static_cast<double>(target.GetPoseAmbiguity()));
        }
    }
}