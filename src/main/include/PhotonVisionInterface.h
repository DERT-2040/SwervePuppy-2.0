#pragma once
#include <photonlib/PhotonUtils.h>
#include <photonlib/PhotonCamera.h>
#include <photonlib/PhotonPoseEstimator.h>

#include <frc/apriltag/AprilTagFieldLayout.h>
#include <frc/apriltag/AprilTagFields.h>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Transform3d.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include <memory>
#include "units/time.h"

class PhotonVisionInterface {
  public:
    void PreStep();
    void PostStep();
    void SmartDashboardCallback();
    PhotonVisionInterface();
    std::optional<photonlib::EstimatedRobotPose> GetEstimatedGlobalPose();

  private:
  const frc::Transform3d robotToCam{
        frc::Translation3d{0.5_m, 0.0_m, 0.5_m},
        frc::Rotation3d{0_rad, 0_rad, 0_rad}};
  photonlib::PhotonPoseEstimator photonEstimator{
      LoadAprilTagLayoutField(frc::AprilTagField::k2023ChargedUp),
      photonlib::PoseStrategy::MULTI_TAG_PNP,
      photonlib::PhotonCamera{"OV5647"}, robotToCam};

      photonlib::PhotonCamera& camera = photonEstimator.GetCamera();
  // std::shared_ptr<photonlib::PhotonCamera> camera{std::make_shared<photonlib::PhotonCamera>(photonEstimator.GetCamera())};
  units::second_t lastEstTimestamp{0_s};
  frc::Pose2d robot2dPose{};
};