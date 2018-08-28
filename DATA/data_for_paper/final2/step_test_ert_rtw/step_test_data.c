/*
 * step_test_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "step_test".
 *
 * Model version              : 1.21
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Tue Aug 28 13:31:25 2018
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
   * Referenced by: '<S15>/Integral Gain'
   */
  0.01,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S15>/Proportional Gain'
   */
  0.05,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S10>/Constant'
   */
  3.0,

  /* Mask Parameter: DetectChange_vinit
   * Referenced by: '<S14>/Delay Input1'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S4>/Analog Input1'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S4>/Analog Input'
   */
  0.01,

  /* Expression: 650
   * Referenced by: '<Root>/Wind_des'
   */
  650.0,

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
   * Referenced by: '<S15>/Integrator'
   */
  0.01,

  /* Expression: InitialConditionForIntegrator
   * Referenced by: '<S15>/Integrator'
   */
  0.0,

  /* Expression: 5.6e-4
   * Referenced by: '<S8>/Gain1'
   */
  0.00056,

  /* Expression: -.61
   * Referenced by: '<S8>/Gain'
   */
  -0.61,

  /* Expression: 170
   * Referenced by: '<S8>/Constant'
   */
  170.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Manual PWM'
   */
  0.0,

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

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S9>/Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S9>/Transfer Fcn'
   */
  50.0,

  /* Expression: .6859
   * Referenced by: '<S9>/Gain1'
   */
  0.6859,

  /* Expression: .2314
   * Referenced by: '<S9>/Constant3'
   */
  0.2314,

  /* Expression: 3
   * Referenced by: '<S9>/Constant1'
   */
  3.0,

  /* Expression: 0.03836
   * Referenced by: '<S9>/Gain2'
   */
  0.03836,

  /* Expression: 0.8882
   * Referenced by: '<S9>/Constant2'
   */
  0.8882,

  /* Expression: 16.36
   * Referenced by: '<S9>/Constant'
   */
  16.36,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S9>/Transfer Fcn1'
   */
  -50.0,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S9>/Transfer Fcn1'
   */
  50.0,

  /* Expression: 1
   * Referenced by: '<S9>/Gain'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S7>/Integrator'
   */
  0.0,

  /* Expression: 40
   * Referenced by: '<Root>/Constant1'
   */
  40.0,

  /* Expression: 0.3933
   * Referenced by: '<S13>/Constant3'
   */
  0.3933,

  /* Expression: 0.03432
   * Referenced by: '<S13>/Gain2'
   */
  0.03432,

  /* Expression: 0.005561
   * Referenced by: '<S13>/Constant4'
   */
  0.005561,

  /* Expression: 686.2
   * Referenced by: '<S9>/Constant4'
   */
  686.2,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  1U
};
