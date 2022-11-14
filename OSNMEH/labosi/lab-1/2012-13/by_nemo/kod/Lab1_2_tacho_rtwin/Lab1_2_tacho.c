/*
 * Lab1_2_tacho.c
 *
 * Real-Time Workshop code generation for Simulink model "Lab1_2_tacho.mdl".
 *
 * Model Version              : 1.11
 * Real-Time Workshop version : 7.3  (R2009a)  15-Jan-2009
 * C source code generated on : Thu Mar 21 20:03:56 2013
 *
 * Target selection: rtwin.tlc
 *   Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Lab1_2_tacho.h"
#include "Lab1_2_tacho_private.h"
#include <stdio.h>
#include "Lab1_2_tacho_dt.h"

/* list of Real-Time Windows Target boards */
const int RTWinBoardCount = 1;
RTWINBOARD RTWinBoards[1] = {
  { "Quanser/MultiQ-PCI", 4294967295U, 0, NULL },
};

/* Block signals (auto storage) */
BlockIO_Lab1_2_tacho Lab1_2_tacho_B;

/* Block states (auto storage) */
D_Work_Lab1_2_tacho Lab1_2_tacho_DWork;

/* Real-time model */
RT_MODEL_Lab1_2_tacho Lab1_2_tacho_M_;
RT_MODEL_Lab1_2_tacho *Lab1_2_tacho_M = &Lab1_2_tacho_M_;

