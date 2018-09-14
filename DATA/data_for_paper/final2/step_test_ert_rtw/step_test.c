/*
 * step_test.c
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

#include "step_test.h"
#include "step_test_private.h"
#include "step_test_dt.h"

/* Block signals (default storage) */
B_step_test_T step_test_B;

/* Continuous states */
X_step_test_T step_test_X;

/* Block states (default storage) */
DW_step_test_T step_test_DW;

/* Real-time model */
RT_MODEL_step_test_T step_test_M_;
RT_MODEL_step_test_T *const step_test_M = &step_test_M_;

/* Forward declaration for local functions */
static codertarget_arduinobase_int_d_T *arduino_PWMOutput_arduino_PWMOu
  (codertarget_arduinobase_int_d_T *obj);
static void SystemProp_matlabCodegenSetA_dm(codertarget_arduinobase_in_dm_T *obj,
  boolean_T value);
static void matlabCodegenHandle_matlabCo_dm(codertarget_arduinobase_in_dm_T *obj);
static void SystemProp_matlabCodegenSe_dms4(dsp_LowpassFilter_step_test_T *obj,
  boolean_T value);
static void step_test_SystemCore_release_d(dspcodegen_FIRFilter_step_tes_T *obj);
static void step_LPHPFilterBase_releaseImpl(dsp_LowpassFilter_step_test_T *obj);
static void step__SystemCore_releaseWrapper(dsp_LowpassFilter_step_test_T *obj);
static void step_test_SystemCore_release_dm(dsp_LowpassFilter_step_test_T *obj);
static void step_tes_SystemCore_delete_dms4(dsp_LowpassFilter_step_test_T *obj);
static void matlabCodegenHandle_matlab_dms4(dsp_LowpassFilter_step_test_T *obj);
static void SystemProp_matlabCodegenSet_dms(dspcodegen_FIRFilter_step_tes_T *obj,
  boolean_T value);
static void step_test_SystemCore_delete_dms(dspcodegen_FIRFilter_step_tes_T *obj);
static void matlabCodegenHandle_matlabC_dms(dspcodegen_FIRFilter_step_tes_T *obj);
static void SystemProp_matlabCodegenSetAnyP(dsp_simulink_MovingAverage_st_T *obj,
  boolean_T value);
static void step_test_SystemCore_release(dsp_simulink_MovingAverage_st_T *obj);
static void step_test_SystemCore_delete(dsp_simulink_MovingAverage_st_T *obj);
static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage_st_T *obj);
static void SystemProp_matlabCodegenSetAn_d(codertarget_arduinobase_int_d_T *obj,
  boolean_T value);
static void matlabCodegenHandle_matlabCod_d(codertarget_arduinobase_int_d_T *obj);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  step_test_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  step_test_step();
  step_test_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  step_test_step();
  step_test_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

static codertarget_arduinobase_int_d_T *arduino_PWMOutput_arduino_PWMOu
  (codertarget_arduinobase_int_d_T *obj)
{
  codertarget_arduinobase_int_d_T *b_obj;

  /* Start for MATLABSystem: '<S1>/PWM1' */
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

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static void SystemProp_matlabCodegenSetA_dm(codertarget_arduinobase_in_dm_T *obj,
  boolean_T value)
{
  /* Start for MATLABSystem: '<S4>/Analog Input1' incorporates:
   *  MATLABSystem: '<S4>/Analog Input'
   */
  obj->matlabCodegenIsDeleted = value;
}

static void matlabCodegenHandle_matlabCo_dm(codertarget_arduinobase_in_dm_T *obj)
{
  /* Start for MATLABSystem: '<S4>/Analog Input1' incorporates:
   *  MATLABSystem: '<S4>/Analog Input'
   */
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetA_dm(obj, true);
  }

  /* End of Start for MATLABSystem: '<S4>/Analog Input1' */
}

static void SystemProp_matlabCodegenSe_dms4(dsp_LowpassFilter_step_test_T *obj,
  boolean_T value)
{
  /* Start for MATLABSystem: '<S4>/Lowpass Filter' */
  obj->matlabCodegenIsDeleted = value;
}

static void step_test_SystemCore_release_d(dspcodegen_FIRFilter_step_tes_T *obj)
{
  /* Start for MATLABSystem: '<S4>/Lowpass Filter' */
  if (obj->isInitialized == 1) {
    obj->isInitialized = 2;
  }

  /* End of Start for MATLABSystem: '<S4>/Lowpass Filter' */
}

static void step_LPHPFilterBase_releaseImpl(dsp_LowpassFilter_step_test_T *obj)
{
  /* Start for MATLABSystem: '<S4>/Lowpass Filter' */
  step_test_SystemCore_release_d(obj->FilterObj);
  obj->NumChannels = -1;
}

static void step__SystemCore_releaseWrapper(dsp_LowpassFilter_step_test_T *obj)
{
  /* Start for MATLABSystem: '<S4>/Lowpass Filter' */
  if (obj->isSetupComplete) {
    step_LPHPFilterBase_releaseImpl(obj);
  }

  /* End of Start for MATLABSystem: '<S4>/Lowpass Filter' */
}

static void step_test_SystemCore_release_dm(dsp_LowpassFilter_step_test_T *obj)
{
  /* Start for MATLABSystem: '<S4>/Lowpass Filter' */
  if (obj->isInitialized == 1) {
    step__SystemCore_releaseWrapper(obj);
  }

  /* End of Start for MATLABSystem: '<S4>/Lowpass Filter' */
}

static void step_tes_SystemCore_delete_dms4(dsp_LowpassFilter_step_test_T *obj)
{
  /* Start for MATLABSystem: '<S4>/Lowpass Filter' */
  step_test_SystemCore_release_dm(obj);
}

static void matlabCodegenHandle_matlab_dms4(dsp_LowpassFilter_step_test_T *obj)
{
  /* Start for MATLABSystem: '<S4>/Lowpass Filter' */
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSe_dms4(obj, true);
    step_tes_SystemCore_delete_dms4(obj);
  }

  /* End of Start for MATLABSystem: '<S4>/Lowpass Filter' */
}

