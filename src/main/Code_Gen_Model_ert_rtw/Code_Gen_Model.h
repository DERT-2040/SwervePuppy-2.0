/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * File: Code_Gen_Model.h
 *
 * Code generated for Simulink model 'Code_Gen_Model'.
 *
 * Model version                  : 2.34
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Thu Jan  4 21:06:24 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
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
#include "rtGetInf.h"
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
  real_T FL_Steer_Module_Angle;        /* '<S140>/Add1' */
  real_T FR_Steer_Module_Angle;        /* '<S141>/Add1' */
  real_T BL_Steer_Module_Angle;        /* '<S142>/Add1' */
  real_T BR_Steer_Module_Angle;        /* '<S143>/Add1' */
  real_T Product6[2];                  /* '<S8>/Product6' */
  real_T KF_Position_X;                /* '<S6>/Signal Copy' */
  real_T KF_Position_Y;                /* '<S6>/Signal Copy1' */
  real_T Spline_Num_Poses;             /* '<S7>/Merge9' */
  real_T Steering_Abs_Cmd;             /* '<S7>/Merge1' */
  real_T Steering_Rel_Cmd;             /* '<S7>/Merge2' */
  real_T Translation_Speed;            /* '<S7>/Merge4' */
  real_T Translation_Angle;            /* '<S7>/Merge3' */
  real_T Translation_Speed_SPF;        /* '<S9>/Merge2' */
  real_T Translation_Speed_RL;         /* '<S242>/Sum' */
  real_T Translation_Angle_SPF;        /* '<S9>/Merge3' */
  real_T Translation_Steering_Cmd;     /* '<S236>/Switch' */
  real_T Steering_Rel_Cmd_SPF;         /* '<S9>/Merge1' */
  real_T Steering_Abs_Cmd_SPF;         /* '<S9>/Merge' */
  real_T Gyro_Angle_Adjustment_SPF;    /* '<S9>/Merge6' */
  real_T Steering_Localized_PID;       /* '<S255>/Saturation2' */
  real_T Steering_Localized_Cmd;       /* '<S251>/Sum' */
  real_T Switch1;                      /* '<S281>/Switch1' */
  real_T Switch1_m;                    /* '<S266>/Switch1' */
  real_T Switch1_o;                    /* '<S271>/Switch1' */
  real_T Switch1_p;                    /* '<S276>/Switch1' */
  real_T BR_Desired_Wheel_Speed;       /* '<S261>/Product3' */
  real_T BR_Desired_Module_Angle;      /* '<S281>/Switch' */
  real_T FL_Desired_Wheel_Speed;       /* '<S261>/Product' */
  real_T FL_Desired_Module_Angle;      /* '<S266>/Switch' */
  real_T FR_Desired_Wheel_Speed;       /* '<S261>/Product1' */
  real_T FR_Desired_Module_Angle;      /* '<S271>/Switch' */
  real_T BL_Desired_Wheel_Speed;       /* '<S261>/Product2' */
  real_T BL_Desired_Module_Angle;      /* '<S276>/Switch' */
  real_T Odom_Position_X;              /* '<S8>/Accumulator2' */
  real_T Odometry_X_global_est_ft;     /* '<S77>/meters to feet' */
  real_T Odometry_X_global_TEAR_ft;    /* '<S77>/Subtract' */
  real_T Odom_Position_Y;              /* '<S8>/Accumulator' */
  real_T Odometry_Y_global_est_ft;     /* '<S77>/meters to feet1' */
  real_T Odometry_Y_global_TEAR_ft;    /* '<S77>/Subtract1' */
  real_T Spline_Index;                 /* '<S85>/Merge4' */
  real_T Spline_Target_Y;              /* '<S82>/Selector6' */
  real_T Spline_Target_X;              /* '<S82>/Selector2' */
  real_T Assignment[450];              /* '<S107>/Assignment' */
  real_T Product2[2];                  /* '<S67>/Product2' */
  real_T Product3[2];                  /* '<S65>/Product3' */
  uint16_T WhileIterator;              /* '<S132>/While Iterator' */
  boolean_T Spline_Enable;             /* '<S7>/Merge7' */
  boolean_T Is_Absolute_Translation_SPF;/* '<S9>/Merge4' */
  boolean_T Is_Absolute_Steering_SPF;  /* '<S9>/Merge5' */
  boolean_T Robot_Reached_Destination; /* '<S9>/Merge7' */
  boolean_T Spline_Out_Of_Bounds;      /* '<S85>/Merge1' */
} B_Code_Gen_Model_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S69>/UD' */
  real_T UD_DSTATE_m;                  /* '<S70>/UD' */
  real_T UD_DSTATE_i;                  /* '<S71>/UD' */
  real_T UD_DSTATE_c;                  /* '<S72>/UD' */
  real_T TappedDelay_X[6];             /* '<S6>/Tapped Delay' */
  real_T TappedDelay1_X[6];            /* '<S6>/Tapped Delay1' */
  real_T MemoryX_DSTATE[2];            /* '<S14>/MemoryX' */
  real_T UD_DSTATE_d;                  /* '<S68>/UD' */
  real_T UnitDelay1_DSTATE;            /* '<S258>/Unit Delay1' */
  real_T UD_DSTATE_a;                  /* '<S257>/UD' */
  real_T UnitDelay_DSTATE_m;           /* '<S255>/Unit Delay' */
  real_T UnitDelay1_DSTATE_k;          /* '<S220>/Unit Delay1' */
  real_T UD_DSTATE_cs;                 /* '<S219>/UD' */
  real_T UnitDelay_DSTATE_a;           /* '<S213>/Unit Delay' */
  real_T UnitDelay1_DSTATE_i;          /* '<S231>/Unit Delay1' */
  real_T UD_DSTATE_l;                  /* '<S230>/UD' */
  real_T UnitDelay_DSTATE_l;           /* '<S216>/Unit Delay' */
  real_T UnitDelay1_DSTATE_a;          /* '<S157>/Unit Delay1' */
  real_T UD_DSTATE_o;                  /* '<S156>/UD' */
  real_T UnitDelay_DSTATE_f;           /* '<S150>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b;          /* '<S168>/Unit Delay1' */
  real_T UD_DSTATE_b;                  /* '<S167>/UD' */
  real_T UnitDelay_DSTATE_e;           /* '<S153>/Unit Delay' */
  real_T UnitDelay1_DSTATE_b1;         /* '<S178>/Unit Delay1' */
  real_T UD_DSTATE_e;                  /* '<S177>/UD' */
  real_T UnitDelay_DSTATE_em;          /* '<S171>/Unit Delay' */
  real_T UnitDelay1_DSTATE_n;          /* '<S189>/Unit Delay1' */
  real_T UD_DSTATE_i1;                 /* '<S188>/UD' */
  real_T UnitDelay_DSTATE_dt;          /* '<S174>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S199>/Unit Delay1' */
  real_T UD_DSTATE_lh;                 /* '<S198>/UD' */
  real_T UnitDelay_DSTATE_gp;          /* '<S192>/Unit Delay' */
  real_T UnitDelay1_DSTATE_nw;         /* '<S210>/Unit Delay1' */
  real_T UD_DSTATE_k;                  /* '<S209>/UD' */
  real_T UnitDelay_DSTATE_k;           /* '<S195>/Unit Delay' */
  real_T Accumulator2_DSTATE;          /* '<S8>/Accumulator2' */
  real_T UnitDelay_DSTATE_c;           /* '<S77>/Unit Delay' */
  real_T Accumulator_DSTATE;           /* '<S8>/Accumulator' */
  real_T UnitDelay1_DSTATE_d;          /* '<S77>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_d2;         /* '<S291>/Unit Delay1' */
  real_T UnitDelay_DSTATE_g4;          /* '<S291>/Unit Delay' */
  real_T UnitDelay_DSTATE_h;           /* '<S290>/Unit Delay' */
  real_T UnitDelay1_DSTATE_kr;         /* '<S290>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_l;          /* '<S300>/Unit Delay1' */
  real_T UnitDelay_DSTATE_p;           /* '<S300>/Unit Delay' */
  real_T FixPtUnitDelay1_DSTATE_f;     /* '<S304>/FixPt Unit Delay1' */
  real_T UnitDelay_DSTATE_l1;          /* '<S2>/Unit Delay' */
  real_T UnitDelay_DSTATE_gh;          /* '<S81>/Unit Delay' */
  real_T UnitDelay_DSTATE_hn;          /* '<S80>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f4;         /* '<S133>/Unit Delay1' */
  real_T UnitDelay_DSTATE_g4g;         /* '<S133>/Unit Delay' */
  real_T UnitDelay_DSTATE_le;          /* '<S83>/Unit Delay' */
  real_T UnitDelay1_DSTATE_kc;         /* '<S83>/Unit Delay1' */
  int32_T Selector4_DIMS1[2];          /* '<S102>/Selector4' */
  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S244>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_c;    /* '<S253>/FixPt Unit Delay2' */
  uint8_T FixPtUnitDelay2_DSTATE_a;    /* '<S304>/FixPt Unit Delay2' */
  boolean_T UnitDelay_DSTATE_ll;       /* '<S5>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_e4;       /* '<S88>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_n;        /* '<S93>/Unit Delay' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<S1>/Switch Case' */
  int8_T If_ActiveSubsystem;           /* '<S9>/If' */
  int8_T Accumulator2_PrevResetState;  /* '<S8>/Accumulator2' */
  int8_T Accumulator_PrevResetState;   /* '<S8>/Accumulator' */
  int8_T If_ActiveSubsystem_h;         /* '<S85>/If' */
  int8_T If_ActiveSubsystem_o;         /* '<S88>/If' */
  int8_T If_ActiveSubsystem_d;         /* '<S90>/If' */
  boolean_T icLoad;                    /* '<S14>/MemoryX' */
  boolean_T EnabledSubsystem_MODE;     /* '<S41>/Enabled Subsystem' */
  boolean_T MeasurementUpdate_MODE;    /* '<S34>/MeasurementUpdate' */
} DW_Code_Gen_Model_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Cos5;                   /* '<S161>/Cos5' */
  const real_T Sin5;                   /* '<S161>/Sin5' */
  const real_T Cos5_g;                 /* '<S182>/Cos5' */
  const real_T Sin5_m;                 /* '<S182>/Sin5' */
  const real_T Cos5_i;                 /* '<S203>/Cos5' */
  const real_T Sin5_e;                 /* '<S203>/Sin5' */
  const real_T Cos5_b;                 /* '<S224>/Cos5' */
  const real_T Sin5_c;                 /* '<S224>/Sin5' */
  const real_T Atan1;                  /* '<S234>/Atan1' */
  const real_T FR_Tangent_Angle;       /* '<S234>/Add1' */
  const real_T Atan3;                  /* '<S234>/Atan3' */
  const real_T BL_Tangent_Angle;       /* '<S234>/Add2' */
  const real_T Atan4;                  /* '<S234>/Atan4' */
  const real_T BR_Tangent_Angle;       /* '<S234>/Add3' */
} ConstB_Code_Gen_Model_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: Spline_Capture_Radius
   * Referenced by: '<S80>/Capture Radius'
   */
  real_T CaptureRadius_tableData[4];

  /* Pooled Parameter (Expression: Spline_Velocity_Axis)
   * Referenced by:
   *   '<S80>/Capture Radius'
   *   '<S80>/Lookahead Distance'
   */
  real_T pooled9[4];

  /* Expression: Spline_Lookahead_Dist
   * Referenced by: '<S80>/Lookahead Distance'
   */
  real_T LookaheadDistance_tableData[4];

  /* Expression: Spline_Ref_Poses_auto
   * Referenced by: '<S2>/Constant4'
   */
  real_T Constant4_Value[76];

  /* Expression: Steering_Mod_Str_Rel_out
   * Referenced by: '<S287>/Modulation_Str_Y_Rel'
   */
  real_T Modulation_Str_Y_Rel_tableData[21];

  /* Expression: Steering_Mod_Str_Rel_in
   * Referenced by: '<S287>/Modulation_Str_Y_Rel'
   */
  real_T Modulation_Str_Y_Rel_bp01Data[21];

  /* Expression: Steering_Mod_Drv_out
   * Referenced by: '<S288>/Modulation_Drv'
   */
  real_T Modulation_Drv_tableData[21];

  /* Expression: Steering_Mod_Drv_in
   * Referenced by: '<S288>/Modulation_Drv'
   */
  real_T Modulation_Drv_bp01Data[21];

  /* Expression: Rotation_Local_Inv
   * Referenced by: '<S8>/Constant4'
   */
  real_T Constant4_Value_d[16];

  /* Pooled Parameter (Expression: Drive_Motor_Control_Scale_Factor)
   * Referenced by:
   *   '<S152>/1-D Lookup Table'
   *   '<S173>/1-D Lookup Table'
   *   '<S194>/1-D Lookup Table'
   *   '<S215>/1-D Lookup Table'
   */
  real_T pooled23[2];

  /* Pooled Parameter (Expression: Drive_Motor_Control_Module_Angle_Error)
   * Referenced by:
   *   '<S152>/1-D Lookup Table'
   *   '<S173>/1-D Lookup Table'
   *   '<S194>/1-D Lookup Table'
   *   '<S215>/1-D Lookup Table'
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
  real_T Photon_Est_Pose_X;            /* '<Root>/Photon_Est_Pose_X' */
  real_T Photon_Est_Pose_Y;            /* '<Root>/Photon_Est_Pose_Y' */
  real_T Photon_Est_Pose_Ambiguity;    /* '<Root>/Photon_Est_Pose_Ambiguity' */
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
extern real_T Autonomous_Desired_X;    /* Variable: Autonomous_Desired_X
                                        * Referenced by: '<S2>/Constant7'
                                        */
