/*
 * basic.c
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
#include "basic_dt.h"

/* Block signals (default storage) */
B_basic_T basic_B;

/* Block states (default storage) */
DW_basic_T basic_DW;

/* Real-time model */
RT_MODEL_basic_T basic_M_;
RT_MODEL_basic_T *const basic_M = &basic_M_;

/* Forward declaration for local functions */
static codertarget_arduinobase_in_b0_T *arduino_PWMOutput_arduino_PWMOu
  (codertarget_arduinobase_in_b0_T *obj);
static void SystemProp_matlabCodegenSetAnyP(codertarget_arduinobase_int_b_T *obj,
  boolean_T value);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_b_T *obj);
static void SystemProp_matlabCodegenSetA_b0(codertarget_arduinobase_in_b0_T *obj,
  boolean_T value);
static void matlabCodegenHandle_matlabCo_b0(codertarget_arduinobase_in_b0_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void basic_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(basic_M, 2));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (basic_M->Timing.TaskCounters.TID[1] == 0) {
    basic_M->Timing.RateInteraction.TID1_2 = (basic_M->Timing.TaskCounters.TID[2]
      == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (basic_M->Timing.TaskCounters.TID[2])++;
  if ((basic_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.01s, 0.0s] */
    basic_M->Timing.TaskCounters.TID[2] = 0;
  }
}

static codertarget_arduinobase_in_b0_T *arduino_PWMOutput_arduino_PWMOu
  (codertarget_arduinobase_in_b0_T *obj)
{
  codertarget_arduinobase_in_b0_T *b_obj;

  /* Start for MATLABSystem: '<S3>/PWM1' */
  obj->isInitialized = 0;
  b_obj = obj;
  obj->Hw.AvailablePwmPinNames.f1 = '2';
  obj->Hw.AvailablePwmPinNames.f2 = '3';
  obj->Hw.AvailablePwmPinNames.f3 = '4';
  obj->Hw.AvailablePwmPinNames.f4 = '5';
  obj->Hw.AvailablePwmPinNames.f5 = '6';
  obj->Hw.AvailablePwmPinNames.f6 = '7';
  obj->Hw.AvailablePwmPinNames.f7 = '8';
  obj->Hw.AvailablePwmPinNames.f8 = '9';
  obj->Hw.AvailablePwmPinNames.f9[0] = '1';
  obj->Hw.AvailablePwmPinNames.f9[1] = '0';
  obj->Hw.AvailablePwmPinNames.f10[0] = '1';
  obj->Hw.AvailablePwmPinNames.f10[1] = '1';
  obj->Hw.AvailablePwmPinNames.f11[0] = '1';
  obj->Hw.AvailablePwmPinNames.f11[1] = '2';
  obj->Hw.AvailablePwmPinNames.f12[0] = '1';
  obj->Hw.AvailablePwmPinNames.f12[1] = '3';
  obj->matlabCodegenIsDeleted = false;
  return b_obj;
}

static void SystemProp_matlabCodegenSetAnyP(codertarget_arduinobase_int_b_T *obj,
  boolean_T value)
{
  /* Start for MATLABSystem: '<Root>/Analog Input1' incorporates:
   *  MATLABSystem: '<Root>/Analog Input'
   */
  obj->matlabCodegenIsDeleted = value;
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_b_T *obj)
{
  /* Start for MATLABSystem: '<Root>/Analog Input1' incorporates:
   *  MATLABSystem: '<Root>/Analog Input'
   */
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetAnyP(obj, true);
  }

  /* End of Start for MATLABSystem: '<Root>/Analog Input1' */
}

static void SystemProp_matlabCodegenSetA_b0(codertarget_arduinobase_in_b0_T *obj,
  boolean_T value)
{
  /* Start for MATLABSystem: '<S3>/PWM1' */
  obj->matlabCodegenIsDeleted = value;
}

