/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.h
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.22
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Nov 25 11:38:35 2023
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

/* Block signals (default storage) */
typedef struct {
  real_T FL_Steer_Module_Angle;        /* '<S20>/Add1' */
  real_T FR_Steer_Module_Angle;        /* '<S21>/Add1' */
  real_T BL_Steer_Module_Angle;        /* '<S22>/Add1' */
  real_T BR_Steer_Module_Angle;        /* '<S23>/Add1' */
  real_T Translation_Speed;            /* '<S1>/Merge4' */
  real_T Translation_Speed_o;          /* '<S122>/Sum' */
  real_T Translation_Angle;            /* '<S1>/Merge3' */
  real_T Translation_Steering_Cmd;     /* '<S116>/Switch' */
  real_T Steering_Rel_Cmd;             /* '<S1>/Merge2' */
  real_T Steering_Abs_Cmd;             /* '<S1>/Merge1' */
  real_T Gyro_Angle_Adjusted;          /* '<S1>/Merge' */
  real_T Steering_Localized_PID;       /* '<S135>/Saturation2' */
  real_T Steering_Localized_Cmd;       /* '<S131>/Sum' */
  real_T BR_Desired_Wheel_Speed;       /* '<S160>/Switch1' */
  real_T BR_Desired_Module_Angle;      /* '<S160>/Switch' */
  real_T BL_Desired_Wheel_Speed;       /* '<S155>/Switch1' */
  real_T BL_Desired_Module_Angle;      /* '<S155>/Switch' */
  real_T FR_Desired_Wheel_Speed;       /* '<S150>/Switch1' */
  real_T FR_Desired_Module_Angle;      /* '<S150>/Switch' */
  real_T FL_Desired_Wheel_Speed;       /* '<S145>/Switch1' */
  real_T FL_Desired_Module_Angle;      /* '<S145>/Switch' */
  real_T Odometry_X_global_est_m;      /* '<S5>/Accumulator2' */
  real_T Odometry_X_global_est_ft;     /* '<S19>/meters to feet' */
  real_T Odometry_X_global_TEAR_ft;    /* '<S19>/Subtract' */
  real_T Odometry_Y_global_est_m;      /* '<S5>/Accumulator' */
  real_T Odometry_Y_global_est_ft;     /* '<S19>/meters to feet1' */
  real_T Odometry_Y_global_TEAR_ft;    /* '<S19>/Subtract1' */
  boolean_T Is_Absolute_Translation;   /* '<S1>/Merge5' */
  boolean_T Is_Absolute_Steering;      /* '<S1>/Merge6' */
} B_Code_Gen_Model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S11>/UD' */
  real_T UD_DSTATE_m;                  /* '<S12>/UD' */
  real_T UD_DSTATE_i;                  /* '<S13>/UD' */
  real_T UD_DSTATE_c;                  /* '<S14>/UD' */
  real_T UD_DSTATE_d;                  /* '<S10>/UD' */
  real_T UnitDelay1_DSTATE;            /* '<S138>/Unit Delay1' */
  real_T UD_DSTATE_a;                  /* '<S137>/UD' */
  real_T UnitDelay_DSTATE_m;           /* '<S135>/Unit Delay' */
  real_T UnitDelay1_DSTATE_k;          /* '<S100>/Unit Delay1' */
  real_T UD_DSTATE_cs;                 /* '<S99>/UD' */
  real_T UnitDelay_DSTATE_a;           /* '<S93>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i;          /* '<S111>/Unit Delay1' */
  real_T UD_DSTATE_l;                  /* '<S110>/UD' */
  real_T UnitDelay_DSTATE_l;           /* '<S96>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S79>/Unit Delay1' */
  real_T UD_DSTATE_lh;                 /* '<S78>/UD' */
  real_T UnitDelay_DSTATE_gp;          /* '<S72>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n;          /* '<S90>/Unit Delay1' */
  real_T UD_DSTATE_k;                  /* '<S89>/UD' */
  real_T UnitDelay_DSTATE_k;           /* '<S75>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b;          /* '<S58>/Unit Delay1' */
  real_T UD_DSTATE_e;                  /* '<S57>/UD' */
  real_T UnitDelay_DSTATE_e;           /* '<S51>/Unit Delay' */
  real_T UnitDelay1_DSTATE_na;         /* '<S69>/Unit Delay1' */
  real_T UD_DSTATE_i1;                 /* '<S68>/UD' */
  real_T UnitDelay_DSTATE_d;           /* '<S54>/Unit Delay' */
  real_T UnitDelay1_DSTATE_a;          /* '<S37>/Unit Delay1' */
  real_T UD_DSTATE_o;                  /* '<S36>/UD' */
  real_T UnitDelay_DSTATE_f;           /* '<S30>/Unit Delay' */
  real_T UnitDelay1_DSTATE_bk;         /* '<S48>/Unit Delay1' */
  real_T UD_DSTATE_b;                  /* '<S47>/UD' */
  real_T UnitDelay_DSTATE_em;          /* '<S33>/Unit Delay' */
  real_T Accumulator2_DSTATE;          /* '<S5>/Accumulator2' */
  real_T UnitDelay_DSTATE_c;           /* '<S19>/Unit Delay' */
  real_T Accumulator_DSTATE;           /* '<S5>/Accumulator' */
  real_T UnitDelay1_DSTATE_d;          /* '<S19>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_d2;         /* '<S170>/Unit Delay1' */
  real_T UnitDelay_DSTATE_g4;          /* '<S170>/Unit Delay' */
  real_T UnitDelay_DSTATE_h;           /* '<S169>/Unit Delay' */
  real_T UnitDelay1_DSTATE_kr;         /* '<S169>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_f;     /* '<S183>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_l;          /* '<S179>/Unit Delay1' */
  real_T UnitDelay_DSTATE_p;           /* '<S179>/Unit Delay' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S124>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S133>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S183>/FixPt Unit Delay2' */
} DW_Code_Gen_Model_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Constant;               /* '<S1>/Constant' */
  const real_T Constant1;              /* '<S1>/Constant1' */
  const real_T Cos5;                   /* '<S41>/Cos5' */
  const real_T Sin5;                   /* '<S41>/Sin5' */
  const real_T Cos5_g;                 /* '<S62>/Cos5' */
  const real_T Sin5_m;                 /* '<S62>/Sin5' */
  const real_T Cos5_i;                 /* '<S83>/Cos5' */
  const real_T Sin5_e;                 /* '<S83>/Sin5' */
  const real_T Cos5_b;                 /* '<S104>/Cos5' */
  const real_T Sin5_c;                 /* '<S104>/Sin5' */
  const real_T UnaryMinus;             /* '<S113>/Unary Minus' */
  const real_T UnaryMinus1;            /* '<S113>/Unary Minus1' */
  const real_T UnaryMinus_p;           /* '<S125>/Unary Minus' */
  const real_T UnaryMinus1_c;          /* '<S125>/Unary Minus1' */
  const real_T Atan2;                  /* '<S114>/Atan2' */
  const real_T FL_Tangent_Angle;       /* '<S114>/Add' */
  const real_T Atan1;                  /* '<S114>/Atan1' */
  const real_T FR_Tangent_Angle;       /* '<S114>/Add1' */
  const real_T Atan3;                  /* '<S114>/Atan3' */
  const real_T BL_Tangent_Angle;       /* '<S114>/Add2' */
  const real_T Atan4;                  /* '<S114>/Atan4' */
  const real_T BR_Tangent_Angle;       /* '<S114>/Add3' */
} ConstB_Code_Gen_Model_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: Steering_Mod_Str_Rel_out
   * Referenced by: '<S166>/Modulation_Str_X_Rel'
   */
  real_T Modulation_Str_X_Rel_tableData[21];

  /* Expression: Steering_Mod_Str_Rel_in
   * Referenced by: '<S166>/Modulation_Str_X_Rel'
   */
  real_T Modulation_Str_X_Rel_bp01Data[21];

  /* Pooled Parameter (Expression: Steering_Mod_Drv_out)
   * Referenced by:
   *   '<S167>/Modulation_Drv_X'
   *   '<S167>/Modulation_Drv_Y'
   */
  real_T pooled8[21];

  /* Pooled Parameter (Expression: Steering_Mod_Drv_in)
   * Referenced by:
   *   '<S167>/Modulation_Drv_X'
   *   '<S167>/Modulation_Drv_Y'
   */
  real_T pooled9[21];

  /* Expression: Rotation_Local_Inv
   * Referenced by: '<S5>/Constant4'
   */
  real_T Constant4_Value[16];

  /* Pooled Parameter (Expression: Drive_Motor_Control_Scale_Factor)
   * Referenced by:
   *   '<S32>/1-D Lookup Table'
   *   '<S53>/1-D Lookup Table'
   *   '<S74>/1-D Lookup Table'
   *   '<S95>/1-D Lookup Table'
   */
  real_T pooled23[2];

  /* Pooled Parameter (Expression: Drive_Motor_Control_Module_Angle_Error)
   * Referenced by:
   *   '<S32>/1-D Lookup Table'
   *   '<S53>/1-D Lookup Table'
   *   '<S74>/1-D Lookup Table'
   *   '<S95>/1-D Lookup Table'
   */
  real_T pooled24[2];
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
  real_T FrontLeft_Drive_Motor_Speed; /* '<Root>/FrontLeft_Drive_Motor_Speed' */
  real_T FrontRight_Drive_Motor_Speed;
                                     /* '<Root>/FrontRight_Drive_Motor_Speed' */
  real_T BackLeft_Drive_Motor_Speed;   /* '<Root>/BackLeft_Drive_Motor_Speed' */
  real_T BackRight_Drive_Motor_Speed; /* '<Root>/BackRight_Drive_Motor_Speed' */
  real_T FrontLeft_Steer_Rev;          /* '<Root>/FrontLeft_Steer_Rev' */
  real_T FrontRight_Steer_Rev;         /* '<Root>/FrontRight_Steer_Rev' */
  real_T BackLeft_Steer_Rev;           /* '<Root>/BackLeft_Steer_Rev' */
  real_T BackRight_Steer_Rev;          /* '<Root>/BackRight_Steer_Rev' */
  real_T FrontLeft_Turn_Offset;        /* '<Root>/FrontLeft_Turn_Offset' */
  real_T FrontRight_Turn_Offset;       /* '<Root>/FrontRight_Turn_Offset' */
  real_T BackLeft_Turn_Offset;         /* '<Root>/BackLeft_Turn_Offset' */
  real_T BackRight_Turn_Offset;        /* '<Root>/BackRight_Turn_Offset' */
  boolean_T Is_Absolute_Steering;      /* '<Root>/Is_Absolute_Steering' */
  boolean_T Is_Absolute_Translation;   /* '<Root>/Is_Absolute_Translation' */
  real_T FrontLeft_Drive_Motor_Rev;    /* '<Root>/FrontLeft_Drive_Motor_Rev' */
  real_T FrontRight_Drive_Motor_Rev;   /* '<Root>/FrontRight_Drive_Motor_Rev' */
  real_T BackLeft_Drive_Motor_Rev;     /* '<Root>/BackLeft_Drive_Motor_Rev' */
  real_T BackRight_Drive_Motor_Rev;    /* '<Root>/BackRight_Drive_Motor_Rev' */
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
extern boolean_T Odometry_X_Y_TEAR;    /* Variable: Odometry_X_Y_TEAR
                                        * Referenced by: '<S19>/Constant'
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
 * Block '<S38>/Data Type Duplicate' : Unused code path elimination
 * Block '<S38>/Data Type Propagation' : Unused code path elimination
 * Block '<S30>/Scope' : Unused code path elimination
 * Block '<S32>/Scope' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Data Type Propagation' : Unused code path elimination
 * Block '<S33>/Scope' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Data Type Propagation' : Unused code path elimination
 * Block '<S51>/Scope' : Unused code path elimination
 * Block '<S53>/Scope' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Data Type Propagation' : Unused code path elimination
 * Block '<S54>/Scope' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S80>/Data Type Propagation' : Unused code path elimination
 * Block '<S72>/Scope' : Unused code path elimination
 * Block '<S74>/Scope' : Unused code path elimination
 * Block '<S91>/Data Type Duplicate' : Unused code path elimination
 * Block '<S91>/Data Type Propagation' : Unused code path elimination
 * Block '<S75>/Scope' : Unused code path elimination
 * Block '<S101>/Data Type Duplicate' : Unused code path elimination
 * Block '<S101>/Data Type Propagation' : Unused code path elimination
 * Block '<S93>/Scope' : Unused code path elimination
 * Block '<S95>/Scope' : Unused code path elimination
 * Block '<S112>/Data Type Duplicate' : Unused code path elimination
 * Block '<S112>/Data Type Propagation' : Unused code path elimination
 * Block '<S96>/Scope' : Unused code path elimination
 * Block '<S123>/Data Type Duplicate' : Unused code path elimination
 * Block '<S123>/Data Type Propagation' : Unused code path elimination
 * Block '<S124>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S132>/Data Type Duplicate' : Unused code path elimination
 * Block '<S132>/Data Type Propagation' : Unused code path elimination
 * Block '<S133>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S139>/Data Type Duplicate' : Unused code path elimination
 * Block '<S139>/Data Type Propagation' : Unused code path elimination
 * Block '<S135>/Scope' : Unused code path elimination
 * Block '<S182>/Data Type Duplicate' : Unused code path elimination
 * Block '<S182>/Data Type Propagation' : Unused code path elimination
 * Block '<S183>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S5>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S5>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S5>/Signal Copy2' : Eliminate redundant signal conversion block
 * Block '<S5>/Signal Copy3' : Eliminate redundant signal conversion block
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
 * '<S3>'   : 'Code_Gen_Model/RoboRio Controls/Degrees to Radians'
 * '<S4>'   : 'Code_Gen_Model/RoboRio Controls/Disabled'
 * '<S5>'   : 'Code_Gen_Model/RoboRio Controls/Odometry'
 * '<S6>'   : 'Code_Gen_Model/RoboRio Controls/Steer_Module_Offset_Adjustments'
 * '<S7>'   : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive'
 * '<S8>'   : 'Code_Gen_Model/RoboRio Controls/Teleop'
 * '<S9>'   : 'Code_Gen_Model/RoboRio Controls/Test'
 * '<S10>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Difference'
 * '<S11>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Difference1'
 * '<S12>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Difference3'
 * '<S13>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Difference4'
 * '<S14>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Difference5'
 * '<S15>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Polar to Cartesian'
 * '<S16>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Polar to Cartesian1'
 * '<S17>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Polar to Cartesian2'
 * '<S18>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Polar to Cartesian3'
 * '<S19>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Tear for validation testing'
 * '<S20>'  : 'Code_Gen_Model/RoboRio Controls/Steer_Module_Offset_Adjustments/Angle Modulus'
 * '<S21>'  : 'Code_Gen_Model/RoboRio Controls/Steer_Module_Offset_Adjustments/Angle Modulus1'
 * '<S22>'  : 'Code_Gen_Model/RoboRio Controls/Steer_Module_Offset_Adjustments/Angle Modulus2'
 * '<S23>'  : 'Code_Gen_Model/RoboRio Controls/Steer_Module_Offset_Adjustments/Angle Modulus3'
 * '<S24>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module'
 * '<S25>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1'
 * '<S26>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2'
 * '<S27>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3'
 * '<S28>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle'
 * '<S29>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor'
 * '<S30>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID'
 * '<S31>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize'
 * '<S32>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor'
 * '<S33>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID'
 * '<S34>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Tangential_Velocity_To_RPM'
 * '<S35>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S36>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID/Difference'
 * '<S37>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S38>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S39>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/Compare To Constant'
 * '<S40>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1'
 * '<S41>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy'
 * '<S42>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy'
 * '<S43>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S44>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy/Compare To Constant'
 * '<S45>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S46>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S47>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Difference'
 * '<S48>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S49>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S50>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor'
 * '<S51>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID'
 * '<S52>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize'
 * '<S53>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor'
 * '<S54>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID'
 * '<S55>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Tangential_Velocity_To_RPM'
 * '<S56>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S57>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID/Difference'
 * '<S58>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S59>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S60>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/Compare To Constant'
 * '<S61>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1'
 * '<S62>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy'
 * '<S63>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy'
 * '<S64>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S65>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy/Compare To Constant'
 * '<S66>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S67>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S68>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Difference'
 * '<S69>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S70>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S71>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor'
 * '<S72>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID'
 * '<S73>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize'
 * '<S74>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor'
 * '<S75>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID'
 * '<S76>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Tangential_Velocity_To_RPM'
 * '<S77>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S78>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID/Difference'
 * '<S79>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S80>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S81>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/Compare To Constant'
 * '<S82>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1'
 * '<S83>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy'
 * '<S84>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy'
 * '<S85>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S86>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy/Compare To Constant'
 * '<S87>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S88>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S89>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Difference'
 * '<S90>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S91>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S92>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor'
 * '<S93>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID'
 * '<S94>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize'
 * '<S95>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor'
 * '<S96>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID'
 * '<S97>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Tangential_Velocity_To_RPM'
 * '<S98>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S99>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID/Difference'
 * '<S100>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S101>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S102>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/Compare To Constant'
 * '<S103>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1'
 * '<S104>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy'
 * '<S105>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy'
 * '<S106>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S107>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy/Compare To Constant'
 * '<S108>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S109>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S110>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Difference'
 * '<S111>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S112>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S113>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit'
 * '<S114>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function'
 * '<S115>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command'
 * '<S116>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command'
 * '<S117>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator'
 * '<S118>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero'
 * '<S119>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero1'
 * '<S120>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero2'
 * '<S121>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero3'
 * '<S122>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter'
 * '<S123>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S124>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S125>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit'
 * '<S126>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID'
 * '<S127>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero'
 * '<S128>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero1'
 * '<S129>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero2'
 * '<S130>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero3'
 * '<S131>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter'
 * '<S132>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S133>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S134>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Compare To Constant'
 * '<S135>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping'
 * '<S136>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Angle Modulus'
 * '<S137>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Difference'
 * '<S138>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Low_Pass_Filter'
 * '<S139>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Saturation Dynamic'
 * '<S140>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command/Angle Modulus'
 * '<S141>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add'
 * '<S142>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1'
 * '<S143>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2'
 * '<S144>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3'
 * '<S145>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver'
 * '<S146>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Cartesian to Polar'
 * '<S147>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian'
 * '<S148>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian1'
 * '<S149>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver/Compare To Zero1'
 * '<S150>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver'
 * '<S151>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Cartesian to Polar'
 * '<S152>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian'
 * '<S153>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian1'
 * '<S154>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver/Compare To Zero1'
 * '<S155>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver'
 * '<S156>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Cartesian to Polar'
 * '<S157>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian'
 * '<S158>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian1'
 * '<S159>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver/Compare To Zero1'
 * '<S160>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver'
 * '<S161>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Cartesian to Polar'
 * '<S162>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian'
 * '<S163>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian1'
 * '<S164>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver/Compare To Zero1'
 * '<S165>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive'
 * '<S166>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering'
 * '<S167>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation'
 * '<S168>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Circular Deadband'
 * '<S169>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment'
 * '<S170>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Latch Outputs when Both Inputs Zero'
 * '<S171>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero'
 * '<S172>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero1'
 * '<S173>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero2'
 * '<S174>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero3'
 * '<S175>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero4'
 * '<S176>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Latch Outputs when Both Inputs Zero/Compare To Zero'
 * '<S177>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Latch Outputs when Both Inputs Zero/Compare To Zero1'
 * '<S178>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit'
 * '<S179>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero'
 * '<S180>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit'
 * '<S181>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter'
 * '<S182>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S183>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S184>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero'
 * '<S185>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero1'
 */
#endif                                 /* RTW_HEADER_Code_Gen_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
