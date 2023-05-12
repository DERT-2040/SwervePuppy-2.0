//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: code_gen_model.h
//
// Code generated for Simulink model 'code_gen_model'.
//
// Model version                  : 1.36
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Thu May 11 19:28:51 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_code_gen_model_h_
#define RTW_HEADER_code_gen_model_h_
#include "rtwtypes.h"
#include "code_gen_model_types.h"

extern "C"
{

#include "rtGetNaN.h"

}

extern "C"
{

#include "rt_nonfinite.h"

}

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model code_gen_model
class code_gen_model final
{
  // public data and function members
 public:
  // Block signals (default storage)
  struct B_code_gen_model_T {
    real_T Motor_Speed;                // '<Root>/Merge'
    real_T Net_input;                  // '<S3>/Add'
    real_T Motor_Speed_g;              // '<S1>/Chart'
  };

  // Block states (default storage) for system '<Root>'
  struct DW_code_gen_model_T {
    real_T UnitDelay_DSTATE;           // '<Root>/Unit Delay'
    real_T time;                       // '<S1>/Chart'
    uint8_T is_active_c3_code_gen_model;// '<S1>/Chart'
    uint8_T is_c3_code_gen_model;      // '<S1>/Chart'
  };

  // Invariant block signals (default storage)
  struct ConstB_code_gen_model_T {
    real_T Gain;                       // '<S2>/Gain'
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_code_gen_model_T {
    real_T Game_State;                 // '<Root>/Game_State'
    real_T Trigger_val_p;              // '<Root>/Trigger_val_p'
    real_T Trigger_val_n;              // '<Root>/Trigger_val_n '
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_code_gen_model_T {
    real_T Motor_speed;                // '<Root>/Motor_speed'
    uint32_T LED_Array[75];            // '<Root>/LED_Array'
  };

  // Real-time Model Data Structure
  struct RT_MODEL_code_gen_model_T {
    const char_T * volatile errorStatus;
  };

  // Copy Constructor
  code_gen_model(code_gen_model const&) = delete;

  // Assignment Operator
  code_gen_model& operator= (code_gen_model const&) & = delete;

  // Move Constructor
  code_gen_model(code_gen_model &&) = delete;

  // Move Assignment Operator
  code_gen_model& operator= (code_gen_model &&) = delete;

  // Real-Time Model get method
  code_gen_model::RT_MODEL_code_gen_model_T * getRTM();

  // Root inports set method
  void setExternalInputs(const ExtU_code_gen_model_T *pExtU_code_gen_model_T)
  {
    code_gen_model_U = *pExtU_code_gen_model_T;
  }

  // Root outports get method
  const ExtY_code_gen_model_T &getExternalOutputs() const
  {
    return code_gen_model_Y;
  }

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  static void terminate();

  // Constructor
  code_gen_model();

  // Destructor
  ~code_gen_model();

  // private data and function members
 private:
  // External inputs
  ExtU_code_gen_model_T code_gen_model_U;

  // External outputs
  ExtY_code_gen_model_T code_gen_model_Y;

  // Block signals
  B_code_gen_model_T code_gen_model_B;

  // Block states
  DW_code_gen_model_T code_gen_model_DW;

  // Real-Time Model
  RT_MODEL_code_gen_model_T code_gen_model_M;
};

extern const code_gen_model::ConstB_code_gen_model_T code_gen_model_ConstB;// constant block i/o 

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'code_gen_model'
//  '<S1>'   : 'code_gen_model/Auto'
//  '<S2>'   : 'code_gen_model/Disabled'
//  '<S3>'   : 'code_gen_model/Teleop'
//  '<S4>'   : 'code_gen_model/Auto/Chart'
//  '<S5>'   : 'code_gen_model/Disabled/Array Triangle Gen Fill'

#endif                                 // RTW_HEADER_code_gen_model_h_

//
// File trailer for generated code.
//
// [EOF]
//
