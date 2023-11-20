/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.11
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Nov 18 23:32:23 2023
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
#include "rt_defines.h"
#include <float.h>

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
 *    '<S1>/Autonomous'
 *    '<S1>/Test'
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
  real_T rtb_Add_ci;
  real_T rtb_Add_f1;
  real_T rtb_Add_f_idx_0;
  real_T rtb_Add_f_idx_1;
  real_T rtb_Add_m;
  real_T rtb_Add_oc;
  real_T rtb_Add_p;
  real_T rtb_Add_pd;
  real_T rtb_Init;
  real_T rtb_Integral_ec;
  real_T rtb_Integral_f;
  real_T rtb_Integral_g;
  real_T rtb_POSEexponentialmatrixfori_0;
  real_T rtb_POSEexponentialmatrixfori_1;
  real_T rtb_Product_bx;
  real_T rtb_Product_j;
  real_T rtb_Product_k;
  real_T rtb_Product_lf;
  real_T rtb_Sin4;
  real_T rtb_SteeringAngle_rad_4;
  real_T rtb_Subtract1_lg;
  real_T rtb_Subtract_kb;
  real_T rtb_Subtract_n;
  real_T rtb_Sum1_li;
  real_T rtb_Sum2_fc;
  real_T rtb_Switch2;
  real_T rtb_Switch2_a;
  real_T rtb_Switch2_g;
  real_T rtb_Switch2_h4;
  real_T rtb_Switch_kj;
  real_T rtb_Total_Limited;
  real_T rtb_thetay;
  int32_T i;
  int32_T i_0;
  int32_T tmp;
  boolean_T rtb_AND;
  boolean_T rtb_Compare_dh;

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
  rtb_Init = (Code_Gen_Model_U.FrontRight_Drive_Rev -
              Code_Gen_Model_DW.UD_DSTATE_m) * 0.039212094760200447;

  /* SignalConversion generated from: '<S4>/Product7' incorporates:
   *  Fcn: '<S14>/r->x'
   *  Fcn: '<S14>/theta->y'
   */
  rtb_Switch2_g_0[2] = rtb_Init * cos(rtb_SteeringAngle_rad_4);
  rtb_Switch2_g_0[3] = rtb_Init * sin(rtb_SteeringAngle_rad_4);

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
  rtb_Sin4 = (Code_Gen_Model_U.BackLeft_Drive_Rev -
              Code_Gen_Model_DW.UD_DSTATE_i) * 0.039212094760200447;

  /* SignalConversion generated from: '<S4>/Product7' incorporates:
   *  Fcn: '<S15>/r->x'
   *  Fcn: '<S15>/theta->y'
   */
  rtb_Switch2_g_0[4] = rtb_Sin4 * cos(rtb_SteeringAngle_rad_4);
  rtb_Switch2_g_0[5] = rtb_Sin4 * sin(rtb_SteeringAngle_rad_4);

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
  rtb_Switch2_a = (Code_Gen_Model_U.BackRight_Drive_Rev -
                   Code_Gen_Model_DW.UD_DSTATE_c) * 0.039212094760200447;

  /* SignalConversion generated from: '<S4>/Product7' incorporates:
   *  Fcn: '<S16>/r->x'
   *  Fcn: '<S16>/theta->y'
   */
  rtb_Switch2_g_0[6] = rtb_Switch2_a * cos(rtb_SteeringAngle_rad_4);
  rtb_Switch2_g_0[7] = rtb_Switch2_a * sin(rtb_SteeringAngle_rad_4);

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
  rtb_Total_Limited = rtb_SteeringAngle_rad_4 - Code_Gen_Model_DW.UD_DSTATE_d;

  /* Sum: '<S4>/Subtract2' incorporates:
   *  Constant: '<S4>/Constant3'
   *  Gain: '<S4>/Gain7'
   *  Math: '<S4>/Square'
   */
  rtb_Switch2_a = 1.0 - rtb_Total_Limited * rtb_Total_Limited *
    0.16666666666666666;

  /* Gain: '<S4>/Gain6' */
  rtb_Total_Limited *= 0.5;

  /* SignalConversion generated from: '<S4>/POSE exponential matrix for improved accuracy while rotating' */
  rtb_POSEexponentialmatrixfori_0 = rtb_Switch2_a;
  rtb_POSEexponentialmatrixfori_1 = rtb_Total_Limited;

  /* SignalConversion generated from: '<S4>/POSE exponential matrix for improved accuracy while rotating' incorporates:
   *  UnaryMinus: '<S4>/Unary Minus2'
   */
  rtb_thetay = -rtb_Total_Limited;

  /* Trigonometry: '<S4>/Trigonometric Function' */
  rtb_Total_Limited = cos(rtb_SteeringAngle_rad_4);

  /* Trigonometry: '<S4>/Trigonometric Function1' */
  rtb_Switch2_a = sin(rtb_SteeringAngle_rad_4);

  /* Product: '<S4>/Product6' incorporates:
   *  Concatenate: '<S4>/POSE exponential matrix for improved accuracy while rotating'
   *  SignalConversion generated from: '<S4>/Rotation matrix from local to global'
   *  UnaryMinus: '<S4>/Unary Minus'
   */
  rtb_thetay = rtb_POSEexponentialmatrixfori_0 * rtb_Product7[0] + rtb_thetay *
    rtb_Product7[1];
  rtb_POSEexponentialmatrixfori_0 = rtb_POSEexponentialmatrixfori_1 *
    rtb_Product7[0] + rtb_POSEexponentialmatrixfori_0 * rtb_Product7[1];
  rtb_POSEexponentialmatrixfori_1 = rtb_Total_Limited * rtb_thetay +
    -rtb_Switch2_a * rtb_POSEexponentialmatrixfori_0;
  rtb_POSEexponentialmatrixfori_0 = rtb_Switch2_a * rtb_thetay +
    rtb_Total_Limited * rtb_POSEexponentialmatrixfori_0;

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtb_Switch2_a = trunc(Code_Gen_Model_U.GameState);
  if (rtIsNaN(rtb_Switch2_a) || rtIsInf(rtb_Switch2_a)) {
    rtb_Switch2_a = 0.0;
  } else {
    rtb_Switch2_a = fmod(rtb_Switch2_a, 4.294967296E+9);
  }

  if (rtb_Switch2_a < 0.0) {
    i = -(int32_T)(uint32_T)-rtb_Switch2_a;
  } else {
    i = (int32_T)(uint32_T)rtb_Switch2_a;
  }

  switch (i) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Disabled' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    Code_Gen_Model_Disabled(&Code_Gen_Model_B.Gyro_Angle_Adjusted,
      &Code_Gen_Model_B.Steering_Abs_Cmd, &Code_Gen_Model_B.Steering_Rel_Cmd,
      &Code_Gen_Model_B.Translation_Angle, &Code_Gen_Model_B.Translation_Speed,
      &Code_Gen_Model_B.Is_Absolute_Translation,
      &Code_Gen_Model_B.Is_Absolute_Steering);

    /* End of Outputs for SubSystem: '<S1>/Disabled' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    Code_Gen_Model_Disabled(&Code_Gen_Model_B.Gyro_Angle_Adjusted,
      &Code_Gen_Model_B.Steering_Abs_Cmd, &Code_Gen_Model_B.Steering_Rel_Cmd,
      &Code_Gen_Model_B.Translation_Angle, &Code_Gen_Model_B.Translation_Speed,
      &Code_Gen_Model_B.Is_Absolute_Translation,
      &Code_Gen_Model_B.Is_Absolute_Steering);

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Teleop' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    /* Switch: '<S171>/Switch1' incorporates:
     *  Constant: '<S171>/Constant'
     *  Constant: '<S171>/Constant1'
     *  Constant: '<S171>/Constant2'
     *  Inport: '<Root>/Steer_Joystick_X'
     *  Inport: '<Root>/Steer_Joystick_Y'
     *  Math: '<S171>/Hypot'
     *  RelationalOperator: '<S171>/GreaterThan'
     *  Switch: '<S171>/Switch'
     */
    if (rt_hypotd_snf(Code_Gen_Model_U.Steer_Joystick_X,
                      Code_Gen_Model_U.Steer_Joystick_Y) > 0.7) {
      rtb_Init = Code_Gen_Model_U.Steer_Joystick_Y;
      rtb_Switch2_g = Code_Gen_Model_U.Steer_Joystick_X;
    } else {
      rtb_Init = 0.0;
      rtb_Switch2_g = 0.0;
    }

    /* End of Switch: '<S171>/Switch1' */

    /* Switch: '<S173>/Switch1' incorporates:
     *  Constant: '<S179>/Constant'
     *  Constant: '<S180>/Constant'
     *  Logic: '<S173>/AND'
     *  RelationalOperator: '<S179>/Compare'
     *  RelationalOperator: '<S180>/Compare'
     *  Switch: '<S173>/Switch2'
     *  UnitDelay: '<S173>/Unit Delay'
     *  UnitDelay: '<S173>/Unit Delay1'
     */
    if (rtb_Switch2_g == 0.0 && rtb_Init == 0.0) {
      rtb_thetay = Code_Gen_Model_DW.UnitDelay1_DSTATE_d;
      rtb_Switch2 = Code_Gen_Model_DW.UnitDelay_DSTATE_g4;
    } else {
      rtb_thetay = rtb_Init;
      rtb_Switch2 = rtb_Switch2_g;
    }

    /* End of Switch: '<S173>/Switch1' */

    /* RelationalOperator: '<S176>/Compare' incorporates:
     *  Constant: '<S176>/Constant'
     */
    rtb_AND = rtb_Switch2 < 0.0;

    /* Switch: '<S172>/Switch' incorporates:
     *  Constant: '<S172>/Constant'
     *  Constant: '<S172>/Constant1'
     *  Constant: '<S174>/Constant'
     *  Constant: '<S175>/Constant'
     *  Logic: '<S172>/Logical Operator'
     *  RelationalOperator: '<S174>/Compare'
     *  RelationalOperator: '<S175>/Compare'
     *  UnitDelay: '<S172>/Unit Delay'
     */
    if (rtb_thetay < 0.0 && Code_Gen_Model_DW.UnitDelay_DSTATE_h >= 0.0 &&
        rtb_AND) {
      rtb_Switch2_a = 6.2831853071795862;
    } else {
      rtb_Switch2_a = 0.0;
    }

    /* Switch: '<S172>/Switch1' incorporates:
     *  Constant: '<S172>/Constant2'
     *  Constant: '<S172>/Constant3'
     *  Constant: '<S177>/Constant'
     *  Constant: '<S178>/Constant'
     *  Logic: '<S172>/Logical Operator1'
     *  RelationalOperator: '<S177>/Compare'
     *  RelationalOperator: '<S178>/Compare'
     *  UnitDelay: '<S172>/Unit Delay'
     */
    if (Code_Gen_Model_DW.UnitDelay_DSTATE_h < 0.0 && rtb_thetay >= 0.0 &&
        rtb_AND) {
      rtb_Add_ci = -6.2831853071795862;
    } else {
      rtb_Add_ci = 0.0;
    }

    /* Sum: '<S172>/Sum1' incorporates:
     *  Switch: '<S172>/Switch'
     *  Switch: '<S172>/Switch1'
     *  UnitDelay: '<S172>/Unit Delay1'
     */
    rtb_Sum1_li = rtb_Switch2_a + rtb_Add_ci +
      Code_Gen_Model_DW.UnitDelay1_DSTATE_kr;

    /* Merge: '<S1>/Merge' incorporates:
     *  Gain: '<S168>/Gain1'
     *  Inport: '<Root>/Gyro_Angle'
     *  Sum: '<S172>/Sum'
     */
    Code_Gen_Model_B.Gyro_Angle_Adjusted = 0.017453292519943295 *
      Code_Gen_Model_U.Gyro_Angle + rtb_Sum1_li;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Trigonometry: '<S169>/Atan2'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd = rt_atan2d_snf(rtb_thetay, rtb_Switch2);

    /* Merge: '<S1>/Merge2' incorporates:
     *  Constant: '<S169>/Constant'
     *  Inport: '<Root>/Steer_Joystick_Y'
     *  Lookup_n-D: '<S169>/Modulation_Str_X_Rel'
     *  Product: '<S169>/Product'
     */
    Code_Gen_Model_B.Steering_Rel_Cmd = look1_binlcpw
      (Code_Gen_Model_U.Steer_Joystick_Y,
       Code_Gen_Model_ConstP.Modulation_Str_X_Rel_bp01Data,
       Code_Gen_Model_ConstP.Modulation_Str_X_Rel_tableData, 20U) * 1.3;

    /* Switch: '<S181>/Switch1' incorporates:
     *  Constant: '<S181>/Constant'
     *  Constant: '<S181>/Constant1'
     *  Inport: '<Root>/Is_Boost_Trigger_Pulled'
     */
    if (Code_Gen_Model_U.Is_Boost_Trigger_Pulled != 0.0) {
      rtb_Switch2_g = 3.658;
    } else {
      rtb_Switch2_g = 1.5;
    }

    /* End of Switch: '<S181>/Switch1' */

    /* Switch: '<S186>/Init' incorporates:
     *  UnitDelay: '<S186>/FixPt Unit Delay1'
     *  UnitDelay: '<S186>/FixPt Unit Delay2'
     */
    if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_Init = rtb_Switch2_g;
    } else {
      rtb_Init = Code_Gen_Model_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S186>/Init' */

    /* Sum: '<S184>/Sum1' */
    rtb_Sin4 = rtb_Switch2_g - rtb_Init;

    /* Switch: '<S185>/Switch2' incorporates:
     *  Constant: '<S183>/Constant1'
     *  Constant: '<S183>/Constant3'
     *  RelationalOperator: '<S185>/LowerRelop1'
     *  RelationalOperator: '<S185>/UpperRelop'
     *  Switch: '<S185>/Switch'
     */
    if (rtb_Sin4 > 0.04) {
      rtb_Sin4 = 0.04;
    } else if (rtb_Sin4 < -0.044444444444444446) {
      /* Switch: '<S185>/Switch' incorporates:
       *  Constant: '<S183>/Constant1'
       */
      rtb_Sin4 = -0.044444444444444446;
    }

    /* Sum: '<S184>/Sum' incorporates:
     *  Switch: '<S185>/Switch2'
     */
    rtb_Sin4 += rtb_Init;

    /* Lookup_n-D: '<S170>/Modulation_Drv_X' incorporates:
     *  Inport: '<Root>/Drive_Joystick_X'
     */
    rtb_Switch2_g = look1_binlcpw(Code_Gen_Model_U.Drive_Joystick_X,
      Code_Gen_Model_ConstP.pooled10, Code_Gen_Model_ConstP.pooled9, 20U);

    /* Lookup_n-D: '<S170>/Modulation_Drv_Y' incorporates:
     *  Inport: '<Root>/Drive_Joystick_Y'
     */
    rtb_Init = look1_binlcpw(Code_Gen_Model_U.Drive_Joystick_Y,
      Code_Gen_Model_ConstP.pooled10, Code_Gen_Model_ConstP.pooled9, 20U);

    /* Product: '<S181>/Product' incorporates:
     *  Math: '<S170>/Magnitude'
     */
    rtb_Switch2_a = rt_hypotd_snf(rtb_Switch2_g, rtb_Init) * rtb_Sin4;

    /* Saturate: '<S181>/Saturation' */
    if (rtb_Switch2_a > 3.658) {
      /* Merge: '<S1>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = 3.658;
    } else if (rtb_Switch2_a < -3.658) {
      /* Merge: '<S1>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = -3.658;
    } else {
      /* Merge: '<S1>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = rtb_Switch2_a;
    }

    /* End of Saturate: '<S181>/Saturation' */

    /* Switch: '<S182>/Switch1' incorporates:
     *  Constant: '<S187>/Constant'
     *  Constant: '<S188>/Constant'
     *  Logic: '<S182>/AND'
     *  RelationalOperator: '<S187>/Compare'
     *  RelationalOperator: '<S188>/Compare'
     *  Switch: '<S182>/Switch2'
     *  UnitDelay: '<S182>/Unit Delay'
     *  UnitDelay: '<S182>/Unit Delay1'
     */
    if (rtb_Switch2_g == 0.0 && rtb_Init == 0.0) {
      rtb_Init = Code_Gen_Model_DW.UnitDelay1_DSTATE_l;
      rtb_Switch2_g = Code_Gen_Model_DW.UnitDelay_DSTATE_p;
    }

    /* End of Switch: '<S182>/Switch1' */

    /* Merge: '<S1>/Merge3' incorporates:
     *  Trigonometry: '<S170>/Atan2'
     */
    Code_Gen_Model_B.Translation_Angle = rt_atan2d_snf(rtb_Init, rtb_Switch2_g);

    /* Merge: '<S1>/Merge5' incorporates:
     *  Inport: '<Root>/Is_Absolute_Translation'
     *  SignalConversion generated from: '<S6>/Is_Absolute_Translation_In'
     */
    Code_Gen_Model_B.Is_Absolute_Translation =
      Code_Gen_Model_U.Is_Absolute_Translation;

    /* Merge: '<S1>/Merge6' incorporates:
     *  Inport: '<Root>/Is_Absolute_Steering'
     *  SignalConversion generated from: '<S6>/Is_Absolute_Steering_In'
     */
    Code_Gen_Model_B.Is_Absolute_Steering =
      Code_Gen_Model_U.Is_Absolute_Steering;

    /* Update for UnitDelay: '<S173>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_d = rtb_thetay;

    /* Update for UnitDelay: '<S172>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_h = rtb_thetay;

    /* Update for UnitDelay: '<S173>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_g4 = rtb_Switch2;

    /* Update for UnitDelay: '<S172>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_kr = rtb_Sum1_li;

    /* Update for UnitDelay: '<S186>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S186>/FixPt Constant'
     */
    Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S186>/FixPt Unit Delay1' */
    Code_Gen_Model_DW.FixPtUnitDelay1_DSTATE_f = rtb_Sin4;

    /* Update for UnitDelay: '<S182>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_l = rtb_Init;

    /* Update for UnitDelay: '<S182>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_p = rtb_Switch2_g;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S7>/Action Port'
     */
    Code_Gen_Model_Disabled(&Code_Gen_Model_B.Gyro_Angle_Adjusted,
      &Code_Gen_Model_B.Steering_Abs_Cmd, &Code_Gen_Model_B.Steering_Rel_Cmd,
      &Code_Gen_Model_B.Translation_Angle, &Code_Gen_Model_B.Translation_Speed,
      &Code_Gen_Model_B.Is_Absolute_Translation,
      &Code_Gen_Model_B.Is_Absolute_Steering);

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Signum: '<S115>/Sign2' incorporates:
   *  UnitDelay: '<S115>/Unit Delay'
   */
  if (rtIsNaN(Code_Gen_Model_B.Translation_Speed_o)) {
    rtb_Switch2_a = (rtNaN);
  } else if (Code_Gen_Model_B.Translation_Speed_o < 0.0) {
    rtb_Switch2_a = -1.0;
  } else {
    rtb_Switch2_a = Code_Gen_Model_B.Translation_Speed_o > 0.0;
  }

  /* Signum: '<S115>/Sign1' */
  if (rtIsNaN(Code_Gen_Model_B.Translation_Speed)) {
    rtb_Add_ci = (rtNaN);
  } else if (Code_Gen_Model_B.Translation_Speed < 0.0) {
    rtb_Add_ci = -1.0;
  } else {
    rtb_Add_ci = Code_Gen_Model_B.Translation_Speed > 0.0;
  }

  /* Product: '<S115>/Product1' incorporates:
   *  Signum: '<S115>/Sign1'
   *  Signum: '<S115>/Sign2'
   */
  rtb_Switch2_a *= rtb_Add_ci;
  if (rtIsNaN(rtb_Switch2_a)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Switch2_a, 256.0);
  }

  if (i < 0) {
    i = (int8_T)-(int8_T)(uint8_T)-(real_T)i;
  }

  /* Switch: '<S115>/Switch' incorporates:
   *  Constant: '<S115>/Constant'
   *  Constant: '<S120>/Constant'
   *  Constant: '<S121>/Constant'
   *  Logic: '<S115>/or'
   *  Product: '<S115>/Product1'
   *  RelationalOperator: '<S120>/Compare'
   *  RelationalOperator: '<S121>/Compare'
   *  UnitDelay: '<S115>/Unit Delay'
   */
  if (Code_Gen_Model_B.Translation_Speed_o == 0.0 || i > 0) {
    rtb_Switch2_a = Code_Gen_Model_B.Translation_Speed;
  } else {
    rtb_Switch2_a = 0.0;
  }

  /* End of Switch: '<S115>/Switch' */

  /* Switch: '<S126>/Init' incorporates:
   *  UnitDelay: '<S126>/FixPt Unit Delay1'
   *  UnitDelay: '<S126>/FixPt Unit Delay2'
   */
  if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Switch2_h4 = rtb_Switch2_a;
  } else {
    rtb_Switch2_h4 = Code_Gen_Model_B.Translation_Speed_o;
  }

  /* End of Switch: '<S126>/Init' */

  /* RelationalOperator: '<S122>/Compare' incorporates:
   *  Constant: '<S122>/Constant'
   */
  rtb_AND = rtb_Switch2_a == 0.0;

  /* RelationalOperator: '<S123>/Compare' incorporates:
   *  Constant: '<S123>/Constant'
   */
  rtb_Compare_dh = rtb_Switch2_a > 0.0;

  /* Abs: '<S115>/Abs' incorporates:
   *  Sum: '<S115>/Subtract'
   *  UnitDelay: '<S115>/Unit Delay'
   */
  rtb_thetay = fabs(Code_Gen_Model_B.Translation_Speed_o -
                    Code_Gen_Model_B.Translation_Speed);

  /* Switch: '<S115>/Switch1' incorporates:
   *  Switch: '<S115>/Switch3'
   *  Switch: '<S115>/Switch5'
   */
  if (rtb_AND) {
    rtb_Sin4 = Code_Gen_Model_ConstB.UnaryMinus;

    /* SignalConversion generated from: '<S115>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S115>/Constant4'
     *  Constant: '<S115>/Constant6'
     */
    rtb_Product7[0] = 0.01;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S115>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S115>/Constant2'
     *  Constant: '<S115>/Constant5'
     */
    rtb_TmpSignalConversionAtLook_o[0] = 0.0;
    rtb_TmpSignalConversionAtLook_o[1] = 0.2;

    /* S-Function (sfix_look1_dyn): '<S115>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S115>/Lookup Table Dynamic'
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
  } else {
    if (rtb_Compare_dh) {
      /* Switch: '<S115>/Switch3' incorporates:
       *  Constant: '<S115>/Constant3'
       */
      rtb_Sin4 = 0.085714285714285715;
    } else {
      rtb_Sin4 = Code_Gen_Model_ConstB.UnaryMinus;
    }

    /* SignalConversion generated from: '<S115>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S115>/Constant10'
     *  Constant: '<S115>/Constant8'
     *  Switch: '<S115>/Switch3'
     */
    rtb_Product7[0] = 0.05;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S115>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S115>/Constant7'
     *  Constant: '<S115>/Constant9'
     */
    rtb_TmpSignalConversionAtLook_o[0] = 0.0;
    rtb_TmpSignalConversionAtLook_o[1] = 0.15;

    /* S-Function (sfix_look1_dyn): '<S115>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S115>/Lookup Table Dynamic1'
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
  }

  /* End of Switch: '<S115>/Switch1' */

  /* Product: '<S115>/Product' */
  rtb_Sin4 *= rtb_thetay;

  /* Sum: '<S124>/Sum1' */
  rtb_Switch2 = rtb_Switch2_a - rtb_Switch2_h4;

  /* Switch: '<S125>/Switch2' incorporates:
   *  RelationalOperator: '<S125>/LowerRelop1'
   */
  if (!(rtb_Switch2 > rtb_Sin4)) {
    /* Switch: '<S115>/Switch2' incorporates:
     *  Constant: '<S115>/Constant1'
     *  Switch: '<S115>/Switch4'
     */
    if (rtb_AND) {
      rtb_Switch2_a = -0.2;
    } else if (rtb_Compare_dh) {
      /* Switch: '<S115>/Switch4' incorporates:
       *  Constant: '<S115>/Constant1'
       */
      rtb_Switch2_a = -0.2;
    } else {
      rtb_Switch2_a = Code_Gen_Model_ConstB.UnaryMinus1;
    }

    /* Product: '<S115>/Product2' incorporates:
     *  Switch: '<S115>/Switch2'
     */
    rtb_Sum1_li = rtb_Switch2_a * rtb_thetay;

    /* Switch: '<S125>/Switch' incorporates:
     *  RelationalOperator: '<S125>/UpperRelop'
     */
    if (rtb_Switch2 < rtb_Sum1_li) {
      rtb_Sin4 = rtb_Sum1_li;
    } else {
      rtb_Sin4 = rtb_Switch2;
    }

    /* End of Switch: '<S125>/Switch' */
  }

  /* End of Switch: '<S125>/Switch2' */

  /* Sum: '<S124>/Sum' */
  Code_Gen_Model_B.Translation_Speed_o = rtb_Sin4 + rtb_Switch2_h4;

  /* Switch: '<S118>/Switch' */
  if (Code_Gen_Model_B.Is_Absolute_Translation) {
    /* Switch: '<S118>/Switch' incorporates:
     *  Constant: '<S142>/Constant3'
     *  Constant: '<S142>/Constant4'
     *  Gain: '<S17>/Gain1'
     *  Inport: '<Root>/Gyro_Angle'
     *  Math: '<S142>/Math Function'
     *  Sum: '<S118>/Subtract'
     *  Sum: '<S142>/Add1'
     *  Sum: '<S142>/Add2'
     */
    Code_Gen_Model_B.Translation_Steering_Cmd = rt_modd_snf
      (Code_Gen_Model_B.Translation_Angle - 0.017453292519943295 *
       Code_Gen_Model_U.Gyro_Angle + 3.1415926535897931, 6.2831853071795862) -
      3.1415926535897931;
  } else {
    /* Switch: '<S118>/Switch' */
    Code_Gen_Model_B.Translation_Steering_Cmd =
      Code_Gen_Model_B.Translation_Angle;
  }

  /* End of Switch: '<S118>/Switch' */

  /* Sum: '<S138>/Add1' incorporates:
   *  Constant: '<S138>/Constant3'
   *  Constant: '<S138>/Constant4'
   *  Math: '<S138>/Math Function'
   *  Sum: '<S137>/Sum'
   *  Sum: '<S138>/Add2'
   */
  rtb_Switch2_h4 = rt_modd_snf(Code_Gen_Model_B.Steering_Abs_Cmd -
    Code_Gen_Model_B.Gyro_Angle_Adjusted + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S140>/Sum1' incorporates:
   *  Constant: '<S137>/Constant2'
   *  Product: '<S140>/Product'
   *  Sum: '<S140>/Sum'
   *  UnitDelay: '<S140>/Unit Delay1'
   */
  rtb_thetay = (rtb_Switch2_h4 - Code_Gen_Model_DW.UnitDelay1_DSTATE) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE;

  /* Product: '<S137>/Product' incorporates:
   *  Constant: '<S137>/Constant3'
   */
  rtb_Switch2 = rtb_thetay * 0.0;

  /* Sum: '<S139>/Diff' incorporates:
   *  UnitDelay: '<S139>/UD'
   *
   * Block description for '<S139>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S139>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Switch2_a = rtb_Switch2 - Code_Gen_Model_DW.UD_DSTATE_a;

  /* Saturate: '<S137>/Saturation' */
  if (rtb_Switch2_a > 0.0) {
    rtb_Switch2_a = 0.0;
  } else if (rtb_Switch2_a < -0.0) {
    rtb_Switch2_a = -0.0;
  }

  /* Sum: '<S137>/Add' incorporates:
   *  Gain: '<S137>/Gain1'
   *  Saturate: '<S137>/Saturation'
   */
  rtb_Init = 1.5 * rtb_Switch2_h4 + rtb_Switch2_a;

  /* Sum: '<S137>/Subtract' incorporates:
   *  Constant: '<S137>/Constant'
   */
  rtb_Sin4 = 1.3 - rtb_Init;

  /* Sum: '<S137>/Sum2' incorporates:
   *  Gain: '<S137>/Gain2'
   *  UnitDelay: '<S137>/Unit Delay'
   */
  rtb_Sum1_li = 0.0 * rtb_Switch2_h4 + Code_Gen_Model_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S141>/Switch2' incorporates:
   *  RelationalOperator: '<S141>/LowerRelop1'
   */
  if (!(rtb_Sum1_li > rtb_Sin4)) {
    /* Sum: '<S137>/Subtract1' incorporates:
     *  Constant: '<S137>/Constant1'
     */
    rtb_Sin4 = -1.3 - rtb_Init;

    /* Switch: '<S141>/Switch' incorporates:
     *  RelationalOperator: '<S141>/UpperRelop'
     */
    if (!(rtb_Sum1_li < rtb_Sin4)) {
      rtb_Sin4 = rtb_Sum1_li;
    }

    /* End of Switch: '<S141>/Switch' */
  }

  /* End of Switch: '<S141>/Switch2' */

  /* Saturate: '<S137>/Saturation1' */
  if (rtb_Sin4 > 0.1) {
    rtb_Sum1_li = 0.1;
  } else if (rtb_Sin4 < -0.1) {
    rtb_Sum1_li = -0.1;
  } else {
    rtb_Sum1_li = rtb_Sin4;
  }

  /* End of Saturate: '<S137>/Saturation1' */

  /* Sum: '<S137>/Add1' */
  rtb_Switch2_a = rtb_Init + rtb_Sum1_li;

  /* Saturate: '<S137>/Saturation2' */
  if (rtb_Switch2_a > 1.3) {
    /* Saturate: '<S137>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = 1.3;
  } else if (rtb_Switch2_a < -1.3) {
    /* Saturate: '<S137>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = -1.3;
  } else {
    /* Saturate: '<S137>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = rtb_Switch2_a;
  }

  /* End of Saturate: '<S137>/Saturation2' */

  /* Switch: '<S117>/Switch' incorporates:
   *  Switch: '<S128>/Switch'
   */
  if (Code_Gen_Model_B.Is_Absolute_Steering) {
    /* Switch: '<S128>/Switch' incorporates:
     *  Abs: '<S128>/Abs'
     *  Constant: '<S128>/Constant'
     *  Constant: '<S136>/Constant'
     *  RelationalOperator: '<S136>/Compare'
     */
    if (fabs(Code_Gen_Model_B.Steering_Localized_PID) > 0.1) {
      rtb_Switch2_h4 = Code_Gen_Model_B.Steering_Localized_PID;
    } else {
      rtb_Switch2_h4 = 0.0;
    }
  } else {
    rtb_Switch2_h4 = Code_Gen_Model_B.Steering_Rel_Cmd;
  }

  /* End of Switch: '<S117>/Switch' */

  /* UnitDelay: '<S127>/Unit Delay' */
  rtb_Sin4 = Code_Gen_Model_B.Steering_Localized_Cmd;

  /* Signum: '<S127>/Sign2' */
  if (rtIsNaN(rtb_Sin4)) {
    rtb_Switch2_a = (rtNaN);
  } else if (rtb_Sin4 < 0.0) {
    rtb_Switch2_a = -1.0;
  } else {
    rtb_Switch2_a = rtb_Sin4 > 0.0;
  }

  /* Signum: '<S127>/Sign1' */
  if (rtIsNaN(rtb_Switch2_h4)) {
    rtb_Add_ci = (rtNaN);
  } else if (rtb_Switch2_h4 < 0.0) {
    rtb_Add_ci = -1.0;
  } else {
    rtb_Add_ci = rtb_Switch2_h4 > 0.0;
  }

  /* Product: '<S127>/Product1' incorporates:
   *  Signum: '<S127>/Sign1'
   *  Signum: '<S127>/Sign2'
   */
  rtb_Switch2_a *= rtb_Add_ci;
  if (rtIsNaN(rtb_Switch2_a)) {
    i = 0;
  } else {
    i = (int32_T)fmod(rtb_Switch2_a, 256.0);
  }

  if (i < 0) {
    i = (int8_T)-(int8_T)(uint8_T)-(real_T)i;
  }

  /* Switch: '<S127>/Switch' incorporates:
   *  Constant: '<S127>/Constant'
   *  Constant: '<S129>/Constant'
   *  Constant: '<S130>/Constant'
   *  Logic: '<S127>/or'
   *  Product: '<S127>/Product1'
   *  RelationalOperator: '<S129>/Compare'
   *  RelationalOperator: '<S130>/Compare'
   */
  if (rtb_Sin4 == 0.0 || i > 0) {
    rtb_Switch_kj = rtb_Switch2_h4;
  } else {
    rtb_Switch_kj = 0.0;
  }

  /* End of Switch: '<S127>/Switch' */

  /* Switch: '<S135>/Init' incorporates:
   *  UnitDelay: '<S135>/FixPt Unit Delay1'
   *  UnitDelay: '<S135>/FixPt Unit Delay2'
   */
  if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Init = rtb_Switch_kj;
  } else {
    rtb_Init = Code_Gen_Model_B.Steering_Localized_Cmd;
  }

  /* End of Switch: '<S135>/Init' */

  /* RelationalOperator: '<S131>/Compare' incorporates:
   *  Constant: '<S131>/Constant'
   */
  rtb_AND = rtb_Switch_kj == 0.0;

  /* RelationalOperator: '<S132>/Compare' incorporates:
   *  Constant: '<S132>/Constant'
   */
  rtb_Compare_dh = rtb_Switch_kj > 0.0;

  /* Abs: '<S127>/Abs' incorporates:
   *  Sum: '<S127>/Subtract'
   */
  rtb_Sin4 = fabs(rtb_Sin4 - rtb_Switch2_h4);

  /* Switch: '<S127>/Switch5' incorporates:
   *  Switch: '<S127>/Switch1'
   */
  if (rtb_AND) {
    /* SignalConversion generated from: '<S127>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S127>/Constant4'
     *  Constant: '<S127>/Constant6'
     */
    rtb_Product7[0] = 0.01;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S127>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S127>/Constant2'
     *  Constant: '<S127>/Constant5'
     */
    rtb_TmpSignalConversionAtLook_o[0] = 0.0;
    rtb_TmpSignalConversionAtLook_o[1] = 0.2;

    /* S-Function (sfix_look1_dyn): '<S127>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S127>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic), &rtb_Product7[0], rtb_Sin4,
                         &rtb_TmpSignalConversionAtLook_o[0], 1U);
    rtb_Sin4 = rtb_LookupTableDynamic;
    rtb_Switch2_a = Code_Gen_Model_ConstB.UnaryMinus_p;
  } else {
    /* SignalConversion generated from: '<S127>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S127>/Constant10'
     *  Constant: '<S127>/Constant8'
     */
    rtb_Product7[0] = 0.1;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S127>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S127>/Constant7'
     *  Constant: '<S127>/Constant9'
     */
    rtb_TmpSignalConversionAtLook_o[0] = 0.0;
    rtb_TmpSignalConversionAtLook_o[1] = 0.2;

    /* S-Function (sfix_look1_dyn): '<S127>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S127>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1), &rtb_Product7[0], rtb_Sin4,
                         &rtb_TmpSignalConversionAtLook_o[0], 1U);
    rtb_Sin4 = rtb_LookupTableDynamic1;

    /* Switch: '<S127>/Switch3' incorporates:
     *  Constant: '<S127>/Constant3'
     */
    if (rtb_Compare_dh) {
      rtb_Switch2_a = 1.0;
    } else {
      rtb_Switch2_a = Code_Gen_Model_ConstB.UnaryMinus_p;
    }

    /* End of Switch: '<S127>/Switch3' */
  }

  /* End of Switch: '<S127>/Switch5' */

  /* Product: '<S127>/Product' incorporates:
   *  Switch: '<S127>/Switch1'
   */
  rtb_Switch2_g = rtb_Switch2_a * rtb_Sin4;

  /* Sum: '<S133>/Sum1' */
  rtb_Switch_kj -= rtb_Init;

  /* Switch: '<S134>/Switch2' incorporates:
   *  RelationalOperator: '<S134>/LowerRelop1'
   */
  if (!(rtb_Switch_kj > rtb_Switch2_g)) {
    /* Switch: '<S127>/Switch2' incorporates:
     *  Constant: '<S127>/Constant1'
     *  Switch: '<S127>/Switch4'
     */
    if (rtb_AND) {
      rtb_Switch2_a = -1.0;
    } else if (rtb_Compare_dh) {
      /* Switch: '<S127>/Switch4' incorporates:
       *  Constant: '<S127>/Constant1'
       */
      rtb_Switch2_a = -1.0;
    } else {
      rtb_Switch2_a = Code_Gen_Model_ConstB.UnaryMinus1_c;
    }

    /* Product: '<S127>/Product2' incorporates:
     *  Switch: '<S127>/Switch2'
     */
    rtb_Switch2_g = rtb_Switch2_a * rtb_Sin4;

    /* Switch: '<S134>/Switch' incorporates:
     *  RelationalOperator: '<S134>/UpperRelop'
     */
    if (!(rtb_Switch_kj < rtb_Switch2_g)) {
      rtb_Switch2_g = rtb_Switch_kj;
    }

    /* End of Switch: '<S134>/Switch' */
  }

  /* End of Switch: '<S134>/Switch2' */

  /* Sum: '<S133>/Sum' */
  Code_Gen_Model_B.Steering_Localized_Cmd = rtb_Switch2_g + rtb_Init;

  /* Fcn: '<S149>/r->x' incorporates:
   *  Fcn: '<S154>/r->x'
   *  Fcn: '<S159>/r->x'
   *  Fcn: '<S164>/r->x'
   */
  rtb_Switch2_a = Code_Gen_Model_B.Translation_Speed_o * cos
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S143>/Add' incorporates:
   *  Fcn: '<S149>/r->x'
   *  Fcn: '<S150>/r->x'
   */
  rtb_Product7[0] = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.FL_Tangent_Angle) + rtb_Switch2_a;

  /* Fcn: '<S149>/theta->y' incorporates:
   *  Fcn: '<S154>/theta->y'
   *  Fcn: '<S159>/theta->y'
   *  Fcn: '<S164>/theta->y'
   */
  rtb_Total_Limited = Code_Gen_Model_B.Translation_Speed_o * sin
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S143>/Add' incorporates:
   *  Fcn: '<S149>/theta->y'
   *  Fcn: '<S150>/theta->y'
   */
  rtb_Product7[1] = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.FL_Tangent_Angle) + rtb_Total_Limited;

  /* Sum: '<S144>/Add' incorporates:
   *  Fcn: '<S155>/r->x'
   *  Fcn: '<S155>/theta->y'
   */
  rtb_TmpSignalConversionAtLook_o[0] = Code_Gen_Model_B.Steering_Localized_Cmd *
    cos(Code_Gen_Model_ConstB.FR_Tangent_Angle) + rtb_Switch2_a;
  rtb_TmpSignalConversionAtLook_o[1] = Code_Gen_Model_B.Steering_Localized_Cmd *
    sin(Code_Gen_Model_ConstB.FR_Tangent_Angle) + rtb_Total_Limited;

  /* Sum: '<S145>/Add' incorporates:
   *  Fcn: '<S160>/r->x'
   *  Fcn: '<S160>/theta->y'
   */
  rtb_Add_f_idx_0 = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.BL_Tangent_Angle) + rtb_Switch2_a;
  rtb_Add_f_idx_1 = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.BL_Tangent_Angle) + rtb_Total_Limited;

  /* Sum: '<S146>/Add' incorporates:
   *  Fcn: '<S165>/r->x'
   *  Fcn: '<S165>/theta->y'
   */
  rtb_Switch2_a += Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.BR_Tangent_Angle);
  rtb_Init = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.BR_Tangent_Angle) + rtb_Total_Limited;

  /* Fcn: '<S163>/x->r' */
  rtb_Total_Limited = rt_hypotd_snf(rtb_Switch2_a, rtb_Init);

  /* Switch: '<S162>/Switch1' incorporates:
   *  Constant: '<S166>/Constant'
   *  RelationalOperator: '<S166>/Compare'
   *  Switch: '<S162>/Switch'
   */
  if (rtb_Total_Limited == 0.0) {
    /* Switch: '<S162>/Switch1' incorporates:
     *  Constant: '<S162>/Constant'
     */
    Code_Gen_Model_B.BR_Wheel_Speed = 1.0E-15;
  } else {
    /* Switch: '<S162>/Switch1' */
    Code_Gen_Model_B.BR_Wheel_Speed = rtb_Total_Limited;

    /* Switch: '<S162>/Switch' incorporates:
     *  Fcn: '<S163>/x->theta'
     */
    Code_Gen_Model_B.BR_Module_Angle = rt_atan2d_snf(rtb_Init, rtb_Switch2_a);
  }

  /* End of Switch: '<S162>/Switch1' */

  /* Trigonometry: '<S106>/Cos4' incorporates:
   *  Switch: '<S94>/Angle_Switch'
   *  Trigonometry: '<S105>/Cos4'
   */
  rtb_Subtract_n = cos(Code_Gen_Model_B.BR_Module_Angle);

  /* Sum: '<S102>/Add1' incorporates:
   *  Constant: '<S102>/Constant3'
   *  Constant: '<S102>/Constant4'
   *  Gain: '<S93>/Revolutions to Radians'
   *  Inport: '<Root>/BackRight_Steer_Encoder'
   *  Inport: '<Root>/BackRight_Turn_Offset'
   *  Math: '<S102>/Math Function'
   *  Sum: '<S102>/Add2'
   *  Sum: '<S93>/Add'
   */
  Code_Gen_Model_B.BR_Steer_Module_Angle_Adjusted = rt_modd_snf
    ((Code_Gen_Model_U.BackRight_Steer_Encoder -
      Code_Gen_Model_U.BackRight_Turn_Offset) * 6.2831853071795862 +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Trigonometry: '<S106>/Sin5' incorporates:
   *  UnaryMinus: '<S104>/Unary Minus'
   */
  rtb_Switch2_h4 = sin(-Code_Gen_Model_B.BR_Steer_Module_Angle_Adjusted);

  /* Trigonometry: '<S106>/Sin4' incorporates:
   *  Switch: '<S94>/Angle_Switch'
   *  Trigonometry: '<S105>/Sin4'
   */
  rtb_Product_j = sin(Code_Gen_Model_B.BR_Module_Angle);

  /* Trigonometry: '<S106>/Cos5' incorporates:
   *  UnaryMinus: '<S104>/Unary Minus'
   */
  rtb_Switch2_a = cos(-Code_Gen_Model_B.BR_Steer_Module_Angle_Adjusted);

  /* Sum: '<S106>/Subtract1' incorporates:
   *  Product: '<S106>/Product2'
   *  Product: '<S106>/Product3'
   *  Trigonometry: '<S106>/Cos4'
   *  Trigonometry: '<S106>/Sin4'
   */
  rtb_Sin4 = rtb_Subtract_n * rtb_Switch2_h4 + rtb_Product_j * rtb_Switch2_a;

  /* Sum: '<S106>/Subtract' incorporates:
   *  Product: '<S106>/Product'
   *  Product: '<S106>/Product1'
   *  Trigonometry: '<S106>/Cos4'
   *  Trigonometry: '<S106>/Sin4'
   */
  rtb_Init = rtb_Subtract_n * rtb_Switch2_a - rtb_Product_j * rtb_Switch2_h4;

  /* Math: '<S106>/Hypot' */
  rtb_Switch2_g = rt_hypotd_snf(rtb_Init, rtb_Sin4);

  /* Switch: '<S106>/Switch' incorporates:
   *  Constant: '<S106>/Constant'
   *  Constant: '<S106>/Constant1'
   *  Constant: '<S107>/Constant'
   *  Product: '<S106>/Divide'
   *  Product: '<S106>/Divide1'
   *  RelationalOperator: '<S107>/Compare'
   *  Switch: '<S106>/Switch1'
   */
  if (rtb_Switch2_g > 1.0E-6) {
    rtb_Total_Limited = rtb_Sin4 / rtb_Switch2_g;
    rtb_Switch2_a = rtb_Init / rtb_Switch2_g;
  } else {
    rtb_Total_Limited = 0.0;
    rtb_Switch2_a = 1.0;
  }

  /* End of Switch: '<S106>/Switch' */

  /* RelationalOperator: '<S103>/Compare' incorporates:
   *  Abs: '<S94>/Abs'
   *  Constant: '<S103>/Constant'
   *  Trigonometry: '<S106>/Atan1'
   */
  rtb_AND = fabs(rt_atan2d_snf(rtb_Total_Limited, rtb_Switch2_a)) >
    1.5707963267948966;

  /* Switch: '<S94>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S94>/Unary Minus'
   */
  if (rtb_AND) {
    rtb_Switch2_a = -Code_Gen_Model_B.BR_Wheel_Speed;
  } else {
    rtb_Switch2_a = Code_Gen_Model_B.BR_Wheel_Speed;
  }

  /* Product: '<S98>/Product2' incorporates:
   *  Constant: '<S98>/Constant'
   *  Switch: '<S94>/Speed_Switch'
   */
  rtb_Total_Limited = rtb_Switch2_a * 1530.1401357649195;

  /* Signum: '<S96>/Sign' */
  if (rtIsNaN(rtb_Total_Limited)) {
    rtb_Switch2_a = (rtNaN);
  } else if (rtb_Total_Limited < 0.0) {
    rtb_Switch2_a = -1.0;
  } else {
    rtb_Switch2_a = rtb_Total_Limited > 0.0;
  }

  /* Signum: '<S96>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Encoder'
   */
  if (rtIsNaN(Code_Gen_Model_U.BackRight_Drive_Encoder)) {
    rtb_Add_ci = (rtNaN);
  } else if (Code_Gen_Model_U.BackRight_Drive_Encoder < 0.0) {
    rtb_Add_ci = -1.0;
  } else {
    rtb_Add_ci = Code_Gen_Model_U.BackRight_Drive_Encoder > 0.0;
  }

  /* Switch: '<S96>/Switch' incorporates:
   *  Abs: '<S96>/Abs'
   *  Constant: '<S113>/Constant'
   *  Constant: '<S96>/Constant'
   *  Inport: '<Root>/BackRight_Drive_Encoder'
   *  Logic: '<S96>/OR'
   *  RelationalOperator: '<S113>/Compare'
   *  RelationalOperator: '<S96>/Equal1'
   *  Signum: '<S96>/Sign'
   *  Signum: '<S96>/Sign1'
   */
  if (!(rtb_Switch2_a == rtb_Add_ci) && !(fabs
       (Code_Gen_Model_U.BackRight_Drive_Encoder) <= 1500.0)) {
    rtb_Total_Limited = 0.0;
  }

  /* End of Switch: '<S96>/Switch' */

  /* Switch: '<S94>/Angle_Switch' incorporates:
   *  Trigonometry: '<S105>/Atan1'
   */
  if (rtb_AND) {
    /* Sum: '<S105>/Subtract1' incorporates:
     *  Product: '<S105>/Product2'
     *  Product: '<S105>/Product3'
     */
    rtb_Sin4 = rtb_Subtract_n * Code_Gen_Model_ConstB.Sin5_c + rtb_Product_j *
      Code_Gen_Model_ConstB.Cos5_b;

    /* Sum: '<S105>/Subtract' incorporates:
     *  Product: '<S105>/Product'
     *  Product: '<S105>/Product1'
     */
    rtb_Switch2_g = rtb_Subtract_n * Code_Gen_Model_ConstB.Cos5_b -
      rtb_Product_j * Code_Gen_Model_ConstB.Sin5_c;

    /* Math: '<S105>/Hypot' */
    rtb_Init = rt_hypotd_snf(rtb_Switch2_g, rtb_Sin4);

    /* Switch: '<S105>/Switch1' incorporates:
     *  Constant: '<S105>/Constant'
     *  Constant: '<S105>/Constant1'
     *  Constant: '<S108>/Constant'
     *  Product: '<S105>/Divide'
     *  Product: '<S105>/Divide1'
     *  RelationalOperator: '<S108>/Compare'
     *  Switch: '<S105>/Switch'
     */
    if (rtb_Init > 1.0E-6) {
      rtb_Switch2_g /= rtb_Init;
      rtb_Sin4 /= rtb_Init;
    } else {
      rtb_Switch2_g = 1.0;
      rtb_Sin4 = 0.0;
    }

    /* End of Switch: '<S105>/Switch1' */
    rtb_Switch2_a = rt_atan2d_snf(rtb_Sin4, rtb_Switch2_g);
  } else {
    rtb_Switch2_a = Code_Gen_Model_B.BR_Module_Angle;
  }

  /* Sum: '<S97>/Add' incorporates:
   *  Sum: '<S95>/Sum'
   */
  rtb_Product_bx = rtb_Switch2_a -
    Code_Gen_Model_B.BR_Steer_Module_Angle_Adjusted;

  /* Product: '<S21>/Product' incorporates:
   *  Abs: '<S97>/Abs'
   *  Constant: '<S114>/Constant3'
   *  Constant: '<S114>/Constant4'
   *  Lookup_n-D: '<S97>/1-D Lookup Table'
   *  Math: '<S114>/Math Function'
   *  Sum: '<S114>/Add1'
   *  Sum: '<S114>/Add2'
   *  Sum: '<S97>/Add'
   */
  rtb_Total_Limited *= look1_binlcpw(fabs(rt_modd_snf(rtb_Product_bx +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
    Code_Gen_Model_ConstP.pooled25, Code_Gen_Model_ConstP.pooled24, 1U);

  /* Gain: '<S92>/Gain' */
  rtb_Switch2_g = 0.00018181818181818181 * rtb_Total_Limited;

  /* Sum: '<S92>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Encoder'
   */
  rtb_Total_Limited -= Code_Gen_Model_U.BackRight_Drive_Encoder;

  /* Sum: '<S100>/Sum1' incorporates:
   *  Constant: '<S92>/Constant2'
   *  Product: '<S100>/Product'
   *  Sum: '<S100>/Sum'
   *  UnitDelay: '<S100>/Unit Delay1'
   */
  rtb_Sin4 = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_k) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_k;

  /* Product: '<S92>/Product' incorporates:
   *  Constant: '<S92>/Constant3'
   */
  rtb_Init = rtb_Sin4 * 9.9999999999999991E-5;

  /* Sum: '<S99>/Diff' incorporates:
   *  UnitDelay: '<S99>/UD'
   *
   * Block description for '<S99>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S99>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Switch2_a = rtb_Init - Code_Gen_Model_DW.UD_DSTATE_cs;

  /* Saturate: '<S92>/Saturation' */
  if (rtb_Switch2_a > 0.2) {
    rtb_Switch2_a = 0.2;
  } else if (rtb_Switch2_a < -0.2) {
    rtb_Switch2_a = -0.2;
  }

  /* Sum: '<S92>/Add' incorporates:
   *  Gain: '<S92>/Gain1'
   *  Saturate: '<S92>/Saturation'
   */
  rtb_Switch_kj = 5.0E-6 * rtb_Total_Limited + rtb_Switch2_g + rtb_Switch2_a;

  /* Sum: '<S92>/Subtract' incorporates:
   *  Constant: '<S92>/Constant'
   */
  rtb_Switch2_h4 = 1.0 - rtb_Switch_kj;

  /* Sum: '<S92>/Sum2' incorporates:
   *  Gain: '<S92>/Gain2'
   *  UnitDelay: '<S92>/Unit Delay'
   */
  rtb_Switch2_g = 0.0 * rtb_Total_Limited + Code_Gen_Model_DW.UnitDelay_DSTATE_a;

  /* Switch: '<S101>/Switch2' incorporates:
   *  Constant: '<S92>/Constant'
   *  RelationalOperator: '<S101>/LowerRelop1'
   *  Sum: '<S92>/Subtract'
   */
  if (!(rtb_Switch2_g > 1.0 - rtb_Switch_kj)) {
    /* Switch: '<S101>/Switch' incorporates:
     *  Constant: '<S92>/Constant1'
     *  RelationalOperator: '<S101>/UpperRelop'
     *  Sum: '<S92>/Subtract1'
     */
    if (rtb_Switch2_g < -1.0 - rtb_Switch_kj) {
      rtb_Switch2_h4 = -1.0 - rtb_Switch_kj;
    } else {
      rtb_Switch2_h4 = rtb_Switch2_g;
    }

    /* End of Switch: '<S101>/Switch' */
  }

  /* End of Switch: '<S101>/Switch2' */

  /* Saturate: '<S92>/Saturation1' */
  if (rtb_Switch2_h4 > 0.0) {
    rtb_Switch2_g = 0.0;
  } else if (rtb_Switch2_h4 < -0.0) {
    rtb_Switch2_g = -0.0;
  } else {
    rtb_Switch2_g = rtb_Switch2_h4;
  }

  /* End of Saturate: '<S92>/Saturation1' */

  /* Sum: '<S92>/Add1' */
  rtb_Switch2_a = rtb_Switch_kj + rtb_Switch2_g;

  /* Saturate: '<S92>/Saturation2' */
  if (rtb_Switch2_a > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Switch2_a < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = rtb_Switch2_a;
  }

  /* End of Saturate: '<S92>/Saturation2' */

  /* Sum: '<S109>/Add1' incorporates:
   *  Constant: '<S109>/Constant3'
   *  Constant: '<S109>/Constant4'
   *  Math: '<S109>/Math Function'
   *  Sum: '<S109>/Add2'
   */
  rtb_Total_Limited = rt_modd_snf(rtb_Product_bx + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S111>/Sum1' incorporates:
   *  Constant: '<S95>/Constant2'
   *  Product: '<S111>/Product'
   *  Sum: '<S111>/Sum'
   *  UnitDelay: '<S111>/Unit Delay1'
   */
  rtb_Switch_kj = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_i) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S95>/Product' incorporates:
   *  Constant: '<S95>/Constant3'
   */
  rtb_Subtract1_lg = rtb_Switch_kj * 0.5;

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
  rtb_Switch2_a = rtb_Subtract1_lg - Code_Gen_Model_DW.UD_DSTATE_l;

  /* Saturate: '<S95>/Saturation' */
  if (rtb_Switch2_a > 0.2) {
    rtb_Switch2_a = 0.2;
  } else if (rtb_Switch2_a < -0.2) {
    rtb_Switch2_a = -0.2;
  }

  /* Sum: '<S95>/Add' incorporates:
   *  Gain: '<S95>/Gain1'
   *  Saturate: '<S95>/Saturation'
   */
  rtb_Add_p = 0.15 * rtb_Total_Limited + rtb_Switch2_a;

  /* Sum: '<S95>/Subtract' incorporates:
   *  Constant: '<S95>/Constant'
   */
  rtb_Switch2_a = 1.0 - rtb_Add_p;

  /* Sum: '<S95>/Sum2' incorporates:
   *  Gain: '<S95>/Gain2'
   *  UnitDelay: '<S95>/Unit Delay'
   */
  rtb_Sum2_fc = 0.005 * rtb_Total_Limited + Code_Gen_Model_DW.UnitDelay_DSTATE_l;

  /* Switch: '<S112>/Switch2' incorporates:
   *  Constant: '<S95>/Constant'
   *  RelationalOperator: '<S112>/LowerRelop1'
   *  Sum: '<S95>/Subtract'
   */
  if (!(rtb_Sum2_fc > 1.0 - rtb_Add_p)) {
    /* Switch: '<S112>/Switch' incorporates:
     *  Constant: '<S95>/Constant1'
     *  RelationalOperator: '<S112>/UpperRelop'
     *  Sum: '<S95>/Subtract1'
     */
    if (rtb_Sum2_fc < -1.0 - rtb_Add_p) {
      rtb_Switch2_a = -1.0 - rtb_Add_p;
    } else {
      rtb_Switch2_a = rtb_Sum2_fc;
    }

    /* End of Switch: '<S112>/Switch' */
  }

  /* End of Switch: '<S112>/Switch2' */

  /* Saturate: '<S95>/Saturation1' */
  if (rtb_Switch2_a > 0.005) {
    rtb_Sum2_fc = 0.005;
  } else if (rtb_Switch2_a < -0.005) {
    rtb_Sum2_fc = -0.005;
  } else {
    rtb_Sum2_fc = rtb_Switch2_a;
  }

  /* End of Saturate: '<S95>/Saturation1' */

  /* Outport: '<Root>/BackRight_Steer_DutyCycle' incorporates:
   *  Saturate: '<S95>/Saturation2'
   *  Sum: '<S95>/Add1'
   */
  Code_Gen_Model_Y.BackRight_Steer_DutyCycle = rtb_Add_p + rtb_Sum2_fc;

  /* Fcn: '<S158>/x->r' */
  rtb_Total_Limited = rt_hypotd_snf(rtb_Add_f_idx_0, rtb_Add_f_idx_1);

  /* Switch: '<S157>/Switch1' incorporates:
   *  Constant: '<S161>/Constant'
   *  RelationalOperator: '<S161>/Compare'
   *  Switch: '<S157>/Switch'
   */
  if (rtb_Total_Limited == 0.0) {
    /* Switch: '<S157>/Switch1' incorporates:
     *  Constant: '<S157>/Constant'
     */
    Code_Gen_Model_B.BL_Wheel_Speed = 1.0E-15;
  } else {
    /* Switch: '<S157>/Switch1' */
    Code_Gen_Model_B.BL_Wheel_Speed = rtb_Total_Limited;

    /* Switch: '<S157>/Switch' incorporates:
     *  Fcn: '<S158>/x->theta'
     */
    Code_Gen_Model_B.BL_Module_Angle = rt_atan2d_snf(rtb_Add_f_idx_1,
      rtb_Add_f_idx_0);
  }

  /* End of Switch: '<S157>/Switch1' */

  /* Trigonometry: '<S83>/Cos4' incorporates:
   *  Switch: '<S71>/Angle_Switch'
   *  Trigonometry: '<S82>/Cos4'
   */
  rtb_Subtract_n = cos(Code_Gen_Model_B.BL_Module_Angle);

  /* Sum: '<S79>/Add1' incorporates:
   *  Constant: '<S79>/Constant3'
   *  Constant: '<S79>/Constant4'
   *  Gain: '<S70>/Revolutions to Radians'
   *  Inport: '<Root>/BackLeft_Steer_Encoder'
   *  Inport: '<Root>/BackLeft_Turn_Offset'
   *  Math: '<S79>/Math Function'
   *  Sum: '<S70>/Add'
   *  Sum: '<S79>/Add2'
   */
  Code_Gen_Model_B.BL_Steer_Module_Angle_Adjusted = rt_modd_snf
    ((Code_Gen_Model_U.BackLeft_Steer_Encoder -
      Code_Gen_Model_U.BackLeft_Turn_Offset) * 6.2831853071795862 +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Trigonometry: '<S83>/Sin5' incorporates:
   *  UnaryMinus: '<S81>/Unary Minus'
   */
  rtb_Switch2_h4 = sin(-Code_Gen_Model_B.BL_Steer_Module_Angle_Adjusted);

  /* Trigonometry: '<S83>/Sin4' incorporates:
   *  Switch: '<S71>/Angle_Switch'
   *  Trigonometry: '<S82>/Sin4'
   */
  rtb_Product_j = sin(Code_Gen_Model_B.BL_Module_Angle);

  /* Trigonometry: '<S83>/Cos5' incorporates:
   *  UnaryMinus: '<S81>/Unary Minus'
   */
  rtb_Switch2_a = cos(-Code_Gen_Model_B.BL_Steer_Module_Angle_Adjusted);

  /* Sum: '<S83>/Subtract1' incorporates:
   *  Product: '<S83>/Product2'
   *  Product: '<S83>/Product3'
   *  Trigonometry: '<S83>/Cos4'
   *  Trigonometry: '<S83>/Sin4'
   */
  rtb_Total_Limited = rtb_Subtract_n * rtb_Switch2_h4 + rtb_Product_j *
    rtb_Switch2_a;

  /* Sum: '<S83>/Subtract' incorporates:
   *  Product: '<S83>/Product'
   *  Product: '<S83>/Product1'
   *  Trigonometry: '<S83>/Cos4'
   *  Trigonometry: '<S83>/Sin4'
   */
  rtb_Add_p = rtb_Subtract_n * rtb_Switch2_a - rtb_Product_j * rtb_Switch2_h4;

  /* Math: '<S83>/Hypot' */
  rtb_Add_f_idx_0 = rt_hypotd_snf(rtb_Add_p, rtb_Total_Limited);

  /* Switch: '<S83>/Switch' incorporates:
   *  Constant: '<S83>/Constant'
   *  Constant: '<S83>/Constant1'
   *  Constant: '<S84>/Constant'
   *  Product: '<S83>/Divide'
   *  Product: '<S83>/Divide1'
   *  RelationalOperator: '<S84>/Compare'
   *  Switch: '<S83>/Switch1'
   */
  if (rtb_Add_f_idx_0 > 1.0E-6) {
    rtb_Total_Limited /= rtb_Add_f_idx_0;
    rtb_Switch2_a = rtb_Add_p / rtb_Add_f_idx_0;
  } else {
    rtb_Total_Limited = 0.0;
    rtb_Switch2_a = 1.0;
  }

  /* End of Switch: '<S83>/Switch' */

  /* RelationalOperator: '<S80>/Compare' incorporates:
   *  Abs: '<S71>/Abs'
   *  Constant: '<S80>/Constant'
   *  Trigonometry: '<S83>/Atan1'
   */
  rtb_AND = fabs(rt_atan2d_snf(rtb_Total_Limited, rtb_Switch2_a)) >
    1.5707963267948966;

  /* Switch: '<S71>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S71>/Unary Minus'
   */
  if (rtb_AND) {
    rtb_Switch2_a = -Code_Gen_Model_B.BL_Wheel_Speed;
  } else {
    rtb_Switch2_a = Code_Gen_Model_B.BL_Wheel_Speed;
  }

  /* Product: '<S75>/Product2' incorporates:
   *  Constant: '<S75>/Constant'
   *  Switch: '<S71>/Speed_Switch'
   */
  rtb_Total_Limited = rtb_Switch2_a * 1530.1401357649195;

  /* Signum: '<S73>/Sign' */
  if (rtIsNaN(rtb_Total_Limited)) {
    rtb_Switch2_a = (rtNaN);
  } else if (rtb_Total_Limited < 0.0) {
    rtb_Switch2_a = -1.0;
  } else {
    rtb_Switch2_a = rtb_Total_Limited > 0.0;
  }

  /* Signum: '<S73>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Encoder'
   */
  if (rtIsNaN(Code_Gen_Model_U.BackLeft_Drive_Encoder)) {
    rtb_Add_ci = (rtNaN);
  } else if (Code_Gen_Model_U.BackLeft_Drive_Encoder < 0.0) {
    rtb_Add_ci = -1.0;
  } else {
    rtb_Add_ci = Code_Gen_Model_U.BackLeft_Drive_Encoder > 0.0;
  }

  /* Switch: '<S73>/Switch' incorporates:
   *  Abs: '<S73>/Abs'
   *  Constant: '<S73>/Constant'
   *  Constant: '<S90>/Constant'
   *  Inport: '<Root>/BackLeft_Drive_Encoder'
   *  Logic: '<S73>/OR'
   *  RelationalOperator: '<S73>/Equal1'
   *  RelationalOperator: '<S90>/Compare'
   *  Signum: '<S73>/Sign'
   *  Signum: '<S73>/Sign1'
   */
  if (!(rtb_Switch2_a == rtb_Add_ci) && !(fabs
       (Code_Gen_Model_U.BackLeft_Drive_Encoder) <= 1500.0)) {
    rtb_Total_Limited = 0.0;
  }

  /* End of Switch: '<S73>/Switch' */

  /* Switch: '<S71>/Angle_Switch' incorporates:
   *  Trigonometry: '<S82>/Atan1'
   */
  if (rtb_AND) {
    /* Sum: '<S82>/Subtract1' incorporates:
     *  Product: '<S82>/Product2'
     *  Product: '<S82>/Product3'
     */
    rtb_Add_p = rtb_Subtract_n * Code_Gen_Model_ConstB.Sin5_e + rtb_Product_j *
      Code_Gen_Model_ConstB.Cos5_i;

    /* Sum: '<S82>/Subtract' incorporates:
     *  Product: '<S82>/Product'
     *  Product: '<S82>/Product1'
     */
    rtb_Switch2_a = rtb_Subtract_n * Code_Gen_Model_ConstB.Cos5_i -
      rtb_Product_j * Code_Gen_Model_ConstB.Sin5_e;

    /* Math: '<S82>/Hypot' */
    rtb_Add_f_idx_0 = rt_hypotd_snf(rtb_Switch2_a, rtb_Add_p);

    /* Switch: '<S82>/Switch1' incorporates:
     *  Constant: '<S82>/Constant'
     *  Constant: '<S82>/Constant1'
     *  Constant: '<S85>/Constant'
     *  Product: '<S82>/Divide'
     *  Product: '<S82>/Divide1'
     *  RelationalOperator: '<S85>/Compare'
     *  Switch: '<S82>/Switch'
     */
    if (rtb_Add_f_idx_0 > 1.0E-6) {
      rtb_Switch2_a /= rtb_Add_f_idx_0;
      rtb_Add_p /= rtb_Add_f_idx_0;
    } else {
      rtb_Switch2_a = 1.0;
      rtb_Add_p = 0.0;
    }

    /* End of Switch: '<S82>/Switch1' */
    rtb_Switch2_a = rt_atan2d_snf(rtb_Add_p, rtb_Switch2_a);
  } else {
    rtb_Switch2_a = Code_Gen_Model_B.BL_Module_Angle;
  }

  /* Sum: '<S74>/Add' incorporates:
   *  Sum: '<S72>/Sum'
   */
  rtb_Product_bx = rtb_Switch2_a -
    Code_Gen_Model_B.BL_Steer_Module_Angle_Adjusted;

  /* Product: '<S20>/Product' incorporates:
   *  Abs: '<S74>/Abs'
   *  Constant: '<S91>/Constant3'
   *  Constant: '<S91>/Constant4'
   *  Lookup_n-D: '<S74>/1-D Lookup Table'
   *  Math: '<S91>/Math Function'
   *  Sum: '<S74>/Add'
   *  Sum: '<S91>/Add1'
   *  Sum: '<S91>/Add2'
   */
  rtb_Total_Limited *= look1_binlcpw(fabs(rt_modd_snf(rtb_Product_bx +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
    Code_Gen_Model_ConstP.pooled25, Code_Gen_Model_ConstP.pooled24, 1U);

  /* Gain: '<S69>/Gain' */
  rtb_Add_f_idx_1 = 0.00018181818181818181 * rtb_Total_Limited;

  /* Sum: '<S69>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Encoder'
   */
  rtb_Total_Limited -= Code_Gen_Model_U.BackLeft_Drive_Encoder;

  /* Sum: '<S77>/Sum1' incorporates:
   *  Constant: '<S69>/Constant2'
   *  Product: '<S77>/Product'
   *  Sum: '<S77>/Sum'
   *  UnitDelay: '<S77>/Unit Delay1'
   */
  rtb_Add_p = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_f) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S69>/Product' incorporates:
   *  Constant: '<S69>/Constant3'
   */
  rtb_Add_f_idx_0 = rtb_Add_p * 9.9999999999999991E-5;

  /* Sum: '<S76>/Diff' incorporates:
   *  UnitDelay: '<S76>/UD'
   *
   * Block description for '<S76>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S76>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Switch2_a = rtb_Add_f_idx_0 - Code_Gen_Model_DW.UD_DSTATE_lh;

  /* Saturate: '<S69>/Saturation' */
  if (rtb_Switch2_a > 0.2) {
    rtb_Switch2_a = 0.2;
  } else if (rtb_Switch2_a < -0.2) {
    rtb_Switch2_a = -0.2;
  }

  /* Sum: '<S69>/Add' incorporates:
   *  Gain: '<S69>/Gain1'
   *  Saturate: '<S69>/Saturation'
   */
  rtb_Add_m = 5.0E-6 * rtb_Total_Limited + rtb_Add_f_idx_1 + rtb_Switch2_a;

  /* Sum: '<S69>/Subtract' incorporates:
   *  Constant: '<S69>/Constant'
   */
  rtb_Switch2_h4 = 1.0 - rtb_Add_m;

  /* Sum: '<S69>/Sum2' incorporates:
   *  Gain: '<S69>/Gain2'
   *  UnitDelay: '<S69>/Unit Delay'
   */
  rtb_Total_Limited = 0.0 * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_gp;

  /* Switch: '<S78>/Switch2' incorporates:
   *  Constant: '<S69>/Constant'
   *  RelationalOperator: '<S78>/LowerRelop1'
   *  Sum: '<S69>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Add_m)) {
    /* Switch: '<S78>/Switch' incorporates:
     *  Constant: '<S69>/Constant1'
     *  RelationalOperator: '<S78>/UpperRelop'
     *  Sum: '<S69>/Subtract1'
     */
    if (rtb_Total_Limited < -1.0 - rtb_Add_m) {
      rtb_Switch2_h4 = -1.0 - rtb_Add_m;
    } else {
      rtb_Switch2_h4 = rtb_Total_Limited;
    }

    /* End of Switch: '<S78>/Switch' */
  }

  /* End of Switch: '<S78>/Switch2' */

  /* Saturate: '<S69>/Saturation1' */
  if (rtb_Switch2_h4 > 0.0) {
    rtb_Add_f_idx_1 = 0.0;
  } else if (rtb_Switch2_h4 < -0.0) {
    rtb_Add_f_idx_1 = -0.0;
  } else {
    rtb_Add_f_idx_1 = rtb_Switch2_h4;
  }

  /* End of Saturate: '<S69>/Saturation1' */

  /* Sum: '<S69>/Add1' */
  rtb_Switch2_a = rtb_Add_m + rtb_Add_f_idx_1;

  /* Saturate: '<S69>/Saturation2' */
  if (rtb_Switch2_a > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Switch2_a < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = rtb_Switch2_a;
  }

  /* End of Saturate: '<S69>/Saturation2' */

  /* Sum: '<S86>/Add1' incorporates:
   *  Constant: '<S86>/Constant3'
   *  Constant: '<S86>/Constant4'
   *  Math: '<S86>/Math Function'
   *  Sum: '<S86>/Add2'
   */
  rtb_Total_Limited = rt_modd_snf(rtb_Product_bx + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S88>/Sum1' incorporates:
   *  Constant: '<S72>/Constant2'
   *  Product: '<S88>/Product'
   *  Sum: '<S88>/Sum'
   *  UnitDelay: '<S88>/Unit Delay1'
   */
  rtb_Add_m = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_n) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S72>/Product' incorporates:
   *  Constant: '<S72>/Constant3'
   */
  rtb_Product_lf = rtb_Add_m * 0.5;

  /* Sum: '<S87>/Diff' incorporates:
   *  UnitDelay: '<S87>/UD'
   *
   * Block description for '<S87>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S87>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Switch2_a = rtb_Product_lf - Code_Gen_Model_DW.UD_DSTATE_k;

  /* Saturate: '<S72>/Saturation' */
  if (rtb_Switch2_a > 0.2) {
    rtb_Switch2_a = 0.2;
  } else if (rtb_Switch2_a < -0.2) {
    rtb_Switch2_a = -0.2;
  }

  /* Sum: '<S72>/Add' incorporates:
   *  Gain: '<S72>/Gain1'
   *  Saturate: '<S72>/Saturation'
   */
  rtb_Add_f1 = 0.15 * rtb_Total_Limited + rtb_Switch2_a;

  /* Sum: '<S72>/Subtract' incorporates:
   *  Constant: '<S72>/Constant'
   */
  rtb_Switch2_a = 1.0 - rtb_Add_f1;

  /* Sum: '<S72>/Sum2' incorporates:
   *  Gain: '<S72>/Gain2'
   *  UnitDelay: '<S72>/Unit Delay'
   */
  rtb_Total_Limited = 0.005 * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S89>/Switch2' incorporates:
   *  Constant: '<S72>/Constant'
   *  RelationalOperator: '<S89>/LowerRelop1'
   *  Sum: '<S72>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Add_f1)) {
    /* Sum: '<S72>/Subtract1' incorporates:
     *  Constant: '<S72>/Constant1'
     */
    rtb_Switch2_a = -1.0 - rtb_Add_f1;

    /* Switch: '<S89>/Switch' incorporates:
     *  Constant: '<S72>/Constant1'
     *  RelationalOperator: '<S89>/UpperRelop'
     *  Sum: '<S72>/Subtract1'
     */
    if (!(rtb_Total_Limited < -1.0 - rtb_Add_f1)) {
      rtb_Switch2_a = rtb_Total_Limited;
    }

    /* End of Switch: '<S89>/Switch' */
  }

  /* End of Switch: '<S89>/Switch2' */

  /* Saturate: '<S72>/Saturation1' */
  if (rtb_Switch2_a > 0.005) {
    rtb_Integral_g = 0.005;
  } else if (rtb_Switch2_a < -0.005) {
    rtb_Integral_g = -0.005;
  } else {
    rtb_Integral_g = rtb_Switch2_a;
  }

  /* End of Saturate: '<S72>/Saturation1' */

  /* Outport: '<Root>/BackLeft_Steer_DutyCycle' incorporates:
   *  Saturate: '<S72>/Saturation2'
   *  Sum: '<S72>/Add1'
   */
  Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = rtb_Add_f1 + rtb_Integral_g;

  /* Fcn: '<S153>/x->r' */
  rtb_Total_Limited = rt_hypotd_snf(rtb_TmpSignalConversionAtLook_o[0],
    rtb_TmpSignalConversionAtLook_o[1]);

  /* Switch: '<S152>/Switch1' incorporates:
   *  Constant: '<S156>/Constant'
   *  RelationalOperator: '<S156>/Compare'
   *  Switch: '<S152>/Switch'
   */
  if (rtb_Total_Limited == 0.0) {
    /* Switch: '<S152>/Switch1' incorporates:
     *  Constant: '<S152>/Constant'
     */
    Code_Gen_Model_B.FR_Wheel_Speed = 1.0E-15;
  } else {
    /* Switch: '<S152>/Switch1' */
    Code_Gen_Model_B.FR_Wheel_Speed = rtb_Total_Limited;

    /* Switch: '<S152>/Switch' incorporates:
     *  Fcn: '<S153>/x->theta'
     */
    Code_Gen_Model_B.FR_Module_Angle = rt_atan2d_snf
      (rtb_TmpSignalConversionAtLook_o[1], rtb_TmpSignalConversionAtLook_o[0]);
  }

  /* End of Switch: '<S152>/Switch1' */

  /* Trigonometry: '<S60>/Cos4' incorporates:
   *  Switch: '<S48>/Angle_Switch'
   *  Trigonometry: '<S59>/Cos4'
   */
  rtb_Subtract_n = cos(Code_Gen_Model_B.FR_Module_Angle);

  /* Sum: '<S56>/Add1' incorporates:
   *  Constant: '<S56>/Constant3'
   *  Constant: '<S56>/Constant4'
   *  Gain: '<S47>/Revolutions to Radians'
   *  Inport: '<Root>/FrontRight_Steer_Encoder'
   *  Inport: '<Root>/FrontRight_Turn_Offset'
   *  Math: '<S56>/Math Function'
   *  Sum: '<S47>/Add'
   *  Sum: '<S56>/Add2'
   */
  Code_Gen_Model_B.FR_Steer_Module_Angle_Adjusted = rt_modd_snf
    ((Code_Gen_Model_U.FrontRight_Steer_Encoder -
      Code_Gen_Model_U.FrontRight_Turn_Offset) * 6.2831853071795862 +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Trigonometry: '<S60>/Sin5' incorporates:
   *  UnaryMinus: '<S58>/Unary Minus'
   */
  rtb_Switch2_h4 = sin(-Code_Gen_Model_B.FR_Steer_Module_Angle_Adjusted);

  /* Trigonometry: '<S60>/Sin4' incorporates:
   *  Switch: '<S48>/Angle_Switch'
   *  Trigonometry: '<S59>/Sin4'
   */
  rtb_Product_j = sin(Code_Gen_Model_B.FR_Module_Angle);

  /* Trigonometry: '<S60>/Cos5' incorporates:
   *  UnaryMinus: '<S58>/Unary Minus'
   */
  rtb_Switch2_a = cos(-Code_Gen_Model_B.FR_Steer_Module_Angle_Adjusted);

  /* Sum: '<S60>/Subtract1' incorporates:
   *  Product: '<S60>/Product2'
   *  Product: '<S60>/Product3'
   *  Trigonometry: '<S60>/Cos4'
   *  Trigonometry: '<S60>/Sin4'
   */
  rtb_Total_Limited = rtb_Subtract_n * rtb_Switch2_h4 + rtb_Product_j *
    rtb_Switch2_a;

  /* Sum: '<S60>/Subtract' incorporates:
   *  Product: '<S60>/Product'
   *  Product: '<S60>/Product1'
   *  Trigonometry: '<S60>/Cos4'
   *  Trigonometry: '<S60>/Sin4'
   */
  rtb_Switch2_a = rtb_Subtract_n * rtb_Switch2_a - rtb_Product_j *
    rtb_Switch2_h4;

  /* Math: '<S60>/Hypot' */
  rtb_Add_f1 = rt_hypotd_snf(rtb_Switch2_a, rtb_Total_Limited);

  /* Switch: '<S60>/Switch' incorporates:
   *  Constant: '<S60>/Constant'
   *  Constant: '<S60>/Constant1'
   *  Constant: '<S61>/Constant'
   *  Product: '<S60>/Divide'
   *  Product: '<S60>/Divide1'
   *  RelationalOperator: '<S61>/Compare'
   *  Switch: '<S60>/Switch1'
   */
  if (rtb_Add_f1 > 1.0E-6) {
    rtb_Total_Limited /= rtb_Add_f1;
    rtb_Switch2_a /= rtb_Add_f1;
  } else {
    rtb_Total_Limited = 0.0;
    rtb_Switch2_a = 1.0;
  }

  /* End of Switch: '<S60>/Switch' */

  /* RelationalOperator: '<S57>/Compare' incorporates:
   *  Abs: '<S48>/Abs'
   *  Constant: '<S57>/Constant'
   *  Trigonometry: '<S60>/Atan1'
   */
  rtb_AND = fabs(rt_atan2d_snf(rtb_Total_Limited, rtb_Switch2_a)) >
    1.5707963267948966;

  /* Switch: '<S48>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S48>/Unary Minus'
   */
  if (rtb_AND) {
    rtb_Switch2_a = -Code_Gen_Model_B.FR_Wheel_Speed;
  } else {
    rtb_Switch2_a = Code_Gen_Model_B.FR_Wheel_Speed;
  }

  /* Product: '<S52>/Product2' incorporates:
   *  Constant: '<S52>/Constant'
   *  Switch: '<S48>/Speed_Switch'
   */
  rtb_Total_Limited = rtb_Switch2_a * 1530.1401357649195;

  /* Signum: '<S50>/Sign' */
  if (rtIsNaN(rtb_Total_Limited)) {
    rtb_Switch2_a = (rtNaN);
  } else if (rtb_Total_Limited < 0.0) {
    rtb_Switch2_a = -1.0;
  } else {
    rtb_Switch2_a = rtb_Total_Limited > 0.0;
  }

  /* Signum: '<S50>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Encoder'
   */
  if (rtIsNaN(Code_Gen_Model_U.FrontRight_Drive_Encoder)) {
    rtb_Add_ci = (rtNaN);
  } else if (Code_Gen_Model_U.FrontRight_Drive_Encoder < 0.0) {
    rtb_Add_ci = -1.0;
  } else {
    rtb_Add_ci = Code_Gen_Model_U.FrontRight_Drive_Encoder > 0.0;
  }

  /* Switch: '<S50>/Switch' incorporates:
   *  Abs: '<S50>/Abs'
   *  Constant: '<S50>/Constant'
   *  Constant: '<S67>/Constant'
   *  Inport: '<Root>/FrontRight_Drive_Encoder'
   *  Logic: '<S50>/OR'
   *  RelationalOperator: '<S50>/Equal1'
   *  RelationalOperator: '<S67>/Compare'
   *  Signum: '<S50>/Sign'
   *  Signum: '<S50>/Sign1'
   */
  if (!(rtb_Switch2_a == rtb_Add_ci) && !(fabs
       (Code_Gen_Model_U.FrontRight_Drive_Encoder) <= 1500.0)) {
    rtb_Total_Limited = 0.0;
  }

  /* End of Switch: '<S50>/Switch' */

  /* Switch: '<S48>/Angle_Switch' incorporates:
   *  Trigonometry: '<S59>/Atan1'
   */
  if (rtb_AND) {
    /* Sum: '<S59>/Subtract1' incorporates:
     *  Product: '<S59>/Product2'
     *  Product: '<S59>/Product3'
     */
    rtb_Switch2_a = rtb_Subtract_n * Code_Gen_Model_ConstB.Sin5_m +
      rtb_Product_j * Code_Gen_Model_ConstB.Cos5_g;

    /* Sum: '<S59>/Subtract' incorporates:
     *  Product: '<S59>/Product'
     *  Product: '<S59>/Product1'
     */
    rtb_Subtract_kb = rtb_Subtract_n * Code_Gen_Model_ConstB.Cos5_g -
      rtb_Product_j * Code_Gen_Model_ConstB.Sin5_m;

    /* Math: '<S59>/Hypot' */
    rtb_Add_f1 = rt_hypotd_snf(rtb_Subtract_kb, rtb_Switch2_a);

    /* Switch: '<S59>/Switch1' incorporates:
     *  Constant: '<S59>/Constant'
     *  Constant: '<S59>/Constant1'
     *  Constant: '<S62>/Constant'
     *  Product: '<S59>/Divide'
     *  Product: '<S59>/Divide1'
     *  RelationalOperator: '<S62>/Compare'
     *  Switch: '<S59>/Switch'
     */
    if (rtb_Add_f1 > 1.0E-6) {
      rtb_Subtract_kb /= rtb_Add_f1;
      rtb_Switch2_a /= rtb_Add_f1;
    } else {
      rtb_Subtract_kb = 1.0;
      rtb_Switch2_a = 0.0;
    }

    /* End of Switch: '<S59>/Switch1' */
    rtb_Switch2_a = rt_atan2d_snf(rtb_Switch2_a, rtb_Subtract_kb);
  } else {
    rtb_Switch2_a = Code_Gen_Model_B.FR_Module_Angle;
  }

  /* Sum: '<S51>/Add' incorporates:
   *  Sum: '<S49>/Sum'
   */
  rtb_Product_bx = rtb_Switch2_a -
    Code_Gen_Model_B.FR_Steer_Module_Angle_Adjusted;

  /* Product: '<S19>/Product' incorporates:
   *  Abs: '<S51>/Abs'
   *  Constant: '<S68>/Constant3'
   *  Constant: '<S68>/Constant4'
   *  Lookup_n-D: '<S51>/1-D Lookup Table'
   *  Math: '<S68>/Math Function'
   *  Sum: '<S51>/Add'
   *  Sum: '<S68>/Add1'
   *  Sum: '<S68>/Add2'
   */
  rtb_Total_Limited *= look1_binlcpw(fabs(rt_modd_snf(rtb_Product_bx +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
    Code_Gen_Model_ConstP.pooled25, Code_Gen_Model_ConstP.pooled24, 1U);

  /* Gain: '<S46>/Gain' */
  rtb_Switch2_h4 = 0.00018181818181818181 * rtb_Total_Limited;

  /* Sum: '<S46>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Encoder'
   */
  rtb_Total_Limited -= Code_Gen_Model_U.FrontRight_Drive_Encoder;

  /* Sum: '<S54>/Sum1' incorporates:
   *  Constant: '<S46>/Constant2'
   *  Product: '<S54>/Product'
   *  Sum: '<S54>/Sum'
   *  UnitDelay: '<S54>/Unit Delay1'
   */
  rtb_Add_f1 = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_b) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S46>/Product' incorporates:
   *  Constant: '<S46>/Constant3'
   */
  rtb_Subtract_kb = rtb_Add_f1 * 9.9999999999999991E-5;

  /* Sum: '<S53>/Diff' incorporates:
   *  UnitDelay: '<S53>/UD'
   *
   * Block description for '<S53>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S53>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Switch2_a = rtb_Subtract_kb - Code_Gen_Model_DW.UD_DSTATE_e;

  /* Saturate: '<S46>/Saturation' */
  if (rtb_Switch2_a > 0.2) {
    rtb_Switch2_a = 0.2;
  } else if (rtb_Switch2_a < -0.2) {
    rtb_Switch2_a = -0.2;
  }

  /* Sum: '<S46>/Add' incorporates:
   *  Gain: '<S46>/Gain1'
   *  Saturate: '<S46>/Saturation'
   */
  rtb_Add_pd = 5.0E-6 * rtb_Total_Limited + rtb_Switch2_h4 + rtb_Switch2_a;

  /* Sum: '<S46>/Subtract' incorporates:
   *  Constant: '<S46>/Constant'
   */
  rtb_Switch2_h4 = 1.0 - rtb_Add_pd;

  /* Sum: '<S46>/Sum2' incorporates:
   *  Gain: '<S46>/Gain2'
   *  UnitDelay: '<S46>/Unit Delay'
   */
  rtb_Total_Limited = 0.0 * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S55>/Switch2' incorporates:
   *  Constant: '<S46>/Constant'
   *  RelationalOperator: '<S55>/LowerRelop1'
   *  Sum: '<S46>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Add_pd)) {
    /* Sum: '<S46>/Subtract1' incorporates:
     *  Constant: '<S46>/Constant1'
     */
    rtb_Switch2_h4 = -1.0 - rtb_Add_pd;

    /* Switch: '<S55>/Switch' incorporates:
     *  Constant: '<S46>/Constant1'
     *  RelationalOperator: '<S55>/UpperRelop'
     *  Sum: '<S46>/Subtract1'
     */
    if (!(rtb_Total_Limited < -1.0 - rtb_Add_pd)) {
      rtb_Switch2_h4 = rtb_Total_Limited;
    }

    /* End of Switch: '<S55>/Switch' */
  }

  /* End of Switch: '<S55>/Switch2' */

  /* Saturate: '<S46>/Saturation1' */
  if (rtb_Switch2_h4 > 0.0) {
    rtb_Integral_f = 0.0;
  } else if (rtb_Switch2_h4 < -0.0) {
    rtb_Integral_f = -0.0;
  } else {
    rtb_Integral_f = rtb_Switch2_h4;
  }

  /* End of Saturate: '<S46>/Saturation1' */

  /* Sum: '<S46>/Add1' */
  rtb_Switch2_a = rtb_Add_pd + rtb_Integral_f;

  /* Saturate: '<S46>/Saturation2' */
  if (rtb_Switch2_a > 1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Switch2_a < -1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = rtb_Switch2_a;
  }

  /* End of Saturate: '<S46>/Saturation2' */

  /* Sum: '<S63>/Add1' incorporates:
   *  Constant: '<S63>/Constant3'
   *  Constant: '<S63>/Constant4'
   *  Math: '<S63>/Math Function'
   *  Sum: '<S63>/Add2'
   */
  rtb_Total_Limited = rt_modd_snf(rtb_Product_bx + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S65>/Sum1' incorporates:
   *  Constant: '<S49>/Constant2'
   *  Product: '<S65>/Product'
   *  Sum: '<S65>/Sum'
   *  UnitDelay: '<S65>/Unit Delay1'
   */
  rtb_Add_pd = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_na) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_na;

  /* Product: '<S49>/Product' incorporates:
   *  Constant: '<S49>/Constant3'
   */
  rtb_Product_k = rtb_Add_pd * 0.5;

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
  rtb_Switch2_a = rtb_Product_k - Code_Gen_Model_DW.UD_DSTATE_i1;

  /* Saturate: '<S49>/Saturation' */
  if (rtb_Switch2_a > 0.2) {
    rtb_Switch2_a = 0.2;
  } else if (rtb_Switch2_a < -0.2) {
    rtb_Switch2_a = -0.2;
  }

  /* Sum: '<S49>/Add' incorporates:
   *  Gain: '<S49>/Gain1'
   *  Saturate: '<S49>/Saturation'
   */
  rtb_Switch2_h4 = 0.15 * rtb_Total_Limited + rtb_Switch2_a;

  /* Sum: '<S49>/Subtract' incorporates:
   *  Constant: '<S49>/Constant'
   */
  rtb_Switch2_a = 1.0 - rtb_Switch2_h4;

  /* Sum: '<S49>/Sum2' incorporates:
   *  Gain: '<S49>/Gain2'
   *  UnitDelay: '<S49>/Unit Delay'
   */
  rtb_Total_Limited = 0.005 * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S66>/Switch2' incorporates:
   *  Constant: '<S49>/Constant'
   *  RelationalOperator: '<S66>/LowerRelop1'
   *  Sum: '<S49>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Switch2_h4)) {
    /* Sum: '<S49>/Subtract1' incorporates:
     *  Constant: '<S49>/Constant1'
     */
    rtb_Switch2_a = -1.0 - rtb_Switch2_h4;

    /* Switch: '<S66>/Switch' incorporates:
     *  Constant: '<S49>/Constant1'
     *  RelationalOperator: '<S66>/UpperRelop'
     *  Sum: '<S49>/Subtract1'
     */
    if (!(rtb_Total_Limited < -1.0 - rtb_Switch2_h4)) {
      rtb_Switch2_a = rtb_Total_Limited;
    }

    /* End of Switch: '<S66>/Switch' */
  }

  /* End of Switch: '<S66>/Switch2' */

  /* Saturate: '<S49>/Saturation1' */
  if (rtb_Switch2_a > 0.005) {
    rtb_Integral_ec = 0.005;
  } else if (rtb_Switch2_a < -0.005) {
    rtb_Integral_ec = -0.005;
  } else {
    rtb_Integral_ec = rtb_Switch2_a;
  }

  /* End of Saturate: '<S49>/Saturation1' */

  /* Outport: '<Root>/FrontRight_Steer_DutyCycle' incorporates:
   *  Saturate: '<S49>/Saturation2'
   *  Sum: '<S49>/Add1'
   */
  Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = rtb_Switch2_h4 + rtb_Integral_ec;

  /* Fcn: '<S148>/x->r' */
  rtb_Total_Limited = rt_hypotd_snf(rtb_Product7[0], rtb_Product7[1]);

  /* Switch: '<S147>/Switch1' incorporates:
   *  Constant: '<S151>/Constant'
   *  RelationalOperator: '<S151>/Compare'
   *  Switch: '<S147>/Switch'
   */
  if (rtb_Total_Limited == 0.0) {
    /* Switch: '<S147>/Switch1' incorporates:
     *  Constant: '<S147>/Constant'
     */
    Code_Gen_Model_B.FL_Wheel_Speed = 1.0E-15;
  } else {
    /* Switch: '<S147>/Switch1' */
    Code_Gen_Model_B.FL_Wheel_Speed = rtb_Total_Limited;

    /* Switch: '<S147>/Switch' incorporates:
     *  Fcn: '<S148>/x->theta'
     */
    Code_Gen_Model_B.FL_Module_Angle = rt_atan2d_snf(rtb_Product7[1],
      rtb_Product7[0]);
  }

  /* End of Switch: '<S147>/Switch1' */

  /* Trigonometry: '<S37>/Cos4' incorporates:
   *  Switch: '<S25>/Angle_Switch'
   *  Trigonometry: '<S36>/Cos4'
   */
  rtb_Subtract_n = cos(Code_Gen_Model_B.FL_Module_Angle);

  /* Sum: '<S33>/Add1' incorporates:
   *  Constant: '<S33>/Constant3'
   *  Constant: '<S33>/Constant4'
   *  Gain: '<S24>/Revolutions to Radians'
   *  Inport: '<Root>/FrontLeft_Steer_Encoder'
   *  Inport: '<Root>/FrontLeft_Turn_Offset'
   *  Math: '<S33>/Math Function'
   *  Sum: '<S24>/Add'
   *  Sum: '<S33>/Add2'
   */
  Code_Gen_Model_B.FL_Steer_Module_Angle_Adjusted = rt_modd_snf
    ((Code_Gen_Model_U.FrontLeft_Steer_Encoder -
      Code_Gen_Model_U.FrontLeft_Turn_Offset) * 6.2831853071795862 +
     3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Trigonometry: '<S37>/Sin5' incorporates:
   *  UnaryMinus: '<S35>/Unary Minus'
   */
  rtb_Switch2_h4 = sin(-Code_Gen_Model_B.FL_Steer_Module_Angle_Adjusted);

  /* Trigonometry: '<S37>/Sin4' incorporates:
   *  Switch: '<S25>/Angle_Switch'
   *  Trigonometry: '<S36>/Sin4'
   */
  rtb_Product_j = sin(Code_Gen_Model_B.FL_Module_Angle);

  /* Trigonometry: '<S37>/Cos5' incorporates:
   *  UnaryMinus: '<S35>/Unary Minus'
   */
  rtb_Switch2_a = cos(-Code_Gen_Model_B.FL_Steer_Module_Angle_Adjusted);

  /* Sum: '<S37>/Subtract1' incorporates:
   *  Product: '<S37>/Product2'
   *  Product: '<S37>/Product3'
   *  Trigonometry: '<S37>/Cos4'
   *  Trigonometry: '<S37>/Sin4'
   */
  rtb_Total_Limited = rtb_Subtract_n * rtb_Switch2_h4 + rtb_Product_j *
    rtb_Switch2_a;

  /* Sum: '<S37>/Subtract' incorporates:
   *  Product: '<S37>/Product'
   *  Product: '<S37>/Product1'
   *  Trigonometry: '<S37>/Cos4'
   *  Trigonometry: '<S37>/Sin4'
   */
  rtb_Switch2_a = rtb_Subtract_n * rtb_Switch2_a - rtb_Product_j *
    rtb_Switch2_h4;

  /* Math: '<S37>/Hypot' */
  rtb_Switch2_h4 = rt_hypotd_snf(rtb_Switch2_a, rtb_Total_Limited);

  /* Switch: '<S37>/Switch' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   *  Constant: '<S38>/Constant'
   *  Product: '<S37>/Divide'
   *  Product: '<S37>/Divide1'
   *  RelationalOperator: '<S38>/Compare'
   *  Switch: '<S37>/Switch1'
   */
  if (rtb_Switch2_h4 > 1.0E-6) {
    rtb_Total_Limited /= rtb_Switch2_h4;
    rtb_Switch2_a /= rtb_Switch2_h4;
  } else {
    rtb_Total_Limited = 0.0;
    rtb_Switch2_a = 1.0;
  }

  /* End of Switch: '<S37>/Switch' */

  /* RelationalOperator: '<S34>/Compare' incorporates:
   *  Abs: '<S25>/Abs'
   *  Constant: '<S34>/Constant'
   *  Trigonometry: '<S37>/Atan1'
   */
  rtb_AND = fabs(rt_atan2d_snf(rtb_Total_Limited, rtb_Switch2_a)) >
    1.5707963267948966;

  /* Switch: '<S25>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S25>/Unary Minus'
   */
  if (rtb_AND) {
    rtb_Switch2_a = -Code_Gen_Model_B.FL_Wheel_Speed;
  } else {
    rtb_Switch2_a = Code_Gen_Model_B.FL_Wheel_Speed;
  }

  /* Product: '<S29>/Product2' incorporates:
   *  Constant: '<S29>/Constant'
   *  Switch: '<S25>/Speed_Switch'
   */
  rtb_Total_Limited = rtb_Switch2_a * 1530.1401357649195;

  /* Signum: '<S27>/Sign' */
  if (rtIsNaN(rtb_Total_Limited)) {
    rtb_Switch2_a = (rtNaN);
  } else if (rtb_Total_Limited < 0.0) {
    rtb_Switch2_a = -1.0;
  } else {
    rtb_Switch2_a = rtb_Total_Limited > 0.0;
  }

  /* Signum: '<S27>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Encoder'
   */
  if (rtIsNaN(Code_Gen_Model_U.FrontLeft_Drive_Encoder)) {
    rtb_Add_ci = (rtNaN);
  } else if (Code_Gen_Model_U.FrontLeft_Drive_Encoder < 0.0) {
    rtb_Add_ci = -1.0;
  } else {
    rtb_Add_ci = Code_Gen_Model_U.FrontLeft_Drive_Encoder > 0.0;
  }

  /* Switch: '<S27>/Switch' incorporates:
   *  Abs: '<S27>/Abs'
   *  Constant: '<S27>/Constant'
   *  Constant: '<S44>/Constant'
   *  Inport: '<Root>/FrontLeft_Drive_Encoder'
   *  Logic: '<S27>/OR'
   *  RelationalOperator: '<S27>/Equal1'
   *  RelationalOperator: '<S44>/Compare'
   *  Signum: '<S27>/Sign'
   *  Signum: '<S27>/Sign1'
   */
  if (!(rtb_Switch2_a == rtb_Add_ci) && !(fabs
       (Code_Gen_Model_U.FrontLeft_Drive_Encoder) <= 1500.0)) {
    rtb_Total_Limited = 0.0;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Switch: '<S25>/Angle_Switch' incorporates:
   *  Trigonometry: '<S36>/Atan1'
   */
  if (rtb_AND) {
    /* Sum: '<S36>/Subtract1' incorporates:
     *  Product: '<S36>/Product2'
     *  Product: '<S36>/Product3'
     */
    rtb_Switch2_a = rtb_Subtract_n * Code_Gen_Model_ConstB.Sin5 + rtb_Product_j *
      Code_Gen_Model_ConstB.Cos5;

    /* Sum: '<S36>/Subtract' incorporates:
     *  Product: '<S36>/Product'
     *  Product: '<S36>/Product1'
     */
    rtb_Subtract_n = rtb_Subtract_n * Code_Gen_Model_ConstB.Cos5 - rtb_Product_j
      * Code_Gen_Model_ConstB.Sin5;

    /* Math: '<S36>/Hypot' */
    rtb_Switch2_h4 = rt_hypotd_snf(rtb_Subtract_n, rtb_Switch2_a);

    /* Switch: '<S36>/Switch1' incorporates:
     *  Constant: '<S36>/Constant'
     *  Constant: '<S36>/Constant1'
     *  Constant: '<S39>/Constant'
     *  Product: '<S36>/Divide'
     *  Product: '<S36>/Divide1'
     *  RelationalOperator: '<S39>/Compare'
     *  Switch: '<S36>/Switch'
     */
    if (rtb_Switch2_h4 > 1.0E-6) {
      rtb_Subtract_n /= rtb_Switch2_h4;
      rtb_Switch2_a /= rtb_Switch2_h4;
    } else {
      rtb_Subtract_n = 1.0;
      rtb_Switch2_a = 0.0;
    }

    /* End of Switch: '<S36>/Switch1' */
    rtb_Switch2_a = rt_atan2d_snf(rtb_Switch2_a, rtb_Subtract_n);
  } else {
    rtb_Switch2_a = Code_Gen_Model_B.FL_Module_Angle;
  }

  /* Sum: '<S28>/Add' incorporates:
   *  Sum: '<S26>/Sum'
   */
  rtb_Product_bx = rtb_Switch2_a -
    Code_Gen_Model_B.FL_Steer_Module_Angle_Adjusted;

  /* Product: '<S18>/Product' incorporates:
   *  Abs: '<S28>/Abs'
   *  Constant: '<S45>/Constant3'
   *  Constant: '<S45>/Constant4'
   *  Lookup_n-D: '<S28>/1-D Lookup Table'
   *  Math: '<S45>/Math Function'
   *  Sum: '<S28>/Add'
   *  Sum: '<S45>/Add1'
   *  Sum: '<S45>/Add2'
   */
  rtb_Total_Limited *= look1_binlcpw(fabs(rt_modd_snf(rtb_Product_bx +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
    Code_Gen_Model_ConstP.pooled25, Code_Gen_Model_ConstP.pooled24, 1U);

  /* Gain: '<S23>/Gain' */
  rtb_Switch2_h4 = 0.00018181818181818181 * rtb_Total_Limited;

  /* Sum: '<S23>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Encoder'
   */
  rtb_Total_Limited -= Code_Gen_Model_U.FrontLeft_Drive_Encoder;

  /* Sum: '<S31>/Sum1' incorporates:
   *  Constant: '<S23>/Constant2'
   *  Product: '<S31>/Product'
   *  Sum: '<S31>/Sum'
   *  UnitDelay: '<S31>/Unit Delay1'
   */
  rtb_Subtract_n = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_a) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_a;

  /* Product: '<S23>/Product' incorporates:
   *  Constant: '<S23>/Constant3'
   */
  rtb_Product_j = rtb_Subtract_n * 9.9999999999999991E-5;

  /* Sum: '<S30>/Diff' incorporates:
   *  UnitDelay: '<S30>/UD'
   *
   * Block description for '<S30>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S30>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Switch2_a = rtb_Product_j - Code_Gen_Model_DW.UD_DSTATE_o;

  /* Saturate: '<S23>/Saturation' */
  if (rtb_Switch2_a > 0.2) {
    rtb_Switch2_a = 0.2;
  } else if (rtb_Switch2_a < -0.2) {
    rtb_Switch2_a = -0.2;
  }

  /* Sum: '<S23>/Add' incorporates:
   *  Gain: '<S23>/Gain1'
   *  Saturate: '<S23>/Saturation'
   */
  rtb_Add_ci = 5.0E-6 * rtb_Total_Limited + rtb_Switch2_h4 + rtb_Switch2_a;

  /* Sum: '<S23>/Subtract' incorporates:
   *  Constant: '<S23>/Constant'
   */
  rtb_Switch2_h4 = 1.0 - rtb_Add_ci;

  /* Sum: '<S23>/Sum2' incorporates:
   *  Gain: '<S23>/Gain2'
   *  UnitDelay: '<S23>/Unit Delay'
   */
  rtb_Total_Limited = 0.0 * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_f;

  /* Switch: '<S32>/Switch2' incorporates:
   *  Constant: '<S23>/Constant'
   *  RelationalOperator: '<S32>/LowerRelop1'
   *  Sum: '<S23>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Add_ci)) {
    /* Sum: '<S23>/Subtract1' incorporates:
     *  Constant: '<S23>/Constant1'
     */
    rtb_Switch2_h4 = -1.0 - rtb_Add_ci;

    /* Switch: '<S32>/Switch' incorporates:
     *  Constant: '<S23>/Constant1'
     *  RelationalOperator: '<S32>/UpperRelop'
     *  Sum: '<S23>/Subtract1'
     */
    if (!(rtb_Total_Limited < -1.0 - rtb_Add_ci)) {
      rtb_Switch2_h4 = rtb_Total_Limited;
    }

    /* End of Switch: '<S32>/Switch' */
  }

  /* End of Switch: '<S32>/Switch2' */

  /* Saturate: '<S23>/Saturation1' */
  if (rtb_Switch2_h4 > 0.0) {
    rtb_Switch2_h4 = 0.0;
  } else if (rtb_Switch2_h4 < -0.0) {
    rtb_Switch2_h4 = -0.0;
  }

  /* End of Saturate: '<S23>/Saturation1' */

  /* Sum: '<S23>/Add1' */
  rtb_Switch2_a = rtb_Add_ci + rtb_Switch2_h4;

  /* Saturate: '<S23>/Saturation2' */
  if (rtb_Switch2_a > 1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Switch2_a < -1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = rtb_Switch2_a;
  }

  /* End of Saturate: '<S23>/Saturation2' */

  /* Sum: '<S40>/Add1' incorporates:
   *  Constant: '<S40>/Constant3'
   *  Constant: '<S40>/Constant4'
   *  Math: '<S40>/Math Function'
   *  Sum: '<S40>/Add2'
   */
  rtb_Total_Limited = rt_modd_snf(rtb_Product_bx + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S42>/Sum1' incorporates:
   *  Constant: '<S26>/Constant2'
   *  Product: '<S42>/Product'
   *  Sum: '<S42>/Sum'
   *  UnitDelay: '<S42>/Unit Delay1'
   */
  rtb_Add_ci = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_bk) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_bk;

  /* Product: '<S26>/Product' incorporates:
   *  Constant: '<S26>/Constant3'
   */
  rtb_Product_bx = rtb_Add_ci * 0.5;

  /* Sum: '<S41>/Diff' incorporates:
   *  UnitDelay: '<S41>/UD'
   *
   * Block description for '<S41>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S41>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Switch2_a = rtb_Product_bx - Code_Gen_Model_DW.UD_DSTATE_b;

  /* Saturate: '<S26>/Saturation' */
  if (rtb_Switch2_a > 0.2) {
    rtb_Switch2_a = 0.2;
  } else if (rtb_Switch2_a < -0.2) {
    rtb_Switch2_a = -0.2;
  }

  /* Sum: '<S26>/Add' incorporates:
   *  Gain: '<S26>/Gain1'
   *  Saturate: '<S26>/Saturation'
   */
  rtb_Add_oc = 0.15 * rtb_Total_Limited + rtb_Switch2_a;

  /* Sum: '<S26>/Subtract' incorporates:
   *  Constant: '<S26>/Constant'
   */
  rtb_Switch2_a = 1.0 - rtb_Add_oc;

  /* Sum: '<S26>/Sum2' incorporates:
   *  Gain: '<S26>/Gain2'
   *  UnitDelay: '<S26>/Unit Delay'
   */
  rtb_Total_Limited = 0.005 * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_em;

  /* Switch: '<S43>/Switch2' incorporates:
   *  Constant: '<S26>/Constant'
   *  RelationalOperator: '<S43>/LowerRelop1'
   *  Sum: '<S26>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Add_oc)) {
    /* Sum: '<S26>/Subtract1' incorporates:
     *  Constant: '<S26>/Constant1'
     */
    rtb_Switch2_a = -1.0 - rtb_Add_oc;

    /* Switch: '<S43>/Switch' incorporates:
     *  Constant: '<S26>/Constant1'
     *  RelationalOperator: '<S43>/UpperRelop'
     *  Sum: '<S26>/Subtract1'
     */
    if (!(rtb_Total_Limited < -1.0 - rtb_Add_oc)) {
      rtb_Switch2_a = rtb_Total_Limited;
    }

    /* End of Switch: '<S43>/Switch' */
  }

  /* End of Switch: '<S43>/Switch2' */

  /* Saturate: '<S26>/Saturation1' */
  if (rtb_Switch2_a > 0.005) {
    rtb_Total_Limited = 0.005;
  } else if (rtb_Switch2_a < -0.005) {
    rtb_Total_Limited = -0.005;
  } else {
    rtb_Total_Limited = rtb_Switch2_a;
  }

  /* End of Saturate: '<S26>/Saturation1' */

  /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' incorporates:
   *  Saturate: '<S26>/Saturation2'
   *  Sum: '<S26>/Add1'
   */
  Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = rtb_Add_oc + rtb_Total_Limited;

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

  /* Update for UnitDelay: '<S126>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S126>/FixPt Constant'
   */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S140>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE = rtb_thetay;

  /* Update for UnitDelay: '<S139>/UD'
   *
   * Block description for '<S139>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_a = rtb_Switch2;

  /* Update for UnitDelay: '<S137>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_m = rtb_Sum1_li;

  /* Update for UnitDelay: '<S135>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S135>/FixPt Constant'
   */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S100>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_k = rtb_Sin4;

  /* Update for UnitDelay: '<S99>/UD'
   *
   * Block description for '<S99>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_cs = rtb_Init;

  /* Update for UnitDelay: '<S92>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_a = rtb_Switch2_g;

  /* Update for UnitDelay: '<S111>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_i = rtb_Switch_kj;

  /* Update for UnitDelay: '<S110>/UD'
   *
   * Block description for '<S110>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_l = rtb_Subtract1_lg;

  /* Update for UnitDelay: '<S95>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_l = rtb_Sum2_fc;

  /* Update for UnitDelay: '<S77>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_f = rtb_Add_p;

  /* Update for UnitDelay: '<S76>/UD'
   *
   * Block description for '<S76>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_lh = rtb_Add_f_idx_0;

  /* Update for UnitDelay: '<S69>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_gp = rtb_Add_f_idx_1;

  /* Update for UnitDelay: '<S88>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_n = rtb_Add_m;

  /* Update for UnitDelay: '<S87>/UD'
   *
   * Block description for '<S87>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_k = rtb_Product_lf;

  /* Update for UnitDelay: '<S72>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_k = rtb_Integral_g;

  /* Update for UnitDelay: '<S54>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_b = rtb_Add_f1;

  /* Update for UnitDelay: '<S53>/UD'
   *
   * Block description for '<S53>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_e = rtb_Subtract_kb;

  /* Update for UnitDelay: '<S46>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_e = rtb_Integral_f;

  /* Update for UnitDelay: '<S65>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_na = rtb_Add_pd;

  /* Update for UnitDelay: '<S64>/UD'
   *
   * Block description for '<S64>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_i1 = rtb_Product_k;

  /* Update for UnitDelay: '<S49>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_d = rtb_Integral_ec;

  /* Update for UnitDelay: '<S31>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_a = rtb_Subtract_n;

  /* Update for UnitDelay: '<S30>/UD'
   *
   * Block description for '<S30>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_o = rtb_Product_j;

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_f = rtb_Switch2_h4;

  /* Update for UnitDelay: '<S42>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_bk = rtb_Add_ci;

  /* Update for UnitDelay: '<S41>/UD'
   *
   * Block description for '<S41>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_b = rtb_Product_bx;

  /* Update for UnitDelay: '<S26>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_em = rtb_Total_Limited;

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

  /* InitializeConditions for UnitDelay: '<S126>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S135>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Accumulator2' */
  Code_Gen_Model_DW.Accumulator2_DSTATE = Code_Gen_Model_ConstB.Constant;

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Accumulator' */
  Code_Gen_Model_DW.Accumulator_DSTATE = Code_Gen_Model_ConstB.Constant1;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S186>/FixPt Unit Delay2' */
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
