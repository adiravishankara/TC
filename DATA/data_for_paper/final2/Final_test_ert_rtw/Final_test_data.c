/*
 * Final_test_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Final_test".
 *
 * Model version              : 1.49
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Wed Sep 12 11:44:58 2018
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
  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S15>/Integral Gain'
   */
  0.01,

  /* Mask Parameter: PIDController3_I
   * Referenced by: '<S20>/Integral Gain'
   */
  5.23638207345188,

  /* Mask Parameter: PIDController3_P
   * Referenced by: '<S20>/Proportional Gain'
   */
  10.1984567978833,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S15>/Proportional Gain'
   */
  0.05,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S11>/Constant'
   */
  3.0,

  /* Mask Parameter: DetectChange_vinit
   * Referenced by: '<S16>/Delay Input1'
   */
  0.0,

  /* Mask Parameter: DetectChange_vinit_c
   * Referenced by: '<S14>/Delay Input1'
   */
  0.0,

  /* Expression: 0.8
   * Referenced by: '<Root>/Gain'
   */
  0.8,

  /* Expression: 0.01
   * Referenced by: '<S3>/Analog Input'
   */
  0.01,

  /* Expression: 0
   * Referenced by: '<S1>/Memory'
   */
  0.0,

  /* Expression: 2.7456647398844
   * Referenced by: '<Root>/Constant2'
   */
  2.7456647398844,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S3>/Transfer Fcn1'
   */
  -10.0,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S3>/Transfer Fcn1'
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

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S20>/Integrator'
   */
  0.01,

  /* Expression: InitialConditionForIntegrator
   * Referenced by: '<S20>/Integrator'
   */
  0.0,

  /* Expression: 40
   * Referenced by: '<S7>/Saturation'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S7>/Saturation'
   */
  0.0,

  /* Expression: 650
   * Referenced by: '<Root>/Wind_des'
   */
  650.0,

  /* Computed Parameter: Integrator_gainval_l
   * Referenced by: '<S15>/Integrator'
   */
  0.01,

  /* Expression: InitialConditionForIntegrator
   * Referenced by: '<S15>/Integrator'
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

  /* Expression: 5.0990117390951
   * Referenced by: '<Root>/Manual PWM'
   */
  5.0990117390951,

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
   * Referenced by: '<S8>/Integrator1'
   */
  0.0,

  /* Expression: 6.146
   * Referenced by: '<S6>/Constant'
   */
  6.146,

  /* Expression: 4.701e-15
   * Referenced by: '<S6>/Gain'
   */
  4.701E-15,

  /* Expression: 0.0731
   * Referenced by: '<S6>/Constant1'
   */
  0.0731,

  /* Expression: 0.3933
   * Referenced by: '<S10>/a'
   */
  0.3933,

  /* Expression: 0.03432
   * Referenced by: '<S10>/b'
   */
  0.03432,

  /* Expression: 0.005561
   * Referenced by: '<S10>/c'
   */
  0.005561,

  /* Expression: 4
   * Referenced by: '<S8>/Gain1'
   */
  4.0,

  /* Expression: 0
   * Referenced by: '<S8>/Integrator'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S8>/Gain'
   */
  3.0,

  /* Expression: .99
   * Referenced by: '<S21>/a'
   */
  0.99,

  /* Expression: .003
   * Referenced by: '<S21>/b'
   */
  0.003,

  /* Expression: .057
   * Referenced by: '<S21>/c'
   */
  0.057,

  /* Expression: 4
   * Referenced by: '<S8>/Gain2'
   */
  4.0,

  /* Expression: 485.3342
   * Referenced by: '<S3>/Constant'
   */
  485.3342,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U,

  /* Computed Parameter: ManualSwitch3_CurrentSetting
   * Referenced by: '<Root>/Manual Switch3'
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
