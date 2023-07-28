/*
 * Catwell_Rom.c
 *
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * Code generation for model "Catwell_Rom".
 *
 * Model version              : 1.10
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Fri Jul 14 20:38:59 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Catwell_Rom.h"
#include "rtwtypes.h"
#include "Catwell_Rom_types.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "Catwell_Rom_private.h"
#include <string.h>
#include <emmintrin.h>
#include "rt_defines.h"
#include <stdlib.h>
#include <stddef.h>

/* Block states (default storage) */
DW_Catwell_Rom_T Catwell_Rom_DW;

/* Real-time model */
static RT_MODEL_Catwell_Rom_T Catwell_Rom_M_;
RT_MODEL_Catwell_Rom_T *const Catwell_Rom_M = &Catwell_Rom_M_;

/* Forward declaration for local functions */
static void Catwell_Rom_emxInit_real_T(emxArray_real_T_Catwell_Rom_T **pEmxArray,
  int32_T numDimensions);
static void emxInitStruct_driving_internal_(driving_internal_planning_Pat_T
  *pStruct);
static void Catwel_emxEnsureCapacity_real_T(emxArray_real_T_Catwell_Rom_T
  *emxArray, int32_T oldNumel);
static void Catwell_Rom_binary_expand_op_i(boolean_T in1_data[], int32_T
  *in1_size, const real_T in3_data[], const int32_T in3_size[2], int32_T in4,
  int32_T in5, int32_T in6, int32_T in7, int32_T in8, int32_T in9);
static void Catwell_Rom_filterPoses(const real_T refPoses_data[], const int32_T
  refPoses_size[2], const real_T refDirections_data[], const int32_T
  *refDirections_size, real_T poses_data[], int32_T poses_size[2], real_T
  directions_data[], int32_T *directions_size);
static void Catwell_Rom_binary_expand_op_ia(boolean_T in1_data[], int32_T
  *in1_size, const real_T in2_data[], int32_T in3, int32_T in4, int32_T in5);
static void Ca_getSegmentBoundaryPointIndex(const real_T directions_data[],
  const int32_T *directions_size, real_T segStartIdx_data[], int32_T
  *segStartIdx_size, real_T segEndIdx_data[], int32_T *segEndIdx_size);
static void Catwell_Ro_binary_expand_op_ia3(real_T in1_data[], int32_T *in1_size,
  const real_T in3_data[], const int32_T in3_size[2], int32_T in4, int32_T in5,
  int32_T in6, int32_T in7, int32_T in8, int32_T in9);
static void Ca_computeCumulativeChordLength(const real_T poses_data[], const
  int32_T poses_size[2], real_T cumChordLength_data[], int32_T
  *cumChordLength_size);
static void Catwel_setSegmentNumSmoothPoses(const real_T
  chordLengthOfSegments_data[], const int32_T *chordLengthOfSegments_size,
  real_T numPosesSeg_data[], int32_T *numPosesSeg_size);
static void Catwell_Rom_spline(const real_T x_data[], const int32_T *x_size,
  const real_T y_data[], const int32_T *y_size, real_T output_breaks_data[],
  int32_T output_breaks_size[2], real_T output_coefs_data[], int32_T
  output_coefs_size[2]);
static void Catwell_Rom_bsxfun(const real_T a_data[], const int32_T a_size[2],
  real_T c_data[], int32_T c_size[2]);
static void Catwell_Rom_linspace(real_T d2, real_T n,
  emxArray_real_T_Catwell_Rom_T *y);
static int32_T Catwell_Rom_bsearch(const real_T x_data[], const int32_T x_size[2],
  real_T xi);
static void Catwell_Rom_ppval(const real_T pp_breaks_data[], const int32_T
  pp_breaks_size[2], const real_T pp_coefs_data[], const int32_T pp_coefs_size[2],
  const real_T x_data[], const int32_T x_size[2], real_T v_data[], int32_T
  v_size[2]);
static void Catwell_Rom_expand_atan2(const real_T a_data[], const int32_T
  a_size[2], const real_T b_data[], const int32_T b_size[2], real_T c_data[],
  int32_T c_size[2]);
static void Catwell_Rom_emxFree_real_T(emxArray_real_T_Catwell_Rom_T **pEmxArray);
static void Catwell_R_binary_expand_op_ia3x(emxArray_real_T_Catwell_Rom_T *in1,
  const emxArray_real_T_Catwell_Rom_T *in3);
static void Catwell_Rom_cumtrapz(const emxArray_real_T_Catwell_Rom_T *x,
  emxArray_real_T_Catwell_Rom_T *z);
static void Cat_computeCumulativePathLength(const real_T splineDx_breaks_data[],
  const int32_T splineDx_breaks_size[2], const real_T splineDx_coefs_data[],
  const real_T splineDy_breaks_data[], const int32_T splineDy_breaks_size[2],
  const real_T splineDy_coefs_data[], const real_T tQuery_data[], const int32_T
  tQuery_size[2], real_T cumLengths_data[], int32_T cumLengths_size[2]);
static void Catwell_Rom_bsxfun_i(const real_T a_data[], const int32_T a_size[2],
  real_T c_data[], int32_T c_size[2]);
static void Catwell__binary_expand_op_ia3xt(real_T in1_data[], int32_T in1_size
  [2], const emxArray_real_T_Catwell_Rom_T *in2, const
  emxArray_real_T_Catwell_Rom_T *in3, const real_T in4_data[], const int32_T
  in4_size[2], const emxArray_real_T_Catwell_Rom_T *in6, const
  emxArray_real_T_Catwell_Rom_T *in7);
static void Catwell_R_computePathCurvatures(const real_T splineDx_breaks_data[],
  const int32_T splineDx_breaks_size[2], const real_T splineDx_coefs_data[],
  const int32_T splineDx_coefs_size[3], const real_T splineDy_breaks_data[],
  const int32_T splineDy_breaks_size[2], const real_T splineDy_coefs_data[],
  const int32_T splineDy_coefs_size[3], const real_T tQuery_data[], const
  int32_T tQuery_size[2], real_T curvatures_data[], int32_T curvatures_size[2]);
static void Catwell_Rom_smoothPathSpline(real_T refPoses_data[], int32_T
  refPoses_size[2], const real_T refDirections_data[], const int32_T
  *refDirections_size, real_T poses[30], real_T directions[10], real_T
  varargout_1[10], real_T varargout_2[10]);
static void emxFreeStruct_driving_internal_(driving_internal_planning_Pat_T
  *pStruct);
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Catwell_Rom_M->Timing.TaskCounters.TID[2])++;
  if ((Catwell_Rom_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.1s, 0.0s] */
    Catwell_Rom_M->Timing.TaskCounters.TID[2] = 0;
  }

  (Catwell_Rom_M->Timing.TaskCounters.TID[3])++;
  if ((Catwell_Rom_M->Timing.TaskCounters.TID[3]) > 49) {/* Sample time: [0.5s, 0.0s] */
    Catwell_Rom_M->Timing.TaskCounters.TID[3] = 0;
  }
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

static void Catwell_Rom_emxInit_real_T(emxArray_real_T_Catwell_Rom_T **pEmxArray,
  int32_T numDimensions)
{
  emxArray_real_T_Catwell_Rom_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T_Catwell_Rom_T *)malloc(sizeof
    (emxArray_real_T_Catwell_Rom_T));
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInitStruct_driving_internal_(driving_internal_planning_Pat_T
  *pStruct)
{
  Catwell_Rom_emxInit_real_T(&pStruct->RefPosesInternal, 2);
  Catwell_Rom_emxInit_real_T(&pStruct->RefDirectionsInternal, 1);
}

static void Catwel_emxEnsureCapacity_real_T(emxArray_real_T_Catwell_Rom_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void Catwell_Rom_binary_expand_op_i(boolean_T in1_data[], int32_T
  *in1_size, const real_T in3_data[], const int32_T in3_size[2], int32_T in4,
  int32_T in5, int32_T in6, int32_T in7, int32_T in8, int32_T in9)
{
  real_T in3_data_0[11];
  real_T in3_data_1[11];
  int32_T i;
  int32_T in3_size_idx_0;
  int32_T in3_size_idx_0_0;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  boolean_T tmp_data[10];
  i = (in5 - in4) + 1;
  loop_ub = in6 == 1 ? i : in6;
  in3_size_idx_0 = loop_ub;
  stride_0_0 = (i != 1);
  stride_1_0 = (in6 != 1);
  for (i = 0; i < loop_ub; i++) {
    in3_data_0[i] = in3_data[(i * stride_0_0 + in4) - 1] - in3_data[i *
      stride_1_0];
  }

  i = (in8 - in7) + 1;
  loop_ub = in9 == 1 ? i : in9;
  in3_size_idx_0_0 = loop_ub;
  stride_0_0 = (i != 1);
  stride_1_0 = (in9 != 1);
  for (i = 0; i < loop_ub; i++) {
    in3_data_1[i] = in3_data[((i * stride_0_0 + in7) + in3_size[0]) - 1] -
      in3_data[i * stride_1_0 + in3_size[0]];
  }

  loop_ub = loop_ub == 1 ? in3_size_idx_0 : loop_ub;
  stride_0_0 = (in3_size_idx_0 != 1);
  stride_1_0 = (in3_size_idx_0_0 != 1);
  for (i = 0; i < loop_ub; i++) {
    real_T varargin_1;
    real_T varargin_1_0;
    varargin_1 = in3_data_0[i * stride_0_0];
    varargin_1_0 = in3_data_1[i * stride_1_0];
    tmp_data[i] = (varargin_1 * varargin_1 + varargin_1_0 * varargin_1_0 >=
                   1.0E-6);
  }

  *in1_size = loop_ub + 1;
  in1_data[0] = true;
  if (loop_ub - 1 >= 0) {
    memcpy(&in1_data[1], &tmp_data[0], (uint32_T)loop_ub * sizeof(boolean_T));
  }
}

static void Catwell_Rom_filterPoses(const real_T refPoses_data[], const int32_T
  refPoses_size[2], const real_T refDirections_data[], const int32_T
  *refDirections_size, real_T poses_data[], int32_T poses_size[2], real_T
  directions_data[], int32_T *directions_size)
{
  real_T varargin_1;
  real_T varargin_1_0;
  int32_T c;
  int32_T d;
  int32_T f;
  int32_T j;
  int32_T k;
  int32_T loop_ub;
  int32_T m;
  int32_T tmp_size;
  int8_T tmp_data[11];
  boolean_T tmp_data_0[11];
  if (refPoses_size[0] < 2) {
    d = 0;
    c = 0;
    f = 0;
    k = 0;
    j = 0;
    m = 0;
  } else {
    d = 1;
    c = refPoses_size[0];
    f = refPoses_size[0] - 1;
    k = 1;
    j = refPoses_size[0];
    m = refPoses_size[0] - 1;
  }

  loop_ub = c - d;
  if ((loop_ub == f) && (loop_ub == m)) {
    tmp_size = loop_ub + 1;
    tmp_data_0[0] = true;
    for (f = 0; f < loop_ub; f++) {
      c = d + f;
      varargin_1 = refPoses_data[c] - refPoses_data[f];
      varargin_1_0 = refPoses_data[c + refPoses_size[0]] - refPoses_data[f +
        refPoses_size[0]];
      tmp_data_0[f + 1] = (varargin_1 * varargin_1 + varargin_1_0 * varargin_1_0
                           >= 1.0E-6);
    }
  } else {
    Catwell_Rom_binary_expand_op_i(tmp_data_0, &tmp_size, refPoses_data,
      refPoses_size, d + 1, c, f, k + 1, j, m);
  }

  loop_ub = tmp_size - 1;
  d = 0;
  for (f = 0; f <= loop_ub; f++) {
    if (tmp_data_0[f]) {
      d++;
    }
  }

  k = d;
  d = 0;
  for (f = 0; f <= loop_ub; f++) {
    if (tmp_data_0[f]) {
      tmp_data[d] = (int8_T)f;
      d++;
    }
  }

  poses_size[0] = k;
  poses_size[1] = refPoses_size[1];
  loop_ub = refPoses_size[1];
  for (f = 0; f < loop_ub; f++) {
    for (d = 0; d < k; d++) {
      poses_data[d + k * f] = refPoses_data[refPoses_size[0] * f + tmp_data[d]];
    }
  }

  *directions_size = k;
  for (f = 0; f < k; f++) {
    directions_data[f] = refDirections_data[tmp_data[f]];
  }

  c = refPoses_size[0];
  loop_ub = refPoses_size[1];
  for (d = 0; d < loop_ub; d++) {
    poses_data[(k + k * d) - 1] = refPoses_data[(refPoses_size[0] * d + c) - 1];
  }

  directions_data[k - 1] = refDirections_data[*refDirections_size - 1];
}

static void Catwell_Rom_binary_expand_op_ia(boolean_T in1_data[], int32_T
  *in1_size, const real_T in2_data[], int32_T in3, int32_T in4, int32_T in5)
{
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  i = (in5 - in4) + 1;
  loop_ub = i == 1 ? in3 : i;
  *in1_size = loop_ub;
  stride_0_0 = (in3 != 1);
  stride_1_0 = (i != 1);
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = (in2_data[(i * stride_1_0 + in4) - 1] + in2_data[i *
                   stride_0_0] == 0.0);
  }
}

