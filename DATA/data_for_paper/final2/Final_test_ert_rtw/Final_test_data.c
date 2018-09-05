/*
 * Final_test_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Final_test".
 *
 * Model version              : 1.36
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Fri Aug 31 13:49:27 2018
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
   * Referenced by: '<S59>/Integral Gain'
   */
  0.01,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S59>/Proportional Gain'
   */
  0.05,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S55>/Constant'
   */
  3.0,

  /* Mask Parameter: DetectChange_vinit
   * Referenced by: '<S58>/Delay Input1'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S4>/Analog Input'
   */
  0.01,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S4>/Transfer Fcn1'
   */
  -30.0,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S4>/Transfer Fcn1'
   */
  30.0,

  /* Expression: 650
   * Referenced by: '<Root>/Wind_des'
   */
  650.0,

  /* Expression: 1
   * Referenced by: '<S3>/Run Sim'
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
   * Referenced by: '<S59>/Integrator'
   */
  0.01,

  /* Expression: InitialConditionForIntegrator
   * Referenced by: '<S59>/Integrator'
   */
  0.0,

  /* Expression: 5.6e-4
   * Referenced by: '<S6>/Gain1'
   */
  0.00056,

  /* Expression: -.61
   * Referenced by: '<S6>/Gain'
   */
  -0.61,

  /* Expression: 170
   * Referenced by: '<S6>/Constant'
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
   * Referenced by: '<S3>/Switch2'
   */
  0.0,

  /* Expression: 40
   * Referenced by: '<S3>/PWM saturation'
   */
  40.0,

  /* Expression: 0
   * Referenced by: '<S3>/PWM saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Motor Switch'
   */
  0.0,

  /* Expression: 40
   * Referenced by: '<S3>/min PWM'
   */
  40.0,

  /* Expression: 40
   * Referenced by: '<S3>/Constant4'
   */
  40.0,

  /* Expression: 16.36
   * Referenced by: '<S7>/b'
   */
  16.36,

  /* Expression: 4.24e-47
   * Referenced by: '<S7>/a'
   */
  4.24E-47,

  /* Expression: 0
   * Referenced by: '<S8>/Integrator1'
   */
  0.0,

  /* Expression: 40
   * Referenced by: '<Root>/Constant1'
   */
  40.0,

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

  /* Expression: .99
   * Referenced by: '<S60>/a'
   */
  0.99,

  /* Expression: .003
   * Referenced by: '<S60>/b'
   */
  0.003,

  /* Expression: .057
   * Referenced by: '<S60>/c'
   */
  0.057,

  /* Expression: 4
   * Referenced by: '<S8>/Gain2'
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

  /* Expression: 4
   * Referenced by: '<S8>/Gain1'
   */
  4.0,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  1U
};