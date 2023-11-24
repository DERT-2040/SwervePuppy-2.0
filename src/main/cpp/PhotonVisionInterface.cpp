#include <include/PhotonVisionInterface.h>

PhotonVisionInterface::PhotonVisionInterface() {
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

void PhotonVisionInterface::updatePhotonVision() {
    photonlib::PhotonPipelineResult latestPipelineResult = camera.GetLatestResult();
    bool hasTargets = latestPipelineResult.HasTargets();

    // Clear the vectors to avoid double initialization
    distances.clear();
    yaws.clear();
    pitches.clear();
    fiducialIds.clear();
    poseAmbiguities.clear();

    if (hasTargets) {
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