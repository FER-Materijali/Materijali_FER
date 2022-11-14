/*
 * rt_round_snf.c
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
 *
 */

#include "rt_round_snf.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function: rt_round_snf =======================================================
 * Abstract:
 *   Calls double-precision version of ROUND, with guard against domain error
 *   and guards against non-finites
 */
real_T rt_round_snf(const real_T xr)
{
  real_T zr, axr;
  if (rtIsNaN(xr)) {
    zr = xr;
  } else {
    axr = fabs(xr);
    if (axr < 4.5035996273704960E+015) {
      if (xr < 0.0) {
        zr = -floor(axr + 0.5);
      } else {
        zr = floor(axr + 0.5);
      }
    } else {
      zr = xr;
    }
  }

  return zr;
}                                      /* end rt_round_snf */