static void Ca_getSegmentBoundaryPointIndex(const real_T directions_data[],
  const int32_T *directions_size, real_T segStartIdx_data[], int32_T
  *segStartIdx_size, real_T segEndIdx_data[], int32_T *segEndIdx_size)
{
  int32_T ii_data[11];
  int32_T switchIndex_data[11];
  int32_T e;
  int32_T f;
  int32_T idx;
  int32_T x_size;
  boolean_T x_data[11];
  boolean_T exitg1;
  if (*directions_size - 1 < 1) {
    idx = 0;
  } else {
    idx = *directions_size - 1;
  }

  if (*directions_size < 2) {
    f = 0;
    e = 0;
  } else {
    f = 1;
    e = *directions_size;
  }

  if (e - f == idx) {
    x_size = idx;
    for (e = 0; e < idx; e++) {
      x_data[e] = (directions_data[f + e] + directions_data[e] == 0.0);
    }
  } else {
    Catwell_Rom_binary_expand_op_ia(x_data, &x_size, directions_data, idx, f + 1,
      e);
  }

  idx = 0;
  e = 1;
  exitg1 = false;
  while ((!exitg1) && (e - 1 <= x_size - 1)) {
    if (x_data[e - 1]) {
      idx++;
      ii_data[idx - 1] = e;
      if (idx >= x_size) {
        exitg1 = true;
      } else {
        e++;
      }
    } else {
      e++;
    }
  }

  if (x_size == 1) {
    if (idx == 0) {
      x_size = 0;
    }
  } else if (idx < 1) {
    x_size = 0;
  } else {
    x_size = idx;
  }

  if (x_size - 1 >= 0) {
    memcpy(&switchIndex_data[0], &ii_data[0], (uint32_T)x_size * sizeof(int32_T));
  }

  *segStartIdx_size = x_size + 1;
  segStartIdx_data[0] = 1.0;
  *segEndIdx_size = x_size + 1;
  for (e = 0; e < x_size; e++) {
    f = switchIndex_data[e];
    segStartIdx_data[e + 1] = f;
    segEndIdx_data[e] = f;
  }

  segEndIdx_data[x_size] = *directions_size;
}

static void Catwell_Ro_binary_expand_op_ia3(real_T in1_data[], int32_T *in1_size,
  const real_T in3_data[], const int32_T in3_size[2], int32_T in4, int32_T in5,
  int32_T in6, int32_T in7, int32_T in8, int32_T in9)
{
  real_T in3_data_0[11];
  real_T in3_data_1[11];
  int32_T i;
  int32_T in3_size_idx_0;
  int32_T in3_size_idx_0_0;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  i = (in5 - in4) + 1;
  loop_ub = in6 == 1 ? i : in6;
  in3_size_idx_0 = loop_ub;
  stride_0_0 = (i != 1);
  stride_1_0 = (in6 != 1);
  for (i = 0; i < loop_ub; i++) {
    in3_data_0[i] = in3_data[(i * stride_0_0 + in4) - 1] - in3_data[i *
      stride_1_0];
  }

  i = (in8 - in7) + 1;
  loop_ub = in9 == 1 ? i : in9;
  in3_size_idx_0_0 = loop_ub;
  stride_0_0 = (i != 1);
  stride_1_0 = (in9 != 1);
  for (i = 0; i < loop_ub; i++) {
    in3_data_1[i] = in3_data[((i * stride_0_0 + in7) + in3_size[0]) - 1] -
      in3_data[i * stride_1_0 + in3_size[0]];
  }

  loop_ub = loop_ub == 1 ? in3_size_idx_0 : loop_ub;
  *in1_size = loop_ub;
  stride_0_0 = (in3_size_idx_0 != 1);
  stride_1_0 = (in3_size_idx_0_0 != 1);
  for (i = 0; i < loop_ub; i++) {
    real_T varargin_1;
    real_T varargin_1_0;
    varargin_1 = in3_data_0[i * stride_0_0];
    varargin_1_0 = in3_data_1[i * stride_1_0];
    in1_data[i] = varargin_1 * varargin_1 + varargin_1_0 * varargin_1_0;
  }
}

static void Ca_computeCumulativeChordLength(const real_T poses_data[], const
  int32_T poses_size[2], real_T cumChordLength_data[], int32_T
  *cumChordLength_size)
{
  __m128d tmp;
  __m128d tmp_0;
  real_T b_x_data[11];
  real_T varargin_1;
  real_T varargin_1_0;
  int32_T c;
  int32_T d;
  int32_T f;
  int32_T j;
  int32_T k;
  int32_T loop_ub;
  int32_T m;
  if (poses_size[0] < 2) {
    d = 0;
    c = 0;
    f = 0;
    k = 0;
    j = 0;
    m = 0;
  } else {
    d = 1;
    c = poses_size[0];
    f = poses_size[0] - 1;
    k = 1;
    j = poses_size[0];
    m = poses_size[0] - 1;
  }

  loop_ub = c - d;
  if ((loop_ub == f) && (loop_ub == m)) {
    f = (loop_ub / 2) << 1;
    k = f - 2;
    for (j = 0; j <= k; j += 2) {
      c = d + j;
      tmp = _mm_sub_pd(_mm_loadu_pd(&poses_data[c]), _mm_loadu_pd(&poses_data[j]));
      tmp_0 = _mm_sub_pd(_mm_loadu_pd(&poses_data[c + poses_size[0]]),
                         _mm_loadu_pd(&poses_data[j + poses_size[0]]));
      _mm_storeu_pd(&b_x_data[j], _mm_add_pd(_mm_mul_pd(tmp, tmp), _mm_mul_pd
        (tmp_0, tmp_0)));
    }

    for (j = f; j < loop_ub; j++) {
      c = d + j;
      varargin_1 = poses_data[c] - poses_data[j];
      varargin_1_0 = poses_data[c + poses_size[0]] - poses_data[j + poses_size[0]];
      b_x_data[j] = varargin_1 * varargin_1 + varargin_1_0 * varargin_1_0;
    }
  } else {
    Catwell_Ro_binary_expand_op_ia3(b_x_data, &loop_ub, poses_data, poses_size,
      d + 1, c, f, k + 1, j, m);
  }

  c = loop_ub - 1;
  f = (loop_ub / 2) << 1;
  k = f - 2;
  for (d = 0; d <= k; d += 2) {
    tmp = _mm_loadu_pd(&b_x_data[d]);
    _mm_storeu_pd(&b_x_data[d], _mm_sqrt_pd(tmp));
  }

  for (d = f; d <= c; d++) {
    b_x_data[d] = sqrt(b_x_data[d]);
  }

  *cumChordLength_size = loop_ub + 1;
  cumChordLength_data[0] = 0.0;
  if (loop_ub - 1 >= 0) {
    memcpy(&cumChordLength_data[1], &b_x_data[0], (uint32_T)loop_ub * sizeof
           (real_T));
  }

  if (loop_ub + 1 != 1) {
    c = loop_ub - 1;
    for (d = 0; d <= c; d++) {
      cumChordLength_data[d + 1] += cumChordLength_data[d];
    }
  }
}

static void Catwel_setSegmentNumSmoothPoses(const real_T
  chordLengthOfSegments_data[], const int32_T *chordLengthOfSegments_size,
  real_T numPosesSeg_data[], int32_T *numPosesSeg_size)
{
  real_T y;
  int32_T i;
  int32_T k;
  int32_T vectorUB;
  int32_T vlen;
  vlen = *chordLengthOfSegments_size;
  if (*chordLengthOfSegments_size == 0) {
    y = 0.0;
  } else {
    y = chordLengthOfSegments_data[0];
    for (k = 2; k <= vlen; k++) {
      y += chordLengthOfSegments_data[k - 1];
    }
  }

  *numPosesSeg_size = *chordLengthOfSegments_size;
  vlen = *chordLengthOfSegments_size;
  k = (*chordLengthOfSegments_size / 2) << 1;
  vectorUB = k - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    _mm_storeu_pd(&numPosesSeg_data[i], _mm_div_pd(_mm_mul_pd(_mm_loadu_pd
      (&chordLengthOfSegments_data[i]), _mm_set1_pd(10.0)), _mm_set1_pd(y)));
  }

  for (i = k; i < vlen; i++) {
    numPosesSeg_data[i] = chordLengthOfSegments_data[i] * 10.0 / y;
  }

  vlen = *chordLengthOfSegments_size - 1;
  for (k = 0; k <= vlen; k++) {
    numPosesSeg_data[k] = floor(numPosesSeg_data[k]);
  }

  if (*chordLengthOfSegments_size - 1 < 1) {
    vlen = 0;
  } else {
    vlen = *chordLengthOfSegments_size - 1;
  }

  if ((vlen == 0) || (vlen == 0)) {
    y = 0.0;
  } else {
    y = numPosesSeg_data[0];
    for (k = 2; k <= vlen; k++) {
      y += numPosesSeg_data[k - 1];
    }
  }

  numPosesSeg_data[*chordLengthOfSegments_size - 1] = 10.0 - y;
}

