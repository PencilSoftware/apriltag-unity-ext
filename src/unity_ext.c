#include "unity_ext.h"
#include <math.h>
#include <string.h>

// Placeholder implementation to allow CI wiring.
// TODO: Replace with actual call path equivalent to apriltag's estimate_tag_pose
// using homography_to_pose + optional Gauss-Newton refinement.

static void identity3(double* R)
{
  memset(R, 0, sizeof(double) * 9);
  R[0] = R[4] = R[8] = 1.0;
}

int estimate_pose_from_corners(
  const double* px, const double* py,
  double tag_size,
  double fx, double fy, double cx, double cy,
  double* R_out,
  double* t_out)
{
  if (!px || !py || !R_out || !t_out) return -1;
  // Minimal stub: returns identity rotation and zero translation
  identity3(R_out);
  t_out[0] = t_out[1] = t_out[2] = 0.0;
  return 0;
}


