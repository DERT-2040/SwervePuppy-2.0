/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.h
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

/* Block signals for system '<S38>/Modulo by Constant' */
typedef struct {
  real_T ModulobyConstant;             /* '<S38>/Modulo by Constant' */
} B_ModulobyConstant_Code_Gen_M_T;

/* Block states (default storage) for system '<S38>/Modulo by Constant' */
typedef struct {
  fixed_system_ModByConstant_Co_T obj; /* '<S38>/Modulo by Constant' */
  boolean_T objisempty;                /* '<S38>/Modulo by Constant' */
} DW_ModulobyConstant_Code_Gen__T;

/* Block signals (default storage) */
typedef struct {
  real_T Translation_Speed;            /* '<S132>/Sum' */
  real_T Translation_Angle;            /* '<S1>/Merge3' */
  real_T Translation_Steering_Cmd;     /* '<S126>/Switch' */
  real_T Steering_Abs_Cmd;             /* '<S1>/Merge1' */
  real_T Steering_Localized_Cmd;       /* '<S141>/Sum' */
  real_T Desired_Module_Angle;         /* '<S169>/Switch' */
  real_T Optimized_Motor_Speed;        /* '<S105>/Product2' */
  real_T Optimized_Module_Angle;       /* '<S102>/Angle_Switch' */
  real_T Desired_Module_Angle_l;       /* '<S164>/Switch' */
  real_T Optimized_Motor_Speed_o;      /* '<S80>/Product2' */
  real_T Optimized_Module_Angle_e;     /* '<S77>/Angle_Switch' */
  real_T Desired_Module_Angle_lh;      /* '<S159>/Switch' */
  real_T Optimized_Motor_Speed_g;      /* '<S55>/Product2' */
  real_T Optimized_Module_Angle_eg;    /* '<S52>/Angle_Switch' */
  real_T Desired_Module_Angle_f;       /* '<S154>/Switch' */
  real_T Optimized_Motor_Speed_n;      /* '<S30>/Product2' */
  real_T Optimized_Module_Angle_p;     /* '<S27>/Angle_Switch' */
  real_T X_global_est_m;               /* '<S4>/Accumulator2' */
  real_T Y_global_est_m;               /* '<S4>/Accumulator' */
  B_ModulobyConstant_Code_Gen_M_T ModulobyConstant_nq;/* '<S38>/Modulo by Constant' */
  B_ModulobyConstant_Code_Gen_M_T ModulobyConstant_j;/* '<S38>/Modulo by Constant' */
  B_ModulobyConstant_Code_Gen_M_T ModulobyConstant_ns;/* '<S38>/Modulo by Constant' */
  B_ModulobyConstant_Code_Gen_M_T ModulobyConstant_l;/* '<S38>/Modulo by Constant' */
  B_ModulobyConstant_Code_Gen_M_T ModulobyConstant_g;/* '<S38>/Modulo by Constant' */
  B_ModulobyConstant_Code_Gen_M_T ModulobyConstant_d;/* '<S38>/Modulo by Constant' */
  B_ModulobyConstant_Code_Gen_M_T ModulobyConstant_n;/* '<S38>/Modulo by Constant' */
  B_ModulobyConstant_Code_Gen_M_T ModulobyConstant;/* '<S38>/Modulo by Constant' */
} B_Code_Gen_Model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S9>/UD' */
  real_T UD_DSTATE_m;                  /* '<S10>/UD' */
  real_T UD_DSTATE_i;                  /* '<S11>/UD' */
  real_T UD_DSTATE_c;                  /* '<S12>/UD' */
  real_T UD_DSTATE_d;                  /* '<S8>/UD' */
  real_T UnitDelay1_DSTATE;            /* '<S146>/Unit Delay1' */
  real_T UD_DSTATE_a;                  /* '<S145>/UD' */
  real_T UnitDelay_DSTATE_m;           /* '<S144>/Unit Delay' */
  real_T UnitDelay1_DSTATE_k;          /* '<S111>/Unit Delay1' */
  real_T UD_DSTATE_cs;                 /* '<S110>/UD' */
  real_T UnitDelay_DSTATE_a;           /* '<S99>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i;          /* '<S107>/Unit Delay1' */
  real_T UD_DSTATE_l;                  /* '<S106>/UD' */
  real_T UnitDelay_DSTATE_l;           /* '<S98>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S86>/Unit Delay1' */
  real_T UD_DSTATE_lh;                 /* '<S85>/UD' */
  real_T UnitDelay_DSTATE_gp;          /* '<S74>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n;          /* '<S82>/Unit Delay1' */
  real_T UD_DSTATE_k;                  /* '<S81>/UD' */
  real_T UnitDelay_DSTATE_k;           /* '<S73>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b;          /* '<S61>/Unit Delay1' */
  real_T UD_DSTATE_e;                  /* '<S60>/UD' */
  real_T UnitDelay_DSTATE_e;           /* '<S49>/Unit Delay' */
  real_T UnitDelay1_DSTATE_na;         /* '<S57>/Unit Delay1' */
  real_T UD_DSTATE_i1;                 /* '<S56>/UD' */
  real_T UnitDelay_DSTATE_d;           /* '<S48>/Unit Delay' */
  real_T UnitDelay1_DSTATE_a;          /* '<S36>/Unit Delay1' */
  real_T UD_DSTATE_o;                  /* '<S35>/UD' */
  real_T UnitDelay_DSTATE_f;           /* '<S24>/Unit Delay' */
  real_T UnitDelay1_DSTATE_bk;         /* '<S32>/Unit Delay1' */
  real_T UD_DSTATE_b;                  /* '<S31>/UD' */
  real_T UnitDelay_DSTATE_em;          /* '<S23>/Unit Delay' */
  real_T Accumulator2_DSTATE;          /* '<S4>/Accumulator2' */
  real_T Accumulator_DSTATE;           /* '<S4>/Accumulator' */
  real_T UnitDelay1_DSTATE_d;          /* '<S180>/Unit Delay1' */
  real_T UnitDelay_DSTATE_h;           /* '<S179>/Unit Delay' */
  real_T UnitDelay_DSTATE_g4;          /* '<S180>/Unit Delay' */
  real_T UnitDelay1_DSTATE_kr;         /* '<S179>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_f;     /* '<S193>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_l;          /* '<S189>/Unit Delay1' */
  real_T UnitDelay_DSTATE_p;           /* '<S189>/Unit Delay' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S134>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S143>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S193>/FixPt Unit Delay2' */
  DW_ModulobyConstant_Code_Gen__T ModulobyConstant_nq;/* '<S38>/Modulo by Constant' */
  DW_ModulobyConstant_Code_Gen__T ModulobyConstant_j;/* '<S38>/Modulo by Constant' */
  DW_ModulobyConstant_Code_Gen__T ModulobyConstant_ns;/* '<S38>/Modulo by Constant' */
  DW_ModulobyConstant_Code_Gen__T ModulobyConstant_l;/* '<S38>/Modulo by Constant' */
  DW_ModulobyConstant_Code_Gen__T ModulobyConstant_g;/* '<S38>/Modulo by Constant' */
  DW_ModulobyConstant_Code_Gen__T ModulobyConstant_d;/* '<S38>/Modulo by Constant' */
  DW_ModulobyConstant_Code_Gen__T ModulobyConstant_n;/* '<S38>/Modulo by Constant' */
  DW_ModulobyConstant_Code_Gen__T ModulobyConstant;/* '<S38>/Modulo by Constant' */
} DW_Code_Gen_Model_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Constant;               /* '<S1>/Constant' */
  const real_T Constant1;              /* '<S1>/Constant1' */
  const real_T UnaryMinus;             /* '<S18>/Unary Minus' */
  const real_T Modulus;                /* '<S34>/Subtract' */
  const real_T Cos5;                   /* '<S43>/Cos5' */
  const real_T Sin5;                   /* '<S43>/Sin5' */
  const real_T UnaryMinus_j;           /* '<S19>/Unary Minus' */
  const real_T Modulus_d;              /* '<S59>/Subtract' */
  const real_T Cos5_g;                 /* '<S68>/Cos5' */
  const real_T Sin5_m;                 /* '<S68>/Sin5' */
  const real_T UnaryMinus_m;           /* '<S20>/Unary Minus' */
  const real_T Modulus_o;              /* '<S84>/Subtract' */
  const real_T Cos5_i;                 /* '<S93>/Cos5' */
  const real_T Sin5_e;                 /* '<S93>/Sin5' */
  const real_T UnaryMinus_e;           /* '<S21>/Unary Minus' */
  const real_T Modulus_i;              /* '<S109>/Subtract' */
  const real_T Cos5_b;                 /* '<S118>/Cos5' */
  const real_T Sin5_c;                 /* '<S118>/Sin5' */
  const real_T UnaryMinus_p;           /* '<S135>/Unary Minus' */
  const real_T UnaryMinus1;            /* '<S135>/Unary Minus1' */
  const real_T UnaryMinus_h;           /* '<S136>/Unary Minus' */
  const real_T Modulus_n;              /* '<S148>/Subtract' */
  const real_T Atan2;                  /* '<S123>/Atan2' */
  const real_T FL_Tangent_Angle;       /* '<S123>/Add' */
  const real_T Atan1;                  /* '<S123>/Atan1' */
  const real_T FR_Tangent_Angle;       /* '<S123>/Add1' */
  const real_T Atan3;                  /* '<S123>/Atan3' */
  const real_T BL_Tangent_Angle;       /* '<S123>/Add2' */
  const real_T Atan4;                  /* '<S123>/Atan4' */
  const real_T BR_Tangent_Angle;       /* '<S123>/Add3' */
} ConstB_Code_Gen_Model_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: Steering_Mod_Str_Rel_out
   * Referenced by: '<S176>/Modulation_Str_X_Rel'
   */
  real_T Modulation_Str_X_Rel_tableData[21];

  /* Expression: Steering_Mod_Str_Rel_in
   * Referenced by: '<S176>/Modulation_Str_X_Rel'
   */
  real_T Modulation_Str_X_Rel_bp01Data[21];

  /* Pooled Parameter (Expression: Steering_Mod_Drv_out)
   * Referenced by:
   *   '<S177>/Modulation_Drv_X'
   *   '<S177>/Modulation_Drv_Y'
   */
  real_T pooled11[21];

  /* Pooled Parameter (Expression: Steering_Mod_Drv_in)
   * Referenced by:
   *   '<S177>/Modulation_Drv_X'
   *   '<S177>/Modulation_Drv_Y'
   */
  real_T pooled12[21];

  /* Expression: Rotation_Local_Inv
   * Referenced by: '<S4>/Constant4'
   */
  real_T Constant4_Value[16];

  /* Pooled Parameter (Expression: Drive_Motor_Control_Scale_Factor)
   * Referenced by:
   *   '<S29>/1-D Lookup Table'
   *   '<S54>/1-D Lookup Table'
   *   '<S79>/1-D Lookup Table'
   *   '<S104>/1-D Lookup Table'
   */
  real_T pooled25[2];

  /* Pooled Parameter (Expression: Drive_Motor_Control_Module_Angle_Error)
   * Referenced by:
   *   '<S29>/1-D Lookup Table'
   *   '<S54>/1-D Lookup Table'
   *   '<S79>/1-D Lookup Table'
   *   '<S104>/1-D Lookup Table'
   */
  real_T pooled26[2];
} ConstP_Code_Gen_Model_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T GameState;                    /* '<Root>/GameState' */
  real_T Steer_Joystick_X;             /* '<Root>/Steer_Joystick_X' */
  real_T Steer_Joystick_Y;             /* '<Root>/Steer_Joystick_Y' */
  real_T Drive_Joystick_X;             /* '<Root>/Drive_Joystick_X' */
  real_T Drive_Joystick_Y;             /* '<Root>/Drive_Joystick_Y' */
  real_T Is_Boost_Trigger_Pulled;      /* '<Root>/Is_Boost_Trigger_Pulled' */
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
  real_T FrontLeft_Drive_Rev;          /* '<Root>/FrontLeft_Drive_Rev' */
  real_T FrontRight_Drive_Rev;         /* '<Root>/FrontRight_Drive_Rev' */
  real_T BackLeft_Drive_Rev;           /* '<Root>/BackLeft_Drive_Rev' */
  real_T BackRight_Drive_Rev;          /* '<Root>/BackRight_Drive_Rev' */
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

