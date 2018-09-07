/*
 * Final_test_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Final_test".
 *
 * Model version              : 1.42
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Fri Sep  7 12:34:04 2018
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Final_test_types_h_
#define RTW_HEADER_Final_test_types_h_
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

/* Custom Type definition for MATLABSystem: '<S4>/Analog Input' */
#include "MW_SVD.h"
#ifndef typedef_cell_wrap_Final_test_T
#define typedef_cell_wrap_Final_test_T

typedef struct {
  uint32_T f1[8];
} cell_wrap_Final_test_T;

#endif                                 /*typedef_cell_wrap_Final_test_T*/

#ifndef typedef_cell_Final_test_T
#define typedef_cell_Final_test_T

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
} cell_Final_test_T;

#endif                                 /*typedef_cell_Final_test_T*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct {
  cell_Final_test_T AvailablePwmPinNames;
} codertarget_arduinobase_inter_T;

#endif                                 /*typedef_codertarget_arduinobase_inter_T*/

#ifndef typedef_codertarget_arduinobase_int_f_T
#define typedef_codertarget_arduinobase_int_f_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  codertarget_arduinobase_inter_T Hw;
  MW_Handle_Type MW_PWM_HANDLE;
} codertarget_arduinobase_int_f_T;

#endif                                 /*typedef_codertarget_arduinobase_int_f_T*/

#ifndef typedef_codertarget_arduinobase_in_fd_T
#define typedef_codertarget_arduinobase_in_fd_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  codertarget_arduinobase_inter_T Hw;
  MW_Handle_Type MW_ANALOGIN_HANDLE;
  real_T SampleTime;
} codertarget_arduinobase_in_fd_T;

#endif                                 /*typedef_codertarget_arduinobase_in_fd_T*/

#ifndef typedef_dsp_simulink_MovingAverage_Fi_T
#define typedef_dsp_simulink_MovingAverage_Fi_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_Final_test_T inputVarSize;
  dsp_private_SlidingWindowAver_T *pStatistic;
  int32_T NumChannels;
} dsp_simulink_MovingAverage_Fi_T;

#endif                                 /*typedef_dsp_simulink_MovingAverage_Fi_T*/

/* Parameters (default storage) */
typedef struct P_Final_test_T_ P_Final_test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Final_test_T RT_MODEL_Final_test_T;

#endif                                 /* RTW_HEADER_Final_test_types_h_ */