static void SystemProp_matlabCodegenSet_dms(dspcodegen_FIRFilter_step_tes_T *obj,
  boolean_T value)
{
  /* Start for MATLABSystem: '<S4>/Lowpass Filter' */
  obj->matlabCodegenIsDeleted = value;
}

static void step_test_SystemCore_delete_dms(dspcodegen_FIRFilter_step_tes_T *obj)
{
  /* Start for MATLABSystem: '<S4>/Lowpass Filter' */
  step_test_SystemCore_release_d(obj);
}

static void matlabCodegenHandle_matlabC_dms(dspcodegen_FIRFilter_step_tes_T *obj)
{
  /* Start for MATLABSystem: '<S4>/Lowpass Filter' */
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSet_dms(obj, true);
    step_test_SystemCore_delete_dms(obj);
  }

  /* End of Start for MATLABSystem: '<S4>/Lowpass Filter' */
}

static void SystemProp_matlabCodegenSetAnyP(dsp_simulink_MovingAverage_st_T *obj,
  boolean_T value)
{
  /* Start for MATLABSystem: '<Root>/Moving Average' */
  obj->matlabCodegenIsDeleted = value;
}

static void step_test_SystemCore_release(dsp_simulink_MovingAverage_st_T *obj)
{
  dsp_private_SlidingWindowAver_T *obj_0;

  /* Start for MATLABSystem: '<Root>/Moving Average' */
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }

  /* End of Start for MATLABSystem: '<Root>/Moving Average' */
}

static void step_test_SystemCore_delete(dsp_simulink_MovingAverage_st_T *obj)
{
  /* Start for MATLABSystem: '<Root>/Moving Average' */
  step_test_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage_st_T *obj)
{
  /* Start for MATLABSystem: '<Root>/Moving Average' */
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetAnyP(obj, true);
    step_test_SystemCore_delete(obj);
  }

  /* End of Start for MATLABSystem: '<Root>/Moving Average' */
}

static void SystemProp_matlabCodegenSetAn_d(codertarget_arduinobase_int_d_T *obj,
  boolean_T value)
{
  /* Start for MATLABSystem: '<S1>/PWM1' */
  obj->matlabCodegenIsDeleted = value;
}

static void matlabCodegenHandle_matlabCod_d(codertarget_arduinobase_int_d_T *obj)
{
  /* Start for MATLABSystem: '<S1>/PWM1' */
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetAn_d(obj, true);
  }

  /* End of Start for MATLABSystem: '<S1>/PWM1' */
}

