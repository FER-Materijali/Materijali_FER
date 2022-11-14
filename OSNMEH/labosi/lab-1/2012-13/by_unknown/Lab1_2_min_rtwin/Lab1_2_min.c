/*
 * Lab1_2_min.c
 *
 * Real-Time Workshop code generation for Simulink model "Lab1_2_min.mdl".
 *
 * Model Version              : 1.9
 * Real-Time Workshop version : 7.3  (R2009a)  15-Jan-2009
 * C source code generated on : Thu Mar 21 19:12:14 2013
 *
 * Target selection: rtwin.tlc
 *   Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Lab1_2_min.h"
#include "Lab1_2_min_private.h"
#include <stdio.h>
#include "Lab1_2_min_dt.h"

/* list of Real-Time Windows Target boards */
const int RTWinBoardCount = 1;
RTWINBOARD RTWinBoards[1] = {
  { "Quanser/MultiQ-PCI", 4294967295U, 0, NULL },
};

/* Block signals (auto storage) */
BlockIO_Lab1_2_min Lab1_2_min_B;

/* Block states (auto storage) */
D_Work_Lab1_2_min Lab1_2_min_DWork;

/* Real-time model */
RT_MODEL_Lab1_2_min Lab1_2_min_M_;
RT_MODEL_Lab1_2_min *Lab1_2_min_M = &Lab1_2_min_M_;

/* Model output function */
void Lab1_2_min_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_MathFunction;

  {
    real_T currentTime;

    /* SignalGenerator: '<Root>/Signal Generator' */
    {
      real_T phase = Lab1_2_min_P.SignalGenerator_Frequency*
        Lab1_2_min_M->Timing.t[0];
      phase = phase-floor(phase);
      rtb_MathFunction = ( phase >= 0.5 ) ?
        Lab1_2_min_P.SignalGenerator_Amplitude :
        -Lab1_2_min_P.SignalGenerator_Amplitude;
    }

    /* Saturate: '<Root>/Saturation' */
    Lab1_2_min_B.Saturation = rt_SATURATE(rtb_MathFunction,
      Lab1_2_min_P.Saturation_LowerSat, Lab1_2_min_P.Saturation_UpperSat);

    /* S-Function Block: <Root>/Analog Output */
    {
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) Lab1_2_min_P.AnalogOutput_RangeMode;
        parm.rangeidx = Lab1_2_min_P.AnalogOutput_VoltRange;
        RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                       &Lab1_2_min_P.AnalogOutput_Channels,
                       &Lab1_2_min_B.Saturation, &parm);
      }
    }

    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = Lab1_2_min_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &Lab1_2_min_P.EncoderInput_Channels,
                     &Lab1_2_min_B.EncoderInput, &parm);
    }

    /* Step: '<Root>/Step' */
    currentTime = Lab1_2_min_M->Timing.t[1];
    if (currentTime < Lab1_2_min_P.Step_Time) {
      currentTime = Lab1_2_min_P.Step_Y0;
    } else {
      currentTime = Lab1_2_min_P.Step_YFinal;
    }

    /* Sum: '<Root>/Sum' */
    Lab1_2_min_B.Sum = Lab1_2_min_B.EncoderInput + currentTime;

    /* Clock: '<Root>/Clock1' */
    rtb_MathFunction = Lab1_2_min_M->Timing.t[0];

    /* Math: '<Root>/Math Function' incorporates:
     *  Constant: '<Root>/Constant'
     */
    rtb_MathFunction = rt_mod_snf(rtb_MathFunction, Lab1_2_min_P.Constant_Value);

    /* Gain: '<Root>/Gain1' incorporates:
     *  Product: '<Root>/Divide'
     */
    Lab1_2_min_B.Gain1 = Lab1_2_min_B.Sum / rtb_MathFunction *
      Lab1_2_min_P.Gain1_Gain;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void Lab1_2_min_update(int_T tid)
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
  if (!(++Lab1_2_min_M->Timing.clockTick0))
    ++Lab1_2_min_M->Timing.clockTickH0;
  Lab1_2_min_M->Timing.t[0] = Lab1_2_min_M->Timing.clockTick0 *
    Lab1_2_min_M->Timing.stepSize0 + Lab1_2_min_M->Timing.clockTickH0 *
    Lab1_2_min_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++Lab1_2_min_M->Timing.clockTick1))
      ++Lab1_2_min_M->Timing.clockTickH1;
    Lab1_2_min_M->Timing.t[1] = Lab1_2_min_M->Timing.clockTick1 *
      Lab1_2_min_M->Timing.stepSize1 + Lab1_2_min_M->Timing.clockTickH1 *
      Lab1_2_min_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model initialize function */
