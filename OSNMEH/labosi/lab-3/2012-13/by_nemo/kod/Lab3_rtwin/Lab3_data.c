/*
 * Lab3_data.c
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

/* Block parameters (auto storage) */
Parameters_Lab3 Lab3_P = {
  0.0,                                 /* Integrator2_IC : '<Root>/Integrator2'
                                        */
  170.0,                               /* StaticGain1_Gain : '<Root>/Static Gain1'
                                        */
  -2.8635602312594494E+002,            /* DerivacijskiKompenzator1_A : '<Root>/Derivacijski Kompenzator1'
                                        */
  -7.1999771980506716E+002,            /* DerivacijskiKompenzator1_C : '<Root>/Derivacijski Kompenzator1'
                                        */
  2.8635602312594495E+000,             /* DerivacijskiKompenzator1_D : '<Root>/Derivacijski Kompenzator1'
                                        */
  1.0,                                 /* k_kab_Gain : '<Root>/1//k_kab'
                                        */
  6.0,                                 /* Limiter_UpperSat : '<Root>/Limiter'
                                        */
  -6.0,                                /* Limiter_LowerSat : '<Root>/Limiter'
                                        */
  0.0,                                 /* AnalogOutput_InitialValue : '<Root>/Analog Output'
                                        */
  0.0,                                 /* AnalogOutput_FinalValue : '<Root>/Analog Output'
                                        */
  6.6666666666666663E+002,             /* Tachoomjer_Gain : '<Root>/Tacho omjer'
                                        */
  1.4285714285714285E-002,             /* Kg_Gain : '<Root>/1//Kg'
                                        */
  1.0,                                 /* Step_Time : '<Root>/Step'
                                        */
  0.0,                                 /* Step_Y0 : '<Root>/Step'
                                        */
  1.0,                                 /* Step_YFinal : '<Root>/Step'
                                        */
  2.0,                                 /* Step1_Time : '<Root>/Step1'
                                        */
  0.0,                                 /* Step1_Y0 : '<Root>/Step1'
                                        */
  -1.0,                                /* Step1_YFinal : '<Root>/Step1'
                                        */
  3.0,                                 /* Step2_Time : '<Root>/Step2'
                                        */
  0.0,                                 /* Step2_Y0 : '<Root>/Step2'
                                        */
  -1.0,                                /* Step2_YFinal : '<Root>/Step2'
                                        */
  4.0,                                 /* Step3_Time : '<Root>/Step3'
                                        */
  0.0,                                 /* Step3_Y0 : '<Root>/Step3'
                                        */
  1.0,                                 /* Step3_YFinal : '<Root>/Step3'
                                        */
  25.0,                                /* Amplitudaokrmin_Gain : '<Root>/Amplituda (okr//min)'
                                        */
  0.0,                                 /* Integrator_IC : '<S1>/Integrator'
                                        */
  9.5492965855137211E+000,             /* radsokrmin_Gain : '<Root>/rad//s -> okr//min'
                                        */
  0.0,                                 /* Integrator1_IC : '<Root>/Integrator1'
                                        */
  170.0,                               /* StaticGain_Gain : '<Root>/Static Gain'
                                        */
  -2.8635602312594494E+002,            /* DerivacijskiKompenzator_A : '<Root>/Derivacijski Kompenzator'
                                        */
  -7.1999771980506716E+002,            /* DerivacijskiKompenzator_C : '<Root>/Derivacijski Kompenzator'
                                        */
  2.8635602312594495E+000,             /* DerivacijskiKompenzator_D : '<Root>/Derivacijski Kompenzator'
                                        */
  0.0075,                              /* Viskoznotrenje_Gain : '<S1>/Viskozno trenje'
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
  1.0471975511965977E-001,             /* okrminrads_Gain : '<Root>/okr//min -> rad//s'
                                        */
  1.0471975511965977E-001,             /* okrminrads_Gain_h : '<Root>/okr//min->rad//s'
                                        */
  0,                                   /* AnalogOutput_Channels : '<Root>/Analog Output'
                                        */
  0,                                   /* AnalogOutput_RangeMode : '<Root>/Analog Output'
                                        */
  0,                                   /* AnalogOutput_VoltRange : '<Root>/Analog Output'
                                        */
  3,                                   /* AnalogInput_Channels : '<Root>/Analog Input'
                                        */
  0,                                   /* AnalogInput_RangeMode : '<Root>/Analog Input'
                                        */
  0                                    /* AnalogInput_VoltRange : '<Root>/Analog Input'
                                        */
};