/* Model step function */
void step_test_step(void)
{
  /* local block i/o variables */
  real_T rtb_FromWs;
  real_T rtb_IntegralGain;
  boolean_T rtb_FixPtRelationalOperator;
  if (rtmIsMajorTimeStep(step_test_M)) {
    /* set solver stop time */
    if (!(step_test_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&step_test_M->solverInfo,
                            ((step_test_M->Timing.clockTickH0 + 1) *
        step_test_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&step_test_M->solverInfo,
                            ((step_test_M->Timing.clockTick0 + 1) *
        step_test_M->Timing.stepSize0 + step_test_M->Timing.clockTickH0 *
        step_test_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(step_test_M)) {
    step_test_M->Timing.t[0] = rtsiGetT(&step_test_M->solverInfo);
  }

  {
    real_T *lastU;
    uint16_T rtb_AnalogInput_0;
    boolean_T p;
    boolean_T p_0;
    dsp_FIRFilter_0_step_test_T *obj;
    int32_T j;

    /* Reset subsysRan breadcrumbs */
    srClearBC(step_test_DW.IfActionSubsystem_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(step_test_DW.IfActionSubsystem1_SubsysRanBC);
    if (rtmIsMajorTimeStep(step_test_M)) {
      /* Start for MATLABSystem: '<S4>/Analog Input' */
      p = false;
      p_0 = true;
      if (!(step_test_DW.obj_g.SampleTime == step_test_P.AnalogInput_SampleTime))
      {
        p_0 = false;
      }

      if (p_0) {
        p = true;
      }

      if (!p) {
        step_test_DW.obj_g.SampleTime = step_test_P.AnalogInput_SampleTime;
      }

      MW_AnalogIn_Start(step_test_DW.obj_g.MW_ANALOGIN_HANDLE);
      MW_AnalogInSingle_ReadResult(step_test_DW.obj_g.MW_ANALOGIN_HANDLE,
        &rtb_AnalogInput_0, 3);

      /* End of Start for MATLABSystem: '<S4>/Analog Input' */

      /* ZeroOrderHold: '<S4>/Zero-Order Hold1' incorporates:
       *  DataTypeConversion: '<S4>/Cast'
       *  MATLABSystem: '<S4>/Analog Input'
       */
      step_test_B.ZeroOrderHold1 = rtb_AnalogInput_0;

      /* Start for MATLABSystem: '<S4>/Lowpass Filter' */
      if (step_test_DW.obj_e.FilterObj->isInitialized != 1) {
        step_test_DW.obj_e.FilterObj->isSetupComplete = false;
        step_test_DW.obj_e.FilterObj->isInitialized = 1;
        step_test_DW.obj_e.FilterObj->isSetupComplete = true;

        /* System object Initialization function: dsp.FIRFilter */
        for (j = 0; j < 83; j++) {
          step_test_DW.obj_e.FilterObj->cSFunObject.W0_states[j] =
            step_test_DW.obj_e.FilterObj->cSFunObject.P0_InitialStates;
        }
      }

      obj = &step_test_DW.obj_e.FilterObj->cSFunObject;

      /* System object Outputs function: dsp.FIRFilter */
      /* Consume delay line and beginning of input samples */
      step_test_B.LowpassFilter = step_test_B.ZeroOrderHold1 *
        step_test_DW.obj_e.FilterObj->cSFunObject.P1_Coefficients[0];
      for (j = 0; j < 83; j++) {
        step_test_B.Product_d = obj->P1_Coefficients[1 + j] * obj->W0_states[j];
        step_test_B.LowpassFilter += step_test_B.Product_d;
      }

      /* Update delay line for next frame */
      for (j = 81; j >= 0; j--) {
        obj->W0_states[1 + j] = obj->W0_states[j];
      }

      step_test_DW.obj_e.FilterObj->cSFunObject.W0_states[0] =
        step_test_B.ZeroOrderHold1;

      /* End of Start for MATLABSystem: '<S4>/Lowpass Filter' */

      /* Sum: '<S8>/Sum' incorporates:
       *  Constant: '<Root>/Wind_des'
       */
      step_test_B.MathFunction1 = step_test_P.Wind_des_Value -
        step_test_B.LowpassFilter;

      /* Product: '<S8>/Product' incorporates:
       *  Constant: '<Root>/Automatic Control'
       */
      step_test_B.Product_d = step_test_B.MathFunction1 *
        step_test_P.AutomaticControl_Value;

      /* RelationalOperator: '<S14>/FixPt Relational Operator' incorporates:
       *  Constant: '<Root>/Automatic Control'
       *  UnitDelay: '<S14>/Delay Input1'
       */
      rtb_FixPtRelationalOperator = (step_test_P.AutomaticControl_Value !=
        step_test_DW.DelayInput1_DSTATE);

      /* DiscreteIntegrator: '<S15>/Integrator' */
      if (rtb_FixPtRelationalOperator && (step_test_DW.Integrator_PrevResetState
           <= 0)) {
        step_test_DW.Integrator_DSTATE = step_test_P.Integrator_IC;
      }

      /* Sum: '<S8>/Sum2' incorporates:
       *  Constant: '<Root>/Wind_des'
       *  Constant: '<S8>/Constant'
       *  Gain: '<S8>/Gain'
       *  Gain: '<S8>/Gain1'
       *  Math: '<S8>/Square'
       */
      step_test_B.Sum2 = (step_test_P.Wind_des_Value *
                          step_test_P.Wind_des_Value * step_test_P.Gain1_Gain +
                          step_test_P.Gain_Gain * step_test_P.Wind_des_Value) +
        step_test_P.Constant_Value;

      /* Product: '<S1>/Product' incorporates:
       *  Constant: '<Root>/Enable'
       *  DiscreteIntegrator: '<S15>/Integrator'
       *  Gain: '<S15>/Proportional Gain'
       *  Sum: '<S15>/Sum'
       *  Sum: '<S8>/Sum1'
       */
      step_test_B.Product = ((step_test_P.DiscretePIDController_P *
        step_test_B.Product_d + step_test_DW.Integrator_DSTATE) +
        step_test_B.Sum2) * step_test_P.Enable_Value;

      /* Gain: '<Root>/Manual PWM' incorporates:
       *  Constant: '<Root>/Constant'
       */
      step_test_B.ManualPWM = step_test_P.ManualPWM_Gain *
        step_test_P.Constant_Value_j;
    }

    /* FromWorkspace: '<S6>/FromWs' */
    {
      real_T *pDataValues = (real_T *) step_test_DW.FromWs_PWORK.DataPtr;
      real_T *pTimeValues = (real_T *) step_test_DW.FromWs_PWORK.TimePtr;
      int_T currTimeIndex = step_test_DW.FromWs_IWORK.PrevIndex;
      real_T t = step_test_M->Timing.t[0];

      /* Get index */
      if (t <= pTimeValues[0]) {
        currTimeIndex = 0;
      } else if (t >= pTimeValues[21]) {
        currTimeIndex = 20;
      } else {
        if (t < pTimeValues[currTimeIndex]) {
          while (t < pTimeValues[currTimeIndex]) {
            currTimeIndex--;
          }
        } else {
          while (t >= pTimeValues[currTimeIndex + 1]) {
            currTimeIndex++;
          }
        }
      }

      step_test_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

      /* Post output */
      {
        real_T t1 = pTimeValues[currTimeIndex];
        real_T t2 = pTimeValues[currTimeIndex + 1];
        if (t1 == t2) {
          if (t < t1) {
            rtb_FromWs = pDataValues[currTimeIndex];
          } else {
            rtb_FromWs = pDataValues[currTimeIndex + 1];
          }
        } else {
          real_T f1 = (t2 - t) / (t2 - t1);
          real_T f2 = 1.0 - f1;
          real_T d1;
          real_T d2;
          int_T TimeIndex= currTimeIndex;
          d1 = pDataValues[TimeIndex];
          d2 = pDataValues[TimeIndex + 1];
          rtb_FromWs = (real_T) rtInterpolate(d1, d2, f1, f2);
          pDataValues += 22;
        }
      }
    }

    /* Switch: '<S1>/Switch2' incorporates:
     *  Constant: '<Root>/Automatic Control'
     *  ManualSwitch: '<Root>/Manual Switch'
     */
    if (step_test_P.AutomaticControl_Value > step_test_P.Switch2_Threshold) {
      step_test_B.PWMsaturation = step_test_B.Product;
    } else if (step_test_P.ManualSwitch_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch' */
      step_test_B.PWMsaturation = step_test_B.ManualPWM;
    } else {
      step_test_B.PWMsaturation = rtb_FromWs;
    }

    /* End of Switch: '<S1>/Switch2' */

    /* Saturate: '<S1>/PWM saturation' */
    if (step_test_B.PWMsaturation > step_test_P.PWMsaturation_UpperSat) {
      step_test_B.PWMsaturation = step_test_P.PWMsaturation_UpperSat;
    } else {
      if (step_test_B.PWMsaturation < step_test_P.PWMsaturation_LowerSat) {
        step_test_B.PWMsaturation = step_test_P.PWMsaturation_LowerSat;
      }
    }

    /* End of Saturate: '<S1>/PWM saturation' */

    /* Sum: '<S1>/Add' incorporates:
     *  Clock: '<S1>/Clock'
     *  Constant: '<Root>/Motor Switch'
     *  Constant: '<S10>/Constant'
     *  Constant: '<S1>/min PWM'
     *  Product: '<S1>/Product1'
     *  RelationalOperator: '<S10>/Compare'
     */
    step_test_B.Add = step_test_B.PWMsaturation * step_test_P.MotorSwitch_Value *
      (real_T)(step_test_M->Timing.t[0] > step_test_P.CompareToConstant_const) +
      step_test_P.minPWM_Value;
    if (rtmIsMajorTimeStep(step_test_M)) {
      /* If: '<S1>/If' incorporates:
       *  Constant: '<S1>/Run Sim'
       *  Inport: '<S12>/In1'
       *  ZeroOrderHold: '<S1>/Zero-Order Hold'
       */
      if (rtmIsMajorTimeStep(step_test_M)) {
        step_test_DW.If_ActiveSubsystem = (int8_T)!(step_test_P.RunSim_Value !=
          1.0);
      }

      switch (step_test_DW.If_ActiveSubsystem) {
       case 0:
        /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
         *  ActionPort: '<S11>/Action Port'
         */
        /* Stop: '<S11>/Stop Simulation' incorporates:
         *  Constant: '<S1>/Constant4'
         *  DataTypeConversion: '<S11>/Cast'
         */
        if (step_test_P.Constant4_Value != 0.0) {
          rtmSetStopRequested(step_test_M, 1);
        }

        /* End of Stop: '<S11>/Stop Simulation' */

        /* SignalConversion: '<S11>/OutportBufferForOut1' incorporates:
         *  Constant: '<S1>/Constant4'
         */
        step_test_B.Merge = step_test_P.Constant4_Value;
        if (rtmIsMajorTimeStep(step_test_M)) {
          srUpdateBC(step_test_DW.IfActionSubsystem_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */
        break;

       case 1:
        /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S12>/Action Port'
         */
        step_test_B.Merge = step_test_B.Add;
        if (rtmIsMajorTimeStep(step_test_M)) {
          srUpdateBC(step_test_DW.IfActionSubsystem1_SubsysRanBC);
        }

        /* End of Outputs for SubSystem: '<S1>/If Action Subsystem1' */
        break;
      }

      /* End of If: '<S1>/If' */
    }

    /* Clock: '<Root>/Clock' */
    step_test_B.Clock = step_test_M->Timing.t[0];

    /* TransferFcn: '<S9>/Transfer Fcn' */
    step_test_B.PWMsaturation = step_test_P.TransferFcn_C *
      step_test_X.TransferFcn_CSTATE;

    /* Gain: '<S9>/Gain1' */
    step_test_B.Gain1_a = step_test_P.Gain1_Gain_f * step_test_B.PWMsaturation;

    /* Math: '<S9>/Square' */
    step_test_B.Square_c = step_test_B.PWMsaturation * step_test_B.PWMsaturation;

    /* Math: '<S9>/Power1' incorporates:
     *  Constant: '<S9>/Constant1'
     */
    if ((step_test_B.PWMsaturation < 0.0) && (step_test_P.Constant1_Value >
         floor(step_test_P.Constant1_Value))) {
      step_test_B.PWMsaturation = -rt_powd_snf(-step_test_B.PWMsaturation,
        step_test_P.Constant1_Value);
    } else {
      step_test_B.PWMsaturation = rt_powd_snf(step_test_B.PWMsaturation,
        step_test_P.Constant1_Value);
    }

    /* End of Math: '<S9>/Power1' */

    /* Sum: '<S9>/Sum1' incorporates:
     *  Constant: '<S9>/Constant2'
     *  Constant: '<S9>/Constant3'
     *  Gain: '<S9>/Gain2'
     *  Product: '<S9>/Product'
     */
    step_test_B.Sum1 = ((step_test_P.Constant3_Value * step_test_B.Square_c +
                         step_test_B.Gain1_a) + step_test_P.Gain2_Gain *
                        step_test_B.PWMsaturation) + step_test_P.Constant2_Value;

    /* TransferFcn: '<S9>/Transfer Fcn1' */
    step_test_B.PWMsaturation = step_test_P.TransferFcn1_C *
      step_test_X.TransferFcn1_CSTATE;

    /* Math: '<S9>/Power' incorporates:
     *  Constant: '<S9>/Constant'
     */
    if ((step_test_P.Constant_Value_k < 0.0) && (step_test_B.PWMsaturation >
         floor(step_test_B.PWMsaturation))) {
      step_test_B.PWMsaturation = -rt_powd_snf(-step_test_P.Constant_Value_k,
        step_test_B.PWMsaturation);
    } else {
      step_test_B.PWMsaturation = rt_powd_snf(step_test_P.Constant_Value_k,
        step_test_B.PWMsaturation);
    }

    /* End of Math: '<S9>/Power' */

    /* Gain: '<S9>/Gain' */
    step_test_B.Gain = step_test_P.Gain_Gain_k * step_test_B.PWMsaturation;

    /* Integrator: '<S7>/Integrator' */
    step_test_B.Integrator = step_test_X.Integrator_CSTATE;
    if (rtmIsMajorTimeStep(step_test_M)) {
      /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
       *  ZeroOrderHold: '<Root>/Zero-Order Hold'
       */
      if (step_test_P.ManualSwitch1_CurrentSetting == 1) {
        step_test_B.ManualSwitch1[0] = step_test_B.Clock;
        step_test_B.ManualSwitch1[1] = step_test_B.LowpassFilter;
        step_test_B.ManualSwitch1[2] = step_test_B.Merge;
        step_test_B.ManualSwitch1[3] = step_test_B.MathFunction1;
        step_test_B.ManualSwitch1[4] = step_test_B.Sum1;
        step_test_B.ManualSwitch1[5] = step_test_B.Gain;
        step_test_B.ManualSwitch1[6] = step_test_B.Integrator;
      } else {
        step_test_B.ManualSwitch1[0] = 0.0;
        step_test_B.ManualSwitch1[1] = 0.0;
        step_test_B.ManualSwitch1[2] = 0.0;
        step_test_B.ManualSwitch1[3] = 0.0;
        step_test_B.ManualSwitch1[4] = 0.0;
        step_test_B.ManualSwitch1[5] = 0.0;
        step_test_B.ManualSwitch1[6] = 0.0;
      }

      /* End of ManualSwitch: '<Root>/Manual Switch1' */
      /* Sum: '<Root>/Sum' incorporates:
       *  Constant: '<Root>/Constant1'
       */
      step_test_B.Sum = step_test_B.Merge - step_test_P.Constant1_Value_i;
    }

    /* Derivative: '<S7>/Derivative' */
    if ((step_test_DW.TimeStampA >= step_test_M->Timing.t[0]) &&
        (step_test_DW.TimeStampB >= step_test_M->Timing.t[0])) {
      step_test_B.PWMsaturation = 0.0;
    } else {
      step_test_B.MathFunction1 = step_test_DW.TimeStampA;
      lastU = &step_test_DW.LastUAtTimeA;
      if (step_test_DW.TimeStampA < step_test_DW.TimeStampB) {
        if (step_test_DW.TimeStampB < step_test_M->Timing.t[0]) {
          step_test_B.MathFunction1 = step_test_DW.TimeStampB;
          lastU = &step_test_DW.LastUAtTimeB;
        }
      } else {
        if (step_test_DW.TimeStampA >= step_test_M->Timing.t[0]) {
          step_test_B.MathFunction1 = step_test_DW.TimeStampB;
          lastU = &step_test_DW.LastUAtTimeB;
        }
      }

      step_test_B.PWMsaturation = (step_test_B.Sum - *lastU) /
        (step_test_M->Timing.t[0] - step_test_B.MathFunction1);
    }

    /* End of Derivative: '<S7>/Derivative' */
    if (rtmIsMajorTimeStep(step_test_M)) {
      /* Math: '<S13>/Math Function1' incorporates:
       *  Constant: '<S13>/Constant3'
       */
      if ((step_test_B.Sum < 0.0) && (step_test_P.Constant3_Value_d > floor
           (step_test_P.Constant3_Value_d))) {
        step_test_B.MathFunction1 = -rt_powd_snf(-step_test_B.Sum,
          step_test_P.Constant3_Value_d);
      } else {
        step_test_B.MathFunction1 = rt_powd_snf(step_test_B.Sum,
          step_test_P.Constant3_Value_d);
      }

      /* End of Math: '<S13>/Math Function1' */

      /* Sum: '<S13>/Sum1' incorporates:
       *  Constant: '<S13>/Constant4'
       *  Gain: '<S13>/Gain2'
       */
      step_test_B.Sum1_h = step_test_P.Gain2_Gain_c * step_test_B.MathFunction1
        + step_test_P.Constant4_Value_p;

      /* Product: '<S7>/Product1' */
      step_test_B.Product1 = step_test_B.Sum * step_test_B.Sum1_h;
    }

    /* Sum: '<S7>/Sum' incorporates:
     *  Product: '<S7>/Product'
     */
    step_test_B.Sum_l = (step_test_B.PWMsaturation * step_test_B.Sum1_h +
                         step_test_B.Product1) - step_test_B.Integrator;
    if (rtmIsMajorTimeStep(step_test_M)) {
      /* Gain: '<S15>/Integral Gain' */
      rtb_IntegralGain = step_test_P.DiscretePIDController_I *
        step_test_B.Product_d;

      /* Start for MATLABSystem: '<Root>/Moving Average' */
      if (step_test_DW.obj.TunablePropsChanged) {
        step_test_DW.obj.TunablePropsChanged = false;
      }

      if (step_test_DW.obj.pStatistic->isInitialized != 1) {
        step_test_DW.obj.pStatistic->isSetupComplete = false;
        step_test_DW.obj.pStatistic->isInitialized = 1;
        step_test_DW.obj.pStatistic->pCumSum = 0.0;
        step_test_DW.obj.pStatistic->pCumRevIndex = 1.0;
        step_test_DW.obj.pStatistic->isSetupComplete = true;
        step_test_DW.obj.pStatistic->pCumSum = 0.0;
        step_test_DW.obj.pStatistic->pCumSumRev[0] = 0.0;
        step_test_DW.obj.pStatistic->pCumSumRev[0] = 0.0;
        step_test_DW.obj.pStatistic->pCumSumRev[1] = 0.0;
        step_test_DW.obj.pStatistic->pCumSumRev[1] = 0.0;
        step_test_DW.obj.pStatistic->pCumSumRev[2] = 0.0;
        step_test_DW.obj.pStatistic->pCumSumRev[2] = 0.0;
        step_test_DW.obj.pStatistic->pCumSumRev[3] = 0.0;
        step_test_DW.obj.pStatistic->pCumSumRev[3] = 0.0;
        step_test_DW.obj.pStatistic->pCumRevIndex = 1.0;
      }

      step_test_B.Product_d = step_test_DW.obj.pStatistic->pCumRevIndex;
      step_test_B.MathFunction1 = step_test_DW.obj.pStatistic->pCumSum;
      step_test_B.csumrev[0] = step_test_DW.obj.pStatistic->pCumSumRev[0];
      step_test_B.csumrev[1] = step_test_DW.obj.pStatistic->pCumSumRev[1];
      step_test_B.csumrev[2] = step_test_DW.obj.pStatistic->pCumSumRev[2];
      step_test_B.csumrev[3] = step_test_DW.obj.pStatistic->pCumSumRev[3];
      step_test_B.MathFunction1 += step_test_B.LowpassFilter;
      j = (int32_T)step_test_B.Product_d - 1;
      step_test_B.PWMsaturation = step_test_B.csumrev[j] +
        step_test_B.MathFunction1;
      step_test_B.csumrev[j] = step_test_B.LowpassFilter;
      if (step_test_B.Product_d != 4.0) {
        step_test_B.Product_d++;
      } else {
        step_test_B.Product_d = 1.0;
        step_test_B.MathFunction1 = 0.0;
        step_test_B.csumrev[2] += step_test_B.csumrev[3];
        step_test_B.csumrev[1] += step_test_B.csumrev[2];
        step_test_B.csumrev[0] += step_test_B.csumrev[1];
      }

      step_test_DW.obj.pStatistic->pCumSum = step_test_B.MathFunction1;
      step_test_DW.obj.pStatistic->pCumSumRev[0] = step_test_B.csumrev[0];
      step_test_DW.obj.pStatistic->pCumSumRev[1] = step_test_B.csumrev[1];
      step_test_DW.obj.pStatistic->pCumSumRev[2] = step_test_B.csumrev[2];
      step_test_DW.obj.pStatistic->pCumSumRev[3] = step_test_B.csumrev[3];
      step_test_DW.obj.pStatistic->pCumRevIndex = step_test_B.Product_d;

      /* MATLABSystem: '<Root>/Moving Average' */
      step_test_B.MovingAverage = step_test_B.PWMsaturation / 5.0;

      /* Sum: '<S9>/Sum' incorporates:
       *  Constant: '<S9>/Constant4'
       */
      step_test_B.Sum_i = step_test_B.LowpassFilter -
        step_test_P.Constant4_Value_g;

      /* Start for MATLABSystem: '<S1>/PWM1' */
      MW_PWM_SetDutyCycle(step_test_DW.obj_n.MW_PWM_HANDLE, step_test_B.Merge);

      /* Start for MATLABSystem: '<S4>/Analog Input1' */
      p = false;
      p_0 = true;
      if (!(step_test_DW.obj_i.SampleTime == step_test_P.AnalogInput1_SampleTime))
      {
        p_0 = false;
      }

      if (p_0) {
        p = true;
      }

      if (!p) {
        step_test_DW.obj_i.SampleTime = step_test_P.AnalogInput1_SampleTime;
      }

      MW_AnalogIn_Start(step_test_DW.obj_i.MW_ANALOGIN_HANDLE);

      /* ZeroOrderHold: '<S4>/Zero-Order Hold' incorporates:
       *  MATLABSystem: '<S4>/Analog Input1'
       *  MATLABSystem: '<S4>/Analog Input1'
       */
      MW_AnalogInSingle_ReadResult(step_test_DW.obj_i.MW_ANALOGIN_HANDLE,
        &step_test_B.ZeroOrderHold, 3);
    }
  }

  if (rtmIsMajorTimeStep(step_test_M)) {
    real_T *lastU;
    if (rtmIsMajorTimeStep(step_test_M)) {
      /* Update for UnitDelay: '<S14>/Delay Input1' incorporates:
       *  Constant: '<Root>/Automatic Control'
       */
      step_test_DW.DelayInput1_DSTATE = step_test_P.AutomaticControl_Value;

      /* Update for DiscreteIntegrator: '<S15>/Integrator' */
      step_test_DW.Integrator_DSTATE += step_test_P.Integrator_gainval *
        rtb_IntegralGain;
      step_test_DW.Integrator_PrevResetState = (int8_T)
        rtb_FixPtRelationalOperator;
    }

    /* Update for Derivative: '<S7>/Derivative' */
    if (step_test_DW.TimeStampA == (rtInf)) {
      step_test_DW.TimeStampA = step_test_M->Timing.t[0];
      lastU = &step_test_DW.LastUAtTimeA;
    } else if (step_test_DW.TimeStampB == (rtInf)) {
      step_test_DW.TimeStampB = step_test_M->Timing.t[0];
      lastU = &step_test_DW.LastUAtTimeB;
    } else if (step_test_DW.TimeStampA < step_test_DW.TimeStampB) {
      step_test_DW.TimeStampA = step_test_M->Timing.t[0];
      lastU = &step_test_DW.LastUAtTimeA;
    } else {
      step_test_DW.TimeStampB = step_test_M->Timing.t[0];
      lastU = &step_test_DW.LastUAtTimeB;
    }

    *lastU = step_test_B.Sum;

    /* End of Update for Derivative: '<S7>/Derivative' */

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, step_test_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(step_test_M)) {/* Sample time: [0.01s, 0.0s] */
      rtExtModeUpload(1, (((step_test_M->Timing.clockTick1+
                            step_test_M->Timing.clockTickH1* 4294967296.0)) *
                          0.01));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(step_test_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(step_test_M)!=-1) &&
          !((rtmGetTFinal(step_test_M)-(((step_test_M->Timing.clockTick1+
               step_test_M->Timing.clockTickH1* 4294967296.0)) * 0.01)) >
            (((step_test_M->Timing.clockTick1+step_test_M->Timing.clockTickH1*
               4294967296.0)) * 0.01) * (DBL_EPSILON))) {
        rtmSetErrorStatus(step_test_M, "Simulation finished");
      }

      if (rtmGetStopRequested(step_test_M)) {
        rtmSetErrorStatus(step_test_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&step_test_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++step_test_M->Timing.clockTick0)) {
      ++step_test_M->Timing.clockTickH0;
    }

    step_test_M->Timing.t[0] = rtsiGetSolverStopTime(&step_test_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      step_test_M->Timing.clockTick1++;
      if (!step_test_M->Timing.clockTick1) {
        step_test_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void step_test_derivatives(void)
{
  XDot_step_test_T *_rtXdot;
  _rtXdot = ((XDot_step_test_T *) step_test_M->derivs);

  /* Derivatives for TransferFcn: '<S9>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += step_test_P.TransferFcn_A *
    step_test_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += step_test_B.Sum_i;

  /* Derivatives for TransferFcn: '<S9>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += step_test_P.TransferFcn1_A *
    step_test_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += step_test_B.LowpassFilter;

  /* Derivatives for Integrator: '<S7>/Integrator' */
  _rtXdot->Integrator_CSTATE = step_test_B.Sum_l;
}

/* Model initialize function */
void step_test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)step_test_M, 0,
                sizeof(RT_MODEL_step_test_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&step_test_M->solverInfo,
                          &step_test_M->Timing.simTimeStep);
    rtsiSetTPtr(&step_test_M->solverInfo, &rtmGetTPtr(step_test_M));
    rtsiSetStepSizePtr(&step_test_M->solverInfo, &step_test_M->Timing.stepSize0);
    rtsiSetdXPtr(&step_test_M->solverInfo, &step_test_M->derivs);
    rtsiSetContStatesPtr(&step_test_M->solverInfo, (real_T **)
                         &step_test_M->contStates);
    rtsiSetNumContStatesPtr(&step_test_M->solverInfo,
      &step_test_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&step_test_M->solverInfo,
      &step_test_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&step_test_M->solverInfo,
      &step_test_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&step_test_M->solverInfo,
      &step_test_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&step_test_M->solverInfo, (&rtmGetErrorStatus
      (step_test_M)));
    rtsiSetRTModelPtr(&step_test_M->solverInfo, step_test_M);
  }

  rtsiSetSimTimeStep(&step_test_M->solverInfo, MAJOR_TIME_STEP);
  step_test_M->intgData.y = step_test_M->odeY;
  step_test_M->intgData.f[0] = step_test_M->odeF[0];
  step_test_M->intgData.f[1] = step_test_M->odeF[1];
  step_test_M->intgData.f[2] = step_test_M->odeF[2];
  step_test_M->contStates = ((X_step_test_T *) &step_test_X);
  rtsiSetSolverData(&step_test_M->solverInfo, (void *)&step_test_M->intgData);
  rtsiSetSolverName(&step_test_M->solverInfo,"ode3");
  rtmSetTPtr(step_test_M, &step_test_M->Timing.tArray[0]);
  rtmSetTFinal(step_test_M, -1);
  step_test_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  step_test_M->Sizes.checksums[0] = (866684759U);
  step_test_M->Sizes.checksums[1] = (4033129876U);
  step_test_M->Sizes.checksums[2] = (1638840440U);
  step_test_M->Sizes.checksums[3] = (3197379108U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    step_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = (sysRanDType *)&step_test_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&step_test_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(step_test_M->extModeInfo,
      &step_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(step_test_M->extModeInfo, step_test_M->Sizes.checksums);
    rteiSetTPtr(step_test_M->extModeInfo, rtmGetTPtr(step_test_M));
  }

  /* block I/O */
  (void) memset(((void *) &step_test_B), 0,
                sizeof(B_step_test_T));

  /* states (continuous) */
  {
    (void) memset((void *)&step_test_X, 0,
                  sizeof(X_step_test_T));
  }

  /* states (dwork) */
  (void) memset((void *)&step_test_DW, 0,
                sizeof(DW_step_test_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    step_test_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_in_dm_T *obj;
    MW_AnalogIn_TriggerSource_Type trigger_val;
    dspcodegen_FIRFilter_step_tes_T *iobj_0;
    codertarget_arduinobase_int_d_T *obj_0;
    static const real_T tmp[84] = { 0.2812679496464367, 0.0047325708220655183,
      0.004704839221449264, 0.0047747143973964068, 0.0048390220505179493,
      0.0048757888964534035, 0.004896359407251194, 0.0049190797209123227,
      0.00495089218377448, 0.0049863662860213376, 0.0050184311796208636,
      0.0050468546260802327, 0.0050768477931036893, 0.0051118864645981477,
      0.005149732868708512, 0.0051856117191174111, 0.0052182445902208552,
      0.0052515083756464187, 0.0052894613881697139, 0.0053302645414855521,
      0.0053668452917061127, 0.0053953348271043589, 0.0054222027345039447,
      0.00545894942037134, 0.0055040771086861118, 0.0055255911636799548,
      0.0054497833539855489, 0.0049815580449548147, 0.0055055962896580768,
      0.0056010085055087089, 0.0054964224678233364, 0.0054555377979713104,
      0.0054656068758708876, 0.0054946706264651923, 0.00551723869843318,
      0.0055280143089420086, 0.0055355178080480072, 0.0055470547997683584,
      0.0055609430303756868, 0.0055707316308847843, 0.0055735319668934191,
      0.0055726351493993742, 0.0055726351493993742, 0.0055735319668934191,
      0.0055707316308847843, 0.0055609430303756868, 0.0055470547997683584,
      0.0055355178080480072, 0.0055280143089420086, 0.00551723869843318,
      0.0054946706264651923, 0.0054656068758708876, 0.0054555377979713104,
      0.0054964224678233364, 0.0056010085055087089, 0.0055055962896580768,
      0.0049815580449548147, 0.0054497833539855489, 0.0055255911636799548,
      0.0055040771086861118, 0.00545894942037134, 0.0054222027345039447,
      0.0053953348271043589, 0.0053668452917061127, 0.0053302645414855521,
      0.0052894613881697139, 0.0052515083756464187, 0.0052182445902208552,
      0.0051856117191174111, 0.005149732868708512, 0.0051118864645981477,
      0.0050768477931036893, 0.0050468546260802327, 0.0050184311796208636,
      0.0049863662860213376, 0.00495089218377448, 0.0049190797209123227,
      0.004896359407251194, 0.0048757888964534035, 0.0048390220505179493,
      0.0047747143973964068, 0.004704839221449264, 0.0047325708220655183,
      0.2812679496464367 };

    int32_T i;

    /* Start for MATLABSystem: '<S4>/Analog Input' */
    step_test_DW.obj_g.matlabCodegenIsDeleted = true;
    obj = &step_test_DW.obj_g;
    step_test_DW.obj_g.isInitialized = 0;
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
    step_test_DW.obj_g.matlabCodegenIsDeleted = false;
    step_test_DW.objisempty = true;
    step_test_DW.obj_g.SampleTime = step_test_P.AnalogInput_SampleTime;
    obj = &step_test_DW.obj_g;
    step_test_DW.obj_g.isSetupComplete = false;
    step_test_DW.obj_g.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(2U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(step_test_DW.obj_g.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    step_test_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Lowpass Filter' */
    step_test_DW.gobj_1.matlabCodegenIsDeleted = true;
    step_test_DW.gobj_0.matlabCodegenIsDeleted = true;
    step_test_DW.obj_e.matlabCodegenIsDeleted = true;
    step_test_DW.obj_e.isInitialized = 0;
    step_test_DW.obj_e.NumChannels = -1;
    step_test_DW.obj_e.matlabCodegenIsDeleted = false;
    step_test_DW.objisempty_c = true;
    iobj_0 = &step_test_DW.gobj_0;
    step_test_DW.obj_e.isSetupComplete = false;
    step_test_DW.obj_e.isInitialized = 1;
    step_test_DW.gobj_0.isInitialized = 0;

    /* System object Constructor function: dsp.FIRFilter */
    iobj_0->cSFunObject.P0_InitialStates = 0.0;
    for (i = 0; i < 84; i++) {
      iobj_0->cSFunObject.P1_Coefficients[i] = tmp[i];
    }

    step_test_DW.gobj_0.matlabCodegenIsDeleted = false;
    step_test_DW.obj_e.FilterObj = &step_test_DW.gobj_0;
    step_test_DW.obj_e.NumChannels = 1;
    step_test_DW.obj_e.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<S4>/Lowpass Filter' */

    /* Start for FromWorkspace: '<S6>/FromWs' */
    {
      static real_T pTimeValues0[] = { 0.0, 30.0, 30.0, 60.0, 60.0, 90.0, 90.0,
        120.0, 120.0, 150.0, 150.0, 180.0, 180.0, 210.0, 210.0, 240.0, 240.0,
        270.0, 270.0, 300.0, 300.0, 340.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, 4.0, 4.0, 6.0, 6.0, 8.0, 8.0,
        10.0, 10.0, 12.0, 12.0, 14.0, 14.0, 16.0, 16.0, 18.0, 18.0, 20.0, 20.0,
        0.0, 0.0 } ;

      step_test_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
      step_test_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
      step_test_DW.FromWs_IWORK.PrevIndex = 0;
    }

    /* Start for If: '<S1>/If' */
    step_test_DW.If_ActiveSubsystem = -1;

    /* Start for MATLABSystem: '<Root>/Moving Average' */
    step_test_DW.obj.matlabCodegenIsDeleted = true;
    step_test_DW.obj.isInitialized = 0;
    step_test_DW.obj.NumChannels = -1;
    step_test_DW.obj.matlabCodegenIsDeleted = false;
    step_test_DW.objisempty_h = true;
    step_test_DW.obj.isSetupComplete = false;
    step_test_DW.obj.isInitialized = 1;
    step_test_DW.obj.NumChannels = 1;
    step_test_DW.gobj_0_n.isInitialized = 0;
    step_test_DW.obj.pStatistic = &step_test_DW.gobj_0_n;
    step_test_DW.obj.isSetupComplete = true;
    step_test_DW.obj.TunablePropsChanged = false;

    /* Start for MATLABSystem: '<S1>/PWM1' */
    step_test_DW.obj_n.matlabCodegenIsDeleted = true;
    arduino_PWMOutput_arduino_PWMOu(&step_test_DW.obj_n);
    step_test_DW.objisempty_b = true;
    obj_0 = &step_test_DW.obj_n;
    step_test_DW.obj_n.isSetupComplete = false;
    step_test_DW.obj_n.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(12U, 0.0, 0.0);
    MW_PWM_Start(step_test_DW.obj_n.MW_PWM_HANDLE);
    step_test_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Analog Input1' */
    step_test_DW.obj_i.matlabCodegenIsDeleted = true;
    obj = &step_test_DW.obj_i;
    step_test_DW.obj_i.isInitialized = 0;
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
    step_test_DW.obj_i.matlabCodegenIsDeleted = false;
    step_test_DW.objisempty_o = true;
    step_test_DW.obj_i.SampleTime = step_test_P.AnalogInput1_SampleTime;
    obj = &step_test_DW.obj_i;
    step_test_DW.obj_i.isSetupComplete = false;
    step_test_DW.obj_i.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(3U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(step_test_DW.obj_i.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    step_test_DW.obj_i.isSetupComplete = true;
  }

  {
    int32_T i;

    /* InitializeConditions for UnitDelay: '<S14>/Delay Input1' */
    step_test_DW.DelayInput1_DSTATE = step_test_P.DetectChange_vinit;

    /* InitializeConditions for DiscreteIntegrator: '<S15>/Integrator' */
    step_test_DW.Integrator_DSTATE = step_test_P.Integrator_IC;
    step_test_DW.Integrator_PrevResetState = 2;

    /* InitializeConditions for TransferFcn: '<S9>/Transfer Fcn' */
    step_test_X.TransferFcn_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S9>/Transfer Fcn1' */
    step_test_X.TransferFcn1_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<S7>/Integrator' */
    step_test_X.Integrator_CSTATE = step_test_P.Integrator_IC_j;

    /* InitializeConditions for Derivative: '<S7>/Derivative' */
    step_test_DW.TimeStampA = (rtInf);
    step_test_DW.TimeStampB = (rtInf);

    /* Start for MATLABSystem: '<S4>/Lowpass Filter' */
    if (step_test_DW.obj_e.FilterObj->isInitialized == 1) {
      /* System object Initialization function: dsp.FIRFilter */
      for (i = 0; i < 83; i++) {
        step_test_DW.obj_e.FilterObj->cSFunObject.W0_states[i] =
          step_test_DW.obj_e.FilterObj->cSFunObject.P0_InitialStates;
      }
    }

    /* End of Start for MATLABSystem: '<S4>/Lowpass Filter' */

    /* Start for MATLABSystem: '<Root>/Moving Average' */
    if (step_test_DW.obj.pStatistic->isInitialized == 1) {
      step_test_DW.obj.pStatistic->pCumSum = 0.0;
      step_test_DW.obj.pStatistic->pCumSumRev[0] = 0.0;
      step_test_DW.obj.pStatistic->pCumSumRev[1] = 0.0;
      step_test_DW.obj.pStatistic->pCumSumRev[2] = 0.0;
      step_test_DW.obj.pStatistic->pCumSumRev[3] = 0.0;
      step_test_DW.obj.pStatistic->pCumRevIndex = 1.0;
    }

    /* End of Start for MATLABSystem: '<Root>/Moving Average' */
  }
}

/* Model terminate function */
void step_test_terminate(void)
{
  /* Terminate for MATLABSystem: '<S4>/Analog Input' */
  matlabCodegenHandle_matlabCo_dm(&step_test_DW.obj_g);

  /* Terminate for MATLABSystem: '<S4>/Lowpass Filter' */
  matlabCodegenHandle_matlab_dms4(&step_test_DW.obj_e);
  matlabCodegenHandle_matlabC_dms(&step_test_DW.gobj_0);
  matlabCodegenHandle_matlabC_dms(&step_test_DW.gobj_1);

  /* Terminate for MATLABSystem: '<Root>/Moving Average' */
  matlabCodegenHandle_matlabCodeg(&step_test_DW.obj);

  /* Terminate for MATLABSystem: '<S1>/PWM1' */
  matlabCodegenHandle_matlabCod_d(&step_test_DW.obj_n);

  /* Terminate for MATLABSystem: '<S4>/Analog Input1' */
  matlabCodegenHandle_matlabCo_dm(&step_test_DW.obj_i);
}
