/*
 * Lab3.c
 *
 * Real-Time Workshop code generation for Simulink model "Lab3.mdl".
 *
 * Model Version              : 1.15
 * Real-Time Workshop version : 7.3  (R2009a)  15-Jan-2009
 * C source code generated on : Fri Apr 12 16:07:47 2013
 *
 * Target selection: rtwin.tlc
 *   Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Lab3.h"
#include "Lab3_private.h"
#include <stdio.h>
#include "Lab3_dt.h"

/* list of Real-Time Windows Target boards */
const int RTWinBoardCount = 1;
RTWINBOARD RTWinBoards[1] = {
  { "Quanser/MultiQ-PCI", 4294967295U, 0, NULL },
};

/* Block signals (auto storage) */
BlockIO_Lab3 Lab3_B;

/* Continuous states */
ContinuousStates_Lab3 Lab3_X;

/* Block states (auto storage) */
D_Work_Lab3 Lab3_DWork;

/* Real-time model */
RT_MODEL_Lab3 Lab3_M_;
RT_MODEL_Lab3 *Lab3_M = &Lab3_M_;

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
  int_T nXc = 5;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Lab3_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void Lab3_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_AnalogInput;
  real_T rtb_Step;
  real_T rtb_okrminrads;

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Lab3_M)) {
    Lab3_M->Timing.t[0] = rtsiGetT(&Lab3_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Lab3_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&Lab3_M->solverInfo,
                          ((Lab3_M->Timing.clockTick0+1)*
      Lab3_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  {
    real_T currentTime;
    real_T rtb_Step1;

    /* Integrator: '<Root>/Integrator2' */
    rtb_Step = Lab3_X.Integrator2_CSTATE;

    /* Gain: '<Root>/Static Gain1' */
    Lab3_B.StaticGain1 = Lab3_P.StaticGain1_Gain * rtb_Step;

    /* TransferFcn Block: '<Root>/Derivacijski Kompenzator1' */
    rtb_Step = Lab3_P.DerivacijskiKompenzator1_D*Lab3_B.StaticGain1;
    rtb_Step += Lab3_P.DerivacijskiKompenzator1_C*
      Lab3_X.DerivacijskiKompenzator1_CSTATE;

    /* Gain: '<Root>/1//k_kab' */
    rtb_Step *= Lab3_P.k_kab_Gain;

    /* Saturate: '<Root>/Limiter' */
    Lab3_B.Limiter = rt_SATURATE(rtb_Step, Lab3_P.Limiter_LowerSat,
      Lab3_P.Limiter_UpperSat);
    if (rtmIsMajorTimeStep(Lab3_M)) {
      /* S-Function Block: <Root>/Analog Output */
      {
        {
          ANALOGIOPARM parm;
          parm.mode = (RANGEMODE) Lab3_P.AnalogOutput_RangeMode;
          parm.rangeidx = Lab3_P.AnalogOutput_VoltRange;
          RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                         &Lab3_P.AnalogOutput_Channels, &Lab3_B.Limiter, &parm);
        }
      }

      /* S-Function Block: <Root>/Analog Input */
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE) Lab3_P.AnalogInput_RangeMode;
        parm.rangeidx = Lab3_P.AnalogInput_VoltRange;
        RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1, &Lab3_P.AnalogInput_Channels,
                       &rtb_AnalogInput, &parm);
      }

      /* Gain: '<Root>/1//Kg' incorporates:
       *  Gain: '<Root>/Tacho omjer'
       */
      Lab3_B.Kg = Lab3_P.Tachoomjer_Gain * rtb_AnalogInput * Lab3_P.Kg_Gain;
    }

    /* Step: '<Root>/Step' */
    currentTime = Lab3_M->Timing.t[0];
    if (currentTime < Lab3_P.Step_Time) {
      rtb_Step = Lab3_P.Step_Y0;
    } else {
      rtb_Step = Lab3_P.Step_YFinal;
    }

    /* Step: '<Root>/Step1' */
    currentTime = Lab3_M->Timing.t[0];
    if (currentTime < Lab3_P.Step1_Time) {
      rtb_Step1 = Lab3_P.Step1_Y0;
    } else {
      rtb_Step1 = Lab3_P.Step1_YFinal;
    }

    /* Step: '<Root>/Step2' */
    currentTime = Lab3_M->Timing.t[0];
    if (currentTime < Lab3_P.Step2_Time) {
      rtb_okrminrads = Lab3_P.Step2_Y0;
    } else {
      rtb_okrminrads = Lab3_P.Step2_YFinal;
    }

    /* Step: '<Root>/Step3' */
    currentTime = Lab3_M->Timing.t[0];
    if (currentTime < Lab3_P.Step3_Time) {
      currentTime = Lab3_P.Step3_Y0;
    } else {
      currentTime = Lab3_P.Step3_YFinal;
    }

    /* Gain: '<Root>/Amplituda (okr//min)' incorporates:
     *  Sum: '<Root>/Sum1'
     */
    Lab3_B.Amplitudaokrmin = (((rtb_Step + rtb_Step1) + rtb_okrminrads) +
      currentTime) * Lab3_P.Amplitudaokrmin_Gain;
    if (rtmIsMajorTimeStep(Lab3_M)) {
    }

    /* Integrator: '<S1>/Integrator' */
    currentTime = Lab3_X.Integrator_CSTATE;

    /* Gain: '<Root>/rad//s -> okr//min' */
    Lab3_B.radsokrmin = Lab3_P.radsokrmin_Gain * Lab3_X.Integrator_CSTATE;
    if (rtmIsMajorTimeStep(Lab3_M)) {
    }

    /* Integrator: '<Root>/Integrator1' */
    rtb_okrminrads = Lab3_X.Integrator1_CSTATE;

    /* Gain: '<Root>/Static Gain' */
    Lab3_B.StaticGain = Lab3_P.StaticGain_Gain * rtb_okrminrads;

    /* TransferFcn Block: '<Root>/Derivacijski Kompenzator' */
    rtb_okrminrads = Lab3_P.DerivacijskiKompenzator_D*Lab3_B.StaticGain;
    rtb_okrminrads += Lab3_P.DerivacijskiKompenzator_C*
      Lab3_X.DerivacijskiKompenzator_CSTATE;

    /* Gain: '<S1>/Inercija' incorporates:
     *  Gain: '<S1>/Napon - > Struja'
     *  Gain: '<S1>/Protuelektromotorna sila e'
     *  Gain: '<S1>/Stuja -> Moment'
     *  Gain: '<S1>/Viskozno trenje'
     *  Saturate: '<S1>/UPM napon zasicenja'
     *  Sum: '<S1>/Sum'
     *  Sum: '<S1>/Sum1'
     */
    Lab3_B.Inercija = ((rt_SATURATE(rtb_okrminrads,
      Lab3_P.UPMnaponzasicenja_LowerSat, Lab3_P.UPMnaponzasicenja_UpperSat) -
                        Lab3_P.Protuelektromotornasilae_Gain * currentTime) *
                       Lab3_P.NaponStruja_Gain * Lab3_P.StujaMoment_Gain -
                       Lab3_P.Viskoznotrenje_Gain * currentTime) *
      Lab3_P.Inercija_Gain;

    /* Gain: '<Root>/okr//min -> rad//s' */
    rtb_okrminrads = Lab3_P.okrminrads_Gain * Lab3_B.Amplitudaokrmin;

    /* Sum: '<Root>/Sum' */
    Lab3_B.Sum = rtb_okrminrads - currentTime;
    if (rtmIsMajorTimeStep(Lab3_M)) {
      /* Gain: '<Root>/okr//min->rad//s' */
      Lab3_B.okrminrads = Lab3_P.okrminrads_Gain_h * Lab3_B.Kg;
    }

    /* Sum: '<Root>/Sum2' */
    Lab3_B.Sum2 = rtb_okrminrads - Lab3_B.okrminrads;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void Lab3_update(int_T tid)
{
  if (rtmIsMajorTimeStep(Lab3_M)) {
    rt_ertODEUpdateContinuousStates(&Lab3_M->solverInfo);
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
  if (!(++Lab3_M->Timing.clockTick0))
    ++Lab3_M->Timing.clockTickH0;
  Lab3_M->Timing.t[0] = Lab3_M->Timing.clockTick0 * Lab3_M->Timing.stepSize0 +
    Lab3_M->Timing.clockTickH0 * Lab3_M->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(Lab3_M)) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++Lab3_M->Timing.clockTick1))
      ++Lab3_M->Timing.clockTickH1;
    Lab3_M->Timing.t[1] = Lab3_M->Timing.clockTick1 * Lab3_M->Timing.stepSize1 +
      Lab3_M->Timing.clockTickH1 * Lab3_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void Lab3_derivatives(void)
{
  /* Derivatives for Integrator: '<Root>/Integrator2' */
  ((StateDerivatives_Lab3 *) Lab3_M->ModelData.derivs)->Integrator2_CSTATE =
    Lab3_B.Sum2;

  /* TransferFcn Block: '<Root>/Derivacijski Kompenzator1' */
  {
    ((StateDerivatives_Lab3 *) Lab3_M->ModelData.derivs)
      ->DerivacijskiKompenzator1_CSTATE = Lab3_B.StaticGain1;
    ((StateDerivatives_Lab3 *) Lab3_M->ModelData.derivs)
      ->DerivacijskiKompenzator1_CSTATE += (Lab3_P.DerivacijskiKompenzator1_A)*
      Lab3_X.DerivacijskiKompenzator1_CSTATE;
  }

  /* Derivatives for Integrator: '<S1>/Integrator' */
  ((StateDerivatives_Lab3 *) Lab3_M->ModelData.derivs)->Integrator_CSTATE =
    Lab3_B.Inercija;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  ((StateDerivatives_Lab3 *) Lab3_M->ModelData.derivs)->Integrator1_CSTATE =
    Lab3_B.Sum;

  /* TransferFcn Block: '<Root>/Derivacijski Kompenzator' */
  {
    ((StateDerivatives_Lab3 *) Lab3_M->ModelData.derivs)
      ->DerivacijskiKompenzator_CSTATE = Lab3_B.StaticGain;
    ((StateDerivatives_Lab3 *) Lab3_M->ModelData.derivs)
      ->DerivacijskiKompenzator_CSTATE += (Lab3_P.DerivacijskiKompenzator_A)*
      Lab3_X.DerivacijskiKompenzator_CSTATE;
  }
}