static void Catwell_Rom_spline(const real_T x_data[], const int32_T *x_size,
  const real_T y_data[], const int32_T *y_size, real_T output_breaks_data[],
  int32_T output_breaks_size[2], real_T output_coefs_data[], int32_T
  output_coefs_size[2])
{
  real_T g_coefs_data[48];
  real_T md_data[22];
  real_T dx_data[21];
  real_T s_data[13];
  real_T dvdf_data[12];
  real_T c_data[4];
  real_T f_coefs_data[4];
  real_T dnnm2;
  int32_T cpage;
  int32_T nxm1;
  int32_T scalarLB;
  boolean_T has_endslopes;
  has_endslopes = (*x_size + 2 == *y_size);
  if ((*x_size <= 2) || ((*x_size <= 3) && (!has_endslopes))) {
    if (*x_size <= 2) {
      if (*x_size + 2 == *y_size) {
        real_T szdvdf_idx_0;
        real_T szdvdf_idx_1;
        szdvdf_idx_0 = y_data[0];
        szdvdf_idx_1 = y_data[*y_size - 1];
        nxm1 = *x_size - 2;
        if (*x_size - 2 >= 0) {
          dnnm2 = x_data[1] - x_data[0];
          f_coefs_data[2] = y_data[0];
          f_coefs_data[3] = y_data[1];
        }

        for (scalarLB = 0; scalarLB <= nxm1; scalarLB++) {
          real_T d31;
          real_T r;
          r = (y_data[2] - y_data[1]) / dnnm2;
          d31 = (r - szdvdf_idx_0) / dnnm2;
          r = (szdvdf_idx_1 - r) / dnnm2;
          f_coefs_data[0] = (r - d31) / dnnm2;
          f_coefs_data[1] = 2.0 * d31 - r;
        }

        scalarLB = 4;
        for (nxm1 = 0; nxm1 < 4; nxm1++) {
          c_data[nxm1] = f_coefs_data[nxm1];
        }
      } else {
        scalarLB = 2;
        c_data[0] = (y_data[1] - y_data[0]) / (x_data[1] - x_data[0]);
        c_data[1] = y_data[0];
      }

      output_breaks_size[0] = 1;
      output_breaks_size[1] = *x_size;
      if (*x_size - 1 >= 0) {
        memcpy(&output_breaks_data[0], &x_data[0], (uint32_T)*x_size * sizeof
               (real_T));
      }

      memcpy(&f_coefs_data[0], &c_data[0], (uint32_T)scalarLB * sizeof(real_T));
    } else {
      real_T d31;
      d31 = x_data[1] - x_data[0];
      dnnm2 = (y_data[1] - y_data[0]) / d31;
      c_data[0] = ((y_data[2] - y_data[1]) / (x_data[2] - x_data[1]) - dnnm2) /
        (x_data[2] - x_data[0]);
      c_data[1] = dnnm2 - c_data[0] * d31;
      c_data[2] = y_data[0];
      output_breaks_size[0] = 1;
      output_breaks_size[1] = 2;
      output_breaks_data[0] = x_data[0];
      output_breaks_data[1] = x_data[2];
      scalarLB = 3;
      for (nxm1 = 0; nxm1 < 3; nxm1++) {
        f_coefs_data[nxm1] = c_data[nxm1];
      }
    }

    output_coefs_size[0] = 1;
    output_coefs_size[1] = scalarLB;
    memcpy(&output_coefs_data[0], &f_coefs_data[0], (uint32_T)scalarLB * sizeof
           (real_T));
  } else {
    __m128d tmp;
    __m128d tmp_2;
    real_T d31;
    real_T r;
    real_T szdvdf_idx_0;
    int32_T d_tmp;
    int32_T nxm1_tmp;
    int32_T s_size_idx_1;
    int32_T vectorUB;
    int32_T yoffset;
    nxm1_tmp = *x_size - 1;
    if (has_endslopes) {
      s_size_idx_1 = *y_size - 2;
      yoffset = 0;
    } else {
      s_size_idx_1 = *y_size;
      yoffset = -1;
    }

    d_tmp = *x_size - 2;
    scalarLB = ((*x_size - 1) / 2) << 1;
    vectorUB = scalarLB - 2;
    for (cpage = 0; cpage <= vectorUB; cpage += 2) {
      tmp_2 = _mm_sub_pd(_mm_loadu_pd(&x_data[cpage + 1]), _mm_loadu_pd
                         (&x_data[cpage]));
      _mm_storeu_pd(&dx_data[cpage], tmp_2);
      nxm1 = yoffset + cpage;
      _mm_storeu_pd(&dvdf_data[cpage], _mm_div_pd(_mm_sub_pd(_mm_loadu_pd
        (&y_data[nxm1 + 2]), _mm_loadu_pd(&y_data[nxm1 + 1])), tmp_2));
    }

    for (cpage = scalarLB; cpage <= d_tmp; cpage++) {
      dnnm2 = x_data[cpage + 1] - x_data[cpage];
      dx_data[cpage] = dnnm2;
      nxm1 = yoffset + cpage;
      dvdf_data[cpage] = (y_data[nxm1 + 2] - y_data[nxm1 + 1]) / dnnm2;
    }

    cpage = (((*x_size - 2) / 2) << 1) + 2;
    nxm1 = cpage - 2;
    for (scalarLB = 2; scalarLB <= nxm1; scalarLB += 2) {
      __m128d tmp_0;
      __m128d tmp_1;
      tmp_2 = _mm_loadu_pd(&dx_data[scalarLB - 1]);
      tmp = _mm_loadu_pd(&dvdf_data[scalarLB - 2]);
      tmp_0 = _mm_loadu_pd(&dx_data[scalarLB - 2]);
      vectorUB = scalarLB - 1;
      tmp_1 = _mm_loadu_pd(&dvdf_data[vectorUB]);
      _mm_storeu_pd(&s_data[scalarLB - 1], _mm_mul_pd(_mm_add_pd(_mm_mul_pd
        (tmp_2, tmp), _mm_mul_pd(tmp_0, tmp_1)), _mm_set1_pd(3.0)));
    }

    for (scalarLB = cpage; scalarLB <= nxm1_tmp; scalarLB++) {
      s_data[scalarLB - 1] = (dx_data[scalarLB - 1] * dvdf_data[scalarLB - 2] +
        dx_data[scalarLB - 2] * dvdf_data[scalarLB - 1]) * 3.0;
    }

    if (has_endslopes) {
      d31 = 0.0;
      dnnm2 = 0.0;
      s_data[0] = y_data[0] * dx_data[1];
      s_data[*x_size - 1] = dx_data[*x_size - 3] * y_data[*x_size + 1];
    } else {
      d31 = x_data[2] - x_data[0];
      dnnm2 = x_data[*x_size - 1] - x_data[*x_size - 3];
      s_data[0] = ((2.0 * d31 + dx_data[0]) * dx_data[1] * dvdf_data[0] +
                   dx_data[0] * dx_data[0] * dvdf_data[1]) / d31;
      r = dx_data[*x_size - 2];
      s_data[*x_size - 1] = ((2.0 * dnnm2 + r) * dx_data[*x_size - 3] *
        dvdf_data[*x_size - 2] + r * r * dvdf_data[*x_size - 3]) / dnnm2;
    }

    md_data[0] = dx_data[1];
    szdvdf_idx_0 = dx_data[*x_size - 3];
    md_data[*x_size - 1] = szdvdf_idx_0;
    for (scalarLB = 2; scalarLB <= nxm1; scalarLB += 2) {
      tmp_2 = _mm_loadu_pd(&dx_data[scalarLB - 1]);
      tmp = _mm_loadu_pd(&dx_data[scalarLB - 2]);
      _mm_storeu_pd(&md_data[scalarLB - 1], _mm_mul_pd(_mm_add_pd(tmp_2, tmp),
        _mm_set1_pd(2.0)));
    }

    for (scalarLB = cpage; scalarLB <= nxm1_tmp; scalarLB++) {
      md_data[scalarLB - 1] = (dx_data[scalarLB - 1] + dx_data[scalarLB - 2]) *
        2.0;
    }

    r = dx_data[1] / md_data[0];
    md_data[1] -= r * d31;
    s_data[1] -= r * s_data[0];
    for (scalarLB = 3; scalarLB <= nxm1_tmp; scalarLB++) {
      r = dx_data[scalarLB - 1] / md_data[scalarLB - 2];
      md_data[scalarLB - 1] -= dx_data[scalarLB - 3] * r;
      s_data[scalarLB - 1] -= s_data[scalarLB - 2] * r;
    }

    r = dnnm2 / md_data[*x_size - 2];
    md_data[*x_size - 1] -= szdvdf_idx_0 * r;
    s_data[*x_size - 1] -= s_data[*x_size - 2] * r;
    s_data[*x_size - 1] /= md_data[*x_size - 1];
    for (scalarLB = nxm1_tmp; scalarLB >= 2; scalarLB--) {
      s_data[scalarLB - 1] = (s_data[scalarLB - 1] - dx_data[scalarLB - 2] *
        s_data[scalarLB]) / md_data[scalarLB - 1];
    }

    s_data[0] = (s_data[0] - d31 * s_data[1]) / md_data[0];
    for (scalarLB = 0; scalarLB <= d_tmp; scalarLB++) {
      r = dvdf_data[scalarLB];
      szdvdf_idx_0 = s_data[scalarLB];
      dnnm2 = dx_data[scalarLB];
      d31 = (r - szdvdf_idx_0) / dnnm2;
      r = (s_data[scalarLB + 1] - r) / dnnm2;
      g_coefs_data[scalarLB] = (r - d31) / dnnm2;
      g_coefs_data[(s_size_idx_1 + scalarLB) - 1] = 2.0 * d31 - r;
      g_coefs_data[((s_size_idx_1 - 1) << 1) + scalarLB] = szdvdf_idx_0;
      g_coefs_data[3 * (s_size_idx_1 - 1) + scalarLB] = y_data[(yoffset +
        scalarLB) + 1];
    }

    output_breaks_size[0] = 1;
    output_breaks_size[1] = *x_size;
    memcpy(&output_breaks_data[0], &x_data[0], (uint32_T)*x_size * sizeof(real_T));
    output_coefs_size[0] = s_size_idx_1 - 1;
    output_coefs_size[1] = 4;
    nxm1 = (s_size_idx_1 - 1) << 2;
    if (nxm1 - 1 >= 0) {
      memcpy(&output_coefs_data[0], &g_coefs_data[0], (uint32_T)nxm1 * sizeof
             (real_T));
    }
  }
}

static void Catwell_Rom_bsxfun(const real_T a_data[], const int32_T a_size[2],
  real_T c_data[], int32_T c_size[2])
{
  int32_T k;
  int32_T k_0;
  c_size[0] = a_size[0];
  c_size[1] = 3;
  if (a_size[0] != 0) {
    int32_T acoef;
    acoef = (a_size[0] != 1);
    for (k = 0; k < 3; k++) {
      int32_T d;
      d = c_size[0];
      for (k_0 = 0; k_0 < d; k_0++) {
        c_data[k_0 + c_size[0] * k] = a_data[acoef * k_0 + a_size[0] * k] * (3.0
          - (real_T)k);
      }
    }
  }
}

static void Catwell_Rom_linspace(real_T d2, real_T n,
  emxArray_real_T_Catwell_Rom_T *y)
{
  real_T delta1;
  int32_T d_k;
  int32_T g;
  if (!(n >= 0.0)) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    delta1 = floor(n);
    d_k = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int32_T)delta1;
    Catwel_emxEnsureCapacity_real_T(y, d_k);
    if ((int32_T)delta1 >= 1) {
      y->data[(int32_T)delta1 - 1] = d2;
      if (y->size[1] >= 2) {
        y->data[0] = 0.0;
        if (y->size[1] >= 3) {
          if (-d2 == 0.0) {
            delta1 = d2 / ((real_T)y->size[1] - 1.0);
            g = y->size[1];
            for (d_k = 2; d_k < g; d_k++) {
              y->data[d_k - 1] = ((real_T)((d_k << 1) - y->size[1]) - 1.0) *
                delta1;
            }

            if ((y->size[1] & 1) == 1) {
              y->data[y->size[1] >> 1] = 0.0;
            }
          } else if ((d2 < 0.0) && (fabs(d2) > 8.9884656743115785E+307)) {
            delta1 = d2 / ((real_T)y->size[1] - 1.0);
            g = y->size[1] - 3;
            for (d_k = 0; d_k <= g; d_k++) {
              y->data[d_k + 1] = ((real_T)d_k + 1.0) * delta1;
            }
          } else {
            delta1 = d2 / ((real_T)y->size[1] - 1.0);
            g = y->size[1] - 3;
            for (d_k = 0; d_k <= g; d_k++) {
              y->data[d_k + 1] = ((real_T)d_k + 1.0) * delta1;
            }
          }
        }
      }
    }
  }
}

static int32_T Catwell_Rom_bsearch(const real_T x_data[], const int32_T x_size[2],
  real_T xi)
{
  int32_T high_i;
  int32_T low_ip1;
  int32_T n;
  n = 1;
  low_ip1 = 1;
  high_i = x_size[1];
  while (high_i > low_ip1 + 1) {
    int32_T mid_i;
    mid_i = (n >> 1) + (high_i >> 1);
    if (((n & 1) == 1) && ((high_i & 1) == 1)) {
      mid_i++;
    }

    if (xi >= x_data[mid_i - 1]) {
      n = mid_i;
      low_ip1 = mid_i;
    } else {
      high_i = mid_i;
    }
  }

  return n;
}

