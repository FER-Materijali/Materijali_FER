/*
 * tester_data.c
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

/* Block parameters (auto storage) */
Parameters_tester tester_P = {
  1.45,                                /* Step_Time : '<Root>/Step'
                                        */
  0.0,                                 /* Step_Y0 : '<Root>/Step'
                                        */
  1.0,                                 /* Step_YFinal : '<Root>/Step'
                                        */
  6.0,                                 /* Limiter_UpperSat : '<Root>/Limiter'
                                        */
  -6.0,                                /* Limiter_LowerSat : '<Root>/Limiter'
                                        */
  0.0,                                 /* AnalogOutput_InitialValue : '<Root>/Analog Output'
                                        */
  0.0,                                 /* AnalogOutput_FinalValue : '<Root>/Analog Output'
                                        */
  6.6666666666666663E+002,             /* tachoomjer_Gain : '<Root>/tacho omjer'
                                        */
  1.4285714285714285E-002,             /* tachoomjer1_Gain : '<Root>/tacho omjer1'
                                        */
  0.0,                                 /* Integrator_IC : '<S1>/Integrator'
                                        */
  9.5492965855137211E+000,             /* radsokrmin_Gain : '<Root>/rad//s -> okr//min'
                                        */
  1.8000000000000002E-002,             /* Viskoznotrenje_Gain : '<S1>/Viskozno trenje'
                                        */
  6.0,                                 /* UPMnaponzasicenja_UpperSat : '<S1>/UPM napon zasicenja'
                                        */
  -6.0,                                /* UPMnaponzasicenja_LowerSat : '<S1>/UPM napon zasicenja'
                                        */
  0.537432,                            /* Protuelektromotornasilae_Gain : '<S1>/Protuelektromotorna sila e'
                                        */
  3.8461538461538458E-001,             /* NaponStruja_Gain : '<S1>/Napon - > Struja'
                                        */
  3.3398000999999994E-001,             /* StujaMoment_Gain : '<S1>/Stuja -> Moment'
                                        */
  500.0,                               /* Inercija_Gain : '<S1>/Inercija'
                                        */
  3,                                   /* AnalogInput_Channels : '<Root>/Analog Input'
                                        */
  0,                                   /* AnalogInput_RangeMode : '<Root>/Analog Input'
                                        */
  0,                                   /* AnalogInput_VoltRange : '<Root>/Analog Input'
                                        */
  0,                                   /* AnalogOutput_Channels : '<Root>/Analog Output'
                                        */
  0,                                   /* AnalogOutput_RangeMode : '<Root>/Analog Output'
                                        */
  0                                    /* AnalogOutput_VoltRange : '<Root>/Analog Output'
                                        */
};
