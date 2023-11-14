#pragma once
#include <photonlib/PhotonUtils.h>
#include <photonlib/PhotonCamera.h>
#include <unordered_map>

class PhotonVisionInterface {
public:
    // This method should be called each tick of the Rio to send new data to Simulink
    void updatePhotonVisionPipeline();
    // Methods to return the vectors
    const std::vector<double>& getDistances() const;

    const std::vector<double>& getYaws() const;

    const std::vector<double>& getPitches() const;

    const std::vector<int>& getFiducialIds() const;
    /**
     * @brief Returns confidence factor [0, 1] of the targets
    */
    const std::vector<double>& getPoseAmbiguities() const;

    const units::length::meter_t determineTargetHeight(int fiducialId) const;

private:
    // Makes PhotonCamera Object
    photonlib::PhotonCamera camera{"photonvision"};
    // Member variables to store data for each detected target
    std::vector<double> distances;
    std::vector<double> yaws;
    std::vector<double> pitches;
    std::vector<int> fiducialIds;
    std::vector<double> poseAmbiguities;
    // Constants with preset values
    static constexpr units::meter_t CAMERA_HEIGHT{1.0}; // meters
    static constexpr units::degree_t CAMERA_PITCH{1.0}; // degrees
};