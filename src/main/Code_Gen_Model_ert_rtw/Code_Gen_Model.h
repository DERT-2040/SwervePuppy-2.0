/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.h
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 1.27
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Jul  8 16:18:42 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Code_Gen_Model_h_
#define RTW_HEADER_Code_Gen_Model_h_
#ifndef Code_Gen_Model_COMMON_INCLUDES_
#define Code_Gen_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Code_Gen_Model_COMMON_INCLUDES_ */

#include "Code_Gen_Model_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S26>/Modulo by Constant' */
typedef struct {
  real_T ModulobyConstant;             /* '<S26>/Modulo by Constant' */
} B_ModulobyConstant_Code_Gen_M_T;

/* Block states (default storage) for system '<S26>/Modulo by Constant' */
typedef struct {
  fixed_system_ModByConstant_Co_T obj; /* '<S26>/Modulo by Constant' */
  boolean_T objisempty;                /* '<S26>/Modulo by Constant' */
} DW_ModulobyConstant_Code_Gen__T;

/* Block signals (default storage) */
typedef struct {
  real_T Translation_Angle;            /* '<S1>/Merge3' */
  real_T Translation_Steering_Cmd;     /* '<S103>/Unary Minus' */
  real_T Steering_Localized_Cmd;       /* '<S102>/Switch' */
  real_T Desired_Module_Angle;         /* '<S129>/x->theta' */
  real_T Optimized_Module_Angle;       /* '<S83>/Angle_Switch' */
  real_T Desired_Module_Angle_c;       /* '<S126>/x->theta' */
  real_T Optimized_Module_Angle_i;     /* '<S61>/Angle_Switch' */
  real_T Desired_Module_Angle_k;       /* '<S123>/x->theta' */
  real_T Optimized_Module_Angle_j;     /* '<S39>/Angle_Switch' */
  real_T Desired_Module_Angle_cd;      /* '<S120>/x->theta' */
  real_T Optimized_Module_Angle_p;     /* '<S17>/Angle_Switch' */
  B_ModulobyConstant_Code_Gen_M_T ModulobyConstant_i;/* '<S26>/Modulo by Constant' */
  B_ModulobyConstant_Code_Gen_M_T ModulobyConstant_l;/* '<S26>/Modulo by Constant' */
  B_ModulobyConstant_Code_Gen_M_T ModulobyConstant_a;/* '<S26>/Modulo by Constant' */
  B_ModulobyConstant_Code_Gen_M_T ModulobyConstant_c;/* '<S26>/Modulo by Constant' */
  B_ModulobyConstant_Code_Gen_M_T ModulobyConstant_o;/* '<S26>/Modulo by Constant' */
  B_ModulobyConstant_Code_Gen_M_T ModulobyConstant_f;/* '<S26>/Modulo by Constant' */
  B_ModulobyConstant_Code_Gen_M_T ModulobyConstant_p;/* '<S26>/Modulo by Constant' */
  B_ModulobyConstant_Code_Gen_M_T ModulobyConstant;/* '<S26>/Modulo by Constant' */
} B_Code_Gen_Model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay1_DSTATE;            /* '<S112>/Unit Delay1' */
  real_T UD_DSTATE;                    /* '<S111>/UD' */
  real_T UnitDelay_DSTATE;             /* '<S110>/Unit Delay' */
  real_T UnitDelay1_DSTATE_m;          /* '<S90>/Unit Delay1' */
  real_T UD_DSTATE_j;                  /* '<S89>/UD' */
  real_T UnitDelay_DSTATE_c;           /* '<S80>/Unit Delay' */
  real_T UnitDelay1_DSTATE_k;          /* '<S86>/Unit Delay1' */
  real_T UD_DSTATE_l;                  /* '<S85>/UD' */
  real_T UnitDelay_DSTATE_d;           /* '<S79>/Unit Delay' */
  real_T UnitDelay1_DSTATE_j;          /* '<S68>/Unit Delay1' */
  real_T UD_DSTATE_lp;                 /* '<S67>/UD' */
  real_T UnitDelay_DSTATE_b;           /* '<S58>/Unit Delay' */
  real_T UnitDelay1_DSTATE_a;          /* '<S64>/Unit Delay1' */
  real_T UD_DSTATE_c;                  /* '<S63>/UD' */
  real_T UnitDelay_DSTATE_k;           /* '<S57>/Unit Delay' */
  real_T UnitDelay1_DSTATE_c;          /* '<S46>/Unit Delay1' */
  real_T UD_DSTATE_la;                 /* '<S45>/UD' */
  real_T UnitDelay_DSTATE_cd;          /* '<S36>/Unit Delay' */
  real_T UnitDelay1_DSTATE_jq;         /* '<S42>/Unit Delay1' */
  real_T UD_DSTATE_g;                  /* '<S41>/UD' */
  real_T UnitDelay_DSTATE_p;           /* '<S35>/Unit Delay' */
  real_T UnitDelay1_DSTATE_e;          /* '<S24>/Unit Delay1' */
  real_T UD_DSTATE_ln;                 /* '<S23>/UD' */
  real_T UnitDelay_DSTATE_j;           /* '<S14>/Unit Delay' */
  real_T UnitDelay1_DSTATE_o;          /* '<S20>/Unit Delay1' */
  real_T UD_DSTATE_f;                  /* '<S19>/UD' */
  real_T UnitDelay_DSTATE_k0;          /* '<S13>/Unit Delay' */
  real_T UnitDelay_DSTATE_g;           /* '<S136>/Unit Delay' */
  real_T UnitDelay1_DSTATE_d;          /* '<S136>/Unit Delay1' */
  real_T PrevY;                        /* '<S135>/Rate Limiter' */
  DW_ModulobyConstant_Code_Gen__T ModulobyConstant_i;/* '<S26>/Modulo by Constant' */
  DW_ModulobyConstant_Code_Gen__T ModulobyConstant_l;/* '<S26>/Modulo by Constant' */
  DW_ModulobyConstant_Code_Gen__T ModulobyConstant_a;/* '<S26>/Modulo by Constant' */
  DW_ModulobyConstant_Code_Gen__T ModulobyConstant_c;/* '<S26>/Modulo by Constant' */
  DW_ModulobyConstant_Code_Gen__T ModulobyConstant_o;/* '<S26>/Modulo by Constant' */
  DW_ModulobyConstant_Code_Gen__T ModulobyConstant_f;/* '<S26>/Modulo by Constant' */
  DW_ModulobyConstant_Code_Gen__T ModulobyConstant_p;/* '<S26>/Modulo by Constant' */
  DW_ModulobyConstant_Code_Gen__T ModulobyConstant;/* '<S26>/Modulo by Constant' */
} DW_Code_Gen_Model_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T UnaryMinus;             /* '<S8>/Unary Minus' */
  const real_T Minus;                  /* '<S13>/Minus' */
  const real_T Error_Bound;            /* '<S13>/Divide' */
  const real_T UnaryMinus_p;           /* '<S13>/Unary Minus' */
  const real_T Modulus;                /* '<S22>/Subtract' */
  const real_T Cos5;                   /* '<S31>/Cos5' */
  const real_T Sin5;                   /* '<S31>/Sin5' */
  const real_T UnaryMinus_m;           /* '<S9>/Unary Minus' */
  const real_T Minus_i;                /* '<S35>/Minus' */
  const real_T Error_Bound_a;          /* '<S35>/Divide' */
  const real_T UnaryMinus_mf;          /* '<S35>/Unary Minus' */
  const real_T Modulus_h;              /* '<S44>/Subtract' */
  const real_T Cos5_c;                 /* '<S53>/Cos5' */
  const real_T Sin5_d;                 /* '<S53>/Sin5' */
  const real_T UnaryMinus_mp;          /* '<S10>/Unary Minus' */
  const real_T Minus_j;                /* '<S57>/Minus' */
  const real_T Error_Bound_j;          /* '<S57>/Divide' */
  const real_T UnaryMinus_a;           /* '<S57>/Unary Minus' */
  const real_T Modulus_hb;             /* '<S66>/Subtract' */
  const real_T Cos5_e;                 /* '<S75>/Cos5' */
  const real_T Sin5_dw;                /* '<S75>/Sin5' */
  const real_T UnaryMinus_b;           /* '<S11>/Unary Minus' */
  const real_T Minus_l;                /* '<S79>/Minus' */
  const real_T Error_Bound_c;          /* '<S79>/Divide' */
  const real_T UnaryMinus_l;           /* '<S79>/Unary Minus' */
  const real_T Modulus_m;              /* '<S88>/Subtract' */
  const real_T Cos5_m;                 /* '<S97>/Cos5' */
  const real_T Sin5_a;                 /* '<S97>/Sin5' */
  const real_T Minus_g;                /* '<S110>/Minus' */
  const real_T Error_Bound_f;          /* '<S110>/Divide' */
  const real_T UnaryMinus_mw;          /* '<S110>/Unary Minus' */
  const real_T Modulus_a;              /* '<S114>/Subtract' */
  const real_T Y;                      /* '<S105>/Y' */
  const real_T X;                      /* '<S105>/X' */
  const real_T Atan2;                  /* '<S105>/Atan2' */
  const real_T Y_j;                    /* '<S106>/Y' */
  const real_T X_j;                    /* '<S106>/X' */
  const real_T Atan2_i;                /* '<S106>/Atan2' */
  const real_T Y_p;                    /* '<S107>/Y' */
  const real_T X_m;                    /* '<S107>/X' */
  const real_T Atan2_p;                /* '<S107>/Atan2' */
  const real_T Y_h;                    /* '<S108>/Y' */
  const real_T X_f;                    /* '<S108>/X' */
  const real_T Atan2_k;                /* '<S108>/Atan2' */
} ConstB_Code_Gen_Model_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S134>/Modulation_Str_X_Abs'
   *   '<S134>/Modulation_Str_X_Rel'
   *   '<S134>/Modulation_Str_Y_Abs'
   *   '<S135>/Modulation_Drv_X'
   *   '<S135>/Modulation_Drv_Y'
   */
  real_T pooled10[21];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S134>/Modulation_Str_X_Abs'
   *   '<S134>/Modulation_Str_X_Rel'
   *   '<S134>/Modulation_Str_Y_Abs'
   *   '<S135>/Modulation_Drv_X'
   *   '<S135>/Modulation_Drv_Y'
   */
  real_T pooled11[21];
} ConstP_Code_Gen_Model_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T GameState;                    /* '<Root>/GameState' */
  real_T Steer_Joystick_X;             /* '<Root>/Steer_Joystick_X' */
  real_T Steer_Joystick_Y;             /* '<Root>/Steer_Joystick_Y' */
  real_T Drive_Joystick_X;             /* '<Root>/Drive_Joystick_X' */
  real_T Drive_Joystick_Y;             /* '<Root>/Drive_Joystick_Y' */
  real_T Gyro_Angle;                   /* '<Root>/Gyro_Angle' */
  real_T FrontLeft_Drive_Encoder;      /* '<Root>/FrontLeft_Drive_Encoder' */
  real_T FrontRight_Drive_Encoder;     /* '<Root>/FrontRight_Drive_Encoder' */
  real_T BackLeft_Drive_Encoder;       /* '<Root>/BackLeft_Drive_Encoder' */
  real_T BackRight_Drive_Encoder;      /* '<Root>/BackRight_Drive_Encoder' */
  real_T FrontLeft_Steer_Encoder;      /* '<Root>/FrontLeft_Steer_Encoder' */
  real_T FrontRight_Steer_Encoder;     /* '<Root>/FrontRight_Steer_Encoder' */
  real_T BackLeft_Steer_Encoder;       /* '<Root>/BackLeft_Steer_Encoder' */
  real_T BackRight_Steer_Encoder;      /* '<Root>/BackRight_Steer_Encoder' */
  real_T FrontLeft_Turn_Offset;        /* '<Root>/FrontLeft_Turn_Offset' */
  real_T FrontRight_Turn_Offset;       /* '<Root>/FrontRight_Turn_Offset' */
  real_T BackLeft_Turn_Offset;         /* '<Root>/BackLeft_Turn_Offset' */
  real_T BackRight_Turn_Offset;        /* '<Root>/BackRight_Turn_Offset' */
  boolean_T Is_Absolute_Steering;      /* '<Root>/Is_Absolute_Steering' */
  boolean_T Is_Absolute_Translation;   /* '<Root>/Is_Absolute_Translation' */
} ExtU_Code_Gen_Model_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T FrontLeft_Drive_DutyCycle;    /* '<Root>/FrontLeft_Drive_DutyCycle' */
  real_T FrontLeft_Steer_DutyCycle;    /* '<Root>/FrontLeft_Steer_DutyCycle' */
  real_T FrontRight_Drive_DutyCycle;   /* '<Root>/FrontRight_Drive_DutyCycle' */
  real_T FrontRight_Steer_DutyCycle;   /* '<Root>/FrontRight_Steer_DutyCycle' */
  real_T BackLeft_Drive_DutyCycle;     /* '<Root>/BackLeft_Drive_DutyCycle' */
  real_T BackLeft_Steer_DutyCycle;     /* '<Root>/BackLeft_Steer_DutyCycle' */
  real_T BackRight_Drive_DutyCycle;    /* '<Root>/BackRight_Drive_DutyCycle' */
  real_T BackRight_Steer_DutyCycle;    /* '<Root>/BackRight_Steer_DutyCycle' */
} ExtY_Code_Gen_Model_T;

