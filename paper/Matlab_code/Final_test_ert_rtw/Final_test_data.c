/*
 * Final_test_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Final_test".
 *
 * Model version              : 1.53
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Sat Sep 15 16:14:57 2018
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Final_test.h"
#include "Final_test_private.h"

/* Block parameters (default storage) */
P_Final_test_T Final_test_P = {
  /* Mask Parameter: PIDController3_I
   * Referenced by: '<S27>/Integral Gain'
   */
  5.23638207345188,

  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S22>/Integral Gain'
   */
  0.01,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S22>/Proportional Gain'
   */
  0.05,

  /* Mask Parameter: PIDController3_P
   * Referenced by: '<S27>/Proportional Gain'
   */
  10.1984567978833,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S18>/Constant'
   */
  3.0,

  /* Mask Parameter: DetectChange_vinit
   * Referenced by: '<S21>/Delay Input1'
   */
  0.0,

  /* Mask Parameter: DetectChange_vinit_i
   * Referenced by: '<S23>/Delay Input1'
   */
  0.0,

  /* Expression: 0.8
   * Referenced by: '<Root>/Gain'
   */
  0.8,

  /* Expression: 0.8
   * Referenced by: '<Root>/Gain1'
   */
  0.8,

  /* Expression: 0.01
   * Referenced by: '<S4>/Analog Input'
   */
  0.01,

  /* Expression: 1.0355029585799
   * Referenced by: '<Root>/Constant2'
   */
  1.0355029585799,

  /* Expression: 0
   * Referenced by: '<S1>/Memory'
   */
  0.0,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S4>/Transfer Fcn1'
   */
  -10.0,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S4>/Transfer Fcn1'
   */
  10.0,

  /* Expression: 1
   * Referenced by: '<S2>/Run Sim'
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

  /* Expression: 650
   * Referenced by: '<Root>/Wind_des'
   */
  650.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S22>/Integrator'
   */
  0.01,

  /* Expression: InitialConditionForIntegrator
   * Referenced by: '<S22>/Integrator'
   */
  0.0,

  /* Expression: 5.6e-4
   * Referenced by: '<S12>/Gain1'
   */
  0.00056,

  /* Expression: -.61
   * Referenced by: '<S12>/Gain'
   */
  -0.61,

  /* Expression: 170
   * Referenced by: '<S12>/Constant'
   */
  170.0,

  /* Computed Parameter: Integrator_gainval_p
   * Referenced by: '<S27>/Integrator'
   */
  0.01,

  /* Expression: InitialConditionForIntegrator
   * Referenced by: '<S27>/Integrator'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S13>/Gain'
   */
  1.0,

  /* Expression: 40
   * Referenced by: '<S13>/Saturation'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S13>/Saturation'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 11.451355661882
   * Referenced by: '<Root>/Manual PWM'
   */
  11.451355661882,

  /* Expression: 0
   * Referenced by: '<S2>/Switch2'
   */
  0.0,

  /* Expression: 40
   * Referenced by: '<S2>/PWM saturation'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S2>/PWM saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Motor Switch'
   */
  0.0,

  /* Expression: 40
   * Referenced by: '<S2>/min PWM'
   */
  40.0,

  /* Expression: 40
   * Referenced by: '<S2>/Constant4'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S14>/Integrator1'
   */
  0.0,

  /* Expression: 6.146
   * Referenced by: '<S15>/Constant'
   */
  6.146,

  /* Expression: 4.701e-15
   * Referenced by: '<S15>/Gain'
   */
  4.701E-15,

  /* Expression: 0.0731
   * Referenced by: '<S15>/Constant1'
   */
  0.0731,

  /* Expression: 40
   * Referenced by: '<Root>/Constant3'
   */
  40.0,

  /* Expression: 4
   * Referenced by: '<S14>/Gain1'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S14>/Integrator'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S14>/Gain'
   */
  3.0,

  /* Expression: .99
   * Referenced by: '<S28>/a'
   */
  0.99,

  /* Expression: .003
   * Referenced by: '<S28>/b'
   */
  0.003,

  /* Expression: .057
   * Referenced by: '<S28>/c'
   */
  0.057,

  /* Expression: 4
   * Referenced by: '<S14>/Gain2'
   */
  4.0,

  /* Expression: 485.3342
   * Referenced by: '<S4>/Constant'
   */
  485.3342,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U,

  /* Computed Parameter: ManualSwitch5_CurrentSetting
   * Referenced by: '<Root>/Manual Switch5'
   */
  0U,

  /* Computed Parameter: ManualSwitch3_CurrentSetting
   * Referenced by: '<Root>/Manual Switch3'
   */
  0U,

  /* Computed Parameter: ManualSwitch4_CurrentSetting
   * Referenced by: '<Root>/Manual Switch4'
   */
  0U,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<Root>/Manual Switch2'
   */
  0U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  1U
};
