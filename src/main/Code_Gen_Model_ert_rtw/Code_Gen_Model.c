/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.34
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sun Dec 31 18:39:08 2023
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
real_T Autonomous_Desired_X = 2.5876;  /* Variable: Autonomous_Desired_X
                                        * Referenced by: '<S2>/Constant7'
                                        */
real_T Autonomous_Desired_Y = 2.4042;  /* Variable: Autonomous_Desired_Y
                                        * Referenced by: '<S2>/Constant8'
                                        */
real_T Boost_Trigger_Decreasing_Limit = -0.044444;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S301>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 3.658;/* Variable: Boost_Trigger_High_Speed
                                         * Referenced by:
                                         *   '<S299>/Constant'
                                         *   '<S299>/Saturation'
                                         */
real_T Boost_Trigger_Increasing_Limit = 0.04;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S301>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S299>/Constant1'
                                        */
real_T Distance_FL_y = 0.18732;        /* Variable: Distance_FL_y
                                        * Referenced by: '<S234>/Constant4'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S150>/Constant3'
                                        *   '<S171>/Constant3'
                                        *   '<S192>/Constant3'
                                        *   '<S213>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S150>/Constant2'
                                   *   '<S171>/Constant2'
                                   *   '<S192>/Constant2'
                                   *   '<S213>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S150>/Saturation'
                                        *   '<S171>/Saturation'
                                        *   '<S192>/Saturation'
                                        *   '<S213>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S150>/Saturation'
                                        *   '<S171>/Saturation'
                                        *   '<S192>/Saturation'
                                        *   '<S213>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00018182;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S150>/Gain'
                                            *   '<S171>/Gain'
                                            *   '<S192>/Gain'
                                            *   '<S213>/Gain'
                                            */
real_T Drive_Motor_Control_I = 0.0;    /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S150>/Gain2'
                                        *   '<S171>/Gain2'
                                        *   '<S192>/Gain2'
                                        *   '<S213>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = 0.0; /* Variable: Drive_Motor_Control_I_LL
                                        * Referenced by:
                                        *   '<S150>/Saturation1'
                                        *   '<S171>/Saturation1'
                                        *   '<S192>/Saturation1'
                                        *   '<S213>/Saturation1'
                                        */
real_T Drive_Motor_Control_I_UL = 0.0; /* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S150>/Saturation1'
                                        *   '<S171>/Saturation1'
                                        *   '<S192>/Saturation1'
                                        *   '<S213>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S150>/Gain1'
                                        *   '<S171>/Gain1'
                                        *   '<S192>/Gain1'
                                        *   '<S213>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 1500.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S155>/Constant'
                            *   '<S176>/Constant'
                            *   '<S197>/Constant'
                            *   '<S218>/Constant'
                            */
real_T KF_Vision_Ambiguity_Thresh = 0.25;/* Variable: KF_Vision_Ambiguity_Thresh
                                          * Referenced by: '<S6>/Constant'
                                          */
real_T Odometry_IC_X = 2.5876;         /* Variable: Odometry_IC_X
                                        * Referenced by: '<S1>/Constant'
                                        */
real_T Odometry_IC_Y = 2.4042;         /* Variable: Odometry_IC_Y
                                        * Referenced by: '<S1>/Constant1'
                                        */
real_T Odometry_Reset_IC = 0.0;        /* Variable: Odometry_Reset_IC
                                        * Referenced by: '<S8>/Constant'
                                        */
real_T Odometry_X_Y_TEAR = 0.0;        /* Variable: Odometry_X_Y_TEAR
                                        * Referenced by: '<S77>/Constant'
                                        */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S135>/Constant2'
                          */
real_T Spline_Max_Centripital_Acceleration = 10.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S135>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 1.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S82>/Constant'
                             */
real_T Spline_Stop_Radius = 0.1;       /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S95>/Constant'
                                        */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S135>/Constant3'
                                     */
real_T Steering_Abs_Deadband_Range = 0.7;/* Variable: Steering_Abs_Deadband_Range
                                          * Referenced by: '<S289>/Constant2'
                                          */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S255>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S255>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S255>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S255>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.1;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S254>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S255>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S255>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S255>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 1.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S255>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -1.3;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S255>/Constant1'
                                   *   '<S255>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 1.3;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S255>/Constant'
                                   *   '<S255>/Saturation2'
                                   */
real_T Steering_Localized_Cmd_Approach_Zero_Error_Thresh = 0.2;
                  /* Variable: Steering_Localized_Cmd_Approach_Zero_Error_Thresh
                   * Referenced by: '<S245>/Constant5'
                   */
real_T Steering_Localized_Cmd_Approach_Zero_Final_Thresh = 0.01;
                  /* Variable: Steering_Localized_Cmd_Approach_Zero_Final_Thresh
                   * Referenced by: '<S245>/Constant6'
                   */
real_T Steering_Localized_Cmd_NonZero_Error_Thresh = 0.2;
                        /* Variable: Steering_Localized_Cmd_NonZero_Error_Thresh
                         * Referenced by: '<S245>/Constant9'
                         */
real_T Steering_Localized_Cmd_NonZero_Final_Scale_Factor = 0.1;
                  /* Variable: Steering_Localized_Cmd_NonZero_Final_Scale_Factor
                   * Referenced by: '<S245>/Constant10'
                   */
real_T Steering_Localized_Cmd_Rate_Limit_Dec = -1.0;
                              /* Variable: Steering_Localized_Cmd_Rate_Limit_Dec
                               * Referenced by: '<S245>/Constant1'
                               */
real_T Steering_Localized_Cmd_Rate_Limit_Inc = 1.0;
                              /* Variable: Steering_Localized_Cmd_Rate_Limit_Inc
                               * Referenced by: '<S245>/Constant3'
                               */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S153>/Constant3'
                                        *   '<S174>/Constant3'
                                        *   '<S195>/Constant3'
                                        *   '<S216>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S153>/Constant2'
                                *   '<S174>/Constant2'
                                *   '<S195>/Constant2'
                                *   '<S216>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S153>/Saturation'
                                           *   '<S174>/Saturation'
                                           *   '<S195>/Saturation'
                                           *   '<S216>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S153>/Saturation'
                                          *   '<S174>/Saturation'
                                          *   '<S195>/Saturation'
                                          *   '<S216>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S153>/Gain2'
                                         *   '<S174>/Gain2'
                                         *   '<S195>/Gain2'
                                         *   '<S216>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S153>/Saturation1'
                                             *   '<S174>/Saturation1'
                                             *   '<S195>/Saturation1'
                                             *   '<S216>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S153>/Saturation1'
                                            *   '<S174>/Saturation1'
                                            *   '<S195>/Saturation1'
                                            *   '<S216>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S153>/Gain1'
                                        *   '<S174>/Gain1'
                                        *   '<S195>/Gain1'
                                        *   '<S216>/Gain1'
                                        */
