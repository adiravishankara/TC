/*
 * Final_test_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Final_test".
 *
 * Model version              : 1.55
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Sat Sep 15 19:14:33 2018
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(dsp_simulink_MovingAverage_f_T),
  sizeof(dsp_private_SlidingWindowAv_f_T),
  sizeof(dsp_simulink_MovingAverage_Fi_T),
  sizeof(dsp_private_SlidingWindowAver_T),
  sizeof(codertarget_arduinobase_int_f_T),
  sizeof(codertarget_arduinobase_in_fd_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "dsp_simulink_MovingAverage_f_T",
  "dsp_private_SlidingWindowAv_f_T",
  "dsp_simulink_MovingAverage_Fi_T",
  "dsp_private_SlidingWindowAver_T",
  "codertarget_arduinobase_int_f_T",
  "codertarget_arduinobase_in_fd_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Final_test_B.ManualSwitch4), 0, 0, 25 },

  { (char_T *)(&Final_test_B.Integrator), 0, 0, 6 }
  ,

  { (char_T *)(&Final_test_DW.gobj_0), 15, 0, 2 },

  { (char_T *)(&Final_test_DW.obj), 14, 0, 1 },

  { (char_T *)(&Final_test_DW.obj_c), 16, 0, 1 },

  { (char_T *)(&Final_test_DW.gobj_0_n), 17, 0, 2 },

  { (char_T *)(&Final_test_DW.obj_g), 19, 0, 1 },

  { (char_T *)(&Final_test_DW.obj_n), 18, 0, 1 },

  { (char_T *)(&Final_test_DW.DelayInput1_DSTATE), 0, 0, 11 },

  { (char_T *)(&Final_test_DW.FromWs_PWORK.TimePtr), 11, 0, 12 },

  { (char_T *)(&Final_test_DW.FromWs_IWORK.PrevIndex), 10, 0, 2 },

  { (char_T *)(&Final_test_DW.Integrator_PrevResetState), 2, 0, 5 },

  { (char_T *)(&Final_test_DW.objisempty), 8, 0, 4 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  13U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Final_test_P.PIDController3_I), 0, 0, 49 },

  { (char_T *)(&Final_test_P.ManualSwitch_CurrentSetting), 3, 0, 6 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] Final_test_dt.h */