static void Catwell_Rom_ppval(const real_T pp_breaks_data[], const int32_T
  pp_breaks_size[2], const real_T pp_coefs_data[], const int32_T pp_coefs_size[2],
  const real_T x_data[], const int32_T x_size[2], real_T v_data[], int32_T
  v_size[2])
{
  real_T x;
  real_T xloc;
  int32_T b;
  int32_T b_ix;
  int32_T ic;
  int32_T ip;
  int32_T numTerms;
  numTerms = pp_coefs_size[1];
  v_size[0] = 1;
  v_size[1] = x_size[1];
  b = x_size[1] - 1;
  for (b_ix = 0; b_ix <= b; b_ix++) {
    x = x_data[b_ix];
    if (!rtIsNaN(x)) {
      ip = Catwell_Rom_bsearch(pp_breaks_data, pp_breaks_size, x) - 1;
      xloc = x - pp_breaks_data[ip];
      x = pp_coefs_data[ip];
      for (ic = 2; ic <= numTerms; ic++) {
        x = pp_coefs_data[(ic - 1) * (pp_breaks_size[1] - 1) + ip] + xloc * x;
      }
    }

    v_data[b_ix] = x;
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

static void Catwell_Rom_expand_atan2(const real_T a_data[], const int32_T
  a_size[2], const real_T b_data[], const int32_T b_size[2], real_T c_data[],
  int32_T c_size[2])
{
  int32_T csz_idx_1;
  int32_T k;
  boolean_T d;
  boolean_T e;
  if (b_size[1] == 1) {
    csz_idx_1 = a_size[1];
  } else if (a_size[1] == 1) {
    csz_idx_1 = b_size[1];
  } else if (a_size[1] <= b_size[1]) {
    csz_idx_1 = a_size[1];
  } else {
    csz_idx_1 = b_size[1];
  }

  c_size[0] = 1;
  c_size[1] = csz_idx_1;
  if (csz_idx_1 != 0) {
    d = (a_size[1] != 1);
    e = (b_size[1] != 1);
    for (k = 0; k < csz_idx_1; k++) {
      c_data[k] = rt_atan2d_snf(a_data[d * k], b_data[e * k]);
    }
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void Catwell_Rom_emxFree_real_T(emxArray_real_T_Catwell_Rom_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T_Catwell_Rom_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_real_T_Catwell_Rom_T *)NULL;
  }
}

static void Catwell_R_binary_expand_op_ia3x(emxArray_real_T_Catwell_Rom_T *in1,
  const emxArray_real_T_Catwell_Rom_T *in3)
{
  emxArray_real_T_Catwell_Rom_T *tmp;
  real_T varargin_1;
  real_T varargin_1_0;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  Catwell_Rom_emxInit_real_T(&tmp, 2);
  i = tmp->size[0] * tmp->size[1];
  tmp->size[0] = 1;
  loop_ub = in3->size[1] == 1 ? in1->size[1] : in3->size[1];
  tmp->size[1] = loop_ub;
  Catwel_emxEnsureCapacity_real_T(tmp, i);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_1 = (in3->size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = in1->data[i * stride_0_1];
    varargin_1_0 = in3->data[i * stride_1_1];
    tmp->data[i] = varargin_1 * varargin_1 + varargin_1_0 * varargin_1_0;
  }

  i = in1->size[0] * in1->size[1];
  in1->size[0] = 1;
  in1->size[1] = tmp->size[1];
  Catwel_emxEnsureCapacity_real_T(in1, i);
  loop_ub = tmp->size[1];
  if (loop_ub - 1 >= 0) {
    memcpy(&in1->data[0], &tmp->data[0], (uint32_T)loop_ub * sizeof(real_T));
  }

  Catwell_Rom_emxFree_real_T(&tmp);
}

static void Catwell_Rom_cumtrapz(const emxArray_real_T_Catwell_Rom_T *x,
  emxArray_real_T_Catwell_Rom_T *z)
{
  real_T s;
  real_T x_0;
  real_T ylast;
  int32_T c;
  int32_T ylast_tmp;
  ylast_tmp = z->size[0] * z->size[1];
  z->size[0] = 1;
  z->size[1] = x->size[1];
  Catwel_emxEnsureCapacity_real_T(z, ylast_tmp);
  if (x->size[1] != 0) {
    s = 0.0;
    ylast = x->data[0];
    z->data[0] = 0.0;
    c = x->size[1] - 1;
    for (ylast_tmp = 0; ylast_tmp < c; ylast_tmp++) {
      x_0 = x->data[ylast_tmp + 1];
      s += (x_0 + ylast) / 2.0;
      ylast = x_0;
      z->data[ylast_tmp + 1] = s;
    }
  }
}

static void Cat_computeCumulativePathLength(const real_T splineDx_breaks_data[],
  const int32_T splineDx_breaks_size[2], const real_T splineDx_coefs_data[],
  const real_T splineDy_breaks_data[], const int32_T splineDy_breaks_size[2],
  const real_T splineDy_coefs_data[], const real_T tQuery_data[], const int32_T
  tQuery_size[2], real_T cumLengths_data[], int32_T cumLengths_size[2])
{
  __m128d tmp;
  __m128d tmp_0;
  emxArray_real_T_Catwell_Rom_T *intervalcumPathLength;
  emxArray_real_T_Catwell_Rom_T *tInteg;
  emxArray_real_T_Catwell_Rom_T *v;
  real_T stepSize;
  real_T tSpacing;
  real_T varargin_1;
  real_T xloc;
  int32_T tmp_data[10];
  int32_T b_ix;
  int32_T ip;
  int32_T nx;
  int32_T vectorUB;
  int8_T y_data[9];
  tSpacing = tQuery_data[1] - tQuery_data[0];
  stepSize = tSpacing / fmax(ceil(tSpacing / 0.01), 10.0);
  tSpacing = rt_roundd_snf(tSpacing / stepSize);
  Catwell_Rom_emxInit_real_T(&tInteg, 2);
  Catwell_Rom_linspace(tQuery_data[tQuery_size[1] - 1], ((real_T)tQuery_size[1]
    - 1.0) * tSpacing + 1.0, tInteg);
  Catwell_Rom_emxInit_real_T(&intervalcumPathLength, 2);
  b_ix = intervalcumPathLength->size[0] * intervalcumPathLength->size[1];
  intervalcumPathLength->size[0] = 1;
  intervalcumPathLength->size[1] = tInteg->size[1];
  Catwel_emxEnsureCapacity_real_T(intervalcumPathLength, b_ix);
  nx = tInteg->size[1] - 1;
  Catwell_Rom_emxInit_real_T(&v, 2);
  b_ix = v->size[0] * v->size[1];
  v->size[0] = 1;
  v->size[1] = tInteg->size[1];
  Catwel_emxEnsureCapacity_real_T(v, b_ix);
  for (b_ix = 0; b_ix <= nx; b_ix++) {
    xloc = tInteg->data[b_ix];
    if (rtIsNaN(xloc)) {
      intervalcumPathLength->data[b_ix] = xloc;
    } else {
      ip = Catwell_Rom_bsearch(splineDx_breaks_data, splineDx_breaks_size, xloc)
        - 1;
      xloc -= splineDx_breaks_data[ip];
      intervalcumPathLength->data[b_ix] = (splineDx_coefs_data[(ip +
        splineDx_breaks_size[1]) - 1] + splineDx_coefs_data[ip] * xloc) * xloc +
        splineDx_coefs_data[((splineDx_breaks_size[1] - 1) << 1) + ip];
    }

    xloc = tInteg->data[b_ix];
    if (rtIsNaN(xloc)) {
      v->data[b_ix] = xloc;
    } else {
      ip = Catwell_Rom_bsearch(splineDy_breaks_data, splineDy_breaks_size, xloc)
        - 1;
      xloc -= splineDy_breaks_data[ip];
      v->data[b_ix] = (splineDy_coefs_data[(ip + splineDy_breaks_size[1]) - 1] +
                       splineDy_coefs_data[ip] * xloc) * xloc +
        splineDy_coefs_data[((splineDy_breaks_size[1] - 1) << 1) + ip];
    }
  }

  if (intervalcumPathLength->size[1] == v->size[1]) {
    b_ix = intervalcumPathLength->size[0] * intervalcumPathLength->size[1];
    intervalcumPathLength->size[0] = 1;
    Catwel_emxEnsureCapacity_real_T(intervalcumPathLength, b_ix);
    ip = (tInteg->size[1] / 2) << 1;
    vectorUB = ip - 2;
    for (b_ix = 0; b_ix <= vectorUB; b_ix += 2) {
      tmp = _mm_loadu_pd(&intervalcumPathLength->data[b_ix]);
      tmp_0 = _mm_loadu_pd(&v->data[b_ix]);
      _mm_storeu_pd(&intervalcumPathLength->data[b_ix], _mm_add_pd(_mm_mul_pd
        (tmp, tmp), _mm_mul_pd(tmp_0, tmp_0)));
    }

    for (b_ix = ip; b_ix <= nx; b_ix++) {
      xloc = intervalcumPathLength->data[b_ix];
      varargin_1 = v->data[b_ix];
      intervalcumPathLength->data[b_ix] = xloc * xloc + varargin_1 * varargin_1;
    }
  } else {
    Catwell_R_binary_expand_op_ia3x(intervalcumPathLength, v);
  }

  b_ix = tInteg->size[0] * tInteg->size[1];
  tInteg->size[0] = 1;
  tInteg->size[1] = intervalcumPathLength->size[1];
  Catwel_emxEnsureCapacity_real_T(tInteg, b_ix);
  nx = intervalcumPathLength->size[1];
  if (nx - 1 >= 0) {
    memcpy(&tInteg->data[0], &intervalcumPathLength->data[0], (uint32_T)nx *
           sizeof(real_T));
  }

  nx = intervalcumPathLength->size[1] - 1;
  ip = (intervalcumPathLength->size[1] / 2) << 1;
  vectorUB = ip - 2;
  for (b_ix = 0; b_ix <= vectorUB; b_ix += 2) {
    tmp = _mm_loadu_pd(&tInteg->data[b_ix]);
    _mm_storeu_pd(&tInteg->data[b_ix], _mm_sqrt_pd(tmp));
  }

  for (b_ix = ip; b_ix <= nx; b_ix++) {
    tInteg->data[b_ix] = sqrt(tInteg->data[b_ix]);
  }

  Catwell_Rom_cumtrapz(tInteg, v);
  Catwell_Rom_emxFree_real_T(&tInteg);
  b_ix = intervalcumPathLength->size[0] * intervalcumPathLength->size[1];
  intervalcumPathLength->size[0] = 1;
  intervalcumPathLength->size[1] = v->size[1];
  Catwel_emxEnsureCapacity_real_T(intervalcumPathLength, b_ix);
  nx = v->size[1];
  ip = (v->size[1] / 2) << 1;
  vectorUB = ip - 2;
  for (b_ix = 0; b_ix <= vectorUB; b_ix += 2) {
    tmp = _mm_loadu_pd(&v->data[b_ix]);
    _mm_storeu_pd(&intervalcumPathLength->data[b_ix], _mm_mul_pd(_mm_set1_pd
      (stepSize), tmp));
  }

  for (b_ix = ip; b_ix < nx; b_ix++) {
    intervalcumPathLength->data[b_ix] = stepSize * v->data[b_ix];
  }

  Catwell_Rom_emxFree_real_T(&v);
  if (tQuery_size[1] - 1 < 1) {
    ip = 0;
  } else {
    ip = tQuery_size[1] - 1;
    nx = tQuery_size[1] - 2;
    for (b_ix = 0; b_ix <= nx; b_ix++) {
      y_data[b_ix] = (int8_T)(b_ix + 1);
    }
  }

  cumLengths_size[0] = 1;
  cumLengths_size[1] = ip + 1;
  nx = ip + 1;
  tmp_data[0] = 0;
  for (b_ix = 0; b_ix < ip; b_ix++) {
    tmp_data[b_ix + 1] = (int32_T)(tSpacing * (real_T)y_data[b_ix] + 1.0) - 1;
  }

  for (b_ix = 0; b_ix < nx; b_ix++) {
    cumLengths_data[b_ix] = intervalcumPathLength->data[tmp_data[b_ix]];
  }

  Catwell_Rom_emxFree_real_T(&intervalcumPathLength);
}

static void Catwell_Rom_bsxfun_i(const real_T a_data[], const int32_T a_size[2],
  real_T c_data[], int32_T c_size[2])
{
  int32_T acoef;
  int32_T k;
  int32_T k_0;
  c_size[0] = a_size[0];
  c_size[1] = 2;
  acoef = (a_size[0] != 1);
  for (k = 0; k < 2; k++) {
    int32_T d;
    d = c_size[0];
    for (k_0 = 0; k_0 < d; k_0++) {
      c_data[k_0 + c_size[0] * k] = a_data[acoef * k_0 + a_size[0] * k] * (2.0 -
        (real_T)k);
    }
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    real_T tmp;
    real_T tmp_0;
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static void Catwell__binary_expand_op_ia3xt(real_T in1_data[], int32_T in1_size
  [2], const emxArray_real_T_Catwell_Rom_T *in2, const
  emxArray_real_T_Catwell_Rom_T *in3, const real_T in4_data[], const int32_T
  in4_size[2], const emxArray_real_T_Catwell_Rom_T *in6, const
  emxArray_real_T_Catwell_Rom_T *in7)
{
  real_T in2_data[10];
  real_T tmp_data[10];
  real_T varargin_1;
  real_T varargin_1_0;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T stride_2_1;
  int32_T stride_3_1;
  int32_T tmp_size_idx_1;
  loop_ub = in7->size[1] == 1 ? in6->size[1] : in7->size[1];
  tmp_size_idx_1 = loop_ub;
  stride_0_1 = (in6->size[1] != 1);
  stride_1_1 = (in7->size[1] != 1);
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = in6->data[i * stride_0_1];
    varargin_1_0 = in7->data[i * stride_1_1];
    tmp_data[i] = varargin_1 * varargin_1 + varargin_1_0 * varargin_1_0;
  }

  i = in4_size[1] == 1 ? in3->size[1] : in4_size[1];
  loop_ub = loop_ub == 1 ? i == 1 ? in1_size[1] == 1 ? in2->size[1] : in1_size[1]
    : i : loop_ub;
  stride_0_1 = (in2->size[1] != 1);
  stride_1_1 = (in1_size[1] != 1);
  stride_2_1 = (in3->size[1] != 1);
  stride_3_1 = (in4_size[1] != 1);
  tmp_size_idx_1 = (tmp_size_idx_1 != 1);
  for (i = 0; i < loop_ub; i++) {
    in2_data[i] = (in2->data[i * stride_0_1] * in1_data[i * stride_1_1] -
                   in3->data[i * stride_2_1] * in4_data[i * stride_3_1]) /
      rt_powd_snf(tmp_data[i * tmp_size_idx_1], 1.5);
  }

  in1_size[0] = 1;
  in1_size[1] = loop_ub;
  if (loop_ub - 1 >= 0) {
    memcpy(&in1_data[0], &in2_data[0], (uint32_T)loop_ub * sizeof(real_T));
  }
}

static void Catwell_R_computePathCurvatures(const real_T splineDx_breaks_data[],
  const int32_T splineDx_breaks_size[2], const real_T splineDx_coefs_data[],
  const int32_T splineDx_coefs_size[3], const real_T splineDy_breaks_data[],
  const int32_T splineDy_breaks_size[2], const real_T splineDy_coefs_data[],
  const int32_T splineDy_coefs_size[3], const real_T tQuery_data[], const
  int32_T tQuery_size[2], real_T curvatures_data[], int32_T curvatures_size[2])
{
  emxArray_real_T_Catwell_Rom_T *v;
  emxArray_real_T_Catwell_Rom_T *v_0;
  emxArray_real_T_Catwell_Rom_T *v_1;
  emxArray_real_T_Catwell_Rom_T *v_2;
  real_T splineD2x_coefs_data[42];
  real_T splineDx_coefs_data_0[42];
  real_T tmp_data[42];
  real_T splineDx_breaks_data_0[22];
  real_T e_data[10];
  real_T xloc;
  real_T xloc_tmp;
  int32_T e_size[2];
  int32_T splineDx_breaks_size_0[2];
  int32_T splineDx_coefs_size_0[2];
  int32_T tmp_size[2];
  int32_T emptyDimValue;
  int32_T ip;
  int32_T loop_ub_tmp;
  int32_T nx_tmp;
  emptyDimValue = (int32_T)((uint32_T)(splineDx_coefs_size[1] * 3) / 3U);
  splineDx_coefs_size_0[0] = emptyDimValue;
  splineDx_coefs_size_0[1] = 2;
  for (ip = 0; ip < 2; ip++) {
    for (nx_tmp = 0; nx_tmp < emptyDimValue; nx_tmp++) {
      splineDx_coefs_data_0[nx_tmp + emptyDimValue * ip] =
        splineDx_coefs_data[splineDx_coefs_size[1] * ip + nx_tmp];
    }
  }

  Catwell_Rom_bsxfun_i(splineDx_coefs_data_0, splineDx_coefs_size_0, tmp_data,
                       tmp_size);
  loop_ub_tmp = (splineDx_breaks_size[1] - 1) << 1;
  if (loop_ub_tmp - 1 >= 0) {
    memcpy(&splineD2x_coefs_data[0], &tmp_data[0], (uint32_T)loop_ub_tmp *
           sizeof(real_T));
  }

  emptyDimValue = (int32_T)((uint32_T)(splineDy_coefs_size[1] * 3) / 3U);
  splineDx_coefs_size_0[0] = emptyDimValue;
  splineDx_coefs_size_0[1] = 2;
  for (ip = 0; ip < 2; ip++) {
    for (nx_tmp = 0; nx_tmp < emptyDimValue; nx_tmp++) {
      splineDx_coefs_data_0[nx_tmp + emptyDimValue * ip] =
        splineDy_coefs_data[splineDy_coefs_size[1] * ip + nx_tmp];
    }
  }

  Catwell_Rom_bsxfun_i(splineDx_coefs_data_0, splineDx_coefs_size_0, tmp_data,
                       tmp_size);
  if (loop_ub_tmp - 1 >= 0) {
    memcpy(&splineDx_coefs_data_0[0], &tmp_data[0], (uint32_T)loop_ub_tmp *
           sizeof(real_T));
  }

  Catwell_Rom_emxInit_real_T(&v, 2);
  emptyDimValue = v->size[0] * v->size[1];
  v->size[0] = 1;
  v->size[1] = tQuery_size[1];
  Catwel_emxEnsureCapacity_real_T(v, emptyDimValue);
  nx_tmp = tQuery_size[1] - 1;
  curvatures_size[0] = 1;
  curvatures_size[1] = tQuery_size[1];
  Catwell_Rom_emxInit_real_T(&v_0, 2);
  emptyDimValue = v_0->size[0] * v_0->size[1];
  v_0->size[0] = 1;
  v_0->size[1] = tQuery_size[1];
  Catwel_emxEnsureCapacity_real_T(v_0, emptyDimValue);
  e_size[0] = 1;
  e_size[1] = tQuery_size[1];
  Catwell_Rom_emxInit_real_T(&v_1, 2);
  emptyDimValue = v_1->size[0] * v_1->size[1];
  v_1->size[0] = 1;
  v_1->size[1] = tQuery_size[1];
  Catwel_emxEnsureCapacity_real_T(v_1, emptyDimValue);
  Catwell_Rom_emxInit_real_T(&v_2, 2);
  emptyDimValue = v_2->size[0] * v_2->size[1];
  v_2->size[0] = 1;
  v_2->size[1] = tQuery_size[1];
  Catwel_emxEnsureCapacity_real_T(v_2, emptyDimValue);
  for (emptyDimValue = 0; emptyDimValue <= nx_tmp; emptyDimValue++) {
    xloc_tmp = tQuery_data[emptyDimValue];
    if (rtIsNaN(xloc_tmp)) {
      v->data[emptyDimValue] = xloc_tmp;
    } else {
      ip = Catwell_Rom_bsearch(splineDx_breaks_data, splineDx_breaks_size,
        xloc_tmp) - 1;
      xloc = xloc_tmp - splineDx_breaks_data[ip];
      v->data[emptyDimValue] = (splineDx_coefs_data[(ip + splineDx_breaks_size[1])
        - 1] + splineDx_coefs_data[ip] * xloc) * xloc +
        splineDx_coefs_data[loop_ub_tmp + ip];
    }

    if (rtIsNaN(xloc_tmp)) {
      curvatures_data[emptyDimValue] = xloc_tmp;
    } else {
      ip = splineDx_breaks_size[1];
      splineDx_breaks_size_0[0] = 1;
      splineDx_breaks_size_0[1] = splineDx_breaks_size[1];
      if (ip - 1 >= 0) {
        memcpy(&splineDx_breaks_data_0[0], &splineDx_breaks_data[0], (uint32_T)
               ip * sizeof(real_T));
      }

      ip = Catwell_Rom_bsearch(splineDx_breaks_data_0, splineDx_breaks_size_0,
        xloc_tmp) - 1;
      curvatures_data[emptyDimValue] = (xloc_tmp - splineDx_breaks_data[ip]) *
        splineDx_coefs_data_0[ip] + splineDx_coefs_data_0[(ip +
        splineDx_breaks_size[1]) - 1];
    }

    if (rtIsNaN(xloc_tmp)) {
      v_0->data[emptyDimValue] = xloc_tmp;
    } else {
      ip = Catwell_Rom_bsearch(splineDy_breaks_data, splineDy_breaks_size,
        xloc_tmp) - 1;
      xloc = xloc_tmp - splineDy_breaks_data[ip];
      v_0->data[emptyDimValue] = (splineDy_coefs_data[(ip +
        splineDy_breaks_size[1]) - 1] + splineDy_coefs_data[ip] * xloc) * xloc +
        splineDy_coefs_data[((splineDy_breaks_size[1] - 1) << 1) + ip];
    }

    if (rtIsNaN(xloc_tmp)) {
      e_data[emptyDimValue] = xloc_tmp;
    } else {
      ip = splineDx_breaks_size[1];
      splineDx_breaks_size_0[0] = 1;
      splineDx_breaks_size_0[1] = splineDx_breaks_size[1];
      if (ip - 1 >= 0) {
        memcpy(&splineDx_breaks_data_0[0], &splineDx_breaks_data[0], (uint32_T)
               ip * sizeof(real_T));
      }

      ip = Catwell_Rom_bsearch(splineDx_breaks_data_0, splineDx_breaks_size_0,
        xloc_tmp) - 1;
      e_data[emptyDimValue] = (xloc_tmp - splineDx_breaks_data[ip]) *
        splineD2x_coefs_data[ip] + splineD2x_coefs_data[(ip +
        splineDx_breaks_size[1]) - 1];
    }

    if (rtIsNaN(xloc_tmp)) {
      v_1->data[emptyDimValue] = xloc_tmp;
    } else {
      ip = Catwell_Rom_bsearch(splineDx_breaks_data, splineDx_breaks_size,
        xloc_tmp) - 1;
      xloc = xloc_tmp - splineDx_breaks_data[ip];
      v_1->data[emptyDimValue] = (splineDx_coefs_data[(ip +
        splineDx_breaks_size[1]) - 1] + splineDx_coefs_data[ip] * xloc) * xloc +
        splineDx_coefs_data[loop_ub_tmp + ip];
    }

    if (rtIsNaN(xloc_tmp)) {
      v_2->data[emptyDimValue] = xloc_tmp;
    } else {
      ip = Catwell_Rom_bsearch(splineDy_breaks_data, splineDy_breaks_size,
        xloc_tmp) - 1;
      xloc = xloc_tmp - splineDy_breaks_data[ip];
      v_2->data[emptyDimValue] = (splineDy_coefs_data[(ip +
        splineDy_breaks_size[1]) - 1] + splineDy_coefs_data[ip] * xloc) * xloc +
        splineDy_coefs_data[((splineDy_breaks_size[1] - 1) << 1) + ip];
    }
  }

  if ((v->size[1] == tQuery_size[1]) && (v_0->size[1] == tQuery_size[1]) &&
      (v_1->size[1] == v_2->size[1])) {
    curvatures_size[0] = 1;
    curvatures_size[1] = v->size[1];
    for (ip = 0; ip <= nx_tmp; ip++) {
      xloc = v_1->data[ip];
      xloc_tmp = v_2->data[ip];
      curvatures_data[ip] = (v->data[ip] * curvatures_data[ip] - v_0->data[ip] *
        e_data[ip]) / rt_powd_snf(xloc * xloc + xloc_tmp * xloc_tmp, 1.5);
    }
  } else {
    Catwell__binary_expand_op_ia3xt(curvatures_data, curvatures_size, v, v_0,
      e_data, e_size, v_1, v_2);
  }

  Catwell_Rom_emxFree_real_T(&v_2);
  Catwell_Rom_emxFree_real_T(&v_1);
  Catwell_Rom_emxFree_real_T(&v_0);
  Catwell_Rom_emxFree_real_T(&v);
}

static void Catwell_Rom_smoothPathSpline(real_T refPoses_data[], int32_T
  refPoses_size[2], const real_T refDirections_data[], const int32_T
  *refDirections_size, real_T poses[30], real_T directions[10], real_T
  varargout_1[10], real_T varargout_2[10])
{
  __m128d tmp;
  emxArray_real_T_Catwell_Rom_T *v;
  emxArray_real_T_Catwell_Rom_T *v_0;
  real_T splineDx_coefs_data[63];
  real_T splineX_coefs_data_0[63];
  real_T tmp_data_2[63];
  real_T splineX_coefs_data[48];
  real_T splineY_coefs_data[48];
  real_T refPoses_data_0[33];
  real_T posesSeg_data[30];
  real_T cumChordLength_data[22];
  real_T splineDy_breaks_data[22];
  real_T splineX_breaks_data[22];
  real_T splineY_breaks_data[22];
  real_T tInterp_data[22];
  real_T tmp_data_0[13];
  real_T tmp_data_1[13];
  real_T chordLengthOfSegments_data[12];
  real_T numPosesSeg_data[12];
  real_T segEndIdx_data[12];
  real_T segStartIdx_data[12];
  real_T b_refDirections_data[11];
  real_T tmp_data[11];
  real_T tQuery_data[10];
  real_T theta_data[10];
  real_T theta_data_0[10];
  real_T x_data[10];
  real_T y_data[10];
  real_T q;
  real_T segEndIdx;
  real_T startIdx;
  real_T xloc;
  int32_T splineDx_coefs_size[3];
  int32_T splineDy_coefs_size[3];
  int32_T refPoses_size_0[2];
  int32_T refPoses_size_1[2];
  int32_T splineDx_breaks_size[2];
  int32_T splineDy_breaks_size[2];
  int32_T splineX_breaks_size[2];
  int32_T splineX_coefs_size[2];
  int32_T splineX_coefs_size_0[2];
  int32_T tQuery_size[2];
  int32_T theta_size[2];
  int32_T theta_size_0[2];
  int32_T tmp_size[2];
  int32_T b_refDirections_size;
  int32_T i;
  int32_T l;
  int32_T loop_ub;
  int32_T nx;
  int32_T nx_tmp;
  int32_T refPoses;
  int32_T segEndIdx_size;
  int32_T segStartIdx_size;
  int32_T tmp_data_tmp;
  int32_T vlen;
  boolean_T rEQ0;
  refPoses_size_1[0] = refPoses_size[0];
  refPoses_size_1[1] = refPoses_size[1];
  loop_ub = refPoses_size[0] * refPoses_size[1] - 1;
  if (loop_ub >= 0) {
    memcpy(&posesSeg_data[0], &refPoses_data[0], (uint32_T)(loop_ub + 1) *
           sizeof(real_T));
  }

  Catwell_Rom_filterPoses(posesSeg_data, refPoses_size_1, refDirections_data,
    refDirections_size, refPoses_data, refPoses_size, b_refDirections_data,
    &b_refDirections_size);
  Ca_getSegmentBoundaryPointIndex(b_refDirections_data, &b_refDirections_size,
    segStartIdx_data, &segStartIdx_size, segEndIdx_data, &segEndIdx_size);
  segEndIdx_size = refPoses_size[0];
  loop_ub = refPoses_size[0];
  vlen = (refPoses_size[0] / 2) << 1;
  b_refDirections_size = vlen - 2;
  for (nx_tmp = 0; nx_tmp <= b_refDirections_size; nx_tmp += 2) {
    tmp = _mm_loadu_pd(&refPoses_data[(refPoses_size[0] << 1) + nx_tmp]);
    _mm_storeu_pd(&tmp_data[nx_tmp], _mm_mul_pd(_mm_set1_pd(0.017453292519943295),
      tmp));
  }

  for (nx_tmp = vlen; nx_tmp < loop_ub; nx_tmp++) {
    tmp_data[nx_tmp] = refPoses_data[(refPoses_size[0] << 1) + nx_tmp] *
      0.017453292519943295;
  }

  for (nx_tmp = 0; nx_tmp < segEndIdx_size; nx_tmp++) {
    refPoses_data[nx_tmp + (refPoses_size[0] << 1)] = tmp_data[nx_tmp];
  }

  memset(&poses[0], 0, 30U * sizeof(real_T));
  memset(&directions[0], 0, 10U * sizeof(real_T));
  loop_ub = (refPoses_size[0] + segStartIdx_size) - 1;
  if (loop_ub - 1 >= 0) {
    memset(&cumChordLength_data[0], 0, (uint32_T)loop_ub * sizeof(real_T));
  }

  memset(&varargout_1[0], 0, 10U * sizeof(real_T));
  memset(&varargout_2[0], 0, 10U * sizeof(real_T));
  i = segStartIdx_size - 1;
  refPoses = refPoses_size[1];
  for (segEndIdx_size = 0; segEndIdx_size <= i; segEndIdx_size++) {
    xloc = segStartIdx_data[segEndIdx_size];
    segEndIdx = segEndIdx_data[segEndIdx_size];
    if (xloc > segEndIdx) {
      vlen = 0;
      b_refDirections_size = 0;
    } else {
      vlen = (int32_T)xloc - 1;
      b_refDirections_size = (int32_T)segEndIdx;
    }

    xloc = (((real_T)segEndIdx_size + 1.0) + xloc) - 1.0;
    segEndIdx = (((real_T)segEndIdx_size + 1.0) + segEndIdx) - 1.0;
    if (xloc > segEndIdx) {
      nx = 0;
      l = 0;
    } else {
      nx = (int32_T)xloc - 1;
      l = (int32_T)segEndIdx;
    }

    loop_ub = b_refDirections_size - vlen;
    refPoses_size_0[0] = loop_ub;
    refPoses_size_0[1] = refPoses_size[1];
    for (nx_tmp = 0; nx_tmp < refPoses; nx_tmp++) {
      for (tmp_data_tmp = 0; tmp_data_tmp < loop_ub; tmp_data_tmp++) {
        refPoses_data_0[tmp_data_tmp + loop_ub * nx_tmp] = refPoses_data[(vlen +
          tmp_data_tmp) + refPoses_size[0] * nx_tmp];
      }
    }

    Ca_computeCumulativeChordLength(refPoses_data_0, refPoses_size_0,
      numPosesSeg_data, &b_refDirections_size);
    loop_ub = l - nx;
    for (nx_tmp = 0; nx_tmp < loop_ub; nx_tmp++) {
      cumChordLength_data[nx + nx_tmp] = numPosesSeg_data[nx_tmp];
    }

    chordLengthOfSegments_data[segEndIdx_size] = cumChordLength_data[(int32_T)
      segEndIdx - 1];
  }

  Catwel_setSegmentNumSmoothPoses(chordLengthOfSegments_data, &segStartIdx_size,
    numPosesSeg_data, &b_refDirections_size);
  Catwell_Rom_emxInit_real_T(&v, 2);
  Catwell_Rom_emxInit_real_T(&v_0, 2);
  for (segEndIdx_size = 0; segEndIdx_size <= i; segEndIdx_size++) {
    xloc = (((real_T)segEndIdx_size + 1.0) + segStartIdx_data[segEndIdx_size]) -
      1.0;
    startIdx = (((real_T)segEndIdx_size + 1.0) + segEndIdx_data[segEndIdx_size])
      - 1.0;
    if (xloc > startIdx) {
      vlen = 0;
      b_refDirections_size = 0;
    } else {
      vlen = (int32_T)xloc - 1;
      b_refDirections_size = (int32_T)startIdx;
    }

    loop_ub = b_refDirections_size - vlen;
    for (nx_tmp = 0; nx_tmp < loop_ub; nx_tmp++) {
      tInterp_data[nx_tmp] = cumChordLength_data[vlen + nx_tmp];
    }

    xloc = segStartIdx_data[segEndIdx_size];
    segEndIdx = segEndIdx_data[segEndIdx_size];
    if (xloc > segEndIdx) {
      nx = 1;
      l = 0;
    } else {
      nx = (int32_T)xloc;
      l = (int32_T)segEndIdx;
    }

    refPoses = l - nx;
    segStartIdx_size = refPoses + 3;
    segEndIdx = b_refDirections_data[(int32_T)segEndIdx - 1];
    xloc = refPoses_data[((refPoses_size[0] << 1) + nx) - 1];
    tmp_data_0[0] = cos(xloc) * segEndIdx;
    startIdx = refPoses_data[((refPoses_size[0] << 1) + l) - 1];
    l = refPoses + 3;
    tmp_data_1[0] = sin(xloc) * segEndIdx;
    for (nx_tmp = 0; nx_tmp <= refPoses; nx_tmp++) {
      tmp_data_tmp = (nx + nx_tmp) - 1;
      tmp_data_0[nx_tmp + 1] = refPoses_data[tmp_data_tmp];
      tmp_data_1[nx_tmp + 1] = refPoses_data[tmp_data_tmp + refPoses_size[0]];
    }

    tmp_data_0[refPoses + 2] = cos(startIdx) * segEndIdx;
    Catwell_Rom_spline(tInterp_data, &loop_ub, tmp_data_0, &segStartIdx_size,
                       splineX_breaks_data, splineX_breaks_size,
                       splineX_coefs_data, splineX_coefs_size);
    tmp_data_1[refPoses + 2] = sin(startIdx) * segEndIdx;
    Catwell_Rom_spline(tInterp_data, &loop_ub, tmp_data_1, &l,
                       splineY_breaks_data, refPoses_size_1, splineY_coefs_data,
                       refPoses_size_0);
    splineDx_breaks_size[0] = 1;
    splineDx_breaks_size[1] = loop_ub;
    for (nx_tmp = 0; nx_tmp < loop_ub; nx_tmp++) {
      tInterp_data[nx_tmp] = cumChordLength_data[vlen + nx_tmp];
    }

    l = (int32_T)((real_T)loop_ub - 1.0);
    splineX_coefs_size_0[0] = (int32_T)((real_T)loop_ub - 1.0);
    splineX_coefs_size_0[1] = 3;
    for (nx_tmp = 0; nx_tmp < 3; nx_tmp++) {
      for (tmp_data_tmp = 0; tmp_data_tmp < l; tmp_data_tmp++) {
        splineX_coefs_data_0[tmp_data_tmp + (int32_T)((real_T)loop_ub - 1.0) *
          nx_tmp] = splineX_coefs_data[(int32_T)((real_T)loop_ub - 1.0) * nx_tmp
          + tmp_data_tmp];
      }
    }

    Catwell_Rom_bsxfun(splineX_coefs_data_0, splineX_coefs_size_0, tmp_data_2,
                       tmp_size);
    splineDx_coefs_size[0] = 1;
    splineDx_coefs_size[1] = loop_ub - 1;
    splineDx_coefs_size[2] = 3;
    refPoses = (loop_ub - 1) * 3;
    if (refPoses - 1 >= 0) {
      memcpy(&splineDx_coefs_data[0], &tmp_data_2[0], (uint32_T)refPoses *
             sizeof(real_T));
    }

    splineDy_breaks_size[0] = 1;
    splineDy_breaks_size[1] = loop_ub;
    for (nx_tmp = 0; nx_tmp < loop_ub; nx_tmp++) {
      splineDy_breaks_data[nx_tmp] = cumChordLength_data[vlen + nx_tmp];
    }

    splineX_coefs_size_0[0] = (int32_T)((real_T)loop_ub - 1.0);
    splineX_coefs_size_0[1] = 3;
    for (nx_tmp = 0; nx_tmp < 3; nx_tmp++) {
      for (tmp_data_tmp = 0; tmp_data_tmp < l; tmp_data_tmp++) {
        splineX_coefs_data_0[tmp_data_tmp + (int32_T)((real_T)loop_ub - 1.0) *
          nx_tmp] = splineY_coefs_data[(int32_T)((real_T)loop_ub - 1.0) * nx_tmp
          + tmp_data_tmp];
      }
    }

    Catwell_Rom_bsxfun(splineX_coefs_data_0, splineX_coefs_size_0, tmp_data_2,
                       tmp_size);
    splineDy_coefs_size[0] = 1;
    splineDy_coefs_size[1] = loop_ub - 1;
    splineDy_coefs_size[2] = 3;
    if (refPoses - 1 >= 0) {
      memcpy(&splineX_coefs_data_0[0], &tmp_data_2[0], (uint32_T)refPoses *
             sizeof(real_T));
    }

    Catwell_Rom_linspace(chordLengthOfSegments_data[segEndIdx_size],
                         numPosesSeg_data[segEndIdx_size], v);
    tQuery_size[0] = 1;
    tQuery_size[1] = v->size[1];
    l = v->size[1];
    if (l - 1 >= 0) {
      memcpy(&tQuery_data[0], &v->data[0], (uint32_T)l * sizeof(real_T));
    }

    Catwell_Rom_ppval(splineX_breaks_data, splineX_breaks_size,
                      splineX_coefs_data, splineX_coefs_size, tQuery_data,
                      tQuery_size, x_data, tmp_size);
    Catwell_Rom_ppval(splineY_breaks_data, refPoses_size_1, splineY_coefs_data,
                      refPoses_size_0, tQuery_data, tQuery_size, y_data,
                      splineX_breaks_size);
    tmp_data_tmp = v->size[0] * v->size[1];
    v->size[0] = 1;
    v->size[1] = tQuery_size[1];
    Catwel_emxEnsureCapacity_real_T(v, tmp_data_tmp);
    nx_tmp = tQuery_size[1] - 1;
    tmp_data_tmp = v_0->size[0] * v_0->size[1];
    v_0->size[0] = 1;
    v_0->size[1] = tQuery_size[1];
    Catwel_emxEnsureCapacity_real_T(v_0, tmp_data_tmp);
    for (l = 0; l <= nx_tmp; l++) {
      startIdx = tQuery_data[l];
      if (rtIsNaN(startIdx)) {
        v->data[l] = startIdx;
      } else {
        nx = Catwell_Rom_bsearch(tInterp_data, splineDx_breaks_size, startIdx) -
          1;
        xloc = startIdx - cumChordLength_data[vlen + nx];
        v->data[l] = (splineDx_coefs_data[((nx + b_refDirections_size) - vlen) -
                      1] + splineDx_coefs_data[nx] * xloc) * xloc +
          splineDx_coefs_data[((loop_ub - 1) << 1) + nx];
      }

      if (rtIsNaN(startIdx)) {
        v_0->data[l] = startIdx;
      } else {
        nx = Catwell_Rom_bsearch(splineDy_breaks_data, splineDy_breaks_size,
          startIdx) - 1;
        xloc = startIdx - cumChordLength_data[vlen + nx];
        v_0->data[l] = (splineX_coefs_data_0[((nx + b_refDirections_size) - vlen)
                        - 1] + splineX_coefs_data_0[nx] * xloc) * xloc +
          splineX_coefs_data_0[((loop_ub - 1) << 1) + nx];
      }
    }

    xloc = (real_T)(segEndIdx == -1.0) * 3.1415926535897931;
    if (v_0->size[1] == v->size[1]) {
      theta_size[1] = v_0->size[1];
      loop_ub = v_0->size[1];
      for (nx_tmp = 0; nx_tmp < loop_ub; nx_tmp++) {
        theta_data[nx_tmp] = rt_atan2d_snf(v_0->data[nx_tmp], v->data[nx_tmp]);
      }
    } else {
      Catwell_Rom_expand_atan2(v_0->data, v_0->size, v->data, v->size,
        theta_data, theta_size);
    }

    theta_size_0[1] = theta_size[1];
    loop_ub = theta_size[1];
    vlen = (theta_size[1] / 2) << 1;
    b_refDirections_size = vlen - 2;
    for (nx_tmp = 0; nx_tmp <= b_refDirections_size; nx_tmp += 2) {
      tmp = _mm_loadu_pd(&theta_data[nx_tmp]);
      _mm_storeu_pd(&theta_data_0[nx_tmp], _mm_sub_pd(tmp, _mm_set1_pd(xloc)));
    }

    for (nx_tmp = vlen; nx_tmp < loop_ub; nx_tmp++) {
      theta_data_0[nx_tmp] = theta_data[nx_tmp] - xloc;
    }

    loop_ub = theta_size_0[1];
    for (nx_tmp = 0; nx_tmp < loop_ub; nx_tmp++) {
      xloc = theta_data_0[nx_tmp];
      if (rtIsNaN(xloc) || rtIsInf(xloc)) {
        startIdx = (rtNaN);
      } else if (xloc == 0.0) {
        startIdx = 0.0;
      } else {
        startIdx = fmod(xloc, 6.2831853071795862);
        rEQ0 = (startIdx == 0.0);
        if (!rEQ0) {
          q = fabs(xloc / 6.2831853071795862);
          rEQ0 = !(fabs(q - floor(q + 0.5)) > 2.2204460492503131E-16 * q);
        }

        if (rEQ0) {
          startIdx = 0.0;
        } else if (xloc < 0.0) {
          startIdx += 6.2831853071795862;
        }
      }

      theta_data[nx_tmp] = startIdx;
    }

    loop_ub = theta_size_0[1] - 1;
    for (nx_tmp = 0; nx_tmp <= loop_ub; nx_tmp++) {
      xloc = theta_data[nx_tmp];
      theta_data[nx_tmp] = (real_T)((xloc == 0.0) && (theta_data_0[nx_tmp] > 0.0))
        * 6.2831853071795862 + xloc;
    }

    l = tmp_size[1];
    loop_ub = tmp_size[1];
    if (loop_ub - 1 >= 0) {
      memcpy(&posesSeg_data[0], &x_data[0], (uint32_T)loop_ub * sizeof(real_T));
    }

    loop_ub = splineX_breaks_size[1];
    for (nx_tmp = 0; nx_tmp < loop_ub; nx_tmp++) {
      posesSeg_data[nx_tmp + tmp_size[1]] = y_data[nx_tmp];
    }

    loop_ub = theta_size[1];
    for (nx_tmp = 0; nx_tmp < loop_ub; nx_tmp++) {
      posesSeg_data[(nx_tmp + tmp_size[1]) + splineX_breaks_size[1]] =
        theta_data[nx_tmp];
    }

    xloc = numPosesSeg_data[0];
    for (b_refDirections_size = 2; b_refDirections_size <= segEndIdx_size + 1;
         b_refDirections_size++) {
      xloc += numPosesSeg_data[b_refDirections_size - 1];
    }

    startIdx = (xloc - numPosesSeg_data[segEndIdx_size]) + 1.0;
    if (startIdx > xloc) {
      vlen = 0;
    } else {
      vlen = (int32_T)startIdx - 1;
    }

    Cat_computeCumulativePathLength(tInterp_data, splineDx_breaks_size,
      splineDx_coefs_data, splineDy_breaks_data, splineDy_breaks_size,
      splineX_coefs_data_0, tQuery_data, tQuery_size, x_data, tmp_size);
    loop_ub = tmp_size[1];
    for (nx_tmp = 0; nx_tmp < loop_ub; nx_tmp++) {
      varargout_1[vlen + nx_tmp] = x_data[nx_tmp];
    }

    if (startIdx > xloc) {
      vlen = 0;
    } else {
      vlen = (int32_T)startIdx - 1;
    }

    Catwell_R_computePathCurvatures(tInterp_data, splineDx_breaks_size,
      splineDx_coefs_data, splineDx_coefs_size, splineDy_breaks_data,
      splineDy_breaks_size, splineX_coefs_data_0, splineDy_coefs_size,
      tQuery_data, tQuery_size, x_data, tmp_size);
    loop_ub = tmp_size[1];
    for (nx_tmp = 0; nx_tmp < loop_ub; nx_tmp++) {
      varargout_2[vlen + nx_tmp] = x_data[nx_tmp];
    }

    if (startIdx > xloc) {
      vlen = 0;
    } else {
      vlen = (int32_T)startIdx - 1;
    }

    for (nx_tmp = 0; nx_tmp < 3; nx_tmp++) {
      for (tmp_data_tmp = 0; tmp_data_tmp < l; tmp_data_tmp++) {
        poses[(vlen + tmp_data_tmp) + 10 * nx_tmp] = posesSeg_data[l * nx_tmp +
          tmp_data_tmp];
      }
    }

    if (startIdx > xloc) {
      vlen = 0;
    } else {
      vlen = (int32_T)startIdx - 1;
    }

    for (nx_tmp = 0; nx_tmp < l; nx_tmp++) {
      directions[vlen + nx_tmp] = segEndIdx;
    }
  }

  Catwell_Rom_emxFree_real_T(&v_0);
  Catwell_Rom_emxFree_real_T(&v);
  for (nx_tmp = 0; nx_tmp <= 8; nx_tmp += 2) {
    tmp = _mm_loadu_pd(&poses[nx_tmp + 20]);
    _mm_storeu_pd(&poses[nx_tmp + 20], _mm_mul_pd(tmp, _mm_set1_pd
      (57.295779513082323)));
  }
}

static void emxFreeStruct_driving_internal_(driving_internal_planning_Pat_T
  *pStruct)
{
  Catwell_Rom_emxFree_real_T(&pStruct->RefPosesInternal);
  Catwell_Rom_emxFree_real_T(&pStruct->RefDirectionsInternal);
}

/* Model step function */
void Catwell_Rom_step(void)
{
  real_T tmp_data[30];
  real_T tmp_data_0[11];
  real_T cumLengths[10];
  real_T curvatures[10];
  real_T rtb_Output;
  real_T rtb_Sum;
  int32_T rtb_Sum_f;
  int32_T s3_iter;
  int8_T inSize[8];
  boolean_T p;
  boolean_T p_0;
  static const int8_T b[15] = { 0, 1, 2, 4, 5, 0, 4, 6, 3, 0, 90, 0, 0, 0, -90 };

  real_T tmp_data_1[33];
  int32_T tmp_size[2];
  int32_T exitg2;
  boolean_T exitg1;
  boolean_T guard1 = false;
  if (Catwell_Rom_M->Timing.TaskCounters.TID[2] == 0) {
    /* Gain: '<S1>/Output' incorporates:
     *  RandomNumber: '<S1>/White Noise'
     */
    rtb_Output = sqrt(Catwell_Rom_P.BandLimitedWhiteNoise_Cov) /
      0.31622776601683794 * Catwell_Rom_DW.NextOutput;

    /* Outputs for Iterator SubSystem: '<Root>/For Iterator Subsystem2' incorporates:
     *  ForIterator: '<S3>/For Iterator'
     */
    for (s3_iter = 1; s3_iter <= Catwell_Rom_P.ForIterator_IterationLimit;
         s3_iter++) {
      /* Switch: '<S3>/Switch' incorporates:
       *  Constant: '<S7>/Constant'
       *  RelationalOperator: '<S7>/Compare'
       *  UnitDelay: '<S3>/Unit Delay'
       */
      if (s3_iter == Catwell_Rom_P.CompareToConstant_const) {
        rtb_Sum = rtb_Output;
      } else {
        rtb_Sum = Catwell_Rom_DW.UnitDelay_DSTATE;
      }

      /* Sum: '<S3>/Sum' incorporates:
       *  Switch: '<S3>/Switch'
       */
      rtb_Sum += (real_T)s3_iter;

      /* Update for UnitDelay: '<S3>/Unit Delay' */
      Catwell_Rom_DW.UnitDelay_DSTATE = rtb_Sum;
    }

    /* End of Outputs for SubSystem: '<Root>/For Iterator Subsystem2' */
  }

  /* Outputs for Iterator SubSystem: '<Root>/For Iterator Subsystem1' incorporates:
   *  ForIterator: '<S2>/For Iterator'
   */
  for (s3_iter = 1; s3_iter <= Catwell_Rom_P.ForIterator_IterationLimit_m;
       s3_iter++) {
    /* Sum: '<S2>/Sum' incorporates:
     *  UnitDelay: '<S2>/Unit Delay'
     */
    rtb_Sum_f = Catwell_Rom_DW.UnitDelay_DSTATE_n + s3_iter;

    /* Update for UnitDelay: '<S2>/Unit Delay' */
    Catwell_Rom_DW.UnitDelay_DSTATE_n = rtb_Sum_f;
  }

  /* End of Outputs for SubSystem: '<Root>/For Iterator Subsystem1' */
  if (Catwell_Rom_M->Timing.TaskCounters.TID[3] == 0) {
    /* MATLAB Function: '<Root>/MATLAB Function3' */
    for (s3_iter = 0; s3_iter < 15; s3_iter++) {
      tmp_data[s3_iter] = b[s3_iter];
    }

    Catwell_Rom_DW.SFunction_DIMS2[0] = 5;
    Catwell_Rom_DW.SFunction_DIMS2[1] = 3;
    Catwell_Rom_DW.SFunction_DIMS3[0] = 5;
    Catwell_Rom_DW.SFunction_DIMS3[1] = 1;

    /* MATLABSystem: '<Root>/Path Smoother Spline' incorporates:
     *  MATLAB Function: '<Root>/MATLAB Function3'
     */
    if (!Catwell_Rom_DW.obj.CacheInputSizes) {
      Catwell_Rom_DW.obj.CacheInputSizes = true;
      Catwell_Rom_DW.obj.inputVarSize[0].f1[0] = 5U;
      Catwell_Rom_DW.obj.inputVarSize[0].f1[1] = 3U;
      Catwell_Rom_DW.obj.inputVarSize[1].f1[0] = 5U;
      Catwell_Rom_DW.obj.inputVarSize[1].f1[1] = 1U;
      for (s3_iter = 0; s3_iter < 6; s3_iter++) {
        Catwell_Rom_DW.obj.inputVarSize[0].f1[s3_iter + 2] = 1U;
        Catwell_Rom_DW.obj.inputVarSize[1].f1[s3_iter + 2] = 1U;
      }
    }

    inSize[0] = 5;
    inSize[1] = 3;
    for (s3_iter = 0; s3_iter < 6; s3_iter++) {
      inSize[s3_iter + 2] = 1;
    }

    rtb_Sum_f = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Sum_f < 8)) {
      if (Catwell_Rom_DW.obj.inputVarSize[0].f1[rtb_Sum_f] != (uint32_T)
          inSize[rtb_Sum_f]) {
        for (s3_iter = 0; s3_iter < 8; s3_iter++) {
          Catwell_Rom_DW.obj.inputVarSize[0].f1[s3_iter] = (uint32_T)
            inSize[s3_iter];
        }

        exitg1 = true;
      } else {
        rtb_Sum_f++;
      }
    }

    inSize[0] = 5;
    inSize[1] = 1;
    for (s3_iter = 0; s3_iter < 6; s3_iter++) {
      inSize[s3_iter + 2] = 1;
    }

    rtb_Sum_f = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Sum_f < 8)) {
      if (Catwell_Rom_DW.obj.inputVarSize[1].f1[rtb_Sum_f] != (uint32_T)
          inSize[rtb_Sum_f]) {
        for (s3_iter = 0; s3_iter < 8; s3_iter++) {
          Catwell_Rom_DW.obj.inputVarSize[1].f1[s3_iter] = (uint32_T)
            inSize[s3_iter];
        }

        exitg1 = true;
      } else {
        rtb_Sum_f++;
      }
    }

    p = false;
    if ((Catwell_Rom_DW.obj.RefPosesInternal->size[0] != 5) ||
        (Catwell_Rom_DW.obj.RefPosesInternal->size[1] != 3)) {
    } else if ((Catwell_Rom_DW.obj.RefPosesInternal->size[0] != 0) &&
               (Catwell_Rom_DW.obj.RefPosesInternal->size[1] != 0)) {
      rtb_Sum_f = 0;
      do {
        exitg2 = 0;
        if (rtb_Sum_f <= Catwell_Rom_DW.obj.RefPosesInternal->size[0] *
            Catwell_Rom_DW.obj.RefPosesInternal->size[1] - 1) {
          if (Catwell_Rom_DW.obj.RefPosesInternal->data[rtb_Sum_f] == (int8_T)
              tmp_data[rtb_Sum_f]) {
            rtb_Sum_f++;
          } else {
            exitg2 = 1;
          }
        } else {
          p = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);
    } else {
      p = true;
    }

    guard1 = false;
    if (p) {
      p = false;
      p_0 = false;
      if (Catwell_Rom_DW.obj.RefDirectionsInternal->size[0] == 5) {
        p_0 = true;
      }

      if (p_0 && (Catwell_Rom_DW.obj.RefDirectionsInternal->size[0] != 0)) {
        rtb_Sum_f = 0;
        exitg1 = false;
        while ((!exitg1) && (rtb_Sum_f <=
                             Catwell_Rom_DW.obj.RefDirectionsInternal->size[0] -
                             1)) {
          if (Catwell_Rom_DW.obj.RefDirectionsInternal->data[rtb_Sum_f] == 1.0)
          {
            rtb_Sum_f++;
          } else {
            p_0 = false;
            exitg1 = true;
          }
        }
      }

      if (p_0) {
        p = true;
      }

      if (p) {
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      s3_iter = Catwell_Rom_DW.obj.RefPosesInternal->size[0] *
        Catwell_Rom_DW.obj.RefPosesInternal->size[1];
      Catwell_Rom_DW.obj.RefPosesInternal->size[0] = 5;
      Catwell_Rom_DW.obj.RefPosesInternal->size[1] = 3;
      Catwel_emxEnsureCapacity_real_T(Catwell_Rom_DW.obj.RefPosesInternal,
        s3_iter);
      for (s3_iter = 0; s3_iter < 15; s3_iter++) {
        Catwell_Rom_DW.obj.RefPosesInternal->data[s3_iter] = (int8_T)
          tmp_data[s3_iter];
      }

      s3_iter = Catwell_Rom_DW.obj.RefDirectionsInternal->size[0];
      Catwell_Rom_DW.obj.RefDirectionsInternal->size[0] = 5;
      Catwel_emxEnsureCapacity_real_T(Catwell_Rom_DW.obj.RefDirectionsInternal,
        s3_iter);
      rtb_Sum_f = 5;
      for (s3_iter = 0; s3_iter < 5; s3_iter++) {
        Catwell_Rom_DW.obj.RefDirectionsInternal->data[s3_iter] = 1.0;
        tmp_data_0[s3_iter] = 1.0;
      }

      tmp_size[0] = 5;
      tmp_size[1] = 3;
      for (s3_iter = 0; s3_iter < 3; s3_iter++) {
        memcpy(&tmp_data_1[s3_iter * 5], &tmp_data[s3_iter * 5], 5U * sizeof
               (real_T));
      }

      Catwell_Rom_smoothPathSpline(tmp_data_1, tmp_size, tmp_data_0, &rtb_Sum_f,
        Catwell_Rom_DW.obj.LastPosesOutput,
        Catwell_Rom_DW.obj.LastDirectionsOutput, cumLengths, curvatures);
    }

    Catwell_Rom_DW.PathSmootherSpline_DIMS1[0] = 10;
    Catwell_Rom_DW.PathSmootherSpline_DIMS1[1] = 3;
    Catwell_Rom_DW.PathSmootherSpline_DIMS2[0] = 10;
    Catwell_Rom_DW.PathSmootherSpline_DIMS2[1] = 1;

    /* End of MATLABSystem: '<Root>/Path Smoother Spline' */
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(Catwell_Rom_M->rtwLogInfo, (Catwell_Rom_M->Timing.t));
  if (Catwell_Rom_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for RandomNumber: '<S1>/White Noise' */
    Catwell_Rom_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&Catwell_Rom_DW.RandSeed) * Catwell_Rom_P.WhiteNoise_StdDev +
      Catwell_Rom_P.WhiteNoise_Mean;
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Catwell_Rom_M)!=-1) &&
        !((rtmGetTFinal(Catwell_Rom_M)-Catwell_Rom_M->Timing.t[0]) >
          Catwell_Rom_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(Catwell_Rom_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Catwell_Rom_M->Timing.clockTick0)) {
    ++Catwell_Rom_M->Timing.clockTickH0;
  }

  Catwell_Rom_M->Timing.t[0] = Catwell_Rom_M->Timing.clockTick0 *
    Catwell_Rom_M->Timing.stepSize0 + Catwell_Rom_M->Timing.clockTickH0 *
    Catwell_Rom_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    Catwell_Rom_M->Timing.clockTick1++;
    if (!Catwell_Rom_M->Timing.clockTick1) {
      Catwell_Rom_M->Timing.clockTickH1++;
    }
  }

  rate_scheduler();
}

