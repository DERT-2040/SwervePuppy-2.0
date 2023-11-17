/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.4
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Nov 16 18:46:57 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Code_Gen_Model.h"
#include "rtwtypes.h"
#include "Code_Gen_Model_private.h"
#include "rt_nonfinite.h"
#include <math.h>
#include "rt_defines.h"
#include <float.h>

/* Exported block parameters */
real_T Boost_Trigger_Decreasing_Limit = -0.044444444444444446;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S190>/Constant1'
                                      */
real_T Boost_Trigger_Increasing_Limit = 0.04;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S190>/Constant3'
                                      */
real_T Translation_Speed_Rate_Limit_Dec = -0.2;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S124>/Constant1'
                                    */
real_T Translation_Speed_Rate_Limit_Inc = 0.085714285714285715;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S124>/Constant3'
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

/* Start for atomic system: */
void Code_Gen_ModulobyConstant_Start(DW_ModulobyConstant_Code_Gen__T *localDW)
{
  /* Start for MATLABSystem: '<S38>/Modulo by Constant' */
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
}

/* Output and update for atomic system: */
void Code_Gen_Model_ModulobyConstant(real_T rtu_0,
  B_ModulobyConstant_Code_Gen_M_T *localB)
{
  real_T yTemp;

  /* MATLABSystem: '<S38>/Modulo by Constant' */
  if (rtIsNaN(rtu_0) || rtIsInf(rtu_0)) {
    yTemp = (rtNaN);
  } else if (rtu_0 == 0.0) {
    yTemp = 0.0;
  } else {
    yTemp = fmod(rtu_0, 1.0);
    if (yTemp == 0.0) {
      yTemp = 0.0;
    } else if (rtu_0 < 0.0) {
      yTemp++;
    }
  }

  /* MATLABSystem: '<S38>/Modulo by Constant' */
  localB->ModulobyConstant = yTemp;
}

/*
 * Output and update for action system:
 *    '<S1>/Disabled'
 *    '<S1>/Autonomous'
 */
