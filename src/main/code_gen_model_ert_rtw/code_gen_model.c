/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: code_gen_model.c
 *
 * Code generated for Simulink model 'code_gen_model'.
 *
 * Model version                  : 1.64
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue May 23 20:55:18 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "code_gen_model.h"
#include "rtwtypes.h"
#include <string.h>
#include "code_gen_model_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <float.h>

/* Named constants for Chart: '<S1>/Chart' */
#define code_gen_model_IN_A            ((uint8_T)1U)
#define code_gen_model_IN_B            ((uint8_T)2U)

/* Exported block parameters */
real_T NeoMaxSpeed = 5700.0;           /* Variable: NeoMaxSpeed
                                        * Referenced by:
                                        *   '<S1>/Constant1'
                                        *   '<S4>/Constant1'
                                        */
real_T gain = 1000.0;                  /* Variable: gain
                                        * Referenced by: '<S4>/Constant'
                                        */

/* Block signals (default storage) */
B_code_gen_model_T code_gen_model_B;

/* Block states (default storage) */
DW_code_gen_model_T code_gen_model_DW;

/* External inputs (root inport signals with default storage) */
ExtU_code_gen_model_T code_gen_model_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_code_gen_model_T code_gen_model_Y;

/* Real-time model */
static RT_MODEL_code_gen_model_T code_gen_model_M_;
RT_MODEL_code_gen_model_T *const code_gen_model_M = &code_gen_model_M_;
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
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void code_gen_model_step(void)
{
  real_T rtb_Add;
  real_T rtb_Current_Sample;
  real_T tmp;
  int32_T Index;

  /* Sum: '<S3>/Add' incorporates:
   *  Inport: '<Root>/Trigger_val_n '
   *  Inport: '<Root>/Trigger_val_p'
   */
  code_gen_model_B.Net_input = code_gen_model_U.Trigger_val_p -
    code_gen_model_U.Trigger_val_n;

  /* If: '<Root>/If' incorporates:
   *  Inport: '<Root>/Game_State'
   */
  if (code_gen_model_U.Game_State == 0.0) {
    /* Outputs for IfAction SubSystem: '<Root>/Auto' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* Chart: '<S1>/Chart' incorporates:
     *  Constant: '<S1>/Speed1'
     *  Constant: '<S1>/Speed2'
     */
    if (code_gen_model_DW.is_active_c3_code_gen_model == 0U) {
      code_gen_model_DW.is_active_c3_code_gen_model = 1U;
      code_gen_model_DW.is_c3_code_gen_model = code_gen_model_IN_A;
      code_gen_model_B.Motor_Speed_g = 500.0;
      code_gen_model_DW.time = 0.0;
    } else if (code_gen_model_DW.is_c3_code_gen_model == code_gen_model_IN_A) {
      if (code_gen_model_DW.time >= 2.0) {
        code_gen_model_DW.is_c3_code_gen_model = code_gen_model_IN_B;
        code_gen_model_B.Motor_Speed_g = -500.0;
        code_gen_model_DW.time = 0.0;
      } else {
        code_gen_model_DW.time += 0.02;
      }

      /* case IN_B: */
    } else if (code_gen_model_DW.time >= 2.0) {
      code_gen_model_DW.is_c3_code_gen_model = code_gen_model_IN_A;
      code_gen_model_B.Motor_Speed_g = 500.0;
      code_gen_model_DW.time = 0.0;
    } else {
      code_gen_model_DW.time += 0.02;
    }

    /* End of Chart: '<S1>/Chart' */

    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<S1>/Constant1'
     *  Product: '<S1>/Divide'
     */
    code_gen_model_B.Motor_Speed = code_gen_model_B.Motor_Speed_g / NeoMaxSpeed;

    /* End of Outputs for SubSystem: '<Root>/Auto' */
  } else if (code_gen_model_U.Game_State == 1.0) {
    /* Outputs for IfAction SubSystem: '<Root>/Teleop' incorporates:
     *  ActionPort: '<S4>/Action Port'
     */
    /* Product: '<S4>/Product' incorporates:
     *  Constant: '<S4>/Constant'
     */
    code_gen_model_B.sig_product = code_gen_model_B.Net_input * gain;

    /* Merge: '<Root>/Merge' incorporates:
     *  Constant: '<S4>/Constant1'
     *  Product: '<S4>/Divide'
     */
    code_gen_model_B.Motor_Speed = code_gen_model_B.sig_product / NeoMaxSpeed;

    /* End of Outputs for SubSystem: '<Root>/Teleop' */
  } else {
    /* Outputs for IfAction SubSystem: '<Root>/Disabled' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Sum: '<S2>/Add' incorporates:
     *  Gain: '<S2>/Gain'
     */
    rtb_Add = 200.0 * code_gen_model_B.Net_input;

    /* UnitDelay: '<S2>/Unit Delay' */
    rtb_Current_Sample = code_gen_model_DW.UnitDelay_DSTATE;

    /* Outputs for Iterator SubSystem: '<S2>/Array Triangle Gen Fill' incorporates:
     *  ForIterator: '<S6>/For Iterator'
     */
    for (Index = 0; Index < 87; Index++) {
      /* Assignment: '<S6>/Assignment' */
      if (Index == 0) {
        /* Outport: '<Root>/LED_Array' */
        memset(&code_gen_model_Y.LED_Array[0], 0, 87U * sizeof(uint8_T));
      }

      /* Sum: '<S6>/Add' incorporates:
       *  Abs: '<S6>/Abs'
       *  Constant: '<S2>/LED_Amplitude'
       *  Constant: '<S2>/LED_Period'
       *  Gain: '<S6>/Gain'
       *  Gain: '<S6>/Gain1'
       *  Gain: '<S6>/Gain2'
       *  Math: '<S6>/Math Function'
       *  Product: '<S6>/Divide'
       *  Product: '<S6>/Product'
       *  Product: '<S6>/Product1'
       *  Sum: '<S6>/Subtract'
       *  Sum: '<S6>/Subtract1'
       */
      tmp = floor(fabs(rt_modd_snf((rtb_Current_Sample - 2500.0) - (real_T)Index
        * rtb_Add, 5000.0) - 2500.0) * 0.072);
      if (rtIsNaN(tmp)) {
        /* Assignment: '<S6>/Assignment' incorporates:
         *  Outport: '<Root>/LED_Array'
         */
        code_gen_model_Y.LED_Array[Index] = 0U;
      } else {
        /* Assignment: '<S6>/Assignment' incorporates:
         *  Outport: '<Root>/LED_Array'
         */
        code_gen_model_Y.LED_Array[Index] = (uint8_T)(int32_T)tmp;
      }

      /* End of Sum: '<S6>/Add' */

      /* Math: '<S6>/Mod1' incorporates:
       *  Constant: '<S2>/LED_Period'
       *  Sum: '<S6>/Sum'
       *  UnitDelay: '<S2>/Unit Delay'
       */
      code_gen_model_DW.UnitDelay_DSTATE = rt_modd_snf(rtb_Current_Sample +
        code_gen_model_ConstB.Gain3, 5000.0);
    }

    /* End of Outputs for SubSystem: '<S2>/Array Triangle Gen Fill' */
    /* End of Outputs for SubSystem: '<Root>/Disabled' */
  }

  /* End of If: '<Root>/If' */

  /* Outport: '<Root>/Motor_speed' */
  code_gen_model_Y.Motor_speed = code_gen_model_B.Motor_Speed;
}

/* Model initialize function */
void code_gen_model_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void code_gen_model_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
