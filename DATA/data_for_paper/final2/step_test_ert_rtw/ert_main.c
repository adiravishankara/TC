#include "step_test.h"
#include "rtwtypes.h"
#include <ext_work.h>
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  step_test_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  noInterrupts();

#endif;

  OverrunFlag--;
  rtExtModeCheckEndTrigger();
}

volatile boolean_T stopRequested = false;
int main(void)
{
  volatile boolean_T runModel = true;
  float modelBaseRate = 0.01;
  float systemClock = 0;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(step_test_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  step_test_initialize();
  interrupts();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(step_test_M));
  rtExtModeCheckInit(2);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(step_test_M->extModeInfo, 2, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(step_test_M, true);
    }
  }

  rtERTExtModeStartMsg();
  noInterrupts();
  configureArduinoARMTimer();
  runModel =
    (rtmGetErrorStatus(step_test_M) == (NULL)) && !rtmGetStopRequested
    (step_test_M);

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  interrupts();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(step_test_M->extModeInfo, 2, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(step_test_M, true);
      }
    }

    stopRequested = !(
                      (rtmGetErrorStatus(step_test_M) == (NULL)) &&
                      !rtmGetStopRequested(step_test_M));
    runModel = !(stopRequested);
    runModel = runModel && MW_Arduino_Loop();
  }

  rtExtModeShutdown(2);

  /* Disable rt_OneStep() here */

  /* Terminate model */
  step_test_terminate();
  noInterrupts();
  return 0;
}
