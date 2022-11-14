/*
 * tester.c
 *
 * Real-Time Workshop code generation for Simulink model "tester.mdl".
 *
 * Model Version              : 1.18
 * Real-Time Workshop version : 7.3  (R2009a)  15-Jan-2009
 * C source code generated on : Fri Apr 12 15:29:55 2013
 *
 * Target selection: rtwin.tlc
 *   Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "tester.h"
#include "tester_private.h"
#include <stdio.h>
#include "tester_dt.h"

/* list of Real-Time Windows Target boards */
const int RTWinBoardCount = 1;
RTWINBOARD RTWinBoards[1] = {
  { "Quanser/MultiQ-PCI", 4294967295U, 0, NULL },
};

/* Block signals (auto storage) */
BlockIO_tester tester_B;

/* Continuous states */
ContinuousStates_tester tester_X;

/* Block states (auto storage) */
D_Work_tester tester_DWork;

/* Real-time model */
RT_MODEL_tester tester_M_;
RT_MODEL_tester *tester_M = &tester_M_;

/* This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  tester_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void tester_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_AnalogInput;

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(tester_M)) {
    tester_M->Timing.t[0] = rtsiGetT(&tester_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(tester_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&tester_M->solverInfo,
                          ((tester_M->Timing.clockTick0+1)*
      tester_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  {
    real_T currentTime;
    if (rtmIsMajorTimeStep(tester_M)) {
      /* S-Function Block: <Root>/Analog Input */
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) tester_P.AnalogInput_RangeMode;
        parm.rangeidx = tester_P.AnalogInput_VoltRange;
        RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1, &tester_P.AnalogInput_Channels,
                       &rtb_AnalogInput, &parm);
      }
    }

    /* Step: '<Root>/Step' */
    currentTime = tester_M->Timing.t[0];
    if (currentTime < tester_P.Step_Time) {
      tester_B.Step = tester_P.Step_Y0;
    } else {
      tester_B.Step = tester_P.Step_YFinal;
    }

    /* Saturate: '<Root>/Limiter' */
    tester_B.Limiter = rt_SATURATE(tester_B.Step, tester_P.Limiter_LowerSat,
      tester_P.Limiter_UpperSat);
    if (rtmIsMajorTimeStep(tester_M)) {
      /* S-Function Block: <Root>/Analog Output */
      {
        {
          ANALOGIOPARM parm;
          parm.mode = (RANGEMODE) tester_P.AnalogOutput_RangeMode;
          parm.rangeidx = tester_P.AnalogOutput_VoltRange;
          RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                         &tester_P.AnalogOutput_Channels, &tester_B.Limiter,
                         &parm);
        }
      }

      /* Gain: '<Root>/tacho omjer1' incorporates:
       *  Gain: '<Root>/tacho omjer'
       */
      tester_B.tachoomjer1 = tester_P.tachoomjer_Gain * rtb_AnalogInput *
        tester_P.tachoomjer1_Gain;
    }

    /* Integrator: '<S1>/Integrator' */
    currentTime = tester_X.Integrator_CSTATE;

    /* Gain: '<Root>/rad//s -> okr//min' */
    tester_B.radsokrmin = tester_P.radsokrmin_Gain * tester_X.Integrator_CSTATE;
    if (rtmIsMajorTimeStep(tester_M)) {
    }

    /* Gain: '<S1>/Inercija' incorporates:
     *  Gain: '<S1>/Napon - > Struja'
     *  Gain: '<S1>/Protuelektromotorna sila e'
     *  Gain: '<S1>/Stuja -> Moment'
     *  Gain: '<S1>/Viskozno trenje'
     *  Saturate: '<S1>/UPM napon zasicenja'
     *  Sum: '<S1>/Sum'
     *  Sum: '<S1>/Sum1'
     */
    tester_B.Inercija = ((rt_SATURATE(tester_B.Step,
      tester_P.UPMnaponzasicenja_LowerSat, tester_P.UPMnaponzasicenja_UpperSat)
                          - tester_P.Protuelektromotornasilae_Gain * currentTime)
                         * tester_P.NaponStruja_Gain * tester_P.StujaMoment_Gain
                         - tester_P.Viskoznotrenje_Gain * currentTime) *
      tester_P.Inercija_Gain;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void tester_update(int_T tid)
{
  if (rtmIsMajorTimeStep(tester_M)) {
    rt_ertODEUpdateContinuousStates(&tester_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++tester_M->Timing.clockTick0))
    ++tester_M->Timing.clockTickH0;
  tester_M->Timing.t[0] = tester_M->Timing.clockTick0 *
    tester_M->Timing.stepSize0 + tester_M->Timing.clockTickH0 *
    tester_M->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(tester_M)) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++tester_M->Timing.clockTick1))
      ++tester_M->Timing.clockTickH1;
    tester_M->Timing.t[1] = tester_M->Timing.clockTick1 *
      tester_M->Timing.stepSize1 + tester_M->Timing.clockTickH1 *
      tester_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void tester_derivatives(void)
{
  /* Derivatives for Integrator: '<S1>/Integrator' */
  ((StateDerivatives_tester *) tester_M->ModelData.derivs)->Integrator_CSTATE =
    tester_B.Inercija;
}

