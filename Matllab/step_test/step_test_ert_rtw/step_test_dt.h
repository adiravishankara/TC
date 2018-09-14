/*
 * step_test_dt.h
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
  sizeof(dsp_simulink_MovingAverage_st_T),
  sizeof(dsp_private_SlidingWindowAver_T),
  sizeof(codertarget_arduinobase_int_d_T),
  sizeof(codertarget_arduinobase_in_dm_T),
  sizeof(dsp_LowpassFilter_step_test_T),
  sizeof(dspcodegen_FIRFilter_step_tes_T)
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
  "dsp_simulink_MovingAverage_st_T",
  "dsp_private_SlidingWindowAver_T",
  "codertarget_arduinobase_int_d_T",
  "codertarget_arduinobase_in_dm_T",
  "dsp_LowpassFilter_step_test_T",
  "dspcodegen_FIRFilter_step_tes_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&step_test_B.ManualSwitch1[0]), 0, 0, 5 },

  { (char_T *)(&step_test_B.ZeroOrderHold1), 0, 0, 9 },

  { (char_T *)(&step_test_B.ZeroOrderHold), 5, 0, 1 }
  ,

  { (char_T *)(&step_test_DW.gobj_0), 19, 0, 2 },

  { (char_T *)(&step_test_DW.obj), 14, 0, 1 },

  { (char_T *)(&step_test_DW.gobj_0_n), 15, 0, 2 },

  { (char_T *)(&step_test_DW.obj_e), 18, 0, 1 },

  { (char_T *)(&step_test_DW.obj_g), 17, 0, 2 },

  { (char_T *)(&step_test_DW.obj_n), 16, 0, 1 },

  { (char_T *)(&step_test_DW.DelayInput1_DSTATE), 0, 0, 2 },

  { (char_T *)(&step_test_DW.FromWs_PWORK.TimePtr), 11, 0, 9 },

  { (char_T *)(&step_test_DW.FromWs_IWORK.PrevIndex), 10, 0, 1 },

  { (char_T *)(&step_test_DW.Integrator_PrevResetState), 2, 0, 3 },

  { (char_T *)(&step_test_DW.objisempty), 8, 0, 6 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  14U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&step_test_P.DiscretePIDController_I), 0, 0, 23 },

  { (char_T *)(&step_test_P.ManualSwitch_CurrentSetting), 3, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] step_test_dt.h */
