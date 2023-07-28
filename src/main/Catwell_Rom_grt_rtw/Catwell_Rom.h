/*
 * Catwell_Rom.h
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

#ifndef RTW_HEADER_Catwell_Rom_h_
#define RTW_HEADER_Catwell_Rom_h_
#ifndef Catwell_Rom_COMMON_INCLUDES_
#define Catwell_Rom_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Catwell_Rom_COMMON_INCLUDES_ */

#include "Catwell_Rom_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include <float.h>
#include <string.h>
#include <stddef.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  driving_internal_planning_Pat_T obj; /* '<Root>/Path Smoother Spline' */
  real_T UnitDelay_DSTATE;             /* '<S3>/Unit Delay' */
  real_T NextOutput;                   /* '<S1>/White Noise' */
  int32_T UnitDelay_DSTATE_n;          /* '<S2>/Unit Delay' */
  int32_T PathSmootherSpline_DIMS1[2]; /* '<Root>/Path Smoother Spline' */
  int32_T PathSmootherSpline_DIMS2[2]; /* '<Root>/Path Smoother Spline' */
  int32_T SFunction_DIMS2[2];          /* '<Root>/MATLAB Function3' */
  int32_T SFunction_DIMS3[2];          /* '<Root>/MATLAB Function3' */
  uint32_T RandSeed;                   /* '<S1>/White Noise' */
  boolean_T objisempty;                /* '<Root>/Path Smoother Spline' */
} DW_Catwell_Rom_T;

/* Parameters (default storage) */
struct P_Catwell_Rom_T_ {
  real_T BandLimitedWhiteNoise_Cov; /* Mask Parameter: BandLimitedWhiteNoise_Cov
                                     * Referenced by: '<S1>/Output'
                                     */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S7>/Constant'
                                       */
  real_T BandLimitedWhiteNoise_seed;
                                   /* Mask Parameter: BandLimitedWhiteNoise_seed
                                    * Referenced by: '<S1>/White Noise'
                                    */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S3>/Out1'
                                        */
  real_T ForIterator_IterationLimit;   /* Expression: 5
                                        * Referenced by: '<S3>/For Iterator'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay'
                                        */
  real_T Samples_Y0;                   /* Computed Parameter: Samples_Y0
                                        * Referenced by: '<S8>/Samples'
                                        */
  real_T Constant1_Value;          /* Expression: Spline_Samples_Per_Quad_Bezier
                                    * Referenced by: '<S8>/Constant1'
                                    */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T Constant7_Value;              /* Expression: 3
                                        * Referenced by: '<S8>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 1
                                        * Referenced by: '<S8>/Constant8'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S1>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S1>/White Noise'
                                        */
  int32_T Out1_Y0_e;                   /* Computed Parameter: Out1_Y0_e
                                        * Referenced by: '<S2>/Out1'
                                        */
  int32_T ForIterator_IterationLimit_m;
                             /* Computed Parameter: ForIterator_IterationLimit_m
                              * Referenced by: '<S2>/For Iterator'
                              */
  int32_T UnitDelay_InitialCondition_b;
                             /* Computed Parameter: UnitDelay_InitialCondition_b
                              * Referenced by: '<S2>/Unit Delay'
                              */
  int32_T ForIterator_IterationLimit_c;
                                   /* Expression: Spline_Samples_Per_Quad_Bezier
                                    * Referenced by: '<S8>/For Iterator'
                                    */
};

/* Real-time Model Data Structure */
struct tag_RTM_Catwell_Rom_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    struct {
      uint8_T TID[4];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[4];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Catwell_Rom_T Catwell_Rom_P;

/* Block states (default storage) */
extern DW_Catwell_Rom_T Catwell_Rom_DW;

/* Model entry point functions */
extern void Catwell_Rom_initialize(void);
extern void Catwell_Rom_step(void);
extern void Catwell_Rom_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Catwell_Rom_T *const Catwell_Rom_M;

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
 * '<S1>'   : 'Catwell_Rom/Band-Limited White Noise'
 * '<S2>'   : 'Catwell_Rom/For Iterator Subsystem1'
 * '<S3>'   : 'Catwell_Rom/For Iterator Subsystem2'
 * '<S4>'   : 'Catwell_Rom/MATLAB Function3'
 * '<S5>'   : 'Catwell_Rom/Ramp1'
 * '<S6>'   : 'Catwell_Rom/Spline_Sampling'
 * '<S7>'   : 'Catwell_Rom/For Iterator Subsystem2/Compare To Constant'
 * '<S8>'   : 'Catwell_Rom/Spline_Sampling/Spline_Sampler'
 */
#endif                                 /* RTW_HEADER_Catwell_Rom_h_ */