static void matlabCodegenHandle_matlabCo_b0(codertarget_arduinobase_in_b0_T *obj)
{
  /* Start for MATLABSystem: '<S3>/PWM1' */
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetA_b0(obj, true);
  }

  /* End of Start for MATLABSystem: '<S3>/PWM1' */
}

/* Model step function for TID0 */
void basic_step0(void)                 /* Sample time: [0.0s, 0.0s] */
{
  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<S3>/TmpRTBAtProduct1Inport1' */
  if (basic_M->Timing.RateInteraction.TID1_2) {
    basic_B.TmpRTBAtProduct1Inport1 = basic_DW.TmpRTBAtProduct1Inport1_Buffer0;

    /* RateTransition: '<S3>/TmpRTBAtProduct1Inport2' */
    basic_B.TmpRTBAtProduct1Inport2 = basic_DW.TmpRTBAtProduct1Inport2_Buffer0;
  }

  /* End of RateTransition: '<S3>/TmpRTBAtProduct1Inport1' */

  /* Product: '<S3>/Product1' incorporates:
   *  Clock: '<S3>/Clock'
   *  Constant: '<S4>/Constant'
   *  RelationalOperator: '<S4>/Compare'
   */
  basic_B.Product1 = basic_B.TmpRTBAtProduct1Inport1 *
    basic_B.TmpRTBAtProduct1Inport2 * (real_T)(basic_M->Timing.t[0] >
    basic_P.CompareToConstant_const);

  /* RateTransition: '<S3>/TmpRTBAtAddInport2' */
  if (basic_M->Timing.RateInteraction.TID1_2) {
    basic_B.TmpRTBAtAddInport2 = basic_DW.TmpRTBAtAddInport2_Buffer0;
  }

  /* End of RateTransition: '<S3>/TmpRTBAtAddInport2' */

  /* Sum: '<S3>/Add' */
  basic_B.DataTypeConversion_p = basic_B.Product1 + basic_B.TmpRTBAtAddInport2;

  /* Start for MATLABSystem: '<S3>/PWM1' */
  MW_PWM_SetDutyCycle(basic_DW.obj_n.MW_PWM_HANDLE, basic_B.DataTypeConversion_p);

  /* External mode */
  rtExtModeUploadCheckTrigger(3);
  rtExtModeUpload(1, basic_M->Timing.t[0]);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(basic_M)!=-1) &&
        !((rtmGetTFinal(basic_M)-basic_M->Timing.t[0]) > basic_M->Timing.t[0] *
          (DBL_EPSILON))) {
      rtmSetErrorStatus(basic_M, "Simulation finished");
    }

    if (rtmGetStopRequested(basic_M)) {
      rtmSetErrorStatus(basic_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++basic_M->Timing.clockTick0)) {
    ++basic_M->Timing.clockTickH0;
  }

  basic_M->Timing.t[0] = basic_M->Timing.clockTick0 * basic_M->Timing.stepSize0
    + basic_M->Timing.clockTickH0 * basic_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  basic_M->Timing.clockTick1++;
  if (!basic_M->Timing.clockTick1) {
    basic_M->Timing.clockTickH1++;
  }
}