/* Model initialize function */
void Catwell_Rom_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Catwell_Rom_M, 0,
                sizeof(RT_MODEL_Catwell_Rom_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Catwell_Rom_M->solverInfo,
                          &Catwell_Rom_M->Timing.simTimeStep);
    rtsiSetTPtr(&Catwell_Rom_M->solverInfo, &rtmGetTPtr(Catwell_Rom_M));
    rtsiSetStepSizePtr(&Catwell_Rom_M->solverInfo,
                       &Catwell_Rom_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Catwell_Rom_M->solverInfo, (&rtmGetErrorStatus
      (Catwell_Rom_M)));
    rtsiSetRTModelPtr(&Catwell_Rom_M->solverInfo, Catwell_Rom_M);
  }

  rtsiSetSimTimeStep(&Catwell_Rom_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Catwell_Rom_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(Catwell_Rom_M, &Catwell_Rom_M->Timing.tArray[0]);
  rtmSetTFinal(Catwell_Rom_M, 3.99);
  Catwell_Rom_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = (NULL);
    Catwell_Rom_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Catwell_Rom_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Catwell_Rom_M->rtwLogInfo, (NULL));
    rtliSetLogT(Catwell_Rom_M->rtwLogInfo, "tout");
    rtliSetLogX(Catwell_Rom_M->rtwLogInfo, "");
    rtliSetLogXFinal(Catwell_Rom_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Catwell_Rom_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Catwell_Rom_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(Catwell_Rom_M->rtwLogInfo, 0);
    rtliSetLogDecimation(Catwell_Rom_M->rtwLogInfo, 1);
    rtliSetLogY(Catwell_Rom_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(Catwell_Rom_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(Catwell_Rom_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&Catwell_Rom_DW, 0,
                sizeof(DW_Catwell_Rom_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Catwell_Rom_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Catwell_Rom_M), Catwell_Rom_M->Timing.stepSize0, (&rtmGetErrorStatus
    (Catwell_Rom_M)));

  {
    real_T tmp;
    int32_T i;
    int32_T t;
    uint32_T tseed;

    /* InitializeConditions for RandomNumber: '<S1>/White Noise' */
    tmp = floor(Catwell_Rom_P.BandLimitedWhiteNoise_seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    tseed = ((((tseed - ((uint32_T)i << 16U)) + (uint32_T)t) << 16U) + (uint32_T)
             t) + (uint32_T)i;
    if (tseed < 1U) {
      tseed = 1144108930U;
    } else if (tseed > 2147483646U) {
      tseed = 2147483646U;
    }

    Catwell_Rom_DW.RandSeed = tseed;
    Catwell_Rom_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&Catwell_Rom_DW.RandSeed) * Catwell_Rom_P.WhiteNoise_StdDev +
      Catwell_Rom_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S1>/White Noise' */

    /* SystemInitialize for Iterator SubSystem: '<Root>/For Iterator Subsystem2' */
    /* InitializeConditions for UnitDelay: '<S3>/Unit Delay' */
    Catwell_Rom_DW.UnitDelay_DSTATE = Catwell_Rom_P.UnitDelay_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<Root>/For Iterator Subsystem2' */

    /* SystemInitialize for Iterator SubSystem: '<Root>/For Iterator Subsystem1' */
    /* InitializeConditions for UnitDelay: '<S2>/Unit Delay' */
    Catwell_Rom_DW.UnitDelay_DSTATE_n =
      Catwell_Rom_P.UnitDelay_InitialCondition_b;

    /* End of SystemInitialize for SubSystem: '<Root>/For Iterator Subsystem1' */
    emxInitStruct_driving_internal_(&Catwell_Rom_DW.obj);

    /* Start for MATLABSystem: '<Root>/Path Smoother Spline' */
    Catwell_Rom_DW.obj.CacheInputSizes = false;
    Catwell_Rom_DW.objisempty = true;
    Catwell_Rom_DW.obj.isInitialized = 1;
    i = Catwell_Rom_DW.SFunction_DIMS2[0];
    if (Catwell_Rom_DW.SFunction_DIMS2[0] < 0) {
      i = 0;
    }

    Catwell_Rom_DW.obj.inputVarSize[0].f1[0] = (uint32_T)i;
    i = Catwell_Rom_DW.SFunction_DIMS2[1];
    if (Catwell_Rom_DW.SFunction_DIMS2[1] < 0) {
      i = 0;
    }

    Catwell_Rom_DW.obj.inputVarSize[0].f1[1] = (uint32_T)i;
    i = Catwell_Rom_DW.SFunction_DIMS3[0];
    if (Catwell_Rom_DW.SFunction_DIMS3[0] < 0) {
      i = 0;
    }

    Catwell_Rom_DW.obj.inputVarSize[1].f1[0] = (uint32_T)i;
    Catwell_Rom_DW.obj.inputVarSize[1].f1[1] = 1U;
    for (i = 0; i < 6; i++) {
      Catwell_Rom_DW.obj.inputVarSize[0].f1[i + 2] = 1U;
      Catwell_Rom_DW.obj.inputVarSize[1].f1[i + 2] = 1U;
    }

    i = Catwell_Rom_DW.obj.RefPosesInternal->size[0] *
      Catwell_Rom_DW.obj.RefPosesInternal->size[1];
    Catwell_Rom_DW.obj.RefPosesInternal->size[0] =
      Catwell_Rom_DW.SFunction_DIMS2[0];
    Catwell_Rom_DW.obj.RefPosesInternal->size[1] =
      Catwell_Rom_DW.SFunction_DIMS2[1];
    Catwel_emxEnsureCapacity_real_T(Catwell_Rom_DW.obj.RefPosesInternal, i);
    t = Catwell_Rom_DW.SFunction_DIMS2[0] * Catwell_Rom_DW.SFunction_DIMS2[1];
    for (i = 0; i < t; i++) {
      Catwell_Rom_DW.obj.RefPosesInternal->data[i] = (rtNaN);
    }

    t = Catwell_Rom_DW.SFunction_DIMS3[0];
    i = Catwell_Rom_DW.obj.RefDirectionsInternal->size[0];
    Catwell_Rom_DW.obj.RefDirectionsInternal->size[0] =
      Catwell_Rom_DW.SFunction_DIMS3[0];
    Catwel_emxEnsureCapacity_real_T(Catwell_Rom_DW.obj.RefDirectionsInternal, i);
    for (i = 0; i < t; i++) {
      Catwell_Rom_DW.obj.RefDirectionsInternal->data[i] = (rtNaN);
    }

    for (i = 0; i < 30; i++) {
      Catwell_Rom_DW.obj.LastPosesOutput[i] = (rtNaN);
    }

    for (i = 0; i < 10; i++) {
      Catwell_Rom_DW.obj.LastDirectionsOutput[i] = (rtNaN);
    }

    /* End of Start for MATLABSystem: '<Root>/Path Smoother Spline' */
  }
}

/* Model terminate function */
void Catwell_Rom_terminate(void)
{
  emxFreeStruct_driving_internal_(&Catwell_Rom_DW.obj);
}
