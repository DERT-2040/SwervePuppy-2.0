/*
 * Catwell_Rom_data.c
 *
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * Code generation for model "Catwell_Rom".
 *
 * Model version              : 1.10
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Fri Jul 14 20:38:59 2023
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Catwell_Rom.h"

/* Block parameters (default storage) */
P_Catwell_Rom_T Catwell_Rom_P = {
  /* Mask Parameter: BandLimitedWhiteNoise_Cov
   * Referenced by: '<S1>/Output'
   */
  0.1,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S7>/Constant'
   */
  1.0,

  /* Mask Parameter: BandLimitedWhiteNoise_seed
   * Referenced by: '<S1>/White Noise'
   */
  23341.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S3>/Out1'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S3>/For Iterator'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S3>/Unit Delay'
   */
  0.0,

  /* Computed Parameter: Samples_Y0
   * Referenced by: '<S8>/Samples'
   */
  0.0,

  /* Expression: Spline_Samples_Per_Quad_Bezier
   * Referenced by: '<S8>/Constant1'
   */
  20.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant2'
   */
  1.0,

  /* Expression: 3
   * Referenced by: '<S8>/Constant7'
   */
  3.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant8'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/White Noise'
   */
  0.0,

  /* Computed Parameter: WhiteNoise_StdDev
   * Referenced by: '<S1>/White Noise'
   */
  1.0,

  /* Computed Parameter: Out1_Y0_e
   * Referenced by: '<S2>/Out1'
   */
  0,

  /* Computed Parameter: ForIterator_IterationLimit_m
   * Referenced by: '<S2>/For Iterator'
   */
  5,

  /* Computed Parameter: UnitDelay_InitialCondition_b
   * Referenced by: '<S2>/Unit Delay'
   */
  0,

  /* Expression: Spline_Samples_Per_Quad_Bezier
   * Referenced by: '<S8>/For Iterator'
   */
  20
};
