/*
 * step_test_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "step_test".
 *
 * Model version              : 1.14
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Fri Jun  8 15:33:11 2018
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "step_test.h"
#include "step_test_private.h"

/* Block parameters (default storage) */
P_step_test_T step_test_P = {
  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S10>/Integral Gain'
   */
  0.01,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S10>/Proportional Gain'
   */
  0.05,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S6>/Constant'
   */
  3.0,

  /* Mask Parameter: DetectChange_vinit
   * Referenced by: '<S9>/Delay Input1'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S2>/Analog Input1'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S2>/Analog Input'
   */
  0.01,

  /* Expression: 664.76923076923
   * Referenced by: '<Root>/Wind_des'
   */
  664.76923076923,

  /* Expression: 1
   * Referenced by: '<S1>/Run Sim'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Automatic Control'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Enable'
   */
  1.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S10>/Integrator'
   */
  0.01,

  /* Expression: InitialConditionForIntegrator
   * Referenced by: '<S10>/Integrator'
   */
  0.0,

  /* Expression: 5.6e-4
   * Referenced by: '<S5>/Gain1'
   */
  0.00056,

  /* Expression: -.61
   * Referenced by: '<S5>/Gain'
   */
  -0.61,

  /* Expression: 170
   * Referenced by: '<S5>/Constant'
   */
  170.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 11.699248120301
   * Referenced by: '<Root>/Manual PWM'
   */
  11.699248120301,

  /* Expression: 0
   * Referenced by: '<S1>/Switch2'
   */
  0.0,

  /* Expression: 40
   * Referenced by: '<S1>/PWM saturation'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S1>/PWM saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Motor Switch'
   */
  0.0,

  /* Expression: 40
   * Referenced by: '<S1>/min PWM'
   */
  40.0,

  /* Expression: 40
   * Referenced by: '<S1>/Constant4'
   */
  40.0,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  1U
};