/* Model initialize function */
void Lab3_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Lab3_M,0,
                sizeof(RT_MODEL_Lab3));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Lab3_M->solverInfo, &Lab3_M->Timing.simTimeStep);
    rtsiSetTPtr(&Lab3_M->solverInfo, &rtmGetTPtr(Lab3_M));
    rtsiSetStepSizePtr(&Lab3_M->solverInfo, &Lab3_M->Timing.stepSize0);
    rtsiSetdXPtr(&Lab3_M->solverInfo, &Lab3_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Lab3_M->solverInfo, &Lab3_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Lab3_M->solverInfo, &Lab3_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&Lab3_M->solverInfo, (&rtmGetErrorStatus(Lab3_M)));
    rtsiSetRTModelPtr(&Lab3_M->solverInfo, Lab3_M);
  }

  rtsiSetSimTimeStep(&Lab3_M->solverInfo, MAJOR_TIME_STEP);
  Lab3_M->ModelData.intgData.f[0] = Lab3_M->ModelData.odeF[0];
  Lab3_M->ModelData.contStates = ((real_T *) &Lab3_X);
  rtsiSetSolverData(&Lab3_M->solverInfo, (void *)&Lab3_M->ModelData.intgData);
  rtsiSetSolverName(&Lab3_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Lab3_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    Lab3_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Lab3_M->Timing.sampleTimes = (&Lab3_M->Timing.sampleTimesArray[0]);
    Lab3_M->Timing.offsetTimes = (&Lab3_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Lab3_M->Timing.sampleTimes[0] = (0.0);
    Lab3_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    Lab3_M->Timing.offsetTimes[0] = (0.0);
    Lab3_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(Lab3_M, &Lab3_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Lab3_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    Lab3_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Lab3_M, 5.0);
  Lab3_M->Timing.stepSize0 = 0.001;
  Lab3_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  Lab3_M->Sizes.checksums[0] = (3554470544U);
  Lab3_M->Sizes.checksums[1] = (3596093219U);
  Lab3_M->Sizes.checksums[2] = (249716508U);
  Lab3_M->Sizes.checksums[3] = (668853763U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Lab3_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo, &Lab3_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, Lab3_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(Lab3_M));
  }

  Lab3_M->solverInfoPtr = (&Lab3_M->solverInfo);
  Lab3_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&Lab3_M->solverInfo, 0.001);
  rtsiSetSolverMode(&Lab3_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  Lab3_M->ModelData.blockIO = ((void *) &Lab3_B);
  (void) memset(((void *) &Lab3_B),0,
                sizeof(BlockIO_Lab3));

  /* parameters */
  Lab3_M->ModelData.defaultParam = ((real_T *) &Lab3_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Lab3_X;
    Lab3_M->ModelData.contStates = (x);
    (void) memset((void *)x,0,
                  sizeof(ContinuousStates_Lab3));
  }

  /* states (dwork) */
  Lab3_M->Work.dwork = ((void *) &Lab3_DWork);
  (void) memset((void *)&Lab3_DWork, 0,
                sizeof(D_Work_Lab3));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    Lab3_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void Lab3_terminate(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Lab3_P.AnalogOutput_RangeMode;
      parm.rangeidx = Lab3_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &Lab3_P.AnalogOutput_Channels,
                     &Lab3_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  Lab3_output(tid);
}

void MdlUpdate(int_T tid)
{
  Lab3_update(tid);
}

void MdlInitializeSizes(void)
{
  Lab3_M->Sizes.numContStates = (5);   /* Number of continuous states */
  Lab3_M->Sizes.numY = (0);            /* Number of model outputs */
  Lab3_M->Sizes.numU = (0);            /* Number of model inputs */
  Lab3_M->Sizes.sysDirFeedThru = (0);  /* The model is not direct feedthrough */
  Lab3_M->Sizes.numSampTimes = (2);    /* Number of sample times */
  Lab3_M->Sizes.numBlocks = (36);      /* Number of blocks */
  Lab3_M->Sizes.numBlockIO = (10);     /* Number of block outputs */
  Lab3_M->Sizes.numBlockPrms = (47);   /* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  Lab3_X.Integrator2_CSTATE = Lab3_P.Integrator2_IC;

  /* TransferFcn Block: '<Root>/Derivacijski Kompenzator1' */
  Lab3_X.DerivacijskiKompenzator1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  Lab3_X.Integrator_CSTATE = Lab3_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  Lab3_X.Integrator1_CSTATE = Lab3_P.Integrator1_IC;

  /* TransferFcn Block: '<Root>/Derivacijski Kompenzator' */
  Lab3_X.DerivacijskiKompenzator_CSTATE = 0.0;
}

void MdlStart(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) Lab3_P.AnalogOutput_RangeMode;
      parm.rangeidx = Lab3_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1, &Lab3_P.AnalogOutput_Channels,
                     &Lab3_P.AnalogOutput_InitialValue, &parm);
    }
  }

  MdlInitialize();
}

RT_MODEL_Lab3 *Lab3(void)
{
  Lab3_initialize(1);
  return Lab3_M;
}

void MdlTerminate(void)
{
  Lab3_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