/* Model step function for TID2 */
void basic_step2(void)                 /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_Sum2;
  real_T rtb_PWMsaturation;
  boolean_T p;
  boolean_T p_0;
  uint16_T rtb_AnalogInput;
  real_T rtb_Switch2;

  /* Start for MATLABSystem: '<Root>/Analog Input' */
  p = false;
  p_0 = true;
  if (!(basic_DW.obj.SampleTime == basic_P.AnalogInput_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    basic_DW.obj.SampleTime = basic_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(basic_DW.obj.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<Root>/Analog Input' */
  MW_AnalogInSingle_ReadResult(basic_DW.obj.MW_ANALOGIN_HANDLE, &rtb_AnalogInput,
    3);

  /* RateTransition: '<Root>/Rate Transition' */
  basic_B.RateTransition = rtb_AnalogInput;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  basic_B.e = basic_P.Constant1_Value - (real_T)basic_B.RateTransition;

  /* Product: '<Root>/Product' incorporates:
   *  Constant: '<Root>/Automatic Control'
   */
  rtb_Switch2 = basic_P.AutomaticControl_Value * basic_B.e;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Delay: '<Root>/Delay'
   *  Gain: '<Root>/st'
   */
  rtb_Sum2 = basic_P.st_Gain * rtb_Switch2 + basic_DW.Delay_DSTATE;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Gain: '<Root>/I'
   *  Gain: '<Root>/P'
   *  Sum: '<Root>/Sum3'
   */
  basic_B.Sum1 = (basic_P.P_Gain * rtb_Switch2 + basic_P.I_Gain * rtb_Sum2) +
    basic_P.Constant2_Value;

  /* Switch: '<S3>/Switch2' incorporates:
   *  Constant: '<Root>/Automatic Control'
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Enable'
   *  Gain: '<S2>/Slider Gain'
   *  Product: '<S3>/Product'
   */
  if (basic_P.AutomaticControl_Value > basic_P.Switch2_Threshold) {
    rtb_Switch2 = basic_P.Enable_Value * basic_B.Sum1;
  } else {
    rtb_Switch2 = basic_P.SliderGain_gain * basic_P.Constant_Value;
  }

  /* End of Switch: '<S3>/Switch2' */

  /* Saturate: '<S3>/PWM saturation' */
  if (rtb_Switch2 > basic_P.PWMsaturation_UpperSat) {
    rtb_PWMsaturation = basic_P.PWMsaturation_UpperSat;
  } else if (rtb_Switch2 < basic_P.PWMsaturation_LowerSat) {
    rtb_PWMsaturation = basic_P.PWMsaturation_LowerSat;
  } else {
    rtb_PWMsaturation = rtb_Switch2;
  }

  /* End of Saturate: '<S3>/PWM saturation' */

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  basic_B.DataTypeConversion = basic_B.e;

  /* Start for MATLABSystem: '<Root>/Analog Input1' */
  p = false;
  p_0 = true;
  if (!(basic_DW.obj_i.SampleTime == basic_P.AnalogInput1_SampleTime)) {
    p_0 = false;
  }

  if (p_0) {
    p = true;
  }

  if (!p) {
    basic_DW.obj_i.SampleTime = basic_P.AnalogInput1_SampleTime;
  }

  MW_AnalogIn_Start(basic_DW.obj_i.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(basic_DW.obj_i.MW_ANALOGIN_HANDLE,
    &rtb_AnalogInput, 3);

  /* End of Start for MATLABSystem: '<Root>/Analog Input1' */

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   *  MATLABSystem: '<Root>/Analog Input1'
   */
  basic_B.Compare = (rtb_AnalogInput >= basic_P.CompareToConstant_const_g);

  /* Update for Delay: '<Root>/Delay' */
  basic_DW.Delay_DSTATE = rtb_Sum2;

  /* Update for RateTransition: '<S3>/TmpRTBAtProduct1Inport1' */
  basic_DW.TmpRTBAtProduct1Inport1_Buffer0 = rtb_PWMsaturation;

  /* Update for RateTransition: '<S3>/TmpRTBAtProduct1Inport2' incorporates:
   *  Constant: '<Root>/Main switch'
   */
  basic_DW.TmpRTBAtProduct1Inport2_Buffer0 = basic_P.Mainswitch_Value;

  /* Update for RateTransition: '<S3>/TmpRTBAtAddInport2' incorporates:
   *  Constant: '<S3>/min PWM'
   */
  basic_DW.TmpRTBAtAddInport2_Buffer0 = basic_P.minPWM_Value;
  rtExtModeUpload(2, (((basic_M->Timing.clockTick2+basic_M->Timing.clockTickH2*
                        4294967296.0)) * 0.01));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.01, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  basic_M->Timing.clockTick2++;
  if (!basic_M->Timing.clockTick2) {
    basic_M->Timing.clockTickH2++;
  }
}

/* Model initialize function */
void basic_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)basic_M, 0,
                sizeof(RT_MODEL_basic_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&basic_M->solverInfo, &basic_M->Timing.simTimeStep);
    rtsiSetTPtr(&basic_M->solverInfo, &rtmGetTPtr(basic_M));
    rtsiSetStepSizePtr(&basic_M->solverInfo, &basic_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&basic_M->solverInfo, (&rtmGetErrorStatus(basic_M)));
    rtsiSetRTModelPtr(&basic_M->solverInfo, basic_M);
  }

  rtsiSetSimTimeStep(&basic_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&basic_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(basic_M, &basic_M->Timing.tArray[0]);
  rtmSetTFinal(basic_M, -1);
  basic_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  basic_M->Sizes.checksums[0] = (2212087965U);
  basic_M->Sizes.checksums[1] = (1254133167U);
  basic_M->Sizes.checksums[2] = (3036995628U);
  basic_M->Sizes.checksums[3] = (3931242401U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    basic_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(basic_M->extModeInfo,
      &basic_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(basic_M->extModeInfo, basic_M->Sizes.checksums);
    rteiSetTPtr(basic_M->extModeInfo, rtmGetTPtr(basic_M));
  }

  /* block I/O */
  (void) memset(((void *) &basic_B), 0,
                sizeof(B_basic_T));

  /* states (dwork) */
  (void) memset((void *)&basic_DW, 0,
                sizeof(DW_basic_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    basic_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_int_b_T *obj;
    MW_AnalogIn_TriggerSource_Type trigger_val;
    codertarget_arduinobase_in_b0_T *obj_0;

    /* Start for MATLABSystem: '<Root>/Analog Input' */
    basic_DW.obj.matlabCodegenIsDeleted = true;
    obj = &basic_DW.obj;
    basic_DW.obj.isInitialized = 0;
    obj->Hw.AvailablePwmPinNames.f1 = '2';
    obj->Hw.AvailablePwmPinNames.f2 = '3';
    obj->Hw.AvailablePwmPinNames.f3 = '4';
    obj->Hw.AvailablePwmPinNames.f4 = '5';
    obj->Hw.AvailablePwmPinNames.f5 = '6';
    obj->Hw.AvailablePwmPinNames.f6 = '7';
    obj->Hw.AvailablePwmPinNames.f7 = '8';
    obj->Hw.AvailablePwmPinNames.f8 = '9';
    obj->Hw.AvailablePwmPinNames.f9[0] = '1';
    obj->Hw.AvailablePwmPinNames.f9[1] = '0';
    obj->Hw.AvailablePwmPinNames.f10[0] = '1';
    obj->Hw.AvailablePwmPinNames.f10[1] = '1';
    obj->Hw.AvailablePwmPinNames.f11[0] = '1';
    obj->Hw.AvailablePwmPinNames.f11[1] = '2';
    obj->Hw.AvailablePwmPinNames.f12[0] = '1';
    obj->Hw.AvailablePwmPinNames.f12[1] = '3';
    basic_DW.obj.matlabCodegenIsDeleted = false;
    basic_DW.objisempty_m = true;
    basic_DW.obj.SampleTime = basic_P.AnalogInput_SampleTime;
    obj = &basic_DW.obj;
    basic_DW.obj.isSetupComplete = false;
    basic_DW.obj.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(2U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(basic_DW.obj.MW_ANALOGIN_HANDLE, trigger_val,
      0U);
    basic_DW.obj.isSetupComplete = true;

    /* Start for RateTransition: '<S3>/TmpRTBAtProduct1Inport1' */
    basic_B.TmpRTBAtProduct1Inport1 = basic_P.TmpRTBAtProduct1Inport1_Initial;

    /* Start for RateTransition: '<S3>/TmpRTBAtProduct1Inport2' */
    basic_B.TmpRTBAtProduct1Inport2 = basic_P.TmpRTBAtProduct1Inport2_Initial;

    /* Start for RateTransition: '<S3>/TmpRTBAtAddInport2' */
    basic_B.TmpRTBAtAddInport2 = basic_P.TmpRTBAtAddInport2_InitialCondi;

    /* Start for MATLABSystem: '<S3>/PWM1' */
    basic_DW.obj_n.matlabCodegenIsDeleted = true;
    arduino_PWMOutput_arduino_PWMOu(&basic_DW.obj_n);
    basic_DW.objisempty = true;
    obj_0 = &basic_DW.obj_n;
    basic_DW.obj_n.isSetupComplete = false;
    basic_DW.obj_n.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(12U, 0.0, 0.0);
    MW_PWM_Start(basic_DW.obj_n.MW_PWM_HANDLE);
    basic_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Analog Input1' */
    basic_DW.obj_i.matlabCodegenIsDeleted = true;
    obj = &basic_DW.obj_i;
    basic_DW.obj_i.isInitialized = 0;
    obj->Hw.AvailablePwmPinNames.f1 = '2';
    obj->Hw.AvailablePwmPinNames.f2 = '3';
    obj->Hw.AvailablePwmPinNames.f3 = '4';
    obj->Hw.AvailablePwmPinNames.f4 = '5';
    obj->Hw.AvailablePwmPinNames.f5 = '6';
    obj->Hw.AvailablePwmPinNames.f6 = '7';
    obj->Hw.AvailablePwmPinNames.f7 = '8';
    obj->Hw.AvailablePwmPinNames.f8 = '9';
    obj->Hw.AvailablePwmPinNames.f9[0] = '1';
    obj->Hw.AvailablePwmPinNames.f9[1] = '0';
    obj->Hw.AvailablePwmPinNames.f10[0] = '1';
    obj->Hw.AvailablePwmPinNames.f10[1] = '1';
    obj->Hw.AvailablePwmPinNames.f11[0] = '1';
    obj->Hw.AvailablePwmPinNames.f11[1] = '2';
    obj->Hw.AvailablePwmPinNames.f12[0] = '1';
    obj->Hw.AvailablePwmPinNames.f12[1] = '3';
    basic_DW.obj_i.matlabCodegenIsDeleted = false;
    basic_DW.objisempty_o = true;
    basic_DW.obj_i.SampleTime = basic_P.AnalogInput1_SampleTime;
    obj = &basic_DW.obj_i;
    basic_DW.obj_i.isSetupComplete = false;
    basic_DW.obj_i.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(3U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(basic_DW.obj_i.MW_ANALOGIN_HANDLE, trigger_val,
      0U);
    basic_DW.obj_i.isSetupComplete = true;
  }

  /* InitializeConditions for Delay: '<Root>/Delay' */
  basic_DW.Delay_DSTATE = basic_P.Delay_InitialCondition;

  /* InitializeConditions for RateTransition: '<S3>/TmpRTBAtProduct1Inport1' */
  basic_DW.TmpRTBAtProduct1Inport1_Buffer0 =
    basic_P.TmpRTBAtProduct1Inport1_Initial;

  /* InitializeConditions for RateTransition: '<S3>/TmpRTBAtProduct1Inport2' */
  basic_DW.TmpRTBAtProduct1Inport2_Buffer0 =
    basic_P.TmpRTBAtProduct1Inport2_Initial;

  /* InitializeConditions for RateTransition: '<S3>/TmpRTBAtAddInport2' */
  basic_DW.TmpRTBAtAddInport2_Buffer0 = basic_P.TmpRTBAtAddInport2_InitialCondi;
}

/* Model terminate function */
void basic_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Analog Input' */
  matlabCodegenHandle_matlabCodeg(&basic_DW.obj);

  /* Terminate for MATLABSystem: '<S3>/PWM1' */
  matlabCodegenHandle_matlabCo_b0(&basic_DW.obj_n);

  /* Terminate for MATLABSystem: '<Root>/Analog Input1' */
  matlabCodegenHandle_matlabCodeg(&basic_DW.obj_i);
}
