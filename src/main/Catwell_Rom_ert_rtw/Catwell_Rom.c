/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Catwell_Rom.c
 *
 * Code generated for Simulink model 'Catwell_Rom'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Jul 19 11:11:47 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 *    3. Safety precaution
 *    4. ROM efficiency
 * Validation result: Not run
 */

#include "Catwell_Rom.h"
#include "rtwtypes.h"
#include "Catwell_Rom_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_Catwell_Rom_T Catwell_Rom_B;

/* External inputs (root inport signals with default storage) */
ExtU_Catwell_Rom_T Catwell_Rom_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Catwell_Rom_T Catwell_Rom_Y;

/* Real-time model */
static RT_MODEL_Catwell_Rom_T Catwell_Rom_M_;
RT_MODEL_Catwell_Rom_T *const Catwell_Rom_M = &Catwell_Rom_M_;
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

/* Model step function */
void Catwell_Rom_step(void)
{
  real_T rtb_Dot_BCBM;
  real_T rtb_Minus1_0;
  real_T rtb_Minus1_idx_0;
  real_T rtb_Minus1_idx_0_tmp;
  real_T rtb_Minus1_idx_1;
  real_T rtb_Minus1_idx_1_tmp;
  real_T rtb_Minus1_idx_1_tmp_0;
  real_T rtb_Minus_0;
  real_T rtb_Minus_idx_0;
  real_T rtb_Sum;
  real_T rtb_Sum1;
  int32_T rtb_Switch;
  int32_T s5_iter;
  boolean_T rtb_Compare_m;

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/Gain1'
   *  Inport: '<Root>/Ref_Poses2'
   *  Inport: '<Root>/Ref_Poses4'
   */
  rtb_Sum = 0.02 * Catwell_Rom_U.Ref_Poses4 + Catwell_Rom_U.Ref_Poses2;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Gain: '<S1>/Gain'
   *  Inport: '<Root>/Ref_Poses3'
   *  Inport: '<Root>/Ref_Poses5'
   */
  rtb_Sum1 = 0.02 * Catwell_Rom_U.Ref_Poses5 + Catwell_Rom_U.Ref_Poses3;

  /* Outputs for Iterator SubSystem: '<S1>/Rectangle_Checks' incorporates:
   *  WhileIterator: '<S5>/While Iterator'
   */
  s5_iter = 1;
  do {
    rtb_Minus1_idx_0_tmp = Catwell_Rom_U.Ref_Poses[s5_iter - 1];
    rtb_Minus1_idx_0 = Catwell_Rom_U.Ref_Poses[s5_iter] - rtb_Minus1_idx_0_tmp;
    rtb_Minus1_idx_1_tmp = Catwell_Rom_U.Ref_Poses[s5_iter + 10];
    rtb_Minus1_idx_1_tmp_0 = Catwell_Rom_U.Ref_Poses[s5_iter + 9];
    rtb_Minus1_idx_1 = rtb_Minus1_idx_1_tmp - rtb_Minus1_idx_1_tmp_0;
    rtb_Dot_BCBM = rt_hypotd_snf(rtb_Minus1_idx_0, rtb_Minus1_idx_1);
    rtb_Minus1_0 = rtb_Minus1_idx_0;
    rtb_Minus1_idx_0 = rtb_Minus1_idx_1 / rtb_Dot_BCBM * 2.0 / 2.0;
    rtb_Minus1_idx_1 = -rtb_Minus1_0 / rtb_Dot_BCBM * 2.0 / 2.0;
    rtb_Minus_0 = Catwell_Rom_U.Ref_Poses[s5_iter] - rtb_Minus1_idx_0;
    rtb_Minus_idx_0 = rtb_Minus_0;
    rtb_Dot_BCBM = (Catwell_Rom_U.Ref_Poses[s5_iter] + rtb_Minus1_idx_0) -
      rtb_Minus_0;
    rtb_Minus1_idx_0 = rtb_Minus1_idx_0_tmp - rtb_Minus1_idx_0;
    rtb_Minus_0 = rtb_Minus1_idx_1_tmp - rtb_Minus1_idx_1;
    rtb_Minus1_idx_0_tmp = (rtb_Minus1_idx_1_tmp + rtb_Minus1_idx_1) -
      rtb_Minus_0;
    rtb_Minus1_0 = rtb_Minus1_idx_1_tmp_0 - rtb_Minus1_idx_1;
    rtb_Compare_m = (Catwell_Rom_U.Ref_Poses[s5_iter] != -9999.0);
    if (rtb_Compare_m) {
      rtb_Switch = s5_iter;
    } else {
      rtb_Switch = -1;
    }

    s5_iter++;
    rtb_Minus1_idx_1_tmp_0 = rtb_Minus_idx_0 - rtb_Minus1_idx_0;
    rtb_Minus1_idx_0 = (rtb_Sum - rtb_Minus1_idx_0) * rtb_Minus1_idx_1_tmp_0;
    rtb_Minus1_idx_1 = rtb_Minus1_idx_1_tmp_0 * rtb_Minus1_idx_1_tmp_0;
    rtb_Minus1_idx_1_tmp_0 = rtb_Minus_0 - rtb_Minus1_0;
    rtb_Minus1_idx_0 += (rtb_Sum1 - rtb_Minus1_0) * rtb_Minus1_idx_1_tmp_0;
    rtb_Minus1_0 = (rtb_Sum - rtb_Minus_idx_0) * rtb_Dot_BCBM + (rtb_Sum1 -
      rtb_Minus_0) * rtb_Minus1_idx_0_tmp;
  } while (rtb_Compare_m && ((!(rtb_Minus1_idx_0 >= 0.0)) || (!(rtb_Minus1_idx_0
              <= rtb_Minus1_idx_1_tmp_0 * rtb_Minus1_idx_1_tmp_0 +
              rtb_Minus1_idx_1)) || (!(rtb_Minus1_0 >= 0.0)) || (!(rtb_Minus1_0 <=
              rtb_Dot_BCBM * rtb_Dot_BCBM + rtb_Minus1_idx_0_tmp *
              rtb_Minus1_idx_0_tmp))) && (s5_iter <= 9));

  /* End of Outputs for SubSystem: '<S1>/Rectangle_Checks' */

  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   */
  rtb_Compare_m = (rtb_Switch != -1);

  /* If: '<S1>/If' */
  if (!rtb_Compare_m) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Outputs for Iterator SubSystem: '<S3>/Circle_Checks' incorporates:
     *  WhileIterator: '<S6>/While Iterator'
     */
    s5_iter = 1;

    /* End of Outputs for SubSystem: '<S3>/Circle_Checks' */
    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */
    do {
      Catwell_Rom_B.WhileIterator = s5_iter;
      s5_iter++;
    } while ((rt_hypotd_snf(rtb_Sum -
                            Catwell_Rom_U.Ref_Poses[Catwell_Rom_B.WhileIterator
                            - 1], rtb_Sum1 -
                            Catwell_Rom_U.Ref_Poses[Catwell_Rom_B.WhileIterator
                            + 9]) > Catwell_Rom_ConstB.Gain) && (s5_iter <= 9));
  }

  /* End of If: '<S1>/If' */

  /* Switch: '<S1>/Switch' */
  if (!rtb_Compare_m) {
    rtb_Switch = Catwell_Rom_B.WhileIterator;
  }

  /* Outport: '<Root>/Index' incorporates:
   *  Constant: '<S4>/FixPt Constant'
   *  Sum: '<S4>/FixPt Sum1'
   *  Switch: '<S1>/Switch'
   */
  Catwell_Rom_Y.Index = (real_T)rtb_Switch + 1.0;
}

/* Model initialize function */
void Catwell_Rom_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void Catwell_Rom_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
