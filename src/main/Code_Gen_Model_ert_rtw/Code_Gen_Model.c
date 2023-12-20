/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.26
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Dec 19 18:41:58 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Code_Gen_Model.h"
#include "rtwtypes.h"
#include "Code_Gen_Model_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <float.h>
#include "rt_defines.h"

/* Exported block parameters */
real_T Boost_Trigger_Decreasing_Limit = -0.044444;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S181>/Constant1'
                                      */
real_T Boost_Trigger_High_Speed = 3.658;/* Variable: Boost_Trigger_High_Speed
                                         * Referenced by:
                                         *   '<S179>/Constant'
                                         *   '<S179>/Saturation'
                                         */
real_T Boost_Trigger_Increasing_Limit = 0.04;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S181>/Constant3'
                                      */
real_T Boost_Trigger_Low_Speed = 1.5;  /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S179>/Constant1'
                                        */
real_T Drive_Motor_Control_D = 0.0001; /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S31>/Constant3'
                                        *   '<S52>/Constant3'
                                        *   '<S73>/Constant3'
                                        *   '<S94>/Constant3'
                                        */
real_T Drive_Motor_Control_D_FilterCoeff = 0.22223;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S31>/Constant2'
                                   *   '<S52>/Constant2'
                                   *   '<S73>/Constant2'
                                   *   '<S94>/Constant2'
                                   */
real_T Drive_Motor_Control_D_LL = -0.2;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S31>/Saturation'
                                        *   '<S52>/Saturation'
                                        *   '<S73>/Saturation'
                                        *   '<S94>/Saturation'
                                        */
real_T Drive_Motor_Control_D_UL = 0.2; /* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S31>/Saturation'
                                        *   '<S52>/Saturation'
                                        *   '<S73>/Saturation'
                                        *   '<S94>/Saturation'
                                        */
real_T Drive_Motor_Control_FF = 0.00018182;/* Variable: Drive_Motor_Control_FF
                                            * Referenced by:
                                            *   '<S31>/Gain'
                                            *   '<S52>/Gain'
                                            *   '<S73>/Gain'
                                            *   '<S94>/Gain'
                                            */
real_T Drive_Motor_Control_I = 0.0;    /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S31>/Gain2'
                                        *   '<S52>/Gain2'
                                        *   '<S73>/Gain2'
                                        *   '<S94>/Gain2'
                                        */
real_T Drive_Motor_Control_I_LL = 0.0; /* Variable: Drive_Motor_Control_I_LL
                                        * Referenced by:
                                        *   '<S31>/Saturation1'
                                        *   '<S52>/Saturation1'
                                        *   '<S73>/Saturation1'
                                        *   '<S94>/Saturation1'
                                        */
real_T Drive_Motor_Control_I_UL = 0.0; /* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S31>/Saturation1'
                                        *   '<S52>/Saturation1'
                                        *   '<S73>/Saturation1'
                                        *   '<S94>/Saturation1'
                                        */
real_T Drive_Motor_Control_P = 5.0E-6; /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S31>/Gain1'
                                        *   '<S52>/Gain1'
                                        *   '<S73>/Gain1'
                                        *   '<S94>/Gain1'
                                        */
real_T Drive_Motor_Control_Sign_Change_Deadband = 1500.0;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S36>/Constant'
                            *   '<S57>/Constant'
                            *   '<S78>/Constant'
                            *   '<S99>/Constant'
                            */
real_T Odometry_Desired_X = 0.0;       /* Variable: Odometry_Desired_X
                                        * Referenced by: '<S2>/Constant7'
                                        */
real_T Odometry_Desired_Y = 0.0;       /* Variable: Odometry_Desired_Y
                                        * Referenced by: '<S2>/Constant8'
                                        */
real_T Odometry_X_Y_TEAR = 0.0;        /* Variable: Odometry_X_Y_TEAR
                                        * Referenced by: '<S19>/Constant'
                                        */
real_T Steering_Abs_Deadband_Range = 0.7;/* Variable: Steering_Abs_Deadband_Range
                                          * Referenced by: '<S169>/Constant2'
                                          */
real_T Steering_Heading_Control_D = 0.0;/* Variable: Steering_Heading_Control_D
                                         * Referenced by: '<S136>/Constant3'
                                         */
real_T Steering_Heading_Control_D_FilterCoeff = 0.22223;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S136>/Constant2'
                              */
real_T Steering_Heading_Control_D_LL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S136>/Saturation'
                                       */
real_T Steering_Heading_Control_D_UL = 0.0;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S136>/Saturation'
                                       */
real_T Steering_Heading_Control_Deadzone = 0.1;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S135>/Constant'
                                   */
real_T Steering_Heading_Control_I = 0.0;/* Variable: Steering_Heading_Control_I
                                         * Referenced by: '<S136>/Gain2'
                                         */
real_T Steering_Heading_Control_I_LL = -0.1;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S136>/Saturation1'
                                       */
real_T Steering_Heading_Control_I_UL = 0.1;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S136>/Saturation1'
                                       */
real_T Steering_Heading_Control_P = 1.5;/* Variable: Steering_Heading_Control_P
                                         * Referenced by: '<S136>/Gain1'
                                         */
real_T Steering_Heading_Control_Total_LL = -1.3;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S136>/Constant1'
                                   *   '<S136>/Saturation2'
                                   */
real_T Steering_Heading_Control_Total_UL = 1.3;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S136>/Constant'
                                   *   '<S136>/Saturation2'
                                   */
real_T Steering_Localized_Cmd_Approach_Zero_Error_Thresh = 0.2;
                  /* Variable: Steering_Localized_Cmd_Approach_Zero_Error_Thresh
                   * Referenced by: '<S126>/Constant5'
                   */
real_T Steering_Localized_Cmd_Approach_Zero_Final_Thresh = 0.01;
                  /* Variable: Steering_Localized_Cmd_Approach_Zero_Final_Thresh
                   * Referenced by: '<S126>/Constant6'
                   */
real_T Steering_Localized_Cmd_NonZero_Error_Thresh = 0.2;
                        /* Variable: Steering_Localized_Cmd_NonZero_Error_Thresh
                         * Referenced by: '<S126>/Constant9'
                         */
real_T Steering_Localized_Cmd_NonZero_Final_Scale_Factor = 0.1;
                  /* Variable: Steering_Localized_Cmd_NonZero_Final_Scale_Factor
                   * Referenced by: '<S126>/Constant10'
                   */
real_T Steering_Localized_Cmd_Rate_Limit_Dec = -1.0;
                              /* Variable: Steering_Localized_Cmd_Rate_Limit_Dec
                               * Referenced by: '<S126>/Constant1'
                               */
real_T Steering_Localized_Cmd_Rate_Limit_Inc = 1.0;
                              /* Variable: Steering_Localized_Cmd_Rate_Limit_Inc
                               * Referenced by: '<S126>/Constant3'
                               */
real_T Steering_Motor_Control_D = 0.5; /* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S34>/Constant3'
                                        *   '<S55>/Constant3'
                                        *   '<S76>/Constant3'
                                        *   '<S97>/Constant3'
                                        */
real_T Steering_Motor_Control_D_FilterCoeff = 0.22223;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S34>/Constant2'
                                *   '<S55>/Constant2'
                                *   '<S76>/Constant2'
                                *   '<S97>/Constant2'
                                */
real_T Steering_Motor_Control_D_LL = -0.2;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S34>/Saturation'
                                           *   '<S55>/Saturation'
                                           *   '<S76>/Saturation'
                                           *   '<S97>/Saturation'
                                           */
real_T Steering_Motor_Control_D_UL = 0.2;/* Variable: Steering_Motor_Control_D_UL
                                          * Referenced by:
                                          *   '<S34>/Saturation'
                                          *   '<S55>/Saturation'
                                          *   '<S76>/Saturation'
                                          *   '<S97>/Saturation'
                                          */
real_T Steering_Motor_Control_I = 0.005;/* Variable: Steering_Motor_Control_I
                                         * Referenced by:
                                         *   '<S34>/Gain2'
                                         *   '<S55>/Gain2'
                                         *   '<S76>/Gain2'
                                         *   '<S97>/Gain2'
                                         */
real_T Steering_Motor_Control_I_LL = -0.005;/* Variable: Steering_Motor_Control_I_LL
                                             * Referenced by:
                                             *   '<S34>/Saturation1'
                                             *   '<S55>/Saturation1'
                                             *   '<S76>/Saturation1'
                                             *   '<S97>/Saturation1'
                                             */
real_T Steering_Motor_Control_I_UL = 0.005;/* Variable: Steering_Motor_Control_I_UL
                                            * Referenced by:
                                            *   '<S34>/Saturation1'
                                            *   '<S55>/Saturation1'
                                            *   '<S76>/Saturation1'
                                            *   '<S97>/Saturation1'
                                            */
real_T Steering_Motor_Control_P = 0.15;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S34>/Gain1'
                                        *   '<S55>/Gain1'
                                        *   '<S76>/Gain1'
                                        *   '<S97>/Gain1'
                                        */
real_T Steering_Relative_Gain = 1.3;   /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S167>/Constant'
                                        */
real_T Translation_Speed_Approach_Zero_Error_Thresh = 0.2;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S114>/Constant5'
                        */
real_T Translation_Speed_Approach_Zero_Final_Thresh = 0.01;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S114>/Constant6'
                        */
real_T Translation_Speed_NonZero_Error_Thresh = 0.15;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S114>/Constant9'
                              */
real_T Translation_Speed_NonZero_Final_Scale_Factor = 0.05;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S114>/Constant10'
                        */
