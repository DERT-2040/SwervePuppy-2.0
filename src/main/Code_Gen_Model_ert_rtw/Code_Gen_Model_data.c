/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model_data.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.4
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Nov 16 18:46:57 2023
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
  -3.1415926535897931,                 /* '<S18>/Unary Minus' */
  6.2831853071795862,                  /* '<S34>/Subtract' */
  -1.0,                                /* '<S43>/Cos5' */
  1.2246467991473532E-16,              /* '<S43>/Sin5' */
  -3.1415926535897931,                 /* '<S19>/Unary Minus' */
  6.2831853071795862,                  /* '<S59>/Subtract' */
  -1.0,                                /* '<S68>/Cos5' */
  1.2246467991473532E-16,              /* '<S68>/Sin5' */
  -3.1415926535897931,                 /* '<S20>/Unary Minus' */
  6.2831853071795862,                  /* '<S84>/Subtract' */
  -1.0,                                /* '<S93>/Cos5' */
  1.2246467991473532E-16,              /* '<S93>/Sin5' */
  -3.1415926535897931,                 /* '<S21>/Unary Minus' */
  6.2831853071795862,                  /* '<S109>/Subtract' */
  -1.0,                                /* '<S118>/Cos5' */
  1.2246467991473532E-16,              /* '<S118>/Sin5' */
  1.0,                                 /* '<S135>/Unary Minus' */
  -1.0,                                /* '<S135>/Unary Minus1' */
  -3.1415926535897931,                 /* '<S136>/Unary Minus' */
  6.2831853071795862,                  /* '<S148>/Subtract' */
  0.78539816339744828,                 /* '<S123>/Atan2' */
  2.3561944901923448,                  /* '<S123>/Add' */
  -0.78539816339744828,                /* '<S123>/Atan1' */
  0.78539816339744828,                 /* '<S123>/Add1' */
  2.3561944901923448,                  /* '<S123>/Atan3' */
  3.9269908169872414,                  /* '<S123>/Add2' */
  -2.3561944901923448,                 /* '<S123>/Atan4' */
  -0.78539816339744828                 /* '<S123>/Add3' */
};

/* Constant parameters (default storage) */
const ConstP_Code_Gen_Model_T Code_Gen_Model_ConstP = {
  /* Expression: Steering_Mod_Str_Rel_out
   * Referenced by: '<S176>/Modulation_Str_X_Rel'
   */
  { -1.0, -0.75, -0.55, -0.4, -0.27, -0.17, -0.1, -0.04, -0.01, -0.0, 0.0, 0.0,
    0.01, 0.04, 0.1, 0.17, 0.27, 0.4, 0.55, 0.75, 1.0 },

  /* Expression: Steering_Mod_Str_Rel_in
   * Referenced by: '<S176>/Modulation_Str_X_Rel'
   */
  { -1.0, -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.25, -0.2, 0.0, 0.2, 0.25,
    0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 },

  /* Pooled Parameter (Expression: Steering_Mod_Drv_out)
   * Referenced by:
   *   '<S177>/Modulation_Drv_X'
   *   '<S177>/Modulation_Drv_Y'
   */
  { -1.0, -0.58, -0.31, -0.18, -0.14, -0.09, -0.06, -0.04, -0.01, -0.0, 0.0, 0.0,
    0.01, 0.04, 0.06, 0.09, 0.14, 0.18, 0.31, 0.58, 1.0 },

  /* Pooled Parameter (Expression: Steering_Mod_Drv_in)
   * Referenced by:
   *   '<S177>/Modulation_Drv_X'
   *   '<S177>/Modulation_Drv_Y'
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
   *   '<S29>/1-D Lookup Table'
   *   '<S54>/1-D Lookup Table'
   *   '<S79>/1-D Lookup Table'
   *   '<S104>/1-D Lookup Table'
   */
  { 1.0, 0.05 },

  /* Pooled Parameter (Expression: Drive_Motor_Control_Module_Angle_Error)
   * Referenced by:
   *   '<S29>/1-D Lookup Table'
   *   '<S54>/1-D Lookup Table'
   *   '<S79>/1-D Lookup Table'
   *   '<S104>/1-D Lookup Table'
   */
  { 0.0, 0.78539816339744828 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
