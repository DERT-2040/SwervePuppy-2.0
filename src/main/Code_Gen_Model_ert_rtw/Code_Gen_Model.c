/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.33
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Dec 29 20:04:56 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Code_Gen_Model.h"
#include "rtwtypes.h"
#include "Code_Gen_Model_private.h"
#include <string.h>
#include <math.h>
#include "rt_nonfinite.h"
#include <float.h>
#include "rt_defines.h"

/* Exported block parameters */
real_T Boost_Trigger_Decreasing_Limit = -0.044444;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S298>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 3.658;/* Variable: Boost_Trigger_High_Speed
                                         * Referenced by:
                                         *   '<S296>/Constant'
                                         *   '<S296>/Saturation'
                                         */
real_T Boost_Trigger_Increasing_Limit = 0.04;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S298>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S296>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S147>/Constant3'
                                        *   '<S168>/Constant3'
                                        *   '<S189>/Constant3'
                                        *   '<S210>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S147>/Constant2'
                                   *   '<S168>/Constant2'
                                   *   '<S189>/Constant2'
                                   *   '<S210>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S147>/Saturation'
                                        *   '<S168>/Saturation'
                                        *   '<S189>/Saturation'
                                        *   '<S210>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S147>/Saturation'
                                        *   '<S168>/Saturation'
                                        *   '<S189>/Saturation'
                                        *   '<S210>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00018182;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S147>/Gain'
                                            *   '<S168>/Gain'
                                            *   '<S189>/Gain'
                                            *   '<S210>/Gain'
                                            */
real_T Drive_Motor_Control_I = 0.0;    /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S147>/Gain2'
                                        *   '<S168>/Gain2'
                                        *   '<S189>/Gain2'
                                        *   '<S210>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = 0.0; /* Variable: Drive_Motor_Control_I_LL
                                        * Referenced by:
                                        *   '<S147>/Saturation1'
                                        *   '<S168>/Saturation1'
                                        *   '<S189>/Saturation1'
                                        *   '<S210>/Saturation1'
                                        */
real_T Drive_Motor_Control_I_UL = 0.0; /* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S147>/Saturation1'
                                        *   '<S168>/Saturation1'
                                        *   '<S189>/Saturation1'
                                        *   '<S210>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S147>/Gain1'
                                        *   '<S168>/Gain1'
                                        *   '<S189>/Gain1'
                                        *   '<S210>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 1500.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S152>/Constant'
                            *   '<S173>/Constant'
                            *   '<S194>/Constant'
                            *   '<S215>/Constant'
                            */
real_T KF_Odom_Covariance = 0.001;     /* Variable: KF_Odom_Covariance
                                        * Referenced by: '<S6>/Constant2'
                                        */
real_T KF_Vision_Ambiguity_Thresh = 0.3;/* Variable: KF_Vision_Ambiguity_Thresh
                                         * Referenced by: '<S6>/Constant'
                                         */
real_T KF_Vision_Covariance = 0.1;     /* Variable: KF_Vision_Covariance
                                        * Referenced by: '<S6>/Constant4'
                                        */
real_T Odometry_Desired_X = 0.0;       /* Variable: Odometry_Desired_X
                                        * Referenced by: '<S2>/Constant7'
                                        */
real_T Odometry_Desired_Y = 0.0;       /* Variable: Odometry_Desired_Y
                                        * Referenced by: '<S2>/Constant8'
                                        */
real_T Odometry_Reset_IC = 0.0;        /* Variable: Odometry_Reset_IC
                                        * Referenced by: '<S8>/Constant'
                                        */
real_T Odometry_X_Y_TEAR = 0.0;        /* Variable: Odometry_X_Y_TEAR
                                        * Referenced by: '<S73>/Constant'
                                        */
real_T Spline_Capture_Radius = 0.1;    /* Variable: Spline_Capture_Radius
                                        * Referenced by:
                                        *   '<S87>/Constant'
                                        *   '<S88>/Constant'
                                        */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S132>/Constant2'
                          */
real_T Spline_Lookahead_Dist = 0.2;    /* Variable: Spline_Lookahead_Dist
                                        * Referenced by: '<S78>/Lookahead Distance'
                                        */
real_T Spline_Max_Centripital_Acceleration = 3.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S132>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 2.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S78>/Constant'
                             */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S132>/Constant3'
                                     */
real_T Steering_Abs_Deadband_Range = 0.7;/* Variable: Steering_Abs_Deadband_Range
                                          * Referenced by: '<S286>/Constant2'
                                          */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S252>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S252>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S252>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S252>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.1;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S251>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S252>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S252>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S252>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 1.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S252>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -1.3;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S252>/Constant1'
                                   *   '<S252>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 1.3;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S252>/Constant'
                                   *   '<S252>/Saturation2'
                                   */
real_T Steering_Localized_Cmd_Approach_Zero_Error_Thresh = 0.2;
                  /* Variable: Steering_Localized_Cmd_Approach_Zero_Error_Thresh
                   * Referenced by: '<S242>/Constant5'
                   */
real_T Steering_Localized_Cmd_Approach_Zero_Final_Thresh = 0.01;
                  /* Variable: Steering_Localized_Cmd_Approach_Zero_Final_Thresh
                   * Referenced by: '<S242>/Constant6'
                   */
real_T Steering_Localized_Cmd_NonZero_Error_Thresh = 0.2;
                        /* Variable: Steering_Localized_Cmd_NonZero_Error_Thresh
                         * Referenced by: '<S242>/Constant9'
                         */
real_T Steering_Localized_Cmd_NonZero_Final_Scale_Factor = 0.1;
                  /* Variable: Steering_Localized_Cmd_NonZero_Final_Scale_Factor
                   * Referenced by: '<S242>/Constant10'
                   */
real_T Steering_Localized_Cmd_Rate_Limit_Dec = -1.0;
                              /* Variable: Steering_Localized_Cmd_Rate_Limit_Dec
                               * Referenced by: '<S242>/Constant1'
                               */
real_T Steering_Localized_Cmd_Rate_Limit_Inc = 1.0;
                              /* Variable: Steering_Localized_Cmd_Rate_Limit_Inc
                               * Referenced by: '<S242>/Constant3'
                               */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S150>/Constant3'
                                        *   '<S171>/Constant3'
                                        *   '<S192>/Constant3'
                                        *   '<S213>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S150>/Constant2'
                                *   '<S171>/Constant2'
                                *   '<S192>/Constant2'
                                *   '<S213>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S150>/Saturation'
                                           *   '<S171>/Saturation'
                                           *   '<S192>/Saturation'
                                           *   '<S213>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S150>/Saturation'
                                          *   '<S171>/Saturation'
                                          *   '<S192>/Saturation'
                                          *   '<S213>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S150>/Gain2'
                                         *   '<S171>/Gain2'
                                         *   '<S192>/Gain2'
                                         *   '<S213>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S150>/Saturation1'
                                             *   '<S171>/Saturation1'
                                             *   '<S192>/Saturation1'
                                             *   '<S213>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S150>/Saturation1'
                                            *   '<S171>/Saturation1'
                                            *   '<S192>/Saturation1'
                                            *   '<S213>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S150>/Gain1'
                                        *   '<S171>/Gain1'
                                        *   '<S192>/Gain1'
                                        *   '<S213>/Gain1'
                                        */
real_T Steering_Relative_Gain = 1.3;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S284>/Constant'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S230>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S230>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S230>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S230>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Inc = 0.085714;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S230>/Constant3'
                                    */

/* Block signals (default storage) */
B_Code_Gen_Model_T Code_Gen_Model_B;

/* Block states (default storage) */
DW_Code_Gen_Model_T Code_Gen_Model_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Code_Gen_Model_T Code_Gen_Model_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Code_Gen_Model_T Code_Gen_Model_Y;

/* Real-time model */
static RT_MODEL_Code_Gen_Model_T Code_Gen_Model_M_;
RT_MODEL_Code_Gen_Model_T *const Code_Gen_Model_M = &Code_Gen_Model_M_;

/* Forward declaration for local functions */
static void Code_Gen_Model_mrdiv(const real_T A[4], const real_T B[4], real_T Y
  [4]);

/* Lookup Binary Search Utility BINARYSEARCH_real_T */
void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi)
{
  /* Find the location of current input value in the data table. */
  *piLeft = 0U;
  *piRght = iHi;
  if (u <= pData[0] ) {
    /* Less than or equal to the smallest point in the table. */
    *piRght = 0U;
  } else if (u >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  } else {
    uint32_T i;

    /* Do a binary search. */
    while (( *piRght - *piLeft ) > 1U ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + *piRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (u < pData[i] ) {
        *piRght = i;
      } else {
        *piLeft = i;
      }
    }
  }
}

/* Lookup Utility LookUp_real_T_real_T */
void LookUp_real_T_real_T(real_T *pY, const real_T *pYData, real_T u, const
  real_T *pUData, uint32_T iHi)
{
  uint32_T iLeft;
  uint32_T iRght;
  BINARYSEARCH_real_T( &(iLeft), &(iRght), u, pUData, iHi);

  {
    real_T lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      real_T num;
      real_T den;
      den = pUData[iRght];
      den -= pUData[iLeft];
      num = u;
      num -= pUData[iLeft];
      lambda = num / den;
    } else {
      lambda = 0.0;
    }

    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = pYData[iLeft];
      yRghtCast = pYData[iRght];
      yLeftCast += lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }
  }
}

real_T look1_binlcpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = (maxIndex >> 1U);
    iLeft = 0U;
    iRght = maxIndex;
    while ((iRght - iLeft) > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = ((iRght + iLeft) >> 1U);
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return ((table[iLeft + 1U] - yL_0d0) * frac) + yL_0d0;
}

/*
 * Output and update for action system:
 *    '<S1>/Disabled'
 *    '<S1>/Test'
 */