/* Model initialize function */
void tester_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)tester_M,0,
                sizeof(RT_MODEL_tester));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&tester_M->solverInfo, &tester_M->Timing.simTimeStep);
    rtsiSetTPtr(&tester_M->solverInfo, &rtmGetTPtr(tester_M));
    rtsiSetStepSizePtr(&tester_M->solverInfo, &tester_M->Timing.stepSize0);
    rtsiSetdXPtr(&tester_M->solverInfo, &tester_M->ModelData.derivs);
    rtsiSetContStatesPtr(&tester_M->solverInfo, &tester_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&tester_M->solverInfo,
      &tester_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&tester_M->solverInfo, (&rtmGetErrorStatus(tester_M)));
    rtsiSetRTModelPtr(&tester_M->solverInfo, tester_M);
  }

  rtsiSetSimTimeStep(&tester_M->solverInfo, MAJOR_TIME_STEP);
  tester_M->ModelData.intgData.f[0] = tester_M->ModelData.odeF[0];
  tester_M->ModelData.contStates = ((real_T *) &tester_X);
  rtsiSetSolverData(&tester_M->solverInfo, (void *)&tester_M->ModelData.intgData);
  rtsiSetSolverName(&tester_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = tester_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    tester_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    tester_M->Timing.sampleTimes = (&tester_M->Timing.sampleTimesArray[0]);
    tester_M->Timing.offsetTimes = (&tester_M->Timing.offsetTimesArray[0]);

    /* task periods */
    tester_M->Timing.sampleTimes[0] = (0.0);
    tester_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    tester_M->Timing.offsetTimes[0] = (0.0);
    tester_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(tester_M, &tester_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = tester_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    tester_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(tester_M, 4.0);
  tester_M->Timing.stepSize0 = 0.001;
  tester_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  tester_M->Sizes.checksums[0] = (245854373U);
  tester_M->Sizes.checksums[1] = (143115081U);
  tester_M->Sizes.checksums[2] = (137583178U);
  tester_M->Sizes.checksums[3] = (2070970804U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    tester_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &tester_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, tester_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(tester_M));
  }

  tester_M->solverInfoPtr = (&tester_M->solverInfo);
  tester_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&tester_M->solverInfo, 0.001);
  rtsiSetSolverMode(&tester_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  tester_M->ModelData.blockIO = ((void *) &tester_B);
  (void) memset(((void *) &tester_B),0,
                sizeof(BlockIO_tester));

  /* parameters */
  tester_M->ModelData.defaultParam = ((real_T *) &tester_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &tester_X;
    tester_M->ModelData.contStates = (x);
    (void) memset((void *)x,0,
                  sizeof(ContinuousStates_tester));
  }

  /* states (dwork) */
  tester_M->Work.dwork = ((void *) &tester_DWork);
  (void) memset((void *)&tester_DWork, 0,
                sizeof(D_Work_tester));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    tester_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void tester_terminate(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) tester_P.AnalogOutput_RangeMode;
      parm.rangeidx = tester_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &tester_P.AnalogOutput_Channels,
                     &tester_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  tester_output(tid);
}

void MdlUpdate(int_T tid)
{
  tester_update(tid);
}

void MdlInitializeSizes(void)
{
  tester_M->Sizes.numContStates = (1); /* Number of continuous states */
  tester_M->Sizes.numY = (0);          /* Number of model outputs */
  tester_M->Sizes.numU = (0);          /* Number of model inputs */
  tester_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  tester_M->Sizes.numSampTimes = (2);  /* Number of sample times */
  tester_M->Sizes.numBlocks = (19);    /* Number of blocks */
  tester_M->Sizes.numBlockIO = (5);    /* Number of block outputs */
  tester_M->Sizes.numBlockPrms = (24); /* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  tester_X.Integrator_CSTATE = tester_P.Integrator_IC;
}

void MdlStart(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) tester_P.AnalogOutput_RangeMode;
      parm.rangeidx = tester_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &tester_P.AnalogOutput_Channels,
                     &tester_P.AnalogOutput_InitialValue, &parm);
    }
  }

  MdlInitialize();
}

RT_MODEL_tester *tester(void)
{
  tester_initialize(1);
  return tester_M;
}

void MdlTerminate(void)
{
  tester_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
