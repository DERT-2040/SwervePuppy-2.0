/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Thu Jun 22 19:21:42 2023
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
  /* Start for MATLABSystem: '<S144>/Modulo by Constant' */
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
}

/* Output and update for atomic system: */
void Code_Gen_Model_ModulobyConstant(real_T rtu_0,
  B_ModulobyConstant_Code_Gen_M_T *localB)
{
  real_T yTemp;

  /* MATLABSystem: '<S144>/Modulo by Constant' */
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

  /* MATLABSystem: '<S144>/Modulo by Constant' */
  localB->ModulobyConstant = yTemp;
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
  real_T rtb_Add_d_idx_0;
  real_T rtb_Add_d_idx_1;
  real_T rtb_Add_f_idx_0;
  real_T rtb_Add_f_idx_1;
  real_T rtb_Add_idx_0;
  real_T rtb_Add_idx_1;
  real_T rtb_Add_l_idx_0;
  real_T rtb_Add_l_idx_1;
  real_T rtb_Filter;
  real_T rtb_Filter_c;
  real_T rtb_Filter_fh;
  real_T rtb_Filter_h;
  real_T rtb_Filter_k;
  real_T rtb_Gyro_Error;
  real_T rtb_Hypot;
  real_T rtb_Hypot_i;
  real_T rtb_Hypot_j;
  real_T rtb_Integrator_i;
  real_T rtb_Modulation_Drv_Y;
  real_T rtb_RateLimiter;
  real_T rtb_Subtract_g;
  real_T rtb_Sum1;
  real_T rtb_Translation_Angle;
  real_T rtb_xtheta;
  boolean_T rtb_Compare_na;
  boolean_T rtb_Is_Absolute_Translation;

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtb_Hypot_j = trunc(Code_Gen_Model_U.GameState);
  if (rtIsNaN(rtb_Hypot_j) || rtIsInf(rtb_Hypot_j)) {
    rtb_Hypot_j = 0.0;
  } else {
    rtb_Hypot_j = fmod(rtb_Hypot_j, 4.294967296E+9);
  }

  switch (rtb_Hypot_j < 0.0 ? -(int32_T)(uint32_T)-rtb_Hypot_j : (int32_T)
          (uint32_T)rtb_Hypot_j) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Disabled' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    Code_Gen_Model_Disabled(&rtb_Filter_fh, &rtb_Filter_c, &rtb_Integrator_i,
      &rtb_Translation_Angle, &rtb_RateLimiter, &rtb_Is_Absolute_Translation,
      &rtb_Compare_na);

    /* End of Outputs for SubSystem: '<S1>/Disabled' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    Code_Gen_Model_Disabled(&rtb_Filter_fh, &rtb_Filter_c, &rtb_Integrator_i,
      &rtb_Translation_Angle, &rtb_RateLimiter, &rtb_Is_Absolute_Translation,
      &rtb_Compare_na);

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Teleop' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Lookup_n-D: '<S536>/Modulation_Str_X_Abs' incorporates:
     *  Inport: '<Root>/Steer_Joystick_X'
     *  Lookup_n-D: '<S536>/Modulation_Str_X_Rel'
     */
    rtb_Gyro_Error = look1_binlcpw(Code_Gen_Model_U.Steer_Joystick_X,
      Code_Gen_Model_ConstP.pooled8, Code_Gen_Model_ConstP.pooled7, 20U);

    /* Lookup_n-D: '<S536>/Modulation_Str_Y_Abs' incorporates:
     *  Inport: '<Root>/Steer_Joystick_Y'
     */
    rtb_Filter_c = look1_binlcpw(Code_Gen_Model_U.Steer_Joystick_Y,
      Code_Gen_Model_ConstP.pooled8, Code_Gen_Model_ConstP.pooled7, 20U);

    /* RelationalOperator: '<S541>/Compare' incorporates:
     *  Constant: '<S541>/Constant'
     */
    rtb_Is_Absolute_Translation = rtb_Filter_c < 0.0;

    /* Switch: '<S538>/Switch' incorporates:
     *  Constant: '<S538>/Constant'
     *  Constant: '<S538>/Constant1'
     *  Constant: '<S539>/Constant'
     *  Constant: '<S540>/Constant'
     *  Logic: '<S538>/Logical Operator'
     *  Lookup_n-D: '<S536>/Modulation_Str_X_Abs'
     *  RelationalOperator: '<S539>/Compare'
     *  RelationalOperator: '<S540>/Compare'
     *  UnitDelay: '<S538>/Unit Delay'
     */
    if (rtb_Gyro_Error < 0.0 && Code_Gen_Model_DW.UnitDelay_DSTATE >= 0.0 &&
        rtb_Is_Absolute_Translation) {
      rtb_Hypot_j = 6.2831853071795862;
    } else {
      rtb_Hypot_j = 0.0;
    }

    /* Switch: '<S538>/Switch1' incorporates:
     *  Constant: '<S538>/Constant2'
     *  Constant: '<S538>/Constant3'
     *  Constant: '<S542>/Constant'
     *  Constant: '<S543>/Constant'
     *  Logic: '<S538>/Logical Operator1'
     *  Lookup_n-D: '<S536>/Modulation_Str_X_Abs'
     *  RelationalOperator: '<S542>/Compare'
     *  RelationalOperator: '<S543>/Compare'
     *  UnitDelay: '<S538>/Unit Delay'
     */
    if (Code_Gen_Model_DW.UnitDelay_DSTATE < 0.0 && rtb_Gyro_Error >= 0.0 &&
        rtb_Is_Absolute_Translation) {
      rtb_Integrator_i = -6.2831853071795862;
    } else {
      rtb_Integrator_i = 0.0;
    }

    /* Sum: '<S538>/Sum1' incorporates:
     *  Switch: '<S538>/Switch'
     *  Switch: '<S538>/Switch1'
     *  UnitDelay: '<S538>/Unit Delay1'
     */
    rtb_Sum1 = rtb_Hypot_j + rtb_Integrator_i +
      Code_Gen_Model_DW.UnitDelay1_DSTATE;

    /* Sum: '<S538>/Sum' incorporates:
     *  Gain: '<S535>/Gain1'
     *  Inport: '<Root>/Gyro_Angle'
     */
    rtb_Filter_fh = 0.017453292519943295 * Code_Gen_Model_U.Gyro_Angle +
      rtb_Sum1;

    /* UnaryMinus: '<S536>/Unary Minus1' incorporates:
     *  Lookup_n-D: '<S536>/Modulation_Str_X_Abs'
     *  Trigonometry: '<S536>/Atan2'
     */
    rtb_Filter_c = -rt_atan2d_snf(rtb_Gyro_Error, rtb_Filter_c);

    /* Gain: '<S536>/Gain' */
    rtb_Integrator_i = -0.75 * rtb_Gyro_Error;

    /* Lookup_n-D: '<S537>/Modulation_Drv_X' incorporates:
     *  Inport: '<Root>/Drive_Joystick_X'
     */
    rtb_RateLimiter = look1_binlcpw(Code_Gen_Model_U.Drive_Joystick_X,
      Code_Gen_Model_ConstP.pooled8, Code_Gen_Model_ConstP.pooled7, 20U);

    /* Lookup_n-D: '<S537>/Modulation_Drv_Y' incorporates:
     *  Inport: '<Root>/Drive_Joystick_Y'
     */
    rtb_Modulation_Drv_Y = look1_binlcpw(Code_Gen_Model_U.Drive_Joystick_Y,
      Code_Gen_Model_ConstP.pooled8, Code_Gen_Model_ConstP.pooled7, 20U);

    /* Trigonometry: '<S537>/Atan2' */
    rtb_Translation_Angle = rt_atan2d_snf(rtb_RateLimiter, rtb_Modulation_Drv_Y);

    /* Math: '<S537>/Magnitude' */
    rtb_RateLimiter = rt_hypotd_snf(rtb_RateLimiter, rtb_Modulation_Drv_Y);

    /* RateLimiter: '<S537>/Rate Limiter' */
    rtb_Modulation_Drv_Y = rtb_RateLimiter - Code_Gen_Model_DW.PrevY;
    if (rtb_Modulation_Drv_Y > 0.018000000000000002) {
      rtb_RateLimiter = Code_Gen_Model_DW.PrevY + 0.018000000000000002;
    } else if (rtb_Modulation_Drv_Y < -19.98) {
      rtb_RateLimiter = Code_Gen_Model_DW.PrevY - 19.98;
    }

    Code_Gen_Model_DW.PrevY = rtb_RateLimiter;

    /* End of RateLimiter: '<S537>/Rate Limiter' */

    /* SignalConversion generated from: '<S5>/Is_Absolute_Translation_In' incorporates:
     *  Inport: '<Root>/Is_Absolute_Steering'
     */
    rtb_Is_Absolute_Translation = Code_Gen_Model_U.Is_Absolute_Steering;

    /* SignalConversion generated from: '<S5>/Is_Absolute_Steering_In' incorporates:
     *  Inport: '<Root>/Is_Absolute_Translation'
     */
    rtb_Compare_na = Code_Gen_Model_U.Is_Absolute_Translation;

    /* Update for UnitDelay: '<S538>/Unit Delay' incorporates:
     *  Lookup_n-D: '<S536>/Modulation_Str_X_Abs'
     */
    Code_Gen_Model_DW.UnitDelay_DSTATE = rtb_Gyro_Error;

    /* Update for UnitDelay: '<S538>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE = rtb_Sum1;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    Code_Gen_Model_Disabled(&rtb_Filter_fh, &rtb_Filter_c, &rtb_Integrator_i,
      &rtb_Translation_Angle, &rtb_RateLimiter, &rtb_Is_Absolute_Translation,
      &rtb_Compare_na);

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S73>/Constant3'
   *  Constant: '<S73>/Constant4'
   *  Gain: '<S7>/Gain1'
   *  Inport: '<Root>/Gyro_Angle'
   *  Math: '<S73>/Math Function'
   *  Sum: '<S73>/Add1'
   *  Sum: '<S73>/Add2'
   */
  if (rtb_Is_Absolute_Translation) {
    rtb_Translation_Angle = rt_modd_snf(0.017453292519943295 *
      Code_Gen_Model_U.Gyro_Angle + rtb_Translation_Angle + 3.1415926535897931,
      6.2831853071795862) - 3.1415926535897931;
  }

  /* End of Switch: '<S15>/Switch' */

  /* UnaryMinus: '<S15>/Unary Minus' */
  rtb_Translation_Angle = -rtb_Translation_Angle;

  /* Sum: '<S21>/Sum' */
  rtb_Gyro_Error = rtb_Filter_c - rtb_Filter_fh;

  /* SampleTimeMath: '<S51>/Tsamp' incorporates:
   *  Gain: '<S48>/Derivative Gain'
   *
   * About '<S51>/Tsamp':
   *  y = u * K where K = 1 / ( w * Ts )
   */
  rtb_Sum1 = 0.0025 * rtb_Gyro_Error * 50.0;

  /* Switch: '<S14>/Switch' */
  if (rtb_Compare_na) {
    /* Sum: '<S65>/Sum' incorporates:
     *  Delay: '<S49>/UD'
     *  DiscreteIntegrator: '<S56>/Integrator'
     *  Sum: '<S49>/Diff'
     */
    rtb_Filter_c = rtb_Gyro_Error + Code_Gen_Model_DW.Integrator_DSTATE +
      (rtb_Sum1 - Code_Gen_Model_DW.UD_DSTATE);

    /* DeadZone: '<S21>/Dead Zone' */
    if (rtb_Filter_c > 0.01) {
      rtb_Integrator_i = rtb_Filter_c - 0.01;
    } else if (rtb_Filter_c >= 0.0) {
      rtb_Integrator_i = 0.0;
    } else {
      rtb_Integrator_i = rtb_Filter_c;
    }

    /* End of DeadZone: '<S21>/Dead Zone' */
  }

  /* End of Switch: '<S14>/Switch' */

  /* Fcn: '<S79>/r->x' incorporates:
   *  Fcn: '<S82>/r->x'
   *  Fcn: '<S85>/r->x'
   *  Fcn: '<S88>/r->x'
   */
  rtb_Filter_c = rtb_RateLimiter * cos(rtb_Translation_Angle);

  /* Sum: '<S74>/Add' incorporates:
   *  Fcn: '<S79>/r->x'
   *  Fcn: '<S80>/r->x'
   */
  rtb_Add_idx_0 = rtb_Integrator_i * cos(Code_Gen_Model_ConstB.Atan2_k) +
    rtb_Filter_c;

  /* Fcn: '<S79>/theta->y' incorporates:
   *  Fcn: '<S82>/theta->y'
   *  Fcn: '<S85>/theta->y'
   *  Fcn: '<S88>/theta->y'
   */
  rtb_Translation_Angle = rtb_RateLimiter * sin(rtb_Translation_Angle);

  /* Sum: '<S74>/Add' incorporates:
   *  Fcn: '<S79>/theta->y'
   *  Fcn: '<S80>/theta->y'
   */
  rtb_Add_idx_1 = rtb_Integrator_i * sin(Code_Gen_Model_ConstB.Atan2_k) +
    rtb_Translation_Angle;

  /* Sum: '<S75>/Add' incorporates:
   *  Fcn: '<S83>/r->x'
   *  Fcn: '<S83>/theta->y'
   */
  rtb_Add_l_idx_0 = rtb_Integrator_i * cos(Code_Gen_Model_ConstB.Atan2) +
    rtb_Filter_c;
  rtb_Add_l_idx_1 = rtb_Integrator_i * sin(Code_Gen_Model_ConstB.Atan2) +
    rtb_Translation_Angle;

  /* Sum: '<S76>/Add' incorporates:
   *  Fcn: '<S86>/r->x'
   *  Fcn: '<S86>/theta->y'
   */
  rtb_Add_d_idx_0 = rtb_Integrator_i * cos(Code_Gen_Model_ConstB.Atan2_i) +
    rtb_Filter_c;
  rtb_Add_d_idx_1 = rtb_Integrator_i * sin(Code_Gen_Model_ConstB.Atan2_i) +
    rtb_Translation_Angle;

  /* Sum: '<S77>/Add' incorporates:
   *  Fcn: '<S89>/r->x'
   *  Fcn: '<S89>/theta->y'
   */
  rtb_Add_f_idx_0 = rtb_Integrator_i * cos(Code_Gen_Model_ConstB.Atan2_p) +
    rtb_Filter_c;
  rtb_Add_f_idx_1 = rtb_Integrator_i * sin(Code_Gen_Model_ConstB.Atan2_p) +
    rtb_Translation_Angle;

  /* Fcn: '<S87>/x->theta' */
  rtb_xtheta = rt_atan2d_snf(rtb_Add_f_idx_1, rtb_Add_f_idx_0);

  /* Trigonometry: '<S483>/Cos4' incorporates:
   *  Switch: '<S426>/Angle_Switch'
   *  Trigonometry: '<S482>/Cos4'
   */
  rtb_Translation_Angle = cos(rtb_xtheta);

  /* Abs: '<S425>/Abs' incorporates:
   *  Inport: '<Root>/BackRight_Steer_Encoder'
   */
  rtb_Abs = fabs(Code_Gen_Model_U.BackRight_Steer_Encoder);
  Code_Gen_Model_ModulobyConstant(rtb_Abs, &Code_Gen_Model_B.ModulobyConstant_i);

  /* Switch: '<S425>/Switch' incorporates:
   *  Constant: '<S479>/Constant'
   *  Inport: '<Root>/BackRight_Steer_Encoder'
   *  RelationalOperator: '<S479>/Compare'
   *  UnaryMinus: '<S425>/Unary Minus'
   */
  if (Code_Gen_Model_U.BackRight_Steer_Encoder >= 0.0) {
    rtb_Hypot_j = Code_Gen_Model_B.ModulobyConstant_i.ModulobyConstant;
  } else {
    rtb_Hypot_j = -Code_Gen_Model_B.ModulobyConstant_i.ModulobyConstant;
  }

  /* Sum: '<S424>/Add' incorporates:
   *  Inport: '<Root>/BackRight_Turn_Offset'
   *  Switch: '<S425>/Switch'
   */
  rtb_Filter_c = rtb_Hypot_j + Code_Gen_Model_U.BackRight_Turn_Offset;

  /* Abs: '<S477>/Abs' */
  rtb_Abs_j = fabs(rtb_Filter_c);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_j,
    &Code_Gen_Model_B.ModulobyConstant_l);

  /* Switch: '<S477>/Switch' incorporates:
   *  Constant: '<S478>/Constant'
   *  RelationalOperator: '<S478>/Compare'
   *  UnaryMinus: '<S477>/Unary Minus'
   */
  if (rtb_Filter_c >= 0.0) {
    rtb_Hypot_j = Code_Gen_Model_B.ModulobyConstant_l.ModulobyConstant;
  } else {
    rtb_Hypot_j = -Code_Gen_Model_B.ModulobyConstant_l.ModulobyConstant;
  }

  /* Gain: '<S424>/Gain' incorporates:
   *  Switch: '<S477>/Switch'
   */
  rtb_Filter_c = 6.2831853071795862 * rtb_Hypot_j;

  /* Trigonometry: '<S483>/Sin5' incorporates:
   *  UnaryMinus: '<S481>/Unary Minus'
   */
  rtb_Filter_fh = sin(-rtb_Filter_c);

  /* Trigonometry: '<S483>/Sin4' incorporates:
   *  Switch: '<S426>/Angle_Switch'
   *  Trigonometry: '<S482>/Sin4'
   */
  rtb_RateLimiter = sin(rtb_xtheta);

  /* Trigonometry: '<S483>/Cos5' incorporates:
   *  UnaryMinus: '<S481>/Unary Minus'
   */
  rtb_Integrator_i = cos(-rtb_Filter_c);

  /* Sum: '<S483>/Subtract1' incorporates:
   *  Product: '<S483>/Product2'
   *  Product: '<S483>/Product3'
   *  Trigonometry: '<S483>/Cos4'
   *  Trigonometry: '<S483>/Sin4'
   */
  rtb_Modulation_Drv_Y = rtb_Translation_Angle * rtb_Filter_fh + rtb_RateLimiter
    * rtb_Integrator_i;

  /* Sum: '<S483>/Subtract' incorporates:
   *  Product: '<S483>/Product'
   *  Product: '<S483>/Product1'
   *  Trigonometry: '<S483>/Cos4'
   *  Trigonometry: '<S483>/Sin4'
   */
  rtb_Integrator_i = rtb_Translation_Angle * rtb_Integrator_i - rtb_RateLimiter *
    rtb_Filter_fh;

  /* Math: '<S483>/Hypot' */
  rtb_Hypot = rt_hypotd_snf(rtb_Integrator_i, rtb_Modulation_Drv_Y);

  /* Switch: '<S483>/Switch' incorporates:
   *  Constant: '<S483>/Constant'
   *  Constant: '<S483>/Constant1'
   *  Constant: '<S484>/Constant'
   *  Product: '<S483>/Divide'
   *  Product: '<S483>/Divide1'
   *  RelationalOperator: '<S484>/Compare'
   *  Switch: '<S483>/Switch1'
   */
  if (rtb_Hypot > 1.0E-6) {
    rtb_Filter_fh = rtb_Modulation_Drv_Y / rtb_Hypot;
    rtb_Integrator_i /= rtb_Hypot;
  } else {
    rtb_Filter_fh = 0.0;
    rtb_Integrator_i = 1.0;
  }

  /* End of Switch: '<S483>/Switch' */

  /* RelationalOperator: '<S480>/Compare' incorporates:
   *  Abs: '<S426>/Abs'
   *  Constant: '<S480>/Constant'
   *  Trigonometry: '<S483>/Atan1'
   */
  rtb_Compare_na = fabs(rt_atan2d_snf(rtb_Filter_fh, rtb_Integrator_i)) >
    1.5707963267948966;

  /* Switch: '<S426>/Speed_Switch' incorporates:
   *  Fcn: '<S87>/x->r'
   *  UnaryMinus: '<S426>/Unary Minus'
   */
  if (rtb_Compare_na) {
    rtb_Hypot_j = -rt_hypotd_snf(rtb_Add_f_idx_0, rtb_Add_f_idx_1);
  } else {
    rtb_Hypot_j = rt_hypotd_snf(rtb_Add_f_idx_0, rtb_Add_f_idx_1);
  }

  /* Sum: '<S12>/Sum' incorporates:
   *  Constant: '<S427>/Gear_Ratio'
   *  Constant: '<S427>/Pi'
   *  Constant: '<S427>/Sec//Min'
   *  Constant: '<S427>/Wheel_Diameter'
   *  Inport: '<Root>/BackRight_Drive_Encoder'
   *  Product: '<S427>/Product2'
   *  Switch: '<S426>/Speed_Switch'
   */
  rtb_Filter_fh = rtb_Hypot_j * 60.0 * 8.14 / 3.1415926535897931 / 0.101600203 -
    Code_Gen_Model_U.BackRight_Drive_Encoder;

  /* Gain: '<S463>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S455>/Filter'
   *  Gain: '<S454>/Derivative Gain'
   *  Sum: '<S455>/SumD'
   */
  rtb_Integrator_i = (1.0E-6 * rtb_Filter_fh - Code_Gen_Model_DW.Filter_DSTATE) *
    100.0;

  /* Sum: '<S469>/Sum' incorporates:
   *  DiscreteIntegrator: '<S460>/Integrator'
   *  Gain: '<S465>/Proportional Gain'
   */
  rtb_Hypot_j = 0.5 * rtb_Filter_fh + Code_Gen_Model_DW.Integrator_DSTATE_j +
    rtb_Integrator_i;

  /* Saturate: '<S467>/Saturation' */
  if (rtb_Hypot_j > 5700.0) {
    rtb_Hypot_j = 5700.0;
  } else if (rtb_Hypot_j < -5700.0) {
    rtb_Hypot_j = -5700.0;
  }

  /* Outport: '<Root>/BackRight_Drive_DutyCycle' incorporates:
   *  Constant: '<S12>/NEO_Max_Speed'
   *  Product: '<S12>/Divide'
   *  Saturate: '<S467>/Saturation'
   */
  Code_Gen_Model_Y.BackRight_Drive_DutyCycle = rtb_Hypot_j / 5700.0;

  /* Gain: '<S457>/Integral Gain' */
  rtb_Modulation_Drv_Y = 0.0 * rtb_Filter_fh;

  /* Switch: '<S426>/Angle_Switch' incorporates:
   *  Trigonometry: '<S482>/Atan1'
   */
  if (rtb_Compare_na) {
    /* Sum: '<S482>/Subtract1' incorporates:
     *  Product: '<S482>/Product2'
     *  Product: '<S482>/Product3'
     */
    rtb_Filter_fh = rtb_Translation_Angle * Code_Gen_Model_ConstB.Sin5_a +
      rtb_RateLimiter * Code_Gen_Model_ConstB.Cos5_m;

    /* Sum: '<S482>/Subtract' incorporates:
     *  Product: '<S482>/Product'
     *  Product: '<S482>/Product1'
     */
    rtb_RateLimiter = rtb_Translation_Angle * Code_Gen_Model_ConstB.Cos5_m -
      rtb_RateLimiter * Code_Gen_Model_ConstB.Sin5_a;

    /* Math: '<S482>/Hypot' */
    rtb_Translation_Angle = rt_hypotd_snf(rtb_RateLimiter, rtb_Filter_fh);

    /* Switch: '<S482>/Switch1' incorporates:
     *  Constant: '<S482>/Constant'
     *  Constant: '<S482>/Constant1'
     *  Constant: '<S485>/Constant'
     *  Product: '<S482>/Divide'
     *  Product: '<S482>/Divide1'
     *  RelationalOperator: '<S485>/Compare'
     *  Switch: '<S482>/Switch'
     */
    if (rtb_Translation_Angle > 1.0E-6) {
      rtb_RateLimiter /= rtb_Translation_Angle;
      rtb_Translation_Angle = rtb_Filter_fh / rtb_Translation_Angle;
    } else {
      rtb_RateLimiter = 1.0;
      rtb_Translation_Angle = 0.0;
    }

    /* End of Switch: '<S482>/Switch1' */
    rtb_Filter_fh = rt_atan2d_snf(rtb_Translation_Angle, rtb_RateLimiter);
  } else {
    rtb_Filter_fh = rtb_xtheta;
  }

  /* Sum: '<S12>/Sum1' */
  rtb_Filter_c = rtb_Filter_fh - rtb_Filter_c;

  /* Gain: '<S520>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S512>/Filter'
   *  Gain: '<S511>/Derivative Gain'
   *  Sum: '<S512>/SumD'
   */
  rtb_Filter_fh = (1.0E-7 * rtb_Filter_c - Code_Gen_Model_DW.Filter_DSTATE_j) *
    100.0;

  /* Gain: '<S515>/Proportional Gain' incorporates:
   *  DiscreteIntegrator: '<S517>/Integrator'
   *  Sum: '<S526>/Sum'
   */
  rtb_Hypot_j = (rtb_Filter_c + Code_Gen_Model_DW.Integrator_DSTATE_d +
                 rtb_Filter_fh) * 0.1;

  /* Saturate: '<S524>/Saturation' */
  if (rtb_Hypot_j > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Hypot_j < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = rtb_Hypot_j;
  }

  /* End of Saturate: '<S524>/Saturation' */

  /* Fcn: '<S84>/x->theta' */
  rtb_Add_f_idx_0 = rt_atan2d_snf(rtb_Add_d_idx_1, rtb_Add_d_idx_0);

  /* Trigonometry: '<S372>/Cos4' incorporates:
   *  Switch: '<S315>/Angle_Switch'
   *  Trigonometry: '<S371>/Cos4'
   */
  rtb_Hypot = cos(rtb_Add_f_idx_0);

  /* Abs: '<S314>/Abs' incorporates:
   *  Inport: '<Root>/BackLeft_Steer_Encoder'
   */
  rtb_Abs_g = fabs(Code_Gen_Model_U.BackLeft_Steer_Encoder);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_g,
    &Code_Gen_Model_B.ModulobyConstant_a);

  /* Switch: '<S314>/Switch' incorporates:
   *  Constant: '<S368>/Constant'
   *  Inport: '<Root>/BackLeft_Steer_Encoder'
   *  RelationalOperator: '<S368>/Compare'
   *  UnaryMinus: '<S314>/Unary Minus'
   */
  if (Code_Gen_Model_U.BackLeft_Steer_Encoder >= 0.0) {
    rtb_Hypot_j = Code_Gen_Model_B.ModulobyConstant_a.ModulobyConstant;
  } else {
    rtb_Hypot_j = -Code_Gen_Model_B.ModulobyConstant_a.ModulobyConstant;
  }

  /* Sum: '<S313>/Add' incorporates:
   *  Inport: '<Root>/BackLeft_Turn_Offset'
   *  Switch: '<S314>/Switch'
   */
  rtb_Translation_Angle = rtb_Hypot_j + Code_Gen_Model_U.BackLeft_Turn_Offset;

  /* Abs: '<S366>/Abs' */
  rtb_Abs_p = fabs(rtb_Translation_Angle);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_p,
    &Code_Gen_Model_B.ModulobyConstant_c);

  /* Switch: '<S366>/Switch' incorporates:
   *  Constant: '<S367>/Constant'
   *  RelationalOperator: '<S367>/Compare'
   *  UnaryMinus: '<S366>/Unary Minus'
   */
  if (rtb_Translation_Angle >= 0.0) {
    rtb_Hypot_j = Code_Gen_Model_B.ModulobyConstant_c.ModulobyConstant;
  } else {
    rtb_Hypot_j = -Code_Gen_Model_B.ModulobyConstant_c.ModulobyConstant;
  }

  /* Gain: '<S313>/Gain' incorporates:
   *  Switch: '<S366>/Switch'
   */
  rtb_Translation_Angle = 6.2831853071795862 * rtb_Hypot_j;

  /* Trigonometry: '<S372>/Sin5' incorporates:
   *  UnaryMinus: '<S370>/Unary Minus'
   */
  rtb_Add_f_idx_1 = sin(-rtb_Translation_Angle);

  /* Trigonometry: '<S372>/Sin4' incorporates:
   *  Switch: '<S315>/Angle_Switch'
   *  Trigonometry: '<S371>/Sin4'
   */
  rtb_Subtract_g = sin(rtb_Add_f_idx_0);

  /* Trigonometry: '<S372>/Cos5' incorporates:
   *  UnaryMinus: '<S370>/Unary Minus'
   */
  rtb_RateLimiter = cos(-rtb_Translation_Angle);

  /* Sum: '<S372>/Subtract1' incorporates:
   *  Product: '<S372>/Product2'
   *  Product: '<S372>/Product3'
   *  Trigonometry: '<S372>/Cos4'
   *  Trigonometry: '<S372>/Sin4'
   */
  rtb_xtheta = rtb_Hypot * rtb_Add_f_idx_1 + rtb_Subtract_g * rtb_RateLimiter;

  /* Sum: '<S372>/Subtract' incorporates:
   *  Product: '<S372>/Product'
   *  Product: '<S372>/Product1'
   *  Trigonometry: '<S372>/Cos4'
   *  Trigonometry: '<S372>/Sin4'
   */
  rtb_RateLimiter = rtb_Hypot * rtb_RateLimiter - rtb_Subtract_g *
    rtb_Add_f_idx_1;

  /* Math: '<S372>/Hypot' */
  rtb_Add_f_idx_1 = rt_hypotd_snf(rtb_RateLimiter, rtb_xtheta);

  /* Switch: '<S372>/Switch' incorporates:
   *  Constant: '<S372>/Constant'
   *  Constant: '<S372>/Constant1'
   *  Constant: '<S373>/Constant'
   *  Product: '<S372>/Divide'
   *  Product: '<S372>/Divide1'
   *  RelationalOperator: '<S373>/Compare'
   *  Switch: '<S372>/Switch1'
   */
  if (rtb_Add_f_idx_1 > 1.0E-6) {
    rtb_Filter_h = rtb_xtheta / rtb_Add_f_idx_1;
    rtb_Add_f_idx_1 = rtb_RateLimiter / rtb_Add_f_idx_1;
  } else {
    rtb_Filter_h = 0.0;
    rtb_Add_f_idx_1 = 1.0;
  }

  /* End of Switch: '<S372>/Switch' */

  /* RelationalOperator: '<S369>/Compare' incorporates:
   *  Abs: '<S315>/Abs'
   *  Constant: '<S369>/Constant'
   *  Trigonometry: '<S372>/Atan1'
   */
  rtb_Compare_na = fabs(rt_atan2d_snf(rtb_Filter_h, rtb_Add_f_idx_1)) >
    1.5707963267948966;

  /* Switch: '<S315>/Speed_Switch' incorporates:
   *  Fcn: '<S84>/x->r'
   *  UnaryMinus: '<S315>/Unary Minus'
   */
  if (rtb_Compare_na) {
    rtb_Hypot_j = -rt_hypotd_snf(rtb_Add_d_idx_0, rtb_Add_d_idx_1);
  } else {
    rtb_Hypot_j = rt_hypotd_snf(rtb_Add_d_idx_0, rtb_Add_d_idx_1);
  }

  /* Sum: '<S11>/Sum' incorporates:
   *  Constant: '<S316>/Gear_Ratio'
   *  Constant: '<S316>/Pi'
   *  Constant: '<S316>/Sec//Min'
   *  Constant: '<S316>/Wheel_Diameter'
   *  Inport: '<Root>/BackLeft_Drive_Encoder'
   *  Product: '<S316>/Product2'
   *  Switch: '<S315>/Speed_Switch'
   */
  rtb_Filter_h = rtb_Hypot_j * 60.0 * 8.14 / 3.1415926535897931 / 0.101600203 -
    Code_Gen_Model_U.BackLeft_Drive_Encoder;

  /* Gain: '<S352>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S344>/Filter'
   *  Gain: '<S343>/Derivative Gain'
   *  Sum: '<S344>/SumD'
   */
  rtb_RateLimiter = (1.0E-6 * rtb_Filter_h - Code_Gen_Model_DW.Filter_DSTATE_g) *
    100.0;

  /* Sum: '<S358>/Sum' incorporates:
   *  DiscreteIntegrator: '<S349>/Integrator'
   *  Gain: '<S354>/Proportional Gain'
   */
  rtb_Hypot_j = 0.5 * rtb_Filter_h + Code_Gen_Model_DW.Integrator_DSTATE_g +
    rtb_RateLimiter;

  /* Saturate: '<S356>/Saturation' */
  if (rtb_Hypot_j > 5700.0) {
    rtb_Hypot_j = 5700.0;
  } else if (rtb_Hypot_j < -5700.0) {
    rtb_Hypot_j = -5700.0;
  }

  /* Outport: '<Root>/BackLeft_Drive_DutyCycle' incorporates:
   *  Constant: '<S11>/NEO_Max_Speed'
   *  Product: '<S11>/Divide'
   *  Saturate: '<S356>/Saturation'
   */
  Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = rtb_Hypot_j / 5700.0;

  /* Gain: '<S346>/Integral Gain' */
  rtb_xtheta = 0.0 * rtb_Filter_h;

  /* Switch: '<S315>/Angle_Switch' incorporates:
   *  Trigonometry: '<S371>/Atan1'
   */
  if (rtb_Compare_na) {
    /* Sum: '<S371>/Subtract1' incorporates:
     *  Product: '<S371>/Product2'
     *  Product: '<S371>/Product3'
     */
    rtb_Add_f_idx_0 = rtb_Hypot * Code_Gen_Model_ConstB.Sin5_dw + rtb_Subtract_g
      * Code_Gen_Model_ConstB.Cos5_e;

    /* Sum: '<S371>/Subtract' incorporates:
     *  Product: '<S371>/Product'
     *  Product: '<S371>/Product1'
     */
    rtb_Subtract_g = rtb_Hypot * Code_Gen_Model_ConstB.Cos5_e - rtb_Subtract_g *
      Code_Gen_Model_ConstB.Sin5_dw;

    /* Math: '<S371>/Hypot' */
    rtb_Hypot = rt_hypotd_snf(rtb_Subtract_g, rtb_Add_f_idx_0);

    /* Switch: '<S371>/Switch1' incorporates:
     *  Constant: '<S371>/Constant'
     *  Constant: '<S371>/Constant1'
     *  Constant: '<S374>/Constant'
     *  Product: '<S371>/Divide'
     *  Product: '<S371>/Divide1'
     *  RelationalOperator: '<S374>/Compare'
     *  Switch: '<S371>/Switch'
     */
    if (rtb_Hypot > 1.0E-6) {
      rtb_Subtract_g /= rtb_Hypot;
      rtb_Hypot = rtb_Add_f_idx_0 / rtb_Hypot;
    } else {
      rtb_Subtract_g = 1.0;
      rtb_Hypot = 0.0;
    }

    /* End of Switch: '<S371>/Switch1' */
    rtb_Filter_h = rt_atan2d_snf(rtb_Hypot, rtb_Subtract_g);
  } else {
    rtb_Filter_h = rtb_Add_f_idx_0;
  }

  /* Sum: '<S11>/Sum1' */
  rtb_Translation_Angle = rtb_Filter_h - rtb_Translation_Angle;

  /* Gain: '<S409>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S401>/Filter'
   *  Gain: '<S400>/Derivative Gain'
   *  Sum: '<S401>/SumD'
   */
  rtb_Hypot = (1.0E-7 * rtb_Translation_Angle -
               Code_Gen_Model_DW.Filter_DSTATE_o) * 100.0;

  /* Gain: '<S404>/Proportional Gain' incorporates:
   *  DiscreteIntegrator: '<S406>/Integrator'
   *  Sum: '<S415>/Sum'
   */
  rtb_Hypot_j = (rtb_Translation_Angle + Code_Gen_Model_DW.Integrator_DSTATE_k +
                 rtb_Hypot) * 0.1;

  /* Saturate: '<S413>/Saturation' */
  if (rtb_Hypot_j > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Hypot_j < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = rtb_Hypot_j;
  }

  /* End of Saturate: '<S413>/Saturation' */

  /* Gain: '<S403>/Integral Gain' */
  rtb_Subtract_g = 0.0 * rtb_Translation_Angle;

  /* Fcn: '<S81>/x->theta' */
  rtb_Add_d_idx_0 = rt_atan2d_snf(rtb_Add_l_idx_1, rtb_Add_l_idx_0);

  /* Trigonometry: '<S261>/Cos4' incorporates:
   *  Switch: '<S204>/Angle_Switch'
   *  Trigonometry: '<S260>/Cos4'
   */
  rtb_Add_f_idx_1 = cos(rtb_Add_d_idx_0);

  /* Abs: '<S203>/Abs' incorporates:
   *  Inport: '<Root>/FrontRight_Steer_Encoder'
   */
  rtb_Abs_c = fabs(Code_Gen_Model_U.FrontRight_Steer_Encoder);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_c,
    &Code_Gen_Model_B.ModulobyConstant_o);

  /* Switch: '<S203>/Switch' incorporates:
   *  Constant: '<S257>/Constant'
   *  Inport: '<Root>/FrontRight_Steer_Encoder'
   *  RelationalOperator: '<S257>/Compare'
   *  UnaryMinus: '<S203>/Unary Minus'
   */
  if (Code_Gen_Model_U.FrontRight_Steer_Encoder >= 0.0) {
    rtb_Hypot_j = Code_Gen_Model_B.ModulobyConstant_o.ModulobyConstant;
  } else {
    rtb_Hypot_j = -Code_Gen_Model_B.ModulobyConstant_o.ModulobyConstant;
  }

  /* Sum: '<S202>/Add' incorporates:
   *  Inport: '<Root>/FrontRight_Turn_Offset'
   *  Switch: '<S203>/Switch'
   */
  rtb_Translation_Angle = rtb_Hypot_j + Code_Gen_Model_U.FrontRight_Turn_Offset;

  /* Abs: '<S255>/Abs' */
  rtb_Abs_a = fabs(rtb_Translation_Angle);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_a,
    &Code_Gen_Model_B.ModulobyConstant_f);

  /* Switch: '<S255>/Switch' incorporates:
   *  Constant: '<S256>/Constant'
   *  RelationalOperator: '<S256>/Compare'
   *  UnaryMinus: '<S255>/Unary Minus'
   */
  if (rtb_Translation_Angle >= 0.0) {
    rtb_Hypot_j = Code_Gen_Model_B.ModulobyConstant_f.ModulobyConstant;
  } else {
    rtb_Hypot_j = -Code_Gen_Model_B.ModulobyConstant_f.ModulobyConstant;
  }

  /* Gain: '<S202>/Gain' incorporates:
   *  Switch: '<S255>/Switch'
   */
  rtb_Translation_Angle = 6.2831853071795862 * rtb_Hypot_j;

  /* Trigonometry: '<S261>/Sin5' incorporates:
   *  UnaryMinus: '<S259>/Unary Minus'
   */
  rtb_Filter_h = sin(-rtb_Translation_Angle);

  /* Trigonometry: '<S261>/Sin4' incorporates:
   *  Switch: '<S204>/Angle_Switch'
   *  Trigonometry: '<S260>/Sin4'
   */
  rtb_Add_d_idx_1 = sin(rtb_Add_d_idx_0);

  /* Trigonometry: '<S261>/Cos5' incorporates:
   *  UnaryMinus: '<S259>/Unary Minus'
   */
  rtb_Filter = cos(-rtb_Translation_Angle);

  /* Sum: '<S261>/Subtract1' incorporates:
   *  Product: '<S261>/Product2'
   *  Product: '<S261>/Product3'
   *  Trigonometry: '<S261>/Cos4'
   *  Trigonometry: '<S261>/Sin4'
   */
  rtb_Add_f_idx_0 = rtb_Add_f_idx_1 * rtb_Filter_h + rtb_Add_d_idx_1 *
    rtb_Filter;

  /* Sum: '<S261>/Subtract' incorporates:
   *  Product: '<S261>/Product'
   *  Product: '<S261>/Product1'
   *  Trigonometry: '<S261>/Cos4'
   *  Trigonometry: '<S261>/Sin4'
   */
  rtb_Filter_h = rtb_Add_f_idx_1 * rtb_Filter - rtb_Add_d_idx_1 * rtb_Filter_h;

  /* Math: '<S261>/Hypot' */
  rtb_Hypot_i = rt_hypotd_snf(rtb_Filter_h, rtb_Add_f_idx_0);

  /* Switch: '<S261>/Switch' incorporates:
   *  Constant: '<S261>/Constant'
   *  Constant: '<S261>/Constant1'
   *  Constant: '<S262>/Constant'
   *  Product: '<S261>/Divide'
   *  Product: '<S261>/Divide1'
   *  RelationalOperator: '<S262>/Compare'
   *  Switch: '<S261>/Switch1'
   */
  if (rtb_Hypot_i > 1.0E-6) {
    rtb_Filter = rtb_Add_f_idx_0 / rtb_Hypot_i;
    rtb_Filter_h /= rtb_Hypot_i;
  } else {
    rtb_Filter = 0.0;
    rtb_Filter_h = 1.0;
  }

  /* End of Switch: '<S261>/Switch' */

  /* RelationalOperator: '<S258>/Compare' incorporates:
   *  Abs: '<S204>/Abs'
   *  Constant: '<S258>/Constant'
   *  Trigonometry: '<S261>/Atan1'
   */
  rtb_Compare_na = fabs(rt_atan2d_snf(rtb_Filter, rtb_Filter_h)) >
    1.5707963267948966;

  /* Switch: '<S204>/Speed_Switch' incorporates:
   *  Fcn: '<S81>/x->r'
   *  UnaryMinus: '<S204>/Unary Minus'
   */
  if (rtb_Compare_na) {
    rtb_Hypot_j = -rt_hypotd_snf(rtb_Add_l_idx_0, rtb_Add_l_idx_1);
  } else {
    rtb_Hypot_j = rt_hypotd_snf(rtb_Add_l_idx_0, rtb_Add_l_idx_1);
  }

  /* Sum: '<S10>/Sum' incorporates:
   *  Constant: '<S205>/Gear_Ratio'
   *  Constant: '<S205>/Pi'
   *  Constant: '<S205>/Sec//Min'
   *  Constant: '<S205>/Wheel_Diameter'
   *  Inport: '<Root>/FrontRight_Drive_Encoder'
   *  Product: '<S205>/Product2'
   *  Switch: '<S204>/Speed_Switch'
   */
  rtb_Filter = rtb_Hypot_j * 60.0 * 8.14 / 3.1415926535897931 / 0.101600203 -
    Code_Gen_Model_U.FrontRight_Drive_Encoder;

  /* Gain: '<S241>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S233>/Filter'
   *  Gain: '<S232>/Derivative Gain'
   *  Sum: '<S233>/SumD'
   */
  rtb_Add_f_idx_0 = (1.0E-6 * rtb_Filter - Code_Gen_Model_DW.Filter_DSTATE_a) *
    100.0;

  /* Sum: '<S247>/Sum' incorporates:
   *  DiscreteIntegrator: '<S238>/Integrator'
   *  Gain: '<S243>/Proportional Gain'
   */
  rtb_Hypot_j = 0.5 * rtb_Filter + Code_Gen_Model_DW.Integrator_DSTATE_l +
    rtb_Add_f_idx_0;

  /* Saturate: '<S245>/Saturation' */
  if (rtb_Hypot_j > 5700.0) {
    rtb_Hypot_j = 5700.0;
  } else if (rtb_Hypot_j < -5700.0) {
    rtb_Hypot_j = -5700.0;
  }

  /* Outport: '<Root>/FrontRight_Drive_DutyCycle' incorporates:
   *  Constant: '<S10>/NEO_Max_Speed'
   *  Product: '<S10>/Divide'
   *  Saturate: '<S245>/Saturation'
   */
  Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = rtb_Hypot_j / 5700.0;

  /* Gain: '<S235>/Integral Gain' */
  rtb_Filter_h = 0.0 * rtb_Filter;

  /* Switch: '<S204>/Angle_Switch' incorporates:
   *  Trigonometry: '<S260>/Atan1'
   */
  if (rtb_Compare_na) {
    /* Sum: '<S260>/Subtract1' incorporates:
     *  Product: '<S260>/Product2'
     *  Product: '<S260>/Product3'
     */
    rtb_Add_d_idx_0 = rtb_Add_f_idx_1 * Code_Gen_Model_ConstB.Sin5_d +
      rtb_Add_d_idx_1 * Code_Gen_Model_ConstB.Cos5_c;

    /* Sum: '<S260>/Subtract' incorporates:
     *  Product: '<S260>/Product'
     *  Product: '<S260>/Product1'
     */
    rtb_Add_d_idx_1 = rtb_Add_f_idx_1 * Code_Gen_Model_ConstB.Cos5_c -
      rtb_Add_d_idx_1 * Code_Gen_Model_ConstB.Sin5_d;

    /* Math: '<S260>/Hypot' */
    rtb_Add_f_idx_1 = rt_hypotd_snf(rtb_Add_d_idx_1, rtb_Add_d_idx_0);

    /* Switch: '<S260>/Switch1' incorporates:
     *  Constant: '<S260>/Constant'
     *  Constant: '<S260>/Constant1'
     *  Constant: '<S263>/Constant'
     *  Product: '<S260>/Divide'
     *  Product: '<S260>/Divide1'
     *  RelationalOperator: '<S263>/Compare'
     *  Switch: '<S260>/Switch'
     */
    if (rtb_Add_f_idx_1 > 1.0E-6) {
      rtb_Add_d_idx_1 /= rtb_Add_f_idx_1;
      rtb_Add_f_idx_1 = rtb_Add_d_idx_0 / rtb_Add_f_idx_1;
    } else {
      rtb_Add_d_idx_1 = 1.0;
      rtb_Add_f_idx_1 = 0.0;
    }

    /* End of Switch: '<S260>/Switch1' */
    rtb_Filter = rt_atan2d_snf(rtb_Add_f_idx_1, rtb_Add_d_idx_1);
  } else {
    rtb_Filter = rtb_Add_d_idx_0;
  }

  /* Sum: '<S10>/Sum1' */
  rtb_Translation_Angle = rtb_Filter - rtb_Translation_Angle;

  /* Gain: '<S298>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S290>/Filter'
   *  Gain: '<S289>/Derivative Gain'
   *  Sum: '<S290>/SumD'
   */
  rtb_Add_f_idx_1 = (1.0E-7 * rtb_Translation_Angle -
                     Code_Gen_Model_DW.Filter_DSTATE_aj) * 100.0;

  /* Gain: '<S293>/Proportional Gain' incorporates:
   *  DiscreteIntegrator: '<S295>/Integrator'
   *  Sum: '<S304>/Sum'
   */
  rtb_Hypot_j = (rtb_Translation_Angle + Code_Gen_Model_DW.Integrator_DSTATE_b +
                 rtb_Add_f_idx_1) * 0.1;

  /* Saturate: '<S302>/Saturation' */
  if (rtb_Hypot_j > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Hypot_j < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = rtb_Hypot_j;
  }

  /* End of Saturate: '<S302>/Saturation' */

  /* Gain: '<S292>/Integral Gain' */
  rtb_Add_d_idx_1 = 0.0 * rtb_Translation_Angle;

  /* Fcn: '<S78>/x->theta' */
  rtb_Add_l_idx_0 = rt_atan2d_snf(rtb_Add_idx_1, rtb_Add_idx_0);

  /* Trigonometry: '<S150>/Cos4' incorporates:
   *  Switch: '<S93>/Angle_Switch'
   *  Trigonometry: '<S149>/Cos4'
   */
  rtb_Add_d_idx_0 = cos(rtb_Add_l_idx_0);

  /* Abs: '<S92>/Abs' incorporates:
   *  Inport: '<Root>/FrontLeft_Steer_Encoder'
   */
  rtb_Abs_cq = fabs(Code_Gen_Model_U.FrontLeft_Steer_Encoder);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_cq,
    &Code_Gen_Model_B.ModulobyConstant_p);

  /* Switch: '<S92>/Switch' incorporates:
   *  Constant: '<S146>/Constant'
   *  Inport: '<Root>/FrontLeft_Steer_Encoder'
   *  RelationalOperator: '<S146>/Compare'
   *  UnaryMinus: '<S92>/Unary Minus'
   */
  if (Code_Gen_Model_U.FrontLeft_Steer_Encoder >= 0.0) {
    rtb_Hypot_j = Code_Gen_Model_B.ModulobyConstant_p.ModulobyConstant;
  } else {
    rtb_Hypot_j = -Code_Gen_Model_B.ModulobyConstant_p.ModulobyConstant;
  }

  /* Sum: '<S91>/Add' incorporates:
   *  Inport: '<Root>/FrontLeft_Turn_Offset'
   *  Switch: '<S92>/Switch'
   */
  rtb_Translation_Angle = rtb_Hypot_j + Code_Gen_Model_U.FrontLeft_Turn_Offset;

  /* Abs: '<S144>/Abs' */
  rtb_Abs_l = fabs(rtb_Translation_Angle);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_l, &Code_Gen_Model_B.ModulobyConstant);

  /* Switch: '<S144>/Switch' incorporates:
   *  Constant: '<S145>/Constant'
   *  RelationalOperator: '<S145>/Compare'
   *  UnaryMinus: '<S144>/Unary Minus'
   */
  if (rtb_Translation_Angle >= 0.0) {
    rtb_Hypot_j = Code_Gen_Model_B.ModulobyConstant.ModulobyConstant;
  } else {
    rtb_Hypot_j = -Code_Gen_Model_B.ModulobyConstant.ModulobyConstant;
  }

  /* Gain: '<S91>/Gain' incorporates:
   *  Switch: '<S144>/Switch'
   */
  rtb_Translation_Angle = 6.2831853071795862 * rtb_Hypot_j;

  /* Trigonometry: '<S150>/Sin5' incorporates:
   *  UnaryMinus: '<S148>/Unary Minus'
   */
  rtb_Add_l_idx_1 = sin(-rtb_Translation_Angle);

  /* Trigonometry: '<S150>/Sin4' incorporates:
   *  Switch: '<S93>/Angle_Switch'
   *  Trigonometry: '<S149>/Sin4'
   */
  rtb_Filter = sin(rtb_Add_l_idx_0);

  /* Trigonometry: '<S150>/Cos5' incorporates:
   *  UnaryMinus: '<S148>/Unary Minus'
   */
  rtb_Filter_k = cos(-rtb_Translation_Angle);

  /* Sum: '<S150>/Subtract1' incorporates:
   *  Product: '<S150>/Product2'
   *  Product: '<S150>/Product3'
   *  Trigonometry: '<S150>/Cos4'
   *  Trigonometry: '<S150>/Sin4'
   */
  rtb_Hypot_i = rtb_Add_d_idx_0 * rtb_Add_l_idx_1 + rtb_Filter * rtb_Filter_k;

  /* Sum: '<S150>/Subtract' incorporates:
   *  Product: '<S150>/Product'
   *  Product: '<S150>/Product1'
   *  Trigonometry: '<S150>/Cos4'
   *  Trigonometry: '<S150>/Sin4'
   */
  rtb_Add_l_idx_1 = rtb_Add_d_idx_0 * rtb_Filter_k - rtb_Filter *
    rtb_Add_l_idx_1;

  /* Math: '<S150>/Hypot' */
  rtb_Hypot_j = rt_hypotd_snf(rtb_Add_l_idx_1, rtb_Hypot_i);

  /* Switch: '<S150>/Switch' incorporates:
   *  Constant: '<S150>/Constant'
   *  Constant: '<S150>/Constant1'
   *  Constant: '<S151>/Constant'
   *  Product: '<S150>/Divide'
   *  Product: '<S150>/Divide1'
   *  RelationalOperator: '<S151>/Compare'
   *  Switch: '<S150>/Switch1'
   */
  if (rtb_Hypot_j > 1.0E-6) {
    rtb_Filter_k = rtb_Hypot_i / rtb_Hypot_j;
    rtb_Add_l_idx_1 /= rtb_Hypot_j;
  } else {
    rtb_Filter_k = 0.0;
    rtb_Add_l_idx_1 = 1.0;
  }

  /* End of Switch: '<S150>/Switch' */

  /* RelationalOperator: '<S147>/Compare' incorporates:
   *  Abs: '<S93>/Abs'
   *  Constant: '<S147>/Constant'
   *  Trigonometry: '<S150>/Atan1'
   */
  rtb_Compare_na = fabs(rt_atan2d_snf(rtb_Filter_k, rtb_Add_l_idx_1)) >
    1.5707963267948966;

  /* Switch: '<S93>/Speed_Switch' incorporates:
   *  Fcn: '<S78>/x->r'
   *  UnaryMinus: '<S93>/Unary Minus'
   */
  if (rtb_Compare_na) {
    rtb_Hypot_j = -rt_hypotd_snf(rtb_Add_idx_0, rtb_Add_idx_1);
  } else {
    rtb_Hypot_j = rt_hypotd_snf(rtb_Add_idx_0, rtb_Add_idx_1);
  }

  /* Sum: '<S9>/Sum' incorporates:
   *  Constant: '<S94>/Gear_Ratio'
   *  Constant: '<S94>/Pi'
   *  Constant: '<S94>/Sec//Min'
   *  Constant: '<S94>/Wheel_Diameter'
   *  Inport: '<Root>/FrontLeft_Drive_Encoder'
   *  Product: '<S94>/Product2'
   *  Switch: '<S93>/Speed_Switch'
   */
  rtb_Filter_k = rtb_Hypot_j * 60.0 * 8.14 / 3.1415926535897931 / 0.101600203 -
    Code_Gen_Model_U.FrontLeft_Drive_Encoder;

  /* Gain: '<S130>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S122>/Filter'
   *  Gain: '<S121>/Derivative Gain'
   *  Sum: '<S122>/SumD'
   */
  rtb_Hypot_i = (1.0E-6 * rtb_Filter_k - Code_Gen_Model_DW.Filter_DSTATE_p) *
    100.0;

  /* Sum: '<S136>/Sum' incorporates:
   *  DiscreteIntegrator: '<S127>/Integrator'
   *  Gain: '<S132>/Proportional Gain'
   */
  rtb_Hypot_j = 0.5 * rtb_Filter_k + Code_Gen_Model_DW.Integrator_DSTATE_p +
    rtb_Hypot_i;

  /* Saturate: '<S134>/Saturation' */
  if (rtb_Hypot_j > 5700.0) {
    rtb_Hypot_j = 5700.0;
  } else if (rtb_Hypot_j < -5700.0) {
    rtb_Hypot_j = -5700.0;
  }

  /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' incorporates:
   *  Constant: '<S9>/NEO_Max_Speed'
   *  Product: '<S9>/Divide'
   *  Saturate: '<S134>/Saturation'
   */
  Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = rtb_Hypot_j / 5700.0;

  /* Gain: '<S124>/Integral Gain' */
  rtb_Add_l_idx_1 = 0.0 * rtb_Filter_k;

  /* Switch: '<S93>/Angle_Switch' incorporates:
   *  Trigonometry: '<S149>/Atan1'
   */
  if (rtb_Compare_na) {
    /* Sum: '<S149>/Subtract1' incorporates:
     *  Product: '<S149>/Product2'
     *  Product: '<S149>/Product3'
     */
    rtb_Add_l_idx_0 = rtb_Add_d_idx_0 * Code_Gen_Model_ConstB.Sin5 + rtb_Filter *
      Code_Gen_Model_ConstB.Cos5;

    /* Sum: '<S149>/Subtract' incorporates:
     *  Product: '<S149>/Product'
     *  Product: '<S149>/Product1'
     */
    rtb_Filter = rtb_Add_d_idx_0 * Code_Gen_Model_ConstB.Cos5 - rtb_Filter *
      Code_Gen_Model_ConstB.Sin5;

    /* Math: '<S149>/Hypot' */
    rtb_Add_d_idx_0 = rt_hypotd_snf(rtb_Filter, rtb_Add_l_idx_0);

    /* Switch: '<S149>/Switch1' incorporates:
     *  Constant: '<S149>/Constant'
     *  Constant: '<S149>/Constant1'
     *  Constant: '<S152>/Constant'
     *  Product: '<S149>/Divide'
     *  Product: '<S149>/Divide1'
     *  RelationalOperator: '<S152>/Compare'
     *  Switch: '<S149>/Switch'
     */
    if (rtb_Add_d_idx_0 > 1.0E-6) {
      rtb_Filter /= rtb_Add_d_idx_0;
      rtb_Add_d_idx_0 = rtb_Add_l_idx_0 / rtb_Add_d_idx_0;
    } else {
      rtb_Filter = 1.0;
      rtb_Add_d_idx_0 = 0.0;
    }

    /* End of Switch: '<S149>/Switch1' */
    rtb_Filter_k = rt_atan2d_snf(rtb_Add_d_idx_0, rtb_Filter);
  } else {
    rtb_Filter_k = rtb_Add_l_idx_0;
  }

  /* Sum: '<S9>/Sum1' */
  rtb_Translation_Angle = rtb_Filter_k - rtb_Translation_Angle;

  /* Gain: '<S187>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S179>/Filter'
   *  Gain: '<S178>/Derivative Gain'
   *  Sum: '<S179>/SumD'
   */
  rtb_Add_d_idx_0 = (1.0E-7 * rtb_Translation_Angle -
                     Code_Gen_Model_DW.Filter_DSTATE_l) * 100.0;

  /* Gain: '<S182>/Proportional Gain' incorporates:
   *  DiscreteIntegrator: '<S184>/Integrator'
   *  Sum: '<S193>/Sum'
   */
  rtb_Hypot_j = (rtb_Translation_Angle + Code_Gen_Model_DW.Integrator_DSTATE_jk
                 + rtb_Add_d_idx_0) * 0.1;

  /* Saturate: '<S191>/Saturation' */
  if (rtb_Hypot_j > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Hypot_j < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = rtb_Hypot_j;
  }

  /* End of Saturate: '<S191>/Saturation' */

  /* Update for DiscreteIntegrator: '<S56>/Integrator' incorporates:
   *  Gain: '<S53>/Integral Gain'
   */
  Code_Gen_Model_DW.Integrator_DSTATE += 0.02 * rtb_Gyro_Error * 0.02;

  /* Update for Delay: '<S49>/UD' */
  Code_Gen_Model_DW.UD_DSTATE = rtb_Sum1;

  /* Update for DiscreteIntegrator: '<S460>/Integrator' */
  Code_Gen_Model_DW.Integrator_DSTATE_j += rtb_Modulation_Drv_Y;

  /* Update for DiscreteIntegrator: '<S455>/Filter' */
  Code_Gen_Model_DW.Filter_DSTATE += 0.02 * rtb_Integrator_i;

  /* Update for DiscreteIntegrator: '<S512>/Filter' */
  Code_Gen_Model_DW.Filter_DSTATE_j += 0.02 * rtb_Filter_fh;

  /* Update for DiscreteIntegrator: '<S517>/Integrator' incorporates:
   *  Gain: '<S514>/Integral Gain'
   */
  Code_Gen_Model_DW.Integrator_DSTATE_d += 0.0 * rtb_Filter_c;

  /* Update for DiscreteIntegrator: '<S349>/Integrator' */
  Code_Gen_Model_DW.Integrator_DSTATE_g += rtb_xtheta;

  /* Update for DiscreteIntegrator: '<S344>/Filter' */
  Code_Gen_Model_DW.Filter_DSTATE_g += 0.02 * rtb_RateLimiter;

  /* Update for DiscreteIntegrator: '<S401>/Filter' */
  Code_Gen_Model_DW.Filter_DSTATE_o += 0.02 * rtb_Hypot;

  /* Update for DiscreteIntegrator: '<S406>/Integrator' */
  Code_Gen_Model_DW.Integrator_DSTATE_k += rtb_Subtract_g;

  /* Update for DiscreteIntegrator: '<S238>/Integrator' */
  Code_Gen_Model_DW.Integrator_DSTATE_l += rtb_Filter_h;

  /* Update for DiscreteIntegrator: '<S233>/Filter' */
  Code_Gen_Model_DW.Filter_DSTATE_a += 0.02 * rtb_Add_f_idx_0;

  /* Update for DiscreteIntegrator: '<S290>/Filter' */
  Code_Gen_Model_DW.Filter_DSTATE_aj += 0.02 * rtb_Add_f_idx_1;

  /* Update for DiscreteIntegrator: '<S295>/Integrator' */
  Code_Gen_Model_DW.Integrator_DSTATE_b += rtb_Add_d_idx_1;

  /* Update for DiscreteIntegrator: '<S127>/Integrator' */
  Code_Gen_Model_DW.Integrator_DSTATE_p += rtb_Add_l_idx_1;

  /* Update for DiscreteIntegrator: '<S122>/Filter' */
  Code_Gen_Model_DW.Filter_DSTATE_p += 0.02 * rtb_Hypot_i;

  /* Update for DiscreteIntegrator: '<S179>/Filter' */
  Code_Gen_Model_DW.Filter_DSTATE_l += 0.02 * rtb_Add_d_idx_0;

  /* Update for DiscreteIntegrator: '<S184>/Integrator' incorporates:
   *  Gain: '<S181>/Integral Gain'
   */
  Code_Gen_Model_DW.Integrator_DSTATE_jk += 0.0 * rtb_Translation_Angle;
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
