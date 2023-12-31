/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model_data.c
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.34
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Dec 30 22:39:24 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Code_Gen_Model.h"

/* Invariant block signals (default storage) */
const ConstB_Code_Gen_Model_T Code_Gen_Model_ConstB = {
  -1.0,                                /* '<S161>/Cos5' */
  1.2246467991473532E-16,              /* '<S161>/Sin5' */
  -1.0,                                /* '<S182>/Cos5' */
  1.2246467991473532E-16,              /* '<S182>/Sin5' */
  -1.0,                                /* '<S203>/Cos5' */
  1.2246467991473532E-16,              /* '<S203>/Sin5' */
  -1.0,                                /* '<S224>/Cos5' */
  1.2246467991473532E-16,              /* '<S224>/Sin5' */
  0.2,                                 /* '<S233>/Unary Minus' */
  0.78539816339744828,                 /* '<S234>/Atan2' */
  2.3561944901923448,                  /* '<S234>/Add' */
  -0.78539816339744828,                /* '<S234>/Atan1' */
  0.78539816339744828,                 /* '<S234>/Add1' */
  2.3561944901923448,                  /* '<S234>/Atan3' */
  3.9269908169872414,                  /* '<S234>/Add2' */
  -2.3561944901923448,                 /* '<S234>/Atan4' */
  -0.78539816339744828                 /* '<S234>/Add3' */
};

/* Constant parameters (default storage) */
const ConstP_Code_Gen_Model_T Code_Gen_Model_ConstP = {
  /* Expression: Spline_Capture_Radius
   * Referenced by: '<S80>/Capture Radius'
   */
  { 0.2, 0.2, 0.25, 0.5 },

  /* Pooled Parameter (Expression: Spline_Velocity_Axis)
   * Referenced by:
   *   '<S80>/Capture Radius'
   *   '<S80>/Lookahead Distance'
   */
  { 0.5, 1.5, 2.5, 3.5 },

  /* Expression: Spline_Lookahead_Dist
   * Referenced by: '<S80>/Lookahead Distance'
   */
  { 0.2, 0.2, 0.2, 0.4 },

  /* Expression: Spline_Ref_Poses_auto
   * Referenced by: '<S2>/Constant4'
   */
  { 2.587625, 2.9058230515339463, 3.3300871202458748, 3.6482851717798215,
    3.1616501485476349, 2.587625, 2.0135998514523656, 1.5269648282201789,
    1.20180570123307, 1.087625, 1.2018057012330696, 1.5269648282201786,
    2.0135998514523656, 2.5876249999999996, 3.1616501485476349,
    3.648285171779821, 3.3300871202458744, 2.9058230515339463, 2.587625,
    2.4042499999999998, 2.722448051533946, 3.1467121202458745,
    3.4649101717798212, 3.7900692987669298, 3.9042499999999998,
    3.7900692987669298, 3.4649101717798212, 2.9782751485476346,
    2.4042499999999998, 1.8302248514523658, 1.3435898282201786,
    1.0184307012330696, 0.90424999999999978, 1.0184307012330698,
    1.3435898282201784, 1.6617878797541248, 2.0860519484660536,
    2.4042499999999998, 3.5, 3.5, 2.4499999999999997, 1.75, 3.5, 3.5, 3.5, 3.5,
    3.5, 3.5, 3.5, 3.5, 3.5, 3.5, 2.4499999999999997, 1.75, 3.5, 3.5,
    0.35000000000000003, 0.78539816339744828, 0.78539816339744828,
    0.78539816339744828, 0.78539816339744828, 1.1780972450961724,
    1.5707963267948966, 1.9634954084936207, 2.3561944901923448,
    2.748893571891069, 3.1415926535897931, 3.5342917352885168,
    3.9269908169872414, 4.319689898685966, 4.71238898038469, 5.1050880620834143,
    5.497787143782138, 5.497787143782138, 5.497787143782138, 5.497787143782138 },

  /* Pooled Parameter (Expression: Steering_Mod_Drv_out)
   * Referenced by:
   *   '<S288>/Modulation_Drv_X'
   *   '<S288>/Modulation_Drv_Y'
   */
  { -1.0, -0.58, -0.31, -0.18, -0.14, -0.09, -0.06, -0.04, -0.01, -0.0, 0.0, 0.0,
    0.01, 0.04, 0.06, 0.09, 0.14, 0.18, 0.31, 0.58, 1.0 },

  /* Pooled Parameter (Expression: Steering_Mod_Drv_in)
   * Referenced by:
   *   '<S288>/Modulation_Drv_X'
   *   '<S288>/Modulation_Drv_Y'
   */
  { -1.0, -0.9, -0.8, -0.7, -0.6, -0.5, -0.45, -0.4, -0.35, -0.3, 0.0, 0.3, 0.35,
    0.4, 0.45, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 },

  /* Expression: Steering_Mod_Str_Rel_out
   * Referenced by: '<S287>/Modulation_Str_X_Rel'
   */
  { -1.0, -0.75, -0.55, -0.4, -0.27, -0.17, -0.1, -0.04, -0.01, -0.0, 0.0, 0.0,
    0.01, 0.04, 0.1, 0.17, 0.27, 0.4, 0.55, 0.75, 1.0 },

  /* Expression: Steering_Mod_Str_Rel_in
   * Referenced by: '<S287>/Modulation_Str_X_Rel'
   */
  { -1.0, -0.9, -0.8, -0.7, -0.6, -0.5, -0.4, -0.3, -0.25, -0.2, 0.0, 0.2, 0.25,
    0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0 },

  /* Expression: Rotation_Local_Inv
   * Referenced by: '<S8>/Constant4'
   */
  { 0.25, 0.0, 0.0, 0.25, 0.25, 0.0, 0.0, 0.25, 0.25, 0.0, 0.0, 0.25, 0.25, 0.0,
    0.0, 0.25 },

  /* Pooled Parameter (Expression: Drive_Motor_Control_Scale_Factor)
   * Referenced by:
   *   '<S152>/1-D Lookup Table'
   *   '<S173>/1-D Lookup Table'
   *   '<S194>/1-D Lookup Table'
   *   '<S215>/1-D Lookup Table'
   */
  { 1.0, 0.05 },

  /* Pooled Parameter (Expression: Drive_Motor_Control_Module_Angle_Error)
   * Referenced by:
   *   '<S152>/1-D Lookup Table'
   *   '<S173>/1-D Lookup Table'
   *   '<S194>/1-D Lookup Table'
   *   '<S215>/1-D Lookup Table'
   */
  { 0.0, 0.78539816339744828 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
