/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model_private.h
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.26
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Tue Dec 19 18:41:58 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Code_Gen_Model_private_h_
#define RTW_HEADER_Code_Gen_Model_private_h_
#include "rtwtypes.h"
#include "Code_Gen_Model_types.h"
#include "Code_Gen_Model.h"

extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi);
void LookUp_real_T_real_T(real_T *pY, const real_T *pYData, real_T u, const
  real_T *pUData, uint32_T iHi);
extern real_T look1_binlcpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void Code_Gen_Model_Disabled(real_T *rty_Gyro_Angle_Adjusted, real_T
  *rty_Steering_Abs_Cmd, real_T *rty_Steering_Rel_Cmd, real_T
  *rty_Translation_Angle, real_T *rty_Translation_Speed, boolean_T
  *rty_Is_Absolute_Translation_Out, boolean_T *rty_Is_Absolute_Steering_Out);

#endif                                /* RTW_HEADER_Code_Gen_Model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