extern real_T Autonomous_Desired_Y;    /* Variable: Autonomous_Desired_Y
                                        * Referenced by: '<S2>/Constant8'
                                        */
extern real_T Boost_Trigger_Decreasing_Limit;
                                     /* Variable: Boost_Trigger_Decreasing_Limit
                                      * Referenced by: '<S301>/Constant1'
                                      */
extern real_T Boost_Trigger_High_Speed;/* Variable: Boost_Trigger_High_Speed
                                        * Referenced by:
                                        *   '<S299>/Constant'
                                        *   '<S299>/Saturation'
                                        */
extern real_T Boost_Trigger_Increasing_Limit;
                                     /* Variable: Boost_Trigger_Increasing_Limit
                                      * Referenced by: '<S301>/Constant3'
                                      */
extern real_T Boost_Trigger_Low_Speed; /* Variable: Boost_Trigger_Low_Speed
                                        * Referenced by: '<S299>/Constant1'
                                        */
extern real_T Distance_FL_y;           /* Variable: Distance_FL_y
                                        * Referenced by: '<S234>/Constant4'
                                        */
extern real_T Drive_Motor_Control_D;   /* Variable: Drive_Motor_Control_D
                                        * Referenced by:
                                        *   '<S150>/Constant3'
                                        *   '<S171>/Constant3'
                                        *   '<S192>/Constant3'
                                        *   '<S213>/Constant3'
                                        */
