#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// Estimate pose from four undistorted image corners and camera intrinsics.
// px, py: length-4 arrays of pixel coordinates, order must match AprilTag Detection Corner1..Corner4
// tag_size: physical edge length in meters
// fx, fy, cx, cy: camera intrinsics
// R_out: row-major 3x3 rotation matrix; t_out: 3x1 translation in camera frame
// Returns 0 on success, non-zero on failure.
int estimate_pose_from_corners(
  const double* px, const double* py,
  double tag_size,
  double fx, double fy, double cx, double cy,
  double* R_out,
  double* t_out);

#ifdef __cplusplus
}
#endif


