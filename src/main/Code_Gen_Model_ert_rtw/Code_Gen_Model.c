/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Jul  8 21:20:54 2023
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
  /* Start for MATLABSystem: '<S26>/Modulo by Constant' */
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
}

/* Output and update for atomic system: */
void Code_Gen_Model_ModulobyConstant(real_T rtu_0,
  B_ModulobyConstant_Code_Gen_M_T *localB)
{
  real_T yTemp;

  /* MATLABSystem: '<S26>/Modulo by Constant' */
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

  /* MATLABSystem: '<S26>/Modulo by Constant' */
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
  real_T rtb_Abs;
  real_T rtb_Abs_j;
  real_T rtb_Abs_g;
  real_T rtb_Abs_p;
  real_T rtb_Abs_c;
  real_T rtb_Abs_a;
  real_T rtb_Abs_cq;
  real_T rtb_Abs_l;
  real_T rtb_Add;
  real_T rtb_Add_da_idx_0;
  real_T rtb_Add_da_idx_1;
  real_T rtb_Add_fs_idx_0;
  real_T rtb_Add_fs_idx_1;
  real_T rtb_Add_hu;
  real_T rtb_Add_l_idx_0;
  real_T rtb_Add_l_idx_1;
  real_T rtb_Add_lm;
  real_T rtb_Add_m_idx_1;
  real_T rtb_Hypot;
  real_T rtb_Hypot_a;
  real_T rtb_Hypot_e;
  real_T rtb_Hypot_i;
  real_T rtb_Integral_j;
  real_T rtb_Minus2;
  real_T rtb_Modulation_Drv_Y;
  real_T rtb_RateLimiter;
  real_T rtb_Sin4;
  real_T rtb_Subtract1_cp;
  real_T rtb_Subtract1_hm;
  real_T rtb_Subtract1_j;
  real_T rtb_Subtract1_ok;
  real_T rtb_Subtract_at;
  real_T rtb_Subtract_l;
  real_T rtb_Subtract_nk;
  real_T rtb_Sum1_m;
  real_T rtb_Switch2;
  real_T rtb_Total_Limited_l;
  real_T u0;
  boolean_T rtb_Compare_na;
  boolean_T rtb_Is_Absolute_Translation;

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S6>/Constant4'
   *  Constant: '<S6>/Constant5'
   *  Constant: '<S6>/Constant6'
   *  Inport: '<Root>/GameState'
   */
  rtb_Total_Limited_l = trunc(Code_Gen_Model_U.GameState);
  if (rtIsNaN(rtb_Total_Limited_l) || rtIsInf(rtb_Total_Limited_l)) {
    rtb_Total_Limited_l = 0.0;
  } else {
    rtb_Total_Limited_l = fmod(rtb_Total_Limited_l, 4.294967296E+9);
  }

  switch (rtb_Total_Limited_l < 0.0 ? -(int32_T)(uint32_T)-rtb_Total_Limited_l :
          (int32_T)(uint32_T)rtb_Total_Limited_l) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Disabled' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    Code_Gen_Model_Disabled(&rtb_Total_Limited_l, &rtb_Minus2, &rtb_Switch2,
      &Code_Gen_Model_B.Translation_Angle, &rtb_RateLimiter,
      &rtb_Is_Absolute_Translation, &rtb_Compare_na);

    /* End of Outputs for SubSystem: '<S1>/Disabled' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    Code_Gen_Model_Disabled(&rtb_Total_Limited_l, &rtb_Minus2, &rtb_Switch2,
      &Code_Gen_Model_B.Translation_Angle, &rtb_RateLimiter,
      &rtb_Is_Absolute_Translation, &rtb_Compare_na);

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Teleop' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Lookup_n-D: '<S134>/Modulation_Str_X_Abs' incorporates:
     *  Inport: '<Root>/Steer_Joystick_X'
     *  Lookup_n-D: '<S134>/Modulation_Str_X_Rel'
     */
    rtb_Sin4 = look1_binlcpw(Code_Gen_Model_U.Steer_Joystick_X,
      Code_Gen_Model_ConstP.pooled11, Code_Gen_Model_ConstP.pooled10, 20U);

    /* UnaryMinus: '<S134>/Unary Minus1' incorporates:
     *  Inport: '<Root>/Steer_Joystick_Y'
     *  Lookup_n-D: '<S134>/Modulation_Str_Y_Abs'
     */
    rtb_Modulation_Drv_Y = -look1_binlcpw(Code_Gen_Model_U.Steer_Joystick_Y,
      Code_Gen_Model_ConstP.pooled11, Code_Gen_Model_ConstP.pooled10, 20U);

    /* RelationalOperator: '<S139>/Compare' incorporates:
     *  Constant: '<S139>/Constant'
     *  UnaryMinus: '<S134>/Unary Minus1'
     */
    rtb_Is_Absolute_Translation = rtb_Modulation_Drv_Y < 0.0;

    /* Switch: '<S136>/Switch' incorporates:
     *  Constant: '<S136>/Constant'
     *  Constant: '<S136>/Constant1'
     *  Constant: '<S137>/Constant'
     *  Constant: '<S138>/Constant'
     *  Logic: '<S136>/Logical Operator'
     *  Lookup_n-D: '<S134>/Modulation_Str_X_Abs'
     *  RelationalOperator: '<S137>/Compare'
     *  RelationalOperator: '<S138>/Compare'
     *  UnaryMinus: '<S134>/Unary Minus2'
     *  UnitDelay: '<S136>/Unit Delay'
     */
    if (-rtb_Sin4 < 0.0 && Code_Gen_Model_DW.UnitDelay_DSTATE_g >= 0.0 &&
        rtb_Is_Absolute_Translation) {
      rtb_Total_Limited_l = 6.2831853071795862;
    } else {
      rtb_Total_Limited_l = 0.0;
    }

    /* Switch: '<S136>/Switch1' incorporates:
     *  Constant: '<S136>/Constant2'
     *  Constant: '<S136>/Constant3'
     *  Constant: '<S140>/Constant'
     *  Constant: '<S141>/Constant'
     *  Logic: '<S136>/Logical Operator1'
     *  Lookup_n-D: '<S134>/Modulation_Str_X_Abs'
     *  RelationalOperator: '<S140>/Compare'
     *  RelationalOperator: '<S141>/Compare'
     *  UnaryMinus: '<S134>/Unary Minus2'
     *  UnitDelay: '<S136>/Unit Delay'
     */
    if (Code_Gen_Model_DW.UnitDelay_DSTATE_g < 0.0 && -rtb_Sin4 >= 0.0 &&
        rtb_Is_Absolute_Translation) {
      rtb_RateLimiter = -6.2831853071795862;
    } else {
      rtb_RateLimiter = 0.0;
    }

    /* Sum: '<S136>/Sum1' incorporates:
     *  Switch: '<S136>/Switch'
     *  Switch: '<S136>/Switch1'
     *  UnitDelay: '<S136>/Unit Delay1'
     */
    rtb_Sum1_m = rtb_Total_Limited_l + rtb_RateLimiter +
      Code_Gen_Model_DW.UnitDelay1_DSTATE_d;

    /* Sum: '<S136>/Sum' incorporates:
     *  Gain: '<S133>/Gain1'
     *  Inport: '<Root>/Gyro_Angle'
     */
    rtb_Total_Limited_l = 0.017453292519943295 * Code_Gen_Model_U.Gyro_Angle +
      rtb_Sum1_m;

    /* UnaryMinus: '<S134>/Unary Minus' incorporates:
     *  Lookup_n-D: '<S134>/Modulation_Str_X_Abs'
     *  Trigonometry: '<S134>/Atan2'
     *  UnaryMinus: '<S134>/Unary Minus2'
     */
    rtb_Minus2 = -rt_atan2d_snf(-rtb_Sin4, rtb_Modulation_Drv_Y);

    /* Product: '<S134>/Product' incorporates:
     *  Constant: '<S134>/Constant'
     */
    rtb_Switch2 = rtb_Sin4 * 0.75;

    /* Lookup_n-D: '<S135>/Modulation_Drv_X' incorporates:
     *  Inport: '<Root>/Drive_Joystick_X'
     */
    rtb_RateLimiter = look1_binlcpw(Code_Gen_Model_U.Drive_Joystick_X,
      Code_Gen_Model_ConstP.pooled11, Code_Gen_Model_ConstP.pooled10, 20U);

    /* Lookup_n-D: '<S135>/Modulation_Drv_Y' incorporates:
     *  Inport: '<Root>/Drive_Joystick_Y'
     */
    rtb_Modulation_Drv_Y = look1_binlcpw(Code_Gen_Model_U.Drive_Joystick_Y,
      Code_Gen_Model_ConstP.pooled11, Code_Gen_Model_ConstP.pooled10, 20U);

    /* Merge: '<S1>/Merge3' incorporates:
     *  Trigonometry: '<S135>/Atan2'
     *  UnaryMinus: '<S135>/Unary Minus'
     */
    Code_Gen_Model_B.Translation_Angle = rt_atan2d_snf(-rtb_RateLimiter,
      rtb_Modulation_Drv_Y);

    /* Math: '<S135>/Magnitude' incorporates:
     *  UnaryMinus: '<S135>/Unary Minus'
     */
    rtb_RateLimiter = rt_hypotd_snf(-rtb_RateLimiter, rtb_Modulation_Drv_Y);

    /* RateLimiter: '<S135>/Rate Limiter' */
    rtb_Modulation_Drv_Y = rtb_RateLimiter - Code_Gen_Model_DW.PrevY;
    if (rtb_Modulation_Drv_Y > 0.018000000000000002) {
      rtb_RateLimiter = Code_Gen_Model_DW.PrevY + 0.018000000000000002;
    } else if (rtb_Modulation_Drv_Y < -20.0) {
      rtb_RateLimiter = Code_Gen_Model_DW.PrevY - 20.0;
    }

    Code_Gen_Model_DW.PrevY = rtb_RateLimiter;

    /* End of RateLimiter: '<S135>/Rate Limiter' */

    /* SignalConversion generated from: '<S5>/Is_Absolute_Translation_In' incorporates:
     *  Inport: '<Root>/Is_Absolute_Translation'
     */
    rtb_Is_Absolute_Translation = Code_Gen_Model_U.Is_Absolute_Translation;

    /* SignalConversion generated from: '<S5>/Is_Absolute_Steering_In' incorporates:
     *  Inport: '<Root>/Is_Absolute_Steering'
     */
    rtb_Compare_na = Code_Gen_Model_U.Is_Absolute_Steering;

    /* Update for UnitDelay: '<S136>/Unit Delay' incorporates:
     *  Lookup_n-D: '<S134>/Modulation_Str_X_Abs'
     *  UnaryMinus: '<S134>/Unary Minus2'
     */
    Code_Gen_Model_DW.UnitDelay_DSTATE_g = -rtb_Sin4;

    /* Update for UnitDelay: '<S136>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_d = rtb_Sum1_m;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    rtb_Total_Limited_l = 0.0;
    rtb_Minus2 = 0.0;
    rtb_Switch2 = 0.0;

    /* Merge: '<S1>/Merge3' incorporates:
     *  Constant: '<S6>/Constant'
     *  Constant: '<S6>/Constant1'
     *  Constant: '<S6>/Constant2'
     *  Constant: '<S6>/Constant3'
     */
    Code_Gen_Model_B.Translation_Angle = 0.0;
    rtb_RateLimiter = 1.0;
    rtb_Is_Absolute_Translation = true;
    rtb_Compare_na = true;

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Switch: '<S103>/Switch' */
  if (rtb_Is_Absolute_Translation) {
    /* UnaryMinus: '<S103>/Unary Minus' incorporates:
     *  Constant: '<S115>/Constant3'
     *  Constant: '<S115>/Constant4'
     *  Gain: '<S7>/Gain1'
     *  Inport: '<Root>/Gyro_Angle'
     *  Math: '<S115>/Math Function'
     *  Sum: '<S115>/Add1'
     *  Sum: '<S115>/Add2'
     */
    Code_Gen_Model_B.Translation_Steering_Cmd = -(rt_modd_snf
      (Code_Gen_Model_B.Translation_Angle - 0.017453292519943295 *
       Code_Gen_Model_U.Gyro_Angle + 3.1415926535897931, 6.2831853071795862) -
      3.1415926535897931);
  } else {
    /* UnaryMinus: '<S103>/Unary Minus' */
    Code_Gen_Model_B.Translation_Steering_Cmd =
      -Code_Gen_Model_B.Translation_Angle;
  }

  /* End of Switch: '<S103>/Switch' */

  /* Sum: '<S110>/Sum' */
  rtb_Minus2 -= rtb_Total_Limited_l;

  /* Sum: '<S114>/Subtract1' incorporates:
   *  Product: '<S114>/Divide'
   *  Product: '<S114>/Product'
   *  Rounding: '<S114>/Fix'
   *  Sum: '<S114>/Minus'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.UnaryMinus_mw) /
                      Code_Gen_Model_ConstB.Modulus_a) *
    Code_Gen_Model_ConstB.Modulus_a;

  /* Sum: '<S114>/Minus2' incorporates:
   *  Product: '<S114>/Divide1'
   *  Product: '<S114>/Product1'
   *  Rounding: '<S114>/Fix1'
   *  Sum: '<S114>/Minus1'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.Error_Bound_f) /
                      Code_Gen_Model_ConstB.Modulus_a) *
    Code_Gen_Model_ConstB.Modulus_a;

  /* Sum: '<S112>/Sum1' incorporates:
   *  Constant: '<S110>/Constant2'
   *  Product: '<S112>/Product'
   *  Sum: '<S112>/Sum'
   *  UnitDelay: '<S112>/Unit Delay1'
   */
  rtb_Sin4 = (rtb_Minus2 - Code_Gen_Model_DW.UnitDelay1_DSTATE) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE;

  /* Sum: '<S111>/Diff' incorporates:
   *  Product: '<S110>/Product'
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
  u0 = rtb_Sin4 - Code_Gen_Model_DW.UD_DSTATE;

  /* Saturate: '<S110>/Saturation' */
  if (u0 > 1000.0) {
    u0 = 1000.0;
  } else if (u0 < -1000.0) {
    u0 = -1000.0;
  }

  /* Sum: '<S110>/Add' incorporates:
   *  Gain: '<S110>/Gain1'
   *  Saturate: '<S110>/Saturation'
   */
  rtb_Add = 0.75 * rtb_Minus2 + u0;

  /* Sum: '<S110>/Subtract' incorporates:
   *  Constant: '<S110>/Constant'
   */
  rtb_Total_Limited_l = 1.0 - rtb_Add;

  /* Sum: '<S110>/Sum2' incorporates:
   *  Gain: '<S110>/Gain2'
   *  UnitDelay: '<S110>/Unit Delay'
   */
  rtb_Modulation_Drv_Y = 0.0009 * rtb_Minus2 +
    Code_Gen_Model_DW.UnitDelay_DSTATE;

  /* Switch: '<S113>/Switch2' incorporates:
   *  Constant: '<S110>/Constant'
   *  RelationalOperator: '<S113>/LowerRelop1'
   *  Sum: '<S110>/Subtract'
   */
  if (!(rtb_Modulation_Drv_Y > 1.0 - rtb_Add)) {
    /* Switch: '<S113>/Switch' incorporates:
     *  Constant: '<S110>/Constant1'
     *  RelationalOperator: '<S113>/UpperRelop'
     *  Sum: '<S110>/Subtract1'
     */
    if (rtb_Modulation_Drv_Y < -1.0 - rtb_Add) {
      rtb_Total_Limited_l = -1.0 - rtb_Add;
    } else {
      rtb_Total_Limited_l = rtb_Modulation_Drv_Y;
    }

    /* End of Switch: '<S113>/Switch' */
  }

  /* End of Switch: '<S113>/Switch2' */

  /* Saturate: '<S110>/Saturation1' */
  if (rtb_Total_Limited_l > 0.08) {
    rtb_Modulation_Drv_Y = 0.08;
  } else if (rtb_Total_Limited_l < -0.08) {
    rtb_Modulation_Drv_Y = -0.08;
  } else {
    rtb_Modulation_Drv_Y = rtb_Total_Limited_l;
  }

  /* End of Saturate: '<S110>/Saturation1' */

  /* Switch: '<S102>/Switch' */
  if (rtb_Compare_na) {
    /* Sum: '<S110>/Add1' */
    rtb_Minus2 = rtb_Add + rtb_Modulation_Drv_Y;

    /* Saturate: '<S110>/Saturation2' */
    if (rtb_Minus2 > 1.0) {
      rtb_Minus2 = 1.0;
    } else if (rtb_Minus2 < -1.0) {
      rtb_Minus2 = -1.0;
    }

    /* End of Saturate: '<S110>/Saturation2' */

    /* DeadZone: '<S109>/Dead Zone' */
    if (rtb_Minus2 > 0.01) {
      /* Switch: '<S102>/Switch' */
      Code_Gen_Model_B.Steering_Localized_Cmd = rtb_Minus2 - 0.01;
    } else if (rtb_Minus2 >= -0.01) {
      /* Switch: '<S102>/Switch' */
      Code_Gen_Model_B.Steering_Localized_Cmd = 0.0;
    } else {
      /* Switch: '<S102>/Switch' */
      Code_Gen_Model_B.Steering_Localized_Cmd = rtb_Minus2 - -0.01;
    }

    /* End of DeadZone: '<S109>/Dead Zone' */
  } else {
    /* Switch: '<S102>/Switch' */
    Code_Gen_Model_B.Steering_Localized_Cmd = rtb_Switch2;
  }

  /* End of Switch: '<S102>/Switch' */

  /* Fcn: '<S121>/r->x' incorporates:
   *  Fcn: '<S124>/r->x'
   *  Fcn: '<S127>/r->x'
   *  Fcn: '<S130>/r->x'
   */
  rtb_Total_Limited_l = rtb_RateLimiter * cos
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S116>/Add' incorporates:
   *  Fcn: '<S121>/r->x'
   *  Fcn: '<S122>/r->x'
   */
  rtb_Sum1_m = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.Atan2_k) + rtb_Total_Limited_l;

  /* Fcn: '<S121>/theta->y' incorporates:
   *  Fcn: '<S124>/theta->y'
   *  Fcn: '<S127>/theta->y'
   *  Fcn: '<S130>/theta->y'
   */
  rtb_RateLimiter *= sin(Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S116>/Add' incorporates:
   *  Fcn: '<S121>/theta->y'
   *  Fcn: '<S122>/theta->y'
   */
  rtb_Add_m_idx_1 = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.Atan2_k) + rtb_RateLimiter;

  /* Sum: '<S117>/Add' incorporates:
   *  Fcn: '<S125>/r->x'
   *  Fcn: '<S125>/theta->y'
   */
  rtb_Add_l_idx_0 = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.Atan2) + rtb_Total_Limited_l;
  rtb_Add_l_idx_1 = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.Atan2) + rtb_RateLimiter;

  /* Sum: '<S118>/Add' incorporates:
   *  Fcn: '<S128>/r->x'
   *  Fcn: '<S128>/theta->y'
   */
  rtb_Add_da_idx_0 = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.Atan2_i) + rtb_Total_Limited_l;
  rtb_Add_da_idx_1 = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.Atan2_i) + rtb_RateLimiter;

  /* Sum: '<S119>/Add' incorporates:
   *  Fcn: '<S131>/r->x'
   *  Fcn: '<S131>/theta->y'
   */
  rtb_Add_fs_idx_0 = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.Atan2_p) + rtb_Total_Limited_l;
  rtb_Add_fs_idx_1 = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.Atan2_p) + rtb_RateLimiter;

  /* Fcn: '<S129>/x->theta' */
  Code_Gen_Model_B.Desired_Module_Angle = rt_atan2d_snf(rtb_Add_fs_idx_1,
    rtb_Add_fs_idx_0);

  /* Trigonometry: '<S98>/Cos4' incorporates:
   *  Switch: '<S83>/Angle_Switch'
   *  Trigonometry: '<S97>/Cos4'
   */
  rtb_Add_lm = cos(Code_Gen_Model_B.Desired_Module_Angle);

  /* Abs: '<S82>/Abs' incorporates:
   *  Inport: '<Root>/BackRight_Steer_Encoder'
   */
  rtb_Abs = fabs(Code_Gen_Model_U.BackRight_Steer_Encoder);
  Code_Gen_Model_ModulobyConstant(rtb_Abs, &Code_Gen_Model_B.ModulobyConstant_i);

  /* Switch: '<S82>/Switch' incorporates:
   *  Constant: '<S94>/Constant'
   *  Inport: '<Root>/BackRight_Steer_Encoder'
   *  RelationalOperator: '<S94>/Compare'
   *  UnaryMinus: '<S82>/Unary Minus'
   */
  if (Code_Gen_Model_U.BackRight_Steer_Encoder >= 0.0) {
    rtb_Total_Limited_l = Code_Gen_Model_B.ModulobyConstant_i.ModulobyConstant;
  } else {
    rtb_Total_Limited_l = -Code_Gen_Model_B.ModulobyConstant_i.ModulobyConstant;
  }

  /* Sum: '<S81>/Add' incorporates:
   *  Inport: '<Root>/BackRight_Turn_Offset'
   *  Switch: '<S82>/Switch'
   */
  rtb_Minus2 = rtb_Total_Limited_l - Code_Gen_Model_U.BackRight_Turn_Offset;

  /* Abs: '<S92>/Abs' */
  rtb_Abs_j = fabs(rtb_Minus2);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_j,
    &Code_Gen_Model_B.ModulobyConstant_l);

  /* Switch: '<S92>/Switch' incorporates:
   *  Constant: '<S93>/Constant'
   *  RelationalOperator: '<S93>/Compare'
   *  UnaryMinus: '<S92>/Unary Minus'
   */
  if (rtb_Minus2 >= 0.0) {
    rtb_Total_Limited_l = Code_Gen_Model_B.ModulobyConstant_l.ModulobyConstant;
  } else {
    rtb_Total_Limited_l = -Code_Gen_Model_B.ModulobyConstant_l.ModulobyConstant;
  }

  /* Gain: '<S81>/Gain' incorporates:
   *  Switch: '<S92>/Switch'
   */
  rtb_Minus2 = 6.2831853071795862 * rtb_Total_Limited_l;

  /* Trigonometry: '<S98>/Sin5' incorporates:
   *  UnaryMinus: '<S96>/Unary Minus'
   */
  rtb_Total_Limited_l = sin(-rtb_Minus2);

  /* Trigonometry: '<S98>/Sin4' incorporates:
   *  Switch: '<S83>/Angle_Switch'
   *  Trigonometry: '<S97>/Sin4'
   */
  rtb_Subtract_at = sin(Code_Gen_Model_B.Desired_Module_Angle);

  /* Trigonometry: '<S98>/Cos5' incorporates:
   *  UnaryMinus: '<S96>/Unary Minus'
   */
  rtb_Switch2 = cos(-rtb_Minus2);

  /* Sum: '<S98>/Subtract1' incorporates:
   *  Product: '<S98>/Product2'
   *  Product: '<S98>/Product3'
   *  Trigonometry: '<S98>/Cos4'
   *  Trigonometry: '<S98>/Sin4'
   */
  rtb_RateLimiter = rtb_Add_lm * rtb_Total_Limited_l + rtb_Subtract_at *
    rtb_Switch2;

  /* Sum: '<S98>/Subtract' incorporates:
   *  Product: '<S98>/Product'
   *  Product: '<S98>/Product1'
   *  Trigonometry: '<S98>/Cos4'
   *  Trigonometry: '<S98>/Sin4'
   */
  rtb_Add = rtb_Add_lm * rtb_Switch2 - rtb_Subtract_at * rtb_Total_Limited_l;

  /* Math: '<S98>/Hypot' */
  rtb_Hypot = rt_hypotd_snf(rtb_Add, rtb_RateLimiter);

  /* Switch: '<S98>/Switch' incorporates:
   *  Constant: '<S98>/Constant'
   *  Constant: '<S98>/Constant1'
   *  Constant: '<S99>/Constant'
   *  Product: '<S98>/Divide'
   *  Product: '<S98>/Divide1'
   *  RelationalOperator: '<S99>/Compare'
   *  Switch: '<S98>/Switch1'
   */
  if (rtb_Hypot > 1.0E-6) {
    rtb_Total_Limited_l = rtb_RateLimiter / rtb_Hypot;
    rtb_Switch2 = rtb_Add / rtb_Hypot;
  } else {
    rtb_Total_Limited_l = 0.0;
    rtb_Switch2 = 1.0;
  }

  /* End of Switch: '<S98>/Switch' */

  /* RelationalOperator: '<S95>/Compare' incorporates:
   *  Abs: '<S83>/Abs'
   *  Constant: '<S95>/Constant'
   *  Trigonometry: '<S98>/Atan1'
   */
  rtb_Compare_na = fabs(rt_atan2d_snf(rtb_Total_Limited_l, rtb_Switch2)) >
    1.5707963267948966;

  /* Switch: '<S83>/Speed_Switch' incorporates:
   *  Fcn: '<S129>/x->r'
   *  UnaryMinus: '<S83>/Unary Minus'
   */
  if (rtb_Compare_na) {
    rtb_Total_Limited_l = -rt_hypotd_snf(rtb_Add_fs_idx_0, rtb_Add_fs_idx_1);
  } else {
    rtb_Total_Limited_l = rt_hypotd_snf(rtb_Add_fs_idx_0, rtb_Add_fs_idx_1);
  }

  /* Product: '<S84>/Product2' incorporates:
   *  Constant: '<S84>/Constant'
   *  Switch: '<S83>/Speed_Switch'
   */
  rtb_Total_Limited_l *= 1530.1401357649195;

  /* Gain: '<S80>/Gain' */
  rtb_Hypot = 0.00018181818181818181 * rtb_Total_Limited_l;

  /* Sum: '<S80>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Encoder'
   */
  rtb_Total_Limited_l -= Code_Gen_Model_U.BackRight_Drive_Encoder;

  /* Sum: '<S90>/Sum1' incorporates:
   *  Constant: '<S80>/Constant2'
   *  Product: '<S90>/Product'
   *  Sum: '<S90>/Sum'
   *  UnitDelay: '<S90>/Unit Delay1'
   */
  rtb_RateLimiter = (rtb_Total_Limited_l - Code_Gen_Model_DW.UnitDelay1_DSTATE_m)
    * 0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_m;

  /* Product: '<S80>/Product' incorporates:
   *  Constant: '<S80>/Constant3'
   */
  rtb_Add = rtb_RateLimiter * 0.0005;

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
  u0 = rtb_Add - Code_Gen_Model_DW.UD_DSTATE_j;

  /* Saturate: '<S80>/Saturation' */
  if (u0 > 0.2) {
    u0 = 0.2;
  } else if (u0 < -0.2) {
    u0 = -0.2;
  }

  /* Sum: '<S80>/Add' incorporates:
   *  Gain: '<S80>/Gain1'
   *  Saturate: '<S80>/Saturation'
   */
  rtb_Add_fs_idx_0 = 0.0001 * rtb_Total_Limited_l + rtb_Hypot + u0;

  /* Sum: '<S80>/Subtract' incorporates:
   *  Constant: '<S80>/Constant'
   */
  rtb_Switch2 = 1.0 - rtb_Add_fs_idx_0;

  /* Sum: '<S80>/Sum2' incorporates:
   *  Gain: '<S80>/Gain2'
   *  UnitDelay: '<S80>/Unit Delay'
   */
  rtb_Hypot = 2.0E-5 * rtb_Total_Limited_l +
    Code_Gen_Model_DW.UnitDelay_DSTATE_c;

  /* Switch: '<S91>/Switch2' incorporates:
   *  Constant: '<S80>/Constant'
   *  RelationalOperator: '<S91>/LowerRelop1'
   *  Sum: '<S80>/Subtract'
   */
  if (!(rtb_Hypot > 1.0 - rtb_Add_fs_idx_0)) {
    /* Switch: '<S91>/Switch' incorporates:
     *  Constant: '<S80>/Constant1'
     *  RelationalOperator: '<S91>/UpperRelop'
     *  Sum: '<S80>/Subtract1'
     */
    if (rtb_Hypot < -1.0 - rtb_Add_fs_idx_0) {
      rtb_Switch2 = -1.0 - rtb_Add_fs_idx_0;
    } else {
      rtb_Switch2 = rtb_Hypot;
    }

    /* End of Switch: '<S91>/Switch' */
  }

  /* End of Switch: '<S91>/Switch2' */

  /* Saturate: '<S80>/Saturation1' */
  if (rtb_Switch2 > 0.1) {
    rtb_Hypot = 0.1;
  } else if (rtb_Switch2 < -0.1) {
    rtb_Hypot = -0.1;
  } else {
    rtb_Hypot = rtb_Switch2;
  }

  /* End of Saturate: '<S80>/Saturation1' */

  /* Sum: '<S80>/Add1' */
  u0 = rtb_Add_fs_idx_0 + rtb_Hypot;

  /* Saturate: '<S80>/Saturation2' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = u0;
  }

  /* End of Saturate: '<S80>/Saturation2' */

  /* Switch: '<S83>/Angle_Switch' */
  if (rtb_Compare_na) {
    /* Sum: '<S97>/Subtract1' incorporates:
     *  Product: '<S97>/Product2'
     *  Product: '<S97>/Product3'
     */
    rtb_Add_fs_idx_0 = rtb_Add_lm * Code_Gen_Model_ConstB.Sin5_a +
      rtb_Subtract_at * Code_Gen_Model_ConstB.Cos5_m;

    /* Sum: '<S97>/Subtract' incorporates:
     *  Product: '<S97>/Product'
     *  Product: '<S97>/Product1'
     */
    rtb_Add_fs_idx_1 = rtb_Add_lm * Code_Gen_Model_ConstB.Cos5_m -
      rtb_Subtract_at * Code_Gen_Model_ConstB.Sin5_a;

    /* Math: '<S97>/Hypot' */
    rtb_Subtract1_ok = rt_hypotd_snf(rtb_Add_fs_idx_1, rtb_Add_fs_idx_0);

    /* Switch: '<S97>/Switch1' incorporates:
     *  Constant: '<S100>/Constant'
     *  Constant: '<S97>/Constant'
     *  Constant: '<S97>/Constant1'
     *  Product: '<S97>/Divide'
     *  Product: '<S97>/Divide1'
     *  RelationalOperator: '<S100>/Compare'
     *  Switch: '<S97>/Switch'
     */
    if (rtb_Subtract1_ok > 1.0E-6) {
      rtb_Add_fs_idx_1 /= rtb_Subtract1_ok;
      rtb_Add_fs_idx_0 /= rtb_Subtract1_ok;
    } else {
      rtb_Add_fs_idx_1 = 1.0;
      rtb_Add_fs_idx_0 = 0.0;
    }

    /* End of Switch: '<S97>/Switch1' */

    /* Switch: '<S83>/Angle_Switch' incorporates:
     *  Trigonometry: '<S97>/Atan1'
     */
    Code_Gen_Model_B.Optimized_Module_Angle = rt_atan2d_snf(rtb_Add_fs_idx_0,
      rtb_Add_fs_idx_1);
  } else {
    /* Switch: '<S83>/Angle_Switch' */
    Code_Gen_Model_B.Optimized_Module_Angle =
      Code_Gen_Model_B.Desired_Module_Angle;
  }

  /* Sum: '<S79>/Sum' */
  rtb_Minus2 = Code_Gen_Model_B.Optimized_Module_Angle - rtb_Minus2;

  /* Sum: '<S88>/Subtract1' incorporates:
   *  Product: '<S88>/Divide'
   *  Product: '<S88>/Product'
   *  Rounding: '<S88>/Fix'
   *  Sum: '<S88>/Minus'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.UnaryMinus_l) /
                      Code_Gen_Model_ConstB.Modulus_m) *
    Code_Gen_Model_ConstB.Modulus_m;

  /* Sum: '<S88>/Minus2' incorporates:
   *  Product: '<S88>/Divide1'
   *  Product: '<S88>/Product1'
   *  Rounding: '<S88>/Fix1'
   *  Sum: '<S88>/Minus1'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.Error_Bound_c) /
                      Code_Gen_Model_ConstB.Modulus_m) *
    Code_Gen_Model_ConstB.Modulus_m;

  /* Sum: '<S86>/Sum1' incorporates:
   *  Constant: '<S79>/Constant2'
   *  Product: '<S86>/Product'
   *  Sum: '<S86>/Sum'
   *  UnitDelay: '<S86>/Unit Delay1'
   */
  rtb_Add_fs_idx_0 = (rtb_Minus2 - Code_Gen_Model_DW.UnitDelay1_DSTATE_k) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_k;

  /* Product: '<S79>/Product' incorporates:
   *  Constant: '<S79>/Constant3'
   */
  rtb_Subtract1_ok = rtb_Add_fs_idx_0 * 0.5;

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
  u0 = rtb_Subtract1_ok - Code_Gen_Model_DW.UD_DSTATE_l;

  /* Saturate: '<S79>/Saturation' */
  if (u0 > 0.2) {
    u0 = 0.2;
  } else if (u0 < -0.2) {
    u0 = -0.2;
  }

  /* Sum: '<S79>/Add' incorporates:
   *  Gain: '<S79>/Gain1'
   *  Saturate: '<S79>/Saturation'
   */
  rtb_Add_hu = 0.15 * rtb_Minus2 + u0;

  /* Sum: '<S79>/Subtract' incorporates:
   *  Constant: '<S79>/Constant'
   */
  rtb_Total_Limited_l = 1.0 - rtb_Add_hu;

  /* Sum: '<S79>/Sum2' incorporates:
   *  Gain: '<S79>/Gain2'
   *  UnitDelay: '<S79>/Unit Delay'
   */
  rtb_Minus2 = 0.005 * rtb_Minus2 + Code_Gen_Model_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S87>/Switch2' incorporates:
   *  Constant: '<S79>/Constant'
   *  RelationalOperator: '<S87>/LowerRelop1'
   *  Sum: '<S79>/Subtract'
   */
  if (!(rtb_Minus2 > 1.0 - rtb_Add_hu)) {
    /* Switch: '<S87>/Switch' incorporates:
     *  Constant: '<S79>/Constant1'
     *  RelationalOperator: '<S87>/UpperRelop'
     *  Sum: '<S79>/Subtract1'
     */
    if (rtb_Minus2 < -1.0 - rtb_Add_hu) {
      rtb_Total_Limited_l = -1.0 - rtb_Add_hu;
    } else {
      rtb_Total_Limited_l = rtb_Minus2;
    }

    /* End of Switch: '<S87>/Switch' */
  }

  /* End of Switch: '<S87>/Switch2' */

  /* Saturate: '<S79>/Saturation1' */
  if (rtb_Total_Limited_l > 0.005) {
    rtb_Add_fs_idx_1 = 0.005;
  } else if (rtb_Total_Limited_l < -0.005) {
    rtb_Add_fs_idx_1 = -0.005;
  } else {
    rtb_Add_fs_idx_1 = rtb_Total_Limited_l;
  }

  /* End of Saturate: '<S79>/Saturation1' */

  /* Sum: '<S79>/Add1' */
  u0 = rtb_Add_hu + rtb_Add_fs_idx_1;

  /* Saturate: '<S79>/Saturation2' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = u0;
  }

  /* End of Saturate: '<S79>/Saturation2' */

  /* Fcn: '<S126>/x->theta' */
  Code_Gen_Model_B.Desired_Module_Angle_c = rt_atan2d_snf(rtb_Add_da_idx_1,
    rtb_Add_da_idx_0);

  /* Trigonometry: '<S76>/Cos4' incorporates:
   *  Switch: '<S61>/Angle_Switch'
   *  Trigonometry: '<S75>/Cos4'
   */
  rtb_Add_lm = cos(Code_Gen_Model_B.Desired_Module_Angle_c);

  /* Abs: '<S60>/Abs' incorporates:
   *  Inport: '<Root>/BackLeft_Steer_Encoder'
   */
  rtb_Abs_g = fabs(Code_Gen_Model_U.BackLeft_Steer_Encoder);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_g,
    &Code_Gen_Model_B.ModulobyConstant_a);

  /* Switch: '<S60>/Switch' incorporates:
   *  Constant: '<S72>/Constant'
   *  Inport: '<Root>/BackLeft_Steer_Encoder'
   *  RelationalOperator: '<S72>/Compare'
   *  UnaryMinus: '<S60>/Unary Minus'
   */
  if (Code_Gen_Model_U.BackLeft_Steer_Encoder >= 0.0) {
    rtb_Total_Limited_l = Code_Gen_Model_B.ModulobyConstant_a.ModulobyConstant;
  } else {
    rtb_Total_Limited_l = -Code_Gen_Model_B.ModulobyConstant_a.ModulobyConstant;
  }

  /* Sum: '<S59>/Add' incorporates:
   *  Inport: '<Root>/BackLeft_Turn_Offset'
   *  Switch: '<S60>/Switch'
   */
  rtb_Minus2 = rtb_Total_Limited_l - Code_Gen_Model_U.BackLeft_Turn_Offset;

  /* Abs: '<S70>/Abs' */
  rtb_Abs_p = fabs(rtb_Minus2);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_p,
    &Code_Gen_Model_B.ModulobyConstant_c);

  /* Switch: '<S70>/Switch' incorporates:
   *  Constant: '<S71>/Constant'
   *  RelationalOperator: '<S71>/Compare'
   *  UnaryMinus: '<S70>/Unary Minus'
   */
  if (rtb_Minus2 >= 0.0) {
    rtb_Total_Limited_l = Code_Gen_Model_B.ModulobyConstant_c.ModulobyConstant;
  } else {
    rtb_Total_Limited_l = -Code_Gen_Model_B.ModulobyConstant_c.ModulobyConstant;
  }

  /* Gain: '<S59>/Gain' incorporates:
   *  Switch: '<S70>/Switch'
   */
  rtb_Minus2 = 6.2831853071795862 * rtb_Total_Limited_l;

  /* Trigonometry: '<S76>/Sin5' incorporates:
   *  UnaryMinus: '<S74>/Unary Minus'
   */
  rtb_Total_Limited_l = sin(-rtb_Minus2);

  /* Trigonometry: '<S76>/Sin4' incorporates:
   *  Switch: '<S61>/Angle_Switch'
   *  Trigonometry: '<S75>/Sin4'
   */
  rtb_Subtract_at = sin(Code_Gen_Model_B.Desired_Module_Angle_c);

  /* Trigonometry: '<S76>/Cos5' incorporates:
   *  UnaryMinus: '<S74>/Unary Minus'
   */
  rtb_Switch2 = cos(-rtb_Minus2);

  /* Sum: '<S76>/Subtract1' incorporates:
   *  Product: '<S76>/Product2'
   *  Product: '<S76>/Product3'
   *  Trigonometry: '<S76>/Cos4'
   *  Trigonometry: '<S76>/Sin4'
   */
  rtb_Add_hu = rtb_Add_lm * rtb_Total_Limited_l + rtb_Subtract_at * rtb_Switch2;

  /* Sum: '<S76>/Subtract' incorporates:
   *  Product: '<S76>/Product'
   *  Product: '<S76>/Product1'
   *  Trigonometry: '<S76>/Cos4'
   *  Trigonometry: '<S76>/Sin4'
   */
  rtb_Subtract_l = rtb_Add_lm * rtb_Switch2 - rtb_Subtract_at *
    rtb_Total_Limited_l;

  /* Math: '<S76>/Hypot' */
  rtb_Hypot_e = rt_hypotd_snf(rtb_Subtract_l, rtb_Add_hu);

  /* Switch: '<S76>/Switch' incorporates:
   *  Constant: '<S76>/Constant'
   *  Constant: '<S76>/Constant1'
   *  Constant: '<S77>/Constant'
   *  Product: '<S76>/Divide'
   *  Product: '<S76>/Divide1'
   *  RelationalOperator: '<S77>/Compare'
   *  Switch: '<S76>/Switch1'
   */
  if (rtb_Hypot_e > 1.0E-6) {
    rtb_Total_Limited_l = rtb_Add_hu / rtb_Hypot_e;
    rtb_Switch2 = rtb_Subtract_l / rtb_Hypot_e;
  } else {
    rtb_Total_Limited_l = 0.0;
    rtb_Switch2 = 1.0;
  }

  /* End of Switch: '<S76>/Switch' */

  /* RelationalOperator: '<S73>/Compare' incorporates:
   *  Abs: '<S61>/Abs'
   *  Constant: '<S73>/Constant'
   *  Trigonometry: '<S76>/Atan1'
   */
  rtb_Compare_na = fabs(rt_atan2d_snf(rtb_Total_Limited_l, rtb_Switch2)) >
    1.5707963267948966;

  /* Switch: '<S61>/Speed_Switch' incorporates:
   *  Fcn: '<S126>/x->r'
   *  UnaryMinus: '<S61>/Unary Minus'
   */
  if (rtb_Compare_na) {
    rtb_Total_Limited_l = -rt_hypotd_snf(rtb_Add_da_idx_0, rtb_Add_da_idx_1);
  } else {
    rtb_Total_Limited_l = rt_hypotd_snf(rtb_Add_da_idx_0, rtb_Add_da_idx_1);
  }

  /* Product: '<S62>/Product2' incorporates:
   *  Constant: '<S62>/Constant'
   *  Switch: '<S61>/Speed_Switch'
   */
  rtb_Total_Limited_l *= 1530.1401357649195;

  /* Gain: '<S58>/Gain' */
  rtb_Hypot_e = 0.00018181818181818181 * rtb_Total_Limited_l;

  /* Sum: '<S58>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Encoder'
   */
  rtb_Total_Limited_l -= Code_Gen_Model_U.BackLeft_Drive_Encoder;

  /* Sum: '<S68>/Sum1' incorporates:
   *  Constant: '<S58>/Constant2'
   *  Product: '<S68>/Product'
   *  Sum: '<S68>/Sum'
   *  UnitDelay: '<S68>/Unit Delay1'
   */
  rtb_Add_hu = (rtb_Total_Limited_l - Code_Gen_Model_DW.UnitDelay1_DSTATE_j) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S58>/Product' incorporates:
   *  Constant: '<S58>/Constant3'
   */
  rtb_Subtract_l = rtb_Add_hu * 0.0005;

  /* Sum: '<S67>/Diff' incorporates:
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
  u0 = rtb_Subtract_l - Code_Gen_Model_DW.UD_DSTATE_lp;

  /* Saturate: '<S58>/Saturation' */
  if (u0 > 0.2) {
    u0 = 0.2;
  } else if (u0 < -0.2) {
    u0 = -0.2;
  }

  /* Sum: '<S58>/Add' incorporates:
   *  Gain: '<S58>/Gain1'
   *  Saturate: '<S58>/Saturation'
   */
  rtb_Add_da_idx_0 = 0.0001 * rtb_Total_Limited_l + rtb_Hypot_e + u0;

  /* Sum: '<S58>/Subtract' incorporates:
   *  Constant: '<S58>/Constant'
   */
  rtb_Switch2 = 1.0 - rtb_Add_da_idx_0;

  /* Sum: '<S58>/Sum2' incorporates:
   *  Gain: '<S58>/Gain2'
   *  UnitDelay: '<S58>/Unit Delay'
   */
  rtb_Hypot_e = 2.0E-5 * rtb_Total_Limited_l +
    Code_Gen_Model_DW.UnitDelay_DSTATE_b;

  /* Switch: '<S69>/Switch2' incorporates:
   *  Constant: '<S58>/Constant'
   *  RelationalOperator: '<S69>/LowerRelop1'
   *  Sum: '<S58>/Subtract'
   */
  if (!(rtb_Hypot_e > 1.0 - rtb_Add_da_idx_0)) {
    /* Switch: '<S69>/Switch' incorporates:
     *  Constant: '<S58>/Constant1'
     *  RelationalOperator: '<S69>/UpperRelop'
     *  Sum: '<S58>/Subtract1'
     */
    if (rtb_Hypot_e < -1.0 - rtb_Add_da_idx_0) {
      rtb_Switch2 = -1.0 - rtb_Add_da_idx_0;
    } else {
      rtb_Switch2 = rtb_Hypot_e;
    }

    /* End of Switch: '<S69>/Switch' */
  }

  /* End of Switch: '<S69>/Switch2' */

  /* Saturate: '<S58>/Saturation1' */
  if (rtb_Switch2 > 0.1) {
    rtb_Hypot_e = 0.1;
  } else if (rtb_Switch2 < -0.1) {
    rtb_Hypot_e = -0.1;
  } else {
    rtb_Hypot_e = rtb_Switch2;
  }

  /* End of Saturate: '<S58>/Saturation1' */

  /* Sum: '<S58>/Add1' */
  u0 = rtb_Add_da_idx_0 + rtb_Hypot_e;

  /* Saturate: '<S58>/Saturation2' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = u0;
  }

  /* End of Saturate: '<S58>/Saturation2' */

  /* Switch: '<S61>/Angle_Switch' */
  if (rtb_Compare_na) {
    /* Sum: '<S75>/Subtract1' incorporates:
     *  Product: '<S75>/Product2'
     *  Product: '<S75>/Product3'
     */
    rtb_Add_da_idx_0 = rtb_Add_lm * Code_Gen_Model_ConstB.Sin5_dw +
      rtb_Subtract_at * Code_Gen_Model_ConstB.Cos5_e;

    /* Sum: '<S75>/Subtract' incorporates:
     *  Product: '<S75>/Product'
     *  Product: '<S75>/Product1'
     */
    rtb_Add_da_idx_1 = rtb_Add_lm * Code_Gen_Model_ConstB.Cos5_e -
      rtb_Subtract_at * Code_Gen_Model_ConstB.Sin5_dw;

    /* Math: '<S75>/Hypot' */
    rtb_Subtract1_hm = rt_hypotd_snf(rtb_Add_da_idx_1, rtb_Add_da_idx_0);

    /* Switch: '<S75>/Switch1' incorporates:
     *  Constant: '<S75>/Constant'
     *  Constant: '<S75>/Constant1'
     *  Constant: '<S78>/Constant'
     *  Product: '<S75>/Divide'
     *  Product: '<S75>/Divide1'
     *  RelationalOperator: '<S78>/Compare'
     *  Switch: '<S75>/Switch'
     */
    if (rtb_Subtract1_hm > 1.0E-6) {
      rtb_Add_da_idx_1 /= rtb_Subtract1_hm;
      rtb_Add_da_idx_0 /= rtb_Subtract1_hm;
    } else {
      rtb_Add_da_idx_1 = 1.0;
      rtb_Add_da_idx_0 = 0.0;
    }

    /* End of Switch: '<S75>/Switch1' */

    /* Switch: '<S61>/Angle_Switch' incorporates:
     *  Trigonometry: '<S75>/Atan1'
     */
    Code_Gen_Model_B.Optimized_Module_Angle_i = rt_atan2d_snf(rtb_Add_da_idx_0,
      rtb_Add_da_idx_1);
  } else {
    /* Switch: '<S61>/Angle_Switch' */
    Code_Gen_Model_B.Optimized_Module_Angle_i =
      Code_Gen_Model_B.Desired_Module_Angle_c;
  }

  /* Sum: '<S57>/Sum' */
  rtb_Minus2 = Code_Gen_Model_B.Optimized_Module_Angle_i - rtb_Minus2;

  /* Sum: '<S66>/Subtract1' incorporates:
   *  Product: '<S66>/Divide'
   *  Product: '<S66>/Product'
   *  Rounding: '<S66>/Fix'
   *  Sum: '<S66>/Minus'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.UnaryMinus_a) /
                      Code_Gen_Model_ConstB.Modulus_hb) *
    Code_Gen_Model_ConstB.Modulus_hb;

  /* Sum: '<S66>/Minus2' incorporates:
   *  Product: '<S66>/Divide1'
   *  Product: '<S66>/Product1'
   *  Rounding: '<S66>/Fix1'
   *  Sum: '<S66>/Minus1'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.Error_Bound_j) /
                      Code_Gen_Model_ConstB.Modulus_hb) *
    Code_Gen_Model_ConstB.Modulus_hb;

  /* Sum: '<S64>/Sum1' incorporates:
   *  Constant: '<S57>/Constant2'
   *  Product: '<S64>/Product'
   *  Sum: '<S64>/Sum'
   *  UnitDelay: '<S64>/Unit Delay1'
   */
  rtb_Add_da_idx_0 = (rtb_Minus2 - Code_Gen_Model_DW.UnitDelay1_DSTATE_a) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_a;

  /* Product: '<S57>/Product' incorporates:
   *  Constant: '<S57>/Constant3'
   */
  rtb_Subtract1_hm = rtb_Add_da_idx_0 * 0.5;

  /* Sum: '<S63>/Diff' incorporates:
   *  UnitDelay: '<S63>/UD'
   *
   * Block description for '<S63>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S63>/UD':
   *
   *  Store in Global RAM
   */
  u0 = rtb_Subtract1_hm - Code_Gen_Model_DW.UD_DSTATE_c;

  /* Saturate: '<S57>/Saturation' */
  if (u0 > 0.2) {
    u0 = 0.2;
  } else if (u0 < -0.2) {
    u0 = -0.2;
  }

  /* Sum: '<S57>/Add' incorporates:
   *  Gain: '<S57>/Gain1'
   *  Saturate: '<S57>/Saturation'
   */
  rtb_Add_lm = 0.15 * rtb_Minus2 + u0;

  /* Sum: '<S57>/Subtract' incorporates:
   *  Constant: '<S57>/Constant'
   */
  rtb_Total_Limited_l = 1.0 - rtb_Add_lm;

  /* Sum: '<S57>/Sum2' incorporates:
   *  Gain: '<S57>/Gain2'
   *  UnitDelay: '<S57>/Unit Delay'
   */
  rtb_Minus2 = 0.005 * rtb_Minus2 + Code_Gen_Model_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S65>/Switch2' incorporates:
   *  Constant: '<S57>/Constant'
   *  RelationalOperator: '<S65>/LowerRelop1'
   *  Sum: '<S57>/Subtract'
   */
  if (!(rtb_Minus2 > 1.0 - rtb_Add_lm)) {
    /* Switch: '<S65>/Switch' incorporates:
     *  Constant: '<S57>/Constant1'
     *  RelationalOperator: '<S65>/UpperRelop'
     *  Sum: '<S57>/Subtract1'
     */
    if (rtb_Minus2 < -1.0 - rtb_Add_lm) {
      rtb_Total_Limited_l = -1.0 - rtb_Add_lm;
    } else {
      rtb_Total_Limited_l = rtb_Minus2;
    }

    /* End of Switch: '<S65>/Switch' */
  }

  /* End of Switch: '<S65>/Switch2' */

  /* Saturate: '<S57>/Saturation1' */
  if (rtb_Total_Limited_l > 0.005) {
    rtb_Add_da_idx_1 = 0.005;
  } else if (rtb_Total_Limited_l < -0.005) {
    rtb_Add_da_idx_1 = -0.005;
  } else {
    rtb_Add_da_idx_1 = rtb_Total_Limited_l;
  }

  /* End of Saturate: '<S57>/Saturation1' */

  /* Sum: '<S57>/Add1' */
  u0 = rtb_Add_lm + rtb_Add_da_idx_1;

  /* Saturate: '<S57>/Saturation2' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = u0;
  }

  /* End of Saturate: '<S57>/Saturation2' */

  /* Fcn: '<S123>/x->theta' */
  Code_Gen_Model_B.Desired_Module_Angle_k = rt_atan2d_snf(rtb_Add_l_idx_1,
    rtb_Add_l_idx_0);

  /* Trigonometry: '<S54>/Cos4' incorporates:
   *  Switch: '<S39>/Angle_Switch'
   *  Trigonometry: '<S53>/Cos4'
   */
  rtb_Add_lm = cos(Code_Gen_Model_B.Desired_Module_Angle_k);

  /* Abs: '<S38>/Abs' incorporates:
   *  Inport: '<Root>/FrontRight_Steer_Encoder'
   */
  rtb_Abs_c = fabs(Code_Gen_Model_U.FrontRight_Steer_Encoder);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_c,
    &Code_Gen_Model_B.ModulobyConstant_o);

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S50>/Constant'
   *  Inport: '<Root>/FrontRight_Steer_Encoder'
   *  RelationalOperator: '<S50>/Compare'
   *  UnaryMinus: '<S38>/Unary Minus'
   */
  if (Code_Gen_Model_U.FrontRight_Steer_Encoder >= 0.0) {
    rtb_Total_Limited_l = Code_Gen_Model_B.ModulobyConstant_o.ModulobyConstant;
  } else {
    rtb_Total_Limited_l = -Code_Gen_Model_B.ModulobyConstant_o.ModulobyConstant;
  }

  /* Sum: '<S37>/Add' incorporates:
   *  Inport: '<Root>/FrontRight_Turn_Offset'
   *  Switch: '<S38>/Switch'
   */
  rtb_Minus2 = rtb_Total_Limited_l - Code_Gen_Model_U.FrontRight_Turn_Offset;

  /* Abs: '<S48>/Abs' */
  rtb_Abs_a = fabs(rtb_Minus2);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_a,
    &Code_Gen_Model_B.ModulobyConstant_f);

  /* Switch: '<S48>/Switch' incorporates:
   *  Constant: '<S49>/Constant'
   *  RelationalOperator: '<S49>/Compare'
   *  UnaryMinus: '<S48>/Unary Minus'
   */
  if (rtb_Minus2 >= 0.0) {
    rtb_Total_Limited_l = Code_Gen_Model_B.ModulobyConstant_f.ModulobyConstant;
  } else {
    rtb_Total_Limited_l = -Code_Gen_Model_B.ModulobyConstant_f.ModulobyConstant;
  }

  /* Gain: '<S37>/Gain' incorporates:
   *  Switch: '<S48>/Switch'
   */
  rtb_Minus2 = 6.2831853071795862 * rtb_Total_Limited_l;

  /* Trigonometry: '<S54>/Sin5' incorporates:
   *  UnaryMinus: '<S52>/Unary Minus'
   */
  rtb_Total_Limited_l = sin(-rtb_Minus2);

  /* Trigonometry: '<S54>/Sin4' incorporates:
   *  Switch: '<S39>/Angle_Switch'
   *  Trigonometry: '<S53>/Sin4'
   */
  rtb_Subtract_at = sin(Code_Gen_Model_B.Desired_Module_Angle_k);

  /* Trigonometry: '<S54>/Cos5' incorporates:
   *  UnaryMinus: '<S52>/Unary Minus'
   */
  rtb_Switch2 = cos(-rtb_Minus2);

  /* Sum: '<S54>/Subtract1' incorporates:
   *  Product: '<S54>/Product2'
   *  Product: '<S54>/Product3'
   *  Trigonometry: '<S54>/Cos4'
   *  Trigonometry: '<S54>/Sin4'
   */
  rtb_Subtract1_j = rtb_Add_lm * rtb_Total_Limited_l + rtb_Subtract_at *
    rtb_Switch2;

  /* Sum: '<S54>/Subtract' incorporates:
   *  Product: '<S54>/Product'
   *  Product: '<S54>/Product1'
   *  Trigonometry: '<S54>/Cos4'
   *  Trigonometry: '<S54>/Sin4'
   */
  rtb_Subtract_nk = rtb_Add_lm * rtb_Switch2 - rtb_Subtract_at *
    rtb_Total_Limited_l;

  /* Math: '<S54>/Hypot' */
  rtb_Hypot_i = rt_hypotd_snf(rtb_Subtract_nk, rtb_Subtract1_j);

  /* Switch: '<S54>/Switch' incorporates:
   *  Constant: '<S54>/Constant'
   *  Constant: '<S54>/Constant1'
   *  Constant: '<S55>/Constant'
   *  Product: '<S54>/Divide'
   *  Product: '<S54>/Divide1'
   *  RelationalOperator: '<S55>/Compare'
   *  Switch: '<S54>/Switch1'
   */
  if (rtb_Hypot_i > 1.0E-6) {
    rtb_Total_Limited_l = rtb_Subtract1_j / rtb_Hypot_i;
    rtb_Switch2 = rtb_Subtract_nk / rtb_Hypot_i;
  } else {
    rtb_Total_Limited_l = 0.0;
    rtb_Switch2 = 1.0;
  }

  /* End of Switch: '<S54>/Switch' */

  /* RelationalOperator: '<S51>/Compare' incorporates:
   *  Abs: '<S39>/Abs'
   *  Constant: '<S51>/Constant'
   *  Trigonometry: '<S54>/Atan1'
   */
  rtb_Compare_na = fabs(rt_atan2d_snf(rtb_Total_Limited_l, rtb_Switch2)) >
    1.5707963267948966;

  /* Switch: '<S39>/Speed_Switch' incorporates:
   *  Fcn: '<S123>/x->r'
   *  UnaryMinus: '<S39>/Unary Minus'
   */
  if (rtb_Compare_na) {
    rtb_Total_Limited_l = -rt_hypotd_snf(rtb_Add_l_idx_0, rtb_Add_l_idx_1);
  } else {
    rtb_Total_Limited_l = rt_hypotd_snf(rtb_Add_l_idx_0, rtb_Add_l_idx_1);
  }

  /* Product: '<S40>/Product2' incorporates:
   *  Constant: '<S40>/Constant'
   *  Switch: '<S39>/Speed_Switch'
   */
  rtb_Total_Limited_l *= 1530.1401357649195;

  /* Gain: '<S36>/Gain' */
  rtb_Hypot_i = 0.00018181818181818181 * rtb_Total_Limited_l;

  /* Sum: '<S36>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Encoder'
   */
  rtb_Total_Limited_l -= Code_Gen_Model_U.FrontRight_Drive_Encoder;

  /* Sum: '<S46>/Sum1' incorporates:
   *  Constant: '<S36>/Constant2'
   *  Product: '<S46>/Product'
   *  Sum: '<S46>/Sum'
   *  UnitDelay: '<S46>/Unit Delay1'
   */
  rtb_Subtract1_j = (rtb_Total_Limited_l - Code_Gen_Model_DW.UnitDelay1_DSTATE_c)
    * 0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_c;

  /* Product: '<S36>/Product' incorporates:
   *  Constant: '<S36>/Constant3'
   */
  rtb_Subtract_nk = rtb_Subtract1_j * 0.0005;

  /* Sum: '<S45>/Diff' incorporates:
   *  UnitDelay: '<S45>/UD'
   *
   * Block description for '<S45>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S45>/UD':
   *
   *  Store in Global RAM
   */
  u0 = rtb_Subtract_nk - Code_Gen_Model_DW.UD_DSTATE_la;

  /* Saturate: '<S36>/Saturation' */
  if (u0 > 0.2) {
    u0 = 0.2;
  } else if (u0 < -0.2) {
    u0 = -0.2;
  }

  /* Sum: '<S36>/Add' incorporates:
   *  Gain: '<S36>/Gain1'
   *  Saturate: '<S36>/Saturation'
   */
  rtb_Add_l_idx_0 = 0.0001 * rtb_Total_Limited_l + rtb_Hypot_i + u0;

  /* Sum: '<S36>/Subtract' incorporates:
   *  Constant: '<S36>/Constant'
   */
  rtb_Switch2 = 1.0 - rtb_Add_l_idx_0;

  /* Sum: '<S36>/Sum2' incorporates:
   *  Gain: '<S36>/Gain2'
   *  UnitDelay: '<S36>/Unit Delay'
   */
  rtb_Total_Limited_l = 2.0E-5 * rtb_Total_Limited_l +
    Code_Gen_Model_DW.UnitDelay_DSTATE_cd;

  /* Switch: '<S47>/Switch2' incorporates:
   *  Constant: '<S36>/Constant'
   *  RelationalOperator: '<S47>/LowerRelop1'
   *  Sum: '<S36>/Subtract'
   */
  if (!(rtb_Total_Limited_l > 1.0 - rtb_Add_l_idx_0)) {
    /* Switch: '<S47>/Switch' incorporates:
     *  Constant: '<S36>/Constant1'
     *  RelationalOperator: '<S47>/UpperRelop'
     *  Sum: '<S36>/Subtract1'
     */
    if (rtb_Total_Limited_l < -1.0 - rtb_Add_l_idx_0) {
      rtb_Switch2 = -1.0 - rtb_Add_l_idx_0;
    } else {
      rtb_Switch2 = rtb_Total_Limited_l;
    }

    /* End of Switch: '<S47>/Switch' */
  }

  /* End of Switch: '<S47>/Switch2' */

  /* Saturate: '<S36>/Saturation1' */
  if (rtb_Switch2 > 0.1) {
    rtb_Hypot_i = 0.1;
  } else if (rtb_Switch2 < -0.1) {
    rtb_Hypot_i = -0.1;
  } else {
    rtb_Hypot_i = rtb_Switch2;
  }

  /* End of Saturate: '<S36>/Saturation1' */

  /* Sum: '<S36>/Add1' */
  u0 = rtb_Add_l_idx_0 + rtb_Hypot_i;

  /* Saturate: '<S36>/Saturation2' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = u0;
  }

  /* End of Saturate: '<S36>/Saturation2' */

  /* Switch: '<S39>/Angle_Switch' */
  if (rtb_Compare_na) {
    /* Sum: '<S53>/Subtract1' incorporates:
     *  Product: '<S53>/Product2'
     *  Product: '<S53>/Product3'
     */
    rtb_Total_Limited_l = rtb_Add_lm * Code_Gen_Model_ConstB.Sin5_d +
      rtb_Subtract_at * Code_Gen_Model_ConstB.Cos5_c;

    /* Sum: '<S53>/Subtract' incorporates:
     *  Product: '<S53>/Product'
     *  Product: '<S53>/Product1'
     */
    rtb_Subtract_at = rtb_Add_lm * Code_Gen_Model_ConstB.Cos5_c -
      rtb_Subtract_at * Code_Gen_Model_ConstB.Sin5_d;

    /* Math: '<S53>/Hypot' */
    rtb_Add_lm = rt_hypotd_snf(rtb_Subtract_at, rtb_Total_Limited_l);

    /* Switch: '<S53>/Switch1' incorporates:
     *  Constant: '<S53>/Constant'
     *  Constant: '<S53>/Constant1'
     *  Constant: '<S56>/Constant'
     *  Product: '<S53>/Divide'
     *  Product: '<S53>/Divide1'
     *  RelationalOperator: '<S56>/Compare'
     *  Switch: '<S53>/Switch'
     */
    if (rtb_Add_lm > 1.0E-6) {
      rtb_Subtract_at /= rtb_Add_lm;
      rtb_Total_Limited_l /= rtb_Add_lm;
    } else {
      rtb_Subtract_at = 1.0;
      rtb_Total_Limited_l = 0.0;
    }

    /* End of Switch: '<S53>/Switch1' */

    /* Switch: '<S39>/Angle_Switch' incorporates:
     *  Trigonometry: '<S53>/Atan1'
     */
    Code_Gen_Model_B.Optimized_Module_Angle_j = rt_atan2d_snf
      (rtb_Total_Limited_l, rtb_Subtract_at);
  } else {
    /* Switch: '<S39>/Angle_Switch' */
    Code_Gen_Model_B.Optimized_Module_Angle_j =
      Code_Gen_Model_B.Desired_Module_Angle_k;
  }

  /* Sum: '<S35>/Sum' */
  rtb_Minus2 = Code_Gen_Model_B.Optimized_Module_Angle_j - rtb_Minus2;

  /* Sum: '<S44>/Subtract1' incorporates:
   *  Product: '<S44>/Divide'
   *  Product: '<S44>/Product'
   *  Rounding: '<S44>/Fix'
   *  Sum: '<S44>/Minus'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.UnaryMinus_mf) /
                      Code_Gen_Model_ConstB.Modulus_h) *
    Code_Gen_Model_ConstB.Modulus_h;

  /* Sum: '<S44>/Minus2' incorporates:
   *  Product: '<S44>/Divide1'
   *  Product: '<S44>/Product1'
   *  Rounding: '<S44>/Fix1'
   *  Sum: '<S44>/Minus1'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.Error_Bound_a) /
                      Code_Gen_Model_ConstB.Modulus_h) *
    Code_Gen_Model_ConstB.Modulus_h;

  /* Sum: '<S42>/Sum1' incorporates:
   *  Constant: '<S35>/Constant2'
   *  Product: '<S42>/Product'
   *  Sum: '<S42>/Sum'
   *  UnitDelay: '<S42>/Unit Delay1'
   */
  rtb_Add_l_idx_0 = (rtb_Minus2 - Code_Gen_Model_DW.UnitDelay1_DSTATE_jq) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_jq;

  /* Product: '<S35>/Product' incorporates:
   *  Constant: '<S35>/Constant3'
   */
  rtb_Add_l_idx_1 = rtb_Add_l_idx_0 * 0.5;

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
  u0 = rtb_Add_l_idx_1 - Code_Gen_Model_DW.UD_DSTATE_g;

  /* Saturate: '<S35>/Saturation' */
  if (u0 > 0.2) {
    u0 = 0.2;
  } else if (u0 < -0.2) {
    u0 = -0.2;
  }

  /* Sum: '<S35>/Add' incorporates:
   *  Gain: '<S35>/Gain1'
   *  Saturate: '<S35>/Saturation'
   */
  rtb_Add_lm = 0.15 * rtb_Minus2 + u0;

  /* Sum: '<S35>/Subtract' incorporates:
   *  Constant: '<S35>/Constant'
   */
  rtb_Total_Limited_l = 1.0 - rtb_Add_lm;

  /* Sum: '<S35>/Sum2' incorporates:
   *  Gain: '<S35>/Gain2'
   *  UnitDelay: '<S35>/Unit Delay'
   */
  rtb_Minus2 = 0.005 * rtb_Minus2 + Code_Gen_Model_DW.UnitDelay_DSTATE_p;

  /* Switch: '<S43>/Switch2' incorporates:
   *  Constant: '<S35>/Constant'
   *  RelationalOperator: '<S43>/LowerRelop1'
   *  Sum: '<S35>/Subtract'
   */
  if (!(rtb_Minus2 > 1.0 - rtb_Add_lm)) {
    /* Sum: '<S35>/Subtract1' incorporates:
     *  Constant: '<S35>/Constant1'
     */
    rtb_Total_Limited_l = -1.0 - rtb_Add_lm;

    /* Switch: '<S43>/Switch' incorporates:
     *  Constant: '<S35>/Constant1'
     *  RelationalOperator: '<S43>/UpperRelop'
     *  Sum: '<S35>/Subtract1'
     */
    if (!(rtb_Minus2 < -1.0 - rtb_Add_lm)) {
      rtb_Total_Limited_l = rtb_Minus2;
    }

    /* End of Switch: '<S43>/Switch' */
  }

  /* End of Switch: '<S43>/Switch2' */

  /* Saturate: '<S35>/Saturation1' */
  if (rtb_Total_Limited_l > 0.005) {
    rtb_Integral_j = 0.005;
  } else if (rtb_Total_Limited_l < -0.005) {
    rtb_Integral_j = -0.005;
  } else {
    rtb_Integral_j = rtb_Total_Limited_l;
  }

  /* End of Saturate: '<S35>/Saturation1' */

  /* Sum: '<S35>/Add1' */
  u0 = rtb_Add_lm + rtb_Integral_j;

  /* Saturate: '<S35>/Saturation2' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = u0;
  }

  /* End of Saturate: '<S35>/Saturation2' */

  /* Fcn: '<S120>/x->theta' */
  Code_Gen_Model_B.Desired_Module_Angle_cd = rt_atan2d_snf(rtb_Add_m_idx_1,
    rtb_Sum1_m);

  /* Trigonometry: '<S32>/Cos4' incorporates:
   *  Switch: '<S17>/Angle_Switch'
   *  Trigonometry: '<S31>/Cos4'
   */
  rtb_Add_lm = cos(Code_Gen_Model_B.Desired_Module_Angle_cd);

  /* Abs: '<S16>/Abs' incorporates:
   *  Inport: '<Root>/FrontLeft_Steer_Encoder'
   */
  rtb_Abs_cq = fabs(Code_Gen_Model_U.FrontLeft_Steer_Encoder);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_cq,
    &Code_Gen_Model_B.ModulobyConstant_p);

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S28>/Constant'
   *  Inport: '<Root>/FrontLeft_Steer_Encoder'
   *  RelationalOperator: '<S28>/Compare'
   *  UnaryMinus: '<S16>/Unary Minus'
   */
  if (Code_Gen_Model_U.FrontLeft_Steer_Encoder >= 0.0) {
    rtb_Total_Limited_l = Code_Gen_Model_B.ModulobyConstant_p.ModulobyConstant;
  } else {
    rtb_Total_Limited_l = -Code_Gen_Model_B.ModulobyConstant_p.ModulobyConstant;
  }

  /* Sum: '<S15>/Add' incorporates:
   *  Inport: '<Root>/FrontLeft_Turn_Offset'
   *  Switch: '<S16>/Switch'
   */
  rtb_Minus2 = rtb_Total_Limited_l - Code_Gen_Model_U.FrontLeft_Turn_Offset;

  /* Abs: '<S26>/Abs' */
  rtb_Abs_l = fabs(rtb_Minus2);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_l, &Code_Gen_Model_B.ModulobyConstant);

  /* Switch: '<S26>/Switch' incorporates:
   *  Constant: '<S27>/Constant'
   *  RelationalOperator: '<S27>/Compare'
   *  UnaryMinus: '<S26>/Unary Minus'
   */
  if (rtb_Minus2 >= 0.0) {
    rtb_Total_Limited_l = Code_Gen_Model_B.ModulobyConstant.ModulobyConstant;
  } else {
    rtb_Total_Limited_l = -Code_Gen_Model_B.ModulobyConstant.ModulobyConstant;
  }

  /* Gain: '<S15>/Gain' incorporates:
   *  Switch: '<S26>/Switch'
   */
  rtb_Minus2 = 6.2831853071795862 * rtb_Total_Limited_l;

  /* Trigonometry: '<S32>/Sin5' incorporates:
   *  UnaryMinus: '<S30>/Unary Minus'
   */
  rtb_Total_Limited_l = sin(-rtb_Minus2);

  /* Trigonometry: '<S32>/Sin4' incorporates:
   *  Switch: '<S17>/Angle_Switch'
   *  Trigonometry: '<S31>/Sin4'
   */
  rtb_Subtract_at = sin(Code_Gen_Model_B.Desired_Module_Angle_cd);

  /* Trigonometry: '<S32>/Cos5' incorporates:
   *  UnaryMinus: '<S30>/Unary Minus'
   */
  rtb_Switch2 = cos(-rtb_Minus2);

  /* Sum: '<S32>/Subtract1' incorporates:
   *  Product: '<S32>/Product2'
   *  Product: '<S32>/Product3'
   *  Trigonometry: '<S32>/Cos4'
   *  Trigonometry: '<S32>/Sin4'
   */
  rtb_Subtract1_cp = rtb_Add_lm * rtb_Total_Limited_l + rtb_Subtract_at *
    rtb_Switch2;

  /* Sum: '<S32>/Subtract' incorporates:
   *  Product: '<S32>/Product'
   *  Product: '<S32>/Product1'
   *  Trigonometry: '<S32>/Cos4'
   *  Trigonometry: '<S32>/Sin4'
   */
  rtb_Switch2 = rtb_Add_lm * rtb_Switch2 - rtb_Subtract_at * rtb_Total_Limited_l;

  /* Math: '<S32>/Hypot' */
  rtb_Hypot_a = rt_hypotd_snf(rtb_Switch2, rtb_Subtract1_cp);

  /* Switch: '<S32>/Switch' incorporates:
   *  Constant: '<S32>/Constant'
   *  Constant: '<S32>/Constant1'
   *  Constant: '<S33>/Constant'
   *  Product: '<S32>/Divide'
   *  Product: '<S32>/Divide1'
   *  RelationalOperator: '<S33>/Compare'
   *  Switch: '<S32>/Switch1'
   */
  if (rtb_Hypot_a > 1.0E-6) {
    rtb_Total_Limited_l = rtb_Subtract1_cp / rtb_Hypot_a;
    rtb_Switch2 /= rtb_Hypot_a;
  } else {
    rtb_Total_Limited_l = 0.0;
    rtb_Switch2 = 1.0;
  }

  /* End of Switch: '<S32>/Switch' */

  /* RelationalOperator: '<S29>/Compare' incorporates:
   *  Abs: '<S17>/Abs'
   *  Constant: '<S29>/Constant'
   *  Trigonometry: '<S32>/Atan1'
   */
  rtb_Compare_na = fabs(rt_atan2d_snf(rtb_Total_Limited_l, rtb_Switch2)) >
    1.5707963267948966;

  /* Switch: '<S17>/Speed_Switch' incorporates:
   *  Fcn: '<S120>/x->r'
   *  UnaryMinus: '<S17>/Unary Minus'
   */
  if (rtb_Compare_na) {
    rtb_Total_Limited_l = -rt_hypotd_snf(rtb_Sum1_m, rtb_Add_m_idx_1);
  } else {
    rtb_Total_Limited_l = rt_hypotd_snf(rtb_Sum1_m, rtb_Add_m_idx_1);
  }

  /* Product: '<S18>/Product2' incorporates:
   *  Constant: '<S18>/Constant'
   *  Switch: '<S17>/Speed_Switch'
   */
  rtb_Total_Limited_l *= 1530.1401357649195;

  /* Gain: '<S14>/Gain' */
  rtb_Switch2 = 0.00018181818181818181 * rtb_Total_Limited_l;

  /* Sum: '<S14>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Encoder'
   */
  rtb_Total_Limited_l -= Code_Gen_Model_U.FrontLeft_Drive_Encoder;

  /* Sum: '<S24>/Sum1' incorporates:
   *  Constant: '<S14>/Constant2'
   *  Product: '<S24>/Product'
   *  Sum: '<S24>/Sum'
   *  UnitDelay: '<S24>/Unit Delay1'
   */
  rtb_Subtract1_cp = (rtb_Total_Limited_l -
                      Code_Gen_Model_DW.UnitDelay1_DSTATE_e) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S14>/Product' incorporates:
   *  Constant: '<S14>/Constant3'
   */
  rtb_Hypot_a = rtb_Subtract1_cp * 0.0005;

  /* Sum: '<S23>/Diff' incorporates:
   *  UnitDelay: '<S23>/UD'
   *
   * Block description for '<S23>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S23>/UD':
   *
   *  Store in Global RAM
   */
  u0 = rtb_Hypot_a - Code_Gen_Model_DW.UD_DSTATE_ln;

  /* Saturate: '<S14>/Saturation' */
  if (u0 > 0.2) {
    u0 = 0.2;
  } else if (u0 < -0.2) {
    u0 = -0.2;
  }

  /* Sum: '<S14>/Add' incorporates:
   *  Gain: '<S14>/Gain1'
   *  Saturate: '<S14>/Saturation'
   */
  rtb_Sum1_m = 0.0001 * rtb_Total_Limited_l + rtb_Switch2 + u0;

  /* Sum: '<S14>/Subtract' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_Switch2 = 1.0 - rtb_Sum1_m;

  /* Sum: '<S14>/Sum2' incorporates:
   *  Gain: '<S14>/Gain2'
   *  UnitDelay: '<S14>/Unit Delay'
   */
  rtb_Total_Limited_l = 2.0E-5 * rtb_Total_Limited_l +
    Code_Gen_Model_DW.UnitDelay_DSTATE_j;

  /* Switch: '<S25>/Switch2' incorporates:
   *  Constant: '<S14>/Constant'
   *  RelationalOperator: '<S25>/LowerRelop1'
   *  Sum: '<S14>/Subtract'
   */
  if (!(rtb_Total_Limited_l > 1.0 - rtb_Sum1_m)) {
    /* Sum: '<S14>/Subtract1' incorporates:
     *  Constant: '<S14>/Constant1'
     */
    rtb_Switch2 = -1.0 - rtb_Sum1_m;

    /* Switch: '<S25>/Switch' incorporates:
     *  Constant: '<S14>/Constant1'
     *  RelationalOperator: '<S25>/UpperRelop'
     *  Sum: '<S14>/Subtract1'
     */
    if (!(rtb_Total_Limited_l < -1.0 - rtb_Sum1_m)) {
      rtb_Switch2 = rtb_Total_Limited_l;
    }

    /* End of Switch: '<S25>/Switch' */
  }

  /* End of Switch: '<S25>/Switch2' */

  /* Saturate: '<S14>/Saturation1' */
  if (rtb_Switch2 > 0.1) {
    rtb_Switch2 = 0.1;
  } else if (rtb_Switch2 < -0.1) {
    rtb_Switch2 = -0.1;
  }

  /* End of Saturate: '<S14>/Saturation1' */

  /* Sum: '<S14>/Add1' */
  u0 = rtb_Sum1_m + rtb_Switch2;

  /* Saturate: '<S14>/Saturation2' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = u0;
  }

  /* End of Saturate: '<S14>/Saturation2' */

  /* Switch: '<S17>/Angle_Switch' */
  if (rtb_Compare_na) {
    /* Sum: '<S31>/Subtract1' incorporates:
     *  Product: '<S31>/Product2'
     *  Product: '<S31>/Product3'
     */
    rtb_Total_Limited_l = rtb_Add_lm * Code_Gen_Model_ConstB.Sin5 +
      rtb_Subtract_at * Code_Gen_Model_ConstB.Cos5;

    /* Sum: '<S31>/Subtract' incorporates:
     *  Product: '<S31>/Product'
     *  Product: '<S31>/Product1'
     */
    rtb_Subtract_at = rtb_Add_lm * Code_Gen_Model_ConstB.Cos5 - rtb_Subtract_at *
      Code_Gen_Model_ConstB.Sin5;

    /* Math: '<S31>/Hypot' */
    rtb_Add_lm = rt_hypotd_snf(rtb_Subtract_at, rtb_Total_Limited_l);

    /* Switch: '<S31>/Switch1' incorporates:
     *  Constant: '<S31>/Constant'
     *  Constant: '<S31>/Constant1'
     *  Constant: '<S34>/Constant'
     *  Product: '<S31>/Divide'
     *  Product: '<S31>/Divide1'
     *  RelationalOperator: '<S34>/Compare'
     *  Switch: '<S31>/Switch'
     */
    if (rtb_Add_lm > 1.0E-6) {
      rtb_Subtract_at /= rtb_Add_lm;
      rtb_Total_Limited_l /= rtb_Add_lm;
    } else {
      rtb_Subtract_at = 1.0;
      rtb_Total_Limited_l = 0.0;
    }

    /* End of Switch: '<S31>/Switch1' */

    /* Switch: '<S17>/Angle_Switch' incorporates:
     *  Trigonometry: '<S31>/Atan1'
     */
    Code_Gen_Model_B.Optimized_Module_Angle_p = rt_atan2d_snf
      (rtb_Total_Limited_l, rtb_Subtract_at);
  } else {
    /* Switch: '<S17>/Angle_Switch' */
    Code_Gen_Model_B.Optimized_Module_Angle_p =
      Code_Gen_Model_B.Desired_Module_Angle_cd;
  }

  /* Sum: '<S13>/Sum' */
  rtb_Minus2 = Code_Gen_Model_B.Optimized_Module_Angle_p - rtb_Minus2;

  /* Sum: '<S22>/Subtract1' incorporates:
   *  Product: '<S22>/Divide'
   *  Product: '<S22>/Product'
   *  Rounding: '<S22>/Fix'
   *  Sum: '<S22>/Minus'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.UnaryMinus_p) /
                      Code_Gen_Model_ConstB.Modulus) *
    Code_Gen_Model_ConstB.Modulus;

  /* Sum: '<S22>/Minus2' incorporates:
   *  Product: '<S22>/Divide1'
   *  Product: '<S22>/Product1'
   *  Rounding: '<S22>/Fix1'
   *  Sum: '<S22>/Minus1'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.Error_Bound) /
                      Code_Gen_Model_ConstB.Modulus) *
    Code_Gen_Model_ConstB.Modulus;

  /* Sum: '<S20>/Sum1' incorporates:
   *  Constant: '<S13>/Constant2'
   *  Product: '<S20>/Product'
   *  Sum: '<S20>/Sum'
   *  UnitDelay: '<S20>/Unit Delay1'
   */
  rtb_Add_lm = (rtb_Minus2 - Code_Gen_Model_DW.UnitDelay1_DSTATE_o) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_o;

  /* Product: '<S13>/Product' incorporates:
   *  Constant: '<S13>/Constant3'
   */
  rtb_Subtract_at = rtb_Add_lm * 0.5;

  /* Sum: '<S19>/Diff' incorporates:
   *  UnitDelay: '<S19>/UD'
   *
   * Block description for '<S19>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S19>/UD':
   *
   *  Store in Global RAM
   */
  u0 = rtb_Subtract_at - Code_Gen_Model_DW.UD_DSTATE_f;

  /* Saturate: '<S13>/Saturation' */
  if (u0 > 0.2) {
    u0 = 0.2;
  } else if (u0 < -0.2) {
    u0 = -0.2;
  }

  /* Sum: '<S13>/Add' incorporates:
   *  Gain: '<S13>/Gain1'
   *  Saturate: '<S13>/Saturation'
   */
  rtb_Sum1_m = 0.15 * rtb_Minus2 + u0;

  /* Sum: '<S13>/Subtract' incorporates:
   *  Constant: '<S13>/Constant'
   */
  rtb_Total_Limited_l = 1.0 - rtb_Sum1_m;

  /* Sum: '<S13>/Sum2' incorporates:
   *  Gain: '<S13>/Gain2'
   *  UnitDelay: '<S13>/Unit Delay'
   */
  rtb_Minus2 = 0.005 * rtb_Minus2 + Code_Gen_Model_DW.UnitDelay_DSTATE_k0;

  /* Switch: '<S21>/Switch2' incorporates:
   *  Constant: '<S13>/Constant'
   *  RelationalOperator: '<S21>/LowerRelop1'
   *  Sum: '<S13>/Subtract'
   */
  if (!(rtb_Minus2 > 1.0 - rtb_Sum1_m)) {
    /* Sum: '<S13>/Subtract1' incorporates:
     *  Constant: '<S13>/Constant1'
     */
    rtb_Total_Limited_l = -1.0 - rtb_Sum1_m;

    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S13>/Constant1'
     *  RelationalOperator: '<S21>/UpperRelop'
     *  Sum: '<S13>/Subtract1'
     */
    if (!(rtb_Minus2 < -1.0 - rtb_Sum1_m)) {
      rtb_Total_Limited_l = rtb_Minus2;
    }

    /* End of Switch: '<S21>/Switch' */
  }

  /* End of Switch: '<S21>/Switch2' */

  /* Saturate: '<S13>/Saturation1' */
  if (rtb_Total_Limited_l > 0.005) {
    rtb_Minus2 = 0.005;
  } else if (rtb_Total_Limited_l < -0.005) {
    rtb_Minus2 = -0.005;
  } else {
    rtb_Minus2 = rtb_Total_Limited_l;
  }

  /* End of Saturate: '<S13>/Saturation1' */

  /* Sum: '<S13>/Add1' */
  u0 = rtb_Sum1_m + rtb_Minus2;

  /* Saturate: '<S13>/Saturation2' */
  if (u0 > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (u0 < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = u0;
  }

  /* End of Saturate: '<S13>/Saturation2' */

  /* Update for UnitDelay: '<S112>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE = rtb_Sin4;

  /* Update for UnitDelay: '<S111>/UD' incorporates:
   *  Product: '<S110>/Product'
   *
   * Block description for '<S111>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE = rtb_Sin4;

  /* Update for UnitDelay: '<S110>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE = rtb_Modulation_Drv_Y;

  /* Update for UnitDelay: '<S90>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_m = rtb_RateLimiter;

  /* Update for UnitDelay: '<S89>/UD'
   *
   * Block description for '<S89>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_j = rtb_Add;

  /* Update for UnitDelay: '<S80>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_c = rtb_Hypot;

  /* Update for UnitDelay: '<S86>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_k = rtb_Add_fs_idx_0;

  /* Update for UnitDelay: '<S85>/UD'
   *
   * Block description for '<S85>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_l = rtb_Subtract1_ok;

  /* Update for UnitDelay: '<S79>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_d = rtb_Add_fs_idx_1;

  /* Update for UnitDelay: '<S68>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_j = rtb_Add_hu;

  /* Update for UnitDelay: '<S67>/UD'
   *
   * Block description for '<S67>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_lp = rtb_Subtract_l;

  /* Update for UnitDelay: '<S58>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_b = rtb_Hypot_e;

  /* Update for UnitDelay: '<S64>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_a = rtb_Add_da_idx_0;

  /* Update for UnitDelay: '<S63>/UD'
   *
   * Block description for '<S63>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_c = rtb_Subtract1_hm;

  /* Update for UnitDelay: '<S57>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_k = rtb_Add_da_idx_1;

  /* Update for UnitDelay: '<S46>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_c = rtb_Subtract1_j;

  /* Update for UnitDelay: '<S45>/UD'
   *
   * Block description for '<S45>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_la = rtb_Subtract_nk;

  /* Update for UnitDelay: '<S36>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_cd = rtb_Hypot_i;

  /* Update for UnitDelay: '<S42>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_jq = rtb_Add_l_idx_0;

  /* Update for UnitDelay: '<S41>/UD'
   *
   * Block description for '<S41>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_g = rtb_Add_l_idx_1;

  /* Update for UnitDelay: '<S35>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_p = rtb_Integral_j;

  /* Update for UnitDelay: '<S24>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_e = rtb_Subtract1_cp;

  /* Update for UnitDelay: '<S23>/UD'
   *
   * Block description for '<S23>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_ln = rtb_Hypot_a;

  /* Update for UnitDelay: '<S14>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_j = rtb_Switch2;

  /* Update for UnitDelay: '<S20>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_o = rtb_Add_lm;

  /* Update for UnitDelay: '<S19>/UD'
   *
   * Block description for '<S19>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_f = rtb_Subtract_at;

  /* Update for UnitDelay: '<S13>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_k0 = rtb_Minus2;
}

/* Model initialize function */
void Code_Gen_Model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_i);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_l);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_a);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_c);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_o);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_f);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_p);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant);
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