extern real_T Drive_Motor_Control_D_FilterCoeff;
                                  /* Variable: Drive_Motor_Control_D_FilterCoeff
                                   * Referenced by:
                                   *   '<S150>/Constant2'
                                   *   '<S171>/Constant2'
                                   *   '<S192>/Constant2'
                                   *   '<S213>/Constant2'
                                   */
extern real_T Drive_Motor_Control_D_LL;/* Variable: Drive_Motor_Control_D_LL
                                        * Referenced by:
                                        *   '<S150>/Saturation'
                                        *   '<S171>/Saturation'
                                        *   '<S192>/Saturation'
                                        *   '<S213>/Saturation'
                                        */
extern real_T Drive_Motor_Control_D_UL;/* Variable: Drive_Motor_Control_D_UL
                                        * Referenced by:
                                        *   '<S150>/Saturation'
                                        *   '<S171>/Saturation'
                                        *   '<S192>/Saturation'
                                        *   '<S213>/Saturation'
                                        */
extern real_T Drive_Motor_Control_FF;  /* Variable: Drive_Motor_Control_FF
                                        * Referenced by:
                                        *   '<S150>/Gain'
                                        *   '<S171>/Gain'
                                        *   '<S192>/Gain'
                                        *   '<S213>/Gain'
                                        */
extern real_T Drive_Motor_Control_I;   /* Variable: Drive_Motor_Control_I
                                        * Referenced by:
                                        *   '<S150>/Gain2'
                                        *   '<S171>/Gain2'
                                        *   '<S192>/Gain2'
                                        *   '<S213>/Gain2'
                                        */
