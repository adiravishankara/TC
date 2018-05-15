/*
 * basic_dt.h
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
  sizeof(codertarget_arduinobase_int_b_T),
  sizeof(codertarget_arduinobase_in_b0_T)
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
  "codertarget_arduinobase_int_b_T",
  "codertarget_arduinobase_in_b0_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&basic_B.e), 0, 0, 8 },

  { (char_T *)(&basic_B.RateTransition), 5, 0, 1 },

  { (char_T *)(&basic_B.Compare), 8, 0, 1 }
  ,

  { (char_T *)(&basic_DW.obj), 14, 0, 2 },

  { (char_T *)(&basic_DW.obj_n), 15, 0, 1 },

  { (char_T *)(&basic_DW.Delay_DSTATE), 0, 0, 4 },

  { (char_T *)(&basic_DW.Scope_PWORK.LoggedData), 11, 0, 7 },

  { (char_T *)(&basic_DW.objisempty), 8, 0, 3 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&basic_P.CompareToConstant_const), 0, 0, 2 },

  { (char_T *)(&basic_P.CompareToConstant_const_g), 5, 0, 1 },

  { (char_T *)(&basic_P.AnalogInput1_SampleTime), 0, 0, 19 },

  { (char_T *)(&basic_P.Delay_DelayLength), 7, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] basic_dt.h */
