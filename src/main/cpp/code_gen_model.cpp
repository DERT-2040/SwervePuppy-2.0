//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: code_gen_model.cpp
//
// Code generated for Simulink model 'code_gen_model'.
//
// Model version                  : 1.20
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Thu May  4 19:45:40 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "code_gen_model.h"
#include "rtwtypes.h"

// Named constants for Chart: '<S1>/Chart'
const uint8_T code_gen_model_IN_A{ 1U };

const uint8_T code_gen_model_IN_B{ 2U };

// Model step function
void code_gen_model::step()
{
  // If: '<Root>/If' incorporates:
  //   Inport: '<Root>/Game_State'

  if (code_gen_model_U.Game_State == 0.0) {
    // Outputs for IfAction SubSystem: '<Root>/Auto' incorporates:
    //   ActionPort: '<S1>/Action Port'

    // Chart: '<S1>/Chart' incorporates:
    //   Constant: '<S1>/Speed1'
    //   Constant: '<S1>/Speed2'

    if (code_gen_model_DW.is_active_c3_code_gen_model == 0U) {
      code_gen_model_DW.is_active_c3_code_gen_model = 1U;
      code_gen_model_DW.is_c3_code_gen_model = code_gen_model_IN_A;
      code_gen_model_B.Motor_Speed = 500.0;
      code_gen_model_DW.time = 0.0;
    } else if (code_gen_model_DW.is_c3_code_gen_model == code_gen_model_IN_A) {
      if (code_gen_model_DW.time >= 2.0) {
        code_gen_model_DW.is_c3_code_gen_model = code_gen_model_IN_B;
        code_gen_model_B.Motor_Speed = -500.0;
        code_gen_model_DW.time = 0.0;
      } else {
        code_gen_model_DW.time += 0.02;
      }

      // case IN_B:
    } else if (code_gen_model_DW.time >= 2.0) {
      code_gen_model_DW.is_c3_code_gen_model = code_gen_model_IN_A;
      code_gen_model_B.Motor_Speed = 500.0;
      code_gen_model_DW.time = 0.0;
    } else {
      code_gen_model_DW.time += 0.02;
    }

    // End of Chart: '<S1>/Chart'

    // Outport: '<Root>/Motor_speed' incorporates:
    //   Constant: '<S1>/Constant1'
    //   Product: '<S1>/Divide'

    code_gen_model_Y.Motor_speed = code_gen_model_B.Motor_Speed / 5700.0;

    // End of Outputs for SubSystem: '<Root>/Auto'
  } else {
    // Outputs for IfAction SubSystem: '<Root>/Teleop' incorporates:
    //   ActionPort: '<S2>/Action Port'

    // Sum: '<S2>/Add' incorporates:
    //   Inport: '<Root>/Trigger_val_n '
    //   Inport: '<Root>/Trigger_val_p'

    code_gen_model_B.Net_input = code_gen_model_U.Trigger_val_p -
      code_gen_model_U.Trigger_val_n;

    // Outport: '<Root>/Motor_speed' incorporates:
    //   Constant: '<S2>/Constant'
    //   Constant: '<S2>/Constant1'
    //   Product: '<S2>/Divide'
    //   Product: '<S2>/Product'

    code_gen_model_Y.Motor_speed = code_gen_model_B.Net_input * 1000.0 / 5700.0;

    // End of Outputs for SubSystem: '<Root>/Teleop'
  }

  // End of If: '<Root>/If'
}

// Model initialize function
void code_gen_model::initialize()
{
  // (no initialization code required)
}

// Model terminate function
void code_gen_model::terminate()
{
  // (no terminate code required)
}

// Constructor
code_gen_model::code_gen_model() :
  code_gen_model_U(),
  code_gen_model_Y(),
  code_gen_model_B(),
  code_gen_model_DW(),
  code_gen_model_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
code_gen_model::~code_gen_model() = default;

// Real-Time Model get method
code_gen_model::RT_MODEL_code_gen_model_T * code_gen_model::getRTM()
{
  return (&code_gen_model_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
