[ActiveSupport MAP]
Device = LFXP2-8E;
Package = TQFP144;
Performance = 5;
LUTS_avail = 8352;
LUTS_used = 263;
FF_avail = 6364;
FF_used = 116;
INPUT_LVCMOS33 = 10;
OUTPUT_LVCMOS33 = 13;
IO_avail = 100;
IO_used = 23;
PLL_avail = 2;
PLL_used = 1;
EBR_avail = 12;
EBR_used = 0;
;
; start of DSP statistics
MULT36X36B = 0;
MULT18X18B = 0;
MULT18X18MACB = 0;
MULT18X18ADDSUBB = 0;
MULT18X18ADDSUBSUMB = 0;
MULT9X9B = 0;
MULT9X9ADDSUBB = 0;
MULT9X9ADDSUBSUMB = 0;
DSP_avail = 32;
DSP_used = 0;
; end of DSP statistics
;
; Begin PLL Section
Instance_Name = I12/PLLInst_0;
Type = EPLLD;
Output_Clock(P)_Actual_Frequency = 200.0000;
CLKOP_BYPASS = DISABLED;
CLKOS_BYPASS = DISABLED;
CLKOK_BYPASS = DISABLED;
CLKI_Divider = 1;
CLKFB_Divider = 8;
CLKOP_Divider = 4;
CLKOK_Divider = 2;
CLKOS_Phase_Shift_(degree) = 0.0;
CLKOS_Duty_Cycle_(*1/16) = 8;
Phase_Duty_Control = STATIC;
; End PLL Section
