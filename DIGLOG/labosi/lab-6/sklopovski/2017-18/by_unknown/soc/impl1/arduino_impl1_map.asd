[ActiveSupport MAP]
Device = LFXP2-5E;
Package = TQFP144;
Performance = 5;
LUTS_avail = 4752;
LUTS_used = 3245;
FF_avail = 3664;
FF_used = 1748;
INPUT_LVCMOS33 = 32;
OUTPUT_LVCMOS33 = 14;
BIDI_LVCMOS33 = 8;
IO_avail = 100;
IO_used = 54;
PLL_avail = 2;
PLL_used = 1;
EBR_avail = 9;
EBR_used = 9;
;
; start of DSP statistics
MULT36X36B = 3;
MULT18X18B = 0;
MULT18X18MACB = 0;
MULT18X18ADDSUBB = 0;
MULT18X18ADDSUBSUMB = 0;
MULT9X9B = 0;
MULT9X9ADDSUBB = 0;
MULT9X9ADDSUBSUMB = 0;
DSP_avail = 24;
DSP_used = 24;
; end of DSP statistics
;
; Begin EBR Section
Instance_Name = f32c_soc_glue/bram/bram_0_1_bram_0_1_0_1;
Type = DP16KB;
Width_A = 4;
Width_B = 4;
Depth_A = 4096;
Depth_B = 4096;
REGMODE_A = NOREG;
REGMODE_B = NOREG;
RESETMODE = SYNC;
WRITEMODE_A = WRITETHROUGH;
WRITEMODE_B = READBEFOREWRITE;
GSR = DISABLED;
Instance_Name = f32c_soc_glue/bram/bram_3_1_bram_3_1_0_0;
Type = DP16KB;
Width_A = 4;
Width_B = 4;
Depth_A = 4096;
Depth_B = 4096;
REGMODE_A = NOREG;
REGMODE_B = NOREG;
RESETMODE = SYNC;
WRITEMODE_A = WRITETHROUGH;
WRITEMODE_B = READBEFOREWRITE;
GSR = DISABLED;
Instance_Name = f32c_soc_glue/bram/bram_3_1_bram_3_1_0_1;
Type = DP16KB;
Width_A = 4;
Width_B = 4;
Depth_A = 4096;
Depth_B = 4096;
REGMODE_A = NOREG;
REGMODE_B = NOREG;
RESETMODE = SYNC;
WRITEMODE_A = WRITETHROUGH;
WRITEMODE_B = READBEFOREWRITE;
GSR = DISABLED;
Instance_Name = f32c_soc_glue/bram/bram_2_1_bram_2_1_0_0;
Type = DP16KB;
Width_A = 4;
Width_B = 4;
Depth_A = 4096;
Depth_B = 4096;
REGMODE_A = NOREG;
REGMODE_B = NOREG;
RESETMODE = SYNC;
WRITEMODE_A = WRITETHROUGH;
WRITEMODE_B = READBEFOREWRITE;
GSR = DISABLED;
Instance_Name = f32c_soc_glue/bram/bram_2_1_bram_2_1_0_1;
Type = DP16KB;
Width_A = 4;
Width_B = 4;
Depth_A = 4096;
Depth_B = 4096;
REGMODE_A = NOREG;
REGMODE_B = NOREG;
RESETMODE = SYNC;
WRITEMODE_A = WRITETHROUGH;
WRITEMODE_B = READBEFOREWRITE;
GSR = DISABLED;
Instance_Name = f32c_soc_glue/bram/bram_1_1_bram_1_1_0_0;
Type = DP16KB;
Width_A = 4;
Width_B = 4;
Depth_A = 4096;
Depth_B = 4096;
REGMODE_A = NOREG;
REGMODE_B = NOREG;
RESETMODE = SYNC;
WRITEMODE_A = WRITETHROUGH;
WRITEMODE_B = READBEFOREWRITE;
GSR = DISABLED;
Instance_Name = f32c_soc_glue/bram/bram_1_1_bram_1_1_0_1;
Type = DP16KB;
Width_A = 4;
Width_B = 4;
Depth_A = 4096;
Depth_B = 4096;
REGMODE_A = NOREG;
REGMODE_B = NOREG;
RESETMODE = SYNC;
WRITEMODE_A = WRITETHROUGH;
WRITEMODE_B = READBEFOREWRITE;
GSR = DISABLED;
Instance_Name = f32c_soc_glue/bram/bram_0_1_bram_0_1_0_0;
Type = DP16KB;
Width_A = 4;
Width_B = 4;
Depth_A = 4096;
Depth_B = 4096;
REGMODE_A = NOREG;
REGMODE_B = NOREG;
RESETMODE = SYNC;
WRITEMODE_A = WRITETHROUGH;
WRITEMODE_B = READBEFOREWRITE;
GSR = DISABLED;
Instance_Name = f32c_soc_glue/pipeline/G_bp_scoretable.bptrace/bptrace_bptrace_0_0;
Type = DP16KB;
Width_A = 2;
Depth_A = 8192;
Depth_B = 8192;
REGMODE_A = NOREG;
REGMODE_B = NOREG;
RESETMODE = SYNC;
WRITEMODE_A = WRITETHROUGH;
WRITEMODE_B = WRITETHROUGH;
GSR = DISABLED;
; End EBR Section
; Begin PLL Section
Instance_Name = clkgen/G_pll_325.PLL/PLL_325.PLLInst_0;
Type = EPLLD;
Output_Clock(P)_Actual_Frequency = 325.0000;
CLKOP_BYPASS = DISABLED;
CLKOS_BYPASS = DISABLED;
CLKOK_BYPASS = DISABLED;
CLKI_Divider = 1;
CLKFB_Divider = 13;
CLKOP_Divider = 2;
CLKOK_Divider = 4;
CLKOS_Phase_Shift_(degree) = 0.0;
CLKOS_Duty_Cycle_(*1/16) = 8;
Phase_Duty_Control = STATIC;
; End PLL Section
