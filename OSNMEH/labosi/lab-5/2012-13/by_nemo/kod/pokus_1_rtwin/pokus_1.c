/*
 * pokus_1.c
 *
 * Real-Time Workshop code generation for Simulink model "pokus_1.mdl".
 *
 * Model Version              : 1.18
 * Real-Time Workshop version : 7.3  (R2009a)  15-Jan-2009
 * C source code generated on : Fri May 24 14:38:16 2013
 *
 * Target selection: rtwin.tlc
 *   Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pokus_1.h"
#include "pokus_1_private.h"
#include <stdio.h>
#include "pokus_1_dt.h"

/* list of Real-Time Windows Target boards */
const int RTWinBoardCount = 1;
RTWINBOARD RTWinBoards[1] = {
  { "Quanser/MultiQ-PCI", 4294967295U, 0, NULL },
};

/* Block signals (auto storage) */
BlockIO_pokus_1 pokus_1_B;

/* Continuous states */
ContinuousStates_pokus_1 pokus_1_X;

/* Block states (auto storage) */
D_Work_pokus_1 pokus_1_DWork;

/* Real-time model */
RT_MODEL_pokus_1 pokus_1_M_;
RT_MODEL_pokus_1 *pokus_1_M = &pokus_1_M_;

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
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  pokus_1_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; i++) {
    *x += h * f0[i];
    x++;
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void pokus_1_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_derivacijasfiltriranjem;

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(pokus_1_M)) {
    pokus_1_M->Timing.t[0] = rtsiGetT(&pokus_1_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(pokus_1_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&pokus_1_M->solverInfo,
                          ((pokus_1_M->Timing.clockTick0+1)*
      pokus_1_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  {
    real_T currentTime;
    real_T rtb_Step1;
    real_T rtb_Step2;
    real_T rtb_Sum1_d;

    /* Step: '<Root>/Step1' */
    currentTime = pokus_1_M->Timing.t[0];
    if (currentTime < pokus_1_P.Step1_Time) {
      rtb_Step1 = pokus_1_P.Step1_Y0;
    } else {
      rtb_Step1 = pokus_1_P.Step1_YFinal;
    }

    /* Step: '<Root>/Step2' */
    currentTime = pokus_1_M->Timing.t[0];
    if (currentTime < pokus_1_P.Step2_Time) {
      rtb_Step2 = pokus_1_P.Step2_Y0;
    } else {
      rtb_Step2 = pokus_1_P.Step2_YFinal;
    }

    /* Step: '<Root>/Step3' */
    currentTime = pokus_1_M->Timing.t[0];
    if (currentTime < pokus_1_P.Step3_Time) {
      rtb_derivacijasfiltriranjem = pokus_1_P.Step3_Y0;
    } else {
      rtb_derivacijasfiltriranjem = pokus_1_P.Step3_YFinal;
    }

    /* Step: '<Root>/Step4' */
    currentTime = pokus_1_M->Timing.t[0];
    if (currentTime < pokus_1_P.Step4_Time) {
      rtb_Sum1_d = pokus_1_P.Step4_Y0;
    } else {
      rtb_Sum1_d = pokus_1_P.Step4_YFinal;
    }

    /* Gain: '<Root>/amplituda' incorporates:
     *  Sum: '<Root>/Sum4'
     */
    pokus_1_B.amplituda = (((rtb_Step1 + rtb_Step2) +
      rtb_derivacijasfiltriranjem) + rtb_Sum1_d) * pokus_1_P.amplituda_Gain;

    /* Gain: '<Root>/stup->rad' */
    rtb_Sum1_d = pokus_1_P.stuprad_Gain * pokus_1_B.amplituda;

    /* S-Function Block: <Root>/Encoder Input */
    {
      ENCODERINPARM parm;
      parm.quad = (QUADMODE) 2;
      parm.index = (INDEXPULSE) 1;
      parm.infilter = pokus_1_P.EncoderInput_InputFilter;
      RTBIO_DriverIO(0, ENCODERINPUT, IOREAD, 1,
                     &pokus_1_P.EncoderInput_Channels,
                     &rtb_derivacijasfiltriranjem, &parm);
    }

    /* Gain: '<Root>/imp//rad' */
    pokus_1_B.imprad = pokus_1_P.imprad_Gain * rtb_derivacijasfiltriranjem;

    /* Gain: '<Root>/Kp1' incorporates:
     *  Sum: '<Root>/Sum2'
     */
    currentTime = (rtb_Sum1_d - pokus_1_B.imprad) * pokus_1_P.Kp1_Gain;

    /* TransferFcn Block: '<Root>/ derivacija s filtriranjem1' */
    pokus_1_B.derivacijasfiltriranjem1 = pokus_1_P.derivacijasfiltriranjem1_D*
      pokus_1_B.imprad;
    pokus_1_B.derivacijasfiltriranjem1 += pokus_1_P.derivacijasfiltriranjem1_C*
      pokus_1_X.derivacijasfiltriranjem1_CSTATE;

    /* Gain: '<Root>/1//K_kab' incorporates:
     *  Gain: '<Root>/Kv1'
     *  Sum: '<Root>/Sum3'
     */
    rtb_derivacijasfiltriranjem = (currentTime - pokus_1_P.Kv1_Gain *
      pokus_1_B.derivacijasfiltriranjem1) * pokus_1_P.K_kab_Gain;

    /* Saturate: '<Root>/Limiter' */
    pokus_1_B.Limiter = rt_SATURATE(rtb_derivacijasfiltriranjem,
      pokus_1_P.Limiter_LowerSat, pokus_1_P.Limiter_UpperSat);
    if (rtmIsMajorTimeStep(pokus_1_M)) {
      /* S-Function Block: <Root>/Analog Output */
      {
        {
          ANALOGIOPARM parm;
          parm.mode = (RANGEMODE) pokus_1_P.AnalogOutput_RangeMode;
          parm.rangeidx = pokus_1_P.AnalogOutput_VoltRange;
          RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                         &pokus_1_P.AnalogOutput_Channels, &pokus_1_B.Limiter,
                         &parm);
        }
      }
    }

    /* Gain: '<Root>/rad>stup1' */
    pokus_1_B.radstup1 = pokus_1_P.radstup1_Gain * pokus_1_B.imprad;
    if (rtmIsMajorTimeStep(pokus_1_M)) {
    }

    /* Integrator: '<Root>/Integrator' */
    pokus_1_B.Integrator = pokus_1_X.Integrator_CSTATE;

    /* Gain: '<Root>/rad>stup' */
    pokus_1_B.radstup = pokus_1_P.radstup_Gain * pokus_1_B.Integrator;
    if (rtmIsMajorTimeStep(pokus_1_M)) {
    }

    /* TransferFcn Block: '<Root>/ derivacija s filtriranjem' */
    rtb_derivacijasfiltriranjem = pokus_1_P.derivacijasfiltriranjem_D*
      pokus_1_B.Integrator;
    rtb_derivacijasfiltriranjem += pokus_1_P.derivacijasfiltriranjem_C*
      pokus_1_X.derivacijasfiltriranjem_CSTATE;

    /* Integrator: '<S1>/Integrator' */
    pokus_1_B.Integrator_a = pokus_1_X.Integrator_CSTATE_j;

    /* Sum: '<Root>/Sum1' incorporates:
     *  Gain: '<Root>/Kp'
     *  Gain: '<Root>/Kv'
     *  Sum: '<Root>/Sum'
     */
    rtb_Sum1_d = (rtb_Sum1_d - pokus_1_B.Integrator) * pokus_1_P.Kp_Gain -
      pokus_1_P.Kv_Gain * rtb_derivacijasfiltriranjem;

    /* Gain: '<S1>/Inercija' incorporates:
     *  Gain: '<S1>/Napon - > Struja'
     *  Gain: '<S1>/Protuelektromotorna sila e'
     *  Gain: '<S1>/Stuja -> Moment'
     *  Gain: '<S1>/Viskozno trenje'
     *  Saturate: '<S1>/UPM napon zasicenja'
     *  Sum: '<S1>/Sum'
     *  Sum: '<S1>/Sum1'
     */
    pokus_1_B.Inercija = ((rt_SATURATE(rtb_Sum1_d,
      pokus_1_P.UPMnaponzasicenja_LowerSat, pokus_1_P.UPMnaponzasicenja_UpperSat)
      - pokus_1_P.Protuelektromotornasilae_Gain * pokus_1_B.Integrator_a) *
                          pokus_1_P.NaponStruja_Gain *
                          pokus_1_P.StujaMoment_Gain -
                          pokus_1_P.Viskoznotrenje_Gain * pokus_1_B.Integrator_a)
      * pokus_1_P.Inercija_Gain;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void pokus_1_update(int_T tid)
{
  if (rtmIsMajorTimeStep(pokus_1_M)) {
    rt_ertODEUpdateContinuousStates(&pokus_1_M->solverInfo);
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
  if (!(++pokus_1_M->Timing.clockTick0))
    ++pokus_1_M->Timing.clockTickH0;
  pokus_1_M->Timing.t[0] = pokus_1_M->Timing.clockTick0 *
    pokus_1_M->Timing.stepSize0 + pokus_1_M->Timing.clockTickH0 *
    pokus_1_M->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(pokus_1_M)) {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++pokus_1_M->Timing.clockTick1))
      ++pokus_1_M->Timing.clockTickH1;
    pokus_1_M->Timing.t[1] = pokus_1_M->Timing.clockTick1 *
      pokus_1_M->Timing.stepSize1 + pokus_1_M->Timing.clockTickH1 *
      pokus_1_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void pokus_1_derivatives(void)
{
  /* TransferFcn Block: '<Root>/ derivacija s filtriranjem1' */
  {
    ((StateDerivatives_pokus_1 *) pokus_1_M->ModelData.derivs)
      ->derivacijasfiltriranjem1_CSTATE = pokus_1_B.imprad;
    ((StateDerivatives_pokus_1 *) pokus_1_M->ModelData.derivs)
      ->derivacijasfiltriranjem1_CSTATE += (pokus_1_P.derivacijasfiltriranjem1_A)*
      pokus_1_X.derivacijasfiltriranjem1_CSTATE;
  }

  /* Derivatives for Integrator: '<Root>/Integrator' */
  ((StateDerivatives_pokus_1 *) pokus_1_M->ModelData.derivs)->Integrator_CSTATE =
    pokus_1_B.Integrator_a;

  /* TransferFcn Block: '<Root>/ derivacija s filtriranjem' */
  {
    ((StateDerivatives_pokus_1 *) pokus_1_M->ModelData.derivs)
      ->derivacijasfiltriranjem_CSTATE = pokus_1_B.Integrator;
    ((StateDerivatives_pokus_1 *) pokus_1_M->ModelData.derivs)
      ->derivacijasfiltriranjem_CSTATE += (pokus_1_P.derivacijasfiltriranjem_A)*
      pokus_1_X.derivacijasfiltriranjem_CSTATE;
  }

  /* Derivatives for Integrator: '<S1>/Integrator' */
  ((StateDerivatives_pokus_1 *) pokus_1_M->ModelData.derivs)
    ->Integrator_CSTATE_j = pokus_1_B.Inercija;
}

/* Model initialize function */
void pokus_1_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  pokus_1_P.EncoderInput_InputFilter = rtInf;

  /* initialize real-time model */
  (void) memset((void *)pokus_1_M,0,
                sizeof(RT_MODEL_pokus_1));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&pokus_1_M->solverInfo, &pokus_1_M->Timing.simTimeStep);
    rtsiSetTPtr(&pokus_1_M->solverInfo, &rtmGetTPtr(pokus_1_M));
    rtsiSetStepSizePtr(&pokus_1_M->solverInfo, &pokus_1_M->Timing.stepSize0);
    rtsiSetdXPtr(&pokus_1_M->solverInfo, &pokus_1_M->ModelData.derivs);
    rtsiSetContStatesPtr(&pokus_1_M->solverInfo,
                         &pokus_1_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&pokus_1_M->solverInfo,
      &pokus_1_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&pokus_1_M->solverInfo, (&rtmGetErrorStatus(pokus_1_M)));
    rtsiSetRTModelPtr(&pokus_1_M->solverInfo, pokus_1_M);
  }

  rtsiSetSimTimeStep(&pokus_1_M->solverInfo, MAJOR_TIME_STEP);
  pokus_1_M->ModelData.intgData.f[0] = pokus_1_M->ModelData.odeF[0];
  pokus_1_M->ModelData.contStates = ((real_T *) &pokus_1_X);
  rtsiSetSolverData(&pokus_1_M->solverInfo, (void *)
                    &pokus_1_M->ModelData.intgData);
  rtsiSetSolverName(&pokus_1_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = pokus_1_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    pokus_1_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    pokus_1_M->Timing.sampleTimes = (&pokus_1_M->Timing.sampleTimesArray[0]);
    pokus_1_M->Timing.offsetTimes = (&pokus_1_M->Timing.offsetTimesArray[0]);

    /* task periods */
    pokus_1_M->Timing.sampleTimes[0] = (0.0);
    pokus_1_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    pokus_1_M->Timing.offsetTimes[0] = (0.0);
    pokus_1_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(pokus_1_M, &pokus_1_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = pokus_1_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    pokus_1_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(pokus_1_M, 10.0);
  pokus_1_M->Timing.stepSize0 = 0.001;
  pokus_1_M->Timing.stepSize1 = 0.001;

  /* external mode info */
  pokus_1_M->Sizes.checksums[0] = (2109340595U);
  pokus_1_M->Sizes.checksums[1] = (1202634295U);
  pokus_1_M->Sizes.checksums[2] = (2791182160U);
  pokus_1_M->Sizes.checksums[3] = (4251741471U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    pokus_1_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &pokus_1_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, pokus_1_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(pokus_1_M));
  }

  pokus_1_M->solverInfoPtr = (&pokus_1_M->solverInfo);
  pokus_1_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&pokus_1_M->solverInfo, 0.001);
  rtsiSetSolverMode(&pokus_1_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  pokus_1_M->ModelData.blockIO = ((void *) &pokus_1_B);
  (void) memset(((void *) &pokus_1_B),0,
                sizeof(BlockIO_pokus_1));

  /* parameters */
  pokus_1_M->ModelData.defaultParam = ((real_T *) &pokus_1_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &pokus_1_X;
    pokus_1_M->ModelData.contStates = (x);
    (void) memset((void *)x,0,
                  sizeof(ContinuousStates_pokus_1));
  }

  /* states (dwork) */
  pokus_1_M->Work.dwork = ((void *) &pokus_1_DWork);
  (void) memset((void *)&pokus_1_DWork, 0,
                sizeof(D_Work_pokus_1));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    pokus_1_M->SpecialInfo.mappingInfo = (&dtInfo);
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
void pokus_1_terminate(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) pokus_1_P.AnalogOutput_RangeMode;
      parm.rangeidx = pokus_1_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &pokus_1_P.AnalogOutput_Channels,
                     &pokus_1_P.AnalogOutput_FinalValue, &parm);
    }
  }
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  pokus_1_output(tid);
}

