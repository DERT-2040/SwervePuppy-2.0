/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model_private.h
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Jun 14 16:13:20 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Code_Gen_Model_private_h_
#define RTW_HEADER_Code_Gen_Model_private_h_
#include "rtwtypes.h"
#include "Code_Gen_Model.h"
#include "Code_Gen_Model_types.h"

extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T look1_binlcpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void Code_Gen_Model_Disabled(real_T *rty_FrontLeft_Drive_DutyCycle,
  real_T *rty_FrontLeft_Steer_DutyCycle, real_T *rty_FrontRight_Drive_DutyCycle,
  real_T *rty_FrontRight_Steer_DutyCycle, real_T *rty_BackLeft_Drive_DutyCycle,
  real_T *rty_BackLeft_Steer_DutyCycle, real_T *rty_BackRight_Drive_DutyCycle,
  real_T *rty_BackRight_Steer_DutyCycle);
extern void Code_Gen_ModulobyConstant_Start(DW_ModulobyConstant_Code_Gen__T
  *localDW);
extern void Code_Gen_Model_ModulobyConstant(real_T rtu_0,
  B_ModulobyConstant_Code_Gen_M_T *localB);

#endif                                /* RTW_HEADER_Code_Gen_Model_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
