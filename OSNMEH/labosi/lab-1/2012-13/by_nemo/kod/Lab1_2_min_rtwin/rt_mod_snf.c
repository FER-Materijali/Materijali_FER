/*
 * rt_mod_snf.c
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

#include "rt_mod_snf.h"
#include "rt_nonfinite.h"
#include <float.h>
#include <math.h>
#include "rt_round_snf.h"

/* Function: rt_mod_snf =======================================================
 * Abstract:
 *   Calls double-precision version of MOD, with guard against domain error
 *   and guards against non-finites
 */
real_T rt_mod_snf(const real_T xr, const real_T yr)
{
  real_T zr, yrf, tr, trf, wr;
  if (yr == 0.0) {
    zr = xr;
  } else if (rtIsInf(xr) || rtIsInf(yr) || rtIsNaN(xr) || rtIsNaN(yr)) {
    zr = (rtNaN);
  } else {
    yrf = floor(yr);
    tr = xr/yr;
    if (yr == yrf) {
      /* Integer denominator.  Use conventional formula.*/
      trf = floor(tr);
      zr = xr - trf*yr;
    } else {
      /* Noninteger denominator. Check for nearly integer quotient.*/
      wr = rt_round_snf(tr);
      if (fabs(tr - wr) <= ((DBL_EPSILON)*fabs(tr))) {
        zr = 0.0;
      } else {
        trf = floor(tr);
        zr = (tr - trf)*yr;
      }
    }
  }

  return zr;
}                                      /* end rt_mod_snf */