extern real_T Drive_Motor_Control_I_LL;/* Variable: Drive_Motor_Control_I_LL
                                        * Referenced by:
                                        *   '<S150>/Saturation1'
                                        *   '<S171>/Saturation1'
                                        *   '<S192>/Saturation1'
                                        *   '<S213>/Saturation1'
                                        */
extern real_T Drive_Motor_Control_I_UL;/* Variable: Drive_Motor_Control_I_UL
                                        * Referenced by:
                                        *   '<S150>/Saturation1'
                                        *   '<S171>/Saturation1'
                                        *   '<S192>/Saturation1'
                                        *   '<S213>/Saturation1'
                                        */
extern real_T Drive_Motor_Control_P;   /* Variable: Drive_Motor_Control_P
                                        * Referenced by:
                                        *   '<S150>/Gain1'
                                        *   '<S171>/Gain1'
                                        *   '<S192>/Gain1'
                                        *   '<S213>/Gain1'
                                        */
extern real_T Drive_Motor_Control_Sign_Change_Deadband;
                           /* Variable: Drive_Motor_Control_Sign_Change_Deadband
                            * Referenced by:
                            *   '<S155>/Constant'
                            *   '<S176>/Constant'
                            *   '<S197>/Constant'
                            *   '<S218>/Constant'
                            */
extern real_T KF_Vision_Ambiguity_Thresh;/* Variable: KF_Vision_Ambiguity_Thresh
                                          * Referenced by: '<S6>/Constant'
                                          */
extern real_T Odometry_IC_X;           /* Variable: Odometry_IC_X
                                        * Referenced by: '<S1>/Constant'
                                        */
extern real_T Odometry_IC_Y;           /* Variable: Odometry_IC_Y
                                        * Referenced by: '<S1>/Constant1'
                                        */
extern real_T Odometry_Reset_IC;       /* Variable: Odometry_Reset_IC
                                        * Referenced by: '<S8>/Constant'
                                        */
extern real_T Odometry_X_Y_TEAR;       /* Variable: Odometry_X_Y_TEAR
                                        * Referenced by: '<S77>/Constant'
                                        */
extern real_T Spline_Last_Pose_Distance_to_Velocity_Gain;
                         /* Variable: Spline_Last_Pose_Distance_to_Velocity_Gain
                          * Referenced by: '<S135>/Constant2'
                          */
extern real_T Spline_Max_Centripital_Acceleration;
                                /* Variable: Spline_Max_Centripital_Acceleration
                                 * Referenced by: '<S135>/Constant1'
                                 */
extern real_T Spline_Pose_Num_Before_End_Reduce_Speed;
                            /* Variable: Spline_Pose_Num_Before_End_Reduce_Speed
                             * Referenced by: '<S82>/Constant'
                             */
extern real_T Spline_Stop_Radius;      /* Variable: Spline_Stop_Radius
                                        * Referenced by: '<S95>/Constant'
                                        */
extern real_T Spline_Velocity_Multiplier_TEST;
                                    /* Variable: Spline_Velocity_Multiplier_TEST
                                     * Referenced by: '<S135>/Constant3'
                                     */
extern real_T Steering_Abs_Deadband_Range;/* Variable: Steering_Abs_Deadband_Range
                                           * Referenced by: '<S289>/Constant2'
                                           */
extern real_T Steering_Heading_Control_D;/* Variable: Steering_Heading_Control_D
                                          * Referenced by: '<S255>/Constant3'
                                          */
extern real_T Steering_Heading_Control_D_FilterCoeff;
                             /* Variable: Steering_Heading_Control_D_FilterCoeff
                              * Referenced by: '<S255>/Constant2'
                              */
extern real_T Steering_Heading_Control_D_LL;
                                      /* Variable: Steering_Heading_Control_D_LL
                                       * Referenced by: '<S255>/Saturation'
                                       */
extern real_T Steering_Heading_Control_D_UL;
                                      /* Variable: Steering_Heading_Control_D_UL
                                       * Referenced by: '<S255>/Saturation'
                                       */
extern real_T Steering_Heading_Control_Deadzone;
                                  /* Variable: Steering_Heading_Control_Deadzone
                                   * Referenced by: '<S254>/Constant'
                                   */
extern real_T Steering_Heading_Control_I;/* Variable: Steering_Heading_Control_I
                                          * Referenced by: '<S255>/Gain2'
                                          */
extern real_T Steering_Heading_Control_I_LL;
                                      /* Variable: Steering_Heading_Control_I_LL
                                       * Referenced by: '<S255>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_I_UL;
                                      /* Variable: Steering_Heading_Control_I_UL
                                       * Referenced by: '<S255>/Saturation1'
                                       */
extern real_T Steering_Heading_Control_P;/* Variable: Steering_Heading_Control_P
                                          * Referenced by: '<S255>/Gain1'
                                          */
extern real_T Steering_Heading_Control_Total_LL;
                                  /* Variable: Steering_Heading_Control_Total_LL
                                   * Referenced by:
                                   *   '<S255>/Constant1'
                                   *   '<S255>/Saturation2'
                                   */
extern real_T Steering_Heading_Control_Total_UL;
                                  /* Variable: Steering_Heading_Control_Total_UL
                                   * Referenced by:
                                   *   '<S255>/Constant'
                                   *   '<S255>/Saturation2'
                                   */
extern real_T Steering_Localized_Cmd_Approach_Zero_Error_Thresh;
                  /* Variable: Steering_Localized_Cmd_Approach_Zero_Error_Thresh
                   * Referenced by: '<S245>/Constant5'
                   */
extern real_T Steering_Localized_Cmd_Approach_Zero_Final_Thresh;
                  /* Variable: Steering_Localized_Cmd_Approach_Zero_Final_Thresh
                   * Referenced by: '<S245>/Constant6'
                   */
