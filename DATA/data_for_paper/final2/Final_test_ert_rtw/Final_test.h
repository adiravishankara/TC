/*
 * Final_test.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Final_test".
 *
 * Model version              : 1.49
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Wed Sep 12 11:44:58 2018
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Final_test_h_
#define RTW_HEADER_Final_test_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef Final_test_COMMON_INCLUDES_
# define Final_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_PWM.h"
#include "MW_AnalogIn.h"
#endif                                 /* Final_test_COMMON_INCLUDES_ */

#include "Final_test_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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
  real_T csumrev[9];
  real_T P_bar[4];
  real_T a[4];
  real_T xh_bar[2];
  real_T K[2];
  real_T Constant2;                    /* '<Root>/Constant2' */
  real_T e;                            /* '<S7>/Sum' */
  real_T TransferFcn1;                 /* '<S3>/Transfer Fcn1' */
  real_T Sum;                          /* '<S20>/Sum' */
  real_T Saturation;                   /* '<S7>/Saturation' */
  real_T Product;                      /* '<S5>/Product' */
  real_T Sum2;                         /* '<S5>/Sum2' */
  real_T Product_m;                    /* '<S2>/Product' */
  real_T ManualPWM;                    /* '<Root>/Manual PWM' */
  real_T Add;                          /* '<S2>/Add' */
  real_T Merge;                        /* '<S2>/Merge' */
  real_T Integrator1;                  /* '<S8>/Integrator1' */
  real_T Sum_k;                        /* '<S6>/Sum' */
  real_T Clock;                        /* '<Root>/Clock' */
  real_T ManualSwitch1[7];             /* '<Root>/Manual Switch1' */
  real_T Integrator;                   /* '<S8>/Integrator' */
  real_T Gain2;                        /* '<S8>/Gain2' */
  real_T Sum_kf;                       /* '<S8>/Sum' */
  real_T Sum_l;                        /* '<S3>/Sum' */
  real_T xest;                         /* '<S1>/MATLAB Function' */
  real_T MovingAverage1;               /* '<Root>/Moving Average1' */
  real_T MovingAverage;                /* '<Root>/Moving Average' */
  real_T cumRevIndex;
  real_T csum;
  real_T z;
} B_Final_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_private_SlidingWindowAv_f_T gobj_0;/* '<Root>/Moving Average1' */
  dsp_private_SlidingWindowAv_f_T gobj_1;/* '<Root>/Moving Average1' */
  dsp_simulink_MovingAverage_Fi_T obj; /* '<Root>/Moving Average' */
  dsp_simulink_MovingAverage_f_T obj_n;/* '<Root>/Moving Average1' */
  dsp_private_SlidingWindowAver_T gobj_0_n;/* '<Root>/Moving Average' */
  dsp_private_SlidingWindowAver_T gobj_1_i;/* '<Root>/Moving Average' */
  codertarget_arduinobase_in_fd_T obj_g;/* '<S3>/Analog Input' */
  codertarget_arduinobase_int_f_T obj_nv;/* '<S2>/PWM1' */
  real_T DelayInput1_DSTATE;           /* '<S16>/Delay Input1' */
  real_T Integrator_DSTATE;            /* '<S20>/Integrator' */
  real_T DelayInput1_DSTATE_m;         /* '<S14>/Delay Input1' */
  real_T Integrator_DSTATE_g;          /* '<S15>/Integrator' */
  real_T Memory_PreviousInput;         /* '<S1>/Memory' */
  real_T P[4];                         /* '<S1>/MATLAB Function' */
  real_T xh[2];                        /* '<S1>/MATLAB Function' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } FromWs_PWORK;                      /* '<S4>/FromWs' */

  struct {
    void *LoggedData;
  } ToWorkspace_PWORK;                 /* '<Root>/To Workspace' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S5>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_f;                     /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_h;                     /* '<S7>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_g;                    /* '<S3>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_a;                     /* '<S2>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    int_T PrevIndex;
  } FromWs_IWORK;                      /* '<S4>/FromWs' */

  int8_T Integrator_PrevResetState;    /* '<S20>/Integrator' */
  int8_T Integrator_PrevResetState_k;  /* '<S15>/Integrator' */
  int8_T If_ActiveSubsystem;           /* '<S2>/If' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S2>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S2>/If Action Subsystem' */
  boolean_T objisempty;                /* '<S3>/Analog Input' */
  boolean_T objisempty_b;              /* '<S2>/PWM1' */
  boolean_T objisempty_d;              /* '<Root>/Moving Average1' */
  boolean_T objisempty_h;              /* '<Root>/Moving Average' */
} DW_Final_test_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<S3>/Transfer Fcn1' */
  real_T Integrator1_CSTATE;           /* '<S8>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S8>/Integrator' */
} X_Final_test_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<S3>/Transfer Fcn1' */
  real_T Integrator1_CSTATE;           /* '<S8>/Integrator1' */
  real_T Integrator_CSTATE;            /* '<S8>/Integrator' */
} XDot_Final_test_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn1_CSTATE;       /* '<S3>/Transfer Fcn1' */
  boolean_T Integrator1_CSTATE;        /* '<S8>/Integrator1' */
  boolean_T Integrator_CSTATE;         /* '<S8>/Integrator' */
} XDis_Final_test_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_Final_test_T_ {
  real_T DiscretePIDController_I;      /* Mask Parameter: DiscretePIDController_I
                                        * Referenced by: '<S15>/Integral Gain'
                                        */
  real_T PIDController3_I;             /* Mask Parameter: PIDController3_I
                                        * Referenced by: '<S20>/Integral Gain'
                                        */
  real_T PIDController3_P;             /* Mask Parameter: PIDController3_P
                                        * Referenced by: '<S20>/Proportional Gain'
                                        */
  real_T DiscretePIDController_P;      /* Mask Parameter: DiscretePIDController_P
                                        * Referenced by: '<S15>/Proportional Gain'
                                        */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S16>/Delay Input1'
                                        */
  real_T DetectChange_vinit_c;         /* Mask Parameter: DetectChange_vinit_c
                                        * Referenced by: '<S14>/Delay Input1'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.8
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: 0.01
                                        * Referenced by: '<S3>/Analog Input'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  real_T Constant2_Value;              /* Expression: 2.7456647398844
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S3>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S3>/Transfer Fcn1'
                                        */
  real_T RunSim_Value;                 /* Expression: 1
                                        * Referenced by: '<S2>/Run Sim'
                                        */
  real_T AutomaticControl_Value;       /* Expression: 0
                                        * Referenced by: '<Root>/Automatic Control'
                                        */
  real_T Enable_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/Enable'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S20>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S20>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 40
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Wind_des_Value;               /* Expression: 650
                                        * Referenced by: '<Root>/Wind_des'
                                        */
  real_T Integrator_gainval_l;         /* Computed Parameter: Integrator_gainval_l
                                        * Referenced by: '<S15>/Integrator'
                                        */
  real_T Integrator_IC_g;              /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S15>/Integrator'
                                        */
  real_T Gain1_Gain;                   /* Expression: 5.6e-4
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Gain_Gain_g;                  /* Expression: -.61
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Constant_Value;               /* Expression: 170
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T ManualPWM_Gain;               /* Expression: 5.0990117390951
                                        * Referenced by: '<Root>/Manual PWM'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<S2>/Switch2'
                                        */
  real_T PWMsaturation_UpperSat;       /* Expression: 40
                                        * Referenced by: '<S2>/PWM saturation'
                                        */
  real_T PWMsaturation_LowerSat;       /* Expression: 0
                                        * Referenced by: '<S2>/PWM saturation'
                                        */
  real_T MotorSwitch_Value;            /* Expression: 0
                                        * Referenced by: '<Root>/Motor Switch'
                                        */
  real_T minPWM_Value;                 /* Expression: 40
                                        * Referenced by: '<S2>/min PWM'
                                        */
  real_T Constant4_Value;              /* Expression: 40
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S8>/Integrator1'
                                        */
  real_T Constant_Value_n;             /* Expression: 6.146
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 4.701e-15
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 0.0731
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T a_Value;                      /* Expression: 0.3933
                                        * Referenced by: '<S10>/a'
                                        */
  real_T b_Gain;                       /* Expression: 0.03432
                                        * Referenced by: '<S10>/b'
                                        */
  real_T c_Value;                      /* Expression: 0.005561
                                        * Referenced by: '<S10>/c'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: 4
                                        * Referenced by: '<S8>/Gain1'
                                        */
  real_T Integrator_IC_e;              /* Expression: 0
                                        * Referenced by: '<S8>/Integrator'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 3
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T a_Value_d;                    /* Expression: .99
                                        * Referenced by: '<S21>/a'
                                        */
  real_T b_Gain_n;                     /* Expression: .003
                                        * Referenced by: '<S21>/b'
                                        */
  real_T c_Value_e;                    /* Expression: .057
                                        * Referenced by: '<S21>/c'
                                        */
  real_T Gain2_Gain;                   /* Expression: 4
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real_T Constant_Value_p;             /* Expression: 485.3342
                                        * Referenced by: '<S3>/Constant'
                                        */
  uint8_T ManualSwitch_CurrentSetting; /* Computed Parameter: ManualSwitch_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch'
                                        */
  uint8_T ManualSwitch3_CurrentSetting;/* Computed Parameter: ManualSwitch3_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch3'
                                        */
  uint8_T ManualSwitch2_CurrentSetting;/* Computed Parameter: ManualSwitch2_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch2'
                                        */
  uint8_T ManualSwitch1_CurrentSetting;/* Computed Parameter: ManualSwitch1_CurrentSetting
                                        * Referenced by: '<Root>/Manual Switch1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Final_test_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_Final_test_T *contStates;
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
extern P_Final_test_T Final_test_P;

/* Block signals (default storage) */
extern B_Final_test_T Final_test_B;

/* Continuous states (default storage) */
extern X_Final_test_T Final_test_X;

/* Block states (default storage) */
extern DW_Final_test_T Final_test_DW;

/* Model entry point functions */
extern void Final_test_initialize(void);
extern void Final_test_step(void);
extern void Final_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Final_test_T *const Final_test_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S6>/Power' : Unused code path elimination
 * Block '<S6>/a' : Unused code path elimination
 * Block '<S6>/b' : Unused code path elimination
 * Block '<S17>/Integral Gain' : Unused code path elimination
 * Block '<S17>/Integrator' : Unused code path elimination
 * Block '<S17>/Proportional Gain' : Unused code path elimination
 * Block '<S17>/Sum' : Unused code path elimination
 * Block '<S18>/Derivative Gain' : Unused code path elimination
 * Block '<S18>/Filter' : Unused code path elimination
 * Block '<S18>/Filter Coefficient' : Unused code path elimination
 * Block '<S18>/Integral Gain' : Unused code path elimination
 * Block '<S18>/Integrator' : Unused code path elimination
 * Block '<S18>/Proportional Gain' : Unused code path elimination
 * Block '<S18>/Sum' : Unused code path elimination
 * Block '<S18>/SumD' : Unused code path elimination
 * Block '<S19>/Derivative Gain' : Unused code path elimination
 * Block '<S19>/Filter' : Unused code path elimination
 * Block '<S19>/Filter Coefficient' : Unused code path elimination
 * Block '<S19>/Integral Gain' : Unused code path elimination
 * Block '<S19>/Integrator' : Unused code path elimination
 * Block '<S19>/Proportional Gain' : Unused code path elimination
 * Block '<S19>/Sum' : Unused code path elimination
 * Block '<S19>/SumD' : Unused code path elimination
 * Block '<Root>/Cast' : Eliminate redundant data type conversion
 * Block '<S2>/RT' : Eliminated since input and output rates are identical
 * Block '<S2>/RT1' : Eliminated since input and output rates are identical
 * Block '<S2>/RT2' : Eliminated since input and output rates are identical
 * Block '<S3>/Zero-Order Hold1' : Eliminated since input and output rates are identical
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
 * '<Root>' : 'Final_test'
 * '<S1>'   : 'Final_test/Kalman Filter'
 * '<S2>'   : 'Final_test/Output'
 * '<S3>'   : 'Final_test/Sensor'
 * '<S4>'   : 'Final_test/Step2'
 * '<S5>'   : 'Final_test/Subsystem1'
 * '<S6>'   : 'Final_test/Subsystem2'
 * '<S7>'   : 'Final_test/Subsystem3'
 * '<S8>'   : 'Final_test/Thrust Model'
 * '<S9>'   : 'Final_test/Kalman Filter/MATLAB Function'
 * '<S10>'  : 'Final_test/Kalman Filter/Subsystem1'
 * '<S11>'  : 'Final_test/Output/Compare To Constant'
 * '<S12>'  : 'Final_test/Output/If Action Subsystem'
 * '<S13>'  : 'Final_test/Output/If Action Subsystem1'
 * '<S14>'  : 'Final_test/Subsystem1/Detect Change'
 * '<S15>'  : 'Final_test/Subsystem1/Discrete PID Controller'
 * '<S16>'  : 'Final_test/Subsystem3/Detect Change'
 * '<S17>'  : 'Final_test/Subsystem3/PID Controller'
 * '<S18>'  : 'Final_test/Subsystem3/PID Controller1'
 * '<S19>'  : 'Final_test/Subsystem3/PID Controller2'
 * '<S20>'  : 'Final_test/Subsystem3/PID Controller3'
 * '<S21>'  : 'Final_test/Thrust Model/Subsystem'
 */
#endif                                 /* RTW_HEADER_Final_test_h_ */
