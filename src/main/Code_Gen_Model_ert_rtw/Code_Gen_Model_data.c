/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model_data.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.27
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Dec 28 16:17:13 2023
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
  -1.0,                                /* '<S107>/Cos5' */
  1.2246467991473532E-16,              /* '<S107>/Sin5' */
  -1.0,                                /* '<S128>/Cos5' */
  1.2246467991473532E-16,              /* '<S128>/Sin5' */
  -1.0,                                /* '<S149>/Cos5' */
  1.2246467991473532E-16,              /* '<S149>/Sin5' */
  -1.0,                                /* '<S170>/Cos5' */
  1.2246467991473532E-16,              /* '<S170>/Sin5' */
  0.2,                                 /* '<S179>/Unary Minus' */
  0.78539816339744828,                 /* '<S180>/Atan2' */
  2.3561944901923448,                  /* '<S180>/Add' */
  -0.78539816339744828,                /* '<S180>/Atan1' */
  0.78539816339744828,                 /* '<S180>/Add1' */
  2.3561944901923448,                  /* '<S180>/Atan3' */
  3.9269908169872414,                  /* '<S180>/Add2' */
  -2.3561944901923448,                 /* '<S180>/Atan4' */
  -0.78539816339744828                 /* '<S180>/Add3' */
};

/* Constant parameters (default storage) */
const ConstP_Code_Gen_Model_T Code_Gen_Model_ConstP = {
  /* Expression: Spline_Ref_Poses_auto
   * Referenced by: '<S2>/Constant4'
   */
  { 0.0, 0.21213203435596426, 0.49497474683058329, 0.70710678118654757,
    0.38268343236508984, 6.123233995736766E-17, -0.38268343236508973,
    -0.70710678118654746, -0.92387953251128674, -1.0, -0.923879532511287,
    -0.70710678118654768, -0.3826834323650895, -1.8369701987210297E-16,
    0.38268343236509, 0.70710678118654735, 0.49497474683058312,
    0.2121320343559642, 0.0, 0.0, 0.21213203435596423, 0.49497474683058318,
    0.70710678118654746, 0.92387953251128674, 1.0, 0.92387953251128674,
    0.70710678118654757, 0.38268343236508989, 1.2246467991473532E-16,
    -0.38268343236508923, -0.70710678118654746, -0.92387953251128685, -1.0,
    -0.92387953251128663, -0.70710678118654768, -0.49497474683058335,
    -0.21213203435596431, 0.0, 3.5, 3.5, 2.4499999999999997, 1.75, 3.5, 3.5, 3.5,
    3.5, 3.5, 3.5, 3.5, 3.5, 3.5, 3.5, 2.4499999999999997, 1.75, 3.5, 3.5,
    0.35000000000000003, 0.78539816339744828, 0.78539816339744828,
    0.78539816339744828, 0.78539816339744828, 1.1780972450961724,
    1.5707963267948966, 1.9634954084936207, 2.3561944901923448,
    2.748893571891069, 3.1415926535897931, 3.5342917352885168,
    3.9269908169872414, 4.319689898685966, 4.71238898038469, 5.1050880620834143,
    5.497787143782138, 5.497787143782138, 5.497787143782138, 5.497787143782138 },

  /* Pooled Parameter (Expression: Steering_Mod_Drv_out)
   * Referenced by:
   *   '<S234>/Modulation_Drv_X'
   *   '<S234>/Modulation_Drv_Y'
   */
  { -1.0, -0.58, -0.31, -0.18, -0.14, -0.09, -0.06, -0.04, -0.01, -0.0, 0.0, 0.0,
    0.01, 0.04, 0.06, 0.09, 0.14, 0.18, 0.31, 0.58, 1.0 },

  /* Pooled Parameter (Expression: Steering_Mod_Drv_in)
   * Referenced by:
   *   '<S234>/Modulation_Drv_X'
   *   '<S234>/Modulation_Drv_Y'
   */
  { -1.0, -0.9, -0.8, -0.7, -0.6, -0.5, -0.45, -0.4, -0.35, -0.3, 0.0, 0.3, 0.35,
    0.4, 0.45, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 },

  /* Expression: Steering_Mod_Str_Rel_out
   * Referenced by: '<S233>/Modulation_Str_X_Rel'
   */
  { -1.0, -0.75, -0.55, -0.4, -0.27, -0.17, -0.1, -0.04, -0.01, -0.0, 0.0, 0.0,
    0.01, 0.04, 0.1, 0.17, 0.27, 0.4, 0.55, 0.75, 1.0 },

  /* Expression: Steering_Mod_Str_Rel_in
   * Referenced by: '<S233>/Modulation_Str_X_Rel'
   */
  { -1.0, -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.25, -0.2, 0.0, 0.2, 0.25,
    0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 },

  /* Expression: Rotation_Local_Inv
   * Referenced by: '<S7>/Constant4'
   */
  { 0.25, 0.0, 0.0, 0.25, 0.25, 0.0, 0.0, 0.25, 0.25, 0.0, 0.0, 0.25, 0.25, 0.0,
    0.0, 0.25 },

  /* Pooled Parameter (Expression: Drive_Motor_Control_Scale_Factor)
   * Referenced by:
   *   '<S98>/1-D Lookup Table'
   *   '<S119>/1-D Lookup Table'
   *   '<S140>/1-D Lookup Table'
   *   '<S161>/1-D Lookup Table'
   */
  { 1.0, 0.05 },

  /* Pooled Parameter (Expression: Drive_Motor_Control_Module_Angle_Error)
   * Referenced by:
   *   '<S98>/1-D Lookup Table'
   *   '<S119>/1-D Lookup Table'
   *   '<S140>/1-D Lookup Table'
   *   '<S161>/1-D Lookup Table'
   */
  { 0.0, 0.78539816339744828 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
