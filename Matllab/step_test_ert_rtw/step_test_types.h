/*
 * step_test_types.h
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

#ifndef RTW_HEADER_step_test_types_h_
#define RTW_HEADER_step_test_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#ifndef typedef_dsp_private_SlidingWindowAver_T
#define typedef_dsp_private_SlidingWindowAver_T

typedef struct {
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[4];
  real_T pCumRevIndex;
} dsp_private_SlidingWindowAver_T;

#endif                                 /*typedef_dsp_private_SlidingWindowAver_T*/

/* Custom Type definition for MATLABSystem: '<S2>/Analog Input' */
#include "MW_SVD.h"
#ifndef struct_mde12672362a75a5cad908219ba2cf40ac
#define struct_mde12672362a75a5cad908219ba2cf40ac

struct mde12672362a75a5cad908219ba2cf40ac
{
  int32_T S0_isInitialized;
  real_T W0_states[83];
  real_T P0_InitialStates;
  real_T P1_Coefficients[84];
};

#endif                                 /*struct_mde12672362a75a5cad908219ba2cf40ac*/

#ifndef typedef_dsp_FIRFilter_0_step_test_T
#define typedef_dsp_FIRFilter_0_step_test_T

typedef struct mde12672362a75a5cad908219ba2cf40ac dsp_FIRFilter_0_step_test_T;

#endif                                 /*typedef_dsp_FIRFilter_0_step_test_T*/

#ifndef struct_mdkUsQJ5LAnqkxP9fmC2PsnD
#define struct_mdkUsQJ5LAnqkxP9fmC2PsnD

struct mdkUsQJ5LAnqkxP9fmC2PsnD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  dsp_FIRFilter_0_step_test_T cSFunObject;
};

#endif                                 /*struct_mdkUsQJ5LAnqkxP9fmC2PsnD*/

#ifndef typedef_dspcodegen_FIRFilter_step_tes_T
#define typedef_dspcodegen_FIRFilter_step_tes_T

typedef struct mdkUsQJ5LAnqkxP9fmC2PsnD dspcodegen_FIRFilter_step_tes_T;

#endif                                 /*typedef_dspcodegen_FIRFilter_step_tes_T*/

#ifndef typedef_cell_wrap_step_test_T
#define typedef_cell_wrap_step_test_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_step_test_T;

#endif                                 /*typedef_cell_wrap_step_test_T*/

#ifndef typedef_cell_step_test_T
#define typedef_cell_step_test_T

typedef struct {
  char_T f1;
  char_T f2;
  char_T f3;
  char_T f4;
  char_T f5;
  char_T f6;
  char_T f7;
  char_T f8;
  char_T f9[2];
  char_T f10[2];
  char_T f11[2];
  char_T f12[2];
} cell_step_test_T;

#endif                                 /*typedef_cell_step_test_T*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct {
  cell_step_test_T AvailablePwmPinNames;
} codertarget_arduinobase_inter_T;

#endif                                 /*typedef_codertarget_arduinobase_inter_T*/

#ifndef typedef_codertarget_arduinobase_int_d_T
#define typedef_codertarget_arduinobase_int_d_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  codertarget_arduinobase_inter_T Hw;
  MW_Handle_Type MW_PWM_HANDLE;
} codertarget_arduinobase_int_d_T;

#endif                                 /*typedef_codertarget_arduinobase_int_d_T*/

#ifndef typedef_codertarget_arduinobase_in_dm_T
#define typedef_codertarget_arduinobase_in_dm_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  codertarget_arduinobase_inter_T Hw;
  MW_Handle_Type MW_ANALOGIN_HANDLE;
  real_T SampleTime;
} codertarget_arduinobase_in_dm_T;

#endif                                 /*typedef_codertarget_arduinobase_in_dm_T*/

#ifndef typedef_dsp_simulink_MovingAverage_st_T
#define typedef_dsp_simulink_MovingAverage_st_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_step_test_T inputVarSize;
  dsp_private_SlidingWindowAver_T *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingAverage_st_T;

#endif                                 /*typedef_dsp_simulink_MovingAverage_st_T*/

#ifndef struct_mdjFPeGrIdoXy1ZtHuQdSxwE
#define struct_mdjFPeGrIdoXy1ZtHuQdSxwE

struct mdjFPeGrIdoXy1ZtHuQdSxwE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_step_test_T inputVarSize;
  int32_T NumChannels;
  dspcodegen_FIRFilter_step_tes_T *FilterObj;
};

#endif                                 /*struct_mdjFPeGrIdoXy1ZtHuQdSxwE*/

#ifndef typedef_dsp_LowpassFilter_step_test_T
#define typedef_dsp_LowpassFilter_step_test_T

typedef struct mdjFPeGrIdoXy1ZtHuQdSxwE dsp_LowpassFilter_step_test_T;

#endif                                 /*typedef_dsp_LowpassFilter_step_test_T*/

/* Parameters (default storage) */
typedef struct P_step_test_T_ P_step_test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_step_test_T RT_MODEL_step_test_T;

#endif                                 /* RTW_HEADER_step_test_types_h_ */
