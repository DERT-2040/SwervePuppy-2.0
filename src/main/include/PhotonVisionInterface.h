#pragma once
#include <photonlib/PhotonUtils.h>
#include <photonlib/PhotonCamera.h>
#include <photonlib/PhotonPoseEstimator.h>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <utility>
#include <frc/apriltag/AprilTagFieldLayout.h>
#include <frc/apriltag/AprilTagFields.h>
#include <frc/geometry/Pose3d.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <algorithm>

extern std::vector<double> yaws;

class PhotonVisionInterface {
public:
    PhotonVisionInterface();
    // This method should be called each tick of the Rio to update the data for each target given to simulink
    void updatePhotonVision();
    void PreStep();
    void PostStep();
    void SmartDashboardCallback();
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
    
    /**
     * @brief Prints out the current dected fiducialIds into console
    */
    const void printFiducialIds() const;
    /**
    *  @brief Returns the timestamp that the camera was updated
    */
    const units::time::second_t getCameraTimestamp() const;
    /**
     * @brief Returns the 3d translation of the robot as a vector (x, y, z)
    */
    const std::vector<double> get3dTranslation() const;
    /**
     * @brief Returns a vector of the robot's 3d rotation (roll, pitch, yaw)
    */
    const std::vector<double> getRobotRotation() const;
    /**
     * @brief Returns the fiducial ids of tags being used for the generated pose
    */
    const std::vector<int> getPoseTargetsFiducialIds() const;



private:
    // Makes a apriltag feild layout for our shop 
    frc::AprilTag tag1 = frc::AprilTag(1, frc::Pose3d(frc::Translation3d(15.513558_m, 1.02743_m, 0.462788_m), frc::Rotation3d(0_rad, 0_rad, 0_rad)));
    frc::AprilTag tag2 = frc::AprilTag(2, frc::Pose3d(frc::Translation3d(15.513558_m, 2.748026_m, 0.462788_m), frc::Rotation3d(0_rad, 0_rad, 0_rad)));
    frc::AprilTag tag3 = frc::AprilTag(3, frc::Pose3d(frc::Translation3d(15.513558_m, 4.424426_m, 0.462788_m), frc::Rotation3d(0_rad, 0_rad, 0_rad)));
    frc::AprilTag tag4 = frc::AprilTag(4, frc::Pose3d(frc::Translation3d(16.513558_m, 6.749796_m, 0.695452_m), frc::Rotation3d(0_rad, 0_rad, 0_rad)));
    frc::AprilTag tag5 = frc::AprilTag(5, frc::Pose3d(frc::Translation3d(0.36195_m, 6.749796_m, 0.695452_m), frc::Rotation3d(0_rad, 0_rad, 0_rad)));
    frc::AprilTag tag6 = frc::AprilTag(6, frc::Pose3d(frc::Translation3d(1.02743_m, 4.424426_m, 0.462788_m), frc::Rotation3d(0_rad, 0_rad, 0_rad)));
    frc::AprilTag tag7 = frc::AprilTag(7, frc::Pose3d(frc::Translation3d(1.02743_m, 2.748026_m, 0.462788_m), frc::Rotation3d(0_rad, 0_rad, 0_rad)));
    frc::AprilTag tag8 = frc::AprilTag(8, frc::Pose3d(frc::Translation3d(1.02743_m, 1.02743_m, 0.462788_m), frc::Rotation3d(0_rad, 0_rad, 0_rad)));

    std::vector<frc::AprilTag> AprilTagList{tag1, tag2, tag3, tag4, tag5, tag6, tag7, tag8};
    frc::AprilTagFieldLayout AprilTagFieldLayout = frc::AprilTagFieldLayout(AprilTagList, 16.54175_m, 8.0137_m);

    // Member variables to store data for each detected target
    std::vector<double> distances{0.0};
    std::vector<double> yaws{0.0};
    std::vector<double> pitches{0.0};
    std::vector<int> fiducialIds{0};
    std::vector<double> poseAmbiguities{0.0};

    // A list of the target heights for finding distance to the targets
    std::vector<units::length::meter_t> targetHeight{0_m, 0.462788_m, 0.462788_m, 0.462788_m, 0.695452_m, 0.695452_m, 0.462788_m, 0.462788_m, 0.462788_m}; 

    //Robot Pose Estimator
    frc::Transform3d robotToCamera = frc::Transform3d(frc::Translation3d(0.5_m, -0.25_m, CAMERA_HEIGHT), frc::Rotation3d(0_rad, CAMERA_PITCH, 0_rad));
    /**
     * @note I do not know exactly why I need std::move() in the constructor but it works so im running with it. Kill me if you want. *shrugs*
    */
    photonlib::PhotonPoseEstimator poseEstimator = photonlib::PhotonPoseEstimator(AprilTagFieldLayout, photonlib::MULTI_TAG_PNP, std::move(photonlib::PhotonCamera("OV5647")), robotToCamera);

    frc::Pose3d estimatedPose;

    units::second_t timestamp;

    wpi::SmallVector<photonlib::PhotonTrackedTarget, 10> poseTargets;

    // Constants with preset values
    static constexpr units::meter_t CAMERA_HEIGHT{0.25}; // meters
    static constexpr units::radian_t CAMERA_PITCH{0_rad}; // degrees (rad)
};