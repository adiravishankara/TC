/*
 * step_test.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "step_test".
 *
 * Model version              : 1.21
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Tue Aug 28 13:31:25 2018
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
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
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
  real_T csumrev[4];
  real_T ZeroOrderHold1;               /* '<S4>/Zero-Order Hold1' */
  real_T Sum2;                         /* '<S8>/Sum2' */
  real_T Product;                      /* '<S1>/Product' */
  real_T ManualPWM;                    /* '<Root>/Manual PWM' */
  real_T Add;                          /* '<S1>/Add' */
  real_T Merge;                        /* '<S1>/Merge' */
  real_T Clock;                        /* '<Root>/Clock' */
  real_T Sum1;                         /* '<S9>/Sum1' */
  real_T Gain;                         /* '<S9>/Gain' */
  real_T Integrator;                   /* '<S7>/Integrator' */
  real_T ManualSwitch1[7];             /* '<Root>/Manual Switch1' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T Sum1_h;                       /* '<S13>/Sum1' */
  real_T Product1;                     /* '<S7>/Product1' */
  real_T Sum_l;                        /* '<S7>/Sum' */
  real_T Sum_i;                        /* '<S9>/Sum' */
  real_T LowpassFilter;                /* '<S4>/Lowpass Filter' */
  real_T MovingAverage;                /* '<Root>/Moving Average' */
  real_T MathFunction1;                /* '<S13>/Math Function1' */
  real_T Product_d;                    /* '<S8>/Product' */
  real_T PWMsaturation;                /* '<S1>/PWM saturation' */
  real_T Gain1_a;                      /* '<S9>/Gain1' */
  real_T Square_c;                     /* '<S9>/Square' */
  uint16_T ZeroOrderHold;              /* '<S4>/Zero-Order Hold' */
} B_step_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dspcodegen_FIRFilter_step_tes_T gobj_0;/* '<S4>/Lowpass Filter' */
  dspcodegen_FIRFilter_step_tes_T gobj_1;/* '<S4>/Lowpass Filter' */
  dsp_simulink_MovingAverage_st_T obj; /* '<Root>/Moving Average' */
  dsp_private_SlidingWindowAver_T gobj_0_n;/* '<Root>/Moving Average' */
  dsp_private_SlidingWindowAver_T gobj_1_i;/* '<Root>/Moving Average' */
  dsp_LowpassFilter_step_test_T obj_e; /* '<S4>/Lowpass Filter' */
  codertarget_arduinobase_in_dm_T obj_g;/* '<S4>/Analog Input' */
  codertarget_arduinobase_in_dm_T obj_i;/* '<S4>/Analog Input1' */
  codertarget_arduinobase_int_d_T obj_n;/* '<S1>/PWM1' */
  real_T DelayInput1_DSTATE;           /* '<S14>/Delay Input1' */
  real_T Integrator_DSTATE;            /* '<S15>/Integrator' */
  real_T TimeStampA;                   /* '<S7>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S7>/Derivative' */
  real_T TimeStampB;                   /* '<S7>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S7>/Derivative' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S6>/FromWs' */

  struct {
    void *LoggedData[4];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    void *LoggedData;
  } Scope_PWORK_o;                     /* '<S8>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S4>/Scope4' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S6>/FromWs' */

  int8_T Integrator_PrevResetState;    /* '<S15>/Integrator' */
  int8_T If_ActiveSubsystem;           /* '<S1>/If' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S1>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S1>/If Action Subsystem' */
  boolean_T objisempty;                /* '<S4>/Analog Input' */
  boolean_T objisempty_c;              /* '<S4>/Lowpass Filter' */
  boolean_T isInitialized;             /* '<S4>/Lowpass Filter' */
  boolean_T objisempty_o;              /* '<S4>/Analog Input1' */
  boolean_T objisempty_b;              /* '<S1>/PWM1' */
  boolean_T objisempty_h;              /* '<Root>/Moving Average' */
} DW_step_test_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S9>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE;          /* '<S9>/Transfer Fcn1' */
  real_T Integrator_CSTATE;            /* '<S7>/Integrator' */
} X_step_test_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S9>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE;          /* '<S9>/Transfer Fcn1' */
  real_T Integrator_CSTATE;            /* '<S7>/Integrator' */
} XDot_step_test_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE;        /* '<S9>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE;       /* '<S9>/Transfer Fcn1' */
  boolean_T Integrator_CSTATE;         /* '<S7>/Integrator' */
} XDis_step_test_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_step_test_T_ {
  real_T DiscretePIDController_I;      /* Mask Parameter: DiscretePIDController_I
                                        * Referenced by: '<S15>/Integral Gain'
                                        */
  real_T DiscretePIDController_P;      /* Mask Parameter: DiscretePIDController_P
                                        * Referenced by: '<S15>/Proportional Gain'
                                        */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S14>/Delay Input1'
                                        */
  real_T AnalogInput1_SampleTime;      /* Expression: 0.01
                                        * Referenced by: '<S4>/Analog Input1'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: 0.01
                                        * Referenced by: '<S4>/Analog Input'
                                        */
  real_T Wind_des_Value;               /* Expression: 650
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
                                        * Referenced by: '<S15>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S15>/Integrator'
                                        */
  real_T Gain1_Gain;                   /* Expression: 5.6e-4
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: -.61
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 170
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T ManualPWM_Gain;               /* Expression: 0
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
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S9>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S9>/Transfer Fcn'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: .6859
                                        * Referenced by: '<S9>/Gain1'
                                        */
  real_T Constant3_Value;              /* Expression: .2314
                                        * Referenced by: '<S9>/Constant3'
                                        */
  real_T Constant1_Value;              /* Expression: 3
                                        * Referenced by: '<S9>/Constant1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 0.03836
                                        * Referenced by: '<S9>/Gain2'
                                        */
  real_T Constant2_Value;              /* Expression: 0.8882
                                        * Referenced by: '<S9>/Constant2'
                                        */
  real_T Constant_Value_k;             /* Expression: 16.36
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S9>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S9>/Transfer Fcn1'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 1
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T Integrator_IC_j;              /* Expression: 0
                                        * Referenced by: '<S7>/Integrator'
                                        */
  real_T Constant1_Value_i;            /* Expression: 40
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant3_Value_d;            /* Expression: 0.3933
                                        * Referenced by: '<S13>/Constant3'
                                        */
  real_T Gain2_Gain_c;                 /* Expression: 0.03432
                                        * Referenced by: '<S13>/Gain2'
                                        */
  real_T Constant4_Value_p;            /* Expression: 0.005561
                                        * Referenced by: '<S13>/Constant4'
                                        */
  real_T Constant4_Value_g;            /* Expression: 686.2
                                        * Referenced by: '<S9>/Constant4'
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
  X_step_test_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[3];
  real_T odeF[3][3];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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

/* Continuous states (default storage) */
extern X_step_test_T step_test_X;

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
 * Block '<S2>/FromWs' : Unused code path elimination
 * Block '<S3>/FromWs' : Unused code path elimination
 * Block '<S4>/Cast1' : Unused code path elimination
 * Block '<S5>/FromWs' : Unused code path elimination
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
 * '<S2>'   : 'step_test/Pulse'
 * '<S3>'   : 'step_test/STEP_RANGE'
 * '<S4>'   : 'step_test/Sensor'
 * '<S5>'   : 'step_test/Signal Builder2'
 * '<S6>'   : 'step_test/Step'
 * '<S7>'   : 'step_test/Subsystem'
 * '<S8>'   : 'step_test/Subsystem1'
 * '<S9>'   : 'step_test/Subsystem2'
 * '<S10>'  : 'step_test/Output/Compare To Constant'
 * '<S11>'  : 'step_test/Output/If Action Subsystem'
 * '<S12>'  : 'step_test/Output/If Action Subsystem1'
 * '<S13>'  : 'step_test/Subsystem/Subsystem'
 * '<S14>'  : 'step_test/Subsystem1/Detect Change'
 * '<S15>'  : 'step_test/Subsystem1/Discrete PID Controller'
 */
#endif                                 /* RTW_HEADER_step_test_h_ */