void MdlUpdate(int_T tid)
{
  pokus_1_update(tid);
}

void MdlInitializeSizes(void)
{
  pokus_1_M->Sizes.numContStates = (4);/* Number of continuous states */
  pokus_1_M->Sizes.numY = (0);         /* Number of model outputs */
  pokus_1_M->Sizes.numU = (0);         /* Number of model inputs */
  pokus_1_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  pokus_1_M->Sizes.numSampTimes = (2); /* Number of sample times */
  pokus_1_M->Sizes.numBlocks = (39);   /* Number of blocks */
  pokus_1_M->Sizes.numBlockIO = (9);   /* Number of block outputs */
  pokus_1_M->Sizes.numBlockPrms = (46);/* Sum of parameter "widths" */
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
    parm.infilter = pokus_1_P.EncoderInput_InputFilter;
    RTBIO_DriverIO(0, ENCODERINPUT, IORESET, 1, &pokus_1_P.EncoderInput_Channels,
                   NULL, &parm);
  }

  /* TransferFcn Block: '<Root>/ derivacija s filtriranjem1' */
  pokus_1_X.derivacijasfiltriranjem1_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  pokus_1_X.Integrator_CSTATE = pokus_1_P.Integrator_IC;

  /* TransferFcn Block: '<Root>/ derivacija s filtriranjem' */
  pokus_1_X.derivacijasfiltriranjem_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  pokus_1_X.Integrator_CSTATE_j = pokus_1_P.Integrator_IC_n;
}

void MdlStart(void)
{
  /* S-Function Block: <Root>/Analog Output */
  {
    {
      ANALOGIOPARM parm;
      parm.mode = (RANGEMODE) pokus_1_P.AnalogOutput_RangeMode;
      parm.rangeidx = pokus_1_P.AnalogOutput_VoltRange;
      RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                     &pokus_1_P.AnalogOutput_Channels,
                     &pokus_1_P.AnalogOutput_InitialValue, &parm);
    }
  }

  MdlInitialize();
}

RT_MODEL_pokus_1 *pokus_1(void)
{
  pokus_1_initialize(1);
  return pokus_1_M;
}

void MdlTerminate(void)
{
  pokus_1_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
