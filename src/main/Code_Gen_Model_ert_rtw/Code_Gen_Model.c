/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Jul 11 18:19:23 2023
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
  /* Start for MATLABSystem: '<S27>/Modulo by Constant' */
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
}

/* Output and update for atomic system: */
void Code_Gen_Model_ModulobyConstant(real_T rtu_0,
  B_ModulobyConstant_Code_Gen_M_T *localB)
{
  real_T yTemp;

  /* MATLABSystem: '<S27>/Modulo by Constant' */
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

  /* MATLABSystem: '<S27>/Modulo by Constant' */
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
  real_T rtb_Abs_b;
  real_T rtb_Abs_j;
  real_T rtb_Abs_gz;
  real_T rtb_Abs_p;
  real_T rtb_Abs_c;
  real_T rtb_Abs_a;
  real_T rtb_Abs_cq;
  real_T rtb_Abs_l;
  real_T rtb_LookupTableDynamic1;
  real_T rtb_LookupTableDynamic;
  real_T rtb_LookupTableDynamic1_l;
  real_T rtb_LookupTableDynamic_p;
  real_T rtb_TmpSignalConversionAtLook_k[2];
  real_T rtb_TmpSignalConversionAtLook_n[2];
  real_T rtb_Add_d_idx_0;
  real_T rtb_Add_d_idx_1;
  real_T rtb_Add_ek;
  real_T rtb_Add_h;
  real_T rtb_Add_hu;
  real_T rtb_Add_i;
  real_T rtb_Add_k;
  real_T rtb_Hypot_i;
  real_T rtb_Integral_j;
  real_T rtb_Integral_oc;
  real_T rtb_Magnitude;
  real_T rtb_Minus2;
  real_T rtb_Product_jb;
  real_T rtb_Product_ln;
  real_T rtb_Sin5;
  real_T rtb_Subtract_b;
  real_T rtb_Subtract_e;
  real_T rtb_Subtract_h;
  real_T rtb_Subtract_l;
  real_T rtb_Sum1_m;
  real_T rtb_Switch1_b;
  real_T rtb_Switch1_hj;
  real_T rtb_Switch1_ip;
  real_T rtb_Switch1_j;
  real_T rtb_Switch2;
  real_T rtb_Switch2_g;
  real_T rtb_Switch2_h;
  real_T rtb_Switch2_p;
  real_T rtb_Total_Limited_l;
  int32_T tmp;
  boolean_T rtb_Compare_gm;
  boolean_T rtb_Compare_j;
  boolean_T rtb_Compare_na;
  boolean_T rtb_Is_Absolute_Translation;

  /* SwitchCase: '<S1>/Switch Case' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant2'
   *  Constant: '<S6>/Constant4'
   *  Constant: '<S6>/Constant5'
   *  Constant: '<S6>/Constant6'
   *  Inport: '<Root>/GameState'
   */
  rtb_Switch2_p = trunc(Code_Gen_Model_U.GameState);
  if (rtIsNaN(rtb_Switch2_p) || rtIsInf(rtb_Switch2_p)) {
    rtb_Switch2_p = 0.0;
  } else {
    rtb_Switch2_p = fmod(rtb_Switch2_p, 4.294967296E+9);
  }

  switch (rtb_Switch2_p < 0.0 ? -(int32_T)(uint32_T)-rtb_Switch2_p : (int32_T)
          (uint32_T)rtb_Switch2_p) {
   case 0:
    /* Outputs for IfAction SubSystem: '<S1>/Disabled' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    Code_Gen_Model_Disabled(&rtb_Total_Limited_l,
      &Code_Gen_Model_B.Steering_Abs_Cmd, &rtb_Minus2,
      &Code_Gen_Model_B.Translation_Angle, &rtb_Switch2_g,
      &rtb_Is_Absolute_Translation, &rtb_Compare_na);

    /* End of Outputs for SubSystem: '<S1>/Disabled' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S1>/Autonomous' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    Code_Gen_Model_Disabled(&rtb_Total_Limited_l,
      &Code_Gen_Model_B.Steering_Abs_Cmd, &rtb_Minus2,
      &Code_Gen_Model_B.Translation_Angle, &rtb_Switch2_g,
      &rtb_Is_Absolute_Translation, &rtb_Compare_na);

    /* End of Outputs for SubSystem: '<S1>/Autonomous' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S1>/Teleop' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    /* Switch: '<S170>/Switch' incorporates:
     *  Constant: '<S170>/Constant'
     *  Constant: '<S170>/Constant1'
     *  Constant: '<S170>/Constant2'
     *  Inport: '<Root>/Steer_Joystick_X'
     *  Inport: '<Root>/Steer_Joystick_Y'
     *  Math: '<S170>/Hypot'
     *  RelationalOperator: '<S170>/GreaterThan'
     *  Switch: '<S170>/Switch1'
     */
    if (rt_hypotd_snf(Code_Gen_Model_U.Steer_Joystick_X,
                      Code_Gen_Model_U.Steer_Joystick_Y) > 0.7) {
      rtb_Minus2 = Code_Gen_Model_U.Steer_Joystick_X;
      rtb_Switch2_g = Code_Gen_Model_U.Steer_Joystick_Y;
    } else {
      rtb_Minus2 = 0.0;
      rtb_Switch2_g = 0.0;
    }

    /* End of Switch: '<S170>/Switch' */

    /* Switch: '<S169>/Switch2' incorporates:
     *  Constant: '<S176>/Constant'
     *  Constant: '<S177>/Constant'
     *  Logic: '<S169>/AND'
     *  RelationalOperator: '<S176>/Compare'
     *  RelationalOperator: '<S177>/Compare'
     *  Switch: '<S169>/Switch1'
     *  UnitDelay: '<S169>/Unit Delay'
     *  UnitDelay: '<S169>/Unit Delay1'
     */
    if (rtb_Minus2 == 0.0 && rtb_Switch2_g == 0.0) {
      rtb_Switch2 = Code_Gen_Model_DW.UnitDelay_DSTATE_kj;
      rtb_Switch1_b = Code_Gen_Model_DW.UnitDelay1_DSTATE_d;
    } else {
      rtb_Switch2 = rtb_Minus2;
      rtb_Switch1_b = rtb_Switch2_g;
    }

    /* End of Switch: '<S169>/Switch2' */

    /* RelationalOperator: '<S173>/Compare' incorporates:
     *  Constant: '<S173>/Constant'
     *  UnaryMinus: '<S166>/Unary Minus1'
     */
    rtb_Is_Absolute_Translation = -rtb_Switch1_b < 0.0;

    /* Switch: '<S168>/Switch' incorporates:
     *  Constant: '<S168>/Constant'
     *  Constant: '<S168>/Constant1'
     *  Constant: '<S171>/Constant'
     *  Constant: '<S172>/Constant'
     *  Logic: '<S168>/Logical Operator'
     *  RelationalOperator: '<S171>/Compare'
     *  RelationalOperator: '<S172>/Compare'
     *  UnaryMinus: '<S166>/Unary Minus2'
     *  UnitDelay: '<S168>/Unit Delay'
     */
    if (-rtb_Switch2 < 0.0 && Code_Gen_Model_DW.UnitDelay_DSTATE_gy >= 0.0 &&
        rtb_Is_Absolute_Translation) {
      rtb_Switch2_p = 6.2831853071795862;
    } else {
      rtb_Switch2_p = 0.0;
    }

    /* Switch: '<S168>/Switch1' incorporates:
     *  Constant: '<S168>/Constant2'
     *  Constant: '<S168>/Constant3'
     *  Constant: '<S174>/Constant'
     *  Constant: '<S175>/Constant'
     *  Logic: '<S168>/Logical Operator1'
     *  RelationalOperator: '<S174>/Compare'
     *  RelationalOperator: '<S175>/Compare'
     *  UnaryMinus: '<S166>/Unary Minus2'
     *  UnitDelay: '<S168>/Unit Delay'
     */
    if (Code_Gen_Model_DW.UnitDelay_DSTATE_gy < 0.0 && -rtb_Switch2 >= 0.0 &&
        rtb_Is_Absolute_Translation) {
      rtb_Sin5 = -6.2831853071795862;
    } else {
      rtb_Sin5 = 0.0;
    }

    /* Sum: '<S168>/Sum1' incorporates:
     *  Switch: '<S168>/Switch'
     *  Switch: '<S168>/Switch1'
     *  UnitDelay: '<S168>/Unit Delay1'
     */
    rtb_Sum1_m = rtb_Switch2_p + rtb_Sin5 +
      Code_Gen_Model_DW.UnitDelay1_DSTATE_dw;

    /* Sum: '<S168>/Sum' incorporates:
     *  Gain: '<S165>/Gain1'
     *  Inport: '<Root>/Gyro_Angle'
     */
    rtb_Total_Limited_l = 0.017453292519943295 * Code_Gen_Model_U.Gyro_Angle +
      rtb_Sum1_m;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Trigonometry: '<S166>/Atan2'
     *  UnaryMinus: '<S166>/Unary Minus'
     *  UnaryMinus: '<S166>/Unary Minus1'
     *  UnaryMinus: '<S166>/Unary Minus2'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd = -rt_atan2d_snf(-rtb_Switch2,
      -rtb_Switch1_b);

    /* Product: '<S166>/Product' incorporates:
     *  Constant: '<S166>/Constant'
     *  Inport: '<Root>/Steer_Joystick_X'
     *  Lookup_n-D: '<S166>/Modulation_Str_X_Rel'
     */
    rtb_Minus2 = look1_binlcpw(Code_Gen_Model_U.Steer_Joystick_X,
      Code_Gen_Model_ConstP.Modulation_Str_X_Rel_bp01Data,
      Code_Gen_Model_ConstP.Modulation_Str_X_Rel_tableData, 20U) * 1.3;

    /* Lookup_n-D: '<S167>/Modulation_Drv_X' incorporates:
     *  Inport: '<Root>/Drive_Joystick_X'
     */
    rtb_Magnitude = look1_binlcpw(Code_Gen_Model_U.Drive_Joystick_X,
      Code_Gen_Model_ConstP.pooled12, Code_Gen_Model_ConstP.pooled11, 20U);

    /* Lookup_n-D: '<S167>/Modulation_Drv_Y' incorporates:
     *  Inport: '<Root>/Drive_Joystick_Y'
     */
    rtb_Switch2_g = look1_binlcpw(Code_Gen_Model_U.Drive_Joystick_Y,
      Code_Gen_Model_ConstP.pooled12, Code_Gen_Model_ConstP.pooled11, 20U);

    /* Switch: '<S178>/Switch2' incorporates:
     *  Constant: '<S180>/Constant'
     *  Constant: '<S181>/Constant'
     *  Logic: '<S178>/AND'
     *  Lookup_n-D: '<S167>/Modulation_Drv_X'
     *  RelationalOperator: '<S180>/Compare'
     *  RelationalOperator: '<S181>/Compare'
     *  Switch: '<S178>/Switch1'
     *  UnaryMinus: '<S167>/Unary Minus'
     *  UnitDelay: '<S178>/Unit Delay'
     *  UnitDelay: '<S178>/Unit Delay1'
     */
    if (-rtb_Magnitude == 0.0 && rtb_Switch2_g == 0.0) {
      rtb_Switch2_h = Code_Gen_Model_DW.UnitDelay_DSTATE_e;
      rtb_Switch1_j = Code_Gen_Model_DW.UnitDelay1_DSTATE_g;
    } else {
      rtb_Switch2_h = -rtb_Magnitude;
      rtb_Switch1_j = rtb_Switch2_g;
    }

    /* End of Switch: '<S178>/Switch2' */

    /* Merge: '<S1>/Merge3' incorporates:
     *  Trigonometry: '<S167>/Atan2'
     */
    Code_Gen_Model_B.Translation_Angle = rt_atan2d_snf(rtb_Switch2_h,
      rtb_Switch1_j);

    /* Math: '<S167>/Magnitude' incorporates:
     *  Lookup_n-D: '<S167>/Modulation_Drv_X'
     *  UnaryMinus: '<S167>/Unary Minus'
     */
    rtb_Magnitude = rt_hypotd_snf(-rtb_Magnitude, rtb_Switch2_g);

    /* Switch: '<S179>/Switch1' incorporates:
     *  Constant: '<S179>/Constant'
     *  Constant: '<S179>/Constant1'
     *  Inport: '<Root>/Is_Boost_Trigger_Pulled'
     */
    if (Code_Gen_Model_U.Is_Boost_Trigger_Pulled != 0.0) {
      rtb_Product_jb = 3.658;
    } else {
      rtb_Product_jb = 1.5;
    }

    /* End of Switch: '<S179>/Switch1' */

    /* Switch: '<S185>/Init' incorporates:
     *  UnitDelay: '<S185>/FixPt Unit Delay1'
     *  UnitDelay: '<S185>/FixPt Unit Delay2'
     */
    if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_l != 0) {
      rtb_Switch2_g = rtb_Product_jb;
    } else {
      rtb_Switch2_g = Code_Gen_Model_DW.FixPtUnitDelay1_DSTATE_k;
    }

    /* End of Switch: '<S185>/Init' */

    /* Sum: '<S183>/Sum1' */
    rtb_Product_jb -= rtb_Switch2_g;

    /* Switch: '<S184>/Switch2' incorporates:
     *  Constant: '<S182>/Constant1'
     *  Constant: '<S182>/Constant3'
     *  RelationalOperator: '<S184>/LowerRelop1'
     *  RelationalOperator: '<S184>/UpperRelop'
     *  Switch: '<S184>/Switch'
     */
    if (rtb_Product_jb > 0.04) {
      rtb_Product_jb = 0.04;
    } else if (rtb_Product_jb < -0.044444444444444446) {
      /* Switch: '<S184>/Switch' incorporates:
       *  Constant: '<S182>/Constant1'
       */
      rtb_Product_jb = -0.044444444444444446;
    }

    /* End of Switch: '<S184>/Switch2' */

    /* Sum: '<S183>/Sum' */
    rtb_Product_jb += rtb_Switch2_g;

    /* Product: '<S179>/Product' */
    rtb_Switch2_g = rtb_Magnitude * rtb_Product_jb;

    /* Saturate: '<S179>/Saturation' */
    if (rtb_Switch2_g > 3.658) {
      rtb_Switch2_g = 3.658;
    } else if (rtb_Switch2_g < -3.658) {
      rtb_Switch2_g = -3.658;
    }

    /* End of Saturate: '<S179>/Saturation' */

    /* SignalConversion generated from: '<S5>/Is_Absolute_Translation_In' incorporates:
     *  Inport: '<Root>/Is_Absolute_Translation'
     */
    rtb_Is_Absolute_Translation = Code_Gen_Model_U.Is_Absolute_Translation;

    /* SignalConversion generated from: '<S5>/Is_Absolute_Steering_In' incorporates:
     *  Inport: '<Root>/Is_Absolute_Steering'
     */
    rtb_Compare_na = Code_Gen_Model_U.Is_Absolute_Steering;

    /* Update for UnitDelay: '<S169>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_kj = rtb_Switch2;

    /* Update for UnitDelay: '<S168>/Unit Delay' incorporates:
     *  UnaryMinus: '<S166>/Unary Minus2'
     */
    Code_Gen_Model_DW.UnitDelay_DSTATE_gy = -rtb_Switch2;

    /* Update for UnitDelay: '<S169>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_d = rtb_Switch1_b;

    /* Update for UnitDelay: '<S168>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_dw = rtb_Sum1_m;

    /* Update for UnitDelay: '<S178>/Unit Delay' */
    Code_Gen_Model_DW.UnitDelay_DSTATE_e = rtb_Switch2_h;

    /* Update for UnitDelay: '<S178>/Unit Delay1' */
    Code_Gen_Model_DW.UnitDelay1_DSTATE_g = rtb_Switch1_j;

    /* Update for UnitDelay: '<S185>/FixPt Unit Delay2' incorporates:
     *  Constant: '<S185>/FixPt Constant'
     */
    Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_l = 0U;

    /* Update for UnitDelay: '<S185>/FixPt Unit Delay1' */
    Code_Gen_Model_DW.FixPtUnitDelay1_DSTATE_k = rtb_Product_jb;

    /* End of Outputs for SubSystem: '<S1>/Teleop' */
    break;

   default:
    /* Outputs for IfAction SubSystem: '<S1>/Test' incorporates:
     *  ActionPort: '<S6>/Action Port'
     */
    rtb_Total_Limited_l = 0.0;

    /* Merge: '<S1>/Merge1' incorporates:
     *  Constant: '<S6>/Constant'
     *  Constant: '<S6>/Constant1'
     */
    Code_Gen_Model_B.Steering_Abs_Cmd = 0.0;
    rtb_Minus2 = 0.0;

    /* Merge: '<S1>/Merge3' incorporates:
     *  Constant: '<S6>/Constant2'
     *  Constant: '<S6>/Constant3'
     */
    Code_Gen_Model_B.Translation_Angle = 0.0;
    rtb_Switch2_g = 1.0;
    rtb_Is_Absolute_Translation = true;
    rtb_Compare_na = true;

    /* End of Outputs for SubSystem: '<S1>/Test' */
    break;
  }

  /* End of SwitchCase: '<S1>/Switch Case' */

  /* Signum: '<S110>/Sign2' incorporates:
   *  UnitDelay: '<S110>/Unit Delay'
   */
  if (rtIsNaN(Code_Gen_Model_B.Translation_Speed)) {
    rtb_Switch2_p = (rtNaN);
  } else if (Code_Gen_Model_B.Translation_Speed < 0.0) {
    rtb_Switch2_p = -1.0;
  } else {
    rtb_Switch2_p = Code_Gen_Model_B.Translation_Speed > 0.0;
  }

  /* Signum: '<S110>/Sign1' */
  if (rtIsNaN(rtb_Switch2_g)) {
    rtb_Sin5 = (rtNaN);
  } else if (rtb_Switch2_g < 0.0) {
    rtb_Sin5 = -1.0;
  } else {
    rtb_Sin5 = rtb_Switch2_g > 0.0;
  }

  /* Product: '<S110>/Product1' incorporates:
   *  Signum: '<S110>/Sign1'
   *  Signum: '<S110>/Sign2'
   */
  rtb_Switch2_p *= rtb_Sin5;
  if (rtIsNaN(rtb_Switch2_p)) {
    tmp = 0;
  } else {
    tmp = (int32_T)fmod(rtb_Switch2_p, 256.0);
  }

  /* Switch: '<S110>/Switch' incorporates:
   *  Constant: '<S110>/Constant'
   *  Constant: '<S118>/Constant'
   *  Constant: '<S119>/Constant'
   *  Logic: '<S110>/or'
   *  Product: '<S110>/Product1'
   *  RelationalOperator: '<S118>/Compare'
   *  RelationalOperator: '<S119>/Compare'
   *  UnitDelay: '<S110>/Unit Delay'
   */
  if (Code_Gen_Model_B.Translation_Speed == 0.0 || (tmp < 0 ? (int32_T)(int8_T)
       -(int8_T)(uint8_T)-(real_T)tmp : tmp) > 0) {
    rtb_Sin5 = rtb_Switch2_g;
  } else {
    rtb_Sin5 = 0.0;
  }

  /* End of Switch: '<S110>/Switch' */

  /* Switch: '<S124>/Init' incorporates:
   *  UnitDelay: '<S124>/FixPt Unit Delay1'
   *  UnitDelay: '<S124>/FixPt Unit Delay2'
   */
  if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE != 0) {
    rtb_Switch2_h = rtb_Sin5;
  } else {
    rtb_Switch2_h = Code_Gen_Model_B.Translation_Speed;
  }

  /* End of Switch: '<S124>/Init' */

  /* RelationalOperator: '<S120>/Compare' incorporates:
   *  Constant: '<S120>/Constant'
   */
  rtb_Compare_j = rtb_Sin5 == 0.0;

  /* RelationalOperator: '<S121>/Compare' incorporates:
   *  Constant: '<S121>/Constant'
   */
  rtb_Compare_gm = rtb_Sin5 > 0.0;

  /* Abs: '<S110>/Abs' incorporates:
   *  Sum: '<S110>/Subtract'
   *  UnitDelay: '<S110>/Unit Delay'
   */
  rtb_Switch2 = fabs(Code_Gen_Model_B.Translation_Speed - rtb_Switch2_g);

  /* Switch: '<S110>/Switch5' incorporates:
   *  Switch: '<S110>/Switch1'
   */
  if (rtb_Compare_j) {
    /* SignalConversion generated from: '<S110>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S110>/Constant4'
     *  Constant: '<S110>/Constant6'
     */
    rtb_TmpSignalConversionAtLook_n[0] = 0.01;
    rtb_TmpSignalConversionAtLook_n[1] = 1.0;

    /* SignalConversion generated from: '<S110>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S110>/Constant2'
     *  Constant: '<S110>/Constant5'
     */
    rtb_TmpSignalConversionAtLook_k[0] = 0.0;
    rtb_TmpSignalConversionAtLook_k[1] = 0.2;

    /* S-Function (sfix_look1_dyn): '<S110>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S110>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic_p),
                         &rtb_TmpSignalConversionAtLook_n[0], rtb_Switch2,
                         &rtb_TmpSignalConversionAtLook_k[0], 1U);
    rtb_Switch2 = rtb_LookupTableDynamic_p;
    rtb_Switch2_p = Code_Gen_Model_ConstB.UnaryMinus_i;
  } else {
    /* SignalConversion generated from: '<S110>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S110>/Constant10'
     *  Constant: '<S110>/Constant8'
     */
    rtb_TmpSignalConversionAtLook_n[0] = 0.05;
    rtb_TmpSignalConversionAtLook_n[1] = 1.0;

    /* SignalConversion generated from: '<S110>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S110>/Constant7'
     *  Constant: '<S110>/Constant9'
     */
    rtb_TmpSignalConversionAtLook_k[0] = 0.0;
    rtb_TmpSignalConversionAtLook_k[1] = 0.15;

    /* S-Function (sfix_look1_dyn): '<S110>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S110>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1_l),
                         &rtb_TmpSignalConversionAtLook_n[0], rtb_Switch2,
                         &rtb_TmpSignalConversionAtLook_k[0], 1U);
    rtb_Switch2 = rtb_LookupTableDynamic1_l;

    /* Switch: '<S110>/Switch3' incorporates:
     *  Constant: '<S110>/Constant3'
     */
    if (rtb_Compare_gm) {
      rtb_Switch2_p = 0.085714285714285715;
    } else {
      rtb_Switch2_p = Code_Gen_Model_ConstB.UnaryMinus_i;
    }

    /* End of Switch: '<S110>/Switch3' */
  }

  /* End of Switch: '<S110>/Switch5' */

  /* Product: '<S110>/Product' incorporates:
   *  Switch: '<S110>/Switch1'
   */
  rtb_Switch2_p *= rtb_Switch2;

  /* Sum: '<S122>/Sum1' */
  rtb_Switch1_b = rtb_Sin5 - rtb_Switch2_h;

  /* Switch: '<S123>/Switch2' incorporates:
   *  RelationalOperator: '<S123>/LowerRelop1'
   */
  if (!(rtb_Switch1_b > rtb_Switch2_p)) {
    /* Switch: '<S110>/Switch2' incorporates:
     *  Constant: '<S110>/Constant1'
     *  Switch: '<S110>/Switch4'
     */
    if (rtb_Compare_j) {
      rtb_Switch2_p = -0.2;
    } else if (rtb_Compare_gm) {
      /* Switch: '<S110>/Switch4' incorporates:
       *  Constant: '<S110>/Constant1'
       */
      rtb_Switch2_p = -0.2;
    } else {
      rtb_Switch2_p = Code_Gen_Model_ConstB.UnaryMinus1;
    }

    /* Product: '<S110>/Product2' incorporates:
     *  Switch: '<S110>/Switch2'
     */
    rtb_Sum1_m = rtb_Switch2_p * rtb_Switch2;

    /* Switch: '<S123>/Switch' incorporates:
     *  RelationalOperator: '<S123>/UpperRelop'
     */
    if (rtb_Switch1_b < rtb_Sum1_m) {
      rtb_Switch2_p = rtb_Sum1_m;
    } else {
      rtb_Switch2_p = rtb_Switch1_b;
    }

    /* End of Switch: '<S123>/Switch' */
  }

  /* End of Switch: '<S123>/Switch2' */

  /* Sum: '<S122>/Sum' */
  Code_Gen_Model_B.Translation_Speed = rtb_Switch2_p + rtb_Switch2_h;

  /* Switch: '<S112>/Switch' */
  if (rtb_Is_Absolute_Translation) {
    /* UnaryMinus: '<S112>/Unary Minus' incorporates:
     *  Constant: '<S139>/Constant3'
     *  Constant: '<S139>/Constant4'
     *  Gain: '<S7>/Gain1'
     *  Inport: '<Root>/Gyro_Angle'
     *  Math: '<S139>/Math Function'
     *  Sum: '<S139>/Add1'
     *  Sum: '<S139>/Add2'
     */
    Code_Gen_Model_B.Translation_Steering_Cmd = -(rt_modd_snf
      (Code_Gen_Model_B.Translation_Angle - 0.017453292519943295 *
       Code_Gen_Model_U.Gyro_Angle + 3.1415926535897931, 6.2831853071795862) -
      3.1415926535897931);
  } else {
    /* UnaryMinus: '<S112>/Unary Minus' */
    Code_Gen_Model_B.Translation_Steering_Cmd =
      -Code_Gen_Model_B.Translation_Angle;
  }

  /* End of Switch: '<S112>/Switch' */

  /* Sum: '<S134>/Sum' */
  rtb_Total_Limited_l = Code_Gen_Model_B.Steering_Abs_Cmd - rtb_Total_Limited_l;

  /* Sum: '<S138>/Subtract1' incorporates:
   *  Product: '<S138>/Divide'
   *  Product: '<S138>/Product'
   *  Rounding: '<S138>/Fix'
   *  Sum: '<S138>/Minus'
   */
  rtb_Total_Limited_l -= trunc((rtb_Total_Limited_l -
    Code_Gen_Model_ConstB.UnaryMinus_mw) / Code_Gen_Model_ConstB.Modulus_a) *
    Code_Gen_Model_ConstB.Modulus_a;

  /* Sum: '<S138>/Minus2' incorporates:
   *  Product: '<S138>/Divide1'
   *  Product: '<S138>/Product1'
   *  Rounding: '<S138>/Fix1'
   *  Sum: '<S138>/Minus1'
   */
  rtb_Total_Limited_l -= trunc((rtb_Total_Limited_l -
    Code_Gen_Model_ConstB.Error_Bound_f) / Code_Gen_Model_ConstB.Modulus_a) *
    Code_Gen_Model_ConstB.Modulus_a;

  /* Sum: '<S136>/Sum1' incorporates:
   *  Constant: '<S134>/Constant2'
   *  Product: '<S136>/Product'
   *  Sum: '<S136>/Sum'
   *  UnitDelay: '<S136>/Unit Delay1'
   */
  rtb_Switch2 = (rtb_Total_Limited_l - Code_Gen_Model_DW.UnitDelay1_DSTATE) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE;

  /* Product: '<S134>/Product' incorporates:
   *  Constant: '<S134>/Constant3'
   */
  rtb_Switch1_b = rtb_Switch2 * 0.0;

  /* Sum: '<S135>/Diff' incorporates:
   *  UnitDelay: '<S135>/UD'
   *
   * Block description for '<S135>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S135>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_k = rtb_Switch1_b - Code_Gen_Model_DW.UD_DSTATE;

  /* Saturate: '<S134>/Saturation' */
  if (rtb_Add_k > 0.0) {
    rtb_Add_k = 0.0;
  } else if (rtb_Add_k < -0.0) {
    rtb_Add_k = -0.0;
  }

  /* Sum: '<S134>/Add' incorporates:
   *  Gain: '<S134>/Gain1'
   *  Saturate: '<S134>/Saturation'
   */
  rtb_Switch2_g = 1.5 * rtb_Total_Limited_l + rtb_Add_k;

  /* Sum: '<S134>/Subtract' incorporates:
   *  Constant: '<S134>/Constant'
   */
  rtb_Switch2_h = 1.3 - rtb_Switch2_g;

  /* Sum: '<S134>/Sum2' incorporates:
   *  Gain: '<S134>/Gain2'
   *  UnitDelay: '<S134>/Unit Delay'
   */
  rtb_Sum1_m = 0.015 * rtb_Total_Limited_l +
    Code_Gen_Model_DW.UnitDelay_DSTATE_g;

  /* Switch: '<S137>/Switch2' incorporates:
   *  Constant: '<S134>/Constant'
   *  RelationalOperator: '<S137>/LowerRelop1'
   *  Sum: '<S134>/Subtract'
   */
  if (!(rtb_Sum1_m > 1.3 - rtb_Switch2_g)) {
    /* Sum: '<S134>/Subtract1' incorporates:
     *  Constant: '<S134>/Constant1'
     */
    rtb_Switch2_h = -1.3 - rtb_Switch2_g;

    /* Switch: '<S137>/Switch' incorporates:
     *  Constant: '<S134>/Constant1'
     *  RelationalOperator: '<S137>/UpperRelop'
     *  Sum: '<S134>/Subtract1'
     */
    if (!(rtb_Sum1_m < -1.3 - rtb_Switch2_g)) {
      rtb_Switch2_h = rtb_Sum1_m;
    }

    /* End of Switch: '<S137>/Switch' */
  }

  /* End of Switch: '<S137>/Switch2' */

  /* Saturate: '<S134>/Saturation1' */
  if (rtb_Switch2_h > 0.1) {
    rtb_Sum1_m = 0.1;
  } else if (rtb_Switch2_h < -0.1) {
    rtb_Sum1_m = -0.1;
  } else {
    rtb_Sum1_m = rtb_Switch2_h;
  }

  /* End of Saturate: '<S134>/Saturation1' */

  /* Switch: '<S111>/Switch' */
  if (rtb_Compare_na) {
    /* Sum: '<S134>/Add1' */
    rtb_Minus2 = rtb_Switch2_g + rtb_Sum1_m;

    /* Saturate: '<S134>/Saturation2' */
    if (rtb_Minus2 > 1.3) {
      rtb_Minus2 = 1.3;
    } else if (rtb_Minus2 < -1.3) {
      rtb_Minus2 = -1.3;
    }

    /* End of Saturate: '<S134>/Saturation2' */

    /* DeadZone: '<S126>/Dead Zone' */
    if (rtb_Minus2 > 0.01) {
      rtb_Minus2 -= 0.01;
    } else if (rtb_Minus2 >= -0.01) {
      rtb_Minus2 = 0.0;
    } else {
      rtb_Minus2 -= -0.01;
    }

    /* End of DeadZone: '<S126>/Dead Zone' */
  }

  /* End of Switch: '<S111>/Switch' */

  /* Signum: '<S125>/Sign2' incorporates:
   *  UnitDelay: '<S125>/Unit Delay'
   */
  if (rtIsNaN(Code_Gen_Model_B.Steering_Localized_Cmd)) {
    rtb_Switch2_p = (rtNaN);
  } else if (Code_Gen_Model_B.Steering_Localized_Cmd < 0.0) {
    rtb_Switch2_p = -1.0;
  } else {
    rtb_Switch2_p = Code_Gen_Model_B.Steering_Localized_Cmd > 0.0;
  }

  /* Signum: '<S125>/Sign1' */
  if (rtIsNaN(rtb_Minus2)) {
    rtb_Sin5 = (rtNaN);
  } else if (rtb_Minus2 < 0.0) {
    rtb_Sin5 = -1.0;
  } else {
    rtb_Sin5 = rtb_Minus2 > 0.0;
  }

  /* Product: '<S125>/Product1' incorporates:
   *  Signum: '<S125>/Sign1'
   *  Signum: '<S125>/Sign2'
   */
  rtb_Switch2_p *= rtb_Sin5;
  if (rtIsNaN(rtb_Switch2_p)) {
    tmp = 0;
  } else {
    tmp = (int32_T)fmod(rtb_Switch2_p, 256.0);
  }

  /* Switch: '<S125>/Switch' incorporates:
   *  Constant: '<S125>/Constant'
   *  Constant: '<S127>/Constant'
   *  Constant: '<S128>/Constant'
   *  Logic: '<S125>/or'
   *  Product: '<S125>/Product1'
   *  RelationalOperator: '<S127>/Compare'
   *  RelationalOperator: '<S128>/Compare'
   *  UnitDelay: '<S125>/Unit Delay'
   */
  if (Code_Gen_Model_B.Steering_Localized_Cmd == 0.0 || (tmp < 0 ? (int32_T)
       (int8_T)-(int8_T)(uint8_T)-(real_T)tmp : tmp) > 0) {
    rtb_Switch2_h = rtb_Minus2;
  } else {
    rtb_Switch2_h = 0.0;
  }

  /* End of Switch: '<S125>/Switch' */

  /* Switch: '<S133>/Init' incorporates:
   *  UnitDelay: '<S133>/FixPt Unit Delay1'
   *  UnitDelay: '<S133>/FixPt Unit Delay2'
   */
  if (Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_d != 0) {
    rtb_Switch1_j = rtb_Switch2_h;
  } else {
    rtb_Switch1_j = Code_Gen_Model_B.Steering_Localized_Cmd;
  }

  /* End of Switch: '<S133>/Init' */

  /* RelationalOperator: '<S129>/Compare' incorporates:
   *  Constant: '<S129>/Constant'
   */
  rtb_Is_Absolute_Translation = rtb_Switch2_h == 0.0;

  /* RelationalOperator: '<S130>/Compare' incorporates:
   *  Constant: '<S130>/Constant'
   */
  rtb_Compare_na = rtb_Switch2_h > 0.0;

  /* Abs: '<S125>/Abs' incorporates:
   *  Sum: '<S125>/Subtract'
   *  UnitDelay: '<S125>/Unit Delay'
   */
  rtb_Minus2 = fabs(Code_Gen_Model_B.Steering_Localized_Cmd - rtb_Minus2);

  /* Switch: '<S125>/Switch5' incorporates:
   *  Switch: '<S125>/Switch1'
   */
  if (rtb_Is_Absolute_Translation) {
    /* SignalConversion generated from: '<S125>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S125>/Constant4'
     *  Constant: '<S125>/Constant6'
     */
    rtb_TmpSignalConversionAtLook_n[0] = 0.01;
    rtb_TmpSignalConversionAtLook_n[1] = 1.0;

    /* SignalConversion generated from: '<S125>/Lookup Table Dynamic' incorporates:
     *  Constant: '<S125>/Constant2'
     *  Constant: '<S125>/Constant5'
     */
    rtb_TmpSignalConversionAtLook_k[0] = 0.0;
    rtb_TmpSignalConversionAtLook_k[1] = 0.2;

    /* S-Function (sfix_look1_dyn): '<S125>/Lookup Table Dynamic' */
    /* Dynamic Look-Up Table Block: '<S125>/Lookup Table Dynamic'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic),
                         &rtb_TmpSignalConversionAtLook_n[0], rtb_Minus2,
                         &rtb_TmpSignalConversionAtLook_k[0], 1U);
    rtb_Minus2 = rtb_LookupTableDynamic;
    rtb_Switch2_p = Code_Gen_Model_ConstB.UnaryMinus_c;
  } else {
    /* SignalConversion generated from: '<S125>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S125>/Constant10'
     *  Constant: '<S125>/Constant8'
     */
    rtb_TmpSignalConversionAtLook_n[0] = 0.1;
    rtb_TmpSignalConversionAtLook_n[1] = 1.0;

    /* SignalConversion generated from: '<S125>/Lookup Table Dynamic1' incorporates:
     *  Constant: '<S125>/Constant7'
     *  Constant: '<S125>/Constant9'
     */
    rtb_TmpSignalConversionAtLook_k[0] = 0.0;
    rtb_TmpSignalConversionAtLook_k[1] = 0.2;

    /* S-Function (sfix_look1_dyn): '<S125>/Lookup Table Dynamic1' */
    /* Dynamic Look-Up Table Block: '<S125>/Lookup Table Dynamic1'
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Input2  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     */
    LookUp_real_T_real_T( &(rtb_LookupTableDynamic1),
                         &rtb_TmpSignalConversionAtLook_n[0], rtb_Minus2,
                         &rtb_TmpSignalConversionAtLook_k[0], 1U);
    rtb_Minus2 = rtb_LookupTableDynamic1;

    /* Switch: '<S125>/Switch3' incorporates:
     *  Constant: '<S125>/Constant3'
     */
    if (rtb_Compare_na) {
      rtb_Switch2_p = 1.0;
    } else {
      rtb_Switch2_p = Code_Gen_Model_ConstB.UnaryMinus_c;
    }

    /* End of Switch: '<S125>/Switch3' */
  }

  /* End of Switch: '<S125>/Switch5' */

  /* Product: '<S125>/Product' incorporates:
   *  Switch: '<S125>/Switch1'
   */
  rtb_Switch2_g = rtb_Switch2_p * rtb_Minus2;

  /* Sum: '<S131>/Sum1' */
  rtb_Switch2_h -= rtb_Switch1_j;

  /* Switch: '<S132>/Switch2' incorporates:
   *  RelationalOperator: '<S132>/LowerRelop1'
   */
  if (!(rtb_Switch2_h > rtb_Switch2_g)) {
    /* Switch: '<S125>/Switch2' incorporates:
     *  Constant: '<S125>/Constant1'
     *  Switch: '<S125>/Switch4'
     */
    if (rtb_Is_Absolute_Translation) {
      rtb_Switch2_p = -1.0;
    } else if (rtb_Compare_na) {
      /* Switch: '<S125>/Switch4' incorporates:
       *  Constant: '<S125>/Constant1'
       */
      rtb_Switch2_p = -1.0;
    } else {
      rtb_Switch2_p = Code_Gen_Model_ConstB.UnaryMinus1_c;
    }

    /* Product: '<S125>/Product2' incorporates:
     *  Switch: '<S125>/Switch2'
     */
    rtb_Switch2_g = rtb_Switch2_p * rtb_Minus2;

    /* Switch: '<S132>/Switch' incorporates:
     *  RelationalOperator: '<S132>/UpperRelop'
     */
    if (!(rtb_Switch2_h < rtb_Switch2_g)) {
      rtb_Switch2_g = rtb_Switch2_h;
    }

    /* End of Switch: '<S132>/Switch' */
  }

  /* End of Switch: '<S132>/Switch2' */

  /* Sum: '<S131>/Sum' */
  Code_Gen_Model_B.Steering_Localized_Cmd = rtb_Switch2_g + rtb_Switch1_j;

  /* Fcn: '<S146>/r->x' incorporates:
   *  Fcn: '<S151>/r->x'
   *  Fcn: '<S156>/r->x'
   *  Fcn: '<S161>/r->x'
   */
  rtb_Switch2_g = Code_Gen_Model_B.Translation_Speed * cos
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S140>/Add' incorporates:
   *  Fcn: '<S146>/r->x'
   *  Fcn: '<S147>/r->x'
   */
  rtb_TmpSignalConversionAtLook_n[0] = Code_Gen_Model_B.Steering_Localized_Cmd *
    cos(Code_Gen_Model_ConstB.Atan2_k) + rtb_Switch2_g;

  /* Fcn: '<S146>/theta->y' incorporates:
   *  Fcn: '<S151>/theta->y'
   *  Fcn: '<S156>/theta->y'
   *  Fcn: '<S161>/theta->y'
   */
  rtb_Total_Limited_l = Code_Gen_Model_B.Translation_Speed * sin
    (Code_Gen_Model_B.Translation_Steering_Cmd);

  /* Sum: '<S140>/Add' incorporates:
   *  Fcn: '<S146>/theta->y'
   *  Fcn: '<S147>/theta->y'
   */
  rtb_TmpSignalConversionAtLook_n[1] = Code_Gen_Model_B.Steering_Localized_Cmd *
    sin(Code_Gen_Model_ConstB.Atan2_k) + rtb_Total_Limited_l;

  /* Sum: '<S141>/Add' incorporates:
   *  Fcn: '<S152>/r->x'
   *  Fcn: '<S152>/theta->y'
   */
  rtb_TmpSignalConversionAtLook_k[0] = Code_Gen_Model_B.Steering_Localized_Cmd *
    cos(Code_Gen_Model_ConstB.Atan2) + rtb_Switch2_g;
  rtb_TmpSignalConversionAtLook_k[1] = Code_Gen_Model_B.Steering_Localized_Cmd *
    sin(Code_Gen_Model_ConstB.Atan2) + rtb_Total_Limited_l;

  /* Sum: '<S142>/Add' incorporates:
   *  Fcn: '<S157>/r->x'
   *  Fcn: '<S157>/theta->y'
   */
  rtb_Add_d_idx_0 = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.Atan2_i) + rtb_Switch2_g;
  rtb_Add_d_idx_1 = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.Atan2_i) + rtb_Total_Limited_l;

  /* Sum: '<S143>/Add' incorporates:
   *  Fcn: '<S162>/r->x'
   *  Fcn: '<S162>/theta->y'
   */
  rtb_Minus2 = Code_Gen_Model_B.Steering_Localized_Cmd * cos
    (Code_Gen_Model_ConstB.Atan2_p) + rtb_Switch2_g;
  rtb_Magnitude = Code_Gen_Model_B.Steering_Localized_Cmd * sin
    (Code_Gen_Model_ConstB.Atan2_p) + rtb_Total_Limited_l;

  /* Fcn: '<S160>/x->r' */
  rtb_Total_Limited_l = rt_hypotd_snf(rtb_Minus2, rtb_Magnitude);

  /* Switch: '<S159>/Switch1' incorporates:
   *  Constant: '<S159>/Constant'
   *  Constant: '<S163>/Constant'
   *  RelationalOperator: '<S163>/Compare'
   *  Switch: '<S159>/Switch'
   */
  if (rtb_Total_Limited_l == 0.0) {
    rtb_Switch2_g = 1.0E-15;
  } else {
    rtb_Switch2_g = rtb_Total_Limited_l;

    /* Switch: '<S159>/Switch' incorporates:
     *  Fcn: '<S160>/x->theta'
     */
    Code_Gen_Model_B.Desired_Module_Angle = rt_atan2d_snf(rtb_Magnitude,
      rtb_Minus2);
  }

  /* End of Switch: '<S159>/Switch1' */

  /* Trigonometry: '<S105>/Cos4' incorporates:
   *  Switch: '<S89>/Angle_Switch'
   *  Trigonometry: '<S104>/Cos4'
   */
  rtb_Add_i = cos(Code_Gen_Model_B.Desired_Module_Angle);

  /* Abs: '<S88>/Abs' incorporates:
   *  Inport: '<Root>/BackRight_Steer_Encoder'
   */
  rtb_Abs_b = fabs(Code_Gen_Model_U.BackRight_Steer_Encoder);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_b,
    &Code_Gen_Model_B.ModulobyConstant_i);

  /* Switch: '<S88>/Switch' incorporates:
   *  Constant: '<S101>/Constant'
   *  Inport: '<Root>/BackRight_Steer_Encoder'
   *  RelationalOperator: '<S101>/Compare'
   *  UnaryMinus: '<S88>/Unary Minus'
   */
  if (Code_Gen_Model_U.BackRight_Steer_Encoder >= 0.0) {
    rtb_Minus2 = Code_Gen_Model_B.ModulobyConstant_i.ModulobyConstant;
  } else {
    rtb_Minus2 = -Code_Gen_Model_B.ModulobyConstant_i.ModulobyConstant;
  }

  /* End of Switch: '<S88>/Switch' */

  /* Sum: '<S87>/Add' incorporates:
   *  Inport: '<Root>/BackRight_Turn_Offset'
   */
  rtb_Minus2 -= Code_Gen_Model_U.BackRight_Turn_Offset;

  /* Abs: '<S99>/Abs' */
  rtb_Abs_j = fabs(rtb_Minus2);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_j,
    &Code_Gen_Model_B.ModulobyConstant_l);

  /* Switch: '<S99>/Switch' incorporates:
   *  Constant: '<S100>/Constant'
   *  RelationalOperator: '<S100>/Compare'
   *  UnaryMinus: '<S99>/Unary Minus'
   */
  if (rtb_Minus2 >= 0.0) {
    rtb_Switch2_p = Code_Gen_Model_B.ModulobyConstant_l.ModulobyConstant;
  } else {
    rtb_Switch2_p = -Code_Gen_Model_B.ModulobyConstant_l.ModulobyConstant;
  }

  /* Gain: '<S87>/Gain' incorporates:
   *  Switch: '<S99>/Switch'
   */
  rtb_Minus2 = 6.2831853071795862 * rtb_Switch2_p;

  /* Trigonometry: '<S105>/Sin5' incorporates:
   *  UnaryMinus: '<S103>/Unary Minus'
   */
  rtb_Sin5 = sin(-rtb_Minus2);

  /* Trigonometry: '<S105>/Sin4' incorporates:
   *  Switch: '<S89>/Angle_Switch'
   *  Trigonometry: '<S104>/Sin4'
   */
  rtb_Subtract_e = sin(Code_Gen_Model_B.Desired_Module_Angle);

  /* Trigonometry: '<S105>/Cos5' incorporates:
   *  UnaryMinus: '<S103>/Unary Minus'
   */
  rtb_Switch2_p = cos(-rtb_Minus2);

  /* Sum: '<S105>/Subtract1' incorporates:
   *  Product: '<S105>/Product2'
   *  Product: '<S105>/Product3'
   *  Trigonometry: '<S105>/Cos4'
   *  Trigonometry: '<S105>/Sin4'
   */
  rtb_Switch2_h = rtb_Add_i * rtb_Sin5 + rtb_Subtract_e * rtb_Switch2_p;

  /* Sum: '<S105>/Subtract' incorporates:
   *  Product: '<S105>/Product'
   *  Product: '<S105>/Product1'
   *  Trigonometry: '<S105>/Cos4'
   *  Trigonometry: '<S105>/Sin4'
   */
  rtb_Switch1_j = rtb_Add_i * rtb_Switch2_p - rtb_Subtract_e * rtb_Sin5;

  /* Math: '<S105>/Hypot' */
  rtb_Magnitude = rt_hypotd_snf(rtb_Switch1_j, rtb_Switch2_h);

  /* Switch: '<S105>/Switch' incorporates:
   *  Constant: '<S105>/Constant'
   *  Constant: '<S105>/Constant1'
   *  Constant: '<S106>/Constant'
   *  Product: '<S105>/Divide'
   *  Product: '<S105>/Divide1'
   *  RelationalOperator: '<S106>/Compare'
   *  Switch: '<S105>/Switch1'
   */
  if (rtb_Magnitude > 1.0E-6) {
    rtb_Total_Limited_l = rtb_Switch2_h / rtb_Magnitude;
    rtb_Switch2_p = rtb_Switch1_j / rtb_Magnitude;
  } else {
    rtb_Total_Limited_l = 0.0;
    rtb_Switch2_p = 1.0;
  }

  /* End of Switch: '<S105>/Switch' */

  /* RelationalOperator: '<S102>/Compare' incorporates:
   *  Abs: '<S89>/Abs'
   *  Constant: '<S102>/Constant'
   *  Trigonometry: '<S105>/Atan1'
   */
  rtb_Compare_na = fabs(rt_atan2d_snf(rtb_Total_Limited_l, rtb_Switch2_p)) >
    1.5707963267948966;

  /* Switch: '<S89>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S89>/Unary Minus'
   */
  if (rtb_Compare_na) {
    rtb_Switch2_g = -rtb_Switch2_g;
  }

  /* Product: '<S91>/Product2' incorporates:
   *  Constant: '<S91>/Constant'
   *  Switch: '<S89>/Speed_Switch'
   */
  Code_Gen_Model_B.Optimized_Motor_Speed = rtb_Switch2_g * 1530.1401357649195;

  /* Signum: '<S90>/Sign' */
  if (rtIsNaN(Code_Gen_Model_B.Optimized_Motor_Speed)) {
    rtb_Switch2_p = (rtNaN);
  } else if (Code_Gen_Model_B.Optimized_Motor_Speed < 0.0) {
    rtb_Switch2_p = -1.0;
  } else {
    rtb_Switch2_p = Code_Gen_Model_B.Optimized_Motor_Speed > 0.0;
  }

  /* Signum: '<S90>/Sign1' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Encoder'
   */
  if (rtIsNaN(Code_Gen_Model_U.BackRight_Drive_Encoder)) {
    rtb_Sin5 = (rtNaN);
  } else if (Code_Gen_Model_U.BackRight_Drive_Encoder < 0.0) {
    rtb_Sin5 = -1.0;
  } else {
    rtb_Sin5 = Code_Gen_Model_U.BackRight_Drive_Encoder > 0.0;
  }

  /* Switch: '<S90>/Switch' incorporates:
   *  Abs: '<S90>/Abs'
   *  Constant: '<S108>/Constant'
   *  Inport: '<Root>/BackRight_Drive_Encoder'
   *  Logic: '<S90>/OR'
   *  RelationalOperator: '<S108>/Compare'
   *  RelationalOperator: '<S90>/Equal1'
   *  Signum: '<S90>/Sign'
   *  Signum: '<S90>/Sign1'
   */
  if (rtb_Switch2_p == rtb_Sin5 || fabs(Code_Gen_Model_U.BackRight_Drive_Encoder)
      <= 600.0) {
    /* Switch: '<S90>/Switch' */
    Code_Gen_Model_B.Adj_Cmd = Code_Gen_Model_B.Optimized_Motor_Speed;
  } else {
    /* Switch: '<S90>/Switch' incorporates:
     *  Constant: '<S90>/Constant'
     */
    Code_Gen_Model_B.Adj_Cmd = 0.0;
  }

  /* End of Switch: '<S90>/Switch' */

  /* Sum: '<S86>/Sum' incorporates:
   *  Inport: '<Root>/BackRight_Drive_Encoder'
   */
  rtb_Total_Limited_l = Code_Gen_Model_B.Adj_Cmd -
    Code_Gen_Model_U.BackRight_Drive_Encoder;

  /* Sum: '<S97>/Sum1' incorporates:
   *  Constant: '<S86>/Constant2'
   *  Product: '<S97>/Product'
   *  Sum: '<S97>/Sum'
   *  UnitDelay: '<S97>/Unit Delay1'
   */
  rtb_Switch2_g = (rtb_Total_Limited_l - Code_Gen_Model_DW.UnitDelay1_DSTATE_m) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_m;

  /* Product: '<S86>/Product' incorporates:
   *  Constant: '<S86>/Constant3'
   */
  rtb_Switch2_h = rtb_Switch2_g * 9.9999999999999991E-5;

  /* Sum: '<S96>/Diff' incorporates:
   *  UnitDelay: '<S96>/UD'
   *
   * Block description for '<S96>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S96>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_k = rtb_Switch2_h - Code_Gen_Model_DW.UD_DSTATE_j;

  /* Saturate: '<S86>/Saturation' */
  if (rtb_Add_k > 0.2) {
    rtb_Add_k = 0.2;
  } else if (rtb_Add_k < -0.2) {
    rtb_Add_k = -0.2;
  }

  /* Sum: '<S86>/Add' incorporates:
   *  Gain: '<S86>/Gain'
   *  Gain: '<S86>/Gain1'
   *  Saturate: '<S86>/Saturation'
   */
  rtb_Magnitude = 0.00018181818181818181 * Code_Gen_Model_B.Adj_Cmd + 5.0E-6 *
    rtb_Total_Limited_l + rtb_Add_k;

  /* Sum: '<S86>/Subtract' incorporates:
   *  Constant: '<S86>/Constant'
   */
  rtb_Switch2_p = 1.0 - rtb_Magnitude;

  /* Sum: '<S86>/Sum2' incorporates:
   *  Gain: '<S86>/Gain2'
   *  UnitDelay: '<S86>/Unit Delay'
   */
  rtb_Switch1_j = 0.0 * rtb_Total_Limited_l +
    Code_Gen_Model_DW.UnitDelay_DSTATE_c3;

  /* Switch: '<S98>/Switch2' incorporates:
   *  Constant: '<S86>/Constant'
   *  RelationalOperator: '<S98>/LowerRelop1'
   *  Sum: '<S86>/Subtract'
   */
  if (!(rtb_Switch1_j > 1.0 - rtb_Magnitude)) {
    /* Switch: '<S98>/Switch' incorporates:
     *  Constant: '<S86>/Constant1'
     *  RelationalOperator: '<S98>/UpperRelop'
     *  Sum: '<S86>/Subtract1'
     */
    if (rtb_Switch1_j < -1.0 - rtb_Magnitude) {
      rtb_Switch2_p = -1.0 - rtb_Magnitude;
    } else {
      rtb_Switch2_p = rtb_Switch1_j;
    }

    /* End of Switch: '<S98>/Switch' */
  }

  /* End of Switch: '<S98>/Switch2' */

  /* Saturate: '<S86>/Saturation1' */
  if (rtb_Switch2_p > 0.0) {
    rtb_Switch1_j = 0.0;
  } else if (rtb_Switch2_p < -0.0) {
    rtb_Switch1_j = -0.0;
  } else {
    rtb_Switch1_j = rtb_Switch2_p;
  }

  /* End of Saturate: '<S86>/Saturation1' */

  /* Sum: '<S86>/Add1' */
  rtb_Add_k = rtb_Magnitude + rtb_Switch1_j;

  /* Saturate: '<S86>/Saturation2' */
  if (rtb_Add_k > 1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_k < -1.0) {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Drive_DutyCycle = rtb_Add_k;
  }

  /* End of Saturate: '<S86>/Saturation2' */

  /* Switch: '<S89>/Angle_Switch' */
  if (rtb_Compare_na) {
    /* Sum: '<S104>/Subtract1' incorporates:
     *  Product: '<S104>/Product2'
     *  Product: '<S104>/Product3'
     */
    rtb_Magnitude = rtb_Add_i * Code_Gen_Model_ConstB.Sin5_a + rtb_Subtract_e *
      Code_Gen_Model_ConstB.Cos5_m;

    /* Sum: '<S104>/Subtract' incorporates:
     *  Product: '<S104>/Product'
     *  Product: '<S104>/Product1'
     */
    rtb_Subtract_l = rtb_Add_i * Code_Gen_Model_ConstB.Cos5_m - rtb_Subtract_e *
      Code_Gen_Model_ConstB.Sin5_a;

    /* Math: '<S104>/Hypot' */
    rtb_Product_jb = rt_hypotd_snf(rtb_Subtract_l, rtb_Magnitude);

    /* Switch: '<S104>/Switch1' incorporates:
     *  Constant: '<S104>/Constant'
     *  Constant: '<S104>/Constant1'
     *  Constant: '<S107>/Constant'
     *  Product: '<S104>/Divide'
     *  Product: '<S104>/Divide1'
     *  RelationalOperator: '<S107>/Compare'
     *  Switch: '<S104>/Switch'
     */
    if (rtb_Product_jb > 1.0E-6) {
      rtb_Subtract_l /= rtb_Product_jb;
      rtb_Magnitude /= rtb_Product_jb;
    } else {
      rtb_Subtract_l = 1.0;
      rtb_Magnitude = 0.0;
    }

    /* End of Switch: '<S104>/Switch1' */

    /* Switch: '<S89>/Angle_Switch' incorporates:
     *  Trigonometry: '<S104>/Atan1'
     */
    Code_Gen_Model_B.Optimized_Module_Angle = rt_atan2d_snf(rtb_Magnitude,
      rtb_Subtract_l);
  } else {
    /* Switch: '<S89>/Angle_Switch' */
    Code_Gen_Model_B.Optimized_Module_Angle =
      Code_Gen_Model_B.Desired_Module_Angle;
  }

  /* Sum: '<S85>/Sum' */
  rtb_Minus2 = Code_Gen_Model_B.Optimized_Module_Angle - rtb_Minus2;

  /* Sum: '<S95>/Subtract1' incorporates:
   *  Product: '<S95>/Divide'
   *  Product: '<S95>/Product'
   *  Rounding: '<S95>/Fix'
   *  Sum: '<S95>/Minus'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.UnaryMinus_l) /
                      Code_Gen_Model_ConstB.Modulus_m) *
    Code_Gen_Model_ConstB.Modulus_m;

  /* Sum: '<S95>/Minus2' incorporates:
   *  Product: '<S95>/Divide1'
   *  Product: '<S95>/Product1'
   *  Rounding: '<S95>/Fix1'
   *  Sum: '<S95>/Minus1'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.Error_Bound_c) /
                      Code_Gen_Model_ConstB.Modulus_m) *
    Code_Gen_Model_ConstB.Modulus_m;

  /* Sum: '<S93>/Sum1' incorporates:
   *  Constant: '<S85>/Constant2'
   *  Product: '<S93>/Product'
   *  Sum: '<S93>/Sum'
   *  UnitDelay: '<S93>/Unit Delay1'
   */
  rtb_Magnitude = (rtb_Minus2 - Code_Gen_Model_DW.UnitDelay1_DSTATE_k) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_k;

  /* Product: '<S85>/Product' incorporates:
   *  Constant: '<S85>/Constant3'
   */
  rtb_Product_jb = rtb_Magnitude * 0.5;

  /* Sum: '<S92>/Diff' incorporates:
   *  UnitDelay: '<S92>/UD'
   *
   * Block description for '<S92>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S92>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_k = rtb_Product_jb - Code_Gen_Model_DW.UD_DSTATE_l;

  /* Saturate: '<S85>/Saturation' */
  if (rtb_Add_k > 0.2) {
    rtb_Add_k = 0.2;
  } else if (rtb_Add_k < -0.2) {
    rtb_Add_k = -0.2;
  }

  /* Sum: '<S85>/Add' incorporates:
   *  Gain: '<S85>/Gain1'
   *  Saturate: '<S85>/Saturation'
   */
  rtb_Add_hu = 0.15 * rtb_Minus2 + rtb_Add_k;

  /* Sum: '<S85>/Subtract' incorporates:
   *  Constant: '<S85>/Constant'
   */
  rtb_Total_Limited_l = 1.0 - rtb_Add_hu;

  /* Sum: '<S85>/Sum2' incorporates:
   *  Gain: '<S85>/Gain2'
   *  UnitDelay: '<S85>/Unit Delay'
   */
  rtb_Minus2 = 0.005 * rtb_Minus2 + Code_Gen_Model_DW.UnitDelay_DSTATE_d;

  /* Switch: '<S94>/Switch2' incorporates:
   *  Constant: '<S85>/Constant'
   *  RelationalOperator: '<S94>/LowerRelop1'
   *  Sum: '<S85>/Subtract'
   */
  if (!(rtb_Minus2 > 1.0 - rtb_Add_hu)) {
    /* Switch: '<S94>/Switch' incorporates:
     *  Constant: '<S85>/Constant1'
     *  RelationalOperator: '<S94>/UpperRelop'
     *  Sum: '<S85>/Subtract1'
     */
    if (rtb_Minus2 < -1.0 - rtb_Add_hu) {
      rtb_Total_Limited_l = -1.0 - rtb_Add_hu;
    } else {
      rtb_Total_Limited_l = rtb_Minus2;
    }

    /* End of Switch: '<S94>/Switch' */
  }

  /* End of Switch: '<S94>/Switch2' */

  /* Saturate: '<S85>/Saturation1' */
  if (rtb_Total_Limited_l > 0.005) {
    rtb_Subtract_l = 0.005;
  } else if (rtb_Total_Limited_l < -0.005) {
    rtb_Subtract_l = -0.005;
  } else {
    rtb_Subtract_l = rtb_Total_Limited_l;
  }

  /* End of Saturate: '<S85>/Saturation1' */

  /* Sum: '<S85>/Add1' */
  rtb_Add_k = rtb_Add_hu + rtb_Subtract_l;

  /* Saturate: '<S85>/Saturation2' */
  if (rtb_Add_k > 1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_k < -1.0) {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackRight_Steer_DutyCycle = rtb_Add_k;
  }

  /* End of Saturate: '<S85>/Saturation2' */

  /* Fcn: '<S155>/x->r' */
  rtb_Total_Limited_l = rt_hypotd_snf(rtb_Add_d_idx_0, rtb_Add_d_idx_1);

  /* Switch: '<S154>/Switch1' incorporates:
   *  Constant: '<S154>/Constant'
   *  Constant: '<S158>/Constant'
   *  RelationalOperator: '<S158>/Compare'
   *  Switch: '<S154>/Switch'
   */
  if (rtb_Total_Limited_l == 0.0) {
    rtb_Add_hu = 1.0E-15;
  } else {
    rtb_Add_hu = rtb_Total_Limited_l;

    /* Switch: '<S154>/Switch' incorporates:
     *  Fcn: '<S155>/x->theta'
     */
    Code_Gen_Model_B.Desired_Module_Angle_f = rt_atan2d_snf(rtb_Add_d_idx_1,
      rtb_Add_d_idx_0);
  }

  /* End of Switch: '<S154>/Switch1' */

  /* Trigonometry: '<S81>/Cos4' incorporates:
   *  Switch: '<S65>/Angle_Switch'
   *  Trigonometry: '<S80>/Cos4'
   */
  rtb_Add_i = cos(Code_Gen_Model_B.Desired_Module_Angle_f);

  /* Abs: '<S64>/Abs' incorporates:
   *  Inport: '<Root>/BackLeft_Steer_Encoder'
   */
  rtb_Abs_gz = fabs(Code_Gen_Model_U.BackLeft_Steer_Encoder);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_gz,
    &Code_Gen_Model_B.ModulobyConstant_a);

  /* Switch: '<S64>/Switch' incorporates:
   *  Constant: '<S77>/Constant'
   *  Inport: '<Root>/BackLeft_Steer_Encoder'
   *  RelationalOperator: '<S77>/Compare'
   *  UnaryMinus: '<S64>/Unary Minus'
   */
  if (Code_Gen_Model_U.BackLeft_Steer_Encoder >= 0.0) {
    rtb_Minus2 = Code_Gen_Model_B.ModulobyConstant_a.ModulobyConstant;
  } else {
    rtb_Minus2 = -Code_Gen_Model_B.ModulobyConstant_a.ModulobyConstant;
  }

  /* End of Switch: '<S64>/Switch' */

  /* Sum: '<S63>/Add' incorporates:
   *  Inport: '<Root>/BackLeft_Turn_Offset'
   */
  rtb_Minus2 -= Code_Gen_Model_U.BackLeft_Turn_Offset;

  /* Abs: '<S75>/Abs' */
  rtb_Abs_p = fabs(rtb_Minus2);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_p,
    &Code_Gen_Model_B.ModulobyConstant_c);

  /* Switch: '<S75>/Switch' incorporates:
   *  Constant: '<S76>/Constant'
   *  RelationalOperator: '<S76>/Compare'
   *  UnaryMinus: '<S75>/Unary Minus'
   */
  if (rtb_Minus2 >= 0.0) {
    rtb_Switch2_p = Code_Gen_Model_B.ModulobyConstant_c.ModulobyConstant;
  } else {
    rtb_Switch2_p = -Code_Gen_Model_B.ModulobyConstant_c.ModulobyConstant;
  }

  /* Gain: '<S63>/Gain' incorporates:
   *  Switch: '<S75>/Switch'
   */
  rtb_Minus2 = 6.2831853071795862 * rtb_Switch2_p;

  /* Trigonometry: '<S81>/Sin5' incorporates:
   *  UnaryMinus: '<S79>/Unary Minus'
   */
  rtb_Sin5 = sin(-rtb_Minus2);

  /* Trigonometry: '<S81>/Sin4' incorporates:
   *  Switch: '<S65>/Angle_Switch'
   *  Trigonometry: '<S80>/Sin4'
   */
  rtb_Subtract_e = sin(Code_Gen_Model_B.Desired_Module_Angle_f);

  /* Trigonometry: '<S81>/Cos5' incorporates:
   *  UnaryMinus: '<S79>/Unary Minus'
   */
  rtb_Switch2_p = cos(-rtb_Minus2);

  /* Sum: '<S81>/Subtract1' incorporates:
   *  Product: '<S81>/Product2'
   *  Product: '<S81>/Product3'
   *  Trigonometry: '<S81>/Cos4'
   *  Trigonometry: '<S81>/Sin4'
   */
  rtb_Total_Limited_l = rtb_Add_i * rtb_Sin5 + rtb_Subtract_e * rtb_Switch2_p;

  /* Sum: '<S81>/Subtract' incorporates:
   *  Product: '<S81>/Product'
   *  Product: '<S81>/Product1'
   *  Trigonometry: '<S81>/Cos4'
   *  Trigonometry: '<S81>/Sin4'
   */
  rtb_Add_d_idx_0 = rtb_Add_i * rtb_Switch2_p - rtb_Subtract_e * rtb_Sin5;

  /* Math: '<S81>/Hypot' */
  rtb_Add_d_idx_1 = rt_hypotd_snf(rtb_Add_d_idx_0, rtb_Total_Limited_l);

  /* Switch: '<S81>/Switch' incorporates:
   *  Constant: '<S81>/Constant'
   *  Constant: '<S81>/Constant1'
   *  Constant: '<S82>/Constant'
   *  Product: '<S81>/Divide'
   *  Product: '<S81>/Divide1'
   *  RelationalOperator: '<S82>/Compare'
   *  Switch: '<S81>/Switch1'
   */
  if (rtb_Add_d_idx_1 > 1.0E-6) {
    rtb_Total_Limited_l /= rtb_Add_d_idx_1;
    rtb_Switch2_p = rtb_Add_d_idx_0 / rtb_Add_d_idx_1;
  } else {
    rtb_Total_Limited_l = 0.0;
    rtb_Switch2_p = 1.0;
  }

  /* End of Switch: '<S81>/Switch' */

  /* RelationalOperator: '<S78>/Compare' incorporates:
   *  Abs: '<S65>/Abs'
   *  Constant: '<S78>/Constant'
   *  Trigonometry: '<S81>/Atan1'
   */
  rtb_Compare_na = fabs(rt_atan2d_snf(rtb_Total_Limited_l, rtb_Switch2_p)) >
    1.5707963267948966;

  /* Switch: '<S65>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S65>/Unary Minus'
   */
  if (rtb_Compare_na) {
    rtb_Add_hu = -rtb_Add_hu;
  }

  /* Product: '<S67>/Product2' incorporates:
   *  Constant: '<S67>/Constant'
   *  Switch: '<S65>/Speed_Switch'
   */
  Code_Gen_Model_B.Optimized_Motor_Speed_g = rtb_Add_hu * 1530.1401357649195;

  /* Signum: '<S66>/Sign' */
  if (rtIsNaN(Code_Gen_Model_B.Optimized_Motor_Speed_g)) {
    rtb_Switch2_p = (rtNaN);
  } else if (Code_Gen_Model_B.Optimized_Motor_Speed_g < 0.0) {
    rtb_Switch2_p = -1.0;
  } else {
    rtb_Switch2_p = Code_Gen_Model_B.Optimized_Motor_Speed_g > 0.0;
  }

  /* Signum: '<S66>/Sign1' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Encoder'
   */
  if (rtIsNaN(Code_Gen_Model_U.BackLeft_Drive_Encoder)) {
    rtb_Sin5 = (rtNaN);
  } else if (Code_Gen_Model_U.BackLeft_Drive_Encoder < 0.0) {
    rtb_Sin5 = -1.0;
  } else {
    rtb_Sin5 = Code_Gen_Model_U.BackLeft_Drive_Encoder > 0.0;
  }

  /* Switch: '<S66>/Switch' incorporates:
   *  Abs: '<S66>/Abs'
   *  Constant: '<S84>/Constant'
   *  Inport: '<Root>/BackLeft_Drive_Encoder'
   *  Logic: '<S66>/OR'
   *  RelationalOperator: '<S66>/Equal1'
   *  RelationalOperator: '<S84>/Compare'
   *  Signum: '<S66>/Sign'
   *  Signum: '<S66>/Sign1'
   */
  if (rtb_Switch2_p == rtb_Sin5 || fabs(Code_Gen_Model_U.BackLeft_Drive_Encoder)
      <= 600.0) {
    /* Switch: '<S66>/Switch' */
    Code_Gen_Model_B.Adj_Cmd_i = Code_Gen_Model_B.Optimized_Motor_Speed_g;
  } else {
    /* Switch: '<S66>/Switch' incorporates:
     *  Constant: '<S66>/Constant'
     */
    Code_Gen_Model_B.Adj_Cmd_i = 0.0;
  }

  /* End of Switch: '<S66>/Switch' */

  /* Sum: '<S62>/Sum' incorporates:
   *  Inport: '<Root>/BackLeft_Drive_Encoder'
   */
  rtb_Total_Limited_l = Code_Gen_Model_B.Adj_Cmd_i -
    Code_Gen_Model_U.BackLeft_Drive_Encoder;

  /* Sum: '<S73>/Sum1' incorporates:
   *  Constant: '<S62>/Constant2'
   *  Product: '<S73>/Product'
   *  Sum: '<S73>/Sum'
   *  UnitDelay: '<S73>/Unit Delay1'
   */
  rtb_Add_hu = (rtb_Total_Limited_l - Code_Gen_Model_DW.UnitDelay1_DSTATE_j) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_j;

  /* Product: '<S62>/Product' incorporates:
   *  Constant: '<S62>/Constant3'
   */
  rtb_Add_d_idx_0 = rtb_Add_hu * 9.9999999999999991E-5;

  /* Sum: '<S72>/Diff' incorporates:
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
  rtb_Add_k = rtb_Add_d_idx_0 - Code_Gen_Model_DW.UD_DSTATE_lp;

  /* Saturate: '<S62>/Saturation' */
  if (rtb_Add_k > 0.2) {
    rtb_Add_k = 0.2;
  } else if (rtb_Add_k < -0.2) {
    rtb_Add_k = -0.2;
  }

  /* Sum: '<S62>/Add' incorporates:
   *  Gain: '<S62>/Gain'
   *  Gain: '<S62>/Gain1'
   *  Saturate: '<S62>/Saturation'
   */
  rtb_Add_h = 0.00018181818181818181 * Code_Gen_Model_B.Adj_Cmd_i + 5.0E-6 *
    rtb_Total_Limited_l + rtb_Add_k;

  /* Sum: '<S62>/Subtract' incorporates:
   *  Constant: '<S62>/Constant'
   */
  rtb_Switch2_p = 1.0 - rtb_Add_h;

  /* Sum: '<S62>/Sum2' incorporates:
   *  Gain: '<S62>/Gain2'
   *  UnitDelay: '<S62>/Unit Delay'
   */
  rtb_Total_Limited_l = 0.0 * rtb_Total_Limited_l +
    Code_Gen_Model_DW.UnitDelay_DSTATE_b;

  /* Switch: '<S74>/Switch2' incorporates:
   *  Constant: '<S62>/Constant'
   *  RelationalOperator: '<S74>/LowerRelop1'
   *  Sum: '<S62>/Subtract'
   */
  if (!(rtb_Total_Limited_l > 1.0 - rtb_Add_h)) {
    /* Switch: '<S74>/Switch' incorporates:
     *  Constant: '<S62>/Constant1'
     *  RelationalOperator: '<S74>/UpperRelop'
     *  Sum: '<S62>/Subtract1'
     */
    if (rtb_Total_Limited_l < -1.0 - rtb_Add_h) {
      rtb_Switch2_p = -1.0 - rtb_Add_h;
    } else {
      rtb_Switch2_p = rtb_Total_Limited_l;
    }

    /* End of Switch: '<S74>/Switch' */
  }

  /* End of Switch: '<S74>/Switch2' */

  /* Saturate: '<S62>/Saturation1' */
  if (rtb_Switch2_p > 0.0) {
    rtb_Add_d_idx_1 = 0.0;
  } else if (rtb_Switch2_p < -0.0) {
    rtb_Add_d_idx_1 = -0.0;
  } else {
    rtb_Add_d_idx_1 = rtb_Switch2_p;
  }

  /* End of Saturate: '<S62>/Saturation1' */

  /* Sum: '<S62>/Add1' */
  rtb_Add_k = rtb_Add_h + rtb_Add_d_idx_1;

  /* Saturate: '<S62>/Saturation2' */
  if (rtb_Add_k > 1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_k < -1.0) {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Drive_DutyCycle = rtb_Add_k;
  }

  /* End of Saturate: '<S62>/Saturation2' */

  /* Switch: '<S65>/Angle_Switch' */
  if (rtb_Compare_na) {
    /* Sum: '<S80>/Subtract1' incorporates:
     *  Product: '<S80>/Product2'
     *  Product: '<S80>/Product3'
     */
    rtb_Total_Limited_l = rtb_Add_i * Code_Gen_Model_ConstB.Sin5_dw +
      rtb_Subtract_e * Code_Gen_Model_ConstB.Cos5_e;

    /* Sum: '<S80>/Subtract' incorporates:
     *  Product: '<S80>/Product'
     *  Product: '<S80>/Product1'
     */
    rtb_Subtract_b = rtb_Add_i * Code_Gen_Model_ConstB.Cos5_e - rtb_Subtract_e *
      Code_Gen_Model_ConstB.Sin5_dw;

    /* Math: '<S80>/Hypot' */
    rtb_Add_h = rt_hypotd_snf(rtb_Subtract_b, rtb_Total_Limited_l);

    /* Switch: '<S80>/Switch1' incorporates:
     *  Constant: '<S80>/Constant'
     *  Constant: '<S80>/Constant1'
     *  Constant: '<S83>/Constant'
     *  Product: '<S80>/Divide'
     *  Product: '<S80>/Divide1'
     *  RelationalOperator: '<S83>/Compare'
     *  Switch: '<S80>/Switch'
     */
    if (rtb_Add_h > 1.0E-6) {
      rtb_Subtract_b /= rtb_Add_h;
      rtb_Total_Limited_l /= rtb_Add_h;
    } else {
      rtb_Subtract_b = 1.0;
      rtb_Total_Limited_l = 0.0;
    }

    /* End of Switch: '<S80>/Switch1' */

    /* Switch: '<S65>/Angle_Switch' incorporates:
     *  Trigonometry: '<S80>/Atan1'
     */
    Code_Gen_Model_B.Optimized_Module_Angle_i = rt_atan2d_snf
      (rtb_Total_Limited_l, rtb_Subtract_b);
  } else {
    /* Switch: '<S65>/Angle_Switch' */
    Code_Gen_Model_B.Optimized_Module_Angle_i =
      Code_Gen_Model_B.Desired_Module_Angle_f;
  }

  /* Sum: '<S61>/Sum' */
  rtb_Minus2 = Code_Gen_Model_B.Optimized_Module_Angle_i - rtb_Minus2;

  /* Sum: '<S71>/Subtract1' incorporates:
   *  Product: '<S71>/Divide'
   *  Product: '<S71>/Product'
   *  Rounding: '<S71>/Fix'
   *  Sum: '<S71>/Minus'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.UnaryMinus_a) /
                      Code_Gen_Model_ConstB.Modulus_hb) *
    Code_Gen_Model_ConstB.Modulus_hb;

  /* Sum: '<S71>/Minus2' incorporates:
   *  Product: '<S71>/Divide1'
   *  Product: '<S71>/Product1'
   *  Rounding: '<S71>/Fix1'
   *  Sum: '<S71>/Minus1'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.Error_Bound_j) /
                      Code_Gen_Model_ConstB.Modulus_hb) *
    Code_Gen_Model_ConstB.Modulus_hb;

  /* Sum: '<S69>/Sum1' incorporates:
   *  Constant: '<S61>/Constant2'
   *  Product: '<S69>/Product'
   *  Sum: '<S69>/Sum'
   *  UnitDelay: '<S69>/Unit Delay1'
   */
  rtb_Add_h = (rtb_Minus2 - Code_Gen_Model_DW.UnitDelay1_DSTATE_a) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_a;

  /* Product: '<S61>/Product' incorporates:
   *  Constant: '<S61>/Constant3'
   */
  rtb_Subtract_b = rtb_Add_h * 0.5;

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
  rtb_Add_k = rtb_Subtract_b - Code_Gen_Model_DW.UD_DSTATE_c;

  /* Saturate: '<S61>/Saturation' */
  if (rtb_Add_k > 0.2) {
    rtb_Add_k = 0.2;
  } else if (rtb_Add_k < -0.2) {
    rtb_Add_k = -0.2;
  }

  /* Sum: '<S61>/Add' incorporates:
   *  Gain: '<S61>/Gain1'
   *  Saturate: '<S61>/Saturation'
   */
  rtb_Add_i = 0.15 * rtb_Minus2 + rtb_Add_k;

  /* Sum: '<S61>/Subtract' incorporates:
   *  Constant: '<S61>/Constant'
   */
  rtb_Total_Limited_l = 1.0 - rtb_Add_i;

  /* Sum: '<S61>/Sum2' incorporates:
   *  Gain: '<S61>/Gain2'
   *  UnitDelay: '<S61>/Unit Delay'
   */
  rtb_Minus2 = 0.005 * rtb_Minus2 + Code_Gen_Model_DW.UnitDelay_DSTATE_k;

  /* Switch: '<S70>/Switch2' incorporates:
   *  Constant: '<S61>/Constant'
   *  RelationalOperator: '<S70>/LowerRelop1'
   *  Sum: '<S61>/Subtract'
   */
  if (!(rtb_Minus2 > 1.0 - rtb_Add_i)) {
    /* Sum: '<S61>/Subtract1' incorporates:
     *  Constant: '<S61>/Constant1'
     */
    rtb_Total_Limited_l = -1.0 - rtb_Add_i;

    /* Switch: '<S70>/Switch' incorporates:
     *  Constant: '<S61>/Constant1'
     *  RelationalOperator: '<S70>/UpperRelop'
     *  Sum: '<S61>/Subtract1'
     */
    if (!(rtb_Minus2 < -1.0 - rtb_Add_i)) {
      rtb_Total_Limited_l = rtb_Minus2;
    }

    /* End of Switch: '<S70>/Switch' */
  }

  /* End of Switch: '<S70>/Switch2' */

  /* Saturate: '<S61>/Saturation1' */
  if (rtb_Total_Limited_l > 0.005) {
    rtb_Integral_oc = 0.005;
  } else if (rtb_Total_Limited_l < -0.005) {
    rtb_Integral_oc = -0.005;
  } else {
    rtb_Integral_oc = rtb_Total_Limited_l;
  }

  /* End of Saturate: '<S61>/Saturation1' */

  /* Sum: '<S61>/Add1' */
  rtb_Add_k = rtb_Add_i + rtb_Integral_oc;

  /* Saturate: '<S61>/Saturation2' */
  if (rtb_Add_k > 1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_k < -1.0) {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/BackLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.BackLeft_Steer_DutyCycle = rtb_Add_k;
  }

  /* End of Saturate: '<S61>/Saturation2' */

  /* Fcn: '<S150>/x->r' */
  rtb_Total_Limited_l = rt_hypotd_snf(rtb_TmpSignalConversionAtLook_k[0],
    rtb_TmpSignalConversionAtLook_k[1]);

  /* Switch: '<S149>/Switch1' incorporates:
   *  Constant: '<S149>/Constant'
   *  Constant: '<S153>/Constant'
   *  RelationalOperator: '<S153>/Compare'
   *  Switch: '<S149>/Switch'
   */
  if (rtb_Total_Limited_l == 0.0) {
    rtb_Switch1_hj = 1.0E-15;
  } else {
    rtb_Switch1_hj = rtb_Total_Limited_l;

    /* Switch: '<S149>/Switch' incorporates:
     *  Fcn: '<S150>/x->theta'
     */
    Code_Gen_Model_B.Desired_Module_Angle_l = rt_atan2d_snf
      (rtb_TmpSignalConversionAtLook_k[1], rtb_TmpSignalConversionAtLook_k[0]);
  }

  /* End of Switch: '<S149>/Switch1' */

  /* Trigonometry: '<S57>/Cos4' incorporates:
   *  Switch: '<S41>/Angle_Switch'
   *  Trigonometry: '<S56>/Cos4'
   */
  rtb_Add_i = cos(Code_Gen_Model_B.Desired_Module_Angle_l);

  /* Abs: '<S40>/Abs' incorporates:
   *  Inport: '<Root>/FrontRight_Steer_Encoder'
   */
  rtb_Abs_c = fabs(Code_Gen_Model_U.FrontRight_Steer_Encoder);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_c,
    &Code_Gen_Model_B.ModulobyConstant_o);

  /* Switch: '<S40>/Switch' incorporates:
   *  Constant: '<S53>/Constant'
   *  Inport: '<Root>/FrontRight_Steer_Encoder'
   *  RelationalOperator: '<S53>/Compare'
   *  UnaryMinus: '<S40>/Unary Minus'
   */
  if (Code_Gen_Model_U.FrontRight_Steer_Encoder >= 0.0) {
    rtb_Minus2 = Code_Gen_Model_B.ModulobyConstant_o.ModulobyConstant;
  } else {
    rtb_Minus2 = -Code_Gen_Model_B.ModulobyConstant_o.ModulobyConstant;
  }

  /* End of Switch: '<S40>/Switch' */

  /* Sum: '<S39>/Add' incorporates:
   *  Inport: '<Root>/FrontRight_Turn_Offset'
   */
  rtb_Minus2 -= Code_Gen_Model_U.FrontRight_Turn_Offset;

  /* Abs: '<S51>/Abs' */
  rtb_Abs_a = fabs(rtb_Minus2);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_a,
    &Code_Gen_Model_B.ModulobyConstant_f);

  /* Switch: '<S51>/Switch' incorporates:
   *  Constant: '<S52>/Constant'
   *  RelationalOperator: '<S52>/Compare'
   *  UnaryMinus: '<S51>/Unary Minus'
   */
  if (rtb_Minus2 >= 0.0) {
    rtb_Switch2_p = Code_Gen_Model_B.ModulobyConstant_f.ModulobyConstant;
  } else {
    rtb_Switch2_p = -Code_Gen_Model_B.ModulobyConstant_f.ModulobyConstant;
  }

  /* Gain: '<S39>/Gain' incorporates:
   *  Switch: '<S51>/Switch'
   */
  rtb_Minus2 = 6.2831853071795862 * rtb_Switch2_p;

  /* Trigonometry: '<S57>/Sin5' incorporates:
   *  UnaryMinus: '<S55>/Unary Minus'
   */
  rtb_Sin5 = sin(-rtb_Minus2);

  /* Trigonometry: '<S57>/Sin4' incorporates:
   *  Switch: '<S41>/Angle_Switch'
   *  Trigonometry: '<S56>/Sin4'
   */
  rtb_Subtract_e = sin(Code_Gen_Model_B.Desired_Module_Angle_l);

  /* Trigonometry: '<S57>/Cos5' incorporates:
   *  UnaryMinus: '<S55>/Unary Minus'
   */
  rtb_Switch2_p = cos(-rtb_Minus2);

  /* Sum: '<S57>/Subtract1' incorporates:
   *  Product: '<S57>/Product2'
   *  Product: '<S57>/Product3'
   *  Trigonometry: '<S57>/Cos4'
   *  Trigonometry: '<S57>/Sin4'
   */
  rtb_Total_Limited_l = rtb_Add_i * rtb_Sin5 + rtb_Subtract_e * rtb_Switch2_p;

  /* Sum: '<S57>/Subtract' incorporates:
   *  Product: '<S57>/Product'
   *  Product: '<S57>/Product1'
   *  Trigonometry: '<S57>/Cos4'
   *  Trigonometry: '<S57>/Sin4'
   */
  rtb_Subtract_h = rtb_Add_i * rtb_Switch2_p - rtb_Subtract_e * rtb_Sin5;

  /* Math: '<S57>/Hypot' */
  rtb_Hypot_i = rt_hypotd_snf(rtb_Subtract_h, rtb_Total_Limited_l);

  /* Switch: '<S57>/Switch' incorporates:
   *  Constant: '<S57>/Constant'
   *  Constant: '<S57>/Constant1'
   *  Constant: '<S58>/Constant'
   *  Product: '<S57>/Divide'
   *  Product: '<S57>/Divide1'
   *  RelationalOperator: '<S58>/Compare'
   *  Switch: '<S57>/Switch1'
   */
  if (rtb_Hypot_i > 1.0E-6) {
    rtb_Total_Limited_l /= rtb_Hypot_i;
    rtb_Switch2_p = rtb_Subtract_h / rtb_Hypot_i;
  } else {
    rtb_Total_Limited_l = 0.0;
    rtb_Switch2_p = 1.0;
  }

  /* End of Switch: '<S57>/Switch' */

  /* RelationalOperator: '<S54>/Compare' incorporates:
   *  Abs: '<S41>/Abs'
   *  Constant: '<S54>/Constant'
   *  Trigonometry: '<S57>/Atan1'
   */
  rtb_Compare_na = fabs(rt_atan2d_snf(rtb_Total_Limited_l, rtb_Switch2_p)) >
    1.5707963267948966;

  /* Switch: '<S41>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S41>/Unary Minus'
   */
  if (rtb_Compare_na) {
    rtb_Switch1_hj = -rtb_Switch1_hj;
  }

  /* Product: '<S43>/Product2' incorporates:
   *  Constant: '<S43>/Constant'
   *  Switch: '<S41>/Speed_Switch'
   */
  Code_Gen_Model_B.Optimized_Motor_Speed_i = rtb_Switch1_hj * 1530.1401357649195;

  /* Signum: '<S42>/Sign' */
  if (rtIsNaN(Code_Gen_Model_B.Optimized_Motor_Speed_i)) {
    rtb_Switch2_p = (rtNaN);
  } else if (Code_Gen_Model_B.Optimized_Motor_Speed_i < 0.0) {
    rtb_Switch2_p = -1.0;
  } else {
    rtb_Switch2_p = Code_Gen_Model_B.Optimized_Motor_Speed_i > 0.0;
  }

  /* Signum: '<S42>/Sign1' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Encoder'
   */
  if (rtIsNaN(Code_Gen_Model_U.FrontRight_Drive_Encoder)) {
    rtb_Sin5 = (rtNaN);
  } else if (Code_Gen_Model_U.FrontRight_Drive_Encoder < 0.0) {
    rtb_Sin5 = -1.0;
  } else {
    rtb_Sin5 = Code_Gen_Model_U.FrontRight_Drive_Encoder > 0.0;
  }

  /* Switch: '<S42>/Switch' incorporates:
   *  Abs: '<S42>/Abs'
   *  Constant: '<S60>/Constant'
   *  Inport: '<Root>/FrontRight_Drive_Encoder'
   *  Logic: '<S42>/OR'
   *  RelationalOperator: '<S42>/Equal1'
   *  RelationalOperator: '<S60>/Compare'
   *  Signum: '<S42>/Sign'
   *  Signum: '<S42>/Sign1'
   */
  if (rtb_Switch2_p == rtb_Sin5 || fabs
      (Code_Gen_Model_U.FrontRight_Drive_Encoder) <= 600.0) {
    /* Switch: '<S42>/Switch' */
    Code_Gen_Model_B.Adj_Cmd_iv = Code_Gen_Model_B.Optimized_Motor_Speed_i;
  } else {
    /* Switch: '<S42>/Switch' incorporates:
     *  Constant: '<S42>/Constant'
     */
    Code_Gen_Model_B.Adj_Cmd_iv = 0.0;
  }

  /* End of Switch: '<S42>/Switch' */

  /* Sum: '<S38>/Sum' incorporates:
   *  Inport: '<Root>/FrontRight_Drive_Encoder'
   */
  rtb_Total_Limited_l = Code_Gen_Model_B.Adj_Cmd_iv -
    Code_Gen_Model_U.FrontRight_Drive_Encoder;

  /* Sum: '<S49>/Sum1' incorporates:
   *  Constant: '<S38>/Constant2'
   *  Product: '<S49>/Product'
   *  Sum: '<S49>/Sum'
   *  UnitDelay: '<S49>/Unit Delay1'
   */
  rtb_Switch1_hj = (rtb_Total_Limited_l - Code_Gen_Model_DW.UnitDelay1_DSTATE_c)
    * 0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_c;

  /* Product: '<S38>/Product' incorporates:
   *  Constant: '<S38>/Constant3'
   */
  rtb_Subtract_h = rtb_Switch1_hj * 9.9999999999999991E-5;

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
  rtb_Add_k = rtb_Subtract_h - Code_Gen_Model_DW.UD_DSTATE_la;

  /* Saturate: '<S38>/Saturation' */
  if (rtb_Add_k > 0.2) {
    rtb_Add_k = 0.2;
  } else if (rtb_Add_k < -0.2) {
    rtb_Add_k = -0.2;
  }

  /* Sum: '<S38>/Add' incorporates:
   *  Gain: '<S38>/Gain'
   *  Gain: '<S38>/Gain1'
   *  Saturate: '<S38>/Saturation'
   */
  rtb_Add_ek = 0.00018181818181818181 * Code_Gen_Model_B.Adj_Cmd_iv + 5.0E-6 *
    rtb_Total_Limited_l + rtb_Add_k;

  /* Sum: '<S38>/Subtract' incorporates:
   *  Constant: '<S38>/Constant'
   */
  rtb_Switch2_p = 1.0 - rtb_Add_ek;

  /* Sum: '<S38>/Sum2' incorporates:
   *  Gain: '<S38>/Gain2'
   *  UnitDelay: '<S38>/Unit Delay'
   */
  rtb_Total_Limited_l = 0.0 * rtb_Total_Limited_l +
    Code_Gen_Model_DW.UnitDelay_DSTATE_cd;

  /* Switch: '<S50>/Switch2' incorporates:
   *  Constant: '<S38>/Constant'
   *  RelationalOperator: '<S50>/LowerRelop1'
   *  Sum: '<S38>/Subtract'
   */
  if (!(rtb_Total_Limited_l > 1.0 - rtb_Add_ek)) {
    /* Switch: '<S50>/Switch' incorporates:
     *  Constant: '<S38>/Constant1'
     *  RelationalOperator: '<S50>/UpperRelop'
     *  Sum: '<S38>/Subtract1'
     */
    if (rtb_Total_Limited_l < -1.0 - rtb_Add_ek) {
      rtb_Switch2_p = -1.0 - rtb_Add_ek;
    } else {
      rtb_Switch2_p = rtb_Total_Limited_l;
    }

    /* End of Switch: '<S50>/Switch' */
  }

  /* End of Switch: '<S50>/Switch2' */

  /* Saturate: '<S38>/Saturation1' */
  if (rtb_Switch2_p > 0.0) {
    rtb_Hypot_i = 0.0;
  } else if (rtb_Switch2_p < -0.0) {
    rtb_Hypot_i = -0.0;
  } else {
    rtb_Hypot_i = rtb_Switch2_p;
  }

  /* End of Saturate: '<S38>/Saturation1' */

  /* Sum: '<S38>/Add1' */
  rtb_Add_k = rtb_Add_ek + rtb_Hypot_i;

  /* Saturate: '<S38>/Saturation2' */
  if (rtb_Add_k > 1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_k < -1.0) {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Drive_DutyCycle = rtb_Add_k;
  }

  /* End of Saturate: '<S38>/Saturation2' */

  /* Switch: '<S41>/Angle_Switch' */
  if (rtb_Compare_na) {
    /* Sum: '<S56>/Subtract1' incorporates:
     *  Product: '<S56>/Product2'
     *  Product: '<S56>/Product3'
     */
    rtb_Total_Limited_l = rtb_Add_i * Code_Gen_Model_ConstB.Sin5_d +
      rtb_Subtract_e * Code_Gen_Model_ConstB.Cos5_c;

    /* Sum: '<S56>/Subtract' incorporates:
     *  Product: '<S56>/Product'
     *  Product: '<S56>/Product1'
     */
    rtb_Subtract_e = rtb_Add_i * Code_Gen_Model_ConstB.Cos5_c - rtb_Subtract_e *
      Code_Gen_Model_ConstB.Sin5_d;

    /* Math: '<S56>/Hypot' */
    rtb_Add_i = rt_hypotd_snf(rtb_Subtract_e, rtb_Total_Limited_l);

    /* Switch: '<S56>/Switch1' incorporates:
     *  Constant: '<S56>/Constant'
     *  Constant: '<S56>/Constant1'
     *  Constant: '<S59>/Constant'
     *  Product: '<S56>/Divide'
     *  Product: '<S56>/Divide1'
     *  RelationalOperator: '<S59>/Compare'
     *  Switch: '<S56>/Switch'
     */
    if (rtb_Add_i > 1.0E-6) {
      rtb_Subtract_e /= rtb_Add_i;
      rtb_Total_Limited_l /= rtb_Add_i;
    } else {
      rtb_Subtract_e = 1.0;
      rtb_Total_Limited_l = 0.0;
    }

    /* End of Switch: '<S56>/Switch1' */

    /* Switch: '<S41>/Angle_Switch' incorporates:
     *  Trigonometry: '<S56>/Atan1'
     */
    Code_Gen_Model_B.Optimized_Module_Angle_j = rt_atan2d_snf
      (rtb_Total_Limited_l, rtb_Subtract_e);
  } else {
    /* Switch: '<S41>/Angle_Switch' */
    Code_Gen_Model_B.Optimized_Module_Angle_j =
      Code_Gen_Model_B.Desired_Module_Angle_l;
  }

  /* Sum: '<S37>/Sum' */
  rtb_Minus2 = Code_Gen_Model_B.Optimized_Module_Angle_j - rtb_Minus2;

  /* Sum: '<S47>/Subtract1' incorporates:
   *  Product: '<S47>/Divide'
   *  Product: '<S47>/Product'
   *  Rounding: '<S47>/Fix'
   *  Sum: '<S47>/Minus'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.UnaryMinus_mf) /
                      Code_Gen_Model_ConstB.Modulus_h) *
    Code_Gen_Model_ConstB.Modulus_h;

  /* Sum: '<S47>/Minus2' incorporates:
   *  Product: '<S47>/Divide1'
   *  Product: '<S47>/Product1'
   *  Rounding: '<S47>/Fix1'
   *  Sum: '<S47>/Minus1'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.Error_Bound_a) /
                      Code_Gen_Model_ConstB.Modulus_h) *
    Code_Gen_Model_ConstB.Modulus_h;

  /* Sum: '<S45>/Sum1' incorporates:
   *  Constant: '<S37>/Constant2'
   *  Product: '<S45>/Product'
   *  Sum: '<S45>/Sum'
   *  UnitDelay: '<S45>/Unit Delay1'
   */
  rtb_Add_ek = (rtb_Minus2 - Code_Gen_Model_DW.UnitDelay1_DSTATE_jq) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_jq;

  /* Product: '<S37>/Product' incorporates:
   *  Constant: '<S37>/Constant3'
   */
  rtb_Product_ln = rtb_Add_ek * 0.5;

  /* Sum: '<S44>/Diff' incorporates:
   *  UnitDelay: '<S44>/UD'
   *
   * Block description for '<S44>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S44>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_k = rtb_Product_ln - Code_Gen_Model_DW.UD_DSTATE_g;

  /* Saturate: '<S37>/Saturation' */
  if (rtb_Add_k > 0.2) {
    rtb_Add_k = 0.2;
  } else if (rtb_Add_k < -0.2) {
    rtb_Add_k = -0.2;
  }

  /* Sum: '<S37>/Add' incorporates:
   *  Gain: '<S37>/Gain1'
   *  Saturate: '<S37>/Saturation'
   */
  rtb_Add_i = 0.15 * rtb_Minus2 + rtb_Add_k;

  /* Sum: '<S37>/Subtract' incorporates:
   *  Constant: '<S37>/Constant'
   */
  rtb_Total_Limited_l = 1.0 - rtb_Add_i;

  /* Sum: '<S37>/Sum2' incorporates:
   *  Gain: '<S37>/Gain2'
   *  UnitDelay: '<S37>/Unit Delay'
   */
  rtb_Minus2 = 0.005 * rtb_Minus2 + Code_Gen_Model_DW.UnitDelay_DSTATE_p;

  /* Switch: '<S46>/Switch2' incorporates:
   *  Constant: '<S37>/Constant'
   *  RelationalOperator: '<S46>/LowerRelop1'
   *  Sum: '<S37>/Subtract'
   */
  if (!(rtb_Minus2 > 1.0 - rtb_Add_i)) {
    /* Sum: '<S37>/Subtract1' incorporates:
     *  Constant: '<S37>/Constant1'
     */
    rtb_Total_Limited_l = -1.0 - rtb_Add_i;

    /* Switch: '<S46>/Switch' incorporates:
     *  Constant: '<S37>/Constant1'
     *  RelationalOperator: '<S46>/UpperRelop'
     *  Sum: '<S37>/Subtract1'
     */
    if (!(rtb_Minus2 < -1.0 - rtb_Add_i)) {
      rtb_Total_Limited_l = rtb_Minus2;
    }

    /* End of Switch: '<S46>/Switch' */
  }

  /* End of Switch: '<S46>/Switch2' */

  /* Saturate: '<S37>/Saturation1' */
  if (rtb_Total_Limited_l > 0.005) {
    rtb_Integral_j = 0.005;
  } else if (rtb_Total_Limited_l < -0.005) {
    rtb_Integral_j = -0.005;
  } else {
    rtb_Integral_j = rtb_Total_Limited_l;
  }

  /* End of Saturate: '<S37>/Saturation1' */

  /* Sum: '<S37>/Add1' */
  rtb_Add_k = rtb_Add_i + rtb_Integral_j;

  /* Saturate: '<S37>/Saturation2' */
  if (rtb_Add_k > 1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_k < -1.0) {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontRight_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontRight_Steer_DutyCycle = rtb_Add_k;
  }

  /* End of Saturate: '<S37>/Saturation2' */

  /* Fcn: '<S145>/x->r' */
  rtb_Total_Limited_l = rt_hypotd_snf(rtb_TmpSignalConversionAtLook_n[0],
    rtb_TmpSignalConversionAtLook_n[1]);

  /* Switch: '<S144>/Switch1' incorporates:
   *  Constant: '<S144>/Constant'
   *  Constant: '<S148>/Constant'
   *  RelationalOperator: '<S148>/Compare'
   *  Switch: '<S144>/Switch'
   */
  if (rtb_Total_Limited_l == 0.0) {
    rtb_Switch1_ip = 1.0E-15;
  } else {
    rtb_Switch1_ip = rtb_Total_Limited_l;

    /* Switch: '<S144>/Switch' incorporates:
     *  Fcn: '<S145>/x->theta'
     */
    Code_Gen_Model_B.Desired_Module_Angle_o = rt_atan2d_snf
      (rtb_TmpSignalConversionAtLook_n[1], rtb_TmpSignalConversionAtLook_n[0]);
  }

  /* End of Switch: '<S144>/Switch1' */

  /* Trigonometry: '<S33>/Cos4' incorporates:
   *  Switch: '<S17>/Angle_Switch'
   *  Trigonometry: '<S32>/Cos4'
   */
  rtb_Add_i = cos(Code_Gen_Model_B.Desired_Module_Angle_o);

  /* Abs: '<S16>/Abs' incorporates:
   *  Inport: '<Root>/FrontLeft_Steer_Encoder'
   */
  rtb_Abs_cq = fabs(Code_Gen_Model_U.FrontLeft_Steer_Encoder);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_cq,
    &Code_Gen_Model_B.ModulobyConstant_p);

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S29>/Constant'
   *  Inport: '<Root>/FrontLeft_Steer_Encoder'
   *  RelationalOperator: '<S29>/Compare'
   *  UnaryMinus: '<S16>/Unary Minus'
   */
  if (Code_Gen_Model_U.FrontLeft_Steer_Encoder >= 0.0) {
    rtb_Minus2 = Code_Gen_Model_B.ModulobyConstant_p.ModulobyConstant;
  } else {
    rtb_Minus2 = -Code_Gen_Model_B.ModulobyConstant_p.ModulobyConstant;
  }

  /* End of Switch: '<S16>/Switch' */

  /* Sum: '<S15>/Add' incorporates:
   *  Inport: '<Root>/FrontLeft_Turn_Offset'
   */
  rtb_Minus2 -= Code_Gen_Model_U.FrontLeft_Turn_Offset;

  /* Abs: '<S27>/Abs' */
  rtb_Abs_l = fabs(rtb_Minus2);
  Code_Gen_Model_ModulobyConstant(rtb_Abs_l, &Code_Gen_Model_B.ModulobyConstant);

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S28>/Constant'
   *  RelationalOperator: '<S28>/Compare'
   *  UnaryMinus: '<S27>/Unary Minus'
   */
  if (rtb_Minus2 >= 0.0) {
    rtb_Switch2_p = Code_Gen_Model_B.ModulobyConstant.ModulobyConstant;
  } else {
    rtb_Switch2_p = -Code_Gen_Model_B.ModulobyConstant.ModulobyConstant;
  }

  /* Gain: '<S15>/Gain' incorporates:
   *  Switch: '<S27>/Switch'
   */
  rtb_Minus2 = 6.2831853071795862 * rtb_Switch2_p;

  /* Trigonometry: '<S33>/Sin5' incorporates:
   *  UnaryMinus: '<S31>/Unary Minus'
   */
  rtb_Sin5 = sin(-rtb_Minus2);

  /* Trigonometry: '<S33>/Sin4' incorporates:
   *  Switch: '<S17>/Angle_Switch'
   *  Trigonometry: '<S32>/Sin4'
   */
  rtb_Subtract_e = sin(Code_Gen_Model_B.Desired_Module_Angle_o);

  /* Trigonometry: '<S33>/Cos5' incorporates:
   *  UnaryMinus: '<S31>/Unary Minus'
   */
  rtb_Switch2_p = cos(-rtb_Minus2);

  /* Sum: '<S33>/Subtract1' incorporates:
   *  Product: '<S33>/Product2'
   *  Product: '<S33>/Product3'
   *  Trigonometry: '<S33>/Cos4'
   *  Trigonometry: '<S33>/Sin4'
   */
  rtb_Total_Limited_l = rtb_Add_i * rtb_Sin5 + rtb_Subtract_e * rtb_Switch2_p;

  /* Sum: '<S33>/Subtract' incorporates:
   *  Product: '<S33>/Product'
   *  Product: '<S33>/Product1'
   *  Trigonometry: '<S33>/Cos4'
   *  Trigonometry: '<S33>/Sin4'
   */
  rtb_Switch2_p = rtb_Add_i * rtb_Switch2_p - rtb_Subtract_e * rtb_Sin5;

  /* Math: '<S33>/Hypot' */
  rtb_Sin5 = rt_hypotd_snf(rtb_Switch2_p, rtb_Total_Limited_l);

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S33>/Constant'
   *  Constant: '<S33>/Constant1'
   *  Constant: '<S34>/Constant'
   *  Product: '<S33>/Divide'
   *  Product: '<S33>/Divide1'
   *  RelationalOperator: '<S34>/Compare'
   *  Switch: '<S33>/Switch1'
   */
  if (rtb_Sin5 > 1.0E-6) {
    rtb_Total_Limited_l /= rtb_Sin5;
    rtb_Switch2_p /= rtb_Sin5;
  } else {
    rtb_Total_Limited_l = 0.0;
    rtb_Switch2_p = 1.0;
  }

  /* End of Switch: '<S33>/Switch' */

  /* RelationalOperator: '<S30>/Compare' incorporates:
   *  Abs: '<S17>/Abs'
   *  Constant: '<S30>/Constant'
   *  Trigonometry: '<S33>/Atan1'
   */
  rtb_Compare_na = fabs(rt_atan2d_snf(rtb_Total_Limited_l, rtb_Switch2_p)) >
    1.5707963267948966;

  /* Switch: '<S17>/Speed_Switch' incorporates:
   *  UnaryMinus: '<S17>/Unary Minus'
   */
  if (rtb_Compare_na) {
    rtb_Switch1_ip = -rtb_Switch1_ip;
  }

  /* Product: '<S19>/Product2' incorporates:
   *  Constant: '<S19>/Constant'
   *  Switch: '<S17>/Speed_Switch'
   */
  Code_Gen_Model_B.Optimized_Motor_Speed_o = rtb_Switch1_ip * 1530.1401357649195;

  /* Signum: '<S18>/Sign' */
  if (rtIsNaN(Code_Gen_Model_B.Optimized_Motor_Speed_o)) {
    rtb_Switch2_p = (rtNaN);
  } else if (Code_Gen_Model_B.Optimized_Motor_Speed_o < 0.0) {
    rtb_Switch2_p = -1.0;
  } else {
    rtb_Switch2_p = Code_Gen_Model_B.Optimized_Motor_Speed_o > 0.0;
  }

  /* Signum: '<S18>/Sign1' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Encoder'
   */
  if (rtIsNaN(Code_Gen_Model_U.FrontLeft_Drive_Encoder)) {
    rtb_Sin5 = (rtNaN);
  } else if (Code_Gen_Model_U.FrontLeft_Drive_Encoder < 0.0) {
    rtb_Sin5 = -1.0;
  } else {
    rtb_Sin5 = Code_Gen_Model_U.FrontLeft_Drive_Encoder > 0.0;
  }

  /* Switch: '<S18>/Switch' incorporates:
   *  Abs: '<S18>/Abs'
   *  Constant: '<S36>/Constant'
   *  Inport: '<Root>/FrontLeft_Drive_Encoder'
   *  Logic: '<S18>/OR'
   *  RelationalOperator: '<S18>/Equal1'
   *  RelationalOperator: '<S36>/Compare'
   *  Signum: '<S18>/Sign'
   *  Signum: '<S18>/Sign1'
   */
  if (rtb_Switch2_p == rtb_Sin5 || fabs(Code_Gen_Model_U.FrontLeft_Drive_Encoder)
      <= 600.0) {
    /* Switch: '<S18>/Switch' */
    Code_Gen_Model_B.Adj_Cmd_f = Code_Gen_Model_B.Optimized_Motor_Speed_o;
  } else {
    /* Switch: '<S18>/Switch' incorporates:
     *  Constant: '<S18>/Constant'
     */
    Code_Gen_Model_B.Adj_Cmd_f = 0.0;
  }

  /* End of Switch: '<S18>/Switch' */

  /* Sum: '<S14>/Sum' incorporates:
   *  Inport: '<Root>/FrontLeft_Drive_Encoder'
   */
  rtb_Total_Limited_l = Code_Gen_Model_B.Adj_Cmd_f -
    Code_Gen_Model_U.FrontLeft_Drive_Encoder;

  /* Sum: '<S25>/Sum1' incorporates:
   *  Constant: '<S14>/Constant2'
   *  Product: '<S25>/Product'
   *  Sum: '<S25>/Sum'
   *  UnitDelay: '<S25>/Unit Delay1'
   */
  rtb_Sin5 = (rtb_Total_Limited_l - Code_Gen_Model_DW.UnitDelay1_DSTATE_e) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_e;

  /* Product: '<S14>/Product' incorporates:
   *  Constant: '<S14>/Constant3'
   */
  rtb_Switch1_ip = rtb_Sin5 * 9.9999999999999991E-5;

  /* Sum: '<S24>/Diff' incorporates:
   *  UnitDelay: '<S24>/UD'
   *
   * Block description for '<S24>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S24>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_k = rtb_Switch1_ip - Code_Gen_Model_DW.UD_DSTATE_ln;

  /* Saturate: '<S14>/Saturation' */
  if (rtb_Add_k > 0.2) {
    rtb_Add_k = 0.2;
  } else if (rtb_Add_k < -0.2) {
    rtb_Add_k = -0.2;
  }

  /* Sum: '<S14>/Add' incorporates:
   *  Gain: '<S14>/Gain'
   *  Gain: '<S14>/Gain1'
   *  Saturate: '<S14>/Saturation'
   */
  rtb_Add_k += 0.00018181818181818181 * Code_Gen_Model_B.Adj_Cmd_f + 5.0E-6 *
    rtb_Total_Limited_l;

  /* Sum: '<S14>/Subtract' incorporates:
   *  Constant: '<S14>/Constant'
   */
  rtb_Switch2_p = 1.0 - rtb_Add_k;

  /* Sum: '<S14>/Sum2' incorporates:
   *  Gain: '<S14>/Gain2'
   *  UnitDelay: '<S14>/Unit Delay'
   */
  rtb_Total_Limited_l = 0.0 * rtb_Total_Limited_l +
    Code_Gen_Model_DW.UnitDelay_DSTATE_j;

  /* Switch: '<S26>/Switch2' incorporates:
   *  Constant: '<S14>/Constant'
   *  RelationalOperator: '<S26>/LowerRelop1'
   *  Sum: '<S14>/Subtract'
   */
  if (!(rtb_Total_Limited_l > 1.0 - rtb_Add_k)) {
    /* Sum: '<S14>/Subtract1' incorporates:
     *  Constant: '<S14>/Constant1'
     */
    rtb_Switch2_p = -1.0 - rtb_Add_k;

    /* Switch: '<S26>/Switch' incorporates:
     *  Constant: '<S14>/Constant1'
     *  RelationalOperator: '<S26>/UpperRelop'
     *  Sum: '<S14>/Subtract1'
     */
    if (!(rtb_Total_Limited_l < -1.0 - rtb_Add_k)) {
      rtb_Switch2_p = rtb_Total_Limited_l;
    }

    /* End of Switch: '<S26>/Switch' */
  }

  /* End of Switch: '<S26>/Switch2' */

  /* Saturate: '<S14>/Saturation1' */
  if (rtb_Switch2_p > 0.0) {
    rtb_Switch2_p = 0.0;
  } else if (rtb_Switch2_p < -0.0) {
    rtb_Switch2_p = -0.0;
  }

  /* End of Saturate: '<S14>/Saturation1' */

  /* Sum: '<S14>/Add1' */
  rtb_Add_k += rtb_Switch2_p;

  /* Saturate: '<S14>/Saturation2' */
  if (rtb_Add_k > 1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = 1.0;
  } else if (rtb_Add_k < -1.0) {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Drive_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Drive_DutyCycle = rtb_Add_k;
  }

  /* End of Saturate: '<S14>/Saturation2' */

  /* Switch: '<S17>/Angle_Switch' */
  if (rtb_Compare_na) {
    /* Sum: '<S32>/Subtract1' incorporates:
     *  Product: '<S32>/Product2'
     *  Product: '<S32>/Product3'
     */
    rtb_Total_Limited_l = rtb_Add_i * Code_Gen_Model_ConstB.Sin5 +
      rtb_Subtract_e * Code_Gen_Model_ConstB.Cos5;

    /* Sum: '<S32>/Subtract' incorporates:
     *  Product: '<S32>/Product'
     *  Product: '<S32>/Product1'
     */
    rtb_Subtract_e = rtb_Add_i * Code_Gen_Model_ConstB.Cos5 - rtb_Subtract_e *
      Code_Gen_Model_ConstB.Sin5;

    /* Math: '<S32>/Hypot' */
    rtb_Add_i = rt_hypotd_snf(rtb_Subtract_e, rtb_Total_Limited_l);

    /* Switch: '<S32>/Switch1' incorporates:
     *  Constant: '<S32>/Constant'
     *  Constant: '<S32>/Constant1'
     *  Constant: '<S35>/Constant'
     *  Product: '<S32>/Divide'
     *  Product: '<S32>/Divide1'
     *  RelationalOperator: '<S35>/Compare'
     *  Switch: '<S32>/Switch'
     */
    if (rtb_Add_i > 1.0E-6) {
      rtb_Subtract_e /= rtb_Add_i;
      rtb_Total_Limited_l /= rtb_Add_i;
    } else {
      rtb_Subtract_e = 1.0;
      rtb_Total_Limited_l = 0.0;
    }

    /* End of Switch: '<S32>/Switch1' */

    /* Switch: '<S17>/Angle_Switch' incorporates:
     *  Trigonometry: '<S32>/Atan1'
     */
    Code_Gen_Model_B.Optimized_Module_Angle_p = rt_atan2d_snf
      (rtb_Total_Limited_l, rtb_Subtract_e);
  } else {
    /* Switch: '<S17>/Angle_Switch' */
    Code_Gen_Model_B.Optimized_Module_Angle_p =
      Code_Gen_Model_B.Desired_Module_Angle_o;
  }

  /* Sum: '<S13>/Sum' */
  rtb_Minus2 = Code_Gen_Model_B.Optimized_Module_Angle_p - rtb_Minus2;

  /* Sum: '<S23>/Subtract1' incorporates:
   *  Product: '<S23>/Divide'
   *  Product: '<S23>/Product'
   *  Rounding: '<S23>/Fix'
   *  Sum: '<S23>/Minus'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.UnaryMinus_p) /
                      Code_Gen_Model_ConstB.Modulus) *
    Code_Gen_Model_ConstB.Modulus;

  /* Sum: '<S23>/Minus2' incorporates:
   *  Product: '<S23>/Divide1'
   *  Product: '<S23>/Product1'
   *  Rounding: '<S23>/Fix1'
   *  Sum: '<S23>/Minus1'
   */
  rtb_Minus2 -= trunc((rtb_Minus2 - Code_Gen_Model_ConstB.Error_Bound) /
                      Code_Gen_Model_ConstB.Modulus) *
    Code_Gen_Model_ConstB.Modulus;

  /* Sum: '<S21>/Sum1' incorporates:
   *  Constant: '<S13>/Constant2'
   *  Product: '<S21>/Product'
   *  Sum: '<S21>/Sum'
   *  UnitDelay: '<S21>/Unit Delay1'
   */
  rtb_Add_i = (rtb_Minus2 - Code_Gen_Model_DW.UnitDelay1_DSTATE_o) *
    0.22223232082821098 + Code_Gen_Model_DW.UnitDelay1_DSTATE_o;

  /* Product: '<S13>/Product' incorporates:
   *  Constant: '<S13>/Constant3'
   */
  rtb_Subtract_e = rtb_Add_i * 0.5;

  /* Sum: '<S20>/Diff' incorporates:
   *  UnitDelay: '<S20>/UD'
   *
   * Block description for '<S20>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S20>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Add_k = rtb_Subtract_e - Code_Gen_Model_DW.UD_DSTATE_f;

  /* Saturate: '<S13>/Saturation' */
  if (rtb_Add_k > 0.2) {
    rtb_Add_k = 0.2;
  } else if (rtb_Add_k < -0.2) {
    rtb_Add_k = -0.2;
  }

  /* Sum: '<S13>/Add' incorporates:
   *  Gain: '<S13>/Gain1'
   *  Saturate: '<S13>/Saturation'
   */
  rtb_Add_k += 0.15 * rtb_Minus2;

  /* Sum: '<S13>/Subtract' incorporates:
   *  Constant: '<S13>/Constant'
   */
  rtb_Total_Limited_l = 1.0 - rtb_Add_k;

  /* Sum: '<S13>/Sum2' incorporates:
   *  Gain: '<S13>/Gain2'
   *  UnitDelay: '<S13>/Unit Delay'
   */
  rtb_Minus2 = 0.005 * rtb_Minus2 + Code_Gen_Model_DW.UnitDelay_DSTATE_k0;

  /* Switch: '<S22>/Switch2' incorporates:
   *  Constant: '<S13>/Constant'
   *  RelationalOperator: '<S22>/LowerRelop1'
   *  Sum: '<S13>/Subtract'
   */
  if (!(rtb_Minus2 > 1.0 - rtb_Add_k)) {
    /* Sum: '<S13>/Subtract1' incorporates:
     *  Constant: '<S13>/Constant1'
     */
    rtb_Total_Limited_l = -1.0 - rtb_Add_k;

    /* Switch: '<S22>/Switch' incorporates:
     *  Constant: '<S13>/Constant1'
     *  RelationalOperator: '<S22>/UpperRelop'
     *  Sum: '<S13>/Subtract1'
     */
    if (!(rtb_Minus2 < -1.0 - rtb_Add_k)) {
      rtb_Total_Limited_l = rtb_Minus2;
    }

    /* End of Switch: '<S22>/Switch' */
  }

  /* End of Switch: '<S22>/Switch2' */

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
  rtb_Add_k += rtb_Minus2;

  /* Saturate: '<S13>/Saturation2' */
  if (rtb_Add_k > 1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = 1.0;
  } else if (rtb_Add_k < -1.0) {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = -1.0;
  } else {
    /* Outport: '<Root>/FrontLeft_Steer_DutyCycle' */
    Code_Gen_Model_Y.FrontLeft_Steer_DutyCycle = rtb_Add_k;
  }

  /* End of Saturate: '<S13>/Saturation2' */

  /* Update for UnitDelay: '<S124>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S124>/FixPt Constant'
   */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE = 0U;

  /* Update for UnitDelay: '<S136>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE = rtb_Switch2;

  /* Update for UnitDelay: '<S135>/UD'
   *
   * Block description for '<S135>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE = rtb_Switch1_b;

  /* Update for UnitDelay: '<S134>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_g = rtb_Sum1_m;

  /* Update for UnitDelay: '<S133>/FixPt Unit Delay2' incorporates:
   *  Constant: '<S133>/FixPt Constant'
   */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_d = 0U;

  /* Update for UnitDelay: '<S97>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_m = rtb_Switch2_g;

  /* Update for UnitDelay: '<S96>/UD'
   *
   * Block description for '<S96>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_j = rtb_Switch2_h;

  /* Update for UnitDelay: '<S86>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_c3 = rtb_Switch1_j;

  /* Update for UnitDelay: '<S93>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_k = rtb_Magnitude;

  /* Update for UnitDelay: '<S92>/UD'
   *
   * Block description for '<S92>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_l = rtb_Product_jb;

  /* Update for UnitDelay: '<S85>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_d = rtb_Subtract_l;

  /* Update for UnitDelay: '<S73>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_j = rtb_Add_hu;

  /* Update for UnitDelay: '<S72>/UD'
   *
   * Block description for '<S72>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_lp = rtb_Add_d_idx_0;

  /* Update for UnitDelay: '<S62>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_b = rtb_Add_d_idx_1;

  /* Update for UnitDelay: '<S69>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_a = rtb_Add_h;

  /* Update for UnitDelay: '<S68>/UD'
   *
   * Block description for '<S68>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_c = rtb_Subtract_b;

  /* Update for UnitDelay: '<S61>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_k = rtb_Integral_oc;

  /* Update for UnitDelay: '<S49>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_c = rtb_Switch1_hj;

  /* Update for UnitDelay: '<S48>/UD'
   *
   * Block description for '<S48>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_la = rtb_Subtract_h;

  /* Update for UnitDelay: '<S38>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_cd = rtb_Hypot_i;

  /* Update for UnitDelay: '<S45>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_jq = rtb_Add_ek;

  /* Update for UnitDelay: '<S44>/UD'
   *
   * Block description for '<S44>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_g = rtb_Product_ln;

  /* Update for UnitDelay: '<S37>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_p = rtb_Integral_j;

  /* Update for UnitDelay: '<S25>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_e = rtb_Sin5;

  /* Update for UnitDelay: '<S24>/UD'
   *
   * Block description for '<S24>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_ln = rtb_Switch1_ip;

  /* Update for UnitDelay: '<S14>/Unit Delay' */
  Code_Gen_Model_DW.UnitDelay_DSTATE_j = rtb_Switch2_p;

  /* Update for UnitDelay: '<S21>/Unit Delay1' */
  Code_Gen_Model_DW.UnitDelay1_DSTATE_o = rtb_Add_i;

  /* Update for UnitDelay: '<S20>/UD'
   *
   * Block description for '<S20>/UD':
   *
   *  Store in Global RAM
   */
  Code_Gen_Model_DW.UD_DSTATE_f = rtb_Subtract_e;

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

  /* InitializeConditions for UnitDelay: '<S124>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE = 1U;

  /* InitializeConditions for UnitDelay: '<S133>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_d = 1U;

  /* SystemInitialize for IfAction SubSystem: '<S1>/Teleop' */
  /* InitializeConditions for UnitDelay: '<S185>/FixPt Unit Delay2' */
  Code_Gen_Model_DW.FixPtUnitDelay2_DSTATE_l = 1U;

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
