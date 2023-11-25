/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.h
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.16
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Fri Nov 24 21:30:40 2023
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
  real_T Translation_Speed;            /* '<S1>/Merge4' */
  real_T Translation_Speed_o;          /* '<S124>/Sum' */
  real_T Translation_Angle;            /* '<S1>/Merge3' */
  real_T Translation_Steering_Cmd;     /* '<S118>/Switch' */
  real_T Steering_Rel_Cmd;             /* '<S1>/Merge2' */
  real_T Steering_Abs_Cmd;             /* '<S1>/Merge1' */
  real_T Gyro_Angle_Adjusted;          /* '<S1>/Merge' */
  real_T Steering_Localized_PID;       /* '<S137>/Saturation2' */
  real_T Steering_Localized_Cmd;       /* '<S133>/Sum' */
  real_T BR_Wheel_Speed;               /* '<S162>/Switch1' */
  real_T BR_Module_Angle;              /* '<S162>/Switch' */
  real_T BR_Steer_Module_Angle_Adjusted;/* '<S102>/Add1' */
  real_T BL_Wheel_Speed;               /* '<S157>/Switch1' */
  real_T BL_Module_Angle;              /* '<S157>/Switch' */
  real_T BL_Steer_Module_Angle_Adjusted;/* '<S79>/Add1' */
  real_T FR_Wheel_Speed;               /* '<S152>/Switch1' */
  real_T FR_Module_Angle;              /* '<S152>/Switch' */
  real_T FR_Steer_Module_Angle_Adjusted;/* '<S56>/Add1' */
  real_T FL_Wheel_Speed;               /* '<S147>/Switch1' */
  real_T FL_Module_Angle;              /* '<S147>/Switch' */
  real_T FL_Steer_Module_Angle_Adjusted;/* '<S33>/Add1' */
  real_T X_global_est_m;               /* '<S4>/Accumulator2' */
  real_T Y_global_est_m;               /* '<S4>/Accumulator' */
  boolean_T Is_Absolute_Translation;   /* '<S1>/Merge5' */
  boolean_T Is_Absolute_Steering;      /* '<S1>/Merge6' */
} B_Code_Gen_Model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S9>/UD' */
  real_T UD_DSTATE_m;                  /* '<S10>/UD' */
  real_T UD_DSTATE_i;                  /* '<S11>/UD' */
  real_T UD_DSTATE_c;                  /* '<S12>/UD' */
  real_T UD_DSTATE_d;                  /* '<S8>/UD' */
  real_T UnitDelay1_DSTATE;            /* '<S140>/Unit Delay1' */
  real_T UD_DSTATE_a;                  /* '<S139>/UD' */
  real_T UnitDelay_DSTATE_m;           /* '<S137>/Unit Delay' */
  real_T UnitDelay1_DSTATE_k;          /* '<S100>/Unit Delay1' */
  real_T UD_DSTATE_cs;                 /* '<S99>/UD' */
  real_T UnitDelay_DSTATE_a;           /* '<S92>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i;          /* '<S111>/Unit Delay1' */
  real_T UD_DSTATE_l;                  /* '<S110>/UD' */
  real_T UnitDelay_DSTATE_l;           /* '<S95>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S77>/Unit Delay1' */
  real_T UD_DSTATE_lh;                 /* '<S76>/UD' */
  real_T UnitDelay_DSTATE_gp;          /* '<S69>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n;          /* '<S88>/Unit Delay1' */
  real_T UD_DSTATE_k;                  /* '<S87>/UD' */
  real_T UnitDelay_DSTATE_k;           /* '<S72>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b;          /* '<S54>/Unit Delay1' */
  real_T UD_DSTATE_e;                  /* '<S53>/UD' */
  real_T UnitDelay_DSTATE_e;           /* '<S46>/Unit Delay' */
  real_T UnitDelay1_DSTATE_na;         /* '<S65>/Unit Delay1' */
  real_T UD_DSTATE_i1;                 /* '<S64>/UD' */
  real_T UnitDelay_DSTATE_d;           /* '<S49>/Unit Delay' */
  real_T UnitDelay1_DSTATE_a;          /* '<S31>/Unit Delay1' */
  real_T UD_DSTATE_o;                  /* '<S30>/UD' */
  real_T UnitDelay_DSTATE_f;           /* '<S23>/Unit Delay' */
  real_T UnitDelay1_DSTATE_bk;         /* '<S42>/Unit Delay1' */
  real_T UD_DSTATE_b;                  /* '<S41>/UD' */
  real_T UnitDelay_DSTATE_em;          /* '<S26>/Unit Delay' */
  real_T Accumulator2_DSTATE;          /* '<S4>/Accumulator2' */
  real_T Accumulator_DSTATE;           /* '<S4>/Accumulator' */
  real_T UnitDelay1_DSTATE_d;          /* '<S173>/Unit Delay1' */
  real_T UnitDelay_DSTATE_h;           /* '<S172>/Unit Delay' */
  real_T UnitDelay_DSTATE_g4;          /* '<S173>/Unit Delay' */
  real_T UnitDelay1_DSTATE_kr;         /* '<S172>/Unit Delay1' */
  real_T FixPtUnitDelay1_DSTATE_f;     /* '<S186>/FixPt Unit Delay1' */
  real_T UnitDelay1_DSTATE_l;          /* '<S182>/Unit Delay1' */
  real_T UnitDelay_DSTATE_p;           /* '<S182>/Unit Delay' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S126>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S135>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S186>/FixPt Unit Delay2' */
} DW_Code_Gen_Model_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Constant;               /* '<S1>/Constant' */
  const real_T Constant1;              /* '<S1>/Constant1' */
  const real_T Cos5;                   /* '<S36>/Cos5' */
  const real_T Sin5;                   /* '<S36>/Sin5' */
  const real_T Cos5_g;                 /* '<S59>/Cos5' */
  const real_T Sin5_m;                 /* '<S59>/Sin5' */
  const real_T Cos5_i;                 /* '<S82>/Cos5' */
  const real_T Sin5_e;                 /* '<S82>/Sin5' */
  const real_T Cos5_b;                 /* '<S105>/Cos5' */
  const real_T Sin5_c;                 /* '<S105>/Sin5' */
  const real_T UnaryMinus;             /* '<S115>/Unary Minus' */
  const real_T UnaryMinus1;            /* '<S115>/Unary Minus1' */
  const real_T UnaryMinus_p;           /* '<S127>/Unary Minus' */
  const real_T UnaryMinus1_c;          /* '<S127>/Unary Minus1' */
  const real_T Atan2;                  /* '<S116>/Atan2' */
  const real_T FL_Tangent_Angle;       /* '<S116>/Add' */
  const real_T Atan1;                  /* '<S116>/Atan1' */
  const real_T FR_Tangent_Angle;       /* '<S116>/Add1' */
  const real_T Atan3;                  /* '<S116>/Atan3' */
  const real_T BL_Tangent_Angle;       /* '<S116>/Add2' */
  const real_T Atan4;                  /* '<S116>/Atan4' */
  const real_T BR_Tangent_Angle;       /* '<S116>/Add3' */
} ConstB_Code_Gen_Model_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: Steering_Mod_Str_Rel_out
   * Referenced by: '<S169>/Modulation_Str_X_Rel'
   */
  real_T Modulation_Str_X_Rel_tableData[21];

  /* Expression: Steering_Mod_Str_Rel_in
   * Referenced by: '<S169>/Modulation_Str_X_Rel'
   */
  real_T Modulation_Str_X_Rel_bp01Data[21];

  /* Pooled Parameter (Expression: Steering_Mod_Drv_out)
   * Referenced by:
   *   '<S170>/Modulation_Drv_X'
   *   '<S170>/Modulation_Drv_Y'
   */
  real_T pooled9[21];

  /* Pooled Parameter (Expression: Steering_Mod_Drv_in)
   * Referenced by:
   *   '<S170>/Modulation_Drv_X'
   *   '<S170>/Modulation_Drv_Y'
   */
  real_T pooled10[21];

  /* Expression: Rotation_Local_Inv
   * Referenced by: '<S4>/Constant4'
   */
  real_T Constant4_Value[16];

  /* Pooled Parameter (Expression: Drive_Motor_Control_Scale_Factor)
   * Referenced by:
   *   '<S28>/1-D Lookup Table'
   *   '<S51>/1-D Lookup Table'
   *   '<S74>/1-D Lookup Table'
   *   '<S97>/1-D Lookup Table'
   */
  real_T pooled24[2];

  /* Pooled Parameter (Expression: Drive_Motor_Control_Module_Angle_Error)
   * Referenced by:
   *   '<S28>/1-D Lookup Table'
   *   '<S51>/1-D Lookup Table'
   *   '<S74>/1-D Lookup Table'
   *   '<S97>/1-D Lookup Table'
   */
  real_T pooled25[2];
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

