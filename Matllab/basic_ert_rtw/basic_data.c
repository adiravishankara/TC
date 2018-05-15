/*
 * basic_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "basic".
 *
 * Model version              : 1.2
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Fri May 11 16:28:18 2018
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "basic.h"
#include "basic_private.h"

/* Block parameters (default storage) */
P_basic_T basic_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S4>/Constant'
   */
  3.0,

  /* Mask Parameter: SliderGain_gain
   * Referenced by: '<S2>/Slider Gain'
   */
  0.0,

  /* Mask Parameter: CompareToConstant_const_g
   * Referenced by: '<S1>/Constant'
   */
  400U,

  /* Expression: 0.01
   * Referenced by: '<Root>/Analog Input1'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<Root>/Analog Input'
   */
  0.01,

  /* Expression: 600
   * Referenced by: '<Root>/Constant1'
   */
  600.0,

  /* Expression: 0
   * Referenced by: '<Root>/Automatic Control'
   */
  0.0,

  /* Expression: 0.05
   * Referenced by: '<Root>/P'
   */
  0.05,

  /* Expression: 0.01
   * Referenced by: '<Root>/st'
   */
  0.01,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: 0.005
   * Referenced by: '<Root>/I'
   */
  0.005,

  /* Expression: 6.5
   * Referenced by: '<Root>/Constant2'
   */
  6.5,

  /* Expression: 1
   * Referenced by: '<Root>/Enable'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

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
   * Referenced by: synthesized block
   */
  0.0,

  /* Expression: 0
   * Referenced by: synthesized block
   */
  0.0,

  /* Expression: 0
   * Referenced by: synthesized block
   */
  0.0,

  /* Expression: 40
   * Referenced by: '<S3>/min PWM'
   */
  40.0,

  /* Expression: 1
   * Referenced by: '<Root>/Main switch'
   */
  1.0,

  /* Computed Parameter: Delay_DelayLength
   * Referenced by: '<Root>/Delay'
   */
  1U
};
