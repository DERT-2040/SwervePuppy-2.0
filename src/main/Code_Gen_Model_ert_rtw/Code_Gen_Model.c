/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.27
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Dec 28 16:17:13 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
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
                                      * Referenced by: '<S247>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 3.658;/* Variable: Boost_Trigger_High_Speed
                                         * Referenced by:
                                         *   '<S245>/Constant'
                                         *   '<S245>/Saturation'
                                         */
real_T Boost_Trigger_Increasing_Limit = 0.04;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S247>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S245>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S96>/Constant3'
                                        *   '<S117>/Constant3'
                                        *   '<S138>/Constant3'
                                        *   '<S159>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S96>/Constant2'
                                   *   '<S117>/Constant2'
                                   *   '<S138>/Constant2'
                                   *   '<S159>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S96>/Saturation'
                                        *   '<S117>/Saturation'
                                        *   '<S138>/Saturation'
                                        *   '<S159>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S96>/Saturation'
                                        *   '<S117>/Saturation'
                                        *   '<S138>/Saturation'
                                        *   '<S159>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00018182;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S96>/Gain'
                                            *   '<S117>/Gain'
                                            *   '<S138>/Gain'
                                            *   '<S159>/Gain'
                                            */
real_T Drive_Motor_Control_I = 0.0;    /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S96>/Gain2'
                                        *   '<S117>/Gain2'
                                        *   '<S138>/Gain2'
                                        *   '<S159>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = 0.0; /* Variable: Drive_Motor_Control_I_LL
                                        * Referenced by:
                                        *   '<S96>/Saturation1'
                                        *   '<S117>/Saturation1'
                                        *   '<S138>/Saturation1'
                                        *   '<S159>/Saturation1'
                                        */
real_T Drive_Motor_Control_I_UL = 0.0; /* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S96>/Saturation1'
                                        *   '<S117>/Saturation1'
                                        *   '<S138>/Saturation1'
                                        *   '<S159>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S96>/Gain1'
                                        *   '<S117>/Gain1'
                                        *   '<S138>/Gain1'
                                        *   '<S159>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 1500.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S101>/Constant'
                            *   '<S122>/Constant'
                            *   '<S143>/Constant'
                            *   '<S164>/Constant'
                            */
real_T Odometry_Desired_X = 0.0;       /* Variable: Odometry_Desired_X
                                        * Referenced by: '<S2>/Constant7'
                                        */
real_T Odometry_Desired_Y = 0.0;       /* Variable: Odometry_Desired_Y
                                        * Referenced by: '<S2>/Constant8'
                                        */
real_T Odometry_Reset_IC = 0.0;        /* Variable: Odometry_Reset_IC
                                        * Referenced by: '<S7>/Constant'
                                        */
real_T Odometry_X_Y_TEAR = 0.0;        /* Variable: Odometry_X_Y_TEAR
                                        * Referenced by: '<S22>/Constant'
                                        */
real_T Spline_Capture_Radius = 0.1;    /* Variable: Spline_Capture_Radius
                                        * Referenced by:
                                        *   '<S36>/Constant'
                                        *   '<S37>/Constant'
                                        */
real_T Spline_Last_Pose_Distance_to_Velocity_Gain = 2.0;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S81>/Constant2'
                          */
real_T Spline_Lookahead_Dist = 0.2;    /* Variable: Spline_Lookahead_Dist
                                        * Referenced by: '<S27>/Lookahead Distance'
                                        */
real_T Spline_Max_Centripital_Acceleration = 3.0;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S81>/Constant1'
                                 */
real_T Spline_Pose_Num_Before_End_Reduce_Speed = 2.0;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S27>/Constant'
                             */
real_T Spline_Velocity_Multiplier_TEST = 1.0;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S81>/Constant3'
                                     */
real_T Steering_Abs_Deadband_Range = 0.7;/* Variable: Steering_Abs_Deadband_Range
                                          * Referenced by: '<S235>/Constant2'
                                          */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S201>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S201>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S201>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S201>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.1;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S200>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S201>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S201>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S201>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 1.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S201>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -1.3;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S201>/Constant1'
                                   *   '<S201>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 1.3;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S201>/Constant'
                                   *   '<S201>/Saturation2'
                                   */
real_T Steering_Localized_Cmd_Approach_Zero_Error_Thresh = 0.2;
                  /* Variable: Steering_Localized_Cmd_Approach_Zero_Error_Thresh
                   * Referenced by: '<S191>/Constant5'
                   */
real_T Steering_Localized_Cmd_Approach_Zero_Final_Thresh = 0.01;
                  /* Variable: Steering_Localized_Cmd_Approach_Zero_Final_Thresh
                   * Referenced by: '<S191>/Constant6'
                   */
real_T Steering_Localized_Cmd_NonZero_Error_Thresh = 0.2;
                        /* Variable: Steering_Localized_Cmd_NonZero_Error_Thresh
                         * Referenced by: '<S191>/Constant9'
                         */
real_T Steering_Localized_Cmd_NonZero_Final_Scale_Factor = 0.1;
                  /* Variable: Steering_Localized_Cmd_NonZero_Final_Scale_Factor
                   * Referenced by: '<S191>/Constant10'
                   */
real_T Steering_Localized_Cmd_Rate_Limit_Dec = -1.0;
                              /* Variable: Steering_Localized_Cmd_Rate_Limit_Dec
                               * Referenced by: '<S191>/Constant1'
                               */
real_T Steering_Localized_Cmd_Rate_Limit_Inc = 1.0;
                              /* Variable: Steering_Localized_Cmd_Rate_Limit_Inc
                               * Referenced by: '<S191>/Constant3'
                               */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S99>/Constant3'
                                        *   '<S120>/Constant3'
                                        *   '<S141>/Constant3'
                                        *   '<S162>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S99>/Constant2'
                                *   '<S120>/Constant2'
                                *   '<S141>/Constant2'
                                *   '<S162>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S99>/Saturation'
                                           *   '<S120>/Saturation'
                                           *   '<S141>/Saturation'
                                           *   '<S162>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S99>/Saturation'
                                          *   '<S120>/Saturation'
                                          *   '<S141>/Saturation'
                                          *   '<S162>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S99>/Gain2'
                                         *   '<S120>/Gain2'
                                         *   '<S141>/Gain2'
                                         *   '<S162>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S99>/Saturation1'
                                             *   '<S120>/Saturation1'
                                             *   '<S141>/Saturation1'
                                             *   '<S162>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S99>/Saturation1'
                                            *   '<S120>/Saturation1'
                                            *   '<S141>/Saturation1'
                                            *   '<S162>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S99>/Gain1'
                                        *   '<S120>/Gain1'
                                        *   '<S141>/Gain1'
                                        *   '<S162>/Gain1'
                                        */
