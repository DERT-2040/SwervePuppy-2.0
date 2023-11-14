#include <include/PhotonVisionInterface.h>

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

const units::length::meter_t PhotonVisionInterface::determineTargetHeight(int fiducialId) const {
    // Define a mapping or lookup for fiducial IDs to tag heights
    std::unordered_map<int, units::length::meter_t> fiducialIdToHeight = {
    //Target hights in meters for each corresponding id
    {1, 0.462788_m}, 
    {2, 0.462788_m},
    {3, 0.462788_m},
    {4, 0.695452_m},
    {5, 0.695452_m},
    {6, 0.462788_m},
    {7, 0.462788_m},
    {8, 0.462788_m}
};

    // Use the fiducial ID to look up the corresponding height
    auto heightIterator = fiducialIdToHeight.find(fiducialId);
    if (heightIterator != fiducialIdToHeight.end()) {
        return heightIterator->second;
    } else {
        // Handle the case where the fiducial ID is not found
        // You might want to return a default value, throw an exception, or handle it accordingly.
        // Here, I'm returning a default value of 0 meters; replace it with your specific logic.
        return 0.0_m;
    }
}

void PhotonVisionInterface::updatePhotonVisionPipeline() {
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
                PhotonVisionInterface::determineTargetHeight(target.GetFiducialId()), 
                CAMERA_PITCH, 
                units::degree_t{target.GetPitch()})));
            yaws.push_back(static_cast<double>(target.GetYaw()));
            pitches.push_back(static_cast<double>(target.GetPitch()));
            fiducialIds.push_back(static_cast<double>(target.GetFiducialId()));
            poseAmbiguities.push_back(static_cast<double>(target.GetPoseAmbiguity()));
        }
    }
}