void Code_Gen_Model_Disabled(real_T *rty_Gyro_Angle_Adjustment, real_T
  *rty_Steering_Abs_Cmd, real_T *rty_Steering_Rel_Cmd, real_T
  *rty_Translation_Angle, real_T *rty_Translation_Speed, boolean_T
  *rty_Is_Absolute_Translation, boolean_T *rty_Is_Absolute_Steering, boolean_T
  *rty_Spline_Enable, real_T rty_Spline_Ref_Poses[76], real_T
  *rty_Spline_Num_Poses)
{
  /* SignalConversion generated from: '<S4>/Spline_Ref_Poses' */
  memset(&rty_Spline_Ref_Poses[0], 0, 76U * (sizeof(real_T)));

  /* SignalConversion generated from: '<S4>/Gyro_Angle_Adjustment' incorporates:
   *  Constant: '<S4>/Constant'
   */
  *rty_Gyro_Angle_Adjustment = 0.0;

  /* SignalConversion generated from: '<S4>/Steering_Abs_Cmd' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  *rty_Steering_Abs_Cmd = 0.0;

  /* SignalConversion generated from: '<S4>/Steering_Rel_Cmd' incorporates:
   *  Constant: '<S4>/Constant2'
   */
  *rty_Steering_Rel_Cmd = 0.0;

  /* SignalConversion generated from: '<S4>/Translation_Angle' incorporates:
   *  Constant: '<S4>/Constant3'
   */
  *rty_Translation_Angle = 0.0;

  /* SignalConversion generated from: '<S4>/Translation_Speed' incorporates:
   *  Constant: '<S4>/Constant4'
   */
  *rty_Translation_Speed = 0.0;

  /* SignalConversion generated from: '<S4>/Is_Absolute_Translation' incorporates:
   *  Constant: '<S4>/Constant5'
   */
  *rty_Is_Absolute_Translation = true;

  /* SignalConversion generated from: '<S4>/Is_Absolute_Steering' incorporates:
   *  Constant: '<S4>/Constant6'
   */
  *rty_Is_Absolute_Steering = true;

  /* SignalConversion generated from: '<S4>/Spline_Enable' incorporates:
   *  Constant: '<S4>/Constant7'
   */
  *rty_Spline_Enable = false;

  /* SignalConversion generated from: '<S4>/Spline_Num_Poses' incorporates:
   *  Constant: '<S4>/Constant9'
   */
  *rty_Spline_Num_Poses = 19.0;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (((rtIsNaN(u0)) || (rtIsNaN(u1))) || (rtIsInf(u0))) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > (DBL_EPSILON * q));
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S15>/Discrete-Time KF - Calculate PLMZ' */
static void Code_Gen_Model_mrdiv(const real_T A[4], const real_T B[4], real_T Y
  [4])
{
  real_T a21;
  real_T a22;
  real_T a22_tmp;
  int32_T Y_tmp;
  int32_T r1;
  int32_T r2;
  if (fabs(B[1]) > fabs(B[0])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }

  a21 = B[r2] / B[r1];
  a22_tmp = B[r1 + 2];
  a22 = B[r2 + 2] - (a22_tmp * a21);
  Y_tmp = (r1 << 1);
  Y[Y_tmp] = A[0] / B[r1];
  r2 <<= 1;
  Y[r2] = (A[2] - (Y[Y_tmp] * a22_tmp)) / a22;
  Y[Y_tmp] -= Y[r2] * a21;
  Y[Y_tmp + 1] = A[1] / B[r1];
  Y[r2 + 1] = (A[3] - (Y[Y_tmp + 1] * a22_tmp)) / a22;
  Y[Y_tmp + 1] -= Y[r2 + 1] * a21;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt((a * a) + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt((b * b) + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if ((rtIsNaN(u0)) || (rtIsNaN(u1))) {
    y = (rtNaN);
  } else if ((rtIsInf(u0)) && (rtIsInf(u1))) {
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

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if ((rtIsNaN(u0)) || (rtIsNaN(u1))) {
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

/* Model step function */
void Code_Gen_Model_step(void)
{
  /* local block i/o variables */
  real_T rtb_LookupTableDynamic1;
  real_T rtb_LookupTableDynamic;
  real_T rtb_LookupTableDynamic1_i;
  real_T rtb_LookupTableDynamic_j;
  real_T rtb_MatrixConcatenate_o[450];
  real_T rtb_Position_and_Curvature[450];
  real_T distance_from_robot[150];
  real_T rtb_Assignment_d[150];
  real_T rtb_MatrixConcatenate_h[100];
  real_T rtb_Spline_Ref_Poses[76];
  real_T rtb_Assignment[42];
  real_T rtb_Selector4[42];
  real_T rtb_Ref_Poses[38];
  real_T rtb_TmpSignalConversionAtProduc[8];
  real_T Abar[4];
  real_T Abar_0[4];
  real_T rtb_Add1_b[4];
  real_T rtb_L[4];
  real_T rtb_M[4];
  real_T rtb_M_0[4];
  real_T rtb_Product[4];
  real_T rtb_Product1[4];
  real_T rtb_Rotationmatrixfromlocaltogl[4];
  real_T rtb_y_g[4];
  real_T rtb_Add2_f[2];
  real_T rtb_Minus_n[2];
  real_T rtb_Reshapey[2];
  real_T tmp[2];
  real_T rtb_Add_c;
  real_T rtb_Add_c4;
  real_T rtb_Add_cz;
  real_T rtb_Add_ec;
  real_T rtb_Add_kl;
  real_T rtb_Add_kz;
  real_T rtb_Add_pw;
  real_T rtb_Atan2_i;
  real_T rtb_Hypot_b;
  real_T rtb_Hypot_g5;
  real_T rtb_Init_e;
  real_T rtb_Integral_kz;
  real_T rtb_Integral_m;
  real_T rtb_Magnitude;
  real_T rtb_MatrixConcatenate_b_idx_0;
  real_T rtb_Merge1;
  real_T rtb_Product_do;
  real_T rtb_Product_dq;
  real_T rtb_Rotationmatrixfromlocalto_0;
  real_T rtb_Steer_Joystick_X_Rel_Mod;
  real_T rtb_Subtract1_la;
  real_T rtb_Subtract_gn;
  real_T rtb_Subtract_i;
  real_T rtb_Sum2_fc;
  real_T rtb_Switch2_ef;
  real_T rtb_Switch2_p;
  real_T rtb_Z_idx_0;
  real_T rtb_Z_idx_2;
  real_T rtb_Z_idx_3;
  real_T rtb_thetay;
  real_T rtb_uDLookupTable_l;
  real_T rtb_y_l3_tmp;
  real_T tmp_0;
  real_T tmp_1;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s104_iter;
  uint16_T s129_iter;
  int8_T rtAction;
  int8_T rtPrevAction;
  boolean_T exitg1;
  boolean_T rtb_Is_Absolute_Steering;
  boolean_T rtb_OR_ao;
  boolean_T rtb_RelationalOperator;
  boolean_T rtb_Switch_b1;

  /* Sum: '<S137>/Add1' incorporates:
   *  Constant: '<S137>/Constant3'
   *  Constant: '<S137>/Constant4'
   *  Gain: '<S10>/Revolutions to Radians'
   *  Inport: '<Root>/FrontLeft_Steer_Rev'
   *  Inport: '<Root>/FrontLeft_Turn_Offset'
   *  Math: '<S137>/Math Function'
   *  Sum: '<S10>/Add'
   *  Sum: '<S137>/Add2'
   */
  Code_Gen_Model_B.FL_Steer_Module_Angle = rt_modd_snf
    (((Code_Gen_Model_U.FrontLeft_Steer_Rev -
       Code_Gen_Model_U.FrontLeft_Turn_Offset) * 6.2831853071795862) +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Rev'
   *  Sum: '<S65>/Diff'
   *  UnitDelay: '<S65>/UD'
   *
   * Block description for '<S65>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S65>/UD':
   *
   *  Store in Global RAM
   */
  rtb_thetay = (Code_Gen_Model_U.FrontLeft_Drive_Motor_Rev -
                Code_Gen_Model_DW.UD_DSTATE) * 0.037290702116950625;

  /* Sum: '<S138>/Add1' incorporates:
   *  Constant: '<S138>/Constant3'
   *  Constant: '<S138>/Constant4'
   *  Gain: '<S10>/Revolutions to Radians1'
   *  Inport: '<Root>/FrontRight_Steer_Rev'
   *  Inport: '<Root>/FrontRight_Turn_Offset'
   *  Math: '<S138>/Math Function'
   *  Sum: '<S10>/Add1'
   *  Sum: '<S138>/Add2'
   */
  Code_Gen_Model_B.FR_Steer_Module_Angle = rt_modd_snf
    (((Code_Gen_Model_U.FrontRight_Steer_Rev -
       Code_Gen_Model_U.FrontRight_Turn_Offset) * 6.2831853071795862) +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S8>/Product1' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Rev'
   *  Sum: '<S66>/Diff'
   *  UnitDelay: '<S66>/UD'
   *
   * Block description for '<S66>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S66>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Init_e = (Code_Gen_Model_U.FrontRight_Drive_Motor_Rev -
                Code_Gen_Model_DW.UD_DSTATE_m) * 0.037290702116950625;

  /* Sum: '<S139>/Add1' incorporates:
   *  Constant: '<S139>/Constant3'
   *  Constant: '<S139>/Constant4'
   *  Gain: '<S10>/Revolutions to Radians2'
   *  Inport: '<Root>/BackLeft_Steer_Rev'
   *  Inport: '<Root>/BackLeft_Turn_Offset'
   *  Math: '<S139>/Math Function'
   *  Sum: '<S10>/Add2'
   *  Sum: '<S139>/Add2'
   */
  Code_Gen_Model_B.BL_Steer_Module_Angle = rt_modd_snf
    (((Code_Gen_Model_U.BackLeft_Steer_Rev -
       Code_Gen_Model_U.BackLeft_Turn_Offset) * 6.2831853071795862) +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S8>/Product2' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Rev'
   *  Sum: '<S67>/Diff'
   *  UnitDelay: '<S67>/UD'
   *
   * Block description for '<S67>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S67>/UD':
   *
   *  Store in Global RAM
   */
  rtb_uDLookupTable_l = (Code_Gen_Model_U.BackLeft_Drive_Motor_Rev -
    Code_Gen_Model_DW.UD_DSTATE_i) * 0.037290702116950625;

  /* Sum: '<S140>/Add1' incorporates:
   *  Constant: '<S140>/Constant3'
   *  Constant: '<S140>/Constant4'
   *  Gain: '<S10>/Revolutions to Radians3'
   *  Inport: '<Root>/BackRight_Steer_Rev'
   *  Inport: '<Root>/BackRight_Turn_Offset'
   *  Math: '<S140>/Math Function'
   *  Sum: '<S10>/Add3'
   *  Sum: '<S140>/Add2'
   */
  Code_Gen_Model_B.BR_Steer_Module_Angle = rt_modd_snf
    (((Code_Gen_Model_U.BackRight_Steer_Rev -
       Code_Gen_Model_U.BackRight_Turn_Offset) * 6.2831853071795862) +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S8>/Product3' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/BackRight_Drive_Motor_Rev'
   *  Sum: '<S68>/Diff'
   *  UnitDelay: '<S68>/UD'
   *
   * Block description for '<S68>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S68>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Switch2_p = (Code_Gen_Model_U.BackRight_Drive_Motor_Rev -
                   Code_Gen_Model_DW.UD_DSTATE_c) * 0.037290702116950625;

  /* SignalConversion generated from: '<S8>/Product7' incorporates:
   *  Fcn: '<S69>/r->x'
   *  Fcn: '<S69>/theta->y'
   *  Fcn: '<S70>/r->x'
   *  Fcn: '<S70>/theta->y'
   *  Fcn: '<S71>/r->x'
   *  Fcn: '<S71>/theta->y'
   *  Fcn: '<S72>/r->x'
   *  Fcn: '<S72>/theta->y'
   */
  rtb_TmpSignalConversionAtProduc[0] = rtb_thetay * cos
    (Code_Gen_Model_B.FL_Steer_Module_Angle);
  rtb_TmpSignalConversionAtProduc[1] = rtb_thetay * sin
    (Code_Gen_Model_B.FL_Steer_Module_Angle);
  rtb_TmpSignalConversionAtProduc[2] = rtb_Init_e * cos
    (Code_Gen_Model_B.FR_Steer_Module_Angle);
  rtb_TmpSignalConversionAtProduc[3] = rtb_Init_e * sin
    (Code_Gen_Model_B.FR_Steer_Module_Angle);
  rtb_TmpSignalConversionAtProduc[4] = rtb_uDLookupTable_l * cos
    (Code_Gen_Model_B.BL_Steer_Module_Angle);
  rtb_TmpSignalConversionAtProduc[5] = rtb_uDLookupTable_l * sin
    (Code_Gen_Model_B.BL_Steer_Module_Angle);
  rtb_TmpSignalConversionAtProduc[6] = rtb_Switch2_p * cos
    (Code_Gen_Model_B.BR_Steer_Module_Angle);
  rtb_TmpSignalConversionAtProduc[7] = rtb_Switch2_p * sin
    (Code_Gen_Model_B.BR_Steer_Module_Angle);

  /* Outputs for Atomic SubSystem: '<S14>/ScalarExpansionQ' */
  /* MATLAB Function: '<S38>/ScalarExpansion' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   *  Product: '<S6>/Product'
   */
  rtb_thetay = (KF_Odom_Covariance + KF_Odom_Covariance) / 2.0;
  rtb_y_g[0] = rtb_thetay;
  rtb_y_l3_tmp = ((0.0 * KF_Odom_Covariance) + (0.0 * KF_Odom_Covariance)) / 2.0;
  rtb_y_g[1] = rtb_y_l3_tmp;
  rtb_y_g[2] = rtb_y_l3_tmp;
  rtb_y_g[3] = rtb_thetay;

  /* End of Outputs for SubSystem: '<S14>/ScalarExpansionQ' */

  /* Outputs for Atomic SubSystem: '<S14>/ReducedQRN' */
  /* Sum: '<S34>/Add' incorporates:
   *  Concatenate: '<S8>/Rotation matrix from local to global'
   *  Math: '<S34>/Transpose2'
   *  Product: '<S34>/Product1'
   */
  for (i = 0; i < 2; i++) {
    rtb_Rotationmatrixfromlocalto_0 = (rtb_y_g[i + 2] * 0.0) + (rtb_y_g[i] * 0.0);
    rtb_Rotationmatrixfromlocaltogl[i] = rtb_Rotationmatrixfromlocalto_0;
    rtb_Rotationmatrixfromlocaltogl[i + 2] = rtb_Rotationmatrixfromlocalto_0;
  }

  /* End of Sum: '<S34>/Add' */

  /* Product: '<S34>/Product3' incorporates:
   *  Concatenate: '<S8>/Rotation matrix from local to global'
   *  Constant: '<S14>/H'
   *  Product: '<S34>/Product4'
   */
  i = 0;
  for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
    rtb_Product[i] = 0.0;
    rtb_Add_kz = (rtb_Rotationmatrixfromlocaltogl[i + 1] * 0.0) +
      (rtb_Rotationmatrixfromlocaltogl[i] * 0.0);
    Abar[i] = rtb_Add_kz;
    rtb_Product[i + 1] = 0.0;
    Abar[i + 1] = rtb_Add_kz;
    i += 2;
  }

  /* End of Product: '<S34>/Product3' */
  /* End of Outputs for SubSystem: '<S14>/ReducedQRN' */

  /* Outputs for Atomic SubSystem: '<S14>/ScalarExpansionR' */
  /* MATLAB Function: '<S39>/ScalarExpansion' incorporates:
   *  Constant: '<S6>/Constant4'
   *  Product: '<S6>/Product1'
   */
  rtb_Rotationmatrixfromlocalto_0 = (KF_Vision_Covariance + KF_Vision_Covariance)
    / 2.0;

  /* Outputs for Atomic SubSystem: '<S14>/ReducedQRN' */
  /* Sum: '<S34>/Add1' incorporates:
   *  MATLAB Function: '<S39>/ScalarExpansion'
   */
  rtb_Add1_b[0] = rtb_Rotationmatrixfromlocalto_0 + Abar[0];

  /* End of Outputs for SubSystem: '<S14>/ReducedQRN' */

  /* MATLAB Function: '<S39>/ScalarExpansion' incorporates:
   *  Constant: '<S6>/Constant3'
   *  Constant: '<S6>/Constant4'
   *  Product: '<S6>/Product1'
   */
  rtb_Atan2_i = ((0.0 * KF_Vision_Covariance) + (0.0 * KF_Vision_Covariance)) /
    2.0;

  /* Outputs for Atomic SubSystem: '<S14>/ReducedQRN' */
  /* Sum: '<S34>/Add1' incorporates:
   *  MATLAB Function: '<S39>/ScalarExpansion'
   */
  rtb_Add1_b[1] = rtb_Atan2_i + Abar[1];
  rtb_Add1_b[2] = rtb_Atan2_i + Abar[2];
  rtb_Add1_b[3] = (Abar[3] + rtb_Product[3]) + rtb_Rotationmatrixfromlocalto_0;

  /* End of Outputs for SubSystem: '<S14>/ScalarExpansionR' */

  /* Product: '<S34>/Product2' incorporates:
   *  Concatenate: '<S8>/Rotation matrix from local to global'
   *  Constant: '<S14>/G'
   *  MATLAB Function: '<S15>/Discrete-Time KF - Calculate PLMZ'
   *  MATLAB Function: '<S38>/ScalarExpansion'
   *  Math: '<S34>/Transpose1'
   *  Product: '<S34>/Product'
   */
  rtb_Z_idx_0 = rtb_Rotationmatrixfromlocaltogl[1];
  rtb_Init_e = rtb_Rotationmatrixfromlocaltogl[0];
  rtb_Z_idx_2 = rtb_Rotationmatrixfromlocaltogl[3];
  rtb_Z_idx_3 = rtb_Rotationmatrixfromlocaltogl[2];

  /* Outputs for Atomic SubSystem: '<S14>/CalculatePL' */
  i = 0;
  for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
    rtb_Atan2_i = Code_Gen_Model_ConstP.pooled19[rtb_Num_Segments + 2];
    rtb_Switch2_p = Code_Gen_Model_ConstP.pooled19[rtb_Num_Segments];
    rtb_Product1[rtb_Num_Segments] = (rtb_Atan2_i * rtb_Z_idx_0) +
      (rtb_Switch2_p * rtb_Init_e);
    rtb_M[i] = rtb_Switch2_p;
    rtb_Product1[rtb_Num_Segments + 2] = (rtb_Atan2_i * rtb_Z_idx_2) +
      (rtb_Switch2_p * rtb_Z_idx_3);
    rtb_M[i + 1] = rtb_Atan2_i;

    /* Outputs for Atomic SubSystem: '<S14>/ScalarExpansionQ' */
    rtb_Rotationmatrixfromlocalto_0 = (rtb_Atan2_i * rtb_y_l3_tmp) +
      (rtb_Switch2_p * rtb_thetay);
    rtb_Atan2_i = (rtb_Atan2_i * rtb_thetay) + (rtb_Switch2_p * rtb_y_l3_tmp);

    /* End of Outputs for SubSystem: '<S14>/ScalarExpansionQ' */
    rtb_Product[i] = (rtb_Atan2_i * 0.0) + rtb_Rotationmatrixfromlocalto_0;
    rtb_Product[i + 1] = (rtb_Rotationmatrixfromlocalto_0 * 0.0) + rtb_Atan2_i;
    i += 2;
  }

  /* End of Product: '<S34>/Product2' */
  /* End of Outputs for SubSystem: '<S14>/CalculatePL' */
  /* End of Outputs for SubSystem: '<S14>/ReducedQRN' */

  /* RelationalOperator: '<S6>/Relational Operator' incorporates:
   *  Constant: '<S6>/Constant'
   *  Inport: '<Root>/Photon_Est_Pose_Ambiguity'
   */
  rtb_RelationalOperator = (Code_Gen_Model_U.Photon_Est_Pose_Ambiguity >=
    KF_Vision_Ambiguity_Thresh);

  /* Delay: '<S14>/MemoryP' incorporates:
   *  Constant: '<S14>/P0'
   */
  if (Code_Gen_Model_DW.icLoad) {
    Code_Gen_Model_DW.MemoryP_DSTATE[0] = 10.0;
    Code_Gen_Model_DW.MemoryP_DSTATE[1] = 0.0;
    Code_Gen_Model_DW.MemoryP_DSTATE[2] = 0.0;
    Code_Gen_Model_DW.MemoryP_DSTATE[3] = 10.0;
  }

  /* Outputs for Atomic SubSystem: '<S14>/CalculatePL' */
  /* MATLAB Function: '<S15>/Discrete-Time KF - Calculate PLMZ' incorporates:
   *  Constant: '<S14>/A'
   *  Constant: '<S14>/C'
   *  Delay: '<S14>/MemoryP'
   *  Product: '<S34>/Product'
   *  Product: '<S34>/Product2'
   *  Sum: '<S34>/Add1'
   */
  if (rtb_RelationalOperator) {
    rtb_Z_idx_0 = Code_Gen_Model_DW.MemoryP_DSTATE[1];
    rtb_Init_e = Code_Gen_Model_DW.MemoryP_DSTATE[0];
    rtb_Z_idx_2 = Code_Gen_Model_DW.MemoryP_DSTATE[3];
    rtb_Z_idx_3 = Code_Gen_Model_DW.MemoryP_DSTATE[2];
    i = 0;
    for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
      rtb_Atan2_i = Code_Gen_Model_ConstP.pooled19[rtb_Num_Segments + 2];
      rtb_Switch2_p = Code_Gen_Model_ConstP.pooled19[rtb_Num_Segments];
      rtb_Add_kz = (rtb_Atan2_i * rtb_Z_idx_0) + (rtb_Switch2_p * rtb_Init_e);
      rtb_Add_cz = (rtb_Atan2_i * rtb_Z_idx_2) + (rtb_Switch2_p * rtb_Z_idx_3);
      rtb_L[rtb_Num_Segments] = (rtb_Add_cz * rtb_M[1]) + (rtb_Add_kz * rtb_M[0]);
      rtb_L[rtb_Num_Segments + 2] = (rtb_Add_cz * rtb_M[3]) + (rtb_Add_kz *
        rtb_M[2]);
      rtb_Add_kz = rtb_M[i + 1];
      Abar[i] = (rtb_Add_kz * rtb_Z_idx_3) + (rtb_M[i] * rtb_Init_e);
      Abar[i + 1] = (rtb_Add_kz * rtb_Z_idx_2) + (rtb_M[i] * rtb_Z_idx_0);
      i += 2;
    }

    rtb_y_g[0] = rtb_L[0] + rtb_Add1_b[0];
    rtb_M[0] = rtb_L[0] + rtb_Product1[0];
    rtb_y_g[1] = rtb_L[1] + rtb_Add1_b[1];
    rtb_M[1] = rtb_L[1] + rtb_Product1[1];
    rtb_y_g[2] = rtb_L[2] + rtb_Add1_b[2];
    rtb_M[2] = rtb_L[2] + rtb_Product1[2];
    rtb_y_g[3] = rtb_L[3] + rtb_Add1_b[3];
    rtb_M[3] = rtb_L[3] + rtb_Product1[3];
    Code_Gen_Model_mrdiv(rtb_M, rtb_y_g, rtb_L);
    Code_Gen_Model_mrdiv(Abar, rtb_y_g, rtb_M);
    rtb_y_g[1] = 0.0;
    rtb_y_g[2] = 0.0;
    rtb_y_g[0] = 1.0;
    rtb_y_g[3] = 1.0;
    rtb_Switch2_p = rtb_Add1_b[1];
    rtb_Add_kz = rtb_Add1_b[0];
    rtb_Switch2_ef = rtb_Add1_b[3];
    rtb_MatrixConcatenate_b_idx_0 = rtb_Add1_b[2];
    rtb_Z_idx_0 = Code_Gen_Model_DW.MemoryP_DSTATE[1];
    rtb_Init_e = Code_Gen_Model_DW.MemoryP_DSTATE[0];
    rtb_Z_idx_2 = Code_Gen_Model_DW.MemoryP_DSTATE[3];
    rtb_Z_idx_3 = Code_Gen_Model_DW.MemoryP_DSTATE[2];
    for (i = 0; i < 2; i++) {
      rtb_Rotationmatrixfromlocalto_0 = rtb_M[i + 2];
      rtb_Atan2_i = rtb_M[i];
      rtb_thetay = rtb_y_g[i] - ((rtb_Rotationmatrixfromlocalto_0 * 0.0) +
        rtb_Atan2_i);
      Abar[i] = rtb_thetay;
      rtb_y_l3_tmp = rtb_y_g[i + 2] - ((rtb_Atan2_i * 0.0) +
        rtb_Rotationmatrixfromlocalto_0);
      Abar[i + 2] = rtb_y_l3_tmp;
      rtb_M_0[i] = (rtb_Rotationmatrixfromlocalto_0 * rtb_Switch2_p) +
        (rtb_Atan2_i * rtb_Add_kz);
      Abar_0[i] = (rtb_y_l3_tmp * rtb_Z_idx_0) + (rtb_thetay * rtb_Init_e);
      rtb_M_0[i + 2] = (rtb_Rotationmatrixfromlocalto_0 * rtb_Switch2_ef) +
        (rtb_Atan2_i * rtb_MatrixConcatenate_b_idx_0);
      Abar_0[i + 2] = (rtb_y_l3_tmp * rtb_Z_idx_2) + (rtb_thetay * rtb_Z_idx_3);
    }

    rtb_Rotationmatrixfromlocalto_0 = rtb_M[2];
    rtb_Atan2_i = rtb_M[0];
    rtb_Switch2_p = rtb_M[3];
    rtb_Add_kz = rtb_M[1];
    rtb_thetay = Abar[2];
    rtb_y_l3_tmp = Abar[0];
    rtb_Z_idx_0 = Abar[3];
    rtb_Init_e = Abar[1];
    for (i = 0; i < 2; i++) {
      rtb_Switch2_ef = rtb_M_0[i + 2];
      rtb_MatrixConcatenate_b_idx_0 = rtb_M_0[i];
      rtb_y_g[i] = (rtb_Switch2_ef * rtb_Rotationmatrixfromlocalto_0) +
        (rtb_MatrixConcatenate_b_idx_0 * rtb_Atan2_i);
      rtb_Z_idx_2 = Abar_0[i + 2];
      rtb_Z_idx_3 = Abar_0[i];
      Abar[i] = (rtb_Z_idx_2 * rtb_thetay) + (rtb_Z_idx_3 * rtb_y_l3_tmp);
      rtb_y_g[i + 2] = (rtb_Switch2_ef * rtb_Switch2_p) +
        (rtb_MatrixConcatenate_b_idx_0 * rtb_Add_kz);
      Abar[i + 2] = (rtb_Z_idx_2 * rtb_Z_idx_0) + (rtb_Z_idx_3 * rtb_Init_e);
    }

    rtb_Z_idx_0 = Abar[0] + rtb_y_g[0];
    rtb_Init_e = Abar[1] + rtb_y_g[1];
    rtb_Z_idx_2 = Abar[2] + rtb_y_g[2];
    rtb_Z_idx_3 = Abar[3] + rtb_y_g[3];
    Code_Gen_Model_mrdiv(rtb_Product1, rtb_Add1_b, rtb_y_g);
    for (i = 0; i < 2; i++) {
      rtb_Rotationmatrixfromlocalto_0 = rtb_y_g[i + 2];
      rtb_Atan2_i = rtb_y_g[i];
      rtb_thetay = Code_Gen_Model_ConstP.pooled19[i] -
        ((rtb_Rotationmatrixfromlocalto_0 * 0.0) + rtb_Atan2_i);
      Abar[i] = rtb_thetay;
      rtb_y_l3_tmp = Code_Gen_Model_ConstP.pooled19[i + 2] - ((rtb_Atan2_i * 0.0)
        + rtb_Rotationmatrixfromlocalto_0);
      Abar[i + 2] = rtb_y_l3_tmp;
      Abar_0[i] = (rtb_y_l3_tmp * rtb_Init_e) + (rtb_thetay * rtb_Z_idx_0);
      Abar_0[i + 2] = (rtb_y_l3_tmp * rtb_Z_idx_3) + (rtb_thetay * rtb_Z_idx_2);
    }

    rtb_Switch2_p = rtb_Product1[2];
    rtb_Add_kz = rtb_Product1[0];
    rtb_Switch2_ef = rtb_Product1[3];
    rtb_MatrixConcatenate_b_idx_0 = rtb_Product1[1];
    rtb_thetay = Abar[2];
    rtb_y_l3_tmp = Abar[0];
    rtb_Z_idx_0 = Abar[3];
    rtb_Init_e = Abar[1];
    for (i = 0; i < 2; i++) {
      rtb_Rotationmatrixfromlocalto_0 = rtb_y_g[i + 2];
      rtb_Atan2_i = rtb_y_g[i];
      rtb_Product1[i] = (rtb_Rotationmatrixfromlocalto_0 * rtb_Switch2_p) +
        (rtb_Atan2_i * rtb_Add_kz);
      rtb_Z_idx_2 = Abar_0[i + 2];
      rtb_Z_idx_3 = Abar_0[i];
      Abar[i] = ((rtb_Z_idx_2 * rtb_thetay) + (rtb_Z_idx_3 * rtb_y_l3_tmp)) +
        rtb_Product[i];
      rtb_Product1[i + 2] = (rtb_Rotationmatrixfromlocalto_0 * rtb_Switch2_ef) +
        (rtb_Atan2_i * rtb_MatrixConcatenate_b_idx_0);
      Abar[i + 2] = ((rtb_Z_idx_2 * rtb_Z_idx_0) + (rtb_Z_idx_3 * rtb_Init_e)) +
        rtb_Product[i + 2];
    }

    rtb_Add1_b[0] = Abar[0] - rtb_Product1[0];
    rtb_Add1_b[1] = Abar[1] - rtb_Product1[1];
    rtb_Add1_b[2] = Abar[2] - rtb_Product1[2];
    rtb_Add1_b[3] = Abar[3] - rtb_Product1[3];
  } else {
    rtb_L[0] = 0.0;
    rtb_M[0] = 0.0;
    rtb_L[1] = 0.0;
    rtb_M[1] = 0.0;
    rtb_L[2] = 0.0;
    rtb_M[2] = 0.0;
    rtb_L[3] = 0.0;
    rtb_M[3] = 0.0;
    rtb_Z_idx_0 = Code_Gen_Model_DW.MemoryP_DSTATE[1];
    rtb_Init_e = Code_Gen_Model_DW.MemoryP_DSTATE[0];
    rtb_Z_idx_2 = Code_Gen_Model_DW.MemoryP_DSTATE[3];
    rtb_Z_idx_3 = Code_Gen_Model_DW.MemoryP_DSTATE[2];
    for (i = 0; i < 2; i++) {
      rtb_Atan2_i = Code_Gen_Model_ConstP.pooled19[i + 2];
      rtb_Switch2_p = Code_Gen_Model_ConstP.pooled19[i];
      rtb_Add_kz = (rtb_Atan2_i * rtb_Z_idx_0) + (rtb_Switch2_p * rtb_Init_e);
      rtb_Add_cz = (rtb_Atan2_i * rtb_Z_idx_2) + (rtb_Switch2_p * rtb_Z_idx_3);
      rtb_Add1_b[i] = ((rtb_Add_cz * 0.0) + rtb_Add_kz) + rtb_Product[i];
      rtb_Add1_b[i + 2] = ((rtb_Add_kz * 0.0) + rtb_Add_cz) + rtb_Product[i + 2];
    }
  }

  /* End of Outputs for SubSystem: '<S14>/CalculatePL' */

  /* Reshape: '<S14>/Reshapey' incorporates:
   *  Inport: '<Root>/Photon_Est_Pose_X'
   *  Inport: '<Root>/Photon_Est_Pose_Y'
   */
  rtb_Reshapey[0] = Code_Gen_Model_U.Photon_Est_Pose_X;
  rtb_Reshapey[1] = Code_Gen_Model_U.Photon_Est_Pose_Y;

  /* Delay: '<S14>/MemoryX' incorporates:
   *  Constant: '<S14>/X0'
   */
  if (Code_Gen_Model_DW.icLoad_i) {
    Code_Gen_Model_DW.MemoryX_DSTATE[0] = 0.0;
    Code_Gen_Model_DW.MemoryX_DSTATE[1] = 0.0;
  }

  /* Gain: '<S3>/Gain1' incorporates:
   *  Inport: '<Root>/Gyro_Angle'
   */
  rtb_thetay = 0.017453292519943295 * Code_Gen_Model_U.Gyro_Angle;

  /* Trigonometry: '<S8>/Trigonometric Function' */
  rtb_Init_e = cos(rtb_thetay);

  /* Trigonometry: '<S8>/Trigonometric Function1' */
  rtb_Switch2_p = sin(rtb_thetay);

  /* SignalConversion generated from: '<S8>/Rotation matrix from local to global' */
  rtb_Rotationmatrixfromlocaltogl[0] = rtb_Init_e;
  rtb_Rotationmatrixfromlocaltogl[1] = rtb_Switch2_p;

  /* SignalConversion generated from: '<S8>/Rotation matrix from local to global' incorporates:
   *  UnaryMinus: '<S8>/Unary Minus'
   */
  rtb_Rotationmatrixfromlocaltogl[2] = -rtb_Switch2_p;
  rtb_Rotationmatrixfromlocaltogl[3] = rtb_Init_e;

  /* Sum: '<S64>/Diff' incorporates:
   *  UnitDelay: '<S64>/UD'
   *
   * Block description for '<S64>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S64>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Init_e = rtb_thetay - Code_Gen_Model_DW.UD_DSTATE_d;

  /* Sum: '<S8>/Subtract2' incorporates:
   *  Constant: '<S8>/Constant3'
   *  Gain: '<S8>/Gain7'
   *  Math: '<S8>/Square'
   */
  rtb_Switch2_p = 1.0 - ((rtb_Init_e * rtb_Init_e) * 0.16666666666666666);

  /* Gain: '<S8>/Gain6' */
  rtb_Init_e *= 0.5;

  /* Product: '<S8>/Product7' incorporates:
   *  Constant: '<S8>/Constant4'
   */
  for (i = 0; i < 2; i++) {
    rtb_Add_kz = 0.0;
    rtb_Num_Segments = 0;
    for (s104_iter = 0; s104_iter < 8; s104_iter++) {
      rtb_Add_kz += Code_Gen_Model_ConstP.Constant4_Value_d[rtb_Num_Segments + i]
        * rtb_TmpSignalConversionAtProduc[s104_iter];
      rtb_Num_Segments += 2;
    }

    tmp[i] = rtb_Add_kz;
  }

  /* End of Product: '<S8>/Product7' */

  /* Product: '<S8>/Product6' incorporates:
   *  Concatenate: '<S8>/Rotation matrix from local to global'
   *  SignalConversion generated from: '<S8>/POSE exponential matrix for improved accuracy while rotating'
   *  UnaryMinus: '<S8>/Unary Minus2'
   */
  rtb_Rotationmatrixfromlocalto_0 = (rtb_Switch2_p * tmp[0]) + (tmp[1] *
    (-rtb_Init_e));
  rtb_Atan2_i = (tmp[0] * rtb_Init_e) + (tmp[1] * rtb_Switch2_p);
  rtb_y_l3_tmp = (rtb_Rotationmatrixfromlocaltogl[0] *
                  rtb_Rotationmatrixfromlocalto_0) +
    (rtb_Rotationmatrixfromlocaltogl[2] * rtb_Atan2_i);
  rtb_Rotationmatrixfromlocalto_0 = (rtb_Rotationmatrixfromlocaltogl[1] *
    rtb_Rotationmatrixfromlocalto_0) + (rtb_Rotationmatrixfromlocaltogl[3] *
    rtb_Atan2_i);

  /* Outputs for Enabled SubSystem: '<S40>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S63>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S33>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S60>/Enable'
   */
  if (rtb_RelationalOperator) {
    Code_Gen_Model_DW.MeasurementUpdate_MODE = true;

    /* Product: '<S60>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S14>/C'
     *  Delay: '<S14>/MemoryX'
     *  Product: '<S63>/Product'
     */
    rtb_Z_idx_0 = (0.0 * Code_Gen_Model_DW.MemoryX_DSTATE[1]) +
      Code_Gen_Model_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Z_idx_0;

    /* Sum: '<S60>/Sum' incorporates:
     *  Constant: '<S14>/D'
     *  Product: '<S60>/C[k]*xhat[k|k-1]'
     *  Product: '<S60>/D[k]*u[k]'
     *  Product: '<S8>/Product6'
     *  Sum: '<S60>/Add1'
     */
    rtb_Init_e = (0.0 * rtb_y_l3_tmp) + (0.0 * rtb_Rotationmatrixfromlocalto_0);
    rtb_Atan2_i = rtb_Reshapey[0] - (rtb_Init_e + rtb_Z_idx_0);

    /* Product: '<S60>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S14>/C'
     *  Delay: '<S14>/MemoryX'
     *  Product: '<S63>/Product'
     */
    rtb_Z_idx_0 = (0.0 * Code_Gen_Model_DW.MemoryX_DSTATE[0]) +
      Code_Gen_Model_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Z_idx_0;

    /* Sum: '<S60>/Sum' incorporates:
     *  Constant: '<S14>/D'
     *  Product: '<S60>/C[k]*xhat[k|k-1]'
     *  Product: '<S60>/D[k]*u[k]'
     *  Sum: '<S60>/Add1'
     */
    rtb_Z_idx_0 = rtb_Reshapey[1] - (rtb_Init_e + rtb_Z_idx_0);
    Code_Gen_Model_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S60>/Product3' */
    Code_Gen_Model_B.Product3[0] = (rtb_L[0] * rtb_Atan2_i) + (rtb_L[2] *
      rtb_Z_idx_0);

    /* Sum: '<S63>/Add1' incorporates:
     *  Product: '<S63>/Product'
     */
    rtb_Init_e = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S60>/Product3' */
    Code_Gen_Model_B.Product3[1] = (rtb_L[1] * rtb_Atan2_i) + (rtb_L[3] *
      rtb_Z_idx_0);

    /* Sum: '<S63>/Add1' incorporates:
     *  Product: '<S63>/Product'
     */
    rtb_Z_idx_0 = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S63>/Product2' */
    Code_Gen_Model_B.Product2[0] = (rtb_M[0] * rtb_Init_e) + (rtb_M[2] *
      rtb_Z_idx_0);
    Code_Gen_Model_B.Product2[1] = (rtb_M[1] * rtb_Init_e) + (rtb_M[3] *
      rtb_Z_idx_0);
  } else {
    if (Code_Gen_Model_DW.MeasurementUpdate_MODE) {
      /* Disable for Product: '<S60>/Product3' incorporates:
       *  Outport: '<S60>/L*(y[k]-yhat[k|k-1])'
       */
      Code_Gen_Model_B.Product3[0] = 0.0;
      Code_Gen_Model_B.Product3[1] = 0.0;
      Code_Gen_Model_DW.MeasurementUpdate_MODE = false;
    }

    if (Code_Gen_Model_DW.EnabledSubsystem_MODE) {
      /* Disable for Product: '<S63>/Product2' incorporates:
       *  Outport: '<S63>/deltax'
       */
      Code_Gen_Model_B.Product2[0] = 0.0;
      Code_Gen_Model_B.Product2[1] = 0.0;
      Code_Gen_Model_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S33>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S40>/Enabled Subsystem' */

  /* Reshape: '<S14>/Reshapexhat' incorporates:
   *  Delay: '<S14>/MemoryX'
   *  Sum: '<S40>/Add'
   */
  Code_Gen_Model_B.Reshapexhat[0] = Code_Gen_Model_B.Product2[0] +
    Code_Gen_Model_DW.MemoryX_DSTATE[0];
  Code_Gen_Model_B.Reshapexhat[1] = Code_Gen_Model_B.Product2[1] +
    Code_Gen_Model_DW.MemoryX_DSTATE[1];

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtPrevAction = Code_Gen_Model_DW.SwitchCase_ActiveSubsystem;
  rtb_Add_kz = trunc(Code_Gen_Model_U.GameState);
  if ((rtIsNaN(rtb_Add_kz)) || (rtIsInf(rtb_Add_kz))) {
    rtb_Add_kz = 0.0;
  } else {
    rtb_Add_kz = fmod(rtb_Add_kz, 4.294967296E+9);
  }

  switch ((rtb_Add_kz < 0.0) ? (-((int32_T)((uint32_T)(-rtb_Add_kz)))) :
          ((int32_T)((uint32_T)rtb_Add_kz))) {
   case 0:
    rtAction = 0;
    break;

   case 1:
    rtAction = 1;
    break;

   case 2:
    rtAction = 2;
    break;

   default:
    rtAction = 3;
    break;
  }

  Code_Gen_Model_DW.SwitchCase_ActiveSubsystem = rtAction;
  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Disabled' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    Code_Gen_Model_Disabled(&rtb_Z_idx_0, &Code_Gen_Model_B.Steering_Abs_Cmd,
      &Code_Gen_Model_B.Steering_Rel_Cmd, &Code_Gen_Model_B.Translation_Angle,
      &Code_Gen_Model_B.Translation_Speed, &rtb_RelationalOperator,
      &rtb_Is_Absolute_Steering, &Code_Gen_Model_B.Spline_Enable,
      rtb_Spline_Ref_Poses, &Code_Gen_Model_B.Spline_Num_Poses);

    /* End of Outputs for SubSystem: '<S1>/Disabled' */
    break;

   case 1:
    if (rtAction != rtPrevAction) {
      /* InitializeConditions for IfAction SubSystem: '<S1>/Autonomous' incorporates:
       *  ActionPort: '<S2>/Action Port'
       */
      /* InitializeConditions for SwitchCase: '<S1>/Switch Case' incorporates:
       *  UnitDelay: '<S2>/Unit Delay'
       */
      Code_Gen_Model_DW.UnitDelay_DSTATE_l1 = 0.0;

      /* End of InitializeConditions for SubSystem: '<S1>/Autonomous' */
    }

    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* SignalConversion generated from: '<S2>/Spline_Ref_Poses' incorporates:
     *  Constant: '<S2>/Constant4'
     *  Merge: '<S7>/Merge8'
     */
    memcpy(&rtb_Spline_Ref_Poses[0], &Code_Gen_Model_ConstP.Constant4_Value[0],
           76U * (sizeof(real_T)));

    /* SignalConversion generated from: '<S2>/Gyro_Angle_Adjustment' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    rtb_Z_idx_0 = 0.0;

    /* Merge: '<S7>/Merge1' incorporates:
     *  Constant: '<S2>/Constant10'
     *  SignalConversion: '<S2>/Signal Copy'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd = 0.78539816339744828;

    /* Merge: '<S7>/Merge2' incorporates:
     *  Constant: '<S2>/Constant2'
     *  SignalConversion: '<S2>/Signal Copy2'
     */
    Code_Gen_Model_B.Steering_Rel_Cmd = 0.0;

    /* Sum: '<S2>/Subtract' incorporates:
     *  Constant: '<S2>/Constant8'
     */
    rtb_Atan2_i = Odometry_Desired_Y - Code_Gen_Model_B.Reshapexhat[1];

    /* Sum: '<S2>/Subtract1' incorporates:
     *  Constant: '<S2>/Constant7'
     */
    rtb_Init_e = Odometry_Desired_X - Code_Gen_Model_B.Reshapexhat[0];

    /* Merge: '<S7>/Merge4' incorporates:
     *  Constant: '<S2>/Constant'
     *  Math: '<S2>/Hypot'
     *  MinMax: '<S2>/Min'
     *  SignalConversion: '<S2>/Signal Copy3'
     */
    Code_Gen_Model_B.Translation_Speed = fmin(rt_hypotd_snf(rtb_Atan2_i,
      rtb_Init_e), 1.0);

    /* Merge: '<S7>/Merge3' incorporates:
     *  SignalConversion: '<S2>/Signal Copy1'
     *  Trigonometry: '<S2>/Atan2'
     */
    Code_Gen_Model_B.Translation_Angle = rt_atan2d_snf(rtb_Atan2_i, rtb_Init_e);

    /* SignalConversion generated from: '<S2>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S2>/Constant5'
     */
    rtb_RelationalOperator = true;

    /* SignalConversion generated from: '<S2>/Is_Absolute_Steering' incorporates:
     *  Constant: '<S2>/Constant6'
     */
    rtb_Is_Absolute_Steering = true;

    /* Switch: '<S2>/Switch1' incorporates:
     *  Constant: '<S2>/Constant11'
     *  Constant: '<S2>/Constant14'
     *  Sum: '<S2>/Sum'
     *  UnitDelay: '<S2>/Unit Delay'
     *  UnitDelay: '<S5>/Unit Delay'
     */
    if (Code_Gen_Model_DW.UnitDelay_DSTATE_ll) {
      rtb_Atan2_i = 0.0;
    } else {
      rtb_Atan2_i = Code_Gen_Model_DW.UnitDelay_DSTATE_l1 + 0.02;
    }

    /* End of Switch: '<S2>/Switch1' */

    /* Merge: '<S7>/Merge7' incorporates:
     *  Constant: '<S2>/Constant12'
     *  Logic: '<S2>/OR'
     *  RelationalOperator: '<S2>/Relational Operator'
     *  Switch: '<S2>/Switch'
     *  UnitDelay: '<S5>/Unit Delay'
     */
    Code_Gen_Model_B.Spline_Enable = ((!Code_Gen_Model_DW.UnitDelay_DSTATE_ll) &&
      (!(rtb_Atan2_i < 1.0)));

    /* Merge: '<S7>/Merge9' incorporates:
     *  Constant: '<S2>/Constant9'
     *  SignalConversion generated from: '<S2>/Spline_Num_Poses'
     */
    Code_Gen_Model_B.Spline_Num_Poses = 19.0;

    /* Update for UnitDelay: '<S2>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_l1 = rtb_Atan2_i;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Teleop' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    /* SignalConversion generated from: '<S12>/Spline_Ref_Poses' incorporates:
     *  Merge: '<S7>/Merge8'
     */
    memset(&rtb_Spline_Ref_Poses[0], 0, 76U * (sizeof(real_T)));

    /* Switch: '<S286>/Switch1' incorporates:
     *  Constant: '<S286>/Constant'
     *  Constant: '<S286>/Constant1'
     *  Constant: '<S286>/Constant2'
     *  Inport: '<Root>/Steer_Joystick_X'
     *  Inport: '<Root>/Steer_Joystick_Y'
     *  Math: '<S286>/Hypot'
     *  RelationalOperator: '<S286>/GreaterThan'
     *  Switch: '<S286>/Switch'
     */
    if (rt_hypotd_snf(Code_Gen_Model_U.Steer_Joystick_X,
                      Code_Gen_Model_U.Steer_Joystick_Y) >
        Steering_Abs_Deadband_Range) {
      rtb_Z_idx_0 = Code_Gen_Model_U.Steer_Joystick_Y;
      rtb_Atan2_i = Code_Gen_Model_U.Steer_Joystick_X;
    } else {
      rtb_Z_idx_0 = 0.0;
      rtb_Atan2_i = 0.0;
    }

    /* End of Switch: '<S286>/Switch1' */

    /* Switch: '<S288>/Switch1' incorporates:
     *  Constant: '<S294>/Constant'
     *  Constant: '<S295>/Constant'
     *  Logic: '<S288>/AND'
     *  RelationalOperator: '<S294>/Compare'
     *  RelationalOperator: '<S295>/Compare'
     *  Switch: '<S288>/Switch2'
     *  UnitDelay: '<S288>/Unit Delay'
     *  UnitDelay: '<S288>/Unit Delay1'
     */
    if ((rtb_Atan2_i == 0.0) && (rtb_Z_idx_0 == 0.0)) {
      rtb_Init_e = Code_Gen_Model_DW.UnitDelay1_DSTATE_d2;
      rtb_Z_idx_2 = Code_Gen_Model_DW.UnitDelay_DSTATE_g4;
    } else {
      rtb_Init_e = rtb_Z_idx_0;
      rtb_Z_idx_2 = rtb_Atan2_i;
    }

    /* End of Switch: '<S288>/Switch1' */

    /* Merge: '<S7>/Merge1' incorporates:
     *  Trigonometry: '<S284>/Atan2'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd = rt_atan2d_snf(rtb_Init_e, rtb_Z_idx_2);

    /* RelationalOperator: '<S291>/Compare' incorporates:
     *  Constant: '<S291>/Constant'
     */
    rtb_RelationalOperator = (rtb_Z_idx_2 < 0.0);

    /* Switch: '<S287>/Switch' incorporates:
     *  Constant: '<S287>/Constant'
     *  Constant: '<S287>/Constant1'
     *  Constant: '<S289>/Constant'
     *  Constant: '<S290>/Constant'
     *  Logic: '<S287>/Logical Operator'
     *  RelationalOperator: '<S289>/Compare'
     *  RelationalOperator: '<S290>/Compare'
     *  UnitDelay: '<S287>/Unit Delay'
     */
    if (((rtb_Init_e < 0.0) && (Code_Gen_Model_DW.UnitDelay_DSTATE_h >= 0.0)) &&
        rtb_RelationalOperator) {
      rtb_Add_kz = 6.2831853071795862;
    } else {
      rtb_Add_kz = 0.0;
    }

    /* Switch: '<S287>/Switch1' incorporates:
     *  Constant: '<S287>/Constant2'
     *  Constant: '<S287>/Constant3'
     *  Constant: '<S292>/Constant'
     *  Constant: '<S293>/Constant'
     *  Logic: '<S287>/Logical Operator1'
     *  RelationalOperator: '<S292>/Compare'
     *  RelationalOperator: '<S293>/Compare'
     *  UnitDelay: '<S287>/Unit Delay'
     */
    if (((Code_Gen_Model_DW.UnitDelay_DSTATE_h < 0.0) && (rtb_Init_e >= 0.0)) &&
        rtb_RelationalOperator) {
      rtb_Add_cz = -6.2831853071795862;
    } else {
      rtb_Add_cz = 0.0;
    }

    /* Sum: '<S287>/Sum1' incorporates:
     *  Switch: '<S287>/Switch'
     *  Switch: '<S287>/Switch1'
     *  UnitDelay: '<S287>/Unit Delay1'
     */
    rtb_Z_idx_0 = (rtb_Add_kz + rtb_Add_cz) +
      Code_Gen_Model_DW.UnitDelay1_DSTATE_kr;

    /* Lookup_n-D: '<S285>/Modulation_Drv_X' incorporates:
     *  Inport: '<Root>/Drive_Joystick_X'
     */
    rtb_Steer_Joystick_X_Rel_Mod = look1_binlcpw
      (Code_Gen_Model_U.Drive_Joystick_X, Code_Gen_Model_ConstP.pooled18,
       Code_Gen_Model_ConstP.pooled17, 20U);

    /* Lookup_n-D: '<S285>/Modulation_Drv_Y' incorporates:
     *  Inport: '<Root>/Drive_Joystick_Y'
     */
    rtb_Atan2_i = look1_binlcpw(Code_Gen_Model_U.Drive_Joystick_Y,
      Code_Gen_Model_ConstP.pooled18, Code_Gen_Model_ConstP.pooled17, 20U);

    /* Switch: '<S297>/Switch1' incorporates:
     *  Constant: '<S302>/Constant'
     *  Constant: '<S303>/Constant'
     *  Logic: '<S297>/AND'
     *  RelationalOperator: '<S302>/Compare'
     *  RelationalOperator: '<S303>/Compare'
     *  Switch: '<S297>/Switch2'
     *  UnitDelay: '<S297>/Unit Delay'
     *  UnitDelay: '<S297>/Unit Delay1'
     */
    if ((rtb_Steer_Joystick_X_Rel_Mod == 0.0) && (rtb_Atan2_i == 0.0)) {
      rtb_Z_idx_3 = Code_Gen_Model_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2_ef = Code_Gen_Model_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Z_idx_3 = rtb_Atan2_i;
      rtb_Switch2_ef = rtb_Steer_Joystick_X_Rel_Mod;
    }

    /* End of Switch: '<S297>/Switch1' */

    /* Merge: '<S7>/Merge3' incorporates:
     *  Trigonometry: '<S285>/Atan2'
     */
    Code_Gen_Model_B.Translation_Angle = rt_atan2d_snf(rtb_Z_idx_3,
      rtb_Switch2_ef);

    /* Math: '<S285>/Magnitude' */
    rtb_Magnitude = rt_hypotd_snf(rtb_Steer_Joystick_X_Rel_Mod, rtb_Atan2_i);

    /* Switch: '<S296>/Switch1' incorporates:
     *  Constant: '<S296>/Constant'
     *  Constant: '<S296>/Constant1'
     *  Inport: '<Root>/Is_Boost_Trigger_Pulled'
     */
    if (Code_Gen_Model_U.Is_Boost_Trigger_Pulled != 0.0) {
      rtb_Steer_Joystick_X_Rel_Mod = Boost_Trigger_High_Speed;
    } else {
      rtb_Steer_Joystick_X_Rel_Mod = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S296>/Switch1' */

    /* Switch: '<S301>/Init' incorporates:
     *  UnitDelay: '<S301>/FixPt Unit Delay1'
     *  UnitDelay: '<S301>/FixPt Unit Delay2'
     */
    if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Atan2_i = rtb_Steer_Joystick_X_Rel_Mod;
    } else {
      rtb_Atan2_i = Code_Gen_Model_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S301>/Init' */

    /* Sum: '<S299>/Sum1' */
    rtb_Steer_Joystick_X_Rel_Mod -= rtb_Atan2_i;

    /* Switch: '<S300>/Switch2' incorporates:
     *  Constant: '<S298>/Constant1'
     *  Constant: '<S298>/Constant3'
     *  RelationalOperator: '<S300>/LowerRelop1'
     *  RelationalOperator: '<S300>/UpperRelop'
     *  Switch: '<S300>/Switch'
     */
    if (rtb_Steer_Joystick_X_Rel_Mod > Boost_Trigger_Increasing_Limit) {
      rtb_Steer_Joystick_X_Rel_Mod = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Steer_Joystick_X_Rel_Mod < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S300>/Switch' incorporates:
       *  Constant: '<S298>/Constant1'
       */
      rtb_Steer_Joystick_X_Rel_Mod = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S300>/Switch2' */

    /* Sum: '<S299>/Sum' */
    rtb_Atan2_i += rtb_Steer_Joystick_X_Rel_Mod;

    /* Product: '<S296>/Product' */
    rtb_Add_ec = rtb_Magnitude * rtb_Atan2_i;

    /* Saturate: '<S296>/Saturation' */
    if (rtb_Add_ec > Boost_Trigger_High_Speed) {
      /* Merge: '<S7>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = Boost_Trigger_High_Speed;
    } else if (rtb_Add_ec < (-Boost_Trigger_High_Speed)) {
      /* Merge: '<S7>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = -Boost_Trigger_High_Speed;
    } else {
      /* Merge: '<S7>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = rtb_Add_ec;
    }

    /* End of Saturate: '<S296>/Saturation' */

    /* Merge: '<S7>/Merge7' incorporates:
     *  Constant: '<S12>/Constant3'
     *  SignalConversion generated from: '<S12>/Spline_Enable'
     */
    Code_Gen_Model_B.Spline_Enable = false;

    /* Merge: '<S7>/Merge2' incorporates:
     *  Constant: '<S284>/Constant'
     *  Inport: '<Root>/Steer_Joystick_Y'
     *  Lookup_n-D: '<S284>/Modulation_Str_X_Rel'
     *  Product: '<S284>/Product'
     */
    Code_Gen_Model_B.Steering_Rel_Cmd = look1_binlcpw
      (Code_Gen_Model_U.Steer_Joystick_Y,
       Code_Gen_Model_ConstP.Modulation_Str_X_Rel_bp01Data,
       Code_Gen_Model_ConstP.Modulation_Str_X_Rel_tableData, 20U) *
      Steering_Relative_Gain;

    /* Merge: '<S7>/Merge9' incorporates:
     *  Constant: '<S12>/Constant9'
     *  SignalConversion generated from: '<S12>/Spline_Num_Poses'
     */
    Code_Gen_Model_B.Spline_Num_Poses = 19.0;

    /* SignalConversion generated from: '<S12>/Is_Absolute_Translation_In' incorporates:
     *  Inport: '<Root>/Is_Absolute_Translation'
     */
    rtb_RelationalOperator = Code_Gen_Model_U.Is_Absolute_Translation;

    /* SignalConversion generated from: '<S12>/Is_Absolute_Steering_In' incorporates:
     *  Inport: '<Root>/Is_Absolute_Steering'
     */
    rtb_Is_Absolute_Steering = Code_Gen_Model_U.Is_Absolute_Steering;

    /* Update for UnitDelay: '<S288>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_d2 = rtb_Init_e;

    /* Update for UnitDelay: '<S288>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_g4 = rtb_Z_idx_2;

    /* Update for UnitDelay: '<S287>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_h = rtb_Init_e;

    /* Update for UnitDelay: '<S287>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_kr = rtb_Z_idx_0;

    /* Update for UnitDelay: '<S297>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_l = rtb_Z_idx_3;

    /* Update for UnitDelay: '<S297>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_p = rtb_Switch2_ef;

    /* Update for UnitDelay: '<S301>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S301>/FixPt Constant'
     */
    Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S301>/FixPt Unit Delay1' */
    Code_Gen_Model_DW.FixPtUnitDelay1_DSTATE_f = rtb_Atan2_i;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    Code_Gen_Model_Disabled(&rtb_Z_idx_0, &Code_Gen_Model_B.Steering_Abs_Cmd,
      &Code_Gen_Model_B.Steering_Rel_Cmd, &Code_Gen_Model_B.Translation_Angle,
      &Code_Gen_Model_B.Translation_Speed, &rtb_RelationalOperator,
      &rtb_Is_Absolute_Steering, &Code_Gen_Model_B.Spline_Enable,
      rtb_Spline_Ref_Poses, &Code_Gen_Model_B.Spline_Num_Poses);

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* If: '<S9>/If' incorporates:
   *  Constant: '<S129>/Constant'
   *  Constant: '<S78>/Lookahead Distance'
   *  Logic: '<S129>/AND'
   *  MATLAB Function: '<S78>/Find closest index to curve'
   *  Product: '<S129>/Product'
   *  RelationalOperator: '<S129>/Relational Operator'
   *  RelationalOperator: '<S129>/Relational Operator1'
   *  Selector: '<S129>/Selector'
   *  Selector: '<S129>/Selector1'
   *  Selector: '<S130>/Selector'
   *  Sum: '<S129>/Add'
   */
  rtPrevAction = Code_Gen_Model_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Code_Gen_Model_B.Spline_Enable);
  Code_Gen_Model_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S81>/If' */
    if (Code_Gen_Model_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S84>/If' */
      if (Code_Gen_Model_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S86>/If' */
        Code_Gen_Model_DW.If_ActiveSubsystem_d = -1;
      }

      Code_Gen_Model_DW.If_ActiveSubsystem_o = -1;
    }

    Code_Gen_Model_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S81>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S9>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S76>/Action Port'
       */
      /* InitializeConditions for If: '<S9>/If' incorporates:
       *  UnitDelay: '<S130>/Unit Delay'
       *  UnitDelay: '<S130>/Unit Delay1'
       *  UnitDelay: '<S77>/Unit Delay'
       *  UnitDelay: '<S79>/Unit Delay'
       *  UnitDelay: '<S79>/Unit Delay1'
       */
      Code_Gen_Model_DW.UnitDelay_DSTATE_gh = 2.0;
      Code_Gen_Model_DW.UnitDelay1_DSTATE_f4 = 0.0;
      Code_Gen_Model_DW.UnitDelay_DSTATE_g4g = 0.0;
      Code_Gen_Model_DW.UnitDelay_DSTATE_le = 0.0;
      Code_Gen_Model_DW.UnitDelay1_DSTATE_kc = 0.0;

      /* End of InitializeConditions for SubSystem: '<S9>/Spline Path Following Enabled' */
    }

    /* Outputs for IfAction SubSystem: '<S9>/Spline Path Following Enabled' incorporates:
     *  ActionPort: '<S76>/Action Port'
     */
    /* Selector: '<S77>/Selector1' incorporates:
     *  Merge: '<S7>/Merge8'
     */
    for (i = 0; i < 19; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses[i];
      rtb_Ref_Poses[i + 19] = rtb_Spline_Ref_Poses[i + 19];
    }

    /* End of Selector: '<S77>/Selector1' */

    /* SignalConversion generated from: '<S77>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Code_Gen_Model_B.Reshapexhat[0];

    /* SignalConversion generated from: '<S77>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Code_Gen_Model_B.Reshapexhat[1];

    /* If: '<S81>/If' incorporates:
     *  RelationalOperator: '<S81>/ '
     *  UnitDelay: '<S77>/Unit Delay'
     */
    rtPrevAction = Code_Gen_Model_DW.If_ActiveSubsystem_h;
    rtAction = (int8_T)(!(Code_Gen_Model_DW.UnitDelay_DSTATE_gh <=
                          Code_Gen_Model_B.Spline_Num_Poses));
    Code_Gen_Model_DW.If_ActiveSubsystem_h = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S84>/If' */
      if (Code_Gen_Model_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S86>/If' */
        Code_Gen_Model_DW.If_ActiveSubsystem_d = -1;
      }

      Code_Gen_Model_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S81>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S84>/Action Port'
       */
      /* InitializeConditions for If: '<S81>/If' incorporates:
       *  UnitDelay: '<S84>/Unit Delay'
       */
      Code_Gen_Model_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Code_Gen_Model_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S81>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S81>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S84>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S84>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S88>/Action Port'
       */
      /* If: '<S84>/If' incorporates:
       *  Selector: '<S77>/Selector1'
       *  Selector: '<S84>/Selector'
       *  Selector: '<S88>/Selector'
       */
      rtb_Add_kz = rtb_Ref_Poses[((int32_T)Code_Gen_Model_DW.UnitDelay_DSTATE_gh)
        - 1];

      /* End of Outputs for SubSystem: '<S84>/Increment_If_Rectangle_Check' */

      /* Sum: '<S84>/Minus' incorporates:
       *  Concatenate: '<S77>/Matrix Concatenate2'
       *  Selector: '<S84>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Add_kz;

      /* Outputs for IfAction SubSystem: '<S84>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S88>/Action Port'
       */
      /* If: '<S84>/If' incorporates:
       *  Selector: '<S77>/Selector1'
       *  Selector: '<S84>/Selector'
       *  Selector: '<S88>/Selector'
       *  Sum: '<S84>/Minus'
       */
      rtb_Init_e = rtb_Ref_Poses[((int32_T)Code_Gen_Model_DW.UnitDelay_DSTATE_gh)
        + 18];

      /* End of Outputs for SubSystem: '<S84>/Increment_If_Rectangle_Check' */

      /* Sum: '<S84>/Minus' incorporates:
       *  Concatenate: '<S77>/Matrix Concatenate2'
       *  Selector: '<S84>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_Init_e;

      /* Math: '<S84>/Hypot' */
      rtb_Z_idx_0 = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S84>/Equal' */
      rtb_Is_Absolute_Steering = (Code_Gen_Model_B.Spline_Num_Poses ==
        Code_Gen_Model_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S84>/Switch' incorporates:
       *  Constant: '<S87>/Constant'
       *  Logic: '<S84>/AND'
       *  Logic: '<S84>/OR'
       *  RelationalOperator: '<S87>/Compare'
       *  UnitDelay: '<S84>/Unit Delay'
       */
      rtb_RelationalOperator = ((Code_Gen_Model_DW.UnitDelay_DSTATE_e4) ||
        (rtb_Is_Absolute_Steering && (rtb_Z_idx_0 <= Spline_Capture_Radius)));

      /* If: '<S84>/If' */
      rtPrevAction = Code_Gen_Model_DW.If_ActiveSubsystem_o;
      if (!rtb_RelationalOperator) {
        if (!rtb_Is_Absolute_Steering) {
          rtAction = 1;
        } else {
          rtAction = 2;
        }
      }

      Code_Gen_Model_DW.If_ActiveSubsystem_o = rtAction;
      if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
        /* Disable for If: '<S86>/If' */
        Code_Gen_Model_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S84>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S86>/Action Port'
         */
        /* If: '<S86>/If' incorporates:
         *  RelationalOperator: '<S86>/Equal'
         */
        rtPrevAction = Code_Gen_Model_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Code_Gen_Model_DW.UnitDelay_DSTATE_gh ==
                              Code_Gen_Model_B.Spline_Num_Poses));
        Code_Gen_Model_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S86>/Is_Last_Point' incorporates:
           *  ActionPort: '<S90>/Action Port'
           */
          /* InitializeConditions for If: '<S86>/If' incorporates:
           *  UnitDelay: '<S90>/Unit Delay'
           */
          Code_Gen_Model_DW.UnitDelay_DSTATE_n = ((rtPrevAction == 0) &&
            (Code_Gen_Model_DW.UnitDelay_DSTATE_n));

          /* End of InitializeConditions for SubSystem: '<S86>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S86>/Is_Last_Point' incorporates:
           *  ActionPort: '<S90>/Action Port'
           */
          /* Switch: '<S90>/Switch' incorporates:
           *  Constant: '<S92>/Constant'
           *  Logic: '<S90>/OR'
           *  RelationalOperator: '<S92>/Compare'
           *  UnitDelay: '<S90>/Unit Delay'
           */
          rtb_Switch_b1 = ((Code_Gen_Model_DW.UnitDelay_DSTATE_n) ||
                           (rtb_Z_idx_0 <= 0.05));

          /* If: '<S90>/If' */
          if (rtb_Switch_b1) {
            /* Outputs for IfAction SubSystem: '<S90>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S93>/Action Port'
             */
            /* Merge: '<S81>/Merge2' incorporates:
             *  Constant: '<S93>/Constant'
             *  SignalConversion generated from: '<S93>/Robot_Reached_Destination'
             */
            rtb_Is_Absolute_Steering = true;

            /* SignalConversion generated from: '<S93>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S93>/Constant1'
             */
            rtb_OR_ao = false;

            /* End of Outputs for SubSystem: '<S90>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S90>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S94>/Action Port'
             */
            /* Merge: '<S81>/Merge2' incorporates:
             *  Constant: '<S94>/Constant'
             *  SignalConversion generated from: '<S94>/Robot_Reached_Destination'
             */
            rtb_Is_Absolute_Steering = false;

            /* SignalConversion generated from: '<S94>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S94>/Constant1'
             */
            rtb_OR_ao = true;

            /* End of Outputs for SubSystem: '<S90>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S90>/If' */

          /* Merge: '<S81>/Merge4' incorporates:
           *  SignalConversion: '<S90>/Signal Copy'
           */
          Code_Gen_Model_B.Spline_Index = Code_Gen_Model_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S90>/Unit Delay' */
          Code_Gen_Model_DW.UnitDelay_DSTATE_n = rtb_Switch_b1;

          /* End of Outputs for SubSystem: '<S86>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S86>/Increment_Search' incorporates:
           *  ActionPort: '<S89>/Action Port'
           */
          /* Merge: '<S81>/Merge2' incorporates:
           *  Constant: '<S89>/Constant'
           *  SignalConversion generated from: '<S89>/Robot_Reached_Destination'
           */
          rtb_Is_Absolute_Steering = false;

          /* SignalConversion generated from: '<S89>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S89>/Constant1'
           */
          rtb_OR_ao = false;

          /* Merge: '<S81>/Merge4' incorporates:
           *  Constant: '<S91>/FixPt Constant'
           *  SignalConversion: '<S89>/Signal Copy'
           *  Sum: '<S91>/FixPt Sum1'
           */
          Code_Gen_Model_B.Spline_Index = Code_Gen_Model_DW.UnitDelay_DSTATE_gh
            + 1.0;

          /* End of Outputs for SubSystem: '<S86>/Increment_Search' */
        }

        /* End of If: '<S86>/If' */
        /* End of Outputs for SubSystem: '<S84>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S84>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S88>/Action Port'
         */
        /* Sum: '<S95>/FixPt Sum1' incorporates:
         *  Constant: '<S95>/FixPt Constant'
         */
        rtb_Z_idx_0 = Code_Gen_Model_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S88>/Selector1' incorporates:
         *  Selector: '<S77>/Selector1'
         */
        rtb_Z_idx_3 = rtb_Ref_Poses[((int32_T)rtb_Z_idx_0) - 1];

        /* Sum: '<S96>/Subtract' incorporates:
         *  Selector: '<S88>/Selector1'
         *  Sum: '<S96>/Minus1'
         */
        rtb_Minus_n[0] = rtb_Z_idx_3 - rtb_Add_kz;

        /* Selector: '<S88>/Selector1' incorporates:
         *  Selector: '<S77>/Selector1'
         */
        rtb_Z_idx_2 = rtb_Ref_Poses[((int32_T)rtb_Z_idx_0) + 18];

        /* Sum: '<S96>/Subtract' incorporates:
         *  Selector: '<S88>/Selector1'
         *  Sum: '<S96>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Z_idx_2 - rtb_Init_e;

        /* Math: '<S96>/Hypot' */
        rtb_Atan2_i = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S96>/Divide' */
        rtb_Z_idx_0 = rtb_Minus_n[1];

        /* UnaryMinus: '<S96>/Unary Minus' */
        rtb_Switch2_p = rtb_Minus_n[0];

        /* Product: '<S96>/Product' incorporates:
         *  Constant: '<S88>/Constant'
         *  Product: '<S96>/Divide'
         *  UnaryMinus: '<S96>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Z_idx_0 / rtb_Atan2_i) * Spline_Capture_Radius;
        rtb_Minus_n[1] = ((-rtb_Switch2_p) / rtb_Atan2_i) *
          Spline_Capture_Radius;

        /* Sum: '<S96>/Add1' incorporates:
         *  Sum: '<S96>/Add2'
         *  Sum: '<S96>/Minus'
         */
        rtb_Switch2_p = rtb_Z_idx_3 - rtb_Minus_n[0];

        /* Sum: '<S96>/Minus4' incorporates:
         *  Sum: '<S96>/Add2'
         *  Sum: '<S96>/Minus'
         */
        rtb_Z_idx_3 = (rtb_Z_idx_3 + rtb_Minus_n[0]) - rtb_Switch2_p;

        /* Sum: '<S96>/Minus5' incorporates:
         *  Concatenate: '<S77>/Matrix Concatenate2'
         *  Sum: '<S96>/Minus'
         */
        rtb_Switch2_ef = rtb_Reshapey[0] - rtb_Switch2_p;

        /* Sum: '<S96>/Add' incorporates:
         *  Sum: '<S96>/Add2'
         *  Sum: '<S96>/Minus1'
         */
        rtb_Z_idx_0 = rtb_Add_kz - rtb_Minus_n[0];

        /* Sum: '<S96>/Minus' incorporates:
         *  Sum: '<S96>/Minus1'
         */
        rtb_Switch2_p -= rtb_Z_idx_0;

        /* DotProduct: '<S96>/Dot Product' incorporates:
         *  Concatenate: '<S77>/Matrix Concatenate2'
         *  Sum: '<S96>/Minus'
         *  Sum: '<S96>/Minus1'
         *  Sum: '<S96>/Minus5'
         */
        rtb_Atan2_i = (rtb_Reshapey[0] - rtb_Z_idx_0) * rtb_Switch2_p;

        /* DotProduct: '<S96>/Dot Product1' incorporates:
         *  Sum: '<S96>/Minus'
         */
        rtb_Add_kz = rtb_Switch2_p * rtb_Switch2_p;

        /* DotProduct: '<S96>/Dot Product2' incorporates:
         *  Sum: '<S96>/Minus4'
         *  Sum: '<S96>/Minus5'
         */
        rtb_MatrixConcatenate_b_idx_0 = rtb_Z_idx_3 * rtb_Switch2_ef;

        /* DotProduct: '<S96>/Dot Product3' incorporates:
         *  Sum: '<S96>/Minus4'
         */
        rtb_Steer_Joystick_X_Rel_Mod = rtb_Z_idx_3 * rtb_Z_idx_3;

        /* Sum: '<S96>/Add1' incorporates:
         *  Sum: '<S96>/Add2'
         *  Sum: '<S96>/Minus'
         */
        rtb_Switch2_p = rtb_Z_idx_2 - rtb_Minus_n[1];

        /* Sum: '<S96>/Minus4' incorporates:
         *  Sum: '<S96>/Add2'
         *  Sum: '<S96>/Minus'
         */
        rtb_Z_idx_3 = (rtb_Z_idx_2 + rtb_Minus_n[1]) - rtb_Switch2_p;

        /* Sum: '<S96>/Minus5' incorporates:
         *  Concatenate: '<S77>/Matrix Concatenate2'
         *  Sum: '<S96>/Minus'
         */
        rtb_Switch2_ef = rtb_Reshapey[1] - rtb_Switch2_p;

        /* Sum: '<S96>/Add' incorporates:
         *  Sum: '<S96>/Add2'
         *  Sum: '<S96>/Minus1'
         */
        rtb_Z_idx_0 = rtb_Init_e - rtb_Minus_n[1];

        /* Sum: '<S96>/Minus' incorporates:
         *  Sum: '<S96>/Minus1'
         */
        rtb_Switch2_p -= rtb_Z_idx_0;

        /* DotProduct: '<S96>/Dot Product' incorporates:
         *  Concatenate: '<S77>/Matrix Concatenate2'
         *  Sum: '<S96>/Minus'
         *  Sum: '<S96>/Minus1'
         *  Sum: '<S96>/Minus5'
         */
        rtb_Atan2_i += (rtb_Reshapey[1] - rtb_Z_idx_0) * rtb_Switch2_p;

        /* RelationalOperator: '<S97>/Compare' incorporates:
         *  Constant: '<S97>/Constant'
         */
        rtb_Is_Absolute_Steering = (rtb_Atan2_i >= 0.0);

        /* RelationalOperator: '<S96>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S96>/Dot Product1'
         *  Sum: '<S96>/Minus'
         */
        rtb_OR_ao = (rtb_Atan2_i <= ((rtb_Switch2_p * rtb_Switch2_p) +
          rtb_Add_kz));

        /* DotProduct: '<S96>/Dot Product2' incorporates:
         *  Sum: '<S96>/Minus4'
         *  Sum: '<S96>/Minus5'
         */
        rtb_Atan2_i = (rtb_Z_idx_3 * rtb_Switch2_ef) +
          rtb_MatrixConcatenate_b_idx_0;

        /* Merge: '<S81>/Merge4' incorporates:
         *  Constant: '<S98>/Constant'
         *  DataTypeConversion: '<S88>/Data Type Conversion'
         *  DotProduct: '<S96>/Dot Product3'
         *  Logic: '<S96>/AND'
         *  RelationalOperator: '<S96>/LessThanOrEqual1'
         *  RelationalOperator: '<S98>/Compare'
         *  Sum: '<S88>/Add'
         *  Sum: '<S96>/Minus4'
         */
        Code_Gen_Model_B.Spline_Index = ((real_T)(((rtb_Is_Absolute_Steering &&
          rtb_OR_ao) && (rtb_Atan2_i >= 0.0)) && (rtb_Atan2_i <= ((rtb_Z_idx_3 *
          rtb_Z_idx_3) + rtb_Steer_Joystick_X_Rel_Mod)))) +
          Code_Gen_Model_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S81>/Merge2' incorporates:
         *  Constant: '<S88>/Constant2'
         *  SignalConversion generated from: '<S88>/Robot_Reached_Destination'
         */
        rtb_Is_Absolute_Steering = false;

        /* SignalConversion generated from: '<S88>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S88>/Constant1'
         */
        rtb_OR_ao = false;

        /* End of Outputs for SubSystem: '<S84>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S84>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S85>/Action Port'
         */
        /* Merge: '<S81>/Merge2' incorporates:
         *  Constant: '<S85>/Constant2'
         *  SignalConversion generated from: '<S85>/Robot_Reached_Destination'
         */
        rtb_Is_Absolute_Steering = false;

        /* SignalConversion generated from: '<S85>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S85>/Constant1'
         */
        rtb_OR_ao = false;

        /* Merge: '<S81>/Merge4' incorporates:
         *  SignalConversion generated from: '<S85>/Current_Index'
         */
        Code_Gen_Model_B.Spline_Index = Code_Gen_Model_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S84>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S81>/Merge1' incorporates:
       *  Constant: '<S84>/Constant'
       *  SignalConversion generated from: '<S84>/Out_Of_Bounds'
       */
      Code_Gen_Model_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S84>/Unit Delay' */
      Code_Gen_Model_DW.UnitDelay_DSTATE_e4 = rtb_RelationalOperator;

      /* End of Outputs for SubSystem: '<S81>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S81>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S83>/Action Port'
       */
      /* Merge: '<S81>/Merge1' incorporates:
       *  Constant: '<S83>/Constant'
       *  SignalConversion generated from: '<S83>/Out_Of_Bounds'
       */
      Code_Gen_Model_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S81>/Merge2' incorporates:
       *  Constant: '<S83>/Constant1'
       *  SignalConversion generated from: '<S83>/Robot_Reached_Destination'
       */
      rtb_Is_Absolute_Steering = false;

      /* SignalConversion generated from: '<S83>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S83>/Constant2'
       */
      rtb_OR_ao = false;

      /* Merge: '<S81>/Merge4' incorporates:
       *  SignalConversion generated from: '<S83>/Current_Index'
       */
      Code_Gen_Model_B.Spline_Index = Code_Gen_Model_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S81>/Escape_Auto_Driving' */
    }

    /* End of If: '<S81>/If' */

    /* If: '<S77>/If1' */
    if (!rtb_OR_ao) {
      /* Outputs for IfAction SubSystem: '<S77>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S82>/Action Port'
       */
      /* Bias: '<S99>/Add Constant' incorporates:
       *  Bias: '<S99>/Bias'
       *  Sum: '<S99>/Subtract'
       */
      rtb_Z_idx_0 = ((Code_Gen_Model_B.Spline_Num_Poses -
                      Code_Gen_Model_B.Spline_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S99>/Selector4' incorporates:
       *  Bias: '<S99>/Bias1'
       *  Constant: '<S101>/FixPt Constant'
       *  Sum: '<S101>/FixPt Sum1'
       */
      rtb_Reshapey[0] = Code_Gen_Model_B.Spline_Index - 1.0;
      rtb_Reshapey[1] = Code_Gen_Model_B.Spline_Num_Poses + 2.0;

      /* Selector: '<S99>/Selector4' */
      s104_iter = ((int32_T)rtb_Reshapey[1]) - ((int32_T)rtb_Reshapey[0]);
      Code_Gen_Model_DW.Selector4_DIMS1[0] = s104_iter + 1;
      Code_Gen_Model_DW.Selector4_DIMS1[1] = 2;
      rtb_Bias1_p = (int32_T)rtb_Reshapey[0];

      /* Concatenate: '<S99>/Matrix Concatenate' incorporates:
       *  Bias: '<S99>/Add Constant1'
       *  Gain: '<S102>/Gain'
       *  Gain: '<S103>/Gain'
       *  Selector: '<S77>/Selector1'
       *  Selector: '<S99>/Selector'
       *  Selector: '<S99>/Selector1'
       *  Selector: '<S99>/Selector2'
       *  Selector: '<S99>/Selector3'
       *  Sum: '<S102>/Subtract'
       *  Sum: '<S103>/Subtract'
       */
      rtb_Assignment[0] = (2.0 * rtb_Ref_Poses[0]) - rtb_Ref_Poses[1];
      rtb_Assignment[21] = (2.0 * rtb_Ref_Poses[19]) - rtb_Ref_Poses[20];
      for (i = 0; i < 19; i++) {
        rtb_Assignment[i + 1] = rtb_Ref_Poses[i];
        rtb_Assignment[i + 22] = rtb_Ref_Poses[i + 19];
      }

      for (i = 0; i < 2; i++) {
        rtb_Assignment[(21 * i) + 20] = (rtb_Ref_Poses[((19 * i) + ((int32_T)
          Code_Gen_Model_B.Spline_Num_Poses)) - 1] * 2.0) - rtb_Ref_Poses
          [(((int32_T)(Code_Gen_Model_B.Spline_Num_Poses - 1.0)) + (19 * i)) - 1];

        /* Selector: '<S99>/Selector4' incorporates:
         *  Bias: '<S99>/Add Constant1'
         *  Gain: '<S102>/Gain'
         *  Selector: '<S99>/Selector'
         *  Selector: '<S99>/Selector1'
         *  Sum: '<S102>/Subtract'
         */
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s104_iter;
             rtb_Num_Segments++) {
          rtb_Selector4[rtb_Num_Segments + (Code_Gen_Model_DW.Selector4_DIMS1[0]
            * i)] = rtb_Assignment[((rtb_Num_Segments + rtb_Bias1_p) + (21 * i))
            - 1];
        }
      }

      /* End of Concatenate: '<S99>/Matrix Concatenate' */

      /* Assignment: '<S99>/Assignment' incorporates:
       *  Selector: '<S99>/Selector4'
       */
      memset(&rtb_Assignment[0], 0, 42U * (sizeof(real_T)));
      rtb_Bias1_p = Code_Gen_Model_DW.Selector4_DIMS1[0];
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (s104_iter = 0; s104_iter < rtb_Bias1_p; s104_iter++) {
          rtb_Assignment[s104_iter + i] = rtb_Selector4
            [(Code_Gen_Model_DW.Selector4_DIMS1[0] * rtb_Num_Segments) +
            s104_iter];
        }

        i += 21;
      }

      /* End of Assignment: '<S99>/Assignment' */

      /* Outputs for Iterator SubSystem: '<S100>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S104>/While Iterator'
       */
      s104_iter = 1;
      do {
        rtb_Init_e = rtb_Assignment[s104_iter + 1];
        rtb_Reshapey[0] = rtb_Init_e - rtb_Assignment[s104_iter - 1];
        rtb_Minus_n[0] = rtb_Assignment[s104_iter] - rtb_Assignment[s104_iter +
          2];
        rtb_Add2_f[0] = rtb_Init_e - rtb_Assignment[s104_iter];
        rtb_Init_e = rtb_Assignment[s104_iter + 22];
        rtb_Reshapey[1] = rtb_Init_e - rtb_Assignment[s104_iter + 20];
        rtb_Add_kz = rtb_Assignment[s104_iter + 21];
        rtb_Minus_n[1] = rtb_Add_kz - rtb_Assignment[s104_iter + 23];
        rtb_Add2_f[1] = rtb_Init_e - rtb_Add_kz;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_Atan2_i = ((real_T)rtb_Bias1_p) / 49.0;
          rtb_Init_e = rt_powd_snf(rtb_Atan2_i, 2.0);
          rtb_Switch2_ef = rt_powd_snf(rtb_Atan2_i, 3.0);
          rtb_Z_idx_2 = (rtb_Atan2_i - (2.0 * rtb_Init_e)) + rtb_Switch2_ef;
          rtb_Z_idx_3 = rtb_Init_e - rtb_Switch2_ef;
          rtb_Switch2_ef = (3.0 * rtb_Init_e) - (2.0 * rtb_Switch2_ef);
          rtb_MatrixConcatenate_b_idx_0 = ((((rtb_Reshapey[0] * rtb_Z_idx_2) +
            (rtb_Minus_n[0] * rtb_Z_idx_3)) * 0.5) + (rtb_Add2_f[0] *
            rtb_Switch2_ef)) + rtb_Assignment[s104_iter];
          rtb_Steer_Joystick_X_Rel_Mod = ((((rtb_Reshapey[1] * rtb_Z_idx_2) +
            (rtb_Minus_n[1] * rtb_Z_idx_3)) * 0.5) + (rtb_Add2_f[1] *
            rtb_Switch2_ef)) + rtb_Add_kz;
          rtb_Z_idx_2 = ((3.0 * rtb_Init_e) - (4.0 * rtb_Atan2_i)) + 1.0;
          rtb_Z_idx_3 = (2.0 * rtb_Atan2_i) - (3.0 * rtb_Init_e);
          rtb_Init_e = (rtb_Atan2_i - rtb_Init_e) * 6.0;
          rtb_Switch2_p = (((rtb_Reshapey[0] * rtb_Z_idx_2) + (rtb_Minus_n[0] *
            rtb_Z_idx_3)) * 0.5) + (rtb_Add2_f[0] * rtb_Init_e);
          rtb_Switch2_ef = rtb_Switch2_p;
          rtb_Product[0] = rtb_Switch2_p;
          rtb_Switch2_p = (((rtb_Reshapey[1] * rtb_Z_idx_2) + (rtb_Minus_n[1] *
            rtb_Z_idx_3)) * 0.5) + (rtb_Add2_f[1] * rtb_Init_e);
          rtb_Init_e = (6.0 * rtb_Atan2_i) - 4.0;
          rtb_Z_idx_2 = (-6.0 * rtb_Atan2_i) + 2.0;
          rtb_Atan2_i = (-12.0 * rtb_Atan2_i) + 6.0;
          if ((rtb_Bias1_p + 1) == 1) {
            memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
          }

          rtb_Assignment_d[rtb_Bias1_p] = rtb_MatrixConcatenate_b_idx_0;
          rtb_Assignment_d[rtb_Bias1_p + 50] = rtb_Steer_Joystick_X_Rel_Mod;
          rtb_Assignment_d[rtb_Bias1_p + 100] = fabs((((((rtb_Reshapey[1] *
            rtb_Init_e) + (rtb_Minus_n[1] * rtb_Z_idx_2)) * 0.5) + (rtb_Add2_f[1]
            * rtb_Atan2_i)) * rtb_Product[0]) - (((((rtb_Reshapey[0] *
            rtb_Init_e) + (rtb_Minus_n[0] * rtb_Z_idx_2)) * 0.5) + (rtb_Add2_f[0]
            * rtb_Atan2_i)) * rtb_Switch2_p)) / rt_powd_snf(rt_hypotd_snf
            (rtb_Switch2_ef, rtb_Switch2_p), 3.0);
        }

        if (s104_iter == 1) {
          memset(&Code_Gen_Model_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Code_Gen_Model_B.Assignment[((i * 50) + (s104_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Atan2_i = rtb_Z_idx_0 - ((real_T)s104_iter);
        rtb_Num_Segments = s104_iter;
        s104_iter++;
      } while ((rtb_Atan2_i >= 4.0) && (s104_iter <= 3));

      /* End of Outputs for SubSystem: '<S100>/Sampling_Loop' */

      /* SignalConversion generated from: '<S82>/Position_and_Curvature' incorporates:
       *  Assignment: '<S104>/Assignment'
       *  Merge: '<S77>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Code_Gen_Model_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S77>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S77>/If Action Subsystem' incorporates:
       *  ActionPort: '<S80>/Action Port'
       */
      /* Product: '<S80>/Product' incorporates:
       *  Selector: '<S77>/Selector'
       *  Selector: '<S77>/Selector1'
       */
      rtb_Atan2_i = rtb_Ref_Poses[((int32_T)Code_Gen_Model_B.Spline_Num_Poses) -
        1];

      /* Product: '<S80>/Product1' incorporates:
       *  Selector: '<S77>/Selector'
       *  Selector: '<S77>/Selector1'
       */
      rtb_Z_idx_0 = rtb_Ref_Poses[((int32_T)Code_Gen_Model_B.Spline_Num_Poses) +
        18];
      for (i = 0; i < 50; i++) {
        /* Product: '<S80>/Product' incorporates:
         *  Constant: '<S80>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Atan2_i;

        /* Product: '<S80>/Product1' incorporates:
         *  Constant: '<S80>/Constant2'
         *  Product: '<S80>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Z_idx_0;
      }

      /* Assignment: '<S80>/Assignment' incorporates:
       *  Concatenate: '<S80>/Matrix Concatenate'
       *  Merge: '<S77>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S80>/Assignment' */

      /* SignalConversion generated from: '<S80>/Num_Segments' incorporates:
       *  Constant: '<S80>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S77>/If Action Subsystem' */
    }

    /* End of If: '<S77>/If1' */

    /* Concatenate: '<S78>/Matrix Concatenate' incorporates:
     *  Merge: '<S77>/Merge'
     *  Selector: '<S78>/Selector'
     *  Selector: '<S78>/Selector1'
     *  Selector: '<S78>/Selector3'
     */
    for (i = 0; i < 50; i++) {
      rtb_MatrixConcatenate_o[i] = rtb_Position_and_Curvature[i];
      rtb_MatrixConcatenate_o[i + 50] = rtb_Position_and_Curvature[i + 150];
      rtb_MatrixConcatenate_o[i + 100] = rtb_Position_and_Curvature[i + 300];
      rtb_MatrixConcatenate_o[i + 150] = rtb_Position_and_Curvature[i + 50];
      rtb_MatrixConcatenate_o[i + 200] = rtb_Position_and_Curvature[i + 200];
      rtb_MatrixConcatenate_o[i + 250] = rtb_Position_and_Curvature[i + 350];
      rtb_MatrixConcatenate_o[i + 300] = rtb_Position_and_Curvature[i + 100];
      rtb_MatrixConcatenate_o[i + 350] = rtb_Position_and_Curvature[i + 250];
      rtb_MatrixConcatenate_o[i + 400] = rtb_Position_and_Curvature[i + 400];
    }

    /* End of Concatenate: '<S78>/Matrix Concatenate' */

    /* MATLAB Function: '<S78>/Distance Along Curve' incorporates:
     *  Concatenate: '<S78>/Matrix Concatenate'
     *  Selector: '<S78>/Selector4'
     *  Selector: '<S78>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s104_iter = 0; s104_iter < 149; s104_iter++) {
      /* Outputs for Iterator SubSystem: '<S100>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S104>/While Iterator'
       */
      rtb_Assignment_d[s104_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s104_iter + 1] -
         rtb_MatrixConcatenate_o[s104_iter], rtb_MatrixConcatenate_o[s104_iter +
         151] - rtb_MatrixConcatenate_o[s104_iter + 150]) +
        rtb_Assignment_d[s104_iter];

      /* End of Outputs for SubSystem: '<S100>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S78>/Distance Along Curve' */

    /* MATLAB Function: '<S78>/Find closest index to curve' incorporates:
     *  Concatenate: '<S78>/Matrix Concatenate'
     *  Selector: '<S130>/Selector'
     *  Selector: '<S78>/Selector4'
     *  Selector: '<S78>/Selector5'
     */
    rtb_Atan2_i = Code_Gen_Model_B.Reshapexhat[0];
    rtb_Z_idx_0 = Code_Gen_Model_B.Reshapexhat[1];
    for (s104_iter = 0; s104_iter < 150; s104_iter++) {
      /* Outputs for Iterator SubSystem: '<S100>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S104>/While Iterator'
       */
      distance_from_robot[s104_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s104_iter] - rtb_Atan2_i,
         rtb_MatrixConcatenate_o[s104_iter + 150] - rtb_Z_idx_0);

      /* End of Outputs for SubSystem: '<S100>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s104_iter = 1;
    } else {
      s104_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s104_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s104_iter == 0) {
      rtb_Z_idx_0 = distance_from_robot[0];
    } else {
      rtb_Z_idx_0 = distance_from_robot[s104_iter - 1];
      for (rtb_Bias1_p = s104_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Atan2_i = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Z_idx_0 > rtb_Atan2_i) {
          rtb_Z_idx_0 = rtb_Atan2_i;
        }
      }
    }

    s104_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s104_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Z_idx_0) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S130>/Selector' incorporates:
     *  Constant: '<S130>/Constant'
     *  MATLAB Function: '<S78>/Find closest index to curve'
     *  MinMax: '<S130>/Min'
     */
    rtb_Atan2_i = rtb_Assignment_d[((int32_T)fmin(50.0, s104_iter)) - 1];

    /* If: '<S130>/If' incorporates:
     *  RelationalOperator: '<S130>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S130>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S133>/Action Port'
       */
      /* SignalConversion generated from: '<S133>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S135>/FixPt Sum1' incorporates:
       *  Constant: '<S135>/FixPt Constant'
       */
      rtb_Z_idx_0 = Code_Gen_Model_B.Spline_Index - 1.0;

      /* SignalConversion generated from: '<S133>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S7>/Merge8'
       *  Selector: '<S133>/Selector11'
       *  Selector: '<S133>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses[((int32_T)rtb_Z_idx_0) + 37];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses[((int32_T)
        Code_Gen_Model_B.Spline_Index) + 37];

      /* SignalConversion generated from: '<S133>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S7>/Merge8'
       *  Selector: '<S133>/Selector1'
       *  Selector: '<S133>/Selector2'
       */
      rtb_Add2_f[0] = rtb_Spline_Ref_Poses[((int32_T)rtb_Z_idx_0) + 56];
      rtb_Add2_f[1] = rtb_Spline_Ref_Poses[((int32_T)
        Code_Gen_Model_B.Spline_Index) + 56];

      /* S-Function (sfix_look1_dyn): '<S133>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S133>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Z_idx_0), &rtb_Minus_n[0], rtb_Atan2_i,
                           &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S133>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S133>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S133>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2_f[0], rtb_Atan2_i,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S130>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S130>/Latch' incorporates:
       *  ActionPort: '<S134>/Action Port'
       */
      /* SignalConversion generated from: '<S134>/In1' incorporates:
       *  UnitDelay: '<S130>/Unit Delay1'
       */
      rtb_Z_idx_0 = Code_Gen_Model_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S134>/In2' incorporates:
       *  UnitDelay: '<S130>/Unit Delay'
       */
      rtb_Merge1 = Code_Gen_Model_DW.UnitDelay_DSTATE_g4g;

      /* End of Outputs for SubSystem: '<S130>/Latch' */
    }

    /* End of If: '<S130>/If' */

    /* Outputs for Iterator SubSystem: '<S78>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S129>/While Iterator'
     */
    s129_iter = 1U;
    rtb_RelationalOperator = true;
    while (rtb_RelationalOperator && (s129_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S78>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S129>/While Iterator'
       */
      Code_Gen_Model_B.WhileIterator = s129_iter;
      rtb_RelationalOperator = ((rtb_Assignment_d[Code_Gen_Model_B.WhileIterator
        - 1] <= (rtb_Assignment_d[s104_iter - 1] + Spline_Lookahead_Dist)) &&
        (Code_Gen_Model_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s129_iter++;
    }

    /* End of Outputs for SubSystem: '<S78>/Find first index that meets distance target' */

    /* Logic: '<S79>/OR' incorporates:
     *  Constant: '<S129>/Constant'
     *  Constant: '<S78>/Lookahead Distance'
     *  Logic: '<S129>/AND'
     *  MATLAB Function: '<S78>/Find closest index to curve'
     *  Product: '<S129>/Product'
     *  RelationalOperator: '<S129>/Relational Operator'
     *  RelationalOperator: '<S129>/Relational Operator1'
     *  Selector: '<S129>/Selector'
     *  Selector: '<S129>/Selector1'
     *  Selector: '<S130>/Selector'
     *  Sum: '<S129>/Add'
     */
    rtb_OR_ao = (rtb_Is_Absolute_Steering ||
                 (Code_Gen_Model_B.Spline_Out_Of_Bounds));

    /* Switch: '<S79>/Switch1' incorporates:
     *  Constant: '<S78>/Constant'
     *  RelationalOperator: '<S78>/Relational Operator'
     *  Sum: '<S78>/Subtract'
     *  Switch: '<S132>/Switch'
     *  Switch: '<S79>/Switch'
     *  UnitDelay: '<S79>/Unit Delay'
     */
    if (rtb_OR_ao) {
      /* Merge: '<S9>/Merge2' incorporates:
       *  Constant: '<S79>/Constant3'
       */
      Code_Gen_Model_B.Translation_Speed_SPF = 0.0;
      rtb_Atan2_i = Code_Gen_Model_DW.UnitDelay_DSTATE_le;
    } else {
      if (Code_Gen_Model_B.Spline_Index >= (Code_Gen_Model_B.Spline_Num_Poses -
           Spline_Pose_Num_Before_End_Reduce_Speed)) {
        /* Merge: '<S9>/Merge2' incorporates:
         *  Concatenate: '<S78>/Matrix Concatenate'
         *  Constant: '<S132>/Constant1'
         *  Constant: '<S132>/Constant2'
         *  Constant: '<S132>/Constant3'
         *  Math: '<S132>/Hypot'
         *  Merge: '<S7>/Merge8'
         *  MinMax: '<S132>/Min'
         *  MinMax: '<S132>/Min1'
         *  Product: '<S132>/Divide'
         *  Product: '<S132>/Product'
         *  Product: '<S132>/Product1'
         *  Selector: '<S78>/Selector10'
         *  Selector: '<S78>/Selector7'
         *  Selector: '<S78>/Selector8'
         *  Selector: '<S78>/Selector9'
         *  Sqrt: '<S132>/Sqrt'
         *  Sum: '<S132>/Subtract'
         *  Sum: '<S132>/Subtract1'
         *  Switch: '<S132>/Switch'
         */
        Code_Gen_Model_B.Translation_Speed_SPF = fmin(rt_hypotd_snf
          (rtb_Spline_Ref_Poses[18] - Code_Gen_Model_B.Reshapexhat[0],
           rtb_Spline_Ref_Poses[37] - Code_Gen_Model_B.Reshapexhat[1]) *
          Spline_Last_Pose_Distance_to_Velocity_Gain, fmin(rtb_Z_idx_0 *
          Spline_Velocity_Multiplier_TEST, sqrt
          (Spline_Max_Centripital_Acceleration /
           rtb_MatrixConcatenate_o[Code_Gen_Model_B.WhileIterator + 299])));
      } else {
        /* Merge: '<S9>/Merge2' incorporates:
         *  Concatenate: '<S78>/Matrix Concatenate'
         *  Constant: '<S132>/Constant1'
         *  Constant: '<S132>/Constant3'
         *  MinMax: '<S132>/Min1'
         *  Product: '<S132>/Divide'
         *  Product: '<S132>/Product1'
         *  Selector: '<S78>/Selector10'
         *  Selector: '<S78>/Selector7'
         *  Sqrt: '<S132>/Sqrt'
         *  Switch: '<S132>/Switch'
         */
        Code_Gen_Model_B.Translation_Speed_SPF = fmin(rtb_Z_idx_0 *
          Spline_Velocity_Multiplier_TEST, sqrt
          (Spline_Max_Centripital_Acceleration /
           rtb_MatrixConcatenate_o[Code_Gen_Model_B.WhileIterator + 299]));
      }

      rtb_Atan2_i = rtb_Merge1;
    }

    /* End of Switch: '<S79>/Switch1' */

    /* Merge: '<S9>/Merge' incorporates:
     *  SignalConversion: '<S79>/Signal Copy'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd_SPF = rtb_Atan2_i;

    /* Selector: '<S78>/Selector6' incorporates:
     *  Concatenate: '<S78>/Matrix Concatenate'
     *  Selector: '<S78>/Selector5'
     */
    Code_Gen_Model_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Code_Gen_Model_B.WhileIterator + 149];

    /* Selector: '<S78>/Selector2' incorporates:
     *  Concatenate: '<S78>/Matrix Concatenate'
     *  Selector: '<S78>/Selector4'
     */
    Code_Gen_Model_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Code_Gen_Model_B.WhileIterator - 1];

    /* Switch: '<S79>/Switch2' incorporates:
     *  Sum: '<S136>/Subtract'
     *  Sum: '<S136>/Subtract1'
     *  Trigonometry: '<S136>/Atan2'
     *  UnitDelay: '<S79>/Unit Delay1'
     */
    if (rtb_OR_ao) {
      rtb_Init_e = Code_Gen_Model_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_Init_e = rt_atan2d_snf(Code_Gen_Model_B.Spline_Target_Y -
        Code_Gen_Model_B.Reshapexhat[1], Code_Gen_Model_B.Spline_Target_X -
        Code_Gen_Model_B.Reshapexhat[0]);
    }

    /* End of Switch: '<S79>/Switch2' */

    /* Merge: '<S9>/Merge3' incorporates:
     *  SignalConversion: '<S79>/Signal Copy2'
     */
    Code_Gen_Model_B.Translation_Angle_SPF = rtb_Init_e;

    /* Merge: '<S9>/Merge7' incorporates:
     *  SignalConversion: '<S76>/Signal Copy'
     */
    Code_Gen_Model_B.Robot_Reached_Destination = rtb_Is_Absolute_Steering;

    /* Merge: '<S9>/Merge1' incorporates:
     *  Constant: '<S79>/Constant2'
     *  SignalConversion generated from: '<S76>/Steering_Rel_Cmd'
     */
    Code_Gen_Model_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S9>/Merge4' incorporates:
     *  Constant: '<S79>/Constant5'
     *  SignalConversion generated from: '<S76>/Is_Absolute_Translation'
     */
    Code_Gen_Model_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S9>/Merge5' incorporates:
     *  Constant: '<S79>/Constant6'
     *  SignalConversion generated from: '<S76>/Is_Absolute_Steering'
     */
    Code_Gen_Model_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S9>/Merge6' incorporates:
     *  Constant: '<S79>/Constant1'
     *  SignalConversion generated from: '<S76>/Gyro_Angle_Adjustment'
     */
    Code_Gen_Model_B.Gyro_Angle_Adjustment_SPF = 0.0;

    /* Update for UnitDelay: '<S77>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_gh = Code_Gen_Model_B.Spline_Index;

    /* Update for UnitDelay: '<S130>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_f4 = rtb_Z_idx_0;

    /* Update for UnitDelay: '<S130>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_g4g = rtb_Merge1;

    /* Update for UnitDelay: '<S79>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_le = rtb_Atan2_i;

    /* Update for UnitDelay: '<S79>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_kc = rtb_Init_e;

    /* End of Outputs for SubSystem: '<S9>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S9>/Pass Through' incorporates:
     *  ActionPort: '<S75>/Action Port'
     */
    /* Merge: '<S9>/Merge7' incorporates:
     *  Constant: '<S75>/Constant'
     *  SignalConversion generated from: '<S75>/Robot_Reached_Destination'
     */
    Code_Gen_Model_B.Robot_Reached_Destination = false;

    /* Merge: '<S9>/Merge' incorporates:
     *  SignalConversion generated from: '<S75>/Steering_Abs_Cmd_In'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd_SPF = Code_Gen_Model_B.Steering_Abs_Cmd;

    /* Merge: '<S9>/Merge1' incorporates:
     *  SignalConversion generated from: '<S75>/Steering_Rel_Cmd_In'
     */
    Code_Gen_Model_B.Steering_Rel_Cmd_SPF = Code_Gen_Model_B.Steering_Rel_Cmd;

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion generated from: '<S75>/Translation_Speed_In'
     */
    Code_Gen_Model_B.Translation_Speed_SPF = Code_Gen_Model_B.Translation_Speed;

    /* Merge: '<S9>/Merge3' incorporates:
     *  SignalConversion generated from: '<S75>/Translation_Angle_In'
     */
    Code_Gen_Model_B.Translation_Angle_SPF = Code_Gen_Model_B.Translation_Angle;

    /* Merge: '<S9>/Merge4' incorporates:
     *  SignalConversion generated from: '<S75>/Is_Absolute_Translation_In'
     */
    Code_Gen_Model_B.Is_Absolute_Translation_SPF = rtb_RelationalOperator;

    /* Merge: '<S9>/Merge5' incorporates:
     *  SignalConversion generated from: '<S75>/Is_Absolute_Steering_In'
     */
    Code_Gen_Model_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S9>/Merge6' incorporates:
     *  SignalConversion generated from: '<S75>/Gyro_Angle_Adjustment_In'
     */
    Code_Gen_Model_B.Gyro_Angle_Adjustment_SPF = rtb_Z_idx_0;

    /* End of Outputs for SubSystem: '<S9>/Pass Through' */
  }

  /* End of If: '<S9>/If' */

  /* Signum: '<S230>/Sign2' incorporates:
   *  UnitDelay: '<S230>/Unit Delay'
   */
  if (rtIsNaN(Code_Gen_Model_B.Translation_Speed_RL)) {
    rtb_Add_kz = (rtNaN);
  } else if (Code_Gen_Model_B.Translation_Speed_RL < 0.0) {
    rtb_Add_kz = -1.0;
  } else {
    rtb_Add_kz = (Code_Gen_Model_B.Translation_Speed_RL > 0.0);
  }

  /* Signum: '<S230>/Sign1' */
  if (rtIsNaN(Code_Gen_Model_B.Translation_Speed_SPF)) {
    rtb_Add_cz = (rtNaN);
  } else if (Code_Gen_Model_B.Translation_Speed_SPF < 0.0) {
    rtb_Add_cz = -1.0;
  } else {
    rtb_Add_cz = (Code_Gen_Model_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S230>/Product1' incorporates:
   *  Signum: '<S230>/Sign1'
   *  Signum: '<S230>/Sign2'
   */
  rtb_Add_kz *= rtb_Add_cz;
  if (rtIsNaN(rtb_Add_kz)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_kz, 256.0);
  }

  /* Switch: '<S230>/Switch' incorporates:
   *  Constant: '<S230>/Constant'
   *  Constant: '<S235>/Constant'
   *  Constant: '<S236>/Constant'
   *  Logic: '<S230>/or'
   *  Product: '<S230>/Product1'
   *  RelationalOperator: '<S235>/Compare'
   *  RelationalOperator: '<S236>/Compare'
   *  UnitDelay: '<S230>/Unit Delay'
   */
  if ((Code_Gen_Model_B.Translation_Speed_RL == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_p = Code_Gen_Model_B.Translation_Speed_SPF;
  } else {
    rtb_Switch2_p = 0.0;
  }

  /* End of Switch: '<S230>/Switch' */

  /* Switch: '<S241>/Init' incorporates:
   *  UnitDelay: '<S241>/FixPt Unit Delay1'
   *  UnitDelay: '<S241>/FixPt Unit Delay2'
   */
  if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p;
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Code_Gen_Model_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S241>/Init' */

  /* RelationalOperator: '<S237>/Compare' incorporates:
   *  Constant: '<S237>/Constant'
   */
  rtb_RelationalOperator = (rtb_Switch2_p == 0.0);

  /* RelationalOperator: '<S238>/Compare' incorporates:
   *  Constant: '<S238>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Switch2_p > 0.0);

  /* Abs: '<S230>/Abs' incorporates:
   *  Sum: '<S230>/Subtract'
   *  UnitDelay: '<S230>/Unit Delay'
   */
  rtb_Merge1 = fabs(Code_Gen_Model_B.Translation_Speed_RL -
                    Code_Gen_Model_B.Translation_Speed_SPF);

  /* Switch: '<S230>/Switch5' incorporates:
   *  Switch: '<S230>/Switch1'
   */
  if (rtb_RelationalOperator) {
    /* SignalConversion generated from: '<S230>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S230>/Constant4'
     *  Constant: '<S230>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S230>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S230>/Constant2'
     *  Constant: '<S230>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S230>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S230>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_j), &rtb_Reshapey[0],
                         rtb_Merge1, &rtb_Minus_n[0], 1U);
    rtb_Merge1 = rtb_LookupTableDynamic_j;
    rtb_Add_kz = Code_Gen_Model_ConstB.UnaryMinus;
  } else {
    /* SignalConversion generated from: '<S230>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S230>/Constant10'
     *  Constant: '<S230>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S230>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S230>/Constant7'
     *  Constant: '<S230>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S230>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S230>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_i), &rtb_Reshapey[0],
                         rtb_Merge1, &rtb_Minus_n[0], 1U);
    rtb_Merge1 = rtb_LookupTableDynamic1_i;

    /* Switch: '<S230>/Switch3' incorporates:
     *  Constant: '<S230>/Constant3'
     */
    if (rtb_Is_Absolute_Steering) {
      rtb_Add_kz = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_kz = Code_Gen_Model_ConstB.UnaryMinus;
    }

    /* End of Switch: '<S230>/Switch3' */
  }

  /* End of Switch: '<S230>/Switch5' */

  /* Product: '<S230>/Product' incorporates:
   *  Switch: '<S230>/Switch1'
   */
  rtb_uDLookupTable_l = rtb_Add_kz * rtb_Merge1;

  /* Sum: '<S239>/Sum1' */
  rtb_Z_idx_0 = rtb_Switch2_p - rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S240>/Switch2' incorporates:
   *  RelationalOperator: '<S240>/LowerRelop1'
   */
  if (!(rtb_Z_idx_0 > rtb_uDLookupTable_l)) {
    /* Switch: '<S230>/Switch2' incorporates:
     *  Constant: '<S230>/Constant1'
     *  Switch: '<S230>/Switch4'
     */
    if (rtb_RelationalOperator) {
      rtb_Atan2_i = -0.2;
    } else if (rtb_Is_Absolute_Steering) {
      /* Switch: '<S230>/Switch4' incorporates:
       *  Constant: '<S230>/Constant1'
       */
      rtb_Atan2_i = -0.2;
    } else {
      /* Switch: '<S230>/Switch4' incorporates:
       *  Constant: '<S230>/Constant3'
       *  UnaryMinus: '<S230>/Unary Minus1'
       */
      rtb_Atan2_i = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S230>/Switch2' */

    /* Product: '<S230>/Product2' */
    rtb_Atan2_i *= rtb_Merge1;

    /* Switch: '<S240>/Switch' incorporates:
     *  RelationalOperator: '<S240>/UpperRelop'
     */
    if (rtb_Z_idx_0 < rtb_Atan2_i) {
      rtb_uDLookupTable_l = rtb_Atan2_i;
    } else {
      rtb_uDLookupTable_l = rtb_Z_idx_0;
    }

    /* End of Switch: '<S240>/Switch' */
  }

  /* End of Switch: '<S240>/Switch2' */

  /* Sum: '<S239>/Sum' */
  Code_Gen_Model_B.Translation_Speed_RL = rtb_uDLookupTable_l +
    rtb_MatrixConcatenate_b_idx_0;

  /* Switch: '<S233>/Switch' */
  if (Code_Gen_Model_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S233>/Switch' incorporates:
     *  Constant: '<S257>/Constant3'
     *  Constant: '<S257>/Constant4'
     *  Math: '<S257>/Math Function'
     *  Sum: '<S233>/Subtract'
     *  Sum: '<S257>/Add1'
     *  Sum: '<S257>/Add2'
     */
    Code_Gen_Model_B.Translation_Steering_Cmd = rt_modd_snf
      ((Code_Gen_Model_B.Translation_Angle_SPF - rtb_thetay) +
       3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S233>/Switch' */
    Code_Gen_Model_B.Translation_Steering_Cmd =
      Code_Gen_Model_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S233>/Switch' */

  /* Sum: '<S253>/Add1' incorporates:
   *  Constant: '<S253>/Constant3'
   *  Constant: '<S253>/Constant4'
   *  Math: '<S253>/Math Function'
   *  Sum: '<S232>/Add'
   *  Sum: '<S252>/Sum'
   *  Sum: '<S253>/Add2'
   */
  rtb_MatrixConcatenate_b_idx_0 = rt_modd_snf
    ((Code_Gen_Model_B.Steering_Abs_Cmd_SPF - (rtb_thetay +
       Code_Gen_Model_B.Gyro_Angle_Adjustment_SPF)) + 3.1415926535897931,
     6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S255>/Sum1' incorporates:
   *  Constant: '<S252>/Constant2'
   *  Product: '<S255>/Product'
   *  Sum: '<S255>/Sum'
   *  UnitDelay: '<S255>/Unit Delay1'
   */
  rtb_Merge1 = ((rtb_MatrixConcatenate_b_idx_0 -
                 Code_Gen_Model_DW.UnitDelay1_DSTATE) *
                Steering_Heading_Control_D_FilterCoeff) +
    Code_Gen_Model_DW.UnitDelay1_DSTATE;

  /* Product: '<S252>/Product' incorporates:
   *  Constant: '<S252>/Constant3'
   */
  rtb_Z_idx_0 = rtb_Merge1 * Steering_Heading_Control_D;

  /* Sum: '<S254>/Diff' incorporates:
   *  UnitDelay: '<S254>/UD'
   *
   * Block description for '<S254>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S254>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Z_idx_0 - Code_Gen_Model_DW.UD_DSTATE_a;

  /* Saturate: '<S252>/Saturation' */
  if (rtb_Add_ec > Steering_Heading_Control_D_UL) {
    rtb_Add_ec = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_ec < Steering_Heading_Control_D_LL) {
    rtb_Add_ec = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S252>/Add' incorporates:
   *  Gain: '<S252>/Gain1'
   *  Saturate: '<S252>/Saturation'
   */
  rtb_Init_e = (Steering_Heading_Control_P * rtb_MatrixConcatenate_b_idx_0) +
    rtb_Add_ec;

  /* Sum: '<S252>/Subtract' incorporates:
   *  Constant: '<S252>/Constant'
   */
  rtb_uDLookupTable_l = Steering_Heading_Control_Total_UL - rtb_Init_e;

  /* Sum: '<S252>/Sum2' incorporates:
   *  Gain: '<S252>/Gain2'
   *  UnitDelay: '<S252>/Unit Delay'
   */
  rtb_Atan2_i = (Steering_Heading_Control_I * rtb_MatrixConcatenate_b_idx_0) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S256>/Switch2' incorporates:
   *  RelationalOperator: '<S256>/LowerRelop1'
   */
  if (!(rtb_Atan2_i > rtb_uDLookupTable_l)) {
    /* Sum: '<S252>/Subtract1' incorporates:
     *  Constant: '<S252>/Constant1'
     */
    rtb_Z_idx_2 = Steering_Heading_Control_Total_LL - rtb_Init_e;

    /* Switch: '<S256>/Switch' incorporates:
     *  RelationalOperator: '<S256>/UpperRelop'
     */
    if (rtb_Atan2_i < rtb_Z_idx_2) {
      rtb_uDLookupTable_l = rtb_Z_idx_2;
    } else {
      rtb_uDLookupTable_l = rtb_Atan2_i;
    }

    /* End of Switch: '<S256>/Switch' */
  }

  /* End of Switch: '<S256>/Switch2' */

  /* Saturate: '<S252>/Saturation1' */
  if (rtb_uDLookupTable_l > Steering_Heading_Control_I_UL) {
    rtb_Atan2_i = Steering_Heading_Control_I_UL;
  } else if (rtb_uDLookupTable_l < Steering_Heading_Control_I_LL) {
    rtb_Atan2_i = Steering_Heading_Control_I_LL;
  } else {
    rtb_Atan2_i = rtb_uDLookupTable_l;
  }

  /* End of Saturate: '<S252>/Saturation1' */

  /* Sum: '<S252>/Add1' */
  rtb_Add_ec = rtb_Init_e + rtb_Atan2_i;

  /* Saturate: '<S252>/Saturation2' */
  if (rtb_Add_ec > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S252>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_ec < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S252>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S252>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = rtb_Add_ec;
  }

  /* End of Saturate: '<S252>/Saturation2' */

  /* Switch: '<S232>/Switch' */
  if (Code_Gen_Model_B.Is_Absolute_Steering_SPF) {
    /* Switch: '<S243>/Switch' incorporates:
     *  Abs: '<S243>/Abs'
     *  Constant: '<S243>/Constant'
     *  Constant: '<S251>/Constant'
     *  RelationalOperator: '<S251>/Compare'
     */
    if (fabs(Code_Gen_Model_B.Steering_Localized_PID) >
        Steering_Heading_Control_Deadzone) {
      rtb_MatrixConcatenate_b_idx_0 = Code_Gen_Model_B.Steering_Localized_PID;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = 0.0;
    }

    /* End of Switch: '<S243>/Switch' */
  } else {
    rtb_MatrixConcatenate_b_idx_0 = Code_Gen_Model_B.Steering_Rel_Cmd_SPF;
  }

  /* End of Switch: '<S232>/Switch' */

  /* Signum: '<S242>/Sign2' incorporates:
   *  UnitDelay: '<S242>/Unit Delay'
   */
  if (rtIsNaN(Code_Gen_Model_B.Steering_Localized_Cmd)) {
    rtb_Add_kz = (rtNaN);
  } else if (Code_Gen_Model_B.Steering_Localized_Cmd < 0.0) {
    rtb_Add_kz = -1.0;
  } else {
    rtb_Add_kz = (Code_Gen_Model_B.Steering_Localized_Cmd > 0.0);
  }

  /* Signum: '<S242>/Sign1' */
  if (rtIsNaN(rtb_MatrixConcatenate_b_idx_0)) {
    rtb_Add_cz = (rtNaN);
  } else if (rtb_MatrixConcatenate_b_idx_0 < 0.0) {
    rtb_Add_cz = -1.0;
  } else {
    rtb_Add_cz = (rtb_MatrixConcatenate_b_idx_0 > 0.0);
  }

  /* Product: '<S242>/Product1' incorporates:
   *  Signum: '<S242>/Sign1'
   *  Signum: '<S242>/Sign2'
   */
  rtb_Add_kz *= rtb_Add_cz;
  if (rtIsNaN(rtb_Add_kz)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_kz, 256.0);
  }

  /* Switch: '<S242>/Switch' incorporates:
   *  Constant: '<S242>/Constant'
   *  Constant: '<S244>/Constant'
   *  Constant: '<S245>/Constant'
   *  Logic: '<S242>/or'
   *  Product: '<S242>/Product1'
   *  RelationalOperator: '<S244>/Compare'
   *  RelationalOperator: '<S245>/Compare'
   *  UnitDelay: '<S242>/Unit Delay'
   */
  if ((Code_Gen_Model_B.Steering_Localized_Cmd == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Z_idx_3 = rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Z_idx_3 = 0.0;
  }

  /* End of Switch: '<S242>/Switch' */

  /* Switch: '<S250>/Init' incorporates:
   *  UnitDelay: '<S250>/FixPt Unit Delay1'
   *  UnitDelay: '<S250>/FixPt Unit Delay2'
   */
  if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Init_e = rtb_Z_idx_3;
  } else {
    rtb_Init_e = Code_Gen_Model_B.Steering_Localized_Cmd;
  }

  /* End of Switch: '<S250>/Init' */

  /* RelationalOperator: '<S246>/Compare' incorporates:
   *  Constant: '<S246>/Constant'
   */
  rtb_RelationalOperator = (rtb_Z_idx_3 == 0.0);

  /* RelationalOperator: '<S247>/Compare' incorporates:
   *  Constant: '<S247>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Z_idx_3 > 0.0);

  /* Abs: '<S242>/Abs' incorporates:
   *  Sum: '<S242>/Subtract'
   *  UnitDelay: '<S242>/Unit Delay'
   */
  rtb_Switch2_ef = fabs(Code_Gen_Model_B.Steering_Localized_Cmd -
                        rtb_MatrixConcatenate_b_idx_0);

  /* Switch: '<S242>/Switch5' incorporates:
   *  Constant: '<S242>/Constant1'
   *  Switch: '<S242>/Switch1'
   *  UnaryMinus: '<S242>/Unary Minus'
   */
  if (rtb_RelationalOperator) {
    /* SignalConversion generated from: '<S242>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S242>/Constant4'
     *  Constant: '<S242>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Localized_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S242>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S242>/Constant2'
     *  Constant: '<S242>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Localized_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S242>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S242>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic), &rtb_Reshapey[0],
                         rtb_Switch2_ef, &rtb_Minus_n[0], 1U);
    rtb_Switch2_ef = rtb_LookupTableDynamic;
    rtb_Add_kz = -Steering_Localized_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S242>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S242>/Constant10'
     *  Constant: '<S242>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Localized_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S242>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S242>/Constant7'
     *  Constant: '<S242>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Localized_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S242>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S242>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1), &rtb_Reshapey[0],
                         rtb_Switch2_ef, &rtb_Minus_n[0], 1U);
    rtb_Switch2_ef = rtb_LookupTableDynamic1;

    /* Switch: '<S242>/Switch3' incorporates:
     *  Constant: '<S242>/Constant1'
     *  Constant: '<S242>/Constant3'
     *  UnaryMinus: '<S242>/Unary Minus'
     */
    if (rtb_Is_Absolute_Steering) {
      rtb_Add_kz = Steering_Localized_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_kz = -Steering_Localized_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S242>/Switch3' */
  }

  /* End of Switch: '<S242>/Switch5' */

  /* Product: '<S242>/Product' incorporates:
   *  Switch: '<S242>/Switch1'
   */
  rtb_Z_idx_2 = rtb_Add_kz * rtb_Switch2_ef;

  /* Sum: '<S248>/Sum1' */
  rtb_Z_idx_3 -= rtb_Init_e;

  /* Switch: '<S249>/Switch2' incorporates:
   *  RelationalOperator: '<S249>/LowerRelop1'
   */
  if (!(rtb_Z_idx_3 > rtb_Z_idx_2)) {
    /* Switch: '<S242>/Switch2' incorporates:
     *  Constant: '<S242>/Constant1'
     *  Constant: '<S242>/Constant3'
     *  Switch: '<S242>/Switch4'
     *  UnaryMinus: '<S242>/Unary Minus1'
     */
    if (rtb_RelationalOperator) {
      rtb_Add_kz = Steering_Localized_Cmd_Rate_Limit_Dec;
    } else if (rtb_Is_Absolute_Steering) {
      /* Switch: '<S242>/Switch4' incorporates:
       *  Constant: '<S242>/Constant1'
       */
      rtb_Add_kz = Steering_Localized_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_kz = -Steering_Localized_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S242>/Product2' incorporates:
     *  Switch: '<S242>/Switch2'
     */
    rtb_Z_idx_2 = rtb_Add_kz * rtb_Switch2_ef;

    /* Switch: '<S249>/Switch' incorporates:
     *  RelationalOperator: '<S249>/UpperRelop'
     */
    if (!(rtb_Z_idx_3 < rtb_Z_idx_2)) {
      rtb_Z_idx_2 = rtb_Z_idx_3;
    }

    /* End of Switch: '<S249>/Switch' */
  }

  /* End of Switch: '<S249>/Switch2' */

  /* Sum: '<S248>/Sum' */
  Code_Gen_Model_B.Steering_Localized_Cmd = rtb_Z_idx_2 + rtb_Init_e;

  /* Fcn: '<S265>/r->x' incorporates:
   *  Fcn: '<S270>/r->x'
   *  Fcn: '<S275>/r->x'
   *  Fcn: '<S280>/r->x'
   */
  rtb_Init_e = Code_Gen_Model_B.Translation_Speed_RL * cos
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S259>/Add' incorporates:
   *  Fcn: '<S265>/r->x'
   *  Fcn: '<S266>/r->x'
   */
  rtb_Reshapey[0] = (Code_Gen_Model_B.Steering_Localized_Cmd * cos
                     (Code_Gen_Model_ConstB.FL_Tangent_Angle)) + rtb_Init_e;

  /* Fcn: '<S265>/theta->y' incorporates:
   *  Fcn: '<S270>/theta->y'
   *  Fcn: '<S275>/theta->y'
   *  Fcn: '<S280>/theta->y'
   */
  rtb_Z_idx_2 = Code_Gen_Model_B.Translation_Speed_RL * sin
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S259>/Add' incorporates:
   *  Fcn: '<S265>/theta->y'
   *  Fcn: '<S266>/theta->y'
   */
  rtb_Reshapey[1] = (Code_Gen_Model_B.Steering_Localized_Cmd * sin
                     (Code_Gen_Model_ConstB.FL_Tangent_Angle)) + rtb_Z_idx_2;

  /* Sum: '<S260>/Add' incorporates:
   *  Fcn: '<S271>/r->x'
   *  Fcn: '<S271>/theta->y'
   */
  rtb_Minus_n[0] = (Code_Gen_Model_B.Steering_Localized_Cmd * cos
                    (Code_Gen_Model_ConstB.FR_Tangent_Angle)) + rtb_Init_e;
  rtb_Minus_n[1] = (Code_Gen_Model_B.Steering_Localized_Cmd * sin
                    (Code_Gen_Model_ConstB.FR_Tangent_Angle)) + rtb_Z_idx_2;

  /* Sum: '<S261>/Add' incorporates:
   *  Fcn: '<S276>/r->x'
   *  Fcn: '<S276>/theta->y'
   */
  rtb_Add2_f[0] = (Code_Gen_Model_B.Steering_Localized_Cmd * cos
                   (Code_Gen_Model_ConstB.BL_Tangent_Angle)) + rtb_Init_e;
  rtb_Add2_f[1] = (Code_Gen_Model_B.Steering_Localized_Cmd * sin
                   (Code_Gen_Model_ConstB.BL_Tangent_Angle)) + rtb_Z_idx_2;

  /* Sum: '<S262>/Add' incorporates:
   *  Fcn: '<S281>/r->x'
   *  Fcn: '<S281>/theta->y'
   */
  rtb_Switch2_ef = (Code_Gen_Model_B.Steering_Localized_Cmd * cos
                    (Code_Gen_Model_ConstB.BR_Tangent_Angle)) + rtb_Init_e;
  rtb_Z_idx_2 += Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.BR_Tangent_Angle);

  /* Fcn: '<S279>/x->r' */
  rtb_Init_e = rt_hypotd_snf(rtb_Switch2_ef, rtb_Z_idx_2);

  /* RelationalOperator: '<S282>/Compare' incorporates:
   *  Constant: '<S282>/Constant'
   */
  rtb_RelationalOperator = (rtb_Init_e == 0.0);

  /* Switch: '<S278>/Switch1' */
  if (rtb_RelationalOperator) {
    /* Switch: '<S278>/Switch1' incorporates:
     *  Constant: '<S278>/Constant'
     */
    Code_Gen_Model_B.Switch1 = 1.0E-15;
  } else {
    /* Switch: '<S278>/Switch1' */
    Code_Gen_Model_B.Switch1 = rtb_Init_e;
  }

  /* End of Switch: '<S278>/Switch1' */

  /* Fcn: '<S264>/x->r' */
  rtb_Init_e = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S267>/Compare' incorporates:
   *  Constant: '<S267>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Init_e == 0.0);

  /* Switch: '<S263>/Switch1' */
  if (rtb_Is_Absolute_Steering) {
    /* Switch: '<S263>/Switch1' incorporates:
     *  Constant: '<S263>/Constant'
     */
    Code_Gen_Model_B.Switch1_m = 1.0E-15;
  } else {
    /* Switch: '<S263>/Switch1' */
    Code_Gen_Model_B.Switch1_m = rtb_Init_e;
  }

  /* End of Switch: '<S263>/Switch1' */

  /* Fcn: '<S269>/x->r' */
  rtb_Switch2_p = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S272>/Compare' incorporates:
   *  Constant: '<S272>/Constant'
   */
  rtb_OR_ao = (rtb_Switch2_p == 0.0);

  /* Switch: '<S268>/Switch1' */
  if (rtb_OR_ao) {
    /* Switch: '<S268>/Switch1' incorporates:
     *  Constant: '<S268>/Constant'
     */
    Code_Gen_Model_B.Switch1_o = 1.0E-15;
  } else {
    /* Switch: '<S268>/Switch1' */
    Code_Gen_Model_B.Switch1_o = rtb_Switch2_p;
  }

  /* End of Switch: '<S268>/Switch1' */

  /* Fcn: '<S274>/x->r' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Add2_f[0], rtb_Add2_f[1]);

  /* RelationalOperator: '<S277>/Compare' incorporates:
   *  Constant: '<S277>/Constant'
   */
  rtb_Switch_b1 = (rtb_MatrixConcatenate_b_idx_0 == 0.0);

  /* Switch: '<S273>/Switch1' */
  if (rtb_Switch_b1) {
    /* Switch: '<S273>/Switch1' incorporates:
     *  Constant: '<S273>/Constant'
     */
    Code_Gen_Model_B.Switch1_p = 1.0E-15;
  } else {
    /* Switch: '<S273>/Switch1' */
    Code_Gen_Model_B.Switch1_p = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Switch: '<S273>/Switch1' */

  /* Product: '<S258>/Divide' incorporates:
   *  Abs: '<S258>/Abs'
   *  Abs: '<S258>/Abs1'
   *  Abs: '<S258>/Abs2'
   *  Abs: '<S258>/Abs3'
   *  Constant: '<S258>/Constant'
   *  MinMax: '<S258>/Max'
   */
  rtb_Init_e = 3.5944420196850411 / fmax(fmax(fmax(fmax(3.5944420196850411,
    Code_Gen_Model_B.Switch1_m), Code_Gen_Model_B.Switch1_o),
    Code_Gen_Model_B.Switch1_p), Code_Gen_Model_B.Switch1);

  /* Product: '<S258>/Product3' */
  Code_Gen_Model_B.BR_Desired_Wheel_Speed = Code_Gen_Model_B.Switch1 *
    rtb_Init_e;

  /* Switch: '<S278>/Switch' */
  if (!rtb_RelationalOperator) {
    /* Switch: '<S278>/Switch' incorporates:
     *  Fcn: '<S279>/x->theta'
     */
    Code_Gen_Model_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Z_idx_2,
      rtb_Switch2_ef);
  }

  /* End of Switch: '<S278>/Switch' */

  /* Trigonometry: '<S222>/Cos4' incorporates:
   *  Switch: '<S211>/Angle_Switch'
   *  Trigonometry: '<S221>/Cos4'
   */
  rtb_Add_kl = cos(Code_Gen_Model_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S222>/Sin5' incorporates:
   *  UnaryMinus: '<S220>/Unary Minus'
   */
  rtb_uDLookupTable_l = sin(-Code_Gen_Model_B.BR_Steer_Module_Angle);

  /* Trigonometry: '<S222>/Sin4' incorporates:
   *  Switch: '<S211>/Angle_Switch'
   *  Trigonometry: '<S221>/Sin4'
   */
  rtb_Subtract_gn = sin(Code_Gen_Model_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S222>/Cos5' incorporates:
   *  UnaryMinus: '<S220>/Unary Minus'
   */
  rtb_MatrixConcatenate_b_idx_0 = cos(-Code_Gen_Model_B.BR_Steer_Module_Angle);

  /* Sum: '<S222>/Subtract1' incorporates:
   *  Product: '<S222>/Product2'
   *  Product: '<S222>/Product3'
   *  Trigonometry: '<S222>/Cos4'
   *  Trigonometry: '<S222>/Sin4'
   */
  rtb_Z_idx_2 = (rtb_Add_kl * rtb_uDLookupTable_l) + (rtb_Subtract_gn *
    rtb_MatrixConcatenate_b_idx_0);

  /* Sum: '<S222>/Subtract' incorporates:
   *  Product: '<S222>/Product'
   *  Product: '<S222>/Product1'
   *  Trigonometry: '<S222>/Cos4'
   *  Trigonometry: '<S222>/Sin4'
   */
  rtb_Z_idx_3 = (rtb_Add_kl * rtb_MatrixConcatenate_b_idx_0) - (rtb_Subtract_gn *
    rtb_uDLookupTable_l);

  /* Math: '<S222>/Hypot' */
  rtb_Switch2_ef = rt_hypotd_snf(rtb_Z_idx_3, rtb_Z_idx_2);

  /* Switch: '<S222>/Switch' incorporates:
   *  Constant: '<S222>/Constant'
   *  Constant: '<S222>/Constant1'
   *  Constant: '<S223>/Constant'
   *  Product: '<S222>/Divide'
   *  Product: '<S222>/Divide1'
   *  RelationalOperator: '<S223>/Compare'
   *  Switch: '<S222>/Switch1'
   */
  if (rtb_Switch2_ef > 1.0E-6) {
    rtb_Switch2_p = rtb_Z_idx_2 / rtb_Switch2_ef;
    rtb_MatrixConcatenate_b_idx_0 = rtb_Z_idx_3 / rtb_Switch2_ef;
  } else {
    rtb_Switch2_p = 0.0;
    rtb_MatrixConcatenate_b_idx_0 = 1.0;
  }

  /* End of Switch: '<S222>/Switch' */

  /* Switch: '<S211>/Speed_Switch' incorporates:
   *  Abs: '<S211>/Abs'
   *  Constant: '<S219>/Constant'
   *  RelationalOperator: '<S219>/Compare'
   *  Switch: '<S211>/Angle_Switch'
   *  Trigonometry: '<S221>/Atan1'
   *  Trigonometry: '<S222>/Atan1'
   *  UnaryMinus: '<S211>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_p, rtb_MatrixConcatenate_b_idx_0)) >
      1.5707963267948966) {
    rtb_Add_kz = -Code_Gen_Model_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S221>/Subtract1' incorporates:
     *  Product: '<S221>/Product2'
     *  Product: '<S221>/Product3'
     *  UnaryMinus: '<S211>/Unary Minus'
     */
    rtb_Z_idx_2 = (rtb_Add_kl * Code_Gen_Model_ConstB.Sin5_c) + (rtb_Subtract_gn
      * Code_Gen_Model_ConstB.Cos5_b);

    /* Sum: '<S221>/Subtract' incorporates:
     *  Product: '<S221>/Product'
     *  Product: '<S221>/Product1'
     */
    rtb_Switch2_ef = (rtb_Add_kl * Code_Gen_Model_ConstB.Cos5_b) -
      (rtb_Subtract_gn * Code_Gen_Model_ConstB.Sin5_c);

    /* Math: '<S221>/Hypot' */
    rtb_Z_idx_3 = rt_hypotd_snf(rtb_Switch2_ef, rtb_Z_idx_2);

    /* Switch: '<S221>/Switch1' incorporates:
     *  Constant: '<S221>/Constant'
     *  Constant: '<S221>/Constant1'
     *  Constant: '<S224>/Constant'
     *  Product: '<S221>/Divide'
     *  Product: '<S221>/Divide1'
     *  RelationalOperator: '<S224>/Compare'
     *  Switch: '<S221>/Switch'
     */
    if (rtb_Z_idx_3 > 1.0E-6) {
      rtb_Switch2_ef /= rtb_Z_idx_3;
      rtb_Z_idx_2 /= rtb_Z_idx_3;
    } else {
      rtb_Switch2_ef = 1.0;
      rtb_Z_idx_2 = 0.0;
    }

    /* End of Switch: '<S221>/Switch1' */
    rtb_uDLookupTable_l = rt_atan2d_snf(rtb_Z_idx_2, rtb_Switch2_ef);
  } else {
    rtb_Add_kz = Code_Gen_Model_B.BR_Desired_Wheel_Speed;
    rtb_uDLookupTable_l = Code_Gen_Model_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S214>/Product2' incorporates:
   *  Constant: '<S214>/Constant'
   *  Switch: '<S211>/Speed_Switch'
   */
  rtb_Switch2_p = rtb_Add_kz * 1530.1401357649195;

  /* Signum: '<S209>/Sign' */
  if (rtIsNaN(rtb_Switch2_p)) {
    rtb_Add_kz = (rtNaN);
  } else if (rtb_Switch2_p < 0.0) {
    rtb_Add_kz = -1.0;
  } else {
    rtb_Add_kz = (rtb_Switch2_p > 0.0);
  }

  /* Signum: '<S209>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.BackRight_Drive_Motor_Speed)) {
    rtb_Add_cz = (rtNaN);
  } else if (Code_Gen_Model_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_cz = -1.0;
  } else {
    rtb_Add_cz = (Code_Gen_Model_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S212>/Add' incorporates:
   *  Sum: '<S213>/Sum'
   */
  rtb_uDLookupTable_l -= Code_Gen_Model_B.BR_Steer_Module_Angle;

  /* Product: '<S144>/Product' incorporates:
   *  Abs: '<S209>/Abs'
   *  Abs: '<S212>/Abs'
   *  Constant: '<S215>/Constant'
   *  Constant: '<S225>/Constant3'
   *  Constant: '<S225>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S209>/OR'
   *  Lookup_n-D: '<S212>/1-D Lookup Table'
   *  Math: '<S225>/Math Function'
   *  RelationalOperator: '<S209>/Equal1'
   *  RelationalOperator: '<S215>/Compare'
   *  Signum: '<S209>/Sign'
   *  Signum: '<S209>/Sign1'
   *  Sum: '<S212>/Add'
   *  Sum: '<S225>/Add1'
   *  Sum: '<S225>/Add2'
   */
  rtb_Switch2_p = (((real_T)((rtb_Add_kz == rtb_Add_cz) || (fabs
    (Code_Gen_Model_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_p) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_uDLookupTable_l + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     Code_Gen_Model_ConstP.pooled26, Code_Gen_Model_ConstP.pooled25, 1U);

  /* Gain: '<S210>/Gain' */
  rtb_Switch2_ef = Drive_Motor_Control_FF * rtb_Switch2_p;

  /* Sum: '<S210>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Switch2_p -= Code_Gen_Model_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S217>/Sum1' incorporates:
   *  Constant: '<S210>/Constant2'
   *  Product: '<S217>/Product'
   *  Sum: '<S217>/Sum'
   *  UnitDelay: '<S217>/Unit Delay1'
   */
  rtb_Z_idx_2 = ((rtb_Switch2_p - Code_Gen_Model_DW.UnitDelay1_DSTATE_k) *
                 Drive_Motor_Control_D_FilterCoeff) +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_k;

  /* Product: '<S210>/Product' incorporates:
   *  Constant: '<S210>/Constant3'
   */
  rtb_Z_idx_3 = rtb_Z_idx_2 * Drive_Motor_Control_D;

  /* Sum: '<S216>/Diff' incorporates:
   *  UnitDelay: '<S216>/UD'
   *
   * Block description for '<S216>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S216>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Z_idx_3 - Code_Gen_Model_DW.UD_DSTATE_cs;

  /* Saturate: '<S210>/Saturation' */
  if (rtb_Add_ec > Drive_Motor_Control_D_UL) {
    rtb_Add_ec = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_ec < Drive_Motor_Control_D_LL) {
    rtb_Add_ec = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S210>/Add' incorporates:
   *  Gain: '<S210>/Gain1'
   *  Saturate: '<S210>/Saturation'
   */
  rtb_Magnitude = ((Drive_Motor_Control_P * rtb_Switch2_p) + rtb_Switch2_ef) +
    rtb_Add_ec;

  /* Sum: '<S210>/Subtract' incorporates:
   *  Constant: '<S210>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Magnitude;

  /* Sum: '<S210>/Sum2' incorporates:
   *  Gain: '<S210>/Gain2'
   *  UnitDelay: '<S210>/Unit Delay'
   */
  rtb_Switch2_ef = (Drive_Motor_Control_I * rtb_Switch2_p) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_a;

  /* Switch: '<S218>/Switch2' incorporates:
   *  Constant: '<S210>/Constant'
   *  RelationalOperator: '<S218>/LowerRelop1'
   *  Sum: '<S210>/Subtract'
   */
  if (!(rtb_Switch2_ef > (1.0 - rtb_Magnitude))) {
    /* Switch: '<S218>/Switch' incorporates:
     *  Constant: '<S210>/Constant1'
     *  RelationalOperator: '<S218>/UpperRelop'
     *  Sum: '<S210>/Subtract1'
     */
    if (rtb_Switch2_ef < (-1.0 - rtb_Magnitude)) {
      rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Magnitude;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_ef;
    }

    /* End of Switch: '<S218>/Switch' */
  }

  /* End of Switch: '<S218>/Switch2' */

  /* Saturate: '<S210>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Drive_Motor_Control_I_UL) {
    rtb_Switch2_ef = Drive_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Drive_Motor_Control_I_LL) {
    rtb_Switch2_ef = Drive_Motor_Control_I_LL;
  } else {
    rtb_Switch2_ef = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S210>/Saturation1' */

  /* Sum: '<S210>/Add1' */
  rtb_Add_ec = rtb_Magnitude + rtb_Switch2_ef;

  /* Saturate: '<S210>/Saturation2' */
  if (rtb_Add_ec > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_ec < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = rtb_Add_ec;
  }

  /* End of Saturate: '<S210>/Saturation2' */

  /* Sum: '<S226>/Add1' incorporates:
   *  Constant: '<S226>/Constant3'
   *  Constant: '<S226>/Constant4'
   *  Math: '<S226>/Math Function'
   *  Sum: '<S226>/Add2'
   */
  rtb_Switch2_p = rt_modd_snf(rtb_uDLookupTable_l + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S228>/Sum1' incorporates:
   *  Constant: '<S213>/Constant2'
   *  Product: '<S228>/Product'
   *  Sum: '<S228>/Sum'
   *  UnitDelay: '<S228>/Unit Delay1'
   */
  rtb_Magnitude = ((rtb_Switch2_p - Code_Gen_Model_DW.UnitDelay1_DSTATE_i) *
                   Steering_Motor_Control_D_FilterCoeff) +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S213>/Product' incorporates:
   *  Constant: '<S213>/Constant3'
   */
  rtb_Steer_Joystick_X_Rel_Mod = rtb_Magnitude * Steering_Motor_Control_D;

  /* Sum: '<S227>/Diff' incorporates:
   *  UnitDelay: '<S227>/UD'
   *
   * Block description for '<S227>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S227>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Steer_Joystick_X_Rel_Mod - Code_Gen_Model_DW.UD_DSTATE_l;

  /* Saturate: '<S213>/Saturation' */
  if (rtb_Add_ec > Steering_Motor_Control_D_UL) {
    rtb_Add_ec = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_ec < Steering_Motor_Control_D_LL) {
    rtb_Add_ec = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S213>/Add' incorporates:
   *  Gain: '<S213>/Gain1'
   *  Saturate: '<S213>/Saturation'
   */
  rtb_Add_pw = (Steering_Motor_Control_P * rtb_Switch2_p) + rtb_Add_ec;

  /* Sum: '<S213>/Subtract' incorporates:
   *  Constant: '<S213>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_pw;

  /* Sum: '<S213>/Sum2' incorporates:
   *  Gain: '<S213>/Gain2'
   *  UnitDelay: '<S213>/Unit Delay'
   */
  rtb_Sum2_fc = (Steering_Motor_Control_I * rtb_Switch2_p) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_l;

  /* Switch: '<S229>/Switch2' incorporates:
   *  Constant: '<S213>/Constant'
   *  RelationalOperator: '<S229>/LowerRelop1'
   *  Sum: '<S213>/Subtract'
   */
  if (!(rtb_Sum2_fc > (1.0 - rtb_Add_pw))) {
    /* Switch: '<S229>/Switch' incorporates:
     *  Constant: '<S213>/Constant1'
     *  RelationalOperator: '<S229>/UpperRelop'
     *  Sum: '<S213>/Subtract1'
     */
    if (rtb_Sum2_fc < (-1.0 - rtb_Add_pw)) {
      rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_pw;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Sum2_fc;
    }

    /* End of Switch: '<S229>/Switch' */
  }

  /* End of Switch: '<S229>/Switch2' */

  /* Saturate: '<S213>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_fc = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S213>/Saturation1' */

  /* Sum: '<S213>/Add1' */
  rtb_Add_ec = rtb_Add_pw + rtb_Sum2_fc;

  /* Saturate: '<S213>/Saturation2' */
  if (rtb_Add_ec > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_ec < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = rtb_Add_ec;
  }

  /* End of Saturate: '<S213>/Saturation2' */

  /* Product: '<S258>/Product' */
  Code_Gen_Model_B.FL_Desired_Wheel_Speed = Code_Gen_Model_B.Switch1_m *
    rtb_Init_e;

  /* Switch: '<S263>/Switch' */
  if (!rtb_Is_Absolute_Steering) {
    /* Switch: '<S263>/Switch' incorporates:
     *  Fcn: '<S264>/x->theta'
     */
    Code_Gen_Model_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S263>/Switch' */

  /* Trigonometry: '<S159>/Cos4' incorporates:
   *  Switch: '<S148>/Angle_Switch'
   *  Trigonometry: '<S158>/Cos4'
   */
  rtb_Add_kl = cos(Code_Gen_Model_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S159>/Sin5' incorporates:
   *  UnaryMinus: '<S157>/Unary Minus'
   */
  rtb_uDLookupTable_l = sin(-Code_Gen_Model_B.FL_Steer_Module_Angle);

  /* Trigonometry: '<S159>/Sin4' incorporates:
   *  Switch: '<S148>/Angle_Switch'
   *  Trigonometry: '<S158>/Sin4'
   */
  rtb_Subtract_gn = sin(Code_Gen_Model_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S159>/Cos5' incorporates:
   *  UnaryMinus: '<S157>/Unary Minus'
   */
  rtb_MatrixConcatenate_b_idx_0 = cos(-Code_Gen_Model_B.FL_Steer_Module_Angle);

  /* Sum: '<S159>/Subtract1' incorporates:
   *  Product: '<S159>/Product2'
   *  Product: '<S159>/Product3'
   *  Trigonometry: '<S159>/Cos4'
   *  Trigonometry: '<S159>/Sin4'
   */
  rtb_Switch2_p = (rtb_Add_kl * rtb_uDLookupTable_l) + (rtb_Subtract_gn *
    rtb_MatrixConcatenate_b_idx_0);

  /* Sum: '<S159>/Subtract' incorporates:
   *  Product: '<S159>/Product'
   *  Product: '<S159>/Product1'
   *  Trigonometry: '<S159>/Cos4'
   *  Trigonometry: '<S159>/Sin4'
   */
  rtb_Add_pw = (rtb_Add_kl * rtb_MatrixConcatenate_b_idx_0) - (rtb_Subtract_gn *
    rtb_uDLookupTable_l);

  /* Math: '<S159>/Hypot' */
  rtb_Hypot_g5 = rt_hypotd_snf(rtb_Add_pw, rtb_Switch2_p);

  /* Switch: '<S159>/Switch' incorporates:
   *  Constant: '<S159>/Constant'
   *  Constant: '<S159>/Constant1'
   *  Constant: '<S160>/Constant'
   *  Product: '<S159>/Divide'
   *  Product: '<S159>/Divide1'
   *  RelationalOperator: '<S160>/Compare'
   *  Switch: '<S159>/Switch1'
   */
  if (rtb_Hypot_g5 > 1.0E-6) {
    rtb_Switch2_p /= rtb_Hypot_g5;
    rtb_MatrixConcatenate_b_idx_0 = rtb_Add_pw / rtb_Hypot_g5;
  } else {
    rtb_Switch2_p = 0.0;
    rtb_MatrixConcatenate_b_idx_0 = 1.0;
  }

  /* End of Switch: '<S159>/Switch' */

  /* Switch: '<S148>/Speed_Switch' incorporates:
   *  Abs: '<S148>/Abs'
   *  Constant: '<S156>/Constant'
   *  RelationalOperator: '<S156>/Compare'
   *  Switch: '<S148>/Angle_Switch'
   *  Trigonometry: '<S158>/Atan1'
   *  Trigonometry: '<S159>/Atan1'
   *  UnaryMinus: '<S148>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_p, rtb_MatrixConcatenate_b_idx_0)) >
      1.5707963267948966) {
    rtb_Add_kz = -Code_Gen_Model_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S158>/Subtract1' incorporates:
     *  Product: '<S158>/Product2'
     *  Product: '<S158>/Product3'
     *  UnaryMinus: '<S148>/Unary Minus'
     */
    rtb_Add_pw = (rtb_Add_kl * Code_Gen_Model_ConstB.Sin5) + (rtb_Subtract_gn *
      Code_Gen_Model_ConstB.Cos5);

    /* Sum: '<S158>/Subtract' incorporates:
     *  Product: '<S158>/Product'
     *  Product: '<S158>/Product1'
     */
    rtb_Subtract_i = (rtb_Add_kl * Code_Gen_Model_ConstB.Cos5) -
      (rtb_Subtract_gn * Code_Gen_Model_ConstB.Sin5);

    /* Math: '<S158>/Hypot' */
    rtb_Hypot_g5 = rt_hypotd_snf(rtb_Subtract_i, rtb_Add_pw);

    /* Switch: '<S158>/Switch1' incorporates:
     *  Constant: '<S158>/Constant'
     *  Constant: '<S158>/Constant1'
     *  Constant: '<S161>/Constant'
     *  Product: '<S158>/Divide'
     *  Product: '<S158>/Divide1'
     *  RelationalOperator: '<S161>/Compare'
     *  Switch: '<S158>/Switch'
     */
    if (rtb_Hypot_g5 > 1.0E-6) {
      rtb_Subtract_i /= rtb_Hypot_g5;
      rtb_Add_pw /= rtb_Hypot_g5;
    } else {
      rtb_Subtract_i = 1.0;
      rtb_Add_pw = 0.0;
    }

    /* End of Switch: '<S158>/Switch1' */
    rtb_uDLookupTable_l = rt_atan2d_snf(rtb_Add_pw, rtb_Subtract_i);
  } else {
    rtb_Add_kz = Code_Gen_Model_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable_l = Code_Gen_Model_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S151>/Product2' incorporates:
   *  Constant: '<S151>/Constant'
   *  Switch: '<S148>/Speed_Switch'
   */
  rtb_Switch2_p = rtb_Add_kz * 1530.1401357649195;

  /* Signum: '<S146>/Sign' */
  if (rtIsNaN(rtb_Switch2_p)) {
    rtb_Add_kz = (rtNaN);
  } else if (rtb_Switch2_p < 0.0) {
    rtb_Add_kz = -1.0;
  } else {
    rtb_Add_kz = (rtb_Switch2_p > 0.0);
  }

  /* Signum: '<S146>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Add_cz = (rtNaN);
  } else if (Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_cz = -1.0;
  } else {
    rtb_Add_cz = (Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S149>/Add' incorporates:
   *  Sum: '<S150>/Sum'
   */
  rtb_uDLookupTable_l -= Code_Gen_Model_B.FL_Steer_Module_Angle;

  /* Product: '<S141>/Product' incorporates:
   *  Abs: '<S146>/Abs'
   *  Abs: '<S149>/Abs'
   *  Constant: '<S152>/Constant'
   *  Constant: '<S162>/Constant3'
   *  Constant: '<S162>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S146>/OR'
   *  Lookup_n-D: '<S149>/1-D Lookup Table'
   *  Math: '<S162>/Math Function'
   *  RelationalOperator: '<S146>/Equal1'
   *  RelationalOperator: '<S152>/Compare'
   *  Signum: '<S146>/Sign'
   *  Signum: '<S146>/Sign1'
   *  Sum: '<S149>/Add'
   *  Sum: '<S162>/Add1'
   *  Sum: '<S162>/Add2'
   */
  rtb_Switch2_p = (((real_T)((rtb_Add_kz == rtb_Add_cz) || (fabs
    (Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_p) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_uDLookupTable_l + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     Code_Gen_Model_ConstP.pooled26, Code_Gen_Model_ConstP.pooled25, 1U);

  /* Gain: '<S147>/Gain' */
  rtb_Subtract_i = Drive_Motor_Control_FF * rtb_Switch2_p;

  /* Sum: '<S147>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Switch2_p -= Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S154>/Sum1' incorporates:
   *  Constant: '<S147>/Constant2'
   *  Product: '<S154>/Product'
   *  Sum: '<S154>/Sum'
   *  UnitDelay: '<S154>/Unit Delay1'
   */
  rtb_Add_pw = ((rtb_Switch2_p - Code_Gen_Model_DW.UnitDelay1_DSTATE_a) *
                Drive_Motor_Control_D_FilterCoeff) +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_a;

  /* Product: '<S147>/Product' incorporates:
   *  Constant: '<S147>/Constant3'
   */
  rtb_Hypot_g5 = rtb_Add_pw * Drive_Motor_Control_D;

  /* Sum: '<S153>/Diff' incorporates:
   *  UnitDelay: '<S153>/UD'
   *
   * Block description for '<S153>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S153>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Hypot_g5 - Code_Gen_Model_DW.UD_DSTATE_o;

  /* Saturate: '<S147>/Saturation' */
  if (rtb_Add_ec > Drive_Motor_Control_D_UL) {
    rtb_Add_ec = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_ec < Drive_Motor_Control_D_LL) {
    rtb_Add_ec = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S147>/Add' incorporates:
   *  Gain: '<S147>/Gain1'
   *  Saturate: '<S147>/Saturation'
   */
  rtb_Add_c4 = ((Drive_Motor_Control_P * rtb_Switch2_p) + rtb_Subtract_i) +
    rtb_Add_ec;

  /* Sum: '<S147>/Subtract' incorporates:
   *  Constant: '<S147>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_c4;

  /* Sum: '<S147>/Sum2' incorporates:
   *  Gain: '<S147>/Gain2'
   *  UnitDelay: '<S147>/Unit Delay'
   */
  rtb_Switch2_p = (Drive_Motor_Control_I * rtb_Switch2_p) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_f;

  /* Switch: '<S155>/Switch2' incorporates:
   *  Constant: '<S147>/Constant'
   *  RelationalOperator: '<S155>/LowerRelop1'
   *  Sum: '<S147>/Subtract'
   */
  if (!(rtb_Switch2_p > (1.0 - rtb_Add_c4))) {
    /* Switch: '<S155>/Switch' incorporates:
     *  Constant: '<S147>/Constant1'
     *  RelationalOperator: '<S155>/UpperRelop'
     *  Sum: '<S147>/Subtract1'
     */
    if (rtb_Switch2_p < (-1.0 - rtb_Add_c4)) {
      rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_c4;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p;
    }

    /* End of Switch: '<S155>/Switch' */
  }

  /* End of Switch: '<S155>/Switch2' */

  /* Saturate: '<S147>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Drive_Motor_Control_I_UL) {
    rtb_Subtract_i = Drive_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Drive_Motor_Control_I_LL) {
    rtb_Subtract_i = Drive_Motor_Control_I_LL;
  } else {
    rtb_Subtract_i = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S147>/Saturation1' */

  /* Sum: '<S147>/Add1' */
  rtb_Add_ec = rtb_Add_c4 + rtb_Subtract_i;

  /* Saturate: '<S147>/Saturation2' */
  if (rtb_Add_ec > 1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_ec < -1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = rtb_Add_ec;
  }

  /* End of Saturate: '<S147>/Saturation2' */

  /* Sum: '<S163>/Add1' incorporates:
   *  Constant: '<S163>/Constant3'
   *  Constant: '<S163>/Constant4'
   *  Math: '<S163>/Math Function'
   *  Sum: '<S163>/Add2'
   */
  rtb_Switch2_p = rt_modd_snf(rtb_uDLookupTable_l + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S165>/Sum1' incorporates:
   *  Constant: '<S150>/Constant2'
   *  Product: '<S165>/Product'
   *  Sum: '<S165>/Sum'
   *  UnitDelay: '<S165>/Unit Delay1'
   */
  rtb_Add_c4 = ((rtb_Switch2_p - Code_Gen_Model_DW.UnitDelay1_DSTATE_b) *
                Steering_Motor_Control_D_FilterCoeff) +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S150>/Product' incorporates:
   *  Constant: '<S150>/Constant3'
   */
  rtb_Product_dq = rtb_Add_c4 * Steering_Motor_Control_D;

  /* Sum: '<S164>/Diff' incorporates:
   *  UnitDelay: '<S164>/UD'
   *
   * Block description for '<S164>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S164>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Product_dq - Code_Gen_Model_DW.UD_DSTATE_b;

  /* Saturate: '<S150>/Saturation' */
  if (rtb_Add_ec > Steering_Motor_Control_D_UL) {
    rtb_Add_ec = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_ec < Steering_Motor_Control_D_LL) {
    rtb_Add_ec = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S150>/Add' incorporates:
   *  Gain: '<S150>/Gain1'
   *  Saturate: '<S150>/Saturation'
   */
  rtb_Add_kl = (Steering_Motor_Control_P * rtb_Switch2_p) + rtb_Add_ec;

  /* Sum: '<S150>/Subtract' incorporates:
   *  Constant: '<S150>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_kl;

  /* Sum: '<S150>/Sum2' incorporates:
   *  Gain: '<S150>/Gain2'
   *  UnitDelay: '<S150>/Unit Delay'
   */
  rtb_Switch2_p = (Steering_Motor_Control_I * rtb_Switch2_p) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S166>/Switch2' incorporates:
   *  Constant: '<S150>/Constant'
   *  RelationalOperator: '<S166>/LowerRelop1'
   *  Sum: '<S150>/Subtract'
   */
  if (!(rtb_Switch2_p > (1.0 - rtb_Add_kl))) {
    /* Switch: '<S166>/Switch' incorporates:
     *  Constant: '<S150>/Constant1'
     *  RelationalOperator: '<S166>/UpperRelop'
     *  Sum: '<S150>/Subtract1'
     */
    if (rtb_Switch2_p < (-1.0 - rtb_Add_kl)) {
      rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_kl;
    } else {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p;
    }

    /* End of Switch: '<S166>/Switch' */
  }

  /* End of Switch: '<S166>/Switch2' */

  /* Saturate: '<S150>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_la = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_la = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_la = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S150>/Saturation1' */

  /* Sum: '<S150>/Add1' */
  rtb_Add_ec = rtb_Add_kl + rtb_Subtract1_la;

  /* Saturate: '<S150>/Saturation2' */
  if (rtb_Add_ec > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_ec < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = rtb_Add_ec;
  }

  /* End of Saturate: '<S150>/Saturation2' */

  /* Product: '<S258>/Product1' */
  Code_Gen_Model_B.FR_Desired_Wheel_Speed = Code_Gen_Model_B.Switch1_o *
    rtb_Init_e;

  /* Switch: '<S268>/Switch' */
  if (!rtb_OR_ao) {
    /* Switch: '<S268>/Switch' incorporates:
     *  Fcn: '<S269>/x->theta'
     */
    Code_Gen_Model_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S268>/Switch' */

  /* Trigonometry: '<S180>/Cos4' incorporates:
   *  Switch: '<S169>/Angle_Switch'
   *  Trigonometry: '<S179>/Cos4'
   */
  rtb_Add_kl = cos(Code_Gen_Model_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S180>/Sin5' incorporates:
   *  UnaryMinus: '<S178>/Unary Minus'
   */
  rtb_uDLookupTable_l = sin(-Code_Gen_Model_B.FR_Steer_Module_Angle);

  /* Trigonometry: '<S180>/Sin4' incorporates:
   *  Switch: '<S169>/Angle_Switch'
   *  Trigonometry: '<S179>/Sin4'
   */
  rtb_Subtract_gn = sin(Code_Gen_Model_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S180>/Cos5' incorporates:
   *  UnaryMinus: '<S178>/Unary Minus'
   */
  rtb_MatrixConcatenate_b_idx_0 = cos(-Code_Gen_Model_B.FR_Steer_Module_Angle);

  /* Sum: '<S180>/Subtract1' incorporates:
   *  Product: '<S180>/Product2'
   *  Product: '<S180>/Product3'
   *  Trigonometry: '<S180>/Cos4'
   *  Trigonometry: '<S180>/Sin4'
   */
  rtb_Switch2_p = (rtb_Add_kl * rtb_uDLookupTable_l) + (rtb_Subtract_gn *
    rtb_MatrixConcatenate_b_idx_0);

  /* Sum: '<S180>/Subtract' incorporates:
   *  Product: '<S180>/Product'
   *  Product: '<S180>/Product1'
   *  Trigonometry: '<S180>/Cos4'
   *  Trigonometry: '<S180>/Sin4'
   */
  rtb_MatrixConcatenate_b_idx_0 = (rtb_Add_kl * rtb_MatrixConcatenate_b_idx_0) -
    (rtb_Subtract_gn * rtb_uDLookupTable_l);

  /* Math: '<S180>/Hypot' */
  rtb_Hypot_b = rt_hypotd_snf(rtb_MatrixConcatenate_b_idx_0, rtb_Switch2_p);

  /* Switch: '<S180>/Switch' incorporates:
   *  Constant: '<S180>/Constant'
   *  Constant: '<S180>/Constant1'
   *  Constant: '<S181>/Constant'
   *  Product: '<S180>/Divide'
   *  Product: '<S180>/Divide1'
   *  RelationalOperator: '<S181>/Compare'
   *  Switch: '<S180>/Switch1'
   */
  if (rtb_Hypot_b > 1.0E-6) {
    rtb_Switch2_p /= rtb_Hypot_b;
    rtb_MatrixConcatenate_b_idx_0 /= rtb_Hypot_b;
  } else {
    rtb_Switch2_p = 0.0;
    rtb_MatrixConcatenate_b_idx_0 = 1.0;
  }

  /* End of Switch: '<S180>/Switch' */

  /* Switch: '<S169>/Speed_Switch' incorporates:
   *  Abs: '<S169>/Abs'
   *  Constant: '<S177>/Constant'
   *  RelationalOperator: '<S177>/Compare'
   *  Switch: '<S169>/Angle_Switch'
   *  Trigonometry: '<S179>/Atan1'
   *  Trigonometry: '<S180>/Atan1'
   *  UnaryMinus: '<S169>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_p, rtb_MatrixConcatenate_b_idx_0)) >
      1.5707963267948966) {
    rtb_Add_kz = -Code_Gen_Model_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S179>/Subtract1' incorporates:
     *  Product: '<S179>/Product2'
     *  Product: '<S179>/Product3'
     *  UnaryMinus: '<S169>/Unary Minus'
     */
    rtb_MatrixConcatenate_b_idx_0 = (rtb_Add_kl * Code_Gen_Model_ConstB.Sin5_m)
      + (rtb_Subtract_gn * Code_Gen_Model_ConstB.Cos5_g);

    /* Sum: '<S179>/Subtract' incorporates:
     *  Product: '<S179>/Product'
     *  Product: '<S179>/Product1'
     */
    rtb_Subtract_gn = (rtb_Add_kl * Code_Gen_Model_ConstB.Cos5_g) -
      (rtb_Subtract_gn * Code_Gen_Model_ConstB.Sin5_m);

    /* Math: '<S179>/Hypot' */
    rtb_Add_kl = rt_hypotd_snf(rtb_Subtract_gn, rtb_MatrixConcatenate_b_idx_0);

    /* Switch: '<S179>/Switch1' incorporates:
     *  Constant: '<S179>/Constant'
     *  Constant: '<S179>/Constant1'
     *  Constant: '<S182>/Constant'
     *  Product: '<S179>/Divide'
     *  Product: '<S179>/Divide1'
     *  RelationalOperator: '<S182>/Compare'
     *  Switch: '<S179>/Switch'
     */
    if (rtb_Add_kl > 1.0E-6) {
      rtb_Subtract_gn /= rtb_Add_kl;
      rtb_MatrixConcatenate_b_idx_0 /= rtb_Add_kl;
    } else {
      rtb_Subtract_gn = 1.0;
      rtb_MatrixConcatenate_b_idx_0 = 0.0;
    }

    /* End of Switch: '<S179>/Switch1' */
    rtb_uDLookupTable_l = rt_atan2d_snf(rtb_MatrixConcatenate_b_idx_0,
      rtb_Subtract_gn);
  } else {
    rtb_Add_kz = Code_Gen_Model_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable_l = Code_Gen_Model_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S172>/Product2' incorporates:
   *  Constant: '<S172>/Constant'
   *  Switch: '<S169>/Speed_Switch'
   */
  rtb_Switch2_p = rtb_Add_kz * 1530.1401357649195;

  /* Signum: '<S167>/Sign' */
  if (rtIsNaN(rtb_Switch2_p)) {
    rtb_Add_kz = (rtNaN);
  } else if (rtb_Switch2_p < 0.0) {
    rtb_Add_kz = -1.0;
  } else {
    rtb_Add_kz = (rtb_Switch2_p > 0.0);
  }

  /* Signum: '<S167>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Add_cz = (rtNaN);
  } else if (Code_Gen_Model_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_cz = -1.0;
  } else {
    rtb_Add_cz = (Code_Gen_Model_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S170>/Add' incorporates:
   *  Sum: '<S171>/Sum'
   */
  rtb_uDLookupTable_l -= Code_Gen_Model_B.FR_Steer_Module_Angle;

  /* Product: '<S142>/Product' incorporates:
   *  Abs: '<S167>/Abs'
   *  Abs: '<S170>/Abs'
   *  Constant: '<S173>/Constant'
   *  Constant: '<S183>/Constant3'
   *  Constant: '<S183>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S167>/OR'
   *  Lookup_n-D: '<S170>/1-D Lookup Table'
   *  Math: '<S183>/Math Function'
   *  RelationalOperator: '<S167>/Equal1'
   *  RelationalOperator: '<S173>/Compare'
   *  Signum: '<S167>/Sign'
   *  Signum: '<S167>/Sign1'
   *  Sum: '<S170>/Add'
   *  Sum: '<S183>/Add1'
   *  Sum: '<S183>/Add2'
   */
  rtb_Switch2_p = (((real_T)((rtb_Add_kz == rtb_Add_cz) || (fabs
    (Code_Gen_Model_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_p) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_uDLookupTable_l + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     Code_Gen_Model_ConstP.pooled26, Code_Gen_Model_ConstP.pooled25, 1U);

  /* Gain: '<S168>/Gain' */
  rtb_MatrixConcatenate_b_idx_0 = Drive_Motor_Control_FF * rtb_Switch2_p;

  /* Sum: '<S168>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Switch2_p -= Code_Gen_Model_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S175>/Sum1' incorporates:
   *  Constant: '<S168>/Constant2'
   *  Product: '<S175>/Product'
   *  Sum: '<S175>/Sum'
   *  UnitDelay: '<S175>/Unit Delay1'
   */
  rtb_Add_kl = ((rtb_Switch2_p - Code_Gen_Model_DW.UnitDelay1_DSTATE_b1) *
                Drive_Motor_Control_D_FilterCoeff) +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_b1;

  /* Product: '<S168>/Product' incorporates:
   *  Constant: '<S168>/Constant3'
   */
  rtb_Subtract_gn = rtb_Add_kl * Drive_Motor_Control_D;

  /* Sum: '<S174>/Diff' incorporates:
   *  UnitDelay: '<S174>/UD'
   *
   * Block description for '<S174>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S174>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Subtract_gn - Code_Gen_Model_DW.UD_DSTATE_e;

  /* Saturate: '<S168>/Saturation' */
  if (rtb_Add_ec > Drive_Motor_Control_D_UL) {
    rtb_Add_ec = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_ec < Drive_Motor_Control_D_LL) {
    rtb_Add_ec = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S168>/Add' incorporates:
   *  Gain: '<S168>/Gain1'
   *  Saturate: '<S168>/Saturation'
   */
  rtb_Add_c = ((Drive_Motor_Control_P * rtb_Switch2_p) +
               rtb_MatrixConcatenate_b_idx_0) + rtb_Add_ec;

  /* Sum: '<S168>/Subtract' incorporates:
   *  Constant: '<S168>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_c;

  /* Sum: '<S168>/Sum2' incorporates:
   *  Gain: '<S168>/Gain2'
   *  UnitDelay: '<S168>/Unit Delay'
   */
  rtb_Switch2_p = (Drive_Motor_Control_I * rtb_Switch2_p) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_em;

  /* Switch: '<S176>/Switch2' incorporates:
   *  Constant: '<S168>/Constant'
   *  RelationalOperator: '<S176>/LowerRelop1'
   *  Sum: '<S168>/Subtract'
   */
  if (!(rtb_Switch2_p > (1.0 - rtb_Add_c))) {
    /* Sum: '<S168>/Subtract1' incorporates:
     *  Constant: '<S168>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_c;

    /* Switch: '<S176>/Switch' incorporates:
     *  Constant: '<S168>/Constant1'
     *  RelationalOperator: '<S176>/UpperRelop'
     *  Sum: '<S168>/Subtract1'
     */
    if (!(rtb_Switch2_p < (-1.0 - rtb_Add_c))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p;
    }

    /* End of Switch: '<S176>/Switch' */
  }

  /* End of Switch: '<S176>/Switch2' */

  /* Saturate: '<S168>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Drive_Motor_Control_I_UL) {
    rtb_Hypot_b = Drive_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Drive_Motor_Control_I_LL) {
    rtb_Hypot_b = Drive_Motor_Control_I_LL;
  } else {
    rtb_Hypot_b = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S168>/Saturation1' */

  /* Sum: '<S168>/Add1' */
  rtb_Add_ec = rtb_Add_c + rtb_Hypot_b;

  /* Saturate: '<S168>/Saturation2' */
  if (rtb_Add_ec > 1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_ec < -1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = rtb_Add_ec;
  }

  /* End of Saturate: '<S168>/Saturation2' */

  /* Sum: '<S184>/Add1' incorporates:
   *  Constant: '<S184>/Constant3'
   *  Constant: '<S184>/Constant4'
   *  Math: '<S184>/Math Function'
   *  Sum: '<S184>/Add2'
   */
  rtb_Switch2_p = rt_modd_snf(rtb_uDLookupTable_l + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S186>/Sum1' incorporates:
   *  Constant: '<S171>/Constant2'
   *  Product: '<S186>/Product'
   *  Sum: '<S186>/Sum'
   *  UnitDelay: '<S186>/Unit Delay1'
   */
  rtb_uDLookupTable_l = ((rtb_Switch2_p - Code_Gen_Model_DW.UnitDelay1_DSTATE_n)
    * Steering_Motor_Control_D_FilterCoeff) +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S171>/Product' incorporates:
   *  Constant: '<S171>/Constant3'
   */
  rtb_Add_c = rtb_uDLookupTable_l * Steering_Motor_Control_D;

  /* Sum: '<S185>/Diff' incorporates:
   *  UnitDelay: '<S185>/UD'
   *
   * Block description for '<S185>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S185>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Add_c - Code_Gen_Model_DW.UD_DSTATE_i1;

  /* Saturate: '<S171>/Saturation' */
  if (rtb_Add_ec > Steering_Motor_Control_D_UL) {
    rtb_Add_ec = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_ec < Steering_Motor_Control_D_LL) {
    rtb_Add_ec = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S171>/Add' incorporates:
   *  Gain: '<S171>/Gain1'
   *  Saturate: '<S171>/Saturation'
   */
  rtb_Add_cz = (Steering_Motor_Control_P * rtb_Switch2_p) + rtb_Add_ec;

  /* Sum: '<S171>/Subtract' incorporates:
   *  Constant: '<S171>/Constant'
   */
  rtb_MatrixConcatenate_b_idx_0 = 1.0 - rtb_Add_cz;

  /* Sum: '<S171>/Sum2' incorporates:
   *  Gain: '<S171>/Gain2'
   *  UnitDelay: '<S171>/Unit Delay'
   */
  rtb_Switch2_p = (Steering_Motor_Control_I * rtb_Switch2_p) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S187>/Switch2' incorporates:
   *  Constant: '<S171>/Constant'
   *  RelationalOperator: '<S187>/LowerRelop1'
   *  Sum: '<S171>/Subtract'
   */
  if (!(rtb_Switch2_p > (1.0 - rtb_Add_cz))) {
    /* Sum: '<S171>/Subtract1' incorporates:
     *  Constant: '<S171>/Constant1'
     */
    rtb_MatrixConcatenate_b_idx_0 = -1.0 - rtb_Add_cz;

    /* Switch: '<S187>/Switch' incorporates:
     *  Constant: '<S171>/Constant1'
     *  RelationalOperator: '<S187>/UpperRelop'
     *  Sum: '<S171>/Subtract1'
     */
    if (!(rtb_Switch2_p < (-1.0 - rtb_Add_cz))) {
      rtb_MatrixConcatenate_b_idx_0 = rtb_Switch2_p;
    }

    /* End of Switch: '<S187>/Switch' */
  }

  /* End of Switch: '<S187>/Switch2' */

  /* Saturate: '<S171>/Saturation1' */
  if (rtb_MatrixConcatenate_b_idx_0 > Steering_Motor_Control_I_UL) {
    rtb_Integral_kz = Steering_Motor_Control_I_UL;
  } else if (rtb_MatrixConcatenate_b_idx_0 < Steering_Motor_Control_I_LL) {
    rtb_Integral_kz = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_kz = rtb_MatrixConcatenate_b_idx_0;
  }

  /* End of Saturate: '<S171>/Saturation1' */

  /* Sum: '<S171>/Add1' */
  rtb_Add_ec = rtb_Add_cz + rtb_Integral_kz;

  /* Saturate: '<S171>/Saturation2' */
  if (rtb_Add_ec > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_ec < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = rtb_Add_ec;
  }

  /* End of Saturate: '<S171>/Saturation2' */

  /* Product: '<S258>/Product2' */
  Code_Gen_Model_B.BL_Desired_Wheel_Speed = Code_Gen_Model_B.Switch1_p *
    rtb_Init_e;

  /* Switch: '<S273>/Switch' */
  if (!rtb_Switch_b1) {
    /* Switch: '<S273>/Switch' incorporates:
     *  Fcn: '<S274>/x->theta'
     */
    Code_Gen_Model_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2_f[1],
      rtb_Add2_f[0]);
  }

  /* End of Switch: '<S273>/Switch' */

  /* Trigonometry: '<S201>/Cos4' incorporates:
   *  Switch: '<S190>/Angle_Switch'
   *  Trigonometry: '<S200>/Cos4'
   */
  rtb_Add_cz = cos(Code_Gen_Model_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S201>/Sin5' incorporates:
   *  UnaryMinus: '<S199>/Unary Minus'
   */
  rtb_MatrixConcatenate_b_idx_0 = sin(-Code_Gen_Model_B.BL_Steer_Module_Angle);

  /* Trigonometry: '<S201>/Sin4' incorporates:
   *  Switch: '<S190>/Angle_Switch'
   *  Trigonometry: '<S200>/Sin4'
   */
  rtb_Product_do = sin(Code_Gen_Model_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S201>/Cos5' incorporates:
   *  UnaryMinus: '<S199>/Unary Minus'
   */
  rtb_Switch2_p = cos(-Code_Gen_Model_B.BL_Steer_Module_Angle);

  /* Sum: '<S201>/Subtract1' incorporates:
   *  Product: '<S201>/Product2'
   *  Product: '<S201>/Product3'
   *  Trigonometry: '<S201>/Cos4'
   *  Trigonometry: '<S201>/Sin4'
   */
  rtb_Init_e = (rtb_Add_cz * rtb_MatrixConcatenate_b_idx_0) + (rtb_Product_do *
    rtb_Switch2_p);

  /* Sum: '<S201>/Subtract' incorporates:
   *  Product: '<S201>/Product'
   *  Product: '<S201>/Product1'
   *  Trigonometry: '<S201>/Cos4'
   *  Trigonometry: '<S201>/Sin4'
   */
  rtb_Switch2_p = (rtb_Add_cz * rtb_Switch2_p) - (rtb_Product_do *
    rtb_MatrixConcatenate_b_idx_0);

  /* Math: '<S201>/Hypot' */
  rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Switch2_p, rtb_Init_e);

  /* Switch: '<S201>/Switch' incorporates:
   *  Constant: '<S201>/Constant'
   *  Constant: '<S201>/Constant1'
   *  Constant: '<S202>/Constant'
   *  Product: '<S201>/Divide'
   *  Product: '<S201>/Divide1'
   *  RelationalOperator: '<S202>/Compare'
   *  Switch: '<S201>/Switch1'
   */
  if (rtb_MatrixConcatenate_b_idx_0 > 1.0E-6) {
    rtb_Init_e /= rtb_MatrixConcatenate_b_idx_0;
    rtb_Switch2_p /= rtb_MatrixConcatenate_b_idx_0;
  } else {
    rtb_Init_e = 0.0;
    rtb_Switch2_p = 1.0;
  }

  /* End of Switch: '<S201>/Switch' */

  /* Switch: '<S190>/Speed_Switch' incorporates:
   *  Abs: '<S190>/Abs'
   *  Constant: '<S198>/Constant'
   *  RelationalOperator: '<S198>/Compare'
   *  Switch: '<S190>/Angle_Switch'
   *  Trigonometry: '<S200>/Atan1'
   *  Trigonometry: '<S201>/Atan1'
   *  UnaryMinus: '<S190>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Init_e, rtb_Switch2_p)) > 1.5707963267948966) {
    rtb_Add_kz = -Code_Gen_Model_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S200>/Subtract1' incorporates:
     *  Product: '<S200>/Product2'
     *  Product: '<S200>/Product3'
     *  UnaryMinus: '<S190>/Unary Minus'
     */
    rtb_Switch2_p = (rtb_Add_cz * Code_Gen_Model_ConstB.Sin5_e) +
      (rtb_Product_do * Code_Gen_Model_ConstB.Cos5_i);

    /* Sum: '<S200>/Subtract' incorporates:
     *  Product: '<S200>/Product'
     *  Product: '<S200>/Product1'
     */
    rtb_Add_cz = (rtb_Add_cz * Code_Gen_Model_ConstB.Cos5_i) - (rtb_Product_do *
      Code_Gen_Model_ConstB.Sin5_e);

    /* Math: '<S200>/Hypot' */
    rtb_MatrixConcatenate_b_idx_0 = rt_hypotd_snf(rtb_Add_cz, rtb_Switch2_p);

    /* Switch: '<S200>/Switch1' incorporates:
     *  Constant: '<S200>/Constant'
     *  Constant: '<S200>/Constant1'
     *  Constant: '<S203>/Constant'
     *  Product: '<S200>/Divide'
     *  Product: '<S200>/Divide1'
     *  RelationalOperator: '<S203>/Compare'
     *  Switch: '<S200>/Switch'
     */
    if (rtb_MatrixConcatenate_b_idx_0 > 1.0E-6) {
      rtb_Add_cz /= rtb_MatrixConcatenate_b_idx_0;
      rtb_Switch2_p /= rtb_MatrixConcatenate_b_idx_0;
    } else {
      rtb_Add_cz = 1.0;
      rtb_Switch2_p = 0.0;
    }

    /* End of Switch: '<S200>/Switch1' */
    rtb_MatrixConcatenate_b_idx_0 = rt_atan2d_snf(rtb_Switch2_p, rtb_Add_cz);
  } else {
    rtb_Add_kz = Code_Gen_Model_B.BL_Desired_Wheel_Speed;
    rtb_MatrixConcatenate_b_idx_0 = Code_Gen_Model_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S193>/Product2' incorporates:
   *  Constant: '<S193>/Constant'
   *  Switch: '<S190>/Speed_Switch'
   */
  rtb_Init_e = rtb_Add_kz * 1530.1401357649195;

  /* Signum: '<S188>/Sign' */
  if (rtIsNaN(rtb_Init_e)) {
    rtb_Add_kz = (rtNaN);
  } else if (rtb_Init_e < 0.0) {
    rtb_Add_kz = -1.0;
  } else {
    rtb_Add_kz = (rtb_Init_e > 0.0);
  }

  /* Signum: '<S188>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Add_cz = (rtNaN);
  } else if (Code_Gen_Model_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_cz = -1.0;
  } else {
    rtb_Add_cz = (Code_Gen_Model_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S191>/Add' incorporates:
   *  Sum: '<S192>/Sum'
   */
  rtb_MatrixConcatenate_b_idx_0 -= Code_Gen_Model_B.BL_Steer_Module_Angle;

  /* Product: '<S143>/Product' incorporates:
   *  Abs: '<S188>/Abs'
   *  Abs: '<S191>/Abs'
   *  Constant: '<S194>/Constant'
   *  Constant: '<S204>/Constant3'
   *  Constant: '<S204>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S188>/OR'
   *  Lookup_n-D: '<S191>/1-D Lookup Table'
   *  Math: '<S204>/Math Function'
   *  RelationalOperator: '<S188>/Equal1'
   *  RelationalOperator: '<S194>/Compare'
   *  Signum: '<S188>/Sign'
   *  Signum: '<S188>/Sign1'
   *  Sum: '<S191>/Add'
   *  Sum: '<S204>/Add1'
   *  Sum: '<S204>/Add2'
   */
  rtb_Init_e = (((real_T)((rtb_Add_kz == rtb_Add_cz) || (fabs
    (Code_Gen_Model_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init_e) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_MatrixConcatenate_b_idx_0 + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     Code_Gen_Model_ConstP.pooled26, Code_Gen_Model_ConstP.pooled25, 1U);

  /* Gain: '<S189>/Gain' */
  rtb_Switch2_p = Drive_Motor_Control_FF * rtb_Init_e;

  /* Sum: '<S189>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Init_e -= Code_Gen_Model_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S196>/Sum1' incorporates:
   *  Constant: '<S189>/Constant2'
   *  Product: '<S196>/Product'
   *  Sum: '<S196>/Sum'
   *  UnitDelay: '<S196>/Unit Delay1'
   */
  rtb_Add_cz = ((rtb_Init_e - Code_Gen_Model_DW.UnitDelay1_DSTATE_f) *
                Drive_Motor_Control_D_FilterCoeff) +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S189>/Product' incorporates:
   *  Constant: '<S189>/Constant3'
   */
  rtb_Product_do = rtb_Add_cz * Drive_Motor_Control_D;

  /* Sum: '<S195>/Diff' incorporates:
   *  UnitDelay: '<S195>/UD'
   *
   * Block description for '<S195>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S195>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Product_do - Code_Gen_Model_DW.UD_DSTATE_lh;

  /* Saturate: '<S189>/Saturation' */
  if (rtb_Add_ec > Drive_Motor_Control_D_UL) {
    rtb_Add_ec = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_ec < Drive_Motor_Control_D_LL) {
    rtb_Add_ec = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S189>/Add' incorporates:
   *  Gain: '<S189>/Gain1'
   *  Saturate: '<S189>/Saturation'
   */
  rtb_Add_kz = ((Drive_Motor_Control_P * rtb_Init_e) + rtb_Switch2_p) +
    rtb_Add_ec;

  /* Sum: '<S189>/Subtract' incorporates:
   *  Constant: '<S189>/Constant'
   */
  rtb_Switch2_p = 1.0 - rtb_Add_kz;

  /* Sum: '<S189>/Sum2' incorporates:
   *  Gain: '<S189>/Gain2'
   *  UnitDelay: '<S189>/Unit Delay'
   */
  rtb_Init_e = (Drive_Motor_Control_I * rtb_Init_e) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_gp;

  /* Switch: '<S197>/Switch2' incorporates:
   *  Constant: '<S189>/Constant'
   *  RelationalOperator: '<S197>/LowerRelop1'
   *  Sum: '<S189>/Subtract'
   */
  if (!(rtb_Init_e > (1.0 - rtb_Add_kz))) {
    /* Sum: '<S189>/Subtract1' incorporates:
     *  Constant: '<S189>/Constant1'
     */
    rtb_Switch2_p = -1.0 - rtb_Add_kz;

    /* Switch: '<S197>/Switch' incorporates:
     *  Constant: '<S189>/Constant1'
     *  RelationalOperator: '<S197>/UpperRelop'
     *  Sum: '<S189>/Subtract1'
     */
    if (!(rtb_Init_e < (-1.0 - rtb_Add_kz))) {
      rtb_Switch2_p = rtb_Init_e;
    }

    /* End of Switch: '<S197>/Switch' */
  }

  /* End of Switch: '<S197>/Switch2' */

  /* Saturate: '<S189>/Saturation1' */
  if (rtb_Switch2_p > Drive_Motor_Control_I_UL) {
    rtb_Integral_m = Drive_Motor_Control_I_UL;
  } else if (rtb_Switch2_p < Drive_Motor_Control_I_LL) {
    rtb_Integral_m = Drive_Motor_Control_I_LL;
  } else {
    rtb_Integral_m = rtb_Switch2_p;
  }

  /* End of Saturate: '<S189>/Saturation1' */

  /* Sum: '<S189>/Add1' */
  rtb_Add_ec = rtb_Add_kz + rtb_Integral_m;

  /* Saturate: '<S189>/Saturation2' */
  if (rtb_Add_ec > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_ec < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = rtb_Add_ec;
  }

  /* End of Saturate: '<S189>/Saturation2' */

  /* Sum: '<S205>/Add1' incorporates:
   *  Constant: '<S205>/Constant3'
   *  Constant: '<S205>/Constant4'
   *  Math: '<S205>/Math Function'
   *  Sum: '<S205>/Add2'
   */
  rtb_Init_e = rt_modd_snf(rtb_MatrixConcatenate_b_idx_0 + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S207>/Sum1' incorporates:
   *  Constant: '<S192>/Constant2'
   *  Product: '<S207>/Product'
   *  Sum: '<S207>/Sum'
   *  UnitDelay: '<S207>/Unit Delay1'
   */
  rtb_MatrixConcatenate_b_idx_0 = ((rtb_Init_e -
    Code_Gen_Model_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S192>/Product' incorporates:
   *  Constant: '<S192>/Constant3'
   */
  rtb_Add_kz = rtb_MatrixConcatenate_b_idx_0 * Steering_Motor_Control_D;

  /* Sum: '<S206>/Diff' incorporates:
   *  UnitDelay: '<S206>/UD'
   *
   * Block description for '<S206>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S206>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Add_kz - Code_Gen_Model_DW.UD_DSTATE_k;

  /* Saturate: '<S192>/Saturation' */
  if (rtb_Add_ec > Steering_Motor_Control_D_UL) {
    rtb_Add_ec = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_ec < Steering_Motor_Control_D_LL) {
    rtb_Add_ec = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S192>/Add' incorporates:
   *  Gain: '<S192>/Gain1'
   *  Saturate: '<S192>/Saturation'
   */
  rtb_Add_ec += Steering_Motor_Control_P * rtb_Init_e;

  /* Sum: '<S192>/Subtract' incorporates:
   *  Constant: '<S192>/Constant'
   */
  rtb_Switch2_p = 1.0 - rtb_Add_ec;

  /* Sum: '<S192>/Sum2' incorporates:
   *  Gain: '<S192>/Gain2'
   *  UnitDelay: '<S192>/Unit Delay'
   */
  rtb_Init_e = (Steering_Motor_Control_I * rtb_Init_e) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S208>/Switch2' incorporates:
   *  Constant: '<S192>/Constant'
   *  RelationalOperator: '<S208>/LowerRelop1'
   *  Sum: '<S192>/Subtract'
   */
  if (!(rtb_Init_e > (1.0 - rtb_Add_ec))) {
    /* Sum: '<S192>/Subtract1' incorporates:
     *  Constant: '<S192>/Constant1'
     */
    rtb_Switch2_p = -1.0 - rtb_Add_ec;

    /* Switch: '<S208>/Switch' incorporates:
     *  Constant: '<S192>/Constant1'
     *  RelationalOperator: '<S208>/UpperRelop'
     *  Sum: '<S192>/Subtract1'
     */
    if (!(rtb_Init_e < (-1.0 - rtb_Add_ec))) {
      rtb_Switch2_p = rtb_Init_e;
    }

    /* End of Switch: '<S208>/Switch' */
  }

  /* End of Switch: '<S208>/Switch2' */

  /* Saturate: '<S192>/Saturation1' */
  if (rtb_Switch2_p > Steering_Motor_Control_I_UL) {
    rtb_Init_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_p < Steering_Motor_Control_I_LL) {
    rtb_Init_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Init_e = rtb_Switch2_p;
  }

  /* End of Saturate: '<S192>/Saturation1' */

  /* Sum: '<S192>/Add1' */
  rtb_Add_ec += rtb_Init_e;

  /* Saturate: '<S192>/Saturation2' */
  if (rtb_Add_ec > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_ec < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = rtb_Add_ec;
  }

  /* End of Saturate: '<S192>/Saturation2' */

  /* DiscreteIntegrator: '<S8>/Accumulator2' incorporates:
   *  Constant: '<S8>/Constant'
   */
  if ((Odometry_Reset_IC > 0.0) &&
      (Code_Gen_Model_DW.Accumulator2_PrevResetState <= 0)) {
    Code_Gen_Model_DW.Accumulator2_DSTATE = Code_Gen_Model_ConstB.Constant;
  }

  /* DiscreteIntegrator: '<S8>/Accumulator2' */
  Code_Gen_Model_B.Odom_Position_X = Code_Gen_Model_DW.Accumulator2_DSTATE;

  /* Gain: '<S73>/meters to feet' */
  Code_Gen_Model_B.Odometry_X_global_est_ft = 3.28084 *
    Code_Gen_Model_B.Odom_Position_X;

  /* RelationalOperator: '<S74>/Compare' incorporates:
   *  Constant: '<S73>/Constant'
   *  Constant: '<S74>/Constant'
   */
  rtb_Switch_b1 = (Odometry_X_Y_TEAR != 0.0);

  /* Switch: '<S73>/Switch' incorporates:
   *  UnitDelay: '<S73>/Unit Delay'
   */
  if (rtb_Switch_b1) {
    rtb_Switch2_p = Code_Gen_Model_B.Odometry_X_global_est_ft;
  } else {
    rtb_Switch2_p = Code_Gen_Model_DW.UnitDelay_DSTATE_c;
  }

  /* End of Switch: '<S73>/Switch' */

  /* Sum: '<S73>/Subtract' */
  Code_Gen_Model_B.Odometry_X_global_TEAR_ft =
    Code_Gen_Model_B.Odometry_X_global_est_ft - rtb_Switch2_p;

  /* DiscreteIntegrator: '<S8>/Accumulator' incorporates:
   *  Constant: '<S8>/Constant'
   */
  if ((Odometry_Reset_IC > 0.0) && (Code_Gen_Model_DW.Accumulator_PrevResetState
       <= 0)) {
    Code_Gen_Model_DW.Accumulator_DSTATE = Code_Gen_Model_ConstB.Constant1;
  }

  /* DiscreteIntegrator: '<S8>/Accumulator' */
  Code_Gen_Model_B.Odom_Position_Y = Code_Gen_Model_DW.Accumulator_DSTATE;

  /* Gain: '<S73>/meters to feet1' */
  Code_Gen_Model_B.Odometry_Y_global_est_ft = 3.28084 *
    Code_Gen_Model_B.Odom_Position_Y;

  /* Switch: '<S73>/Switch1' incorporates:
   *  UnitDelay: '<S73>/Unit Delay1'
   */
  if (rtb_Switch_b1) {
    rtb_Add_ec = Code_Gen_Model_B.Odometry_Y_global_est_ft;
  } else {
    rtb_Add_ec = Code_Gen_Model_DW.UnitDelay1_DSTATE_d;
  }

  /* End of Switch: '<S73>/Switch1' */

  /* Sum: '<S73>/Subtract1' */
  Code_Gen_Model_B.Odometry_Y_global_TEAR_ft =
    Code_Gen_Model_B.Odometry_Y_global_est_ft - rtb_Add_ec;

  /* Update for UnitDelay: '<S65>/UD' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Rev'
   *
   * Block description for '<S65>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE = Code_Gen_Model_U.FrontLeft_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S66>/UD' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Rev'
   *
   * Block description for '<S66>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_m = Code_Gen_Model_U.FrontRight_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S67>/UD' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Rev'
   *
   * Block description for '<S67>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_i = Code_Gen_Model_U.BackLeft_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S68>/UD' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Rev'
   *
   * Block description for '<S68>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_c = Code_Gen_Model_U.BackRight_Drive_Motor_Rev;

  /* Update for Delay: '<S14>/MemoryP' */
  Code_Gen_Model_DW.icLoad = false;
  Code_Gen_Model_DW.MemoryP_DSTATE[0] = rtb_Add1_b[0];
  Code_Gen_Model_DW.MemoryP_DSTATE[1] = rtb_Add1_b[1];
  Code_Gen_Model_DW.MemoryP_DSTATE[2] = rtb_Add1_b[2];
  Code_Gen_Model_DW.MemoryP_DSTATE[3] = rtb_Add1_b[3];

  /* Update for Delay: '<S14>/MemoryX' */
  Code_Gen_Model_DW.icLoad_i = false;

  /* Product: '<S33>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S14>/A'
   *  Delay: '<S14>/MemoryX'
   */
  tmp_0 = (0.0 * Code_Gen_Model_DW.MemoryX_DSTATE[1]) +
    Code_Gen_Model_DW.MemoryX_DSTATE[0];
  tmp_1 = (0.0 * Code_Gen_Model_DW.MemoryX_DSTATE[0]) +
    Code_Gen_Model_DW.MemoryX_DSTATE[1];

  /* Update for Delay: '<S14>/MemoryX' incorporates:
   *  Constant: '<S14>/B'
   *  Product: '<S33>/A[k]*xhat[k|k-1]'
   *  Product: '<S33>/B[k]*u[k]'
   *  Product: '<S8>/Product6'
   *  Sum: '<S33>/Add'
   */
  Code_Gen_Model_DW.MemoryX_DSTATE[0] = (((0.0 * rtb_Rotationmatrixfromlocalto_0)
    + rtb_y_l3_tmp) + tmp_0) + Code_Gen_Model_B.Product3[0];
  Code_Gen_Model_DW.MemoryX_DSTATE[1] = (((0.0 * rtb_y_l3_tmp) +
    rtb_Rotationmatrixfromlocalto_0) + tmp_1) + Code_Gen_Model_B.Product3[1];

  /* Update for UnitDelay: '<S64>/UD'
   *
   * Block description for '<S64>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_d = rtb_thetay;

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_ll =
    Code_Gen_Model_B.Robot_Reached_Destination;

  /* Update for UnitDelay: '<S241>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S241>/FixPt Constant'
   */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S255>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S254>/UD'
   *
   * Block description for '<S254>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_a = rtb_Z_idx_0;

  /* Update for UnitDelay: '<S252>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_m = rtb_Atan2_i;

  /* Update for UnitDelay: '<S250>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S250>/FixPt Constant'
   */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S217>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_k = rtb_Z_idx_2;

  /* Update for UnitDelay: '<S216>/UD'
   *
   * Block description for '<S216>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_cs = rtb_Z_idx_3;

  /* Update for UnitDelay: '<S210>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_a = rtb_Switch2_ef;

  /* Update for UnitDelay: '<S228>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_i = rtb_Magnitude;

  /* Update for UnitDelay: '<S227>/UD'
   *
   * Block description for '<S227>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_l = rtb_Steer_Joystick_X_Rel_Mod;

  /* Update for UnitDelay: '<S213>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_l = rtb_Sum2_fc;

  /* Update for UnitDelay: '<S154>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_a = rtb_Add_pw;

  /* Update for UnitDelay: '<S153>/UD'
   *
   * Block description for '<S153>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_o = rtb_Hypot_g5;

  /* Update for UnitDelay: '<S147>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_f = rtb_Subtract_i;

  /* Update for UnitDelay: '<S165>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_b = rtb_Add_c4;

  /* Update for UnitDelay: '<S164>/UD'
   *
   * Block description for '<S164>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_b = rtb_Product_dq;

  /* Update for UnitDelay: '<S150>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_e = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S175>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_b1 = rtb_Add_kl;

  /* Update for UnitDelay: '<S174>/UD'
   *
   * Block description for '<S174>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_e = rtb_Subtract_gn;

  /* Update for UnitDelay: '<S168>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_em = rtb_Hypot_b;

  /* Update for UnitDelay: '<S186>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_n = rtb_uDLookupTable_l;

  /* Update for UnitDelay: '<S185>/UD'
   *
   * Block description for '<S185>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_i1 = rtb_Add_c;

  /* Update for UnitDelay: '<S171>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_dt = rtb_Integral_kz;

  /* Update for UnitDelay: '<S196>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_f = rtb_Add_cz;

  /* Update for UnitDelay: '<S195>/UD'
   *
   * Block description for '<S195>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_lh = rtb_Product_do;

  /* Update for UnitDelay: '<S189>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_gp = rtb_Integral_m;

  /* Update for UnitDelay: '<S207>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_nw = rtb_MatrixConcatenate_b_idx_0;

  /* Update for UnitDelay: '<S206>/UD'
   *
   * Block description for '<S206>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_k = rtb_Add_kz;

  /* Update for UnitDelay: '<S192>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_k = rtb_Init_e;

  /* Update for DiscreteIntegrator: '<S8>/Accumulator2' incorporates:
   *  Constant: '<S8>/Constant'
   *  DiscreteIntegrator: '<S8>/Accumulator'
   *  Product: '<S8>/Product6'
   */
  Code_Gen_Model_DW.Accumulator2_DSTATE += rtb_y_l3_tmp;
  if (Odometry_Reset_IC > 0.0) {
    Code_Gen_Model_DW.Accumulator2_PrevResetState = 1;
    Code_Gen_Model_DW.Accumulator_PrevResetState = 1;
  } else {
    if (Odometry_Reset_IC < 0.0) {
      Code_Gen_Model_DW.Accumulator2_PrevResetState = -1;
    } else if (Odometry_Reset_IC == 0.0) {
      Code_Gen_Model_DW.Accumulator2_PrevResetState = 0;
    } else {
      Code_Gen_Model_DW.Accumulator2_PrevResetState = 2;
    }

    if (Odometry_Reset_IC < 0.0) {
      Code_Gen_Model_DW.Accumulator_PrevResetState = -1;
    } else if (Odometry_Reset_IC == 0.0) {
      Code_Gen_Model_DW.Accumulator_PrevResetState = 0;
    } else {
      Code_Gen_Model_DW.Accumulator_PrevResetState = 2;
    }
  }

  /* End of Update for DiscreteIntegrator: '<S8>/Accumulator2' */

  /* Update for UnitDelay: '<S73>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_c = rtb_Switch2_p;

  /* Update for DiscreteIntegrator: '<S8>/Accumulator' incorporates:
   *  Product: '<S8>/Product6'
   */
  Code_Gen_Model_DW.Accumulator_DSTATE += rtb_Rotationmatrixfromlocalto_0;

  /* Update for UnitDelay: '<S73>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_d = rtb_Add_ec;
}

/* Model initialize function */
void Code_Gen_Model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for SwitchCase: '<S1>/Switch Case' */
  Code_Gen_Model_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for If: '<S9>/If' */
  Code_Gen_Model_DW.If_ActiveSubsystem = -1;

  /* InitializeConditions for Delay: '<S14>/MemoryP' */
  Code_Gen_Model_DW.icLoad = true;

  /* InitializeConditions for Delay: '<S14>/MemoryX' */
  Code_Gen_Model_DW.icLoad_i = true;

  /* InitializeConditions for UnitDelay: '<S241>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S250>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S8>/Accumulator2' */
  Code_Gen_Model_DW.Accumulator2_DSTATE = Code_Gen_Model_ConstB.Constant;
  Code_Gen_Model_DW.Accumulator2_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S8>/Accumulator' */
  Code_Gen_Model_DW.Accumulator_DSTATE = Code_Gen_Model_ConstB.Constant1;
  Code_Gen_Model_DW.Accumulator_PrevResetState = 2;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S301>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S9>/Spline Path Following Enabled' */
  /* Start for If: '<S81>/If' */
  Code_Gen_Model_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S77>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S81>/Robot_Index_Is_Valid' */
  /* Start for If: '<S84>/If' */
  Code_Gen_Model_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S84>/Circle_Check_Valid' */
  /* Start for If: '<S86>/If' */
  Code_Gen_Model_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S84>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S81>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S9>/Spline Path Following Enabled' */
}

/* Model terminate function */
void Code_Gen_Model_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
