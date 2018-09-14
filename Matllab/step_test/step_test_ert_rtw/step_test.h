/*
 * step_test.h
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

#ifndef RTW_HEADER_step_test_h_
#define RTW_HEADER_step_test_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef step_test_COMMON_INCLUDES_
# define step_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_PWM.h"
#include "MW_AnalogIn.h"
#endif                                 /* step_test_COMMON_INCLUDES_ */

#include "step_test_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T ManualSwitch1[5];             /* '<Root>/Manual Switch1' */
  real_T csumrev[4];
  real_T ZeroOrderHold1;               /* '<S2>/Zero-Order Hold1' */
  real_T Sum2;                         /* '<S5>/Sum2' */
  real_T Product;                      /* '<S1>/Product' */
  real_T ManualPWM;                    /* '<Root>/Manual PWM' */
  real_T Add;                          /* '<S1>/Add' */
  real_T Merge;                        /* '<S1>/Merge' */
  real_T Clock;                        /* '<Root>/Clock' */
  real_T LowpassFilter;                /* '<S2>/Lowpass Filter' */
  real_T MovingAverage;                /* '<Root>/Moving Average' */
  uint16_T ZeroOrderHold;              /* '<S2>/Zero-Order Hold' */
} B_step_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dspcodegen_FIRFilter_step_tes_T gobj_0;/* '<S2>/Lowpass Filter' */
  dspcodegen_FIRFilter_step_tes_T gobj_1;/* '<S2>/Lowpass Filter' */
  dsp_simulink_MovingAverage_st_T obj; /* '<Root>/Moving Average' */
  dsp_private_SlidingWindowAver_T gobj_0_n;/* '<Root>/Moving Average' */
  dsp_private_SlidingWindowAver_T gobj_1_i;/* '<Root>/Moving Average' */
  dsp_LowpassFilter_step_test_T obj_e; /* '<S2>/Lowpass Filter' */
  codertarget_arduinobase_in_dm_T obj_g;/* '<S2>/Analog Input' */
  codertarget_arduinobase_in_dm_T obj_i;/* '<S2>/Analog Input1' */
  codertarget_arduinobase_int_d_T obj_n;/* '<S1>/PWM1' */
  real_T DelayInput1_DSTATE;           /* '<S9>/Delay Input1' */
  real_T Integrator_DSTATE;            /* '<S10>/Integrator' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S4>/FromWs' */

  struct {
    void *LoggedData[4];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S2>/Scope4' */

  struct {
    void *LoggedData;
  } Scope_PWORK_o;                     /* '<S5>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S4>/FromWs' */

  int8_T Integrator_PrevResetState;    /* '<S10>/Integrator' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S1>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S1>/If Action Subsystem' */
  boolean_T objisempty;                /* '<S2>/Analog Input' */
  boolean_T objisempty_c;              /* '<S2>/Lowpass Filter' */
  boolean_T isInitialized;             /* '<S2>/Lowpass Filter' */
  boolean_T objisempty_o;              /* '<S2>/Analog Input1' */
  boolean_T objisempty_b;              /* '<S1>/PWM1' */
  boolean_T objisempty_h;              /* '<Root>/Moving Average' */
} DW_step_test_T;

/* Parameters (default storage) */
struct P_step_test_T_ {
  real_T DiscretePIDController_I;      /* Mask Parameter: DiscretePIDController_I
                                        * Referenced by: '<S10>/Integral Gain'
                                        */
  real_T DiscretePIDController_P;      /* Mask Parameter: DiscretePIDController_P
                                        * Referenced by: '<S10>/Proportional Gain'
                                        */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S9>/Delay Input1'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: 0.01
                                        * Referenced by: '<S2>/Analog Input1'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: 0.01
                                        * Referenced by: '<S2>/Analog Input'
                                        */
  real_T Wind_des_Value;               /* Expression: 664.76923076923
                                        * Referenced by: '<Root>/Wind_des'
                                        */
  real_T RunSim_Value;                 /* Expression: 1
                                        * Referenced by: '<S1>/Run Sim'
                                        */
  real_T AutomaticControl_Value;       /* Expression: 0
                                        * Referenced by: '<Root>/Automatic Control'
                                        */
  real_T Enable_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/Enable'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real_T Gain1_Gain;                   /* Expression: 5.6e-4
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: -.61
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 170
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T ManualPWM_Gain;               /* Expression: 11.699248120301
                                        * Referenced by: '<Root>/Manual PWM'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S1>/Switch2'
                                        */
  real_T PWMsaturation_UpperSat;       /* Expression: 40
                                        * Referenced by: '<S1>/PWM saturation'
                                        */
  real_T PWMsaturation_LowerSat;       /* Expression: 0
                                        * Referenced by: '<S1>/PWM saturation'
                                        */
  real_T MotorSwitch_Value;            /* Expression: 0
                                        * Referenced by: '<Root>/Motor Switch'
                                        */
  real_T minPWM_Value;                 /* Expression: 40
                                        * Referenced by: '<S1>/min PWM'
                                        */
  real_T Constant4_Value;              /* Expression: 40
                                        * Referenced by: '<S1>/Constant4'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;/* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_step_test_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_step_test_T step_test_P;

/* Block signals (default storage) */
extern B_step_test_T step_test_B;

/* Block states (default storage) */
extern DW_step_test_T step_test_DW;

/* Model entry point functions */
extern void step_test_initialize(void);
extern void step_test_step(void);
extern void step_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_step_test_T *const step_test_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Cast' : Eliminate redundant data type conversion
 * Block '<S1>/RT' : Eliminated since input and output rates are identical
 * Block '<S1>/RT1' : Eliminated since input and output rates are identical
 * Block '<S1>/RT2' : Eliminated since input and output rates are identical
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'step_test'
 * '<S1>'   : 'step_test/Output'
 * '<S2>'   : 'step_test/Sensor'
 * '<S3>'   : 'step_test/Signal Builder'
 * '<S4>'   : 'step_test/Signal Builder1'
 * '<S5>'   : 'step_test/Subsystem1'
 * '<S6>'   : 'step_test/Output/Compare To Constant'
 * '<S7>'   : 'step_test/Output/If Action Subsystem'
 * '<S8>'   : 'step_test/Output/If Action Subsystem1'
 * '<S9>'   : 'step_test/Subsystem1/Detect Change'
 * '<S10>'  : 'step_test/Subsystem1/Discrete PID Controller'
 */
#endif                                 /* RTW_HEADER_step_test_h_ */
