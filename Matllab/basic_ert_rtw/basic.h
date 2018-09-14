/*
 * basic.h
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

#ifndef RTW_HEADER_basic_h_
#define RTW_HEADER_basic_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef basic_COMMON_INCLUDES_
# define basic_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_AnalogIn.h"
#include "MW_PWM.h"
#endif                                 /* basic_COMMON_INCLUDES_ */

#include "basic_types.h"

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

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T e;                            /* '<Root>/Sum' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T DataTypeConversion;           /* '<Root>/Data Type Conversion' */
  real_T TmpRTBAtProduct1Inport1;      /* '<S3>/PWM saturation' */
  real_T TmpRTBAtProduct1Inport2;
  real_T Product1;                     /* '<S3>/Product1' */
  real_T TmpRTBAtAddInport2;           /* '<S3>/min PWM' */
  real_T DataTypeConversion_p;         /* '<S3>/Data Type Conversion' */
  uint16_T RateTransition;             /* '<Root>/Rate Transition' */
  boolean_T Compare;                   /* '<S1>/Compare' */
} B_basic_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_b_T obj; /* '<Root>/Analog Input' */
  codertarget_arduinobase_int_b_T obj_i;/* '<Root>/Analog Input1' */
  codertarget_arduinobase_in_b0_T obj_n;/* '<S3>/PWM1' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T TmpRTBAtProduct1Inport1_Buffer0;/* synthesized block */
  real_T TmpRTBAtProduct1Inport2_Buffer0;/* synthesized block */
  real_T TmpRTBAtAddInport2_Buffer0;   /* synthesized block */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    void *LoggedData;
  } Scope_PWORK_b;                     /* '<S3>/Scope' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK_a;               /* '<S3>/To Workspace' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  boolean_T objisempty;                /* '<S3>/PWM1' */
  boolean_T objisempty_m;              /* '<Root>/Analog Input' */
  boolean_T objisempty_o;              /* '<Root>/Analog Input1' */
} DW_basic_T;

/* Parameters (default storage) */
struct P_basic_T_ {
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T SliderGain_gain;              /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S2>/Slider Gain'
                                        */
  uint16_T CompareToConstant_const_g;  /* Mask Parameter: CompareToConstant_const_g
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: 0.01
                                        * Referenced by: '<Root>/Analog Input1'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: 0.01
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  real_T Constant1_Value;              /* Expression: 600
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T AutomaticControl_Value;       /* Expression: 0
                                        * Referenced by: '<Root>/Automatic Control'
                                        */
  real_T P_Gain;                       /* Expression: 0.05
                                        * Referenced by: '<Root>/P'
                                        */
  real_T st_Gain;                      /* Expression: 0.01
                                        * Referenced by: '<Root>/st'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T I_Gain;                       /* Expression: 0.005
                                        * Referenced by: '<Root>/I'
                                        */
  real_T Constant2_Value;              /* Expression: 6.5
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Enable_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/Enable'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S3>/Switch2'
                                        */
  real_T PWMsaturation_UpperSat;       /* Expression: 40
                                        * Referenced by: '<S3>/PWM saturation'
                                        */
  real_T PWMsaturation_LowerSat;       /* Expression: 0
                                        * Referenced by: '<S3>/PWM saturation'
                                        */
  real_T TmpRTBAtProduct1Inport1_Initial;/* Expression: 0
                                          * Referenced by: synthesized block
                                          */
  real_T TmpRTBAtProduct1Inport2_Initial;/* Expression: 0
                                          * Referenced by: synthesized block
                                          */
  real_T TmpRTBAtAddInport2_InitialCondi;/* Expression: 0
                                          * Referenced by: synthesized block
                                          */
  real_T minPWM_Value;                 /* Expression: 40
                                        * Referenced by: '<S3>/min PWM'
                                        */
  real_T Mainswitch_Value;             /* Expression: 1
                                        * Referenced by: '<Root>/Main switch'
                                        */
  uint32_T Delay_DelayLength;          /* Computed Parameter: Delay_DelayLength
                                        * Referenced by: '<Root>/Delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_basic_T {
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
    uint32_T clockTick2;
    uint32_T clockTickH2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_basic_T basic_P;

/* Block signals (default storage) */
extern B_basic_T basic_B;

/* Block states (default storage) */
extern DW_basic_T basic_DW;

/* External function called from main */
extern void basic_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void basic_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void basic_initialize(void);
extern void basic_step0(void);
extern void basic_step2(void);
extern void basic_terminate(void);

/* Real-time Model object */
extern RT_MODEL_basic_T *const basic_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Rate Transition1' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'basic'
 * '<S1>'   : 'basic/Compare To Constant'
 * '<S2>'   : 'basic/Slider Gain'
 * '<S3>'   : 'basic/Subsystem'
 * '<S4>'   : 'basic/Subsystem/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_basic_h_ */
