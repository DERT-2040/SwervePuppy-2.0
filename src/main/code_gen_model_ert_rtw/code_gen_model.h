/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: code_gen_model.h
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

#ifndef RTW_HEADER_code_gen_model_h_
#define RTW_HEADER_code_gen_model_h_
#ifndef code_gen_model_COMMON_INCLUDES_
#define code_gen_model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* code_gen_model_COMMON_INCLUDES_ */

#include "code_gen_model_types.h"
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
  real_T Net_input;                    /* '<S3>/Add' */
  real_T Motor_Speed;                  /* '<Root>/Merge' */
  real_T sig_product;                  /* '<S4>/Product' */
  real_T Motor_Speed_g;                /* '<S1>/Chart' */
} B_code_gen_model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S2>/Unit Delay' */
  real_T time;                         /* '<S1>/Chart' */
  uint8_T is_active_c3_code_gen_model; /* '<S1>/Chart' */
  uint8_T is_c3_code_gen_model;        /* '<S1>/Chart' */
} DW_code_gen_model_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Gain3;                  /* '<S6>/Gain3' */
} ConstB_code_gen_model_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Game_State;                   /* '<Root>/Game_State' */
  real_T Trigger_val_p;                /* '<Root>/Trigger_val_p' */
  real_T Trigger_val_n;                /* '<Root>/Trigger_val_n ' */
} ExtU_code_gen_model_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Motor_speed;                  /* '<Root>/Motor_speed' */
  uint8_T LED_Array[87];               /* '<Root>/LED_Array' */
} ExtY_code_gen_model_T;

/* Real-time Model Data Structure */
struct tag_RTM_code_gen_model_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_code_gen_model_T code_gen_model_B;

/* Block states (default storage) */
extern DW_code_gen_model_T code_gen_model_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_code_gen_model_T code_gen_model_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_code_gen_model_T code_gen_model_Y;
extern const ConstB_code_gen_model_T code_gen_model_ConstB;/* constant block i/o */

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T NeoMaxSpeed;             /* Variable: NeoMaxSpeed
                                        * Referenced by:
                                        *   '<S1>/Constant1'
                                        *   '<S4>/Constant1'
                                        */
extern real_T gain;                    /* Variable: gain
                                        * Referenced by: '<S4>/Constant'
                                        */

/* Model entry point functions */
extern void code_gen_model_initialize(void);
extern void code_gen_model_step(void);
extern void code_gen_model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_code_gen_model_T *const code_gen_model_M;

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
 * '<Root>' : 'code_gen_model'
 * '<S1>'   : 'code_gen_model/Auto'
 * '<S2>'   : 'code_gen_model/Disabled'
 * '<S3>'   : 'code_gen_model/Sum Triggers'
 * '<S4>'   : 'code_gen_model/Teleop'
 * '<S5>'   : 'code_gen_model/Auto/Chart'
 * '<S6>'   : 'code_gen_model/Disabled/Array Triangle Gen Fill'
 */
#endif                                 /* RTW_HEADER_code_gen_model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
