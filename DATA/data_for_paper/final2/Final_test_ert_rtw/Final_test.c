/*
 * Final_test.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Final_test".
 *
 * Model version              : 1.39
 * Simulink Coder version : 8.14 (R2018a) 06-Feb-2018
 * C source code generated on : Wed Sep  5 12:04:40 2018
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Final_test.h"
#include "Final_test_private.h"
#include "Final_test_dt.h"

/* Block signals (default storage) */
B_Final_test_T Final_test_B;

/* Continuous states */
X_Final_test_T Final_test_X;

/* Block states (default storage) */
DW_Final_test_T Final_test_DW;

/* Real-time model */
RT_MODEL_Final_test_T Final_test_M_;
RT_MODEL_Final_test_T *const Final_test_M = &Final_test_M_;

/* Forward declaration for local functions */
static codertarget_arduinobase_int_f_T *arduino_PWMOutput_arduino_PWMOu
  (codertarget_arduinobase_int_f_T *obj);
static void SystemProp_matlabCodegenSetAnyP(dsp_simulink_MovingAverage_Fi_T *obj,
  boolean_T value);
static void Final_test_SystemCore_release(dsp_simulink_MovingAverage_Fi_T *obj);
static void Final_test_SystemCore_delete(dsp_simulink_MovingAverage_Fi_T *obj);
static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage_Fi_T *obj);
static void SystemProp_matlabCodegenSetA_fd(codertarget_arduinobase_in_fd_T *obj,
  boolean_T value);
static void matlabCodegenHandle_matlabCo_fd(codertarget_arduinobase_in_fd_T *obj);
static void SystemProp_matlabCodegenSetAn_f(codertarget_arduinobase_int_f_T *obj,
  boolean_T value);
static void matlabCodegenHandle_matlabCod_f(codertarget_arduinobase_int_f_T *obj);

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
  Final_test_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  Final_test_step();
  Final_test_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  Final_test_step();
  Final_test_derivatives();

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

static codertarget_arduinobase_int_f_T *arduino_PWMOutput_arduino_PWMOu
  (codertarget_arduinobase_int_f_T *obj)
{
  codertarget_arduinobase_int_f_T *b_obj;

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

static void SystemProp_matlabCodegenSetAnyP(dsp_simulink_MovingAverage_Fi_T *obj,
  boolean_T value)
{
  /* Start for MATLABSystem: '<Root>/Moving Average' */
  obj->matlabCodegenIsDeleted = value;
}

static void Final_test_SystemCore_release(dsp_simulink_MovingAverage_Fi_T *obj)
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

static void Final_test_SystemCore_delete(dsp_simulink_MovingAverage_Fi_T *obj)
{
  /* Start for MATLABSystem: '<Root>/Moving Average' */
  Final_test_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage_Fi_T *obj)
{
  /* Start for MATLABSystem: '<Root>/Moving Average' */
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetAnyP(obj, true);
    Final_test_SystemCore_delete(obj);
  }

  /* End of Start for MATLABSystem: '<Root>/Moving Average' */
}

static void SystemProp_matlabCodegenSetA_fd(codertarget_arduinobase_in_fd_T *obj,
  boolean_T value)
{
  /* Start for MATLABSystem: '<S4>/Analog Input' */
  obj->matlabCodegenIsDeleted = value;
}

static void matlabCodegenHandle_matlabCo_fd(codertarget_arduinobase_in_fd_T *obj)
{
  /* Start for MATLABSystem: '<S4>/Analog Input' */
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetA_fd(obj, true);
  }

  /* End of Start for MATLABSystem: '<S4>/Analog Input' */
}

static void SystemProp_matlabCodegenSetAn_f(codertarget_arduinobase_int_f_T *obj,
  boolean_T value)
{
  /* Start for MATLABSystem: '<S3>/PWM1' */
  obj->matlabCodegenIsDeleted = value;
}

static void matlabCodegenHandle_matlabCod_f(codertarget_arduinobase_int_f_T *obj)
{
  /* Start for MATLABSystem: '<S3>/PWM1' */
  if (!obj->matlabCodegenIsDeleted) {
    SystemProp_matlabCodegenSetAn_f(obj, true);
  }

  /* End of Start for MATLABSystem: '<S3>/PWM1' */
}

