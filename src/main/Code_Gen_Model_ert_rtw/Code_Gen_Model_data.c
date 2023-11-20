/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model_data.c
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

/* Invariant block signals (default storage) */
const ConstB_Code_Gen_Model_T Code_Gen_Model_ConstB = {
  0.0,                                 /* '<S1>/Constant' */
  0.0,                                 /* '<S1>/Constant1' */
  -1.0,                                /* '<S36>/Cos5' */
  1.2246467991473532E-16,              /* '<S36>/Sin5' */
  -1.0,                                /* '<S59>/Cos5' */
  1.2246467991473532E-16,              /* '<S59>/Sin5' */
  -1.0,                                /* '<S82>/Cos5' */
  1.2246467991473532E-16,              /* '<S82>/Sin5' */
  -1.0,                                /* '<S105>/Cos5' */
  1.2246467991473532E-16,              /* '<S105>/Sin5' */
  0.2,                                 /* '<S115>/Unary Minus' */
  -0.085714285714285715,               /* '<S115>/Unary Minus1' */
  1.0,                                 /* '<S127>/Unary Minus' */
  -1.0,                                /* '<S127>/Unary Minus1' */
  0.78539816339744828,                 /* '<S116>/Atan2' */
  2.3561944901923448,                  /* '<S116>/Add' */
  -0.78539816339744828,                /* '<S116>/Atan1' */
  0.78539816339744828,                 /* '<S116>/Add1' */
  2.3561944901923448,                  /* '<S116>/Atan3' */
  3.9269908169872414,                  /* '<S116>/Add2' */
  -2.3561944901923448,                 /* '<S116>/Atan4' */
  -0.78539816339744828                 /* '<S116>/Add3' */
};

/* Constant parameters (default storage) */
const ConstP_Code_Gen_Model_T Code_Gen_Model_ConstP = {
  /* Expression: Steering_Mod_Str_Rel_out
   * Referenced by: '<S169>/Modulation_Str_X_Rel'
   */
  { -1.0, -0.75, -0.55, -0.4, -0.27, -0.17, -0.1, -0.04, -0.01, -0.0, 0.0, 0.0,
    0.01, 0.04, 0.1, 0.17, 0.27, 0.4, 0.55, 0.75, 1.0 },

  /* Expression: Steering_Mod_Str_Rel_in
   * Referenced by: '<S169>/Modulation_Str_X_Rel'
   */
  { -1.0, -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.25, -0.2, 0.0, 0.2, 0.25,
    0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 },

  /* Pooled Parameter (Expression: Steering_Mod_Drv_out)
   * Referenced by:
   *   '<S170>/Modulation_Drv_X'
   *   '<S170>/Modulation_Drv_Y'
   */
  { -1.0, -0.58, -0.31, -0.18, -0.14, -0.09, -0.06, -0.04, -0.01, -0.0, 0.0, 0.0,
    0.01, 0.04, 0.06, 0.09, 0.14, 0.18, 0.31, 0.58, 1.0 },

  /* Pooled Parameter (Expression: Steering_Mod_Drv_in)
   * Referenced by:
   *   '<S170>/Modulation_Drv_X'
   *   '<S170>/Modulation_Drv_Y'
   */
  { -1.0, -0.9, -0.8, -0.7, -0.6, -0.5, -0.45, -0.4, -0.35, -0.3, 0.0, 0.3, 0.35,
    0.4, 0.45, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 },

  /* Expression: Rotation_Local_Inv
   * Referenced by: '<S4>/Constant4'
   */
  { 0.25, 0.0, 0.0, 0.25, 0.25, 0.0, 0.0, 0.25, 0.25, 0.0, 0.0, 0.25, 0.25, 0.0,
    0.0, 0.25 },

  /* Pooled Parameter (Expression: Drive_Motor_Control_Scale_Factor)
   * Referenced by:
   *   '<S28>/1-D Lookup Table'
   *   '<S51>/1-D Lookup Table'
   *   '<S74>/1-D Lookup Table'
   *   '<S97>/1-D Lookup Table'
   */
  { 1.0, 0.05 },

  /* Pooled Parameter (Expression: Drive_Motor_Control_Module_Angle_Error)
   * Referenced by:
   *   '<S28>/1-D Lookup Table'
   *   '<S51>/1-D Lookup Table'
   *   '<S74>/1-D Lookup Table'
   *   '<S97>/1-D Lookup Table'
   */
  { 0.0, 0.78539816339744828 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
