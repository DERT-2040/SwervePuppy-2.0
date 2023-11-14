#pragma once
#include <photonlib/PhotonUtils.h>
#include <photonlib/PhotonCamera.h>
#include <unordered_map>

class PhotonVisionInterface {
public:
    // This method should be called each tick of the Rio to send new data to Simulink
    void updatePhotonVisionPipeline();
    // Methods to return the vectors
    /**
     * @brief Returns vector of the distance from each target to the camera.
    */
    const std::vector<double>& getDistances() const;
    /**
     * @brief Returns vector of yaw angles of the targets
    */
    const std::vector<double>& getYaws() const;
    /**
     * @brief Returns vector of pitch angles of the targets
    */
    const std::vector<double>& getPitches() const;
    /**
     * @brief Returns a vector of target Ids from the targets (1-8 for 2023 game)
    */
    const std::vector<int>& getFiducialIds() const;
    /**
     * @brief Returns vector of confidence factors [0, 1] of the targets
    */
    const std::vector<double>& getPoseAmbiguities() const;

    /**
     * @brief Returns the vertical height of each target, needs to be setup for each game and senerio. 
    */
    const units::length::meter_t determineTargetHeight(int fiducialId) const;

private:
    // Makes PhotonCamera Object
    photonlib::PhotonCamera camera{"OV5647"};
    // Member variables to store data for each detected target
    std::vector<double> distances;
    std::vector<double> yaws;
    std::vector<double> pitches;
    std::vector<int> fiducialIds;
    std::vector<double> poseAmbiguities;
    // Constants with preset values
    static constexpr units::meter_t CAMERA_HEIGHT{0.25}; // meters
    static constexpr units::degree_t CAMERA_PITCH{0.0}; // degrees
};