real_T Steering_Relative_Gain = 1.3;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S287>/Constant'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S233>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S233>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S233>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S233>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -0.2;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S233>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 0.085714;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S233>/Constant3'
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
  real_T rtb_Add2_f[2];
  real_T rtb_Minus_n[2];
  real_T rtb_Reshapey[2];
  real_T tmp[2];
  real_T rtb_Add_c4;
  real_T rtb_Add_ie;
  real_T rtb_Add_ls;
  real_T rtb_Add_nh;
  real_T rtb_Add_pd;
  real_T rtb_Add_pw;
  real_T rtb_Hypot_b;
  real_T rtb_Hypot_g5;
  real_T rtb_Init_e;
  real_T rtb_Integral_kz;
  real_T rtb_Integral_m;
  real_T rtb_MatrixConcatenate_b_idx_1;
  real_T rtb_Merge1;
  real_T rtb_Optimized_Module_Angle;
  real_T rtb_Product_do;
  real_T rtb_Product_dq;
  real_T rtb_Rotationmatrixfromlocalto_0;
  real_T rtb_Rotationmatrixfromlocalto_1;
  real_T rtb_Rotationmatrixfromlocalto_2;
  real_T rtb_Rotationmatrixfromlocalto_3;
  real_T rtb_Steer_Joystick_X_Rel_Mod;
  real_T rtb_Subtract1_la;
  real_T rtb_Subtract_gn;
  real_T rtb_Subtract_i;
  real_T rtb_Sum2_fc;
  real_T rtb_Switch1_p2;
  real_T rtb_Switch2_ef;
  real_T rtb_Switch2_p;
  real_T rtb_thetay;
  real_T rtb_uDLookupTable_l;
  real_T tmp_0;
  real_T tmp_1;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s107_iter;
  uint16_T s132_iter;
  int8_T rtAction;
  int8_T rtPrevAction;
  boolean_T exitg1;
  boolean_T rtb_Is_Absolute_Steering;
  boolean_T rtb_Is_Absolute_Translation;
  boolean_T rtb_OR_ao;
  boolean_T rtb_Switch_b1;

  /* Sum: '<S140>/Add1' incorporates:
   *  Constant: '<S140>/Constant3'
   *  Constant: '<S140>/Constant4'
   *  Gain: '<S10>/Revolutions to Radians'
   *  Inport: '<Root>/FrontLeft_Steer_Rev'
   *  Inport: '<Root>/FrontLeft_Turn_Offset'
   *  Math: '<S140>/Math Function'
   *  Sum: '<S10>/Add'
   *  Sum: '<S140>/Add2'
   */
  Code_Gen_Model_B.FL_Steer_Module_Angle = rt_modd_snf
    (((Code_Gen_Model_U.FrontLeft_Steer_Rev -
       Code_Gen_Model_U.FrontLeft_Turn_Offset) * 6.2831853071795862) +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S8>/Product' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Rev'
   *  Sum: '<S69>/Diff'
   *  UnitDelay: '<S69>/UD'
   *
   * Block description for '<S69>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S69>/UD':
   *
   *  Store in Global RAM
   */
  rtb_thetay = (Code_Gen_Model_U.FrontLeft_Drive_Motor_Rev -
                Code_Gen_Model_DW.UD_DSTATE) * 0.037290702116950625;

  /* Sum: '<S141>/Add1' incorporates:
   *  Constant: '<S141>/Constant3'
   *  Constant: '<S141>/Constant4'
   *  Gain: '<S10>/Revolutions to Radians1'
   *  Inport: '<Root>/FrontRight_Steer_Rev'
   *  Inport: '<Root>/FrontRight_Turn_Offset'
   *  Math: '<S141>/Math Function'
   *  Sum: '<S10>/Add1'
   *  Sum: '<S141>/Add2'
   */
  Code_Gen_Model_B.FR_Steer_Module_Angle = rt_modd_snf
    (((Code_Gen_Model_U.FrontRight_Steer_Rev -
       Code_Gen_Model_U.FrontRight_Turn_Offset) * 6.2831853071795862) +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S8>/Product1' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Rev'
   *  Sum: '<S70>/Diff'
   *  UnitDelay: '<S70>/UD'
   *
   * Block description for '<S70>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S70>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Init_e = (Code_Gen_Model_U.FrontRight_Drive_Motor_Rev -
                Code_Gen_Model_DW.UD_DSTATE_m) * 0.037290702116950625;

  /* Sum: '<S142>/Add1' incorporates:
   *  Constant: '<S142>/Constant3'
   *  Constant: '<S142>/Constant4'
   *  Gain: '<S10>/Revolutions to Radians2'
   *  Inport: '<Root>/BackLeft_Steer_Rev'
   *  Inport: '<Root>/BackLeft_Turn_Offset'
   *  Math: '<S142>/Math Function'
   *  Sum: '<S10>/Add2'
   *  Sum: '<S142>/Add2'
   */
  Code_Gen_Model_B.BL_Steer_Module_Angle = rt_modd_snf
    (((Code_Gen_Model_U.BackLeft_Steer_Rev -
       Code_Gen_Model_U.BackLeft_Turn_Offset) * 6.2831853071795862) +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S8>/Product2' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Rev'
   *  Sum: '<S71>/Diff'
   *  UnitDelay: '<S71>/UD'
   *
   * Block description for '<S71>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S71>/UD':
   *
   *  Store in Global RAM
   */
  rtb_uDLookupTable_l = (Code_Gen_Model_U.BackLeft_Drive_Motor_Rev -
    Code_Gen_Model_DW.UD_DSTATE_i) * 0.037290702116950625;

  /* Sum: '<S143>/Add1' incorporates:
   *  Constant: '<S143>/Constant3'
   *  Constant: '<S143>/Constant4'
   *  Gain: '<S10>/Revolutions to Radians3'
   *  Inport: '<Root>/BackRight_Steer_Rev'
   *  Inport: '<Root>/BackRight_Turn_Offset'
   *  Math: '<S143>/Math Function'
   *  Sum: '<S10>/Add3'
   *  Sum: '<S143>/Add2'
   */
  Code_Gen_Model_B.BR_Steer_Module_Angle = rt_modd_snf
    (((Code_Gen_Model_U.BackRight_Steer_Rev -
       Code_Gen_Model_U.BackRight_Turn_Offset) * 6.2831853071795862) +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S8>/Product3' incorporates:
   *  Constant: '<S8>/Constant1'
   *  Inport: '<Root>/BackRight_Drive_Motor_Rev'
   *  Sum: '<S72>/Diff'
   *  UnitDelay: '<S72>/UD'
   *
   * Block description for '<S72>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S72>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Switch2_p = (Code_Gen_Model_U.BackRight_Drive_Motor_Rev -
                   Code_Gen_Model_DW.UD_DSTATE_c) * 0.037290702116950625;

  /* SignalConversion generated from: '<S8>/Product7' incorporates:
   *  Fcn: '<S73>/r->x'
   *  Fcn: '<S73>/theta->y'
   *  Fcn: '<S74>/r->x'
   *  Fcn: '<S74>/theta->y'
   *  Fcn: '<S75>/r->x'
   *  Fcn: '<S75>/theta->y'
   *  Fcn: '<S76>/r->x'
   *  Fcn: '<S76>/theta->y'
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

  /* Reshape: '<S14>/Reshapey' incorporates:
   *  Inport: '<Root>/Photon_Est_Pose_X'
   *  Inport: '<Root>/Photon_Est_Pose_Y'
   *  S-Function (sfix_udelay): '<S6>/Tapped Delay'
   *  S-Function (sfix_udelay): '<S6>/Tapped Delay1'
   *  Sum: '<S6>/Add'
   *  Sum: '<S6>/Add1'
   */
  rtb_Reshapey[0] = (((((Code_Gen_Model_U.Photon_Est_Pose_X +
    Code_Gen_Model_DW.TappedDelay_X[0]) + Code_Gen_Model_DW.TappedDelay_X[1]) +
                       Code_Gen_Model_DW.TappedDelay_X[2]) +
                      Code_Gen_Model_DW.TappedDelay_X[3]) +
                     Code_Gen_Model_DW.TappedDelay_X[4]) +
    Code_Gen_Model_DW.TappedDelay_X[5];
  rtb_Reshapey[1] = (((((Code_Gen_Model_U.Photon_Est_Pose_Y +
    Code_Gen_Model_DW.TappedDelay1_X[0]) + Code_Gen_Model_DW.TappedDelay1_X[1])
                       + Code_Gen_Model_DW.TappedDelay1_X[2]) +
                      Code_Gen_Model_DW.TappedDelay1_X[3]) +
                     Code_Gen_Model_DW.TappedDelay1_X[4]) +
    Code_Gen_Model_DW.TappedDelay1_X[5];

  /* Delay: '<S14>/MemoryX' incorporates:
   *  Constant: '<S14>/X0'
   */
  if (Code_Gen_Model_DW.icLoad) {
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
  rtb_Rotationmatrixfromlocalto_0 = rtb_Init_e;
  rtb_Rotationmatrixfromlocalto_1 = rtb_Switch2_p;

  /* SignalConversion generated from: '<S8>/Rotation matrix from local to global' incorporates:
   *  UnaryMinus: '<S8>/Unary Minus'
   */
  rtb_Rotationmatrixfromlocalto_2 = -rtb_Switch2_p;
  rtb_Rotationmatrixfromlocalto_3 = rtb_Init_e;

  /* Sum: '<S68>/Diff' incorporates:
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
    rtb_Add_ie = 0.0;
    rtb_Num_Segments = 0;
    for (s107_iter = 0; s107_iter < 8; s107_iter++) {
      rtb_Add_ie += Code_Gen_Model_ConstP.Constant4_Value_d[rtb_Num_Segments + i]
        * rtb_TmpSignalConversionAtProduc[s107_iter];
      rtb_Num_Segments += 2;
    }

    tmp[i] = rtb_Add_ie;
  }

  /* End of Product: '<S8>/Product7' */

  /* Product: '<S8>/Product6' incorporates:
   *  SignalConversion generated from: '<S8>/POSE exponential matrix for improved accuracy while rotating'
   *  UnaryMinus: '<S8>/Unary Minus2'
   */
  rtb_Switch1_p2 = (rtb_Switch2_p * tmp[0]) + ((-rtb_Init_e) * tmp[1]);
  rtb_Init_e = (rtb_Init_e * tmp[0]) + (rtb_Switch2_p * tmp[1]);

  /* Product: '<S8>/Product6' incorporates:
   *  Concatenate: '<S8>/Rotation matrix from local to global'
   */
  Code_Gen_Model_B.Product6[0] = (rtb_Rotationmatrixfromlocalto_0 *
    rtb_Switch1_p2) + (rtb_Rotationmatrixfromlocalto_2 * rtb_Init_e);
  Code_Gen_Model_B.Product6[1] = (rtb_Rotationmatrixfromlocalto_1 *
    rtb_Switch1_p2) + (rtb_Rotationmatrixfromlocalto_3 * rtb_Init_e);

  /* Outputs for Enabled SubSystem: '<S41>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S67>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S34>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S65>/Enable'
   */
  /* RelationalOperator: '<S6>/Relational Operator' incorporates:
   *  Constant: '<S6>/Constant'
   *  Inport: '<Root>/Photon_Est_Pose_Ambiguity'
   */
  if (Code_Gen_Model_U.Photon_Est_Pose_Ambiguity <= KF_Vision_Ambiguity_Thresh)
  {
    Code_Gen_Model_DW.MeasurementUpdate_MODE = true;

    /* Product: '<S65>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S14>/C'
     *  Delay: '<S14>/MemoryX'
     *  Product: '<S67>/Product'
     */
    rtb_Rotationmatrixfromlocalto_2 = (0.0 * Code_Gen_Model_DW.MemoryX_DSTATE[1])
      + Code_Gen_Model_DW.MemoryX_DSTATE[0];
    rtb_Minus_n[0] = rtb_Rotationmatrixfromlocalto_2;

    /* Sum: '<S65>/Sum' incorporates:
     *  Constant: '<S14>/D'
     *  Product: '<S65>/C[k]*xhat[k|k-1]'
     *  Product: '<S65>/D[k]*u[k]'
     *  Sum: '<S65>/Add1'
     */
    rtb_Rotationmatrixfromlocalto_1 = (0.0 * Code_Gen_Model_B.Product6[0]) +
      (0.0 * Code_Gen_Model_B.Product6[1]);
    rtb_Init_e = rtb_Reshapey[0] - (rtb_Rotationmatrixfromlocalto_1 +
      rtb_Rotationmatrixfromlocalto_2);

    /* Product: '<S65>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S14>/C'
     *  Delay: '<S14>/MemoryX'
     *  Product: '<S67>/Product'
     */
    rtb_Rotationmatrixfromlocalto_2 = (0.0 * Code_Gen_Model_DW.MemoryX_DSTATE[0])
      + Code_Gen_Model_DW.MemoryX_DSTATE[1];
    rtb_Minus_n[1] = rtb_Rotationmatrixfromlocalto_2;

    /* Sum: '<S65>/Sum' incorporates:
     *  Constant: '<S14>/D'
     *  Product: '<S65>/C[k]*xhat[k|k-1]'
     *  Product: '<S65>/D[k]*u[k]'
     *  Sum: '<S65>/Add1'
     */
    rtb_Rotationmatrixfromlocalto_1 = rtb_Reshapey[1] -
      (rtb_Rotationmatrixfromlocalto_1 + rtb_Rotationmatrixfromlocalto_2);
    Code_Gen_Model_DW.EnabledSubsystem_MODE = true;

    /* Product: '<S65>/Product3' incorporates:
     *  Constant: '<S15>/KalmanGainL'
     */
    Code_Gen_Model_B.Product3[0] = (0.0951249219725039 * rtb_Init_e) +
      (-2.0601714451538746E-17 * rtb_Rotationmatrixfromlocalto_1);

    /* Sum: '<S67>/Add1' incorporates:
     *  Product: '<S67>/Product'
     */
    rtb_Rotationmatrixfromlocalto_2 = rtb_Reshapey[0] - rtb_Minus_n[0];

    /* Product: '<S65>/Product3' incorporates:
     *  Constant: '<S15>/KalmanGainL'
     */
    Code_Gen_Model_B.Product3[1] = (1.304610855474728E-16 * rtb_Init_e) +
      (0.095124921972504 * rtb_Rotationmatrixfromlocalto_1);

    /* Sum: '<S67>/Add1' incorporates:
     *  Product: '<S67>/Product'
     */
    rtb_Rotationmatrixfromlocalto_1 = rtb_Reshapey[1] - rtb_Minus_n[1];

    /* Product: '<S67>/Product2' incorporates:
     *  Constant: '<S15>/KalmanGainM'
     */
    Code_Gen_Model_B.Product2[0] = (0.09512492197250387 *
      rtb_Rotationmatrixfromlocalto_2) + (5.9896845167210271E-17 *
      rtb_Rotationmatrixfromlocalto_1);
    Code_Gen_Model_B.Product2[1] = (5.9896845167210271E-17 *
      rtb_Rotationmatrixfromlocalto_2) + (0.095124921972503981 *
      rtb_Rotationmatrixfromlocalto_1);
  } else {
    if (Code_Gen_Model_DW.MeasurementUpdate_MODE) {
      /* Disable for Product: '<S65>/Product3' incorporates:
       *  Outport: '<S65>/L*(y[k]-yhat[k|k-1])'
       */
      Code_Gen_Model_B.Product3[0] = 0.0;
      Code_Gen_Model_B.Product3[1] = 0.0;
      Code_Gen_Model_DW.MeasurementUpdate_MODE = false;
    }

    if (Code_Gen_Model_DW.EnabledSubsystem_MODE) {
      /* Disable for Product: '<S67>/Product2' incorporates:
       *  Outport: '<S67>/deltax'
       */
      Code_Gen_Model_B.Product2[0] = 0.0;
      Code_Gen_Model_B.Product2[1] = 0.0;
      Code_Gen_Model_DW.EnabledSubsystem_MODE = false;
    }
  }

  /* End of RelationalOperator: '<S6>/Relational Operator' */
  /* End of Outputs for SubSystem: '<S34>/MeasurementUpdate' */
  /* End of Outputs for SubSystem: '<S41>/Enabled Subsystem' */

  /* Sum: '<S41>/Add' incorporates:
   *  Delay: '<S14>/MemoryX'
   */
  rtb_Reshapey[0] = Code_Gen_Model_B.Product2[0] +
    Code_Gen_Model_DW.MemoryX_DSTATE[0];
  rtb_Reshapey[1] = Code_Gen_Model_B.Product2[1] +
    Code_Gen_Model_DW.MemoryX_DSTATE[1];

  /* SignalConversion: '<S6>/Signal Copy' */
  Code_Gen_Model_B.KF_Position_X = rtb_Reshapey[0];

  /* SignalConversion: '<S6>/Signal Copy1' */
  Code_Gen_Model_B.KF_Position_Y = rtb_Reshapey[1];

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtPrevAction = Code_Gen_Model_DW.SwitchCase_ActiveSubsystem;
  rtb_Add_ie = trunc(Code_Gen_Model_U.GameState);
  if ((rtIsNaN(rtb_Add_ie)) || (rtIsInf(rtb_Add_ie))) {
    rtb_Add_ie = 0.0;
  } else {
    rtb_Add_ie = fmod(rtb_Add_ie, 4.294967296E+9);
  }

  switch ((rtb_Add_ie < 0.0) ? (-((int32_T)((uint32_T)(-rtb_Add_ie)))) :
          ((int32_T)((uint32_T)rtb_Add_ie))) {
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
    Code_Gen_Model_Disabled(&rtb_Rotationmatrixfromlocalto_1,
      &Code_Gen_Model_B.Steering_Abs_Cmd, &Code_Gen_Model_B.Steering_Rel_Cmd,
      &Code_Gen_Model_B.Translation_Angle, &Code_Gen_Model_B.Translation_Speed,
      &rtb_Is_Absolute_Translation, &rtb_Is_Absolute_Steering,
      &Code_Gen_Model_B.Spline_Enable, rtb_Spline_Ref_Poses,
      &Code_Gen_Model_B.Spline_Num_Poses);

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
    rtb_Rotationmatrixfromlocalto_1 = 0.0;

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
    rtb_Rotationmatrixfromlocalto_2 = Autonomous_Desired_Y -
      Code_Gen_Model_B.KF_Position_Y;

    /* Sum: '<S2>/Subtract1' incorporates:
     *  Constant: '<S2>/Constant7'
     */
    rtb_Init_e = Autonomous_Desired_X - Code_Gen_Model_B.KF_Position_X;

    /* Merge: '<S7>/Merge4' incorporates:
     *  Constant: '<S2>/Constant'
     *  Math: '<S2>/Hypot'
     *  MinMax: '<S2>/Min'
     *  SignalConversion: '<S2>/Signal Copy3'
     */
    Code_Gen_Model_B.Translation_Speed = fmin(rt_hypotd_snf
      (rtb_Rotationmatrixfromlocalto_2, rtb_Init_e), 1.0);

    /* Merge: '<S7>/Merge3' incorporates:
     *  SignalConversion: '<S2>/Signal Copy1'
     *  Trigonometry: '<S2>/Atan2'
     */
    Code_Gen_Model_B.Translation_Angle = rt_atan2d_snf
      (rtb_Rotationmatrixfromlocalto_2, rtb_Init_e);

    /* SignalConversion generated from: '<S2>/Is_Absolute_Translation' incorporates:
     *  Constant: '<S2>/Constant5'
     */
    rtb_Is_Absolute_Translation = true;

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
      rtb_Rotationmatrixfromlocalto_2 = 0.0;
    } else {
      rtb_Rotationmatrixfromlocalto_2 = Code_Gen_Model_DW.UnitDelay_DSTATE_l1 +
        0.02;
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
      (!(rtb_Rotationmatrixfromlocalto_2 < 1.0)));

    /* Merge: '<S7>/Merge9' incorporates:
     *  Constant: '<S2>/Constant9'
     *  SignalConversion generated from: '<S2>/Spline_Num_Poses'
     */
    Code_Gen_Model_B.Spline_Num_Poses = 19.0;

    /* Update for UnitDelay: '<S2>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_l1 = rtb_Rotationmatrixfromlocalto_2;

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

    /* Switch: '<S289>/Switch1' incorporates:
     *  Constant: '<S289>/Constant'
     *  Constant: '<S289>/Constant1'
     *  Constant: '<S289>/Constant2'
     *  Inport: '<Root>/Steer_Joystick_X'
     *  Inport: '<Root>/Steer_Joystick_Y'
     *  Math: '<S289>/Hypot'
     *  RelationalOperator: '<S289>/GreaterThan'
     *  Switch: '<S289>/Switch'
     */
    if (rt_hypotd_snf(Code_Gen_Model_U.Steer_Joystick_X,
                      Code_Gen_Model_U.Steer_Joystick_Y) >
        Steering_Abs_Deadband_Range) {
      rtb_Rotationmatrixfromlocalto_1 = Code_Gen_Model_U.Steer_Joystick_Y;
      rtb_Rotationmatrixfromlocalto_2 = Code_Gen_Model_U.Steer_Joystick_X;
    } else {
      rtb_Rotationmatrixfromlocalto_1 = 0.0;
      rtb_Rotationmatrixfromlocalto_2 = 0.0;
    }

    /* End of Switch: '<S289>/Switch1' */

    /* Switch: '<S291>/Switch1' incorporates:
     *  Constant: '<S297>/Constant'
     *  Constant: '<S298>/Constant'
     *  Logic: '<S291>/AND'
     *  RelationalOperator: '<S297>/Compare'
     *  RelationalOperator: '<S298>/Compare'
     *  Switch: '<S291>/Switch2'
     *  UnitDelay: '<S291>/Unit Delay'
     *  UnitDelay: '<S291>/Unit Delay1'
     */
    if ((rtb_Rotationmatrixfromlocalto_2 == 0.0) &&
        (rtb_Rotationmatrixfromlocalto_1 == 0.0)) {
      rtb_Init_e = Code_Gen_Model_DW.UnitDelay1_DSTATE_d2;
      rtb_Rotationmatrixfromlocalto_3 = Code_Gen_Model_DW.UnitDelay_DSTATE_g4;
    } else {
      rtb_Init_e = rtb_Rotationmatrixfromlocalto_1;
      rtb_Rotationmatrixfromlocalto_3 = rtb_Rotationmatrixfromlocalto_2;
    }

    /* End of Switch: '<S291>/Switch1' */

    /* Merge: '<S7>/Merge1' incorporates:
     *  Trigonometry: '<S287>/Atan2'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd = rt_atan2d_snf(rtb_Init_e,
      rtb_Rotationmatrixfromlocalto_3);

    /* RelationalOperator: '<S294>/Compare' incorporates:
     *  Constant: '<S294>/Constant'
     */
    rtb_Is_Absolute_Translation = (rtb_Rotationmatrixfromlocalto_3 < 0.0);

    /* Switch: '<S290>/Switch' incorporates:
     *  Constant: '<S290>/Constant'
     *  Constant: '<S290>/Constant1'
     *  Constant: '<S292>/Constant'
     *  Constant: '<S293>/Constant'
     *  Logic: '<S290>/Logical Operator'
     *  RelationalOperator: '<S292>/Compare'
     *  RelationalOperator: '<S293>/Compare'
     *  UnitDelay: '<S290>/Unit Delay'
     */
    if (((rtb_Init_e < 0.0) && (Code_Gen_Model_DW.UnitDelay_DSTATE_h >= 0.0)) &&
        rtb_Is_Absolute_Translation) {
      rtb_Add_ie = 6.2831853071795862;
    } else {
      rtb_Add_ie = 0.0;
    }

    /* Switch: '<S290>/Switch1' incorporates:
     *  Constant: '<S290>/Constant2'
     *  Constant: '<S290>/Constant3'
     *  Constant: '<S295>/Constant'
     *  Constant: '<S296>/Constant'
     *  Logic: '<S290>/Logical Operator1'
     *  RelationalOperator: '<S295>/Compare'
     *  RelationalOperator: '<S296>/Compare'
     *  UnitDelay: '<S290>/Unit Delay'
     */
    if (((Code_Gen_Model_DW.UnitDelay_DSTATE_h < 0.0) && (rtb_Init_e >= 0.0)) &&
        rtb_Is_Absolute_Translation) {
      rtb_Product_do = -6.2831853071795862;
    } else {
      rtb_Product_do = 0.0;
    }

    /* Sum: '<S290>/Sum1' incorporates:
     *  Switch: '<S290>/Switch'
     *  Switch: '<S290>/Switch1'
     *  UnitDelay: '<S290>/Unit Delay1'
     */
    rtb_Rotationmatrixfromlocalto_1 = (rtb_Add_ie + rtb_Product_do) +
      Code_Gen_Model_DW.UnitDelay1_DSTATE_kr;

    /* Lookup_n-D: '<S288>/Modulation_Drv_X' incorporates:
     *  Inport: '<Root>/Drive_Joystick_X'
     */
    rtb_Steer_Joystick_X_Rel_Mod = look1_binlcpw
      (Code_Gen_Model_U.Drive_Joystick_X, Code_Gen_Model_ConstP.pooled19,
       Code_Gen_Model_ConstP.pooled18, 20U);

    /* Lookup_n-D: '<S288>/Modulation_Drv_Y' incorporates:
     *  Inport: '<Root>/Drive_Joystick_Y'
     */
    rtb_Rotationmatrixfromlocalto_2 = look1_binlcpw
      (Code_Gen_Model_U.Drive_Joystick_Y, Code_Gen_Model_ConstP.pooled19,
       Code_Gen_Model_ConstP.pooled18, 20U);

    /* Switch: '<S300>/Switch1' incorporates:
     *  Constant: '<S305>/Constant'
     *  Constant: '<S306>/Constant'
     *  Logic: '<S300>/AND'
     *  RelationalOperator: '<S305>/Compare'
     *  RelationalOperator: '<S306>/Compare'
     *  Switch: '<S300>/Switch2'
     *  UnitDelay: '<S300>/Unit Delay'
     *  UnitDelay: '<S300>/Unit Delay1'
     */
    if ((rtb_Steer_Joystick_X_Rel_Mod == 0.0) &&
        (rtb_Rotationmatrixfromlocalto_2 == 0.0)) {
      rtb_Switch1_p2 = Code_Gen_Model_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2_ef = Code_Gen_Model_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1_p2 = rtb_Rotationmatrixfromlocalto_2;
      rtb_Switch2_ef = rtb_Steer_Joystick_X_Rel_Mod;
    }

    /* End of Switch: '<S300>/Switch1' */

    /* Merge: '<S7>/Merge3' incorporates:
     *  Trigonometry: '<S288>/Atan2'
     */
    Code_Gen_Model_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1_p2,
      rtb_Switch2_ef);

    /* Math: '<S288>/Magnitude' */
    rtb_Rotationmatrixfromlocalto_0 = rt_hypotd_snf(rtb_Steer_Joystick_X_Rel_Mod,
      rtb_Rotationmatrixfromlocalto_2);

    /* Switch: '<S299>/Switch1' incorporates:
     *  Constant: '<S299>/Constant'
     *  Constant: '<S299>/Constant1'
     *  Inport: '<Root>/Is_Boost_Trigger_Pulled'
     */
    if (Code_Gen_Model_U.Is_Boost_Trigger_Pulled != 0.0) {
      rtb_Steer_Joystick_X_Rel_Mod = Boost_Trigger_High_Speed;
    } else {
      rtb_Steer_Joystick_X_Rel_Mod = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S299>/Switch1' */

    /* Switch: '<S304>/Init' incorporates:
     *  UnitDelay: '<S304>/FixPt Unit Delay1'
     *  UnitDelay: '<S304>/FixPt Unit Delay2'
     */
    if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Rotationmatrixfromlocalto_2 = rtb_Steer_Joystick_X_Rel_Mod;
    } else {
      rtb_Rotationmatrixfromlocalto_2 =
        Code_Gen_Model_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S304>/Init' */

    /* Sum: '<S302>/Sum1' */
    rtb_Steer_Joystick_X_Rel_Mod -= rtb_Rotationmatrixfromlocalto_2;

    /* Switch: '<S303>/Switch2' incorporates:
     *  Constant: '<S301>/Constant1'
     *  Constant: '<S301>/Constant3'
     *  RelationalOperator: '<S303>/LowerRelop1'
     *  RelationalOperator: '<S303>/UpperRelop'
     *  Switch: '<S303>/Switch'
     */
    if (rtb_Steer_Joystick_X_Rel_Mod > Boost_Trigger_Increasing_Limit) {
      rtb_Steer_Joystick_X_Rel_Mod = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Steer_Joystick_X_Rel_Mod < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S303>/Switch' incorporates:
       *  Constant: '<S301>/Constant1'
       */
      rtb_Steer_Joystick_X_Rel_Mod = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S303>/Switch2' */

    /* Sum: '<S302>/Sum' */
    rtb_Rotationmatrixfromlocalto_2 += rtb_Steer_Joystick_X_Rel_Mod;

    /* Product: '<S299>/Product' */
    rtb_Add_ls = rtb_Rotationmatrixfromlocalto_0 *
      rtb_Rotationmatrixfromlocalto_2;

    /* Saturate: '<S299>/Saturation' */
    if (rtb_Add_ls > Boost_Trigger_High_Speed) {
      /* Merge: '<S7>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = Boost_Trigger_High_Speed;
    } else if (rtb_Add_ls < (-Boost_Trigger_High_Speed)) {
      /* Merge: '<S7>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = -Boost_Trigger_High_Speed;
    } else {
      /* Merge: '<S7>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = rtb_Add_ls;
    }

    /* End of Saturate: '<S299>/Saturation' */

    /* Merge: '<S7>/Merge7' incorporates:
     *  Constant: '<S12>/Constant3'
     *  SignalConversion generated from: '<S12>/Spline_Enable'
     */
    Code_Gen_Model_B.Spline_Enable = false;

    /* Merge: '<S7>/Merge2' incorporates:
     *  Constant: '<S287>/Constant'
     *  Inport: '<Root>/Steer_Joystick_Y'
     *  Lookup_n-D: '<S287>/Modulation_Str_X_Rel'
     *  Product: '<S287>/Product'
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
    rtb_Is_Absolute_Translation = Code_Gen_Model_U.Is_Absolute_Translation;

    /* SignalConversion generated from: '<S12>/Is_Absolute_Steering_In' incorporates:
     *  Inport: '<Root>/Is_Absolute_Steering'
     */
    rtb_Is_Absolute_Steering = Code_Gen_Model_U.Is_Absolute_Steering;

    /* Update for UnitDelay: '<S291>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_d2 = rtb_Init_e;

    /* Update for UnitDelay: '<S291>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_g4 = rtb_Rotationmatrixfromlocalto_3;

    /* Update for UnitDelay: '<S290>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_h = rtb_Init_e;

    /* Update for UnitDelay: '<S290>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_kr = rtb_Rotationmatrixfromlocalto_1;

    /* Update for UnitDelay: '<S300>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_l = rtb_Switch1_p2;

    /* Update for UnitDelay: '<S300>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_p = rtb_Switch2_ef;

    /* Update for UnitDelay: '<S304>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S304>/FixPt Constant'
     */
    Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S304>/FixPt Unit Delay1' */
    Code_Gen_Model_DW.FixPtUnitDelay1_DSTATE_f = rtb_Rotationmatrixfromlocalto_2;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S13>/Action Port'
     */
    Code_Gen_Model_Disabled(&rtb_Rotationmatrixfromlocalto_1,
      &Code_Gen_Model_B.Steering_Abs_Cmd, &Code_Gen_Model_B.Steering_Rel_Cmd,
      &Code_Gen_Model_B.Translation_Angle, &Code_Gen_Model_B.Translation_Speed,
      &rtb_Is_Absolute_Translation, &rtb_Is_Absolute_Steering,
      &Code_Gen_Model_B.Spline_Enable, rtb_Spline_Ref_Poses,
      &Code_Gen_Model_B.Spline_Num_Poses);

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* If: '<S9>/If' incorporates:
   *  Constant: '<S132>/Constant'
   *  Logic: '<S132>/AND'
   *  MATLAB Function: '<S82>/Find closest index to curve'
   *  Product: '<S132>/Product'
   *  RelationalOperator: '<S132>/Relational Operator'
   *  RelationalOperator: '<S132>/Relational Operator1'
   *  Selector: '<S132>/Selector'
   *  Selector: '<S132>/Selector1'
   *  Selector: '<S133>/Selector'
   *  Sum: '<S132>/Add'
   */
  rtPrevAction = Code_Gen_Model_DW.If_ActiveSubsystem;
  rtAction = (int8_T)(!Code_Gen_Model_B.Spline_Enable);
  Code_Gen_Model_DW.If_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S85>/If' */
    if (Code_Gen_Model_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S88>/If' */
      if (Code_Gen_Model_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S90>/If' */
        Code_Gen_Model_DW.If_ActiveSubsystem_d = -1;
      }

      Code_Gen_Model_DW.If_ActiveSubsystem_o = -1;
    }

    Code_Gen_Model_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S85>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S9>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S80>/Action Port'
       */
      /* InitializeConditions for If: '<S9>/If' incorporates:
       *  UnitDelay: '<S133>/Unit Delay'
       *  UnitDelay: '<S133>/Unit Delay1'
       *  UnitDelay: '<S80>/Unit Delay'
       *  UnitDelay: '<S81>/Unit Delay'
       *  UnitDelay: '<S83>/Unit Delay'
       *  UnitDelay: '<S83>/Unit Delay1'
       */
      Code_Gen_Model_DW.UnitDelay_DSTATE_gh = 2.0;
      Code_Gen_Model_DW.UnitDelay_DSTATE_hn = 0.0;
      Code_Gen_Model_DW.UnitDelay1_DSTATE_f4 = 0.0;
      Code_Gen_Model_DW.UnitDelay_DSTATE_g4g = 0.0;
      Code_Gen_Model_DW.UnitDelay_DSTATE_le = 0.0;
      Code_Gen_Model_DW.UnitDelay1_DSTATE_kc = 0.0;

      /* End of InitializeConditions for SubSystem: '<S9>/Spline Path Following Enabled' */
    }

    /* Outputs for IfAction SubSystem: '<S9>/Spline Path Following Enabled' incorporates:
     *  ActionPort: '<S80>/Action Port'
     */
    /* Selector: '<S81>/Selector1' incorporates:
     *  Merge: '<S7>/Merge8'
     */
    for (i = 0; i < 19; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses[i];
      rtb_Ref_Poses[i + 19] = rtb_Spline_Ref_Poses[i + 19];
    }

    /* End of Selector: '<S81>/Selector1' */

    /* Lookup_n-D: '<S80>/Capture Radius' incorporates:
     *  UnitDelay: '<S80>/Unit Delay'
     */
    rtb_Rotationmatrixfromlocalto_1 = look1_binlcpw
      (Code_Gen_Model_DW.UnitDelay_DSTATE_hn, Code_Gen_Model_ConstP.pooled9,
       Code_Gen_Model_ConstP.CaptureRadius_tableData, 3U);

    /* SignalConversion generated from: '<S81>/Matrix Concatenate2' */
    rtb_Reshapey[0] = Code_Gen_Model_B.KF_Position_X;

    /* SignalConversion generated from: '<S81>/Matrix Concatenate2' */
    rtb_Reshapey[1] = Code_Gen_Model_B.KF_Position_Y;

    /* If: '<S85>/If' incorporates:
     *  RelationalOperator: '<S85>/ '
     *  UnitDelay: '<S81>/Unit Delay'
     */
    rtPrevAction = Code_Gen_Model_DW.If_ActiveSubsystem_h;
    rtAction = (int8_T)(!(Code_Gen_Model_DW.UnitDelay_DSTATE_gh <=
                          Code_Gen_Model_B.Spline_Num_Poses));
    Code_Gen_Model_DW.If_ActiveSubsystem_h = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for If: '<S88>/If' */
      if (Code_Gen_Model_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S90>/If' */
        Code_Gen_Model_DW.If_ActiveSubsystem_d = -1;
      }

      Code_Gen_Model_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S85>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S88>/Action Port'
       */
      /* InitializeConditions for If: '<S85>/If' incorporates:
       *  UnitDelay: '<S88>/Unit Delay'
       */
      Code_Gen_Model_DW.UnitDelay_DSTATE_e4 = ((rtPrevAction == 0) &&
        (Code_Gen_Model_DW.UnitDelay_DSTATE_e4));

      /* End of InitializeConditions for SubSystem: '<S85>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S85>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S88>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S88>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S91>/Action Port'
       */
      /* If: '<S88>/If' incorporates:
       *  Selector: '<S81>/Selector1'
       *  Selector: '<S88>/Selector'
       *  Selector: '<S91>/Selector'
       */
      rtb_Optimized_Module_Angle = rtb_Ref_Poses[((int32_T)
        Code_Gen_Model_DW.UnitDelay_DSTATE_gh) - 1];

      /* End of Outputs for SubSystem: '<S88>/Increment_If_Rectangle_Check' */

      /* Sum: '<S88>/Minus' incorporates:
       *  Concatenate: '<S81>/Matrix Concatenate2'
       *  Selector: '<S88>/Selector'
       */
      rtb_Minus_n[0] = rtb_Reshapey[0] - rtb_Optimized_Module_Angle;

      /* Outputs for IfAction SubSystem: '<S88>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S91>/Action Port'
       */
      /* If: '<S88>/If' incorporates:
       *  Selector: '<S81>/Selector1'
       *  Selector: '<S88>/Selector'
       *  Selector: '<S91>/Selector'
       *  Sum: '<S88>/Minus'
       */
      rtb_Rotationmatrixfromlocalto_3 = rtb_Ref_Poses[((int32_T)
        Code_Gen_Model_DW.UnitDelay_DSTATE_gh) + 18];

      /* End of Outputs for SubSystem: '<S88>/Increment_If_Rectangle_Check' */

      /* Sum: '<S88>/Minus' incorporates:
       *  Concatenate: '<S81>/Matrix Concatenate2'
       *  Selector: '<S88>/Selector'
       */
      rtb_Minus_n[1] = rtb_Reshapey[1] - rtb_Rotationmatrixfromlocalto_3;

      /* Math: '<S88>/Hypot' */
      rtb_Rotationmatrixfromlocalto_2 = rt_hypotd_snf(rtb_Minus_n[0],
        rtb_Minus_n[1]);

      /* RelationalOperator: '<S88>/Equal' */
      rtb_Is_Absolute_Steering = (Code_Gen_Model_B.Spline_Num_Poses ==
        Code_Gen_Model_DW.UnitDelay_DSTATE_gh);

      /* Switch: '<S88>/Switch' incorporates:
       *  Logic: '<S88>/AND'
       *  Logic: '<S88>/OR'
       *  RelationalOperator: '<S88>/Relational Operator'
       *  UnitDelay: '<S88>/Unit Delay'
       */
      rtb_Is_Absolute_Translation = ((Code_Gen_Model_DW.UnitDelay_DSTATE_e4) ||
        ((rtb_Rotationmatrixfromlocalto_2 <= rtb_Rotationmatrixfromlocalto_1) &&
         rtb_Is_Absolute_Steering));

      /* If: '<S88>/If' */
      rtPrevAction = Code_Gen_Model_DW.If_ActiveSubsystem_o;
      if (!rtb_Is_Absolute_Translation) {
        if (!rtb_Is_Absolute_Steering) {
          rtAction = 1;
        } else {
          rtAction = 2;
        }
      }

      Code_Gen_Model_DW.If_ActiveSubsystem_o = rtAction;
      if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
        /* Disable for If: '<S90>/If' */
        Code_Gen_Model_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S88>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S90>/Action Port'
         */
        /* If: '<S90>/If' incorporates:
         *  RelationalOperator: '<S90>/Equal'
         */
        rtPrevAction = Code_Gen_Model_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)(!(Code_Gen_Model_DW.UnitDelay_DSTATE_gh ==
                              Code_Gen_Model_B.Spline_Num_Poses));
        Code_Gen_Model_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S90>/Is_Last_Point' incorporates:
           *  ActionPort: '<S93>/Action Port'
           */
          /* InitializeConditions for If: '<S90>/If' incorporates:
           *  UnitDelay: '<S93>/Unit Delay'
           */
          Code_Gen_Model_DW.UnitDelay_DSTATE_n = ((rtPrevAction == 0) &&
            (Code_Gen_Model_DW.UnitDelay_DSTATE_n));

          /* End of InitializeConditions for SubSystem: '<S90>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S90>/Is_Last_Point' incorporates:
           *  ActionPort: '<S93>/Action Port'
           */
          /* Switch: '<S93>/Switch' incorporates:
           *  Constant: '<S95>/Constant'
           *  Logic: '<S93>/OR'
           *  RelationalOperator: '<S95>/Compare'
           *  UnitDelay: '<S93>/Unit Delay'
           */
          rtb_Switch_b1 = ((Code_Gen_Model_DW.UnitDelay_DSTATE_n) ||
                           (rtb_Rotationmatrixfromlocalto_2 <=
                            Spline_Stop_Radius));

          /* If: '<S93>/If' */
          if (rtb_Switch_b1) {
            /* Outputs for IfAction SubSystem: '<S93>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S96>/Action Port'
             */
            /* Merge: '<S85>/Merge2' incorporates:
             *  Constant: '<S96>/Constant'
             *  SignalConversion generated from: '<S96>/Robot_Reached_Destination'
             */
            rtb_Is_Absolute_Steering = true;

            /* SignalConversion generated from: '<S96>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S96>/Constant1'
             */
            rtb_OR_ao = false;

            /* End of Outputs for SubSystem: '<S93>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S93>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S97>/Action Port'
             */
            /* Merge: '<S85>/Merge2' incorporates:
             *  Constant: '<S97>/Constant'
             *  SignalConversion generated from: '<S97>/Robot_Reached_Destination'
             */
            rtb_Is_Absolute_Steering = false;

            /* SignalConversion generated from: '<S97>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S97>/Constant1'
             */
            rtb_OR_ao = true;

            /* End of Outputs for SubSystem: '<S93>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S93>/If' */

          /* Merge: '<S85>/Merge4' incorporates:
           *  SignalConversion: '<S93>/Signal Copy'
           */
          Code_Gen_Model_B.Spline_Index = Code_Gen_Model_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S93>/Unit Delay' */
          Code_Gen_Model_DW.UnitDelay_DSTATE_n = rtb_Switch_b1;

          /* End of Outputs for SubSystem: '<S90>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S90>/Increment_Search' incorporates:
           *  ActionPort: '<S92>/Action Port'
           */
          /* Merge: '<S85>/Merge2' incorporates:
           *  Constant: '<S92>/Constant'
           *  SignalConversion generated from: '<S92>/Robot_Reached_Destination'
           */
          rtb_Is_Absolute_Steering = false;

          /* SignalConversion generated from: '<S92>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S92>/Constant1'
           */
          rtb_OR_ao = false;

          /* Merge: '<S85>/Merge4' incorporates:
           *  Constant: '<S94>/FixPt Constant'
           *  SignalConversion: '<S92>/Signal Copy'
           *  Sum: '<S94>/FixPt Sum1'
           */
          Code_Gen_Model_B.Spline_Index = Code_Gen_Model_DW.UnitDelay_DSTATE_gh
            + 1.0;

          /* End of Outputs for SubSystem: '<S90>/Increment_Search' */
        }

        /* End of If: '<S90>/If' */
        /* End of Outputs for SubSystem: '<S88>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S88>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S91>/Action Port'
         */
        /* Sum: '<S98>/FixPt Sum1' incorporates:
         *  Constant: '<S98>/FixPt Constant'
         */
        rtb_Rotationmatrixfromlocalto_2 = Code_Gen_Model_DW.UnitDelay_DSTATE_gh
          + 1.0;

        /* Selector: '<S91>/Selector1' incorporates:
         *  Selector: '<S81>/Selector1'
         */
        rtb_Switch2_ef = rtb_Ref_Poses[((int32_T)rtb_Rotationmatrixfromlocalto_2)
          - 1];

        /* Sum: '<S99>/Subtract' incorporates:
         *  Selector: '<S91>/Selector1'
         *  Sum: '<S99>/Minus1'
         */
        rtb_Minus_n[0] = rtb_Switch2_ef - rtb_Optimized_Module_Angle;

        /* Selector: '<S91>/Selector1' incorporates:
         *  Selector: '<S81>/Selector1'
         */
        rtb_Switch1_p2 = rtb_Ref_Poses[((int32_T)rtb_Rotationmatrixfromlocalto_2)
          + 18];

        /* Sum: '<S99>/Subtract' incorporates:
         *  Selector: '<S91>/Selector1'
         *  Sum: '<S99>/Minus1'
         */
        rtb_Minus_n[1] = rtb_Switch1_p2 - rtb_Rotationmatrixfromlocalto_3;

        /* Math: '<S99>/Hypot' */
        rtb_Init_e = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

        /* Product: '<S99>/Divide' */
        rtb_Rotationmatrixfromlocalto_2 = rtb_Minus_n[1];

        /* UnaryMinus: '<S99>/Unary Minus' */
        rtb_Switch2_p = rtb_Minus_n[0];

        /* Product: '<S99>/Product' incorporates:
         *  Product: '<S99>/Divide'
         *  UnaryMinus: '<S99>/Unary Minus'
         */
        rtb_Minus_n[0] = (rtb_Rotationmatrixfromlocalto_2 / rtb_Init_e) *
          rtb_Rotationmatrixfromlocalto_1;
        rtb_Minus_n[1] = ((-rtb_Switch2_p) / rtb_Init_e) *
          rtb_Rotationmatrixfromlocalto_1;

        /* Sum: '<S99>/Add1' incorporates:
         *  Sum: '<S99>/Add2'
         *  Sum: '<S99>/Minus'
         */
        rtb_Switch2_p = rtb_Switch2_ef - rtb_Minus_n[0];

        /* Sum: '<S99>/Minus4' incorporates:
         *  Sum: '<S99>/Add2'
         *  Sum: '<S99>/Minus'
         */
        rtb_Switch2_ef = (rtb_Switch2_ef + rtb_Minus_n[0]) - rtb_Switch2_p;

        /* Sum: '<S99>/Minus5' incorporates:
         *  Concatenate: '<S81>/Matrix Concatenate2'
         *  Sum: '<S99>/Minus'
         */
        rtb_Rotationmatrixfromlocalto_0 = rtb_Reshapey[0] - rtb_Switch2_p;

        /* Sum: '<S99>/Add' incorporates:
         *  Sum: '<S99>/Add2'
         *  Sum: '<S99>/Minus1'
         */
        rtb_Rotationmatrixfromlocalto_2 = rtb_Optimized_Module_Angle -
          rtb_Minus_n[0];

        /* Sum: '<S99>/Minus' incorporates:
         *  Sum: '<S99>/Minus1'
         */
        rtb_Switch2_p -= rtb_Rotationmatrixfromlocalto_2;

        /* DotProduct: '<S99>/Dot Product' incorporates:
         *  Concatenate: '<S81>/Matrix Concatenate2'
         *  Sum: '<S99>/Minus'
         *  Sum: '<S99>/Minus1'
         *  Sum: '<S99>/Minus5'
         */
        rtb_Init_e = (rtb_Reshapey[0] - rtb_Rotationmatrixfromlocalto_2) *
          rtb_Switch2_p;

        /* DotProduct: '<S99>/Dot Product1' incorporates:
         *  Sum: '<S99>/Minus'
         */
        rtb_Optimized_Module_Angle = rtb_Switch2_p * rtb_Switch2_p;

        /* DotProduct: '<S99>/Dot Product2' incorporates:
         *  Sum: '<S99>/Minus4'
         *  Sum: '<S99>/Minus5'
         */
        rtb_Steer_Joystick_X_Rel_Mod = rtb_Switch2_ef *
          rtb_Rotationmatrixfromlocalto_0;

        /* DotProduct: '<S99>/Dot Product3' incorporates:
         *  Sum: '<S99>/Minus4'
         */
        rtb_MatrixConcatenate_b_idx_1 = rtb_Switch2_ef * rtb_Switch2_ef;

        /* Sum: '<S99>/Add1' incorporates:
         *  Sum: '<S99>/Add2'
         *  Sum: '<S99>/Minus'
         */
        rtb_Switch2_p = rtb_Switch1_p2 - rtb_Minus_n[1];

        /* Sum: '<S99>/Minus4' incorporates:
         *  Sum: '<S99>/Add2'
         *  Sum: '<S99>/Minus'
         */
        rtb_Switch2_ef = (rtb_Switch1_p2 + rtb_Minus_n[1]) - rtb_Switch2_p;

        /* Sum: '<S99>/Minus5' incorporates:
         *  Concatenate: '<S81>/Matrix Concatenate2'
         *  Sum: '<S99>/Minus'
         */
        rtb_Rotationmatrixfromlocalto_0 = rtb_Reshapey[1] - rtb_Switch2_p;

        /* Sum: '<S99>/Add' incorporates:
         *  Sum: '<S99>/Add2'
         *  Sum: '<S99>/Minus1'
         */
        rtb_Rotationmatrixfromlocalto_2 = rtb_Rotationmatrixfromlocalto_3 -
          rtb_Minus_n[1];

        /* Sum: '<S99>/Minus' incorporates:
         *  Sum: '<S99>/Minus1'
         */
        rtb_Switch2_p -= rtb_Rotationmatrixfromlocalto_2;

        /* DotProduct: '<S99>/Dot Product' incorporates:
         *  Concatenate: '<S81>/Matrix Concatenate2'
         *  Sum: '<S99>/Minus'
         *  Sum: '<S99>/Minus1'
         *  Sum: '<S99>/Minus5'
         */
        rtb_Init_e += (rtb_Reshapey[1] - rtb_Rotationmatrixfromlocalto_2) *
          rtb_Switch2_p;

        /* RelationalOperator: '<S100>/Compare' incorporates:
         *  Constant: '<S100>/Constant'
         */
        rtb_Is_Absolute_Steering = (rtb_Init_e >= 0.0);

        /* RelationalOperator: '<S99>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S99>/Dot Product1'
         *  Sum: '<S99>/Minus'
         */
        rtb_OR_ao = (rtb_Init_e <= ((rtb_Switch2_p * rtb_Switch2_p) +
          rtb_Optimized_Module_Angle));

        /* DotProduct: '<S99>/Dot Product2' incorporates:
         *  Sum: '<S99>/Minus4'
         *  Sum: '<S99>/Minus5'
         */
        rtb_Init_e = (rtb_Switch2_ef * rtb_Rotationmatrixfromlocalto_0) +
          rtb_Steer_Joystick_X_Rel_Mod;

        /* Merge: '<S85>/Merge4' incorporates:
         *  Constant: '<S101>/Constant'
         *  DataTypeConversion: '<S91>/Data Type Conversion'
         *  DotProduct: '<S99>/Dot Product3'
         *  Logic: '<S99>/AND'
         *  RelationalOperator: '<S101>/Compare'
         *  RelationalOperator: '<S99>/LessThanOrEqual1'
         *  Sum: '<S91>/Add'
         *  Sum: '<S99>/Minus4'
         */
        Code_Gen_Model_B.Spline_Index = ((real_T)(((rtb_Is_Absolute_Steering &&
          rtb_OR_ao) && (rtb_Init_e >= 0.0)) && (rtb_Init_e <= ((rtb_Switch2_ef *
          rtb_Switch2_ef) + rtb_MatrixConcatenate_b_idx_1)))) +
          Code_Gen_Model_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S85>/Merge2' incorporates:
         *  Constant: '<S91>/Constant2'
         *  SignalConversion generated from: '<S91>/Robot_Reached_Destination'
         */
        rtb_Is_Absolute_Steering = false;

        /* SignalConversion generated from: '<S91>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S91>/Constant1'
         */
        rtb_OR_ao = false;

        /* End of Outputs for SubSystem: '<S88>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S88>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S89>/Action Port'
         */
        /* Merge: '<S85>/Merge2' incorporates:
         *  Constant: '<S89>/Constant2'
         *  SignalConversion generated from: '<S89>/Robot_Reached_Destination'
         */
        rtb_Is_Absolute_Steering = false;

        /* SignalConversion generated from: '<S89>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S89>/Constant1'
         */
        rtb_OR_ao = false;

        /* Merge: '<S85>/Merge4' incorporates:
         *  SignalConversion generated from: '<S89>/Current_Index'
         */
        Code_Gen_Model_B.Spline_Index = Code_Gen_Model_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S88>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S85>/Merge1' incorporates:
       *  Constant: '<S88>/Constant'
       *  SignalConversion generated from: '<S88>/Out_Of_Bounds'
       */
      Code_Gen_Model_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S88>/Unit Delay' */
      Code_Gen_Model_DW.UnitDelay_DSTATE_e4 = rtb_Is_Absolute_Translation;

      /* End of Outputs for SubSystem: '<S85>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S85>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S87>/Action Port'
       */
      /* Merge: '<S85>/Merge1' incorporates:
       *  Constant: '<S87>/Constant'
       *  SignalConversion generated from: '<S87>/Out_Of_Bounds'
       */
      Code_Gen_Model_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S85>/Merge2' incorporates:
       *  Constant: '<S87>/Constant1'
       *  SignalConversion generated from: '<S87>/Robot_Reached_Destination'
       */
      rtb_Is_Absolute_Steering = false;

      /* SignalConversion generated from: '<S87>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S87>/Constant2'
       */
      rtb_OR_ao = false;

      /* Merge: '<S85>/Merge4' incorporates:
       *  SignalConversion generated from: '<S87>/Current_Index'
       */
      Code_Gen_Model_B.Spline_Index = Code_Gen_Model_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S85>/Escape_Auto_Driving' */
    }

    /* End of If: '<S85>/If' */

    /* If: '<S81>/If1' */
    if (!rtb_OR_ao) {
      /* Outputs for IfAction SubSystem: '<S81>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S86>/Action Port'
       */
      /* Bias: '<S102>/Add Constant' incorporates:
       *  Bias: '<S102>/Bias'
       *  Sum: '<S102>/Subtract'
       */
      rtb_Rotationmatrixfromlocalto_2 = ((Code_Gen_Model_B.Spline_Num_Poses -
        Code_Gen_Model_B.Spline_Index) + 3.0) + 1.0;

      /* SignalConversion generated from: '<S102>/Selector4' incorporates:
       *  Bias: '<S102>/Bias1'
       *  Constant: '<S104>/FixPt Constant'
       *  Sum: '<S104>/FixPt Sum1'
       */
      rtb_Reshapey[0] = Code_Gen_Model_B.Spline_Index - 1.0;
      rtb_Reshapey[1] = Code_Gen_Model_B.Spline_Num_Poses + 2.0;

      /* Selector: '<S102>/Selector4' */
      s107_iter = ((int32_T)rtb_Reshapey[1]) - ((int32_T)rtb_Reshapey[0]);
      Code_Gen_Model_DW.Selector4_DIMS1[0] = s107_iter + 1;
      Code_Gen_Model_DW.Selector4_DIMS1[1] = 2;
      rtb_Bias1_p = (int32_T)rtb_Reshapey[0];

      /* Concatenate: '<S102>/Matrix Concatenate' incorporates:
       *  Bias: '<S102>/Add Constant1'
       *  Gain: '<S105>/Gain'
       *  Gain: '<S106>/Gain'
       *  Selector: '<S102>/Selector'
       *  Selector: '<S102>/Selector1'
       *  Selector: '<S102>/Selector2'
       *  Selector: '<S102>/Selector3'
       *  Selector: '<S81>/Selector1'
       *  Sum: '<S105>/Subtract'
       *  Sum: '<S106>/Subtract'
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

        /* Selector: '<S102>/Selector4' incorporates:
         *  Bias: '<S102>/Add Constant1'
         *  Gain: '<S105>/Gain'
         *  Selector: '<S102>/Selector'
         *  Selector: '<S102>/Selector1'
         *  Sum: '<S105>/Subtract'
         */
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s107_iter;
             rtb_Num_Segments++) {
          rtb_Selector4[rtb_Num_Segments + (Code_Gen_Model_DW.Selector4_DIMS1[0]
            * i)] = rtb_Assignment[((rtb_Num_Segments + rtb_Bias1_p) + (21 * i))
            - 1];
        }
      }

      /* End of Concatenate: '<S102>/Matrix Concatenate' */

      /* Assignment: '<S102>/Assignment' incorporates:
       *  Selector: '<S102>/Selector4'
       */
      memset(&rtb_Assignment[0], 0, 42U * (sizeof(real_T)));
      rtb_Bias1_p = Code_Gen_Model_DW.Selector4_DIMS1[0];
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (s107_iter = 0; s107_iter < rtb_Bias1_p; s107_iter++) {
          rtb_Assignment[s107_iter + i] = rtb_Selector4
            [(Code_Gen_Model_DW.Selector4_DIMS1[0] * rtb_Num_Segments) +
            s107_iter];
        }

        i += 21;
      }

      /* End of Assignment: '<S102>/Assignment' */

      /* Outputs for Iterator SubSystem: '<S103>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S107>/While Iterator'
       */
      s107_iter = 1;
      do {
        rtb_Switch2_p = rtb_Assignment[s107_iter + 1];
        rtb_Reshapey[0] = rtb_Switch2_p - rtb_Assignment[s107_iter - 1];
        rtb_Minus_n[0] = rtb_Assignment[s107_iter] - rtb_Assignment[s107_iter +
          2];
        rtb_Add2_f[0] = rtb_Switch2_p - rtb_Assignment[s107_iter];
        rtb_Switch2_p = rtb_Assignment[s107_iter + 22];
        rtb_Reshapey[1] = rtb_Switch2_p - rtb_Assignment[s107_iter + 20];
        rtb_Optimized_Module_Angle = rtb_Assignment[s107_iter + 21];
        rtb_Minus_n[1] = rtb_Optimized_Module_Angle - rtb_Assignment[s107_iter +
          23];
        rtb_Add2_f[1] = rtb_Switch2_p - rtb_Optimized_Module_Angle;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_Init_e = ((real_T)rtb_Bias1_p) / 49.0;
          rtb_Rotationmatrixfromlocalto_3 = rt_powd_snf(rtb_Init_e, 2.0);
          rtb_Rotationmatrixfromlocalto_0 = rt_powd_snf(rtb_Init_e, 3.0);
          rtb_Switch1_p2 = (rtb_Init_e - (2.0 * rtb_Rotationmatrixfromlocalto_3))
            + rtb_Rotationmatrixfromlocalto_0;
          rtb_Switch2_ef = rtb_Rotationmatrixfromlocalto_3 -
            rtb_Rotationmatrixfromlocalto_0;
          rtb_Rotationmatrixfromlocalto_0 = (3.0 *
            rtb_Rotationmatrixfromlocalto_3) - (2.0 *
            rtb_Rotationmatrixfromlocalto_0);
          rtb_Steer_Joystick_X_Rel_Mod = ((((rtb_Reshapey[0] * rtb_Switch1_p2) +
            (rtb_Minus_n[0] * rtb_Switch2_ef)) * 0.5) + (rtb_Add2_f[0] *
            rtb_Rotationmatrixfromlocalto_0)) + rtb_Assignment[s107_iter];
          rtb_MatrixConcatenate_b_idx_1 = ((((rtb_Reshapey[1] * rtb_Switch1_p2)
            + (rtb_Minus_n[1] * rtb_Switch2_ef)) * 0.5) + (rtb_Add2_f[1] *
            rtb_Rotationmatrixfromlocalto_0)) + rtb_Optimized_Module_Angle;
          rtb_Switch1_p2 = ((3.0 * rtb_Rotationmatrixfromlocalto_3) - (4.0 *
            rtb_Init_e)) + 1.0;
          rtb_Switch2_ef = (2.0 * rtb_Init_e) - (3.0 *
            rtb_Rotationmatrixfromlocalto_3);
          rtb_Rotationmatrixfromlocalto_3 = (rtb_Init_e -
            rtb_Rotationmatrixfromlocalto_3) * 6.0;
          rtb_Rotationmatrixfromlocalto_0 = (((rtb_Reshapey[0] * rtb_Switch1_p2)
            + (rtb_Minus_n[0] * rtb_Switch2_ef)) * 0.5) + (rtb_Add2_f[0] *
            rtb_Rotationmatrixfromlocalto_3);
          rtb_Switch2_p = (((rtb_Reshapey[1] * rtb_Switch1_p2) + (rtb_Minus_n[1]
            * rtb_Switch2_ef)) * 0.5) + (rtb_Add2_f[1] *
            rtb_Rotationmatrixfromlocalto_3);
          rtb_Rotationmatrixfromlocalto_3 = (6.0 * rtb_Init_e) - 4.0;
          rtb_Switch1_p2 = (-6.0 * rtb_Init_e) + 2.0;
          rtb_Init_e = (-12.0 * rtb_Init_e) + 6.0;
          if ((rtb_Bias1_p + 1) == 1) {
            memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
          }

          rtb_Assignment_d[rtb_Bias1_p] = rtb_Steer_Joystick_X_Rel_Mod;
          rtb_Assignment_d[rtb_Bias1_p + 50] = rtb_MatrixConcatenate_b_idx_1;
          rtb_Assignment_d[rtb_Bias1_p + 100] = fabs((((((rtb_Reshapey[1] *
            rtb_Rotationmatrixfromlocalto_3) + (rtb_Minus_n[1] * rtb_Switch1_p2))
            * 0.5) + (rtb_Add2_f[1] * rtb_Init_e)) *
            rtb_Rotationmatrixfromlocalto_0) - (((((rtb_Reshapey[0] *
            rtb_Rotationmatrixfromlocalto_3) + (rtb_Minus_n[0] * rtb_Switch1_p2))
            * 0.5) + (rtb_Add2_f[0] * rtb_Init_e)) * rtb_Switch2_p)) /
            rt_powd_snf(rt_hypotd_snf(rtb_Rotationmatrixfromlocalto_0,
            rtb_Switch2_p), 3.0);
        }

        if (s107_iter == 1) {
          memset(&Code_Gen_Model_B.Assignment[0], 0, 450U * (sizeof(real_T)));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Code_Gen_Model_B.Assignment[((i * 50) + (s107_iter * 150)) +
                 -150], &rtb_Assignment_d[i * 50], 50U * (sizeof(real_T)));
        }

        rtb_Init_e = rtb_Rotationmatrixfromlocalto_2 - ((real_T)s107_iter);
        rtb_Num_Segments = s107_iter;
        s107_iter++;
      } while ((rtb_Init_e >= 4.0) && (s107_iter <= 3));

      /* End of Outputs for SubSystem: '<S103>/Sampling_Loop' */

      /* SignalConversion generated from: '<S86>/Position_and_Curvature' incorporates:
       *  Assignment: '<S107>/Assignment'
       *  Merge: '<S81>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Code_Gen_Model_B.Assignment[0],
             450U * (sizeof(real_T)));

      /* End of Outputs for SubSystem: '<S81>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S81>/If Action Subsystem' incorporates:
       *  ActionPort: '<S84>/Action Port'
       */
      /* Product: '<S84>/Product' incorporates:
       *  Selector: '<S81>/Selector'
       *  Selector: '<S81>/Selector1'
       */
      rtb_Init_e = rtb_Ref_Poses[((int32_T)Code_Gen_Model_B.Spline_Num_Poses) -
        1];

      /* Product: '<S84>/Product1' incorporates:
       *  Selector: '<S81>/Selector'
       *  Selector: '<S81>/Selector1'
       */
      rtb_Rotationmatrixfromlocalto_2 = rtb_Ref_Poses[((int32_T)
        Code_Gen_Model_B.Spline_Num_Poses) + 18];
      for (i = 0; i < 50; i++) {
        /* Product: '<S84>/Product' incorporates:
         *  Constant: '<S84>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_Init_e;

        /* Product: '<S84>/Product1' incorporates:
         *  Constant: '<S84>/Constant2'
         *  Product: '<S84>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Rotationmatrixfromlocalto_2;
      }

      /* Assignment: '<S84>/Assignment' incorporates:
       *  Concatenate: '<S84>/Matrix Concatenate'
       *  Merge: '<S81>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * (sizeof(real_T)));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S84>/Assignment' */

      /* SignalConversion generated from: '<S84>/Num_Segments' incorporates:
       *  Constant: '<S84>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S81>/If Action Subsystem' */
    }

    /* End of If: '<S81>/If1' */

    /* Concatenate: '<S82>/Matrix Concatenate' incorporates:
     *  Merge: '<S81>/Merge'
     *  Selector: '<S82>/Selector'
     *  Selector: '<S82>/Selector1'
     *  Selector: '<S82>/Selector3'
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

    /* End of Concatenate: '<S82>/Matrix Concatenate' */

    /* MATLAB Function: '<S82>/Distance Along Curve' incorporates:
     *  Concatenate: '<S82>/Matrix Concatenate'
     *  Selector: '<S82>/Selector4'
     *  Selector: '<S82>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * (sizeof(real_T)));
    for (s107_iter = 0; s107_iter < 149; s107_iter++) {
      /* Outputs for Iterator SubSystem: '<S103>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S107>/While Iterator'
       */
      rtb_Assignment_d[s107_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s107_iter + 1] -
         rtb_MatrixConcatenate_o[s107_iter], rtb_MatrixConcatenate_o[s107_iter +
         151] - rtb_MatrixConcatenate_o[s107_iter + 150]) +
        rtb_Assignment_d[s107_iter];

      /* End of Outputs for SubSystem: '<S103>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S82>/Distance Along Curve' */

    /* MATLAB Function: '<S82>/Find closest index to curve' incorporates:
     *  Concatenate: '<S82>/Matrix Concatenate'
     *  Selector: '<S133>/Selector'
     *  Selector: '<S82>/Selector4'
     *  Selector: '<S82>/Selector5'
     */
    for (s107_iter = 0; s107_iter < 150; s107_iter++) {
      /* Outputs for Iterator SubSystem: '<S103>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S107>/While Iterator'
       */
      distance_from_robot[s107_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s107_iter] - Code_Gen_Model_B.KF_Position_X,
         rtb_MatrixConcatenate_o[s107_iter + 150] -
         Code_Gen_Model_B.KF_Position_Y);

      /* End of Outputs for SubSystem: '<S103>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s107_iter = 1;
    } else {
      s107_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while ((!exitg1) && (rtb_Bias1_p < 151)) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s107_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s107_iter == 0) {
      rtb_Rotationmatrixfromlocalto_2 = distance_from_robot[0];
    } else {
      rtb_Rotationmatrixfromlocalto_2 = distance_from_robot[s107_iter - 1];
      for (rtb_Bias1_p = s107_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_Init_e = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_Rotationmatrixfromlocalto_2 > rtb_Init_e) {
          rtb_Rotationmatrixfromlocalto_2 = rtb_Init_e;
        }
      }
    }

    s107_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while ((!exitg1) && (rtb_Bias1_p < 150)) {
      s107_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_Rotationmatrixfromlocalto_2) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S133>/Selector' incorporates:
     *  Constant: '<S133>/Constant'
     *  MATLAB Function: '<S82>/Find closest index to curve'
     *  MinMax: '<S133>/Min'
     */
    rtb_Init_e = rtb_Assignment_d[((int32_T)fmin(50.0, s107_iter)) - 1];

    /* If: '<S133>/If' incorporates:
     *  RelationalOperator: '<S133>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S133>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S136>/Action Port'
       */
      /* SignalConversion generated from: '<S136>/Lookup Table Dynamic' */
      rtb_Reshapey[0] = rtb_Assignment_d[0];
      rtb_Reshapey[1] = rtb_Assignment_d[49];

      /* Sum: '<S138>/FixPt Sum1' incorporates:
       *  Constant: '<S138>/FixPt Constant'
       */
      rtb_Rotationmatrixfromlocalto_2 = Code_Gen_Model_B.Spline_Index - 1.0;

      /* SignalConversion generated from: '<S136>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S7>/Merge8'
       *  Selector: '<S136>/Selector11'
       *  Selector: '<S136>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses[((int32_T)
        rtb_Rotationmatrixfromlocalto_2) + 37];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses[((int32_T)
        Code_Gen_Model_B.Spline_Index) + 37];

      /* SignalConversion generated from: '<S136>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S7>/Merge8'
       *  Selector: '<S136>/Selector1'
       *  Selector: '<S136>/Selector2'
       */
      rtb_Add2_f[0] = rtb_Spline_Ref_Poses[((int32_T)
        rtb_Rotationmatrixfromlocalto_2) + 56];
      rtb_Add2_f[1] = rtb_Spline_Ref_Poses[((int32_T)
        Code_Gen_Model_B.Spline_Index) + 56];

      /* S-Function (sfix_look1_dyn): '<S136>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S136>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Rotationmatrixfromlocalto_2), &rtb_Minus_n[0],
                           rtb_Init_e, &rtb_Reshapey[0], 1U);

      /* SignalConversion: '<S136>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S136>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S136>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2_f[0], rtb_Init_e,
                           &rtb_Reshapey[0], 1U);

      /* End of Outputs for SubSystem: '<S133>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S133>/Latch' incorporates:
       *  ActionPort: '<S137>/Action Port'
       */
      /* SignalConversion generated from: '<S137>/In1' incorporates:
       *  UnitDelay: '<S133>/Unit Delay1'
       */
      rtb_Rotationmatrixfromlocalto_2 = Code_Gen_Model_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S137>/In2' incorporates:
       *  UnitDelay: '<S133>/Unit Delay'
       */
      rtb_Merge1 = Code_Gen_Model_DW.UnitDelay_DSTATE_g4g;

      /* End of Outputs for SubSystem: '<S133>/Latch' */
    }

    /* End of If: '<S133>/If' */

    /* MinMax: '<S80>/Min' incorporates:
     *  Lookup_n-D: '<S80>/Lookahead Distance'
     *  UnitDelay: '<S80>/Unit Delay'
     */
    rtb_Rotationmatrixfromlocalto_1 = fmin(rtb_Rotationmatrixfromlocalto_1,
      look1_binlcpw(Code_Gen_Model_DW.UnitDelay_DSTATE_hn,
                    Code_Gen_Model_ConstP.pooled9,
                    Code_Gen_Model_ConstP.LookaheadDistance_tableData, 3U));

    /* Outputs for Iterator SubSystem: '<S82>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S132>/While Iterator'
     */
    s132_iter = 1U;
    rtb_Is_Absolute_Translation = true;
    while (rtb_Is_Absolute_Translation && (s132_iter <= 150)) {
      /* Outputs for Iterator SubSystem: '<S82>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S132>/While Iterator'
       */
      Code_Gen_Model_B.WhileIterator = s132_iter;
      rtb_Is_Absolute_Translation =
        ((rtb_Assignment_d[Code_Gen_Model_B.WhileIterator - 1] <=
          (rtb_Assignment_d[s107_iter - 1] + rtb_Rotationmatrixfromlocalto_1)) &&
         (Code_Gen_Model_B.WhileIterator < (((real_T)rtb_Num_Segments) * 50.0)));
      s132_iter++;
    }

    /* End of Outputs for SubSystem: '<S82>/Find first index that meets distance target' */

    /* Switch: '<S135>/Switch' incorporates:
     *  Concatenate: '<S82>/Matrix Concatenate'
     *  Constant: '<S132>/Constant'
     *  Constant: '<S135>/Constant1'
     *  Constant: '<S135>/Constant2'
     *  Constant: '<S135>/Constant3'
     *  Constant: '<S82>/Constant'
     *  Logic: '<S132>/AND'
     *  MATLAB Function: '<S82>/Find closest index to curve'
     *  Math: '<S135>/Hypot'
     *  Merge: '<S7>/Merge8'
     *  MinMax: '<S135>/Min'
     *  MinMax: '<S135>/Min1'
     *  Product: '<S132>/Product'
     *  Product: '<S135>/Divide'
     *  Product: '<S135>/Product'
     *  Product: '<S135>/Product1'
     *  RelationalOperator: '<S132>/Relational Operator'
     *  RelationalOperator: '<S132>/Relational Operator1'
     *  RelationalOperator: '<S82>/Relational Operator'
     *  Selector: '<S132>/Selector'
     *  Selector: '<S132>/Selector1'
     *  Selector: '<S133>/Selector'
     *  Selector: '<S82>/Selector10'
     *  Selector: '<S82>/Selector7'
     *  Selector: '<S82>/Selector8'
     *  Selector: '<S82>/Selector9'
     *  Sqrt: '<S135>/Sqrt'
     *  Sum: '<S132>/Add'
     *  Sum: '<S135>/Subtract'
     *  Sum: '<S135>/Subtract1'
     *  Sum: '<S82>/Subtract'
     */
    if (Code_Gen_Model_B.Spline_Index >= (Code_Gen_Model_B.Spline_Num_Poses -
         Spline_Pose_Num_Before_End_Reduce_Speed)) {
      rtb_Rotationmatrixfromlocalto_1 = fmin(rt_hypotd_snf(rtb_Spline_Ref_Poses
        [18] - Code_Gen_Model_B.KF_Position_X, rtb_Spline_Ref_Poses[37] -
        Code_Gen_Model_B.KF_Position_Y) *
        Spline_Last_Pose_Distance_to_Velocity_Gain, fmin
        (rtb_Rotationmatrixfromlocalto_2 * Spline_Velocity_Multiplier_TEST, sqrt
         (Spline_Max_Centripital_Acceleration /
          rtb_MatrixConcatenate_o[Code_Gen_Model_B.WhileIterator + 299])));
    } else {
      rtb_Rotationmatrixfromlocalto_1 = fmin(rtb_Rotationmatrixfromlocalto_2 *
        Spline_Velocity_Multiplier_TEST, sqrt
        (Spline_Max_Centripital_Acceleration /
         rtb_MatrixConcatenate_o[Code_Gen_Model_B.WhileIterator + 299]));
    }

    /* End of Switch: '<S135>/Switch' */

    /* Logic: '<S83>/OR' */
    rtb_OR_ao = (rtb_Is_Absolute_Steering ||
                 (Code_Gen_Model_B.Spline_Out_Of_Bounds));

    /* Switch: '<S83>/Switch1' incorporates:
     *  Switch: '<S83>/Switch'
     *  UnitDelay: '<S83>/Unit Delay'
     */
    if (rtb_OR_ao) {
      /* Merge: '<S9>/Merge2' incorporates:
       *  Constant: '<S83>/Constant3'
       *  SignalConversion: '<S83>/Signal Copy1'
       */
      Code_Gen_Model_B.Translation_Speed_SPF = 0.0;
      rtb_Init_e = Code_Gen_Model_DW.UnitDelay_DSTATE_le;
    } else {
      /* Merge: '<S9>/Merge2' incorporates:
       *  SignalConversion: '<S83>/Signal Copy1'
       */
      Code_Gen_Model_B.Translation_Speed_SPF = rtb_Rotationmatrixfromlocalto_1;
      rtb_Init_e = rtb_Merge1;
    }

    /* End of Switch: '<S83>/Switch1' */

    /* Merge: '<S9>/Merge' incorporates:
     *  SignalConversion: '<S83>/Signal Copy'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd_SPF = rtb_Init_e;

    /* Selector: '<S82>/Selector6' incorporates:
     *  Concatenate: '<S82>/Matrix Concatenate'
     *  Selector: '<S82>/Selector5'
     */
    Code_Gen_Model_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Code_Gen_Model_B.WhileIterator + 149];

    /* Selector: '<S82>/Selector2' incorporates:
     *  Concatenate: '<S82>/Matrix Concatenate'
     *  Selector: '<S82>/Selector4'
     */
    Code_Gen_Model_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Code_Gen_Model_B.WhileIterator - 1];

    /* Switch: '<S83>/Switch2' incorporates:
     *  Sum: '<S139>/Subtract'
     *  Sum: '<S139>/Subtract1'
     *  Trigonometry: '<S139>/Atan2'
     *  UnitDelay: '<S83>/Unit Delay1'
     */
    if (rtb_OR_ao) {
      rtb_Rotationmatrixfromlocalto_3 = Code_Gen_Model_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_Rotationmatrixfromlocalto_3 = rt_atan2d_snf
        (Code_Gen_Model_B.Spline_Target_Y - Code_Gen_Model_B.KF_Position_Y,
         Code_Gen_Model_B.Spline_Target_X - Code_Gen_Model_B.KF_Position_X);
    }

    /* End of Switch: '<S83>/Switch2' */

    /* Merge: '<S9>/Merge3' incorporates:
     *  SignalConversion: '<S83>/Signal Copy2'
     */
    Code_Gen_Model_B.Translation_Angle_SPF = rtb_Rotationmatrixfromlocalto_3;

    /* Merge: '<S9>/Merge7' incorporates:
     *  SignalConversion: '<S80>/Signal Copy'
     */
    Code_Gen_Model_B.Robot_Reached_Destination = rtb_Is_Absolute_Steering;

    /* Merge: '<S9>/Merge1' incorporates:
     *  Constant: '<S83>/Constant2'
     *  SignalConversion generated from: '<S80>/Steering_Rel_Cmd'
     */
    Code_Gen_Model_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S9>/Merge4' incorporates:
     *  Constant: '<S83>/Constant5'
     *  SignalConversion generated from: '<S80>/Is_Absolute_Translation'
     */
    Code_Gen_Model_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S9>/Merge5' incorporates:
     *  Constant: '<S83>/Constant6'
     *  SignalConversion generated from: '<S80>/Is_Absolute_Steering'
     */
    Code_Gen_Model_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S9>/Merge6' incorporates:
     *  Constant: '<S83>/Constant1'
     *  SignalConversion generated from: '<S80>/Gyro_Angle_Adjustment'
     */
    Code_Gen_Model_B.Gyro_Angle_Adjustment_SPF = 0.0;

    /* Update for UnitDelay: '<S81>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_gh = Code_Gen_Model_B.Spline_Index;

    /* Update for UnitDelay: '<S80>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_hn = rtb_Rotationmatrixfromlocalto_1;

    /* Update for UnitDelay: '<S133>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_f4 = rtb_Rotationmatrixfromlocalto_2;

    /* Update for UnitDelay: '<S133>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_g4g = rtb_Merge1;

    /* Update for UnitDelay: '<S83>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_le = rtb_Init_e;

    /* Update for UnitDelay: '<S83>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_kc = rtb_Rotationmatrixfromlocalto_3;

    /* End of Outputs for SubSystem: '<S9>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S9>/Pass Through' incorporates:
     *  ActionPort: '<S79>/Action Port'
     */
    /* Merge: '<S9>/Merge7' incorporates:
     *  Constant: '<S79>/Constant'
     *  SignalConversion generated from: '<S79>/Robot_Reached_Destination'
     */
    Code_Gen_Model_B.Robot_Reached_Destination = false;

    /* Merge: '<S9>/Merge' incorporates:
     *  SignalConversion generated from: '<S79>/Steering_Abs_Cmd_In'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd_SPF = Code_Gen_Model_B.Steering_Abs_Cmd;

    /* Merge: '<S9>/Merge1' incorporates:
     *  SignalConversion generated from: '<S79>/Steering_Rel_Cmd_In'
     */
    Code_Gen_Model_B.Steering_Rel_Cmd_SPF = Code_Gen_Model_B.Steering_Rel_Cmd;

    /* Merge: '<S9>/Merge2' incorporates:
     *  SignalConversion generated from: '<S79>/Translation_Speed_In'
     */
    Code_Gen_Model_B.Translation_Speed_SPF = Code_Gen_Model_B.Translation_Speed;

    /* Merge: '<S9>/Merge3' incorporates:
     *  SignalConversion generated from: '<S79>/Translation_Angle_In'
     */
    Code_Gen_Model_B.Translation_Angle_SPF = Code_Gen_Model_B.Translation_Angle;

    /* Merge: '<S9>/Merge4' incorporates:
     *  SignalConversion generated from: '<S79>/Is_Absolute_Translation_In'
     */
    Code_Gen_Model_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation;

    /* Merge: '<S9>/Merge5' incorporates:
     *  SignalConversion generated from: '<S79>/Is_Absolute_Steering_In'
     */
    Code_Gen_Model_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S9>/Merge6' incorporates:
     *  SignalConversion generated from: '<S79>/Gyro_Angle_Adjustment_In'
     */
    Code_Gen_Model_B.Gyro_Angle_Adjustment_SPF = rtb_Rotationmatrixfromlocalto_1;

    /* End of Outputs for SubSystem: '<S9>/Pass Through' */
  }

  /* End of If: '<S9>/If' */

  /* UnitDelay: '<S233>/Unit Delay' */
  rtb_Init_e = Code_Gen_Model_B.Translation_Speed_RL;

  /* Signum: '<S233>/Sign2' */
  if (rtIsNaN(rtb_Init_e)) {
    rtb_Add_ie = (rtNaN);
  } else if (rtb_Init_e < 0.0) {
    rtb_Add_ie = -1.0;
  } else {
    rtb_Add_ie = (rtb_Init_e > 0.0);
  }

  /* Signum: '<S233>/Sign1' */
  if (rtIsNaN(Code_Gen_Model_B.Translation_Speed_SPF)) {
    rtb_Product_do = (rtNaN);
  } else if (Code_Gen_Model_B.Translation_Speed_SPF < 0.0) {
    rtb_Product_do = -1.0;
  } else {
    rtb_Product_do = (Code_Gen_Model_B.Translation_Speed_SPF > 0.0);
  }

  /* Product: '<S233>/Product1' incorporates:
   *  Signum: '<S233>/Sign1'
   *  Signum: '<S233>/Sign2'
   */
  rtb_Add_ie *= rtb_Product_do;
  if (rtIsNaN(rtb_Add_ie)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_ie, 256.0);
  }

  /* Switch: '<S233>/Switch' incorporates:
   *  Constant: '<S233>/Constant'
   *  Constant: '<S238>/Constant'
   *  Constant: '<S239>/Constant'
   *  Logic: '<S233>/or'
   *  Product: '<S233>/Product1'
   *  RelationalOperator: '<S238>/Compare'
   *  RelationalOperator: '<S239>/Compare'
   */
  if ((rtb_Init_e == 0.0) || (((i < 0) ? ((int32_T)((int8_T)(-((int8_T)((uint8_T)
             (-((real_T)i))))))) : i) > 0)) {
    rtb_Switch2_p = Code_Gen_Model_B.Translation_Speed_SPF;
  } else {
    rtb_Switch2_p = 0.0;
  }

  /* End of Switch: '<S233>/Switch' */

  /* Switch: '<S244>/Init' incorporates:
   *  UnitDelay: '<S244>/FixPt Unit Delay1'
   *  UnitDelay: '<S244>/FixPt Unit Delay2'
   */
  if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Optimized_Module_Angle = rtb_Switch2_p;
  } else {
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S244>/Init' */

  /* RelationalOperator: '<S240>/Compare' incorporates:
   *  Constant: '<S240>/Constant'
   */
  rtb_Is_Absolute_Translation = (rtb_Switch2_p == 0.0);

  /* RelationalOperator: '<S241>/Compare' incorporates:
   *  Constant: '<S241>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Switch2_p > 0.0);

  /* Abs: '<S233>/Abs' incorporates:
   *  Sum: '<S233>/Subtract'
   */
  rtb_Merge1 = fabs(rtb_Init_e - Code_Gen_Model_B.Translation_Speed_SPF);

  /* Switch: '<S233>/Switch5' incorporates:
   *  Constant: '<S233>/Constant1'
   *  Switch: '<S233>/Switch1'
   *  UnaryMinus: '<S233>/Unary Minus'
   */
  if (rtb_Is_Absolute_Translation) {
    /* SignalConversion generated from: '<S233>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S233>/Constant4'
     *  Constant: '<S233>/Constant6'
     */
    rtb_Reshapey[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S233>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S233>/Constant2'
     *  Constant: '<S233>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S233>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S233>/Lookup Table Dynamic'
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
    rtb_Add_ie = -Translation_Speed_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S233>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S233>/Constant10'
     *  Constant: '<S233>/Constant8'
     */
    rtb_Reshapey[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S233>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S233>/Constant7'
     *  Constant: '<S233>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S233>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S233>/Lookup Table Dynamic1'
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

    /* Switch: '<S233>/Switch3' incorporates:
     *  Constant: '<S233>/Constant1'
     *  Constant: '<S233>/Constant3'
     *  UnaryMinus: '<S233>/Unary Minus'
     */
    if (rtb_Is_Absolute_Steering) {
      rtb_Add_ie = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_ie = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S233>/Switch3' */
  }

  /* End of Switch: '<S233>/Switch5' */

  /* Product: '<S233>/Product' incorporates:
   *  Switch: '<S233>/Switch1'
   */
  rtb_uDLookupTable_l = rtb_Add_ie * rtb_Merge1;

  /* Sum: '<S242>/Sum1' */
  rtb_Rotationmatrixfromlocalto_1 = rtb_Switch2_p - rtb_Optimized_Module_Angle;

  /* Switch: '<S243>/Switch2' incorporates:
   *  RelationalOperator: '<S243>/LowerRelop1'
   */
  if (!(rtb_Rotationmatrixfromlocalto_1 > rtb_uDLookupTable_l)) {
    /* Switch: '<S233>/Switch2' incorporates:
     *  Constant: '<S233>/Constant1'
     *  Switch: '<S233>/Switch4'
     */
    if (rtb_Is_Absolute_Translation) {
      rtb_Rotationmatrixfromlocalto_2 = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_Is_Absolute_Steering) {
      /* Switch: '<S233>/Switch4' incorporates:
       *  Constant: '<S233>/Constant1'
       */
      rtb_Rotationmatrixfromlocalto_2 = Translation_Speed_Rate_Limit_Dec;
    } else {
      /* Switch: '<S233>/Switch4' incorporates:
       *  Constant: '<S233>/Constant3'
       *  UnaryMinus: '<S233>/Unary Minus1'
       */
      rtb_Rotationmatrixfromlocalto_2 = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S233>/Switch2' */

    /* Product: '<S233>/Product2' */
    rtb_Rotationmatrixfromlocalto_2 *= rtb_Merge1;

    /* Switch: '<S243>/Switch' incorporates:
     *  RelationalOperator: '<S243>/UpperRelop'
     */
    if (rtb_Rotationmatrixfromlocalto_1 < rtb_Rotationmatrixfromlocalto_2) {
      rtb_uDLookupTable_l = rtb_Rotationmatrixfromlocalto_2;
    } else {
      rtb_uDLookupTable_l = rtb_Rotationmatrixfromlocalto_1;
    }

    /* End of Switch: '<S243>/Switch' */
  }

  /* End of Switch: '<S243>/Switch2' */

  /* Sum: '<S242>/Sum' */
  Code_Gen_Model_B.Translation_Speed_RL = rtb_uDLookupTable_l +
    rtb_Optimized_Module_Angle;

  /* Switch: '<S236>/Switch' */
  if (Code_Gen_Model_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S236>/Switch' incorporates:
     *  Constant: '<S260>/Constant3'
     *  Constant: '<S260>/Constant4'
     *  Math: '<S260>/Math Function'
     *  Sum: '<S236>/Subtract'
     *  Sum: '<S260>/Add1'
     *  Sum: '<S260>/Add2'
     */
    Code_Gen_Model_B.Translation_Steering_Cmd = rt_modd_snf
      ((Code_Gen_Model_B.Translation_Angle_SPF - rtb_thetay) +
       3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S236>/Switch' */
    Code_Gen_Model_B.Translation_Steering_Cmd =
      Code_Gen_Model_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S236>/Switch' */

  /* Sum: '<S256>/Add1' incorporates:
   *  Constant: '<S256>/Constant3'
   *  Constant: '<S256>/Constant4'
   *  Math: '<S256>/Math Function'
   *  Sum: '<S235>/Add'
   *  Sum: '<S255>/Sum'
   *  Sum: '<S256>/Add2'
   */
  rtb_Optimized_Module_Angle = rt_modd_snf
    ((Code_Gen_Model_B.Steering_Abs_Cmd_SPF - (rtb_thetay +
       Code_Gen_Model_B.Gyro_Angle_Adjustment_SPF)) + 3.1415926535897931,
     6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S258>/Sum1' incorporates:
   *  Constant: '<S255>/Constant2'
   *  Product: '<S258>/Product'
   *  Sum: '<S258>/Sum'
   *  UnitDelay: '<S258>/Unit Delay1'
   */
  rtb_Merge1 = ((rtb_Optimized_Module_Angle -
                 Code_Gen_Model_DW.UnitDelay1_DSTATE) *
                Steering_Heading_Control_D_FilterCoeff) +
    Code_Gen_Model_DW.UnitDelay1_DSTATE;

  /* Product: '<S255>/Product' incorporates:
   *  Constant: '<S255>/Constant3'
   */
  rtb_Rotationmatrixfromlocalto_1 = rtb_Merge1 * Steering_Heading_Control_D;

  /* Sum: '<S257>/Diff' incorporates:
   *  UnitDelay: '<S257>/UD'
   *
   * Block description for '<S257>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S257>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ls = rtb_Rotationmatrixfromlocalto_1 - Code_Gen_Model_DW.UD_DSTATE_a;

  /* Saturate: '<S255>/Saturation' */
  if (rtb_Add_ls > Steering_Heading_Control_D_UL) {
    rtb_Add_ls = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_ls < Steering_Heading_Control_D_LL) {
    rtb_Add_ls = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S255>/Add' incorporates:
   *  Gain: '<S255>/Gain1'
   *  Saturate: '<S255>/Saturation'
   */
  rtb_Init_e = (Steering_Heading_Control_P * rtb_Optimized_Module_Angle) +
    rtb_Add_ls;

  /* Sum: '<S255>/Subtract' incorporates:
   *  Constant: '<S255>/Constant'
   */
  rtb_uDLookupTable_l = Steering_Heading_Control_Total_UL - rtb_Init_e;

  /* Sum: '<S255>/Sum2' incorporates:
   *  Gain: '<S255>/Gain2'
   *  UnitDelay: '<S255>/Unit Delay'
   */
  rtb_Rotationmatrixfromlocalto_2 = (Steering_Heading_Control_I *
    rtb_Optimized_Module_Angle) + Code_Gen_Model_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S259>/Switch2' incorporates:
   *  RelationalOperator: '<S259>/LowerRelop1'
   */
  if (!(rtb_Rotationmatrixfromlocalto_2 > rtb_uDLookupTable_l)) {
    /* Sum: '<S255>/Subtract1' incorporates:
     *  Constant: '<S255>/Constant1'
     */
    rtb_Rotationmatrixfromlocalto_3 = Steering_Heading_Control_Total_LL -
      rtb_Init_e;

    /* Switch: '<S259>/Switch' incorporates:
     *  RelationalOperator: '<S259>/UpperRelop'
     */
    if (rtb_Rotationmatrixfromlocalto_2 < rtb_Rotationmatrixfromlocalto_3) {
      rtb_uDLookupTable_l = rtb_Rotationmatrixfromlocalto_3;
    } else {
      rtb_uDLookupTable_l = rtb_Rotationmatrixfromlocalto_2;
    }

    /* End of Switch: '<S259>/Switch' */
  }

  /* End of Switch: '<S259>/Switch2' */

  /* Saturate: '<S255>/Saturation1' */
  if (rtb_uDLookupTable_l > Steering_Heading_Control_I_UL) {
    rtb_Rotationmatrixfromlocalto_2 = Steering_Heading_Control_I_UL;
  } else if (rtb_uDLookupTable_l < Steering_Heading_Control_I_LL) {
    rtb_Rotationmatrixfromlocalto_2 = Steering_Heading_Control_I_LL;
  } else {
    rtb_Rotationmatrixfromlocalto_2 = rtb_uDLookupTable_l;
  }

  /* End of Saturate: '<S255>/Saturation1' */

  /* Sum: '<S255>/Add1' */
  rtb_Add_ls = rtb_Init_e + rtb_Rotationmatrixfromlocalto_2;

  /* Saturate: '<S255>/Saturation2' */
  if (rtb_Add_ls > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S255>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_ls < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S255>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S255>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = rtb_Add_ls;
  }

  /* End of Saturate: '<S255>/Saturation2' */

  /* Switch: '<S235>/Switch' */
  if (Code_Gen_Model_B.Is_Absolute_Steering_SPF) {
    /* Switch: '<S246>/Switch' incorporates:
     *  Abs: '<S246>/Abs'
     *  Constant: '<S246>/Constant'
     *  Constant: '<S254>/Constant'
     *  RelationalOperator: '<S254>/Compare'
     */
    if (fabs(Code_Gen_Model_B.Steering_Localized_PID) >
        Steering_Heading_Control_Deadzone) {
      rtb_Optimized_Module_Angle = Code_Gen_Model_B.Steering_Localized_PID;
    } else {
      rtb_Optimized_Module_Angle = 0.0;
    }

    /* End of Switch: '<S246>/Switch' */
  } else {
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.Steering_Rel_Cmd_SPF;
  }

  /* End of Switch: '<S235>/Switch' */

  /* Signum: '<S245>/Sign2' incorporates:
   *  UnitDelay: '<S245>/Unit Delay'
   */
  if (rtIsNaN(Code_Gen_Model_B.Steering_Localized_Cmd)) {
    rtb_Add_ie = (rtNaN);
  } else if (Code_Gen_Model_B.Steering_Localized_Cmd < 0.0) {
    rtb_Add_ie = -1.0;
  } else {
    rtb_Add_ie = (Code_Gen_Model_B.Steering_Localized_Cmd > 0.0);
  }

  /* Signum: '<S245>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle)) {
    rtb_Product_do = (rtNaN);
  } else if (rtb_Optimized_Module_Angle < 0.0) {
    rtb_Product_do = -1.0;
  } else {
    rtb_Product_do = (rtb_Optimized_Module_Angle > 0.0);
  }

  /* Product: '<S245>/Product1' incorporates:
   *  Signum: '<S245>/Sign1'
   *  Signum: '<S245>/Sign2'
   */
  rtb_Add_ie *= rtb_Product_do;
  if (rtIsNaN(rtb_Add_ie)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_ie, 256.0);
  }

  /* Switch: '<S245>/Switch' incorporates:
   *  Constant: '<S245>/Constant'
   *  Constant: '<S247>/Constant'
   *  Constant: '<S248>/Constant'
   *  Logic: '<S245>/or'
   *  Product: '<S245>/Product1'
   *  RelationalOperator: '<S247>/Compare'
   *  RelationalOperator: '<S248>/Compare'
   *  UnitDelay: '<S245>/Unit Delay'
   */
  if ((Code_Gen_Model_B.Steering_Localized_Cmd == 0.0) || (((i < 0) ? ((int32_T)
         ((int8_T)(-((int8_T)((uint8_T)(-((real_T)i))))))) : i) > 0)) {
    rtb_Switch1_p2 = rtb_Optimized_Module_Angle;
  } else {
    rtb_Switch1_p2 = 0.0;
  }

  /* End of Switch: '<S245>/Switch' */

  /* Switch: '<S253>/Init' incorporates:
   *  UnitDelay: '<S253>/FixPt Unit Delay1'
   *  UnitDelay: '<S253>/FixPt Unit Delay2'
   */
  if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Init_e = rtb_Switch1_p2;
  } else {
    rtb_Init_e = Code_Gen_Model_B.Steering_Localized_Cmd;
  }

  /* End of Switch: '<S253>/Init' */

  /* RelationalOperator: '<S249>/Compare' incorporates:
   *  Constant: '<S249>/Constant'
   */
  rtb_Is_Absolute_Translation = (rtb_Switch1_p2 == 0.0);

  /* RelationalOperator: '<S250>/Compare' incorporates:
   *  Constant: '<S250>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Switch1_p2 > 0.0);

  /* Abs: '<S245>/Abs' incorporates:
   *  Sum: '<S245>/Subtract'
   *  UnitDelay: '<S245>/Unit Delay'
   */
  rtb_Switch2_ef = fabs(Code_Gen_Model_B.Steering_Localized_Cmd -
                        rtb_Optimized_Module_Angle);

  /* Switch: '<S245>/Switch5' incorporates:
   *  Constant: '<S245>/Constant1'
   *  Switch: '<S245>/Switch1'
   *  UnaryMinus: '<S245>/Unary Minus'
   */
  if (rtb_Is_Absolute_Translation) {
    /* SignalConversion generated from: '<S245>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S245>/Constant4'
     *  Constant: '<S245>/Constant6'
     */
    rtb_Reshapey[0] = Steering_Localized_Cmd_Approach_Zero_Final_Thresh;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S245>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S245>/Constant2'
     *  Constant: '<S245>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Localized_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S245>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S245>/Lookup Table Dynamic'
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
    rtb_Add_ie = -Steering_Localized_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S245>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S245>/Constant10'
     *  Constant: '<S245>/Constant8'
     */
    rtb_Reshapey[0] = Steering_Localized_Cmd_NonZero_Final_Scale_Factor;
    rtb_Reshapey[1] = 1.0;

    /* SignalConversion generated from: '<S245>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S245>/Constant7'
     *  Constant: '<S245>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Localized_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S245>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S245>/Lookup Table Dynamic1'
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

    /* Switch: '<S245>/Switch3' incorporates:
     *  Constant: '<S245>/Constant1'
     *  Constant: '<S245>/Constant3'
     *  UnaryMinus: '<S245>/Unary Minus'
     */
    if (rtb_Is_Absolute_Steering) {
      rtb_Add_ie = Steering_Localized_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_ie = -Steering_Localized_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S245>/Switch3' */
  }

  /* End of Switch: '<S245>/Switch5' */

  /* Product: '<S245>/Product' incorporates:
   *  Switch: '<S245>/Switch1'
   */
  rtb_Rotationmatrixfromlocalto_3 = rtb_Add_ie * rtb_Switch2_ef;

  /* Sum: '<S251>/Sum1' */
  rtb_Switch1_p2 -= rtb_Init_e;

  /* Switch: '<S252>/Switch2' incorporates:
   *  RelationalOperator: '<S252>/LowerRelop1'
   */
  if (!(rtb_Switch1_p2 > rtb_Rotationmatrixfromlocalto_3)) {
    /* Switch: '<S245>/Switch2' incorporates:
     *  Constant: '<S245>/Constant1'
     *  Constant: '<S245>/Constant3'
     *  Switch: '<S245>/Switch4'
     *  UnaryMinus: '<S245>/Unary Minus1'
     */
    if (rtb_Is_Absolute_Translation) {
      rtb_Add_ie = Steering_Localized_Cmd_Rate_Limit_Dec;
    } else if (rtb_Is_Absolute_Steering) {
      /* Switch: '<S245>/Switch4' incorporates:
       *  Constant: '<S245>/Constant1'
       */
      rtb_Add_ie = Steering_Localized_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_ie = -Steering_Localized_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S245>/Product2' incorporates:
     *  Switch: '<S245>/Switch2'
     */
    rtb_Rotationmatrixfromlocalto_3 = rtb_Add_ie * rtb_Switch2_ef;

    /* Switch: '<S252>/Switch' incorporates:
     *  RelationalOperator: '<S252>/UpperRelop'
     */
    if (!(rtb_Switch1_p2 < rtb_Rotationmatrixfromlocalto_3)) {
      rtb_Rotationmatrixfromlocalto_3 = rtb_Switch1_p2;
    }

    /* End of Switch: '<S252>/Switch' */
  }

  /* End of Switch: '<S252>/Switch2' */

  /* Sum: '<S251>/Sum' */
  Code_Gen_Model_B.Steering_Localized_Cmd = rtb_Rotationmatrixfromlocalto_3 +
    rtb_Init_e;

  /* Outputs for Atomic SubSystem: '<S148>/Initialize Function' */
  /* Sum: '<S234>/Add' incorporates:
   *  Constant: '<S234>/Constant'
   *  Constant: '<S234>/Constant4'
   *  Constant: '<S234>/Constant5'
   *  Trigonometry: '<S234>/Atan2'
   */
  rtb_Init_e = rt_atan2d_snf(Distance_FL_y, 0.187325) + 1.5707963267948966;

  /* End of Outputs for SubSystem: '<S148>/Initialize Function' */

  /* Fcn: '<S268>/r->x' incorporates:
   *  Fcn: '<S273>/r->x'
   *  Fcn: '<S278>/r->x'
   *  Fcn: '<S283>/r->x'
   */
  rtb_Switch2_p = Code_Gen_Model_B.Translation_Speed_RL * cos
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S262>/Add' incorporates:
   *  Fcn: '<S268>/r->x'
   *  Fcn: '<S269>/r->x'
   */
  rtb_Reshapey[0] = (Code_Gen_Model_B.Steering_Localized_Cmd * cos(rtb_Init_e))
    + rtb_Switch2_p;

  /* Fcn: '<S268>/theta->y' incorporates:
   *  Fcn: '<S273>/theta->y'
   *  Fcn: '<S278>/theta->y'
   *  Fcn: '<S283>/theta->y'
   */
  rtb_Rotationmatrixfromlocalto_3 = Code_Gen_Model_B.Translation_Speed_RL * sin
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S262>/Add' incorporates:
   *  Fcn: '<S268>/theta->y'
   *  Fcn: '<S269>/theta->y'
   */
  rtb_Reshapey[1] = (Code_Gen_Model_B.Steering_Localized_Cmd * sin(rtb_Init_e))
    + rtb_Rotationmatrixfromlocalto_3;

  /* Sum: '<S263>/Add' incorporates:
   *  Fcn: '<S274>/r->x'
   *  Fcn: '<S274>/theta->y'
   */
  rtb_Minus_n[0] = (Code_Gen_Model_B.Steering_Localized_Cmd * cos
                    (Code_Gen_Model_ConstB.FR_Tangent_Angle)) + rtb_Switch2_p;
  rtb_Minus_n[1] = (Code_Gen_Model_B.Steering_Localized_Cmd * sin
                    (Code_Gen_Model_ConstB.FR_Tangent_Angle)) +
    rtb_Rotationmatrixfromlocalto_3;

  /* Sum: '<S264>/Add' incorporates:
   *  Fcn: '<S279>/r->x'
   *  Fcn: '<S279>/theta->y'
   */
  rtb_Add2_f[0] = (Code_Gen_Model_B.Steering_Localized_Cmd * cos
                   (Code_Gen_Model_ConstB.BL_Tangent_Angle)) + rtb_Switch2_p;
  rtb_Add2_f[1] = (Code_Gen_Model_B.Steering_Localized_Cmd * sin
                   (Code_Gen_Model_ConstB.BL_Tangent_Angle)) +
    rtb_Rotationmatrixfromlocalto_3;

  /* Sum: '<S265>/Add' incorporates:
   *  Fcn: '<S284>/r->x'
   *  Fcn: '<S284>/theta->y'
   */
  rtb_Rotationmatrixfromlocalto_0 = (Code_Gen_Model_B.Steering_Localized_Cmd *
    cos(Code_Gen_Model_ConstB.BR_Tangent_Angle)) + rtb_Switch2_p;
  rtb_Rotationmatrixfromlocalto_3 += Code_Gen_Model_B.Steering_Localized_Cmd *
    sin(Code_Gen_Model_ConstB.BR_Tangent_Angle);

  /* Fcn: '<S282>/x->r' */
  rtb_Init_e = rt_hypotd_snf(rtb_Rotationmatrixfromlocalto_0,
    rtb_Rotationmatrixfromlocalto_3);

  /* RelationalOperator: '<S285>/Compare' incorporates:
   *  Constant: '<S285>/Constant'
   */
  rtb_Is_Absolute_Translation = (rtb_Init_e == 0.0);

  /* Switch: '<S281>/Switch1' */
  if (rtb_Is_Absolute_Translation) {
    /* Switch: '<S281>/Switch1' incorporates:
     *  Constant: '<S281>/Constant'
     */
    Code_Gen_Model_B.Switch1 = 1.0E-15;
  } else {
    /* Switch: '<S281>/Switch1' */
    Code_Gen_Model_B.Switch1 = rtb_Init_e;
  }

  /* End of Switch: '<S281>/Switch1' */

  /* Fcn: '<S267>/x->r' */
  rtb_Init_e = rt_hypotd_snf(rtb_Reshapey[0], rtb_Reshapey[1]);

  /* RelationalOperator: '<S270>/Compare' incorporates:
   *  Constant: '<S270>/Constant'
   */
  rtb_Is_Absolute_Steering = (rtb_Init_e == 0.0);

  /* Switch: '<S266>/Switch1' */
  if (rtb_Is_Absolute_Steering) {
    /* Switch: '<S266>/Switch1' incorporates:
     *  Constant: '<S266>/Constant'
     */
    Code_Gen_Model_B.Switch1_m = 1.0E-15;
  } else {
    /* Switch: '<S266>/Switch1' */
    Code_Gen_Model_B.Switch1_m = rtb_Init_e;
  }

  /* End of Switch: '<S266>/Switch1' */

  /* Fcn: '<S272>/x->r' */
  rtb_Switch2_p = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S275>/Compare' incorporates:
   *  Constant: '<S275>/Constant'
   */
  rtb_OR_ao = (rtb_Switch2_p == 0.0);

  /* Switch: '<S271>/Switch1' */
  if (rtb_OR_ao) {
    /* Switch: '<S271>/Switch1' incorporates:
     *  Constant: '<S271>/Constant'
     */
    Code_Gen_Model_B.Switch1_o = 1.0E-15;
  } else {
    /* Switch: '<S271>/Switch1' */
    Code_Gen_Model_B.Switch1_o = rtb_Switch2_p;
  }

  /* End of Switch: '<S271>/Switch1' */

  /* Fcn: '<S277>/x->r' */
  rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_Add2_f[0], rtb_Add2_f[1]);

  /* RelationalOperator: '<S280>/Compare' incorporates:
   *  Constant: '<S280>/Constant'
   */
  rtb_Switch_b1 = (rtb_Optimized_Module_Angle == 0.0);

  /* Switch: '<S276>/Switch1' */
  if (rtb_Switch_b1) {
    /* Switch: '<S276>/Switch1' incorporates:
     *  Constant: '<S276>/Constant'
     */
    Code_Gen_Model_B.Switch1_p = 1.0E-15;
  } else {
    /* Switch: '<S276>/Switch1' */
    Code_Gen_Model_B.Switch1_p = rtb_Optimized_Module_Angle;
  }

  /* End of Switch: '<S276>/Switch1' */

  /* Product: '<S261>/Divide' incorporates:
   *  Abs: '<S261>/Abs'
   *  Abs: '<S261>/Abs1'
   *  Abs: '<S261>/Abs2'
   *  Abs: '<S261>/Abs3'
   *  Constant: '<S261>/Constant'
   *  MinMax: '<S261>/Max'
   */
  rtb_Init_e = 3.5944420196850411 / fmax(fmax(fmax(fmax(3.5944420196850411,
    Code_Gen_Model_B.Switch1_m), Code_Gen_Model_B.Switch1_o),
    Code_Gen_Model_B.Switch1_p), Code_Gen_Model_B.Switch1);

  /* Product: '<S261>/Product3' */
  Code_Gen_Model_B.BR_Desired_Wheel_Speed = Code_Gen_Model_B.Switch1 *
    rtb_Init_e;

  /* Switch: '<S281>/Switch' */
  if (!rtb_Is_Absolute_Translation) {
    /* Switch: '<S281>/Switch' incorporates:
     *  Fcn: '<S282>/x->theta'
     */
    Code_Gen_Model_B.BR_Desired_Module_Angle = rt_atan2d_snf
      (rtb_Rotationmatrixfromlocalto_3, rtb_Rotationmatrixfromlocalto_0);
  }

  /* End of Switch: '<S281>/Switch' */

  /* Trigonometry: '<S225>/Cos4' incorporates:
   *  Switch: '<S214>/Angle_Switch'
   *  Trigonometry: '<S224>/Cos4'
   */
  rtb_MatrixConcatenate_b_idx_1 = cos(Code_Gen_Model_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S225>/Sin5' incorporates:
   *  UnaryMinus: '<S223>/Unary Minus'
   */
  rtb_uDLookupTable_l = sin(-Code_Gen_Model_B.BR_Steer_Module_Angle);

  /* Trigonometry: '<S225>/Sin4' incorporates:
   *  Switch: '<S214>/Angle_Switch'
   *  Trigonometry: '<S224>/Sin4'
   */
  rtb_Subtract_gn = sin(Code_Gen_Model_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S225>/Cos5' incorporates:
   *  UnaryMinus: '<S223>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Code_Gen_Model_B.BR_Steer_Module_Angle);

  /* Sum: '<S225>/Subtract1' incorporates:
   *  Product: '<S225>/Product2'
   *  Product: '<S225>/Product3'
   *  Trigonometry: '<S225>/Cos4'
   *  Trigonometry: '<S225>/Sin4'
   */
  rtb_Rotationmatrixfromlocalto_3 = (rtb_MatrixConcatenate_b_idx_1 *
    rtb_uDLookupTable_l) + (rtb_Subtract_gn * rtb_Optimized_Module_Angle);

  /* Sum: '<S225>/Subtract' incorporates:
   *  Product: '<S225>/Product'
   *  Product: '<S225>/Product1'
   *  Trigonometry: '<S225>/Cos4'
   *  Trigonometry: '<S225>/Sin4'
   */
  rtb_Switch1_p2 = (rtb_MatrixConcatenate_b_idx_1 * rtb_Optimized_Module_Angle)
    - (rtb_Subtract_gn * rtb_uDLookupTable_l);

  /* Math: '<S225>/Hypot' */
  rtb_Switch2_ef = rt_hypotd_snf(rtb_Switch1_p2, rtb_Rotationmatrixfromlocalto_3);

  /* Switch: '<S225>/Switch' incorporates:
   *  Constant: '<S225>/Constant'
   *  Constant: '<S225>/Constant1'
   *  Constant: '<S226>/Constant'
   *  Product: '<S225>/Divide'
   *  Product: '<S225>/Divide1'
   *  RelationalOperator: '<S226>/Compare'
   *  Switch: '<S225>/Switch1'
   */
  if (rtb_Switch2_ef > 1.0E-6) {
    rtb_Switch2_p = rtb_Rotationmatrixfromlocalto_3 / rtb_Switch2_ef;
    rtb_Optimized_Module_Angle = rtb_Switch1_p2 / rtb_Switch2_ef;
  } else {
    rtb_Switch2_p = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S225>/Switch' */

  /* Switch: '<S214>/Speed_Switch' incorporates:
   *  Abs: '<S214>/Abs'
   *  Constant: '<S222>/Constant'
   *  RelationalOperator: '<S222>/Compare'
   *  Switch: '<S214>/Angle_Switch'
   *  Trigonometry: '<S224>/Atan1'
   *  Trigonometry: '<S225>/Atan1'
   *  UnaryMinus: '<S214>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_p, rtb_Optimized_Module_Angle)) >
      1.5707963267948966) {
    rtb_Add_ie = -Code_Gen_Model_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S224>/Subtract1' incorporates:
     *  Product: '<S224>/Product2'
     *  Product: '<S224>/Product3'
     *  UnaryMinus: '<S214>/Unary Minus'
     */
    rtb_Rotationmatrixfromlocalto_3 = (rtb_MatrixConcatenate_b_idx_1 *
      Code_Gen_Model_ConstB.Sin5_c) + (rtb_Subtract_gn *
      Code_Gen_Model_ConstB.Cos5_b);

    /* Sum: '<S224>/Subtract' incorporates:
     *  Product: '<S224>/Product'
     *  Product: '<S224>/Product1'
     */
    rtb_Switch2_ef = (rtb_MatrixConcatenate_b_idx_1 *
                      Code_Gen_Model_ConstB.Cos5_b) - (rtb_Subtract_gn *
      Code_Gen_Model_ConstB.Sin5_c);

    /* Math: '<S224>/Hypot' */
    rtb_Switch1_p2 = rt_hypotd_snf(rtb_Switch2_ef,
      rtb_Rotationmatrixfromlocalto_3);

    /* Switch: '<S224>/Switch1' incorporates:
     *  Constant: '<S224>/Constant'
     *  Constant: '<S224>/Constant1'
     *  Constant: '<S227>/Constant'
     *  Product: '<S224>/Divide'
     *  Product: '<S224>/Divide1'
     *  RelationalOperator: '<S227>/Compare'
     *  Switch: '<S224>/Switch'
     */
    if (rtb_Switch1_p2 > 1.0E-6) {
      rtb_Switch2_ef /= rtb_Switch1_p2;
      rtb_Rotationmatrixfromlocalto_3 /= rtb_Switch1_p2;
    } else {
      rtb_Switch2_ef = 1.0;
      rtb_Rotationmatrixfromlocalto_3 = 0.0;
    }

    /* End of Switch: '<S224>/Switch1' */
    rtb_uDLookupTable_l = rt_atan2d_snf(rtb_Rotationmatrixfromlocalto_3,
      rtb_Switch2_ef);
  } else {
    rtb_Add_ie = Code_Gen_Model_B.BR_Desired_Wheel_Speed;
    rtb_uDLookupTable_l = Code_Gen_Model_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S217>/Product2' incorporates:
   *  Constant: '<S217>/Constant'
   *  Switch: '<S214>/Speed_Switch'
   */
  rtb_Switch2_p = rtb_Add_ie * 1530.1401357649195;

  /* Signum: '<S212>/Sign' */
  if (rtIsNaN(rtb_Switch2_p)) {
    rtb_Add_ie = (rtNaN);
  } else if (rtb_Switch2_p < 0.0) {
    rtb_Add_ie = -1.0;
  } else {
    rtb_Add_ie = (rtb_Switch2_p > 0.0);
  }

  /* Signum: '<S212>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.BackRight_Drive_Motor_Speed)) {
    rtb_Product_do = (rtNaN);
  } else if (Code_Gen_Model_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Product_do = -1.0;
  } else {
    rtb_Product_do = (Code_Gen_Model_U.BackRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S215>/Add' incorporates:
   *  Sum: '<S216>/Sum'
   */
  rtb_uDLookupTable_l -= Code_Gen_Model_B.BR_Steer_Module_Angle;

  /* Product: '<S147>/Product' incorporates:
   *  Abs: '<S212>/Abs'
   *  Abs: '<S215>/Abs'
   *  Constant: '<S218>/Constant'
   *  Constant: '<S228>/Constant3'
   *  Constant: '<S228>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S212>/OR'
   *  Lookup_n-D: '<S215>/1-D Lookup Table'
   *  Math: '<S228>/Math Function'
   *  RelationalOperator: '<S212>/Equal1'
   *  RelationalOperator: '<S218>/Compare'
   *  Signum: '<S212>/Sign'
   *  Signum: '<S212>/Sign1'
   *  Sum: '<S215>/Add'
   *  Sum: '<S228>/Add1'
   *  Sum: '<S228>/Add2'
   */
  rtb_Switch2_p = (((real_T)((rtb_Add_ie == rtb_Product_do) || (fabs
    (Code_Gen_Model_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_p) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_uDLookupTable_l + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     Code_Gen_Model_ConstP.pooled26, Code_Gen_Model_ConstP.pooled25, 1U);

  /* Gain: '<S213>/Gain' */
  rtb_Switch2_ef = Drive_Motor_Control_FF * rtb_Switch2_p;

  /* Sum: '<S213>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Switch2_p -= Code_Gen_Model_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S220>/Sum1' incorporates:
   *  Constant: '<S213>/Constant2'
   *  Product: '<S220>/Product'
   *  Sum: '<S220>/Sum'
   *  UnitDelay: '<S220>/Unit Delay1'
   */
  rtb_Rotationmatrixfromlocalto_3 = ((rtb_Switch2_p -
    Code_Gen_Model_DW.UnitDelay1_DSTATE_k) * Drive_Motor_Control_D_FilterCoeff)
    + Code_Gen_Model_DW.UnitDelay1_DSTATE_k;

  /* Product: '<S213>/Product' incorporates:
   *  Constant: '<S213>/Constant3'
   */
  rtb_Switch1_p2 = rtb_Rotationmatrixfromlocalto_3 * Drive_Motor_Control_D;

  /* Sum: '<S219>/Diff' incorporates:
   *  UnitDelay: '<S219>/UD'
   *
   * Block description for '<S219>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S219>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ls = rtb_Switch1_p2 - Code_Gen_Model_DW.UD_DSTATE_cs;

  /* Saturate: '<S213>/Saturation' */
  if (rtb_Add_ls > Drive_Motor_Control_D_UL) {
    rtb_Add_ls = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_ls < Drive_Motor_Control_D_LL) {
    rtb_Add_ls = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S213>/Add' incorporates:
   *  Gain: '<S213>/Gain1'
   *  Saturate: '<S213>/Saturation'
   */
  rtb_Rotationmatrixfromlocalto_0 = ((Drive_Motor_Control_P * rtb_Switch2_p) +
    rtb_Switch2_ef) + rtb_Add_ls;

  /* Sum: '<S213>/Subtract' incorporates:
   *  Constant: '<S213>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Rotationmatrixfromlocalto_0;

  /* Sum: '<S213>/Sum2' incorporates:
   *  Gain: '<S213>/Gain2'
   *  UnitDelay: '<S213>/Unit Delay'
   */
  rtb_Switch2_ef = (Drive_Motor_Control_I * rtb_Switch2_p) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_a;

  /* Switch: '<S221>/Switch2' incorporates:
   *  Constant: '<S213>/Constant'
   *  RelationalOperator: '<S221>/LowerRelop1'
   *  Sum: '<S213>/Subtract'
   */
  if (!(rtb_Switch2_ef > (1.0 - rtb_Rotationmatrixfromlocalto_0))) {
    /* Switch: '<S221>/Switch' incorporates:
     *  Constant: '<S213>/Constant1'
     *  RelationalOperator: '<S221>/UpperRelop'
     *  Sum: '<S213>/Subtract1'
     */
    if (rtb_Switch2_ef < (-1.0 - rtb_Rotationmatrixfromlocalto_0)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_Rotationmatrixfromlocalto_0;
    } else {
      rtb_Optimized_Module_Angle = rtb_Switch2_ef;
    }

    /* End of Switch: '<S221>/Switch' */
  }

  /* End of Switch: '<S221>/Switch2' */

  /* Saturate: '<S213>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Drive_Motor_Control_I_UL) {
    rtb_Switch2_ef = Drive_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Drive_Motor_Control_I_LL) {
    rtb_Switch2_ef = Drive_Motor_Control_I_LL;
  } else {
    rtb_Switch2_ef = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S213>/Saturation1' */

  /* Sum: '<S213>/Add1' */
  rtb_Add_ls = rtb_Rotationmatrixfromlocalto_0 + rtb_Switch2_ef;

  /* Saturate: '<S213>/Saturation2' */
  if (rtb_Add_ls > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_ls < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = rtb_Add_ls;
  }

  /* End of Saturate: '<S213>/Saturation2' */

  /* Sum: '<S229>/Add1' incorporates:
   *  Constant: '<S229>/Constant3'
   *  Constant: '<S229>/Constant4'
   *  Math: '<S229>/Math Function'
   *  Sum: '<S229>/Add2'
   */
  rtb_Switch2_p = rt_modd_snf(rtb_uDLookupTable_l + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S231>/Sum1' incorporates:
   *  Constant: '<S216>/Constant2'
   *  Product: '<S231>/Product'
   *  Sum: '<S231>/Sum'
   *  UnitDelay: '<S231>/Unit Delay1'
   */
  rtb_Rotationmatrixfromlocalto_0 = ((rtb_Switch2_p -
    Code_Gen_Model_DW.UnitDelay1_DSTATE_i) *
    Steering_Motor_Control_D_FilterCoeff) +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S216>/Product' incorporates:
   *  Constant: '<S216>/Constant3'
   */
  rtb_Steer_Joystick_X_Rel_Mod = rtb_Rotationmatrixfromlocalto_0 *
    Steering_Motor_Control_D;

  /* Sum: '<S230>/Diff' incorporates:
   *  UnitDelay: '<S230>/UD'
   *
   * Block description for '<S230>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S230>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ls = rtb_Steer_Joystick_X_Rel_Mod - Code_Gen_Model_DW.UD_DSTATE_l;

  /* Saturate: '<S216>/Saturation' */
  if (rtb_Add_ls > Steering_Motor_Control_D_UL) {
    rtb_Add_ls = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_ls < Steering_Motor_Control_D_LL) {
    rtb_Add_ls = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S216>/Add' incorporates:
   *  Gain: '<S216>/Gain1'
   *  Saturate: '<S216>/Saturation'
   */
  rtb_Add_pw = (Steering_Motor_Control_P * rtb_Switch2_p) + rtb_Add_ls;

  /* Sum: '<S216>/Subtract' incorporates:
   *  Constant: '<S216>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Add_pw;

  /* Sum: '<S216>/Sum2' incorporates:
   *  Gain: '<S216>/Gain2'
   *  UnitDelay: '<S216>/Unit Delay'
   */
  rtb_Sum2_fc = (Steering_Motor_Control_I * rtb_Switch2_p) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_l;

  /* Switch: '<S232>/Switch2' incorporates:
   *  Constant: '<S216>/Constant'
   *  RelationalOperator: '<S232>/LowerRelop1'
   *  Sum: '<S216>/Subtract'
   */
  if (!(rtb_Sum2_fc > (1.0 - rtb_Add_pw))) {
    /* Switch: '<S232>/Switch' incorporates:
     *  Constant: '<S216>/Constant1'
     *  RelationalOperator: '<S232>/UpperRelop'
     *  Sum: '<S216>/Subtract1'
     */
    if (rtb_Sum2_fc < (-1.0 - rtb_Add_pw)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_Add_pw;
    } else {
      rtb_Optimized_Module_Angle = rtb_Sum2_fc;
    }

    /* End of Switch: '<S232>/Switch' */
  }

  /* End of Switch: '<S232>/Switch2' */

  /* Saturate: '<S216>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_fc = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S216>/Saturation1' */

  /* Sum: '<S216>/Add1' */
  rtb_Add_ls = rtb_Add_pw + rtb_Sum2_fc;

  /* Saturate: '<S216>/Saturation2' */
  if (rtb_Add_ls > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_ls < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = rtb_Add_ls;
  }

  /* End of Saturate: '<S216>/Saturation2' */

  /* Product: '<S261>/Product' */
  Code_Gen_Model_B.FL_Desired_Wheel_Speed = Code_Gen_Model_B.Switch1_m *
    rtb_Init_e;

  /* Switch: '<S266>/Switch' */
  if (!rtb_Is_Absolute_Steering) {
    /* Switch: '<S266>/Switch' incorporates:
     *  Fcn: '<S267>/x->theta'
     */
    Code_Gen_Model_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Reshapey[1],
      rtb_Reshapey[0]);
  }

  /* End of Switch: '<S266>/Switch' */

  /* Trigonometry: '<S162>/Cos4' incorporates:
   *  Switch: '<S151>/Angle_Switch'
   *  Trigonometry: '<S161>/Cos4'
   */
  rtb_MatrixConcatenate_b_idx_1 = cos(Code_Gen_Model_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S162>/Sin5' incorporates:
   *  UnaryMinus: '<S160>/Unary Minus'
   */
  rtb_uDLookupTable_l = sin(-Code_Gen_Model_B.FL_Steer_Module_Angle);

  /* Trigonometry: '<S162>/Sin4' incorporates:
   *  Switch: '<S151>/Angle_Switch'
   *  Trigonometry: '<S161>/Sin4'
   */
  rtb_Subtract_gn = sin(Code_Gen_Model_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S162>/Cos5' incorporates:
   *  UnaryMinus: '<S160>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Code_Gen_Model_B.FL_Steer_Module_Angle);

  /* Sum: '<S162>/Subtract1' incorporates:
   *  Product: '<S162>/Product2'
   *  Product: '<S162>/Product3'
   *  Trigonometry: '<S162>/Cos4'
   *  Trigonometry: '<S162>/Sin4'
   */
  rtb_Switch2_p = (rtb_MatrixConcatenate_b_idx_1 * rtb_uDLookupTable_l) +
    (rtb_Subtract_gn * rtb_Optimized_Module_Angle);

  /* Sum: '<S162>/Subtract' incorporates:
   *  Product: '<S162>/Product'
   *  Product: '<S162>/Product1'
   *  Trigonometry: '<S162>/Cos4'
   *  Trigonometry: '<S162>/Sin4'
   */
  rtb_Add_pw = (rtb_MatrixConcatenate_b_idx_1 * rtb_Optimized_Module_Angle) -
    (rtb_Subtract_gn * rtb_uDLookupTable_l);

  /* Math: '<S162>/Hypot' */
  rtb_Hypot_g5 = rt_hypotd_snf(rtb_Add_pw, rtb_Switch2_p);

  /* Switch: '<S162>/Switch' incorporates:
   *  Constant: '<S162>/Constant'
   *  Constant: '<S162>/Constant1'
   *  Constant: '<S163>/Constant'
   *  Product: '<S162>/Divide'
   *  Product: '<S162>/Divide1'
   *  RelationalOperator: '<S163>/Compare'
   *  Switch: '<S162>/Switch1'
   */
  if (rtb_Hypot_g5 > 1.0E-6) {
    rtb_Switch2_p /= rtb_Hypot_g5;
    rtb_Optimized_Module_Angle = rtb_Add_pw / rtb_Hypot_g5;
  } else {
    rtb_Switch2_p = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S162>/Switch' */

  /* Switch: '<S151>/Speed_Switch' incorporates:
   *  Abs: '<S151>/Abs'
   *  Constant: '<S159>/Constant'
   *  RelationalOperator: '<S159>/Compare'
   *  Switch: '<S151>/Angle_Switch'
   *  Trigonometry: '<S161>/Atan1'
   *  Trigonometry: '<S162>/Atan1'
   *  UnaryMinus: '<S151>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_p, rtb_Optimized_Module_Angle)) >
      1.5707963267948966) {
    rtb_Add_ie = -Code_Gen_Model_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S161>/Subtract1' incorporates:
     *  Product: '<S161>/Product2'
     *  Product: '<S161>/Product3'
     *  UnaryMinus: '<S151>/Unary Minus'
     */
    rtb_Add_pw = (rtb_MatrixConcatenate_b_idx_1 * Code_Gen_Model_ConstB.Sin5) +
      (rtb_Subtract_gn * Code_Gen_Model_ConstB.Cos5);

    /* Sum: '<S161>/Subtract' incorporates:
     *  Product: '<S161>/Product'
     *  Product: '<S161>/Product1'
     */
    rtb_Subtract_i = (rtb_MatrixConcatenate_b_idx_1 * Code_Gen_Model_ConstB.Cos5)
      - (rtb_Subtract_gn * Code_Gen_Model_ConstB.Sin5);

    /* Math: '<S161>/Hypot' */
    rtb_Hypot_g5 = rt_hypotd_snf(rtb_Subtract_i, rtb_Add_pw);

    /* Switch: '<S161>/Switch1' incorporates:
     *  Constant: '<S161>/Constant'
     *  Constant: '<S161>/Constant1'
     *  Constant: '<S164>/Constant'
     *  Product: '<S161>/Divide'
     *  Product: '<S161>/Divide1'
     *  RelationalOperator: '<S164>/Compare'
     *  Switch: '<S161>/Switch'
     */
    if (rtb_Hypot_g5 > 1.0E-6) {
      rtb_Subtract_i /= rtb_Hypot_g5;
      rtb_Add_pw /= rtb_Hypot_g5;
    } else {
      rtb_Subtract_i = 1.0;
      rtb_Add_pw = 0.0;
    }

    /* End of Switch: '<S161>/Switch1' */
    rtb_uDLookupTable_l = rt_atan2d_snf(rtb_Add_pw, rtb_Subtract_i);
  } else {
    rtb_Add_ie = Code_Gen_Model_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable_l = Code_Gen_Model_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S154>/Product2' incorporates:
   *  Constant: '<S154>/Constant'
   *  Switch: '<S151>/Speed_Switch'
   */
  rtb_Switch2_p = rtb_Add_ie * 1530.1401357649195;

  /* Signum: '<S149>/Sign' */
  if (rtIsNaN(rtb_Switch2_p)) {
    rtb_Add_ie = (rtNaN);
  } else if (rtb_Switch2_p < 0.0) {
    rtb_Add_ie = -1.0;
  } else {
    rtb_Add_ie = (rtb_Switch2_p > 0.0);
  }

  /* Signum: '<S149>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Product_do = (rtNaN);
  } else if (Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Product_do = -1.0;
  } else {
    rtb_Product_do = (Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S152>/Add' incorporates:
   *  Sum: '<S153>/Sum'
   */
  rtb_uDLookupTable_l -= Code_Gen_Model_B.FL_Steer_Module_Angle;

  /* Product: '<S144>/Product' incorporates:
   *  Abs: '<S149>/Abs'
   *  Abs: '<S152>/Abs'
   *  Constant: '<S155>/Constant'
   *  Constant: '<S165>/Constant3'
   *  Constant: '<S165>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S149>/OR'
   *  Lookup_n-D: '<S152>/1-D Lookup Table'
   *  Math: '<S165>/Math Function'
   *  RelationalOperator: '<S149>/Equal1'
   *  RelationalOperator: '<S155>/Compare'
   *  Signum: '<S149>/Sign'
   *  Signum: '<S149>/Sign1'
   *  Sum: '<S152>/Add'
   *  Sum: '<S165>/Add1'
   *  Sum: '<S165>/Add2'
   */
  rtb_Switch2_p = (((real_T)((rtb_Add_ie == rtb_Product_do) || (fabs
    (Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_p) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_uDLookupTable_l + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     Code_Gen_Model_ConstP.pooled26, Code_Gen_Model_ConstP.pooled25, 1U);

  /* Gain: '<S150>/Gain' */
  rtb_Subtract_i = Drive_Motor_Control_FF * rtb_Switch2_p;

  /* Sum: '<S150>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Switch2_p -= Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S157>/Sum1' incorporates:
   *  Constant: '<S150>/Constant2'
   *  Product: '<S157>/Product'
   *  Sum: '<S157>/Sum'
   *  UnitDelay: '<S157>/Unit Delay1'
   */
  rtb_Add_pw = ((rtb_Switch2_p - Code_Gen_Model_DW.UnitDelay1_DSTATE_a) *
                Drive_Motor_Control_D_FilterCoeff) +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_a;

  /* Product: '<S150>/Product' incorporates:
   *  Constant: '<S150>/Constant3'
   */
  rtb_Hypot_g5 = rtb_Add_pw * Drive_Motor_Control_D;

  /* Sum: '<S156>/Diff' incorporates:
   *  UnitDelay: '<S156>/UD'
   *
   * Block description for '<S156>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S156>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ls = rtb_Hypot_g5 - Code_Gen_Model_DW.UD_DSTATE_o;

  /* Saturate: '<S150>/Saturation' */
  if (rtb_Add_ls > Drive_Motor_Control_D_UL) {
    rtb_Add_ls = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_ls < Drive_Motor_Control_D_LL) {
    rtb_Add_ls = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S150>/Add' incorporates:
   *  Gain: '<S150>/Gain1'
   *  Saturate: '<S150>/Saturation'
   */
  rtb_Add_c4 = ((Drive_Motor_Control_P * rtb_Switch2_p) + rtb_Subtract_i) +
    rtb_Add_ls;

  /* Sum: '<S150>/Subtract' incorporates:
   *  Constant: '<S150>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Add_c4;

  /* Sum: '<S150>/Sum2' incorporates:
   *  Gain: '<S150>/Gain2'
   *  UnitDelay: '<S150>/Unit Delay'
   */
  rtb_Switch2_p = (Drive_Motor_Control_I * rtb_Switch2_p) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_f;

  /* Switch: '<S158>/Switch2' incorporates:
   *  Constant: '<S150>/Constant'
   *  RelationalOperator: '<S158>/LowerRelop1'
   *  Sum: '<S150>/Subtract'
   */
  if (!(rtb_Switch2_p > (1.0 - rtb_Add_c4))) {
    /* Switch: '<S158>/Switch' incorporates:
     *  Constant: '<S150>/Constant1'
     *  RelationalOperator: '<S158>/UpperRelop'
     *  Sum: '<S150>/Subtract1'
     */
    if (rtb_Switch2_p < (-1.0 - rtb_Add_c4)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_Add_c4;
    } else {
      rtb_Optimized_Module_Angle = rtb_Switch2_p;
    }

    /* End of Switch: '<S158>/Switch' */
  }

  /* End of Switch: '<S158>/Switch2' */

  /* Saturate: '<S150>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Drive_Motor_Control_I_UL) {
    rtb_Subtract_i = Drive_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Drive_Motor_Control_I_LL) {
    rtb_Subtract_i = Drive_Motor_Control_I_LL;
  } else {
    rtb_Subtract_i = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S150>/Saturation1' */

  /* Sum: '<S150>/Add1' */
  rtb_Add_ls = rtb_Add_c4 + rtb_Subtract_i;

  /* Saturate: '<S150>/Saturation2' */
  if (rtb_Add_ls > 1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_ls < -1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = rtb_Add_ls;
  }

  /* End of Saturate: '<S150>/Saturation2' */

  /* Sum: '<S166>/Add1' incorporates:
   *  Constant: '<S166>/Constant3'
   *  Constant: '<S166>/Constant4'
   *  Math: '<S166>/Math Function'
   *  Sum: '<S166>/Add2'
   */
  rtb_Switch2_p = rt_modd_snf(rtb_uDLookupTable_l + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S168>/Sum1' incorporates:
   *  Constant: '<S153>/Constant2'
   *  Product: '<S168>/Product'
   *  Sum: '<S168>/Sum'
   *  UnitDelay: '<S168>/Unit Delay1'
   */
  rtb_Add_c4 = ((rtb_Switch2_p - Code_Gen_Model_DW.UnitDelay1_DSTATE_b) *
                Steering_Motor_Control_D_FilterCoeff) +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S153>/Product' incorporates:
   *  Constant: '<S153>/Constant3'
   */
  rtb_Product_dq = rtb_Add_c4 * Steering_Motor_Control_D;

  /* Sum: '<S167>/Diff' incorporates:
   *  UnitDelay: '<S167>/UD'
   *
   * Block description for '<S167>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S167>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ls = rtb_Product_dq - Code_Gen_Model_DW.UD_DSTATE_b;

  /* Saturate: '<S153>/Saturation' */
  if (rtb_Add_ls > Steering_Motor_Control_D_UL) {
    rtb_Add_ls = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_ls < Steering_Motor_Control_D_LL) {
    rtb_Add_ls = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S153>/Add' incorporates:
   *  Gain: '<S153>/Gain1'
   *  Saturate: '<S153>/Saturation'
   */
  rtb_MatrixConcatenate_b_idx_1 = (Steering_Motor_Control_P * rtb_Switch2_p) +
    rtb_Add_ls;

  /* Sum: '<S153>/Subtract' incorporates:
   *  Constant: '<S153>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_MatrixConcatenate_b_idx_1;

  /* Sum: '<S153>/Sum2' incorporates:
   *  Gain: '<S153>/Gain2'
   *  UnitDelay: '<S153>/Unit Delay'
   */
  rtb_Switch2_p = (Steering_Motor_Control_I * rtb_Switch2_p) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S169>/Switch2' incorporates:
   *  Constant: '<S153>/Constant'
   *  RelationalOperator: '<S169>/LowerRelop1'
   *  Sum: '<S153>/Subtract'
   */
  if (!(rtb_Switch2_p > (1.0 - rtb_MatrixConcatenate_b_idx_1))) {
    /* Switch: '<S169>/Switch' incorporates:
     *  Constant: '<S153>/Constant1'
     *  RelationalOperator: '<S169>/UpperRelop'
     *  Sum: '<S153>/Subtract1'
     */
    if (rtb_Switch2_p < (-1.0 - rtb_MatrixConcatenate_b_idx_1)) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_MatrixConcatenate_b_idx_1;
    } else {
      rtb_Optimized_Module_Angle = rtb_Switch2_p;
    }

    /* End of Switch: '<S169>/Switch' */
  }

  /* End of Switch: '<S169>/Switch2' */

  /* Saturate: '<S153>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_la = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_la = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_la = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S153>/Saturation1' */

  /* Sum: '<S153>/Add1' */
  rtb_Add_ls = rtb_MatrixConcatenate_b_idx_1 + rtb_Subtract1_la;

  /* Saturate: '<S153>/Saturation2' */
  if (rtb_Add_ls > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_ls < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = rtb_Add_ls;
  }

  /* End of Saturate: '<S153>/Saturation2' */

  /* Product: '<S261>/Product1' */
  Code_Gen_Model_B.FR_Desired_Wheel_Speed = Code_Gen_Model_B.Switch1_o *
    rtb_Init_e;

  /* Switch: '<S271>/Switch' */
  if (!rtb_OR_ao) {
    /* Switch: '<S271>/Switch' incorporates:
     *  Fcn: '<S272>/x->theta'
     */
    Code_Gen_Model_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S271>/Switch' */

  /* Trigonometry: '<S183>/Cos4' incorporates:
   *  Switch: '<S172>/Angle_Switch'
   *  Trigonometry: '<S182>/Cos4'
   */
  rtb_MatrixConcatenate_b_idx_1 = cos(Code_Gen_Model_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S183>/Sin5' incorporates:
   *  UnaryMinus: '<S181>/Unary Minus'
   */
  rtb_uDLookupTable_l = sin(-Code_Gen_Model_B.FR_Steer_Module_Angle);

  /* Trigonometry: '<S183>/Sin4' incorporates:
   *  Switch: '<S172>/Angle_Switch'
   *  Trigonometry: '<S182>/Sin4'
   */
  rtb_Subtract_gn = sin(Code_Gen_Model_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S183>/Cos5' incorporates:
   *  UnaryMinus: '<S181>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Code_Gen_Model_B.FR_Steer_Module_Angle);

  /* Sum: '<S183>/Subtract1' incorporates:
   *  Product: '<S183>/Product2'
   *  Product: '<S183>/Product3'
   *  Trigonometry: '<S183>/Cos4'
   *  Trigonometry: '<S183>/Sin4'
   */
  rtb_Switch2_p = (rtb_MatrixConcatenate_b_idx_1 * rtb_uDLookupTable_l) +
    (rtb_Subtract_gn * rtb_Optimized_Module_Angle);

  /* Sum: '<S183>/Subtract' incorporates:
   *  Product: '<S183>/Product'
   *  Product: '<S183>/Product1'
   *  Trigonometry: '<S183>/Cos4'
   *  Trigonometry: '<S183>/Sin4'
   */
  rtb_Optimized_Module_Angle = (rtb_MatrixConcatenate_b_idx_1 *
    rtb_Optimized_Module_Angle) - (rtb_Subtract_gn * rtb_uDLookupTable_l);

  /* Math: '<S183>/Hypot' */
  rtb_Hypot_b = rt_hypotd_snf(rtb_Optimized_Module_Angle, rtb_Switch2_p);

  /* Switch: '<S183>/Switch' incorporates:
   *  Constant: '<S183>/Constant'
   *  Constant: '<S183>/Constant1'
   *  Constant: '<S184>/Constant'
   *  Product: '<S183>/Divide'
   *  Product: '<S183>/Divide1'
   *  RelationalOperator: '<S184>/Compare'
   *  Switch: '<S183>/Switch1'
   */
  if (rtb_Hypot_b > 1.0E-6) {
    rtb_Switch2_p /= rtb_Hypot_b;
    rtb_Optimized_Module_Angle /= rtb_Hypot_b;
  } else {
    rtb_Switch2_p = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S183>/Switch' */

  /* Switch: '<S172>/Speed_Switch' incorporates:
   *  Abs: '<S172>/Abs'
   *  Constant: '<S180>/Constant'
   *  RelationalOperator: '<S180>/Compare'
   *  Switch: '<S172>/Angle_Switch'
   *  Trigonometry: '<S182>/Atan1'
   *  Trigonometry: '<S183>/Atan1'
   *  UnaryMinus: '<S172>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_p, rtb_Optimized_Module_Angle)) >
      1.5707963267948966) {
    rtb_Add_ie = -Code_Gen_Model_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S182>/Subtract1' incorporates:
     *  Product: '<S182>/Product2'
     *  Product: '<S182>/Product3'
     *  UnaryMinus: '<S172>/Unary Minus'
     */
    rtb_Optimized_Module_Angle = (rtb_MatrixConcatenate_b_idx_1 *
      Code_Gen_Model_ConstB.Sin5_m) + (rtb_Subtract_gn *
      Code_Gen_Model_ConstB.Cos5_g);

    /* Sum: '<S182>/Subtract' incorporates:
     *  Product: '<S182>/Product'
     *  Product: '<S182>/Product1'
     */
    rtb_Subtract_gn = (rtb_MatrixConcatenate_b_idx_1 *
                       Code_Gen_Model_ConstB.Cos5_g) - (rtb_Subtract_gn *
      Code_Gen_Model_ConstB.Sin5_m);

    /* Math: '<S182>/Hypot' */
    rtb_MatrixConcatenate_b_idx_1 = rt_hypotd_snf(rtb_Subtract_gn,
      rtb_Optimized_Module_Angle);

    /* Switch: '<S182>/Switch1' incorporates:
     *  Constant: '<S182>/Constant'
     *  Constant: '<S182>/Constant1'
     *  Constant: '<S185>/Constant'
     *  Product: '<S182>/Divide'
     *  Product: '<S182>/Divide1'
     *  RelationalOperator: '<S185>/Compare'
     *  Switch: '<S182>/Switch'
     */
    if (rtb_MatrixConcatenate_b_idx_1 > 1.0E-6) {
      rtb_Subtract_gn /= rtb_MatrixConcatenate_b_idx_1;
      rtb_Optimized_Module_Angle /= rtb_MatrixConcatenate_b_idx_1;
    } else {
      rtb_Subtract_gn = 1.0;
      rtb_Optimized_Module_Angle = 0.0;
    }

    /* End of Switch: '<S182>/Switch1' */
    rtb_uDLookupTable_l = rt_atan2d_snf(rtb_Optimized_Module_Angle,
      rtb_Subtract_gn);
  } else {
    rtb_Add_ie = Code_Gen_Model_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable_l = Code_Gen_Model_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S175>/Product2' incorporates:
   *  Constant: '<S175>/Constant'
   *  Switch: '<S172>/Speed_Switch'
   */
  rtb_Switch2_p = rtb_Add_ie * 1530.1401357649195;

  /* Signum: '<S170>/Sign' */
  if (rtIsNaN(rtb_Switch2_p)) {
    rtb_Add_ie = (rtNaN);
  } else if (rtb_Switch2_p < 0.0) {
    rtb_Add_ie = -1.0;
  } else {
    rtb_Add_ie = (rtb_Switch2_p > 0.0);
  }

  /* Signum: '<S170>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Product_do = (rtNaN);
  } else if (Code_Gen_Model_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Product_do = -1.0;
  } else {
    rtb_Product_do = (Code_Gen_Model_U.FrontRight_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S173>/Add' incorporates:
   *  Sum: '<S174>/Sum'
   */
  rtb_uDLookupTable_l -= Code_Gen_Model_B.FR_Steer_Module_Angle;

  /* Product: '<S145>/Product' incorporates:
   *  Abs: '<S170>/Abs'
   *  Abs: '<S173>/Abs'
   *  Constant: '<S176>/Constant'
   *  Constant: '<S186>/Constant3'
   *  Constant: '<S186>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S170>/OR'
   *  Lookup_n-D: '<S173>/1-D Lookup Table'
   *  Math: '<S186>/Math Function'
   *  RelationalOperator: '<S170>/Equal1'
   *  RelationalOperator: '<S176>/Compare'
   *  Signum: '<S170>/Sign'
   *  Signum: '<S170>/Sign1'
   *  Sum: '<S173>/Add'
   *  Sum: '<S186>/Add1'
   *  Sum: '<S186>/Add2'
   */
  rtb_Switch2_p = (((real_T)((rtb_Add_ie == rtb_Product_do) || (fabs
    (Code_Gen_Model_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Switch2_p) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_uDLookupTable_l + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     Code_Gen_Model_ConstP.pooled26, Code_Gen_Model_ConstP.pooled25, 1U);

  /* Gain: '<S171>/Gain' */
  rtb_Optimized_Module_Angle = Drive_Motor_Control_FF * rtb_Switch2_p;

  /* Sum: '<S171>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Switch2_p -= Code_Gen_Model_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S178>/Sum1' incorporates:
   *  Constant: '<S171>/Constant2'
   *  Product: '<S178>/Product'
   *  Sum: '<S178>/Sum'
   *  UnitDelay: '<S178>/Unit Delay1'
   */
  rtb_MatrixConcatenate_b_idx_1 = ((rtb_Switch2_p -
    Code_Gen_Model_DW.UnitDelay1_DSTATE_b1) * Drive_Motor_Control_D_FilterCoeff)
    + Code_Gen_Model_DW.UnitDelay1_DSTATE_b1;

  /* Product: '<S171>/Product' incorporates:
   *  Constant: '<S171>/Constant3'
   */
  rtb_Subtract_gn = rtb_MatrixConcatenate_b_idx_1 * Drive_Motor_Control_D;

  /* Sum: '<S177>/Diff' incorporates:
   *  UnitDelay: '<S177>/UD'
   *
   * Block description for '<S177>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S177>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ls = rtb_Subtract_gn - Code_Gen_Model_DW.UD_DSTATE_e;

  /* Saturate: '<S171>/Saturation' */
  if (rtb_Add_ls > Drive_Motor_Control_D_UL) {
    rtb_Add_ls = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_ls < Drive_Motor_Control_D_LL) {
    rtb_Add_ls = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S171>/Add' incorporates:
   *  Gain: '<S171>/Gain1'
   *  Saturate: '<S171>/Saturation'
   */
  rtb_Add_pd = ((Drive_Motor_Control_P * rtb_Switch2_p) +
                rtb_Optimized_Module_Angle) + rtb_Add_ls;

  /* Sum: '<S171>/Subtract' incorporates:
   *  Constant: '<S171>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Add_pd;

  /* Sum: '<S171>/Sum2' incorporates:
   *  Gain: '<S171>/Gain2'
   *  UnitDelay: '<S171>/Unit Delay'
   */
  rtb_Switch2_p = (Drive_Motor_Control_I * rtb_Switch2_p) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_em;

  /* Switch: '<S179>/Switch2' incorporates:
   *  Constant: '<S171>/Constant'
   *  RelationalOperator: '<S179>/LowerRelop1'
   *  Sum: '<S171>/Subtract'
   */
  if (!(rtb_Switch2_p > (1.0 - rtb_Add_pd))) {
    /* Sum: '<S171>/Subtract1' incorporates:
     *  Constant: '<S171>/Constant1'
     */
    rtb_Optimized_Module_Angle = -1.0 - rtb_Add_pd;

    /* Switch: '<S179>/Switch' incorporates:
     *  Constant: '<S171>/Constant1'
     *  RelationalOperator: '<S179>/UpperRelop'
     *  Sum: '<S171>/Subtract1'
     */
    if (!(rtb_Switch2_p < (-1.0 - rtb_Add_pd))) {
      rtb_Optimized_Module_Angle = rtb_Switch2_p;
    }

    /* End of Switch: '<S179>/Switch' */
  }

  /* End of Switch: '<S179>/Switch2' */

  /* Saturate: '<S171>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Drive_Motor_Control_I_UL) {
    rtb_Hypot_b = Drive_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Drive_Motor_Control_I_LL) {
    rtb_Hypot_b = Drive_Motor_Control_I_LL;
  } else {
    rtb_Hypot_b = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S171>/Saturation1' */

  /* Sum: '<S171>/Add1' */
  rtb_Add_ls = rtb_Add_pd + rtb_Hypot_b;

  /* Saturate: '<S171>/Saturation2' */
  if (rtb_Add_ls > 1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_ls < -1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = rtb_Add_ls;
  }

  /* End of Saturate: '<S171>/Saturation2' */

  /* Sum: '<S187>/Add1' incorporates:
   *  Constant: '<S187>/Constant3'
   *  Constant: '<S187>/Constant4'
   *  Math: '<S187>/Math Function'
   *  Sum: '<S187>/Add2'
   */
  rtb_Switch2_p = rt_modd_snf(rtb_uDLookupTable_l + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S189>/Sum1' incorporates:
   *  Constant: '<S174>/Constant2'
   *  Product: '<S189>/Product'
   *  Sum: '<S189>/Sum'
   *  UnitDelay: '<S189>/Unit Delay1'
   */
  rtb_uDLookupTable_l = ((rtb_Switch2_p - Code_Gen_Model_DW.UnitDelay1_DSTATE_n)
    * Steering_Motor_Control_D_FilterCoeff) +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S174>/Product' incorporates:
   *  Constant: '<S174>/Constant3'
   */
  rtb_Add_pd = rtb_uDLookupTable_l * Steering_Motor_Control_D;

  /* Sum: '<S188>/Diff' incorporates:
   *  UnitDelay: '<S188>/UD'
   *
   * Block description for '<S188>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S188>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ls = rtb_Add_pd - Code_Gen_Model_DW.UD_DSTATE_i1;

  /* Saturate: '<S174>/Saturation' */
  if (rtb_Add_ls > Steering_Motor_Control_D_UL) {
    rtb_Add_ls = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_ls < Steering_Motor_Control_D_LL) {
    rtb_Add_ls = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S174>/Add' incorporates:
   *  Gain: '<S174>/Gain1'
   *  Saturate: '<S174>/Saturation'
   */
  rtb_Add_ie = (Steering_Motor_Control_P * rtb_Switch2_p) + rtb_Add_ls;

  /* Sum: '<S174>/Subtract' incorporates:
   *  Constant: '<S174>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Add_ie;

  /* Sum: '<S174>/Sum2' incorporates:
   *  Gain: '<S174>/Gain2'
   *  UnitDelay: '<S174>/Unit Delay'
   */
  rtb_Switch2_p = (Steering_Motor_Control_I * rtb_Switch2_p) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S190>/Switch2' incorporates:
   *  Constant: '<S174>/Constant'
   *  RelationalOperator: '<S190>/LowerRelop1'
   *  Sum: '<S174>/Subtract'
   */
  if (!(rtb_Switch2_p > (1.0 - rtb_Add_ie))) {
    /* Sum: '<S174>/Subtract1' incorporates:
     *  Constant: '<S174>/Constant1'
     */
    rtb_Optimized_Module_Angle = -1.0 - rtb_Add_ie;

    /* Switch: '<S190>/Switch' incorporates:
     *  Constant: '<S174>/Constant1'
     *  RelationalOperator: '<S190>/UpperRelop'
     *  Sum: '<S174>/Subtract1'
     */
    if (!(rtb_Switch2_p < (-1.0 - rtb_Add_ie))) {
      rtb_Optimized_Module_Angle = rtb_Switch2_p;
    }

    /* End of Switch: '<S190>/Switch' */
  }

  /* End of Switch: '<S190>/Switch2' */

  /* Saturate: '<S174>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Integral_kz = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Integral_kz = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_kz = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S174>/Saturation1' */

  /* Sum: '<S174>/Add1' */
  rtb_Add_ls = rtb_Add_ie + rtb_Integral_kz;

  /* Saturate: '<S174>/Saturation2' */
  if (rtb_Add_ls > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_ls < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = rtb_Add_ls;
  }

  /* End of Saturate: '<S174>/Saturation2' */

  /* Product: '<S261>/Product2' */
  Code_Gen_Model_B.BL_Desired_Wheel_Speed = Code_Gen_Model_B.Switch1_p *
    rtb_Init_e;

  /* Switch: '<S276>/Switch' */
  if (!rtb_Switch_b1) {
    /* Switch: '<S276>/Switch' incorporates:
     *  Fcn: '<S277>/x->theta'
     */
    Code_Gen_Model_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2_f[1],
      rtb_Add2_f[0]);
  }

  /* End of Switch: '<S276>/Switch' */

  /* Trigonometry: '<S204>/Cos4' incorporates:
   *  Switch: '<S193>/Angle_Switch'
   *  Trigonometry: '<S203>/Cos4'
   */
  rtb_Add_ie = cos(Code_Gen_Model_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S204>/Sin5' incorporates:
   *  UnaryMinus: '<S202>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Code_Gen_Model_B.BL_Steer_Module_Angle);

  /* Trigonometry: '<S204>/Sin4' incorporates:
   *  Switch: '<S193>/Angle_Switch'
   *  Trigonometry: '<S203>/Sin4'
   */
  rtb_Product_do = sin(Code_Gen_Model_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S204>/Cos5' incorporates:
   *  UnaryMinus: '<S202>/Unary Minus'
   */
  rtb_Switch2_p = cos(-Code_Gen_Model_B.BL_Steer_Module_Angle);

  /* Sum: '<S204>/Subtract1' incorporates:
   *  Product: '<S204>/Product2'
   *  Product: '<S204>/Product3'
   *  Trigonometry: '<S204>/Cos4'
   *  Trigonometry: '<S204>/Sin4'
   */
  rtb_Init_e = (rtb_Add_ie * rtb_Optimized_Module_Angle) + (rtb_Product_do *
    rtb_Switch2_p);

  /* Sum: '<S204>/Subtract' incorporates:
   *  Product: '<S204>/Product'
   *  Product: '<S204>/Product1'
   *  Trigonometry: '<S204>/Cos4'
   *  Trigonometry: '<S204>/Sin4'
   */
  rtb_Switch2_p = (rtb_Add_ie * rtb_Switch2_p) - (rtb_Product_do *
    rtb_Optimized_Module_Angle);

  /* Math: '<S204>/Hypot' */
  rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_Switch2_p, rtb_Init_e);

  /* Switch: '<S204>/Switch' incorporates:
   *  Constant: '<S204>/Constant'
   *  Constant: '<S204>/Constant1'
   *  Constant: '<S205>/Constant'
   *  Product: '<S204>/Divide'
   *  Product: '<S204>/Divide1'
   *  RelationalOperator: '<S205>/Compare'
   *  Switch: '<S204>/Switch1'
   */
  if (rtb_Optimized_Module_Angle > 1.0E-6) {
    rtb_Init_e /= rtb_Optimized_Module_Angle;
    rtb_Switch2_p /= rtb_Optimized_Module_Angle;
  } else {
    rtb_Init_e = 0.0;
    rtb_Switch2_p = 1.0;
  }

  /* End of Switch: '<S204>/Switch' */

  /* Switch: '<S193>/Speed_Switch' incorporates:
   *  Abs: '<S193>/Abs'
   *  Constant: '<S201>/Constant'
   *  RelationalOperator: '<S201>/Compare'
   *  Switch: '<S193>/Angle_Switch'
   *  Trigonometry: '<S203>/Atan1'
   *  Trigonometry: '<S204>/Atan1'
   *  UnaryMinus: '<S193>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Init_e, rtb_Switch2_p)) > 1.5707963267948966) {
    rtb_Init_e = -Code_Gen_Model_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S203>/Subtract1' incorporates:
     *  Product: '<S203>/Product2'
     *  Product: '<S203>/Product3'
     *  UnaryMinus: '<S193>/Unary Minus'
     */
    rtb_Switch2_p = (rtb_Add_ie * Code_Gen_Model_ConstB.Sin5_e) +
      (rtb_Product_do * Code_Gen_Model_ConstB.Cos5_i);

    /* Sum: '<S203>/Subtract' incorporates:
     *  Product: '<S203>/Product'
     *  Product: '<S203>/Product1'
     */
    rtb_Add_ie = (rtb_Add_ie * Code_Gen_Model_ConstB.Cos5_i) - (rtb_Product_do *
      Code_Gen_Model_ConstB.Sin5_e);

    /* Math: '<S203>/Hypot' */
    rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_Add_ie, rtb_Switch2_p);

    /* Switch: '<S203>/Switch1' incorporates:
     *  Constant: '<S203>/Constant'
     *  Constant: '<S203>/Constant1'
     *  Constant: '<S206>/Constant'
     *  Product: '<S203>/Divide'
     *  Product: '<S203>/Divide1'
     *  RelationalOperator: '<S206>/Compare'
     *  Switch: '<S203>/Switch'
     */
    if (rtb_Optimized_Module_Angle > 1.0E-6) {
      rtb_Add_ie /= rtb_Optimized_Module_Angle;
      rtb_Switch2_p /= rtb_Optimized_Module_Angle;
    } else {
      rtb_Add_ie = 1.0;
      rtb_Switch2_p = 0.0;
    }

    /* End of Switch: '<S203>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Switch2_p, rtb_Add_ie);
  } else {
    rtb_Init_e = Code_Gen_Model_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.BL_Desired_Module_Angle;
  }

  /* End of Switch: '<S193>/Speed_Switch' */

  /* Product: '<S196>/Product2' incorporates:
   *  Constant: '<S196>/Constant'
   */
  rtb_Init_e *= 1530.1401357649195;

  /* Signum: '<S191>/Sign' */
  if (rtIsNaN(rtb_Init_e)) {
    rtb_Add_ie = (rtNaN);
  } else if (rtb_Init_e < 0.0) {
    rtb_Add_ie = -1.0;
  } else {
    rtb_Add_ie = (rtb_Init_e > 0.0);
  }

  /* Signum: '<S191>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Product_do = (rtNaN);
  } else if (Code_Gen_Model_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Product_do = -1.0;
  } else {
    rtb_Product_do = (Code_Gen_Model_U.BackLeft_Drive_Motor_Speed > 0.0);
  }

  /* Sum: '<S194>/Add' incorporates:
   *  Sum: '<S195>/Sum'
   */
  rtb_Optimized_Module_Angle -= Code_Gen_Model_B.BL_Steer_Module_Angle;

  /* Product: '<S146>/Product' incorporates:
   *  Abs: '<S191>/Abs'
   *  Abs: '<S194>/Abs'
   *  Constant: '<S197>/Constant'
   *  Constant: '<S207>/Constant3'
   *  Constant: '<S207>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S191>/OR'
   *  Lookup_n-D: '<S194>/1-D Lookup Table'
   *  Math: '<S207>/Math Function'
   *  RelationalOperator: '<S191>/Equal1'
   *  RelationalOperator: '<S197>/Compare'
   *  Signum: '<S191>/Sign'
   *  Signum: '<S191>/Sign1'
   *  Sum: '<S194>/Add'
   *  Sum: '<S207>/Add1'
   *  Sum: '<S207>/Add2'
   */
  rtb_Init_e = (((real_T)((rtb_Add_ie == rtb_Product_do) || (fabs
    (Code_Gen_Model_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband))) * rtb_Init_e) * look1_binlcpw
    (fabs(rt_modd_snf(rtb_Optimized_Module_Angle + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     Code_Gen_Model_ConstP.pooled26, Code_Gen_Model_ConstP.pooled25, 1U);

  /* Gain: '<S192>/Gain' */
  rtb_Switch2_p = Drive_Motor_Control_FF * rtb_Init_e;

  /* Sum: '<S192>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Init_e -= Code_Gen_Model_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S199>/Sum1' incorporates:
   *  Constant: '<S192>/Constant2'
   *  Product: '<S199>/Product'
   *  Sum: '<S199>/Sum'
   *  UnitDelay: '<S199>/Unit Delay1'
   */
  rtb_Add_ie = ((rtb_Init_e - Code_Gen_Model_DW.UnitDelay1_DSTATE_f) *
                Drive_Motor_Control_D_FilterCoeff) +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S192>/Product' incorporates:
   *  Constant: '<S192>/Constant3'
   */
  rtb_Product_do = rtb_Add_ie * Drive_Motor_Control_D;

  /* Sum: '<S198>/Diff' incorporates:
   *  UnitDelay: '<S198>/UD'
   *
   * Block description for '<S198>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S198>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ls = rtb_Product_do - Code_Gen_Model_DW.UD_DSTATE_lh;

  /* Saturate: '<S192>/Saturation' */
  if (rtb_Add_ls > Drive_Motor_Control_D_UL) {
    rtb_Add_ls = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_ls < Drive_Motor_Control_D_LL) {
    rtb_Add_ls = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S192>/Add' incorporates:
   *  Gain: '<S192>/Gain1'
   *  Saturate: '<S192>/Saturation'
   */
  rtb_Add_nh = ((Drive_Motor_Control_P * rtb_Init_e) + rtb_Switch2_p) +
    rtb_Add_ls;

  /* Sum: '<S192>/Subtract' incorporates:
   *  Constant: '<S192>/Constant'
   */
  rtb_Switch2_p = 1.0 - rtb_Add_nh;

  /* Sum: '<S192>/Sum2' incorporates:
   *  Gain: '<S192>/Gain2'
   *  UnitDelay: '<S192>/Unit Delay'
   */
  rtb_Init_e = (Drive_Motor_Control_I * rtb_Init_e) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_gp;

  /* Switch: '<S200>/Switch2' incorporates:
   *  Constant: '<S192>/Constant'
   *  RelationalOperator: '<S200>/LowerRelop1'
   *  Sum: '<S192>/Subtract'
   */
  if (!(rtb_Init_e > (1.0 - rtb_Add_nh))) {
    /* Sum: '<S192>/Subtract1' incorporates:
     *  Constant: '<S192>/Constant1'
     */
    rtb_Switch2_p = -1.0 - rtb_Add_nh;

    /* Switch: '<S200>/Switch' incorporates:
     *  Constant: '<S192>/Constant1'
     *  RelationalOperator: '<S200>/UpperRelop'
     *  Sum: '<S192>/Subtract1'
     */
    if (!(rtb_Init_e < (-1.0 - rtb_Add_nh))) {
      rtb_Switch2_p = rtb_Init_e;
    }

    /* End of Switch: '<S200>/Switch' */
  }

  /* End of Switch: '<S200>/Switch2' */

  /* Saturate: '<S192>/Saturation1' */
  if (rtb_Switch2_p > Drive_Motor_Control_I_UL) {
    rtb_Integral_m = Drive_Motor_Control_I_UL;
  } else if (rtb_Switch2_p < Drive_Motor_Control_I_LL) {
    rtb_Integral_m = Drive_Motor_Control_I_LL;
  } else {
    rtb_Integral_m = rtb_Switch2_p;
  }

  /* End of Saturate: '<S192>/Saturation1' */

  /* Sum: '<S192>/Add1' */
  rtb_Add_ls = rtb_Add_nh + rtb_Integral_m;

  /* Saturate: '<S192>/Saturation2' */
  if (rtb_Add_ls > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_ls < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = rtb_Add_ls;
  }

  /* End of Saturate: '<S192>/Saturation2' */

  /* Sum: '<S208>/Add1' incorporates:
   *  Constant: '<S208>/Constant3'
   *  Constant: '<S208>/Constant4'
   *  Math: '<S208>/Math Function'
   *  Sum: '<S208>/Add2'
   */
  rtb_Init_e = rt_modd_snf(rtb_Optimized_Module_Angle + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S210>/Sum1' incorporates:
   *  Constant: '<S195>/Constant2'
   *  Product: '<S210>/Product'
   *  Sum: '<S210>/Sum'
   *  UnitDelay: '<S210>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = ((rtb_Init_e -
    Code_Gen_Model_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff) +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S195>/Product' incorporates:
   *  Constant: '<S195>/Constant3'
   */
  rtb_Add_nh = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S209>/Diff' incorporates:
   *  UnitDelay: '<S209>/UD'
   *
   * Block description for '<S209>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S209>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ls = rtb_Add_nh - Code_Gen_Model_DW.UD_DSTATE_k;

  /* Saturate: '<S195>/Saturation' */
  if (rtb_Add_ls > Steering_Motor_Control_D_UL) {
    rtb_Add_ls = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_ls < Steering_Motor_Control_D_LL) {
    rtb_Add_ls = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S195>/Add' incorporates:
   *  Gain: '<S195>/Gain1'
   *  Saturate: '<S195>/Saturation'
   */
  rtb_Add_ls += Steering_Motor_Control_P * rtb_Init_e;

  /* Sum: '<S195>/Subtract' incorporates:
   *  Constant: '<S195>/Constant'
   */
  rtb_Switch2_p = 1.0 - rtb_Add_ls;

  /* Sum: '<S195>/Sum2' incorporates:
   *  Gain: '<S195>/Gain2'
   *  UnitDelay: '<S195>/Unit Delay'
   */
  rtb_Init_e = (Steering_Motor_Control_I * rtb_Init_e) +
    Code_Gen_Model_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S211>/Switch2' incorporates:
   *  Constant: '<S195>/Constant'
   *  RelationalOperator: '<S211>/LowerRelop1'
   *  Sum: '<S195>/Subtract'
   */
  if (!(rtb_Init_e > (1.0 - rtb_Add_ls))) {
    /* Sum: '<S195>/Subtract1' incorporates:
     *  Constant: '<S195>/Constant1'
     */
    rtb_Switch2_p = -1.0 - rtb_Add_ls;

    /* Switch: '<S211>/Switch' incorporates:
     *  Constant: '<S195>/Constant1'
     *  RelationalOperator: '<S211>/UpperRelop'
     *  Sum: '<S195>/Subtract1'
     */
    if (!(rtb_Init_e < (-1.0 - rtb_Add_ls))) {
      rtb_Switch2_p = rtb_Init_e;
    }

    /* End of Switch: '<S211>/Switch' */
  }

  /* End of Switch: '<S211>/Switch2' */

  /* Saturate: '<S195>/Saturation1' */
  if (rtb_Switch2_p > Steering_Motor_Control_I_UL) {
    rtb_Init_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_p < Steering_Motor_Control_I_LL) {
    rtb_Init_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Init_e = rtb_Switch2_p;
  }

  /* End of Saturate: '<S195>/Saturation1' */

  /* Sum: '<S195>/Add1' */
  rtb_Add_ls += rtb_Init_e;

  /* Saturate: '<S195>/Saturation2' */
  if (rtb_Add_ls > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_ls < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = rtb_Add_ls;
  }

  /* End of Saturate: '<S195>/Saturation2' */

  /* RelationalOperator: '<S78>/Compare' incorporates:
   *  Constant: '<S77>/Constant'
   *  Constant: '<S78>/Constant'
   */
  rtb_Switch_b1 = (Odometry_X_Y_TEAR != 0.0);

  /* DiscreteIntegrator: '<S8>/Accumulator2' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S8>/Constant'
   */
  if ((Odometry_Reset_IC > 0.0) &&
      (Code_Gen_Model_DW.Accumulator2_PrevResetState <= 0)) {
    Code_Gen_Model_DW.Accumulator2_DSTATE = Odometry_IC_X;
  }

  /* DiscreteIntegrator: '<S8>/Accumulator2' */
  Code_Gen_Model_B.Odom_Position_X = Code_Gen_Model_DW.Accumulator2_DSTATE;

  /* Gain: '<S77>/meters to feet' */
  Code_Gen_Model_B.Odometry_X_global_est_ft = 3.28084 *
    Code_Gen_Model_B.Odom_Position_X;

  /* Switch: '<S77>/Switch' incorporates:
   *  UnitDelay: '<S77>/Unit Delay'
   */
  if (rtb_Switch_b1) {
    rtb_Switch2_p = Code_Gen_Model_B.Odometry_X_global_est_ft;
  } else {
    rtb_Switch2_p = Code_Gen_Model_DW.UnitDelay_DSTATE_c;
  }

  /* End of Switch: '<S77>/Switch' */

  /* Sum: '<S77>/Subtract' */
  Code_Gen_Model_B.Odometry_X_global_TEAR_ft =
    Code_Gen_Model_B.Odometry_X_global_est_ft - rtb_Switch2_p;

  /* DiscreteIntegrator: '<S8>/Accumulator' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S8>/Constant'
   */
  if ((Odometry_Reset_IC > 0.0) && (Code_Gen_Model_DW.Accumulator_PrevResetState
       <= 0)) {
    Code_Gen_Model_DW.Accumulator_DSTATE = Odometry_IC_Y;
  }

  /* DiscreteIntegrator: '<S8>/Accumulator' */
  Code_Gen_Model_B.Odom_Position_Y = Code_Gen_Model_DW.Accumulator_DSTATE;

  /* Gain: '<S77>/meters to feet1' */
  Code_Gen_Model_B.Odometry_Y_global_est_ft = 3.28084 *
    Code_Gen_Model_B.Odom_Position_Y;

  /* Switch: '<S77>/Switch1' incorporates:
   *  UnitDelay: '<S77>/Unit Delay1'
   */
  if (rtb_Switch_b1) {
    rtb_Add_ls = Code_Gen_Model_B.Odometry_Y_global_est_ft;
  } else {
    rtb_Add_ls = Code_Gen_Model_DW.UnitDelay1_DSTATE_d;
  }

  /* End of Switch: '<S77>/Switch1' */

  /* Sum: '<S77>/Subtract1' */
  Code_Gen_Model_B.Odometry_Y_global_TEAR_ft =
    Code_Gen_Model_B.Odometry_Y_global_est_ft - rtb_Add_ls;

  /* Update for UnitDelay: '<S69>/UD' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Rev'
   *
   * Block description for '<S69>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE = Code_Gen_Model_U.FrontLeft_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S70>/UD' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Rev'
   *
   * Block description for '<S70>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_m = Code_Gen_Model_U.FrontRight_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S71>/UD' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Rev'
   *
   * Block description for '<S71>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_i = Code_Gen_Model_U.BackLeft_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S72>/UD' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Rev'
   *
   * Block description for '<S72>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_c = Code_Gen_Model_U.BackRight_Drive_Motor_Rev;
  for (rtb_Num_Segments = 0; rtb_Num_Segments < 5; rtb_Num_Segments++) {
    /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay' incorporates:
     *  Bias: '<S107>/Bias'
     *  Merge: '<S81>/Merge1'
     *  S-Function (sfix_udelay): '<S6>/Tapped Delay1'
     */
    Code_Gen_Model_DW.TappedDelay_X[rtb_Num_Segments] =
      Code_Gen_Model_DW.TappedDelay_X[rtb_Num_Segments + 1];

    /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay1' incorporates:
     *  Bias: '<S107>/Bias'
     *  Merge: '<S81>/Merge1'
     *  S-Function (sfix_udelay): '<S6>/Tapped Delay'
     */
    Code_Gen_Model_DW.TappedDelay1_X[rtb_Num_Segments] =
      Code_Gen_Model_DW.TappedDelay1_X[rtb_Num_Segments + 1];
  }

  /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay' */
  Code_Gen_Model_DW.TappedDelay_X[5] = Code_Gen_Model_B.Product6[0];

  /* Update for S-Function (sfix_udelay): '<S6>/Tapped Delay1' */
  Code_Gen_Model_DW.TappedDelay1_X[5] = Code_Gen_Model_B.Product6[1];

  /* Update for Delay: '<S14>/MemoryX' */
  Code_Gen_Model_DW.icLoad = false;

  /* Product: '<S34>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S14>/A'
   *  Delay: '<S14>/MemoryX'
   */
  tmp_0 = (0.0 * Code_Gen_Model_DW.MemoryX_DSTATE[1]) +
    Code_Gen_Model_DW.MemoryX_DSTATE[0];
  tmp_1 = (0.0 * Code_Gen_Model_DW.MemoryX_DSTATE[0]) +
    Code_Gen_Model_DW.MemoryX_DSTATE[1];

  /* Update for Delay: '<S14>/MemoryX' incorporates:
   *  Constant: '<S14>/B'
   *  Product: '<S34>/A[k]*xhat[k|k-1]'
   *  Product: '<S34>/B[k]*u[k]'
   *  Sum: '<S34>/Add'
   */
  Code_Gen_Model_DW.MemoryX_DSTATE[0] = (((0.0 * Code_Gen_Model_B.Product6[1]) +
    Code_Gen_Model_B.Product6[0]) + tmp_0) + Code_Gen_Model_B.Product3[0];
  Code_Gen_Model_DW.MemoryX_DSTATE[1] = (((0.0 * Code_Gen_Model_B.Product6[0]) +
    Code_Gen_Model_B.Product6[1]) + tmp_1) + Code_Gen_Model_B.Product3[1];

  /* Update for UnitDelay: '<S68>/UD'
   *
   * Block description for '<S68>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_d = rtb_thetay;

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_ll =
    Code_Gen_Model_B.Robot_Reached_Destination;

  /* Update for UnitDelay: '<S244>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S244>/FixPt Constant'
   */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S258>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S257>/UD'
   *
   * Block description for '<S257>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_a = rtb_Rotationmatrixfromlocalto_1;

  /* Update for UnitDelay: '<S255>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_m = rtb_Rotationmatrixfromlocalto_2;

  /* Update for UnitDelay: '<S253>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S253>/FixPt Constant'
   */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S220>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_k = rtb_Rotationmatrixfromlocalto_3;

  /* Update for UnitDelay: '<S219>/UD'
   *
   * Block description for '<S219>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_cs = rtb_Switch1_p2;

  /* Update for UnitDelay: '<S213>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_a = rtb_Switch2_ef;

  /* Update for UnitDelay: '<S231>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_i = rtb_Rotationmatrixfromlocalto_0;

  /* Update for UnitDelay: '<S230>/UD'
   *
   * Block description for '<S230>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_l = rtb_Steer_Joystick_X_Rel_Mod;

  /* Update for UnitDelay: '<S216>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_l = rtb_Sum2_fc;

  /* Update for UnitDelay: '<S157>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_a = rtb_Add_pw;

  /* Update for UnitDelay: '<S156>/UD'
   *
   * Block description for '<S156>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_o = rtb_Hypot_g5;

  /* Update for UnitDelay: '<S150>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_f = rtb_Subtract_i;

  /* Update for UnitDelay: '<S168>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_b = rtb_Add_c4;

  /* Update for UnitDelay: '<S167>/UD'
   *
   * Block description for '<S167>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_b = rtb_Product_dq;

  /* Update for UnitDelay: '<S153>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_e = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S178>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_b1 = rtb_MatrixConcatenate_b_idx_1;

  /* Update for UnitDelay: '<S177>/UD'
   *
   * Block description for '<S177>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_e = rtb_Subtract_gn;

  /* Update for UnitDelay: '<S171>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_em = rtb_Hypot_b;

  /* Update for UnitDelay: '<S189>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_n = rtb_uDLookupTable_l;

  /* Update for UnitDelay: '<S188>/UD'
   *
   * Block description for '<S188>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_i1 = rtb_Add_pd;

  /* Update for UnitDelay: '<S174>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_dt = rtb_Integral_kz;

  /* Update for UnitDelay: '<S199>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_f = rtb_Add_ie;

  /* Update for UnitDelay: '<S198>/UD'
   *
   * Block description for '<S198>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_lh = rtb_Product_do;

  /* Update for UnitDelay: '<S192>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_gp = rtb_Integral_m;

  /* Update for UnitDelay: '<S210>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S209>/UD'
   *
   * Block description for '<S209>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_k = rtb_Add_nh;

  /* Update for UnitDelay: '<S195>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_k = rtb_Init_e;

  /* Update for DiscreteIntegrator: '<S8>/Accumulator2' incorporates:
   *  Constant: '<S8>/Constant'
   *  DiscreteIntegrator: '<S8>/Accumulator'
   */
  Code_Gen_Model_DW.Accumulator2_DSTATE += Code_Gen_Model_B.Product6[0];
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

  /* Update for UnitDelay: '<S77>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_c = rtb_Switch2_p;

  /* Update for DiscreteIntegrator: '<S8>/Accumulator' */
  Code_Gen_Model_DW.Accumulator_DSTATE += Code_Gen_Model_B.Product6[1];

  /* Update for UnitDelay: '<S77>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_d = rtb_Add_ls;
}

/* Model initialize function */
void Code_Gen_Model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  {
    real_T Constant;
    real_T Constant1;

    /* Start for SwitchCase: '<S1>/Switch Case' */
    Code_Gen_Model_DW.SwitchCase_ActiveSubsystem = -1;

    /* Start for If: '<S9>/If' */
    Code_Gen_Model_DW.If_ActiveSubsystem = -1;

    /* Start for Constant: '<S1>/Constant' */
    Constant = Odometry_IC_X;

    /* Start for Constant: '<S1>/Constant1' */
    Constant1 = Odometry_IC_Y;

    /* InitializeConditions for Delay: '<S14>/MemoryX' */
    Code_Gen_Model_DW.icLoad = true;

    /* InitializeConditions for UnitDelay: '<S244>/FixPt Unit Delay2' */
    Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE = 1U;

    /* InitializeConditions for UnitDelay: '<S253>/FixPt Unit Delay2' */
    Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c = 1U;

    /* InitializeConditions for DiscreteIntegrator: '<S8>/Accumulator2' */
    Code_Gen_Model_DW.Accumulator2_DSTATE = Constant;
    Code_Gen_Model_DW.Accumulator2_PrevResetState = 2;

    /* InitializeConditions for DiscreteIntegrator: '<S8>/Accumulator' */
    Code_Gen_Model_DW.Accumulator_DSTATE = Constant1;
    Code_Gen_Model_DW.Accumulator_PrevResetState = 2;

    /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
    /* InitializeConditions for UnitDelay: '<S304>/FixPt Unit Delay2' */
    Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a = 1U;

    /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

    /* SystemInitialize for IfAction SubSystem: '<S9>/Spline Path Following Enabled' */
    /* Start for If: '<S85>/If' */
    Code_Gen_Model_DW.If_ActiveSubsystem_h = -1;

    /* InitializeConditions for UnitDelay: '<S81>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_gh = 2.0;

    /* SystemInitialize for IfAction SubSystem: '<S85>/Robot_Index_Is_Valid' */
    /* Start for If: '<S88>/If' */
    Code_Gen_Model_DW.If_ActiveSubsystem_o = -1;

    /* SystemInitialize for IfAction SubSystem: '<S88>/Circle_Check_Valid' */
    /* Start for If: '<S90>/If' */
    Code_Gen_Model_DW.If_ActiveSubsystem_d = -1;

    /* End of SystemInitialize for SubSystem: '<S88>/Circle_Check_Valid' */
    /* End of SystemInitialize for SubSystem: '<S85>/Robot_Index_Is_Valid' */
    /* End of SystemInitialize for SubSystem: '<S9>/Spline Path Following Enabled' */
  }
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
