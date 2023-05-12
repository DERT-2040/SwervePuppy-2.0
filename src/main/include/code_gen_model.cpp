//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: code_gen_model.cpp
//
// Code generated for Simulink model 'code_gen_model'.
//
// Model version                  : 1.35
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Thu May 11 18:20:31 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "code_gen_model.h"
#include "rtwtypes.h"
#include "code_gen_model_private.h"
#include <cmath>
#include <cfloat>

extern "C"
{

#include "rt_nonfinite.h"

}

// Named constants for Chart: '<S1>/Chart'
const uint8_T code_gen_model_IN_A{ 1U };

const uint8_T code_gen_model_IN_B{ 2U };

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (std::isnan(u0) || std::isnan(u1) || std::isinf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (std::isinf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = std::fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > std::floor(u1))) {
      real_T q;
      q = std::abs(u0 / u1);
      yEq = !(std::abs(q - std::floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

// Model step function
void code_gen_model::step()
{
  real_T tmp;
  int32_T Index;
  int32_T i;

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
      code_gen_model_B.Motor_Speed_g = 500.0;
      code_gen_model_DW.time = 0.0;
    } else if (code_gen_model_DW.is_c3_code_gen_model == code_gen_model_IN_A) {
      if (code_gen_model_DW.time >= 2.0) {
        code_gen_model_DW.is_c3_code_gen_model = code_gen_model_IN_B;
        code_gen_model_B.Motor_Speed_g = -500.0;
        code_gen_model_DW.time = 0.0;
      } else {
        code_gen_model_DW.time += 0.02;
      }

      // case IN_B:
    } else if (code_gen_model_DW.time >= 2.0) {
      code_gen_model_DW.is_c3_code_gen_model = code_gen_model_IN_A;
      code_gen_model_B.Motor_Speed_g = 500.0;
      code_gen_model_DW.time = 0.0;
    } else {
      code_gen_model_DW.time += 0.02;
    }

    // End of Chart: '<S1>/Chart'

    // Merge: '<Root>/Merge' incorporates:
    //   Constant: '<S1>/Constant1'
    //   Product: '<S1>/Divide'

    code_gen_model_B.Motor_Speed = code_gen_model_B.Motor_Speed_g / 5700.0;

    // End of Outputs for SubSystem: '<Root>/Auto'
  } else if (code_gen_model_U.Game_State == 1.0) {
    // Outputs for IfAction SubSystem: '<Root>/Teleop' incorporates:
    //   ActionPort: '<S3>/Action Port'

    // Sum: '<S3>/Add' incorporates:
    //   Inport: '<Root>/Trigger_val_n '
    //   Inport: '<Root>/Trigger_val_p'

    code_gen_model_B.Net_input = code_gen_model_U.Trigger_val_p -
      code_gen_model_U.Trigger_val_n;

    // Merge: '<Root>/Merge' incorporates:
    //   Constant: '<S3>/Constant'
    //   Constant: '<S3>/Constant1'
    //   Product: '<S3>/Divide'
    //   Product: '<S3>/Product'

    code_gen_model_B.Motor_Speed = code_gen_model_B.Net_input * 1000.0 / 5700.0;

    // End of Outputs for SubSystem: '<Root>/Teleop'
  } else {
    // Outputs for IfAction SubSystem: '<Root>/Disabled' incorporates:
    //   ActionPort: '<S2>/Action Port'

    // Outputs for Iterator SubSystem: '<S2>/Array Triangle Gen Fill' incorporates:
    //   ForIterator: '<S5>/For Iterator'

    for (Index = 0; Index < 8; Index++) {
      // Assignment: '<S5>/Assignment'
      if (Index == 0) {
        // Outport: '<Root>/LED_Array'
        for (i = 0; i < 8; i++) {
          code_gen_model_Y.LED_Array[i] = 0U;
        }
      }

      // Product: '<S5>/Product' incorporates:
      //   Abs: '<S5>/Abs'
      //   Constant: '<S2>/LED_Amplitude'
      //   Constant: '<S2>/LED_Offset_Per_LED'
      //   Constant: '<S2>/LED_Period'
      //   Gain: '<S5>/Gain'
      //   Gain: '<S5>/Gain1'
      //   Gain: '<S5>/Gain2'
      //   Math: '<S5>/Math Function'
      //   Product: '<S5>/Divide'
      //   Product: '<S5>/Product1'
      //   Sum: '<S5>/Subtract'
      //   Sum: '<S5>/Subtract1'
      //   UnitDelay: '<Root>/Unit Delay'

      tmp = std::floor(std::abs(rt_modd_snf((code_gen_model_DW.UnitDelay_DSTATE
        - 2500.0) - static_cast<real_T>(Index) * 125.0, 5000.0) - 2500.0) *
                       0.072);
      if (std::isnan(tmp)) {
        // Assignment: '<S5>/Assignment' incorporates:
        //   Outport: '<Root>/LED_Array'

        code_gen_model_Y.LED_Array[Index] = 0U;
      } else {
        // Assignment: '<S5>/Assignment' incorporates:
        //   Outport: '<Root>/LED_Array'

        code_gen_model_Y.LED_Array[Index] = static_cast<uint32_T>
          (static_cast<int32_T>(tmp));
      }

      // End of Product: '<S5>/Product'
    }

    // End of Outputs for SubSystem: '<S2>/Array Triangle Gen Fill'

    // Math: '<S2>/Mod1' incorporates:
    //   Constant: '<S2>/LED_Period'
    //   Sum: '<S2>/Add'
    //   UnitDelay: '<Root>/Unit Delay'

    code_gen_model_DW.UnitDelay_DSTATE = rt_modd_snf
      (code_gen_model_DW.UnitDelay_DSTATE + code_gen_model_ConstB.Gain, 5000.0);

    // End of Outputs for SubSystem: '<Root>/Disabled'
  }

  // End of If: '<Root>/If'

  // Outport: '<Root>/Motor_speed'
  code_gen_model_Y.Motor_speed = code_gen_model_B.Motor_Speed;
}

// Model initialize function
void code_gen_model::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
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