/* Real-time Model Data Structure */
struct tag_RTM_Code_Gen_Model_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Code_Gen_Model_T Code_Gen_Model_B;

/* Block states (default storage) */
extern DW_Code_Gen_Model_T Code_Gen_Model_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Code_Gen_Model_T Code_Gen_Model_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Code_Gen_Model_T Code_Gen_Model_Y;
extern const ConstB_Code_Gen_Model_T Code_Gen_Model_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_Code_Gen_Model_T Code_Gen_Model_ConstP;

/* Model entry point functions */
extern void Code_Gen_Model_initialize(void);
extern void Code_Gen_Model_step(void);
extern void Code_Gen_Model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Code_Gen_Model_T *const Code_Gen_Model_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Propagation' : Unused code path elimination
 * Block '<S13>/Scope' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Propagation' : Unused code path elimination
 * Block '<S14>/Scope' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Propagation' : Unused code path elimination
 * Block '<S35>/Scope' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S47>/Data Type Propagation' : Unused code path elimination
 * Block '<S36>/Scope' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Propagation' : Unused code path elimination
 * Block '<S57>/Scope' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/Data Type Propagation' : Unused code path elimination
 * Block '<S58>/Scope' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate' : Unused code path elimination
 * Block '<S87>/Data Type Propagation' : Unused code path elimination
 * Block '<S79>/Scope' : Unused code path elimination
 * Block '<S91>/Data Type Duplicate' : Unused code path elimination
 * Block '<S91>/Data Type Propagation' : Unused code path elimination
 * Block '<S80>/Scope' : Unused code path elimination
 * Block '<S113>/Data Type Duplicate' : Unused code path elimination
 * Block '<S113>/Data Type Propagation' : Unused code path elimination
 * Block '<S110>/Scope' : Unused code path elimination
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
 * '<Root>' : 'Code_Gen_Model'
 * '<S1>'   : 'Code_Gen_Model/Control'
 * '<S2>'   : 'Code_Gen_Model/Control/Autonomous'
 * '<S3>'   : 'Code_Gen_Model/Control/Disabled'
 * '<S4>'   : 'Code_Gen_Model/Control/Swerve_Drive'
 * '<S5>'   : 'Code_Gen_Model/Control/Teleop'
 * '<S6>'   : 'Code_Gen_Model/Control/Test'
 * '<S7>'   : 'Code_Gen_Model/Control/Swerve_Drive/Degrees to Radians'
 * '<S8>'   : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module'
 * '<S9>'   : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1'
 * '<S10>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2'
 * '<S11>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3'
 * '<S12>'  : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle'
 * '<S13>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Continuous PID'
 * '<S14>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID'
 * '<S15>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Make_Turning_Encoder_Value'
 * '<S16>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Modulus 1 with sign'
 * '<S17>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Optimize'
 * '<S18>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Tangential_Velocity_To_RPM'
 * '<S19>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Continuous PID/Difference'
 * '<S20>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Continuous PID/Low_Pass_Filter'
 * '<S21>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Continuous PID/Saturation Dynamic'
 * '<S22>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Continuous PID/Subsystem'
 * '<S23>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID/Difference'
 * '<S24>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S25>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S26>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Make_Turning_Encoder_Value/Modulus 1 with sign'
 * '<S27>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Make_Turning_Encoder_Value/Modulus 1 with sign/Compare To Zero'
 * '<S28>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Modulus 1 with sign/Compare To Zero'
 * '<S29>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Optimize/Compare To Constant'
 * '<S30>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1'
 * '<S31>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy'
 * '<S32>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy'
 * '<S33>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S34>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy/Compare To Constant'
 * '<S35>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Continuous PID'
 * '<S36>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID'
 * '<S37>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Make_Turning_Encoder_Value'
 * '<S38>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Modulus 1 with sign'
 * '<S39>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Optimize'
 * '<S40>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Tangential_Velocity_To_RPM'
 * '<S41>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Continuous PID/Difference'
 * '<S42>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Continuous PID/Low_Pass_Filter'
 * '<S43>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Continuous PID/Saturation Dynamic'
 * '<S44>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Continuous PID/Subsystem'
 * '<S45>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID/Difference'
 * '<S46>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S47>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S48>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Make_Turning_Encoder_Value/Modulus 1 with sign'
 * '<S49>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Make_Turning_Encoder_Value/Modulus 1 with sign/Compare To Zero'
 * '<S50>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Modulus 1 with sign/Compare To Zero'
 * '<S51>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Optimize/Compare To Constant'
 * '<S52>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1'
 * '<S53>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy'
 * '<S54>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy'
 * '<S55>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S56>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy/Compare To Constant'
 * '<S57>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Continuous PID'
 * '<S58>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID'
 * '<S59>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Make_Turning_Encoder_Value'
 * '<S60>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Modulus 1 with sign'
 * '<S61>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Optimize'
 * '<S62>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Tangential_Velocity_To_RPM'
 * '<S63>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Continuous PID/Difference'
 * '<S64>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Continuous PID/Low_Pass_Filter'
 * '<S65>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Continuous PID/Saturation Dynamic'
 * '<S66>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Continuous PID/Subsystem'
 * '<S67>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID/Difference'
 * '<S68>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S69>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S70>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Make_Turning_Encoder_Value/Modulus 1 with sign'
 * '<S71>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Make_Turning_Encoder_Value/Modulus 1 with sign/Compare To Zero'
 * '<S72>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Modulus 1 with sign/Compare To Zero'
 * '<S73>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Optimize/Compare To Constant'
 * '<S74>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1'
 * '<S75>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy'
 * '<S76>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy'
 * '<S77>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S78>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy/Compare To Constant'
 * '<S79>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Continuous PID'
 * '<S80>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID'
 * '<S81>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Make_Turning_Encoder_Value'
 * '<S82>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Modulus 1 with sign'
 * '<S83>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Optimize'
 * '<S84>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Tangential_Velocity_To_RPM'
 * '<S85>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Continuous PID/Difference'
 * '<S86>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Continuous PID/Low_Pass_Filter'
 * '<S87>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Continuous PID/Saturation Dynamic'
 * '<S88>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Continuous PID/Subsystem'
 * '<S89>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID/Difference'
 * '<S90>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S91>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S92>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Make_Turning_Encoder_Value/Modulus 1 with sign'
 * '<S93>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Make_Turning_Encoder_Value/Modulus 1 with sign/Compare To Zero'
 * '<S94>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Modulus 1 with sign/Compare To Zero'
 * '<S95>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Optimize/Compare To Constant'
 * '<S96>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1'
 * '<S97>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy'
 * '<S98>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy'
 * '<S99>'  : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S100>' : 'Code_Gen_Model/Control/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy/Compare To Constant'
 * '<S101>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function'
 * '<S102>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command'
 * '<S103>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command'
 * '<S104>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator'
 * '<S105>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function/Optimal_Wheel_Rotate_Angle'
 * '<S106>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function/Optimal_Wheel_Rotate_Angle1'
 * '<S107>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function/Optimal_Wheel_Rotate_Angle2'
 * '<S108>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function/Optimal_Wheel_Rotate_Angle3'
 * '<S109>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID'
 * '<S110>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Continuous PID'
 * '<S111>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Continuous PID/Difference'
 * '<S112>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Continuous PID/Low_Pass_Filter'
 * '<S113>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Continuous PID/Saturation Dynamic'
 * '<S114>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Continuous PID/Subsystem'
 * '<S115>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command/Field_Oriented_Offset2'
 * '<S116>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add'
 * '<S117>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1'
 * '<S118>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2'
 * '<S119>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3'
 * '<S120>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Cartesian to Polar'
 * '<S121>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian'
 * '<S122>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian1'
 * '<S123>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Cartesian to Polar'
 * '<S124>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian'
 * '<S125>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian1'
 * '<S126>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Cartesian to Polar'
 * '<S127>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian'
 * '<S128>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian1'
 * '<S129>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Cartesian to Polar'
 * '<S130>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian'
 * '<S131>' : 'Code_Gen_Model/Control/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian1'
 * '<S132>' : 'Code_Gen_Model/Control/Teleop/Joystick_Input_To_Swerve_Drive'
 * '<S133>' : 'Code_Gen_Model/Control/Teleop/Joystick_Input_To_Swerve_Drive/Degrees to Radians'
 * '<S134>' : 'Code_Gen_Model/Control/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering'
 * '<S135>' : 'Code_Gen_Model/Control/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation'
 * '<S136>' : 'Code_Gen_Model/Control/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment'
 * '<S137>' : 'Code_Gen_Model/Control/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero'
 * '<S138>' : 'Code_Gen_Model/Control/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero1'
 * '<S139>' : 'Code_Gen_Model/Control/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero2'
 * '<S140>' : 'Code_Gen_Model/Control/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero3'
 * '<S141>' : 'Code_Gen_Model/Control/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero4'
 */
#endif                                 /* RTW_HEADER_Code_Gen_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
