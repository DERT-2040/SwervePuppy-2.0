/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Catwell_Rom.h
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

#ifndef RTW_HEADER_Catwell_Rom_h_
#define RTW_HEADER_Catwell_Rom_h_
#ifndef Catwell_Rom_COMMON_INCLUDES_
#define Catwell_Rom_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Catwell_Rom_COMMON_INCLUDES_ */

#include "Catwell_Rom_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  int32_T WhileIterator;               /* '<S6>/While Iterator' */
} B_Catwell_Rom_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Gain;                   /* '<S6>/Gain' */
} ConstB_Catwell_Rom_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Ref_Poses[20];                /* '<Root>/Ref_Poses' */
  real_T Ref_Poses1;                   /* '<Root>/Ref_Poses1' */
  real_T Ref_Poses2;                   /* '<Root>/Ref_Poses2' */
  real_T Ref_Poses3;                   /* '<Root>/Ref_Poses3' */
  real_T Ref_Poses4;                   /* '<Root>/Ref_Poses4' */
  real_T Ref_Poses5;                   /* '<Root>/Ref_Poses5' */
} ExtU_Catwell_Rom_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Index;                        /* '<Root>/Index' */
} ExtY_Catwell_Rom_T;

/* Real-time Model Data Structure */
struct tag_RTM_Catwell_Rom_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Catwell_Rom_T Catwell_Rom_B;

/* External inputs (root inport signals with default storage) */
extern ExtU_Catwell_Rom_T Catwell_Rom_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Catwell_Rom_T Catwell_Rom_Y;
extern const ConstB_Catwell_Rom_T Catwell_Rom_ConstB;/* constant block i/o */

/* Model entry point functions */
extern void Catwell_Rom_initialize(void);
extern void Catwell_Rom_step(void);
extern void Catwell_Rom_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Catwell_Rom_T *const Catwell_Rom_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/FixPt Data Type Duplicate' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Catwell_Rom'
 * '<S1>'   : 'Catwell_Rom/Autonomously_Navigate_Points1'
 * '<S2>'   : 'Catwell_Rom/Autonomously_Navigate_Points1/Compare To Constant'
 * '<S3>'   : 'Catwell_Rom/Autonomously_Navigate_Points1/If Action Subsystem'
 * '<S4>'   : 'Catwell_Rom/Autonomously_Navigate_Points1/Increment Real World'
 * '<S5>'   : 'Catwell_Rom/Autonomously_Navigate_Points1/Rectangle_Checks'
 * '<S6>'   : 'Catwell_Rom/Autonomously_Navigate_Points1/If Action Subsystem/Circle_Checks'
 * '<S7>'   : 'Catwell_Rom/Autonomously_Navigate_Points1/Rectangle_Checks/Bandwidth_Check_Between_Two_Points'
 * '<S8>'   : 'Catwell_Rom/Autonomously_Navigate_Points1/Rectangle_Checks/Compare To Constant'
 * '<S9>'   : 'Catwell_Rom/Autonomously_Navigate_Points1/Rectangle_Checks/Bandwidth_Check_Between_Two_Points/Compare To Constant'
 * '<S10>'  : 'Catwell_Rom/Autonomously_Navigate_Points1/Rectangle_Checks/Bandwidth_Check_Between_Two_Points/Compare To Constant1'
 */
#endif                                 /* RTW_HEADER_Catwell_Rom_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
