#pragma once
#include <photonlib/PhotonUtils.h>
#include <photonlib/PhotonCamera.h>
#include <photonlib/PhotonPoseEstimator.h>

#include <frc/apriltag/AprilTagFieldLayout.h>
#include <frc/apriltag/AprilTagFields.h>
#include <frc/geometry/Pose2d.h>
#include <frc/geometry/Transform3d.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <math.h>

#include <memory>
#include "units/time.h"

class PhotonVisionInterface {
  public:
    void PreStep();
    void PostStep();
    void SmartDashboardCallback();
    PhotonVisionInterface();
    frc::Pose2d PhotonVisionInterface::GetEstimatedGlobalPose();

  private:
  double m_pi = 3.1415926535897;
  // Makes a apriltag feild layout for our shop 
    frc::AprilTag tag2 = frc::AprilTag(2, frc::Pose3d(frc::Translation3d(2.032_m, 4.5212_m, 0.4953_m), frc::Rotation3d(0_rad, 0_rad, 4.71238898_rad))); 
    frc::AprilTag tag3 = frc::AprilTag(3, frc::Pose3d(frc::Translation3d(5.207_m, 2.8702_m, 1.1811_m), frc::Rotation3d(0_rad, 0_rad, 3.1415926535897_rad)));
    frc::AprilTag tag4 = frc::AprilTag(4, frc::Pose3d(frc::Translation3d(5.207_m, 1.3462_m, 0.8382_m), frc::Rotation3d(0_rad, 0_rad, 3.1415926535897_rad)));
    frc::AprilTag tag5 = frc::AprilTag(5, frc::Pose3d(frc::Translation3d(3.8354_m, 0_m, 0.8763_m), frc::Rotation3d(0_rad, 0_rad, 1.570796327_rad))); 
    frc::AprilTag tag6 = frc::AprilTag(6, frc::Pose3d(frc::Translation3d(1.1684_m, 1.8542_m, 0.2032_m), frc::Rotation3d(0_rad, 0_rad, 0_rad)));
    frc::AprilTag tag7 = frc::AprilTag(7, frc::Pose3d(frc::Translation3d(1.778_m, 0_m, 0.4953_m), frc::Rotation3d(0_rad, 0_rad, 1.570796327_rad)));
    frc::AprilTag tag8 = frc::AprilTag(8, frc::Pose3d(frc::Translation3d(-0.6858_m, 4.0894_m, 0.1778_m), frc::Rotation3d(0_rad, 0_rad, 0_rad)));

    std::vector<frc::AprilTag> AprilTagList{tag2, tag3, tag4, tag5, tag6, tag7, tag8};
    frc::AprilTagFieldLayout AprilTagFieldLayout = frc::AprilTagFieldLayout(AprilTagList, 4.5212_m, 4.572_m);

  const frc::Transform3d robotToCam{
        frc::Translation3d{0.254_m, 0.0508_m, 0.1524_m},
        frc::Rotation3d{0_rad, 0_rad, 0_rad}};
  photonlib::PhotonPoseEstimator photonEstimator{
      AprilTagFieldLayout,
      photonlib::PoseStrategy::MULTI_TAG_PNP,
      photonlib::PhotonCamera{"OV5647"}, robotToCam};

      photonlib::PhotonCamera& camera = photonEstimator.GetCamera();
  // std::shared_ptr<photonlib::PhotonCamera> camera{std::make_shared<photonlib::PhotonCamera>(photonEstimator.GetCamera())};
  units::second_t lastEstTimestamp{0_s};
  frc::Pose2d robot2dPose{};
};