/*
 * Exported Global Parameters
 *
 * Note: Exported global parameters are tunable parameters with an exported
 * global storage class designation.  Code generation will declare the memory for
 * these parameters and exports their symbols.
 *
 */
extern real_T Boost_Trigger_Decreasing_Limit;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S190>/Constant1'
                                      */
extern real_T Boost_Trigger_Increasing_Limit;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S190>/Constant3'
                                      */
extern real_T Translation_Speed_Rate_Limit_Dec;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S124>/Constant1'
                                    */
extern real_T Translation_Speed_Rate_Limit_Inc;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S124>/Constant3'
                                    */

/* Model entry point functions */
extern void Code_Gen_Model_initialize(void);
extern void Code_Gen_Model_step(void);
extern void Code_Gen_Model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Code_Gen_Model_T *const Code_Gen_Model_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S33>/Data Type Propagation' : Unused code path elimination
 * Block '<S23>/Scope' : Unused code path elimination
 * Block '<S37>/Data Type Duplicate' : Unused code path elimination
 * Block '<S37>/Data Type Propagation' : Unused code path elimination
 * Block '<S24>/Scope' : Unused code path elimination
 * Block '<S29>/Scope' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Data Type Propagation' : Unused code path elimination
 * Block '<S48>/Scope' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate' : Unused code path elimination
 * Block '<S62>/Data Type Propagation' : Unused code path elimination
 * Block '<S49>/Scope' : Unused code path elimination
 * Block '<S54>/Scope' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S83>/Data Type Propagation' : Unused code path elimination
 * Block '<S73>/Scope' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate' : Unused code path elimination
 * Block '<S87>/Data Type Propagation' : Unused code path elimination
 * Block '<S74>/Scope' : Unused code path elimination
 * Block '<S79>/Scope' : Unused code path elimination
 * Block '<S108>/Data Type Duplicate' : Unused code path elimination
 * Block '<S108>/Data Type Propagation' : Unused code path elimination
 * Block '<S98>/Scope' : Unused code path elimination
 * Block '<S112>/Data Type Duplicate' : Unused code path elimination
 * Block '<S112>/Data Type Propagation' : Unused code path elimination
 * Block '<S99>/Scope' : Unused code path elimination
 * Block '<S104>/Scope' : Unused code path elimination
 * Block '<S133>/Data Type Duplicate' : Unused code path elimination
 * Block '<S133>/Data Type Propagation' : Unused code path elimination
 * Block '<S134>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S142>/Data Type Duplicate' : Unused code path elimination
 * Block '<S142>/Data Type Propagation' : Unused code path elimination
 * Block '<S143>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S147>/Data Type Duplicate' : Unused code path elimination
 * Block '<S147>/Data Type Propagation' : Unused code path elimination
 * Block '<S144>/Scope' : Unused code path elimination
 * Block '<S192>/Data Type Duplicate' : Unused code path elimination
 * Block '<S192>/Data Type Propagation' : Unused code path elimination
 * Block '<S193>/FixPt Data Type Duplicate1' : Unused code path elimination
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
 * '<S1>'   : 'Code_Gen_Model/RoboRio Controls'
 * '<S2>'   : 'Code_Gen_Model/RoboRio Controls/Autonomous'
 * '<S3>'   : 'Code_Gen_Model/RoboRio Controls/Disabled'
 * '<S4>'   : 'Code_Gen_Model/RoboRio Controls/Odometry'
 * '<S5>'   : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive'
 * '<S6>'   : 'Code_Gen_Model/RoboRio Controls/Teleop'
 * '<S7>'   : 'Code_Gen_Model/RoboRio Controls/Test'
 * '<S8>'   : 'Code_Gen_Model/RoboRio Controls/Odometry/Difference'
 * '<S9>'   : 'Code_Gen_Model/RoboRio Controls/Odometry/Difference1'
 * '<S10>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Difference3'
 * '<S11>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Difference4'
 * '<S12>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Difference5'
 * '<S13>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Polar to Cartesian'
 * '<S14>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Polar to Cartesian1'
 * '<S15>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Polar to Cartesian2'
 * '<S16>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Polar to Cartesian3'
 * '<S17>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Degrees to Radians'
 * '<S18>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module'
 * '<S19>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1'
 * '<S20>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2'
 * '<S21>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3'
 * '<S22>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle'
 * '<S23>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Continuous PID'
 * '<S24>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID'
 * '<S25>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Make_Turning_Encoder_Value'
 * '<S26>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Modulus 1 with sign'
 * '<S27>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize'
 * '<S28>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Sign_Dependant_Limiter'
 * '<S29>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Subsystem'
 * '<S30>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Tangential_Velocity_To_RPM'
 * '<S31>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Continuous PID/Difference'
 * '<S32>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Continuous PID/Low_Pass_Filter'
 * '<S33>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Continuous PID/Saturation Dynamic'
 * '<S34>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Continuous PID/Subsystem'
 * '<S35>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID/Difference'
 * '<S36>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S37>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S38>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Make_Turning_Encoder_Value/Modulus 1 with sign'
 * '<S39>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Make_Turning_Encoder_Value/Modulus 1 with sign/Compare To Zero'
 * '<S40>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Modulus 1 with sign/Compare To Zero'
 * '<S41>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/Compare To Constant'
 * '<S42>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1'
 * '<S43>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy'
 * '<S44>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy'
 * '<S45>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S46>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy/Compare To Constant'
 * '<S47>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Sign_Dependant_Limiter/Compare To Constant'
 * '<S48>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Continuous PID'
 * '<S49>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID'
 * '<S50>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Make_Turning_Encoder_Value'
 * '<S51>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Modulus 1 with sign'
 * '<S52>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize'
 * '<S53>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Sign_Dependant_Limiter'
 * '<S54>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Subsystem'
 * '<S55>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Tangential_Velocity_To_RPM'
 * '<S56>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Continuous PID/Difference'
 * '<S57>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Continuous PID/Low_Pass_Filter'
 * '<S58>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Continuous PID/Saturation Dynamic'
 * '<S59>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Continuous PID/Subsystem'
 * '<S60>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID/Difference'
 * '<S61>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S62>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S63>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Make_Turning_Encoder_Value/Modulus 1 with sign'
 * '<S64>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Make_Turning_Encoder_Value/Modulus 1 with sign/Compare To Zero'
 * '<S65>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Modulus 1 with sign/Compare To Zero'
 * '<S66>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/Compare To Constant'
 * '<S67>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1'
 * '<S68>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy'
 * '<S69>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy'
 * '<S70>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S71>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy/Compare To Constant'
 * '<S72>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Sign_Dependant_Limiter/Compare To Constant'
 * '<S73>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Continuous PID'
 * '<S74>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID'
 * '<S75>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Make_Turning_Encoder_Value'
 * '<S76>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Modulus 1 with sign'
 * '<S77>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize'
 * '<S78>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Sign_Dependant_Limiter'
 * '<S79>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Subsystem'
 * '<S80>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Tangential_Velocity_To_RPM'
 * '<S81>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Continuous PID/Difference'
 * '<S82>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Continuous PID/Low_Pass_Filter'
 * '<S83>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Continuous PID/Saturation Dynamic'
 * '<S84>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Continuous PID/Subsystem'
 * '<S85>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID/Difference'
 * '<S86>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S87>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S88>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Make_Turning_Encoder_Value/Modulus 1 with sign'
 * '<S89>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Make_Turning_Encoder_Value/Modulus 1 with sign/Compare To Zero'
 * '<S90>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Modulus 1 with sign/Compare To Zero'
 * '<S91>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/Compare To Constant'
 * '<S92>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1'
 * '<S93>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy'
 * '<S94>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy'
 * '<S95>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S96>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy/Compare To Constant'
 * '<S97>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Sign_Dependant_Limiter/Compare To Constant'
 * '<S98>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Continuous PID'
 * '<S99>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID'
 * '<S100>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Make_Turning_Encoder_Value'
 * '<S101>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Modulus 1 with sign'
 * '<S102>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize'
 * '<S103>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Sign_Dependant_Limiter'
 * '<S104>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Subsystem'
 * '<S105>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Tangential_Velocity_To_RPM'
 * '<S106>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Continuous PID/Difference'
 * '<S107>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Continuous PID/Low_Pass_Filter'
 * '<S108>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Continuous PID/Saturation Dynamic'
 * '<S109>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Continuous PID/Subsystem'
 * '<S110>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID/Difference'
 * '<S111>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S112>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S113>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Make_Turning_Encoder_Value/Modulus 1 with sign'
 * '<S114>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Make_Turning_Encoder_Value/Modulus 1 with sign/Compare To Zero'
 * '<S115>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Modulus 1 with sign/Compare To Zero'
 * '<S116>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/Compare To Constant'
 * '<S117>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1'
 * '<S118>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy'
 * '<S119>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy'
 * '<S120>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S121>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy/Compare To Constant'
 * '<S122>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Sign_Dependant_Limiter/Compare To Constant'
 * '<S123>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function'
 * '<S124>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Rate Limit'
 * '<S125>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command'
 * '<S126>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command'
 * '<S127>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator'
 * '<S128>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Rate Limit/Compare To Zero'
 * '<S129>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Rate Limit/Compare To Zero1'
 * '<S130>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Rate Limit/Compare To Zero2'
 * '<S131>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Rate Limit/Compare To Zero3'
 * '<S132>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Rate Limit/Discrete Rate Limiter'
 * '<S133>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S134>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S135>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Rate Limit2'
 * '<S136>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID'
 * '<S137>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Rate Limit2/Compare To Zero'
 * '<S138>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Rate Limit2/Compare To Zero1'
 * '<S139>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Rate Limit2/Compare To Zero2'
 * '<S140>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Rate Limit2/Compare To Zero3'
 * '<S141>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Rate Limit2/Discrete Rate Limiter'
 * '<S142>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Rate Limit2/Discrete Rate Limiter/Saturation Dynamic'
 * '<S143>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Rate Limit2/Discrete Rate Limiter/Unit Delay External IC'
 * '<S144>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Continuous PID1'
 * '<S145>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Continuous PID1/Difference'
 * '<S146>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Continuous PID1/Low_Pass_Filter'
 * '<S147>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Continuous PID1/Saturation Dynamic'
 * '<S148>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Continuous PID1/Subsystem'
 * '<S149>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command/Field_Oriented_Offset2'
 * '<S150>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add'
 * '<S151>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1'
 * '<S152>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2'
 * '<S153>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3'
 * '<S154>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver'
 * '<S155>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Cartesian to Polar'
 * '<S156>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian'
 * '<S157>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian1'
 * '<S158>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver/Compare To Zero1'
 * '<S159>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver'
 * '<S160>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Cartesian to Polar'
 * '<S161>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian'
 * '<S162>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian1'
 * '<S163>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver/Compare To Zero1'
 * '<S164>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver'
 * '<S165>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Cartesian to Polar'
 * '<S166>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian'
 * '<S167>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian1'
 * '<S168>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver/Compare To Zero1'
 * '<S169>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver'
 * '<S170>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Cartesian to Polar'
 * '<S171>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian'
 * '<S172>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian1'
 * '<S173>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver/Compare To Zero1'
 * '<S174>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive'
 * '<S175>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Degrees to Radians'
 * '<S176>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering'
 * '<S177>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation'
 * '<S178>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Circular Deadband'
 * '<S179>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment'
 * '<S180>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Latch Outputs when Both Inputs Zero'
 * '<S181>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero'
 * '<S182>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero1'
 * '<S183>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero2'
 * '<S184>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero3'
 * '<S185>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero4'
 * '<S186>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Latch Outputs when Both Inputs Zero/Compare To Zero'
 * '<S187>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Latch Outputs when Both Inputs Zero/Compare To Zero1'
 * '<S188>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit'
 * '<S189>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero'
 * '<S190>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit'
 * '<S191>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter'
 * '<S192>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S193>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S194>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero'
 * '<S195>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero1'
 */
#endif                                 /* RTW_HEADER_Code_Gen_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