extern real_T Steering_Localized_Cmd_NonZero_Error_Thresh;
                        /* Variable: Steering_Localized_Cmd_NonZero_Error_Thresh
                         * Referenced by: '<S245>/Constant9'
                         */
extern real_T Steering_Localized_Cmd_NonZero_Final_Scale_Factor;
                  /* Variable: Steering_Localized_Cmd_NonZero_Final_Scale_Factor
                   * Referenced by: '<S245>/Constant10'
                   */
extern real_T Steering_Localized_Cmd_Rate_Limit_Dec;
                              /* Variable: Steering_Localized_Cmd_Rate_Limit_Dec
                               * Referenced by: '<S245>/Constant1'
                               */
extern real_T Steering_Localized_Cmd_Rate_Limit_Inc;
                              /* Variable: Steering_Localized_Cmd_Rate_Limit_Inc
                               * Referenced by: '<S245>/Constant3'
                               */
extern real_T Steering_Motor_Control_D;/* Variable: Steering_Motor_Control_D
                                        * Referenced by:
                                        *   '<S153>/Constant3'
                                        *   '<S174>/Constant3'
                                        *   '<S195>/Constant3'
                                        *   '<S216>/Constant3'
                                        */
extern real_T Steering_Motor_Control_D_FilterCoeff;
                               /* Variable: Steering_Motor_Control_D_FilterCoeff
                                * Referenced by:
                                *   '<S153>/Constant2'
                                *   '<S174>/Constant2'
                                *   '<S195>/Constant2'
                                *   '<S216>/Constant2'
                                */
extern real_T Steering_Motor_Control_D_LL;/* Variable: Steering_Motor_Control_D_LL
                                           * Referenced by:
                                           *   '<S153>/Saturation'
                                           *   '<S174>/Saturation'
                                           *   '<S195>/Saturation'
                                           *   '<S216>/Saturation'
                                           */
extern real_T Steering_Motor_Control_D_UL;/* Variable: Steering_Motor_Control_D_UL
                                           * Referenced by:
                                           *   '<S153>/Saturation'
                                           *   '<S174>/Saturation'
                                           *   '<S195>/Saturation'
                                           *   '<S216>/Saturation'
                                           */
extern real_T Steering_Motor_Control_I;/* Variable: Steering_Motor_Control_I
                                        * Referenced by:
                                        *   '<S153>/Gain2'
                                        *   '<S174>/Gain2'
                                        *   '<S195>/Gain2'
                                        *   '<S216>/Gain2'
                                        */
extern real_T Steering_Motor_Control_I_LL;/* Variable: Steering_Motor_Control_I_LL
                                           * Referenced by:
                                           *   '<S153>/Saturation1'
                                           *   '<S174>/Saturation1'
                                           *   '<S195>/Saturation1'
                                           *   '<S216>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_I_UL;/* Variable: Steering_Motor_Control_I_UL
                                           * Referenced by:
                                           *   '<S153>/Saturation1'
                                           *   '<S174>/Saturation1'
                                           *   '<S195>/Saturation1'
                                           *   '<S216>/Saturation1'
                                           */
extern real_T Steering_Motor_Control_P;/* Variable: Steering_Motor_Control_P
                                        * Referenced by:
                                        *   '<S153>/Gain1'
                                        *   '<S174>/Gain1'
                                        *   '<S195>/Gain1'
                                        *   '<S216>/Gain1'
                                        */
extern real_T Steering_Relative_Gain;  /* Variable: Steering_Relative_Gain
                                        * Referenced by: '<S287>/Constant'
                                        */
extern real_T Translation_Speed_Approach_Zero_Error_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Error_Thresh
                        * Referenced by: '<S233>/Constant5'
                        */
extern real_T Translation_Speed_Approach_Zero_Final_Thresh;
                       /* Variable: Translation_Speed_Approach_Zero_Final_Thresh
                        * Referenced by: '<S233>/Constant6'
                        */
extern real_T Translation_Speed_NonZero_Error_Thresh;
                             /* Variable: Translation_Speed_NonZero_Error_Thresh
                              * Referenced by: '<S233>/Constant9'
                              */
extern real_T Translation_Speed_NonZero_Final_Scale_Factor;
                       /* Variable: Translation_Speed_NonZero_Final_Scale_Factor
                        * Referenced by: '<S233>/Constant10'
                        */
extern real_T Translation_Speed_Rate_Limit_Dec;
                                   /* Variable: Translation_Speed_Rate_Limit_Dec
                                    * Referenced by: '<S233>/Constant1'
                                    */
