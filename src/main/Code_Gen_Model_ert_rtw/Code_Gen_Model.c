/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.22
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Nov 25 11:38:35 2023
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
boolean_T Odometry_X_Y_TEAR = false;   /* Variable: Odometry_X_Y_TEAR
                                        * Referenced by: '<S19>/Constant'
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
 *    '<S1>/Autonomous'
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
  real_T rtb_Init;
  real_T rtb_Integral_da;
  real_T rtb_Integral_i;
  real_T rtb_Integral_je;
  real_T rtb_Modulation_Drv_X;
  real_T rtb_Optimized_Module_Angle;
  real_T rtb_POSEexponentialmatrixfori_0;
  real_T rtb_POSEexponentialmatrixfori_1;
  real_T rtb_POSEexponentialmatrixfori_2;
  real_T rtb_Product_go;
  real_T rtb_Product_lf;
  real_T rtb_Product_n3;
  real_T rtb_Product_nw;
  real_T rtb_Subtract1_lg;
  real_T rtb_Subtract1_pl;
  real_T rtb_Subtract_kb;
  real_T rtb_Subtract_n;
  real_T rtb_Sum1_li;
  real_T rtb_Sum2_fc;
  real_T rtb_Switch2;
  real_T rtb_Switch2_d;
  real_T rtb_Switch_kj;
  real_T rtb_Total_Limited;
  real_T rtb_thetay;
  real_T rtb_uDLookupTable;
  int32_T i;
  int32_T i_0;
  int32_T tmp;
  boolean_T rtb_AND;
  boolean_T rtb_Compare_dh;

  /* Sum: '<S20>/Add1' incorporates:
   *  Constant: '<S20>/Constant3'
   *  Constant: '<S20>/Constant4'
   *  Gain: '<S6>/Revolutions to Radians'
   *  Inport: '<Root>/FrontLeft_Steer_Rev'
   *  Inport: '<Root>/FrontLeft_Turn_Offset'
   *  Math: '<S20>/Math Function'
   *  Sum: '<S20>/Add2'
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
                Code_Gen_Model_DW.UD_DSTATE) * 0.039212094760200447;

  /* Sum: '<S21>/Add1' incorporates:
   *  Constant: '<S21>/Constant3'
   *  Constant: '<S21>/Constant4'
   *  Gain: '<S6>/Revolutions to Radians1'
   *  Inport: '<Root>/FrontRight_Steer_Rev'
   *  Inport: '<Root>/FrontRight_Turn_Offset'
   *  Math: '<S21>/Math Function'
   *  Sum: '<S21>/Add2'
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
  rtb_Init = (Code_Gen_Model_U.FrontRight_Drive_Motor_Rev -
              Code_Gen_Model_DW.UD_DSTATE_m) * 0.039212094760200447;

  /* Sum: '<S22>/Add1' incorporates:
   *  Constant: '<S22>/Constant3'
   *  Constant: '<S22>/Constant4'
   *  Gain: '<S6>/Revolutions to Radians2'
   *  Inport: '<Root>/BackLeft_Steer_Rev'
   *  Inport: '<Root>/BackLeft_Turn_Offset'
   *  Math: '<S22>/Math Function'
   *  Sum: '<S22>/Add2'
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
                       Code_Gen_Model_DW.UD_DSTATE_i) * 0.039212094760200447;

  /* Sum: '<S23>/Add1' incorporates:
   *  Constant: '<S23>/Constant3'
   *  Constant: '<S23>/Constant4'
   *  Gain: '<S6>/Revolutions to Radians3'
   *  Inport: '<Root>/BackRight_Steer_Rev'
   *  Inport: '<Root>/BackRight_Turn_Offset'
   *  Math: '<S23>/Math Function'
   *  Sum: '<S23>/Add2'
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
                   Code_Gen_Model_DW.UD_DSTATE_c) * 0.039212094760200447;

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
  rtb_thetay_0[2] = rtb_Init * cos(Code_Gen_Model_B.FR_Steer_Module_Angle);
  rtb_thetay_0[3] = rtb_Init * sin(Code_Gen_Model_B.FR_Steer_Module_Angle);
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
     *  ActionPort: '<S8>/Action Port'
     */
    /* Switch: '<S168>/Switch1' incorporates:
     *  Constant: '<S168>/Constant'
     *  Constant: '<S168>/Constant1'
     *  Constant: '<S168>/Constant2'
     *  Inport: '<Root>/Steer_Joystick_X'
     *  Inport: '<Root>/Steer_Joystick_Y'
     *  Math: '<S168>/Hypot'
     *  RelationalOperator: '<S168>/GreaterThan'
     *  Switch: '<S168>/Switch'
     */
    if (rt_hypotd_snf(Code_Gen_Model_U.Steer_Joystick_X,
                      Code_Gen_Model_U.Steer_Joystick_Y) > 0.7) {
      rtb_POSEexponentialmatrixfori_0 = Code_Gen_Model_U.Steer_Joystick_Y;
      rtb_uDLookupTable = Code_Gen_Model_U.Steer_Joystick_X;
    } else {
      rtb_POSEexponentialmatrixfori_0 = 0.0;
      rtb_uDLookupTable = 0.0;
    }

    /* End of Switch: '<S168>/Switch1' */

    /* Switch: '<S170>/Switch1' incorporates:
     *  Constant: '<S176>/Constant'
     *  Constant: '<S177>/Constant'
     *  Logic: '<S170>/AND'
     *  RelationalOperator: '<S176>/Compare'
     *  RelationalOperator: '<S177>/Compare'
     *  Switch: '<S170>/Switch2'
     *  UnitDelay: '<S170>/Unit Delay'
     *  UnitDelay: '<S170>/Unit Delay1'
     */
    if (rtb_uDLookupTable == 0.0 && rtb_POSEexponentialmatrixfori_0 == 0.0) {
      rtb_POSEexponentialmatrixfori_0 = Code_Gen_Model_DW.UnitDelay1_DSTATE_d2;
      rtb_Switch2 = Code_Gen_Model_DW.UnitDelay_DSTATE_g4;
    } else {
      rtb_Switch2 = rtb_uDLookupTable;
    }

    /* End of Switch: '<S170>/Switch1' */

    /* Merge: '<S1>/Merge1' incorporates:
     *  Trigonometry: '<S166>/Atan2'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd = rt_atan2d_snf
      (rtb_POSEexponentialmatrixfori_0, rtb_Switch2);

    /* RelationalOperator: '<S173>/Compare' incorporates:
     *  Constant: '<S173>/Constant'
     */
    rtb_AND = rtb_Switch2 < 0.0;

    /* Switch: '<S169>/Switch' incorporates:
     *  Constant: '<S169>/Constant'
     *  Constant: '<S169>/Constant1'
     *  Constant: '<S171>/Constant'
     *  Constant: '<S172>/Constant'
     *  Logic: '<S169>/Logical Operator'
     *  RelationalOperator: '<S171>/Compare'
     *  RelationalOperator: '<S172>/Compare'
     *  UnitDelay: '<S169>/Unit Delay'
     */
    if (rtb_POSEexponentialmatrixfori_0 < 0.0 &&
        Code_Gen_Model_DW.UnitDelay_DSTATE_h >= 0.0 && rtb_AND) {
      rtb_Switch2_d = 6.2831853071795862;
    } else {
      rtb_Switch2_d = 0.0;
    }

    /* Switch: '<S169>/Switch1' incorporates:
     *  Constant: '<S169>/Constant2'
     *  Constant: '<S169>/Constant3'
     *  Constant: '<S174>/Constant'
     *  Constant: '<S175>/Constant'
     *  Logic: '<S169>/Logical Operator1'
     *  RelationalOperator: '<S174>/Compare'
     *  RelationalOperator: '<S175>/Compare'
     *  UnitDelay: '<S169>/Unit Delay'
     */
    if (Code_Gen_Model_DW.UnitDelay_DSTATE_h < 0.0 &&
        rtb_POSEexponentialmatrixfori_0 >= 0.0 && rtb_AND) {
      rtb_Subtract_n = -6.2831853071795862;
    } else {
      rtb_Subtract_n = 0.0;
    }

    /* Sum: '<S169>/Sum1' incorporates:
     *  Switch: '<S169>/Switch'
     *  Switch: '<S169>/Switch1'
     *  UnitDelay: '<S169>/Unit Delay1'
     */
    rtb_Sum1_li = rtb_Switch2_d + rtb_Subtract_n +
      Code_Gen_Model_DW.UnitDelay1_DSTATE_kr;

    /* Merge: '<S1>/Merge' incorporates:
     *  Sum: '<S169>/Sum'
     */
    Code_Gen_Model_B.Gyro_Angle_Adjusted = rtb_thetay + rtb_Sum1_li;

    /* Merge: '<S1>/Merge2' incorporates:
     *  Constant: '<S166>/Constant'
     *  Inport: '<Root>/Steer_Joystick_Y'
     *  Lookup_n-D: '<S166>/Modulation_Str_X_Rel'
     *  Product: '<S166>/Product'
     */
    Code_Gen_Model_B.Steering_Rel_Cmd = look1_binlcpw
      (Code_Gen_Model_U.Steer_Joystick_Y,
       Code_Gen_Model_ConstP.Modulation_Str_X_Rel_bp01Data,
       Code_Gen_Model_ConstP.Modulation_Str_X_Rel_tableData, 20U) * 1.3;

    /* Switch: '<S178>/Switch1' incorporates:
     *  Constant: '<S178>/Constant'
     *  Constant: '<S178>/Constant1'
     *  Inport: '<Root>/Is_Boost_Trigger_Pulled'
     */
    if (Code_Gen_Model_U.Is_Boost_Trigger_Pulled != 0.0) {
      rtb_Modulation_Drv_X = 3.658;
    } else {
      rtb_Modulation_Drv_X = 1.5;
    }

    /* End of Switch: '<S178>/Switch1' */

    /* Switch: '<S183>/Init' incorporates:
     *  UnitDelay: '<S183>/FixPt Unit Delay1'
     *  UnitDelay: '<S183>/FixPt Unit Delay2'
     */
    if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a != 0) {
      rtb_uDLookupTable = rtb_Modulation_Drv_X;
    } else {
      rtb_uDLookupTable = Code_Gen_Model_DW.FixPtUnitDelay1_DSTATE_f;
    }

    /* End of Switch: '<S183>/Init' */

    /* Sum: '<S181>/Sum1' */
    rtb_Init = rtb_Modulation_Drv_X - rtb_uDLookupTable;

    /* Switch: '<S182>/Switch2' incorporates:
     *  Constant: '<S180>/Constant1'
     *  Constant: '<S180>/Constant3'
     *  RelationalOperator: '<S182>/LowerRelop1'
     *  RelationalOperator: '<S182>/UpperRelop'
     *  Switch: '<S182>/Switch'
     */
    if (rtb_Init > 0.04) {
      rtb_Init = 0.04;
    } else if (rtb_Init < -0.044444444444444446) {
      /* Switch: '<S182>/Switch' incorporates:
       *  Constant: '<S180>/Constant1'
       */
      rtb_Init = -0.044444444444444446;
    }

    /* Sum: '<S181>/Sum' incorporates:
     *  Switch: '<S182>/Switch2'
     */
    rtb_Init += rtb_uDLookupTable;

    /* Lookup_n-D: '<S167>/Modulation_Drv_X' incorporates:
     *  Inport: '<Root>/Drive_Joystick_X'
     */
    rtb_Modulation_Drv_X = look1_binlcpw(Code_Gen_Model_U.Drive_Joystick_X,
      Code_Gen_Model_ConstP.pooled9, Code_Gen_Model_ConstP.pooled8, 20U);

    /* Lookup_n-D: '<S167>/Modulation_Drv_Y' incorporates:
     *  Inport: '<Root>/Drive_Joystick_Y'
     */
    rtb_uDLookupTable = look1_binlcpw(Code_Gen_Model_U.Drive_Joystick_Y,
      Code_Gen_Model_ConstP.pooled9, Code_Gen_Model_ConstP.pooled8, 20U);

    /* Product: '<S178>/Product' incorporates:
     *  Math: '<S167>/Magnitude'
     */
    rtb_Add_cc = rt_hypotd_snf(rtb_Modulation_Drv_X, rtb_uDLookupTable) *
      rtb_Init;

    /* Saturate: '<S178>/Saturation' */
    if (rtb_Add_cc > 3.658) {
      /* Merge: '<S1>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = 3.658;
    } else if (rtb_Add_cc < -3.658) {
      /* Merge: '<S1>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = -3.658;
    } else {
      /* Merge: '<S1>/Merge4' */
      Code_Gen_Model_B.Translation_Speed = rtb_Add_cc;
    }

    /* End of Saturate: '<S178>/Saturation' */

    /* Switch: '<S179>/Switch1' incorporates:
     *  Constant: '<S184>/Constant'
     *  Constant: '<S185>/Constant'
     *  Logic: '<S179>/AND'
     *  RelationalOperator: '<S184>/Compare'
     *  RelationalOperator: '<S185>/Compare'
     *  Switch: '<S179>/Switch2'
     *  UnitDelay: '<S179>/Unit Delay'
     *  UnitDelay: '<S179>/Unit Delay1'
     */
    if (rtb_Modulation_Drv_X == 0.0 && rtb_uDLookupTable == 0.0) {
      rtb_uDLookupTable = Code_Gen_Model_DW.UnitDelay1_DSTATE_l;
      rtb_Modulation_Drv_X = Code_Gen_Model_DW.UnitDelay_DSTATE_p;
    }

    /* End of Switch: '<S179>/Switch1' */

    /* Merge: '<S1>/Merge3' incorporates:
     *  Trigonometry: '<S167>/Atan2'
     */
    Code_Gen_Model_B.Translation_Angle = rt_atan2d_snf(rtb_uDLookupTable,
      rtb_Modulation_Drv_X);

    /* Merge: '<S1>/Merge5' incorporates:
     *  Inport: '<Root>/Is_Absolute_Translation'
     *  SignalConversion generated from: '<S8>/Is_Absolute_Translation_In'
     */
    Code_Gen_Model_B.Is_Absolute_Translation =
      Code_Gen_Model_U.Is_Absolute_Translation;

    /* Merge: '<S1>/Merge6' incorporates:
     *  Inport: '<Root>/Is_Absolute_Steering'
     *  SignalConversion generated from: '<S8>/Is_Absolute_Steering_In'
     */
    Code_Gen_Model_B.Is_Absolute_Steering =
      Code_Gen_Model_U.Is_Absolute_Steering;

    /* Update for UnitDelay: '<S170>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_d2 = rtb_POSEexponentialmatrixfori_0;

    /* Update for UnitDelay: '<S170>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_g4 = rtb_Switch2;

    /* Update for UnitDelay: '<S169>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_h = rtb_POSEexponentialmatrixfori_0;

    /* Update for UnitDelay: '<S169>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_kr = rtb_Sum1_li;

    /* Update for UnitDelay: '<S183>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S183>/FixPt Constant'
     */
    Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_a = 0U;

    /* Update for UnitDelay: '<S183>/FixPt Unit Delay1' */
    Code_Gen_Model_DW.FixPtUnitDelay1_DSTATE_f = rtb_Init;

    /* Update for UnitDelay: '<S179>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_l = rtb_uDLookupTable;

    /* Update for UnitDelay: '<S179>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_p = rtb_Modulation_Drv_X;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S9>/Action Port'
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

  /* Signum: '<S113>/Sign2' incorporates:
   *  UnitDelay: '<S113>/Unit Delay'
   */
  if (rtIsNaN(Code_Gen_Model_B.Translation_Speed_o)) {
    rtb_Switch2_d = (rtNaN);
  } else if (Code_Gen_Model_B.Translation_Speed_o < 0.0) {
    rtb_Switch2_d = -1.0;
  } else {
    rtb_Switch2_d = Code_Gen_Model_B.Translation_Speed_o > 0.0;
  }

  /* Signum: '<S113>/Sign1' */
  if (rtIsNaN(Code_Gen_Model_B.Translation_Speed)) {
    rtb_Subtract_n = (rtNaN);
  } else if (Code_Gen_Model_B.Translation_Speed < 0.0) {
    rtb_Subtract_n = -1.0;
  } else {
    rtb_Subtract_n = Code_Gen_Model_B.Translation_Speed > 0.0;
  }

  /* Product: '<S113>/Product1' incorporates:
   *  Signum: '<S113>/Sign1'
   *  Signum: '<S113>/Sign2'
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

  /* Switch: '<S113>/Switch' incorporates:
   *  Constant: '<S113>/Constant'
   *  Constant: '<S118>/Constant'
   *  Constant: '<S119>/Constant'
   *  Logic: '<S113>/or'
   *  Product: '<S113>/Product1'
   *  RelationalOperator: '<S118>/Compare'
   *  RelationalOperator: '<S119>/Compare'
   *  UnitDelay: '<S113>/Unit Delay'
   */
  if (Code_Gen_Model_B.Translation_Speed_o == 0.0 || i > 0) {
    rtb_Switch2_d = Code_Gen_Model_B.Translation_Speed;
  } else {
    rtb_Switch2_d = 0.0;
  }

  /* End of Switch: '<S113>/Switch' */

  /* Switch: '<S124>/Init' incorporates:
   *  UnitDelay: '<S124>/FixPt Unit Delay1'
   *  UnitDelay: '<S124>/FixPt Unit Delay2'
   */
  if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Optimized_Module_Angle = rtb_Switch2_d;
  } else {
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.Translation_Speed_o;
  }

  /* End of Switch: '<S124>/Init' */

  /* RelationalOperator: '<S120>/Compare' incorporates:
   *  Constant: '<S120>/Constant'
   */
  rtb_AND = rtb_Switch2_d == 0.0;

  /* RelationalOperator: '<S121>/Compare' incorporates:
   *  Constant: '<S121>/Constant'
   */
  rtb_Compare_dh = rtb_Switch2_d > 0.0;

  /* Abs: '<S113>/Abs' incorporates:
   *  Sum: '<S113>/Subtract'
   *  UnitDelay: '<S113>/Unit Delay'
   */
  rtb_POSEexponentialmatrixfori_0 = fabs(Code_Gen_Model_B.Translation_Speed_o -
    Code_Gen_Model_B.Translation_Speed);

  /* Switch: '<S113>/Switch1' incorporates:
   *  Switch: '<S113>/Switch3'
   *  Switch: '<S113>/Switch5'
   */
  if (rtb_AND) {
    rtb_uDLookupTable = Code_Gen_Model_ConstB.UnaryMinus;

    /* SignalConversion generated from: '<S113>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S113>/Constant4'
     *  Constant: '<S113>/Constant6'
     */
    rtb_Product7[0] = 0.01;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S113>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S113>/Constant2'
     *  Constant: '<S113>/Constant5'
     */
    rtb_TmpSignalConversionAtLook_o[0] = 0.0;
    rtb_TmpSignalConversionAtLook_o[1] = 0.2;

    /* S-Function (sfix_look1_dyn): '<S113>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S113>/Lookup Table Dynamic'
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
    if (rtb_Compare_dh) {
      /* Switch: '<S113>/Switch3' incorporates:
       *  Constant: '<S113>/Constant3'
       */
      rtb_uDLookupTable = 0.085714285714285715;
    } else {
      rtb_uDLookupTable = Code_Gen_Model_ConstB.UnaryMinus;
    }

    /* SignalConversion generated from: '<S113>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S113>/Constant10'
     *  Constant: '<S113>/Constant8'
     *  Switch: '<S113>/Switch3'
     */
    rtb_Product7[0] = 0.05;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S113>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S113>/Constant7'
     *  Constant: '<S113>/Constant9'
     */
    rtb_TmpSignalConversionAtLook_o[0] = 0.0;
    rtb_TmpSignalConversionAtLook_o[1] = 0.15;

    /* S-Function (sfix_look1_dyn): '<S113>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S113>/Lookup Table Dynamic1'
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

  /* End of Switch: '<S113>/Switch1' */

  /* Product: '<S113>/Product' */
  rtb_uDLookupTable *= rtb_POSEexponentialmatrixfori_0;

  /* Sum: '<S122>/Sum1' */
  rtb_Switch2 = rtb_Switch2_d - rtb_Optimized_Module_Angle;

  /* Switch: '<S123>/Switch2' incorporates:
   *  RelationalOperator: '<S123>/LowerRelop1'
   */
  if (!(rtb_Switch2 > rtb_uDLookupTable)) {
    /* Switch: '<S113>/Switch2' incorporates:
     *  Constant: '<S113>/Constant1'
     *  Switch: '<S113>/Switch4'
     */
    if (rtb_AND) {
      rtb_Switch2_d = -0.2;
    } else if (rtb_Compare_dh) {
      /* Switch: '<S113>/Switch4' incorporates:
       *  Constant: '<S113>/Constant1'
       */
      rtb_Switch2_d = -0.2;
    } else {
      rtb_Switch2_d = Code_Gen_Model_ConstB.UnaryMinus1;
    }

    /* Product: '<S113>/Product2' incorporates:
     *  Switch: '<S113>/Switch2'
     */
    rtb_Sum1_li = rtb_Switch2_d * rtb_POSEexponentialmatrixfori_0;

    /* Switch: '<S123>/Switch' incorporates:
     *  RelationalOperator: '<S123>/UpperRelop'
     */
    if (rtb_Switch2 < rtb_Sum1_li) {
      rtb_uDLookupTable = rtb_Sum1_li;
    } else {
      rtb_uDLookupTable = rtb_Switch2;
    }

    /* End of Switch: '<S123>/Switch' */
  }

  /* End of Switch: '<S123>/Switch2' */

  /* Sum: '<S122>/Sum' */
  Code_Gen_Model_B.Translation_Speed_o = rtb_uDLookupTable +
    rtb_Optimized_Module_Angle;

  /* Switch: '<S116>/Switch' */
  if (Code_Gen_Model_B.Is_Absolute_Translation) {
    /* Switch: '<S116>/Switch' incorporates:
     *  Constant: '<S140>/Constant3'
     *  Constant: '<S140>/Constant4'
     *  Math: '<S140>/Math Function'
     *  Sum: '<S116>/Subtract'
     *  Sum: '<S140>/Add1'
     *  Sum: '<S140>/Add2'
     */
    Code_Gen_Model_B.Translation_Steering_Cmd = rt_modd_snf
      (Code_Gen_Model_B.Translation_Angle - rtb_thetay + 3.1415926535897931,
       6.2831853071795862) - 3.1415926535897931;
  } else {
    /* Switch: '<S116>/Switch' */
    Code_Gen_Model_B.Translation_Steering_Cmd =
      Code_Gen_Model_B.Translation_Angle;
  }

  /* End of Switch: '<S116>/Switch' */

  /* Sum: '<S136>/Add1' incorporates:
   *  Constant: '<S136>/Constant3'
   *  Constant: '<S136>/Constant4'
   *  Math: '<S136>/Math Function'
   *  Sum: '<S135>/Sum'
   *  Sum: '<S136>/Add2'
   */
  rtb_Optimized_Module_Angle = rt_modd_snf(Code_Gen_Model_B.Steering_Abs_Cmd -
    Code_Gen_Model_B.Gyro_Angle_Adjusted + 3.1415926535897931,
    6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S138>/Sum1' incorporates:
   *  Constant: '<S135>/Constant2'
   *  Product: '<S138>/Product'
   *  Sum: '<S138>/Sum'
   *  UnitDelay: '<S138>/Unit Delay1'
   */
  rtb_POSEexponentialmatrixfori_0 = (rtb_Optimized_Module_Angle -
    Code_Gen_Model_DW.UnitDelay1_DSTATE) * 0.22223232082821098 +
    Code_Gen_Model_DW.UnitDelay1_DSTATE;

  /* Product: '<S135>/Product' incorporates:
   *  Constant: '<S135>/Constant3'
   */
  rtb_Switch2 = rtb_POSEexponentialmatrixfori_0 * 0.0;

  /* Sum: '<S137>/Diff' incorporates:
   *  UnitDelay: '<S137>/UD'
   *
   * Block description for '<S137>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S137>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_cc = rtb_Switch2 - Code_Gen_Model_DW.UD_DSTATE_a;

  /* Saturate: '<S135>/Saturation' */
  if (rtb_Add_cc > 0.0) {
    rtb_Add_cc = 0.0;
  } else if (rtb_Add_cc < -0.0) {
    rtb_Add_cc = -0.0;
  }

  /* Sum: '<S135>/Add' incorporates:
   *  Gain: '<S135>/Gain1'
   *  Saturate: '<S135>/Saturation'
   */
  rtb_Init = 1.5 * rtb_Optimized_Module_Angle + rtb_Add_cc;

  /* Sum: '<S135>/Subtract' incorporates:
   *  Constant: '<S135>/Constant'
   */
  rtb_uDLookupTable = 1.3 - rtb_Init;

  /* Sum: '<S135>/Sum2' incorporates:
   *  Gain: '<S135>/Gain2'
   *  UnitDelay: '<S135>/Unit Delay'
   */
  rtb_Sum1_li = 0.0 * rtb_Optimized_Module_Angle +
    Code_Gen_Model_DW.UnitDelay_DSTATE_m;

  /* Switch: '<S139>/Switch2' incorporates:
   *  RelationalOperator: '<S139>/LowerRelop1'
   */
  if (!(rtb_Sum1_li > rtb_uDLookupTable)) {
    /* Sum: '<S135>/Subtract1' incorporates:
     *  Constant: '<S135>/Constant1'
     */
    rtb_uDLookupTable = -1.3 - rtb_Init;

    /* Switch: '<S139>/Switch' incorporates:
     *  RelationalOperator: '<S139>/UpperRelop'
     */
    if (!(rtb_Sum1_li < rtb_uDLookupTable)) {
      rtb_uDLookupTable = rtb_Sum1_li;
    }

    /* End of Switch: '<S139>/Switch' */
  }

  /* End of Switch: '<S139>/Switch2' */

  /* Saturate: '<S135>/Saturation1' */
  if (rtb_uDLookupTable > 0.1) {
    rtb_Sum1_li = 0.1;
  } else if (rtb_uDLookupTable < -0.1) {
    rtb_Sum1_li = -0.1;
  } else {
    rtb_Sum1_li = rtb_uDLookupTable;
  }

  /* End of Saturate: '<S135>/Saturation1' */

  /* Sum: '<S135>/Add1' */
  rtb_Add_cc = rtb_Init + rtb_Sum1_li;

  /* Saturate: '<S135>/Saturation2' */
  if (rtb_Add_cc > 1.3) {
    /* Saturate: '<S135>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = 1.3;
  } else if (rtb_Add_cc < -1.3) {
    /* Saturate: '<S135>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = -1.3;
  } else {
    /* Saturate: '<S135>/Saturation2' */
    Code_Gen_Model_B.Steering_Localized_PID = rtb_Add_cc;
  }

  /* End of Saturate: '<S135>/Saturation2' */

  /* Switch: '<S115>/Switch' incorporates:
   *  Switch: '<S126>/Switch'
   */
  if (Code_Gen_Model_B.Is_Absolute_Steering) {
    /* Switch: '<S126>/Switch' incorporates:
     *  Abs: '<S126>/Abs'
     *  Constant: '<S126>/Constant'
     *  Constant: '<S134>/Constant'
     *  RelationalOperator: '<S134>/Compare'
     */
    if (fabs(Code_Gen_Model_B.Steering_Localized_PID) > 0.1) {
      rtb_Optimized_Module_Angle = Code_Gen_Model_B.Steering_Localized_PID;
    } else {
      rtb_Optimized_Module_Angle = 0.0;
    }
  } else {
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.Steering_Rel_Cmd;
  }

  /* End of Switch: '<S115>/Switch' */

  /* UnitDelay: '<S125>/Unit Delay' */
  rtb_uDLookupTable = Code_Gen_Model_B.Steering_Localized_Cmd;

  /* Signum: '<S125>/Sign2' */
  if (rtIsNaN(rtb_uDLookupTable)) {
    rtb_Switch2_d = (rtNaN);
  } else if (rtb_uDLookupTable < 0.0) {
    rtb_Switch2_d = -1.0;
  } else {
    rtb_Switch2_d = rtb_uDLookupTable > 0.0;
  }

  /* Signum: '<S125>/Sign1' */
  if (rtIsNaN(rtb_Optimized_Module_Angle)) {
    rtb_Subtract_n = (rtNaN);
  } else if (rtb_Optimized_Module_Angle < 0.0) {
    rtb_Subtract_n = -1.0;
  } else {
    rtb_Subtract_n = rtb_Optimized_Module_Angle > 0.0;
  }

  /* Product: '<S125>/Product1' incorporates:
   *  Signum: '<S125>/Sign1'
   *  Signum: '<S125>/Sign2'
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

  /* Switch: '<S125>/Switch' incorporates:
   *  Constant: '<S125>/Constant'
   *  Constant: '<S127>/Constant'
   *  Constant: '<S128>/Constant'
   *  Logic: '<S125>/or'
   *  Product: '<S125>/Product1'
   *  RelationalOperator: '<S127>/Compare'
   *  RelationalOperator: '<S128>/Compare'
   */
  if (rtb_uDLookupTable == 0.0 || i > 0) {
    rtb_Switch_kj = rtb_Optimized_Module_Angle;
  } else {
    rtb_Switch_kj = 0.0;
  }

  /* End of Switch: '<S125>/Switch' */

  /* Switch: '<S133>/Init' incorporates:
   *  UnitDelay: '<S133>/FixPt Unit Delay1'
   *  UnitDelay: '<S133>/FixPt Unit Delay2'
   */
  if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c != 0) {
    rtb_Init = rtb_Switch_kj;
  } else {
    rtb_Init = Code_Gen_Model_B.Steering_Localized_Cmd;
  }

  /* End of Switch: '<S133>/Init' */

  /* RelationalOperator: '<S129>/Compare' incorporates:
   *  Constant: '<S129>/Constant'
   */
  rtb_AND = rtb_Switch_kj == 0.0;

  /* RelationalOperator: '<S130>/Compare' incorporates:
   *  Constant: '<S130>/Constant'
   */
  rtb_Compare_dh = rtb_Switch_kj > 0.0;

  /* Abs: '<S125>/Abs' incorporates:
   *  Sum: '<S125>/Subtract'
   */
  rtb_uDLookupTable = fabs(rtb_uDLookupTable - rtb_Optimized_Module_Angle);

  /* Switch: '<S125>/Switch5' incorporates:
   *  Switch: '<S125>/Switch1'
   */
  if (rtb_AND) {
    /* SignalConversion generated from: '<S125>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S125>/Constant4'
     *  Constant: '<S125>/Constant6'
     */
    rtb_Product7[0] = 0.01;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S125>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S125>/Constant2'
     *  Constant: '<S125>/Constant5'
     */
    rtb_TmpSignalConversionAtLook_o[0] = 0.0;
    rtb_TmpSignalConversionAtLook_o[1] = 0.2;

    /* S-Function (sfix_look1_dyn): '<S125>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S125>/Lookup Table Dynamic'
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
    rtb_Switch2_d = Code_Gen_Model_ConstB.UnaryMinus_p;
  } else {
    /* SignalConversion generated from: '<S125>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S125>/Constant10'
     *  Constant: '<S125>/Constant8'
     */
    rtb_Product7[0] = 0.1;
    rtb_Product7[1] = 1.0;

    /* SignalConversion generated from: '<S125>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S125>/Constant7'
     *  Constant: '<S125>/Constant9'
     */
    rtb_TmpSignalConversionAtLook_o[0] = 0.0;
    rtb_TmpSignalConversionAtLook_o[1] = 0.2;

    /* S-Function (sfix_look1_dyn): '<S125>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S125>/Lookup Table Dynamic1'
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

    /* Switch: '<S125>/Switch3' incorporates:
     *  Constant: '<S125>/Constant3'
     */
    if (rtb_Compare_dh) {
      rtb_Switch2_d = 1.0;
    } else {
      rtb_Switch2_d = Code_Gen_Model_ConstB.UnaryMinus_p;
    }

    /* End of Switch: '<S125>/Switch3' */
  }

  /* End of Switch: '<S125>/Switch5' */

  /* Product: '<S125>/Product' incorporates:
   *  Switch: '<S125>/Switch1'
   */
  rtb_Modulation_Drv_X = rtb_Switch2_d * rtb_uDLookupTable;

  /* Sum: '<S131>/Sum1' */
  rtb_Switch_kj -= rtb_Init;

  /* Switch: '<S132>/Switch2' incorporates:
   *  RelationalOperator: '<S132>/LowerRelop1'
   */
  if (!(rtb_Switch_kj > rtb_Modulation_Drv_X)) {
    /* Switch: '<S125>/Switch2' incorporates:
     *  Constant: '<S125>/Constant1'
     *  Switch: '<S125>/Switch4'
     */
    if (rtb_AND) {
      rtb_Switch2_d = -1.0;
    } else if (rtb_Compare_dh) {
      /* Switch: '<S125>/Switch4' incorporates:
       *  Constant: '<S125>/Constant1'
       */
      rtb_Switch2_d = -1.0;
    } else {
      rtb_Switch2_d = Code_Gen_Model_ConstB.UnaryMinus1_c;
    }

    /* Product: '<S125>/Product2' incorporates:
     *  Switch: '<S125>/Switch2'
     */
    rtb_Modulation_Drv_X = rtb_Switch2_d * rtb_uDLookupTable;

    /* Switch: '<S132>/Switch' incorporates:
     *  RelationalOperator: '<S132>/UpperRelop'
     */
    if (!(rtb_Switch_kj < rtb_Modulation_Drv_X)) {
      rtb_Modulation_Drv_X = rtb_Switch_kj;
    }

    /* End of Switch: '<S132>/Switch' */
  }

  /* End of Switch: '<S132>/Switch2' */

  /* Sum: '<S131>/Sum' */
  Code_Gen_Model_B.Steering_Localized_Cmd = rtb_Modulation_Drv_X + rtb_Init;

  /* Fcn: '<S147>/r->x' incorporates:
   *  Fcn: '<S152>/r->x'
   *  Fcn: '<S157>/r->x'
   *  Fcn: '<S162>/r->x'
   */
  rtb_Switch2_d = Code_Gen_Model_B.Translation_Speed_o * cos
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S141>/Add' incorporates:
   *  Fcn: '<S147>/r->x'
   *  Fcn: '<S148>/r->x'
   */
  rtb_Product7[0] = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.FL_Tangent_Angle) + rtb_Switch2_d;

  /* Fcn: '<S147>/theta->y' incorporates:
   *  Fcn: '<S152>/theta->y'
   *  Fcn: '<S157>/theta->y'
   *  Fcn: '<S162>/theta->y'
   */
  rtb_Total_Limited = Code_Gen_Model_B.Translation_Speed_o * sin
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S141>/Add' incorporates:
   *  Fcn: '<S147>/theta->y'
   *  Fcn: '<S148>/theta->y'
   */
  rtb_Product7[1] = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.FL_Tangent_Angle) + rtb_Total_Limited;

  /* Sum: '<S142>/Add' incorporates:
   *  Fcn: '<S153>/r->x'
   *  Fcn: '<S153>/theta->y'
   */
  rtb_TmpSignalConversionAtLook_o[0] = Code_Gen_Model_B.Steering_Localized_Cmd *
    cos(Code_Gen_Model_ConstB.FR_Tangent_Angle) + rtb_Switch2_d;
  rtb_TmpSignalConversionAtLook_o[1] = Code_Gen_Model_B.Steering_Localized_Cmd *
    sin(Code_Gen_Model_ConstB.FR_Tangent_Angle) + rtb_Total_Limited;

  /* Sum: '<S143>/Add' incorporates:
   *  Fcn: '<S158>/r->x'
   *  Fcn: '<S158>/theta->y'
   */
  rtb_Add_f_idx_0 = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.BL_Tangent_Angle) + rtb_Switch2_d;
  rtb_Add_f_idx_1 = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.BL_Tangent_Angle) + rtb_Total_Limited;

  /* Sum: '<S144>/Add' incorporates:
   *  Fcn: '<S163>/r->x'
   *  Fcn: '<S163>/theta->y'
   */
  rtb_Switch2_d += Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.BR_Tangent_Angle);
  rtb_Init = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.BR_Tangent_Angle) + rtb_Total_Limited;

  /* Fcn: '<S161>/x->r' */
  rtb_Total_Limited = rt_hypotd_snf(rtb_Switch2_d, rtb_Init);

  /* Switch: '<S160>/Switch1' incorporates:
   *  Constant: '<S164>/Constant'
   *  RelationalOperator: '<S164>/Compare'
   *  Switch: '<S160>/Switch'
   */
  if (rtb_Total_Limited == 0.0) {
    /* Switch: '<S160>/Switch1' incorporates:
     *  Constant: '<S160>/Constant'
     */
    Code_Gen_Model_B.BR_Desired_Wheel_Speed = 1.0E-15;
  } else {
    /* Switch: '<S160>/Switch1' */
    Code_Gen_Model_B.BR_Desired_Wheel_Speed = rtb_Total_Limited;

    /* Switch: '<S160>/Switch' incorporates:
     *  Fcn: '<S161>/x->theta'
     */
    Code_Gen_Model_B.BR_Desired_Module_Angle = rt_atan2d_snf(rtb_Init,
      rtb_Switch2_d);
  }

  /* End of Switch: '<S160>/Switch1' */

  /* Trigonometry: '<S105>/Cos4' incorporates:
   *  Switch: '<S94>/Angle_Switch'
   *  Trigonometry: '<S104>/Cos4'
   */
  rtb_Subtract_n = cos(Code_Gen_Model_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S105>/Sin5' incorporates:
   *  UnaryMinus: '<S103>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Code_Gen_Model_B.BR_Steer_Module_Angle);

  /* Trigonometry: '<S105>/Sin4' incorporates:
   *  Switch: '<S94>/Angle_Switch'
   *  Trigonometry: '<S104>/Sin4'
   */
  rtb_Product_nw = sin(Code_Gen_Model_B.BR_Desired_Module_Angle);

  /* Trigonometry: '<S105>/Cos5' incorporates:
   *  UnaryMinus: '<S103>/Unary Minus'
   */
  rtb_Switch2_d = cos(-Code_Gen_Model_B.BR_Steer_Module_Angle);

  /* Sum: '<S105>/Subtract1' incorporates:
   *  Product: '<S105>/Product2'
   *  Product: '<S105>/Product3'
   *  Trigonometry: '<S105>/Cos4'
   *  Trigonometry: '<S105>/Sin4'
   */
  rtb_uDLookupTable = rtb_Subtract_n * rtb_Optimized_Module_Angle +
    rtb_Product_nw * rtb_Switch2_d;

  /* Sum: '<S105>/Subtract' incorporates:
   *  Product: '<S105>/Product'
   *  Product: '<S105>/Product1'
   *  Trigonometry: '<S105>/Cos4'
   *  Trigonometry: '<S105>/Sin4'
   */
  rtb_Init = rtb_Subtract_n * rtb_Switch2_d - rtb_Product_nw *
    rtb_Optimized_Module_Angle;

  /* Math: '<S105>/Hypot' */
  rtb_Modulation_Drv_X = rt_hypotd_snf(rtb_Init, rtb_uDLookupTable);

  /* Switch: '<S105>/Switch' incorporates:
   *  Constant: '<S105>/Constant'
   *  Constant: '<S105>/Constant1'
   *  Constant: '<S106>/Constant'
   *  Product: '<S105>/Divide'
   *  Product: '<S105>/Divide1'
   *  RelationalOperator: '<S106>/Compare'
   *  Switch: '<S105>/Switch1'
   */
  if (rtb_Modulation_Drv_X > 1.0E-6) {
    rtb_Total_Limited = rtb_uDLookupTable / rtb_Modulation_Drv_X;
    rtb_Switch2_d = rtb_Init / rtb_Modulation_Drv_X;
  } else {
    rtb_Total_Limited = 0.0;
    rtb_Switch2_d = 1.0;
  }

  /* End of Switch: '<S105>/Switch' */

  /* Switch: '<S94>/Speed_Switch' incorporates:
   *  Abs: '<S94>/Abs'
   *  Constant: '<S102>/Constant'
   *  RelationalOperator: '<S102>/Compare'
   *  Switch: '<S94>/Angle_Switch'
   *  Trigonometry: '<S104>/Atan1'
   *  Trigonometry: '<S105>/Atan1'
   *  UnaryMinus: '<S94>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Total_Limited, rtb_Switch2_d)) > 1.5707963267948966)
  {
    rtb_Switch2_d = -Code_Gen_Model_B.BR_Desired_Wheel_Speed;

    /* Sum: '<S104>/Subtract1' incorporates:
     *  Product: '<S104>/Product2'
     *  Product: '<S104>/Product3'
     *  UnaryMinus: '<S94>/Unary Minus'
     */
    rtb_uDLookupTable = rtb_Subtract_n * Code_Gen_Model_ConstB.Sin5_c +
      rtb_Product_nw * Code_Gen_Model_ConstB.Cos5_b;

    /* Sum: '<S104>/Subtract' incorporates:
     *  Product: '<S104>/Product'
     *  Product: '<S104>/Product1'
     */
    rtb_Modulation_Drv_X = rtb_Subtract_n * Code_Gen_Model_ConstB.Cos5_b -
      rtb_Product_nw * Code_Gen_Model_ConstB.Sin5_c;

    /* Math: '<S104>/Hypot' */
    rtb_Init = rt_hypotd_snf(rtb_Modulation_Drv_X, rtb_uDLookupTable);

    /* Switch: '<S104>/Switch1' incorporates:
     *  Constant: '<S104>/Constant'
     *  Constant: '<S104>/Constant1'
     *  Constant: '<S107>/Constant'
     *  Product: '<S104>/Divide'
     *  Product: '<S104>/Divide1'
     *  RelationalOperator: '<S107>/Compare'
     *  Switch: '<S104>/Switch'
     */
    if (rtb_Init > 1.0E-6) {
      rtb_Modulation_Drv_X /= rtb_Init;
      rtb_uDLookupTable /= rtb_Init;
    } else {
      rtb_Modulation_Drv_X = 1.0;
      rtb_uDLookupTable = 0.0;
    }

    /* End of Switch: '<S104>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_uDLookupTable,
      rtb_Modulation_Drv_X);
  } else {
    rtb_Switch2_d = Code_Gen_Model_B.BR_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.BR_Desired_Module_Angle;
  }

  /* Product: '<S97>/Product2' incorporates:
   *  Constant: '<S97>/Constant'
   *  Switch: '<S94>/Speed_Switch'
   */
  rtb_Total_Limited = rtb_Switch2_d * 1530.1401357649195;

  /* Signum: '<S92>/Sign' */
  if (rtIsNaN(rtb_Total_Limited)) {
    rtb_Switch2_d = (rtNaN);
  } else if (rtb_Total_Limited < 0.0) {
    rtb_Switch2_d = -1.0;
  } else {
    rtb_Switch2_d = rtb_Total_Limited > 0.0;
  }

  /* Signum: '<S92>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.BackRight_Drive_Motor_Speed)) {
    rtb_Subtract_n = (rtNaN);
  } else if (Code_Gen_Model_U.BackRight_Drive_Motor_Speed < 0.0) {
    rtb_Subtract_n = -1.0;
  } else {
    rtb_Subtract_n = Code_Gen_Model_U.BackRight_Drive_Motor_Speed > 0.0;
  }

  /* Sum: '<S95>/Add' incorporates:
   *  Sum: '<S96>/Sum'
   */
  rtb_Optimized_Module_Angle -= Code_Gen_Model_B.BR_Steer_Module_Angle;

  /* Product: '<S27>/Product' incorporates:
   *  Abs: '<S92>/Abs'
   *  Abs: '<S95>/Abs'
   *  Constant: '<S108>/Constant3'
   *  Constant: '<S108>/Constant4'
   *  Constant: '<S98>/Constant'
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   *  Logic: '<S92>/OR'
   *  Lookup_n-D: '<S95>/1-D Lookup Table'
   *  Math: '<S108>/Math Function'
   *  RelationalOperator: '<S92>/Equal1'
   *  RelationalOperator: '<S98>/Compare'
   *  Signum: '<S92>/Sign'
   *  Signum: '<S92>/Sign1'
   *  Sum: '<S108>/Add1'
   *  Sum: '<S108>/Add2'
   *  Sum: '<S95>/Add'
   */
  rtb_Total_Limited = (real_T)(rtb_Switch2_d == rtb_Subtract_n || fabs
    (Code_Gen_Model_U.BackRight_Drive_Motor_Speed) <= 1500.0) *
    rtb_Total_Limited * look1_binlcpw(fabs(rt_modd_snf
    (rtb_Optimized_Module_Angle + 1.5707963267948966, 3.1415926535897931) -
    1.5707963267948966), Code_Gen_Model_ConstP.pooled24,
    Code_Gen_Model_ConstP.pooled23, 1U);

  /* Gain: '<S93>/Gain' */
  rtb_Modulation_Drv_X = 0.00018181818181818181 * rtb_Total_Limited;

  /* Sum: '<S93>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Motor_Speed'
   */
  rtb_Total_Limited -= Code_Gen_Model_U.BackRight_Drive_Motor_Speed;

  /* Sum: '<S100>/Sum1' incorporates:
   *  Constant: '<S93>/Constant2'
   *  Product: '<S100>/Product'
   *  Sum: '<S100>/Sum'
   *  UnitDelay: '<S100>/Unit Delay1'
   */
  rtb_uDLookupTable = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_k)
    * 0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_k;

  /* Product: '<S93>/Product' incorporates:
   *  Constant: '<S93>/Constant3'
   */
  rtb_Init = rtb_uDLookupTable * 9.9999999999999991E-5;

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
  rtb_Add_cc = rtb_Init - Code_Gen_Model_DW.UD_DSTATE_cs;

  /* Saturate: '<S93>/Saturation' */
  if (rtb_Add_cc > 0.2) {
    rtb_Add_cc = 0.2;
  } else if (rtb_Add_cc < -0.2) {
    rtb_Add_cc = -0.2;
  }

  /* Sum: '<S93>/Add' incorporates:
   *  Gain: '<S93>/Gain1'
   *  Saturate: '<S93>/Saturation'
   */
  rtb_Switch_kj = 5.0E-6 * rtb_Total_Limited + rtb_Modulation_Drv_X + rtb_Add_cc;

  /* Sum: '<S93>/Subtract' incorporates:
   *  Constant: '<S93>/Constant'
   */
  rtb_Switch2_d = 1.0 - rtb_Switch_kj;

  /* Sum: '<S93>/Sum2' incorporates:
   *  Gain: '<S93>/Gain2'
   *  UnitDelay: '<S93>/Unit Delay'
   */
  rtb_Modulation_Drv_X = 0.0 * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_a;

  /* Switch: '<S101>/Switch2' incorporates:
   *  Constant: '<S93>/Constant'
   *  RelationalOperator: '<S101>/LowerRelop1'
   *  Sum: '<S93>/Subtract'
   */
  if (!(rtb_Modulation_Drv_X > 1.0 - rtb_Switch_kj)) {
    /* Switch: '<S101>/Switch' incorporates:
     *  Constant: '<S93>/Constant1'
     *  RelationalOperator: '<S101>/UpperRelop'
     *  Sum: '<S93>/Subtract1'
     */
    if (rtb_Modulation_Drv_X < -1.0 - rtb_Switch_kj) {
      rtb_Switch2_d = -1.0 - rtb_Switch_kj;
    } else {
      rtb_Switch2_d = rtb_Modulation_Drv_X;
    }

    /* End of Switch: '<S101>/Switch' */
  }

  /* End of Switch: '<S101>/Switch2' */

  /* Saturate: '<S93>/Saturation1' */
  if (rtb_Switch2_d > 0.0) {
    rtb_Modulation_Drv_X = 0.0;
  } else if (rtb_Switch2_d < -0.0) {
    rtb_Modulation_Drv_X = -0.0;
  } else {
    rtb_Modulation_Drv_X = rtb_Switch2_d;
  }

  /* End of Saturate: '<S93>/Saturation1' */

  /* Sum: '<S93>/Add1' */
  rtb_Add_cc = rtb_Switch_kj + rtb_Modulation_Drv_X;

  /* Saturate: '<S93>/Saturation2' */
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

  /* End of Saturate: '<S93>/Saturation2' */

  /* Sum: '<S109>/Add1' incorporates:
   *  Constant: '<S109>/Constant3'
   *  Constant: '<S109>/Constant4'
   *  Math: '<S109>/Math Function'
   *  Sum: '<S109>/Add2'
   */
  rtb_Total_Limited = rt_modd_snf(rtb_Optimized_Module_Angle +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S111>/Sum1' incorporates:
   *  Constant: '<S96>/Constant2'
   *  Product: '<S111>/Product'
   *  Sum: '<S111>/Sum'
   *  UnitDelay: '<S111>/Unit Delay1'
   */
  rtb_Switch_kj = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_i) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_i;

  /* Product: '<S96>/Product' incorporates:
   *  Constant: '<S96>/Constant3'
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
  rtb_Add_cc = rtb_Subtract1_lg - Code_Gen_Model_DW.UD_DSTATE_l;

  /* Saturate: '<S96>/Saturation' */
  if (rtb_Add_cc > 0.2) {
    rtb_Add_cc = 0.2;
  } else if (rtb_Add_cc < -0.2) {
    rtb_Add_cc = -0.2;
  }

  /* Sum: '<S96>/Add' incorporates:
   *  Gain: '<S96>/Gain1'
   *  Saturate: '<S96>/Saturation'
   */
  rtb_Add_p = 0.15 * rtb_Total_Limited + rtb_Add_cc;

  /* Sum: '<S96>/Subtract' incorporates:
   *  Constant: '<S96>/Constant'
   */
  rtb_Switch2_d = 1.0 - rtb_Add_p;

  /* Sum: '<S96>/Sum2' incorporates:
   *  Gain: '<S96>/Gain2'
   *  UnitDelay: '<S96>/Unit Delay'
   */
  rtb_Sum2_fc = 0.005 * rtb_Total_Limited + Code_Gen_Model_DW.UnitDelay_DSTATE_l;

  /* Switch: '<S112>/Switch2' incorporates:
   *  Constant: '<S96>/Constant'
   *  RelationalOperator: '<S112>/LowerRelop1'
   *  Sum: '<S96>/Subtract'
   */
  if (!(rtb_Sum2_fc > 1.0 - rtb_Add_p)) {
    /* Switch: '<S112>/Switch' incorporates:
     *  Constant: '<S96>/Constant1'
     *  RelationalOperator: '<S112>/UpperRelop'
     *  Sum: '<S96>/Subtract1'
     */
    if (rtb_Sum2_fc < -1.0 - rtb_Add_p) {
      rtb_Switch2_d = -1.0 - rtb_Add_p;
    } else {
      rtb_Switch2_d = rtb_Sum2_fc;
    }

    /* End of Switch: '<S112>/Switch' */
  }

  /* End of Switch: '<S112>/Switch2' */

  /* Saturate: '<S96>/Saturation1' */
  if (rtb_Switch2_d > 0.005) {
    rtb_Sum2_fc = 0.005;
  } else if (rtb_Switch2_d < -0.005) {
    rtb_Sum2_fc = -0.005;
  } else {
    rtb_Sum2_fc = rtb_Switch2_d;
  }

  /* End of Saturate: '<S96>/Saturation1' */

  /* Outport: '<Root>/BackRight_Steer_DutyCycle' incorporates:
   *  Saturate: '<S96>/Saturation2'
   *  Sum: '<S96>/Add1'
   */
  Code_Gen_Model_Y.BackRight_Steer_DutyCycle = rtb_Add_p + rtb_Sum2_fc;

  /* Fcn: '<S156>/x->r' */
  rtb_Total_Limited = rt_hypotd_snf(rtb_Add_f_idx_0, rtb_Add_f_idx_1);

  /* Switch: '<S155>/Switch1' incorporates:
   *  Constant: '<S159>/Constant'
   *  RelationalOperator: '<S159>/Compare'
   *  Switch: '<S155>/Switch'
   */
  if (rtb_Total_Limited == 0.0) {
    /* Switch: '<S155>/Switch1' incorporates:
     *  Constant: '<S155>/Constant'
     */
    Code_Gen_Model_B.BL_Desired_Wheel_Speed = 1.0E-15;
  } else {
    /* Switch: '<S155>/Switch1' */
    Code_Gen_Model_B.BL_Desired_Wheel_Speed = rtb_Total_Limited;

    /* Switch: '<S155>/Switch' incorporates:
     *  Fcn: '<S156>/x->theta'
     */
    Code_Gen_Model_B.BL_Desired_Module_Angle = rt_atan2d_snf(rtb_Add_f_idx_1,
      rtb_Add_f_idx_0);
  }

  /* End of Switch: '<S155>/Switch1' */

  /* Trigonometry: '<S84>/Cos4' incorporates:
   *  Switch: '<S73>/Angle_Switch'
   *  Trigonometry: '<S83>/Cos4'
   */
  rtb_Subtract_n = cos(Code_Gen_Model_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S84>/Sin5' incorporates:
   *  UnaryMinus: '<S82>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Code_Gen_Model_B.BL_Steer_Module_Angle);

  /* Trigonometry: '<S84>/Sin4' incorporates:
   *  Switch: '<S73>/Angle_Switch'
   *  Trigonometry: '<S83>/Sin4'
   */
  rtb_Product_nw = sin(Code_Gen_Model_B.BL_Desired_Module_Angle);

  /* Trigonometry: '<S84>/Cos5' incorporates:
   *  UnaryMinus: '<S82>/Unary Minus'
   */
  rtb_Switch2_d = cos(-Code_Gen_Model_B.BL_Steer_Module_Angle);

  /* Sum: '<S84>/Subtract1' incorporates:
   *  Product: '<S84>/Product2'
   *  Product: '<S84>/Product3'
   *  Trigonometry: '<S84>/Cos4'
   *  Trigonometry: '<S84>/Sin4'
   */
  rtb_Total_Limited = rtb_Subtract_n * rtb_Optimized_Module_Angle +
    rtb_Product_nw * rtb_Switch2_d;

  /* Sum: '<S84>/Subtract' incorporates:
   *  Product: '<S84>/Product'
   *  Product: '<S84>/Product1'
   *  Trigonometry: '<S84>/Cos4'
   *  Trigonometry: '<S84>/Sin4'
   */
  rtb_Add_p = rtb_Subtract_n * rtb_Switch2_d - rtb_Product_nw *
    rtb_Optimized_Module_Angle;

  /* Math: '<S84>/Hypot' */
  rtb_Add_f_idx_0 = rt_hypotd_snf(rtb_Add_p, rtb_Total_Limited);

  /* Switch: '<S84>/Switch' incorporates:
   *  Constant: '<S84>/Constant'
   *  Constant: '<S84>/Constant1'
   *  Constant: '<S85>/Constant'
   *  Product: '<S84>/Divide'
   *  Product: '<S84>/Divide1'
   *  RelationalOperator: '<S85>/Compare'
   *  Switch: '<S84>/Switch1'
   */
  if (rtb_Add_f_idx_0 > 1.0E-6) {
    rtb_Total_Limited /= rtb_Add_f_idx_0;
    rtb_Switch2_d = rtb_Add_p / rtb_Add_f_idx_0;
  } else {
    rtb_Total_Limited = 0.0;
    rtb_Switch2_d = 1.0;
  }

  /* End of Switch: '<S84>/Switch' */

  /* Switch: '<S73>/Speed_Switch' incorporates:
   *  Abs: '<S73>/Abs'
   *  Constant: '<S81>/Constant'
   *  RelationalOperator: '<S81>/Compare'
   *  Switch: '<S73>/Angle_Switch'
   *  Trigonometry: '<S83>/Atan1'
   *  Trigonometry: '<S84>/Atan1'
   *  UnaryMinus: '<S73>/Unary Minus'
   */
  if (fabs(rt_atan2d_snf(rtb_Total_Limited, rtb_Switch2_d)) > 1.5707963267948966)
  {
    rtb_Switch2_d = -Code_Gen_Model_B.BL_Desired_Wheel_Speed;

    /* Sum: '<S83>/Subtract1' incorporates:
     *  Product: '<S83>/Product2'
     *  Product: '<S83>/Product3'
     *  UnaryMinus: '<S73>/Unary Minus'
     */
    rtb_Add_p = rtb_Subtract_n * Code_Gen_Model_ConstB.Sin5_e + rtb_Product_nw *
      Code_Gen_Model_ConstB.Cos5_i;

    /* Sum: '<S83>/Subtract' incorporates:
     *  Product: '<S83>/Product'
     *  Product: '<S83>/Product1'
     */
    rtb_Add_f_idx_1 = rtb_Subtract_n * Code_Gen_Model_ConstB.Cos5_i -
      rtb_Product_nw * Code_Gen_Model_ConstB.Sin5_e;

    /* Math: '<S83>/Hypot' */
    rtb_Add_f_idx_0 = rt_hypotd_snf(rtb_Add_f_idx_1, rtb_Add_p);

    /* Switch: '<S83>/Switch1' incorporates:
     *  Constant: '<S83>/Constant'
     *  Constant: '<S83>/Constant1'
     *  Constant: '<S86>/Constant'
     *  Product: '<S83>/Divide'
     *  Product: '<S83>/Divide1'
     *  RelationalOperator: '<S86>/Compare'
     *  Switch: '<S83>/Switch'
     */
    if (rtb_Add_f_idx_0 > 1.0E-6) {
      rtb_Add_f_idx_1 /= rtb_Add_f_idx_0;
      rtb_Add_p /= rtb_Add_f_idx_0;
    } else {
      rtb_Add_f_idx_1 = 1.0;
      rtb_Add_p = 0.0;
    }

    /* End of Switch: '<S83>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Add_p, rtb_Add_f_idx_1);
  } else {
    rtb_Switch2_d = Code_Gen_Model_B.BL_Desired_Wheel_Speed;
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.BL_Desired_Module_Angle;
  }

  /* Product: '<S76>/Product2' incorporates:
   *  Constant: '<S76>/Constant'
   *  Switch: '<S73>/Speed_Switch'
   */
  rtb_Total_Limited = rtb_Switch2_d * 1530.1401357649195;

  /* Signum: '<S71>/Sign' */
  if (rtIsNaN(rtb_Total_Limited)) {
    rtb_Switch2_d = (rtNaN);
  } else if (rtb_Total_Limited < 0.0) {
    rtb_Switch2_d = -1.0;
  } else {
    rtb_Switch2_d = rtb_Total_Limited > 0.0;
  }

  /* Signum: '<S71>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.BackLeft_Drive_Motor_Speed)) {
    rtb_Subtract_n = (rtNaN);
  } else if (Code_Gen_Model_U.BackLeft_Drive_Motor_Speed < 0.0) {
    rtb_Subtract_n = -1.0;
  } else {
    rtb_Subtract_n = Code_Gen_Model_U.BackLeft_Drive_Motor_Speed > 0.0;
  }

  /* Sum: '<S74>/Add' incorporates:
   *  Sum: '<S75>/Sum'
   */
  rtb_Optimized_Module_Angle -= Code_Gen_Model_B.BL_Steer_Module_Angle;

  /* Product: '<S26>/Product' incorporates:
   *  Abs: '<S71>/Abs'
   *  Abs: '<S74>/Abs'
   *  Constant: '<S77>/Constant'
   *  Constant: '<S87>/Constant3'
   *  Constant: '<S87>/Constant4'
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   *  Logic: '<S71>/OR'
   *  Lookup_n-D: '<S74>/1-D Lookup Table'
   *  Math: '<S87>/Math Function'
   *  RelationalOperator: '<S71>/Equal1'
   *  RelationalOperator: '<S77>/Compare'
   *  Signum: '<S71>/Sign'
   *  Signum: '<S71>/Sign1'
   *  Sum: '<S74>/Add'
   *  Sum: '<S87>/Add1'
   *  Sum: '<S87>/Add2'
   */
  rtb_Total_Limited = (real_T)(rtb_Switch2_d == rtb_Subtract_n || fabs
    (Code_Gen_Model_U.BackLeft_Drive_Motor_Speed) <= 1500.0) * rtb_Total_Limited
    * look1_binlcpw(fabs(rt_modd_snf(rtb_Optimized_Module_Angle +
    1.5707963267948966, 3.1415926535897931) - 1.5707963267948966),
                    Code_Gen_Model_ConstP.pooled24,
                    Code_Gen_Model_ConstP.pooled23, 1U);

  /* Gain: '<S72>/Gain' */
  rtb_Add_f_idx_1 = 0.00018181818181818181 * rtb_Total_Limited;

  /* Sum: '<S72>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Motor_Speed'
   */
  rtb_Total_Limited -= Code_Gen_Model_U.BackLeft_Drive_Motor_Speed;

  /* Sum: '<S79>/Sum1' incorporates:
   *  Constant: '<S72>/Constant2'
   *  Product: '<S79>/Product'
   *  Sum: '<S79>/Sum'
   *  UnitDelay: '<S79>/Unit Delay1'
   */
  rtb_Add_p = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_f) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_f;

  /* Product: '<S72>/Product' incorporates:
   *  Constant: '<S72>/Constant3'
   */
  rtb_Add_f_idx_0 = rtb_Add_p * 9.9999999999999991E-5;

  /* Sum: '<S78>/Diff' incorporates:
   *  UnitDelay: '<S78>/UD'
   *
   * Block description for '<S78>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S78>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_cc = rtb_Add_f_idx_0 - Code_Gen_Model_DW.UD_DSTATE_lh;

  /* Saturate: '<S72>/Saturation' */
  if (rtb_Add_cc > 0.2) {
    rtb_Add_cc = 0.2;
  } else if (rtb_Add_cc < -0.2) {
    rtb_Add_cc = -0.2;
  }

  /* Sum: '<S72>/Add' incorporates:
   *  Gain: '<S72>/Gain1'
   *  Saturate: '<S72>/Saturation'
   */
  rtb_Add_lb = 5.0E-6 * rtb_Total_Limited + rtb_Add_f_idx_1 + rtb_Add_cc;

  /* Sum: '<S72>/Subtract' incorporates:
   *  Constant: '<S72>/Constant'
   */
  rtb_Switch2_d = 1.0 - rtb_Add_lb;

  /* Sum: '<S72>/Sum2' incorporates:
   *  Gain: '<S72>/Gain2'
   *  UnitDelay: '<S72>/Unit Delay'
   */
  rtb_Total_Limited = 0.0 * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_gp;

  /* Switch: '<S80>/Switch2' incorporates:
   *  Constant: '<S72>/Constant'
   *  RelationalOperator: '<S80>/LowerRelop1'
   *  Sum: '<S72>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Add_lb)) {
    /* Switch: '<S80>/Switch' incorporates:
     *  Constant: '<S72>/Constant1'
     *  RelationalOperator: '<S80>/UpperRelop'
     *  Sum: '<S72>/Subtract1'
     */
    if (rtb_Total_Limited < -1.0 - rtb_Add_lb) {
      rtb_Switch2_d = -1.0 - rtb_Add_lb;
    } else {
      rtb_Switch2_d = rtb_Total_Limited;
    }

    /* End of Switch: '<S80>/Switch' */
  }

  /* End of Switch: '<S80>/Switch2' */

  /* Saturate: '<S72>/Saturation1' */
  if (rtb_Switch2_d > 0.0) {
    rtb_Add_f_idx_1 = 0.0;
  } else if (rtb_Switch2_d < -0.0) {
    rtb_Add_f_idx_1 = -0.0;
  } else {
    rtb_Add_f_idx_1 = rtb_Switch2_d;
  }

  /* End of Saturate: '<S72>/Saturation1' */

  /* Sum: '<S72>/Add1' */
  rtb_Add_cc = rtb_Add_lb + rtb_Add_f_idx_1;

  /* Saturate: '<S72>/Saturation2' */
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

  /* End of Saturate: '<S72>/Saturation2' */

  /* Sum: '<S88>/Add1' incorporates:
   *  Constant: '<S88>/Constant3'
   *  Constant: '<S88>/Constant4'
   *  Math: '<S88>/Math Function'
   *  Sum: '<S88>/Add2'
   */
  rtb_Total_Limited = rt_modd_snf(rtb_Optimized_Module_Angle +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S90>/Sum1' incorporates:
   *  Constant: '<S75>/Constant2'
   *  Product: '<S90>/Product'
   *  Sum: '<S90>/Sum'
   *  UnitDelay: '<S90>/Unit Delay1'
   */
  rtb_Add_lb = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_n) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_n;

  /* Product: '<S75>/Product' incorporates:
   *  Constant: '<S75>/Constant3'
   */
  rtb_Product_lf = rtb_Add_lb * 0.5;

  /* Sum: '<S89>/Diff' incorporates:
   *  UnitDelay: '<S89>/UD'
   *
   * Block description for '<S89>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S89>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_cc = rtb_Product_lf - Code_Gen_Model_DW.UD_DSTATE_k;

  /* Saturate: '<S75>/Saturation' */
  if (rtb_Add_cc > 0.2) {
    rtb_Add_cc = 0.2;
  } else if (rtb_Add_cc < -0.2) {
    rtb_Add_cc = -0.2;
  }

  /* Sum: '<S75>/Add' incorporates:
   *  Gain: '<S75>/Gain1'
   *  Saturate: '<S75>/Saturation'
   */
  rtb_Optimized_Module_Angle = 0.15 * rtb_Total_Limited + rtb_Add_cc;

  /* Sum: '<S75>/Subtract' incorporates:
   *  Constant: '<S75>/Constant'
   */
  rtb_Switch2_d = 1.0 - rtb_Optimized_Module_Angle;

  /* Sum: '<S75>/Sum2' incorporates:
   *  Gain: '<S75>/Gain2'
   *  UnitDelay: '<S75>/Unit Delay'
   */
  rtb_Total_Limited = 0.005 * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S91>/Switch2' incorporates:
   *  Constant: '<S75>/Constant'
   *  RelationalOperator: '<S91>/LowerRelop1'
   *  Sum: '<S75>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Optimized_Module_Angle)) {
    /* Switch: '<S91>/Switch' incorporates:
     *  Constant: '<S75>/Constant1'
     *  RelationalOperator: '<S91>/UpperRelop'
     *  Sum: '<S75>/Subtract1'
     */
    if (rtb_Total_Limited < -1.0 - rtb_Optimized_Module_Angle) {
      rtb_Switch2_d = -1.0 - rtb_Optimized_Module_Angle;
    } else {
      rtb_Switch2_d = rtb_Total_Limited;
    }

    /* End of Switch: '<S91>/Switch' */
  }

  /* End of Switch: '<S91>/Switch2' */

  /* Saturate: '<S75>/Saturation1' */
  if (rtb_Switch2_d > 0.005) {
    rtb_Subtract1_pl = 0.005;
  } else if (rtb_Switch2_d < -0.005) {
    rtb_Subtract1_pl = -0.005;
  } else {
    rtb_Subtract1_pl = rtb_Switch2_d;
  }

  /* End of Saturate: '<S75>/Saturation1' */

  /* Outport: '<Root>/BackLeft_Steer_DutyCycle' incorporates:
   *  Saturate: '<S75>/Saturation2'
   *  Sum: '<S75>/Add1'
   */
  Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = rtb_Optimized_Module_Angle +
    rtb_Subtract1_pl;

  /* Fcn: '<S151>/x->r' */
  rtb_Total_Limited = rt_hypotd_snf(rtb_TmpSignalConversionAtLook_o[0],
    rtb_TmpSignalConversionAtLook_o[1]);

  /* Switch: '<S150>/Switch1' incorporates:
   *  Constant: '<S154>/Constant'
   *  RelationalOperator: '<S154>/Compare'
   *  Switch: '<S150>/Switch'
   */
  if (rtb_Total_Limited == 0.0) {
    /* Switch: '<S150>/Switch1' incorporates:
     *  Constant: '<S150>/Constant'
     */
    Code_Gen_Model_B.FR_Desired_Wheel_Speed = 1.0E-15;
  } else {
    /* Switch: '<S150>/Switch1' */
    Code_Gen_Model_B.FR_Desired_Wheel_Speed = rtb_Total_Limited;

    /* Switch: '<S150>/Switch' incorporates:
     *  Fcn: '<S151>/x->theta'
     */
    Code_Gen_Model_B.FR_Desired_Module_Angle = rt_atan2d_snf
      (rtb_TmpSignalConversionAtLook_o[1], rtb_TmpSignalConversionAtLook_o[0]);
  }

  /* End of Switch: '<S150>/Switch1' */

  /* Trigonometry: '<S63>/Cos4' incorporates:
   *  Switch: '<S52>/Angle_Switch'
   *  Trigonometry: '<S62>/Cos4'
   */
  rtb_Subtract_n = cos(Code_Gen_Model_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S63>/Sin5' incorporates:
   *  UnaryMinus: '<S61>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Code_Gen_Model_B.FR_Steer_Module_Angle);

  /* Trigonometry: '<S63>/Sin4' incorporates:
   *  Switch: '<S52>/Angle_Switch'
   *  Trigonometry: '<S62>/Sin4'
   */
  rtb_Product_nw = sin(Code_Gen_Model_B.FR_Desired_Module_Angle);

  /* Trigonometry: '<S63>/Cos5' incorporates:
   *  UnaryMinus: '<S61>/Unary Minus'
   */
  rtb_Switch2_d = cos(-Code_Gen_Model_B.FR_Steer_Module_Angle);

  /* Sum: '<S63>/Subtract1' incorporates:
   *  Product: '<S63>/Product2'
   *  Product: '<S63>/Product3'
   *  Trigonometry: '<S63>/Cos4'
   *  Trigonometry: '<S63>/Sin4'
   */
  rtb_Total_Limited = rtb_Subtract_n * rtb_Optimized_Module_Angle +
    rtb_Product_nw * rtb_Switch2_d;

  /* Sum: '<S63>/Subtract' incorporates:
   *  Product: '<S63>/Product'
   *  Product: '<S63>/Product1'
   *  Trigonometry: '<S63>/Cos4'
   *  Trigonometry: '<S63>/Sin4'
   */
  rtb_Optimized_Module_Angle = rtb_Subtract_n * rtb_Switch2_d - rtb_Product_nw *
    rtb_Optimized_Module_Angle;

  /* Math: '<S63>/Hypot' */
  rtb_Switch2_d = rt_hypotd_snf(rtb_Optimized_Module_Angle, rtb_Total_Limited);

  /* Switch: '<S63>/Switch' incorporates:
   *  Constant: '<S63>/Constant'
   *  Constant: '<S63>/Constant1'
   *  Constant: '<S64>/Constant'
   *  Product: '<S63>/Divide'
   *  Product: '<S63>/Divide1'
   *  RelationalOperator: '<S64>/Compare'
   *  Switch: '<S63>/Switch1'
   */
  if (rtb_Switch2_d > 1.0E-6) {
    rtb_Total_Limited /= rtb_Switch2_d;
    rtb_Switch2_d = rtb_Optimized_Module_Angle / rtb_Switch2_d;
  } else {
    rtb_Total_Limited = 0.0;
    rtb_Switch2_d = 1.0;
  }

  /* End of Switch: '<S63>/Switch' */

  /* RelationalOperator: '<S60>/Compare' incorporates:
   *  Abs: '<S52>/Abs'
   *  Constant: '<S60>/Constant'
   *  Trigonometry: '<S63>/Atan1'
   */
  rtb_AND = fabs(rt_atan2d_snf(rtb_Total_Limited, rtb_Switch2_d)) >
    1.5707963267948966;

  /* Switch: '<S52>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S52>/Unary Minus'
   */
  if (rtb_AND) {
    rtb_Switch2_d = -Code_Gen_Model_B.FR_Desired_Wheel_Speed;
  } else {
    rtb_Switch2_d = Code_Gen_Model_B.FR_Desired_Wheel_Speed;
  }

  /* Product: '<S55>/Product2' incorporates:
   *  Constant: '<S55>/Constant'
   *  Switch: '<S52>/Speed_Switch'
   */
  rtb_Total_Limited = rtb_Switch2_d * 1530.1401357649195;

  /* Switch: '<S52>/Angle_Switch' incorporates:
   *  Trigonometry: '<S62>/Atan1'
   */
  if (rtb_AND) {
    /* Sum: '<S62>/Subtract1' incorporates:
     *  Product: '<S62>/Product2'
     *  Product: '<S62>/Product3'
     */
    rtb_Optimized_Module_Angle = rtb_Subtract_n * Code_Gen_Model_ConstB.Sin5_m +
      rtb_Product_nw * Code_Gen_Model_ConstB.Cos5_g;

    /* Sum: '<S62>/Subtract' incorporates:
     *  Product: '<S62>/Product'
     *  Product: '<S62>/Product1'
     */
    rtb_Subtract_kb = rtb_Subtract_n * Code_Gen_Model_ConstB.Cos5_g -
      rtb_Product_nw * Code_Gen_Model_ConstB.Sin5_m;

    /* Math: '<S62>/Hypot' */
    rtb_Switch2_d = rt_hypotd_snf(rtb_Subtract_kb, rtb_Optimized_Module_Angle);

    /* Switch: '<S62>/Switch1' incorporates:
     *  Constant: '<S62>/Constant'
     *  Constant: '<S62>/Constant1'
     *  Constant: '<S65>/Constant'
     *  Product: '<S62>/Divide'
     *  Product: '<S62>/Divide1'
     *  RelationalOperator: '<S65>/Compare'
     *  Switch: '<S62>/Switch'
     */
    if (rtb_Switch2_d > 1.0E-6) {
      rtb_Subtract_kb /= rtb_Switch2_d;
      rtb_Optimized_Module_Angle /= rtb_Switch2_d;
    } else {
      rtb_Subtract_kb = 1.0;
      rtb_Optimized_Module_Angle = 0.0;
    }

    /* End of Switch: '<S62>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Optimized_Module_Angle,
      rtb_Subtract_kb);
  } else {
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.FR_Desired_Module_Angle;
  }

  /* Signum: '<S50>/Sign' */
  if (rtIsNaN(rtb_Total_Limited)) {
    rtb_Switch2_d = (rtNaN);
  } else if (rtb_Total_Limited < 0.0) {
    rtb_Switch2_d = -1.0;
  } else {
    rtb_Switch2_d = rtb_Total_Limited > 0.0;
  }

  /* Signum: '<S50>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.FrontRight_Drive_Motor_Speed)) {
    rtb_Subtract_n = (rtNaN);
  } else if (Code_Gen_Model_U.FrontRight_Drive_Motor_Speed < 0.0) {
    rtb_Subtract_n = -1.0;
  } else {
    rtb_Subtract_n = Code_Gen_Model_U.FrontRight_Drive_Motor_Speed > 0.0;
  }

  /* Sum: '<S53>/Add' incorporates:
   *  Sum: '<S54>/Sum'
   */
  rtb_Optimized_Module_Angle -= Code_Gen_Model_B.FR_Steer_Module_Angle;

  /* Product: '<S25>/Product' incorporates:
   *  Abs: '<S50>/Abs'
   *  Abs: '<S53>/Abs'
   *  Constant: '<S56>/Constant'
   *  Constant: '<S66>/Constant3'
   *  Constant: '<S66>/Constant4'
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   *  Logic: '<S50>/OR'
   *  Lookup_n-D: '<S53>/1-D Lookup Table'
   *  Math: '<S66>/Math Function'
   *  RelationalOperator: '<S50>/Equal1'
   *  RelationalOperator: '<S56>/Compare'
   *  Signum: '<S50>/Sign'
   *  Signum: '<S50>/Sign1'
   *  Sum: '<S53>/Add'
   *  Sum: '<S66>/Add1'
   *  Sum: '<S66>/Add2'
   */
  rtb_Total_Limited = (real_T)(rtb_Switch2_d == rtb_Subtract_n || fabs
    (Code_Gen_Model_U.FrontRight_Drive_Motor_Speed) <= 1500.0) *
    rtb_Total_Limited * look1_binlcpw(fabs(rt_modd_snf
    (rtb_Optimized_Module_Angle + 1.5707963267948966, 3.1415926535897931) -
    1.5707963267948966), Code_Gen_Model_ConstP.pooled24,
    Code_Gen_Model_ConstP.pooled23, 1U);

  /* Gain: '<S51>/Gain' */
  rtb_Switch2_d = 0.00018181818181818181 * rtb_Total_Limited;

  /* Sum: '<S51>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Motor_Speed'
   */
  rtb_Total_Limited -= Code_Gen_Model_U.FrontRight_Drive_Motor_Speed;

  /* Sum: '<S58>/Sum1' incorporates:
   *  Constant: '<S51>/Constant2'
   *  Product: '<S58>/Product'
   *  Sum: '<S58>/Sum'
   *  UnitDelay: '<S58>/Unit Delay1'
   */
  rtb_Subtract_kb = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_b) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_b;

  /* Product: '<S51>/Product' incorporates:
   *  Constant: '<S51>/Constant3'
   */
  rtb_Product_n3 = rtb_Subtract_kb * 9.9999999999999991E-5;

  /* Sum: '<S57>/Diff' incorporates:
   *  UnitDelay: '<S57>/UD'
   *
   * Block description for '<S57>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S57>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_cc = rtb_Product_n3 - Code_Gen_Model_DW.UD_DSTATE_e;

  /* Saturate: '<S51>/Saturation' */
  if (rtb_Add_cc > 0.2) {
    rtb_Add_cc = 0.2;
  } else if (rtb_Add_cc < -0.2) {
    rtb_Add_cc = -0.2;
  }

  /* Sum: '<S51>/Add' incorporates:
   *  Gain: '<S51>/Gain1'
   *  Saturate: '<S51>/Saturation'
   */
  rtb_Add_k = 5.0E-6 * rtb_Total_Limited + rtb_Switch2_d + rtb_Add_cc;

  /* Sum: '<S51>/Subtract' incorporates:
   *  Constant: '<S51>/Constant'
   */
  rtb_Switch2_d = 1.0 - rtb_Add_k;

  /* Sum: '<S51>/Sum2' incorporates:
   *  Gain: '<S51>/Gain2'
   *  UnitDelay: '<S51>/Unit Delay'
   */
  rtb_Total_Limited = 0.0 * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_e;

  /* Switch: '<S59>/Switch2' incorporates:
   *  Constant: '<S51>/Constant'
   *  RelationalOperator: '<S59>/LowerRelop1'
   *  Sum: '<S51>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Add_k)) {
    /* Sum: '<S51>/Subtract1' incorporates:
     *  Constant: '<S51>/Constant1'
     */
    rtb_Switch2_d = -1.0 - rtb_Add_k;

    /* Switch: '<S59>/Switch' incorporates:
     *  Constant: '<S51>/Constant1'
     *  RelationalOperator: '<S59>/UpperRelop'
     *  Sum: '<S51>/Subtract1'
     */
    if (!(rtb_Total_Limited < -1.0 - rtb_Add_k)) {
      rtb_Switch2_d = rtb_Total_Limited;
    }

    /* End of Switch: '<S59>/Switch' */
  }

  /* End of Switch: '<S59>/Switch2' */

  /* Saturate: '<S51>/Saturation1' */
  if (rtb_Switch2_d > 0.0) {
    rtb_Integral_i = 0.0;
  } else if (rtb_Switch2_d < -0.0) {
    rtb_Integral_i = -0.0;
  } else {
    rtb_Integral_i = rtb_Switch2_d;
  }

  /* End of Saturate: '<S51>/Saturation1' */

  /* Sum: '<S51>/Add1' */
  rtb_Add_cc = rtb_Add_k + rtb_Integral_i;

  /* Saturate: '<S51>/Saturation2' */
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

  /* End of Saturate: '<S51>/Saturation2' */

  /* Sum: '<S67>/Add1' incorporates:
   *  Constant: '<S67>/Constant3'
   *  Constant: '<S67>/Constant4'
   *  Math: '<S67>/Math Function'
   *  Sum: '<S67>/Add2'
   */
  rtb_Total_Limited = rt_modd_snf(rtb_Optimized_Module_Angle +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S69>/Sum1' incorporates:
   *  Constant: '<S54>/Constant2'
   *  Product: '<S69>/Product'
   *  Sum: '<S69>/Sum'
   *  UnitDelay: '<S69>/Unit Delay1'
   */
  rtb_Add_k = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_na) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_na;

  /* Product: '<S54>/Product' incorporates:
   *  Constant: '<S54>/Constant3'
   */
  rtb_Product_go = rtb_Add_k * 0.5;

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
  rtb_Add_cc = rtb_Product_go - Code_Gen_Model_DW.UD_DSTATE_i1;

  /* Saturate: '<S54>/Saturation' */
  if (rtb_Add_cc > 0.2) {
    rtb_Add_cc = 0.2;
  } else if (rtb_Add_cc < -0.2) {
    rtb_Add_cc = -0.2;
  }

  /* Sum: '<S54>/Add' incorporates:
   *  Gain: '<S54>/Gain1'
   *  Saturate: '<S54>/Saturation'
   */
  rtb_Optimized_Module_Angle = 0.15 * rtb_Total_Limited + rtb_Add_cc;

  /* Sum: '<S54>/Subtract' incorporates:
   *  Constant: '<S54>/Constant'
   */
  rtb_Switch2_d = 1.0 - rtb_Optimized_Module_Angle;

  /* Sum: '<S54>/Sum2' incorporates:
   *  Gain: '<S54>/Gain2'
   *  UnitDelay: '<S54>/Unit Delay'
   */
  rtb_Total_Limited = 0.005 * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S70>/Switch2' incorporates:
   *  Constant: '<S54>/Constant'
   *  RelationalOperator: '<S70>/LowerRelop1'
   *  Sum: '<S54>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Optimized_Module_Angle)) {
    /* Sum: '<S54>/Subtract1' incorporates:
     *  Constant: '<S54>/Constant1'
     */
    rtb_Switch2_d = -1.0 - rtb_Optimized_Module_Angle;

    /* Switch: '<S70>/Switch' incorporates:
     *  Constant: '<S54>/Constant1'
     *  RelationalOperator: '<S70>/UpperRelop'
     *  Sum: '<S54>/Subtract1'
     */
    if (!(rtb_Total_Limited < -1.0 - rtb_Optimized_Module_Angle)) {
      rtb_Switch2_d = rtb_Total_Limited;
    }

    /* End of Switch: '<S70>/Switch' */
  }

  /* End of Switch: '<S70>/Switch2' */

  /* Saturate: '<S54>/Saturation1' */
  if (rtb_Switch2_d > 0.005) {
    rtb_Integral_je = 0.005;
  } else if (rtb_Switch2_d < -0.005) {
    rtb_Integral_je = -0.005;
  } else {
    rtb_Integral_je = rtb_Switch2_d;
  }

  /* End of Saturate: '<S54>/Saturation1' */

  /* Outport: '<Root>/FrontRight_Steer_DutyCycle' incorporates:
   *  Saturate: '<S54>/Saturation2'
   *  Sum: '<S54>/Add1'
   */
  Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = rtb_Optimized_Module_Angle +
    rtb_Integral_je;

  /* Fcn: '<S146>/x->r' */
  rtb_Total_Limited = rt_hypotd_snf(rtb_Product7[0], rtb_Product7[1]);

  /* Switch: '<S145>/Switch1' incorporates:
   *  Constant: '<S149>/Constant'
   *  RelationalOperator: '<S149>/Compare'
   *  Switch: '<S145>/Switch'
   */
  if (rtb_Total_Limited == 0.0) {
    /* Switch: '<S145>/Switch1' incorporates:
     *  Constant: '<S145>/Constant'
     */
    Code_Gen_Model_B.FL_Desired_Wheel_Speed = 1.0E-15;
  } else {
    /* Switch: '<S145>/Switch1' */
    Code_Gen_Model_B.FL_Desired_Wheel_Speed = rtb_Total_Limited;

    /* Switch: '<S145>/Switch' incorporates:
     *  Fcn: '<S146>/x->theta'
     */
    Code_Gen_Model_B.FL_Desired_Module_Angle = rt_atan2d_snf(rtb_Product7[1],
      rtb_Product7[0]);
  }

  /* End of Switch: '<S145>/Switch1' */

  /* Trigonometry: '<S42>/Cos4' incorporates:
   *  Switch: '<S31>/Angle_Switch'
   *  Trigonometry: '<S41>/Cos4'
   */
  rtb_Subtract_n = cos(Code_Gen_Model_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S42>/Sin5' incorporates:
   *  UnaryMinus: '<S40>/Unary Minus'
   */
  rtb_Optimized_Module_Angle = sin(-Code_Gen_Model_B.FL_Steer_Module_Angle);

  /* Trigonometry: '<S42>/Sin4' incorporates:
   *  Switch: '<S31>/Angle_Switch'
   *  Trigonometry: '<S41>/Sin4'
   */
  rtb_Product_nw = sin(Code_Gen_Model_B.FL_Desired_Module_Angle);

  /* Trigonometry: '<S42>/Cos5' incorporates:
   *  UnaryMinus: '<S40>/Unary Minus'
   */
  rtb_Switch2_d = cos(-Code_Gen_Model_B.FL_Steer_Module_Angle);

  /* Sum: '<S42>/Subtract1' incorporates:
   *  Product: '<S42>/Product2'
   *  Product: '<S42>/Product3'
   *  Trigonometry: '<S42>/Cos4'
   *  Trigonometry: '<S42>/Sin4'
   */
  rtb_Total_Limited = rtb_Subtract_n * rtb_Optimized_Module_Angle +
    rtb_Product_nw * rtb_Switch2_d;

  /* Sum: '<S42>/Subtract' incorporates:
   *  Product: '<S42>/Product'
   *  Product: '<S42>/Product1'
   *  Trigonometry: '<S42>/Cos4'
   *  Trigonometry: '<S42>/Sin4'
   */
  rtb_Optimized_Module_Angle = rtb_Subtract_n * rtb_Switch2_d - rtb_Product_nw *
    rtb_Optimized_Module_Angle;

  /* Math: '<S42>/Hypot' */
  rtb_Switch2_d = rt_hypotd_snf(rtb_Optimized_Module_Angle, rtb_Total_Limited);

  /* Switch: '<S42>/Switch' incorporates:
   *  Constant: '<S42>/Constant'
   *  Constant: '<S42>/Constant1'
   *  Constant: '<S43>/Constant'
   *  Product: '<S42>/Divide'
   *  Product: '<S42>/Divide1'
   *  RelationalOperator: '<S43>/Compare'
   *  Switch: '<S42>/Switch1'
   */
  if (rtb_Switch2_d > 1.0E-6) {
    rtb_Total_Limited /= rtb_Switch2_d;
    rtb_Switch2_d = rtb_Optimized_Module_Angle / rtb_Switch2_d;
  } else {
    rtb_Total_Limited = 0.0;
    rtb_Switch2_d = 1.0;
  }

  /* End of Switch: '<S42>/Switch' */

  /* RelationalOperator: '<S39>/Compare' incorporates:
   *  Abs: '<S31>/Abs'
   *  Constant: '<S39>/Constant'
   *  Trigonometry: '<S42>/Atan1'
   */
  rtb_AND = fabs(rt_atan2d_snf(rtb_Total_Limited, rtb_Switch2_d)) >
    1.5707963267948966;

  /* Switch: '<S31>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S31>/Unary Minus'
   */
  if (rtb_AND) {
    rtb_Switch2_d = -Code_Gen_Model_B.FL_Desired_Wheel_Speed;
  } else {
    rtb_Switch2_d = Code_Gen_Model_B.FL_Desired_Wheel_Speed;
  }

  /* Product: '<S34>/Product2' incorporates:
   *  Constant: '<S34>/Constant'
   *  Switch: '<S31>/Speed_Switch'
   */
  rtb_Total_Limited = rtb_Switch2_d * 1530.1401357649195;

  /* Switch: '<S31>/Angle_Switch' incorporates:
   *  Trigonometry: '<S41>/Atan1'
   */
  if (rtb_AND) {
    /* Sum: '<S41>/Subtract1' incorporates:
     *  Product: '<S41>/Product2'
     *  Product: '<S41>/Product3'
     */
    rtb_Optimized_Module_Angle = rtb_Subtract_n * Code_Gen_Model_ConstB.Sin5 +
      rtb_Product_nw * Code_Gen_Model_ConstB.Cos5;

    /* Sum: '<S41>/Subtract' incorporates:
     *  Product: '<S41>/Product'
     *  Product: '<S41>/Product1'
     */
    rtb_Subtract_n = rtb_Subtract_n * Code_Gen_Model_ConstB.Cos5 -
      rtb_Product_nw * Code_Gen_Model_ConstB.Sin5;

    /* Math: '<S41>/Hypot' */
    rtb_Switch2_d = rt_hypotd_snf(rtb_Subtract_n, rtb_Optimized_Module_Angle);

    /* Switch: '<S41>/Switch1' incorporates:
     *  Constant: '<S41>/Constant'
     *  Constant: '<S41>/Constant1'
     *  Constant: '<S44>/Constant'
     *  Product: '<S41>/Divide'
     *  Product: '<S41>/Divide1'
     *  RelationalOperator: '<S44>/Compare'
     *  Switch: '<S41>/Switch'
     */
    if (rtb_Switch2_d > 1.0E-6) {
      rtb_Subtract_n /= rtb_Switch2_d;
      rtb_Optimized_Module_Angle /= rtb_Switch2_d;
    } else {
      rtb_Subtract_n = 1.0;
      rtb_Optimized_Module_Angle = 0.0;
    }

    /* End of Switch: '<S41>/Switch1' */
    rtb_Optimized_Module_Angle = rt_atan2d_snf(rtb_Optimized_Module_Angle,
      rtb_Subtract_n);
  } else {
    rtb_Optimized_Module_Angle = Code_Gen_Model_B.FL_Desired_Module_Angle;
  }

  /* Signum: '<S29>/Sign' */
  if (rtIsNaN(rtb_Total_Limited)) {
    rtb_Switch2_d = (rtNaN);
  } else if (rtb_Total_Limited < 0.0) {
    rtb_Switch2_d = -1.0;
  } else {
    rtb_Switch2_d = rtb_Total_Limited > 0.0;
  }

  /* Signum: '<S29>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  if (rtIsNaN(Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed)) {
    rtb_Subtract_n = (rtNaN);
  } else if (Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed < 0.0) {
    rtb_Subtract_n = -1.0;
  } else {
    rtb_Subtract_n = Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed > 0.0;
  }

  /* Sum: '<S32>/Add' incorporates:
   *  Sum: '<S33>/Sum'
   */
  rtb_Optimized_Module_Angle -= Code_Gen_Model_B.FL_Steer_Module_Angle;

  /* Product: '<S24>/Product' incorporates:
   *  Abs: '<S29>/Abs'
   *  Abs: '<S32>/Abs'
   *  Constant: '<S35>/Constant'
   *  Constant: '<S45>/Constant3'
   *  Constant: '<S45>/Constant4'
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   *  Logic: '<S29>/OR'
   *  Lookup_n-D: '<S32>/1-D Lookup Table'
   *  Math: '<S45>/Math Function'
   *  RelationalOperator: '<S29>/Equal1'
   *  RelationalOperator: '<S35>/Compare'
   *  Signum: '<S29>/Sign'
   *  Signum: '<S29>/Sign1'
   *  Sum: '<S32>/Add'
   *  Sum: '<S45>/Add1'
   *  Sum: '<S45>/Add2'
   */
  rtb_Total_Limited = (real_T)(rtb_Switch2_d == rtb_Subtract_n || fabs
    (Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed) <= 1500.0) *
    rtb_Total_Limited * look1_binlcpw(fabs(rt_modd_snf
    (rtb_Optimized_Module_Angle + 1.5707963267948966, 3.1415926535897931) -
    1.5707963267948966), Code_Gen_Model_ConstP.pooled24,
    Code_Gen_Model_ConstP.pooled23, 1U);

  /* Gain: '<S30>/Gain' */
  rtb_Switch2_d = 0.00018181818181818181 * rtb_Total_Limited;

  /* Sum: '<S30>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Motor_Speed'
   */
  rtb_Total_Limited -= Code_Gen_Model_U.FrontLeft_Drive_Motor_Speed;

  /* Sum: '<S37>/Sum1' incorporates:
   *  Constant: '<S30>/Constant2'
   *  Product: '<S37>/Product'
   *  Sum: '<S37>/Sum'
   *  UnitDelay: '<S37>/Unit Delay1'
   */
  rtb_Subtract_n = (rtb_Total_Limited - Code_Gen_Model_DW.UnitDelay1_DSTATE_a) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_a;

  /* Product: '<S30>/Product' incorporates:
   *  Constant: '<S30>/Constant3'
   */
  rtb_Product_nw = rtb_Subtract_n * 9.9999999999999991E-5;

  /* Sum: '<S36>/Diff' incorporates:
   *  UnitDelay: '<S36>/UD'
   *
   * Block description for '<S36>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S36>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_cc = rtb_Product_nw - Code_Gen_Model_DW.UD_DSTATE_o;

  /* Saturate: '<S30>/Saturation' */
  if (rtb_Add_cc > 0.2) {
    rtb_Add_cc = 0.2;
  } else if (rtb_Add_cc < -0.2) {
    rtb_Add_cc = -0.2;
  }

  /* Sum: '<S30>/Add' incorporates:
   *  Gain: '<S30>/Gain1'
   *  Saturate: '<S30>/Saturation'
   */
  rtb_Add_ia = 5.0E-6 * rtb_Total_Limited + rtb_Switch2_d + rtb_Add_cc;

  /* Sum: '<S30>/Subtract' incorporates:
   *  Constant: '<S30>/Constant'
   */
  rtb_Switch2_d = 1.0 - rtb_Add_ia;

  /* Sum: '<S30>/Sum2' incorporates:
   *  Gain: '<S30>/Gain2'
   *  UnitDelay: '<S30>/Unit Delay'
   */
  rtb_Total_Limited = 0.0 * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_f;

  /* Switch: '<S38>/Switch2' incorporates:
   *  Constant: '<S30>/Constant'
   *  RelationalOperator: '<S38>/LowerRelop1'
   *  Sum: '<S30>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Add_ia)) {
    /* Sum: '<S30>/Subtract1' incorporates:
     *  Constant: '<S30>/Constant1'
     */
    rtb_Switch2_d = -1.0 - rtb_Add_ia;

    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S30>/Constant1'
     *  RelationalOperator: '<S38>/UpperRelop'
     *  Sum: '<S30>/Subtract1'
     */
    if (!(rtb_Total_Limited < -1.0 - rtb_Add_ia)) {
      rtb_Switch2_d = rtb_Total_Limited;
    }

    /* End of Switch: '<S38>/Switch' */
  }

  /* End of Switch: '<S38>/Switch2' */

  /* Saturate: '<S30>/Saturation1' */
  if (rtb_Switch2_d > 0.0) {
    rtb_Integral_da = 0.0;
  } else if (rtb_Switch2_d < -0.0) {
    rtb_Integral_da = -0.0;
  } else {
    rtb_Integral_da = rtb_Switch2_d;
  }

  /* End of Saturate: '<S30>/Saturation1' */

  /* Sum: '<S30>/Add1' */
  rtb_Add_cc = rtb_Add_ia + rtb_Integral_da;

  /* Saturate: '<S30>/Saturation2' */
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

  /* End of Saturate: '<S30>/Saturation2' */

  /* Sum: '<S46>/Add1' incorporates:
   *  Constant: '<S46>/Constant3'
   *  Constant: '<S46>/Constant4'
   *  Math: '<S46>/Math Function'
   *  Sum: '<S46>/Add2'
   */
  rtb_Total_Limited = rt_modd_snf(rtb_Optimized_Module_Angle +
    3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;

  /* Sum: '<S48>/Sum1' incorporates:
   *  Constant: '<S33>/Constant2'
   *  Product: '<S48>/Product'
   *  Sum: '<S48>/Sum'
   *  UnitDelay: '<S48>/Unit Delay1'
   */
  rtb_Optimized_Module_Angle = (rtb_Total_Limited -
    Code_Gen_Model_DW.UnitDelay1_DSTATE_bk) * 0.22223232082821098 +
    Code_Gen_Model_DW.UnitDelay1_DSTATE_bk;

  /* Product: '<S33>/Product' incorporates:
   *  Constant: '<S33>/Constant3'
   */
  rtb_Add_ia = rtb_Optimized_Module_Angle * 0.5;

  /* Sum: '<S47>/Diff' incorporates:
   *  UnitDelay: '<S47>/UD'
   *
   * Block description for '<S47>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S47>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_cc = rtb_Add_ia - Code_Gen_Model_DW.UD_DSTATE_b;

  /* Saturate: '<S33>/Saturation' */
  if (rtb_Add_cc > 0.2) {
    rtb_Add_cc = 0.2;
  } else if (rtb_Add_cc < -0.2) {
    rtb_Add_cc = -0.2;
  }

  /* Sum: '<S33>/Add' incorporates:
   *  Gain: '<S33>/Gain1'
   *  Saturate: '<S33>/Saturation'
   */
  rtb_Add_cc += 0.15 * rtb_Total_Limited;

  /* Sum: '<S33>/Subtract' incorporates:
   *  Constant: '<S33>/Constant'
   */
  rtb_Switch2_d = 1.0 - rtb_Add_cc;

  /* Sum: '<S33>/Sum2' incorporates:
   *  Gain: '<S33>/Gain2'
   *  UnitDelay: '<S33>/Unit Delay'
   */
  rtb_Total_Limited = 0.005 * rtb_Total_Limited +
    Code_Gen_Model_DW.UnitDelay_DSTATE_em;

  /* Switch: '<S49>/Switch2' incorporates:
   *  Constant: '<S33>/Constant'
   *  RelationalOperator: '<S49>/LowerRelop1'
   *  Sum: '<S33>/Subtract'
   */
  if (!(rtb_Total_Limited > 1.0 - rtb_Add_cc)) {
    /* Sum: '<S33>/Subtract1' incorporates:
     *  Constant: '<S33>/Constant1'
     */
    rtb_Switch2_d = -1.0 - rtb_Add_cc;

    /* Switch: '<S49>/Switch' incorporates:
     *  Constant: '<S33>/Constant1'
     *  RelationalOperator: '<S49>/UpperRelop'
     *  Sum: '<S33>/Subtract1'
     */
    if (!(rtb_Total_Limited < -1.0 - rtb_Add_cc)) {
      rtb_Switch2_d = rtb_Total_Limited;
    }

    /* End of Switch: '<S49>/Switch' */
  }

  /* End of Switch: '<S49>/Switch2' */

  /* Saturate: '<S33>/Saturation1' */
  if (rtb_Switch2_d > 0.005) {
    rtb_Total_Limited = 0.005;
  } else if (rtb_Switch2_d < -0.005) {
    rtb_Total_Limited = -0.005;
  } else {
    rtb_Total_Limited = rtb_Switch2_d;
  }

  /* End of Saturate: '<S33>/Saturation1' */

  /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' incorporates:
   *  Saturate: '<S33>/Saturation2'
   *  Sum: '<S33>/Add1'
   */
  Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = rtb_Add_cc + rtb_Total_Limited;

  /* DiscreteIntegrator: '<S5>/Accumulator2' */
  Code_Gen_Model_B.Odometry_X_global_est_m =
    Code_Gen_Model_DW.Accumulator2_DSTATE;

  /* Gain: '<S19>/meters to feet' */
  Code_Gen_Model_B.Odometry_X_global_est_ft = 3.28084 *
    Code_Gen_Model_B.Odometry_X_global_est_m;

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S19>/Constant'
   *  UnitDelay: '<S19>/Unit Delay'
   */
  if (Odometry_X_Y_TEAR) {
    rtb_Switch2_d = Code_Gen_Model_B.Odometry_X_global_est_ft;
  } else {
    rtb_Switch2_d = Code_Gen_Model_DW.UnitDelay_DSTATE_c;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Sum: '<S19>/Subtract' */
  Code_Gen_Model_B.Odometry_X_global_TEAR_ft =
    Code_Gen_Model_B.Odometry_X_global_est_ft - rtb_Switch2_d;

  /* DiscreteIntegrator: '<S5>/Accumulator' */
  Code_Gen_Model_B.Odometry_Y_global_est_m =
    Code_Gen_Model_DW.Accumulator_DSTATE;

  /* Gain: '<S19>/meters to feet1' */
  Code_Gen_Model_B.Odometry_Y_global_est_ft = 3.28084 *
    Code_Gen_Model_B.Odometry_Y_global_est_m;

  /* Switch: '<S19>/Switch1' incorporates:
   *  Constant: '<S19>/Constant'
   *  UnitDelay: '<S19>/Unit Delay1'
   */
  if (Odometry_X_Y_TEAR) {
    rtb_Add_cc = Code_Gen_Model_B.Odometry_Y_global_est_ft;
  } else {
    rtb_Add_cc = Code_Gen_Model_DW.UnitDelay1_DSTATE_d;
  }

  /* End of Switch: '<S19>/Switch1' */

  /* Sum: '<S19>/Subtract1' */
  Code_Gen_Model_B.Odometry_Y_global_TEAR_ft =
    Code_Gen_Model_B.Odometry_Y_global_est_ft - rtb_Add_cc;

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

  /* Update for UnitDelay: '<S124>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S124>/FixPt Constant'
   */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S138>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE = rtb_POSEexponentialmatrixfori_0;

  /* Update for UnitDelay: '<S137>/UD'
   *
   * Block description for '<S137>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_a = rtb_Switch2;

  /* Update for UnitDelay: '<S135>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_m = rtb_Sum1_li;

  /* Update for UnitDelay: '<S133>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S133>/FixPt Constant'
   */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c = 0U;

  /* Update for UnitDelay: '<S100>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_k = rtb_uDLookupTable;

  /* Update for UnitDelay: '<S99>/UD'
   *
   * Block description for '<S99>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_cs = rtb_Init;

  /* Update for UnitDelay: '<S93>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_a = rtb_Modulation_Drv_X;

  /* Update for UnitDelay: '<S111>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_i = rtb_Switch_kj;

  /* Update for UnitDelay: '<S110>/UD'
   *
   * Block description for '<S110>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_l = rtb_Subtract1_lg;

  /* Update for UnitDelay: '<S96>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_l = rtb_Sum2_fc;

  /* Update for UnitDelay: '<S79>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_f = rtb_Add_p;

  /* Update for UnitDelay: '<S78>/UD'
   *
   * Block description for '<S78>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_lh = rtb_Add_f_idx_0;

  /* Update for UnitDelay: '<S72>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_gp = rtb_Add_f_idx_1;

  /* Update for UnitDelay: '<S90>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_n = rtb_Add_lb;

  /* Update for UnitDelay: '<S89>/UD'
   *
   * Block description for '<S89>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_k = rtb_Product_lf;

  /* Update for UnitDelay: '<S75>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_k = rtb_Subtract1_pl;

  /* Update for UnitDelay: '<S58>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_b = rtb_Subtract_kb;

  /* Update for UnitDelay: '<S57>/UD'
   *
   * Block description for '<S57>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_e = rtb_Product_n3;

  /* Update for UnitDelay: '<S51>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_e = rtb_Integral_i;

  /* Update for UnitDelay: '<S69>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_na = rtb_Add_k;

  /* Update for UnitDelay: '<S68>/UD'
   *
   * Block description for '<S68>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_i1 = rtb_Product_go;

  /* Update for UnitDelay: '<S54>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_d = rtb_Integral_je;

  /* Update for UnitDelay: '<S37>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_a = rtb_Subtract_n;

  /* Update for UnitDelay: '<S36>/UD'
   *
   * Block description for '<S36>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_o = rtb_Product_nw;

  /* Update for UnitDelay: '<S30>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_f = rtb_Integral_da;

  /* Update for UnitDelay: '<S48>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_bk = rtb_Optimized_Module_Angle;

  /* Update for UnitDelay: '<S47>/UD'
   *
   * Block description for '<S47>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_b = rtb_Add_ia;

  /* Update for UnitDelay: '<S33>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_em = rtb_Total_Limited;

  /* Update for DiscreteIntegrator: '<S5>/Accumulator2' incorporates:
   *  Product: '<S5>/Product6'
   */
  Code_Gen_Model_DW.Accumulator2_DSTATE += rtb_POSEexponentialmatrixfori_1;

  /* Update for UnitDelay: '<S19>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_c = rtb_Switch2_d;

  /* Update for DiscreteIntegrator: '<S5>/Accumulator' incorporates:
   *  Product: '<S5>/Product6'
   */
  Code_Gen_Model_DW.Accumulator_DSTATE += rtb_POSEexponentialmatrixfori_2;

  /* Update for UnitDelay: '<S19>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_d = rtb_Add_cc;
}

/* Model initialize function */
void Code_Gen_Model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* InitializeConditions for UnitDelay: '<S124>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S133>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_c = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Accumulator2' */
  Code_Gen_Model_DW.Accumulator2_DSTATE = Code_Gen_Model_ConstB.Constant;

  /* InitializeConditions for DiscreteIntegrator: '<S5>/Accumulator' */
  Code_Gen_Model_DW.Accumulator_DSTATE = Code_Gen_Model_ConstB.Constant1;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S183>/FixPt Unit Delay2' */
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
