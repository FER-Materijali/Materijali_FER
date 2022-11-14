/*
 * Lab1_1.c
 *
 * Real-Time Workshop code generation for Simulink model "Lab1_1.mdl".
 *
 * Model Version              : 1.5
 * Real-Time Workshop version : 7.3  (R2009a)  15-Jan-2009
 * C source code generated on : Thu Mar 21 17:27:48 2013
 *
 * Target selection: rtwin.tlc
 *   Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Lab1_1.h"
#include "Lab1_1_private.h"
#include <stdio.h>
#include "Lab1_1_dt.h"

/* list of Real-Time Windows Target boards */
const int RTWinBoardCount = 1;
RTWINBOARD RTWinBoards[1] = {
  { "Quanser/MultiQ-PCI", 4294967295U, 0, NULL },
};

/* Block signals (auto storage) */
BlockIO_Lab1_1 Lab1_1_B;

/* Block states (auto storage) */
D_Work_Lab1_1 Lab1_1_DWork;

/* Real-time model */
RT_MODEL_Lab1_1 Lab1_1_M_;
RT_MODEL_Lab1_1 *Lab1_1_M = &Lab1_1_M_;

/* Model output function */
void Lab1_1_output(int_T tid)
{
  /* SignalGenerator: '<Root>/Signal Generator' */
  {
    real_T phase = Lab1_1_P.SignalGenerator_Frequency*Lab1_1_M->Timing.t[0];
    phase = 1.0-2.0*(phase-floor(phase));
    Lab1_1_B.SignalGenerator = Lab1_1_P.SignalGenerator_Amplitude*phase;
  }

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Lab1_1_P.AnalogOutput_RangeMode;
      parm.rangeidx = Lab1_1_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Lab1_1_P.AnalogOutput_Channels, &Lab1_1_B.SignalGenerator,
                     &parm);
    }
  }

  /* S-Function Block: <Root>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) Lab1_1_P.AnalogInput_RangeMode;
    parm.rangeidx = Lab1_1_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1, &Lab1_1_P.AnalogInput_Channels,
                   &Lab1_1_B.AnalogInput, &parm);
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void Lab1_1_update(int_T tid)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Lab1_1_M->Timing.clockTick0))
    ++Lab1_1_M->Timing.clockTickH0;
  Lab1_1_M->Timing.t[0] = Lab1_1_M->Timing.clockTick0 *
    Lab1_1_M->Timing.stepSize0 + Lab1_1_M->Timing.clockTickH0 *
    Lab1_1_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Lab1_1_M->Timing.clockTick1))
      ++Lab1_1_M->Timing.clockTickH1;
    Lab1_1_M->Timing.t[1] = Lab1_1_M->Timing.clockTick1 *
      Lab1_1_M->Timing.stepSize1 + Lab1_1_M->Timing.clockTickH1 *
      Lab1_1_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void Lab1_1_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Lab1_1_M,0,
                sizeof(RT_MODEL_Lab1_1));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Lab1_1_M->solverInfo, &Lab1_1_M->Timing.simTimeStep);
    rtsiSetTPtr(&Lab1_1_M->solverInfo, &rtmGetTPtr(Lab1_1_M));
    rtsiSetStepSizePtr(&Lab1_1_M->solverInfo, &Lab1_1_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Lab1_1_M->solverInfo, (&rtmGetErrorStatus(Lab1_1_M)));
    rtsiSetRTModelPtr(&Lab1_1_M->solverInfo, Lab1_1_M);
  }

  rtsiSetSimTimeStep(&Lab1_1_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Lab1_1_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Lab1_1_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Lab1_1_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Lab1_1_M->Timing.sampleTimes = (&Lab1_1_M->Timing.sampleTimesArray[0]);
    Lab1_1_M->Timing.offsetTimes = (&Lab1_1_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Lab1_1_M->Timing.sampleTimes[0] = (0.0);
    Lab1_1_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Lab1_1_M->Timing.offsetTimes[0] = (0.0);
    Lab1_1_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Lab1_1_M, &Lab1_1_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Lab1_1_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Lab1_1_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Lab1_1_M, 8.0);
  Lab1_1_M->Timing.stepSize0 = 0.001;
  Lab1_1_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  Lab1_1_M->Sizes.checksums[0] = (1615670247U);
  Lab1_1_M->Sizes.checksums[1] = (1105621495U);
  Lab1_1_M->Sizes.checksums[2] = (1869848546U);
  Lab1_1_M->Sizes.checksums[3] = (988458482U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Lab1_1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &Lab1_1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, Lab1_1_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(Lab1_1_M));
  }

  Lab1_1_M->solverInfoPtr = (&Lab1_1_M->solverInfo);
  Lab1_1_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Lab1_1_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Lab1_1_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Lab1_1_M->ModelData.blockIO = ((void *) &Lab1_1_B);
  (void) memset(((void *) &Lab1_1_B),0,
                sizeof(BlockIO_Lab1_1));

  /* parameters */
  Lab1_1_M->ModelData.defaultParam = ((real_T *) &Lab1_1_P);

  /* states (dwork) */
  Lab1_1_M->Work.dwork = ((void *) &Lab1_1_DWork);
  (void) memset((void *)&Lab1_1_DWork, 0,
                sizeof(D_Work_Lab1_1));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    Lab1_1_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void Lab1_1_terminate(void)
{
  /* S-Function Block: <Root>/Analog Output */

  /* no final value should be set */
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Lab1_1_output(tid);
}

void MdlUpdate(int_T tid)
{
  Lab1_1_update(tid);
}

void MdlInitializeSizes(void)
{
  Lab1_1_M->Sizes.numContStates = (0); /* Number of continuous states */
  Lab1_1_M->Sizes.numY = (0);          /* Number of model outputs */
  Lab1_1_M->Sizes.numU = (0);          /* Number of model inputs */
  Lab1_1_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Lab1_1_M->Sizes.numSampTimes = (2);  /* Number of sample times */
  Lab1_1_M->Sizes.numBlocks = (6);     /* Number of blocks */
  Lab1_1_M->Sizes.numBlockIO = (2);    /* Number of block outputs */
  Lab1_1_M->Sizes.numBlockPrms = (8);  /* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  /* S-Function Block: <Root>/Analog Output */

  /* no initial value should be set */
  MdlInitialize();
}

RT_MODEL_Lab1_1 *Lab1_1(void)
{
  Lab1_1_initialize(1);
  return Lab1_1_M;
}

void MdlTerminate(void)
{
  Lab1_1_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
