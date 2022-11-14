  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Lab3_P)
    ;%
      section.nData     = 41;
      section.data(41)  = dumData; %prealloc
      
	  ;% Lab3_P.Integrator2_IC
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lab3_P.StaticGain1_Gain
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lab3_P.DerivacijskiKompenzator1_A
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Lab3_P.DerivacijskiKompenzator1_C
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Lab3_P.DerivacijskiKompenzator1_D
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Lab3_P.k_kab_Gain
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Lab3_P.Limiter_UpperSat
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Lab3_P.Limiter_LowerSat
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Lab3_P.AnalogOutput_InitialValue
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Lab3_P.AnalogOutput_FinalValue
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Lab3_P.Tachoomjer_Gain
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Lab3_P.Kg_Gain
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Lab3_P.Step_Time
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Lab3_P.Step_Y0
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Lab3_P.Step_YFinal
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Lab3_P.Step1_Time
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Lab3_P.Step1_Y0
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Lab3_P.Step1_YFinal
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Lab3_P.Step2_Time
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Lab3_P.Step2_Y0
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Lab3_P.Step2_YFinal
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Lab3_P.Step3_Time
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Lab3_P.Step3_Y0
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Lab3_P.Step3_YFinal
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Lab3_P.Amplitudaokrmin_Gain
	  section.data(25).logicalSrcIdx = 25;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Lab3_P.Integrator_IC
	  section.data(26).logicalSrcIdx = 26;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Lab3_P.radsokrmin_Gain
	  section.data(27).logicalSrcIdx = 27;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Lab3_P.Integrator1_IC
	  section.data(28).logicalSrcIdx = 28;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Lab3_P.StaticGain_Gain
	  section.data(29).logicalSrcIdx = 29;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Lab3_P.DerivacijskiKompenzator_A
	  section.data(30).logicalSrcIdx = 30;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Lab3_P.DerivacijskiKompenzator_C
	  section.data(31).logicalSrcIdx = 31;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Lab3_P.DerivacijskiKompenzator_D
	  section.data(32).logicalSrcIdx = 32;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Lab3_P.Viskoznotrenje_Gain
	  section.data(33).logicalSrcIdx = 34;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Lab3_P.UPMnaponzasicenja_UpperSat
	  section.data(34).logicalSrcIdx = 35;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Lab3_P.UPMnaponzasicenja_LowerSat
	  section.data(35).logicalSrcIdx = 36;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Lab3_P.Protuelektromotornasilae_Gain
	  section.data(36).logicalSrcIdx = 37;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Lab3_P.NaponStruja_Gain
	  section.data(37).logicalSrcIdx = 38;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Lab3_P.StujaMoment_Gain
	  section.data(38).logicalSrcIdx = 39;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Lab3_P.Inercija_Gain
	  section.data(39).logicalSrcIdx = 40;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Lab3_P.okrminrads_Gain
	  section.data(40).logicalSrcIdx = 41;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Lab3_P.okrminrads_Gain_h
	  section.data(41).logicalSrcIdx = 42;
	  section.data(41).dtTransOffset = 40;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Lab3_P.AnalogOutput_Channels
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lab3_P.AnalogOutput_RangeMode
	  section.data(2).logicalSrcIdx = 44;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lab3_P.AnalogOutput_VoltRange
	  section.data(3).logicalSrcIdx = 45;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Lab3_P.AnalogInput_Channels
	  section.data(4).logicalSrcIdx = 46;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Lab3_P.AnalogInput_RangeMode
	  section.data(5).logicalSrcIdx = 47;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Lab3_P.AnalogInput_VoltRange
	  section.data(6).logicalSrcIdx = 48;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Lab3_B)
    ;%
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Lab3_B.StaticGain1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lab3_B.Limiter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lab3_B.Kg
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Lab3_B.Amplitudaokrmin
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Lab3_B.radsokrmin
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Lab3_B.StaticGain
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Lab3_B.Inercija
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Lab3_B.Sum
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Lab3_B.okrminrads
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Lab3_B.Sum2
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Lab3_DWork)
    ;%
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Lab3_DWork.n1_real_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Lab3_DWork.n1_ref_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Lab3_DWork.n1_sim_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Lab3_DWork.v_ref_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3554470544;
  targMap.checksum1 = 3596093219;
  targMap.checksum2 = 249716508;
  targMap.checksum3 = 668853763;