/* Model output function */
void Lab1_2_tacho_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_AnalogInput;
  real_T rtb_SignalGenerator;

  /* S-Function Block: <Root>/Analog Input */
  {
    ANALOGIOPARM parm;
    parm.mode = (RANGEMODE) Lab1_2_tacho_P.AnalogInput_RangeMode;
    parm.rangeidx = Lab1_2_tacho_P.AnalogInput_VoltRange;
    RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                   &Lab1_2_tacho_P.AnalogInput_Channels, &rtb_AnalogInput, &parm);
  }

  /* SignalGenerator: '<Root>/Signal Generator' */
  {
    real_T phase = Lab1_2_tacho_P.SignalGenerator_Frequency*
      Lab1_2_tacho_M->Timing.t[0];
    phase = phase-floor(phase);
    rtb_SignalGenerator = ( phase >= 0.5 ) ?
      Lab1_2_tacho_P.SignalGenerator_Amplitude :
      -Lab1_2_tacho_P.SignalGenerator_Amplitude;
  }

  /* Saturate: '<Root>/Saturation' */
  Lab1_2_tacho_B.Saturation = rt_SATURATE(rtb_SignalGenerator,
    Lab1_2_tacho_P.Saturation_LowerSat, Lab1_2_tacho_P.Saturation_UpperSat);

  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Lab1_2_tacho_P.AnalogOutput_RangeMode;
      parm.rangeidx = Lab1_2_tacho_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Lab1_2_tacho_P.AnalogOutput_Channels,
                     &Lab1_2_tacho_B.Saturation, &parm);
    }
  }

  /* Gain: '<Root>/Gain1' */
  Lab1_2_tacho_B.Gain1 = Lab1_2_tacho_P.Gain1_Gain * rtb_AnalogInput;

  /* Gain: '<Root>/Gain' */
  Lab1_2_tacho_B.Gain = Lab1_2_tacho_P.Gain_Gain * rtb_AnalogInput;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void Lab1_2_tacho_update(int_T tid)
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
  if (!(++Lab1_2_tacho_M->Timing.clockTick0))
    ++Lab1_2_tacho_M->Timing.clockTickH0;
  Lab1_2_tacho_M->Timing.t[0] = Lab1_2_tacho_M->Timing.clockTick0 *
    Lab1_2_tacho_M->Timing.stepSize0 + Lab1_2_tacho_M->Timing.clockTickH0 *
    Lab1_2_tacho_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++Lab1_2_tacho_M->Timing.clockTick1))
      ++Lab1_2_tacho_M->Timing.clockTickH1;
    Lab1_2_tacho_M->Timing.t[1] = Lab1_2_tacho_M->Timing.clockTick1 *
      Lab1_2_tacho_M->Timing.stepSize1 + Lab1_2_tacho_M->Timing.clockTickH1 *
      Lab1_2_tacho_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void Lab1_2_tacho_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Lab1_2_tacho_M,0,
                sizeof(RT_MODEL_Lab1_2_tacho));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Lab1_2_tacho_M->solverInfo,
                          &Lab1_2_tacho_M->Timing.simTimeStep);
    rtsiSetTPtr(&Lab1_2_tacho_M->solverInfo, &rtmGetTPtr(Lab1_2_tacho_M));
    rtsiSetStepSizePtr(&Lab1_2_tacho_M->solverInfo,
                       &Lab1_2_tacho_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Lab1_2_tacho_M->solverInfo, (&rtmGetErrorStatus
      (Lab1_2_tacho_M)));
    rtsiSetRTModelPtr(&Lab1_2_tacho_M->solverInfo, Lab1_2_tacho_M);
  }

  rtsiSetSimTimeStep(&Lab1_2_tacho_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Lab1_2_tacho_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Lab1_2_tacho_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Lab1_2_tacho_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Lab1_2_tacho_M->Timing.sampleTimes =
      (&Lab1_2_tacho_M->Timing.sampleTimesArray[0]);
    Lab1_2_tacho_M->Timing.offsetTimes =
      (&Lab1_2_tacho_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Lab1_2_tacho_M->Timing.sampleTimes[0] = (0.0);
    Lab1_2_tacho_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Lab1_2_tacho_M->Timing.offsetTimes[0] = (0.0);
    Lab1_2_tacho_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Lab1_2_tacho_M, &Lab1_2_tacho_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Lab1_2_tacho_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Lab1_2_tacho_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Lab1_2_tacho_M, 10.0);
  Lab1_2_tacho_M->Timing.stepSize0 = 0.001;
  Lab1_2_tacho_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  Lab1_2_tacho_M->Sizes.checksums[0] = (1529650101U);
  Lab1_2_tacho_M->Sizes.checksums[1] = (1174119479U);
  Lab1_2_tacho_M->Sizes.checksums[2] = (1994721394U);
  Lab1_2_tacho_M->Sizes.checksums[3] = (940111242U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Lab1_2_tacho_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &Lab1_2_tacho_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, Lab1_2_tacho_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(Lab1_2_tacho_M));
  }

  Lab1_2_tacho_M->solverInfoPtr = (&Lab1_2_tacho_M->solverInfo);
  Lab1_2_tacho_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Lab1_2_tacho_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Lab1_2_tacho_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Lab1_2_tacho_M->ModelData.blockIO = ((void *) &Lab1_2_tacho_B);
  (void) memset(((void *) &Lab1_2_tacho_B),0,
                sizeof(BlockIO_Lab1_2_tacho));

  /* parameters */
  Lab1_2_tacho_M->ModelData.defaultParam = ((real_T *) &Lab1_2_tacho_P);

  /* states (dwork) */
  Lab1_2_tacho_M->Work.dwork = ((void *) &Lab1_2_tacho_DWork);
  (void) memset((void *)&Lab1_2_tacho_DWork, 0,
                sizeof(D_Work_Lab1_2_tacho));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    Lab1_2_tacho_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void Lab1_2_tacho_terminate(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Lab1_2_tacho_P.AnalogOutput_RangeMode;
      parm.rangeidx = Lab1_2_tacho_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Lab1_2_tacho_P.AnalogOutput_Channels,
                     &Lab1_2_tacho_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Lab1_2_tacho_output(tid);
}

void MdlUpdate(int_T tid)
{
  Lab1_2_tacho_update(tid);
}

void MdlInitializeSizes(void)
{
  Lab1_2_tacho_M->Sizes.numContStates = (0);/* Number of continuous states */
  Lab1_2_tacho_M->Sizes.numY = (0);    /* Number of model outputs */
  Lab1_2_tacho_M->Sizes.numU = (0);    /* Number of model inputs */
  Lab1_2_tacho_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Lab1_2_tacho_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Lab1_2_tacho_M->Sizes.numBlocks = (9);/* Number of blocks */
  Lab1_2_tacho_M->Sizes.numBlockIO = (3);/* Number of block outputs */
  Lab1_2_tacho_M->Sizes.numBlockPrms = (14);/* Sum of parameter "widths" */
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
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Lab1_2_tacho_P.AnalogOutput_RangeMode;
      parm.rangeidx = Lab1_2_tacho_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Lab1_2_tacho_P.AnalogOutput_Channels,
                     &Lab1_2_tacho_P.AnalogOutput_InitialValue, &parm);
    }
  }

  MdlInitialize();
}

RT_MODEL_Lab1_2_tacho *Lab1_2_tacho(void)
{
  Lab1_2_tacho_initialize(1);
  return Lab1_2_tacho_M;
}

void MdlTerminate(void)
{
  Lab1_2_tacho_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
