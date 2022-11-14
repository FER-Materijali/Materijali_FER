/*
 * pokus_1_data.c
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

/* Block parameters (auto storage) */
Parameters_pokus_1 pokus_1_P = {
  1.0,                                 /* Step1_Time : '<Root>/Step1'
                                        */
  0.0,                                 /* Step1_Y0 : '<Root>/Step1'
                                        */
  1.0,                                 /* Step1_YFinal : '<Root>/Step1'
                                        */
  2.0,                                 /* Step2_Time : '<Root>/Step2'
                                        */
  0.0,                                 /* Step2_Y0 : '<Root>/Step2'
                                        */
  -1.0,                                /* Step2_YFinal : '<Root>/Step2'
                                        */
  3.0,                                 /* Step3_Time : '<Root>/Step3'
                                        */
  0.0,                                 /* Step3_Y0 : '<Root>/Step3'
                                        */
  -1.0,                                /* Step3_YFinal : '<Root>/Step3'
                                        */
  4.0,                                 /* Step4_Time : '<Root>/Step4'
                                        */
  0.0,                                 /* Step4_Y0 : '<Root>/Step4'
                                        */
  1.0,                                 /* Step4_YFinal : '<Root>/Step4'
                                        */
  25.0,                                /* amplituda_Gain : '<Root>/amplituda'
                                        */
  8.7222222222222232E-003,             /* stuprad_Gain : '<Root>/stup->rad'
                                        */
  0.0,                                 /* EncoderInput_InputFilter : '<Root>/Encoder Input'
                                        */
  -0.0007666015625,                    /* imprad_Gain : '<Root>/imp//rad'
                                        */
  2.9339887220818998E+001,             /* Kp1_Gain : '<Root>/Kp1'
                                        */
  -250.0,                              /* derivacijasfiltriranjem1_A : '<Root>/ derivacija s filtriranjem1'
                                        */
  -62500.0,                            /* derivacijasfiltriranjem1_C : '<Root>/ derivacija s filtriranjem1'
                                        */
  250.0,                               /* derivacijasfiltriranjem1_D : '<Root>/ derivacija s filtriranjem1'
                                        */
  3.6428026413221559E-001,             /* Kv1_Gain : '<Root>/Kv1'
                                        */
  1.0,                                 /* K_kab_Gain : '<Root>/1//K_kab'
                                        */
  6.0,                                 /* Limiter_UpperSat : '<Root>/Limiter'
                                        */
  -6.0,                                /* Limiter_LowerSat : '<Root>/Limiter'
                                        */
  0.0,                                 /* AnalogOutput_InitialValue : '<Root>/Analog Output'
                                        */
  0.0,                                 /* AnalogOutput_FinalValue : '<Root>/Analog Output'
                                        */
  1.1464968152866241E+002,             /* radstup1_Gain : '<Root>/rad>stup1'
                                        */
  0.0,                                 /* Integrator_IC : '<Root>/Integrator'
                                        */
  1.1464968152866241E+002,             /* radstup_Gain : '<Root>/rad>stup'
                                        */
  -250.0,                              /* derivacijasfiltriranjem_A : '<Root>/ derivacija s filtriranjem'
                                        */
  -62500.0,                            /* derivacijasfiltriranjem_C : '<Root>/ derivacija s filtriranjem'
                                        */
  250.0,                               /* derivacijasfiltriranjem_D : '<Root>/ derivacija s filtriranjem'
                                        */
  2.9339887220818998E+001,             /* Kp_Gain : '<Root>/Kp'
                                        */
  3.6428026413221559E-001,             /* Kv_Gain : '<Root>/Kv'
                                        */
  0.0,                                 /* Integrator_IC_n : '<S1>/Integrator'
                                        */
  0.004,                               /* Viskoznotrenje_Gain : '<S1>/Viskozno trenje'
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
  0,                                   /* EncoderInput_Channels : '<Root>/Encoder Input'
                                        */
  0,                                   /* AnalogOutput_Channels : '<Root>/Analog Output'
                                        */
  0,                                   /* AnalogOutput_RangeMode : '<Root>/Analog Output'
                                        */
  0                                    /* AnalogOutput_VoltRange : '<Root>/Analog Output'
                                        */
};