real_T Translation_Speed_Rate_Limit_Dec = -0.2;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S114>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 0.085714;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S114>/Constant3'
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
void Code_Gen_Model_Disabled(real_T *rty_Gyro_Angle_Adjusted, real_T
  *rty_Steering_Abs_Cmd, real_T *rty_Steering_Rel_Cmd, real_T
  *rty_Translation_Angle, real_T *rty_Translation_Speed, boolean_T
  *rty_Is_Absolute_Translation_Out, boolean_T *rty_Is_Absolute_Steering_Out)
{
  /* SignalConversion generated from: '<S4>/Gyro_Angle_Adjusted' incorporates:
   *  Constant: '<S4>/Constant'
   */
  *rty_Gyro_Angle_Adjusted = 0.0;

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

  /* SignalConversion generated from: '<S4>/Is_Absolute_Translation_Out' incorporates:
   *  Constant: '<S4>/Constant5'
   */
  *rty_Is_Absolute_Translation_Out = true;

  /* SignalConversion generated from: '<S4>/Is_Absolute_Steering_Out' incorporates:
   *  Constant: '<S4>/Constant6'
   */
  *rty_Is_Absolute_Steering_Out = true;
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

/* Model step function */
void Code_Gen_Model_step(void)
{
  /* local block i/o variables */
  real_T rtb_LookupTableDynamic1;
  real_T rtb_LookupTableDynamic;
  real_T rtb_LookupTableDynamic1_i;
  real_T rtb_LookupTableDynamic_j;
  real_T rtb_thetay_0[8];
  real_T rtb_Product7[2];
  real_T rtb_TmpSignalConversionAtLook_o[2];
  real_T rtb_Add_cc;
  real_T rtb_Add_f_idx_0;
  real_T rtb_Add_f_idx_1;
  real_T rtb_Add_ia;
  real_T rtb_Add_k;
  real_T rtb_Add_lb;
  real_T rtb_Add_p;
  real_T rtb_Init_e;
  real_T rtb_Integral_da;
  real_T rtb_Integral_i;
  real_T rtb_Integral_je;
  real_T rtb_Magnitude;
  real_T rtb_Optimized_Module_Angle;
  real_T rtb_POSEexponentialmatrixfori_0;
  real_T rtb_POSEexponentialmatrixfori_1;
  real_T rtb_POSEexponentialmatrixfori_2;
  real_T rtb_Product_go;
  real_T rtb_Product_lf;
  real_T rtb_Product_n3;
  real_T rtb_Product_nw;
  real_T rtb_Steer_Joystick_X_Rel_Mod;
  real_T rtb_Subtract1_hh;
  real_T rtb_Subtract1_o;
  real_T rtb_Subtract_kb;
  real_T rtb_Subtract_n;
  real_T rtb_Sum2_fc;
  real_T rtb_Switch2;
  real_T rtb_Switch2_d;
  real_T rtb_Switch2_o;
  real_T rtb_Total_Limited;
  real_T rtb_thetay;
  real_T rtb_uDLookupTable;
  int32_T i;
  int32_T i_0;
  int32_T tmp;
  boolean_T rtb_Compare_lk;
  boolean_T rtb_Compare_m3;
  boolean_T rtb_Compare_o;
  boolean_T rtb_Is_Absolute_Translation;

  /* Sum: '<S21>/Add1' incorporates:
   *  Constant: '<S21>/Constant3'
   *  Constant: '<S21>/Constant4'
   *  Gain: '<S6>/Revolutions to Radians'
   *  Inport: '<Root>/FrontLeft_Steer_Rev'
   *  Inport: '<Root>/FrontLeft_Turn_Offset'
   *  Math: '<S21>/Math Function'
   *  Sum: '<S21>/Add2'
   *  Sum: '<S6>/Add'
   */
  Code_Gen_Model_B.FL_Steer_Module_Angle = rt_modd_snf
    ((Code_Gen_Model_U.FrontLeft_Steer_Rev -
      Code_Gen_Model_U.FrontLeft_Turn_Offset) * 6.2831853071795862 +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S5>/Product' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Rev'
   *  Sum: '<S11>/Diff'
   *  UnitDelay: '<S11>/UD'
   *
   * Block description for '<S11>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S11>/UD':
   *
   *  Store in Global RAM
   */
  rtb_thetay = (Code_Gen_Model_U.FrontLeft_Drive_Motor_Rev -
                Code_Gen_Model_DW.UD_DSTATE) * 0.037290702116950625;

  /* Sum: '<S22>/Add1' incorporates:
   *  Constant: '<S22>/Constant3'
   *  Constant: '<S22>/Constant4'
   *  Gain: '<S6>/Revolutions to Radians1'
   *  Inport: '<Root>/FrontRight_Steer_Rev'
   *  Inport: '<Root>/FrontRight_Turn_Offset'
   *  Math: '<S22>/Math Function'
   *  Sum: '<S22>/Add2'
   *  Sum: '<S6>/Add1'
   */
  Code_Gen_Model_B.FR_Steer_Module_Angle = rt_modd_snf
    ((Code_Gen_Model_U.FrontRight_Steer_Rev -
      Code_Gen_Model_U.FrontRight_Turn_Offset) * 6.2831853071795862 +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S5>/Product1' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Rev'
   *  Sum: '<S12>/Diff'
   *  UnitDelay: '<S12>/UD'
   *
   * Block description for '<S12>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S12>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Init_e = (Code_Gen_Model_U.FrontRight_Drive_Motor_Rev -
                Code_Gen_Model_DW.UD_DSTATE_m) * 0.037290702116950625;

  /* Sum: '<S23>/Add1' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant4'
   *  Gain: '<S6>/Revolutions to Radians2'
   *  Inport: '<Root>/BackLeft_Steer_Rev'
   *  Inport: '<Root>/BackLeft_Turn_Offset'
   *  Math: '<S23>/Math Function'
   *  Sum: '<S23>/Add2'
   *  Sum: '<S6>/Add2'
   */
  Code_Gen_Model_B.BL_Steer_Module_Angle = rt_modd_snf
    ((Code_Gen_Model_U.BackLeft_Steer_Rev -
      Code_Gen_Model_U.BackLeft_Turn_Offset) * 6.2831853071795862 +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S5>/Product2' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Rev'
   *  Sum: '<S13>/Diff'
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
  rtb_uDLookupTable = (Code_Gen_Model_U.BackLeft_Drive_Motor_Rev -
                       Code_Gen_Model_DW.UD_DSTATE_i) * 0.037290702116950625;

  /* Sum: '<S24>/Add1' incorporates:
   *  Constant: '<S24>/Constant3'
   *  Constant: '<S24>/Constant4'
   *  Gain: '<S6>/Revolutions to Radians3'
   *  Inport: '<Root>/BackRight_Steer_Rev'
   *  Inport: '<Root>/BackRight_Turn_Offset'
   *  Math: '<S24>/Math Function'
   *  Sum: '<S24>/Add2'
   *  Sum: '<S6>/Add3'
   */
  Code_Gen_Model_B.BR_Steer_Module_Angle = rt_modd_snf
    ((Code_Gen_Model_U.BackRight_Steer_Rev -
      Code_Gen_Model_U.BackRight_Turn_Offset) * 6.2831853071795862 +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Product: '<S5>/Product3' incorporates:
   *  Constant: '<S5>/Constant1'
   *  Inport: '<Root>/BackRight_Drive_Motor_Rev'
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
  rtb_Switch2_d = (Code_Gen_Model_U.BackRight_Drive_Motor_Rev -
                   Code_Gen_Model_DW.UD_DSTATE_c) * 0.037290702116950625;

  /* SignalConversion generated from: '<S5>/Product7' incorporates:
   *  Fcn: '<S15>/r->x'
   *  Fcn: '<S15>/theta->y'
   *  Fcn: '<S16>/r->x'
   *  Fcn: '<S16>/theta->y'
   *  Fcn: '<S17>/r->x'
   *  Fcn: '<S17>/theta->y'
   *  Fcn: '<S18>/r->x'
   *  Fcn: '<S18>/theta->y'
   */
  rtb_thetay_0[0] = rtb_thetay * cos(Code_Gen_Model_B.FL_Steer_Module_Angle);
  rtb_thetay_0[1] = rtb_thetay * sin(Code_Gen_Model_B.FL_Steer_Module_Angle);
  rtb_thetay_0[2] = rtb_Init_e * cos(Code_Gen_Model_B.FR_Steer_Module_Angle);
  rtb_thetay_0[3] = rtb_Init_e * sin(Code_Gen_Model_B.FR_Steer_Module_Angle);
  rtb_thetay_0[4] = rtb_uDLookupTable * cos
    (Code_Gen_Model_B.BL_Steer_Module_Angle);
  rtb_thetay_0[5] = rtb_uDLookupTable * sin
    (Code_Gen_Model_B.BL_Steer_Module_Angle);
  rtb_thetay_0[6] = rtb_Switch2_d * cos(Code_Gen_Model_B.BR_Steer_Module_Angle);
  rtb_thetay_0[7] = rtb_Switch2_d * sin(Code_Gen_Model_B.BR_Steer_Module_Angle);

  /* Product: '<S5>/Product7' incorporates:
   *  Constant: '<S5>/Constant4'
   */
  for (i = 0; i < 2; i++) {
    rtb_thetay = 0.0;
    tmp = 0;
    for (i_0 = 0; i_0 < 8; i_0++) {
      rtb_thetay += Code_Gen_Model_ConstP.Constant4_Value[tmp + i] *
        rtb_thetay_0[i_0];
      tmp += 2;
    }

    rtb_Product7[i] = rtb_thetay;
  }

  /* End of Product: '<S5>/Product7' */

  /* Gain: '<S3>/Gain1' incorporates:
   *  Inport: '<Root>/Gyro_Angle'
   */
  rtb_thetay = 0.017453292519943295 * Code_Gen_Model_U.Gyro_Angle;

  /* Sum: '<S10>/Diff' incorporates:
   *  UnitDelay: '<S10>/UD'
   *
   * Block description for '<S10>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S10>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Total_Limited = rtb_thetay - Code_Gen_Model_DW.UD_DSTATE_d;

  /* Sum: '<S5>/Subtract2' incorporates:
   *  Constant: '<S5>/Constant3'
   *  Gain: '<S5>/Gain7'
   *  Math: '<S5>/Square'
   */
  rtb_Switch2_d = 1.0 - rtb_Total_Limited * rtb_Total_Limited *
    0.16666666666666666;

  /* Gain: '<S5>/Gain6' */
  rtb_Total_Limited *= 0.5;

  /* SignalConversion generated from: '<S5>/POSE exponential matrix for improved accuracy while rotating' */
  rtb_POSEexponentialmatrixfori_0 = rtb_Switch2_d;
  rtb_POSEexponentialmatrixfori_1 = rtb_Total_Limited;

  /* SignalConversion generated from: '<S5>/POSE exponential matrix for improved accuracy while rotating' incorporates:
   *  UnaryMinus: '<S5>/Unary Minus2'
   */
  rtb_POSEexponentialmatrixfori_2 = -rtb_Total_Limited;

  /* Trigonometry: '<S5>/Trigonometric Function' */
  rtb_Total_Limited = cos(rtb_thetay);

  /* Trigonometry: '<S5>/Trigonometric Function1' */
  rtb_Switch2_d = sin(rtb_thetay);

  /* Product: '<S5>/Product6' incorporates:
   *  Concatenate: '<S5>/POSE exponential matrix for improved accuracy while rotating'
   *  SignalConversion generated from: '<S5>/Rotation matrix from local to global'
   *  UnaryMinus: '<S5>/Unary Minus'
   */
  rtb_POSEexponentialmatrixfori_2 = rtb_POSEexponentialmatrixfori_0 *
    rtb_Product7[0] + rtb_POSEexponentialmatrixfori_2 * rtb_Product7[1];
  rtb_POSEexponentialmatrixfori_0 = rtb_POSEexponentialmatrixfori_1 *
    rtb_Product7[0] + rtb_POSEexponentialmatrixfori_0 * rtb_Product7[1];
  rtb_POSEexponentialmatrixfori_1 = rtb_Total_Limited *
    rtb_POSEexponentialmatrixfori_2 + -rtb_Switch2_d *
    rtb_POSEexponentialmatrixfori_0;
  rtb_POSEexponentialmatrixfori_2 = rtb_Switch2_d *
    rtb_POSEexponentialmatrixfori_2 + rtb_Total_Limited *
    rtb_POSEexponentialmatrixfori_0;

  /* DiscreteIntegrator: '<S5>/Accumulator2' */
  Code_Gen_Model_B.Odometry_X_global_est_m =
    Code_Gen_Model_DW.Accumulator2_DSTATE;

  /* DiscreteIntegrator: '<S5>/Accumulator' */
  Code_Gen_Model_B.Odometry_Y_global_est_m =
    Code_Gen_Model_DW.Accumulator_DSTATE;

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtb_Switch2_d = trunc(Code_Gen_Model_U.GameState);
  if (rtIsNaN(rtb_Switch2_d) || rtIsInf(rtb_Switch2_d)) {
    rtb_Switch2_d = 0.0;
  } else {
    rtb_Switch2_d = fmod(rtb_Switch2_d, 4.294967296E+9);
  }

  if (rtb_Switch2_d < 0.0) {
    i = -(int32_T)(uint32_T)-rtb_Switch2_d;
  } else {
    i = (int32_T)(uint32_T)rtb_Switch2_d;
  }

  switch (i) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Disabled' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    Code_Gen_Model_Disabled(&Code_Gen_Model_B.Gyro_Angle_Adjusted,
      &Code_Gen_Model_B.Steering_Abs_Cmd, &Code_Gen_Model_B.Steering_Rel_Cmd,
      &Code_Gen_Model_B.Translation_Angle, &Code_Gen_Model_B.Translation_Speed,
      &rtb_Is_Absolute_Translation, &rtb_Compare_m3);

    /* End of Outputs for SubSystem: '<S1>/Disabled' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Sum: '<S2>/Subtract' incorporates:
     *  Constant: '<S2>/Constant8'
     */
    rtb_POSEexponentialmatrixfori_0 = Odometry_Desired_Y -
      Code_Gen_Model_B.Odometry_Y_global_est_m;

    /* Sum: '<S2>/Subtract1' incorporates:
     *  Constant: '<S2>/Constant7'
     */
    rtb_Subtract1_o = Odometry_Desired_X -
      Code_Gen_Model_B.Odometry_X_global_est_m;

    /* Merge: '<S1>/Merge4' incorporates:
     *  Constant: '<S2>/Constant'
     *  Math: '<S2>/Hypot'
     *  MinMax: '<S2>/Min'
     */
    Code_Gen_Model_B.Translation_Speed = fmin(rt_hypotd_snf
      (rtb_POSEexponentialmatrixfori_0, rtb_Subtract1_o), 1.0);

    /* Trigonometry: '<S2>/Atan2' */
    rtb_POSEexponentialmatrixfori_0 = rt_atan2d_snf
      (rtb_POSEexponentialmatrixfori_0, rtb_Subtract1_o);

    /* Merge: '<S1>/Merge1' incorporates:
     *  SignalConversion: '<S2>/Signal Copy'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd = rtb_POSEexponentialmatrixfori_0;

    /* Merge: '<S1>/Merge3' incorporates:
     *  SignalConversion: '<S2>/Signal Copy1'
     */
    Code_Gen_Model_B.Translation_Angle = rtb_POSEexponentialmatrixfori_0;

    /* Merge: '<S1>/Merge2' incorporates:
     *  Constant: '<S2>/Constant2'
     *  SignalConversion generated from: '<S2>/Steering_Rel_Cmd'
     */
    Code_Gen_Model_B.Steering_Rel_Cmd = 0.0;

    /* SignalConversion generated from: '<S2>/Is_Absolute_Translation_Out' incorporates:
     *  Constant: '<S2>/Constant5'
     */
    rtb_Is_Absolute_Translation = true;

    /* SignalConversion generated from: '<S2>/Is_Absolute_Steering_Out' incorporates:
     *  Constant: '<S2>/Constant6'
     */
    rtb_Compare_m3 = true;

    /* Merge: '<S1>/Merge' incorporates:
     *  SignalConversion generated from: '<S2>/Gyro_Angle'
     */
    Code_Gen_Model_B.Gyro_Angle_Adjusted = rtb_thetay;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Teleop' incorporates:
     *  ActionPort: '<S8>/Action Port'
     */
    /* Switch: '<S169>/Switch1' incorporates:
     *  Constant: '<S169>/Constant'
     *  Constant: '<S169>/Constant1'
     *  Constant: '<S169>/Constant2'
     *  Inport: '<Root>/Steer_Joystick_X'
     *  Inport: '<Root>/Steer_Joystick_Y'
     *  Math: '<S169>/Hypot'
     *  RelationalOperator: '<S169>/GreaterThan'
     *  Switch: '<S169>/Switch'
     */
    if (rt_hypotd_snf(Code_Gen_Model_U.Steer_Joystick_X,
                      Code_Gen_Model_U.Steer_Joystick_Y) >
        Steering_Abs_Deadband_Range) {
      rtb_Subtract1_o = Code_Gen_Model_U.Steer_Joystick_Y;
      rtb_POSEexponentialmatrixfori_0 = Code_Gen_Model_U.Steer_Joystick_X;
    } else {
      rtb_Subtract1_o = 0.0;
      rtb_POSEexponentialmatrixfori_0 = 0.0;
    }

    /* End of Switch: '<S169>/Switch1' */

    /* Switch: '<S171>/Switch1' incorporates:
     *  Constant: '<S177>/Constant'
     *  Constant: '<S178>/Constant'
     *  Logic: '<S171>/AND'
     *  RelationalOperator: '<S177>/Compare'
     *  RelationalOperator: '<S178>/Compare'
     *  Switch: '<S171>/Switch2'
     *  UnitDelay: '<S171>/Unit Delay'
     *  UnitDelay: '<S171>/Unit Delay1'
     */
    if (rtb_POSEexponentialmatrixfori_0 == 0.0 && rtb_Subtract1_o == 0.0) {
      rtb_Subtract1_o = Code_Gen_Model_DW.UnitDelay1_DSTATE_d2;
      rtb_Switch2 = Code_Gen_Model_DW.UnitDelay_DSTATE_g4;
    } else {
      rtb_Switch2 = rtb_POSEexponentialmatrixfori_0;
    }

    /* End of Switch: '<S171>/Switch1' */

    /* Merge: '<S1>/Merge1' incorporates:
     *  Trigonometry: '<S167>/Atan2'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd = rt_atan2d_snf(rtb_Subtract1_o,
      rtb_Switch2);

    /* RelationalOperator: '<S174>/Compare' incorporates:
     *  Constant: '<S174>/Constant'
     */
    rtb_Is_Absolute_Translation = rtb_Switch2 < 0.0;

    /* Switch: '<S170>/Switch' incorporates:
     *  Constant: '<S170>/Constant'
     *  Constant: '<S170>/Constant1'
     *  Constant: '<S172>/Constant'
     *  Constant: '<S173>/Constant'
     *  Logic: '<S170>/Logical Operator'
     *  RelationalOperator: '<S172>/Compare'
     *  RelationalOperator: '<S173>/Compare'
     *  UnitDelay: '<S170>/Unit Delay'
     */
    if (rtb_Subtract1_o < 0.0 && Code_Gen_Model_DW.UnitDelay_DSTATE_h >= 0.0 &&
        rtb_Is_Absolute_Translation) {
      rtb_Switch2_d = 6.2831853071795862;
    } else {
      rtb_Switch2_d = 0.0;
    }

    /* Switch: '<S170>/Switch1' incorporates:
     *  Constant: '<S170>/Constant2'
     *  Constant: '<S170>/Constant3'
     *  Constant: '<S175>/Constant'
     *  Constant: '<S176>/Constant'
     *  Logic: '<S170>/Logical Operator1'
     *  RelationalOperator: '<S175>/Compare'
     *  RelationalOperator: '<S176>/Compare'
     *  UnitDelay: '<S170>/Unit Delay'
     */
    if (Code_Gen_Model_DW.UnitDelay_DSTATE_h < 0.0 && rtb_Subtract1_o >= 0.0 &&
        rtb_Is_Absolute_Translation) {
      rtb_Subtract_n = -6.2831853071795862;
    } else {
      rtb_Subtract_n = 0.0;
    }

    /* Sum: '<S170>/Sum1' incorporates:
     *  Switch: '<S170>/Switch'
     *  Switch: '<S170>/Switch1'
     *  UnitDelay: '<S170>/Unit Delay1'
     */
    rtb_uDLookupTable = rtb_Switch2_d + rtb_Subtract_n +
      Code_Gen_Model_DW.UnitDelay1_DSTATE_kr;

    /* Merge: '<S1>/Merge' incorporates:
     *  Sum: '<S170>/Sum'
     */
    Code_Gen_Model_B.Gyro_Angle_Adjusted = rtb_thetay + rtb_uDLookupTable;

    /* Lookup_n-D: '<S168>/Modulation_Drv_X' incorporates:
     *  Inport: '<Root>/Drive_Joystick_X'
     */
    rtb_Steer_Joystick_X_Rel_Mod = look1_binlcpw
      (Code_Gen_Model_U.Drive_Joystick_X, Code_Gen_Model_ConstP.pooled8,
       Code_Gen_Model_ConstP.pooled7, 20U);

    /* Lookup_n-D: '<S168>/Modulation_Drv_Y' incorporates:
     *  Inport: '<Root>/Drive_Joystick_Y'
     */
    rtb_POSEexponentialmatrixfori_0 = look1_binlcpw
      (Code_Gen_Model_U.Drive_Joystick_Y, Code_Gen_Model_ConstP.pooled8,
       Code_Gen_Model_ConstP.pooled7, 20U);

    /* Switch: '<S180>/Switch1' incorporates:
     *  Constant: '<S185>/Constant'
     *  Constant: '<S186>/Constant'
     *  Logic: '<S180>/AND'
     *  RelationalOperator: '<S185>/Compare'
     *  RelationalOperator: '<S186>/Compare'
     *  Switch: '<S180>/Switch2'
     *  UnitDelay: '<S180>/Unit Delay'
     *  UnitDelay: '<S180>/Unit Delay1'
     */
    if (rtb_Steer_Joystick_X_Rel_Mod == 0.0 && rtb_POSEexponentialmatrixfori_0 ==
        0.0) {
      rtb_Init_e = Code_Gen_Model_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2_o = Code_Gen_Model_DW.UnitDelay_DSTATE_p;
    } else {
      rtb_Init_e = rtb_POSEexponentialmatrixfori_0;
      rtb_Switch2_o = rtb_Steer_Joystick_X_Rel_Mod;
    }

    /* End of Switch: '<S180>/Switch1' */

    /* Merge: '<S1>/Merge3' incorporates:
     *  Trigonometry: '<S168>/Atan2'
     */
    Code_Gen_Model_B.Translation_Angle = rt_atan2d_snf(rtb_Init_e, rtb_Switch2_o);

    /* Math: '<S168>/Magnitude' */
    rtb_Magnitude = rt_hypotd_snf(rtb_Steer_Joystick_X_Rel_Mod,
      rtb_POSEexponentialmatrixfori_0);

    /* Switch: '<S179>/Switch1' incorporates:
     *  Constant: '<S179>/Constant'
     *  Constant: '<S179>/Constant1'
     *  Inport: '<Root>/Is_Boost_Trigger_Pulled'
     */
    if (Code_Gen_Model_U.Is_Boost_Trigger_Pulled != 0.0) {
      rtb_Steer_Joystick_X_Rel_Mod = Boost_Trigger_High_Speed;
    } else {
      rtb_Steer_Joystick_X_Rel_Mod = Boost_Trigger_Low_Speed;
    }

    /* End of Switch: '<S179>/Switch1' */

    /* Switch: '<S184>/Init' incorporates:
     *  UnitDelay: '<S184>/FixPt Unit Delay1'
     *  UnitDelay: '<S184>/FixPt Unit Delay2'
     */
    if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_POSEexponentialmatrixfori_0 = rtb_Steer_Joystick_X_Rel_Mod;
    } else {
      rtb_POSEexponentialmatrixfori_0 =
        Code_Gen_Model_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S184>/Init' */

    /* Sum: '<S182>/Sum1' */
    rtb_Steer_Joystick_X_Rel_Mod -= rtb_POSEexponentialmatrixfori_0;

    /* Switch: '<S183>/Switch2' incorporates:
     *  Constant: '<S181>/Constant1'
     *  Constant: '<S181>/Constant3'
     *  RelationalOperator: '<S183>/LowerRelop1'
     *  RelationalOperator: '<S183>/UpperRelop'
     *  Switch: '<S183>/Switch'
     */
    if (rtb_Steer_Joystick_X_Rel_Mod > Boost_Trigger_Increasing_Limit) {
      rtb_Steer_Joystick_X_Rel_Mod = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Steer_Joystick_X_Rel_Mod < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S183>/Switch' incorporates:
       *  Constant: '<S181>/Constant1'
       */
      rtb_Steer_Joystick_X_Rel_Mod = Boost_Trigger_Decreasing_Limit;
    }

    /* End of Switch: '<S183>/Switch2' */

    /* Sum: '<S182>/Sum' */
    rtb_POSEexponentialmatrixfori_0 += rtb_Steer_Joystick_X_Rel_Mod;

    /* Product: '<S179>/Product' */
    rtb_Add_cc = rtb_Magnitude * rtb_POSEexponentialmatrixfori_0;

    /* Saturate: '<S179>/Saturation' */
    if (rtb_Add_cc > Boost_Trigger_High_Speed) {
      /* Merge: '<S1>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = Boost_Trigger_High_Speed;
    } else if (rtb_Add_cc < -Boost_Trigger_High_Speed) {
      /* Merge: '<S1>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = -Boost_Trigger_High_Speed;
    } else {
      /* Merge: '<S1>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = rtb_Add_cc;
    }

    /* End of Saturate: '<S179>/Saturation' */

    /* Merge: '<S1>/Merge2' incorporates:
     *  Constant: '<S167>/Constant'
     *  Inport: '<Root>/Steer_Joystick_Y'
     *  Lookup_n-D: '<S167>/Modulation_Str_X_Rel'
     *  Product: '<S167>/Product'
     */
    Code_Gen_Model_B.Steering_Rel_Cmd = look1_binlcpw
      (Code_Gen_Model_U.Steer_Joystick_Y,
       Code_Gen_Model_ConstP.Modulation_Str_X_Rel_bp01Data,
       Code_Gen_Model_ConstP.Modulation_Str_X_Rel_tableData, 20U) *
      Steering_Relative_Gain;

    /* SignalConversion generated from: '<S8>/Is_Absolute_Translation_In' incorporates:
     *  Inport: '<Root>/Is_Absolute_Translation'
     */
    rtb_Is_Absolute_Translation = Code_Gen_Model_U.Is_Absolute_Translation;

    /* SignalConversion generated from: '<S8>/Is_Absolute_Steering_In' incorporates:
     *  Inport: '<Root>/Is_Absolute_Steering'
     */
    rtb_Compare_m3 = Code_Gen_Model_U.Is_Absolute_Steering;

    /* Update for UnitDelay: '<S171>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_d2 = rtb_Subtract1_o;

    /* Update for UnitDelay: '<S171>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_g4 = rtb_Switch2;

    /* Update for UnitDelay: '<S170>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_h = rtb_Subtract1_o;

    /* Update for UnitDelay: '<S170>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_kr = rtb_uDLookupTable;

    /* Update for UnitDelay: '<S180>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_l = rtb_Init_e;

    /* Update for UnitDelay: '<S180>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_p = rtb_Switch2_o;

    /* Update for UnitDelay: '<S184>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S184>/FixPt Constant'
     */
    Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S184>/FixPt Unit Delay1' */
    Code_Gen_Model_DW.FixPtUnitDelay1_DSTATE_f = rtb_POSEexponentialmatrixfori_0;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    Code_Gen_Model_Disabled(&Code_Gen_Model_B.Gyro_Angle_Adjusted,
      &Code_Gen_Model_B.Steering_Abs_Cmd, &Code_Gen_Model_B.Steering_Rel_Cmd,
      &Code_Gen_Model_B.Translation_Angle, &Code_Gen_Model_B.Translation_Speed,
      &rtb_Is_Absolute_Translation, &rtb_Compare_m3);

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Signum: '<S114>/Sign2' incorporates:
   *  UnitDelay: '<S114>/Unit Delay'
   */
  if (rtIsNaN(Code_Gen_Model_B.Translation_Speed_o)) {
    rtb_Switch2_d = (rtNaN);
  } else if (Code_Gen_Model_B.Translation_Speed_o < 0.0) {
    rtb_Switch2_d = -1.0;
  } else {
    rtb_Switch2_d = Code_Gen_Model_B.Translation_Speed_o > 0.0;
  }

  /* Signum: '<S114>/Sign1' */
  if (rtIsNaN(Code_Gen_Model_B.Translation_Speed)) {
    rtb_Subtract_n = (rtNaN);
  } else if (Code_Gen_Model_B.Translation_Speed < 0.0) {
    rtb_Subtract_n = -1.0;
  } else {
    rtb_Subtract_n = Code_Gen_Model_B.Translation_Speed > 0.0;
  }

  /* Product: '<S114>/Product1' incorporates:
   *  Signum: '<S114>/Sign1'
   *  Signum: '<S114>/Sign2'
   */
  rtb_Switch2_d *= rtb_Subtract_n;
  if (rtIsNaN(rtb_Switch2_d)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Switch2_d, 256.0);
  }

  if (i < 0) {
    i = (int8_T)-(int8_T)(uint8_T)-(real_T)i;
  }

  /* Switch: '<S114>/Switch' incorporates:
   *  Constant: '<S114>/Constant'
   *  Constant: '<S119>/Constant'
   *  Constant: '<S120>/Constant'
   *  Logic: '<S114>/or'
   *  Product: '<S114>/Product1'
   *  RelationalOperator: '<S119>/Compare'
   *  RelationalOperator: '<S120>/Compare'
   *  UnitDelay: '<S114>/Unit Delay'
   */
  if (Code_Gen_Model_B.Translation_Speed_o == 0.0 || i > 0) {
    rtb_Switch2_d = Code_Gen_Model_B.Translation_Speed;
  } else {
    rtb_Switch2_d = 0.0;
  }

  /* End of Switch: '<S114>/Switch' */

  /* Switch: '<S125>/Init' incorporates:
   *  UnitDelay: '<S125>/FixPt Unit Delay1'
   *  UnitDelay: '<S125>/FixPt Unit Delay2'
   */
  if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Optimized_Module_Angle = rtb_Switch2_d;
  } else {
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.Translation_Speed_o;
  }

  /* End of Switch: '<S125>/Init' */

  /* RelationalOperator: '<S121>/Compare' incorporates:
   *  Constant: '<S121>/Constant'
   */
  rtb_Compare_o = rtb_Switch2_d == 0.0;

  /* RelationalOperator: '<S122>/Compare' incorporates:
   *  Constant: '<S122>/Constant'
   */
  rtb_Compare_lk = rtb_Switch2_d > 0.0;

  /* Abs: '<S114>/Abs' incorporates:
   *  Sum: '<S114>/Subtract'
   *  UnitDelay: '<S114>/Unit Delay'
   */
  rtb_POSEexponentialmatrixfori_0 = fabs(Code_Gen_Model_B.Translation_Speed_o -
    Code_Gen_Model_B.Translation_Speed);

  /* Switch: '<S114>/Switch1' incorporates:
   *  Constant: '<S114>/Constant1'
   *  Switch: '<S114>/Switch3'
   *  Switch: '<S114>/Switch5'
   *  UnaryMinus: '<S114>/Unary Minus'
   */
  if (rtb_Compare_o) {
    rtb_uDLookupTable = -Translation_Speed_Rate_Limit_Dec;

    /* SignalConversion generated from: '<S114>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S114>/Constant1'
     *  Constant: '<S114>/Constant4'
     *  Constant: '<S114>/Constant6'
     *  UnaryMinus: '<S114>/Unary Minus'
     */
    rtb_Product7[0] = Translation_Speed_Approach_Zero_Final_Thresh;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S114>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S114>/Constant2'
     *  Constant: '<S114>/Constant5'
     */
    rtb_TmpSignalConversionAtLook_o[0] = 0.0;
    rtb_TmpSignalConversionAtLook_o[1] =
      Translation_Speed_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S114>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S114>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_j), &rtb_Product7[0],
                         rtb_POSEexponentialmatrixfori_0,
                         &rtb_TmpSignalConversionAtLook_o[0], 1U);
    rtb_POSEexponentialmatrixfori_0 = rtb_LookupTableDynamic_j;
  } else {
    if (rtb_Compare_lk) {
      /* Switch: '<S114>/Switch3' incorporates:
       *  Constant: '<S114>/Constant3'
       */
      rtb_uDLookupTable = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_uDLookupTable = -Translation_Speed_Rate_Limit_Dec;
    }

    /* SignalConversion generated from: '<S114>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S114>/Constant1'
     *  Constant: '<S114>/Constant10'
     *  Constant: '<S114>/Constant8'
     *  UnaryMinus: '<S114>/Unary Minus'
     */
    rtb_Product7[0] = Translation_Speed_NonZero_Final_Scale_Factor;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S114>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S114>/Constant7'
     *  Constant: '<S114>/Constant9'
     */
    rtb_TmpSignalConversionAtLook_o[0] = 0.0;
    rtb_TmpSignalConversionAtLook_o[1] = Translation_Speed_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S114>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S114>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_i), &rtb_Product7[0],
                         rtb_POSEexponentialmatrixfori_0,
                         &rtb_TmpSignalConversionAtLook_o[0], 1U);
    rtb_POSEexponentialmatrixfori_0 = rtb_LookupTableDynamic1_i;
  }

  /* End of Switch: '<S114>/Switch1' */

  /* Product: '<S114>/Product' */
  rtb_uDLookupTable *= rtb_POSEexponentialmatrixfori_0;

  /* Sum: '<S123>/Sum1' */
  rtb_Subtract1_o = rtb_Switch2_d - rtb_Optimized_Module_Angle;

  /* Switch: '<S124>/Switch2' incorporates:
   *  RelationalOperator: '<S124>/LowerRelop1'
   */
  if (!(rtb_Subtract1_o > rtb_uDLookupTable)) {
    /* Switch: '<S114>/Switch2' incorporates:
     *  Constant: '<S114>/Constant1'
     *  Constant: '<S114>/Constant3'
     *  Switch: '<S114>/Switch4'
     *  UnaryMinus: '<S114>/Unary Minus1'
     */
    if (rtb_Compare_o) {
      rtb_Switch2_d = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_Compare_lk) {
      /* Switch: '<S114>/Switch4' incorporates:
       *  Constant: '<S114>/Constant1'
       */
      rtb_Switch2_d = Translation_Speed_Rate_Limit_Dec;
    } else {
      rtb_Switch2_d = -Translation_Speed_Rate_Limit_Inc;
    }

    /* Product: '<S114>/Product2' incorporates:
     *  Switch: '<S114>/Switch2'
     */
    rtb_Switch2 = rtb_Switch2_d * rtb_POSEexponentialmatrixfori_0;

    /* Switch: '<S124>/Switch' incorporates:
     *  RelationalOperator: '<S124>/UpperRelop'
     */
    if (rtb_Subtract1_o < rtb_Switch2) {
      rtb_uDLookupTable = rtb_Switch2;
    } else {
      rtb_uDLookupTable = rtb_Subtract1_o;
    }

    /* End of Switch: '<S124>/Switch' */
  }

  /* End of Switch: '<S124>/Switch2' */

  /* Sum: '<S123>/Sum' */
  Code_Gen_Model_B.Translation_Speed_o = rtb_uDLookupTable +
    rtb_Optimized_Module_Angle;

  /* Switch: '<S117>/Switch' */
  if (rtb_Is_Absolute_Translation) {
    /* Switch: '<S117>/Switch' incorporates:
     *  Constant: '<S141>/Constant3'
     *  Constant: '<S141>/Constant4'
     *  Math: '<S141>/Math Function'
     *  Sum: '<S117>/Subtract'
     *  Sum: '<S141>/Add1'
     *  Sum: '<S141>/Add2'
     */
    Code_Gen_Model_B.Translation_Steering_Cmd = rt_modd_snf
      (Code_Gen_Model_B.Translation_Angle - rtb_thetay + 3.1415926535897931,
       6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S117>/Switch' */
    Code_Gen_Model_B.Translation_Steering_Cmd =
      Code_Gen_Model_B.Translation_Angle;
  }

  /* End of Switch: '<S117>/Switch' */

  /* Sum: '<S137>/Add1' incorporates:
   *  Constant: '<S137>/Constant3'
   *  Constant: '<S137>/Constant4'
   *  Math: '<S137>/Math Function'
   *  Sum: '<S136>/Sum'
   *  Sum: '<S137>/Add2'
   */
  rtb_Optimized_Module_Angle = rt_modd_snf(Code_Gen_Model_B.Steering_Abs_Cmd -
    Code_Gen_Model_B.Gyro_Angle_Adjusted + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S139>/Sum1' incorporates:
   *  Constant: '<S136>/Constant2'
   *  Product: '<S139>/Product'
   *  Sum: '<S139>/Sum'
   *  UnitDelay: '<S139>/Unit Delay1'
   */
  rtb_POSEexponentialmatrixfori_0 = (rtb_Optimized_Module_Angle -
    Code_Gen_Model_DW.UnitDelay1_DSTATE) *
    Steering_Heading_Control_D_FilterCoeff + Code_Gen_Model_DW.UnitDelay1_DSTATE;

  /* Product: '<S136>/Product' incorporates:
   *  Constant: '<S136>/Constant3'
   */
  rtb_Subtract1_o = rtb_POSEexponentialmatrixfori_0 * Steering_Heading_Control_D;

  /* Sum: '<S138>/Diff' incorporates:
   *  UnitDelay: '<S138>/UD'
   *
   * Block description for '<S138>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S138>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_cc = rtb_Subtract1_o - Code_Gen_Model_DW.UD_DSTATE_a;

  /* Saturate: '<S136>/Saturation' */
  if (rtb_Add_cc > Steering_Heading_Control_D_UL) {
    rtb_Add_cc = Steering_Heading_Control_D_UL;
  } else if (rtb_Add_cc < Steering_Heading_Control_D_LL) {
    rtb_Add_cc = Steering_Heading_Control_D_LL;
  }

  /* Sum: '<S136>/Add' incorporates:
   *  Gain: '<S136>/Gain1'
   *  Saturate: '<S136>/Saturation'
   */
  rtb_Init_e = Steering_Heading_Control_P * rtb_Optimized_Module_Angle +
    rtb_Add_cc;

  /* Sum: '<S136>/Subtract' incorporates:
   *  Constant: '<S136>/Constant'
   */
  rtb_uDLookupTable = Steering_Heading_Control_Total_UL - rtb_Init_e;

  /* Sum: '<S136>/Sum2' incorporates:
   *  Gain: '<S136>/Gain2'
   *  UnitDelay: '<S136>/Unit Delay'
   */
  rtb_Switch2 = Steering_Heading_Control_I * rtb_Optimized_Module_Angle +
    Code_Gen_Model_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S140>/Switch2' incorporates:
   *  RelationalOperator: '<S140>/LowerRelop1'
   */
  if (!(rtb_Switch2 > rtb_uDLookupTable)) {
    /* Sum: '<S136>/Subtract1' incorporates:
     *  Constant: '<S136>/Constant1'
     */
    rtb_uDLookupTable = Steering_Heading_Control_Total_LL - rtb_Init_e;

    /* Switch: '<S140>/Switch' incorporates:
     *  RelationalOperator: '<S140>/UpperRelop'
     */
    if (!(rtb_Switch2 < rtb_uDLookupTable)) {
      rtb_uDLookupTable = rtb_Switch2;
    }

    /* End of Switch: '<S140>/Switch' */
  }

  /* End of Switch: '<S140>/Switch2' */

  /* Saturate: '<S136>/Saturation1' */
  if (rtb_uDLookupTable > Steering_Heading_Control_I_UL) {
    rtb_Switch2 = Steering_Heading_Control_I_UL;
  } else if (rtb_uDLookupTable < Steering_Heading_Control_I_LL) {
    rtb_Switch2 = Steering_Heading_Control_I_LL;
  } else {
    rtb_Switch2 = rtb_uDLookupTable;
  }

  /* End of Saturate: '<S136>/Saturation1' */

  /* Sum: '<S136>/Add1' */
  rtb_Add_cc = rtb_Init_e + rtb_Switch2;

  /* Saturate: '<S136>/Saturation2' */
  if (rtb_Add_cc > Steering_Heading_Control_Total_UL) {
    /* Saturate: '<S136>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = Steering_Heading_Control_Total_UL;
  } else if (rtb_Add_cc < Steering_Heading_Control_Total_LL) {
    /* Saturate: '<S136>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = Steering_Heading_Control_Total_LL;
  } else {
    /* Saturate: '<S136>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = rtb_Add_cc;
  }

  /* End of Saturate: '<S136>/Saturation2' */

  /* Switch: '<S116>/Switch' incorporates:
   *  Switch: '<S127>/Switch'
   */
  if (rtb_Compare_m3) {
    /* Switch: '<S127>/Switch' incorporates:
     *  Abs: '<S127>/Abs'
     *  Constant: '<S127>/Constant'
     *  Constant: '<S135>/Constant'
     *  RelationalOperator: '<S135>/Compare'
     */
    if (fabs(Code_Gen_Model_B.Steering_Localized_PID) >
        Steering_Heading_Control_Deadzone) {
      rtb_Optimized_Module_Angle = Code_Gen_Model_B.Steering_Localized_PID;
    } else {
      rtb_Optimized_Module_Angle = 0.0;
    }
  } else {
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.Steering_Rel_Cmd;
  }

  /* End of Switch: '<S116>/Switch' */

  /* UnitDelay: '<S126>/Unit Delay' */
  rtb_uDLookupTable = Code_Gen_Model_B.Steering_Localized_Cmd;

  /* Signum: '<S126>/Sign2' */
  if (rtIsNaN(rtb_uDLookupTable)) {
    rtb_Switch2_d = (rtNaN);
  } else if (rtb_uDLookupTable < 0.0) {
    rtb_Switch2_d = -1.0;
  } else {
    rtb_Switch2_d = rtb_uDLookupTable > 0.0;
  }

  /* Signum: '<S126>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle)) {
    rtb_Subtract_n = (rtNaN);
  } else if (rtb_Optimized_Module_Angle < 0.0) {
    rtb_Subtract_n = -1.0;
  } else {
    rtb_Subtract_n = rtb_Optimized_Module_Angle > 0.0;
  }

  /* Product: '<S126>/Product1' incorporates:
   *  Signum: '<S126>/Sign1'
   *  Signum: '<S126>/Sign2'
   */
  rtb_Switch2_d *= rtb_Subtract_n;
  if (rtIsNaN(rtb_Switch2_d)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Switch2_d, 256.0);
  }

  if (i < 0) {
    i = (int8_T)-(int8_T)(uint8_T)-(real_T)i;
  }

  /* Switch: '<S126>/Switch' incorporates:
   *  Constant: '<S126>/Constant'
   *  Constant: '<S128>/Constant'
   *  Constant: '<S129>/Constant'
   *  Logic: '<S126>/or'
   *  Product: '<S126>/Product1'
   *  RelationalOperator: '<S128>/Compare'
   *  RelationalOperator: '<S129>/Compare'
   */
  if (rtb_uDLookupTable == 0.0 || i > 0) {
    rtb_Magnitude = rtb_Optimized_Module_Angle;
  } else {
    rtb_Magnitude = 0.0;
  }

  /* End of Switch: '<S126>/Switch' */

  /* Switch: '<S134>/Init' incorporates:
   *  UnitDelay: '<S134>/FixPt Unit Delay1'
   *  UnitDelay: '<S134>/FixPt Unit Delay2'
   */
  if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Init_e = rtb_Magnitude;
  } else {
    rtb_Init_e = Code_Gen_Model_B.Steering_Localized_Cmd;
  }

  /* End of Switch: '<S134>/Init' */

  /* RelationalOperator: '<S130>/Compare' incorporates:
   *  Constant: '<S130>/Constant'
   */
  rtb_Is_Absolute_Translation = rtb_Magnitude == 0.0;

  /* RelationalOperator: '<S131>/Compare' incorporates:
   *  Constant: '<S131>/Constant'
   */
  rtb_Compare_m3 = rtb_Magnitude > 0.0;

  /* Abs: '<S126>/Abs' incorporates:
   *  Sum: '<S126>/Subtract'
   */
  rtb_uDLookupTable = fabs(rtb_uDLookupTable - rtb_Optimized_Module_Angle);

  /* Switch: '<S126>/Switch5' incorporates:
   *  Constant: '<S126>/Constant1'
   *  Switch: '<S126>/Switch1'
   *  UnaryMinus: '<S126>/Unary Minus'
   */
  if (rtb_Is_Absolute_Translation) {
    /* SignalConversion generated from: '<S126>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S126>/Constant4'
     *  Constant: '<S126>/Constant6'
     */
    rtb_Product7[0] = Steering_Localized_Cmd_Approach_Zero_Final_Thresh;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S126>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S126>/Constant2'
     *  Constant: '<S126>/Constant5'
     */
    rtb_TmpSignalConversionAtLook_o[0] = 0.0;
    rtb_TmpSignalConversionAtLook_o[1] =
      Steering_Localized_Cmd_Approach_Zero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S126>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S126>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic), &rtb_Product7[0],
                         rtb_uDLookupTable, &rtb_TmpSignalConversionAtLook_o[0],
                         1U);
    rtb_uDLookupTable = rtb_LookupTableDynamic;
    rtb_Switch2_d = -Steering_Localized_Cmd_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S126>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S126>/Constant10'
     *  Constant: '<S126>/Constant8'
     */
    rtb_Product7[0] = Steering_Localized_Cmd_NonZero_Final_Scale_Factor;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S126>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S126>/Constant7'
     *  Constant: '<S126>/Constant9'
     */
    rtb_TmpSignalConversionAtLook_o[0] = 0.0;
    rtb_TmpSignalConversionAtLook_o[1] =
      Steering_Localized_Cmd_NonZero_Error_Thresh;

    /* S-Function (sfix_look1_dyn): '<S126>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S126>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1), &rtb_Product7[0],
                         rtb_uDLookupTable, &rtb_TmpSignalConversionAtLook_o[0],
                         1U);
    rtb_uDLookupTable = rtb_LookupTableDynamic1;

    /* Switch: '<S126>/Switch3' incorporates:
     *  Constant: '<S126>/Constant1'
     *  Constant: '<S126>/Constant3'
     *  UnaryMinus: '<S126>/Unary Minus'
     */
    if (rtb_Compare_m3) {
      rtb_Switch2_d = Steering_Localized_Cmd_Rate_Limit_Inc;
    } else {
      rtb_Switch2_d = -Steering_Localized_Cmd_Rate_Limit_Dec;
    }

    /* End of Switch: '<S126>/Switch3' */
  }

  /* End of Switch: '<S126>/Switch5' */

  /* Product: '<S126>/Product' incorporates:
   *  Switch: '<S126>/Switch1'
   */
  rtb_Switch2_o = rtb_Switch2_d * rtb_uDLookupTable;

  /* Sum: '<S132>/Sum1' */
  rtb_Magnitude -= rtb_Init_e;

  /* Switch: '<S133>/Switch2' incorporates:
   *  RelationalOperator: '<S133>/LowerRelop1'
   */
  if (!(rtb_Magnitude > rtb_Switch2_o)) {
    /* Switch: '<S126>/Switch2' incorporates:
     *  Constant: '<S126>/Constant1'
     *  Constant: '<S126>/Constant3'
     *  Switch: '<S126>/Switch4'
     *  UnaryMinus: '<S126>/Unary Minus1'
     */
    if (rtb_Is_Absolute_Translation) {
      rtb_Switch2_d = Steering_Localized_Cmd_Rate_Limit_Dec;
    } else if (rtb_Compare_m3) {
      /* Switch: '<S126>/Switch4' incorporates:
       *  Constant: '<S126>/Constant1'
       */
      rtb_Switch2_d = Steering_Localized_Cmd_Rate_Limit_Dec;
    } else {
      rtb_Switch2_d = -Steering_Localized_Cmd_Rate_Limit_Inc;
    }

    /* Product: '<S126>/Product2' incorporates:
     *  Switch: '<S126>/Switch2'
     */
    rtb_Switch2_o = rtb_Switch2_d * rtb_uDLookupTable;

    /* Switch: '<S133>/Switch' incorporates:
     *  RelationalOperator: '<S133>/UpperRelop'
     */
    if (!(rtb_Magnitude < rtb_Switch2_o)) {
      rtb_Switch2_o = rtb_Magnitude;
    }

    /* End of Switch: '<S133>/Switch' */
  }

  /* End of Switch: '<S133>/Switch2' */

  /* Sum: '<S132>/Sum' */
  Code_Gen_Model_B.Steering_Localized_Cmd = rtb_Switch2_o + rtb_Init_e;

  /* Fcn: '<S148>/r->x' incorporates:
   *  Fcn: '<S153>/r->x'
   *  Fcn: '<S158>/r->x'
   *  Fcn: '<S163>/r->x'
   */
  rtb_Switch2_d = Code_Gen_Model_B.Translation_Speed_o * cos
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S142>/Add' incorporates:
   *  Fcn: '<S148>/r->x'
   *  Fcn: '<S149>/r->x'
   */
  rtb_Product7[0] = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.FL_Tangent_Angle) + rtb_Switch2_d;

  /* Fcn: '<S148>/theta->y' incorporates:
   *  Fcn: '<S153>/theta->y'
   *  Fcn: '<S158>/theta->y'
   *  Fcn: '<S163>/theta->y'
   */
  rtb_Total_Limited = Code_Gen_Model_B.Translation_Speed_o * sin
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S142>/Add' incorporates:
   *  Fcn: '<S148>/theta->y'
   *  Fcn: '<S149>/theta->y'
   */
  rtb_Product7[1] = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.FL_Tangent_Angle) + rtb_Total_Limited;

  /* Sum: '<S143>/Add' incorporates:
   *  Fcn: '<S154>/r->x'
   *  Fcn: '<S154>/theta->y'
   */
  rtb_TmpSignalConversionAtLook_o[0] = Code_Gen_Model_B.Steering_Localized_Cmd *
    cos(Code_Gen_Model_ConstB.FR_Tangent_Angle) + rtb_Switch2_d;
  rtb_TmpSignalConversionAtLook_o[1] = Code_Gen_Model_B.Steering_Localized_Cmd *
    sin(Code_Gen_Model_ConstB.FR_Tangent_Angle) + rtb_Total_Limited;

  /* Sum: '<S144>/Add' incorporates:
   *  Fcn: '<S159>/r->x'
   *  Fcn: '<S159>/theta->y'
   */
  rtb_Add_f_idx_0 = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.BL_Tangent_Angle) + rtb_Switch2_d;
  rtb_Add_f_idx_1 = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.BL_Tangent_Angle) + rtb_Total_Limited;

  /* Sum: '<S145>/Add' incorporates:
   *  Fcn: '<S164>/r->x'
   *  Fcn: '<S164>/theta->y'
   */
  rtb_Switch2_d += Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.BR_Tangent_Angle);
  rtb_Init_e = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.BR_Tangent_Angle) + rtb_Total_Limited;

  /* Fcn: '<S162>/x->r' */
  rtb_Total_Limited = rt_hypotd_snf(rtb_Switch2_d, rtb_Init_e);

  /* Switch: '<S161>/Switch1' incorporates:
   *  Constant: '<S165>/Constant'
   *  RelationalOperator: '<S165>/Compare'
   *  Switch: '<S161>/Switch'
   */
  if (rtb_Total_Limited == 0.0) {
    /* Switch: '<S161>/Switch1' incorporates:
     *  Constant: '<S161>/Constant'
     */
    Code_Gen_Model_B.BR_Desired_Wheel_Speed = 1.0E-15;
  } else {
    /* Switch: '<S161>/Switch1' */
    Code_Gen_Model_B.BR_Desired_Wheel_Speed = rtb_Total_Limited;

    /* Switch: '<S161>/Switch' incorporates:
     *  Fcn: '<S162>/x->theta'
     */
    Code_Gen_Model_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Init_e,
      rtb_Switch2_d);
  }

  /* End of Switch: '<S161>/Switch1' */

  /* Trigonometry: '<S106>/Cos4' incorporates:
   *  Switch: '<S95>/Angle_Switch'
   *  Trigonometry: '<S105>/Cos4'
   */
  rtb_Subtract_n = cos(Code_Gen_Model_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S106>/Sin5' incorporates:
   *  UnaryMinus: '<S104>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Code_Gen_Model_B.BR_Steer_Module_Angle);

  /* Trigonometry: '<S106>/Sin4' incorporates:
   *  Switch: '<S95>/Angle_Switch'
   *  Trigonometry: '<S105>/Sin4'
   */
  rtb_Product_nw = sin(Code_Gen_Model_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S106>/Cos5' incorporates:
   *  UnaryMinus: '<S104>/Unary Minus'
   */
  rtb_Switch2_d = cos(-Code_Gen_Model_B.BR_Steer_Module_Angle);

  /* Sum: '<S106>/Subtract1' incorporates:
   *  Product: '<S106>/Product2'
   *  Product: '<S106>/Product3'
   *  Trigonometry: '<S106>/Cos4'
   *  Trigonometry: '<S106>/Sin4'
   */
  rtb_uDLookupTable = rtb_Subtract_n * rtb_Optimized_Module_Angle +
    rtb_Product_nw * rtb_Switch2_d;

  /* Sum: '<S106>/Subtract' incorporates:
   *  Product: '<S106>/Product'
   *  Product: '<S106>/Product1'
   *  Trigonometry: '<S106>/Cos4'
   *  Trigonometry: '<S106>/Sin4'
   */
  rtb_Init_e = rtb_Subtract_n * rtb_Switch2_d - rtb_Product_nw *
    rtb_Optimized_Module_Angle;

  /* Math: '<S106>/Hypot' */
  rtb_Switch2_o = rt_hypotd_snf(rtb_Init_e, rtb_uDLookupTable);

  /* Switch: '<S106>/Switch' incorporates:
   *  Constant: '<S106>/Constant'
   *  Constant: '<S106>/Constant1'
   *  Constant: '<S107>/Constant'
   *  Product: '<S106>/Divide'
   *  Product: '<S106>/Divide1'
   *  RelationalOperator: '<S107>/Compare'
   *  Switch: '<S106>/Switch1'
   */
  if (rtb_Switch2_o > 1.0E-6) {
    rtb_Total_Limited = rtb_uDLookupTable / rtb_Switch2_o;
    rtb_Switch2_d = rtb_Init_e / rtb_Switch2_o;
  } else {
    rtb_Total_Limited = 0.0;
    rtb_Switch2_d = 1.0;
  }

  /* End of Switch: '<S106>/Switch' */

  /* Switch: '<S95>/Speed_Switch' incorporates:
   *  Abs: '<S95>/Abs'
   *  Constant: '<S103>/Constant'
   *  RelationalOperator: '<S103>/Compare'
   *  Switch: '<S95>/Angle_Switch'
   *  Trigonometry: '<S105>/Atan1'
   *  Trigonometry: '<S106>/Atan1'
   *  UnaryMinus: '<S95>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Total_Limited, rtb_Switch2_d)) > 1.5707963267948966)
  {
    rtb_Switch2_d = -Code_Gen_Model_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S105>/Subtract1' incorporates:
     *  Product: '<S105>/Product2'
     *  Product: '<S105>/Product3'
     *  UnaryMinus: '<S95>/Unary Minus'
     */
    rtb_uDLookupTable = rtb_Subtract_n * Code_Gen_Model_ConstB.Sin5_c +
      rtb_Product_nw * Code_Gen_Model_ConstB.Cos5_b;

    /* Sum: '<S105>/Subtract' incorporates:
     *  Product: '<S105>/Product'
     *  Product: '<S105>/Product1'
     */
    rtb_Switch2_o = rtb_Subtract_n * Code_Gen_Model_ConstB.Cos5_b -
      rtb_Product_nw * Code_Gen_Model_ConstB.Sin5_c;

    /* Math: '<S105>/Hypot' */
    rtb_Init_e = rt_hypotd_snf(rtb_Switch2_o, rtb_uDLookupTable);

    /* Switch: '<S105>/Switch1' incorporates:
     *  Constant: '<S105>/Constant'
     *  Constant: '<S105>/Constant1'
     *  Constant: '<S108>/Constant'
     *  Product: '<S105>/Divide'
     *  Product: '<S105>/Divide1'
     *  RelationalOperator: '<S108>/Compare'
     *  Switch: '<S105>/Switch'
     */
    if (rtb_Init_e > 1.0E-6) {
      rtb_Switch2_o /= rtb_Init_e;
      rtb_uDLookupTable /= rtb_Init_e;
    } else {
      rtb_Switch2_o = 1.0;
      rtb_uDLookupTable = 0.0;
    }

    /* End of Switch: '<S105>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_uDLookupTable, rtb_Switch2_o);
  } else {
    rtb_Switch2_d = Code_Gen_Model_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S98>/Product2' incorporates:
   *  Constant: '<S98>/Constant'
   *  Switch: '<S95>/Speed_Switch'
   */
  rtb_Total_Limited = rtb_Switch2_d * 1530.1401357649195;

  /* Signum: '<S93>/Sign' */
  if (rtIsNaN(rtb_Total_Limited)) {
    rtb_Switch2_d = (rtNaN);
  } else if (rtb_Total_Limited < 0.0) {
    rtb_Switch2_d = -1.0;
  } else {
    rtb_Switch2_d = rtb_Total_Limited > 0.0;
  }

  /* Signum: '<S93>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.BackRight_Drive_Motor_Speed)) {
    rtb_Subtract_n = (rtNaN);
  } else if (Code_Gen_Model_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Subtract_n = -1.0;
  } else {
    rtb_Subtract_n = Code_Gen_Model_U.BackRight_Drive_Motor_Speed > 0.0;
  }

  /* Sum: '<S96>/Add' incorporates:
   *  Sum: '<S97>/Sum'
   */
  rtb_Optimized_Module_Angle -= Code_Gen_Model_B.BR_Steer_Module_Angle;

  /* Product: '<S28>/Product' incorporates:
   *  Abs: '<S93>/Abs'
   *  Abs: '<S96>/Abs'
   *  Constant: '<S109>/Constant3'
   *  Constant: '<S109>/Constant4'
   *  Constant: '<S99>/Constant'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S93>/OR'
   *  Lookup_n-D: '<S96>/1-D Lookup Table'
   *  Math: '<S109>/Math Function'
   *  RelationalOperator: '<S93>/Equal1'
   *  RelationalOperator: '<S99>/Compare'
   *  Signum: '<S93>/Sign'
   *  Signum: '<S93>/Sign1'
   *  Sum: '<S109>/Add1'
   *  Sum: '<S109>/Add2'
   *  Sum: '<S96>/Add'
   */
  rtb_Total_Limited = (real_T)(rtb_Switch2_d == rtb_Subtract_n || fabs
    (Code_Gen_Model_U.BackRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband) * rtb_Total_Limited *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  Code_Gen_Model_ConstP.pooled14, Code_Gen_Model_ConstP.pooled13,
                  1U);

  /* Gain: '<S94>/Gain' */
  rtb_Switch2_o = Drive_Motor_Control_FF * rtb_Total_Limited;

  /* Sum: '<S94>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Total_Limited -= Code_Gen_Model_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S101>/Sum1' incorporates:
   *  Constant: '<S94>/Constant2'
   *  Product: '<S101>/Product'
   *  Sum: '<S101>/Sum'
   *  UnitDelay: '<S101>/Unit Delay1'
   */
  rtb_uDLookupTable = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_k)
    * Drive_Motor_Control_D_FilterCoeff + Code_Gen_Model_DW.UnitDelay1_DSTATE_k;

  /* Product: '<S94>/Product' incorporates:
   *  Constant: '<S94>/Constant3'
   */
  rtb_Init_e = rtb_uDLookupTable * Drive_Motor_Control_D;

  /* Sum: '<S100>/Diff' incorporates:
   *  UnitDelay: '<S100>/UD'
   *
   * Block description for '<S100>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S100>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_cc = rtb_Init_e - Code_Gen_Model_DW.UD_DSTATE_cs;

  /* Saturate: '<S94>/Saturation' */
  if (rtb_Add_cc > Drive_Motor_Control_D_UL) {
    rtb_Add_cc = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_cc < Drive_Motor_Control_D_LL) {
    rtb_Add_cc = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S94>/Add' incorporates:
   *  Gain: '<S94>/Gain1'
   *  Saturate: '<S94>/Saturation'
   */
  rtb_Magnitude = Drive_Motor_Control_P * rtb_Total_Limited + rtb_Switch2_o +
    rtb_Add_cc;

  /* Sum: '<S94>/Subtract' incorporates:
   *  Constant: '<S94>/Constant'
   */
  rtb_Switch2_d = 1.0 - rtb_Magnitude;

  /* Sum: '<S94>/Sum2' incorporates:
   *  Gain: '<S94>/Gain2'
   *  UnitDelay: '<S94>/Unit Delay'
   */
  rtb_Switch2_o = Drive_Motor_Control_I * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_a;

  /* Switch: '<S102>/Switch2' incorporates:
   *  Constant: '<S94>/Constant'
   *  RelationalOperator: '<S102>/LowerRelop1'
   *  Sum: '<S94>/Subtract'
   */
  if (!(rtb_Switch2_o > 1.0 - rtb_Magnitude)) {
    /* Switch: '<S102>/Switch' incorporates:
     *  Constant: '<S94>/Constant1'
     *  RelationalOperator: '<S102>/UpperRelop'
     *  Sum: '<S94>/Subtract1'
     */
    if (rtb_Switch2_o < -1.0 - rtb_Magnitude) {
      rtb_Switch2_d = -1.0 - rtb_Magnitude;
    } else {
      rtb_Switch2_d = rtb_Switch2_o;
    }

    /* End of Switch: '<S102>/Switch' */
  }

  /* End of Switch: '<S102>/Switch2' */

  /* Saturate: '<S94>/Saturation1' */
  if (rtb_Switch2_d > Drive_Motor_Control_I_UL) {
    rtb_Switch2_o = Drive_Motor_Control_I_UL;
  } else if (rtb_Switch2_d < Drive_Motor_Control_I_LL) {
    rtb_Switch2_o = Drive_Motor_Control_I_LL;
  } else {
    rtb_Switch2_o = rtb_Switch2_d;
  }

  /* End of Saturate: '<S94>/Saturation1' */

  /* Sum: '<S94>/Add1' */
  rtb_Add_cc = rtb_Magnitude + rtb_Switch2_o;

  /* Saturate: '<S94>/Saturation2' */
  if (rtb_Add_cc > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_cc < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = rtb_Add_cc;
  }

  /* End of Saturate: '<S94>/Saturation2' */

  /* Sum: '<S110>/Add1' incorporates:
   *  Constant: '<S110>/Constant3'
   *  Constant: '<S110>/Constant4'
   *  Math: '<S110>/Math Function'
   *  Sum: '<S110>/Add2'
   */
  rtb_Total_Limited = rt_modd_snf(rtb_Optimized_Module_Angle +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S112>/Sum1' incorporates:
   *  Constant: '<S97>/Constant2'
   *  Product: '<S112>/Product'
   *  Sum: '<S112>/Sum'
   *  UnitDelay: '<S112>/Unit Delay1'
   */
  rtb_Magnitude = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_i) *
    Steering_Motor_Control_D_FilterCoeff + Code_Gen_Model_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S97>/Product' incorporates:
   *  Constant: '<S97>/Constant3'
   */
  rtb_Steer_Joystick_X_Rel_Mod = rtb_Magnitude * Steering_Motor_Control_D;

  /* Sum: '<S111>/Diff' incorporates:
   *  UnitDelay: '<S111>/UD'
   *
   * Block description for '<S111>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S111>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_cc = rtb_Steer_Joystick_X_Rel_Mod - Code_Gen_Model_DW.UD_DSTATE_l;

  /* Saturate: '<S97>/Saturation' */
  if (rtb_Add_cc > Steering_Motor_Control_D_UL) {
    rtb_Add_cc = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_cc < Steering_Motor_Control_D_LL) {
    rtb_Add_cc = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S97>/Add' incorporates:
   *  Gain: '<S97>/Gain1'
   *  Saturate: '<S97>/Saturation'
   */
  rtb_Add_p = Steering_Motor_Control_P * rtb_Total_Limited + rtb_Add_cc;

  /* Sum: '<S97>/Subtract' incorporates:
   *  Constant: '<S97>/Constant'
   */
  rtb_Switch2_d = 1.0 - rtb_Add_p;

  /* Sum: '<S97>/Sum2' incorporates:
   *  Gain: '<S97>/Gain2'
   *  UnitDelay: '<S97>/Unit Delay'
   */
  rtb_Sum2_fc = Steering_Motor_Control_I * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_l;

  /* Switch: '<S113>/Switch2' incorporates:
   *  Constant: '<S97>/Constant'
   *  RelationalOperator: '<S113>/LowerRelop1'
   *  Sum: '<S97>/Subtract'
   */
  if (!(rtb_Sum2_fc > 1.0 - rtb_Add_p)) {
    /* Switch: '<S113>/Switch' incorporates:
     *  Constant: '<S97>/Constant1'
     *  RelationalOperator: '<S113>/UpperRelop'
     *  Sum: '<S97>/Subtract1'
     */
    if (rtb_Sum2_fc < -1.0 - rtb_Add_p) {
      rtb_Switch2_d = -1.0 - rtb_Add_p;
    } else {
      rtb_Switch2_d = rtb_Sum2_fc;
    }

    /* End of Switch: '<S113>/Switch' */
  }

  /* End of Switch: '<S113>/Switch2' */

  /* Saturate: '<S97>/Saturation1' */
  if (rtb_Switch2_d > Steering_Motor_Control_I_UL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_d < Steering_Motor_Control_I_LL) {
    rtb_Sum2_fc = Steering_Motor_Control_I_LL;
  } else {
    rtb_Sum2_fc = rtb_Switch2_d;
  }

  /* End of Saturate: '<S97>/Saturation1' */

  /* Sum: '<S97>/Add1' */
  rtb_Add_cc = rtb_Add_p + rtb_Sum2_fc;

  /* Saturate: '<S97>/Saturation2' */
  if (rtb_Add_cc > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_cc < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = rtb_Add_cc;
  }

  /* End of Saturate: '<S97>/Saturation2' */

  /* Fcn: '<S157>/x->r' */
  rtb_Total_Limited = rt_hypotd_snf(rtb_Add_f_idx_0, rtb_Add_f_idx_1);

  /* Switch: '<S156>/Switch1' incorporates:
   *  Constant: '<S160>/Constant'
   *  RelationalOperator: '<S160>/Compare'
   *  Switch: '<S156>/Switch'
   */
  if (rtb_Total_Limited == 0.0) {
    /* Switch: '<S156>/Switch1' incorporates:
     *  Constant: '<S156>/Constant'
     */
    Code_Gen_Model_B.BL_Desired_Wheel_Speed = 1.0E-15;
  } else {
    /* Switch: '<S156>/Switch1' */
    Code_Gen_Model_B.BL_Desired_Wheel_Speed = rtb_Total_Limited;

    /* Switch: '<S156>/Switch' incorporates:
     *  Fcn: '<S157>/x->theta'
     */
    Code_Gen_Model_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add_f_idx_1,
      rtb_Add_f_idx_0);
  }

  /* End of Switch: '<S156>/Switch1' */

  /* Trigonometry: '<S85>/Cos4' incorporates:
   *  Switch: '<S74>/Angle_Switch'
   *  Trigonometry: '<S84>/Cos4'
   */
  rtb_Subtract_n = cos(Code_Gen_Model_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S85>/Sin5' incorporates:
   *  UnaryMinus: '<S83>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Code_Gen_Model_B.BL_Steer_Module_Angle);

  /* Trigonometry: '<S85>/Sin4' incorporates:
   *  Switch: '<S74>/Angle_Switch'
   *  Trigonometry: '<S84>/Sin4'
   */
  rtb_Product_nw = sin(Code_Gen_Model_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S85>/Cos5' incorporates:
   *  UnaryMinus: '<S83>/Unary Minus'
   */
  rtb_Switch2_d = cos(-Code_Gen_Model_B.BL_Steer_Module_Angle);

  /* Sum: '<S85>/Subtract1' incorporates:
   *  Product: '<S85>/Product2'
   *  Product: '<S85>/Product3'
   *  Trigonometry: '<S85>/Cos4'
   *  Trigonometry: '<S85>/Sin4'
   */
  rtb_Total_Limited = rtb_Subtract_n * rtb_Optimized_Module_Angle +
    rtb_Product_nw * rtb_Switch2_d;

  /* Sum: '<S85>/Subtract' incorporates:
   *  Product: '<S85>/Product'
   *  Product: '<S85>/Product1'
   *  Trigonometry: '<S85>/Cos4'
   *  Trigonometry: '<S85>/Sin4'
   */
  rtb_Add_p = rtb_Subtract_n * rtb_Switch2_d - rtb_Product_nw *
    rtb_Optimized_Module_Angle;

  /* Math: '<S85>/Hypot' */
  rtb_Add_f_idx_0 = rt_hypotd_snf(rtb_Add_p, rtb_Total_Limited);

  /* Switch: '<S85>/Switch' incorporates:
   *  Constant: '<S85>/Constant'
   *  Constant: '<S85>/Constant1'
   *  Constant: '<S86>/Constant'
   *  Product: '<S85>/Divide'
   *  Product: '<S85>/Divide1'
   *  RelationalOperator: '<S86>/Compare'
   *  Switch: '<S85>/Switch1'
   */
  if (rtb_Add_f_idx_0 > 1.0E-6) {
    rtb_Total_Limited /= rtb_Add_f_idx_0;
    rtb_Switch2_d = rtb_Add_p / rtb_Add_f_idx_0;
  } else {
    rtb_Total_Limited = 0.0;
    rtb_Switch2_d = 1.0;
  }

  /* End of Switch: '<S85>/Switch' */

  /* Switch: '<S74>/Speed_Switch' incorporates:
   *  Abs: '<S74>/Abs'
   *  Constant: '<S82>/Constant'
   *  RelationalOperator: '<S82>/Compare'
   *  Switch: '<S74>/Angle_Switch'
   *  Trigonometry: '<S84>/Atan1'
   *  Trigonometry: '<S85>/Atan1'
   *  UnaryMinus: '<S74>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Total_Limited, rtb_Switch2_d)) > 1.5707963267948966)
  {
    rtb_Switch2_d = -Code_Gen_Model_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S84>/Subtract1' incorporates:
     *  Product: '<S84>/Product2'
     *  Product: '<S84>/Product3'
     *  UnaryMinus: '<S74>/Unary Minus'
     */
    rtb_Add_p = rtb_Subtract_n * Code_Gen_Model_ConstB.Sin5_e + rtb_Product_nw *
      Code_Gen_Model_ConstB.Cos5_i;

    /* Sum: '<S84>/Subtract' incorporates:
     *  Product: '<S84>/Product'
     *  Product: '<S84>/Product1'
     */
    rtb_Add_f_idx_1 = rtb_Subtract_n * Code_Gen_Model_ConstB.Cos5_i -
      rtb_Product_nw * Code_Gen_Model_ConstB.Sin5_e;

    /* Math: '<S84>/Hypot' */
    rtb_Add_f_idx_0 = rt_hypotd_snf(rtb_Add_f_idx_1, rtb_Add_p);

    /* Switch: '<S84>/Switch1' incorporates:
     *  Constant: '<S84>/Constant'
     *  Constant: '<S84>/Constant1'
     *  Constant: '<S87>/Constant'
     *  Product: '<S84>/Divide'
     *  Product: '<S84>/Divide1'
     *  RelationalOperator: '<S87>/Compare'
     *  Switch: '<S84>/Switch'
     */
    if (rtb_Add_f_idx_0 > 1.0E-6) {
      rtb_Add_f_idx_1 /= rtb_Add_f_idx_0;
      rtb_Add_p /= rtb_Add_f_idx_0;
    } else {
      rtb_Add_f_idx_1 = 1.0;
      rtb_Add_p = 0.0;
    }

    /* End of Switch: '<S84>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Add_p, rtb_Add_f_idx_1);
  } else {
    rtb_Switch2_d = Code_Gen_Model_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S77>/Product2' incorporates:
   *  Constant: '<S77>/Constant'
   *  Switch: '<S74>/Speed_Switch'
   */
  rtb_Total_Limited = rtb_Switch2_d * 1530.1401357649195;

  /* Signum: '<S72>/Sign' */
  if (rtIsNaN(rtb_Total_Limited)) {
    rtb_Switch2_d = (rtNaN);
  } else if (rtb_Total_Limited < 0.0) {
    rtb_Switch2_d = -1.0;
  } else {
    rtb_Switch2_d = rtb_Total_Limited > 0.0;
  }

  /* Signum: '<S72>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Subtract_n = (rtNaN);
  } else if (Code_Gen_Model_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Subtract_n = -1.0;
  } else {
    rtb_Subtract_n = Code_Gen_Model_U.BackLeft_Drive_Motor_Speed > 0.0;
  }

  /* Sum: '<S75>/Add' incorporates:
   *  Sum: '<S76>/Sum'
   */
  rtb_Optimized_Module_Angle -= Code_Gen_Model_B.BL_Steer_Module_Angle;

  /* Product: '<S27>/Product' incorporates:
   *  Abs: '<S72>/Abs'
   *  Abs: '<S75>/Abs'
   *  Constant: '<S78>/Constant'
   *  Constant: '<S88>/Constant3'
   *  Constant: '<S88>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S72>/OR'
   *  Lookup_n-D: '<S75>/1-D Lookup Table'
   *  Math: '<S88>/Math Function'
   *  RelationalOperator: '<S72>/Equal1'
   *  RelationalOperator: '<S78>/Compare'
   *  Signum: '<S72>/Sign'
   *  Signum: '<S72>/Sign1'
   *  Sum: '<S75>/Add'
   *  Sum: '<S88>/Add1'
   *  Sum: '<S88>/Add2'
   */
  rtb_Total_Limited = (real_T)(rtb_Switch2_d == rtb_Subtract_n || fabs
    (Code_Gen_Model_U.BackLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband) * rtb_Total_Limited *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  Code_Gen_Model_ConstP.pooled14, Code_Gen_Model_ConstP.pooled13,
                  1U);

  /* Gain: '<S73>/Gain' */
  rtb_Add_f_idx_1 = Drive_Motor_Control_FF * rtb_Total_Limited;

  /* Sum: '<S73>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Total_Limited -= Code_Gen_Model_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S80>/Sum1' incorporates:
   *  Constant: '<S73>/Constant2'
   *  Product: '<S80>/Product'
   *  Sum: '<S80>/Sum'
   *  UnitDelay: '<S80>/Unit Delay1'
   */
  rtb_Add_p = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_f) *
    Drive_Motor_Control_D_FilterCoeff + Code_Gen_Model_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S73>/Product' incorporates:
   *  Constant: '<S73>/Constant3'
   */
  rtb_Add_f_idx_0 = rtb_Add_p * Drive_Motor_Control_D;

  /* Sum: '<S79>/Diff' incorporates:
   *  UnitDelay: '<S79>/UD'
   *
   * Block description for '<S79>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S79>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_cc = rtb_Add_f_idx_0 - Code_Gen_Model_DW.UD_DSTATE_lh;

  /* Saturate: '<S73>/Saturation' */
  if (rtb_Add_cc > Drive_Motor_Control_D_UL) {
    rtb_Add_cc = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_cc < Drive_Motor_Control_D_LL) {
    rtb_Add_cc = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S73>/Add' incorporates:
   *  Gain: '<S73>/Gain1'
   *  Saturate: '<S73>/Saturation'
   */
  rtb_Add_lb = Drive_Motor_Control_P * rtb_Total_Limited + rtb_Add_f_idx_1 +
    rtb_Add_cc;

  /* Sum: '<S73>/Subtract' incorporates:
   *  Constant: '<S73>/Constant'
   */
  rtb_Switch2_d = 1.0 - rtb_Add_lb;

  /* Sum: '<S73>/Sum2' incorporates:
   *  Gain: '<S73>/Gain2'
   *  UnitDelay: '<S73>/Unit Delay'
   */
  rtb_Total_Limited = Drive_Motor_Control_I * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_gp;

  /* Switch: '<S81>/Switch2' incorporates:
   *  Constant: '<S73>/Constant'
   *  RelationalOperator: '<S81>/LowerRelop1'
   *  Sum: '<S73>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Add_lb)) {
    /* Switch: '<S81>/Switch' incorporates:
     *  Constant: '<S73>/Constant1'
     *  RelationalOperator: '<S81>/UpperRelop'
     *  Sum: '<S73>/Subtract1'
     */
    if (rtb_Total_Limited < -1.0 - rtb_Add_lb) {
      rtb_Switch2_d = -1.0 - rtb_Add_lb;
    } else {
      rtb_Switch2_d = rtb_Total_Limited;
    }

    /* End of Switch: '<S81>/Switch' */
  }

  /* End of Switch: '<S81>/Switch2' */

  /* Saturate: '<S73>/Saturation1' */
  if (rtb_Switch2_d > Drive_Motor_Control_I_UL) {
    rtb_Add_f_idx_1 = Drive_Motor_Control_I_UL;
  } else if (rtb_Switch2_d < Drive_Motor_Control_I_LL) {
    rtb_Add_f_idx_1 = Drive_Motor_Control_I_LL;
  } else {
    rtb_Add_f_idx_1 = rtb_Switch2_d;
  }

  /* End of Saturate: '<S73>/Saturation1' */

  /* Sum: '<S73>/Add1' */
  rtb_Add_cc = rtb_Add_lb + rtb_Add_f_idx_1;

  /* Saturate: '<S73>/Saturation2' */
  if (rtb_Add_cc > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_cc < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = rtb_Add_cc;
  }

  /* End of Saturate: '<S73>/Saturation2' */

  /* Sum: '<S89>/Add1' incorporates:
   *  Constant: '<S89>/Constant3'
   *  Constant: '<S89>/Constant4'
   *  Math: '<S89>/Math Function'
   *  Sum: '<S89>/Add2'
   */
  rtb_Total_Limited = rt_modd_snf(rtb_Optimized_Module_Angle +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S91>/Sum1' incorporates:
   *  Constant: '<S76>/Constant2'
   *  Product: '<S91>/Product'
   *  Sum: '<S91>/Sum'
   *  UnitDelay: '<S91>/Unit Delay1'
   */
  rtb_Add_lb = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_n) *
    Steering_Motor_Control_D_FilterCoeff + Code_Gen_Model_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S76>/Product' incorporates:
   *  Constant: '<S76>/Constant3'
   */
  rtb_Product_lf = rtb_Add_lb * Steering_Motor_Control_D;

  /* Sum: '<S90>/Diff' incorporates:
   *  UnitDelay: '<S90>/UD'
   *
   * Block description for '<S90>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S90>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_cc = rtb_Product_lf - Code_Gen_Model_DW.UD_DSTATE_k;

  /* Saturate: '<S76>/Saturation' */
  if (rtb_Add_cc > Steering_Motor_Control_D_UL) {
    rtb_Add_cc = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_cc < Steering_Motor_Control_D_LL) {
    rtb_Add_cc = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S76>/Add' incorporates:
   *  Gain: '<S76>/Gain1'
   *  Saturate: '<S76>/Saturation'
   */
  rtb_Optimized_Module_Angle = Steering_Motor_Control_P * rtb_Total_Limited +
    rtb_Add_cc;

  /* Sum: '<S76>/Subtract' incorporates:
   *  Constant: '<S76>/Constant'
   */
  rtb_Switch2_d = 1.0 - rtb_Optimized_Module_Angle;

  /* Sum: '<S76>/Sum2' incorporates:
   *  Gain: '<S76>/Gain2'
   *  UnitDelay: '<S76>/Unit Delay'
   */
  rtb_Total_Limited = Steering_Motor_Control_I * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S92>/Switch2' incorporates:
   *  Constant: '<S76>/Constant'
   *  RelationalOperator: '<S92>/LowerRelop1'
   *  Sum: '<S76>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Optimized_Module_Angle)) {
    /* Switch: '<S92>/Switch' incorporates:
     *  Constant: '<S76>/Constant1'
     *  RelationalOperator: '<S92>/UpperRelop'
     *  Sum: '<S76>/Subtract1'
     */
    if (rtb_Total_Limited < -1.0 - rtb_Optimized_Module_Angle) {
      rtb_Switch2_d = -1.0 - rtb_Optimized_Module_Angle;
    } else {
      rtb_Switch2_d = rtb_Total_Limited;
    }

    /* End of Switch: '<S92>/Switch' */
  }

  /* End of Switch: '<S92>/Switch2' */

  /* Saturate: '<S76>/Saturation1' */
  if (rtb_Switch2_d > Steering_Motor_Control_I_UL) {
    rtb_Subtract1_hh = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_d < Steering_Motor_Control_I_LL) {
    rtb_Subtract1_hh = Steering_Motor_Control_I_LL;
  } else {
    rtb_Subtract1_hh = rtb_Switch2_d;
  }

  /* End of Saturate: '<S76>/Saturation1' */

  /* Sum: '<S76>/Add1' */
  rtb_Add_cc = rtb_Optimized_Module_Angle + rtb_Subtract1_hh;

  /* Saturate: '<S76>/Saturation2' */
  if (rtb_Add_cc > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_cc < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = rtb_Add_cc;
  }

  /* End of Saturate: '<S76>/Saturation2' */

  /* Fcn: '<S152>/x->r' */
  rtb_Total_Limited = rt_hypotd_snf(rtb_TmpSignalConversionAtLook_o[0],
    rtb_TmpSignalConversionAtLook_o[1]);

  /* Switch: '<S151>/Switch1' incorporates:
   *  Constant: '<S155>/Constant'
   *  RelationalOperator: '<S155>/Compare'
   *  Switch: '<S151>/Switch'
   */
  if (rtb_Total_Limited == 0.0) {
    /* Switch: '<S151>/Switch1' incorporates:
     *  Constant: '<S151>/Constant'
     */
    Code_Gen_Model_B.FR_Desired_Wheel_Speed = 1.0E-15;
  } else {
    /* Switch: '<S151>/Switch1' */
    Code_Gen_Model_B.FR_Desired_Wheel_Speed = rtb_Total_Limited;

    /* Switch: '<S151>/Switch' incorporates:
     *  Fcn: '<S152>/x->theta'
     */
    Code_Gen_Model_B.FR_Desired_Module_Angle = rt_atan2d_snf
      (rtb_TmpSignalConversionAtLook_o[1], rtb_TmpSignalConversionAtLook_o[0]);
  }

  /* End of Switch: '<S151>/Switch1' */

  /* Trigonometry: '<S64>/Cos4' incorporates:
   *  Switch: '<S53>/Angle_Switch'
   *  Trigonometry: '<S63>/Cos4'
   */
  rtb_Subtract_n = cos(Code_Gen_Model_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S64>/Sin5' incorporates:
   *  UnaryMinus: '<S62>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Code_Gen_Model_B.FR_Steer_Module_Angle);

  /* Trigonometry: '<S64>/Sin4' incorporates:
   *  Switch: '<S53>/Angle_Switch'
   *  Trigonometry: '<S63>/Sin4'
   */
  rtb_Product_nw = sin(Code_Gen_Model_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S64>/Cos5' incorporates:
   *  UnaryMinus: '<S62>/Unary Minus'
   */
  rtb_Switch2_d = cos(-Code_Gen_Model_B.FR_Steer_Module_Angle);

  /* Sum: '<S64>/Subtract1' incorporates:
   *  Product: '<S64>/Product2'
   *  Product: '<S64>/Product3'
   *  Trigonometry: '<S64>/Cos4'
   *  Trigonometry: '<S64>/Sin4'
   */
  rtb_Total_Limited = rtb_Subtract_n * rtb_Optimized_Module_Angle +
    rtb_Product_nw * rtb_Switch2_d;

  /* Sum: '<S64>/Subtract' incorporates:
   *  Product: '<S64>/Product'
   *  Product: '<S64>/Product1'
   *  Trigonometry: '<S64>/Cos4'
   *  Trigonometry: '<S64>/Sin4'
   */
  rtb_Optimized_Module_Angle = rtb_Subtract_n * rtb_Switch2_d - rtb_Product_nw *
    rtb_Optimized_Module_Angle;

  /* Math: '<S64>/Hypot' */
  rtb_Switch2_d = rt_hypotd_snf(rtb_Optimized_Module_Angle, rtb_Total_Limited);

  /* Switch: '<S64>/Switch' incorporates:
   *  Constant: '<S64>/Constant'
   *  Constant: '<S64>/Constant1'
   *  Constant: '<S65>/Constant'
   *  Product: '<S64>/Divide'
   *  Product: '<S64>/Divide1'
   *  RelationalOperator: '<S65>/Compare'
   *  Switch: '<S64>/Switch1'
   */
  if (rtb_Switch2_d > 1.0E-6) {
    rtb_Total_Limited /= rtb_Switch2_d;
    rtb_Switch2_d = rtb_Optimized_Module_Angle / rtb_Switch2_d;
  } else {
    rtb_Total_Limited = 0.0;
    rtb_Switch2_d = 1.0;
  }

  /* End of Switch: '<S64>/Switch' */

  /* RelationalOperator: '<S61>/Compare' incorporates:
   *  Abs: '<S53>/Abs'
   *  Constant: '<S61>/Constant'
   *  Trigonometry: '<S64>/Atan1'
   */
  rtb_Compare_m3 = fabs(rt_atan2d_snf(rtb_Total_Limited, rtb_Switch2_d)) >
    1.5707963267948966;

  /* Switch: '<S53>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S53>/Unary Minus'
   */
  if (rtb_Compare_m3) {
    rtb_Switch2_d = -Code_Gen_Model_B.FR_Desired_Wheel_Speed;
  } else {
    rtb_Switch2_d = Code_Gen_Model_B.FR_Desired_Wheel_Speed;
  }

  /* Product: '<S56>/Product2' incorporates:
   *  Constant: '<S56>/Constant'
   *  Switch: '<S53>/Speed_Switch'
   */
  rtb_Total_Limited = rtb_Switch2_d * 1530.1401357649195;

  /* Switch: '<S53>/Angle_Switch' incorporates:
   *  Trigonometry: '<S63>/Atan1'
   */
  if (rtb_Compare_m3) {
    /* Sum: '<S63>/Subtract1' incorporates:
     *  Product: '<S63>/Product2'
     *  Product: '<S63>/Product3'
     */
    rtb_Optimized_Module_Angle = rtb_Subtract_n * Code_Gen_Model_ConstB.Sin5_m +
      rtb_Product_nw * Code_Gen_Model_ConstB.Cos5_g;

    /* Sum: '<S63>/Subtract' incorporates:
     *  Product: '<S63>/Product'
     *  Product: '<S63>/Product1'
     */
    rtb_Subtract_kb = rtb_Subtract_n * Code_Gen_Model_ConstB.Cos5_g -
      rtb_Product_nw * Code_Gen_Model_ConstB.Sin5_m;

    /* Math: '<S63>/Hypot' */
    rtb_Switch2_d = rt_hypotd_snf(rtb_Subtract_kb, rtb_Optimized_Module_Angle);

    /* Switch: '<S63>/Switch1' incorporates:
     *  Constant: '<S63>/Constant'
     *  Constant: '<S63>/Constant1'
     *  Constant: '<S66>/Constant'
     *  Product: '<S63>/Divide'
     *  Product: '<S63>/Divide1'
     *  RelationalOperator: '<S66>/Compare'
     *  Switch: '<S63>/Switch'
     */
    if (rtb_Switch2_d > 1.0E-6) {
      rtb_Subtract_kb /= rtb_Switch2_d;
      rtb_Optimized_Module_Angle /= rtb_Switch2_d;
    } else {
      rtb_Subtract_kb = 1.0;
      rtb_Optimized_Module_Angle = 0.0;
    }

    /* End of Switch: '<S63>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Optimized_Module_Angle,
      rtb_Subtract_kb);
  } else {
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.FR_Desired_Module_Angle;
  }

  /* Signum: '<S51>/Sign' */
  if (rtIsNaN(rtb_Total_Limited)) {
    rtb_Switch2_d = (rtNaN);
  } else if (rtb_Total_Limited < 0.0) {
    rtb_Switch2_d = -1.0;
  } else {
    rtb_Switch2_d = rtb_Total_Limited > 0.0;
  }

  /* Signum: '<S51>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Subtract_n = (rtNaN);
  } else if (Code_Gen_Model_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Subtract_n = -1.0;
  } else {
    rtb_Subtract_n = Code_Gen_Model_U.FrontRight_Drive_Motor_Speed > 0.0;
  }

  /* Sum: '<S54>/Add' incorporates:
   *  Sum: '<S55>/Sum'
   */
  rtb_Optimized_Module_Angle -= Code_Gen_Model_B.FR_Steer_Module_Angle;

  /* Product: '<S26>/Product' incorporates:
   *  Abs: '<S51>/Abs'
   *  Abs: '<S54>/Abs'
   *  Constant: '<S57>/Constant'
   *  Constant: '<S67>/Constant3'
   *  Constant: '<S67>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S51>/OR'
   *  Lookup_n-D: '<S54>/1-D Lookup Table'
   *  Math: '<S67>/Math Function'
   *  RelationalOperator: '<S51>/Equal1'
   *  RelationalOperator: '<S57>/Compare'
   *  Signum: '<S51>/Sign'
   *  Signum: '<S51>/Sign1'
   *  Sum: '<S54>/Add'
   *  Sum: '<S67>/Add1'
   *  Sum: '<S67>/Add2'
   */
  rtb_Total_Limited = (real_T)(rtb_Switch2_d == rtb_Subtract_n || fabs
    (Code_Gen_Model_U.FrontRight_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband) * rtb_Total_Limited *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  Code_Gen_Model_ConstP.pooled14, Code_Gen_Model_ConstP.pooled13,
                  1U);

  /* Gain: '<S52>/Gain' */
  rtb_Switch2_d = Drive_Motor_Control_FF * rtb_Total_Limited;

  /* Sum: '<S52>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Total_Limited -= Code_Gen_Model_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S59>/Sum1' incorporates:
   *  Constant: '<S52>/Constant2'
   *  Product: '<S59>/Product'
   *  Sum: '<S59>/Sum'
   *  UnitDelay: '<S59>/Unit Delay1'
   */
  rtb_Subtract_kb = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_b) *
    Drive_Motor_Control_D_FilterCoeff + Code_Gen_Model_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S52>/Product' incorporates:
   *  Constant: '<S52>/Constant3'
   */
  rtb_Product_n3 = rtb_Subtract_kb * Drive_Motor_Control_D;

  /* Sum: '<S58>/Diff' incorporates:
   *  UnitDelay: '<S58>/UD'
   *
   * Block description for '<S58>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S58>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_cc = rtb_Product_n3 - Code_Gen_Model_DW.UD_DSTATE_e;

  /* Saturate: '<S52>/Saturation' */
  if (rtb_Add_cc > Drive_Motor_Control_D_UL) {
    rtb_Add_cc = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_cc < Drive_Motor_Control_D_LL) {
    rtb_Add_cc = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S52>/Add' incorporates:
   *  Gain: '<S52>/Gain1'
   *  Saturate: '<S52>/Saturation'
   */
  rtb_Add_k = Drive_Motor_Control_P * rtb_Total_Limited + rtb_Switch2_d +
    rtb_Add_cc;

  /* Sum: '<S52>/Subtract' incorporates:
   *  Constant: '<S52>/Constant'
   */
  rtb_Switch2_d = 1.0 - rtb_Add_k;

  /* Sum: '<S52>/Sum2' incorporates:
   *  Gain: '<S52>/Gain2'
   *  UnitDelay: '<S52>/Unit Delay'
   */
  rtb_Total_Limited = Drive_Motor_Control_I * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S60>/Switch2' incorporates:
   *  Constant: '<S52>/Constant'
   *  RelationalOperator: '<S60>/LowerRelop1'
   *  Sum: '<S52>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Add_k)) {
    /* Sum: '<S52>/Subtract1' incorporates:
     *  Constant: '<S52>/Constant1'
     */
    rtb_Switch2_d = -1.0 - rtb_Add_k;

    /* Switch: '<S60>/Switch' incorporates:
     *  Constant: '<S52>/Constant1'
     *  RelationalOperator: '<S60>/UpperRelop'
     *  Sum: '<S52>/Subtract1'
     */
    if (!(rtb_Total_Limited < -1.0 - rtb_Add_k)) {
      rtb_Switch2_d = rtb_Total_Limited;
    }

    /* End of Switch: '<S60>/Switch' */
  }

  /* End of Switch: '<S60>/Switch2' */

  /* Saturate: '<S52>/Saturation1' */
  if (rtb_Switch2_d > Drive_Motor_Control_I_UL) {
    rtb_Integral_i = Drive_Motor_Control_I_UL;
  } else if (rtb_Switch2_d < Drive_Motor_Control_I_LL) {
    rtb_Integral_i = Drive_Motor_Control_I_LL;
  } else {
    rtb_Integral_i = rtb_Switch2_d;
  }

  /* End of Saturate: '<S52>/Saturation1' */

  /* Sum: '<S52>/Add1' */
  rtb_Add_cc = rtb_Add_k + rtb_Integral_i;

  /* Saturate: '<S52>/Saturation2' */
  if (rtb_Add_cc > 1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_cc < -1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = rtb_Add_cc;
  }

  /* End of Saturate: '<S52>/Saturation2' */

  /* Sum: '<S68>/Add1' incorporates:
   *  Constant: '<S68>/Constant3'
   *  Constant: '<S68>/Constant4'
   *  Math: '<S68>/Math Function'
   *  Sum: '<S68>/Add2'
   */
  rtb_Total_Limited = rt_modd_snf(rtb_Optimized_Module_Angle +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S70>/Sum1' incorporates:
   *  Constant: '<S55>/Constant2'
   *  Product: '<S70>/Product'
   *  Sum: '<S70>/Sum'
   *  UnitDelay: '<S70>/Unit Delay1'
   */
  rtb_Add_k = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_na) *
    Steering_Motor_Control_D_FilterCoeff +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_na;

  /* Product: '<S55>/Product' incorporates:
   *  Constant: '<S55>/Constant3'
   */
  rtb_Product_go = rtb_Add_k * Steering_Motor_Control_D;

  /* Sum: '<S69>/Diff' incorporates:
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
  rtb_Add_cc = rtb_Product_go - Code_Gen_Model_DW.UD_DSTATE_i1;

  /* Saturate: '<S55>/Saturation' */
  if (rtb_Add_cc > Steering_Motor_Control_D_UL) {
    rtb_Add_cc = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_cc < Steering_Motor_Control_D_LL) {
    rtb_Add_cc = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S55>/Add' incorporates:
   *  Gain: '<S55>/Gain1'
   *  Saturate: '<S55>/Saturation'
   */
  rtb_Optimized_Module_Angle = Steering_Motor_Control_P * rtb_Total_Limited +
    rtb_Add_cc;

  /* Sum: '<S55>/Subtract' incorporates:
   *  Constant: '<S55>/Constant'
   */
  rtb_Switch2_d = 1.0 - rtb_Optimized_Module_Angle;

  /* Sum: '<S55>/Sum2' incorporates:
   *  Gain: '<S55>/Gain2'
   *  UnitDelay: '<S55>/Unit Delay'
   */
  rtb_Total_Limited = Steering_Motor_Control_I * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S71>/Switch2' incorporates:
   *  Constant: '<S55>/Constant'
   *  RelationalOperator: '<S71>/LowerRelop1'
   *  Sum: '<S55>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Optimized_Module_Angle)) {
    /* Sum: '<S55>/Subtract1' incorporates:
     *  Constant: '<S55>/Constant1'
     */
    rtb_Switch2_d = -1.0 - rtb_Optimized_Module_Angle;

    /* Switch: '<S71>/Switch' incorporates:
     *  Constant: '<S55>/Constant1'
     *  RelationalOperator: '<S71>/UpperRelop'
     *  Sum: '<S55>/Subtract1'
     */
    if (!(rtb_Total_Limited < -1.0 - rtb_Optimized_Module_Angle)) {
      rtb_Switch2_d = rtb_Total_Limited;
    }

    /* End of Switch: '<S71>/Switch' */
  }

  /* End of Switch: '<S71>/Switch2' */

  /* Saturate: '<S55>/Saturation1' */
  if (rtb_Switch2_d > Steering_Motor_Control_I_UL) {
    rtb_Integral_je = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_d < Steering_Motor_Control_I_LL) {
    rtb_Integral_je = Steering_Motor_Control_I_LL;
  } else {
    rtb_Integral_je = rtb_Switch2_d;
  }

  /* End of Saturate: '<S55>/Saturation1' */

  /* Sum: '<S55>/Add1' */
  rtb_Add_cc = rtb_Optimized_Module_Angle + rtb_Integral_je;

  /* Saturate: '<S55>/Saturation2' */
  if (rtb_Add_cc > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_cc < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = rtb_Add_cc;
  }

  /* End of Saturate: '<S55>/Saturation2' */

  /* Fcn: '<S147>/x->r' */
  rtb_Total_Limited = rt_hypotd_snf(rtb_Product7[0], rtb_Product7[1]);

  /* Switch: '<S146>/Switch1' incorporates:
   *  Constant: '<S150>/Constant'
   *  RelationalOperator: '<S150>/Compare'
   *  Switch: '<S146>/Switch'
   */
  if (rtb_Total_Limited == 0.0) {
    /* Switch: '<S146>/Switch1' incorporates:
     *  Constant: '<S146>/Constant'
     */
    Code_Gen_Model_B.FL_Desired_Wheel_Speed = 1.0E-15;
  } else {
    /* Switch: '<S146>/Switch1' */
    Code_Gen_Model_B.FL_Desired_Wheel_Speed = rtb_Total_Limited;

    /* Switch: '<S146>/Switch' incorporates:
     *  Fcn: '<S147>/x->theta'
     */
    Code_Gen_Model_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Product7[1],
      rtb_Product7[0]);
  }

  /* End of Switch: '<S146>/Switch1' */

  /* Trigonometry: '<S43>/Cos4' incorporates:
   *  Switch: '<S32>/Angle_Switch'
   *  Trigonometry: '<S42>/Cos4'
   */
  rtb_Subtract_n = cos(Code_Gen_Model_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S43>/Sin5' incorporates:
   *  UnaryMinus: '<S41>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Code_Gen_Model_B.FL_Steer_Module_Angle);

  /* Trigonometry: '<S43>/Sin4' incorporates:
   *  Switch: '<S32>/Angle_Switch'
   *  Trigonometry: '<S42>/Sin4'
   */
  rtb_Product_nw = sin(Code_Gen_Model_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S43>/Cos5' incorporates:
   *  UnaryMinus: '<S41>/Unary Minus'
   */
  rtb_Switch2_d = cos(-Code_Gen_Model_B.FL_Steer_Module_Angle);

  /* Sum: '<S43>/Subtract1' incorporates:
   *  Product: '<S43>/Product2'
   *  Product: '<S43>/Product3'
   *  Trigonometry: '<S43>/Cos4'
   *  Trigonometry: '<S43>/Sin4'
   */
  rtb_Total_Limited = rtb_Subtract_n * rtb_Optimized_Module_Angle +
    rtb_Product_nw * rtb_Switch2_d;

  /* Sum: '<S43>/Subtract' incorporates:
   *  Product: '<S43>/Product'
   *  Product: '<S43>/Product1'
   *  Trigonometry: '<S43>/Cos4'
   *  Trigonometry: '<S43>/Sin4'
   */
  rtb_Optimized_Module_Angle = rtb_Subtract_n * rtb_Switch2_d - rtb_Product_nw *
    rtb_Optimized_Module_Angle;

  /* Math: '<S43>/Hypot' */
  rtb_Switch2_d = rt_hypotd_snf(rtb_Optimized_Module_Angle, rtb_Total_Limited);

  /* Switch: '<S43>/Switch' incorporates:
   *  Constant: '<S43>/Constant'
   *  Constant: '<S43>/Constant1'
   *  Constant: '<S44>/Constant'
   *  Product: '<S43>/Divide'
   *  Product: '<S43>/Divide1'
   *  RelationalOperator: '<S44>/Compare'
   *  Switch: '<S43>/Switch1'
   */
  if (rtb_Switch2_d > 1.0E-6) {
    rtb_Total_Limited /= rtb_Switch2_d;
    rtb_Switch2_d = rtb_Optimized_Module_Angle / rtb_Switch2_d;
  } else {
    rtb_Total_Limited = 0.0;
    rtb_Switch2_d = 1.0;
  }

  /* End of Switch: '<S43>/Switch' */

  /* RelationalOperator: '<S40>/Compare' incorporates:
   *  Abs: '<S32>/Abs'
   *  Constant: '<S40>/Constant'
   *  Trigonometry: '<S43>/Atan1'
   */
  rtb_Compare_m3 = fabs(rt_atan2d_snf(rtb_Total_Limited, rtb_Switch2_d)) >
    1.5707963267948966;

  /* Switch: '<S32>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S32>/Unary Minus'
   */
  if (rtb_Compare_m3) {
    rtb_Switch2_d = -Code_Gen_Model_B.FL_Desired_Wheel_Speed;
  } else {
    rtb_Switch2_d = Code_Gen_Model_B.FL_Desired_Wheel_Speed;
  }

  /* Product: '<S35>/Product2' incorporates:
   *  Constant: '<S35>/Constant'
   *  Switch: '<S32>/Speed_Switch'
   */
  rtb_Total_Limited = rtb_Switch2_d * 1530.1401357649195;

  /* Switch: '<S32>/Angle_Switch' incorporates:
   *  Trigonometry: '<S42>/Atan1'
   */
  if (rtb_Compare_m3) {
    /* Sum: '<S42>/Subtract1' incorporates:
     *  Product: '<S42>/Product2'
     *  Product: '<S42>/Product3'
     */
    rtb_Optimized_Module_Angle = rtb_Subtract_n * Code_Gen_Model_ConstB.Sin5 +
      rtb_Product_nw * Code_Gen_Model_ConstB.Cos5;

    /* Sum: '<S42>/Subtract' incorporates:
     *  Product: '<S42>/Product'
     *  Product: '<S42>/Product1'
     */
    rtb_Subtract_n = rtb_Subtract_n * Code_Gen_Model_ConstB.Cos5 -
      rtb_Product_nw * Code_Gen_Model_ConstB.Sin5;

    /* Math: '<S42>/Hypot' */
    rtb_Switch2_d = rt_hypotd_snf(rtb_Subtract_n, rtb_Optimized_Module_Angle);

    /* Switch: '<S42>/Switch1' incorporates:
     *  Constant: '<S42>/Constant'
     *  Constant: '<S42>/Constant1'
     *  Constant: '<S45>/Constant'
     *  Product: '<S42>/Divide'
     *  Product: '<S42>/Divide1'
     *  RelationalOperator: '<S45>/Compare'
     *  Switch: '<S42>/Switch'
     */
    if (rtb_Switch2_d > 1.0E-6) {
      rtb_Subtract_n /= rtb_Switch2_d;
      rtb_Optimized_Module_Angle /= rtb_Switch2_d;
    } else {
      rtb_Subtract_n = 1.0;
      rtb_Optimized_Module_Angle = 0.0;
    }

    /* End of Switch: '<S42>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Optimized_Module_Angle,
      rtb_Subtract_n);
  } else {
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.FL_Desired_Module_Angle;
  }

  /* Signum: '<S30>/Sign' */
  if (rtIsNaN(rtb_Total_Limited)) {
    rtb_Switch2_d = (rtNaN);
  } else if (rtb_Total_Limited < 0.0) {
    rtb_Switch2_d = -1.0;
  } else {
    rtb_Switch2_d = rtb_Total_Limited > 0.0;
  }

  /* Signum: '<S30>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Subtract_n = (rtNaN);
  } else if (Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Subtract_n = -1.0;
  } else {
    rtb_Subtract_n = Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed > 0.0;
  }

  /* Sum: '<S33>/Add' incorporates:
   *  Sum: '<S34>/Sum'
   */
  rtb_Optimized_Module_Angle -= Code_Gen_Model_B.FL_Steer_Module_Angle;

  /* Product: '<S25>/Product' incorporates:
   *  Abs: '<S30>/Abs'
   *  Abs: '<S33>/Abs'
   *  Constant: '<S36>/Constant'
   *  Constant: '<S46>/Constant3'
   *  Constant: '<S46>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S30>/OR'
   *  Lookup_n-D: '<S33>/1-D Lookup Table'
   *  Math: '<S46>/Math Function'
   *  RelationalOperator: '<S30>/Equal1'
   *  RelationalOperator: '<S36>/Compare'
   *  Signum: '<S30>/Sign'
   *  Signum: '<S30>/Sign1'
   *  Sum: '<S33>/Add'
   *  Sum: '<S46>/Add1'
   *  Sum: '<S46>/Add2'
   */
  rtb_Total_Limited = (real_T)(rtb_Switch2_d == rtb_Subtract_n || fabs
    (Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed) <=
    Drive_Motor_Control_Sign_Change_Deadband) * rtb_Total_Limited *
    look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                  Code_Gen_Model_ConstP.pooled14, Code_Gen_Model_ConstP.pooled13,
                  1U);

  /* Gain: '<S31>/Gain' */
  rtb_Switch2_d = Drive_Motor_Control_FF * rtb_Total_Limited;

  /* Sum: '<S31>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Total_Limited -= Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S38>/Sum1' incorporates:
   *  Constant: '<S31>/Constant2'
   *  Product: '<S38>/Product'
   *  Sum: '<S38>/Sum'
   *  UnitDelay: '<S38>/Unit Delay1'
   */
  rtb_Subtract_n = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_a) *
    Drive_Motor_Control_D_FilterCoeff + Code_Gen_Model_DW.UnitDelay1_DSTATE_a;

  /* Product: '<S31>/Product' incorporates:
   *  Constant: '<S31>/Constant3'
   */
  rtb_Product_nw = rtb_Subtract_n * Drive_Motor_Control_D;

  /* Sum: '<S37>/Diff' incorporates:
   *  UnitDelay: '<S37>/UD'
   *
   * Block description for '<S37>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S37>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_cc = rtb_Product_nw - Code_Gen_Model_DW.UD_DSTATE_o;

  /* Saturate: '<S31>/Saturation' */
  if (rtb_Add_cc > Drive_Motor_Control_D_UL) {
    rtb_Add_cc = Drive_Motor_Control_D_UL;
  } else if (rtb_Add_cc < Drive_Motor_Control_D_LL) {
    rtb_Add_cc = Drive_Motor_Control_D_LL;
  }

  /* Sum: '<S31>/Add' incorporates:
   *  Gain: '<S31>/Gain1'
   *  Saturate: '<S31>/Saturation'
   */
  rtb_Add_ia = Drive_Motor_Control_P * rtb_Total_Limited + rtb_Switch2_d +
    rtb_Add_cc;

  /* Sum: '<S31>/Subtract' incorporates:
   *  Constant: '<S31>/Constant'
   */
  rtb_Switch2_d = 1.0 - rtb_Add_ia;

  /* Sum: '<S31>/Sum2' incorporates:
   *  Gain: '<S31>/Gain2'
   *  UnitDelay: '<S31>/Unit Delay'
   */
  rtb_Total_Limited = Drive_Motor_Control_I * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_f;

  /* Switch: '<S39>/Switch2' incorporates:
   *  Constant: '<S31>/Constant'
   *  RelationalOperator: '<S39>/LowerRelop1'
   *  Sum: '<S31>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Add_ia)) {
    /* Sum: '<S31>/Subtract1' incorporates:
     *  Constant: '<S31>/Constant1'
     */
    rtb_Switch2_d = -1.0 - rtb_Add_ia;

    /* Switch: '<S39>/Switch' incorporates:
     *  Constant: '<S31>/Constant1'
     *  RelationalOperator: '<S39>/UpperRelop'
     *  Sum: '<S31>/Subtract1'
     */
    if (!(rtb_Total_Limited < -1.0 - rtb_Add_ia)) {
      rtb_Switch2_d = rtb_Total_Limited;
    }

    /* End of Switch: '<S39>/Switch' */
  }

  /* End of Switch: '<S39>/Switch2' */

  /* Saturate: '<S31>/Saturation1' */
  if (rtb_Switch2_d > Drive_Motor_Control_I_UL) {
    rtb_Integral_da = Drive_Motor_Control_I_UL;
  } else if (rtb_Switch2_d < Drive_Motor_Control_I_LL) {
    rtb_Integral_da = Drive_Motor_Control_I_LL;
  } else {
    rtb_Integral_da = rtb_Switch2_d;
  }

  /* End of Saturate: '<S31>/Saturation1' */

  /* Sum: '<S31>/Add1' */
  rtb_Add_cc = rtb_Add_ia + rtb_Integral_da;

  /* Saturate: '<S31>/Saturation2' */
  if (rtb_Add_cc > 1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_cc < -1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = rtb_Add_cc;
  }

  /* End of Saturate: '<S31>/Saturation2' */

  /* Sum: '<S47>/Add1' incorporates:
   *  Constant: '<S47>/Constant3'
   *  Constant: '<S47>/Constant4'
   *  Math: '<S47>/Math Function'
   *  Sum: '<S47>/Add2'
   */
  rtb_Total_Limited = rt_modd_snf(rtb_Optimized_Module_Angle +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S49>/Sum1' incorporates:
   *  Constant: '<S34>/Constant2'
   *  Product: '<S49>/Product'
   *  Sum: '<S49>/Sum'
   *  UnitDelay: '<S49>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = (rtb_Total_Limited -
    Code_Gen_Model_DW.UnitDelay1_DSTATE_bk) *
    Steering_Motor_Control_D_FilterCoeff +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_bk;

  /* Product: '<S34>/Product' incorporates:
   *  Constant: '<S34>/Constant3'
   */
  rtb_Add_ia = rtb_Optimized_Module_Angle * Steering_Motor_Control_D;

  /* Sum: '<S48>/Diff' incorporates:
   *  UnitDelay: '<S48>/UD'
   *
   * Block description for '<S48>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S48>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_cc = rtb_Add_ia - Code_Gen_Model_DW.UD_DSTATE_b;

  /* Saturate: '<S34>/Saturation' */
  if (rtb_Add_cc > Steering_Motor_Control_D_UL) {
    rtb_Add_cc = Steering_Motor_Control_D_UL;
  } else if (rtb_Add_cc < Steering_Motor_Control_D_LL) {
    rtb_Add_cc = Steering_Motor_Control_D_LL;
  }

  /* Sum: '<S34>/Add' incorporates:
   *  Gain: '<S34>/Gain1'
   *  Saturate: '<S34>/Saturation'
   */
  rtb_Add_cc += Steering_Motor_Control_P * rtb_Total_Limited;

  /* Sum: '<S34>/Subtract' incorporates:
   *  Constant: '<S34>/Constant'
   */
  rtb_Switch2_d = 1.0 - rtb_Add_cc;

  /* Sum: '<S34>/Sum2' incorporates:
   *  Gain: '<S34>/Gain2'
   *  UnitDelay: '<S34>/Unit Delay'
   */
  rtb_Total_Limited = Steering_Motor_Control_I * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_em;

  /* Switch: '<S50>/Switch2' incorporates:
   *  Constant: '<S34>/Constant'
   *  RelationalOperator: '<S50>/LowerRelop1'
   *  Sum: '<S34>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Add_cc)) {
    /* Sum: '<S34>/Subtract1' incorporates:
     *  Constant: '<S34>/Constant1'
     */
    rtb_Switch2_d = -1.0 - rtb_Add_cc;

    /* Switch: '<S50>/Switch' incorporates:
     *  Constant: '<S34>/Constant1'
     *  RelationalOperator: '<S50>/UpperRelop'
     *  Sum: '<S34>/Subtract1'
     */
    if (!(rtb_Total_Limited < -1.0 - rtb_Add_cc)) {
      rtb_Switch2_d = rtb_Total_Limited;
    }

    /* End of Switch: '<S50>/Switch' */
  }

  /* End of Switch: '<S50>/Switch2' */

  /* Saturate: '<S34>/Saturation1' */
  if (rtb_Switch2_d > Steering_Motor_Control_I_UL) {
    rtb_Total_Limited = Steering_Motor_Control_I_UL;
  } else if (rtb_Switch2_d < Steering_Motor_Control_I_LL) {
    rtb_Total_Limited = Steering_Motor_Control_I_LL;
  } else {
    rtb_Total_Limited = rtb_Switch2_d;
  }

  /* End of Saturate: '<S34>/Saturation1' */

  /* Sum: '<S34>/Add1' */
  rtb_Add_cc += rtb_Total_Limited;

  /* Saturate: '<S34>/Saturation2' */
  if (rtb_Add_cc > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_cc < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = rtb_Add_cc;
  }

  /* End of Saturate: '<S34>/Saturation2' */

  /* Gain: '<S19>/meters to feet1' */
  Code_Gen_Model_B.Odometry_Y_global_est_ft = 3.28084 *
    Code_Gen_Model_B.Odometry_Y_global_est_m;

  /* RelationalOperator: '<S20>/Compare' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S20>/Constant'
   */
  rtb_Compare_m3 = Odometry_X_Y_TEAR != 0.0;

  /* Switch: '<S19>/Switch1' incorporates:
   *  UnitDelay: '<S19>/Unit Delay1'
   */
  if (rtb_Compare_m3) {
    rtb_Switch2_d = Code_Gen_Model_B.Odometry_Y_global_est_ft;
  } else {
    rtb_Switch2_d = Code_Gen_Model_DW.UnitDelay1_DSTATE_d;
  }

  /* End of Switch: '<S19>/Switch1' */

  /* Sum: '<S19>/Subtract1' */
  Code_Gen_Model_B.Odometry_Y_global_TEAR_ft =
    Code_Gen_Model_B.Odometry_Y_global_est_ft - rtb_Switch2_d;

  /* Gain: '<S19>/meters to feet' */
  Code_Gen_Model_B.Odometry_X_global_est_ft = 3.28084 *
    Code_Gen_Model_B.Odometry_X_global_est_m;

  /* Switch: '<S19>/Switch' incorporates:
   *  UnitDelay: '<S19>/Unit Delay'
   */
  if (rtb_Compare_m3) {
    rtb_Add_cc = Code_Gen_Model_B.Odometry_X_global_est_ft;
  } else {
    rtb_Add_cc = Code_Gen_Model_DW.UnitDelay_DSTATE_c;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Sum: '<S19>/Subtract' */
  Code_Gen_Model_B.Odometry_X_global_TEAR_ft =
    Code_Gen_Model_B.Odometry_X_global_est_ft - rtb_Add_cc;

  /* Update for UnitDelay: '<S11>/UD' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Rev'
   *
   * Block description for '<S11>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE = Code_Gen_Model_U.FrontLeft_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S12>/UD' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Rev'
   *
   * Block description for '<S12>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_m = Code_Gen_Model_U.FrontRight_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S13>/UD' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Rev'
   *
   * Block description for '<S13>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_i = Code_Gen_Model_U.BackLeft_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S14>/UD' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Rev'
   *
   * Block description for '<S14>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_c = Code_Gen_Model_U.BackRight_Drive_Motor_Rev;

  /* Update for UnitDelay: '<S10>/UD'
   *
   * Block description for '<S10>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_d = rtb_thetay;

  /* Update for DiscreteIntegrator: '<S5>/Accumulator2' incorporates:
   *  Product: '<S5>/Product6'
   */
  Code_Gen_Model_DW.Accumulator2_DSTATE += rtb_POSEexponentialmatrixfori_1;

  /* Update for DiscreteIntegrator: '<S5>/Accumulator' incorporates:
   *  Product: '<S5>/Product6'
   */
  Code_Gen_Model_DW.Accumulator_DSTATE += rtb_POSEexponentialmatrixfori_2;

  /* Update for UnitDelay: '<S125>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S125>/FixPt Constant'
   */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S139>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE = rtb_POSEexponentialmatrixfori_0;

  /* Update for UnitDelay: '<S138>/UD'
   *
   * Block description for '<S138>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_a = rtb_Subtract1_o;

  /* Update for UnitDelay: '<S136>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_m = rtb_Switch2;

  /* Update for UnitDelay: '<S134>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S134>/FixPt Constant'
   */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S101>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_k = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S100>/UD'
   *
   * Block description for '<S100>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_cs = rtb_Init_e;

  /* Update for UnitDelay: '<S94>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_a = rtb_Switch2_o;

  /* Update for UnitDelay: '<S112>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_i = rtb_Magnitude;

  /* Update for UnitDelay: '<S111>/UD'
   *
   * Block description for '<S111>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_l = rtb_Steer_Joystick_X_Rel_Mod;

  /* Update for UnitDelay: '<S97>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_l = rtb_Sum2_fc;

  /* Update for UnitDelay: '<S80>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_f = rtb_Add_p;

  /* Update for UnitDelay: '<S79>/UD'
   *
   * Block description for '<S79>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_lh = rtb_Add_f_idx_0;

  /* Update for UnitDelay: '<S73>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_gp = rtb_Add_f_idx_1;

  /* Update for UnitDelay: '<S91>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_n = rtb_Add_lb;

  /* Update for UnitDelay: '<S90>/UD'
   *
   * Block description for '<S90>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_k = rtb_Product_lf;

  /* Update for UnitDelay: '<S76>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_k = rtb_Subtract1_hh;

  /* Update for UnitDelay: '<S59>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_b = rtb_Subtract_kb;

  /* Update for UnitDelay: '<S58>/UD'
   *
   * Block description for '<S58>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_e = rtb_Product_n3;

  /* Update for UnitDelay: '<S52>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_e = rtb_Integral_i;

  /* Update for UnitDelay: '<S70>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_na = rtb_Add_k;

  /* Update for UnitDelay: '<S69>/UD'
   *
   * Block description for '<S69>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_i1 = rtb_Product_go;

  /* Update for UnitDelay: '<S55>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_d = rtb_Integral_je;

  /* Update for UnitDelay: '<S38>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_a = rtb_Subtract_n;

  /* Update for UnitDelay: '<S37>/UD'
   *
   * Block description for '<S37>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_o = rtb_Product_nw;

  /* Update for UnitDelay: '<S31>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_f = rtb_Integral_da;

  /* Update for UnitDelay: '<S49>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_bk = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S48>/UD'
   *
   * Block description for '<S48>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_b = rtb_Add_ia;

  /* Update for UnitDelay: '<S34>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_em = rtb_Total_Limited;

  /* Update for UnitDelay: '<S19>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_d = rtb_Switch2_d;

  /* Update for UnitDelay: '<S19>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_c = rtb_Add_cc;
}

/* Model initialize function */
void Code_Gen_Model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Accumulator2' */
  Code_Gen_Model_DW.Accumulator2_DSTATE = Code_Gen_Model_ConstB.Constant;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Accumulator' */
  Code_Gen_Model_DW.Accumulator_DSTATE = Code_Gen_Model_ConstB.Constant1;

  /* InitializeConditions for UnitDelay: '<S125>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S134>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S184>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a = 1U;

  /* End of SystemInitialize for SubSystem: '<S1>/Teleop' */
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
