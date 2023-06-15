/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 1.24
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Thu Jun 15 09:55:47 2023
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

/*
 * Output and update for action system:
 *    '<S1>/Disabled'
 *    '<S1>/Test'
 */
void Code_Gen_Model_Disabled(real_T *rty_FrontLeft_Drive_DutyCycle, real_T
  *rty_FrontLeft_Steer_DutyCycle, real_T *rty_FrontRight_Drive_DutyCycle, real_T
  *rty_FrontRight_Steer_DutyCycle, real_T *rty_BackLeft_Drive_DutyCycle, real_T *
  rty_BackLeft_Steer_DutyCycle, real_T *rty_BackRight_Drive_DutyCycle, real_T
  *rty_BackRight_Steer_DutyCycle)
{
  /* Constant: '<S3>/Constant' */
  *rty_FrontLeft_Drive_DutyCycle = 0.0;

  /* Constant: '<S3>/Constant1' */
  *rty_FrontLeft_Steer_DutyCycle = 0.0;

  /* Constant: '<S3>/Constant2' */
  *rty_FrontRight_Drive_DutyCycle = 0.0;

  /* Constant: '<S3>/Constant3' */
  *rty_FrontRight_Steer_DutyCycle = 0.0;

  /* Constant: '<S3>/Constant4' */
  *rty_BackLeft_Drive_DutyCycle = 0.0;

  /* Constant: '<S3>/Constant5' */
  *rty_BackLeft_Steer_DutyCycle = 0.0;

  /* Constant: '<S3>/Constant6' */
  *rty_BackRight_Drive_DutyCycle = 0.0;

  /* Constant: '<S3>/Constant7' */
  *rty_BackRight_Steer_DutyCycle = 0.0;
}

/* Start for atomic system: */
void Code_Gen_ModulobyConstant_Start(DW_ModulobyConstant_Code_Gen__T *localDW)
{
  /* Start for MATLABSystem: '<S67>/Modulo by Constant' */
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
}