/* Model entry point functions */
extern void Code_Gen_Model_initialize(void);
extern void Code_Gen_Model_step(void);
extern void Code_Gen_Model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Code_Gen_Model_T *const Code_Gen_Model_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Propagation' : Unused code path elimination
 * Block '<S23>/Scope' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Propagation' : Unused code path elimination
 * Block '<S26>/Scope' : Unused code path elimination
 * Block '<S28>/Scope' : Unused code path elimination
 * Block '<S55>/Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/Data Type Propagation' : Unused code path elimination
 * Block '<S46>/Scope' : Unused code path elimination
 * Block '<S66>/Data Type Duplicate' : Unused code path elimination
 * Block '<S66>/Data Type Propagation' : Unused code path elimination
 * Block '<S49>/Scope' : Unused code path elimination
 * Block '<S51>/Scope' : Unused code path elimination
 * Block '<S78>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Data Type Propagation' : Unused code path elimination
 * Block '<S69>/Scope' : Unused code path elimination
 * Block '<S89>/Data Type Duplicate' : Unused code path elimination
 * Block '<S89>/Data Type Propagation' : Unused code path elimination
 * Block '<S72>/Scope' : Unused code path elimination
 * Block '<S74>/Scope' : Unused code path elimination
 * Block '<S101>/Data Type Duplicate' : Unused code path elimination
 * Block '<S101>/Data Type Propagation' : Unused code path elimination
 * Block '<S92>/Scope' : Unused code path elimination
 * Block '<S112>/Data Type Duplicate' : Unused code path elimination
 * Block '<S112>/Data Type Propagation' : Unused code path elimination
 * Block '<S95>/Scope' : Unused code path elimination
 * Block '<S97>/Scope' : Unused code path elimination
 * Block '<S125>/Data Type Duplicate' : Unused code path elimination
 * Block '<S125>/Data Type Propagation' : Unused code path elimination
 * Block '<S126>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S134>/Data Type Duplicate' : Unused code path elimination
 * Block '<S134>/Data Type Propagation' : Unused code path elimination
 * Block '<S135>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S141>/Data Type Duplicate' : Unused code path elimination
 * Block '<S141>/Data Type Propagation' : Unused code path elimination
 * Block '<S137>/Scope' : Unused code path elimination
 * Block '<S185>/Data Type Duplicate' : Unused code path elimination
 * Block '<S185>/Data Type Propagation' : Unused code path elimination
 * Block '<S186>/FixPt Data Type Duplicate1' : Unused code path elimination
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
 * '<S23>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID'
 * '<S24>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Make_Turning_Encoder_Value'
 * '<S25>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize'
 * '<S26>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/PID with Angle Modulus'
 * '<S27>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Reduce Speed before Direction Change'
 * '<S28>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Reduce Speed when Turning'
 * '<S29>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Tangential_Velocity_To_RPM'
 * '<S30>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID/Difference'
 * '<S31>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S32>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S33>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Make_Turning_Encoder_Value/Angle Modulus'
 * '<S34>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/Compare To Constant'
 * '<S35>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1'
 * '<S36>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy'
 * '<S37>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy'
 * '<S38>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S39>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy/Compare To Constant'
 * '<S40>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/PID with Angle Modulus/Angle Modulus'
 * '<S41>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/PID with Angle Modulus/Difference'
 * '<S42>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/PID with Angle Modulus/Low_Pass_Filter'
 * '<S43>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/PID with Angle Modulus/Saturation Dynamic'
 * '<S44>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Reduce Speed before Direction Change/Compare To Constant'
 * '<S45>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Reduce Speed when Turning/Angle Modulus to plus or minus pi over two'
 * '<S46>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID'
 * '<S47>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Make_Turning_Encoder_Value'
 * '<S48>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize'
 * '<S49>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/PID with Angle Modulus'
 * '<S50>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Reduce Speed before Direction Change'
 * '<S51>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Reduce Speed when Turning'
 * '<S52>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Tangential_Velocity_To_RPM'
 * '<S53>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID/Difference'
 * '<S54>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S55>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S56>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Make_Turning_Encoder_Value/Angle Modulus'
 * '<S57>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/Compare To Constant'
 * '<S58>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1'
 * '<S59>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy'
 * '<S60>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy'
 * '<S61>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S62>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy/Compare To Constant'
 * '<S63>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/PID with Angle Modulus/Angle Modulus'
 * '<S64>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/PID with Angle Modulus/Difference'
 * '<S65>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/PID with Angle Modulus/Low_Pass_Filter'
 * '<S66>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/PID with Angle Modulus/Saturation Dynamic'
 * '<S67>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Reduce Speed before Direction Change/Compare To Constant'
 * '<S68>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Reduce Speed when Turning/Angle Modulus to plus or minus pi over two'
 * '<S69>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID'
 * '<S70>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Make_Turning_Encoder_Value'
 * '<S71>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize'
 * '<S72>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/PID with Angle Modulus'
 * '<S73>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Reduce Speed before Direction Change'
 * '<S74>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Reduce Speed when Turning'
 * '<S75>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Tangential_Velocity_To_RPM'
 * '<S76>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID/Difference'
 * '<S77>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S78>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S79>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Make_Turning_Encoder_Value/Angle Modulus'
 * '<S80>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/Compare To Constant'
 * '<S81>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1'
 * '<S82>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy'
 * '<S83>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy'
 * '<S84>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S85>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy/Compare To Constant'
 * '<S86>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/PID with Angle Modulus/Angle Modulus'
 * '<S87>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/PID with Angle Modulus/Difference'
 * '<S88>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/PID with Angle Modulus/Low_Pass_Filter'
 * '<S89>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/PID with Angle Modulus/Saturation Dynamic'
 * '<S90>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Reduce Speed before Direction Change/Compare To Constant'
 * '<S91>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Reduce Speed when Turning/Angle Modulus to plus or minus pi over two'
 * '<S92>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID'
 * '<S93>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Make_Turning_Encoder_Value'
 * '<S94>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize'
 * '<S95>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/PID with Angle Modulus'
 * '<S96>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Reduce Speed before Direction Change'
 * '<S97>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Reduce Speed when Turning'
 * '<S98>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Tangential_Velocity_To_RPM'
 * '<S99>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID/Difference'
 * '<S100>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S101>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S102>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Make_Turning_Encoder_Value/Angle Modulus'
 * '<S103>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/Compare To Constant'
 * '<S104>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1'
 * '<S105>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy'
 * '<S106>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy'
 * '<S107>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S108>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy/Compare To Constant'
 * '<S109>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/PID with Angle Modulus/Angle Modulus'
 * '<S110>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/PID with Angle Modulus/Difference'
 * '<S111>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/PID with Angle Modulus/Low_Pass_Filter'
 * '<S112>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/PID with Angle Modulus/Saturation Dynamic'
 * '<S113>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Reduce Speed before Direction Change/Compare To Constant'
 * '<S114>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Reduce Speed when Turning/Angle Modulus to plus or minus pi over two'
 * '<S115>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit'
 * '<S116>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function'
 * '<S117>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command'
 * '<S118>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command'
 * '<S119>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator'
 * '<S120>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero'
 * '<S121>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero1'
 * '<S122>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero2'
 * '<S123>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero3'
 * '<S124>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter'
 * '<S125>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S126>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S127>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit'
 * '<S128>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID'
 * '<S129>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero'
 * '<S130>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero1'
 * '<S131>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero2'
 * '<S132>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero3'
 * '<S133>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter'
 * '<S134>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S135>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S136>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Compare To Constant'
 * '<S137>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping'
 * '<S138>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Angle Modulus'
 * '<S139>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Difference'
 * '<S140>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Low_Pass_Filter'
 * '<S141>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Saturation Dynamic'
 * '<S142>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command/Angle Modulus'
 * '<S143>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add'
 * '<S144>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1'
 * '<S145>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2'
 * '<S146>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3'
 * '<S147>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver'
 * '<S148>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Cartesian to Polar'
 * '<S149>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian'
 * '<S150>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian1'
 * '<S151>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver/Compare To Zero1'
 * '<S152>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver'
 * '<S153>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Cartesian to Polar'
 * '<S154>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian'
 * '<S155>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian1'
 * '<S156>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver/Compare To Zero1'
 * '<S157>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver'
 * '<S158>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Cartesian to Polar'
 * '<S159>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian'
 * '<S160>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian1'
 * '<S161>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver/Compare To Zero1'
 * '<S162>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver'
 * '<S163>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Cartesian to Polar'
 * '<S164>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian'
 * '<S165>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian1'
 * '<S166>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver/Compare To Zero1'
 * '<S167>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive'
 * '<S168>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Degrees to Radians'
 * '<S169>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering'
 * '<S170>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation'
 * '<S171>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Circular Deadband'
 * '<S172>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment'
 * '<S173>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Latch Outputs when Both Inputs Zero'
 * '<S174>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero'
 * '<S175>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero1'
 * '<S176>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero2'
 * '<S177>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero3'
 * '<S178>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero4'
 * '<S179>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Latch Outputs when Both Inputs Zero/Compare To Zero'
 * '<S180>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Latch Outputs when Both Inputs Zero/Compare To Zero1'
 * '<S181>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit'
 * '<S182>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero'
 * '<S183>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit'
 * '<S184>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter'
 * '<S185>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S186>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S187>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero'
 * '<S188>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero1'
 */
#endif                                 /* RTW_HEADER_Code_Gen_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