void Code_Gen_Model_Disabled(real_T *rty_Gyro_Angle_Adjusted, real_T
  *rty_Steering_Abs_Cmd, real_T *rty_Steering_Rel_Cmd, real_T
  *rty_Translation_Angle, real_T *rty_Translation_Speed, boolean_T
  *rty_Is_Absolute_Translation_Out, boolean_T *rty_Is_Absolute_Steering_Out)
{
  /* Constant: '<S3>/Constant' */
  *rty_Gyro_Angle_Adjusted = 0.0;

  /* Constant: '<S3>/Constant1' */
  *rty_Steering_Abs_Cmd = 0.0;

  /* Constant: '<S3>/Constant2' */
  *rty_Steering_Rel_Cmd = 0.0;

  /* Constant: '<S3>/Constant3' */
  *rty_Translation_Angle = 0.0;

  /* Constant: '<S3>/Constant4' */
  *rty_Translation_Speed = 0.0;

  /* Constant: '<S3>/Constant5' */
  *rty_Is_Absolute_Translation_Out = true;

  /* Constant: '<S3>/Constant6' */
  *rty_Is_Absolute_Steering_Out = true;
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

/* Model step function */
void Code_Gen_Model_step(void)
{
  /* local block i/o variables */
  real_T rtb_LookupTableDynamic1;
  real_T rtb_LookupTableDynamic;
  real_T rtb_LookupTableDynamic1_i;
  real_T rtb_LookupTableDynamic_j;
  real_T rtb_Switch2_g_0[8];
  real_T rtb_Product7[2];
  real_T rtb_TmpSignalConversionAtLook_o[2];
  real_T rtb_Add_b0;
  real_T rtb_Add_f_idx_0;
  real_T rtb_Add_f_idx_1;
  real_T rtb_Add_k;
  real_T rtb_Add_kl;
  real_T rtb_Add_p;
  real_T rtb_Hypot_e;
  real_T rtb_Integral_ec;
  real_T rtb_Integral_f;
  real_T rtb_Integral_g;
  real_T rtb_Minus2;
  real_T rtb_Modulation_Drv_X;
  real_T rtb_POSEexponentialmatrixfori_0;
  real_T rtb_POSEexponentialmatrixfori_1;
  real_T rtb_Product_j;
  real_T rtb_Product_k;
  real_T rtb_Product_lf;
  real_T rtb_Sin4;
  real_T rtb_Sin5;
  real_T rtb_SteeringAngle_rad_4;
  real_T rtb_Subtract1_b;
  real_T rtb_Subtract1_lg;
  real_T rtb_Subtract_n;
  real_T rtb_Subtract_pa;
  real_T rtb_Sum1_li;
  real_T rtb_Switch1_h;
  real_T rtb_Switch2;
  real_T rtb_Switch2_g;
  real_T rtb_Switch2_h4;
  real_T rtb_Switch_ga;
  real_T rtb_Total_Limited_j;
  real_T rtb_thetay;
  int32_T i;
  int32_T i_0;
  int32_T tmp;
  boolean_T rtb_Compare_b4c;
  boolean_T rtb_Compare_fh;
  boolean_T rtb_Compare_ov;
  boolean_T rtb_Is_Absolute_Translation;

  /* Gain: '<S4>/Gain' incorporates:
   *  Inport: '<Root>/FrontLeft_Steer_Encoder'
   */
  rtb_SteeringAngle_rad_4 = 6.2831853071795862 *
    Code_Gen_Model_U.FrontLeft_Steer_Encoder;

  /* Product: '<S4>/Product' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Inport: '<Root>/FrontLeft_Drive_Rev'
   *  Sum: '<S9>/Diff'
   *  UnitDelay: '<S9>/UD'
   *
   * Block description for '<S9>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S9>/UD':
   *
   *  Store in Global RAM
   */
  rtb_thetay = (Code_Gen_Model_U.FrontLeft_Drive_Rev -
                Code_Gen_Model_DW.UD_DSTATE) * 0.039212094760200447;

  /* SignalConversion generated from: '<S4>/Product7' incorporates:
   *  Fcn: '<S13>/r->x'
   *  Fcn: '<S13>/theta->y'
   */
  rtb_Switch2_g_0[0] = rtb_thetay * cos(rtb_SteeringAngle_rad_4);
  rtb_Switch2_g_0[1] = rtb_thetay * sin(rtb_SteeringAngle_rad_4);

  /* Gain: '<S4>/Gain1' incorporates:
   *  Inport: '<Root>/FrontRight_Steer_Encoder'
   */
  rtb_SteeringAngle_rad_4 = 6.2831853071795862 *
    Code_Gen_Model_U.FrontRight_Steer_Encoder;

  /* Product: '<S4>/Product1' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Inport: '<Root>/FrontRight_Drive_Rev'
   *  Sum: '<S10>/Diff'
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
  rtb_Switch_ga = (Code_Gen_Model_U.FrontRight_Drive_Rev -
                   Code_Gen_Model_DW.UD_DSTATE_m) * 0.039212094760200447;

  /* SignalConversion generated from: '<S4>/Product7' incorporates:
   *  Fcn: '<S14>/r->x'
   *  Fcn: '<S14>/theta->y'
   */
  rtb_Switch2_g_0[2] = rtb_Switch_ga * cos(rtb_SteeringAngle_rad_4);
  rtb_Switch2_g_0[3] = rtb_Switch_ga * sin(rtb_SteeringAngle_rad_4);

  /* Gain: '<S4>/Gain2' incorporates:
   *  Inport: '<Root>/BackLeft_Steer_Encoder'
   */
  rtb_SteeringAngle_rad_4 = 6.2831853071795862 *
    Code_Gen_Model_U.BackLeft_Steer_Encoder;

  /* Product: '<S4>/Product2' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Inport: '<Root>/BackLeft_Drive_Rev'
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
  rtb_Sin5 = (Code_Gen_Model_U.BackLeft_Drive_Rev -
              Code_Gen_Model_DW.UD_DSTATE_i) * 0.039212094760200447;

  /* SignalConversion generated from: '<S4>/Product7' incorporates:
   *  Fcn: '<S15>/r->x'
   *  Fcn: '<S15>/theta->y'
   */
  rtb_Switch2_g_0[4] = rtb_Sin5 * cos(rtb_SteeringAngle_rad_4);
  rtb_Switch2_g_0[5] = rtb_Sin5 * sin(rtb_SteeringAngle_rad_4);

  /* Gain: '<S4>/Gain3' incorporates:
   *  Inport: '<Root>/BackRight_Steer_Encoder'
   */
  rtb_SteeringAngle_rad_4 = 6.2831853071795862 *
    Code_Gen_Model_U.BackRight_Steer_Encoder;

  /* Product: '<S4>/Product3' incorporates:
   *  Constant: '<S4>/Constant1'
   *  Inport: '<Root>/BackRight_Drive_Rev'
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
  rtb_Minus2 = (Code_Gen_Model_U.BackRight_Drive_Rev -
                Code_Gen_Model_DW.UD_DSTATE_c) * 0.039212094760200447;

  /* SignalConversion generated from: '<S4>/Product7' incorporates:
   *  Fcn: '<S16>/r->x'
   *  Fcn: '<S16>/theta->y'
   */
  rtb_Switch2_g_0[6] = rtb_Minus2 * cos(rtb_SteeringAngle_rad_4);
  rtb_Switch2_g_0[7] = rtb_Minus2 * sin(rtb_SteeringAngle_rad_4);

  /* Product: '<S4>/Product7' incorporates:
   *  Constant: '<S4>/Constant4'
   */
  for (i = 0; i < 2; i++) {
    rtb_SteeringAngle_rad_4 = 0.0;
    tmp = 0;
    for (i_0 = 0; i_0 < 8; i_0++) {
      rtb_SteeringAngle_rad_4 += Code_Gen_Model_ConstP.Constant4_Value[tmp + i] *
        rtb_Switch2_g_0[i_0];
      tmp += 2;
    }

    rtb_Product7[i] = rtb_SteeringAngle_rad_4;
  }

  /* End of Product: '<S4>/Product7' */

  /* Gain: '<S4>/Gain4' incorporates:
   *  Inport: '<Root>/Gyro_Angle'
   */
  rtb_SteeringAngle_rad_4 = 0.017453292519943295 * Code_Gen_Model_U.Gyro_Angle;

  /* Sum: '<S8>/Diff' incorporates:
   *  UnitDelay: '<S8>/UD'
   *
   * Block description for '<S8>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S8>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Total_Limited_j = rtb_SteeringAngle_rad_4 - Code_Gen_Model_DW.UD_DSTATE_d;

  /* Sum: '<S4>/Subtract2' incorporates:
   *  Constant: '<S4>/Constant3'
   *  Gain: '<S4>/Gain7'
   *  Math: '<S4>/Square'
   */
  rtb_Minus2 = 1.0 - rtb_Total_Limited_j * rtb_Total_Limited_j *
    0.16666666666666666;

  /* Gain: '<S4>/Gain6' */
  rtb_Total_Limited_j *= 0.5;

  /* SignalConversion generated from: '<S4>/POSE exponential matrix for improved accuracy while rotating' */
  rtb_POSEexponentialmatrixfori_0 = rtb_Minus2;
  rtb_POSEexponentialmatrixfori_1 = rtb_Total_Limited_j;

  /* SignalConversion generated from: '<S4>/POSE exponential matrix for improved accuracy while rotating' incorporates:
   *  UnaryMinus: '<S4>/Unary Minus2'
   */
  rtb_thetay = -rtb_Total_Limited_j;

  /* Trigonometry: '<S4>/Trigonometric Function' */
  rtb_Total_Limited_j = cos(rtb_SteeringAngle_rad_4);

  /* Trigonometry: '<S4>/Trigonometric Function1' */
  rtb_Minus2 = sin(rtb_SteeringAngle_rad_4);

  /* Product: '<S4>/Product6' incorporates:
   *  Concatenate: '<S4>/POSE exponential matrix for improved accuracy while rotating'
   *  SignalConversion generated from: '<S4>/Rotation matrix from local to global'
   *  UnaryMinus: '<S4>/Unary Minus'
   */
  rtb_thetay = rtb_POSEexponentialmatrixfori_0 * rtb_Product7[0] + rtb_thetay *
    rtb_Product7[1];
  rtb_POSEexponentialmatrixfori_0 = rtb_POSEexponentialmatrixfori_1 *
    rtb_Product7[0] + rtb_POSEexponentialmatrixfori_0 * rtb_Product7[1];
  rtb_POSEexponentialmatrixfori_1 = rtb_Total_Limited_j * rtb_thetay +
    -rtb_Minus2 * rtb_POSEexponentialmatrixfori_0;
  rtb_POSEexponentialmatrixfori_0 = rtb_Minus2 * rtb_thetay +
    rtb_Total_Limited_j * rtb_POSEexponentialmatrixfori_0;

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Constant: '<S7>/Constant'
   *  Constant: '<S7>/Constant2'
   *  Constant: '<S7>/Constant4'
   *  Constant: '<S7>/Constant5'
   *  Constant: '<S7>/Constant6'
   *  Inport: '<Root>/GameState'
   */
  rtb_Product_j = trunc(Code_Gen_Model_U.GameState);
  if (rtIsNaN(rtb_Product_j) || rtIsInf(rtb_Product_j)) {
    rtb_Product_j = 0.0;
  } else {
    rtb_Product_j = fmod(rtb_Product_j, 4.294967296E+9);
  }

  if (rtb_Product_j < 0.0) {
    i = -(int32_T)(uint32_T)-rtb_Product_j;
  } else {
    i = (int32_T)(uint32_T)rtb_Product_j;
  }

  switch (i) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Disabled' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    Code_Gen_Model_Disabled(&rtb_Switch2_g, &Code_Gen_Model_B.Steering_Abs_Cmd,
      &rtb_Switch_ga, &Code_Gen_Model_B.Translation_Angle, &rtb_Total_Limited_j,
      &rtb_Is_Absolute_Translation, &rtb_Compare_b4c);

    /* End of Outputs for SubSystem: '<S1>/Disabled' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    Code_Gen_Model_Disabled(&rtb_Switch2_g, &Code_Gen_Model_B.Steering_Abs_Cmd,
      &rtb_Switch_ga, &Code_Gen_Model_B.Translation_Angle, &rtb_Total_Limited_j,
      &rtb_Is_Absolute_Translation, &rtb_Compare_b4c);

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Teleop' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Switch: '<S178>/Switch1' incorporates:
     *  Constant: '<S178>/Constant'
     *  Constant: '<S178>/Constant1'
     *  Constant: '<S178>/Constant2'
     *  Inport: '<Root>/Steer_Joystick_X'
     *  Inport: '<Root>/Steer_Joystick_Y'
     *  Math: '<S178>/Hypot'
     *  RelationalOperator: '<S178>/GreaterThan'
     *  Switch: '<S178>/Switch'
     */
    if (rt_hypotd_snf(Code_Gen_Model_U.Steer_Joystick_X,
                      Code_Gen_Model_U.Steer_Joystick_Y) > 0.7) {
      rtb_Sin4 = Code_Gen_Model_U.Steer_Joystick_Y;
      rtb_Modulation_Drv_X = Code_Gen_Model_U.Steer_Joystick_X;
    } else {
      rtb_Sin4 = 0.0;
      rtb_Modulation_Drv_X = 0.0;
    }

    /* End of Switch: '<S178>/Switch1' */

    /* Switch: '<S180>/Switch1' incorporates:
     *  Constant: '<S186>/Constant'
     *  Constant: '<S187>/Constant'
     *  Logic: '<S180>/AND'
     *  RelationalOperator: '<S186>/Compare'
     *  RelationalOperator: '<S187>/Compare'
     *  Switch: '<S180>/Switch2'
     *  UnitDelay: '<S180>/Unit Delay'
     *  UnitDelay: '<S180>/Unit Delay1'
     */
    if (rtb_Modulation_Drv_X == 0.0 && rtb_Sin4 == 0.0) {
      rtb_thetay = Code_Gen_Model_DW.UnitDelay1_DSTATE_d;
      rtb_Switch2 = Code_Gen_Model_DW.UnitDelay_DSTATE_g4;
    } else {
      rtb_thetay = rtb_Sin4;
      rtb_Switch2 = rtb_Modulation_Drv_X;
    }

    /* End of Switch: '<S180>/Switch1' */

    /* RelationalOperator: '<S183>/Compare' incorporates:
     *  Constant: '<S183>/Constant'
     */
    rtb_Is_Absolute_Translation = rtb_Switch2 < 0.0;

    /* Switch: '<S179>/Switch' incorporates:
     *  Constant: '<S179>/Constant'
     *  Constant: '<S179>/Constant1'
     *  Constant: '<S181>/Constant'
     *  Constant: '<S182>/Constant'
     *  Logic: '<S179>/Logical Operator'
     *  RelationalOperator: '<S181>/Compare'
     *  RelationalOperator: '<S182>/Compare'
     *  UnitDelay: '<S179>/Unit Delay'
     */
    if (rtb_thetay < 0.0 && Code_Gen_Model_DW.UnitDelay_DSTATE_h >= 0.0 &&
        rtb_Is_Absolute_Translation) {
      rtb_Product_j = 6.2831853071795862;
    } else {
      rtb_Product_j = 0.0;
    }

    /* Switch: '<S179>/Switch1' incorporates:
     *  Constant: '<S179>/Constant2'
     *  Constant: '<S179>/Constant3'
     *  Constant: '<S184>/Constant'
     *  Constant: '<S185>/Constant'
     *  Logic: '<S179>/Logical Operator1'
     *  RelationalOperator: '<S184>/Compare'
     *  RelationalOperator: '<S185>/Compare'
     *  UnitDelay: '<S179>/Unit Delay'
     */
    if (Code_Gen_Model_DW.UnitDelay_DSTATE_h < 0.0 && rtb_thetay >= 0.0 &&
        rtb_Is_Absolute_Translation) {
      rtb_Sin5 = -6.2831853071795862;
    } else {
      rtb_Sin5 = 0.0;
    }

    /* Sum: '<S179>/Sum1' incorporates:
     *  Switch: '<S179>/Switch'
     *  Switch: '<S179>/Switch1'
     *  UnitDelay: '<S179>/Unit Delay1'
     */
    rtb_Sum1_li = rtb_Product_j + rtb_Sin5 +
      Code_Gen_Model_DW.UnitDelay1_DSTATE_kr;

    /* Sum: '<S179>/Sum' incorporates:
     *  Gain: '<S175>/Gain1'
     *  Inport: '<Root>/Gyro_Angle'
     */
    rtb_Switch2_g = 0.017453292519943295 * Code_Gen_Model_U.Gyro_Angle +
      rtb_Sum1_li;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Trigonometry: '<S176>/Atan2'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd = rt_atan2d_snf(rtb_thetay, rtb_Switch2);

    /* Product: '<S176>/Product' incorporates:
     *  Constant: '<S176>/Constant'
     *  Inport: '<Root>/Steer_Joystick_Y'
     *  Lookup_n-D: '<S176>/Modulation_Str_X_Rel'
     */
    rtb_Switch_ga = look1_binlcpw(Code_Gen_Model_U.Steer_Joystick_Y,
      Code_Gen_Model_ConstP.Modulation_Str_X_Rel_bp01Data,
      Code_Gen_Model_ConstP.Modulation_Str_X_Rel_tableData, 20U) * 1.3;

    /* Switch: '<S188>/Switch1' incorporates:
     *  Constant: '<S188>/Constant'
     *  Constant: '<S188>/Constant1'
     *  Inport: '<Root>/Is_Boost_Trigger_Pulled'
     */
    if (Code_Gen_Model_U.Is_Boost_Trigger_Pulled != 0.0) {
      rtb_Modulation_Drv_X = 3.658;
    } else {
      rtb_Modulation_Drv_X = 1.5;
    }

    /* End of Switch: '<S188>/Switch1' */

    /* Switch: '<S193>/Init' incorporates:
     *  UnitDelay: '<S193>/FixPt Unit Delay1'
     *  UnitDelay: '<S193>/FixPt Unit Delay2'
     */
    if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Sin4 = rtb_Modulation_Drv_X;
    } else {
      rtb_Sin4 = Code_Gen_Model_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S193>/Init' */

    /* Sum: '<S191>/Sum1' */
    rtb_Minus2 = rtb_Modulation_Drv_X - rtb_Sin4;

    /* Switch: '<S192>/Switch2' incorporates:
     *  Constant: '<S190>/Constant1'
     *  Constant: '<S190>/Constant3'
     *  RelationalOperator: '<S192>/LowerRelop1'
     *  RelationalOperator: '<S192>/UpperRelop'
     *  Switch: '<S192>/Switch'
     */
    if (rtb_Minus2 > Boost_Trigger_Increasing_Limit) {
      rtb_Minus2 = Boost_Trigger_Increasing_Limit;
    } else if (rtb_Minus2 < Boost_Trigger_Decreasing_Limit) {
      /* Switch: '<S192>/Switch' incorporates:
       *  Constant: '<S190>/Constant1'
       */
      rtb_Minus2 = Boost_Trigger_Decreasing_Limit;
    }

    /* Sum: '<S191>/Sum' incorporates:
     *  Switch: '<S192>/Switch2'
     */
    rtb_Minus2 += rtb_Sin4;

    /* Lookup_n-D: '<S177>/Modulation_Drv_X' incorporates:
     *  Inport: '<Root>/Drive_Joystick_X'
     */
    rtb_Modulation_Drv_X = look1_binlcpw(Code_Gen_Model_U.Drive_Joystick_X,
      Code_Gen_Model_ConstP.pooled12, Code_Gen_Model_ConstP.pooled11, 20U);

    /* Lookup_n-D: '<S177>/Modulation_Drv_Y' incorporates:
     *  Inport: '<Root>/Drive_Joystick_Y'
     */
    rtb_Sin4 = look1_binlcpw(Code_Gen_Model_U.Drive_Joystick_Y,
      Code_Gen_Model_ConstP.pooled12, Code_Gen_Model_ConstP.pooled11, 20U);

    /* Product: '<S188>/Product' incorporates:
     *  Math: '<S177>/Magnitude'
     */
    rtb_Total_Limited_j = rt_hypotd_snf(rtb_Modulation_Drv_X, rtb_Sin4) *
      rtb_Minus2;

    /* Saturate: '<S188>/Saturation' */
    if (rtb_Total_Limited_j > 3.658) {
      rtb_Total_Limited_j = 3.658;
    } else if (rtb_Total_Limited_j < -3.658) {
      rtb_Total_Limited_j = -3.658;
    }

    /* End of Saturate: '<S188>/Saturation' */

    /* Switch: '<S189>/Switch1' incorporates:
     *  Constant: '<S194>/Constant'
     *  Constant: '<S195>/Constant'
     *  Logic: '<S189>/AND'
     *  RelationalOperator: '<S194>/Compare'
     *  RelationalOperator: '<S195>/Compare'
     *  Switch: '<S189>/Switch2'
     *  UnitDelay: '<S189>/Unit Delay'
     *  UnitDelay: '<S189>/Unit Delay1'
     */
    if (rtb_Modulation_Drv_X == 0.0 && rtb_Sin4 == 0.0) {
      rtb_Sin4 = Code_Gen_Model_DW.UnitDelay1_DSTATE_l;
      rtb_Modulation_Drv_X = Code_Gen_Model_DW.UnitDelay_DSTATE_p;
    }

    /* End of Switch: '<S189>/Switch1' */

    /* Merge: '<S1>/Merge3' incorporates:
     *  Trigonometry: '<S177>/Atan2'
     */
    Code_Gen_Model_B.Translation_Angle = rt_atan2d_snf(rtb_Sin4,
      rtb_Modulation_Drv_X);

    /* SignalConversion generated from: '<S6>/Is_Absolute_Translation_In' incorporates:
     *  Inport: '<Root>/Is_Absolute_Translation'
     */
    rtb_Is_Absolute_Translation = Code_Gen_Model_U.Is_Absolute_Translation;

    /* SignalConversion generated from: '<S6>/Is_Absolute_Steering_In' incorporates:
     *  Inport: '<Root>/Is_Absolute_Steering'
     */
    rtb_Compare_b4c = Code_Gen_Model_U.Is_Absolute_Steering;

    /* Update for UnitDelay: '<S180>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_d = rtb_thetay;

    /* Update for UnitDelay: '<S179>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_h = rtb_thetay;

    /* Update for UnitDelay: '<S180>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_g4 = rtb_Switch2;

    /* Update for UnitDelay: '<S179>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_kr = rtb_Sum1_li;

    /* Update for UnitDelay: '<S193>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S193>/FixPt Constant'
     */
    Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S193>/FixPt Unit Delay1' */
    Code_Gen_Model_DW.FixPtUnitDelay1_DSTATE_f = rtb_Minus2;

    /* Update for UnitDelay: '<S189>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_l = rtb_Sin4;

    /* Update for UnitDelay: '<S189>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_p = rtb_Modulation_Drv_X;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    rtb_Switch2_g = 0.0;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S7>/Constant'
     *  Constant: '<S7>/Constant1'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd = 0.0;
    rtb_Switch_ga = 0.0;

    /* Merge: '<S1>/Merge3' incorporates:
     *  Constant: '<S7>/Constant2'
     *  Constant: '<S7>/Constant3'
     */
    Code_Gen_Model_B.Translation_Angle = 0.0;
    rtb_Total_Limited_j = 1.0;
    rtb_Is_Absolute_Translation = true;
    rtb_Compare_b4c = true;

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* UnitDelay: '<S124>/Unit Delay' */
  rtb_Minus2 = Code_Gen_Model_B.Translation_Speed;

  /* Signum: '<S124>/Sign2' */
  if (rtIsNaN(rtb_Minus2)) {
    rtb_Product_j = (rtNaN);
  } else if (rtb_Minus2 < 0.0) {
    rtb_Product_j = -1.0;
  } else {
    rtb_Product_j = rtb_Minus2 > 0.0;
  }

  /* Signum: '<S124>/Sign1' */
  if (rtIsNaN(rtb_Total_Limited_j)) {
    rtb_Sin5 = (rtNaN);
  } else if (rtb_Total_Limited_j < 0.0) {
    rtb_Sin5 = -1.0;
  } else {
    rtb_Sin5 = rtb_Total_Limited_j > 0.0;
  }

  /* Product: '<S124>/Product1' incorporates:
   *  Signum: '<S124>/Sign1'
   *  Signum: '<S124>/Sign2'
   */
  rtb_Product_j *= rtb_Sin5;
  if (rtIsNaN(rtb_Product_j)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Product_j, 256.0);
  }

  if (i < 0) {
    i = (int8_T)-(int8_T)(uint8_T)-(real_T)i;
  }

  /* Switch: '<S124>/Switch' incorporates:
   *  Constant: '<S124>/Constant'
   *  Constant: '<S128>/Constant'
   *  Constant: '<S129>/Constant'
   *  Logic: '<S124>/or'
   *  Product: '<S124>/Product1'
   *  RelationalOperator: '<S128>/Compare'
   *  RelationalOperator: '<S129>/Compare'
   */
  if (rtb_Minus2 == 0.0 || i > 0) {
    rtb_Switch2_h4 = rtb_Total_Limited_j;
  } else {
    rtb_Switch2_h4 = 0.0;
  }

  /* End of Switch: '<S124>/Switch' */

  /* Switch: '<S134>/Init' incorporates:
   *  UnitDelay: '<S134>/FixPt Unit Delay1'
   *  UnitDelay: '<S134>/FixPt Unit Delay2'
   */
  if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Sin5 = rtb_Switch2_h4;
  } else {
    rtb_Sin5 = Code_Gen_Model_B.Translation_Speed;
  }

  /* End of Switch: '<S134>/Init' */

  /* RelationalOperator: '<S130>/Compare' incorporates:
   *  Constant: '<S130>/Constant'
   */
  rtb_Compare_fh = rtb_Switch2_h4 == 0.0;

  /* RelationalOperator: '<S131>/Compare' incorporates:
   *  Constant: '<S131>/Constant'
   */
  rtb_Compare_ov = rtb_Switch2_h4 > 0.0;

  /* Abs: '<S124>/Abs' incorporates:
   *  Sum: '<S124>/Subtract'
   */
  rtb_thetay = fabs(rtb_Minus2 - rtb_Total_Limited_j);

  /* Switch: '<S124>/Switch5' incorporates:
   *  Constant: '<S124>/Constant1'
   *  Switch: '<S124>/Switch1'
   *  UnaryMinus: '<S124>/Unary Minus'
   */
  if (rtb_Compare_fh) {
    /* SignalConversion generated from: '<S124>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S124>/Constant4'
     *  Constant: '<S124>/Constant6'
     */
    rtb_Product7[0] = 0.01;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S124>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S124>/Constant2'
     *  Constant: '<S124>/Constant5'
     */
    rtb_TmpSignalConversionAtLook_o[0] = 0.0;
    rtb_TmpSignalConversionAtLook_o[1] = 0.2;

    /* S-Function (sfix_look1_dyn): '<S124>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S124>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_j), &rtb_Product7[0],
                         rtb_thetay, &rtb_TmpSignalConversionAtLook_o[0], 1U);
    rtb_thetay = rtb_LookupTableDynamic_j;
    rtb_Product_j = -Translation_Speed_Rate_Limit_Dec;
  } else {
    /* SignalConversion generated from: '<S124>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S124>/Constant10'
     *  Constant: '<S124>/Constant8'
     */
    rtb_Product7[0] = 0.05;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S124>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S124>/Constant7'
     *  Constant: '<S124>/Constant9'
     */
    rtb_TmpSignalConversionAtLook_o[0] = 0.0;
    rtb_TmpSignalConversionAtLook_o[1] = 0.15;

    /* S-Function (sfix_look1_dyn): '<S124>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S124>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_i), &rtb_Product7[0],
                         rtb_thetay, &rtb_TmpSignalConversionAtLook_o[0], 1U);
    rtb_thetay = rtb_LookupTableDynamic1_i;

    /* Switch: '<S124>/Switch3' incorporates:
     *  Constant: '<S124>/Constant1'
     *  Constant: '<S124>/Constant3'
     *  UnaryMinus: '<S124>/Unary Minus'
     */
    if (rtb_Compare_ov) {
      rtb_Product_j = Translation_Speed_Rate_Limit_Inc;
    } else {
      rtb_Product_j = -Translation_Speed_Rate_Limit_Dec;
    }

    /* End of Switch: '<S124>/Switch3' */
  }

  /* End of Switch: '<S124>/Switch5' */

  /* Product: '<S124>/Product' incorporates:
   *  Switch: '<S124>/Switch1'
   */
  rtb_Sin4 = rtb_Product_j * rtb_thetay;

  /* Sum: '<S132>/Sum1' */
  rtb_Switch2 = rtb_Switch2_h4 - rtb_Sin5;

  /* Switch: '<S133>/Switch2' incorporates:
   *  RelationalOperator: '<S133>/LowerRelop1'
   */
  if (!(rtb_Switch2 > rtb_Sin4)) {
    /* Switch: '<S124>/Switch2' incorporates:
     *  Constant: '<S124>/Constant1'
     *  Constant: '<S124>/Constant3'
     *  Switch: '<S124>/Switch4'
     *  UnaryMinus: '<S124>/Unary Minus1'
     */
    if (rtb_Compare_fh) {
      rtb_Product_j = Translation_Speed_Rate_Limit_Dec;
    } else if (rtb_Compare_ov) {
      /* Switch: '<S124>/Switch4' incorporates:
       *  Constant: '<S124>/Constant1'
       */
      rtb_Product_j = Translation_Speed_Rate_Limit_Dec;
    } else {
      rtb_Product_j = -Translation_Speed_Rate_Limit_Inc;
    }

    /* Product: '<S124>/Product2' incorporates:
     *  Switch: '<S124>/Switch2'
     */
    rtb_Sum1_li = rtb_Product_j * rtb_thetay;

    /* Switch: '<S133>/Switch' incorporates:
     *  RelationalOperator: '<S133>/UpperRelop'
     */
    if (rtb_Switch2 < rtb_Sum1_li) {
      rtb_Sin4 = rtb_Sum1_li;
    } else {
      rtb_Sin4 = rtb_Switch2;
    }

    /* End of Switch: '<S133>/Switch' */
  }

  /* End of Switch: '<S133>/Switch2' */

  /* Sum: '<S132>/Sum' */
  Code_Gen_Model_B.Translation_Speed = rtb_Sin4 + rtb_Sin5;

  /* Switch: '<S126>/Switch' */
  if (rtb_Is_Absolute_Translation) {
    /* Switch: '<S126>/Switch' incorporates:
     *  Constant: '<S149>/Constant3'
     *  Constant: '<S149>/Constant4'
     *  Gain: '<S17>/Gain1'
     *  Inport: '<Root>/Gyro_Angle'
     *  Math: '<S149>/Math Function'
     *  Sum: '<S149>/Add1'
     *  Sum: '<S149>/Add2'
     */
    Code_Gen_Model_B.Translation_Steering_Cmd = rt_modd_snf
      (Code_Gen_Model_B.Translation_Angle - 0.017453292519943295 *
       Code_Gen_Model_U.Gyro_Angle + 3.1415926535897931, 6.2831853071795862) -
      3.1415926535897931;
  } else {
    /* Switch: '<S126>/Switch' */
    Code_Gen_Model_B.Translation_Steering_Cmd =
      Code_Gen_Model_B.Translation_Angle;
  }

  /* End of Switch: '<S126>/Switch' */

  /* Sum: '<S144>/Sum' */
  rtb_Switch2_g = Code_Gen_Model_B.Steering_Abs_Cmd - rtb_Switch2_g;

  /* Sum: '<S148>/Subtract1' incorporates:
   *  Product: '<S148>/Divide'
   *  Product: '<S148>/Product'
   *  Rounding: '<S148>/Fix'
   *  Sum: '<S148>/Minus'
   */
  rtb_Switch2_g -= trunc((rtb_Switch2_g - Code_Gen_Model_ConstB.UnaryMinus_h) /
    Code_Gen_Model_ConstB.Modulus_n) * Code_Gen_Model_ConstB.Modulus_n;

  /* Sum: '<S148>/Minus2' incorporates:
   *  Constant: '<S136>/Constant1'
   *  Product: '<S148>/Divide1'
   *  Product: '<S148>/Product1'
   *  Rounding: '<S148>/Fix1'
   *  Sum: '<S148>/Minus1'
   */
  rtb_Switch2_g -= trunc((rtb_Switch2_g - 3.1415926535897931) /
    Code_Gen_Model_ConstB.Modulus_n) * Code_Gen_Model_ConstB.Modulus_n;

  /* Sum: '<S146>/Sum1' incorporates:
   *  Constant: '<S144>/Constant2'
   *  Product: '<S146>/Product'
   *  Sum: '<S146>/Sum'
   *  UnitDelay: '<S146>/Unit Delay1'
   */
  rtb_thetay = (rtb_Switch2_g - Code_Gen_Model_DW.UnitDelay1_DSTATE) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE;

  /* Product: '<S144>/Product' incorporates:
   *  Constant: '<S144>/Constant3'
   */
  rtb_Switch2 = rtb_thetay * 0.0;

  /* Sum: '<S145>/Diff' incorporates:
   *  UnitDelay: '<S145>/UD'
   *
   * Block description for '<S145>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S145>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_kl = rtb_Switch2 - Code_Gen_Model_DW.UD_DSTATE_a;

  /* Saturate: '<S144>/Saturation' */
  if (rtb_Add_kl > 0.0) {
    rtb_Add_kl = 0.0;
  } else if (rtb_Add_kl < -0.0) {
    rtb_Add_kl = -0.0;
  }

  /* Sum: '<S144>/Add' incorporates:
   *  Gain: '<S144>/Gain1'
   *  Saturate: '<S144>/Saturation'
   */
  rtb_Minus2 = 1.5 * rtb_Switch2_g + rtb_Add_kl;

  /* Sum: '<S144>/Subtract' incorporates:
   *  Constant: '<S144>/Constant'
   */
  rtb_Switch2_h4 = 1.3 - rtb_Minus2;

  /* Sum: '<S144>/Sum2' incorporates:
   *  Gain: '<S144>/Gain2'
   *  UnitDelay: '<S144>/Unit Delay'
   */
  rtb_Sum1_li = 0.015 * rtb_Switch2_g + Code_Gen_Model_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S147>/Switch2' incorporates:
   *  Constant: '<S144>/Constant'
   *  RelationalOperator: '<S147>/LowerRelop1'
   *  Sum: '<S144>/Subtract'
   */
  if (!(rtb_Sum1_li > 1.3 - rtb_Minus2)) {
    /* Switch: '<S147>/Switch' incorporates:
     *  Constant: '<S144>/Constant1'
     *  RelationalOperator: '<S147>/UpperRelop'
     *  Sum: '<S144>/Subtract1'
     */
    if (rtb_Sum1_li < -1.3 - rtb_Minus2) {
      rtb_Switch2_h4 = -1.3 - rtb_Minus2;
    } else {
      rtb_Switch2_h4 = rtb_Sum1_li;
    }

    /* End of Switch: '<S147>/Switch' */
  }

  /* End of Switch: '<S147>/Switch2' */

  /* Saturate: '<S144>/Saturation1' */
  if (rtb_Switch2_h4 > 0.1) {
    rtb_Sum1_li = 0.1;
  } else if (rtb_Switch2_h4 < -0.1) {
    rtb_Sum1_li = -0.1;
  } else {
    rtb_Sum1_li = rtb_Switch2_h4;
  }

  /* End of Saturate: '<S144>/Saturation1' */

  /* Switch: '<S125>/Switch' */
  if (rtb_Compare_b4c) {
    /* Sum: '<S144>/Add1' */
    rtb_Minus2 += rtb_Sum1_li;

    /* Saturate: '<S144>/Saturation2' */
    if (rtb_Minus2 > 1.3) {
      rtb_Minus2 = 1.3;
    } else if (rtb_Minus2 < -1.3) {
      rtb_Minus2 = -1.3;
    }

    /* End of Saturate: '<S144>/Saturation2' */

    /* DeadZone: '<S136>/Dead Zone' */
    if (rtb_Minus2 > 0.01) {
      rtb_Switch_ga = rtb_Minus2 - 0.01;
    } else if (rtb_Minus2 >= -0.01) {
      rtb_Switch_ga = 0.0;
    } else {
      rtb_Switch_ga = rtb_Minus2 - -0.01;
    }

    /* End of DeadZone: '<S136>/Dead Zone' */
  }

  /* End of Switch: '<S125>/Switch' */

  /* Signum: '<S135>/Sign2' incorporates:
   *  UnitDelay: '<S135>/Unit Delay'
   */
  if (rtIsNaN(Code_Gen_Model_B.Steering_Localized_Cmd)) {
    rtb_Product_j = (rtNaN);
  } else if (Code_Gen_Model_B.Steering_Localized_Cmd < 0.0) {
    rtb_Product_j = -1.0;
  } else {
    rtb_Product_j = Code_Gen_Model_B.Steering_Localized_Cmd > 0.0;
  }

  /* Signum: '<S135>/Sign1' */
  if (rtIsNaN(rtb_Switch_ga)) {
    rtb_Sin5 = (rtNaN);
  } else if (rtb_Switch_ga < 0.0) {
    rtb_Sin5 = -1.0;
  } else {
    rtb_Sin5 = rtb_Switch_ga > 0.0;
  }

  /* Product: '<S135>/Product1' incorporates:
   *  Signum: '<S135>/Sign1'
   *  Signum: '<S135>/Sign2'
   */
  rtb_Product_j *= rtb_Sin5;
  if (rtIsNaN(rtb_Product_j)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Product_j, 256.0);
  }

  if (i < 0) {
    i = (int8_T)-(int8_T)(uint8_T)-(real_T)i;
  }

  /* Switch: '<S135>/Switch' incorporates:
   *  Constant: '<S135>/Constant'
   *  Constant: '<S137>/Constant'
   *  Constant: '<S138>/Constant'
   *  Logic: '<S135>/or'
   *  Product: '<S135>/Product1'
   *  RelationalOperator: '<S137>/Compare'
   *  RelationalOperator: '<S138>/Compare'
   *  UnitDelay: '<S135>/Unit Delay'
   */
  if (Code_Gen_Model_B.Steering_Localized_Cmd == 0.0 || i > 0) {
    rtb_Sin5 = rtb_Switch_ga;
  } else {
    rtb_Sin5 = 0.0;
  }

  /* End of Switch: '<S135>/Switch' */

  /* Switch: '<S143>/Init' incorporates:
   *  UnitDelay: '<S143>/FixPt Unit Delay1'
   *  UnitDelay: '<S143>/FixPt Unit Delay2'
   */
  if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Sin4 = rtb_Sin5;
  } else {
    rtb_Sin4 = Code_Gen_Model_B.Steering_Localized_Cmd;
  }

  /* End of Switch: '<S143>/Init' */

  /* RelationalOperator: '<S139>/Compare' incorporates:
   *  Constant: '<S139>/Constant'
   */
  rtb_Is_Absolute_Translation = rtb_Sin5 == 0.0;

  /* RelationalOperator: '<S140>/Compare' incorporates:
   *  Constant: '<S140>/Constant'
   */
  rtb_Compare_b4c = rtb_Sin5 > 0.0;

  /* Abs: '<S135>/Abs' incorporates:
   *  Sum: '<S135>/Subtract'
   *  UnitDelay: '<S135>/Unit Delay'
   */
  rtb_Minus2 = fabs(Code_Gen_Model_B.Steering_Localized_Cmd - rtb_Switch_ga);

  /* Switch: '<S135>/Switch5' incorporates:
   *  Switch: '<S135>/Switch1'
   */
  if (rtb_Is_Absolute_Translation) {
    /* SignalConversion generated from: '<S135>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S135>/Constant4'
     *  Constant: '<S135>/Constant6'
     */
    rtb_Product7[0] = 0.01;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S135>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S135>/Constant2'
     *  Constant: '<S135>/Constant5'
     */
    rtb_TmpSignalConversionAtLook_o[0] = 0.0;
    rtb_TmpSignalConversionAtLook_o[1] = 0.2;

    /* S-Function (sfix_look1_dyn): '<S135>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S135>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic), &rtb_Product7[0],
                         rtb_Minus2, &rtb_TmpSignalConversionAtLook_o[0], 1U);
    rtb_Minus2 = rtb_LookupTableDynamic;
    rtb_Product_j = Code_Gen_Model_ConstB.UnaryMinus_p;
  } else {
    /* SignalConversion generated from: '<S135>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S135>/Constant10'
     *  Constant: '<S135>/Constant8'
     */
    rtb_Product7[0] = 0.1;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S135>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S135>/Constant7'
     *  Constant: '<S135>/Constant9'
     */
    rtb_TmpSignalConversionAtLook_o[0] = 0.0;
    rtb_TmpSignalConversionAtLook_o[1] = 0.2;

    /* S-Function (sfix_look1_dyn): '<S135>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S135>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1), &rtb_Product7[0],
                         rtb_Minus2, &rtb_TmpSignalConversionAtLook_o[0], 1U);
    rtb_Minus2 = rtb_LookupTableDynamic1;

    /* Switch: '<S135>/Switch3' incorporates:
     *  Constant: '<S135>/Constant3'
     */
    if (rtb_Compare_b4c) {
      rtb_Product_j = 1.0;
    } else {
      rtb_Product_j = Code_Gen_Model_ConstB.UnaryMinus_p;
    }

    /* End of Switch: '<S135>/Switch3' */
  }

  /* End of Switch: '<S135>/Switch5' */

  /* Product: '<S135>/Product' incorporates:
   *  Switch: '<S135>/Switch1'
   */
  rtb_Switch2_g = rtb_Product_j * rtb_Minus2;

  /* Sum: '<S141>/Sum1' */
  rtb_Switch_ga = rtb_Sin5 - rtb_Sin4;

  /* Switch: '<S142>/Switch2' incorporates:
   *  RelationalOperator: '<S142>/LowerRelop1'
   */
  if (!(rtb_Switch_ga > rtb_Switch2_g)) {
    /* Switch: '<S135>/Switch2' incorporates:
     *  Constant: '<S135>/Constant1'
     *  Switch: '<S135>/Switch4'
     */
    if (rtb_Is_Absolute_Translation) {
      rtb_Product_j = -1.0;
    } else if (rtb_Compare_b4c) {
      /* Switch: '<S135>/Switch4' incorporates:
       *  Constant: '<S135>/Constant1'
       */
      rtb_Product_j = -1.0;
    } else {
      rtb_Product_j = Code_Gen_Model_ConstB.UnaryMinus1;
    }

    /* Product: '<S135>/Product2' incorporates:
     *  Switch: '<S135>/Switch2'
     */
    rtb_Switch2_g = rtb_Product_j * rtb_Minus2;

    /* Switch: '<S142>/Switch' incorporates:
     *  RelationalOperator: '<S142>/UpperRelop'
     */
    if (!(rtb_Switch_ga < rtb_Switch2_g)) {
      rtb_Switch2_g = rtb_Switch_ga;
    }

    /* End of Switch: '<S142>/Switch' */
  }

  /* End of Switch: '<S142>/Switch2' */

  /* Sum: '<S141>/Sum' */
  Code_Gen_Model_B.Steering_Localized_Cmd = rtb_Switch2_g + rtb_Sin4;

  /* Fcn: '<S156>/r->x' incorporates:
   *  Fcn: '<S161>/r->x'
   *  Fcn: '<S166>/r->x'
   *  Fcn: '<S171>/r->x'
   */
  rtb_Minus2 = Code_Gen_Model_B.Translation_Speed * cos
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S150>/Add' incorporates:
   *  Fcn: '<S156>/r->x'
   *  Fcn: '<S157>/r->x'
   */
  rtb_Product7[0] = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.FL_Tangent_Angle) + rtb_Minus2;

  /* Fcn: '<S156>/theta->y' incorporates:
   *  Fcn: '<S161>/theta->y'
   *  Fcn: '<S166>/theta->y'
   *  Fcn: '<S171>/theta->y'
   */
  rtb_Total_Limited_j = Code_Gen_Model_B.Translation_Speed * sin
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S150>/Add' incorporates:
   *  Fcn: '<S156>/theta->y'
   *  Fcn: '<S157>/theta->y'
   */
  rtb_Product7[1] = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.FL_Tangent_Angle) + rtb_Total_Limited_j;

  /* Sum: '<S151>/Add' incorporates:
   *  Fcn: '<S162>/r->x'
   *  Fcn: '<S162>/theta->y'
   */
  rtb_TmpSignalConversionAtLook_o[0] = Code_Gen_Model_B.Steering_Localized_Cmd *
    cos(Code_Gen_Model_ConstB.FR_Tangent_Angle) + rtb_Minus2;
  rtb_TmpSignalConversionAtLook_o[1] = Code_Gen_Model_B.Steering_Localized_Cmd *
    sin(Code_Gen_Model_ConstB.FR_Tangent_Angle) + rtb_Total_Limited_j;

  /* Sum: '<S152>/Add' incorporates:
   *  Fcn: '<S167>/r->x'
   *  Fcn: '<S167>/theta->y'
   */
  rtb_Add_f_idx_0 = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.BL_Tangent_Angle) + rtb_Minus2;
  rtb_Add_f_idx_1 = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.BL_Tangent_Angle) + rtb_Total_Limited_j;

  /* Sum: '<S153>/Add' incorporates:
   *  Fcn: '<S172>/r->x'
   *  Fcn: '<S172>/theta->y'
   */
  rtb_Minus2 += Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.BR_Tangent_Angle);
  rtb_Switch_ga = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.BR_Tangent_Angle) + rtb_Total_Limited_j;

  /* Fcn: '<S170>/x->r' */
  rtb_Total_Limited_j = rt_hypotd_snf(rtb_Minus2, rtb_Switch_ga);

  /* Switch: '<S169>/Switch1' incorporates:
   *  Constant: '<S169>/Constant'
   *  Constant: '<S173>/Constant'
   *  RelationalOperator: '<S173>/Compare'
   *  Switch: '<S169>/Switch'
   */
  if (rtb_Total_Limited_j == 0.0) {
    rtb_Switch2_g = 1.0E-15;
  } else {
    rtb_Switch2_g = rtb_Total_Limited_j;

    /* Switch: '<S169>/Switch' incorporates:
     *  Fcn: '<S170>/x->theta'
     */
    Code_Gen_Model_B.Desired_Module_Angle = rt_atan2d_snf(rtb_Switch_ga,
      rtb_Minus2);
  }

  /* End of Switch: '<S169>/Switch1' */

  /* Trigonometry: '<S119>/Cos4' incorporates:
   *  Switch: '<S102>/Angle_Switch'
   *  Trigonometry: '<S118>/Cos4'
   */
  rtb_Subtract_n = cos(Code_Gen_Model_B.Desired_Module_Angle);

  /* Abs: '<S101>/Abs' incorporates:
   *  Inport: '<Root>/BackRight_Steer_Encoder'
   */
  Code_Gen_Model_ModulobyConstant(fabs(Code_Gen_Model_U.BackRight_Steer_Encoder),
    &Code_Gen_Model_B.ModulobyConstant_nq);

  /* Switch: '<S101>/Switch' incorporates:
   *  Constant: '<S115>/Constant'
   *  Inport: '<Root>/BackRight_Steer_Encoder'
   *  RelationalOperator: '<S115>/Compare'
   *  UnaryMinus: '<S101>/Unary Minus'
   */
  if (Code_Gen_Model_U.BackRight_Steer_Encoder >= 0.0) {
    rtb_Minus2 = Code_Gen_Model_B.ModulobyConstant_nq.ModulobyConstant;
  } else {
    rtb_Minus2 = -Code_Gen_Model_B.ModulobyConstant_nq.ModulobyConstant;
  }

  /* End of Switch: '<S101>/Switch' */

  /* Sum: '<S100>/Add' incorporates:
   *  Inport: '<Root>/BackRight_Turn_Offset'
   */
  rtb_Minus2 -= Code_Gen_Model_U.BackRight_Turn_Offset;

  /* Abs: '<S113>/Abs' */
  Code_Gen_Model_ModulobyConstant(fabs(rtb_Minus2),
    &Code_Gen_Model_B.ModulobyConstant_j);

  /* Switch: '<S113>/Switch' incorporates:
   *  Constant: '<S114>/Constant'
   *  RelationalOperator: '<S114>/Compare'
   *  UnaryMinus: '<S113>/Unary Minus'
   */
  if (rtb_Minus2 >= 0.0) {
    rtb_Product_j = Code_Gen_Model_B.ModulobyConstant_j.ModulobyConstant;
  } else {
    rtb_Product_j = -Code_Gen_Model_B.ModulobyConstant_j.ModulobyConstant;
  }

  /* Gain: '<S100>/Gain' incorporates:
   *  Switch: '<S113>/Switch'
   */
  rtb_Minus2 = 6.2831853071795862 * rtb_Product_j;

  /* Trigonometry: '<S119>/Sin5' incorporates:
   *  UnaryMinus: '<S117>/Unary Minus'
   */
  rtb_Sin5 = sin(-rtb_Minus2);

  /* Trigonometry: '<S119>/Sin4' incorporates:
   *  Switch: '<S102>/Angle_Switch'
   *  Trigonometry: '<S118>/Sin4'
   */
  rtb_Product_j = sin(Code_Gen_Model_B.Desired_Module_Angle);

  /* Trigonometry: '<S119>/Cos5' incorporates:
   *  UnaryMinus: '<S117>/Unary Minus'
   */
  rtb_Switch2_h4 = cos(-rtb_Minus2);

  /* Sum: '<S119>/Subtract1' incorporates:
   *  Product: '<S119>/Product2'
   *  Product: '<S119>/Product3'
   *  Trigonometry: '<S119>/Cos4'
   *  Trigonometry: '<S119>/Sin4'
   */
  rtb_Switch_ga = rtb_Subtract_n * rtb_Sin5 + rtb_Product_j * rtb_Switch2_h4;

  /* Sum: '<S119>/Subtract' incorporates:
   *  Product: '<S119>/Product'
   *  Product: '<S119>/Product1'
   *  Trigonometry: '<S119>/Cos4'
   *  Trigonometry: '<S119>/Sin4'
   */
  rtb_Sin4 = rtb_Subtract_n * rtb_Switch2_h4 - rtb_Product_j * rtb_Sin5;

  /* Math: '<S119>/Hypot' */
  rtb_Modulation_Drv_X = rt_hypotd_snf(rtb_Sin4, rtb_Switch_ga);

  /* Switch: '<S119>/Switch' incorporates:
   *  Constant: '<S119>/Constant'
   *  Constant: '<S119>/Constant1'
   *  Constant: '<S120>/Constant'
   *  Product: '<S119>/Divide'
   *  Product: '<S119>/Divide1'
   *  RelationalOperator: '<S120>/Compare'
   *  Switch: '<S119>/Switch1'
   */
  if (rtb_Modulation_Drv_X > 1.0E-6) {
    rtb_Total_Limited_j = rtb_Switch_ga / rtb_Modulation_Drv_X;
    rtb_Switch2_h4 = rtb_Sin4 / rtb_Modulation_Drv_X;
  } else {
    rtb_Total_Limited_j = 0.0;
    rtb_Switch2_h4 = 1.0;
  }

  /* End of Switch: '<S119>/Switch' */

  /* RelationalOperator: '<S116>/Compare' incorporates:
   *  Abs: '<S102>/Abs'
   *  Constant: '<S116>/Constant'
   *  Trigonometry: '<S119>/Atan1'
   */
  rtb_Compare_b4c = fabs(rt_atan2d_snf(rtb_Total_Limited_j, rtb_Switch2_h4)) >
    1.5707963267948966;

  /* Switch: '<S102>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S102>/Unary Minus'
   */
  if (rtb_Compare_b4c) {
    rtb_Switch2_g = -rtb_Switch2_g;
  }

  /* Product: '<S105>/Product2' incorporates:
   *  Constant: '<S105>/Constant'
   *  Switch: '<S102>/Speed_Switch'
   */
  Code_Gen_Model_B.Optimized_Motor_Speed = rtb_Switch2_g * 1530.1401357649195;

  /* Switch: '<S102>/Angle_Switch' */
  if (rtb_Compare_b4c) {
    /* Sum: '<S118>/Subtract1' incorporates:
     *  Product: '<S118>/Product2'
     *  Product: '<S118>/Product3'
     */
    rtb_Switch2_g = rtb_Subtract_n * Code_Gen_Model_ConstB.Sin5_c +
      rtb_Product_j * Code_Gen_Model_ConstB.Cos5_b;

    /* Sum: '<S118>/Subtract' incorporates:
     *  Product: '<S118>/Product'
     *  Product: '<S118>/Product1'
     */
    rtb_Sin4 = rtb_Subtract_n * Code_Gen_Model_ConstB.Cos5_b - rtb_Product_j *
      Code_Gen_Model_ConstB.Sin5_c;

    /* Math: '<S118>/Hypot' */
    rtb_Switch_ga = rt_hypotd_snf(rtb_Sin4, rtb_Switch2_g);

    /* Switch: '<S118>/Switch1' incorporates:
     *  Constant: '<S118>/Constant'
     *  Constant: '<S118>/Constant1'
     *  Constant: '<S121>/Constant'
     *  Product: '<S118>/Divide'
     *  Product: '<S118>/Divide1'
     *  RelationalOperator: '<S121>/Compare'
     *  Switch: '<S118>/Switch'
     */
    if (rtb_Switch_ga > 1.0E-6) {
      rtb_Sin4 /= rtb_Switch_ga;
      rtb_Switch2_g /= rtb_Switch_ga;
    } else {
      rtb_Sin4 = 1.0;
      rtb_Switch2_g = 0.0;
    }

    /* End of Switch: '<S118>/Switch1' */

    /* Switch: '<S102>/Angle_Switch' incorporates:
     *  Trigonometry: '<S118>/Atan1'
     */
    Code_Gen_Model_B.Optimized_Module_Angle = rt_atan2d_snf(rtb_Switch2_g,
      rtb_Sin4);
  } else {
    /* Switch: '<S102>/Angle_Switch' */
    Code_Gen_Model_B.Optimized_Module_Angle =
      Code_Gen_Model_B.Desired_Module_Angle;
  }

  /* Signum: '<S103>/Sign' */
  if (rtIsNaN(Code_Gen_Model_B.Optimized_Motor_Speed)) {
    rtb_Product_j = (rtNaN);
  } else if (Code_Gen_Model_B.Optimized_Motor_Speed < 0.0) {
    rtb_Product_j = -1.0;
  } else {
    rtb_Product_j = Code_Gen_Model_B.Optimized_Motor_Speed > 0.0;
  }

  /* Signum: '<S103>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Encoder'
   */
  if (rtIsNaN(Code_Gen_Model_U.BackRight_Drive_Encoder)) {
    rtb_Sin5 = (rtNaN);
  } else if (Code_Gen_Model_U.BackRight_Drive_Encoder < 0.0) {
    rtb_Sin5 = -1.0;
  } else {
    rtb_Sin5 = Code_Gen_Model_U.BackRight_Drive_Encoder > 0.0;
  }

  /* Switch: '<S103>/Switch' incorporates:
   *  Abs: '<S103>/Abs'
   *  Constant: '<S103>/Constant'
   *  Constant: '<S122>/Constant'
   *  Inport: '<Root>/BackRight_Drive_Encoder'
   *  Logic: '<S103>/OR'
   *  RelationalOperator: '<S103>/Equal1'
   *  RelationalOperator: '<S122>/Compare'
   *  Signum: '<S103>/Sign'
   *  Signum: '<S103>/Sign1'
   */
  if (rtb_Product_j == rtb_Sin5 || fabs(Code_Gen_Model_U.BackRight_Drive_Encoder)
      <= 600.0) {
    rtb_Product_j = Code_Gen_Model_B.Optimized_Motor_Speed;
  } else {
    rtb_Product_j = 0.0;
  }

  /* Sum: '<S104>/Add' incorporates:
   *  Sum: '<S98>/Sum'
   */
  rtb_Minus2 = Code_Gen_Model_B.Optimized_Module_Angle - rtb_Minus2;

  /* Product: '<S21>/Product' incorporates:
   *  Abs: '<S104>/Abs'
   *  Lookup_n-D: '<S104>/1-D Lookup Table'
   *  Sum: '<S104>/Add'
   *  Switch: '<S103>/Switch'
   */
  rtb_Total_Limited_j = look1_binlcpw(fabs(rtb_Minus2),
    Code_Gen_Model_ConstP.pooled26, Code_Gen_Model_ConstP.pooled25, 1U) *
    rtb_Product_j;

  /* Gain: '<S99>/Gain' */
  rtb_Sin4 = 0.00018181818181818181 * rtb_Total_Limited_j;

  /* Sum: '<S99>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Encoder'
   */
  rtb_Total_Limited_j -= Code_Gen_Model_U.BackRight_Drive_Encoder;

  /* Sum: '<S111>/Sum1' incorporates:
   *  Constant: '<S99>/Constant2'
   *  Product: '<S111>/Product'
   *  Sum: '<S111>/Sum'
   *  UnitDelay: '<S111>/Unit Delay1'
   */
  rtb_Switch2_g = (rtb_Total_Limited_j - Code_Gen_Model_DW.UnitDelay1_DSTATE_k) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_k;

  /* Product: '<S99>/Product' incorporates:
   *  Constant: '<S99>/Constant3'
   */
  rtb_Switch_ga = rtb_Switch2_g * 9.9999999999999991E-5;

  /* Sum: '<S110>/Diff' incorporates:
   *  UnitDelay: '<S110>/UD'
   *
   * Block description for '<S110>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S110>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_kl = rtb_Switch_ga - Code_Gen_Model_DW.UD_DSTATE_cs;

  /* Saturate: '<S99>/Saturation' */
  if (rtb_Add_kl > 0.2) {
    rtb_Add_kl = 0.2;
  } else if (rtb_Add_kl < -0.2) {
    rtb_Add_kl = -0.2;
  }

  /* Sum: '<S99>/Add' incorporates:
   *  Gain: '<S99>/Gain1'
   *  Saturate: '<S99>/Saturation'
   */
  rtb_Modulation_Drv_X = 5.0E-6 * rtb_Total_Limited_j + rtb_Sin4 + rtb_Add_kl;

  /* Sum: '<S99>/Subtract' incorporates:
   *  Constant: '<S99>/Constant'
   */
  rtb_Switch2_h4 = 1.0 - rtb_Modulation_Drv_X;

  /* Sum: '<S99>/Sum2' incorporates:
   *  Gain: '<S99>/Gain2'
   *  UnitDelay: '<S99>/Unit Delay'
   */
  rtb_Sin4 = 0.0 * rtb_Total_Limited_j + Code_Gen_Model_DW.UnitDelay_DSTATE_a;

  /* Switch: '<S112>/Switch2' incorporates:
   *  Constant: '<S99>/Constant'
   *  RelationalOperator: '<S112>/LowerRelop1'
   *  Sum: '<S99>/Subtract'
   */
  if (!(rtb_Sin4 > 1.0 - rtb_Modulation_Drv_X)) {
    /* Switch: '<S112>/Switch' incorporates:
     *  Constant: '<S99>/Constant1'
     *  RelationalOperator: '<S112>/UpperRelop'
     *  Sum: '<S99>/Subtract1'
     */
    if (rtb_Sin4 < -1.0 - rtb_Modulation_Drv_X) {
      rtb_Switch2_h4 = -1.0 - rtb_Modulation_Drv_X;
    } else {
      rtb_Switch2_h4 = rtb_Sin4;
    }

    /* End of Switch: '<S112>/Switch' */
  }

  /* End of Switch: '<S112>/Switch2' */

  /* Saturate: '<S99>/Saturation1' */
  if (rtb_Switch2_h4 > 0.0) {
    rtb_Sin4 = 0.0;
  } else if (rtb_Switch2_h4 < -0.0) {
    rtb_Sin4 = -0.0;
  } else {
    rtb_Sin4 = rtb_Switch2_h4;
  }

  /* End of Saturate: '<S99>/Saturation1' */

  /* Sum: '<S99>/Add1' */
  rtb_Add_kl = rtb_Modulation_Drv_X + rtb_Sin4;

  /* Saturate: '<S99>/Saturation2' */
  if (rtb_Add_kl > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_kl < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = rtb_Add_kl;
  }

  /* End of Saturate: '<S99>/Saturation2' */

  /* Sum: '<S109>/Subtract1' incorporates:
   *  Product: '<S109>/Divide'
   *  Product: '<S109>/Product'
   *  Rounding: '<S109>/Fix'
   *  Sum: '<S109>/Minus'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.UnaryMinus_e) /
                      Code_Gen_Model_ConstB.Modulus_i) *
    Code_Gen_Model_ConstB.Modulus_i;

  /* Sum: '<S109>/Minus2' incorporates:
   *  Constant: '<S21>/Constant1'
   *  Product: '<S109>/Divide1'
   *  Product: '<S109>/Product1'
   *  Rounding: '<S109>/Fix1'
   *  Sum: '<S109>/Minus1'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - 3.1415926535897931) /
                      Code_Gen_Model_ConstB.Modulus_i) *
    Code_Gen_Model_ConstB.Modulus_i;

  /* Sum: '<S107>/Sum1' incorporates:
   *  Constant: '<S98>/Constant2'
   *  Product: '<S107>/Product'
   *  Sum: '<S107>/Sum'
   *  UnitDelay: '<S107>/Unit Delay1'
   */
  rtb_Modulation_Drv_X = (rtb_Minus2 - Code_Gen_Model_DW.UnitDelay1_DSTATE_i) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S98>/Product' incorporates:
   *  Constant: '<S98>/Constant3'
   */
  rtb_Subtract1_lg = rtb_Modulation_Drv_X * 0.5;

  /* Sum: '<S106>/Diff' incorporates:
   *  UnitDelay: '<S106>/UD'
   *
   * Block description for '<S106>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S106>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_kl = rtb_Subtract1_lg - Code_Gen_Model_DW.UD_DSTATE_l;

  /* Saturate: '<S98>/Saturation' */
  if (rtb_Add_kl > 0.2) {
    rtb_Add_kl = 0.2;
  } else if (rtb_Add_kl < -0.2) {
    rtb_Add_kl = -0.2;
  }

  /* Sum: '<S98>/Add' incorporates:
   *  Gain: '<S98>/Gain1'
   *  Saturate: '<S98>/Saturation'
   */
  rtb_Add_p = 0.15 * rtb_Minus2 + rtb_Add_kl;

  /* Sum: '<S98>/Subtract' incorporates:
   *  Constant: '<S98>/Constant'
   */
  rtb_Total_Limited_j = 1.0 - rtb_Add_p;

  /* Sum: '<S98>/Sum2' incorporates:
   *  Gain: '<S98>/Gain2'
   *  UnitDelay: '<S98>/Unit Delay'
   */
  rtb_Minus2 = 0.005 * rtb_Minus2 + Code_Gen_Model_DW.UnitDelay_DSTATE_l;

  /* Switch: '<S108>/Switch2' incorporates:
   *  Constant: '<S98>/Constant'
   *  RelationalOperator: '<S108>/LowerRelop1'
   *  Sum: '<S98>/Subtract'
   */
  if (!(rtb_Minus2 > 1.0 - rtb_Add_p)) {
    /* Switch: '<S108>/Switch' incorporates:
     *  Constant: '<S98>/Constant1'
     *  RelationalOperator: '<S108>/UpperRelop'
     *  Sum: '<S98>/Subtract1'
     */
    if (rtb_Minus2 < -1.0 - rtb_Add_p) {
      rtb_Total_Limited_j = -1.0 - rtb_Add_p;
    } else {
      rtb_Total_Limited_j = rtb_Minus2;
    }

    /* End of Switch: '<S108>/Switch' */
  }

  /* End of Switch: '<S108>/Switch2' */

  /* Saturate: '<S98>/Saturation1' */
  if (rtb_Total_Limited_j > 0.005) {
    rtb_Subtract1_b = 0.005;
  } else if (rtb_Total_Limited_j < -0.005) {
    rtb_Subtract1_b = -0.005;
  } else {
    rtb_Subtract1_b = rtb_Total_Limited_j;
  }

  /* End of Saturate: '<S98>/Saturation1' */

  /* Sum: '<S98>/Add1' */
  rtb_Add_kl = rtb_Add_p + rtb_Subtract1_b;

  /* Saturate: '<S98>/Saturation2' */
  if (rtb_Add_kl > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_kl < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = rtb_Add_kl;
  }

  /* End of Saturate: '<S98>/Saturation2' */

  /* Fcn: '<S165>/x->r' */
  rtb_Total_Limited_j = rt_hypotd_snf(rtb_Add_f_idx_0, rtb_Add_f_idx_1);

  /* Switch: '<S164>/Switch1' incorporates:
   *  Constant: '<S164>/Constant'
   *  Constant: '<S168>/Constant'
   *  RelationalOperator: '<S168>/Compare'
   *  Switch: '<S164>/Switch'
   */
  if (rtb_Total_Limited_j == 0.0) {
    rtb_Add_p = 1.0E-15;
  } else {
    rtb_Add_p = rtb_Total_Limited_j;

    /* Switch: '<S164>/Switch' incorporates:
     *  Fcn: '<S165>/x->theta'
     */
    Code_Gen_Model_B.Desired_Module_Angle_l = rt_atan2d_snf(rtb_Add_f_idx_1,
      rtb_Add_f_idx_0);
  }

  /* End of Switch: '<S164>/Switch1' */

  /* Trigonometry: '<S94>/Cos4' incorporates:
   *  Switch: '<S77>/Angle_Switch'
   *  Trigonometry: '<S93>/Cos4'
   */
  rtb_Subtract_n = cos(Code_Gen_Model_B.Desired_Module_Angle_l);

  /* Abs: '<S76>/Abs' incorporates:
   *  Inport: '<Root>/BackLeft_Steer_Encoder'
   */
  Code_Gen_Model_ModulobyConstant(fabs(Code_Gen_Model_U.BackLeft_Steer_Encoder),
    &Code_Gen_Model_B.ModulobyConstant_ns);

  /* Switch: '<S76>/Switch' incorporates:
   *  Constant: '<S90>/Constant'
   *  Inport: '<Root>/BackLeft_Steer_Encoder'
   *  RelationalOperator: '<S90>/Compare'
   *  UnaryMinus: '<S76>/Unary Minus'
   */
  if (Code_Gen_Model_U.BackLeft_Steer_Encoder >= 0.0) {
    rtb_Minus2 = Code_Gen_Model_B.ModulobyConstant_ns.ModulobyConstant;
  } else {
    rtb_Minus2 = -Code_Gen_Model_B.ModulobyConstant_ns.ModulobyConstant;
  }

  /* End of Switch: '<S76>/Switch' */

  /* Sum: '<S75>/Add' incorporates:
   *  Inport: '<Root>/BackLeft_Turn_Offset'
   */
  rtb_Minus2 -= Code_Gen_Model_U.BackLeft_Turn_Offset;

  /* Abs: '<S88>/Abs' */
  Code_Gen_Model_ModulobyConstant(fabs(rtb_Minus2),
    &Code_Gen_Model_B.ModulobyConstant_l);

  /* Switch: '<S88>/Switch' incorporates:
   *  Constant: '<S89>/Constant'
   *  RelationalOperator: '<S89>/Compare'
   *  UnaryMinus: '<S88>/Unary Minus'
   */
  if (rtb_Minus2 >= 0.0) {
    rtb_Product_j = Code_Gen_Model_B.ModulobyConstant_l.ModulobyConstant;
  } else {
    rtb_Product_j = -Code_Gen_Model_B.ModulobyConstant_l.ModulobyConstant;
  }

  /* Gain: '<S75>/Gain' incorporates:
   *  Switch: '<S88>/Switch'
   */
  rtb_Minus2 = 6.2831853071795862 * rtb_Product_j;

  /* Trigonometry: '<S94>/Sin5' incorporates:
   *  UnaryMinus: '<S92>/Unary Minus'
   */
  rtb_Sin5 = sin(-rtb_Minus2);

  /* Trigonometry: '<S94>/Sin4' incorporates:
   *  Switch: '<S77>/Angle_Switch'
   *  Trigonometry: '<S93>/Sin4'
   */
  rtb_Product_j = sin(Code_Gen_Model_B.Desired_Module_Angle_l);

  /* Trigonometry: '<S94>/Cos5' incorporates:
   *  UnaryMinus: '<S92>/Unary Minus'
   */
  rtb_Switch2_h4 = cos(-rtb_Minus2);

  /* Sum: '<S94>/Subtract1' incorporates:
   *  Product: '<S94>/Product2'
   *  Product: '<S94>/Product3'
   *  Trigonometry: '<S94>/Cos4'
   *  Trigonometry: '<S94>/Sin4'
   */
  rtb_Add_f_idx_0 = rtb_Subtract_n * rtb_Sin5 + rtb_Product_j * rtb_Switch2_h4;

  /* Sum: '<S94>/Subtract' incorporates:
   *  Product: '<S94>/Product'
   *  Product: '<S94>/Product1'
   *  Trigonometry: '<S94>/Cos4'
   *  Trigonometry: '<S94>/Sin4'
   */
  rtb_Add_f_idx_1 = rtb_Subtract_n * rtb_Switch2_h4 - rtb_Product_j * rtb_Sin5;

  /* Math: '<S94>/Hypot' */
  rtb_Hypot_e = rt_hypotd_snf(rtb_Add_f_idx_1, rtb_Add_f_idx_0);

  /* Switch: '<S94>/Switch' incorporates:
   *  Constant: '<S94>/Constant'
   *  Constant: '<S94>/Constant1'
   *  Constant: '<S95>/Constant'
   *  Product: '<S94>/Divide'
   *  Product: '<S94>/Divide1'
   *  RelationalOperator: '<S95>/Compare'
   *  Switch: '<S94>/Switch1'
   */
  if (rtb_Hypot_e > 1.0E-6) {
    rtb_Total_Limited_j = rtb_Add_f_idx_0 / rtb_Hypot_e;
    rtb_Switch2_h4 = rtb_Add_f_idx_1 / rtb_Hypot_e;
  } else {
    rtb_Total_Limited_j = 0.0;
    rtb_Switch2_h4 = 1.0;
  }

  /* End of Switch: '<S94>/Switch' */

  /* RelationalOperator: '<S91>/Compare' incorporates:
   *  Abs: '<S77>/Abs'
   *  Constant: '<S91>/Constant'
   *  Trigonometry: '<S94>/Atan1'
   */
  rtb_Compare_b4c = fabs(rt_atan2d_snf(rtb_Total_Limited_j, rtb_Switch2_h4)) >
    1.5707963267948966;

  /* Switch: '<S77>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S77>/Unary Minus'
   */
  if (rtb_Compare_b4c) {
    rtb_Add_p = -rtb_Add_p;
  }

  /* Product: '<S80>/Product2' incorporates:
   *  Constant: '<S80>/Constant'
   *  Switch: '<S77>/Speed_Switch'
   */
  Code_Gen_Model_B.Optimized_Motor_Speed_o = rtb_Add_p * 1530.1401357649195;

  /* Switch: '<S77>/Angle_Switch' */
  if (rtb_Compare_b4c) {
    /* Sum: '<S93>/Subtract1' incorporates:
     *  Product: '<S93>/Product2'
     *  Product: '<S93>/Product3'
     */
    rtb_Add_p = rtb_Subtract_n * Code_Gen_Model_ConstB.Sin5_e + rtb_Product_j *
      Code_Gen_Model_ConstB.Cos5_i;

    /* Sum: '<S93>/Subtract' incorporates:
     *  Product: '<S93>/Product'
     *  Product: '<S93>/Product1'
     */
    rtb_Total_Limited_j = rtb_Subtract_n * Code_Gen_Model_ConstB.Cos5_i -
      rtb_Product_j * Code_Gen_Model_ConstB.Sin5_e;

    /* Math: '<S93>/Hypot' */
    rtb_Add_f_idx_0 = rt_hypotd_snf(rtb_Total_Limited_j, rtb_Add_p);

    /* Switch: '<S93>/Switch1' incorporates:
     *  Constant: '<S93>/Constant'
     *  Constant: '<S93>/Constant1'
     *  Constant: '<S96>/Constant'
     *  Product: '<S93>/Divide'
     *  Product: '<S93>/Divide1'
     *  RelationalOperator: '<S96>/Compare'
     *  Switch: '<S93>/Switch'
     */
    if (rtb_Add_f_idx_0 > 1.0E-6) {
      rtb_Total_Limited_j /= rtb_Add_f_idx_0;
      rtb_Add_p /= rtb_Add_f_idx_0;
    } else {
      rtb_Total_Limited_j = 1.0;
      rtb_Add_p = 0.0;
    }

    /* End of Switch: '<S93>/Switch1' */

    /* Switch: '<S77>/Angle_Switch' incorporates:
     *  Trigonometry: '<S93>/Atan1'
     */
    Code_Gen_Model_B.Optimized_Module_Angle_e = rt_atan2d_snf(rtb_Add_p,
      rtb_Total_Limited_j);
  } else {
    /* Switch: '<S77>/Angle_Switch' */
    Code_Gen_Model_B.Optimized_Module_Angle_e =
      Code_Gen_Model_B.Desired_Module_Angle_l;
  }

  /* Signum: '<S78>/Sign' */
  if (rtIsNaN(Code_Gen_Model_B.Optimized_Motor_Speed_o)) {
    rtb_Product_j = (rtNaN);
  } else if (Code_Gen_Model_B.Optimized_Motor_Speed_o < 0.0) {
    rtb_Product_j = -1.0;
  } else {
    rtb_Product_j = Code_Gen_Model_B.Optimized_Motor_Speed_o > 0.0;
  }

  /* Signum: '<S78>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Encoder'
   */
  if (rtIsNaN(Code_Gen_Model_U.BackLeft_Drive_Encoder)) {
    rtb_Sin5 = (rtNaN);
  } else if (Code_Gen_Model_U.BackLeft_Drive_Encoder < 0.0) {
    rtb_Sin5 = -1.0;
  } else {
    rtb_Sin5 = Code_Gen_Model_U.BackLeft_Drive_Encoder > 0.0;
  }

  /* Switch: '<S78>/Switch' incorporates:
   *  Abs: '<S78>/Abs'
   *  Constant: '<S78>/Constant'
   *  Constant: '<S97>/Constant'
   *  Inport: '<Root>/BackLeft_Drive_Encoder'
   *  Logic: '<S78>/OR'
   *  RelationalOperator: '<S78>/Equal1'
   *  RelationalOperator: '<S97>/Compare'
   *  Signum: '<S78>/Sign'
   *  Signum: '<S78>/Sign1'
   */
  if (rtb_Product_j == rtb_Sin5 || fabs(Code_Gen_Model_U.BackLeft_Drive_Encoder)
      <= 600.0) {
    rtb_Product_j = Code_Gen_Model_B.Optimized_Motor_Speed_o;
  } else {
    rtb_Product_j = 0.0;
  }

  /* Sum: '<S79>/Add' incorporates:
   *  Sum: '<S73>/Sum'
   */
  rtb_Minus2 = Code_Gen_Model_B.Optimized_Module_Angle_e - rtb_Minus2;

  /* Product: '<S20>/Product' incorporates:
   *  Abs: '<S79>/Abs'
   *  Lookup_n-D: '<S79>/1-D Lookup Table'
   *  Sum: '<S79>/Add'
   *  Switch: '<S78>/Switch'
   */
  rtb_Total_Limited_j = look1_binlcpw(fabs(rtb_Minus2),
    Code_Gen_Model_ConstP.pooled26, Code_Gen_Model_ConstP.pooled25, 1U) *
    rtb_Product_j;

  /* Gain: '<S74>/Gain' */
  rtb_Add_f_idx_1 = 0.00018181818181818181 * rtb_Total_Limited_j;

  /* Sum: '<S74>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Encoder'
   */
  rtb_Total_Limited_j -= Code_Gen_Model_U.BackLeft_Drive_Encoder;

  /* Sum: '<S86>/Sum1' incorporates:
   *  Constant: '<S74>/Constant2'
   *  Product: '<S86>/Product'
   *  Sum: '<S86>/Sum'
   *  UnitDelay: '<S86>/Unit Delay1'
   */
  rtb_Add_p = (rtb_Total_Limited_j - Code_Gen_Model_DW.UnitDelay1_DSTATE_f) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S74>/Product' incorporates:
   *  Constant: '<S74>/Constant3'
   */
  rtb_Add_f_idx_0 = rtb_Add_p * 9.9999999999999991E-5;

  /* Sum: '<S85>/Diff' incorporates:
   *  UnitDelay: '<S85>/UD'
   *
   * Block description for '<S85>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S85>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_kl = rtb_Add_f_idx_0 - Code_Gen_Model_DW.UD_DSTATE_lh;

  /* Saturate: '<S74>/Saturation' */
  if (rtb_Add_kl > 0.2) {
    rtb_Add_kl = 0.2;
  } else if (rtb_Add_kl < -0.2) {
    rtb_Add_kl = -0.2;
  }

  /* Sum: '<S74>/Add' incorporates:
   *  Gain: '<S74>/Gain1'
   *  Saturate: '<S74>/Saturation'
   */
  rtb_Hypot_e = 5.0E-6 * rtb_Total_Limited_j + rtb_Add_f_idx_1 + rtb_Add_kl;

  /* Sum: '<S74>/Subtract' incorporates:
   *  Constant: '<S74>/Constant'
   */
  rtb_Switch2_h4 = 1.0 - rtb_Hypot_e;

  /* Sum: '<S74>/Sum2' incorporates:
   *  Gain: '<S74>/Gain2'
   *  UnitDelay: '<S74>/Unit Delay'
   */
  rtb_Total_Limited_j = 0.0 * rtb_Total_Limited_j +
    Code_Gen_Model_DW.UnitDelay_DSTATE_gp;

  /* Switch: '<S87>/Switch2' incorporates:
   *  Constant: '<S74>/Constant'
   *  RelationalOperator: '<S87>/LowerRelop1'
   *  Sum: '<S74>/Subtract'
   */
  if (!(rtb_Total_Limited_j > 1.0 - rtb_Hypot_e)) {
    /* Switch: '<S87>/Switch' incorporates:
     *  Constant: '<S74>/Constant1'
     *  RelationalOperator: '<S87>/UpperRelop'
     *  Sum: '<S74>/Subtract1'
     */
    if (rtb_Total_Limited_j < -1.0 - rtb_Hypot_e) {
      rtb_Switch2_h4 = -1.0 - rtb_Hypot_e;
    } else {
      rtb_Switch2_h4 = rtb_Total_Limited_j;
    }

    /* End of Switch: '<S87>/Switch' */
  }

  /* End of Switch: '<S87>/Switch2' */

  /* Saturate: '<S74>/Saturation1' */
  if (rtb_Switch2_h4 > 0.0) {
    rtb_Add_f_idx_1 = 0.0;
  } else if (rtb_Switch2_h4 < -0.0) {
    rtb_Add_f_idx_1 = -0.0;
  } else {
    rtb_Add_f_idx_1 = rtb_Switch2_h4;
  }

  /* End of Saturate: '<S74>/Saturation1' */

  /* Sum: '<S74>/Add1' */
  rtb_Add_kl = rtb_Hypot_e + rtb_Add_f_idx_1;

  /* Saturate: '<S74>/Saturation2' */
  if (rtb_Add_kl > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_kl < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = rtb_Add_kl;
  }

  /* End of Saturate: '<S74>/Saturation2' */

  /* Sum: '<S84>/Subtract1' incorporates:
   *  Product: '<S84>/Divide'
   *  Product: '<S84>/Product'
   *  Rounding: '<S84>/Fix'
   *  Sum: '<S84>/Minus'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.UnaryMinus_m) /
                      Code_Gen_Model_ConstB.Modulus_o) *
    Code_Gen_Model_ConstB.Modulus_o;

  /* Sum: '<S84>/Minus2' incorporates:
   *  Constant: '<S20>/Constant1'
   *  Product: '<S84>/Divide1'
   *  Product: '<S84>/Product1'
   *  Rounding: '<S84>/Fix1'
   *  Sum: '<S84>/Minus1'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - 3.1415926535897931) /
                      Code_Gen_Model_ConstB.Modulus_o) *
    Code_Gen_Model_ConstB.Modulus_o;

  /* Sum: '<S82>/Sum1' incorporates:
   *  Constant: '<S73>/Constant2'
   *  Product: '<S82>/Product'
   *  Sum: '<S82>/Sum'
   *  UnitDelay: '<S82>/Unit Delay1'
   */
  rtb_Hypot_e = (rtb_Minus2 - Code_Gen_Model_DW.UnitDelay1_DSTATE_n) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S73>/Product' incorporates:
   *  Constant: '<S73>/Constant3'
   */
  rtb_Product_lf = rtb_Hypot_e * 0.5;

  /* Sum: '<S81>/Diff' incorporates:
   *  UnitDelay: '<S81>/UD'
   *
   * Block description for '<S81>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S81>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_kl = rtb_Product_lf - Code_Gen_Model_DW.UD_DSTATE_k;

  /* Saturate: '<S73>/Saturation' */
  if (rtb_Add_kl > 0.2) {
    rtb_Add_kl = 0.2;
  } else if (rtb_Add_kl < -0.2) {
    rtb_Add_kl = -0.2;
  }

  /* Sum: '<S73>/Add' incorporates:
   *  Gain: '<S73>/Gain1'
   *  Saturate: '<S73>/Saturation'
   */
  rtb_Add_b0 = 0.15 * rtb_Minus2 + rtb_Add_kl;

  /* Sum: '<S73>/Subtract' incorporates:
   *  Constant: '<S73>/Constant'
   */
  rtb_Total_Limited_j = 1.0 - rtb_Add_b0;

  /* Sum: '<S73>/Sum2' incorporates:
   *  Gain: '<S73>/Gain2'
   *  UnitDelay: '<S73>/Unit Delay'
   */
  rtb_Minus2 = 0.005 * rtb_Minus2 + Code_Gen_Model_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S83>/Switch2' incorporates:
   *  Constant: '<S73>/Constant'
   *  RelationalOperator: '<S83>/LowerRelop1'
   *  Sum: '<S73>/Subtract'
   */
  if (!(rtb_Minus2 > 1.0 - rtb_Add_b0)) {
    /* Sum: '<S73>/Subtract1' incorporates:
     *  Constant: '<S73>/Constant1'
     */
    rtb_Total_Limited_j = -1.0 - rtb_Add_b0;

    /* Switch: '<S83>/Switch' incorporates:
     *  Constant: '<S73>/Constant1'
     *  RelationalOperator: '<S83>/UpperRelop'
     *  Sum: '<S73>/Subtract1'
     */
    if (!(rtb_Minus2 < -1.0 - rtb_Add_b0)) {
      rtb_Total_Limited_j = rtb_Minus2;
    }

    /* End of Switch: '<S83>/Switch' */
  }

  /* End of Switch: '<S83>/Switch2' */

  /* Saturate: '<S73>/Saturation1' */
  if (rtb_Total_Limited_j > 0.005) {
    rtb_Integral_g = 0.005;
  } else if (rtb_Total_Limited_j < -0.005) {
    rtb_Integral_g = -0.005;
  } else {
    rtb_Integral_g = rtb_Total_Limited_j;
  }

  /* End of Saturate: '<S73>/Saturation1' */

  /* Sum: '<S73>/Add1' */
  rtb_Add_kl = rtb_Add_b0 + rtb_Integral_g;

  /* Saturate: '<S73>/Saturation2' */
  if (rtb_Add_kl > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_kl < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = rtb_Add_kl;
  }

  /* End of Saturate: '<S73>/Saturation2' */

  /* Fcn: '<S160>/x->r' */
  rtb_Total_Limited_j = rt_hypotd_snf(rtb_TmpSignalConversionAtLook_o[0],
    rtb_TmpSignalConversionAtLook_o[1]);

  /* Switch: '<S159>/Switch1' incorporates:
   *  Constant: '<S159>/Constant'
   *  Constant: '<S163>/Constant'
   *  RelationalOperator: '<S163>/Compare'
   *  Switch: '<S159>/Switch'
   */
  if (rtb_Total_Limited_j == 0.0) {
    rtb_Add_b0 = 1.0E-15;
  } else {
    rtb_Add_b0 = rtb_Total_Limited_j;

    /* Switch: '<S159>/Switch' incorporates:
     *  Fcn: '<S160>/x->theta'
     */
    Code_Gen_Model_B.Desired_Module_Angle_lh = rt_atan2d_snf
      (rtb_TmpSignalConversionAtLook_o[1], rtb_TmpSignalConversionAtLook_o[0]);
  }

  /* End of Switch: '<S159>/Switch1' */

  /* Trigonometry: '<S69>/Cos4' incorporates:
   *  Switch: '<S52>/Angle_Switch'
   *  Trigonometry: '<S68>/Cos4'
   */
  rtb_Subtract_n = cos(Code_Gen_Model_B.Desired_Module_Angle_lh);

  /* Abs: '<S51>/Abs' incorporates:
   *  Inport: '<Root>/FrontRight_Steer_Encoder'
   */
  Code_Gen_Model_ModulobyConstant(fabs(Code_Gen_Model_U.FrontRight_Steer_Encoder),
    &Code_Gen_Model_B.ModulobyConstant_g);

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S65>/Constant'
   *  Inport: '<Root>/FrontRight_Steer_Encoder'
   *  RelationalOperator: '<S65>/Compare'
   *  UnaryMinus: '<S51>/Unary Minus'
   */
  if (Code_Gen_Model_U.FrontRight_Steer_Encoder >= 0.0) {
    rtb_Minus2 = Code_Gen_Model_B.ModulobyConstant_g.ModulobyConstant;
  } else {
    rtb_Minus2 = -Code_Gen_Model_B.ModulobyConstant_g.ModulobyConstant;
  }

  /* End of Switch: '<S51>/Switch' */

  /* Sum: '<S50>/Add' incorporates:
   *  Inport: '<Root>/FrontRight_Turn_Offset'
   */
  rtb_Minus2 -= Code_Gen_Model_U.FrontRight_Turn_Offset;

  /* Abs: '<S63>/Abs' */
  Code_Gen_Model_ModulobyConstant(fabs(rtb_Minus2),
    &Code_Gen_Model_B.ModulobyConstant_d);

  /* Switch: '<S63>/Switch' incorporates:
   *  Constant: '<S64>/Constant'
   *  RelationalOperator: '<S64>/Compare'
   *  UnaryMinus: '<S63>/Unary Minus'
   */
  if (rtb_Minus2 >= 0.0) {
    rtb_Product_j = Code_Gen_Model_B.ModulobyConstant_d.ModulobyConstant;
  } else {
    rtb_Product_j = -Code_Gen_Model_B.ModulobyConstant_d.ModulobyConstant;
  }

  /* Gain: '<S50>/Gain' incorporates:
   *  Switch: '<S63>/Switch'
   */
  rtb_Minus2 = 6.2831853071795862 * rtb_Product_j;

  /* Trigonometry: '<S69>/Sin5' incorporates:
   *  UnaryMinus: '<S67>/Unary Minus'
   */
  rtb_Sin5 = sin(-rtb_Minus2);

  /* Trigonometry: '<S69>/Sin4' incorporates:
   *  Switch: '<S52>/Angle_Switch'
   *  Trigonometry: '<S68>/Sin4'
   */
  rtb_Product_j = sin(Code_Gen_Model_B.Desired_Module_Angle_lh);

  /* Trigonometry: '<S69>/Cos5' incorporates:
   *  UnaryMinus: '<S67>/Unary Minus'
   */
  rtb_Switch2_h4 = cos(-rtb_Minus2);

  /* Sum: '<S69>/Subtract1' incorporates:
   *  Product: '<S69>/Product2'
   *  Product: '<S69>/Product3'
   *  Trigonometry: '<S69>/Cos4'
   *  Trigonometry: '<S69>/Sin4'
   */
  rtb_Total_Limited_j = rtb_Subtract_n * rtb_Sin5 + rtb_Product_j *
    rtb_Switch2_h4;

  /* Sum: '<S69>/Subtract' incorporates:
   *  Product: '<S69>/Product'
   *  Product: '<S69>/Product1'
   *  Trigonometry: '<S69>/Cos4'
   *  Trigonometry: '<S69>/Sin4'
   */
  rtb_Subtract_pa = rtb_Subtract_n * rtb_Switch2_h4 - rtb_Product_j * rtb_Sin5;

  /* Math: '<S69>/Hypot' */
  rtb_Switch2_h4 = rt_hypotd_snf(rtb_Subtract_pa, rtb_Total_Limited_j);

  /* Switch: '<S69>/Switch' incorporates:
   *  Constant: '<S69>/Constant'
   *  Constant: '<S69>/Constant1'
   *  Constant: '<S70>/Constant'
   *  Product: '<S69>/Divide'
   *  Product: '<S69>/Divide1'
   *  RelationalOperator: '<S70>/Compare'
   *  Switch: '<S69>/Switch1'
   */
  if (rtb_Switch2_h4 > 1.0E-6) {
    rtb_Total_Limited_j /= rtb_Switch2_h4;
    rtb_Switch2_h4 = rtb_Subtract_pa / rtb_Switch2_h4;
  } else {
    rtb_Total_Limited_j = 0.0;
    rtb_Switch2_h4 = 1.0;
  }

  /* End of Switch: '<S69>/Switch' */

  /* RelationalOperator: '<S66>/Compare' incorporates:
   *  Abs: '<S52>/Abs'
   *  Constant: '<S66>/Constant'
   *  Trigonometry: '<S69>/Atan1'
   */
  rtb_Compare_b4c = fabs(rt_atan2d_snf(rtb_Total_Limited_j, rtb_Switch2_h4)) >
    1.5707963267948966;

  /* Switch: '<S52>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S52>/Unary Minus'
   */
  if (rtb_Compare_b4c) {
    rtb_Add_b0 = -rtb_Add_b0;
  }

  /* Product: '<S55>/Product2' incorporates:
   *  Constant: '<S55>/Constant'
   *  Switch: '<S52>/Speed_Switch'
   */
  Code_Gen_Model_B.Optimized_Motor_Speed_g = rtb_Add_b0 * 1530.1401357649195;

  /* Switch: '<S52>/Angle_Switch' */
  if (rtb_Compare_b4c) {
    /* Sum: '<S68>/Subtract1' incorporates:
     *  Product: '<S68>/Product2'
     *  Product: '<S68>/Product3'
     */
    rtb_Total_Limited_j = rtb_Subtract_n * Code_Gen_Model_ConstB.Sin5_m +
      rtb_Product_j * Code_Gen_Model_ConstB.Cos5_g;

    /* Sum: '<S68>/Subtract' incorporates:
     *  Product: '<S68>/Product'
     *  Product: '<S68>/Product1'
     */
    rtb_Subtract_pa = rtb_Subtract_n * Code_Gen_Model_ConstB.Cos5_g -
      rtb_Product_j * Code_Gen_Model_ConstB.Sin5_m;

    /* Math: '<S68>/Hypot' */
    rtb_Add_b0 = rt_hypotd_snf(rtb_Subtract_pa, rtb_Total_Limited_j);

    /* Switch: '<S68>/Switch1' incorporates:
     *  Constant: '<S68>/Constant'
     *  Constant: '<S68>/Constant1'
     *  Constant: '<S71>/Constant'
     *  Product: '<S68>/Divide'
     *  Product: '<S68>/Divide1'
     *  RelationalOperator: '<S71>/Compare'
     *  Switch: '<S68>/Switch'
     */
    if (rtb_Add_b0 > 1.0E-6) {
      rtb_Subtract_pa /= rtb_Add_b0;
      rtb_Total_Limited_j /= rtb_Add_b0;
    } else {
      rtb_Subtract_pa = 1.0;
      rtb_Total_Limited_j = 0.0;
    }

    /* End of Switch: '<S68>/Switch1' */

    /* Switch: '<S52>/Angle_Switch' incorporates:
     *  Trigonometry: '<S68>/Atan1'
     */
    Code_Gen_Model_B.Optimized_Module_Angle_eg = rt_atan2d_snf
      (rtb_Total_Limited_j, rtb_Subtract_pa);
  } else {
    /* Switch: '<S52>/Angle_Switch' */
    Code_Gen_Model_B.Optimized_Module_Angle_eg =
      Code_Gen_Model_B.Desired_Module_Angle_lh;
  }

  /* Signum: '<S53>/Sign' */
  if (rtIsNaN(Code_Gen_Model_B.Optimized_Motor_Speed_g)) {
    rtb_Product_j = (rtNaN);
  } else if (Code_Gen_Model_B.Optimized_Motor_Speed_g < 0.0) {
    rtb_Product_j = -1.0;
  } else {
    rtb_Product_j = Code_Gen_Model_B.Optimized_Motor_Speed_g > 0.0;
  }

  /* Signum: '<S53>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Encoder'
   */
  if (rtIsNaN(Code_Gen_Model_U.FrontRight_Drive_Encoder)) {
    rtb_Sin5 = (rtNaN);
  } else if (Code_Gen_Model_U.FrontRight_Drive_Encoder < 0.0) {
    rtb_Sin5 = -1.0;
  } else {
    rtb_Sin5 = Code_Gen_Model_U.FrontRight_Drive_Encoder > 0.0;
  }

  /* Switch: '<S53>/Switch' incorporates:
   *  Abs: '<S53>/Abs'
   *  Constant: '<S53>/Constant'
   *  Constant: '<S72>/Constant'
   *  Inport: '<Root>/FrontRight_Drive_Encoder'
   *  Logic: '<S53>/OR'
   *  RelationalOperator: '<S53>/Equal1'
   *  RelationalOperator: '<S72>/Compare'
   *  Signum: '<S53>/Sign'
   *  Signum: '<S53>/Sign1'
   */
  if (rtb_Product_j == rtb_Sin5 || fabs
      (Code_Gen_Model_U.FrontRight_Drive_Encoder) <= 600.0) {
    rtb_Product_j = Code_Gen_Model_B.Optimized_Motor_Speed_g;
  } else {
    rtb_Product_j = 0.0;
  }

  /* Sum: '<S54>/Add' incorporates:
   *  Sum: '<S48>/Sum'
   */
  rtb_Minus2 = Code_Gen_Model_B.Optimized_Module_Angle_eg - rtb_Minus2;

  /* Product: '<S19>/Product' incorporates:
   *  Abs: '<S54>/Abs'
   *  Lookup_n-D: '<S54>/1-D Lookup Table'
   *  Sum: '<S54>/Add'
   *  Switch: '<S53>/Switch'
   */
  rtb_Total_Limited_j = look1_binlcpw(fabs(rtb_Minus2),
    Code_Gen_Model_ConstP.pooled26, Code_Gen_Model_ConstP.pooled25, 1U) *
    rtb_Product_j;

  /* Gain: '<S49>/Gain' */
  rtb_Switch2_h4 = 0.00018181818181818181 * rtb_Total_Limited_j;

  /* Sum: '<S49>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Encoder'
   */
  rtb_Total_Limited_j -= Code_Gen_Model_U.FrontRight_Drive_Encoder;

  /* Sum: '<S61>/Sum1' incorporates:
   *  Constant: '<S49>/Constant2'
   *  Product: '<S61>/Product'
   *  Sum: '<S61>/Sum'
   *  UnitDelay: '<S61>/Unit Delay1'
   */
  rtb_Add_b0 = (rtb_Total_Limited_j - Code_Gen_Model_DW.UnitDelay1_DSTATE_b) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S49>/Product' incorporates:
   *  Constant: '<S49>/Constant3'
   */
  rtb_Subtract_pa = rtb_Add_b0 * 9.9999999999999991E-5;

  /* Sum: '<S60>/Diff' incorporates:
   *  UnitDelay: '<S60>/UD'
   *
   * Block description for '<S60>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S60>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_kl = rtb_Subtract_pa - Code_Gen_Model_DW.UD_DSTATE_e;

  /* Saturate: '<S49>/Saturation' */
  if (rtb_Add_kl > 0.2) {
    rtb_Add_kl = 0.2;
  } else if (rtb_Add_kl < -0.2) {
    rtb_Add_kl = -0.2;
  }

  /* Sum: '<S49>/Add' incorporates:
   *  Gain: '<S49>/Gain1'
   *  Saturate: '<S49>/Saturation'
   */
  rtb_Add_k = 5.0E-6 * rtb_Total_Limited_j + rtb_Switch2_h4 + rtb_Add_kl;

  /* Sum: '<S49>/Subtract' incorporates:
   *  Constant: '<S49>/Constant'
   */
  rtb_Switch2_h4 = 1.0 - rtb_Add_k;

  /* Sum: '<S49>/Sum2' incorporates:
   *  Gain: '<S49>/Gain2'
   *  UnitDelay: '<S49>/Unit Delay'
   */
  rtb_Total_Limited_j = 0.0 * rtb_Total_Limited_j +
    Code_Gen_Model_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S62>/Switch2' incorporates:
   *  Constant: '<S49>/Constant'
   *  RelationalOperator: '<S62>/LowerRelop1'
   *  Sum: '<S49>/Subtract'
   */
  if (!(rtb_Total_Limited_j > 1.0 - rtb_Add_k)) {
    /* Sum: '<S49>/Subtract1' incorporates:
     *  Constant: '<S49>/Constant1'
     */
    rtb_Switch2_h4 = -1.0 - rtb_Add_k;

    /* Switch: '<S62>/Switch' incorporates:
     *  Constant: '<S49>/Constant1'
     *  RelationalOperator: '<S62>/UpperRelop'
     *  Sum: '<S49>/Subtract1'
     */
    if (!(rtb_Total_Limited_j < -1.0 - rtb_Add_k)) {
      rtb_Switch2_h4 = rtb_Total_Limited_j;
    }

    /* End of Switch: '<S62>/Switch' */
  }

  /* End of Switch: '<S62>/Switch2' */

  /* Saturate: '<S49>/Saturation1' */
  if (rtb_Switch2_h4 > 0.0) {
    rtb_Integral_f = 0.0;
  } else if (rtb_Switch2_h4 < -0.0) {
    rtb_Integral_f = -0.0;
  } else {
    rtb_Integral_f = rtb_Switch2_h4;
  }

  /* End of Saturate: '<S49>/Saturation1' */

  /* Sum: '<S49>/Add1' */
  rtb_Add_kl = rtb_Add_k + rtb_Integral_f;

  /* Saturate: '<S49>/Saturation2' */
  if (rtb_Add_kl > 1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_kl < -1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = rtb_Add_kl;
  }

  /* End of Saturate: '<S49>/Saturation2' */

  /* Sum: '<S59>/Subtract1' incorporates:
   *  Product: '<S59>/Divide'
   *  Product: '<S59>/Product'
   *  Rounding: '<S59>/Fix'
   *  Sum: '<S59>/Minus'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.UnaryMinus_j) /
                      Code_Gen_Model_ConstB.Modulus_d) *
    Code_Gen_Model_ConstB.Modulus_d;

  /* Sum: '<S59>/Minus2' incorporates:
   *  Constant: '<S19>/Constant1'
   *  Product: '<S59>/Divide1'
   *  Product: '<S59>/Product1'
   *  Rounding: '<S59>/Fix1'
   *  Sum: '<S59>/Minus1'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - 3.1415926535897931) /
                      Code_Gen_Model_ConstB.Modulus_d) *
    Code_Gen_Model_ConstB.Modulus_d;

  /* Sum: '<S57>/Sum1' incorporates:
   *  Constant: '<S48>/Constant2'
   *  Product: '<S57>/Product'
   *  Sum: '<S57>/Sum'
   *  UnitDelay: '<S57>/Unit Delay1'
   */
  rtb_Add_k = (rtb_Minus2 - Code_Gen_Model_DW.UnitDelay1_DSTATE_na) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_na;

  /* Product: '<S48>/Product' incorporates:
   *  Constant: '<S48>/Constant3'
   */
  rtb_Product_k = rtb_Add_k * 0.5;

  /* Sum: '<S56>/Diff' incorporates:
   *  UnitDelay: '<S56>/UD'
   *
   * Block description for '<S56>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S56>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_kl = rtb_Product_k - Code_Gen_Model_DW.UD_DSTATE_i1;

  /* Saturate: '<S48>/Saturation' */
  if (rtb_Add_kl > 0.2) {
    rtb_Add_kl = 0.2;
  } else if (rtb_Add_kl < -0.2) {
    rtb_Add_kl = -0.2;
  }

  /* Sum: '<S48>/Add' incorporates:
   *  Gain: '<S48>/Gain1'
   *  Saturate: '<S48>/Saturation'
   */
  rtb_Switch2_h4 = 0.15 * rtb_Minus2 + rtb_Add_kl;

  /* Sum: '<S48>/Subtract' incorporates:
   *  Constant: '<S48>/Constant'
   */
  rtb_Total_Limited_j = 1.0 - rtb_Switch2_h4;

  /* Sum: '<S48>/Sum2' incorporates:
   *  Gain: '<S48>/Gain2'
   *  UnitDelay: '<S48>/Unit Delay'
   */
  rtb_Minus2 = 0.005 * rtb_Minus2 + Code_Gen_Model_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S58>/Switch2' incorporates:
   *  Constant: '<S48>/Constant'
   *  RelationalOperator: '<S58>/LowerRelop1'
   *  Sum: '<S48>/Subtract'
   */
  if (!(rtb_Minus2 > 1.0 - rtb_Switch2_h4)) {
    /* Sum: '<S48>/Subtract1' incorporates:
     *  Constant: '<S48>/Constant1'
     */
    rtb_Total_Limited_j = -1.0 - rtb_Switch2_h4;

    /* Switch: '<S58>/Switch' incorporates:
     *  Constant: '<S48>/Constant1'
     *  RelationalOperator: '<S58>/UpperRelop'
     *  Sum: '<S48>/Subtract1'
     */
    if (!(rtb_Minus2 < -1.0 - rtb_Switch2_h4)) {
      rtb_Total_Limited_j = rtb_Minus2;
    }

    /* End of Switch: '<S58>/Switch' */
  }

  /* End of Switch: '<S58>/Switch2' */

  /* Saturate: '<S48>/Saturation1' */
  if (rtb_Total_Limited_j > 0.005) {
    rtb_Integral_ec = 0.005;
  } else if (rtb_Total_Limited_j < -0.005) {
    rtb_Integral_ec = -0.005;
  } else {
    rtb_Integral_ec = rtb_Total_Limited_j;
  }

  /* End of Saturate: '<S48>/Saturation1' */

  /* Sum: '<S48>/Add1' */
  rtb_Add_kl = rtb_Switch2_h4 + rtb_Integral_ec;

  /* Saturate: '<S48>/Saturation2' */
  if (rtb_Add_kl > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_kl < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = rtb_Add_kl;
  }

  /* End of Saturate: '<S48>/Saturation2' */

  /* Fcn: '<S155>/x->r' */
  rtb_Total_Limited_j = rt_hypotd_snf(rtb_Product7[0], rtb_Product7[1]);

  /* Switch: '<S154>/Switch1' incorporates:
   *  Constant: '<S154>/Constant'
   *  Constant: '<S158>/Constant'
   *  RelationalOperator: '<S158>/Compare'
   *  Switch: '<S154>/Switch'
   */
  if (rtb_Total_Limited_j == 0.0) {
    rtb_Switch1_h = 1.0E-15;
  } else {
    rtb_Switch1_h = rtb_Total_Limited_j;

    /* Switch: '<S154>/Switch' incorporates:
     *  Fcn: '<S155>/x->theta'
     */
    Code_Gen_Model_B.Desired_Module_Angle_f = rt_atan2d_snf(rtb_Product7[1],
      rtb_Product7[0]);
  }

  /* End of Switch: '<S154>/Switch1' */

  /* Trigonometry: '<S44>/Cos4' incorporates:
   *  Switch: '<S27>/Angle_Switch'
   *  Trigonometry: '<S43>/Cos4'
   */
  rtb_Subtract_n = cos(Code_Gen_Model_B.Desired_Module_Angle_f);

  /* Abs: '<S26>/Abs' incorporates:
   *  Inport: '<Root>/FrontLeft_Steer_Encoder'
   */
  Code_Gen_Model_ModulobyConstant(fabs(Code_Gen_Model_U.FrontLeft_Steer_Encoder),
    &Code_Gen_Model_B.ModulobyConstant_n);

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S40>/Constant'
   *  Inport: '<Root>/FrontLeft_Steer_Encoder'
   *  RelationalOperator: '<S40>/Compare'
   *  UnaryMinus: '<S26>/Unary Minus'
   */
  if (Code_Gen_Model_U.FrontLeft_Steer_Encoder >= 0.0) {
    rtb_Minus2 = Code_Gen_Model_B.ModulobyConstant_n.ModulobyConstant;
  } else {
    rtb_Minus2 = -Code_Gen_Model_B.ModulobyConstant_n.ModulobyConstant;
  }

  /* End of Switch: '<S26>/Switch' */

  /* Sum: '<S25>/Add' incorporates:
   *  Inport: '<Root>/FrontLeft_Turn_Offset'
   */
  rtb_Minus2 -= Code_Gen_Model_U.FrontLeft_Turn_Offset;

  /* Abs: '<S38>/Abs' */
  Code_Gen_Model_ModulobyConstant(fabs(rtb_Minus2),
    &Code_Gen_Model_B.ModulobyConstant);

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S39>/Constant'
   *  RelationalOperator: '<S39>/Compare'
   *  UnaryMinus: '<S38>/Unary Minus'
   */
  if (rtb_Minus2 >= 0.0) {
    rtb_Product_j = Code_Gen_Model_B.ModulobyConstant.ModulobyConstant;
  } else {
    rtb_Product_j = -Code_Gen_Model_B.ModulobyConstant.ModulobyConstant;
  }

  /* Gain: '<S25>/Gain' incorporates:
   *  Switch: '<S38>/Switch'
   */
  rtb_Minus2 = 6.2831853071795862 * rtb_Product_j;

  /* Trigonometry: '<S44>/Sin5' incorporates:
   *  UnaryMinus: '<S42>/Unary Minus'
   */
  rtb_Sin5 = sin(-rtb_Minus2);

  /* Trigonometry: '<S44>/Sin4' incorporates:
   *  Switch: '<S27>/Angle_Switch'
   *  Trigonometry: '<S43>/Sin4'
   */
  rtb_Product_j = sin(Code_Gen_Model_B.Desired_Module_Angle_f);

  /* Trigonometry: '<S44>/Cos5' incorporates:
   *  UnaryMinus: '<S42>/Unary Minus'
   */
  rtb_Switch2_h4 = cos(-rtb_Minus2);

  /* Sum: '<S44>/Subtract1' incorporates:
   *  Product: '<S44>/Product2'
   *  Product: '<S44>/Product3'
   *  Trigonometry: '<S44>/Cos4'
   *  Trigonometry: '<S44>/Sin4'
   */
  rtb_Total_Limited_j = rtb_Subtract_n * rtb_Sin5 + rtb_Product_j *
    rtb_Switch2_h4;

  /* Sum: '<S44>/Subtract' incorporates:
   *  Product: '<S44>/Product'
   *  Product: '<S44>/Product1'
   *  Trigonometry: '<S44>/Cos4'
   *  Trigonometry: '<S44>/Sin4'
   */
  rtb_Switch2_h4 = rtb_Subtract_n * rtb_Switch2_h4 - rtb_Product_j * rtb_Sin5;

  /* Math: '<S44>/Hypot' */
  rtb_Sin5 = rt_hypotd_snf(rtb_Switch2_h4, rtb_Total_Limited_j);

  /* Switch: '<S44>/Switch' incorporates:
   *  Constant: '<S44>/Constant'
   *  Constant: '<S44>/Constant1'
   *  Constant: '<S45>/Constant'
   *  Product: '<S44>/Divide'
   *  Product: '<S44>/Divide1'
   *  RelationalOperator: '<S45>/Compare'
   *  Switch: '<S44>/Switch1'
   */
  if (rtb_Sin5 > 1.0E-6) {
    rtb_Total_Limited_j /= rtb_Sin5;
    rtb_Switch2_h4 /= rtb_Sin5;
  } else {
    rtb_Total_Limited_j = 0.0;
    rtb_Switch2_h4 = 1.0;
  }

  /* End of Switch: '<S44>/Switch' */

  /* Switch: '<S27>/Speed_Switch' incorporates:
   *  Abs: '<S27>/Abs'
   *  Constant: '<S41>/Constant'
   *  RelationalOperator: '<S41>/Compare'
   *  Switch: '<S27>/Angle_Switch'
   *  Trigonometry: '<S44>/Atan1'
   *  UnaryMinus: '<S27>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Total_Limited_j, rtb_Switch2_h4)) >
      1.5707963267948966) {
    rtb_Switch1_h = -rtb_Switch1_h;

    /* Sum: '<S43>/Subtract1' incorporates:
     *  Product: '<S43>/Product2'
     *  Product: '<S43>/Product3'
     *  UnaryMinus: '<S27>/Unary Minus'
     */
    rtb_Total_Limited_j = rtb_Subtract_n * Code_Gen_Model_ConstB.Sin5 +
      rtb_Product_j * Code_Gen_Model_ConstB.Cos5;

    /* Sum: '<S43>/Subtract' incorporates:
     *  Product: '<S43>/Product'
     *  Product: '<S43>/Product1'
     */
    rtb_Subtract_n = rtb_Subtract_n * Code_Gen_Model_ConstB.Cos5 - rtb_Product_j
      * Code_Gen_Model_ConstB.Sin5;

    /* Math: '<S43>/Hypot' */
    rtb_Switch2_h4 = rt_hypotd_snf(rtb_Subtract_n, rtb_Total_Limited_j);

    /* Switch: '<S43>/Switch1' incorporates:
     *  Constant: '<S43>/Constant'
     *  Constant: '<S43>/Constant1'
     *  Constant: '<S46>/Constant'
     *  Product: '<S43>/Divide'
     *  Product: '<S43>/Divide1'
     *  RelationalOperator: '<S46>/Compare'
     *  Switch: '<S43>/Switch'
     */
    if (rtb_Switch2_h4 > 1.0E-6) {
      rtb_Subtract_n /= rtb_Switch2_h4;
      rtb_Total_Limited_j /= rtb_Switch2_h4;
    } else {
      rtb_Subtract_n = 1.0;
      rtb_Total_Limited_j = 0.0;
    }

    /* End of Switch: '<S43>/Switch1' */

    /* Switch: '<S27>/Angle_Switch' incorporates:
     *  Trigonometry: '<S43>/Atan1'
     */
    Code_Gen_Model_B.Optimized_Module_Angle_p = rt_atan2d_snf
      (rtb_Total_Limited_j, rtb_Subtract_n);
  } else {
    /* Switch: '<S27>/Angle_Switch' */
    Code_Gen_Model_B.Optimized_Module_Angle_p =
      Code_Gen_Model_B.Desired_Module_Angle_f;
  }

  /* Product: '<S30>/Product2' incorporates:
   *  Constant: '<S30>/Constant'
   *  Switch: '<S27>/Speed_Switch'
   */
  Code_Gen_Model_B.Optimized_Motor_Speed_n = rtb_Switch1_h * 1530.1401357649195;

  /* Signum: '<S28>/Sign' */
  if (rtIsNaN(Code_Gen_Model_B.Optimized_Motor_Speed_n)) {
    rtb_Product_j = (rtNaN);
  } else if (Code_Gen_Model_B.Optimized_Motor_Speed_n < 0.0) {
    rtb_Product_j = -1.0;
  } else {
    rtb_Product_j = Code_Gen_Model_B.Optimized_Motor_Speed_n > 0.0;
  }

  /* Signum: '<S28>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Encoder'
   */
  if (rtIsNaN(Code_Gen_Model_U.FrontLeft_Drive_Encoder)) {
    rtb_Sin5 = (rtNaN);
  } else if (Code_Gen_Model_U.FrontLeft_Drive_Encoder < 0.0) {
    rtb_Sin5 = -1.0;
  } else {
    rtb_Sin5 = Code_Gen_Model_U.FrontLeft_Drive_Encoder > 0.0;
  }

  /* Switch: '<S28>/Switch' incorporates:
   *  Abs: '<S28>/Abs'
   *  Constant: '<S28>/Constant'
   *  Constant: '<S47>/Constant'
   *  Inport: '<Root>/FrontLeft_Drive_Encoder'
   *  Logic: '<S28>/OR'
   *  RelationalOperator: '<S28>/Equal1'
   *  RelationalOperator: '<S47>/Compare'
   *  Signum: '<S28>/Sign'
   *  Signum: '<S28>/Sign1'
   */
  if (rtb_Product_j == rtb_Sin5 || fabs(Code_Gen_Model_U.FrontLeft_Drive_Encoder)
      <= 600.0) {
    rtb_Product_j = Code_Gen_Model_B.Optimized_Motor_Speed_n;
  } else {
    rtb_Product_j = 0.0;
  }

  /* Sum: '<S29>/Add' incorporates:
   *  Sum: '<S23>/Sum'
   */
  rtb_Minus2 = Code_Gen_Model_B.Optimized_Module_Angle_p - rtb_Minus2;

  /* Product: '<S18>/Product' incorporates:
   *  Abs: '<S29>/Abs'
   *  Lookup_n-D: '<S29>/1-D Lookup Table'
   *  Sum: '<S29>/Add'
   *  Switch: '<S28>/Switch'
   */
  rtb_Total_Limited_j = look1_binlcpw(fabs(rtb_Minus2),
    Code_Gen_Model_ConstP.pooled26, Code_Gen_Model_ConstP.pooled25, 1U) *
    rtb_Product_j;

  /* Gain: '<S24>/Gain' */
  rtb_Switch2_h4 = 0.00018181818181818181 * rtb_Total_Limited_j;

  /* Sum: '<S24>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Encoder'
   */
  rtb_Total_Limited_j -= Code_Gen_Model_U.FrontLeft_Drive_Encoder;

  /* Sum: '<S36>/Sum1' incorporates:
   *  Constant: '<S24>/Constant2'
   *  Product: '<S36>/Product'
   *  Sum: '<S36>/Sum'
   *  UnitDelay: '<S36>/Unit Delay1'
   */
  rtb_Subtract_n = (rtb_Total_Limited_j - Code_Gen_Model_DW.UnitDelay1_DSTATE_a)
    * 0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_a;

  /* Product: '<S24>/Product' incorporates:
   *  Constant: '<S24>/Constant3'
   */
  rtb_Product_j = rtb_Subtract_n * 9.9999999999999991E-5;

  /* Sum: '<S35>/Diff' incorporates:
   *  UnitDelay: '<S35>/UD'
   *
   * Block description for '<S35>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S35>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_kl = rtb_Product_j - Code_Gen_Model_DW.UD_DSTATE_o;

  /* Saturate: '<S24>/Saturation' */
  if (rtb_Add_kl > 0.2) {
    rtb_Add_kl = 0.2;
  } else if (rtb_Add_kl < -0.2) {
    rtb_Add_kl = -0.2;
  }

  /* Sum: '<S24>/Add' incorporates:
   *  Gain: '<S24>/Gain1'
   *  Saturate: '<S24>/Saturation'
   */
  rtb_Sin5 = 5.0E-6 * rtb_Total_Limited_j + rtb_Switch2_h4 + rtb_Add_kl;

  /* Sum: '<S24>/Subtract' incorporates:
   *  Constant: '<S24>/Constant'
   */
  rtb_Switch2_h4 = 1.0 - rtb_Sin5;

  /* Sum: '<S24>/Sum2' incorporates:
   *  Gain: '<S24>/Gain2'
   *  UnitDelay: '<S24>/Unit Delay'
   */
  rtb_Total_Limited_j = 0.0 * rtb_Total_Limited_j +
    Code_Gen_Model_DW.UnitDelay_DSTATE_f;

  /* Switch: '<S37>/Switch2' incorporates:
   *  Constant: '<S24>/Constant'
   *  RelationalOperator: '<S37>/LowerRelop1'
   *  Sum: '<S24>/Subtract'
   */
  if (!(rtb_Total_Limited_j > 1.0 - rtb_Sin5)) {
    /* Sum: '<S24>/Subtract1' incorporates:
     *  Constant: '<S24>/Constant1'
     */
    rtb_Switch2_h4 = -1.0 - rtb_Sin5;

    /* Switch: '<S37>/Switch' incorporates:
     *  Constant: '<S24>/Constant1'
     *  RelationalOperator: '<S37>/UpperRelop'
     *  Sum: '<S24>/Subtract1'
     */
    if (!(rtb_Total_Limited_j < -1.0 - rtb_Sin5)) {
      rtb_Switch2_h4 = rtb_Total_Limited_j;
    }

    /* End of Switch: '<S37>/Switch' */
  }

  /* End of Switch: '<S37>/Switch2' */

  /* Saturate: '<S24>/Saturation1' */
  if (rtb_Switch2_h4 > 0.0) {
    rtb_Switch2_h4 = 0.0;
  } else if (rtb_Switch2_h4 < -0.0) {
    rtb_Switch2_h4 = -0.0;
  }

  /* End of Saturate: '<S24>/Saturation1' */

  /* Sum: '<S24>/Add1' */
  rtb_Add_kl = rtb_Sin5 + rtb_Switch2_h4;

  /* Saturate: '<S24>/Saturation2' */
  if (rtb_Add_kl > 1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_kl < -1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = rtb_Add_kl;
  }

  /* End of Saturate: '<S24>/Saturation2' */

  /* Sum: '<S34>/Subtract1' incorporates:
   *  Product: '<S34>/Divide'
   *  Product: '<S34>/Product'
   *  Rounding: '<S34>/Fix'
   *  Sum: '<S34>/Minus'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.UnaryMinus) /
                      Code_Gen_Model_ConstB.Modulus) *
    Code_Gen_Model_ConstB.Modulus;

  /* Sum: '<S34>/Minus2' incorporates:
   *  Constant: '<S18>/Constant1'
   *  Product: '<S34>/Divide1'
   *  Product: '<S34>/Product1'
   *  Rounding: '<S34>/Fix1'
   *  Sum: '<S34>/Minus1'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - 3.1415926535897931) /
                      Code_Gen_Model_ConstB.Modulus) *
    Code_Gen_Model_ConstB.Modulus;

  /* Sum: '<S32>/Sum1' incorporates:
   *  Constant: '<S23>/Constant2'
   *  Product: '<S32>/Product'
   *  Sum: '<S32>/Sum'
   *  UnitDelay: '<S32>/Unit Delay1'
   */
  rtb_Sin5 = (rtb_Minus2 - Code_Gen_Model_DW.UnitDelay1_DSTATE_bk) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_bk;

  /* Product: '<S23>/Product' incorporates:
   *  Constant: '<S23>/Constant3'
   */
  rtb_Switch1_h = rtb_Sin5 * 0.5;

  /* Sum: '<S31>/Diff' incorporates:
   *  UnitDelay: '<S31>/UD'
   *
   * Block description for '<S31>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S31>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_kl = rtb_Switch1_h - Code_Gen_Model_DW.UD_DSTATE_b;

  /* Saturate: '<S23>/Saturation' */
  if (rtb_Add_kl > 0.2) {
    rtb_Add_kl = 0.2;
  } else if (rtb_Add_kl < -0.2) {
    rtb_Add_kl = -0.2;
  }

  /* Sum: '<S23>/Add' incorporates:
   *  Gain: '<S23>/Gain1'
   *  Saturate: '<S23>/Saturation'
   */
  rtb_Add_kl += 0.15 * rtb_Minus2;

  /* Sum: '<S23>/Subtract' incorporates:
   *  Constant: '<S23>/Constant'
   */
  rtb_Total_Limited_j = 1.0 - rtb_Add_kl;

  /* Sum: '<S23>/Sum2' incorporates:
   *  Gain: '<S23>/Gain2'
   *  UnitDelay: '<S23>/Unit Delay'
   */
  rtb_Minus2 = 0.005 * rtb_Minus2 + Code_Gen_Model_DW.UnitDelay_DSTATE_em;

  /* Switch: '<S33>/Switch2' incorporates:
   *  Constant: '<S23>/Constant'
   *  RelationalOperator: '<S33>/LowerRelop1'
   *  Sum: '<S23>/Subtract'
   */
  if (!(rtb_Minus2 > 1.0 - rtb_Add_kl)) {
    /* Sum: '<S23>/Subtract1' incorporates:
     *  Constant: '<S23>/Constant1'
     */
    rtb_Total_Limited_j = -1.0 - rtb_Add_kl;

    /* Switch: '<S33>/Switch' incorporates:
     *  Constant: '<S23>/Constant1'
     *  RelationalOperator: '<S33>/UpperRelop'
     *  Sum: '<S23>/Subtract1'
     */
    if (!(rtb_Minus2 < -1.0 - rtb_Add_kl)) {
      rtb_Total_Limited_j = rtb_Minus2;
    }

    /* End of Switch: '<S33>/Switch' */
  }

  /* End of Switch: '<S33>/Switch2' */

  /* Saturate: '<S23>/Saturation1' */
  if (rtb_Total_Limited_j > 0.005) {
    rtb_Minus2 = 0.005;
  } else if (rtb_Total_Limited_j < -0.005) {
    rtb_Minus2 = -0.005;
  } else {
    rtb_Minus2 = rtb_Total_Limited_j;
  }

  /* End of Saturate: '<S23>/Saturation1' */

  /* Sum: '<S23>/Add1' */
  rtb_Add_kl += rtb_Minus2;

  /* Saturate: '<S23>/Saturation2' */
  if (rtb_Add_kl > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_kl < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = rtb_Add_kl;
  }

  /* End of Saturate: '<S23>/Saturation2' */

  /* DiscreteIntegrator: '<S4>/Accumulator2' */
  Code_Gen_Model_B.X_global_est_m = Code_Gen_Model_DW.Accumulator2_DSTATE;

  /* DiscreteIntegrator: '<S4>/Accumulator' */
  Code_Gen_Model_B.Y_global_est_m = Code_Gen_Model_DW.Accumulator_DSTATE;

  /* Update for UnitDelay: '<S9>/UD' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Rev'
   *
   * Block description for '<S9>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE = Code_Gen_Model_U.FrontLeft_Drive_Rev;

  /* Update for UnitDelay: '<S10>/UD' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Rev'
   *
   * Block description for '<S10>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_m = Code_Gen_Model_U.FrontRight_Drive_Rev;

  /* Update for UnitDelay: '<S11>/UD' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Rev'
   *
   * Block description for '<S11>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_i = Code_Gen_Model_U.BackLeft_Drive_Rev;

  /* Update for UnitDelay: '<S12>/UD' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Rev'
   *
   * Block description for '<S12>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_c = Code_Gen_Model_U.BackRight_Drive_Rev;

  /* Update for UnitDelay: '<S8>/UD'
   *
   * Block description for '<S8>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_d = rtb_SteeringAngle_rad_4;

  /* Update for UnitDelay: '<S134>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S134>/FixPt Constant'
   */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S146>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE = rtb_thetay;

  /* Update for UnitDelay: '<S145>/UD'
   *
   * Block description for '<S145>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_a = rtb_Switch2;

  /* Update for UnitDelay: '<S144>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_m = rtb_Sum1_li;

  /* Update for UnitDelay: '<S143>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S143>/FixPt Constant'
   */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S111>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_k = rtb_Switch2_g;

  /* Update for UnitDelay: '<S110>/UD'
   *
   * Block description for '<S110>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_cs = rtb_Switch_ga;

  /* Update for UnitDelay: '<S99>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_a = rtb_Sin4;

  /* Update for UnitDelay: '<S107>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_i = rtb_Modulation_Drv_X;

  /* Update for UnitDelay: '<S106>/UD'
   *
   * Block description for '<S106>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_l = rtb_Subtract1_lg;

  /* Update for UnitDelay: '<S98>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_l = rtb_Subtract1_b;

  /* Update for UnitDelay: '<S86>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_f = rtb_Add_p;

  /* Update for UnitDelay: '<S85>/UD'
   *
   * Block description for '<S85>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_lh = rtb_Add_f_idx_0;

  /* Update for UnitDelay: '<S74>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_gp = rtb_Add_f_idx_1;

  /* Update for UnitDelay: '<S82>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_n = rtb_Hypot_e;

  /* Update for UnitDelay: '<S81>/UD'
   *
   * Block description for '<S81>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_k = rtb_Product_lf;

  /* Update for UnitDelay: '<S73>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_k = rtb_Integral_g;

  /* Update for UnitDelay: '<S61>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_b = rtb_Add_b0;

  /* Update for UnitDelay: '<S60>/UD'
   *
   * Block description for '<S60>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_e = rtb_Subtract_pa;

  /* Update for UnitDelay: '<S49>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_e = rtb_Integral_f;

  /* Update for UnitDelay: '<S57>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_na = rtb_Add_k;

  /* Update for UnitDelay: '<S56>/UD'
   *
   * Block description for '<S56>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_i1 = rtb_Product_k;

  /* Update for UnitDelay: '<S48>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_d = rtb_Integral_ec;

  /* Update for UnitDelay: '<S36>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_a = rtb_Subtract_n;

  /* Update for UnitDelay: '<S35>/UD'
   *
   * Block description for '<S35>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_o = rtb_Product_j;

  /* Update for UnitDelay: '<S24>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_f = rtb_Switch2_h4;

  /* Update for UnitDelay: '<S32>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_bk = rtb_Sin5;

  /* Update for UnitDelay: '<S31>/UD'
   *
   * Block description for '<S31>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_b = rtb_Switch1_h;

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_em = rtb_Minus2;

  /* Update for DiscreteIntegrator: '<S4>/Accumulator2' incorporates:
   *  Product: '<S4>/Product6'
   */
  Code_Gen_Model_DW.Accumulator2_DSTATE += rtb_POSEexponentialmatrixfori_1;

  /* Update for DiscreteIntegrator: '<S4>/Accumulator' incorporates:
   *  Product: '<S4>/Product6'
   */
  Code_Gen_Model_DW.Accumulator_DSTATE += rtb_POSEexponentialmatrixfori_0;
}

/* Model initialize function */
void Code_Gen_Model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_nq);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_j);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_ns);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_l);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_g);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_d);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_n);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant);

  /* InitializeConditions for UnitDelay: '<S134>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S143>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Accumulator2' */
  Code_Gen_Model_DW.Accumulator2_DSTATE = Code_Gen_Model_ConstB.Constant;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Accumulator' */
  Code_Gen_Model_DW.Accumulator_DSTATE = Code_Gen_Model_ConstB.Constant1;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S193>/FixPt Unit Delay2' */
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