/* Model step function */
void Final_test_step(void)
{
  /* local block i/o variables */
  real_T rtb_FromWs;
  real_T rtb_IntegralGain;
  boolean_T rtb_FixPtRelationalOperator;
  int8_T R[4];
  static const real_T a[4] = { 0.9998, -0.0394, 0.009851, 0.9702 };

  static const real_T b_b[4] = { 0.9998, 0.009851, -0.0394, 0.9702 };

  uint16_T rtb_AnalogInput_0;
  boolean_T p;
  boolean_T p_0;
  real_T rtb_PWMsaturation;
  real_T rtb_Product1;
  int32_T i;
  if (rtmIsMajorTimeStep(Final_test_M)) {
    /* set solver stop time */
    if (!(Final_test_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Final_test_M->solverInfo,
                            ((Final_test_M->Timing.clockTickH0 + 1) *
        Final_test_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Final_test_M->solverInfo,
                            ((Final_test_M->Timing.clockTick0 + 1) *
        Final_test_M->Timing.stepSize0 + Final_test_M->Timing.clockTickH0 *
        Final_test_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Final_test_M)) {
    Final_test_M->Timing.t[0] = rtsiGetT(&Final_test_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_test_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(Final_test_DW.IfActionSubsystem1_SubsysRanBC);

  /* TransferFcn: '<S4>/Transfer Fcn1' */
  Final_test_B.TransferFcn1 = 0.0;
  Final_test_B.TransferFcn1 += Final_test_P.TransferFcn1_C *
    Final_test_X.TransferFcn1_CSTATE;

  /* Sum: '<S7>/Sum' incorporates:
   *  Constant: '<Root>/Wind_des'
   */
  Final_test_B.e = Final_test_P.Wind_des_Value - Final_test_B.TransferFcn1;

  /* Product: '<S7>/Product' incorporates:
   *  Constant: '<Root>/Automatic Control'
   */
  Final_test_B.Product = Final_test_B.e * Final_test_P.AutomaticControl_Value;
  if (rtmIsMajorTimeStep(Final_test_M)) {
    /* RelationalOperator: '<S53>/FixPt Relational Operator' incorporates:
     *  Constant: '<Root>/Automatic Control'
     *  UnitDelay: '<S53>/Delay Input1'
     */
    rtb_FixPtRelationalOperator = (Final_test_P.AutomaticControl_Value !=
      Final_test_DW.DelayInput1_DSTATE);

    /* DiscreteIntegrator: '<S54>/Integrator' */
    if (rtb_FixPtRelationalOperator && (Final_test_DW.Integrator_PrevResetState <=
         0)) {
      Final_test_DW.Integrator_DSTATE = Final_test_P.Integrator_IC;
    }

    /* Sum: '<S7>/Sum2' incorporates:
     *  Constant: '<Root>/Wind_des'
     *  Constant: '<S7>/Constant'
     *  Gain: '<S7>/Gain'
     *  Gain: '<S7>/Gain1'
     *  Math: '<S7>/Square'
     */
    Final_test_B.Sum2 = (Final_test_P.Wind_des_Value *
                         Final_test_P.Wind_des_Value * Final_test_P.Gain1_Gain +
                         Final_test_P.Gain_Gain * Final_test_P.Wind_des_Value) +
      Final_test_P.Constant_Value;

    /* Product: '<S3>/Product' incorporates:
     *  Constant: '<Root>/Enable'
     *  DiscreteIntegrator: '<S54>/Integrator'
     *  Gain: '<S54>/Proportional Gain'
     *  Sum: '<S54>/Sum'
     *  Sum: '<S7>/Sum1'
     */
    Final_test_B.Product_m = ((Final_test_P.DiscretePIDController_P *
      Final_test_B.Product + Final_test_DW.Integrator_DSTATE) +
      Final_test_B.Sum2) * Final_test_P.Enable_Value;

    /* Gain: '<Root>/Manual PWM' incorporates:
     *  Constant: '<Root>/Constant'
     */
    Final_test_B.ManualPWM = Final_test_P.ManualPWM_Gain *
      Final_test_P.Constant_Value_j;
  }

  /* FromWorkspace: '<S5>/FromWs' */
  {
    real_T *pDataValues = (real_T *) Final_test_DW.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) Final_test_DW.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = Final_test_DW.FromWs_IWORK.PrevIndex;
    real_T t = Final_test_M->Timing.t[0];

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

    Final_test_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

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

  /* Switch: '<S3>/Switch2' incorporates:
   *  Constant: '<Root>/Automatic Control'
   *  ManualSwitch: '<Root>/Manual Switch'
   */
  if (Final_test_P.AutomaticControl_Value > Final_test_P.Switch2_Threshold) {
    rtb_PWMsaturation = Final_test_B.Product_m;
  } else if (Final_test_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Manual Switch' */
    rtb_PWMsaturation = Final_test_B.ManualPWM;
  } else {
    rtb_PWMsaturation = rtb_FromWs;
  }

  /* End of Switch: '<S3>/Switch2' */

  /* Saturate: '<S3>/PWM saturation' */
  if (rtb_PWMsaturation > Final_test_P.PWMsaturation_UpperSat) {
    rtb_PWMsaturation = Final_test_P.PWMsaturation_UpperSat;
  } else {
    if (rtb_PWMsaturation < Final_test_P.PWMsaturation_LowerSat) {
      rtb_PWMsaturation = Final_test_P.PWMsaturation_LowerSat;
    }
  }

  /* End of Saturate: '<S3>/PWM saturation' */

  /* Sum: '<S3>/Add' incorporates:
   *  Clock: '<S3>/Clock'
   *  Constant: '<Root>/Motor Switch'
   *  Constant: '<S3>/min PWM'
   *  Constant: '<S50>/Constant'
   *  Product: '<S3>/Product1'
   *  RelationalOperator: '<S50>/Compare'
   */
  Final_test_B.Add = rtb_PWMsaturation * Final_test_P.MotorSwitch_Value *
    (real_T)(Final_test_M->Timing.t[0] > Final_test_P.CompareToConstant_const) +
    Final_test_P.minPWM_Value;
  if (rtmIsMajorTimeStep(Final_test_M)) {
    /* If: '<S3>/If' incorporates:
     *  Constant: '<S3>/Run Sim'
     *  Inport: '<S52>/In1'
     *  ZeroOrderHold: '<S3>/Zero-Order Hold'
     */
    if (rtmIsMajorTimeStep(Final_test_M)) {
      Final_test_DW.If_ActiveSubsystem = (int8_T)!(Final_test_P.RunSim_Value !=
        1.0);
    }

    switch (Final_test_DW.If_ActiveSubsystem) {
     case 0:
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
       *  ActionPort: '<S51>/Action Port'
       */
      /* Stop: '<S51>/Stop Simulation' incorporates:
       *  Constant: '<S3>/Constant4'
       *  DataTypeConversion: '<S51>/Cast'
       */
      if (Final_test_P.Constant4_Value != 0.0) {
        rtmSetStopRequested(Final_test_M, 1);
      }

      /* End of Stop: '<S51>/Stop Simulation' */

      /* SignalConversion: '<S51>/OutportBufferForOut1' incorporates:
       *  Constant: '<S3>/Constant4'
       */
      Final_test_B.Merge = Final_test_P.Constant4_Value;
      if (rtmIsMajorTimeStep(Final_test_M)) {
        srUpdateBC(Final_test_DW.IfActionSubsystem_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S52>/Action Port'
       */
      Final_test_B.Merge = Final_test_B.Add;
      if (rtmIsMajorTimeStep(Final_test_M)) {
        srUpdateBC(Final_test_DW.IfActionSubsystem1_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */
      break;
    }

    /* End of If: '<S3>/If' */
  }

  /* Clock: '<Root>/Clock' */
  Final_test_B.Clock = Final_test_M->Timing.t[0];

  /* Math: '<S8>/Power' incorporates:
   *  Constant: '<S8>/b'
   */
  if ((Final_test_B.TransferFcn1 < 0.0) && (Final_test_P.b_Value > floor
       (Final_test_P.b_Value))) {
    rtb_PWMsaturation = -rt_powd_snf(-Final_test_B.TransferFcn1,
      Final_test_P.b_Value);
  } else {
    rtb_PWMsaturation = rt_powd_snf(Final_test_B.TransferFcn1,
      Final_test_P.b_Value);
  }

  /* End of Math: '<S8>/Power' */

  /* Gain: '<S8>/a' */
  Final_test_B.a = Final_test_P.a_Gain * rtb_PWMsaturation;

  /* Integrator: '<S9>/Integrator1' */
  Final_test_B.Integrator1 = Final_test_X.Integrator1_CSTATE;
  if (rtmIsMajorTimeStep(Final_test_M)) {
    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    rtb_PWMsaturation = Final_test_B.Merge - Final_test_P.Constant1_Value;

    /* Math: '<S11>/Math Function1' incorporates:
     *  Constant: '<S11>/a'
     */
    if ((rtb_PWMsaturation < 0.0) && (Final_test_P.a_Value > floor
         (Final_test_P.a_Value))) {
      rtb_Product1 = -rt_powd_snf(-rtb_PWMsaturation, Final_test_P.a_Value);
    } else {
      rtb_Product1 = rt_powd_snf(rtb_PWMsaturation, Final_test_P.a_Value);
    }

    /* End of Math: '<S11>/Math Function1' */

    /* Product: '<S11>/Product1' incorporates:
     *  Constant: '<S11>/c'
     *  Gain: '<S11>/b'
     *  Sum: '<S11>/Sum1'
     */
    rtb_Product1 = (Final_test_P.b_Gain * rtb_Product1 + Final_test_P.c_Value) *
      rtb_PWMsaturation;

    /* MATLAB Function: '<S1>/MATLAB Function' */
    R[0] = 0;
    R[1] = 0;
    R[2] = 0;
    R[3] = 0;
    for (i = 0; i < 2; i++) {
      R[i + (i << 1)] = 5;
      Final_test_B.a_m[i] = 0.0;
      Final_test_B.a_m[i] += a[i] * Final_test_DW.P[0];
      Final_test_B.a_m[i] += a[i + 2] * Final_test_DW.P[1];
      Final_test_B.a_m[i + 2] = 0.0;
      Final_test_B.a_m[i + 2] += a[i] * Final_test_DW.P[2];
      Final_test_B.a_m[i + 2] += a[i + 2] * Final_test_DW.P[3];
      Final_test_B.xh_bar[i] = (a[i + 2] * Final_test_DW.xh[1] + a[i] *
        Final_test_DW.xh[0]) + (0.039202 * (real_T)i + 0.000198) * rtb_Product1;
    }

    for (i = 0; i < 2; i++) {
      Final_test_B.P_bar[i << 1] = (b_b[(i << 1) + 1] * Final_test_B.a_m[2] +
        b_b[i << 1] * Final_test_B.a_m[0]) + (real_T)R[i << 1];
      Final_test_B.P_bar[1 + (i << 1)] = (b_b[(i << 1) + 1] * Final_test_B.a_m[3]
        + b_b[i << 1] * Final_test_B.a_m[1]) + (real_T)R[(i << 1) + 1];
    }

    rtb_Product1 = 1.0 / (((0.0 * Final_test_B.P_bar[3] + Final_test_B.P_bar[2])
      * 0.0 + (0.0 * Final_test_B.P_bar[1] + Final_test_B.P_bar[0])) + 1.0);
    Final_test_B.K[0] = (Final_test_B.P_bar[2] * 0.0 + Final_test_B.P_bar[0]) *
      rtb_Product1;
    Final_test_B.K[1] = (Final_test_B.P_bar[3] * 0.0 + Final_test_B.P_bar[1]) *
      rtb_Product1;
    rtb_Product1 = Final_test_B.a - (0.0 * Final_test_B.xh_bar[1] +
      Final_test_B.xh_bar[0]);

    /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
     *  ZeroOrderHold: '<Root>/Zero-Order Hold'
     */
    if (Final_test_P.ManualSwitch1_CurrentSetting == 1) {
      Final_test_B.ManualSwitch1[0] = Final_test_B.Clock;
      Final_test_B.ManualSwitch1[1] = Final_test_B.TransferFcn1;
      Final_test_B.ManualSwitch1[2] = Final_test_B.Merge;
      Final_test_B.ManualSwitch1[3] = Final_test_B.e;
      Final_test_B.ManualSwitch1[4] = Final_test_B.a;
      Final_test_B.ManualSwitch1[5] = Final_test_B.Integrator1;
    } else {
      Final_test_B.ManualSwitch1[0] = 0.0;
      Final_test_B.ManualSwitch1[1] = 0.0;
      Final_test_B.ManualSwitch1[2] = 0.0;
      Final_test_B.ManualSwitch1[3] = 0.0;
      Final_test_B.ManualSwitch1[4] = 0.0;
      Final_test_B.ManualSwitch1[5] = 0.0;
    }

    for (i = 0; i < 2; i++) {
      /* MATLAB Function: '<S1>/MATLAB Function' */
      Final_test_DW.xh[i] = Final_test_B.K[i] * rtb_Product1 +
        Final_test_B.xh_bar[i];
      Final_test_B.a_m[i] = 1.0 - Final_test_B.K[i];
      Final_test_B.a_m[i + 2] = 1.0 - Final_test_B.K[i] * 0.0;
      Final_test_DW.P[i] = 0.0;
      Final_test_DW.P[i] += Final_test_B.a_m[i] * Final_test_B.P_bar[0];
      Final_test_DW.P[i] += Final_test_B.a_m[i + 2] * Final_test_B.P_bar[1];
      Final_test_DW.P[i + 2] = 0.0;
      Final_test_DW.P[i + 2] += Final_test_B.a_m[i] * Final_test_B.P_bar[2];
      Final_test_DW.P[i + 2] += Final_test_B.a_m[i + 2] * Final_test_B.P_bar[3];

      /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
       *  MATLAB Function: '<S1>/MATLAB Function'
       */
      if (Final_test_P.ManualSwitch1_CurrentSetting == 1) {
        Final_test_B.ManualSwitch1[i + 6] = Final_test_DW.xh[i];
      } else {
        Final_test_B.ManualSwitch1[i + 6] = 0.0;
      }
    }

    /* Math: '<S55>/Math Function1' incorporates:
     *  Constant: '<S55>/a'
     */
    if ((rtb_PWMsaturation < 0.0) && (Final_test_P.a_Value_d > floor
         (Final_test_P.a_Value_d))) {
      rtb_Product1 = -rt_powd_snf(-rtb_PWMsaturation, Final_test_P.a_Value_d);
    } else {
      rtb_Product1 = rt_powd_snf(rtb_PWMsaturation, Final_test_P.a_Value_d);
    }

    /* End of Math: '<S55>/Math Function1' */

    /* Gain: '<S9>/Gain2' incorporates:
     *  Constant: '<S55>/c'
     *  Gain: '<S55>/b'
     *  Product: '<S9>/Product1'
     *  Sum: '<S55>/Sum1'
     */
    Final_test_B.Gain2 = (Final_test_P.b_Gain_n * rtb_Product1 +
                          Final_test_P.c_Value_e) * rtb_PWMsaturation *
      Final_test_P.Gain2_Gain;
  }

  /* Integrator: '<S9>/Integrator' */
  Final_test_B.Integrator = Final_test_X.Integrator_CSTATE;

  /* Sum: '<S9>/Sum' incorporates:
   *  Gain: '<S9>/Gain'
   *  Gain: '<S9>/Gain1'
   */
  Final_test_B.Sum = (Final_test_B.Gain2 - Final_test_P.Gain1_Gain_h *
                      Final_test_B.Integrator1) - Final_test_P.Gain_Gain_n *
    Final_test_B.Integrator;
  if (rtmIsMajorTimeStep(Final_test_M)) {
    /* Gain: '<S54>/Integral Gain' */
    rtb_IntegralGain = Final_test_P.DiscretePIDController_I *
      Final_test_B.Product;
  }

  /* Start for MATLABSystem: '<Root>/Moving Average' */
  if (Final_test_DW.obj.TunablePropsChanged) {
    Final_test_DW.obj.TunablePropsChanged = false;
  }

  if (Final_test_DW.obj.pStatistic->isInitialized != 1) {
    Final_test_DW.obj.pStatistic->isSetupComplete = false;
    Final_test_DW.obj.pStatistic->isInitialized = 1;
    Final_test_DW.obj.pStatistic->pCumSum = 0.0;
    Final_test_DW.obj.pStatistic->pCumRevIndex = 1.0;
    Final_test_DW.obj.pStatistic->isSetupComplete = true;
    Final_test_DW.obj.pStatistic->pCumSum = 0.0;
    Final_test_DW.obj.pStatistic->pCumSumRev[0] = 0.0;
    Final_test_DW.obj.pStatistic->pCumSumRev[0] = 0.0;
    Final_test_DW.obj.pStatistic->pCumSumRev[1] = 0.0;
    Final_test_DW.obj.pStatistic->pCumSumRev[1] = 0.0;
    Final_test_DW.obj.pStatistic->pCumSumRev[2] = 0.0;
    Final_test_DW.obj.pStatistic->pCumSumRev[2] = 0.0;
    Final_test_DW.obj.pStatistic->pCumSumRev[3] = 0.0;
    Final_test_DW.obj.pStatistic->pCumSumRev[3] = 0.0;
    Final_test_DW.obj.pStatistic->pCumRevIndex = 1.0;
  }

  rtb_PWMsaturation = Final_test_DW.obj.pStatistic->pCumRevIndex;
  rtb_Product1 = Final_test_DW.obj.pStatistic->pCumSum;
  Final_test_B.P_bar[0] = Final_test_DW.obj.pStatistic->pCumSumRev[0];
  Final_test_B.P_bar[1] = Final_test_DW.obj.pStatistic->pCumSumRev[1];
  Final_test_B.P_bar[2] = Final_test_DW.obj.pStatistic->pCumSumRev[2];
  Final_test_B.P_bar[3] = Final_test_DW.obj.pStatistic->pCumSumRev[3];
  rtb_Product1 += Final_test_B.TransferFcn1;
  i = (int32_T)rtb_PWMsaturation - 1;
  Final_test_B.z = Final_test_B.P_bar[i] + rtb_Product1;
  Final_test_B.P_bar[i] = Final_test_B.TransferFcn1;
  if (rtb_PWMsaturation != 4.0) {
    rtb_PWMsaturation++;
  } else {
    rtb_PWMsaturation = 1.0;
    rtb_Product1 = 0.0;
    Final_test_B.P_bar[2] += Final_test_B.P_bar[3];
    Final_test_B.P_bar[1] += Final_test_B.P_bar[2];
    Final_test_B.P_bar[0] += Final_test_B.P_bar[1];
  }

  Final_test_DW.obj.pStatistic->pCumSum = rtb_Product1;
  Final_test_DW.obj.pStatistic->pCumSumRev[0] = Final_test_B.P_bar[0];
  Final_test_DW.obj.pStatistic->pCumSumRev[1] = Final_test_B.P_bar[1];
  Final_test_DW.obj.pStatistic->pCumSumRev[2] = Final_test_B.P_bar[2];
  Final_test_DW.obj.pStatistic->pCumSumRev[3] = Final_test_B.P_bar[3];
  Final_test_DW.obj.pStatistic->pCumRevIndex = rtb_PWMsaturation;

  /* MATLABSystem: '<Root>/Moving Average' */
  Final_test_B.MovingAverage = Final_test_B.z / 5.0;
  if (rtmIsMajorTimeStep(Final_test_M)) {
    /* Start for MATLABSystem: '<S4>/Analog Input' */
    p = false;
    p_0 = true;
    if (!(Final_test_DW.obj_g.SampleTime == Final_test_P.AnalogInput_SampleTime))
    {
      p_0 = false;
    }

    if (p_0) {
      p = true;
    }

    if (!p) {
      Final_test_DW.obj_g.SampleTime = Final_test_P.AnalogInput_SampleTime;
    }

    MW_AnalogIn_Start(Final_test_DW.obj_g.MW_ANALOGIN_HANDLE);
    MW_AnalogInSingle_ReadResult(Final_test_DW.obj_g.MW_ANALOGIN_HANDLE,
      &rtb_AnalogInput_0, 3);

    /* End of Start for MATLABSystem: '<S4>/Analog Input' */

    /* ZeroOrderHold: '<S4>/Zero-Order Hold1' incorporates:
     *  DataTypeConversion: '<S4>/Cast'
     *  MATLABSystem: '<S4>/Analog Input'
     */
    Final_test_B.ZeroOrderHold1 = rtb_AnalogInput_0;

    /* Start for MATLABSystem: '<S3>/PWM1' */
    MW_PWM_SetDutyCycle(Final_test_DW.obj_n.MW_PWM_HANDLE, Final_test_B.Merge);
  }

  if (rtmIsMajorTimeStep(Final_test_M)) {
    if (rtmIsMajorTimeStep(Final_test_M)) {
      /* Update for UnitDelay: '<S53>/Delay Input1' incorporates:
       *  Constant: '<Root>/Automatic Control'
       */
      Final_test_DW.DelayInput1_DSTATE = Final_test_P.AutomaticControl_Value;

      /* Update for DiscreteIntegrator: '<S54>/Integrator' */
      Final_test_DW.Integrator_DSTATE += Final_test_P.Integrator_gainval *
        rtb_IntegralGain;
      Final_test_DW.Integrator_PrevResetState = (int8_T)
        rtb_FixPtRelationalOperator;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, Final_test_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(Final_test_M)) {/* Sample time: [0.01s, 0.0s] */
      rtExtModeUpload(1, (((Final_test_M->Timing.clockTick1+
                            Final_test_M->Timing.clockTickH1* 4294967296.0)) *
                          0.01));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(Final_test_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(Final_test_M)!=-1) &&
          !((rtmGetTFinal(Final_test_M)-(((Final_test_M->Timing.clockTick1+
               Final_test_M->Timing.clockTickH1* 4294967296.0)) * 0.01)) >
            (((Final_test_M->Timing.clockTick1+Final_test_M->Timing.clockTickH1*
               4294967296.0)) * 0.01) * (DBL_EPSILON))) {
        rtmSetErrorStatus(Final_test_M, "Simulation finished");
      }

      if (rtmGetStopRequested(Final_test_M)) {
        rtmSetErrorStatus(Final_test_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&Final_test_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Final_test_M->Timing.clockTick0)) {
      ++Final_test_M->Timing.clockTickH0;
    }

    Final_test_M->Timing.t[0] = rtsiGetSolverStopTime(&Final_test_M->solverInfo);

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
      Final_test_M->Timing.clockTick1++;
      if (!Final_test_M->Timing.clockTick1) {
        Final_test_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void Final_test_derivatives(void)
{
  XDot_Final_test_T *_rtXdot;
  _rtXdot = ((XDot_Final_test_T *) Final_test_M->derivs);

  /* Derivatives for TransferFcn: '<S4>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = 0.0;
  _rtXdot->TransferFcn1_CSTATE += Final_test_P.TransferFcn1_A *
    Final_test_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += Final_test_B.ZeroOrderHold1;

  /* Derivatives for Integrator: '<S9>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = Final_test_B.Integrator;

  /* Derivatives for Integrator: '<S9>/Integrator' */
  _rtXdot->Integrator_CSTATE = Final_test_B.Sum;
}

/* Model initialize function */
void Final_test_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Final_test_M, 0,
                sizeof(RT_MODEL_Final_test_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Final_test_M->solverInfo,
                          &Final_test_M->Timing.simTimeStep);
    rtsiSetTPtr(&Final_test_M->solverInfo, &rtmGetTPtr(Final_test_M));
    rtsiSetStepSizePtr(&Final_test_M->solverInfo,
                       &Final_test_M->Timing.stepSize0);
    rtsiSetdXPtr(&Final_test_M->solverInfo, &Final_test_M->derivs);
    rtsiSetContStatesPtr(&Final_test_M->solverInfo, (real_T **)
                         &Final_test_M->contStates);
    rtsiSetNumContStatesPtr(&Final_test_M->solverInfo,
      &Final_test_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Final_test_M->solverInfo,
      &Final_test_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Final_test_M->solverInfo,
      &Final_test_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Final_test_M->solverInfo,
      &Final_test_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Final_test_M->solverInfo, (&rtmGetErrorStatus
      (Final_test_M)));
    rtsiSetRTModelPtr(&Final_test_M->solverInfo, Final_test_M);
  }

  rtsiSetSimTimeStep(&Final_test_M->solverInfo, MAJOR_TIME_STEP);
  Final_test_M->intgData.y = Final_test_M->odeY;
  Final_test_M->intgData.f[0] = Final_test_M->odeF[0];
  Final_test_M->intgData.f[1] = Final_test_M->odeF[1];
  Final_test_M->intgData.f[2] = Final_test_M->odeF[2];
  Final_test_M->contStates = ((X_Final_test_T *) &Final_test_X);
  rtsiSetSolverData(&Final_test_M->solverInfo, (void *)&Final_test_M->intgData);
  rtsiSetSolverName(&Final_test_M->solverInfo,"ode3");
  rtmSetTPtr(Final_test_M, &Final_test_M->Timing.tArray[0]);
  rtmSetTFinal(Final_test_M, -1);
  Final_test_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  Final_test_M->Sizes.checksums[0] = (2946863433U);
  Final_test_M->Sizes.checksums[1] = (1710839790U);
  Final_test_M->Sizes.checksums[2] = (2091369673U);
  Final_test_M->Sizes.checksums[3] = (1246343091U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    Final_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)&Final_test_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&Final_test_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[7] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Final_test_M->extModeInfo,
      &Final_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Final_test_M->extModeInfo, Final_test_M->Sizes.checksums);
    rteiSetTPtr(Final_test_M->extModeInfo, rtmGetTPtr(Final_test_M));
  }

  /* block I/O */
  (void) memset(((void *) &Final_test_B), 0,
                sizeof(B_Final_test_T));

  /* states (continuous) */
  {
    (void) memset((void *)&Final_test_X, 0,
                  sizeof(X_Final_test_T));
  }

  /* states (dwork) */
  (void) memset((void *)&Final_test_DW, 0,
                sizeof(DW_Final_test_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Final_test_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_in_fd_T *obj;
    MW_AnalogIn_TriggerSource_Type trigger_val;
    codertarget_arduinobase_int_f_T *obj_0;

    /* Start for FromWorkspace: '<S5>/FromWs' */
    {
      static real_T pTimeValues0[] = { 0.0, 30.0, 30.0, 60.0, 60.0, 90.0, 90.0,
        120.0, 120.0, 150.0, 150.0, 180.0, 180.0, 210.0, 210.0, 240.0, 240.0,
        270.0, 270.0, 300.0, 300.0, 340.0 } ;

      static real_T pDataValues0[] = { 0.0, 0.0, 4.0, 4.0, 6.0, 6.0, 8.0, 8.0,
        10.0, 10.0, 12.0, 12.0, 14.0, 14.0, 16.0, 16.0, 18.0, 18.0, 20.0, 20.0,
        0.0, 0.0 } ;

      Final_test_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
      Final_test_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
      Final_test_DW.FromWs_IWORK.PrevIndex = 0;
    }

    /* Start for If: '<S3>/If' */
    Final_test_DW.If_ActiveSubsystem = -1;

    /* Start for MATLABSystem: '<Root>/Moving Average' */
    Final_test_DW.obj.matlabCodegenIsDeleted = true;
    Final_test_DW.obj.isInitialized = 0;
    Final_test_DW.obj.NumChannels = -1;
    Final_test_DW.obj.matlabCodegenIsDeleted = false;
    Final_test_DW.objisempty_h = true;
    Final_test_DW.obj.isSetupComplete = false;
    Final_test_DW.obj.isInitialized = 1;
    Final_test_DW.obj.NumChannels = 1;
    Final_test_DW.gobj_0.isInitialized = 0;
    Final_test_DW.obj.pStatistic = &Final_test_DW.gobj_0;
    Final_test_DW.obj.isSetupComplete = true;
    Final_test_DW.obj.TunablePropsChanged = false;

    /* Start for MATLABSystem: '<S4>/Analog Input' */
    Final_test_DW.obj_g.matlabCodegenIsDeleted = true;
    obj = &Final_test_DW.obj_g;
    Final_test_DW.obj_g.isInitialized = 0;
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
    Final_test_DW.obj_g.matlabCodegenIsDeleted = false;
    Final_test_DW.objisempty = true;
    Final_test_DW.obj_g.SampleTime = Final_test_P.AnalogInput_SampleTime;
    obj = &Final_test_DW.obj_g;
    Final_test_DW.obj_g.isSetupComplete = false;
    Final_test_DW.obj_g.isInitialized = 1;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(2U);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(Final_test_DW.obj_g.MW_ANALOGIN_HANDLE,
      trigger_val, 0U);
    Final_test_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/PWM1' */
    Final_test_DW.obj_n.matlabCodegenIsDeleted = true;
    arduino_PWMOutput_arduino_PWMOu(&Final_test_DW.obj_n);
    Final_test_DW.objisempty_b = true;
    obj_0 = &Final_test_DW.obj_n;
    Final_test_DW.obj_n.isSetupComplete = false;
    Final_test_DW.obj_n.isInitialized = 1;
    obj_0->MW_PWM_HANDLE = MW_PWM_Open(12U, 0.0, 0.0);
    MW_PWM_Start(Final_test_DW.obj_n.MW_PWM_HANDLE);
    Final_test_DW.obj_n.isSetupComplete = true;
  }

  /* InitializeConditions for TransferFcn: '<S4>/Transfer Fcn1' */
  Final_test_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S53>/Delay Input1' */
  Final_test_DW.DelayInput1_DSTATE = Final_test_P.DetectChange_vinit;

  /* InitializeConditions for DiscreteIntegrator: '<S54>/Integrator' */
  Final_test_DW.Integrator_DSTATE = Final_test_P.Integrator_IC;
  Final_test_DW.Integrator_PrevResetState = 2;

  /* InitializeConditions for Integrator: '<S9>/Integrator1' */
  Final_test_X.Integrator1_CSTATE = Final_test_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S9>/Integrator' */
  Final_test_X.Integrator_CSTATE = Final_test_P.Integrator_IC_e;

  /* SystemInitialize for MATLAB Function: '<S1>/MATLAB Function' */
  Final_test_DW.P[0] = 0.0;
  Final_test_DW.P[1] = 0.0;
  Final_test_DW.P[2] = 0.0;
  Final_test_DW.P[3] = 0.0;
  Final_test_DW.P[0] = 1.0;
  Final_test_DW.xh[0] = 0.0;
  Final_test_DW.P[3] = 1.0;
  Final_test_DW.xh[1] = 0.0;

  /* Start for MATLABSystem: '<Root>/Moving Average' */
  if (Final_test_DW.obj.pStatistic->isInitialized == 1) {
    Final_test_DW.obj.pStatistic->pCumSum = 0.0;
    Final_test_DW.obj.pStatistic->pCumSumRev[0] = 0.0;
    Final_test_DW.obj.pStatistic->pCumSumRev[1] = 0.0;
    Final_test_DW.obj.pStatistic->pCumSumRev[2] = 0.0;
    Final_test_DW.obj.pStatistic->pCumSumRev[3] = 0.0;
    Final_test_DW.obj.pStatistic->pCumRevIndex = 1.0;
  }

  /* End of Start for MATLABSystem: '<Root>/Moving Average' */
}

/* Model terminate function */
void Final_test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Moving Average' */
  matlabCodegenHandle_matlabCodeg(&Final_test_DW.obj);

  /* Terminate for MATLABSystem: '<S4>/Analog Input' */
  matlabCodegenHandle_matlabCo_fd(&Final_test_DW.obj_g);

  /* Terminate for MATLABSystem: '<S3>/PWM1' */
  matlabCodegenHandle_matlabCod_f(&Final_test_DW.obj_n);
}