extern real_T Translation_Speed_Rate_Limit_Inc;
                                   /* Variable: Translation_Speed_Rate_Limit_Inc
                                    * Referenced by: '<S233>/Constant3'
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
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Conversion' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S60>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S19>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Conversion' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/G' : Unused code path elimination
 * Block '<S14>/H' : Unused code path elimination
 * Block '<S14>/N' : Unused code path elimination
 * Block '<S14>/P0' : Unused code path elimination
 * Block '<S14>/Q' : Unused code path elimination
 * Block '<S14>/R' : Unused code path elimination
 * Block '<S46>/CheckSignalProperties' : Unused code path elimination
 * Block '<S55>/CheckSignalProperties' : Unused code path elimination
 * Block '<S56>/CheckSignalProperties' : Unused code path elimination
 * Block '<S8>/To Workspace2' : Unused code path elimination
 * Block '<S8>/To Workspace3' : Unused code path elimination
 * Block '<S9>/Gain' : Unused code path elimination
 * Block '<S9>/Gain1' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<S94>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S98>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S104>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S138>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S82>/To Workspace' : Unused code path elimination
 * Block '<S82>/To Workspace1' : Unused code path elimination
 * Block '<S158>/Data Type Duplicate' : Unused code path elimination
 * Block '<S158>/Data Type Propagation' : Unused code path elimination
 * Block '<S150>/Scope' : Unused code path elimination
 * Block '<S152>/Scope' : Unused code path elimination
 * Block '<S169>/Data Type Duplicate' : Unused code path elimination
 * Block '<S169>/Data Type Propagation' : Unused code path elimination
 * Block '<S153>/Scope' : Unused code path elimination
 * Block '<S179>/Data Type Duplicate' : Unused code path elimination
 * Block '<S179>/Data Type Propagation' : Unused code path elimination
 * Block '<S171>/Scope' : Unused code path elimination
 * Block '<S173>/Scope' : Unused code path elimination
 * Block '<S190>/Data Type Duplicate' : Unused code path elimination
 * Block '<S190>/Data Type Propagation' : Unused code path elimination
 * Block '<S174>/Scope' : Unused code path elimination
 * Block '<S200>/Data Type Duplicate' : Unused code path elimination
 * Block '<S200>/Data Type Propagation' : Unused code path elimination
 * Block '<S192>/Scope' : Unused code path elimination
 * Block '<S194>/Scope' : Unused code path elimination
 * Block '<S211>/Data Type Duplicate' : Unused code path elimination
 * Block '<S211>/Data Type Propagation' : Unused code path elimination
 * Block '<S195>/Scope' : Unused code path elimination
 * Block '<S221>/Data Type Duplicate' : Unused code path elimination
 * Block '<S221>/Data Type Propagation' : Unused code path elimination
 * Block '<S213>/Scope' : Unused code path elimination
 * Block '<S215>/Scope' : Unused code path elimination
 * Block '<S232>/Data Type Duplicate' : Unused code path elimination
 * Block '<S232>/Data Type Propagation' : Unused code path elimination
 * Block '<S216>/Scope' : Unused code path elimination
 * Block '<S243>/Data Type Duplicate' : Unused code path elimination
 * Block '<S243>/Data Type Propagation' : Unused code path elimination
 * Block '<S244>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S252>/Data Type Duplicate' : Unused code path elimination
 * Block '<S252>/Data Type Propagation' : Unused code path elimination
 * Block '<S253>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S259>/Data Type Duplicate' : Unused code path elimination
 * Block '<S259>/Data Type Propagation' : Unused code path elimination
 * Block '<S255>/Scope' : Unused code path elimination
 * Block '<S303>/Data Type Duplicate' : Unused code path elimination
 * Block '<S303>/Data Type Propagation' : Unused code path elimination
 * Block '<S304>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S57>/Conversion' : Eliminate redundant data type conversion
 * Block '<S58>/Conversion' : Eliminate redundant data type conversion
 * Block '<S60>/Conversion' : Eliminate redundant data type conversion
 * Block '<S14>/DataTypeConversionEnable' : Eliminate redundant data type conversion
 * Block '<S30>/Conversion' : Eliminate redundant data type conversion
 * Block '<S34>/Reshape' : Reshape block reduction
 * Block '<S14>/ReshapeX0' : Reshape block reduction
 * Block '<S14>/Reshapeu' : Reshape block reduction
 * Block '<S14>/Reshapexhat' : Reshape block reduction
 * Block '<S8>/Signal Copy' : Eliminate redundant signal conversion block
 * Block '<S8>/Signal Copy1' : Eliminate redundant signal conversion block
 * Block '<S8>/Signal Copy2' : Eliminate redundant signal conversion block
 * Block '<S8>/Signal Copy3' : Eliminate redundant signal conversion block
 * Block '<S134>/Signal Copy' : Eliminate redundant signal conversion block
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
 * '<S5>'   : 'Code_Gen_Model/RoboRio Controls/Internal Feedback'
 * '<S6>'   : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter'
 * '<S7>'   : 'Code_Gen_Model/RoboRio Controls/Merge'
 * '<S8>'   : 'Code_Gen_Model/RoboRio Controls/Odometry'
 * '<S9>'   : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following'
 * '<S10>'  : 'Code_Gen_Model/RoboRio Controls/Steer_Module_Offset_Adjustments'
 * '<S11>'  : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive'
 * '<S12>'  : 'Code_Gen_Model/RoboRio Controls/Teleop'
 * '<S13>'  : 'Code_Gen_Model/RoboRio Controls/Test'
 * '<S14>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter'
 * '<S15>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/CalculatePL'
 * '<S16>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/CalculateYhat'
 * '<S17>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator'
 * '<S18>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/DataTypeConversionA'
 * '<S19>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/DataTypeConversionB'
 * '<S20>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/DataTypeConversionC'
 * '<S21>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/DataTypeConversionD'
 * '<S22>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/DataTypeConversionG'
 * '<S23>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/DataTypeConversionH'
 * '<S24>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/DataTypeConversionN'
 * '<S25>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/DataTypeConversionP'
 * '<S26>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/DataTypeConversionP0'
 * '<S27>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/DataTypeConversionQ'
 * '<S28>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/DataTypeConversionR'
 * '<S29>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/DataTypeConversionReset'
 * '<S30>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/DataTypeConversionX'
 * '<S31>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/DataTypeConversionX0'
 * '<S32>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/DataTypeConversionu'
 * '<S33>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/MemoryP'
 * '<S34>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/Observer'
 * '<S35>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/ReducedQRN'
 * '<S36>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/Reset'
 * '<S37>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/Reshapeyhat'
 * '<S38>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/ScalarExpansionP0'
 * '<S39>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/ScalarExpansionQ'
 * '<S40>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/ScalarExpansionR'
 * '<S41>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/UseCurrentEstimator'
 * '<S42>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/checkA'
 * '<S43>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/checkB'
 * '<S44>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/checkC'
 * '<S45>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/checkD'
 * '<S46>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/checkEnable'
 * '<S47>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/checkG'
 * '<S48>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/checkH'
 * '<S49>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/checkN'
 * '<S50>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/checkP0'
 * '<S51>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/checkQ'
 * '<S52>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/checkR'
 * '<S53>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/checkReset'
 * '<S54>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/checkX0'
 * '<S55>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/checku'
 * '<S56>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/checky'
 * '<S57>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S58>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S59>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S60>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S61>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/CalculatePL/Ground'
 * '<S62>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/CalculateYhat/Ground'
 * '<S63>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput'
 * '<S64>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
 * '<S65>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/Observer/MeasurementUpdate'
 * '<S66>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/ReducedQRN/Ground'
 * '<S67>'  : 'Code_Gen_Model/RoboRio Controls/Kalman_Filter/Kalman Filter/UseCurrentEstimator/Enabled Subsystem'
 * '<S68>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Difference'
 * '<S69>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Difference1'
 * '<S70>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Difference3'
 * '<S71>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Difference4'
 * '<S72>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Difference5'
 * '<S73>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Polar to Cartesian'
 * '<S74>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Polar to Cartesian1'
 * '<S75>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Polar to Cartesian2'
 * '<S76>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Polar to Cartesian3'
 * '<S77>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Tear for validation testing'
 * '<S78>'  : 'Code_Gen_Model/RoboRio Controls/Odometry/Tear for validation testing/Compare To Zero'
 * '<S79>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Pass Through'
 * '<S80>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled'
 * '<S81>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses'
 * '<S82>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Find_Targets'
 * '<S83>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands'
 * '<S84>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/If Action Subsystem'
 * '<S85>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification'
 * '<S86>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning'
 * '<S87>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Escape_Auto_Driving'
 * '<S88>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid'
 * '<S89>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Catch-all if not the last point and not in the circle'
 * '<S90>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid'
 * '<S91>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check'
 * '<S92>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search'
 * '<S93>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point'
 * '<S94>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Increment_Search/Increment Real World'
 * '<S95>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Compare To Constant'
 * '<S96>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Robot_Is_At_Destination'
 * '<S97>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Circle_Check_Valid/Is_Last_Point/Straight_Line_Path_To_End'
 * '<S98>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Increment Real World'
 * '<S99>'  : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference'
 * '<S100>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant'
 * '<S101>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Index_Modification/Robot_Index_Is_Valid/Increment_If_Rectangle_Check/Subsystem Reference/Compare To Constant1'
 * '<S102>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots'
 * '<S103>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning'
 * '<S104>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Decrement Real World'
 * '<S105>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose'
 * '<S106>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Make_Knots/Find_Control_Pose1'
 * '<S107>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop'
 * '<S108>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Compare To Constant'
 * '<S109>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve'
 * '<S110>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Find_Point_Coefficients'
 * '<S111>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve'
 * '<S112>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc'
 * '<S113>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos'
 * '<S114>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel'
 * '<S115>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature'
 * '<S116>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_U_And_Powers'
 * '<S117>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/Subsystem Reference'
 * '<S118>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddA'
 * '<S119>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddB'
 * '<S120>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Acc/ddC'
 * '<S121>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/A'
 * '<S122>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/B'
 * '<S123>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/C'
 * '<S124>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Pos/Subsystem Reference'
 * '<S125>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/Subsystem Reference'
 * '<S126>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dA'
 * '<S127>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dB'
 * '<S128>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Catmull_Rom_Vel/dC'
 * '<S129>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Autonomously_Navigate_Poses/Make_Knots_and_Path_Planning/Path_Planning/Sampling_Loop/Sample_Catmull_Rom_Pos_And_Curve/Sample_Curve/Find_Curvature/MATLAB Function'
 * '<S130>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Distance Along Curve'
 * '<S131>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find closest index to curve'
 * '<S132>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find first index that meets distance target'
 * '<S133>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading'
 * '<S134>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Heading'
 * '<S135>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Velocity'
 * '<S136>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables'
 * '<S137>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Latch'
 * '<S138>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Find_Targets/Find velocity and heading/Dynamic Lookup Tables/Decrement'
 * '<S139>' : 'Code_Gen_Model/RoboRio Controls/Spline_Path_Following/Spline Path Following Enabled/Steering_and_Drive_Commands/Translation Angle'
 * '<S140>' : 'Code_Gen_Model/RoboRio Controls/Steer_Module_Offset_Adjustments/Angle Modulus'
 * '<S141>' : 'Code_Gen_Model/RoboRio Controls/Steer_Module_Offset_Adjustments/Angle Modulus1'
 * '<S142>' : 'Code_Gen_Model/RoboRio Controls/Steer_Module_Offset_Adjustments/Angle Modulus2'
 * '<S143>' : 'Code_Gen_Model/RoboRio Controls/Steer_Module_Offset_Adjustments/Angle Modulus3'
 * '<S144>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module'
 * '<S145>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1'
 * '<S146>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2'
 * '<S147>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3'
 * '<S148>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle'
 * '<S149>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor'
 * '<S150>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID'
 * '<S151>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize'
 * '<S152>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor'
 * '<S153>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID'
 * '<S154>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Tangential_Velocity_To_RPM'
 * '<S155>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S156>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID/Difference'
 * '<S157>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S158>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S159>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/Compare To Constant'
 * '<S160>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1'
 * '<S161>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy'
 * '<S162>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy'
 * '<S163>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S164>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Optimize/RotateBy/Compare To Constant'
 * '<S165>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S166>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S167>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Difference'
 * '<S168>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S169>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S170>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor'
 * '<S171>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID'
 * '<S172>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize'
 * '<S173>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor'
 * '<S174>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID'
 * '<S175>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Tangential_Velocity_To_RPM'
 * '<S176>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S177>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID/Difference'
 * '<S178>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S179>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S180>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/Compare To Constant'
 * '<S181>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1'
 * '<S182>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy'
 * '<S183>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy'
 * '<S184>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S185>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Optimize/RotateBy/Compare To Constant'
 * '<S186>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S187>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S188>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Difference'
 * '<S189>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S190>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module1/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S191>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor'
 * '<S192>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID'
 * '<S193>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize'
 * '<S194>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor'
 * '<S195>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID'
 * '<S196>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Tangential_Velocity_To_RPM'
 * '<S197>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S198>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID/Difference'
 * '<S199>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S200>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S201>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/Compare To Constant'
 * '<S202>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1'
 * '<S203>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy'
 * '<S204>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy'
 * '<S205>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S206>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Optimize/RotateBy/Compare To Constant'
 * '<S207>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S208>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S209>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Difference'
 * '<S210>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S211>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module2/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S212>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor'
 * '<S213>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID'
 * '<S214>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize'
 * '<S215>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor'
 * '<S216>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID'
 * '<S217>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Tangential_Velocity_To_RPM'
 * '<S218>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Direction Change Drive Reduction Factor/Compare To Constant'
 * '<S219>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID/Difference'
 * '<S220>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID/Low_Pass_Filter'
 * '<S221>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Drive Feed Forward plus PID/Saturation Dynamic'
 * '<S222>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/Compare To Constant'
 * '<S223>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1'
 * '<S224>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy'
 * '<S225>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy'
 * '<S226>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/Minus1/RotateBy/Compare To Constant'
 * '<S227>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Optimize/RotateBy/Compare To Constant'
 * '<S228>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Steering Module Error Drive Reduction Factor/Angle Modulus to plus or minus pi over two'
 * '<S229>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Angle Modulus'
 * '<S230>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Difference'
 * '<S231>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Low_Pass_Filter'
 * '<S232>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Swerve_Drive_Module3/Steering with Angle Error Modulus PID/Saturation Dynamic'
 * '<S233>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit'
 * '<S234>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Initialize Function'
 * '<S235>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command'
 * '<S236>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command'
 * '<S237>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator'
 * '<S238>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero'
 * '<S239>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero1'
 * '<S240>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero2'
 * '<S241>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Compare To Zero3'
 * '<S242>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter'
 * '<S243>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S244>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S245>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit'
 * '<S246>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID'
 * '<S247>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero'
 * '<S248>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero1'
 * '<S249>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero2'
 * '<S250>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Compare To Zero3'
 * '<S251>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter'
 * '<S252>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S253>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Complex Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S254>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/Compare To Constant'
 * '<S255>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping'
 * '<S256>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Angle Modulus'
 * '<S257>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Difference'
 * '<S258>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Low_Pass_Filter'
 * '<S259>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Steering Localized Command/Steering Heading PID/PID with Error Wrapping/Saturation Dynamic'
 * '<S260>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Translation Steering Command/Angle Modulus'
 * '<S261>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Reduce Speeds for Maximum Speed Limit'
 * '<S262>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add'
 * '<S263>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1'
 * '<S264>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2'
 * '<S265>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3'
 * '<S266>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver'
 * '<S267>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Cartesian to Polar'
 * '<S268>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian'
 * '<S269>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Polar to Cartesian1'
 * '<S270>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add/Angle_Saver/Compare To Zero1'
 * '<S271>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver'
 * '<S272>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Cartesian to Polar'
 * '<S273>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian'
 * '<S274>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Polar to Cartesian1'
 * '<S275>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add1/Angle_Saver/Compare To Zero1'
 * '<S276>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver'
 * '<S277>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Cartesian to Polar'
 * '<S278>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian'
 * '<S279>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Polar to Cartesian1'
 * '<S280>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add2/Angle_Saver/Compare To Zero1'
 * '<S281>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver'
 * '<S282>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Cartesian to Polar'
 * '<S283>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian'
 * '<S284>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Polar to Cartesian1'
 * '<S285>' : 'Code_Gen_Model/RoboRio Controls/Swerve_Drive/Wheel Module Speed and Angle/Wheel_Angle_Calculator/Vector_Add3/Angle_Saver/Compare To Zero1'
 * '<S286>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive'
 * '<S287>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering'
 * '<S288>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation'
 * '<S289>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Circular Deadband'
 * '<S290>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment'
 * '<S291>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Latch Outputs when Both Inputs Zero'
 * '<S292>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero'
 * '<S293>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero1'
 * '<S294>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero2'
 * '<S295>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero3'
 * '<S296>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Gyro_Adjustment/Compare To Zero4'
 * '<S297>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Latch Outputs when Both Inputs Zero/Compare To Zero'
 * '<S298>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Steering/Latch Outputs when Both Inputs Zero/Compare To Zero1'
 * '<S299>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit'
 * '<S300>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero'
 * '<S301>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit'
 * '<S302>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter'
 * '<S303>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Saturation Dynamic'
 * '<S304>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Boost and Rate Limit/Simple Rate Limit/Discrete Rate Limiter/Unit Delay External IC'
 * '<S305>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero'
 * '<S306>' : 'Code_Gen_Model/RoboRio Controls/Teleop/Joystick_Input_To_Swerve_Drive/Robot_Desired_Translation/Latch Outputs when Both Inputs Zero/Compare To Zero1'
 */
#endif                                 /* RTW_HEADER_Code_Gen_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