void Lab1_2_min_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  Lab1_2_min_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)Lab1_2_min_M,0,
                sizeof(RT_MODEL_Lab1_2_min));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Lab1_2_min_M->solverInfo,
                          &Lab1_2_min_M->Timing.simTimeStep);
    rtsiSetTPtr(&Lab1_2_min_M->solverInfo, &rtmGetTPtr(Lab1_2_min_M));
    rtsiSetStepSizePtr(&Lab1_2_min_M->solverInfo,
                       &Lab1_2_min_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&Lab1_2_min_M->solverInfo, (&rtmGetErrorStatus
      (Lab1_2_min_M)));
    rtsiSetRTModelPtr(&Lab1_2_min_M->solverInfo, Lab1_2_min_M);
  }

  rtsiSetSimTimeStep(&Lab1_2_min_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&Lab1_2_min_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Lab1_2_min_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Lab1_2_min_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Lab1_2_min_M->Timing.sampleTimes = (&Lab1_2_min_M->Timing.sampleTimesArray[0]);
    Lab1_2_min_M->Timing.offsetTimes = (&Lab1_2_min_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Lab1_2_min_M->Timing.sampleTimes[0] = (0.0);
    Lab1_2_min_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Lab1_2_min_M->Timing.offsetTimes[0] = (0.0);
    Lab1_2_min_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Lab1_2_min_M, &Lab1_2_min_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Lab1_2_min_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Lab1_2_min_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Lab1_2_min_M, 10.0);
  Lab1_2_min_M->Timing.stepSize0 = 0.001;
  Lab1_2_min_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  Lab1_2_min_M->Sizes.checksums[0] = (699618759U);
  Lab1_2_min_M->Sizes.checksums[1] = (2264789928U);
  Lab1_2_min_M->Sizes.checksums[2] = (2130566168U);
  Lab1_2_min_M->Sizes.checksums[3] = (2647488127U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Lab1_2_min_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &Lab1_2_min_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, Lab1_2_min_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(Lab1_2_min_M));
  }

  Lab1_2_min_M->solverInfoPtr = (&Lab1_2_min_M->solverInfo);
  Lab1_2_min_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Lab1_2_min_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Lab1_2_min_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Lab1_2_min_M->ModelData.blockIO = ((void *) &Lab1_2_min_B);
  (void) memset(((void *) &Lab1_2_min_B),0,
                sizeof(BlockIO_Lab1_2_min));

  /* parameters */
  Lab1_2_min_M->ModelData.defaultParam = ((real_T *) &Lab1_2_min_P);

  /* states (dwork) */
  Lab1_2_min_M->Work.dwork = ((void *) &Lab1_2_min_DWork);
  (void) memset((void *)&Lab1_2_min_DWork, 0,
                sizeof(D_Work_Lab1_2_min));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    Lab1_2_min_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void Lab1_2_min_terminate(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Lab1_2_min_P.AnalogOutput_RangeMode;
      parm.rangeidx = Lab1_2_min_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Lab1_2_min_P.AnalogOutput_Channels,
                     &Lab1_2_min_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Lab1_2_min_output(tid);
}

void MdlUpdate(int_T tid)
{
  Lab1_2_min_update(tid);
}

void MdlInitializeSizes(void)
{
  Lab1_2_min_M->Sizes.numContStates = (0);/* Number of continuous states */
  Lab1_2_min_M->Sizes.numY = (0);      /* Number of model outputs */
  Lab1_2_min_M->Sizes.numU = (0);      /* Number of model inputs */
  Lab1_2_min_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Lab1_2_min_M->Sizes.numSampTimes = (2);/* Number of sample times */
  Lab1_2_min_M->Sizes.numBlocks = (14);/* Number of blocks */
  Lab1_2_min_M->Sizes.numBlockIO = (4);/* Number of block outputs */
  Lab1_2_min_M->Sizes.numBlockPrms = (16);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* S-Function Block: <Root>/Encoder Input */
  {
    ENCODERINPARM parm;
    parm.quad = (QUADMODE) 2;
    parm.index = (INDEXPULSE) 1;
    parm.infilter = Lab1_2_min_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1,
                   &Lab1_2_min_P.EncoderInput_Channels, NULL, &parm);
  }
}

void MdlStart(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Lab1_2_min_P.AnalogOutput_RangeMode;
      parm.rangeidx = Lab1_2_min_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &Lab1_2_min_P.AnalogOutput_Channels,
                     &Lab1_2_min_P.AnalogOutput_InitialValue, &parm);
    }
  }

  MdlInitialize();
}

RT_MODEL_Lab1_2_min *Lab1_2_min(void)
{
  Lab1_2_min_initialize(1);
  return Lab1_2_min_M;
}

void MdlTerminate(void)
{
  Lab1_2_min_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