real_T Steering_Relative_Gain = 1.3;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S233>/Constant'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S179>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S179>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S179>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S179>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Inc = 0.085714;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S179>/Constant3'
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
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = iRght + iLeft >> 1U;
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
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
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
  memset(&rty_Spline_Ref_Poses[0], 0, 76U * sizeof(real_T));

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
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if (u1 < 0.0 != u0 < 0.0) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = y == 0.0;
    if (!yEq && u1 > floor(u1)) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if (u0 < 0.0 != u1 < 0.0) {
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
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
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
    } else if (u1 == 0.5 && u0 >= 0.0) {
      y = sqrt(u0);
    } else if (u0 < 0.0 && u1 > floor(u1)) {
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
  real_T rtb_thetay_0[8];
  real_T rtb_Add2_f[2];
  real_T rtb_Minus_n[2];
  real_T rtb_Product7[2];
  real_T rtb_Add_c;
  real_T rtb_Add_c4;
  real_T rtb_Add_cz;
  real_T rtb_Add_ec;
  real_T rtb_Add_kl;
  real_T rtb_Add_kz;
  real_T rtb_Add_pw;
  real_T rtb_Hypot_b;
  real_T rtb_Hypot_g5;
  real_T rtb_Init_e;
  real_T rtb_Integral_kz;
  real_T rtb_Integral_m;
  real_T rtb_Magnitude;
  real_T rtb_Merge1;
  real_T rtb_Optimized_Module_Angle;
  real_T rtb_POSEexponentialmatrixfori_0;
  real_T rtb_POSEexponentialmatrixfori_1;
  real_T rtb_POSEexponentialmatrixfori_2;
  real_T rtb_POSEexponentialmatrixfori_3;
  real_T rtb_Product_do;
  real_T rtb_Product_dq;
  real_T rtb_Steer_Joystick_X_Rel_Mod;
  real_T rtb_Subtract1_la;
  real_T rtb_Subtract_gn;
  real_T rtb_Subtract_i;
  real_T rtb_Sum2_fc;
  real_T rtb_Switch1_p2;
  real_T rtb_Switch2;
  real_T rtb_Switch2_p;
  real_T rtb_UnitDelay_f;
  real_T rtb_thetay;
  real_T rtb_uDLookupTable_l;
  int32_T i;
  int32_T rtb_Bias1_p;
  int32_T rtb_Num_Segments;
  int32_T s53_iter;
  uint16_T s78_iter;
  int8_T rtAction;
  int8_T rtPrevAction;
  boolean_T exitg1;
  boolean_T rtb_Is_Absolute_Steering;
  boolean_T rtb_Is_Absolute_Translation;
  boolean_T rtb_OR_ao;
  boolean_T rtb_Switch_b1;

  /* Sum: '<S86>/Add1' incorporates:
   *  Constant: '<S86>/Constant3'
   *  Constant: '<S86>/Constant4'
   *  Gain: '<S9>/Revolutions to Radians'
   *  Inport: '<Root>/FrontLeft_Steer_Rev'
   *  Inport: '<Root>/FrontLeft_Turn_Offset'
   *  Math: '<S86>/Math Function'
   *  Sum: '<S86>/Add2'
   *  Sum: '<S9>/Add'
   */
  Code_Gen_Model_B.FL_Steer_Module_Angle = rt_modd_snf
    ((Code_Gen_Model_U.FrontLeft_Steer_Rev -
      Code_Gen_Model_U.FrontLeft_Turn_Offset) * 6.2831853071795862 +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Rev'
   *  Sum: '<S14>/Diff'
   *  UnitDelay: '<S14>/UD'
   *
   * Block description for '<S14>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S14>/UD':
   *
   *  Store in Global RAM
   */
  rtb_thetay = (Code_Gen_Model_U.FrontLeft_Drive_Motor_Rev -
                Code_Gen_Model_DW.UD_DSTATE) * 0.037290702116950625;

  /* Sum: '<S87>/Add1' incorporates:
   *  Constant: '<S87>/Constant3'
   *  Constant: '<S87>/Constant4'
   *  Gain: '<S9>/Revolutions to Radians1'
   *  Inport: '<Root>/FrontRight_Steer_Rev'
   *  Inport: '<Root>/FrontRight_Turn_Offset'
   *  Math: '<S87>/Math Function'
   *  Sum: '<S87>/Add2'
   *  Sum: '<S9>/Add1'
   */
  Code_Gen_Model_B.FR_Steer_Module_Angle = rt_modd_snf
    ((Code_Gen_Model_U.FrontRight_Steer_Rev -
      Code_Gen_Model_U.FrontRight_Turn_Offset) * 6.2831853071795862 +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S7>/Product1' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Rev'
   *  Sum: '<S15>/Diff'
   *  UnitDelay: '<S15>/UD'
   *
   * Block description for '<S15>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S15>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Init_e = (Code_Gen_Model_U.FrontRight_Drive_Motor_Rev -
                Code_Gen_Model_DW.UD_DSTATE_m) * 0.037290702116950625;

  /* Sum: '<S88>/Add1' incorporates:
   *  Constant: '<S88>/Constant3'
   *  Constant: '<S88>/Constant4'
   *  Gain: '<S9>/Revolutions to Radians2'
   *  Inport: '<Root>/BackLeft_Steer_Rev'
   *  Inport: '<Root>/BackLeft_Turn_Offset'
   *  Math: '<S88>/Math Function'
   *  Sum: '<S88>/Add2'
   *  Sum: '<S9>/Add2'
   */
  Code_Gen_Model_B.BL_Steer_Module_Angle = rt_modd_snf
    ((Code_Gen_Model_U.BackLeft_Steer_Rev -
      Code_Gen_Model_U.BackLeft_Turn_Offset) * 6.2831853071795862 +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S7>/Product2' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Rev'
   *  Sum: '<S16>/Diff'
   *  UnitDelay: '<S16>/UD'
   *
   * Block description for '<S16>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S16>/UD':
   *
   *  Store in Global RAM
   */
  rtb_uDLookupTable_l = (Code_Gen_Model_U.BackLeft_Drive_Motor_Rev -
    Code_Gen_Model_DW.UD_DSTATE_i) * 0.037290702116950625;

  /* Sum: '<S89>/Add1' incorporates:
   *  Constant: '<S89>/Constant3'
   *  Constant: '<S89>/Constant4'
   *  Gain: '<S9>/Revolutions to Radians3'
   *  Inport: '<Root>/BackRight_Steer_Rev'
   *  Inport: '<Root>/BackRight_Turn_Offset'
   *  Math: '<S89>/Math Function'
   *  Sum: '<S89>/Add2'
   *  Sum: '<S9>/Add3'
   */
  Code_Gen_Model_B.BR_Steer_Module_Angle = rt_modd_snf
    ((Code_Gen_Model_U.BackRight_Steer_Rev -
      Code_Gen_Model_U.BackRight_Turn_Offset) * 6.2831853071795862 +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S7>/Product3' incorporates:
   *  Constant: '<S7>/Constant1'
   *  Inport: '<Root>/BackRight_Drive_Motor_Rev'
   *  Sum: '<S17>/Diff'
   *  UnitDelay: '<S17>/UD'
   *
   * Block description for '<S17>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S17>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Switch2_p = (Code_Gen_Model_U.BackRight_Drive_Motor_Rev -
                   Code_Gen_Model_DW.UD_DSTATE_c) * 0.037290702116950625;

  /* SignalConversion generated from: '<S7>/Product7' incorporates:
   *  Fcn: '<S18>/r->x'
   *  Fcn: '<S18>/theta->y'
   *  Fcn: '<S19>/r->x'
   *  Fcn: '<S19>/theta->y'
   *  Fcn: '<S20>/r->x'
   *  Fcn: '<S20>/theta->y'
   *  Fcn: '<S21>/r->x'
   *  Fcn: '<S21>/theta->y'
   */
  rtb_thetay_0[0] = rtb_thetay * cos(Code_Gen_Model_B.FL_Steer_Module_Angle);
  rtb_thetay_0[1] = rtb_thetay * sin(Code_Gen_Model_B.FL_Steer_Module_Angle);
  rtb_thetay_0[2] = rtb_Init_e * cos(Code_Gen_Model_B.FR_Steer_Module_Angle);
  rtb_thetay_0[3] = rtb_Init_e * sin(Code_Gen_Model_B.FR_Steer_Module_Angle);
  rtb_thetay_0[4] = rtb_uDLookupTable_l * cos
    (Code_Gen_Model_B.BL_Steer_Module_Angle);
  rtb_thetay_0[5] = rtb_uDLookupTable_l * sin
    (Code_Gen_Model_B.BL_Steer_Module_Angle);
  rtb_thetay_0[6] = rtb_Switch2_p * cos(Code_Gen_Model_B.BR_Steer_Module_Angle);
  rtb_thetay_0[7] = rtb_Switch2_p * sin(Code_Gen_Model_B.BR_Steer_Module_Angle);

  /* Product: '<S7>/Product7' incorporates:
   *  Constant: '<S7>/Constant4'
   */
  for (i = 0; i < 2; i++) {
    rtb_thetay = 0.0;
    rtb_Num_Segments = 0;
    for (s53_iter = 0; s53_iter < 8; s53_iter++) {
      rtb_thetay += Code_Gen_Model_ConstP.Constant4_Value_d[rtb_Num_Segments + i]
        * rtb_thetay_0[s53_iter];
      rtb_Num_Segments += 2;
    }

    rtb_Product7[i] = rtb_thetay;
  }

  /* End of Product: '<S7>/Product7' */

  /* Gain: '<S3>/Gain1' incorporates:
   *  Inport: '<Root>/Gyro_Angle'
   */
  rtb_thetay = 0.017453292519943295 * Code_Gen_Model_U.Gyro_Angle;

  /* Sum: '<S13>/Diff' incorporates:
   *  UnitDelay: '<S13>/UD'
   *
   * Block description for '<S13>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S13>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Init_e = rtb_thetay - Code_Gen_Model_DW.UD_DSTATE_d;

  /* Sum: '<S7>/Subtract2' incorporates:
   *  Constant: '<S7>/Constant3'
   *  Gain: '<S7>/Gain7'
   *  Math: '<S7>/Square'
   */
  rtb_Switch2_p = 1.0 - rtb_Init_e * rtb_Init_e * 0.16666666666666666;

  /* Gain: '<S7>/Gain6' */
  rtb_Init_e *= 0.5;

  /* SignalConversion generated from: '<S7>/POSE exponential matrix for improved accuracy while rotating' */
  rtb_POSEexponentialmatrixfori_0 = rtb_Switch2_p;
  rtb_POSEexponentialmatrixfori_1 = rtb_Init_e;

  /* SignalConversion generated from: '<S7>/POSE exponential matrix for improved accuracy while rotating' incorporates:
   *  UnaryMinus: '<S7>/Unary Minus2'
   */
  rtb_POSEexponentialmatrixfori_2 = -rtb_Init_e;
  rtb_POSEexponentialmatrixfori_3 = rtb_Switch2_p;

  /* Trigonometry: '<S7>/Trigonometric Function' */
  rtb_Init_e = cos(rtb_thetay);

  /* Trigonometry: '<S7>/Trigonometric Function1' */
  rtb_Switch2_p = sin(rtb_thetay);

  /* Product: '<S7>/Product6' incorporates:
   *  Concatenate: '<S7>/POSE exponential matrix for improved accuracy while rotating'
   *  SignalConversion generated from: '<S7>/Rotation matrix from local to global'
   *  UnaryMinus: '<S7>/Unary Minus'
   */
  rtb_POSEexponentialmatrixfori_2 = rtb_POSEexponentialmatrixfori_0 *
    rtb_Product7[0] + rtb_POSEexponentialmatrixfori_2 * rtb_Product7[1];
  rtb_POSEexponentialmatrixfori_3 = rtb_POSEexponentialmatrixfori_1 *
    rtb_Product7[0] + rtb_POSEexponentialmatrixfori_3 * rtb_Product7[1];
  rtb_POSEexponentialmatrixfori_1 = rtb_Init_e * rtb_POSEexponentialmatrixfori_2
    + -rtb_Switch2_p * rtb_POSEexponentialmatrixfori_3;
  rtb_POSEexponentialmatrixfori_2 = rtb_Switch2_p *
    rtb_POSEexponentialmatrixfori_2 + rtb_Init_e *
    rtb_POSEexponentialmatrixfori_3;

  /* DiscreteIntegrator: '<S7>/Accumulator2' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if (Odometry_Reset_IC > 0.0 && Code_Gen_Model_DW.Accumulator2_PrevResetState <=
      0) {
    Code_Gen_Model_DW.Accumulator2_DSTATE = Code_Gen_Model_ConstB.Constant;
  }

  /* DiscreteIntegrator: '<S7>/Accumulator2' */
  Code_Gen_Model_B.Odom_Position_X_global =
    Code_Gen_Model_DW.Accumulator2_DSTATE;

  /* DiscreteIntegrator: '<S7>/Accumulator' incorporates:
   *  Constant: '<S7>/Constant'
   */
  if (Odometry_Reset_IC > 0.0 && Code_Gen_Model_DW.Accumulator_PrevResetState <=
      0) {
    Code_Gen_Model_DW.Accumulator_DSTATE = Code_Gen_Model_ConstB.Constant1;
  }

  /* DiscreteIntegrator: '<S7>/Accumulator' */
  Code_Gen_Model_B.Odom_Position_Y_global = Code_Gen_Model_DW.Accumulator_DSTATE;

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtPrevAction = Code_Gen_Model_DW.SwitchCase_ActiveSubsystem;
  rtb_Add_ec = trunc(Code_Gen_Model_U.GameState);
  if (rtIsNaN(rtb_Add_ec) || rtIsInf(rtb_Add_ec)) {
    rtb_Add_ec = 0.0;
  } else {
    rtb_Add_ec = fmod(rtb_Add_ec, 4.294967296E+9);
  }

  if (rtb_Add_ec < 0.0) {
    i = -(int32_T)(uint32_T)-rtb_Add_ec;
  } else {
    i = (int32_T)(uint32_T)rtb_Add_ec;
  }

  switch (i) {
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
    Code_Gen_Model_Disabled(&rtb_UnitDelay_f, &Code_Gen_Model_B.Steering_Abs_Cmd,
      &Code_Gen_Model_B.Steering_Rel_Cmd, &Code_Gen_Model_B.Translation_Angle,
      &Code_Gen_Model_B.Translation_Speed, &rtb_Is_Absolute_Translation,
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
     *  Merge: '<S6>/Merge8'
     */
    memcpy(&rtb_Spline_Ref_Poses[0], &Code_Gen_Model_ConstP.Constant4_Value[0],
           76U * sizeof(real_T));

    /* SignalConversion generated from: '<S2>/Gyro_Angle_Adjustment' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    rtb_UnitDelay_f = 0.0;

    /* Merge: '<S6>/Merge1' incorporates:
     *  Constant: '<S2>/Constant10'
     *  SignalConversion: '<S2>/Signal Copy'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd = 0.78539816339744828;

    /* Merge: '<S6>/Merge2' incorporates:
     *  Constant: '<S2>/Constant2'
     *  SignalConversion: '<S2>/Signal Copy2'
     */
    Code_Gen_Model_B.Steering_Rel_Cmd = 0.0;

    /* Sum: '<S2>/Subtract' incorporates:
     *  Constant: '<S2>/Constant8'
     */
    rtb_POSEexponentialmatrixfori_3 = Odometry_Desired_Y -
      Code_Gen_Model_B.Odom_Position_Y_global;

    /* Sum: '<S2>/Subtract1' incorporates:
     *  Constant: '<S2>/Constant7'
     */
    rtb_Init_e = Odometry_Desired_X - Code_Gen_Model_B.Odom_Position_X_global;

    /* Merge: '<S6>/Merge4' incorporates:
     *  Constant: '<S2>/Constant'
     *  Math: '<S2>/Hypot'
     *  MinMax: '<S2>/Min'
     *  SignalConversion: '<S2>/Signal Copy3'
     */
    Code_Gen_Model_B.Translation_Speed = fmin(rt_hypotd_snf
      (rtb_POSEexponentialmatrixfori_3, rtb_Init_e), 1.0);

    /* Merge: '<S6>/Merge3' incorporates:
     *  SignalConversion: '<S2>/Signal Copy1'
     *  Trigonometry: '<S2>/Atan2'
     */
    Code_Gen_Model_B.Translation_Angle = rt_atan2d_snf
      (rtb_POSEexponentialmatrixfori_3, rtb_Init_e);

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
      rtb_POSEexponentialmatrixfori_3 = 0.0;
    } else {
      rtb_POSEexponentialmatrixfori_3 = Code_Gen_Model_DW.UnitDelay_DSTATE_l1 +
        0.02;
    }

    /* End of Switch: '<S2>/Switch1' */

    /* Merge: '<S6>/Merge7' incorporates:
     *  Constant: '<S2>/Constant12'
     *  Logic: '<S2>/OR'
     *  RelationalOperator: '<S2>/Relational Operator'
     *  Switch: '<S2>/Switch'
     *  UnitDelay: '<S5>/Unit Delay'
     */
    Code_Gen_Model_B.Spline_Enable = !Code_Gen_Model_DW.UnitDelay_DSTATE_ll &&
      !(rtb_POSEexponentialmatrixfori_3 < 1.0);

    /* Merge: '<S6>/Merge9' incorporates:
     *  Constant: '<S2>/Constant9'
     *  SignalConversion generated from: '<S2>/Spline_Num_Poses'
     */
    Code_Gen_Model_B.Spline_Num_Poses = 19.0;

    /* Update for UnitDelay: '<S2>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_l1 = rtb_POSEexponentialmatrixfori_3;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Teleop' incorporates:
     *  ActionPort: '<S11>/Action Port'
     */
    /* SignalConversion generated from: '<S11>/Spline_Ref_Poses' incorporates:
     *  Merge: '<S6>/Merge8'
     */
    memset(&rtb_Spline_Ref_Poses[0], 0, 76U * sizeof(real_T));

    /* Switch: '<S235>/Switch1' incorporates:
     *  Constant: '<S235>/Constant'
     *  Constant: '<S235>/Constant1'
     *  Constant: '<S235>/Constant2'
     *  Inport: '<Root>/Steer_Joystick_X'
     *  Inport: '<Root>/Steer_Joystick_Y'
     *  Math: '<S235>/Hypot'
     *  RelationalOperator: '<S235>/GreaterThan'
     *  Switch: '<S235>/Switch'
     */
    if (rt_hypotd_snf(Code_Gen_Model_U.Steer_Joystick_X,
                      Code_Gen_Model_U.Steer_Joystick_Y) >
        Steering_Abs_Deadband_Range) {
      rtb_UnitDelay_f = Code_Gen_Model_U.Steer_Joystick_Y;
      rtb_POSEexponentialmatrixfori_3 = Code_Gen_Model_U.Steer_Joystick_X;
    } else {
      rtb_UnitDelay_f = 0.0;
      rtb_POSEexponentialmatrixfori_3 = 0.0;
    }

    /* End of Switch: '<S235>/Switch1' */

    /* Switch: '<S237>/Switch1' incorporates:
     *  Constant: '<S243>/Constant'
     *  Constant: '<S244>/Constant'
     *  Logic: '<S237>/AND'
     *  RelationalOperator: '<S243>/Compare'
     *  RelationalOperator: '<S244>/Compare'
     *  Switch: '<S237>/Switch2'
     *  UnitDelay: '<S237>/Unit Delay'
     *  UnitDelay: '<S237>/Unit Delay1'
     */
    if (rtb_POSEexponentialmatrixfori_3 == 0.0 && rtb_UnitDelay_f == 0.0) {
      rtb_Init_e = Code_Gen_Model_DW.UnitDelay1_DSTATE_d2;
      rtb_Switch2 = Code_Gen_Model_DW.UnitDelay_DSTATE_g4;
    } else {
      rtb_Init_e = rtb_UnitDelay_f;
      rtb_Switch2 = rtb_POSEexponentialmatrixfori_3;
    }

    /* End of Switch: '<S237>/Switch1' */

    /* Merge: '<S6>/Merge1' incorporates:
     *  Trigonometry: '<S233>/Atan2'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd = rt_atan2d_snf(rtb_Init_e, rtb_Switch2);

    /* RelationalOperator: '<S240>/Compare' incorporates:
     *  Constant: '<S240>/Constant'
     */
    rtb_Is_Absolute_Translation = rtb_Switch2 < 0.0;

    /* Switch: '<S236>/Switch' incorporates:
     *  Constant: '<S236>/Constant'
     *  Constant: '<S236>/Constant1'
     *  Constant: '<S238>/Constant'
     *  Constant: '<S239>/Constant'
     *  Logic: '<S236>/Logical Operator'
     *  RelationalOperator: '<S238>/Compare'
     *  RelationalOperator: '<S239>/Compare'
     *  UnitDelay: '<S236>/Unit Delay'
     */
    if (rtb_Init_e < 0.0 && Code_Gen_Model_DW.UnitDelay_DSTATE_h >= 0.0 &&
        rtb_Is_Absolute_Translation) {
      rtb_Add_ec = 6.2831853071795862;
    } else {
      rtb_Add_ec = 0.0;
    }

    /* Switch: '<S236>/Switch1' incorporates:
     *  Constant: '<S236>/Constant2'
     *  Constant: '<S236>/Constant3'
     *  Constant: '<S241>/Constant'
     *  Constant: '<S242>/Constant'
     *  Logic: '<S236>/Logical Operator1'
     *  RelationalOperator: '<S241>/Compare'
     *  RelationalOperator: '<S242>/Compare'
     *  UnitDelay: '<S236>/Unit Delay'
     */
    if (Code_Gen_Model_DW.UnitDelay_DSTATE_h < 0.0 && rtb_Init_e >= 0.0 &&
        rtb_Is_Absolute_Translation) {
      rtb_Add_cz = -6.2831853071795862;
    } else {
      rtb_Add_cz = 0.0;
    }

    /* Sum: '<S236>/Sum1' incorporates:
     *  Switch: '<S236>/Switch'
     *  Switch: '<S236>/Switch1'
     *  UnitDelay: '<S236>/Unit Delay1'
     */
    rtb_UnitDelay_f = rtb_Add_ec + rtb_Add_cz +
      Code_Gen_Model_DW.UnitDelay1_DSTATE_kr;

    /* Lookup_n-D: '<S234>/Modulation_Drv_X' incorporates:
     *  Inport: '<Root>/Drive_Joystick_X'
     */
    rtb_Steer_Joystick_X_Rel_Mod = look1_binlcpw
      (Code_Gen_Model_U.Drive_Joystick_X, Code_Gen_Model_ConstP.pooled18,
       Code_Gen_Model_ConstP.pooled17, 20U);

    /* Lookup_n-D: '<S234>/Modulation_Drv_Y' incorporates:
     *  Inport: '<Root>/Drive_Joystick_Y'
     */
    rtb_POSEexponentialmatrixfori_3 = look1_binlcpw
      (Code_Gen_Model_U.Drive_Joystick_Y, Code_Gen_Model_ConstP.pooled18,
       Code_Gen_Model_ConstP.pooled17, 20U);

    /* Switch: '<S246>/Switch1' incorporates:
     *  Constant: '<S251>/Constant'
     *  Constant: '<S252>/Constant'
     *  Logic: '<S246>/AND'
     *  RelationalOperator: '<S251>/Compare'
     *  RelationalOperator: '<S252>/Compare'
     *  Switch: '<S246>/Switch2'
     *  UnitDelay: '<S246>/Unit Delay'
     *  UnitDelay: '<S246>/Unit Delay1'
     */
    if (rtb_Steer_Joystick_X_Rel_Mod == 0.0 && rtb_POSEexponentialmatrixfori_3 ==
        0.0) {
      rtb_Switch1_p2 = Code_Gen_Model_DW.UnitDelay1_DSTATE_l;
      rtb_POSEexponentialmatrixfori_0 = Code_Gen_Model_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Switch1_p2 = rtb_POSEexponentialmatrixfori_3;
      rtb_POSEexponentialmatrixfori_0 = rtb_Steer_Joystick_X_Rel_Mod;
    }

    /* End of Switch: '<S246>/Switch1' */

    /* Merge: '<S6>/Merge3' incorporates:
     *  Trigonometry: '<S234>/Atan2'
     */
    Code_Gen_Model_B.Translation_Angle = rt_atan2d_snf(rtb_Switch1_p2,
      rtb_POSEexponentialmatrixfori_0);

    /* Math: '<S234>/Magnitude' */
    rtb_Magnitude = rt_hypotd_snf(rtb_Steer_Joystick_X_Rel_Mod,
      rtb_POSEexponentialmatrixfori_3);

    /* Switch: '<S245>/Switch1' incorporates:
     *  Constant: '<S245>/Constant'
     *  Constant: '<S245>/Constant1'
     *  Inport: '<Root>/Is_Boost_Trigger_Pulled'
     */
    if (Code_Gen_Model_U.Is_Boost_Trigger_Pulled != 0.0) {
      rtb_Steer_Joystick_X_Rel_Mod = Boost_Trigger_High_Speed;
    } else {
      rtb_Steer_Joystick_X_Rel_Mod = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S245>/Switch1' */

    /* Switch: '<S250>/Init' incorporates:
     *  UnitDelay: '<S250>/FixPt Unit Delay1'
     *  UnitDelay: '<S250>/FixPt Unit Delay2'
     */
    if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_POSEexponentialmatrixfori_3 = rtb_Steer_Joystick_X_Rel_Mod;
    } else {
      rtb_POSEexponentialmatrixfori_3 =
        Code_Gen_Model_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S250>/Init' */

    /* Sum: '<S248>/Sum1' */
    rtb_Steer_Joystick_X_Rel_Mod -= rtb_POSEexponentialmatrixfori_3;

    /* Switch: '<S249>/Switch2' incorporates:
     *  Constant: '<S247>/Constant1'
     *  Constant: '<S247>/Constant3'
     *  RelationalOperator: '<S249>/LowerRelop1'
     *  RelationalOperator: '<S249>/UpperRelop'
     *  Switch: '<S249>/Switch'
     */
    if (rtb_Steer_Joystick_X_Rel_Mod > Boost_Trigger_Increasing_Limit) {
      rtb_Steer_Joystick_X_Rel_Mod = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Steer_Joystick_X_Rel_Mod < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S249>/Switch' incorporates:
       *  Constant: '<S247>/Constant1'
       */
      rtb_Steer_Joystick_X_Rel_Mod = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S249>/Switch2' */

    /* Sum: '<S248>/Sum' */
    rtb_POSEexponentialmatrixfori_3 += rtb_Steer_Joystick_X_Rel_Mod;

    /* Product: '<S245>/Product' */
    rtb_Add_ec = rtb_Magnitude * rtb_POSEexponentialmatrixfori_3;

    /* Saturate: '<S245>/Saturation' */
    if (rtb_Add_ec > Boost_Trigger_High_Speed) {
      /* Merge: '<S6>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = Boost_Trigger_High_Speed;
    } else if (rtb_Add_ec < -Boost_Trigger_High_Speed) {
      /* Merge: '<S6>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = -Boost_Trigger_High_Speed;
    } else {
      /* Merge: '<S6>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = rtb_Add_ec;
    }

    /* End of Saturate: '<S245>/Saturation' */

    /* Merge: '<S6>/Merge7' incorporates:
     *  Constant: '<S11>/Constant3'
     *  SignalConversion generated from: '<S11>/Spline_Enable'
     */
    Code_Gen_Model_B.Spline_Enable = false;

    /* Merge: '<S6>/Merge2' incorporates:
     *  Constant: '<S233>/Constant'
     *  Inport: '<Root>/Steer_Joystick_Y'
     *  Lookup_n-D: '<S233>/Modulation_Str_X_Rel'
     *  Product: '<S233>/Product'
     */
    Code_Gen_Model_B.Steering_Rel_Cmd = look1_binlcpw
      (Code_Gen_Model_U.Steer_Joystick_Y,
       Code_Gen_Model_ConstP.Modulation_Str_X_Rel_bp01Data,
       Code_Gen_Model_ConstP.Modulation_Str_X_Rel_tableData, 20U) *
      Steering_Relative_Gain;

    /* Merge: '<S6>/Merge9' incorporates:
     *  Constant: '<S11>/Constant9'
     *  SignalConversion generated from: '<S11>/Spline_Num_Poses'
     */
    Code_Gen_Model_B.Spline_Num_Poses = 19.0;

    /* SignalConversion generated from: '<S11>/Is_Absolute_Translation_In' incorporates:
     *  Inport: '<Root>/Is_Absolute_Translation'
     */
    rtb_Is_Absolute_Translation = Code_Gen_Model_U.Is_Absolute_Translation;

    /* SignalConversion generated from: '<S11>/Is_Absolute_Steering_In' incorporates:
     *  Inport: '<Root>/Is_Absolute_Steering'
     */
    rtb_Is_Absolute_Steering = Code_Gen_Model_U.Is_Absolute_Steering;

    /* Update for UnitDelay: '<S237>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_d2 = rtb_Init_e;

    /* Update for UnitDelay: '<S237>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_g4 = rtb_Switch2;

    /* Update for UnitDelay: '<S236>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_h = rtb_Init_e;

    /* Update for UnitDelay: '<S236>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_kr = rtb_UnitDelay_f;

    /* Update for UnitDelay: '<S246>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_l = rtb_Switch1_p2;

    /* Update for UnitDelay: '<S246>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_p = rtb_POSEexponentialmatrixfori_0;

    /* Update for UnitDelay: '<S250>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S250>/FixPt Constant'
     */
    Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S250>/FixPt Unit Delay1' */
    Code_Gen_Model_DW.FixPtUnitDelay1_DSTATE_f = rtb_POSEexponentialmatrixfori_3;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S12>/Action Port'
     */
    Code_Gen_Model_Disabled(&rtb_UnitDelay_f, &Code_Gen_Model_B.Steering_Abs_Cmd,
      &Code_Gen_Model_B.Steering_Rel_Cmd, &Code_Gen_Model_B.Translation_Angle,
      &Code_Gen_Model_B.Translation_Speed, &rtb_Is_Absolute_Translation,
      &rtb_Is_Absolute_Steering, &Code_Gen_Model_B.Spline_Enable,
      rtb_Spline_Ref_Poses, &Code_Gen_Model_B.Spline_Num_Poses);

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* If: '<S8>/If' incorporates:
   *  Constant: '<S27>/Lookahead Distance'
   *  Constant: '<S78>/Constant'
   *  Logic: '<S78>/AND'
   *  MATLAB Function: '<S27>/Find closest index to curve'
   *  Product: '<S78>/Product'
   *  RelationalOperator: '<S78>/Relational Operator'
   *  RelationalOperator: '<S78>/Relational Operator1'
   *  Selector: '<S78>/Selector'
   *  Selector: '<S78>/Selector1'
   *  Selector: '<S79>/Selector'
   *  Sum: '<S78>/Add'
   */
  rtPrevAction = Code_Gen_Model_DW.If_ActiveSubsystem;
  rtAction = (int8_T)!Code_Gen_Model_B.Spline_Enable;
  Code_Gen_Model_DW.If_ActiveSubsystem = rtAction;
  if (rtPrevAction != rtAction && rtPrevAction == 0) {
    /* Disable for If: '<S30>/If' */
    if (Code_Gen_Model_DW.If_ActiveSubsystem_h == 0) {
      /* Disable for If: '<S33>/If' */
      if (Code_Gen_Model_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S35>/If' */
        Code_Gen_Model_DW.If_ActiveSubsystem_d = -1;
      }

      Code_Gen_Model_DW.If_ActiveSubsystem_o = -1;
    }

    Code_Gen_Model_DW.If_ActiveSubsystem_h = -1;

    /* End of Disable for If: '<S30>/If' */
  }

  if (rtAction == 0) {
    if (rtPrevAction != 0) {
      /* InitializeConditions for IfAction SubSystem: '<S8>/Spline Path Following Enabled' incorporates:
       *  ActionPort: '<S25>/Action Port'
       */
      /* InitializeConditions for If: '<S8>/If' incorporates:
       *  UnitDelay: '<S26>/Unit Delay'
       *  UnitDelay: '<S28>/Unit Delay'
       *  UnitDelay: '<S28>/Unit Delay1'
       *  UnitDelay: '<S79>/Unit Delay'
       *  UnitDelay: '<S79>/Unit Delay1'
       */
      Code_Gen_Model_DW.UnitDelay_DSTATE_gh = 2.0;
      Code_Gen_Model_DW.UnitDelay1_DSTATE_f4 = 0.0;
      Code_Gen_Model_DW.UnitDelay_DSTATE_g4g = 0.0;
      Code_Gen_Model_DW.UnitDelay_DSTATE_le = 0.0;
      Code_Gen_Model_DW.UnitDelay1_DSTATE_kc = 0.0;

      /* End of InitializeConditions for SubSystem: '<S8>/Spline Path Following Enabled' */
    }

    /* Outputs for IfAction SubSystem: '<S8>/Spline Path Following Enabled' incorporates:
     *  ActionPort: '<S25>/Action Port'
     */
    /* Selector: '<S26>/Selector1' incorporates:
     *  Merge: '<S6>/Merge8'
     */
    for (i = 0; i < 19; i++) {
      rtb_Ref_Poses[i] = rtb_Spline_Ref_Poses[i];
      rtb_Ref_Poses[i + 19] = rtb_Spline_Ref_Poses[i + 19];
    }

    /* End of Selector: '<S26>/Selector1' */

    /* SignalConversion generated from: '<S26>/Matrix Concatenate2' */
    rtb_Product7[0] = Code_Gen_Model_B.Odom_Position_X_global;

    /* SignalConversion generated from: '<S26>/Matrix Concatenate2' */
    rtb_Product7[1] = Code_Gen_Model_B.Odom_Position_Y_global;

    /* If: '<S30>/If' incorporates:
     *  RelationalOperator: '<S30>/ '
     *  UnitDelay: '<S26>/Unit Delay'
     */
    rtPrevAction = Code_Gen_Model_DW.If_ActiveSubsystem_h;
    rtAction = (int8_T)!(Code_Gen_Model_DW.UnitDelay_DSTATE_gh <=
                         Code_Gen_Model_B.Spline_Num_Poses);
    Code_Gen_Model_DW.If_ActiveSubsystem_h = rtAction;
    if (rtPrevAction != rtAction && rtPrevAction == 0) {
      /* Disable for If: '<S33>/If' */
      if (Code_Gen_Model_DW.If_ActiveSubsystem_o == 0) {
        /* Disable for If: '<S35>/If' */
        Code_Gen_Model_DW.If_ActiveSubsystem_d = -1;
      }

      Code_Gen_Model_DW.If_ActiveSubsystem_o = -1;
    }

    if (rtAction == 0) {
      /* InitializeConditions for IfAction SubSystem: '<S30>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S33>/Action Port'
       */
      /* InitializeConditions for If: '<S30>/If' incorporates:
       *  UnitDelay: '<S33>/Unit Delay'
       */
      Code_Gen_Model_DW.UnitDelay_DSTATE_e4 = rtPrevAction == 0 &&
        Code_Gen_Model_DW.UnitDelay_DSTATE_e4;

      /* End of InitializeConditions for SubSystem: '<S30>/Robot_Index_Is_Valid' */

      /* Outputs for IfAction SubSystem: '<S30>/Robot_Index_Is_Valid' incorporates:
       *  ActionPort: '<S33>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S33>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S37>/Action Port'
       */
      /* If: '<S33>/If' incorporates:
       *  Selector: '<S26>/Selector1'
       *  Selector: '<S33>/Selector'
       *  Selector: '<S37>/Selector'
       */
      rtb_Optimized_Module_Angle = rtb_Ref_Poses[(int32_T)
        Code_Gen_Model_DW.UnitDelay_DSTATE_gh - 1];

      /* End of Outputs for SubSystem: '<S33>/Increment_If_Rectangle_Check' */

      /* Sum: '<S33>/Minus' incorporates:
       *  Concatenate: '<S26>/Matrix Concatenate2'
       *  Selector: '<S33>/Selector'
       */
      rtb_Minus_n[0] = rtb_Product7[0] - rtb_Optimized_Module_Angle;

      /* Outputs for IfAction SubSystem: '<S33>/Increment_If_Rectangle_Check' incorporates:
       *  ActionPort: '<S37>/Action Port'
       */
      /* If: '<S33>/If' incorporates:
       *  Selector: '<S26>/Selector1'
       *  Selector: '<S33>/Selector'
       *  Selector: '<S37>/Selector'
       *  Sum: '<S33>/Minus'
       */
      rtb_Init_e = rtb_Ref_Poses[(int32_T)Code_Gen_Model_DW.UnitDelay_DSTATE_gh
        + 18];

      /* End of Outputs for SubSystem: '<S33>/Increment_If_Rectangle_Check' */

      /* Sum: '<S33>/Minus' incorporates:
       *  Concatenate: '<S26>/Matrix Concatenate2'
       *  Selector: '<S33>/Selector'
       */
      rtb_Minus_n[1] = rtb_Product7[1] - rtb_Init_e;

      /* Math: '<S33>/Hypot' */
      rtb_UnitDelay_f = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

      /* RelationalOperator: '<S33>/Equal' */
      rtb_Is_Absolute_Steering = Code_Gen_Model_B.Spline_Num_Poses ==
        Code_Gen_Model_DW.UnitDelay_DSTATE_gh;

      /* Switch: '<S33>/Switch' incorporates:
       *  Constant: '<S36>/Constant'
       *  Logic: '<S33>/AND'
       *  Logic: '<S33>/OR'
       *  RelationalOperator: '<S36>/Compare'
       *  UnitDelay: '<S33>/Unit Delay'
       */
      rtb_Is_Absolute_Translation = Code_Gen_Model_DW.UnitDelay_DSTATE_e4 ||
        rtb_Is_Absolute_Steering && rtb_UnitDelay_f <= Spline_Capture_Radius;

      /* If: '<S33>/If' */
      rtPrevAction = Code_Gen_Model_DW.If_ActiveSubsystem_o;
      if (!rtb_Is_Absolute_Translation) {
        if (!rtb_Is_Absolute_Steering) {
          rtAction = 1;
        } else {
          rtAction = 2;
        }
      }

      Code_Gen_Model_DW.If_ActiveSubsystem_o = rtAction;
      if (rtPrevAction != rtAction && rtPrevAction == 0) {
        /* Disable for If: '<S35>/If' */
        Code_Gen_Model_DW.If_ActiveSubsystem_d = -1;
      }

      switch (rtAction) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S33>/Circle_Check_Valid' incorporates:
         *  ActionPort: '<S35>/Action Port'
         */
        /* If: '<S35>/If' incorporates:
         *  RelationalOperator: '<S35>/Equal'
         */
        rtPrevAction = Code_Gen_Model_DW.If_ActiveSubsystem_d;
        rtAction = (int8_T)!(Code_Gen_Model_DW.UnitDelay_DSTATE_gh ==
                             Code_Gen_Model_B.Spline_Num_Poses);
        Code_Gen_Model_DW.If_ActiveSubsystem_d = rtAction;
        if (rtAction == 0) {
          /* InitializeConditions for IfAction SubSystem: '<S35>/Is_Last_Point' incorporates:
           *  ActionPort: '<S39>/Action Port'
           */
          /* InitializeConditions for If: '<S35>/If' incorporates:
           *  UnitDelay: '<S39>/Unit Delay'
           */
          Code_Gen_Model_DW.UnitDelay_DSTATE_n = rtPrevAction == 0 &&
            Code_Gen_Model_DW.UnitDelay_DSTATE_n;

          /* End of InitializeConditions for SubSystem: '<S35>/Is_Last_Point' */

          /* Outputs for IfAction SubSystem: '<S35>/Is_Last_Point' incorporates:
           *  ActionPort: '<S39>/Action Port'
           */
          /* Switch: '<S39>/Switch' incorporates:
           *  Constant: '<S41>/Constant'
           *  Logic: '<S39>/OR'
           *  RelationalOperator: '<S41>/Compare'
           *  UnitDelay: '<S39>/Unit Delay'
           */
          rtb_Switch_b1 = Code_Gen_Model_DW.UnitDelay_DSTATE_n ||
            rtb_UnitDelay_f <= 0.05;

          /* If: '<S39>/If' */
          if (rtb_Switch_b1) {
            /* Outputs for IfAction SubSystem: '<S39>/Robot_Is_At_Destination' incorporates:
             *  ActionPort: '<S42>/Action Port'
             */
            /* Merge: '<S30>/Merge2' incorporates:
             *  Constant: '<S42>/Constant'
             *  SignalConversion generated from: '<S42>/Robot_Reached_Destination'
             */
            rtb_Is_Absolute_Steering = true;

            /* SignalConversion generated from: '<S42>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S42>/Constant1'
             */
            rtb_OR_ao = false;

            /* End of Outputs for SubSystem: '<S39>/Robot_Is_At_Destination' */
          } else {
            /* Outputs for IfAction SubSystem: '<S39>/Straight_Line_Path_To_End' incorporates:
             *  ActionPort: '<S43>/Action Port'
             */
            /* Merge: '<S30>/Merge2' incorporates:
             *  Constant: '<S43>/Constant'
             *  SignalConversion generated from: '<S43>/Robot_Reached_Destination'
             */
            rtb_Is_Absolute_Steering = false;

            /* SignalConversion generated from: '<S43>/Make_Staight_Line_To_End' incorporates:
             *  Constant: '<S43>/Constant1'
             */
            rtb_OR_ao = true;

            /* End of Outputs for SubSystem: '<S39>/Straight_Line_Path_To_End' */
          }

          /* End of If: '<S39>/If' */

          /* Merge: '<S30>/Merge4' incorporates:
           *  SignalConversion: '<S39>/Signal Copy'
           */
          Code_Gen_Model_B.Spline_Index = Code_Gen_Model_DW.UnitDelay_DSTATE_gh;

          /* Update for UnitDelay: '<S39>/Unit Delay' */
          Code_Gen_Model_DW.UnitDelay_DSTATE_n = rtb_Switch_b1;

          /* End of Outputs for SubSystem: '<S35>/Is_Last_Point' */
        } else {
          /* Outputs for IfAction SubSystem: '<S35>/Increment_Search' incorporates:
           *  ActionPort: '<S38>/Action Port'
           */
          /* Merge: '<S30>/Merge2' incorporates:
           *  Constant: '<S38>/Constant'
           *  SignalConversion generated from: '<S38>/Robot_Reached_Destination'
           */
          rtb_Is_Absolute_Steering = false;

          /* SignalConversion generated from: '<S38>/Make_Staight_Line_To_End' incorporates:
           *  Constant: '<S38>/Constant1'
           */
          rtb_OR_ao = false;

          /* Merge: '<S30>/Merge4' incorporates:
           *  Constant: '<S40>/FixPt Constant'
           *  SignalConversion: '<S38>/Signal Copy'
           *  Sum: '<S40>/FixPt Sum1'
           */
          Code_Gen_Model_B.Spline_Index = Code_Gen_Model_DW.UnitDelay_DSTATE_gh
            + 1.0;

          /* End of Outputs for SubSystem: '<S35>/Increment_Search' */
        }

        /* End of If: '<S35>/If' */
        /* End of Outputs for SubSystem: '<S33>/Circle_Check_Valid' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S33>/Increment_If_Rectangle_Check' incorporates:
         *  ActionPort: '<S37>/Action Port'
         */
        /* Sum: '<S44>/FixPt Sum1' incorporates:
         *  Constant: '<S44>/FixPt Constant'
         */
        rtb_UnitDelay_f = Code_Gen_Model_DW.UnitDelay_DSTATE_gh + 1.0;

        /* Selector: '<S37>/Selector1' incorporates:
         *  Selector: '<S26>/Selector1'
         */
        rtb_Switch1_p2 = rtb_Ref_Poses[(int32_T)rtb_UnitDelay_f - 1];

        /* Sum: '<S45>/Subtract' incorporates:
         *  Selector: '<S37>/Selector1'
         *  Sum: '<S45>/Minus1'
         */
        rtb_Minus_n[0] = rtb_Switch1_p2 - rtb_Optimized_Module_Angle;

        /* Selector: '<S37>/Selector1' incorporates:
         *  Selector: '<S26>/Selector1'
         */
        rtb_UnitDelay_f = rtb_Ref_Poses[(int32_T)rtb_UnitDelay_f + 18];

        /* Sum: '<S45>/Subtract' incorporates:
         *  Selector: '<S37>/Selector1'
         *  Sum: '<S45>/Minus1'
         */
        rtb_Minus_n[1] = rtb_UnitDelay_f - rtb_Init_e;

        /* Math: '<S45>/Hypot' */
        rtb_POSEexponentialmatrixfori_3 = rt_hypotd_snf(rtb_Minus_n[0],
          rtb_Minus_n[1]);

        /* Product: '<S45>/Divide' */
        rtb_Switch2 = rtb_Minus_n[1];

        /* UnaryMinus: '<S45>/Unary Minus' */
        rtb_Switch2_p = rtb_Minus_n[0];

        /* Product: '<S45>/Product' incorporates:
         *  Constant: '<S37>/Constant'
         *  Product: '<S45>/Divide'
         *  UnaryMinus: '<S45>/Unary Minus'
         */
        rtb_Minus_n[0] = rtb_Switch2 / rtb_POSEexponentialmatrixfori_3 *
          Spline_Capture_Radius;
        rtb_Minus_n[1] = -rtb_Switch2_p / rtb_POSEexponentialmatrixfori_3 *
          Spline_Capture_Radius;

        /* Sum: '<S45>/Add1' incorporates:
         *  Sum: '<S45>/Add2'
         *  Sum: '<S45>/Minus'
         */
        rtb_Switch2_p = rtb_Switch1_p2 - rtb_Minus_n[0];

        /* Sum: '<S45>/Minus4' incorporates:
         *  Sum: '<S45>/Add2'
         *  Sum: '<S45>/Minus'
         */
        rtb_Switch1_p2 = rtb_Switch1_p2 + rtb_Minus_n[0] - rtb_Switch2_p;

        /* Sum: '<S45>/Minus5' incorporates:
         *  Concatenate: '<S26>/Matrix Concatenate2'
         *  Sum: '<S45>/Minus'
         */
        rtb_POSEexponentialmatrixfori_0 = rtb_Product7[0] - rtb_Switch2_p;

        /* Sum: '<S45>/Add' incorporates:
         *  Sum: '<S45>/Add2'
         *  Sum: '<S45>/Minus1'
         */
        rtb_Switch2 = rtb_Optimized_Module_Angle - rtb_Minus_n[0];

        /* Sum: '<S45>/Minus' incorporates:
         *  Sum: '<S45>/Minus1'
         */
        rtb_Switch2_p -= rtb_Switch2;

        /* DotProduct: '<S45>/Dot Product' incorporates:
         *  Concatenate: '<S26>/Matrix Concatenate2'
         *  Sum: '<S45>/Minus'
         *  Sum: '<S45>/Minus1'
         *  Sum: '<S45>/Minus5'
         */
        rtb_POSEexponentialmatrixfori_3 = (rtb_Product7[0] - rtb_Switch2) *
          rtb_Switch2_p;

        /* DotProduct: '<S45>/Dot Product1' incorporates:
         *  Sum: '<S45>/Minus'
         */
        rtb_Optimized_Module_Angle = rtb_Switch2_p * rtb_Switch2_p;

        /* DotProduct: '<S45>/Dot Product2' incorporates:
         *  Sum: '<S45>/Minus4'
         *  Sum: '<S45>/Minus5'
         */
        rtb_Steer_Joystick_X_Rel_Mod = rtb_Switch1_p2 *
          rtb_POSEexponentialmatrixfori_0;

        /* DotProduct: '<S45>/Dot Product3' incorporates:
         *  Sum: '<S45>/Minus4'
         */
        rtb_Magnitude = rtb_Switch1_p2 * rtb_Switch1_p2;

        /* Sum: '<S45>/Add1' incorporates:
         *  Sum: '<S45>/Add2'
         *  Sum: '<S45>/Minus'
         */
        rtb_Switch2_p = rtb_UnitDelay_f - rtb_Minus_n[1];

        /* Sum: '<S45>/Minus4' incorporates:
         *  Sum: '<S45>/Add2'
         *  Sum: '<S45>/Minus'
         */
        rtb_Switch1_p2 = rtb_UnitDelay_f + rtb_Minus_n[1] - rtb_Switch2_p;

        /* Sum: '<S45>/Minus5' incorporates:
         *  Concatenate: '<S26>/Matrix Concatenate2'
         *  Sum: '<S45>/Minus'
         */
        rtb_POSEexponentialmatrixfori_0 = rtb_Product7[1] - rtb_Switch2_p;

        /* Sum: '<S45>/Add' incorporates:
         *  Sum: '<S45>/Add2'
         *  Sum: '<S45>/Minus1'
         */
        rtb_Switch2 = rtb_Init_e - rtb_Minus_n[1];

        /* Sum: '<S45>/Minus' incorporates:
         *  Sum: '<S45>/Minus1'
         */
        rtb_Switch2_p -= rtb_Switch2;

        /* DotProduct: '<S45>/Dot Product' incorporates:
         *  Concatenate: '<S26>/Matrix Concatenate2'
         *  Sum: '<S45>/Minus'
         *  Sum: '<S45>/Minus1'
         *  Sum: '<S45>/Minus5'
         */
        rtb_POSEexponentialmatrixfori_3 += (rtb_Product7[1] - rtb_Switch2) *
          rtb_Switch2_p;

        /* RelationalOperator: '<S46>/Compare' incorporates:
         *  Constant: '<S46>/Constant'
         */
        rtb_Is_Absolute_Steering = rtb_POSEexponentialmatrixfori_3 >= 0.0;

        /* RelationalOperator: '<S45>/LessThanOrEqual' incorporates:
         *  DotProduct: '<S45>/Dot Product1'
         *  Sum: '<S45>/Minus'
         */
        rtb_OR_ao = rtb_POSEexponentialmatrixfori_3 <= rtb_Switch2_p *
          rtb_Switch2_p + rtb_Optimized_Module_Angle;

        /* DotProduct: '<S45>/Dot Product2' incorporates:
         *  Sum: '<S45>/Minus4'
         *  Sum: '<S45>/Minus5'
         */
        rtb_POSEexponentialmatrixfori_3 = rtb_Switch1_p2 *
          rtb_POSEexponentialmatrixfori_0 + rtb_Steer_Joystick_X_Rel_Mod;

        /* Merge: '<S30>/Merge4' incorporates:
         *  Constant: '<S47>/Constant'
         *  DataTypeConversion: '<S37>/Data Type Conversion'
         *  DotProduct: '<S45>/Dot Product3'
         *  Logic: '<S45>/AND'
         *  RelationalOperator: '<S45>/LessThanOrEqual1'
         *  RelationalOperator: '<S47>/Compare'
         *  Sum: '<S37>/Add'
         *  Sum: '<S45>/Minus4'
         */
        Code_Gen_Model_B.Spline_Index = (real_T)(rtb_Is_Absolute_Steering &&
          rtb_OR_ao && rtb_POSEexponentialmatrixfori_3 >= 0.0 &&
          rtb_POSEexponentialmatrixfori_3 <= rtb_Switch1_p2 * rtb_Switch1_p2 +
          rtb_Magnitude) + Code_Gen_Model_DW.UnitDelay_DSTATE_gh;

        /* Merge: '<S30>/Merge2' incorporates:
         *  Constant: '<S37>/Constant2'
         *  SignalConversion generated from: '<S37>/Robot_Reached_Destination'
         */
        rtb_Is_Absolute_Steering = false;

        /* SignalConversion generated from: '<S37>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S37>/Constant1'
         */
        rtb_OR_ao = false;

        /* End of Outputs for SubSystem: '<S33>/Increment_If_Rectangle_Check' */
        break;

       default:
        /* Outputs for IfAction SubSystem: '<S33>/Catch-all if not the last point and not in the circle' incorporates:
         *  ActionPort: '<S34>/Action Port'
         */
        /* Merge: '<S30>/Merge2' incorporates:
         *  Constant: '<S34>/Constant2'
         *  SignalConversion generated from: '<S34>/Robot_Reached_Destination'
         */
        rtb_Is_Absolute_Steering = false;

        /* SignalConversion generated from: '<S34>/Make_Staight_Line_To_End' incorporates:
         *  Constant: '<S34>/Constant1'
         */
        rtb_OR_ao = false;

        /* Merge: '<S30>/Merge4' incorporates:
         *  SignalConversion generated from: '<S34>/Current_Index'
         */
        Code_Gen_Model_B.Spline_Index = Code_Gen_Model_DW.UnitDelay_DSTATE_gh;

        /* End of Outputs for SubSystem: '<S33>/Catch-all if not the last point and not in the circle' */
        break;
      }

      /* Merge: '<S30>/Merge1' incorporates:
       *  Constant: '<S33>/Constant'
       *  SignalConversion generated from: '<S33>/Out_Of_Bounds'
       */
      Code_Gen_Model_B.Spline_Out_Of_Bounds = false;

      /* Update for UnitDelay: '<S33>/Unit Delay' */
      Code_Gen_Model_DW.UnitDelay_DSTATE_e4 = rtb_Is_Absolute_Translation;

      /* End of Outputs for SubSystem: '<S30>/Robot_Index_Is_Valid' */
    } else {
      /* Outputs for IfAction SubSystem: '<S30>/Escape_Auto_Driving' incorporates:
       *  ActionPort: '<S32>/Action Port'
       */
      /* Merge: '<S30>/Merge1' incorporates:
       *  Constant: '<S32>/Constant'
       *  SignalConversion generated from: '<S32>/Out_Of_Bounds'
       */
      Code_Gen_Model_B.Spline_Out_Of_Bounds = true;

      /* Merge: '<S30>/Merge2' incorporates:
       *  Constant: '<S32>/Constant1'
       *  SignalConversion generated from: '<S32>/Robot_Reached_Destination'
       */
      rtb_Is_Absolute_Steering = false;

      /* SignalConversion generated from: '<S32>/Make_Staight_Line_To_End' incorporates:
       *  Constant: '<S32>/Constant2'
       */
      rtb_OR_ao = false;

      /* Merge: '<S30>/Merge4' incorporates:
       *  SignalConversion generated from: '<S32>/Current_Index'
       */
      Code_Gen_Model_B.Spline_Index = Code_Gen_Model_DW.UnitDelay_DSTATE_gh;

      /* End of Outputs for SubSystem: '<S30>/Escape_Auto_Driving' */
    }

    /* End of If: '<S30>/If' */

    /* If: '<S26>/If1' */
    if (!rtb_OR_ao) {
      /* Outputs for IfAction SubSystem: '<S26>/Make_Knots_and_Path_Planning' incorporates:
       *  ActionPort: '<S31>/Action Port'
       */
      /* Bias: '<S48>/Add Constant' incorporates:
       *  Bias: '<S48>/Bias'
       *  Sum: '<S48>/Subtract'
       */
      rtb_UnitDelay_f = Code_Gen_Model_B.Spline_Num_Poses -
        Code_Gen_Model_B.Spline_Index + 3.0 + 1.0;

      /* SignalConversion generated from: '<S48>/Selector4' incorporates:
       *  Bias: '<S48>/Bias1'
       *  Constant: '<S50>/FixPt Constant'
       *  Sum: '<S50>/FixPt Sum1'
       */
      rtb_Product7[0] = Code_Gen_Model_B.Spline_Index - 1.0;
      rtb_Product7[1] = Code_Gen_Model_B.Spline_Num_Poses + 2.0;

      /* Selector: '<S48>/Selector4' */
      s53_iter = (int32_T)rtb_Product7[1] - (int32_T)rtb_Product7[0];
      Code_Gen_Model_DW.Selector4_DIMS1[0] = s53_iter + 1;
      Code_Gen_Model_DW.Selector4_DIMS1[1] = 2;
      rtb_Bias1_p = (int32_T)rtb_Product7[0];

      /* Concatenate: '<S48>/Matrix Concatenate' incorporates:
       *  Bias: '<S48>/Add Constant1'
       *  Gain: '<S51>/Gain'
       *  Gain: '<S52>/Gain'
       *  Selector: '<S26>/Selector1'
       *  Selector: '<S48>/Selector'
       *  Selector: '<S48>/Selector1'
       *  Selector: '<S48>/Selector2'
       *  Selector: '<S48>/Selector3'
       *  Sum: '<S51>/Subtract'
       *  Sum: '<S52>/Subtract'
       */
      rtb_Assignment[0] = 2.0 * rtb_Ref_Poses[0] - rtb_Ref_Poses[1];
      rtb_Assignment[21] = 2.0 * rtb_Ref_Poses[19] - rtb_Ref_Poses[20];
      for (i = 0; i < 19; i++) {
        rtb_Assignment[i + 1] = rtb_Ref_Poses[i];
        rtb_Assignment[i + 22] = rtb_Ref_Poses[i + 19];
      }

      for (i = 0; i < 2; i++) {
        rtb_Assignment[21 * i + 20] = rtb_Ref_Poses[19 * i + (int32_T)
          Code_Gen_Model_B.Spline_Num_Poses - 1] * 2.0 - rtb_Ref_Poses[(int32_T)
          (Code_Gen_Model_B.Spline_Num_Poses - 1.0) + 19 * i - 1];

        /* Selector: '<S48>/Selector4' incorporates:
         *  Bias: '<S48>/Add Constant1'
         *  Gain: '<S51>/Gain'
         *  Selector: '<S48>/Selector'
         *  Selector: '<S48>/Selector1'
         *  Sum: '<S51>/Subtract'
         */
        for (rtb_Num_Segments = 0; rtb_Num_Segments <= s53_iter;
             rtb_Num_Segments++) {
          rtb_Selector4[rtb_Num_Segments + Code_Gen_Model_DW.Selector4_DIMS1[0] *
            i] = rtb_Assignment[rtb_Num_Segments + rtb_Bias1_p + 21 * i - 1];
        }
      }

      /* End of Concatenate: '<S48>/Matrix Concatenate' */

      /* Assignment: '<S48>/Assignment' incorporates:
       *  Selector: '<S48>/Selector4'
       */
      memset(&rtb_Assignment[0], 0, 42U * sizeof(real_T));
      rtb_Bias1_p = Code_Gen_Model_DW.Selector4_DIMS1[0];
      i = 0;
      for (rtb_Num_Segments = 0; rtb_Num_Segments < 2; rtb_Num_Segments++) {
        for (s53_iter = 0; s53_iter < rtb_Bias1_p; s53_iter++) {
          rtb_Assignment[s53_iter + i] =
            rtb_Selector4[Code_Gen_Model_DW.Selector4_DIMS1[0] *
            rtb_Num_Segments + s53_iter];
        }

        i += 21;
      }

      /* End of Assignment: '<S48>/Assignment' */

      /* Outputs for Iterator SubSystem: '<S49>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S53>/While Iterator'
       */
      s53_iter = 1;
      do {
        rtb_Init_e = rtb_Assignment[s53_iter + 1];
        rtb_Product7[0] = rtb_Init_e - rtb_Assignment[s53_iter - 1];
        rtb_Minus_n[0] = rtb_Assignment[s53_iter] - rtb_Assignment[s53_iter + 2];
        rtb_Add2_f[0] = rtb_Init_e - rtb_Assignment[s53_iter];
        rtb_Init_e = rtb_Assignment[s53_iter + 22];
        rtb_Product7[1] = rtb_Init_e - rtb_Assignment[s53_iter + 20];
        rtb_Optimized_Module_Angle = rtb_Assignment[s53_iter + 21];
        rtb_Minus_n[1] = rtb_Optimized_Module_Angle - rtb_Assignment[s53_iter +
          23];
        rtb_Add2_f[1] = rtb_Init_e - rtb_Optimized_Module_Angle;
        for (rtb_Bias1_p = 0; rtb_Bias1_p < 50; rtb_Bias1_p++) {
          rtb_POSEexponentialmatrixfori_3 = (real_T)rtb_Bias1_p / 49.0;
          rtb_Init_e = rt_powd_snf(rtb_POSEexponentialmatrixfori_3, 2.0);
          rtb_POSEexponentialmatrixfori_0 = rt_powd_snf
            (rtb_POSEexponentialmatrixfori_3, 3.0);
          rtb_Switch2 = rtb_POSEexponentialmatrixfori_3 - 2.0 * rtb_Init_e +
            rtb_POSEexponentialmatrixfori_0;
          rtb_Switch1_p2 = rtb_Init_e - rtb_POSEexponentialmatrixfori_0;
          rtb_POSEexponentialmatrixfori_0 = 3.0 * rtb_Init_e - 2.0 *
            rtb_POSEexponentialmatrixfori_0;
          rtb_Steer_Joystick_X_Rel_Mod = (rtb_Product7[0] * rtb_Switch2 +
            rtb_Minus_n[0] * rtb_Switch1_p2) * 0.5 + rtb_Add2_f[0] *
            rtb_POSEexponentialmatrixfori_0 + rtb_Assignment[s53_iter];
          rtb_Magnitude = (rtb_Product7[1] * rtb_Switch2 + rtb_Minus_n[1] *
                           rtb_Switch1_p2) * 0.5 + rtb_Add2_f[1] *
            rtb_POSEexponentialmatrixfori_0 + rtb_Optimized_Module_Angle;
          rtb_Switch2 = 3.0 * rtb_Init_e - 4.0 * rtb_POSEexponentialmatrixfori_3
            + 1.0;
          rtb_Switch1_p2 = 2.0 * rtb_POSEexponentialmatrixfori_3 - 3.0 *
            rtb_Init_e;
          rtb_Init_e = (rtb_POSEexponentialmatrixfori_3 - rtb_Init_e) * 6.0;
          rtb_POSEexponentialmatrixfori_0 = (rtb_Product7[0] * rtb_Switch2 +
            rtb_Minus_n[0] * rtb_Switch1_p2) * 0.5 + rtb_Add2_f[0] * rtb_Init_e;
          rtb_Switch2_p = (rtb_Product7[1] * rtb_Switch2 + rtb_Minus_n[1] *
                           rtb_Switch1_p2) * 0.5 + rtb_Add2_f[1] * rtb_Init_e;
          rtb_Init_e = 6.0 * rtb_POSEexponentialmatrixfori_3 - 4.0;
          rtb_Switch2 = -6.0 * rtb_POSEexponentialmatrixfori_3 + 2.0;
          rtb_POSEexponentialmatrixfori_3 = -12.0 *
            rtb_POSEexponentialmatrixfori_3 + 6.0;
          if (rtb_Bias1_p + 1 == 1) {
            memset(&rtb_Assignment_d[0], 0, 150U * sizeof(real_T));
          }

          rtb_Assignment_d[rtb_Bias1_p] = rtb_Steer_Joystick_X_Rel_Mod;
          rtb_Assignment_d[rtb_Bias1_p + 50] = rtb_Magnitude;
          rtb_Assignment_d[rtb_Bias1_p + 100] = fabs(((rtb_Product7[1] *
            rtb_Init_e + rtb_Minus_n[1] * rtb_Switch2) * 0.5 + rtb_Add2_f[1] *
            rtb_POSEexponentialmatrixfori_3) * rtb_POSEexponentialmatrixfori_0 -
            ((rtb_Product7[0] * rtb_Init_e + rtb_Minus_n[0] * rtb_Switch2) * 0.5
             + rtb_Add2_f[0] * rtb_POSEexponentialmatrixfori_3) * rtb_Switch2_p)
            / rt_powd_snf(rt_hypotd_snf(rtb_POSEexponentialmatrixfori_0,
            rtb_Switch2_p), 3.0);
        }

        if (s53_iter == 1) {
          memset(&Code_Gen_Model_B.Assignment[0], 0, 450U * sizeof(real_T));
        }

        for (i = 0; i < 3; i++) {
          memcpy(&Code_Gen_Model_B.Assignment[i * 50 + s53_iter * 150 + -150],
                 &rtb_Assignment_d[i * 50], 50U * sizeof(real_T));
        }

        rtb_POSEexponentialmatrixfori_3 = rtb_UnitDelay_f - (real_T)s53_iter;
        rtb_Num_Segments = s53_iter;
        s53_iter++;
      } while (rtb_POSEexponentialmatrixfori_3 >= 4.0 && s53_iter <= 3);

      /* End of Outputs for SubSystem: '<S49>/Sampling_Loop' */

      /* SignalConversion generated from: '<S31>/Position_and_Curvature' incorporates:
       *  Assignment: '<S53>/Assignment'
       *  Merge: '<S26>/Merge'
       */
      memcpy(&rtb_Position_and_Curvature[0], &Code_Gen_Model_B.Assignment[0],
             450U * sizeof(real_T));

      /* End of Outputs for SubSystem: '<S26>/Make_Knots_and_Path_Planning' */
    } else {
      /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      /* Product: '<S29>/Product' incorporates:
       *  Selector: '<S26>/Selector'
       *  Selector: '<S26>/Selector1'
       */
      rtb_POSEexponentialmatrixfori_3 = rtb_Ref_Poses[(int32_T)
        Code_Gen_Model_B.Spline_Num_Poses - 1];

      /* Product: '<S29>/Product1' incorporates:
       *  Selector: '<S26>/Selector'
       *  Selector: '<S26>/Selector1'
       */
      rtb_Init_e = rtb_Ref_Poses[(int32_T)Code_Gen_Model_B.Spline_Num_Poses + 18];
      for (i = 0; i < 50; i++) {
        /* Product: '<S29>/Product' incorporates:
         *  Constant: '<S29>/Constant2'
         */
        rtb_MatrixConcatenate_h[i] = rtb_POSEexponentialmatrixfori_3;

        /* Product: '<S29>/Product1' incorporates:
         *  Constant: '<S29>/Constant2'
         *  Product: '<S29>/Product'
         */
        rtb_MatrixConcatenate_h[i + 50] = rtb_Init_e;
      }

      /* Assignment: '<S29>/Assignment' incorporates:
       *  Concatenate: '<S29>/Matrix Concatenate'
       *  Merge: '<S26>/Merge'
       */
      memset(&rtb_Position_and_Curvature[0], 0, 450U * sizeof(real_T));
      for (i = 0; i < 50; i++) {
        rtb_Position_and_Curvature[i] = rtb_MatrixConcatenate_h[i];
        rtb_Position_and_Curvature[i + 50] = rtb_MatrixConcatenate_h[i + 50];
      }

      /* End of Assignment: '<S29>/Assignment' */

      /* SignalConversion generated from: '<S29>/Num_Segments' incorporates:
       *  Constant: '<S29>/Constant1'
       */
      rtb_Num_Segments = 1;

      /* End of Outputs for SubSystem: '<S26>/If Action Subsystem' */
    }

    /* End of If: '<S26>/If1' */

    /* Concatenate: '<S27>/Matrix Concatenate' incorporates:
     *  Merge: '<S26>/Merge'
     *  Selector: '<S27>/Selector'
     *  Selector: '<S27>/Selector1'
     *  Selector: '<S27>/Selector3'
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

    /* End of Concatenate: '<S27>/Matrix Concatenate' */

    /* MATLAB Function: '<S27>/Distance Along Curve' incorporates:
     *  Concatenate: '<S27>/Matrix Concatenate'
     *  Selector: '<S27>/Selector4'
     *  Selector: '<S27>/Selector5'
     */
    memset(&rtb_Assignment_d[0], 0, 150U * sizeof(real_T));
    for (s53_iter = 0; s53_iter < 149; s53_iter++) {
      /* Outputs for Iterator SubSystem: '<S49>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S53>/While Iterator'
       */
      rtb_Assignment_d[s53_iter + 1] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s53_iter + 1] -
         rtb_MatrixConcatenate_o[s53_iter], rtb_MatrixConcatenate_o[s53_iter +
         151] - rtb_MatrixConcatenate_o[s53_iter + 150]) +
        rtb_Assignment_d[s53_iter];

      /* End of Outputs for SubSystem: '<S49>/Sampling_Loop' */
    }

    /* End of MATLAB Function: '<S27>/Distance Along Curve' */

    /* MATLAB Function: '<S27>/Find closest index to curve' incorporates:
     *  Concatenate: '<S27>/Matrix Concatenate'
     *  Selector: '<S27>/Selector4'
     *  Selector: '<S27>/Selector5'
     *  Selector: '<S79>/Selector'
     */
    for (s53_iter = 0; s53_iter < 150; s53_iter++) {
      /* Outputs for Iterator SubSystem: '<S49>/Sampling_Loop' incorporates:
       *  WhileIterator: '<S53>/While Iterator'
       */
      distance_from_robot[s53_iter] = rt_hypotd_snf
        (rtb_MatrixConcatenate_o[s53_iter] -
         Code_Gen_Model_B.Odom_Position_X_global,
         rtb_MatrixConcatenate_o[s53_iter + 150] -
         Code_Gen_Model_B.Odom_Position_Y_global);

      /* End of Outputs for SubSystem: '<S49>/Sampling_Loop' */
    }

    if (!rtIsNaN(distance_from_robot[0])) {
      s53_iter = 1;
    } else {
      s53_iter = 0;
      rtb_Bias1_p = 2;
      exitg1 = false;
      while (!exitg1 && rtb_Bias1_p < 151) {
        if (!rtIsNaN(distance_from_robot[rtb_Bias1_p - 1])) {
          s53_iter = rtb_Bias1_p;
          exitg1 = true;
        } else {
          rtb_Bias1_p++;
        }
      }
    }

    if (s53_iter == 0) {
      rtb_UnitDelay_f = distance_from_robot[0];
    } else {
      rtb_UnitDelay_f = distance_from_robot[s53_iter - 1];
      for (rtb_Bias1_p = s53_iter + 1; rtb_Bias1_p < 151; rtb_Bias1_p++) {
        rtb_POSEexponentialmatrixfori_3 = distance_from_robot[rtb_Bias1_p - 1];
        if (rtb_UnitDelay_f > rtb_POSEexponentialmatrixfori_3) {
          rtb_UnitDelay_f = rtb_POSEexponentialmatrixfori_3;
        }
      }
    }

    s53_iter = 1;
    rtb_Bias1_p = 0;
    exitg1 = false;
    while (!exitg1 && rtb_Bias1_p < 150) {
      s53_iter = rtb_Bias1_p + 1;
      if (distance_from_robot[rtb_Bias1_p] == rtb_UnitDelay_f) {
        exitg1 = true;
      } else {
        rtb_Bias1_p++;
      }
    }

    /* Selector: '<S79>/Selector' incorporates:
     *  Constant: '<S79>/Constant'
     *  MATLAB Function: '<S27>/Find closest index to curve'
     *  MinMax: '<S79>/Min'
     */
    rtb_POSEexponentialmatrixfori_3 = rtb_Assignment_d[(int32_T)fmin(50.0,
      s53_iter) - 1];

    /* If: '<S79>/If' incorporates:
     *  RelationalOperator: '<S79>/Relational Operator'
     */
    if (rtb_Assignment_d[0] != rtb_Assignment_d[49]) {
      /* Outputs for IfAction SubSystem: '<S79>/Dynamic Lookup Tables' incorporates:
       *  ActionPort: '<S82>/Action Port'
       */
      /* SignalConversion generated from: '<S82>/Lookup Table Dynamic' */
      rtb_Product7[0] = rtb_Assignment_d[0];
      rtb_Product7[1] = rtb_Assignment_d[49];

      /* Sum: '<S84>/FixPt Sum1' incorporates:
       *  Constant: '<S84>/FixPt Constant'
       */
      rtb_UnitDelay_f = Code_Gen_Model_B.Spline_Index - 1.0;

      /* SignalConversion generated from: '<S82>/Lookup Table Dynamic' incorporates:
       *  Merge: '<S6>/Merge8'
       *  Selector: '<S82>/Selector11'
       *  Selector: '<S82>/Selector12'
       */
      rtb_Minus_n[0] = rtb_Spline_Ref_Poses[(int32_T)rtb_UnitDelay_f + 37];
      rtb_Minus_n[1] = rtb_Spline_Ref_Poses[(int32_T)
        Code_Gen_Model_B.Spline_Index + 37];

      /* SignalConversion generated from: '<S82>/Lookup Table Dynamic1' incorporates:
       *  Merge: '<S6>/Merge8'
       *  Selector: '<S82>/Selector1'
       *  Selector: '<S82>/Selector2'
       */
      rtb_Add2_f[0] = rtb_Spline_Ref_Poses[(int32_T)rtb_UnitDelay_f + 56];
      rtb_Add2_f[1] = rtb_Spline_Ref_Poses[(int32_T)
        Code_Gen_Model_B.Spline_Index + 56];

      /* S-Function (sfix_look1_dyn): '<S82>/Lookup Table Dynamic' */
      /* Dynamic Look-Up Table Block: '<S82>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_UnitDelay_f), &rtb_Minus_n[0],
                           rtb_POSEexponentialmatrixfori_3, &rtb_Product7[0], 1U);

      /* SignalConversion: '<S82>/Signal Copy' incorporates:
       *  S-Function (sfix_look1_dyn): '<S82>/Lookup Table Dynamic1'
       */
      /* Dynamic Look-Up Table Block: '<S82>/Lookup Table Dynamic1'
       * Input0  Data Type:  Floating Point real_T
       * Input1  Data Type:  Floating Point real_T
       * Input2  Data Type:  Floating Point real_T
       * Output0 Data Type:  Floating Point real_T
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_real_T_real_T( &(rtb_Merge1), &rtb_Add2_f[0],
                           rtb_POSEexponentialmatrixfori_3, &rtb_Product7[0], 1U);

      /* End of Outputs for SubSystem: '<S79>/Dynamic Lookup Tables' */
    } else {
      /* Outputs for IfAction SubSystem: '<S79>/Latch' incorporates:
       *  ActionPort: '<S83>/Action Port'
       */
      /* SignalConversion generated from: '<S83>/In1' incorporates:
       *  UnitDelay: '<S79>/Unit Delay1'
       */
      rtb_UnitDelay_f = Code_Gen_Model_DW.UnitDelay1_DSTATE_f4;

      /* SignalConversion generated from: '<S83>/In2' incorporates:
       *  UnitDelay: '<S79>/Unit Delay'
       */
      rtb_Merge1 = Code_Gen_Model_DW.UnitDelay_DSTATE_g4g;

      /* End of Outputs for SubSystem: '<S79>/Latch' */
    }

    /* End of If: '<S79>/If' */

    /* Outputs for Iterator SubSystem: '<S27>/Find first index that meets distance target' incorporates:
     *  WhileIterator: '<S78>/While Iterator'
     */
    s78_iter = 1U;
    rtb_Is_Absolute_Translation = true;
    while (rtb_Is_Absolute_Translation && s78_iter <= 150) {
      /* Outputs for Iterator SubSystem: '<S27>/Find first index that meets distance target' incorporates:
       *  WhileIterator: '<S78>/While Iterator'
       */
      Code_Gen_Model_B.WhileIterator = s78_iter;
      rtb_Is_Absolute_Translation =
        rtb_Assignment_d[Code_Gen_Model_B.WhileIterator - 1] <=
        rtb_Assignment_d[s53_iter - 1] + Spline_Lookahead_Dist &&
        Code_Gen_Model_B.WhileIterator < (real_T)rtb_Num_Segments * 50.0;
      s78_iter++;
    }

    /* End of Outputs for SubSystem: '<S27>/Find first index that meets distance target' */

    /* Logic: '<S28>/OR' incorporates:
     *  Constant: '<S27>/Lookahead Distance'
     *  Constant: '<S78>/Constant'
     *  Logic: '<S78>/AND'
     *  MATLAB Function: '<S27>/Find closest index to curve'
     *  Product: '<S78>/Product'
     *  RelationalOperator: '<S78>/Relational Operator'
     *  RelationalOperator: '<S78>/Relational Operator1'
     *  Selector: '<S78>/Selector'
     *  Selector: '<S78>/Selector1'
     *  Selector: '<S79>/Selector'
     *  Sum: '<S78>/Add'
     */
    rtb_OR_ao = rtb_Is_Absolute_Steering ||
      Code_Gen_Model_B.Spline_Out_Of_Bounds;

    /* Switch: '<S28>/Switch1' incorporates:
     *  Constant: '<S27>/Constant'
     *  RelationalOperator: '<S27>/Relational Operator'
     *  Sum: '<S27>/Subtract'
     *  Switch: '<S28>/Switch'
     *  Switch: '<S81>/Switch'
     *  UnitDelay: '<S28>/Unit Delay'
     */
    if (rtb_OR_ao) {
      /* Merge: '<S8>/Merge2' incorporates:
       *  Constant: '<S28>/Constant3'
       */
      Code_Gen_Model_B.Translation_Speed_SPF = 0.0;
      rtb_POSEexponentialmatrixfori_3 = Code_Gen_Model_DW.UnitDelay_DSTATE_le;
    } else {
      if (Code_Gen_Model_B.Spline_Index >= Code_Gen_Model_B.Spline_Num_Poses -
          Spline_Pose_Num_Before_End_Reduce_Speed) {
        /* Merge: '<S8>/Merge2' incorporates:
         *  Concatenate: '<S27>/Matrix Concatenate'
         *  Constant: '<S81>/Constant1'
         *  Constant: '<S81>/Constant2'
         *  Constant: '<S81>/Constant3'
         *  Math: '<S81>/Hypot'
         *  Merge: '<S6>/Merge8'
         *  MinMax: '<S81>/Min'
         *  MinMax: '<S81>/Min1'
         *  Product: '<S81>/Divide'
         *  Product: '<S81>/Product'
         *  Product: '<S81>/Product1'
         *  Selector: '<S27>/Selector10'
         *  Selector: '<S27>/Selector7'
         *  Selector: '<S27>/Selector8'
         *  Selector: '<S27>/Selector9'
         *  Sqrt: '<S81>/Sqrt'
         *  Sum: '<S81>/Subtract'
         *  Sum: '<S81>/Subtract1'
         *  Switch: '<S81>/Switch'
         */
        Code_Gen_Model_B.Translation_Speed_SPF = fmin(rt_hypotd_snf
          (rtb_Spline_Ref_Poses[18] - Code_Gen_Model_B.Odom_Position_X_global,
           rtb_Spline_Ref_Poses[37] - Code_Gen_Model_B.Odom_Position_Y_global) *
          Spline_Last_Pose_Distance_to_Velocity_Gain, fmin(rtb_UnitDelay_f *
          Spline_Velocity_Multiplier_TEST, sqrt
          (Spline_Max_Centripital_Acceleration /
           rtb_MatrixConcatenate_o[Code_Gen_Model_B.WhileIterator + 299])));
      } else {
        /* Merge: '<S8>/Merge2' incorporates:
         *  Concatenate: '<S27>/Matrix Concatenate'
         *  Constant: '<S81>/Constant1'
         *  Constant: '<S81>/Constant3'
         *  MinMax: '<S81>/Min1'
         *  Product: '<S81>/Divide'
         *  Product: '<S81>/Product1'
         *  Selector: '<S27>/Selector10'
         *  Selector: '<S27>/Selector7'
         *  Sqrt: '<S81>/Sqrt'
         *  Switch: '<S81>/Switch'
         */
        Code_Gen_Model_B.Translation_Speed_SPF = fmin(rtb_UnitDelay_f *
          Spline_Velocity_Multiplier_TEST, sqrt
          (Spline_Max_Centripital_Acceleration /
           rtb_MatrixConcatenate_o[Code_Gen_Model_B.WhileIterator + 299]));
      }

      rtb_POSEexponentialmatrixfori_3 = rtb_Merge1;
    }

    /* End of Switch: '<S28>/Switch1' */

    /* Merge: '<S8>/Merge' incorporates:
     *  SignalConversion: '<S28>/Signal Copy'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd_SPF = rtb_POSEexponentialmatrixfori_3;

    /* Selector: '<S27>/Selector6' incorporates:
     *  Concatenate: '<S27>/Matrix Concatenate'
     *  Selector: '<S27>/Selector5'
     */
    Code_Gen_Model_B.Spline_Target_Y =
      rtb_MatrixConcatenate_o[Code_Gen_Model_B.WhileIterator + 149];

    /* Selector: '<S27>/Selector2' incorporates:
     *  Concatenate: '<S27>/Matrix Concatenate'
     *  Selector: '<S27>/Selector4'
     */
    Code_Gen_Model_B.Spline_Target_X =
      rtb_MatrixConcatenate_o[Code_Gen_Model_B.WhileIterator - 1];

    /* Switch: '<S28>/Switch2' incorporates:
     *  Sum: '<S85>/Subtract'
     *  Sum: '<S85>/Subtract1'
     *  Trigonometry: '<S85>/Atan2'
     *  UnitDelay: '<S28>/Unit Delay1'
     */
    if (rtb_OR_ao) {
      rtb_Init_e = Code_Gen_Model_DW.UnitDelay1_DSTATE_kc;
    } else {
      rtb_Init_e = rt_atan2d_snf(Code_Gen_Model_B.Spline_Target_Y -
        Code_Gen_Model_B.Odom_Position_Y_global,
        Code_Gen_Model_B.Spline_Target_X -
        Code_Gen_Model_B.Odom_Position_X_global);
    }

    /* End of Switch: '<S28>/Switch2' */

    /* Merge: '<S8>/Merge3' incorporates:
     *  SignalConversion: '<S28>/Signal Copy2'
     */
    Code_Gen_Model_B.Translation_Angle_SPF = rtb_Init_e;

    /* Merge: '<S8>/Merge7' incorporates:
     *  SignalConversion: '<S25>/Signal Copy'
     */
    Code_Gen_Model_B.Robot_Reached_Destination = rtb_Is_Absolute_Steering;

    /* Merge: '<S8>/Merge1' incorporates:
     *  Constant: '<S28>/Constant2'
     *  SignalConversion generated from: '<S25>/Steering_Rel_Cmd'
     */
    Code_Gen_Model_B.Steering_Rel_Cmd_SPF = 0.0;

    /* Merge: '<S8>/Merge4' incorporates:
     *  Constant: '<S28>/Constant5'
     *  SignalConversion generated from: '<S25>/Is_Absolute_Translation'
     */
    Code_Gen_Model_B.Is_Absolute_Translation_SPF = true;

    /* Merge: '<S8>/Merge5' incorporates:
     *  Constant: '<S28>/Constant6'
     *  SignalConversion generated from: '<S25>/Is_Absolute_Steering'
     */
    Code_Gen_Model_B.Is_Absolute_Steering_SPF = true;

    /* Merge: '<S8>/Merge6' incorporates:
     *  Constant: '<S28>/Constant1'
     *  SignalConversion generated from: '<S25>/Gyro_Angle_Adjustment'
     */
    Code_Gen_Model_B.Gyro_Angle_Adjustment_SPF = 0.0;

    /* Update for UnitDelay: '<S26>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_gh = Code_Gen_Model_B.Spline_Index;

    /* Update for UnitDelay: '<S79>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_f4 = rtb_UnitDelay_f;

    /* Update for UnitDelay: '<S79>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_g4g = rtb_Merge1;

    /* Update for UnitDelay: '<S28>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_le = rtb_POSEexponentialmatrixfori_3;

    /* Update for UnitDelay: '<S28>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_kc = rtb_Init_e;

    /* End of Outputs for SubSystem: '<S8>/Spline Path Following Enabled' */
  } else {
    /* Outputs for IfAction SubSystem: '<S8>/Pass Through' incorporates:
     *  ActionPort: '<S24>/Action Port'
     */
    /* Merge: '<S8>/Merge7' incorporates:
     *  Constant: '<S24>/Constant'
     *  SignalConversion generated from: '<S24>/Robot_Reached_Destination'
     */
    Code_Gen_Model_B.Robot_Reached_Destination = false;

    /* Merge: '<S8>/Merge' incorporates:
     *  SignalConversion generated from: '<S24>/Steering_Abs_Cmd_In'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd_SPF = Code_Gen_Model_B.Steering_Abs_Cmd;

    /* Merge: '<S8>/Merge1' incorporates:
     *  SignalConversion generated from: '<S24>/Steering_Rel_Cmd_In'
     */
    Code_Gen_Model_B.Steering_Rel_Cmd_SPF = Code_Gen_Model_B.Steering_Rel_Cmd;

    /* Merge: '<S8>/Merge2' incorporates:
     *  SignalConversion generated from: '<S24>/Translation_Speed_In'
     */
    Code_Gen_Model_B.Translation_Speed_SPF = Code_Gen_Model_B.Translation_Speed;

    /* Merge: '<S8>/Merge3' incorporates:
     *  SignalConversion generated from: '<S24>/Translation_Angle_In'
     */
    Code_Gen_Model_B.Translation_Angle_SPF = Code_Gen_Model_B.Translation_Angle;

    /* Merge: '<S8>/Merge4' incorporates:
     *  SignalConversion generated from: '<S24>/Is_Absolute_Translation_In'
     */
    Code_Gen_Model_B.Is_Absolute_Translation_SPF = rtb_Is_Absolute_Translation;

    /* Merge: '<S8>/Merge5' incorporates:
     *  SignalConversion generated from: '<S24>/Is_Absolute_Steering_In'
     */
    Code_Gen_Model_B.Is_Absolute_Steering_SPF = rtb_Is_Absolute_Steering;

    /* Merge: '<S8>/Merge6' incorporates:
     *  SignalConversion generated from: '<S24>/Gyro_Angle_Adjustment_In'
     */
    Code_Gen_Model_B.Gyro_Angle_Adjustment_SPF = rtb_UnitDelay_f;

    /* End of Outputs for SubSystem: '<S8>/Pass Through' */
  }

  /* End of If: '<S8>/If' */

  /* Signum: '<S179>/Sign2' incorporates:
   *  UnitDelay: '<S179>/Unit Delay'
   */
  if (rtIsNaN(Code_Gen_Model_B.Translation_Speed_RL)) {
    rtb_Add_ec = (rtNaN);
  } else if (Code_Gen_Model_B.Translation_Speed_RL < 0.0) {
    rtb_Add_ec = -1.0;
  } else {
    rtb_Add_ec = Code_Gen_Model_B.Translation_Speed_RL > 0.0;
  }

  /* Signum: '<S179>/Sign1' */
  if (rtIsNaN(Code_Gen_Model_B.Translation_Speed_SPF)) {
    rtb_Add_cz = (rtNaN);
  } else if (Code_Gen_Model_B.Translation_Speed_SPF < 0.0) {
    rtb_Add_cz = -1.0;
  } else {
    rtb_Add_cz = Code_Gen_Model_B.Translation_Speed_SPF > 0.0;
  }

  /* Product: '<S179>/Product1' incorporates:
   *  Signum: '<S179>/Sign1'
   *  Signum: '<S179>/Sign2'
   */
  rtb_Add_ec *= rtb_Add_cz;
  if (rtIsNaN(rtb_Add_ec)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_ec, 256.0);
  }

  if (i < 0) {
    i = (int8_T)-(int8_T)(uint8_T)-(real_T)i;
  }

  /* Switch: '<S179>/Switch' incorporates:
   *  Constant: '<S179>/Constant'
   *  Constant: '<S184>/Constant'
   *  Constant: '<S185>/Constant'
   *  Logic: '<S179>/or'
   *  Product: '<S179>/Product1'
   *  RelationalOperator: '<S184>/Compare'
   *  RelationalOperator: '<S185>/Compare'
   *  UnitDelay: '<S179>/Unit Delay'
   */
  if (Code_Gen_Model_B.Translation_Speed_RL == 0.0 || i > 0) {
    rtb_Switch2_p = Code_Gen_Model_B.Translation_Speed_SPF;
  } else {
    rtb_Switch2_p = 0.0;
  }

  /* End of Switch: '<S179>/Switch' */

  /* Switch: '<S190>/Init' incorporates:
   *  UnitDelay: '<S190>/FixPt Unit Delay1'
   *  UnitDelay: '<S190>/FixPt Unit Delay2'
   */
  if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Optimized_Module_Angle = rtb_Switch2_p;
  } else {
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.Translation_Speed_RL;
  }

  /* End of Switch: '<S190>/Init' */

  /* RelationalOperator: '<S186>/Compare' incorporates:
   *  Constant: '<S186>/Constant'
   */
  rtb_Is_Absolute_Translation = rtb_Switch2_p == 0.0;

  /* RelationalOperator: '<S187>/Compare' incorporates:
   *  Constant: '<S187>/Constant'
   */
  rtb_Is_Absolute_Steering = rtb_Switch2_p > 0.0;

  /* Abs: '<S179>/Abs' incorporates:
   *  Sum: '<S179>/Subtract'
   *  UnitDelay: '<S179>/Unit Delay'
   */
  rtb_Merge1 = fabs(Code_Gen_Model_B.Translation_Speed_RL -
                    Code_Gen_Model_B.Translation_Speed_SPF);

  /* Switch: '<S179>/Switch5' incorporates:
   *  Switch: '<S179>/Switch1'
   */
  if (rtb_Is_Absolute_Translation) {
    /* SignalConversion generated from: '<S179>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S179>/Constant4'
     *  Constant: '<S179>/Constant6'
     */
    rtb_Product7[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S179>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S179>/Constant2'
     *  Constant: '<S179>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S179>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S179>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_j), &rtb_Product7[0],
                         rtb_Merge1, &rtb_Minus_n[0], 1U);
    rtb_Merge1 = rtb_LookupTableDynamic_j;
    rtb_Add_ec = Code_Gen_Model_ConstB.UnaryMinus;
  } else {
    /* SignalConversion generated from: '<S179>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S179>/Constant10'
     *  Constant: '<S179>/Constant8'
     */
    rtb_Product7[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S179>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S179>/Constant7'
     *  Constant: '<S179>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S179>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S179>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_i), &rtb_Product7[0],
                         rtb_Merge1, &rtb_Minus_n[0], 1U);
    rtb_Merge1 = rtb_LookupTableDynamic1_i;

    /* Switch: '<S179>/Switch3' incorporates:
     *  Constant: '<S179>/Constant3'
     */
    if (rtb_Is_Absolute_Steering) {
      rtb_Add_ec = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Add_ec = Code_Gen_Model_ConstB.UnaryMinus;
    }

    /* End of Switch: '<S179>/Switch3' */
  }

  /* End of Switch: '<S179>/Switch5' */

  /* Product: '<S179>/Product' incorporates:
   *  Switch: '<S179>/Switch1'
   */
  rtb_uDLookupTable_l = rtb_Add_ec * rtb_Merge1;

  /* Sum: '<S188>/Sum1' */
  rtb_UnitDelay_f = rtb_Switch2_p - rtb_Optimized_Module_Angle;

  /* Switch: '<S189>/Switch2' incorporates:
   *  RelationalOperator: '<S189>/LowerRelop1'
   */
  if (!(rtb_UnitDelay_f > rtb_uDLookupTable_l)) {
    /* Switch: '<S179>/Switch2' incorporates:
     *  Constant: '<S179>/Constant1'
     *  Switch: '<S179>/Switch4'
     */
    if (rtb_Is_Absolute_Translation) {
      rtb_POSEexponentialmatrixfori_3 = -0.2;
    } else if (rtb_Is_Absolute_Steering) {
      /* Switch: '<S179>/Switch4' incorporates:
       *  Constant: '<S179>/Constant1'
       */
      rtb_POSEexponentialmatrixfori_3 = -0.2;
    } else {
      /* Switch: '<S179>/Switch4' incorporates:
       *  Constant: '<S179>/Constant3'
       *  UnaryMinus: '<S179>/Unary Minus1'
       */
      rtb_POSEexponentialmatrixfori_3 = -Translation_Speed_Rate_Limit_Inc;
    }

    /* End of Switch: '<S179>/Switch2' */

    /* Product: '<S179>/Product2' */
    rtb_POSEexponentialmatrixfori_3 *= rtb_Merge1;

    /* Switch: '<S189>/Switch' incorporates:
     *  RelationalOperator: '<S189>/UpperRelop'
     */
    if (rtb_UnitDelay_f < rtb_POSEexponentialmatrixfori_3) {
      rtb_uDLookupTable_l = rtb_POSEexponentialmatrixfori_3;
    } else {
      rtb_uDLookupTable_l = rtb_UnitDelay_f;
    }

    /* End of Switch: '<S189>/Switch' */
  }

  /* End of Switch: '<S189>/Switch2' */

  /* Sum: '<S188>/Sum' */
  Code_Gen_Model_B.Translation_Speed_RL = rtb_uDLookupTable_l +
    rtb_Optimized_Module_Angle;

  /* Switch: '<S182>/Switch' */
  if (Code_Gen_Model_B.Is_Absolute_Translation_SPF) {
    /* Switch: '<S182>/Switch' incorporates:
     *  Constant: '<S206>/Constant3'
     *  Constant: '<S206>/Constant4'
     *  Math: '<S206>/Math Function'
     *  Sum: '<S182>/Subtract'
     *  Sum: '<S206>/Add1'
     *  Sum: '<S206>/Add2'
     */
    Code_Gen_Model_B.Translation_Steering_Cmd = rt_modd_snf
      (Code_Gen_Model_B.Translation_Angle_SPF - rtb_thetay + 3.1415926535897931,
       6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S182>/Switch' */
    Code_Gen_Model_B.Translation_Steering_Cmd =
      Code_Gen_Model_B.Translation_Angle_SPF;
  }

  /* End of Switch: '<S182>/Switch' */

  /* Sum: '<S202>/Add1' incorporates:
   *  Constant: '<S202>/Constant3'
   *  Constant: '<S202>/Constant4'
   *  Math: '<S202>/Math Function'
   *  Sum: '<S181>/Add'
   *  Sum: '<S201>/Sum'
   *  Sum: '<S202>/Add2'
   */
  rtb_Optimized_Module_Angle = rt_modd_snf(Code_Gen_Model_B.Steering_Abs_Cmd_SPF
    - (rtb_thetay + Code_Gen_Model_B.Gyro_Angle_Adjustment_SPF) +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S204>/Sum1' incorporates:
   *  Constant: '<S201>/Constant2'
   *  Product: '<S204>/Product'
   *  Sum: '<S204>/Sum'
   *  UnitDelay: '<S204>/Unit Delay1'
   */
  rtb_Merge1 = (rtb_Optimized_Module_Angle - Code_Gen_Model_DW.UnitDelay1_DSTATE)
    * Steering_Heading_Control_D_FilterCoeff +
    Code_Gen_Model_DW.UnitDelay1_DSTATE;

  /* Product: '<S201>/Product' incorporates:
   *  Constant: '<S201>/Constant3'
   */
  rtb_UnitDelay_f = rtb_Merge1 * Steering_Heading_Control_D;

  /* Sum: '<S203>/Diff' incorporates:
   *  UnitDelay: '<S203>/UD'
   *
   * Block description for '<S203>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S203>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_UnitDelay_f - Code_Gen_Model_DW.UD_DSTATE_a;

  /* Saturate: '<S201>/Saturation' */
  if (rtb_Add_ec > Steering_Heading_Control_D_UL) {
    rtb_Add_ec = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_ec < Steering_Heading_Control_D_LL) {
    rtb_Add_ec = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S201>/Add' incorporates:
   *  Gain: '<S201>/Gain1'
   *  Saturate: '<S201>/Saturation'
   */
  rtb_Init_e = Steering_Heading_Control_P * rtb_Optimized_Module_Angle +
    rtb_Add_ec;

  /* Sum: '<S201>/Subtract' incorporates:
   *  Constant: '<S201>/Constant'
   */
  rtb_uDLookupTable_l = Steering_Heading_Control_Total_UL - rtb_Init_e;

  /* Sum: '<S201>/Sum2' incorporates:
   *  Gain: '<S201>/Gain2'
   *  UnitDelay: '<S201>/Unit Delay'
   */
  rtb_POSEexponentialmatrixfori_3 = Steering_Heading_Control_I *
    rtb_Optimized_Module_Angle + Code_Gen_Model_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S205>/Switch2' incorporates:
   *  RelationalOperator: '<S205>/LowerRelop1'
   */
  if (!(rtb_POSEexponentialmatrixfori_3 > rtb_uDLookupTable_l)) {
    /* Sum: '<S201>/Subtract1' incorporates:
     *  Constant: '<S201>/Constant1'
     */
    rtb_Switch2 = Steering_Heading_Control_Total_LL - rtb_Init_e;

    /* Switch: '<S205>/Switch' incorporates:
     *  RelationalOperator: '<S205>/UpperRelop'
     */
    if (rtb_POSEexponentialmatrixfori_3 < rtb_Switch2) {
      rtb_uDLookupTable_l = rtb_Switch2;
    } else {
      rtb_uDLookupTable_l = rtb_POSEexponentialmatrixfori_3;
    }

    /* End of Switch: '<S205>/Switch' */
  }

  /* End of Switch: '<S205>/Switch2' */

  /* Saturate: '<S201>/Saturation1' */
  if (rtb_uDLookupTable_l > Steering_Heading_Control_I_UL) {
    rtb_POSEexponentialmatrixfori_3 = Steering_Heading_Control_I_UL;
  } else if (rtb_uDLookupTable_l < Steering_Heading_Control_I_LL) {
    rtb_POSEexponentialmatrixfori_3 = Steering_Heading_Control_I_LL;
  } else {
    rtb_POSEexponentialmatrixfori_3 = rtb_uDLookupTable_l;
  }

  /* End of Saturate: '<S201>/Saturation1' */

  /* Sum: '<S201>/Add1' */
  rtb_Add_ec = rtb_Init_e + rtb_POSEexponentialmatrixfori_3;

  /* Saturate: '<S201>/Saturation2' */
  if (rtb_Add_ec > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S201>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_ec < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S201>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S201>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = rtb_Add_ec;
  }

  /* End of Saturate: '<S201>/Saturation2' */

  /* Switch: '<S181>/Switch' incorporates:
   *  Switch: '<S192>/Switch'
   */
  if (Code_Gen_Model_B.Is_Absolute_Steering_SPF) {
    /* Switch: '<S192>/Switch' incorporates:
     *  Abs: '<S192>/Abs'
     *  Constant: '<S192>/Constant'
     *  Constant: '<S200>/Constant'
     *  RelationalOperator: '<S200>/Compare'
     */
    if (fabs(Code_Gen_Model_B.Steering_Localized_PID) >
        Steering_Heading_Control_Deadzone) {
      rtb_Optimized_Module_Angle = Code_Gen_Model_B.Steering_Localized_PID;
    } else {
      rtb_Optimized_Module_Angle = 0.0;
    }
  } else {
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.Steering_Rel_Cmd_SPF;
  }

  /* End of Switch: '<S181>/Switch' */

  /* Signum: '<S191>/Sign2' incorporates:
   *  UnitDelay: '<S191>/Unit Delay'
   */
  if (rtIsNaN(Code_Gen_Model_B.Steering_Localized_Cmd)) {
    rtb_Add_ec = (rtNaN);
  } else if (Code_Gen_Model_B.Steering_Localized_Cmd < 0.0) {
    rtb_Add_ec = -1.0;
  } else {
    rtb_Add_ec = Code_Gen_Model_B.Steering_Localized_Cmd > 0.0;
  }

  /* Signum: '<S191>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle)) {
    rtb_Add_cz = (rtNaN);
  } else if (rtb_Optimized_Module_Angle < 0.0) {
    rtb_Add_cz = -1.0;
  } else {
    rtb_Add_cz = rtb_Optimized_Module_Angle > 0.0;
  }

  /* Product: '<S191>/Product1' incorporates:
   *  Signum: '<S191>/Sign1'
   *  Signum: '<S191>/Sign2'
   */
  rtb_Add_ec *= rtb_Add_cz;
  if (rtIsNaN(rtb_Add_ec)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Add_ec, 256.0);
  }

  if (i < 0) {
    i = (int8_T)-(int8_T)(uint8_T)-(real_T)i;
  }

  /* Switch: '<S191>/Switch' incorporates:
   *  Constant: '<S191>/Constant'
   *  Constant: '<S193>/Constant'
   *  Constant: '<S194>/Constant'
   *  Logic: '<S191>/or'
   *  Product: '<S191>/Product1'
   *  RelationalOperator: '<S193>/Compare'
   *  RelationalOperator: '<S194>/Compare'
   *  UnitDelay: '<S191>/Unit Delay'
   */
  if (Code_Gen_Model_B.Steering_Localized_Cmd == 0.0 || i > 0) {
    rtb_Switch1_p2 = rtb_Optimized_Module_Angle;
  } else {
    rtb_Switch1_p2 = 0.0;
  }

  /* End of Switch: '<S191>/Switch' */

  /* Switch: '<S199>/Init' incorporates:
   *  UnitDelay: '<S199>/FixPt Unit Delay1'
   *  UnitDelay: '<S199>/FixPt Unit Delay2'
   */
  if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Init_e = rtb_Switch1_p2;
  } else {
    rtb_Init_e = Code_Gen_Model_B.Steering_Localized_Cmd;
  }

  /* End of Switch: '<S199>/Init' */

  /* RelationalOperator: '<S195>/Compare' incorporates:
   *  Constant: '<S195>/Constant'
   */
  rtb_Is_Absolute_Translation = rtb_Switch1_p2 == 0.0;

  /* RelationalOperator: '<S196>/Compare' incorporates:
   *  Constant: '<S196>/Constant'
   */
  rtb_Is_Absolute_Steering = rtb_Switch1_p2 > 0.0;

  /* Abs: '<S191>/Abs' incorporates:
   *  Sum: '<S191>/Subtract'
   *  UnitDelay: '<S191>/Unit Delay'
   */
  rtb_POSEexponentialmatrixfori_0 = fabs(Code_Gen_Model_B.Steering_Localized_Cmd
    - rtb_Optimized_Module_Angle);

  /* Switch: '<S191>/Switch5' incorporates:
   *  Constant: '<S191>/Constant1'
   *  Switch: '<S191>/Switch1'
   *  UnaryMinus: '<S191>/Unary Minus'
   */
  if (rtb_Is_Absolute_Translation) {
    /* SignalConversion generated from: '<S191>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S191>/Constant4'
     *  Constant: '<S191>/Constant6'
     */
    rtb_Product7[0] = Steering_Localized_Cmd_Approach_Zero_Final_Thresh;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S191>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S191>/Constant2'
     *  Constant: '<S191>/Constant5'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Localized_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S191>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S191>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic), &rtb_Product7[0],
                         rtb_POSEexponentialmatrixfori_0, &rtb_Minus_n[0], 1U);
    rtb_POSEexponentialmatrixfori_0 = rtb_LookupTableDynamic;
    rtb_Add_ec = -Steering_Localized_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S191>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S191>/Constant10'
     *  Constant: '<S191>/Constant8'
     */
    rtb_Product7[0] = Steering_Localized_Cmd_NonZero_Final_Scale_Factor;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S191>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S191>/Constant7'
     *  Constant: '<S191>/Constant9'
     */
    rtb_Minus_n[0] = 0.0;
    rtb_Minus_n[1] = Steering_Localized_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S191>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S191>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1), &rtb_Product7[0],
                         rtb_POSEexponentialmatrixfori_0, &rtb_Minus_n[0], 1U);
    rtb_POSEexponentialmatrixfori_0 = rtb_LookupTableDynamic1;

    /* Switch: '<S191>/Switch3' incorporates:
     *  Constant: '<S191>/Constant1'
     *  Constant: '<S191>/Constant3'
     *  UnaryMinus: '<S191>/Unary Minus'
     */
    if (rtb_Is_Absolute_Steering) {
      rtb_Add_ec = Steering_Localized_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Add_ec = -Steering_Localized_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S191>/Switch3' */
  }

  /* End of Switch: '<S191>/Switch5' */

  /* Product: '<S191>/Product' incorporates:
   *  Switch: '<S191>/Switch1'
   */
  rtb_Switch2 = rtb_Add_ec * rtb_POSEexponentialmatrixfori_0;

  /* Sum: '<S197>/Sum1' */
  rtb_Switch1_p2 -= rtb_Init_e;

  /* Switch: '<S198>/Switch2' incorporates:
   *  RelationalOperator: '<S198>/LowerRelop1'
   */
  if (!(rtb_Switch1_p2 > rtb_Switch2)) {
    /* Switch: '<S191>/Switch2' incorporates:
     *  Constant: '<S191>/Constant1'
     *  Constant: '<S191>/Constant3'
     *  Switch: '<S191>/Switch4'
     *  UnaryMinus: '<S191>/Unary Minus1'
     */
    if (rtb_Is_Absolute_Translation) {
      rtb_Add_ec = Steering_Localized_Cmd_Rate_Limit_Dec;
    } else if (rtb_Is_Absolute_Steering) {
      /* Switch: '<S191>/Switch4' incorporates:
       *  Constant: '<S191>/Constant1'
       */
      rtb_Add_ec = Steering_Localized_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Add_ec = -Steering_Localized_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S191>/Product2' incorporates:
     *  Switch: '<S191>/Switch2'
     */
    rtb_Switch2 = rtb_Add_ec * rtb_POSEexponentialmatrixfori_0;

    /* Switch: '<S198>/Switch' incorporates:
     *  RelationalOperator: '<S198>/UpperRelop'
     */
    if (!(rtb_Switch1_p2 < rtb_Switch2)) {
      rtb_Switch2 = rtb_Switch1_p2;
    }

    /* End of Switch: '<S198>/Switch' */
  }

  /* End of Switch: '<S198>/Switch2' */

  /* Sum: '<S197>/Sum' */
  Code_Gen_Model_B.Steering_Localized_Cmd = rtb_Switch2 + rtb_Init_e;

  /* Fcn: '<S214>/r->x' incorporates:
   *  Fcn: '<S219>/r->x'
   *  Fcn: '<S224>/r->x'
   *  Fcn: '<S229>/r->x'
   */
  rtb_Init_e = Code_Gen_Model_B.Translation_Speed_RL * cos
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S208>/Add' incorporates:
   *  Fcn: '<S214>/r->x'
   *  Fcn: '<S215>/r->x'
   */
  rtb_Product7[0] = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.FL_Tangent_Angle) + rtb_Init_e;

  /* Fcn: '<S214>/theta->y' incorporates:
   *  Fcn: '<S219>/theta->y'
   *  Fcn: '<S224>/theta->y'
   *  Fcn: '<S229>/theta->y'
   */
  rtb_Switch2_p = Code_Gen_Model_B.Translation_Speed_RL * sin
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S208>/Add' incorporates:
   *  Fcn: '<S214>/theta->y'
   *  Fcn: '<S215>/theta->y'
   */
  rtb_Product7[1] = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.FL_Tangent_Angle) + rtb_Switch2_p;

  /* Sum: '<S209>/Add' incorporates:
   *  Fcn: '<S220>/r->x'
   *  Fcn: '<S220>/theta->y'
   */
  rtb_Minus_n[0] = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.FR_Tangent_Angle) + rtb_Init_e;
  rtb_Minus_n[1] = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.FR_Tangent_Angle) + rtb_Switch2_p;

  /* Sum: '<S210>/Add' incorporates:
   *  Fcn: '<S225>/r->x'
   *  Fcn: '<S225>/theta->y'
   */
  rtb_Add2_f[0] = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.BL_Tangent_Angle) + rtb_Init_e;
  rtb_Add2_f[1] = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.BL_Tangent_Angle) + rtb_Switch2_p;

  /* Sum: '<S211>/Add' incorporates:
   *  Fcn: '<S230>/r->x'
   *  Fcn: '<S230>/theta->y'
   */
  rtb_POSEexponentialmatrixfori_0 = Code_Gen_Model_B.Steering_Localized_Cmd *
    cos(Code_Gen_Model_ConstB.BR_Tangent_Angle) + rtb_Init_e;
  rtb_Switch2 = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.BR_Tangent_Angle) + rtb_Switch2_p;

  /* Fcn: '<S228>/x->r' */
  rtb_Init_e = rt_hypotd_snf(rtb_POSEexponentialmatrixfori_0, rtb_Switch2);

  /* RelationalOperator: '<S231>/Compare' incorporates:
   *  Constant: '<S231>/Constant'
   */
  rtb_Is_Absolute_Translation = rtb_Init_e == 0.0;

  /* Switch: '<S227>/Switch1' */
  if (rtb_Is_Absolute_Translation) {
    /* Switch: '<S227>/Switch1' incorporates:
     *  Constant: '<S227>/Constant'
     */
    Code_Gen_Model_B.Switch1 = 1.0E-15;
  } else {
    /* Switch: '<S227>/Switch1' */
    Code_Gen_Model_B.Switch1 = rtb_Init_e;
  }

  /* End of Switch: '<S227>/Switch1' */

  /* Fcn: '<S213>/x->r' */
  rtb_Init_e = rt_hypotd_snf(rtb_Product7[0], rtb_Product7[1]);

  /* RelationalOperator: '<S216>/Compare' incorporates:
   *  Constant: '<S216>/Constant'
   */
  rtb_Is_Absolute_Steering = rtb_Init_e == 0.0;

  /* Switch: '<S212>/Switch1' */
  if (rtb_Is_Absolute_Steering) {
    /* Switch: '<S212>/Switch1' incorporates:
     *  Constant: '<S212>/Constant'
     */
    Code_Gen_Model_B.Switch1_m = 1.0E-15;
  } else {
    /* Switch: '<S212>/Switch1' */
    Code_Gen_Model_B.Switch1_m = rtb_Init_e;
  }

  /* End of Switch: '<S212>/Switch1' */

  /* Fcn: '<S218>/x->r' */
  rtb_Switch2_p = rt_hypotd_snf(rtb_Minus_n[0], rtb_Minus_n[1]);

  /* RelationalOperator: '<S221>/Compare' incorporates:
   *  Constant: '<S221>/Constant'
   */
  rtb_OR_ao = rtb_Switch2_p == 0.0;

  /* Switch: '<S217>/Switch1' */
  if (rtb_OR_ao) {
    /* Switch: '<S217>/Switch1' incorporates:
     *  Constant: '<S217>/Constant'
     */
    Code_Gen_Model_B.Switch1_o = 1.0E-15;
  } else {
    /* Switch: '<S217>/Switch1' */
    Code_Gen_Model_B.Switch1_o = rtb_Switch2_p;
  }

  /* End of Switch: '<S217>/Switch1' */

  /* Fcn: '<S223>/x->r' */
  rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_Add2_f[0], rtb_Add2_f[1]);

  /* RelationalOperator: '<S226>/Compare' incorporates:
   *  Constant: '<S226>/Constant'
   */
  rtb_Switch_b1 = rtb_Optimized_Module_Angle == 0.0;

  /* Switch: '<S222>/Switch1' */
  if (rtb_Switch_b1) {
    /* Switch: '<S222>/Switch1' incorporates:
     *  Constant: '<S222>/Constant'
     */
    Code_Gen_Model_B.Switch1_p = 1.0E-15;
  } else {
    /* Switch: '<S222>/Switch1' */
    Code_Gen_Model_B.Switch1_p = rtb_Optimized_Module_Angle;
  }

  /* End of Switch: '<S222>/Switch1' */

  /* Product: '<S207>/Divide' incorporates:
   *  Abs: '<S207>/Abs'
   *  Abs: '<S207>/Abs1'
   *  Abs: '<S207>/Abs2'
   *  Abs: '<S207>/Abs3'
   *  Constant: '<S207>/Constant'
   *  MinMax: '<S207>/Max'
   */
  rtb_Init_e = 3.5944420196850411 / fmax(fmax(fmax(fmax(3.5944420196850411,
    Code_Gen_Model_B.Switch1_m), Code_Gen_Model_B.Switch1_o),
    Code_Gen_Model_B.Switch1_p), Code_Gen_Model_B.Switch1);

  /* Product: '<S207>/Product3' */
  Code_Gen_Model_B.BR_Desired_Wheel_Speed = Code_Gen_Model_B.Switch1 *
    rtb_Init_e;

  /* Switch: '<S227>/Switch' */
  if (!rtb_Is_Absolute_Translation) {
    /* Switch: '<S227>/Switch' incorporates:
     *  Fcn: '<S228>/x->theta'
     */
    Code_Gen_Model_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Switch2,
      rtb_POSEexponentialmatrixfori_0);
  }

  /* End of Switch: '<S227>/Switch' */

  /* Trigonometry: '<S171>/Cos4' incorporates:
   *  Switch: '<S160>/Angle_Switch'
   *  Trigonometry: '<S170>/Cos4'
   */
  rtb_Add_kl = cos(Code_Gen_Model_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S171>/Sin5' incorporates:
   *  UnaryMinus: '<S169>/Unary Minus'
   */
  rtb_uDLookupTable_l = sin(-Code_Gen_Model_B.BR_Steer_Module_Angle);

  /* Trigonometry: '<S171>/Sin4' incorporates:
   *  Switch: '<S160>/Angle_Switch'
   *  Trigonometry: '<S170>/Sin4'
   */
  rtb_Subtract_gn = sin(Code_Gen_Model_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S171>/Cos5' incorporates:
   *  UnaryMinus: '<S169>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Code_Gen_Model_B.BR_Steer_Module_Angle);

  /* Sum: '<S171>/Subtract1' incorporates:
   *  Product: '<S171>/Product2'
   *  Product: '<S171>/Product3'
   *  Trigonometry: '<S171>/Cos4'
   *  Trigonometry: '<S171>/Sin4'
   */
  rtb_Switch2 = rtb_Add_kl * rtb_uDLookupTable_l + rtb_Subtract_gn *
    rtb_Optimized_Module_Angle;

  /* Sum: '<S171>/Subtract' incorporates:
   *  Product: '<S171>/Product'
   *  Product: '<S171>/Product1'
   *  Trigonometry: '<S171>/Cos4'
   *  Trigonometry: '<S171>/Sin4'
   */
  rtb_Switch1_p2 = rtb_Add_kl * rtb_Optimized_Module_Angle - rtb_Subtract_gn *
    rtb_uDLookupTable_l;

  /* Math: '<S171>/Hypot' */
  rtb_POSEexponentialmatrixfori_0 = rt_hypotd_snf(rtb_Switch1_p2, rtb_Switch2);

  /* Switch: '<S171>/Switch' incorporates:
   *  Constant: '<S171>/Constant'
   *  Constant: '<S171>/Constant1'
   *  Constant: '<S172>/Constant'
   *  Product: '<S171>/Divide'
   *  Product: '<S171>/Divide1'
   *  RelationalOperator: '<S172>/Compare'
   *  Switch: '<S171>/Switch1'
   */
  if (rtb_POSEexponentialmatrixfori_0 > 1.0E-6) {
    rtb_Switch2_p = rtb_Switch2 / rtb_POSEexponentialmatrixfori_0;
    rtb_Optimized_Module_Angle = rtb_Switch1_p2 /
      rtb_POSEexponentialmatrixfori_0;
  } else {
    rtb_Switch2_p = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S171>/Switch' */

  /* Switch: '<S160>/Speed_Switch' incorporates:
   *  Abs: '<S160>/Abs'
   *  Constant: '<S168>/Constant'
   *  RelationalOperator: '<S168>/Compare'
   *  Switch: '<S160>/Angle_Switch'
   *  Trigonometry: '<S170>/Atan1'
   *  Trigonometry: '<S171>/Atan1'
   *  UnaryMinus: '<S160>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_p, rtb_Optimized_Module_Angle)) >
      1.5707963267948966) {
    rtb_Add_ec = -Code_Gen_Model_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S170>/Subtract1' incorporates:
     *  Product: '<S170>/Product2'
     *  Product: '<S170>/Product3'
     *  UnaryMinus: '<S160>/Unary Minus'
     */
    rtb_Switch2 = rtb_Add_kl * Code_Gen_Model_ConstB.Sin5_c + rtb_Subtract_gn *
      Code_Gen_Model_ConstB.Cos5_b;

    /* Sum: '<S170>/Subtract' incorporates:
     *  Product: '<S170>/Product'
     *  Product: '<S170>/Product1'
     */
    rtb_POSEexponentialmatrixfori_0 = rtb_Add_kl * Code_Gen_Model_ConstB.Cos5_b
      - rtb_Subtract_gn * Code_Gen_Model_ConstB.Sin5_c;

    /* Math: '<S170>/Hypot' */
    rtb_Switch1_p2 = rt_hypotd_snf(rtb_POSEexponentialmatrixfori_0, rtb_Switch2);

    /* Switch: '<S170>/Switch1' incorporates:
     *  Constant: '<S170>/Constant'
     *  Constant: '<S170>/Constant1'
     *  Constant: '<S173>/Constant'
     *  Product: '<S170>/Divide'
     *  Product: '<S170>/Divide1'
     *  RelationalOperator: '<S173>/Compare'
     *  Switch: '<S170>/Switch'
     */
    if (rtb_Switch1_p2 > 1.0E-6) {
      rtb_POSEexponentialmatrixfori_0 /= rtb_Switch1_p2;
      rtb_Switch2 /= rtb_Switch1_p2;
    } else {
      rtb_POSEexponentialmatrixfori_0 = 1.0;
      rtb_Switch2 = 0.0;
    }

    /* End of Switch: '<S170>/Switch1' */
    rtb_uDLookupTable_l = rt_atan2d_snf(rtb_Switch2,
      rtb_POSEexponentialmatrixfori_0);
  } else {
    rtb_Add_ec = Code_Gen_Model_B.BR_Desired_Wheel_Speed;
    rtb_uDLookupTable_l = Code_Gen_Model_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S163>/Product2' incorporates:
   *  Constant: '<S163>/Constant'
   *  Switch: '<S160>/Speed_Switch'
   */
  rtb_Switch2_p = rtb_Add_ec * 1530.1401357649195;

  /* Signum: '<S158>/Sign' */
  if (rtIsNaN(rtb_Switch2_p)) {
    rtb_Add_ec = (rtNaN);
  } else if (rtb_Switch2_p < 0.0) {
    rtb_Add_ec = -1.0;
  } else {
    rtb_Add_ec = rtb_Switch2_p > 0.0;
  }

  /* Signum: '<S158>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.BackRight_Drive_Motor_Speed)) {
    rtb_Add_cz = (rtNaN);
  } else if (Code_Gen_Model_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_cz = -1.0;
  } else {
    rtb_Add_cz = Code_Gen_Model_U.BackRight_Drive_Motor_Speed > 0.0;
  }

  /* Sum: '<S161>/Add' incorporates:
   *  Sum: '<S162>/Sum'
   */
  rtb_uDLookupTable_l -= Code_Gen_Model_B.BR_Steer_Module_Angle;

  /* Product: '<S93>/Product' incorporates:
   *  Abs: '<S158>/Abs'
   *  Abs: '<S161>/Abs'
   *  Constant: '<S164>/Constant'
   *  Constant: '<S174>/Constant3'
   *  Constant: '<S174>/Constant4'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S158>/OR'
   *  Lookup_n-D: '<S161>/1-D Lookup Table'
   *  Math: '<S174>/Math Function'
   *  RelationalOperator: '<S158>/Equal1'
   *  RelationalOperator: '<S164>/Compare'
   *  Signum: '<S158>/Sign'
   *  Signum: '<S158>/Sign1'
   *  Sum: '<S161>/Add'
   *  Sum: '<S174>/Add1'
   *  Sum: '<S174>/Add2'
   */
  rtb_Switch2_p = (real_T)(rtb_Add_ec == rtb_Add_cz || fabs
    (Code_Gen_Model_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband) * rtb_Switch2_p * look1_binlcpw
    (fabs(rt_modd_snf(rtb_uDLookupTable_l + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     Code_Gen_Model_ConstP.pooled24, Code_Gen_Model_ConstP.pooled23, 1U);

  /* Gain: '<S159>/Gain' */
  rtb_POSEexponentialmatrixfori_0 = Drive_Motor_Control_FF * rtb_Switch2_p;

  /* Sum: '<S159>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Switch2_p -= Code_Gen_Model_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S166>/Sum1' incorporates:
   *  Constant: '<S159>/Constant2'
   *  Product: '<S166>/Product'
   *  Sum: '<S166>/Sum'
   *  UnitDelay: '<S166>/Unit Delay1'
   */
  rtb_Switch2 = (rtb_Switch2_p - Code_Gen_Model_DW.UnitDelay1_DSTATE_k) *
    Drive_Motor_Control_D_FilterCoeff + Code_Gen_Model_DW.UnitDelay1_DSTATE_k;

  /* Product: '<S159>/Product' incorporates:
   *  Constant: '<S159>/Constant3'
   */
  rtb_Switch1_p2 = rtb_Switch2 * Drive_Motor_Control_D;

  /* Sum: '<S165>/Diff' incorporates:
   *  UnitDelay: '<S165>/UD'
   *
   * Block description for '<S165>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S165>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Switch1_p2 - Code_Gen_Model_DW.UD_DSTATE_cs;

  /* Saturate: '<S159>/Saturation' */
  if (rtb_Add_ec > Drive_Motor_Control_D_UL) {
    rtb_Add_ec = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_ec < Drive_Motor_Control_D_LL) {
    rtb_Add_ec = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S159>/Add' incorporates:
   *  Gain: '<S159>/Gain1'
   *  Saturate: '<S159>/Saturation'
   */
  rtb_Magnitude = Drive_Motor_Control_P * rtb_Switch2_p +
    rtb_POSEexponentialmatrixfori_0 + rtb_Add_ec;

  /* Sum: '<S159>/Subtract' incorporates:
   *  Constant: '<S159>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Magnitude;

  /* Sum: '<S159>/Sum2' incorporates:
   *  Gain: '<S159>/Gain2'
   *  UnitDelay: '<S159>/Unit Delay'
   */
  rtb_POSEexponentialmatrixfori_0 = Drive_Motor_Control_I * rtb_Switch2_p +
    Code_Gen_Model_DW.UnitDelay_DSTATE_a;

  /* Switch: '<S167>/Switch2' incorporates:
   *  Constant: '<S159>/Constant'
   *  RelationalOperator: '<S167>/LowerRelop1'
   *  Sum: '<S159>/Subtract'
   */
  if (!(rtb_POSEexponentialmatrixfori_0 > 1.0 - rtb_Magnitude)) {
    /* Switch: '<S167>/Switch' incorporates:
     *  Constant: '<S159>/Constant1'
     *  RelationalOperator: '<S167>/UpperRelop'
     *  Sum: '<S159>/Subtract1'
     */
    if (rtb_POSEexponentialmatrixfori_0 < -1.0 - rtb_Magnitude) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_Magnitude;
    } else {
      rtb_Optimized_Module_Angle = rtb_POSEexponentialmatrixfori_0;
    }

    /* End of Switch: '<S167>/Switch' */
  }

  /* End of Switch: '<S167>/Switch2' */

  /* Saturate: '<S159>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Drive_Motor_Control_I_UL) {
    rtb_POSEexponentialmatrixfori_0 = Drive_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Drive_Motor_Control_I_LL) {
    rtb_POSEexponentialmatrixfori_0 = Drive_Motor_Control_I_LL;
  } else {
    rtb_POSEexponentialmatrixfori_0 = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S159>/Saturation1' */

  /* Sum: '<S159>/Add1' */
  rtb_Add_ec = rtb_Magnitude + rtb_POSEexponentialmatrixfori_0;

  /* Saturate: '<S159>/Saturation2' */
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

  /* End of Saturate: '<S159>/Saturation2' */

  /* Sum: '<S175>/Add1' incorporates:
   *  Constant: '<S175>/Constant3'
   *  Constant: '<S175>/Constant4'
   *  Math: '<S175>/Math Function'
   *  Sum: '<S175>/Add2'
   */
  rtb_Switch2_p = rt_modd_snf(rtb_uDLookupTable_l + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S177>/Sum1' incorporates:
   *  Constant: '<S162>/Constant2'
   *  Product: '<S177>/Product'
   *  Sum: '<S177>/Sum'
   *  UnitDelay: '<S177>/Unit Delay1'
   */
  rtb_Magnitude = (rtb_Switch2_p - Code_Gen_Model_DW.UnitDelay1_DSTATE_i) *
    Steering_Motor_Control_D_FilterCoeff + Code_Gen_Model_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S162>/Product' incorporates:
   *  Constant: '<S162>/Constant3'
   */
  rtb_Steer_Joystick_X_Rel_Mod = rtb_Magnitude * Steering_Motor_Control_D;

  /* Sum: '<S176>/Diff' incorporates:
   *  UnitDelay: '<S176>/UD'
   *
   * Block description for '<S176>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S176>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Steer_Joystick_X_Rel_Mod - Code_Gen_Model_DW.UD_DSTATE_l;

  /* Saturate: '<S162>/Saturation' */
  if (rtb_Add_ec > Steering_Motor_Control_D_UL) {
    rtb_Add_ec = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_ec < Steering_Motor_Control_D_LL) {
    rtb_Add_ec = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S162>/Add' incorporates:
   *  Gain: '<S162>/Gain1'
   *  Saturate: '<S162>/Saturation'
   */
  rtb_Add_pw = Steering_Motor_Control_P * rtb_Switch2_p + rtb_Add_ec;

  /* Sum: '<S162>/Subtract' incorporates:
   *  Constant: '<S162>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Add_pw;

  /* Sum: '<S162>/Sum2' incorporates:
   *  Gain: '<S162>/Gain2'
   *  UnitDelay: '<S162>/Unit Delay'
   */
  rtb_Sum2_fc = Steering_Motor_Control_I * rtb_Switch2_p +
    Code_Gen_Model_DW.UnitDelay_DSTATE_l;

  /* Switch: '<S178>/Switch2' incorporates:
   *  Constant: '<S162>/Constant'
   *  RelationalOperator: '<S178>/LowerRelop1'
   *  Sum: '<S162>/Subtract'
   */
  if (!(rtb_Sum2_fc > 1.0 - rtb_Add_pw)) {
    /* Switch: '<S178>/Switch' incorporates:
     *  Constant: '<S162>/Constant1'
     *  RelationalOperator: '<S178>/UpperRelop'
     *  Sum: '<S162>/Subtract1'
     */
    if (rtb_Sum2_fc < -1.0 - rtb_Add_pw) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_Add_pw;
    } else {
      rtb_Optimized_Module_Angle = rtb_Sum2_fc;
    }

    /* End of Switch: '<S178>/Switch' */
  }

  /* End of Switch: '<S178>/Switch2' */

  /* Saturate: '<S162>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_fc = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S162>/Saturation1' */

  /* Sum: '<S162>/Add1' */
  rtb_Add_ec = rtb_Add_pw + rtb_Sum2_fc;

  /* Saturate: '<S162>/Saturation2' */
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

  /* End of Saturate: '<S162>/Saturation2' */

  /* Product: '<S207>/Product' */
  Code_Gen_Model_B.FL_Desired_Wheel_Speed = Code_Gen_Model_B.Switch1_m *
    rtb_Init_e;

  /* Switch: '<S212>/Switch' */
  if (!rtb_Is_Absolute_Steering) {
    /* Switch: '<S212>/Switch' incorporates:
     *  Fcn: '<S213>/x->theta'
     */
    Code_Gen_Model_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Product7[1],
      rtb_Product7[0]);
  }

  /* End of Switch: '<S212>/Switch' */

  /* Trigonometry: '<S108>/Cos4' incorporates:
   *  Switch: '<S97>/Angle_Switch'
   *  Trigonometry: '<S107>/Cos4'
   */
  rtb_Add_kl = cos(Code_Gen_Model_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S108>/Sin5' incorporates:
   *  UnaryMinus: '<S106>/Unary Minus'
   */
  rtb_uDLookupTable_l = sin(-Code_Gen_Model_B.FL_Steer_Module_Angle);

  /* Trigonometry: '<S108>/Sin4' incorporates:
   *  Switch: '<S97>/Angle_Switch'
   *  Trigonometry: '<S107>/Sin4'
   */
  rtb_Subtract_gn = sin(Code_Gen_Model_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S108>/Cos5' incorporates:
   *  UnaryMinus: '<S106>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Code_Gen_Model_B.FL_Steer_Module_Angle);

  /* Sum: '<S108>/Subtract1' incorporates:
   *  Product: '<S108>/Product2'
   *  Product: '<S108>/Product3'
   *  Trigonometry: '<S108>/Cos4'
   *  Trigonometry: '<S108>/Sin4'
   */
  rtb_Switch2_p = rtb_Add_kl * rtb_uDLookupTable_l + rtb_Subtract_gn *
    rtb_Optimized_Module_Angle;

  /* Sum: '<S108>/Subtract' incorporates:
   *  Product: '<S108>/Product'
   *  Product: '<S108>/Product1'
   *  Trigonometry: '<S108>/Cos4'
   *  Trigonometry: '<S108>/Sin4'
   */
  rtb_Add_pw = rtb_Add_kl * rtb_Optimized_Module_Angle - rtb_Subtract_gn *
    rtb_uDLookupTable_l;

  /* Math: '<S108>/Hypot' */
  rtb_Hypot_g5 = rt_hypotd_snf(rtb_Add_pw, rtb_Switch2_p);

  /* Switch: '<S108>/Switch' incorporates:
   *  Constant: '<S108>/Constant'
   *  Constant: '<S108>/Constant1'
   *  Constant: '<S109>/Constant'
   *  Product: '<S108>/Divide'
   *  Product: '<S108>/Divide1'
   *  RelationalOperator: '<S109>/Compare'
   *  Switch: '<S108>/Switch1'
   */
  if (rtb_Hypot_g5 > 1.0E-6) {
    rtb_Switch2_p /= rtb_Hypot_g5;
    rtb_Optimized_Module_Angle = rtb_Add_pw / rtb_Hypot_g5;
  } else {
    rtb_Switch2_p = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S108>/Switch' */

  /* Switch: '<S97>/Speed_Switch' incorporates:
   *  Abs: '<S97>/Abs'
   *  Constant: '<S105>/Constant'
   *  RelationalOperator: '<S105>/Compare'
   *  Switch: '<S97>/Angle_Switch'
   *  Trigonometry: '<S107>/Atan1'
   *  Trigonometry: '<S108>/Atan1'
   *  UnaryMinus: '<S97>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_p, rtb_Optimized_Module_Angle)) >
      1.5707963267948966) {
    rtb_Add_ec = -Code_Gen_Model_B.FL_Desired_Wheel_Speed;

    /* Sum: '<S107>/Subtract1' incorporates:
     *  Product: '<S107>/Product2'
     *  Product: '<S107>/Product3'
     *  UnaryMinus: '<S97>/Unary Minus'
     */
    rtb_Add_pw = rtb_Add_kl * Code_Gen_Model_ConstB.Sin5 + rtb_Subtract_gn *
      Code_Gen_Model_ConstB.Cos5;

    /* Sum: '<S107>/Subtract' incorporates:
     *  Product: '<S107>/Product'
     *  Product: '<S107>/Product1'
     */
    rtb_Subtract_i = rtb_Add_kl * Code_Gen_Model_ConstB.Cos5 - rtb_Subtract_gn *
      Code_Gen_Model_ConstB.Sin5;

    /* Math: '<S107>/Hypot' */
    rtb_Hypot_g5 = rt_hypotd_snf(rtb_Subtract_i, rtb_Add_pw);

    /* Switch: '<S107>/Switch1' incorporates:
     *  Constant: '<S107>/Constant'
     *  Constant: '<S107>/Constant1'
     *  Constant: '<S110>/Constant'
     *  Product: '<S107>/Divide'
     *  Product: '<S107>/Divide1'
     *  RelationalOperator: '<S110>/Compare'
     *  Switch: '<S107>/Switch'
     */
    if (rtb_Hypot_g5 > 1.0E-6) {
      rtb_Subtract_i /= rtb_Hypot_g5;
      rtb_Add_pw /= rtb_Hypot_g5;
    } else {
      rtb_Subtract_i = 1.0;
      rtb_Add_pw = 0.0;
    }

    /* End of Switch: '<S107>/Switch1' */
    rtb_uDLookupTable_l = rt_atan2d_snf(rtb_Add_pw, rtb_Subtract_i);
  } else {
    rtb_Add_ec = Code_Gen_Model_B.FL_Desired_Wheel_Speed;
    rtb_uDLookupTable_l = Code_Gen_Model_B.FL_Desired_Module_Angle;
  }

  /* Product: '<S100>/Product2' incorporates:
   *  Constant: '<S100>/Constant'
   *  Switch: '<S97>/Speed_Switch'
   */
  rtb_Switch2_p = rtb_Add_ec * 1530.1401357649195;

  /* Signum: '<S95>/Sign' */
  if (rtIsNaN(rtb_Switch2_p)) {
    rtb_Add_ec = (rtNaN);
  } else if (rtb_Switch2_p < 0.0) {
    rtb_Add_ec = -1.0;
  } else {
    rtb_Add_ec = rtb_Switch2_p > 0.0;
  }

  /* Signum: '<S95>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Add_cz = (rtNaN);
  } else if (Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_cz = -1.0;
  } else {
    rtb_Add_cz = Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed > 0.0;
  }

  /* Sum: '<S98>/Add' incorporates:
   *  Sum: '<S99>/Sum'
   */
  rtb_uDLookupTable_l -= Code_Gen_Model_B.FL_Steer_Module_Angle;

  /* Product: '<S90>/Product' incorporates:
   *  Abs: '<S95>/Abs'
   *  Abs: '<S98>/Abs'
   *  Constant: '<S101>/Constant'
   *  Constant: '<S111>/Constant3'
   *  Constant: '<S111>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S95>/OR'
   *  Lookup_n-D: '<S98>/1-D Lookup Table'
   *  Math: '<S111>/Math Function'
   *  RelationalOperator: '<S101>/Compare'
   *  RelationalOperator: '<S95>/Equal1'
   *  Signum: '<S95>/Sign'
   *  Signum: '<S95>/Sign1'
   *  Sum: '<S111>/Add1'
   *  Sum: '<S111>/Add2'
   *  Sum: '<S98>/Add'
   */
  rtb_Switch2_p = (real_T)(rtb_Add_ec == rtb_Add_cz || fabs
    (Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband) * rtb_Switch2_p * look1_binlcpw
    (fabs(rt_modd_snf(rtb_uDLookupTable_l + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     Code_Gen_Model_ConstP.pooled24, Code_Gen_Model_ConstP.pooled23, 1U);

  /* Gain: '<S96>/Gain' */
  rtb_Subtract_i = Drive_Motor_Control_FF * rtb_Switch2_p;

  /* Sum: '<S96>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Switch2_p -= Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S103>/Sum1' incorporates:
   *  Constant: '<S96>/Constant2'
   *  Product: '<S103>/Product'
   *  Sum: '<S103>/Sum'
   *  UnitDelay: '<S103>/Unit Delay1'
   */
  rtb_Add_pw = (rtb_Switch2_p - Code_Gen_Model_DW.UnitDelay1_DSTATE_a) *
    Drive_Motor_Control_D_FilterCoeff + Code_Gen_Model_DW.UnitDelay1_DSTATE_a;

  /* Product: '<S96>/Product' incorporates:
   *  Constant: '<S96>/Constant3'
   */
  rtb_Hypot_g5 = rtb_Add_pw * Drive_Motor_Control_D;

  /* Sum: '<S102>/Diff' incorporates:
   *  UnitDelay: '<S102>/UD'
   *
   * Block description for '<S102>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S102>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Hypot_g5 - Code_Gen_Model_DW.UD_DSTATE_o;

  /* Saturate: '<S96>/Saturation' */
  if (rtb_Add_ec > Drive_Motor_Control_D_UL) {
    rtb_Add_ec = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_ec < Drive_Motor_Control_D_LL) {
    rtb_Add_ec = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S96>/Add' incorporates:
   *  Gain: '<S96>/Gain1'
   *  Saturate: '<S96>/Saturation'
   */
  rtb_Add_c4 = Drive_Motor_Control_P * rtb_Switch2_p + rtb_Subtract_i +
    rtb_Add_ec;

  /* Sum: '<S96>/Subtract' incorporates:
   *  Constant: '<S96>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Add_c4;

  /* Sum: '<S96>/Sum2' incorporates:
   *  Gain: '<S96>/Gain2'
   *  UnitDelay: '<S96>/Unit Delay'
   */
  rtb_Switch2_p = Drive_Motor_Control_I * rtb_Switch2_p +
    Code_Gen_Model_DW.UnitDelay_DSTATE_f;

  /* Switch: '<S104>/Switch2' incorporates:
   *  Constant: '<S96>/Constant'
   *  RelationalOperator: '<S104>/LowerRelop1'
   *  Sum: '<S96>/Subtract'
   */
  if (!(rtb_Switch2_p > 1.0 - rtb_Add_c4)) {
    /* Switch: '<S104>/Switch' incorporates:
     *  Constant: '<S96>/Constant1'
     *  RelationalOperator: '<S104>/UpperRelop'
     *  Sum: '<S96>/Subtract1'
     */
    if (rtb_Switch2_p < -1.0 - rtb_Add_c4) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_Add_c4;
    } else {
      rtb_Optimized_Module_Angle = rtb_Switch2_p;
    }

    /* End of Switch: '<S104>/Switch' */
  }

  /* End of Switch: '<S104>/Switch2' */

  /* Saturate: '<S96>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Drive_Motor_Control_I_UL) {
    rtb_Subtract_i = Drive_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Drive_Motor_Control_I_LL) {
    rtb_Subtract_i = Drive_Motor_Control_I_LL;
  } else {
    rtb_Subtract_i = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S96>/Saturation1' */

  /* Sum: '<S96>/Add1' */
  rtb_Add_ec = rtb_Add_c4 + rtb_Subtract_i;

  /* Saturate: '<S96>/Saturation2' */
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

  /* End of Saturate: '<S96>/Saturation2' */

  /* Sum: '<S112>/Add1' incorporates:
   *  Constant: '<S112>/Constant3'
   *  Constant: '<S112>/Constant4'
   *  Math: '<S112>/Math Function'
   *  Sum: '<S112>/Add2'
   */
  rtb_Switch2_p = rt_modd_snf(rtb_uDLookupTable_l + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S114>/Sum1' incorporates:
   *  Constant: '<S99>/Constant2'
   *  Product: '<S114>/Product'
   *  Sum: '<S114>/Sum'
   *  UnitDelay: '<S114>/Unit Delay1'
   */
  rtb_Add_c4 = (rtb_Switch2_p - Code_Gen_Model_DW.UnitDelay1_DSTATE_b) *
    Steering_Motor_Control_D_FilterCoeff + Code_Gen_Model_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S99>/Product' incorporates:
   *  Constant: '<S99>/Constant3'
   */
  rtb_Product_dq = rtb_Add_c4 * Steering_Motor_Control_D;

  /* Sum: '<S113>/Diff' incorporates:
   *  UnitDelay: '<S113>/UD'
   *
   * Block description for '<S113>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S113>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Product_dq - Code_Gen_Model_DW.UD_DSTATE_b;

  /* Saturate: '<S99>/Saturation' */
  if (rtb_Add_ec > Steering_Motor_Control_D_UL) {
    rtb_Add_ec = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_ec < Steering_Motor_Control_D_LL) {
    rtb_Add_ec = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S99>/Add' incorporates:
   *  Gain: '<S99>/Gain1'
   *  Saturate: '<S99>/Saturation'
   */
  rtb_Add_kl = Steering_Motor_Control_P * rtb_Switch2_p + rtb_Add_ec;

  /* Sum: '<S99>/Subtract' incorporates:
   *  Constant: '<S99>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Add_kl;

  /* Sum: '<S99>/Sum2' incorporates:
   *  Gain: '<S99>/Gain2'
   *  UnitDelay: '<S99>/Unit Delay'
   */
  rtb_Switch2_p = Steering_Motor_Control_I * rtb_Switch2_p +
    Code_Gen_Model_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S115>/Switch2' incorporates:
   *  Constant: '<S99>/Constant'
   *  RelationalOperator: '<S115>/LowerRelop1'
   *  Sum: '<S99>/Subtract'
   */
  if (!(rtb_Switch2_p > 1.0 - rtb_Add_kl)) {
    /* Switch: '<S115>/Switch' incorporates:
     *  Constant: '<S99>/Constant1'
     *  RelationalOperator: '<S115>/UpperRelop'
     *  Sum: '<S99>/Subtract1'
     */
    if (rtb_Switch2_p < -1.0 - rtb_Add_kl) {
      rtb_Optimized_Module_Angle = -1.0 - rtb_Add_kl;
    } else {
      rtb_Optimized_Module_Angle = rtb_Switch2_p;
    }

    /* End of Switch: '<S115>/Switch' */
  }

  /* End of Switch: '<S115>/Switch2' */

  /* Saturate: '<S99>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_la = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_la = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_la = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S99>/Saturation1' */

  /* Sum: '<S99>/Add1' */
  rtb_Add_ec = rtb_Add_kl + rtb_Subtract1_la;

  /* Saturate: '<S99>/Saturation2' */
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

  /* End of Saturate: '<S99>/Saturation2' */

  /* Product: '<S207>/Product1' */
  Code_Gen_Model_B.FR_Desired_Wheel_Speed = Code_Gen_Model_B.Switch1_o *
    rtb_Init_e;

  /* Switch: '<S217>/Switch' */
  if (!rtb_OR_ao) {
    /* Switch: '<S217>/Switch' incorporates:
     *  Fcn: '<S218>/x->theta'
     */
    Code_Gen_Model_B.FR_Desired_Module_Angle = rt_atan2d_snf(rtb_Minus_n[1],
      rtb_Minus_n[0]);
  }

  /* End of Switch: '<S217>/Switch' */

  /* Trigonometry: '<S129>/Cos4' incorporates:
   *  Switch: '<S118>/Angle_Switch'
   *  Trigonometry: '<S128>/Cos4'
   */
  rtb_Add_kl = cos(Code_Gen_Model_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S129>/Sin5' incorporates:
   *  UnaryMinus: '<S127>/Unary Minus'
   */
  rtb_uDLookupTable_l = sin(-Code_Gen_Model_B.FR_Steer_Module_Angle);

  /* Trigonometry: '<S129>/Sin4' incorporates:
   *  Switch: '<S118>/Angle_Switch'
   *  Trigonometry: '<S128>/Sin4'
   */
  rtb_Subtract_gn = sin(Code_Gen_Model_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S129>/Cos5' incorporates:
   *  UnaryMinus: '<S127>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = cos(-Code_Gen_Model_B.FR_Steer_Module_Angle);

  /* Sum: '<S129>/Subtract1' incorporates:
   *  Product: '<S129>/Product2'
   *  Product: '<S129>/Product3'
   *  Trigonometry: '<S129>/Cos4'
   *  Trigonometry: '<S129>/Sin4'
   */
  rtb_Switch2_p = rtb_Add_kl * rtb_uDLookupTable_l + rtb_Subtract_gn *
    rtb_Optimized_Module_Angle;

  /* Sum: '<S129>/Subtract' incorporates:
   *  Product: '<S129>/Product'
   *  Product: '<S129>/Product1'
   *  Trigonometry: '<S129>/Cos4'
   *  Trigonometry: '<S129>/Sin4'
   */
  rtb_Optimized_Module_Angle = rtb_Add_kl * rtb_Optimized_Module_Angle -
    rtb_Subtract_gn * rtb_uDLookupTable_l;

  /* Math: '<S129>/Hypot' */
  rtb_Hypot_b = rt_hypotd_snf(rtb_Optimized_Module_Angle, rtb_Switch2_p);

  /* Switch: '<S129>/Switch' incorporates:
   *  Constant: '<S129>/Constant'
   *  Constant: '<S129>/Constant1'
   *  Constant: '<S130>/Constant'
   *  Product: '<S129>/Divide'
   *  Product: '<S129>/Divide1'
   *  RelationalOperator: '<S130>/Compare'
   *  Switch: '<S129>/Switch1'
   */
  if (rtb_Hypot_b > 1.0E-6) {
    rtb_Switch2_p /= rtb_Hypot_b;
    rtb_Optimized_Module_Angle /= rtb_Hypot_b;
  } else {
    rtb_Switch2_p = 0.0;
    rtb_Optimized_Module_Angle = 1.0;
  }

  /* End of Switch: '<S129>/Switch' */

  /* Switch: '<S118>/Speed_Switch' incorporates:
   *  Abs: '<S118>/Abs'
   *  Constant: '<S126>/Constant'
   *  RelationalOperator: '<S126>/Compare'
   *  Switch: '<S118>/Angle_Switch'
   *  Trigonometry: '<S128>/Atan1'
   *  Trigonometry: '<S129>/Atan1'
   *  UnaryMinus: '<S118>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Switch2_p, rtb_Optimized_Module_Angle)) >
      1.5707963267948966) {
    rtb_Add_ec = -Code_Gen_Model_B.FR_Desired_Wheel_Speed;

    /* Sum: '<S128>/Subtract1' incorporates:
     *  Product: '<S128>/Product2'
     *  Product: '<S128>/Product3'
     *  UnaryMinus: '<S118>/Unary Minus'
     */
    rtb_Optimized_Module_Angle = rtb_Add_kl * Code_Gen_Model_ConstB.Sin5_m +
      rtb_Subtract_gn * Code_Gen_Model_ConstB.Cos5_g;

    /* Sum: '<S128>/Subtract' incorporates:
     *  Product: '<S128>/Product'
     *  Product: '<S128>/Product1'
     */
    rtb_Subtract_gn = rtb_Add_kl * Code_Gen_Model_ConstB.Cos5_g -
      rtb_Subtract_gn * Code_Gen_Model_ConstB.Sin5_m;

    /* Math: '<S128>/Hypot' */
    rtb_Add_kl = rt_hypotd_snf(rtb_Subtract_gn, rtb_Optimized_Module_Angle);

    /* Switch: '<S128>/Switch1' incorporates:
     *  Constant: '<S128>/Constant'
     *  Constant: '<S128>/Constant1'
     *  Constant: '<S131>/Constant'
     *  Product: '<S128>/Divide'
     *  Product: '<S128>/Divide1'
     *  RelationalOperator: '<S131>/Compare'
     *  Switch: '<S128>/Switch'
     */
    if (rtb_Add_kl > 1.0E-6) {
      rtb_Subtract_gn /= rtb_Add_kl;
      rtb_Optimized_Module_Angle /= rtb_Add_kl;
    } else {
      rtb_Subtract_gn = 1.0;
      rtb_Optimized_Module_Angle = 0.0;
    }

    /* End of Switch: '<S128>/Switch1' */
    rtb_uDLookupTable_l = rt_atan2d_snf(rtb_Optimized_Module_Angle,
      rtb_Subtract_gn);
  } else {
    rtb_Add_ec = Code_Gen_Model_B.FR_Desired_Wheel_Speed;
    rtb_uDLookupTable_l = Code_Gen_Model_B.FR_Desired_Module_Angle;
  }

  /* Product: '<S121>/Product2' incorporates:
   *  Constant: '<S121>/Constant'
   *  Switch: '<S118>/Speed_Switch'
   */
  rtb_Switch2_p = rtb_Add_ec * 1530.1401357649195;

  /* Signum: '<S116>/Sign' */
  if (rtIsNaN(rtb_Switch2_p)) {
    rtb_Add_ec = (rtNaN);
  } else if (rtb_Switch2_p < 0.0) {
    rtb_Add_ec = -1.0;
  } else {
    rtb_Add_ec = rtb_Switch2_p > 0.0;
  }

  /* Signum: '<S116>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Add_cz = (rtNaN);
  } else if (Code_Gen_Model_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Add_cz = -1.0;
  } else {
    rtb_Add_cz = Code_Gen_Model_U.FrontRight_Drive_Motor_Speed > 0.0;
  }

  /* Sum: '<S119>/Add' incorporates:
   *  Sum: '<S120>/Sum'
   */
  rtb_uDLookupTable_l -= Code_Gen_Model_B.FR_Steer_Module_Angle;

  /* Product: '<S91>/Product' incorporates:
   *  Abs: '<S116>/Abs'
   *  Abs: '<S119>/Abs'
   *  Constant: '<S122>/Constant'
   *  Constant: '<S132>/Constant3'
   *  Constant: '<S132>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S116>/OR'
   *  Lookup_n-D: '<S119>/1-D Lookup Table'
   *  Math: '<S132>/Math Function'
   *  RelationalOperator: '<S116>/Equal1'
   *  RelationalOperator: '<S122>/Compare'
   *  Signum: '<S116>/Sign'
   *  Signum: '<S116>/Sign1'
   *  Sum: '<S119>/Add'
   *  Sum: '<S132>/Add1'
   *  Sum: '<S132>/Add2'
   */
  rtb_Switch2_p = (real_T)(rtb_Add_ec == rtb_Add_cz || fabs
    (Code_Gen_Model_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband) * rtb_Switch2_p * look1_binlcpw
    (fabs(rt_modd_snf(rtb_uDLookupTable_l + 1.5707963267948966,
                      3.1415926535897931) - 1.5707963267948966),
     Code_Gen_Model_ConstP.pooled24, Code_Gen_Model_ConstP.pooled23, 1U);

  /* Gain: '<S117>/Gain' */
  rtb_Optimized_Module_Angle = Drive_Motor_Control_FF * rtb_Switch2_p;

  /* Sum: '<S117>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Switch2_p -= Code_Gen_Model_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S124>/Sum1' incorporates:
   *  Constant: '<S117>/Constant2'
   *  Product: '<S124>/Product'
   *  Sum: '<S124>/Sum'
   *  UnitDelay: '<S124>/Unit Delay1'
   */
  rtb_Add_kl = (rtb_Switch2_p - Code_Gen_Model_DW.UnitDelay1_DSTATE_b1) *
    Drive_Motor_Control_D_FilterCoeff + Code_Gen_Model_DW.UnitDelay1_DSTATE_b1;

  /* Product: '<S117>/Product' incorporates:
   *  Constant: '<S117>/Constant3'
   */
  rtb_Subtract_gn = rtb_Add_kl * Drive_Motor_Control_D;

  /* Sum: '<S123>/Diff' incorporates:
   *  UnitDelay: '<S123>/UD'
   *
   * Block description for '<S123>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S123>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Subtract_gn - Code_Gen_Model_DW.UD_DSTATE_e;

  /* Saturate: '<S117>/Saturation' */
  if (rtb_Add_ec > Drive_Motor_Control_D_UL) {
    rtb_Add_ec = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_ec < Drive_Motor_Control_D_LL) {
    rtb_Add_ec = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S117>/Add' incorporates:
   *  Gain: '<S117>/Gain1'
   *  Saturate: '<S117>/Saturation'
   */
  rtb_Add_c = Drive_Motor_Control_P * rtb_Switch2_p + rtb_Optimized_Module_Angle
    + rtb_Add_ec;

  /* Sum: '<S117>/Subtract' incorporates:
   *  Constant: '<S117>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Add_c;

  /* Sum: '<S117>/Sum2' incorporates:
   *  Gain: '<S117>/Gain2'
   *  UnitDelay: '<S117>/Unit Delay'
   */
  rtb_Switch2_p = Drive_Motor_Control_I * rtb_Switch2_p +
    Code_Gen_Model_DW.UnitDelay_DSTATE_em;

  /* Switch: '<S125>/Switch2' incorporates:
   *  Constant: '<S117>/Constant'
   *  RelationalOperator: '<S125>/LowerRelop1'
   *  Sum: '<S117>/Subtract'
   */
  if (!(rtb_Switch2_p > 1.0 - rtb_Add_c)) {
    /* Sum: '<S117>/Subtract1' incorporates:
     *  Constant: '<S117>/Constant1'
     */
    rtb_Optimized_Module_Angle = -1.0 - rtb_Add_c;

    /* Switch: '<S125>/Switch' incorporates:
     *  Constant: '<S117>/Constant1'
     *  RelationalOperator: '<S125>/UpperRelop'
     *  Sum: '<S117>/Subtract1'
     */
    if (!(rtb_Switch2_p < -1.0 - rtb_Add_c)) {
      rtb_Optimized_Module_Angle = rtb_Switch2_p;
    }

    /* End of Switch: '<S125>/Switch' */
  }

  /* End of Switch: '<S125>/Switch2' */

  /* Saturate: '<S117>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Drive_Motor_Control_I_UL) {
    rtb_Hypot_b = Drive_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Drive_Motor_Control_I_LL) {
    rtb_Hypot_b = Drive_Motor_Control_I_LL;
  } else {
    rtb_Hypot_b = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S117>/Saturation1' */

  /* Sum: '<S117>/Add1' */
  rtb_Add_ec = rtb_Add_c + rtb_Hypot_b;

  /* Saturate: '<S117>/Saturation2' */
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

  /* End of Saturate: '<S117>/Saturation2' */

  /* Sum: '<S133>/Add1' incorporates:
   *  Constant: '<S133>/Constant3'
   *  Constant: '<S133>/Constant4'
   *  Math: '<S133>/Math Function'
   *  Sum: '<S133>/Add2'
   */
  rtb_Switch2_p = rt_modd_snf(rtb_uDLookupTable_l + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S135>/Sum1' incorporates:
   *  Constant: '<S120>/Constant2'
   *  Product: '<S135>/Product'
   *  Sum: '<S135>/Sum'
   *  UnitDelay: '<S135>/Unit Delay1'
   */
  rtb_uDLookupTable_l = (rtb_Switch2_p - Code_Gen_Model_DW.UnitDelay1_DSTATE_n) *
    Steering_Motor_Control_D_FilterCoeff + Code_Gen_Model_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S120>/Product' incorporates:
   *  Constant: '<S120>/Constant3'
   */
  rtb_Add_c = rtb_uDLookupTable_l * Steering_Motor_Control_D;

  /* Sum: '<S134>/Diff' incorporates:
   *  UnitDelay: '<S134>/UD'
   *
   * Block description for '<S134>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S134>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Add_c - Code_Gen_Model_DW.UD_DSTATE_i1;

  /* Saturate: '<S120>/Saturation' */
  if (rtb_Add_ec > Steering_Motor_Control_D_UL) {
    rtb_Add_ec = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_ec < Steering_Motor_Control_D_LL) {
    rtb_Add_ec = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S120>/Add' incorporates:
   *  Gain: '<S120>/Gain1'
   *  Saturate: '<S120>/Saturation'
   */
  rtb_Add_cz = Steering_Motor_Control_P * rtb_Switch2_p + rtb_Add_ec;

  /* Sum: '<S120>/Subtract' incorporates:
   *  Constant: '<S120>/Constant'
   */
  rtb_Optimized_Module_Angle = 1.0 - rtb_Add_cz;

  /* Sum: '<S120>/Sum2' incorporates:
   *  Gain: '<S120>/Gain2'
   *  UnitDelay: '<S120>/Unit Delay'
   */
  rtb_Switch2_p = Steering_Motor_Control_I * rtb_Switch2_p +
    Code_Gen_Model_DW.UnitDelay_DSTATE_dt;

  /* Switch: '<S136>/Switch2' incorporates:
   *  Constant: '<S120>/Constant'
   *  RelationalOperator: '<S136>/LowerRelop1'
   *  Sum: '<S120>/Subtract'
   */
  if (!(rtb_Switch2_p > 1.0 - rtb_Add_cz)) {
    /* Sum: '<S120>/Subtract1' incorporates:
     *  Constant: '<S120>/Constant1'
     */
    rtb_Optimized_Module_Angle = -1.0 - rtb_Add_cz;

    /* Switch: '<S136>/Switch' incorporates:
     *  Constant: '<S120>/Constant1'
     *  RelationalOperator: '<S136>/UpperRelop'
     *  Sum: '<S120>/Subtract1'
     */
    if (!(rtb_Switch2_p < -1.0 - rtb_Add_cz)) {
      rtb_Optimized_Module_Angle = rtb_Switch2_p;
    }

    /* End of Switch: '<S136>/Switch' */
  }

  /* End of Switch: '<S136>/Switch2' */

  /* Saturate: '<S120>/Saturation1' */
  if (rtb_Optimized_Module_Angle > Steering_Motor_Control_I_UL) {
    rtb_Integral_kz = Steering_Motor_Control_I_UL;
  } else if (rtb_Optimized_Module_Angle < Steering_Motor_Control_I_LL) {
    rtb_Integral_kz = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_kz = rtb_Optimized_Module_Angle;
  }

  /* End of Saturate: '<S120>/Saturation1' */

  /* Sum: '<S120>/Add1' */
  rtb_Add_ec = rtb_Add_cz + rtb_Integral_kz;

  /* Saturate: '<S120>/Saturation2' */
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

  /* End of Saturate: '<S120>/Saturation2' */

  /* Product: '<S207>/Product2' */
  Code_Gen_Model_B.BL_Desired_Wheel_Speed = Code_Gen_Model_B.Switch1_p *
    rtb_Init_e;

  /* Switch: '<S222>/Switch' */
  if (!rtb_Switch_b1) {
    /* Switch: '<S222>/Switch' incorporates:
     *  Fcn: '<S223>/x->theta'
     */
    Code_Gen_Model_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add2_f[1],
      rtb_Add2_f[0]);
  }

  /* End of Switch: '<S222>/Switch' */

  /* Trigonometry: '<S150>/Cos4' incorporates:
   *  Switch: '<S139>/Angle_Switch'
   *  Trigonometry: '<S149>/Cos4'
   */
  rtb_Add_cz = cos(Code_Gen_Model_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S150>/Sin5' incorporates:
   *  UnaryMinus: '<S148>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Code_Gen_Model_B.BL_Steer_Module_Angle);

  /* Trigonometry: '<S150>/Sin4' incorporates:
   *  Switch: '<S139>/Angle_Switch'
   *  Trigonometry: '<S149>/Sin4'
   */
  rtb_Product_do = sin(Code_Gen_Model_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S150>/Cos5' incorporates:
   *  UnaryMinus: '<S148>/Unary Minus'
   */
  rtb_Switch2_p = cos(-Code_Gen_Model_B.BL_Steer_Module_Angle);

  /* Sum: '<S150>/Subtract1' incorporates:
   *  Product: '<S150>/Product2'
   *  Product: '<S150>/Product3'
   *  Trigonometry: '<S150>/Cos4'
   *  Trigonometry: '<S150>/Sin4'
   */
  rtb_Init_e = rtb_Add_cz * rtb_Optimized_Module_Angle + rtb_Product_do *
    rtb_Switch2_p;

  /* Sum: '<S150>/Subtract' incorporates:
   *  Product: '<S150>/Product'
   *  Product: '<S150>/Product1'
   *  Trigonometry: '<S150>/Cos4'
   *  Trigonometry: '<S150>/Sin4'
   */
  rtb_Switch2_p = rtb_Add_cz * rtb_Switch2_p - rtb_Product_do *
    rtb_Optimized_Module_Angle;

  /* Math: '<S150>/Hypot' */
  rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_Switch2_p, rtb_Init_e);

  /* Switch: '<S150>/Switch' incorporates:
   *  Constant: '<S150>/Constant'
   *  Constant: '<S150>/Constant1'
   *  Constant: '<S151>/Constant'
   *  Product: '<S150>/Divide'
   *  Product: '<S150>/Divide1'
   *  RelationalOperator: '<S151>/Compare'
   *  Switch: '<S150>/Switch1'
   */
  if (rtb_Optimized_Module_Angle > 1.0E-6) {
    rtb_Init_e /= rtb_Optimized_Module_Angle;
    rtb_Switch2_p /= rtb_Optimized_Module_Angle;
  } else {
    rtb_Init_e = 0.0;
    rtb_Switch2_p = 1.0;
  }

  /* End of Switch: '<S150>/Switch' */

  /* Switch: '<S139>/Speed_Switch' incorporates:
   *  Abs: '<S139>/Abs'
   *  Constant: '<S147>/Constant'
   *  RelationalOperator: '<S147>/Compare'
   *  Switch: '<S139>/Angle_Switch'
   *  Trigonometry: '<S149>/Atan1'
   *  Trigonometry: '<S150>/Atan1'
   *  UnaryMinus: '<S139>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Init_e, rtb_Switch2_p)) > 1.5707963267948966) {
    rtb_Add_ec = -Code_Gen_Model_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S149>/Subtract1' incorporates:
     *  Product: '<S149>/Product2'
     *  Product: '<S149>/Product3'
     *  UnaryMinus: '<S139>/Unary Minus'
     */
    rtb_Switch2_p = rtb_Add_cz * Code_Gen_Model_ConstB.Sin5_e + rtb_Product_do *
      Code_Gen_Model_ConstB.Cos5_i;

    /* Sum: '<S149>/Subtract' incorporates:
     *  Product: '<S149>/Product'
     *  Product: '<S149>/Product1'
     */
    rtb_Add_cz = rtb_Add_cz * Code_Gen_Model_ConstB.Cos5_i - rtb_Product_do *
      Code_Gen_Model_ConstB.Sin5_e;

    /* Math: '<S149>/Hypot' */
    rtb_Optimized_Module_Angle = rt_hypotd_snf(rtb_Add_cz, rtb_Switch2_p);

    /* Switch: '<S149>/Switch1' incorporates:
     *  Constant: '<S149>/Constant'
     *  Constant: '<S149>/Constant1'
     *  Constant: '<S152>/Constant'
     *  Product: '<S149>/Divide'
     *  Product: '<S149>/Divide1'
     *  RelationalOperator: '<S152>/Compare'
     *  Switch: '<S149>/Switch'
     */
    if (rtb_Optimized_Module_Angle > 1.0E-6) {
      rtb_Add_cz /= rtb_Optimized_Module_Angle;
      rtb_Switch2_p /= rtb_Optimized_Module_Angle;
    } else {
      rtb_Add_cz = 1.0;
      rtb_Switch2_p = 0.0;
    }

    /* End of Switch: '<S149>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Switch2_p, rtb_Add_cz);
  } else {
    rtb_Add_ec = Code_Gen_Model_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S142>/Product2' incorporates:
   *  Constant: '<S142>/Constant'
   *  Switch: '<S139>/Speed_Switch'
   */
  rtb_Init_e = rtb_Add_ec * 1530.1401357649195;

  /* Signum: '<S137>/Sign' */
  if (rtIsNaN(rtb_Init_e)) {
    rtb_Add_ec = (rtNaN);
  } else if (rtb_Init_e < 0.0) {
    rtb_Add_ec = -1.0;
  } else {
    rtb_Add_ec = rtb_Init_e > 0.0;
  }

  /* Signum: '<S137>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Add_cz = (rtNaN);
  } else if (Code_Gen_Model_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Add_cz = -1.0;
  } else {
    rtb_Add_cz = Code_Gen_Model_U.BackLeft_Drive_Motor_Speed > 0.0;
  }

  /* Sum: '<S140>/Add' incorporates:
   *  Sum: '<S141>/Sum'
   */
  rtb_Optimized_Module_Angle -= Code_Gen_Model_B.BL_Steer_Module_Angle;

  /* Product: '<S92>/Product' incorporates:
   *  Abs: '<S137>/Abs'
   *  Abs: '<S140>/Abs'
   *  Constant: '<S143>/Constant'
   *  Constant: '<S153>/Constant3'
   *  Constant: '<S153>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S137>/OR'
   *  Lookup_n-D: '<S140>/1-D Lookup Table'
   *  Math: '<S153>/Math Function'
   *  RelationalOperator: '<S137>/Equal1'
   *  RelationalOperator: '<S143>/Compare'
   *  Signum: '<S137>/Sign'
   *  Signum: '<S137>/Sign1'
   *  Sum: '<S140>/Add'
   *  Sum: '<S153>/Add1'
   *  Sum: '<S153>/Add2'
   */
  rtb_Init_e = (real_T)(rtb_Add_ec == rtb_Add_cz || fabs
                        (Code_Gen_Model_U.BackLeft_Drive_Motor_Speed) <=
                        Drive_Motor_Control_Sign_Change_Deadband) * rtb_Init_e *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  Code_Gen_Model_ConstP.pooled24, Code_Gen_Model_ConstP.pooled23,
                  1U);

  /* Gain: '<S138>/Gain' */
  rtb_Switch2_p = Drive_Motor_Control_FF * rtb_Init_e;

  /* Sum: '<S138>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Init_e -= Code_Gen_Model_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S145>/Sum1' incorporates:
   *  Constant: '<S138>/Constant2'
   *  Product: '<S145>/Product'
   *  Sum: '<S145>/Sum'
   *  UnitDelay: '<S145>/Unit Delay1'
   */
  rtb_Add_cz = (rtb_Init_e - Code_Gen_Model_DW.UnitDelay1_DSTATE_f) *
    Drive_Motor_Control_D_FilterCoeff + Code_Gen_Model_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S138>/Product' incorporates:
   *  Constant: '<S138>/Constant3'
   */
  rtb_Product_do = rtb_Add_cz * Drive_Motor_Control_D;

  /* Sum: '<S144>/Diff' incorporates:
   *  UnitDelay: '<S144>/UD'
   *
   * Block description for '<S144>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S144>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Product_do - Code_Gen_Model_DW.UD_DSTATE_lh;

  /* Saturate: '<S138>/Saturation' */
  if (rtb_Add_ec > Drive_Motor_Control_D_UL) {
    rtb_Add_ec = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_ec < Drive_Motor_Control_D_LL) {
    rtb_Add_ec = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S138>/Add' incorporates:
   *  Gain: '<S138>/Gain1'
   *  Saturate: '<S138>/Saturation'
   */
  rtb_Add_kz = Drive_Motor_Control_P * rtb_Init_e + rtb_Switch2_p + rtb_Add_ec;

  /* Sum: '<S138>/Subtract' incorporates:
   *  Constant: '<S138>/Constant'
   */
  rtb_Switch2_p = 1.0 - rtb_Add_kz;

  /* Sum: '<S138>/Sum2' incorporates:
   *  Gain: '<S138>/Gain2'
   *  UnitDelay: '<S138>/Unit Delay'
   */
  rtb_Init_e = Drive_Motor_Control_I * rtb_Init_e +
    Code_Gen_Model_DW.UnitDelay_DSTATE_gp;

  /* Switch: '<S146>/Switch2' incorporates:
   *  Constant: '<S138>/Constant'
   *  RelationalOperator: '<S146>/LowerRelop1'
   *  Sum: '<S138>/Subtract'
   */
  if (!(rtb_Init_e > 1.0 - rtb_Add_kz)) {
    /* Sum: '<S138>/Subtract1' incorporates:
     *  Constant: '<S138>/Constant1'
     */
    rtb_Switch2_p = -1.0 - rtb_Add_kz;

    /* Switch: '<S146>/Switch' incorporates:
     *  Constant: '<S138>/Constant1'
     *  RelationalOperator: '<S146>/UpperRelop'
     *  Sum: '<S138>/Subtract1'
     */
    if (!(rtb_Init_e < -1.0 - rtb_Add_kz)) {
      rtb_Switch2_p = rtb_Init_e;
    }

    /* End of Switch: '<S146>/Switch' */
  }

  /* End of Switch: '<S146>/Switch2' */

  /* Saturate: '<S138>/Saturation1' */
  if (rtb_Switch2_p > Drive_Motor_Control_I_UL) {
    rtb_Integral_m = Drive_Motor_Control_I_UL;
  } else if (rtb_Switch2_p < Drive_Motor_Control_I_LL) {
    rtb_Integral_m = Drive_Motor_Control_I_LL;
  } else {
    rtb_Integral_m = rtb_Switch2_p;
  }

  /* End of Saturate: '<S138>/Saturation1' */

  /* Sum: '<S138>/Add1' */
  rtb_Add_ec = rtb_Add_kz + rtb_Integral_m;

  /* Saturate: '<S138>/Saturation2' */
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

  /* End of Saturate: '<S138>/Saturation2' */

  /* Sum: '<S154>/Add1' incorporates:
   *  Constant: '<S154>/Constant3'
   *  Constant: '<S154>/Constant4'
   *  Math: '<S154>/Math Function'
   *  Sum: '<S154>/Add2'
   */
  rtb_Init_e = rt_modd_snf(rtb_Optimized_Module_Angle + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S156>/Sum1' incorporates:
   *  Constant: '<S141>/Constant2'
   *  Product: '<S156>/Product'
   *  Sum: '<S156>/Sum'
   *  UnitDelay: '<S156>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = (rtb_Init_e -
    Code_Gen_Model_DW.UnitDelay1_DSTATE_nw) *
    Steering_Motor_Control_D_FilterCoeff +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_nw;

  /* Product: '<S141>/Product' incorporates:
   *  Constant: '<S141>/Constant3'
   */
  rtb_Add_kz = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S155>/Diff' incorporates:
   *  UnitDelay: '<S155>/UD'
   *
   * Block description for '<S155>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S155>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_ec = rtb_Add_kz - Code_Gen_Model_DW.UD_DSTATE_k;

  /* Saturate: '<S141>/Saturation' */
  if (rtb_Add_ec > Steering_Motor_Control_D_UL) {
    rtb_Add_ec = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_ec < Steering_Motor_Control_D_LL) {
    rtb_Add_ec = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S141>/Add' incorporates:
   *  Gain: '<S141>/Gain1'
   *  Saturate: '<S141>/Saturation'
   */
  rtb_Add_ec += Steering_Motor_Control_P * rtb_Init_e;

  /* Sum: '<S141>/Subtract' incorporates:
   *  Constant: '<S141>/Constant'
   */
  rtb_Switch2_p = 1.0 - rtb_Add_ec;

  /* Sum: '<S141>/Sum2' incorporates:
   *  Gain: '<S141>/Gain2'
   *  UnitDelay: '<S141>/Unit Delay'
   */
  rtb_Init_e = Steering_Motor_Control_I * rtb_Init_e +
    Code_Gen_Model_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S157>/Switch2' incorporates:
   *  Constant: '<S141>/Constant'
   *  RelationalOperator: '<S157>/LowerRelop1'
   *  Sum: '<S141>/Subtract'
   */
  if (!(rtb_Init_e > 1.0 - rtb_Add_ec)) {
    /* Sum: '<S141>/Subtract1' incorporates:
     *  Constant: '<S141>/Constant1'
     */
    rtb_Switch2_p = -1.0 - rtb_Add_ec;

    /* Switch: '<S157>/Switch' incorporates:
     *  Constant: '<S141>/Constant1'
     *  RelationalOperator: '<S157>/UpperRelop'
     *  Sum: '<S141>/Subtract1'
     */
    if (!(rtb_Init_e < -1.0 - rtb_Add_ec)) {
      rtb_Switch2_p = rtb_Init_e;
    }

    /* End of Switch: '<S157>/Switch' */
  }

  /* End of Switch: '<S157>/Switch2' */

  /* Saturate: '<S141>/Saturation1' */
  if (rtb_Switch2_p > Steering_Motor_Control_I_UL) {
    rtb_Init_e = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_p < Steering_Motor_Control_I_LL) {
    rtb_Init_e = Steering_Motor_Control_I_LL;
  } else {
    rtb_Init_e = rtb_Switch2_p;
  }

  /* End of Saturate: '<S141>/Saturation1' */

  /* Sum: '<S141>/Add1' */
  rtb_Add_ec += rtb_Init_e;

  /* Saturate: '<S141>/Saturation2' */
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

  /* End of Saturate: '<S141>/Saturation2' */

  /* Gain: '<S22>/meters to feet1' */
  Code_Gen_Model_B.Odometry_Y_global_est_ft = 3.28084 *
    Code_Gen_Model_B.Odom_Position_Y_global;

  /* RelationalOperator: '<S23>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S23>/Constant'
   */
  rtb_Switch_b1 = Odometry_X_Y_TEAR != 0.0;

  /* Switch: '<S22>/Switch1' incorporates:
   *  UnitDelay: '<S22>/Unit Delay1'
   */
  if (rtb_Switch_b1) {
    rtb_Switch2_p = Code_Gen_Model_B.Odometry_Y_global_est_ft;
  } else {
    rtb_Switch2_p = Code_Gen_Model_DW.UnitDelay1_DSTATE_d;
  }

  /* End of Switch: '<S22>/Switch1' */

  /* Sum: '<S22>/Subtract1' */
  Code_Gen_Model_B.Odometry_Y_global_TEAR_ft =
    Code_Gen_Model_B.Odometry_Y_global_est_ft - rtb_Switch2_p;

  /* Gain: '<S22>/meters to feet' */
  Code_Gen_Model_B.Odometry_X_global_est_ft = 3.28084 *
    Code_Gen_Model_B.Odom_Position_X_global;

  /* Switch: '<S22>/Switch' incorporates:
   *  UnitDelay: '<S22>/Unit Delay'
   */
  if (rtb_Switch_b1) {
    rtb_Add_ec = Code_Gen_Model_B.Odometry_X_global_est_ft;
  } else {
    rtb_Add_ec = Code_Gen_Model_DW.UnitDelay_DSTATE_c;
  }

  /* End of Switch: '<S22>/Switch' */

  /* Sum: '<S22>/Subtract' */
  Code_Gen_Model_B.Odometry_X_global_TEAR_ft =
    Code_Gen_Model_B.Odometry_X_global_est_ft - rtb_Add_ec;

  /* Update for UnitDelay: '<S14>/UD' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Rev'
   *
   * Block description for '<S14>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE = Code_Gen_Model_U.FrontLeft_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S15>/UD' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Rev'
   *
   * Block description for '<S15>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_m = Code_Gen_Model_U.FrontRight_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S16>/UD' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Rev'
   *
   * Block description for '<S16>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_i = Code_Gen_Model_U.BackLeft_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S17>/UD' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Rev'
   *
   * Block description for '<S17>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_c = Code_Gen_Model_U.BackRight_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S13>/UD'
   *
   * Block description for '<S13>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_d = rtb_thetay;

  /* Update for DiscreteIntegrator: '<S7>/Accumulator2' incorporates:
   *  Constant: '<S7>/Constant'
   *  DiscreteIntegrator: '<S7>/Accumulator'
   *  Product: '<S7>/Product6'
   */
  Code_Gen_Model_DW.Accumulator2_DSTATE += rtb_POSEexponentialmatrixfori_1;
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

  /* End of Update for DiscreteIntegrator: '<S7>/Accumulator2' */

  /* Update for DiscreteIntegrator: '<S7>/Accumulator' incorporates:
   *  Product: '<S7>/Product6'
   */
  Code_Gen_Model_DW.Accumulator_DSTATE += rtb_POSEexponentialmatrixfori_2;

  /* Update for UnitDelay: '<S5>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_ll =
    Code_Gen_Model_B.Robot_Reached_Destination;

  /* Update for UnitDelay: '<S190>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S190>/FixPt Constant'
   */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S204>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE = rtb_Merge1;

  /* Update for UnitDelay: '<S203>/UD'
   *
   * Block description for '<S203>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_a = rtb_UnitDelay_f;

  /* Update for UnitDelay: '<S201>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_m = rtb_POSEexponentialmatrixfori_3;

  /* Update for UnitDelay: '<S199>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S199>/FixPt Constant'
   */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S166>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_k = rtb_Switch2;

  /* Update for UnitDelay: '<S165>/UD'
   *
   * Block description for '<S165>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_cs = rtb_Switch1_p2;

  /* Update for UnitDelay: '<S159>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_a = rtb_POSEexponentialmatrixfori_0;

  /* Update for UnitDelay: '<S177>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_i = rtb_Magnitude;

  /* Update for UnitDelay: '<S176>/UD'
   *
   * Block description for '<S176>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_l = rtb_Steer_Joystick_X_Rel_Mod;

  /* Update for UnitDelay: '<S162>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_l = rtb_Sum2_fc;

  /* Update for UnitDelay: '<S103>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_a = rtb_Add_pw;

  /* Update for UnitDelay: '<S102>/UD'
   *
   * Block description for '<S102>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_o = rtb_Hypot_g5;

  /* Update for UnitDelay: '<S96>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_f = rtb_Subtract_i;

  /* Update for UnitDelay: '<S114>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_b = rtb_Add_c4;

  /* Update for UnitDelay: '<S113>/UD'
   *
   * Block description for '<S113>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_b = rtb_Product_dq;

  /* Update for UnitDelay: '<S99>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_e = rtb_Subtract1_la;

  /* Update for UnitDelay: '<S124>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_b1 = rtb_Add_kl;

  /* Update for UnitDelay: '<S123>/UD'
   *
   * Block description for '<S123>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_e = rtb_Subtract_gn;

  /* Update for UnitDelay: '<S117>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_em = rtb_Hypot_b;

  /* Update for UnitDelay: '<S135>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_n = rtb_uDLookupTable_l;

  /* Update for UnitDelay: '<S134>/UD'
   *
   * Block description for '<S134>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_i1 = rtb_Add_c;

  /* Update for UnitDelay: '<S120>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_dt = rtb_Integral_kz;

  /* Update for UnitDelay: '<S145>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_f = rtb_Add_cz;

  /* Update for UnitDelay: '<S144>/UD'
   *
   * Block description for '<S144>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_lh = rtb_Product_do;

  /* Update for UnitDelay: '<S138>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_gp = rtb_Integral_m;

  /* Update for UnitDelay: '<S156>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_nw = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S155>/UD'
   *
   * Block description for '<S155>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_k = rtb_Add_kz;

  /* Update for UnitDelay: '<S141>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_k = rtb_Init_e;

  /* Update for UnitDelay: '<S22>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_d = rtb_Switch2_p;

  /* Update for UnitDelay: '<S22>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_c = rtb_Add_ec;
}

/* Model initialize function */
void Code_Gen_Model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for SwitchCase: '<S1>/Switch Case' */
  Code_Gen_Model_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for If: '<S8>/If' */
  Code_Gen_Model_DW.If_ActiveSubsystem = -1;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Accumulator2' */
  Code_Gen_Model_DW.Accumulator2_DSTATE = Code_Gen_Model_ConstB.Constant;
  Code_Gen_Model_DW.Accumulator2_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S7>/Accumulator' */
  Code_Gen_Model_DW.Accumulator_DSTATE = Code_Gen_Model_ConstB.Constant1;
  Code_Gen_Model_DW.Accumulator_PrevResetState = 2;

  /* InitializeConditions for UnitDelay: '<S190>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S199>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S250>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */

  /* SystemInitialize for IfAction SubSystem: '<S8>/Spline Path Following Enabled' */
  /* Start for If: '<S30>/If' */
  Code_Gen_Model_DW.If_ActiveSubsystem_h = -1;

  /* InitializeConditions for UnitDelay: '<S26>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_gh = 2.0;

  /* SystemInitialize for IfAction SubSystem: '<S30>/Robot_Index_Is_Valid' */
  /* Start for If: '<S33>/If' */
  Code_Gen_Model_DW.If_ActiveSubsystem_o = -1;

  /* SystemInitialize for IfAction SubSystem: '<S33>/Circle_Check_Valid' */
  /* Start for If: '<S35>/If' */
  Code_Gen_Model_DW.If_ActiveSubsystem_d = -1;

  /* End of SystemInitialize for SubSystem: '<S33>/Circle_Check_Valid' */
  /* End of SystemInitialize for SubSystem: '<S30>/Robot_Index_Is_Valid' */
  /* End of SystemInitialize for SubSystem: '<S8>/Spline Path Following Enabled' */
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