/* Output and update for atomic system: */
void Code_Gen_Model_ModulobyConstant(real_T rtu_0,
  B_ModulobyConstant_Code_Gen_M_T *localB)
{
  real_T yTemp;

  /* MATLABSystem: '<S67>/Modulo by Constant' */
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

  /* MATLABSystem: '<S67>/Modulo by Constant' */
  localB->ModulobyConstant = yTemp;
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
  real_T rtb_Abs;
  real_T rtb_Abs_b;
  real_T rtb_Abs_i;
  real_T rtb_Abs_m;
  real_T rtb_Abs_ba;
  real_T rtb_Abs_f;
  real_T rtb_Abs_fq;
  real_T rtb_Abs_p;
  real_T rateLimiterRate;
  real_T rtb_Add_g_idx_0;
  real_T rtb_Add_g_idx_1;
  real_T rtb_Add_idx_0;
  real_T rtb_Add_idx_1;
  real_T rtb_Add_l_idx_0;
  real_T rtb_Add_l_idx_1;
  real_T rtb_Add_o_idx_0;
  real_T rtb_Add_o_idx_1;
  real_T rtb_Filter;
  real_T rtb_Filter_n;
  real_T rtb_Filter_o;
  real_T rtb_Filter_oh;
  real_T rtb_Gain1;
  real_T rtb_Hypot;
  real_T rtb_Hypot_m;
  real_T rtb_Hypot_o;
  real_T rtb_Integrator_be;
  real_T rtb_Integrator_d;
  real_T rtb_Integrator_i;
  real_T rtb_Subtract1;
  real_T rtb_Subtract_g;
  real_T rtb_Sum1;
  real_T rtb_Sum1_h;
  real_T rtb_Tsamp;
  real_T rtb_xtheta;
  boolean_T rtb_Compare_g;

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Inport: '<Root>/GameState'
   */
  rtb_Hypot_m = trunc(Code_Gen_Model_U.GameState);
  if (rtIsNaN(rtb_Hypot_m) || rtIsInf(rtb_Hypot_m)) {
    rtb_Hypot_m = 0.0;
  } else {
    rtb_Hypot_m = fmod(rtb_Hypot_m, 4.294967296E+9);
  }

  switch (rtb_Hypot_m < 0.0 ? -(int32_T)(uint32_T)-rtb_Hypot_m : (int32_T)
          (uint32_T)rtb_Hypot_m) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Disabled' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' incorporates:
     *  Outport: '<Root>/BackLeft_Drive_DutyCycle'
     *  Outport: '<Root>/BackLeft_Steer_DutyCycle'
     *  Outport: '<Root>/BackRight_Drive_DutyCycle'
     *  Outport: '<Root>/FrontLeft_Drive_DutyCycle'
     *  Outport: '<Root>/FrontLeft_Steer_DutyCycle'
     *  Outport: '<Root>/FrontRight_Drive_DutyCycle'
     *  Outport: '<Root>/FrontRight_Steer_DutyCycle'
     */
    Code_Gen_Model_Disabled(&Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle,
      &Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle,
      &Code_Gen_Model_Y.FrontRight_Drive_DutyCycle,
      &Code_Gen_Model_Y.FrontRight_Steer_DutyCycle,
      &Code_Gen_Model_Y.BackLeft_Drive_DutyCycle,
      &Code_Gen_Model_Y.BackLeft_Steer_DutyCycle,
      &Code_Gen_Model_Y.BackRight_Drive_DutyCycle,
      &Code_Gen_Model_Y.BackRight_Steer_DutyCycle);

    /* End of Outputs for SubSystem: '<S1>/Disabled' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' incorporates:
     *  Constant: '<S2>/Constant'
     */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = 0.0;

    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' incorporates:
     *  Constant: '<S2>/Constant7'
     */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = 0.0;

    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' incorporates:
     *  Constant: '<S2>/Constant1'
     */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = 0.0;

    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' incorporates:
     *  Constant: '<S2>/Constant2'
     */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = 0.0;

    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' incorporates:
     *  Constant: '<S2>/Constant3'
     */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = 0.0;

    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' incorporates:
     *  Constant: '<S2>/Constant4'
     */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = 0.0;

    /* Outport: '<Root>/BackRight_Drive_DutyCycle' incorporates:
     *  Constant: '<S2>/Constant5'
     */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = 0.0;

    /* Outport: '<Root>/BackRight_Steer_DutyCycle' incorporates:
     *  Constant: '<S2>/Constant6'
     */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = 0.0;

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Teleop' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Lookup_n-D: '<S460>/Modulation_Drv_X' incorporates:
     *  Inport: '<Root>/Drive_Joystick_X'
     */
    rtb_Integrator_i = look1_binlcpw(Code_Gen_Model_U.Drive_Joystick_X,
      Code_Gen_Model_ConstP.pooled6, Code_Gen_Model_ConstP.pooled5, 20U);

    /* Lookup_n-D: '<S460>/Modulation_Drv_Y' incorporates:
     *  Inport: '<Root>/Drive_Joystick_Y'
     */
    rtb_Sum1_h = look1_binlcpw(Code_Gen_Model_U.Drive_Joystick_Y,
      Code_Gen_Model_ConstP.pooled6, Code_Gen_Model_ConstP.pooled5, 20U);

    /* Math: '<S460>/Magnitude' */
    rtb_Integrator_d = rt_hypotd_snf(rtb_Integrator_i, rtb_Sum1_h);

    /* RateLimiter: '<S460>/Rate Limiter' */
    rateLimiterRate = rtb_Integrator_d - Code_Gen_Model_DW.PrevY;
    if (rateLimiterRate > 0.018000000000000002) {
      rtb_Integrator_d = Code_Gen_Model_DW.PrevY + 0.018000000000000002;
    } else if (rateLimiterRate < -19.98) {
      rtb_Integrator_d = Code_Gen_Model_DW.PrevY - 19.98;
    }

    Code_Gen_Model_DW.PrevY = rtb_Integrator_d;

    /* End of RateLimiter: '<S460>/Rate Limiter' */

    /* Gain: '<S457>/Gain1' incorporates:
     *  Inport: '<Root>/Gyro_Angle'
     */
    rtb_Gain1 = 0.017453292519943295 * Code_Gen_Model_U.Gyro_Angle;

    /* Switch: '<S460>/Switch' incorporates:
     *  Constant: '<S524>/Constant3'
     *  Constant: '<S524>/Constant4'
     *  Inport: '<Root>/Is_Absolute_Translation'
     *  Math: '<S524>/Math Function'
     *  Sum: '<S524>/Add1'
     *  Sum: '<S524>/Add2'
     *  Trigonometry: '<S460>/Atan2'
     */
    if (Code_Gen_Model_U.Is_Absolute_Translation) {
      rtb_Sum1_h = rt_modd_snf(rt_atan2d_snf(rtb_Integrator_i, rtb_Sum1_h) +
        rtb_Gain1 + 3.1415926535897931, 6.2831853071795862) - 3.1415926535897931;
    } else {
      rtb_Sum1_h = rt_atan2d_snf(rtb_Integrator_i, rtb_Sum1_h);
    }

    /* End of Switch: '<S460>/Switch' */

    /* Lookup_n-D: '<S459>/Modulation_Str_X_Abs' incorporates:
     *  Inport: '<Root>/Steer_Joystick_X'
     *  Lookup_n-D: '<S459>/Modulation_Str_X_Rel'
     *  Switch: '<S459>/Switch'
     */
    rateLimiterRate = look1_binlcpw(Code_Gen_Model_U.Steer_Joystick_X,
      Code_Gen_Model_ConstP.pooled6, Code_Gen_Model_ConstP.pooled5, 20U);

    /* Lookup_n-D: '<S459>/Modulation_Str_Y_Abs' incorporates:
     *  Inport: '<Root>/Steer_Joystick_Y'
     */
    rtb_Integrator_be = look1_binlcpw(Code_Gen_Model_U.Steer_Joystick_Y,
      Code_Gen_Model_ConstP.pooled6, Code_Gen_Model_ConstP.pooled5, 20U);

    /* RelationalOperator: '<S470>/Compare' incorporates:
     *  Constant: '<S470>/Constant'
     */
    rtb_Compare_g = rtb_Integrator_be < 0.0;

    /* Switch: '<S466>/Switch' incorporates:
     *  Constant: '<S466>/Constant'
     *  Constant: '<S466>/Constant1'
     *  Constant: '<S468>/Constant'
     *  Constant: '<S469>/Constant'
     *  Logic: '<S466>/Logical Operator'
     *  Lookup_n-D: '<S459>/Modulation_Str_X_Abs'
     *  RelationalOperator: '<S468>/Compare'
     *  RelationalOperator: '<S469>/Compare'
     *  UnitDelay: '<S466>/Unit Delay'
     */
    if (rateLimiterRate < 0.0 && Code_Gen_Model_DW.UnitDelay_DSTATE >= 0.0 &&
        rtb_Compare_g) {
      rtb_Hypot_m = 6.2831853071795862;
    } else {
      rtb_Hypot_m = 0.0;
    }

    /* Switch: '<S466>/Switch1' incorporates:
     *  Constant: '<S466>/Constant2'
     *  Constant: '<S466>/Constant3'
     *  Constant: '<S471>/Constant'
     *  Constant: '<S472>/Constant'
     *  Logic: '<S466>/Logical Operator1'
     *  Lookup_n-D: '<S459>/Modulation_Str_X_Abs'
     *  RelationalOperator: '<S471>/Compare'
     *  RelationalOperator: '<S472>/Compare'
     *  UnitDelay: '<S466>/Unit Delay'
     */
    if (Code_Gen_Model_DW.UnitDelay_DSTATE < 0.0 && rateLimiterRate >= 0.0 &&
        rtb_Compare_g) {
      rtb_Sum1 = -6.2831853071795862;
    } else {
      rtb_Sum1 = 0.0;
    }

    /* Sum: '<S466>/Sum1' incorporates:
     *  Switch: '<S466>/Switch'
     *  Switch: '<S466>/Switch1'
     *  UnitDelay: '<S466>/Unit Delay1'
     */
    rtb_Sum1 = rtb_Hypot_m + rtb_Sum1 + Code_Gen_Model_DW.UnitDelay1_DSTATE;

    /* Sum: '<S467>/Sum' incorporates:
     *  Lookup_n-D: '<S459>/Modulation_Str_X_Abs'
     *  Sum: '<S466>/Sum'
     *  Trigonometry: '<S459>/Atan2'
     *  UnaryMinus: '<S459>/Unary Minus1'
     */
    rtb_Gain1 = -rt_atan2d_snf(rateLimiterRate, rtb_Integrator_be) - (rtb_Gain1
      + rtb_Sum1);

    /* SampleTimeMath: '<S502>/Tsamp' incorporates:
     *  Gain: '<S499>/Derivative Gain'
     *
     * About '<S502>/Tsamp':
     *  y = u * K where K = 1 / ( w * Ts )
     */
    rtb_Tsamp = 0.0025 * rtb_Gain1 * 50.0;

    /* Switch: '<S459>/Switch' incorporates:
     *  Gain: '<S459>/Gain'
     *  Inport: '<Root>/Is_Absolute_Steering'
     */
    if (Code_Gen_Model_U.Is_Absolute_Steering) {
      /* Sum: '<S516>/Sum' incorporates:
       *  Delay: '<S500>/UD'
       *  DiscreteIntegrator: '<S507>/Integrator'
       *  Sum: '<S500>/Diff'
       */
      rtb_Integrator_be = rtb_Gain1 + Code_Gen_Model_DW.Integrator_DSTATE +
        (rtb_Tsamp - Code_Gen_Model_DW.UD_DSTATE);

      /* DeadZone: '<S467>/Dead Zone' */
      if (rtb_Integrator_be > 0.01) {
        rtb_Filter_o = rtb_Integrator_be - 0.01;
      } else if (rtb_Integrator_be >= 0.0) {
        rtb_Filter_o = 0.0;
      } else {
        rtb_Filter_o = rtb_Integrator_be;
      }

      /* End of DeadZone: '<S467>/Dead Zone' */
    } else {
      rtb_Filter_o = -0.75 * rateLimiterRate;
    }

    /* Fcn: '<S530>/r->x' incorporates:
     *  Fcn: '<S533>/r->x'
     *  Fcn: '<S536>/r->x'
     *  Fcn: '<S539>/r->x'
     *  UnaryMinus: '<S460>/Unary Minus'
     */
    rtb_Integrator_be = rtb_Integrator_d * cos(-rtb_Sum1_h);

    /* Sum: '<S525>/Add' incorporates:
     *  Fcn: '<S530>/r->x'
     *  Fcn: '<S531>/r->x'
     */
    rtb_Add_idx_0 = rtb_Filter_o * cos(Code_Gen_Model_ConstB.Atan2_k) +
      rtb_Integrator_be;

    /* Fcn: '<S530>/theta->y' incorporates:
     *  Fcn: '<S533>/theta->y'
     *  Fcn: '<S536>/theta->y'
     *  Fcn: '<S539>/theta->y'
     *  UnaryMinus: '<S460>/Unary Minus'
     */
    rtb_Sum1_h = rtb_Integrator_d * sin(-rtb_Sum1_h);

    /* Sum: '<S525>/Add' incorporates:
     *  Fcn: '<S530>/theta->y'
     *  Fcn: '<S531>/theta->y'
     */
    rtb_Add_idx_1 = rtb_Filter_o * sin(Code_Gen_Model_ConstB.Atan2_k) +
      rtb_Sum1_h;

    /* Sum: '<S526>/Add' incorporates:
     *  Fcn: '<S534>/r->x'
     *  Fcn: '<S534>/theta->y'
     */
    rtb_Add_l_idx_0 = rtb_Filter_o * cos(Code_Gen_Model_ConstB.Atan2) +
      rtb_Integrator_be;
    rtb_Add_l_idx_1 = rtb_Filter_o * sin(Code_Gen_Model_ConstB.Atan2) +
      rtb_Sum1_h;

    /* Sum: '<S527>/Add' incorporates:
     *  Fcn: '<S537>/r->x'
     *  Fcn: '<S537>/theta->y'
     */
    rtb_Add_o_idx_0 = rtb_Filter_o * cos(Code_Gen_Model_ConstB.Atan2_n) +
      rtb_Integrator_be;
    rtb_Add_o_idx_1 = rtb_Filter_o * sin(Code_Gen_Model_ConstB.Atan2_n) +
      rtb_Sum1_h;

    /* Sum: '<S528>/Add' incorporates:
     *  Fcn: '<S540>/r->x'
     *  Fcn: '<S540>/theta->y'
     */
    rtb_Add_g_idx_0 = rtb_Filter_o * cos(Code_Gen_Model_ConstB.Atan2_o) +
      rtb_Integrator_be;
    rtb_Add_g_idx_1 = rtb_Filter_o * sin(Code_Gen_Model_ConstB.Atan2_o) +
      rtb_Sum1_h;

    /* Fcn: '<S538>/x->theta' */
    rtb_xtheta = rt_atan2d_snf(rtb_Add_g_idx_1, rtb_Add_g_idx_0);

    /* Trigonometry: '<S406>/Cos4' incorporates:
     *  Switch: '<S349>/Angle_Switch'
     *  Trigonometry: '<S405>/Cos4'
     */
    rtb_Sum1_h = cos(rtb_xtheta);

    /* Abs: '<S348>/Abs' incorporates:
     *  Inport: '<Root>/BackRight_Steer_Encoder'
     */
    rtb_Abs = fabs(Code_Gen_Model_U.BackRight_Steer_Encoder);
    Code_Gen_Model_ModulobyConstant(rtb_Abs,
      &Code_Gen_Model_B.ModulobyConstant_er);

    /* Switch: '<S348>/Switch' incorporates:
     *  Constant: '<S402>/Constant'
     *  Inport: '<Root>/BackRight_Steer_Encoder'
     *  RelationalOperator: '<S402>/Compare'
     *  UnaryMinus: '<S348>/Unary Minus'
     */
    if (Code_Gen_Model_U.BackRight_Steer_Encoder >= 0.0) {
      rtb_Hypot_m = Code_Gen_Model_B.ModulobyConstant_er.ModulobyConstant;
    } else {
      rtb_Hypot_m = -Code_Gen_Model_B.ModulobyConstant_er.ModulobyConstant;
    }

    /* Sum: '<S347>/Add' incorporates:
     *  Inport: '<Root>/BackRight_Turn_Offset'
     *  Switch: '<S348>/Switch'
     */
    rtb_Integrator_d = rtb_Hypot_m + Code_Gen_Model_U.BackRight_Turn_Offset;

    /* Abs: '<S400>/Abs' */
    rtb_Abs_b = fabs(rtb_Integrator_d);
    Code_Gen_Model_ModulobyConstant(rtb_Abs_b,
      &Code_Gen_Model_B.ModulobyConstant_l);

    /* Switch: '<S400>/Switch' incorporates:
     *  Constant: '<S401>/Constant'
     *  RelationalOperator: '<S401>/Compare'
     *  UnaryMinus: '<S400>/Unary Minus'
     */
    if (rtb_Integrator_d >= 0.0) {
      rtb_Hypot_m = Code_Gen_Model_B.ModulobyConstant_l.ModulobyConstant;
    } else {
      rtb_Hypot_m = -Code_Gen_Model_B.ModulobyConstant_l.ModulobyConstant;
    }

    /* Gain: '<S347>/Gain' incorporates:
     *  Switch: '<S400>/Switch'
     */
    rtb_Integrator_d = 6.2831853071795862 * rtb_Hypot_m;

    /* Trigonometry: '<S406>/Sin5' incorporates:
     *  UnaryMinus: '<S404>/Unary Minus'
     */
    rtb_Filter_o = sin(-rtb_Integrator_d);

    /* Trigonometry: '<S406>/Sin4' incorporates:
     *  Switch: '<S349>/Angle_Switch'
     *  Trigonometry: '<S405>/Sin4'
     */
    rtb_Integrator_i = sin(rtb_xtheta);

    /* Trigonometry: '<S406>/Cos5' incorporates:
     *  UnaryMinus: '<S404>/Unary Minus'
     */
    rtb_Integrator_be = cos(-rtb_Integrator_d);

    /* Sum: '<S406>/Subtract1' incorporates:
     *  Product: '<S406>/Product2'
     *  Product: '<S406>/Product3'
     *  Trigonometry: '<S406>/Cos4'
     *  Trigonometry: '<S406>/Sin4'
     */
    rtb_Subtract1 = rtb_Sum1_h * rtb_Filter_o + rtb_Integrator_i *
      rtb_Integrator_be;

    /* Sum: '<S406>/Subtract' incorporates:
     *  Product: '<S406>/Product'
     *  Product: '<S406>/Product1'
     *  Trigonometry: '<S406>/Cos4'
     *  Trigonometry: '<S406>/Sin4'
     */
    rtb_Integrator_be = rtb_Sum1_h * rtb_Integrator_be - rtb_Integrator_i *
      rtb_Filter_o;

    /* Math: '<S406>/Hypot' */
    rtb_Hypot = rt_hypotd_snf(rtb_Integrator_be, rtb_Subtract1);

    /* Switch: '<S406>/Switch' incorporates:
     *  Constant: '<S406>/Constant'
     *  Constant: '<S406>/Constant1'
     *  Constant: '<S407>/Constant'
     *  Product: '<S406>/Divide'
     *  Product: '<S406>/Divide1'
     *  RelationalOperator: '<S407>/Compare'
     *  Switch: '<S406>/Switch1'
     */
    if (rtb_Hypot > 1.0E-6) {
      rtb_Filter_o = rtb_Subtract1 / rtb_Hypot;
      rtb_Integrator_be /= rtb_Hypot;
    } else {
      rtb_Filter_o = 0.0;
      rtb_Integrator_be = 1.0;
    }

    /* End of Switch: '<S406>/Switch' */

    /* RelationalOperator: '<S403>/Compare' incorporates:
     *  Abs: '<S349>/Abs'
     *  Constant: '<S403>/Constant'
     *  Trigonometry: '<S406>/Atan1'
     */
    rtb_Compare_g = fabs(rt_atan2d_snf(rtb_Filter_o, rtb_Integrator_be)) >
      1.5707963267948966;

    /* Switch: '<S349>/Speed_Switch' incorporates:
     *  Fcn: '<S538>/x->r'
     *  UnaryMinus: '<S349>/Unary Minus'
     */
    if (rtb_Compare_g) {
      rtb_Hypot_m = -rt_hypotd_snf(rtb_Add_g_idx_0, rtb_Add_g_idx_1);
    } else {
      rtb_Hypot_m = rt_hypotd_snf(rtb_Add_g_idx_0, rtb_Add_g_idx_1);
    }

    /* Sum: '<S12>/Sum' incorporates:
     *  Constant: '<S350>/Gear_Ratio'
     *  Constant: '<S350>/Pi'
     *  Constant: '<S350>/Sec//Min'
     *  Constant: '<S350>/Wheel_Diameter'
     *  Inport: '<Root>/BackRight_Drive_Encoder'
     *  Product: '<S350>/Product2'
     *  Switch: '<S349>/Speed_Switch'
     */
    rtb_Filter_o = rtb_Hypot_m * 60.0 * 8.14 / 3.1415926535897931 / 0.101600203
      - Code_Gen_Model_U.BackRight_Drive_Encoder;

    /* Gain: '<S386>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S378>/Filter'
     *  Gain: '<S377>/Derivative Gain'
     *  Sum: '<S378>/SumD'
     */
    rtb_Integrator_be = (1.0E-6 * rtb_Filter_o - Code_Gen_Model_DW.Filter_DSTATE)
      * 100.0;

    /* Sum: '<S392>/Sum' incorporates:
     *  DiscreteIntegrator: '<S383>/Integrator'
     *  Gain: '<S388>/Proportional Gain'
     */
    rtb_Hypot_m = 0.5 * rtb_Filter_o + Code_Gen_Model_DW.Integrator_DSTATE_a +
      rtb_Integrator_be;

    /* Saturate: '<S390>/Saturation' */
    if (rtb_Hypot_m > 5700.0) {
      rtb_Hypot_m = 5700.0;
    } else if (rtb_Hypot_m < -5700.0) {
      rtb_Hypot_m = -5700.0;
    }

    /* Outport: '<Root>/BackRight_Steer_DutyCycle' incorporates:
     *  Constant: '<S12>/NEO_Max_Speed'
     *  Product: '<S12>/Divide'
     *  Saturate: '<S390>/Saturation'
     */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = rtb_Hypot_m / 5700.0;

    /* Gain: '<S380>/Integral Gain' */
    rtb_Subtract1 = 0.0 * rtb_Filter_o;

    /* Switch: '<S349>/Angle_Switch' incorporates:
     *  Trigonometry: '<S405>/Atan1'
     */
    if (rtb_Compare_g) {
      /* Sum: '<S405>/Subtract1' incorporates:
       *  Product: '<S405>/Product2'
       *  Product: '<S405>/Product3'
       */
      rtb_Filter_o = rtb_Sum1_h * Code_Gen_Model_ConstB.Sin5_l +
        rtb_Integrator_i * Code_Gen_Model_ConstB.Cos5_g;

      /* Sum: '<S405>/Subtract' incorporates:
       *  Product: '<S405>/Product'
       *  Product: '<S405>/Product1'
       */
      rtb_Integrator_i = rtb_Sum1_h * Code_Gen_Model_ConstB.Cos5_g -
        rtb_Integrator_i * Code_Gen_Model_ConstB.Sin5_l;

      /* Math: '<S405>/Hypot' */
      rtb_Sum1_h = rt_hypotd_snf(rtb_Integrator_i, rtb_Filter_o);

      /* Switch: '<S405>/Switch1' incorporates:
       *  Constant: '<S405>/Constant'
       *  Constant: '<S405>/Constant1'
       *  Constant: '<S408>/Constant'
       *  Product: '<S405>/Divide'
       *  Product: '<S405>/Divide1'
       *  RelationalOperator: '<S408>/Compare'
       *  Switch: '<S405>/Switch'
       */
      if (rtb_Sum1_h > 1.0E-6) {
        rtb_Integrator_i /= rtb_Sum1_h;
        rtb_Sum1_h = rtb_Filter_o / rtb_Sum1_h;
      } else {
        rtb_Integrator_i = 1.0;
        rtb_Sum1_h = 0.0;
      }

      /* End of Switch: '<S405>/Switch1' */
      rtb_Filter_o = rt_atan2d_snf(rtb_Sum1_h, rtb_Integrator_i);
    } else {
      rtb_Filter_o = rtb_xtheta;
    }

    /* Sum: '<S12>/Sum1' */
    rtb_Integrator_d = rtb_Filter_o - rtb_Integrator_d;

    /* Gain: '<S443>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S435>/Filter'
     *  Gain: '<S434>/Derivative Gain'
     *  Sum: '<S435>/SumD'
     */
    rtb_Filter_o = (1.0E-7 * rtb_Integrator_d -
                    Code_Gen_Model_DW.Filter_DSTATE_m) * 100.0;

    /* Gain: '<S438>/Proportional Gain' incorporates:
     *  DiscreteIntegrator: '<S440>/Integrator'
     *  Sum: '<S449>/Sum'
     */
    rtb_Hypot_m = (rtb_Integrator_d + Code_Gen_Model_DW.Integrator_DSTATE_n +
                   rtb_Filter_o) * 0.1;

    /* Saturate: '<S447>/Saturation' */
    if (rtb_Hypot_m > 1.0) {
      /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
      Code_Gen_Model_Y.BackRight_Drive_DutyCycle = 1.0;
    } else if (rtb_Hypot_m < -1.0) {
      /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
      Code_Gen_Model_Y.BackRight_Drive_DutyCycle = -1.0;
    } else {
      /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
      Code_Gen_Model_Y.BackRight_Drive_DutyCycle = rtb_Hypot_m;
    }

    /* End of Saturate: '<S447>/Saturation' */

    /* Fcn: '<S535>/x->theta' */
    rtb_Add_g_idx_0 = rt_atan2d_snf(rtb_Add_o_idx_1, rtb_Add_o_idx_0);

    /* Trigonometry: '<S295>/Cos4' incorporates:
     *  Switch: '<S238>/Angle_Switch'
     *  Trigonometry: '<S294>/Cos4'
     */
    rtb_Hypot = cos(rtb_Add_g_idx_0);

    /* Abs: '<S237>/Abs' incorporates:
     *  Inport: '<Root>/BackLeft_Steer_Encoder'
     */
    rtb_Abs_i = fabs(Code_Gen_Model_U.BackLeft_Steer_Encoder);
    Code_Gen_Model_ModulobyConstant(rtb_Abs_i,
      &Code_Gen_Model_B.ModulobyConstant_g);

    /* Switch: '<S237>/Switch' incorporates:
     *  Constant: '<S291>/Constant'
     *  Inport: '<Root>/BackLeft_Steer_Encoder'
     *  RelationalOperator: '<S291>/Compare'
     *  UnaryMinus: '<S237>/Unary Minus'
     */
    if (Code_Gen_Model_U.BackLeft_Steer_Encoder >= 0.0) {
      rtb_Hypot_m = Code_Gen_Model_B.ModulobyConstant_g.ModulobyConstant;
    } else {
      rtb_Hypot_m = -Code_Gen_Model_B.ModulobyConstant_g.ModulobyConstant;
    }

    /* Sum: '<S236>/Add' incorporates:
     *  Inport: '<Root>/BackLeft_Turn_Offset'
     *  Switch: '<S237>/Switch'
     */
    rtb_Sum1_h = rtb_Hypot_m + Code_Gen_Model_U.BackLeft_Turn_Offset;

    /* Abs: '<S289>/Abs' */
    rtb_Abs_m = fabs(rtb_Sum1_h);
    Code_Gen_Model_ModulobyConstant(rtb_Abs_m,
      &Code_Gen_Model_B.ModulobyConstant_p);

    /* Switch: '<S289>/Switch' incorporates:
     *  Constant: '<S290>/Constant'
     *  RelationalOperator: '<S290>/Compare'
     *  UnaryMinus: '<S289>/Unary Minus'
     */
    if (rtb_Sum1_h >= 0.0) {
      rtb_Hypot_m = Code_Gen_Model_B.ModulobyConstant_p.ModulobyConstant;
    } else {
      rtb_Hypot_m = -Code_Gen_Model_B.ModulobyConstant_p.ModulobyConstant;
    }

    /* Gain: '<S236>/Gain' incorporates:
     *  Switch: '<S289>/Switch'
     */
    rtb_Sum1_h = 6.2831853071795862 * rtb_Hypot_m;

    /* Trigonometry: '<S295>/Sin5' incorporates:
     *  UnaryMinus: '<S293>/Unary Minus'
     */
    rtb_Add_g_idx_1 = sin(-rtb_Sum1_h);

    /* Trigonometry: '<S295>/Sin4' incorporates:
     *  Switch: '<S238>/Angle_Switch'
     *  Trigonometry: '<S294>/Sin4'
     */
    rtb_Subtract_g = sin(rtb_Add_g_idx_0);

    /* Trigonometry: '<S295>/Cos5' incorporates:
     *  UnaryMinus: '<S293>/Unary Minus'
     */
    rtb_Integrator_i = cos(-rtb_Sum1_h);

    /* Sum: '<S295>/Subtract1' incorporates:
     *  Product: '<S295>/Product2'
     *  Product: '<S295>/Product3'
     *  Trigonometry: '<S295>/Cos4'
     *  Trigonometry: '<S295>/Sin4'
     */
    rtb_xtheta = rtb_Hypot * rtb_Add_g_idx_1 + rtb_Subtract_g * rtb_Integrator_i;

    /* Sum: '<S295>/Subtract' incorporates:
     *  Product: '<S295>/Product'
     *  Product: '<S295>/Product1'
     *  Trigonometry: '<S295>/Cos4'
     *  Trigonometry: '<S295>/Sin4'
     */
    rtb_Integrator_i = rtb_Hypot * rtb_Integrator_i - rtb_Subtract_g *
      rtb_Add_g_idx_1;

    /* Math: '<S295>/Hypot' */
    rtb_Add_g_idx_1 = rt_hypotd_snf(rtb_Integrator_i, rtb_xtheta);

    /* Switch: '<S295>/Switch' incorporates:
     *  Constant: '<S295>/Constant'
     *  Constant: '<S295>/Constant1'
     *  Constant: '<S296>/Constant'
     *  Product: '<S295>/Divide'
     *  Product: '<S295>/Divide1'
     *  RelationalOperator: '<S296>/Compare'
     *  Switch: '<S295>/Switch1'
     */
    if (rtb_Add_g_idx_1 > 1.0E-6) {
      rtb_Filter_oh = rtb_xtheta / rtb_Add_g_idx_1;
      rtb_Add_g_idx_1 = rtb_Integrator_i / rtb_Add_g_idx_1;
    } else {
      rtb_Filter_oh = 0.0;
      rtb_Add_g_idx_1 = 1.0;
    }

    /* End of Switch: '<S295>/Switch' */

    /* RelationalOperator: '<S292>/Compare' incorporates:
     *  Abs: '<S238>/Abs'
     *  Constant: '<S292>/Constant'
     *  Trigonometry: '<S295>/Atan1'
     */
    rtb_Compare_g = fabs(rt_atan2d_snf(rtb_Filter_oh, rtb_Add_g_idx_1)) >
      1.5707963267948966;

    /* Switch: '<S238>/Speed_Switch' incorporates:
     *  Fcn: '<S535>/x->r'
     *  UnaryMinus: '<S238>/Unary Minus'
     */
    if (rtb_Compare_g) {
      rtb_Hypot_m = -rt_hypotd_snf(rtb_Add_o_idx_0, rtb_Add_o_idx_1);
    } else {
      rtb_Hypot_m = rt_hypotd_snf(rtb_Add_o_idx_0, rtb_Add_o_idx_1);
    }

    /* Sum: '<S11>/Sum' incorporates:
     *  Constant: '<S239>/Gear_Ratio'
     *  Constant: '<S239>/Pi'
     *  Constant: '<S239>/Sec//Min'
     *  Constant: '<S239>/Wheel_Diameter'
     *  Inport: '<Root>/BackLeft_Drive_Encoder'
     *  Product: '<S239>/Product2'
     *  Switch: '<S238>/Speed_Switch'
     */
    rtb_Filter_oh = rtb_Hypot_m * 60.0 * 8.14 / 3.1415926535897931 / 0.101600203
      - Code_Gen_Model_U.BackLeft_Drive_Encoder;

    /* Gain: '<S275>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S267>/Filter'
     *  Gain: '<S266>/Derivative Gain'
     *  Sum: '<S267>/SumD'
     */
    rtb_Integrator_i = (1.0E-6 * rtb_Filter_oh -
                        Code_Gen_Model_DW.Filter_DSTATE_k) * 100.0;

    /* Sum: '<S281>/Sum' incorporates:
     *  DiscreteIntegrator: '<S272>/Integrator'
     *  Gain: '<S277>/Proportional Gain'
     */
    rtb_Hypot_m = 0.5 * rtb_Filter_oh + Code_Gen_Model_DW.Integrator_DSTATE_m +
      rtb_Integrator_i;

    /* Saturate: '<S279>/Saturation' */
    if (rtb_Hypot_m > 5700.0) {
      rtb_Hypot_m = 5700.0;
    } else if (rtb_Hypot_m < -5700.0) {
      rtb_Hypot_m = -5700.0;
    }

    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' incorporates:
     *  Constant: '<S11>/NEO_Max_Speed'
     *  Product: '<S11>/Divide'
     *  Saturate: '<S279>/Saturation'
     */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = rtb_Hypot_m / 5700.0;

    /* Gain: '<S269>/Integral Gain' */
    rtb_xtheta = 0.0 * rtb_Filter_oh;

    /* Switch: '<S238>/Angle_Switch' incorporates:
     *  Trigonometry: '<S294>/Atan1'
     */
    if (rtb_Compare_g) {
      /* Sum: '<S294>/Subtract1' incorporates:
       *  Product: '<S294>/Product2'
       *  Product: '<S294>/Product3'
       */
      rtb_Add_g_idx_0 = rtb_Hypot * Code_Gen_Model_ConstB.Sin5_h +
        rtb_Subtract_g * Code_Gen_Model_ConstB.Cos5_i;

      /* Sum: '<S294>/Subtract' incorporates:
       *  Product: '<S294>/Product'
       *  Product: '<S294>/Product1'
       */
      rtb_Subtract_g = rtb_Hypot * Code_Gen_Model_ConstB.Cos5_i - rtb_Subtract_g
        * Code_Gen_Model_ConstB.Sin5_h;

      /* Math: '<S294>/Hypot' */
      rtb_Hypot = rt_hypotd_snf(rtb_Subtract_g, rtb_Add_g_idx_0);

      /* Switch: '<S294>/Switch1' incorporates:
       *  Constant: '<S294>/Constant'
       *  Constant: '<S294>/Constant1'
       *  Constant: '<S297>/Constant'
       *  Product: '<S294>/Divide'
       *  Product: '<S294>/Divide1'
       *  RelationalOperator: '<S297>/Compare'
       *  Switch: '<S294>/Switch'
       */
      if (rtb_Hypot > 1.0E-6) {
        rtb_Subtract_g /= rtb_Hypot;
        rtb_Hypot = rtb_Add_g_idx_0 / rtb_Hypot;
      } else {
        rtb_Subtract_g = 1.0;
        rtb_Hypot = 0.0;
      }

      /* End of Switch: '<S294>/Switch1' */
      rtb_Filter_oh = rt_atan2d_snf(rtb_Hypot, rtb_Subtract_g);
    } else {
      rtb_Filter_oh = rtb_Add_g_idx_0;
    }

    /* Sum: '<S11>/Sum1' */
    rtb_Sum1_h = rtb_Filter_oh - rtb_Sum1_h;

    /* Gain: '<S332>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S324>/Filter'
     *  Gain: '<S323>/Derivative Gain'
     *  Sum: '<S324>/SumD'
     */
    rtb_Hypot = (1.0E-7 * rtb_Sum1_h - Code_Gen_Model_DW.Filter_DSTATE_j) *
      100.0;

    /* Gain: '<S327>/Proportional Gain' incorporates:
     *  DiscreteIntegrator: '<S329>/Integrator'
     *  Sum: '<S338>/Sum'
     */
    rtb_Hypot_m = (rtb_Sum1_h + Code_Gen_Model_DW.Integrator_DSTATE_g +
                   rtb_Hypot) * 0.1;

    /* Saturate: '<S336>/Saturation' */
    if (rtb_Hypot_m > 1.0) {
      /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
      Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = 1.0;
    } else if (rtb_Hypot_m < -1.0) {
      /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
      Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = -1.0;
    } else {
      /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
      Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = rtb_Hypot_m;
    }

    /* End of Saturate: '<S336>/Saturation' */

    /* Gain: '<S326>/Integral Gain' */
    rtb_Subtract_g = 0.0 * rtb_Sum1_h;

    /* Fcn: '<S532>/x->theta' */
    rtb_Add_o_idx_0 = rt_atan2d_snf(rtb_Add_l_idx_1, rtb_Add_l_idx_0);

    /* Trigonometry: '<S184>/Cos4' incorporates:
     *  Switch: '<S127>/Angle_Switch'
     *  Trigonometry: '<S183>/Cos4'
     */
    rtb_Add_g_idx_1 = cos(rtb_Add_o_idx_0);

    /* Abs: '<S126>/Abs' incorporates:
     *  Inport: '<Root>/FrontRight_Steer_Encoder'
     */
    rtb_Abs_ba = fabs(Code_Gen_Model_U.FrontRight_Steer_Encoder);
    Code_Gen_Model_ModulobyConstant(rtb_Abs_ba,
      &Code_Gen_Model_B.ModulobyConstant_a);

    /* Switch: '<S126>/Switch' incorporates:
     *  Constant: '<S180>/Constant'
     *  Inport: '<Root>/FrontRight_Steer_Encoder'
     *  RelationalOperator: '<S180>/Compare'
     *  UnaryMinus: '<S126>/Unary Minus'
     */
    if (Code_Gen_Model_U.FrontRight_Steer_Encoder >= 0.0) {
      rtb_Hypot_m = Code_Gen_Model_B.ModulobyConstant_a.ModulobyConstant;
    } else {
      rtb_Hypot_m = -Code_Gen_Model_B.ModulobyConstant_a.ModulobyConstant;
    }

    /* Sum: '<S125>/Add' incorporates:
     *  Inport: '<Root>/FrontRight_Turn_Offset'
     *  Switch: '<S126>/Switch'
     */
    rtb_Sum1_h = rtb_Hypot_m + Code_Gen_Model_U.FrontRight_Turn_Offset;

    /* Abs: '<S178>/Abs' */
    rtb_Abs_f = fabs(rtb_Sum1_h);
    Code_Gen_Model_ModulobyConstant(rtb_Abs_f,
      &Code_Gen_Model_B.ModulobyConstant_f);

    /* Switch: '<S178>/Switch' incorporates:
     *  Constant: '<S179>/Constant'
     *  RelationalOperator: '<S179>/Compare'
     *  UnaryMinus: '<S178>/Unary Minus'
     */
    if (rtb_Sum1_h >= 0.0) {
      rtb_Hypot_m = Code_Gen_Model_B.ModulobyConstant_f.ModulobyConstant;
    } else {
      rtb_Hypot_m = -Code_Gen_Model_B.ModulobyConstant_f.ModulobyConstant;
    }

    /* Gain: '<S125>/Gain' incorporates:
     *  Switch: '<S178>/Switch'
     */
    rtb_Sum1_h = 6.2831853071795862 * rtb_Hypot_m;

    /* Trigonometry: '<S184>/Sin5' incorporates:
     *  UnaryMinus: '<S182>/Unary Minus'
     */
    rtb_Filter_oh = sin(-rtb_Sum1_h);

    /* Trigonometry: '<S184>/Sin4' incorporates:
     *  Switch: '<S127>/Angle_Switch'
     *  Trigonometry: '<S183>/Sin4'
     */
    rtb_Add_o_idx_1 = sin(rtb_Add_o_idx_0);

    /* Trigonometry: '<S184>/Cos5' incorporates:
     *  UnaryMinus: '<S182>/Unary Minus'
     */
    rtb_Filter = cos(-rtb_Sum1_h);

    /* Sum: '<S184>/Subtract1' incorporates:
     *  Product: '<S184>/Product2'
     *  Product: '<S184>/Product3'
     *  Trigonometry: '<S184>/Cos4'
     *  Trigonometry: '<S184>/Sin4'
     */
    rtb_Add_g_idx_0 = rtb_Add_g_idx_1 * rtb_Filter_oh + rtb_Add_o_idx_1 *
      rtb_Filter;

    /* Sum: '<S184>/Subtract' incorporates:
     *  Product: '<S184>/Product'
     *  Product: '<S184>/Product1'
     *  Trigonometry: '<S184>/Cos4'
     *  Trigonometry: '<S184>/Sin4'
     */
    rtb_Filter_oh = rtb_Add_g_idx_1 * rtb_Filter - rtb_Add_o_idx_1 *
      rtb_Filter_oh;

    /* Math: '<S184>/Hypot' */
    rtb_Hypot_o = rt_hypotd_snf(rtb_Filter_oh, rtb_Add_g_idx_0);

    /* Switch: '<S184>/Switch' incorporates:
     *  Constant: '<S184>/Constant'
     *  Constant: '<S184>/Constant1'
     *  Constant: '<S185>/Constant'
     *  Product: '<S184>/Divide'
     *  Product: '<S184>/Divide1'
     *  RelationalOperator: '<S185>/Compare'
     *  Switch: '<S184>/Switch1'
     */
    if (rtb_Hypot_o > 1.0E-6) {
      rtb_Filter = rtb_Add_g_idx_0 / rtb_Hypot_o;
      rtb_Filter_oh /= rtb_Hypot_o;
    } else {
      rtb_Filter = 0.0;
      rtb_Filter_oh = 1.0;
    }

    /* End of Switch: '<S184>/Switch' */

    /* RelationalOperator: '<S181>/Compare' incorporates:
     *  Abs: '<S127>/Abs'
     *  Constant: '<S181>/Constant'
     *  Trigonometry: '<S184>/Atan1'
     */
    rtb_Compare_g = fabs(rt_atan2d_snf(rtb_Filter, rtb_Filter_oh)) >
      1.5707963267948966;

    /* Switch: '<S127>/Speed_Switch' incorporates:
     *  Fcn: '<S532>/x->r'
     *  UnaryMinus: '<S127>/Unary Minus'
     */
    if (rtb_Compare_g) {
      rtb_Hypot_m = -rt_hypotd_snf(rtb_Add_l_idx_0, rtb_Add_l_idx_1);
    } else {
      rtb_Hypot_m = rt_hypotd_snf(rtb_Add_l_idx_0, rtb_Add_l_idx_1);
    }

    /* Sum: '<S10>/Sum' incorporates:
     *  Constant: '<S128>/Gear_Ratio'
     *  Constant: '<S128>/Pi'
     *  Constant: '<S128>/Sec//Min'
     *  Constant: '<S128>/Wheel_Diameter'
     *  Inport: '<Root>/FrontRight_Drive_Encoder'
     *  Product: '<S128>/Product2'
     *  Switch: '<S127>/Speed_Switch'
     */
    rtb_Filter = rtb_Hypot_m * 60.0 * 8.14 / 3.1415926535897931 / 0.101600203 -
      Code_Gen_Model_U.FrontRight_Drive_Encoder;

    /* Gain: '<S164>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S156>/Filter'
     *  Gain: '<S155>/Derivative Gain'
     *  Sum: '<S156>/SumD'
     */
    rtb_Add_g_idx_0 = (1.0E-6 * rtb_Filter - Code_Gen_Model_DW.Filter_DSTATE_k3)
      * 100.0;

    /* Sum: '<S170>/Sum' incorporates:
     *  DiscreteIntegrator: '<S161>/Integrator'
     *  Gain: '<S166>/Proportional Gain'
     */
    rtb_Hypot_m = 0.5 * rtb_Filter + Code_Gen_Model_DW.Integrator_DSTATE_b +
      rtb_Add_g_idx_0;

    /* Saturate: '<S168>/Saturation' */
    if (rtb_Hypot_m > 5700.0) {
      rtb_Hypot_m = 5700.0;
    } else if (rtb_Hypot_m < -5700.0) {
      rtb_Hypot_m = -5700.0;
    }

    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' incorporates:
     *  Constant: '<S10>/NEO_Max_Speed'
     *  Product: '<S10>/Divide'
     *  Saturate: '<S168>/Saturation'
     */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = rtb_Hypot_m / 5700.0;

    /* Gain: '<S158>/Integral Gain' */
    rtb_Filter_oh = 0.0 * rtb_Filter;

    /* Switch: '<S127>/Angle_Switch' incorporates:
     *  Trigonometry: '<S183>/Atan1'
     */
    if (rtb_Compare_g) {
      /* Sum: '<S183>/Subtract1' incorporates:
       *  Product: '<S183>/Product2'
       *  Product: '<S183>/Product3'
       */
      rtb_Add_o_idx_0 = rtb_Add_g_idx_1 * Code_Gen_Model_ConstB.Sin5_b +
        rtb_Add_o_idx_1 * Code_Gen_Model_ConstB.Cos5_p;

      /* Sum: '<S183>/Subtract' incorporates:
       *  Product: '<S183>/Product'
       *  Product: '<S183>/Product1'
       */
      rtb_Add_o_idx_1 = rtb_Add_g_idx_1 * Code_Gen_Model_ConstB.Cos5_p -
        rtb_Add_o_idx_1 * Code_Gen_Model_ConstB.Sin5_b;

      /* Math: '<S183>/Hypot' */
      rtb_Add_g_idx_1 = rt_hypotd_snf(rtb_Add_o_idx_1, rtb_Add_o_idx_0);

      /* Switch: '<S183>/Switch1' incorporates:
       *  Constant: '<S183>/Constant'
       *  Constant: '<S183>/Constant1'
       *  Constant: '<S186>/Constant'
       *  Product: '<S183>/Divide'
       *  Product: '<S183>/Divide1'
       *  RelationalOperator: '<S186>/Compare'
       *  Switch: '<S183>/Switch'
       */
      if (rtb_Add_g_idx_1 > 1.0E-6) {
        rtb_Add_o_idx_1 /= rtb_Add_g_idx_1;
        rtb_Add_g_idx_1 = rtb_Add_o_idx_0 / rtb_Add_g_idx_1;
      } else {
        rtb_Add_o_idx_1 = 1.0;
        rtb_Add_g_idx_1 = 0.0;
      }

      /* End of Switch: '<S183>/Switch1' */
      rtb_Filter = rt_atan2d_snf(rtb_Add_g_idx_1, rtb_Add_o_idx_1);
    } else {
      rtb_Filter = rtb_Add_o_idx_0;
    }

    /* Sum: '<S10>/Sum1' */
    rtb_Sum1_h = rtb_Filter - rtb_Sum1_h;

    /* Gain: '<S221>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S213>/Filter'
     *  Gain: '<S212>/Derivative Gain'
     *  Sum: '<S213>/SumD'
     */
    rtb_Add_g_idx_1 = (1.0E-7 * rtb_Sum1_h - Code_Gen_Model_DW.Filter_DSTATE_i) *
      100.0;

    /* Gain: '<S216>/Proportional Gain' incorporates:
     *  DiscreteIntegrator: '<S218>/Integrator'
     *  Sum: '<S227>/Sum'
     */
    rtb_Hypot_m = (rtb_Sum1_h + Code_Gen_Model_DW.Integrator_DSTATE_d +
                   rtb_Add_g_idx_1) * 0.1;

    /* Saturate: '<S225>/Saturation' */
    if (rtb_Hypot_m > 1.0) {
      /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
      Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = 1.0;
    } else if (rtb_Hypot_m < -1.0) {
      /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
      Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = -1.0;
    } else {
      /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
      Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = rtb_Hypot_m;
    }

    /* End of Saturate: '<S225>/Saturation' */

    /* Gain: '<S215>/Integral Gain' */
    rtb_Add_o_idx_1 = 0.0 * rtb_Sum1_h;

    /* Fcn: '<S529>/x->theta' */
    rtb_Add_l_idx_0 = rt_atan2d_snf(rtb_Add_idx_1, rtb_Add_idx_0);

    /* Trigonometry: '<S73>/Cos4' incorporates:
     *  Switch: '<S16>/Angle_Switch'
     *  Trigonometry: '<S72>/Cos4'
     */
    rtb_Add_o_idx_0 = cos(rtb_Add_l_idx_0);

    /* Abs: '<S15>/Abs' incorporates:
     *  Inport: '<Root>/FrontLeft_Steer_Encoder'
     */
    rtb_Abs_fq = fabs(Code_Gen_Model_U.FrontLeft_Steer_Encoder);
    Code_Gen_Model_ModulobyConstant(rtb_Abs_fq,
      &Code_Gen_Model_B.ModulobyConstant_e);

    /* Switch: '<S15>/Switch' incorporates:
     *  Constant: '<S69>/Constant'
     *  Inport: '<Root>/FrontLeft_Steer_Encoder'
     *  RelationalOperator: '<S69>/Compare'
     *  UnaryMinus: '<S15>/Unary Minus'
     */
    if (Code_Gen_Model_U.FrontLeft_Steer_Encoder >= 0.0) {
      rtb_Hypot_m = Code_Gen_Model_B.ModulobyConstant_e.ModulobyConstant;
    } else {
      rtb_Hypot_m = -Code_Gen_Model_B.ModulobyConstant_e.ModulobyConstant;
    }

    /* Sum: '<S14>/Add' incorporates:
     *  Inport: '<Root>/FrontLeft_Turn_Offset'
     *  Switch: '<S15>/Switch'
     */
    rtb_Sum1_h = rtb_Hypot_m + Code_Gen_Model_U.FrontLeft_Turn_Offset;

    /* Abs: '<S67>/Abs' */
    rtb_Abs_p = fabs(rtb_Sum1_h);
    Code_Gen_Model_ModulobyConstant(rtb_Abs_p,
      &Code_Gen_Model_B.ModulobyConstant);

    /* Switch: '<S67>/Switch' incorporates:
     *  Constant: '<S68>/Constant'
     *  RelationalOperator: '<S68>/Compare'
     *  UnaryMinus: '<S67>/Unary Minus'
     */
    if (rtb_Sum1_h >= 0.0) {
      rtb_Hypot_m = Code_Gen_Model_B.ModulobyConstant.ModulobyConstant;
    } else {
      rtb_Hypot_m = -Code_Gen_Model_B.ModulobyConstant.ModulobyConstant;
    }

    /* Gain: '<S14>/Gain' incorporates:
     *  Switch: '<S67>/Switch'
     */
    rtb_Sum1_h = 6.2831853071795862 * rtb_Hypot_m;

    /* Trigonometry: '<S73>/Sin5' incorporates:
     *  UnaryMinus: '<S71>/Unary Minus'
     */
    rtb_Add_l_idx_1 = sin(-rtb_Sum1_h);

    /* Trigonometry: '<S73>/Sin4' incorporates:
     *  Switch: '<S16>/Angle_Switch'
     *  Trigonometry: '<S72>/Sin4'
     */
    rtb_Filter = sin(rtb_Add_l_idx_0);

    /* Trigonometry: '<S73>/Cos5' incorporates:
     *  UnaryMinus: '<S71>/Unary Minus'
     */
    rtb_Filter_n = cos(-rtb_Sum1_h);

    /* Sum: '<S73>/Subtract1' incorporates:
     *  Product: '<S73>/Product2'
     *  Product: '<S73>/Product3'
     *  Trigonometry: '<S73>/Cos4'
     *  Trigonometry: '<S73>/Sin4'
     */
    rtb_Hypot_o = rtb_Add_o_idx_0 * rtb_Add_l_idx_1 + rtb_Filter * rtb_Filter_n;

    /* Sum: '<S73>/Subtract' incorporates:
     *  Product: '<S73>/Product'
     *  Product: '<S73>/Product1'
     *  Trigonometry: '<S73>/Cos4'
     *  Trigonometry: '<S73>/Sin4'
     */
    rtb_Add_l_idx_1 = rtb_Add_o_idx_0 * rtb_Filter_n - rtb_Filter *
      rtb_Add_l_idx_1;

    /* Math: '<S73>/Hypot' */
    rtb_Hypot_m = rt_hypotd_snf(rtb_Add_l_idx_1, rtb_Hypot_o);

    /* Switch: '<S73>/Switch' incorporates:
     *  Constant: '<S73>/Constant'
     *  Constant: '<S73>/Constant1'
     *  Constant: '<S74>/Constant'
     *  Product: '<S73>/Divide'
     *  Product: '<S73>/Divide1'
     *  RelationalOperator: '<S74>/Compare'
     *  Switch: '<S73>/Switch1'
     */
    if (rtb_Hypot_m > 1.0E-6) {
      rtb_Filter_n = rtb_Hypot_o / rtb_Hypot_m;
      rtb_Add_l_idx_1 /= rtb_Hypot_m;
    } else {
      rtb_Filter_n = 0.0;
      rtb_Add_l_idx_1 = 1.0;
    }

    /* End of Switch: '<S73>/Switch' */

    /* RelationalOperator: '<S70>/Compare' incorporates:
     *  Abs: '<S16>/Abs'
     *  Constant: '<S70>/Constant'
     *  Trigonometry: '<S73>/Atan1'
     */
    rtb_Compare_g = fabs(rt_atan2d_snf(rtb_Filter_n, rtb_Add_l_idx_1)) >
      1.5707963267948966;

    /* Switch: '<S16>/Speed_Switch' incorporates:
     *  Fcn: '<S529>/x->r'
     *  UnaryMinus: '<S16>/Unary Minus'
     */
    if (rtb_Compare_g) {
      rtb_Hypot_m = -rt_hypotd_snf(rtb_Add_idx_0, rtb_Add_idx_1);
    } else {
      rtb_Hypot_m = rt_hypotd_snf(rtb_Add_idx_0, rtb_Add_idx_1);
    }

    /* Sum: '<S9>/Sum' incorporates:
     *  Constant: '<S17>/Gear_Ratio'
     *  Constant: '<S17>/Pi'
     *  Constant: '<S17>/Sec//Min'
     *  Constant: '<S17>/Wheel_Diameter'
     *  Inport: '<Root>/FrontLeft_Drive_Encoder'
     *  Product: '<S17>/Product2'
     *  Switch: '<S16>/Speed_Switch'
     */
    rtb_Filter_n = rtb_Hypot_m * 60.0 * 8.14 / 3.1415926535897931 / 0.101600203
      - Code_Gen_Model_U.FrontLeft_Drive_Encoder;

    /* Gain: '<S53>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S45>/Filter'
     *  Gain: '<S44>/Derivative Gain'
     *  Sum: '<S45>/SumD'
     */
    rtb_Hypot_o = (1.0E-6 * rtb_Filter_n - Code_Gen_Model_DW.Filter_DSTATE_l) *
      100.0;

    /* Sum: '<S59>/Sum' incorporates:
     *  DiscreteIntegrator: '<S50>/Integrator'
     *  Gain: '<S55>/Proportional Gain'
     */
    rtb_Hypot_m = 0.5 * rtb_Filter_n + Code_Gen_Model_DW.Integrator_DSTATE_b5 +
      rtb_Hypot_o;

    /* Saturate: '<S57>/Saturation' */
    if (rtb_Hypot_m > 5700.0) {
      rtb_Hypot_m = 5700.0;
    } else if (rtb_Hypot_m < -5700.0) {
      rtb_Hypot_m = -5700.0;
    }

    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' incorporates:
     *  Constant: '<S9>/NEO_Max_Speed'
     *  Product: '<S9>/Divide'
     *  Saturate: '<S57>/Saturation'
     */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = rtb_Hypot_m / 5700.0;

    /* Gain: '<S47>/Integral Gain' */
    rtb_Add_l_idx_1 = 0.0 * rtb_Filter_n;

    /* Switch: '<S16>/Angle_Switch' incorporates:
     *  Trigonometry: '<S72>/Atan1'
     */
    if (rtb_Compare_g) {
      /* Sum: '<S72>/Subtract1' incorporates:
       *  Product: '<S72>/Product2'
       *  Product: '<S72>/Product3'
       */
      rtb_Add_l_idx_0 = rtb_Add_o_idx_0 * Code_Gen_Model_ConstB.Sin5 +
        rtb_Filter * Code_Gen_Model_ConstB.Cos5;

      /* Sum: '<S72>/Subtract' incorporates:
       *  Product: '<S72>/Product'
       *  Product: '<S72>/Product1'
       */
      rtb_Filter = rtb_Add_o_idx_0 * Code_Gen_Model_ConstB.Cos5 - rtb_Filter *
        Code_Gen_Model_ConstB.Sin5;

      /* Math: '<S72>/Hypot' */
      rtb_Add_o_idx_0 = rt_hypotd_snf(rtb_Filter, rtb_Add_l_idx_0);

      /* Switch: '<S72>/Switch1' incorporates:
       *  Constant: '<S72>/Constant'
       *  Constant: '<S72>/Constant1'
       *  Constant: '<S75>/Constant'
       *  Product: '<S72>/Divide'
       *  Product: '<S72>/Divide1'
       *  RelationalOperator: '<S75>/Compare'
       *  Switch: '<S72>/Switch'
       */
      if (rtb_Add_o_idx_0 > 1.0E-6) {
        rtb_Filter /= rtb_Add_o_idx_0;
        rtb_Add_o_idx_0 = rtb_Add_l_idx_0 / rtb_Add_o_idx_0;
      } else {
        rtb_Filter = 1.0;
        rtb_Add_o_idx_0 = 0.0;
      }

      /* End of Switch: '<S72>/Switch1' */
      rtb_Filter_n = rt_atan2d_snf(rtb_Add_o_idx_0, rtb_Filter);
    } else {
      rtb_Filter_n = rtb_Add_l_idx_0;
    }

    /* Sum: '<S9>/Sum1' */
    rtb_Sum1_h = rtb_Filter_n - rtb_Sum1_h;

    /* Gain: '<S110>/Filter Coefficient' incorporates:
     *  DiscreteIntegrator: '<S102>/Filter'
     *  Gain: '<S101>/Derivative Gain'
     *  Sum: '<S102>/SumD'
     */
    rtb_Add_o_idx_0 = (1.0E-7 * rtb_Sum1_h - Code_Gen_Model_DW.Filter_DSTATE_mx)
      * 100.0;

    /* Gain: '<S105>/Proportional Gain' incorporates:
     *  DiscreteIntegrator: '<S107>/Integrator'
     *  Sum: '<S116>/Sum'
     */
    rtb_Hypot_m = (rtb_Sum1_h + Code_Gen_Model_DW.Integrator_DSTATE_f +
                   rtb_Add_o_idx_0) * 0.1;

    /* Saturate: '<S114>/Saturation' */
    if (rtb_Hypot_m > 1.0) {
      /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
      Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = 1.0;
    } else if (rtb_Hypot_m < -1.0) {
      /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
      Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = -1.0;
    } else {
      /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
      Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = rtb_Hypot_m;
    }

    /* End of Saturate: '<S114>/Saturation' */

    /* Update for UnitDelay: '<S466>/Unit Delay' incorporates:
     *  Lookup_n-D: '<S459>/Modulation_Str_X_Abs'
     */
    Code_Gen_Model_DW.UnitDelay_DSTATE = rateLimiterRate;

    /* Update for UnitDelay: '<S466>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE = rtb_Sum1;

    /* Update for DiscreteIntegrator: '<S507>/Integrator' incorporates:
     *  Gain: '<S504>/Integral Gain'
     */
    Code_Gen_Model_DW.Integrator_DSTATE += 0.02 * rtb_Gain1 * 0.02;

    /* Update for Delay: '<S500>/UD' */
    Code_Gen_Model_DW.UD_DSTATE = rtb_Tsamp;

    /* Update for DiscreteIntegrator: '<S383>/Integrator' */
    Code_Gen_Model_DW.Integrator_DSTATE_a += rtb_Subtract1;

    /* Update for DiscreteIntegrator: '<S378>/Filter' */
    Code_Gen_Model_DW.Filter_DSTATE += 0.02 * rtb_Integrator_be;

    /* Update for DiscreteIntegrator: '<S435>/Filter' */
    Code_Gen_Model_DW.Filter_DSTATE_m += 0.02 * rtb_Filter_o;

    /* Update for DiscreteIntegrator: '<S440>/Integrator' incorporates:
     *  Gain: '<S437>/Integral Gain'
     */
    Code_Gen_Model_DW.Integrator_DSTATE_n += 0.0 * rtb_Integrator_d;

    /* Update for DiscreteIntegrator: '<S272>/Integrator' */
    Code_Gen_Model_DW.Integrator_DSTATE_m += rtb_xtheta;

    /* Update for DiscreteIntegrator: '<S267>/Filter' */
    Code_Gen_Model_DW.Filter_DSTATE_k += 0.02 * rtb_Integrator_i;

    /* Update for DiscreteIntegrator: '<S324>/Filter' */
    Code_Gen_Model_DW.Filter_DSTATE_j += 0.02 * rtb_Hypot;

    /* Update for DiscreteIntegrator: '<S329>/Integrator' */
    Code_Gen_Model_DW.Integrator_DSTATE_g += rtb_Subtract_g;

    /* Update for DiscreteIntegrator: '<S161>/Integrator' */
    Code_Gen_Model_DW.Integrator_DSTATE_b += rtb_Filter_oh;

    /* Update for DiscreteIntegrator: '<S156>/Filter' */
    Code_Gen_Model_DW.Filter_DSTATE_k3 += 0.02 * rtb_Add_g_idx_0;

    /* Update for DiscreteIntegrator: '<S213>/Filter' */
    Code_Gen_Model_DW.Filter_DSTATE_i += 0.02 * rtb_Add_g_idx_1;

    /* Update for DiscreteIntegrator: '<S218>/Integrator' */
    Code_Gen_Model_DW.Integrator_DSTATE_d += rtb_Add_o_idx_1;

    /* Update for DiscreteIntegrator: '<S50>/Integrator' */
    Code_Gen_Model_DW.Integrator_DSTATE_b5 += rtb_Add_l_idx_1;

    /* Update for DiscreteIntegrator: '<S45>/Filter' */
    Code_Gen_Model_DW.Filter_DSTATE_l += 0.02 * rtb_Hypot_o;

    /* Update for DiscreteIntegrator: '<S102>/Filter' */
    Code_Gen_Model_DW.Filter_DSTATE_mx += 0.02 * rtb_Add_o_idx_0;

    /* Update for DiscreteIntegrator: '<S107>/Integrator' incorporates:
     *  Gain: '<S104>/Integral Gain'
     */
    Code_Gen_Model_DW.Integrator_DSTATE_f += 0.0 * rtb_Sum1_h;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' incorporates:
     *  Outport: '<Root>/BackLeft_Drive_DutyCycle'
     *  Outport: '<Root>/BackLeft_Steer_DutyCycle'
     *  Outport: '<Root>/BackRight_Drive_DutyCycle'
     *  Outport: '<Root>/FrontLeft_Drive_DutyCycle'
     *  Outport: '<Root>/FrontLeft_Steer_DutyCycle'
     *  Outport: '<Root>/FrontRight_Drive_DutyCycle'
     *  Outport: '<Root>/FrontRight_Steer_DutyCycle'
     */
    Code_Gen_Model_Disabled(&Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle,
      &Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle,
      &Code_Gen_Model_Y.FrontRight_Drive_DutyCycle,
      &Code_Gen_Model_Y.FrontRight_Steer_DutyCycle,
      &Code_Gen_Model_Y.BackLeft_Drive_DutyCycle,
      &Code_Gen_Model_Y.BackLeft_Steer_DutyCycle,
      &Code_Gen_Model_Y.BackRight_Drive_DutyCycle,
      &Code_Gen_Model_Y.BackRight_Steer_DutyCycle);

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */
}

/* Model initialize function */
void Code_Gen_Model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for IfAction SubSystem: '<S1>/Teleop' */
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_er);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_l);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_g);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_p);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_a);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_f);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant_e);
  Code_Gen_ModulobyConstant_Start(&Code_Gen_Model_DW.ModulobyConstant);

  /* End of Start for SubSystem: '<S1>/Teleop' */
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
