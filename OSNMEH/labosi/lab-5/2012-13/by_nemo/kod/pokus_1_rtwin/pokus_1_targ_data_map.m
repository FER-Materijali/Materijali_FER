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
    ;% Auto data (pokus_1_P)
    ;%
      section.nData     = 42;
      section.data(42)  = dumData; %prealloc
      
	  ;% pokus_1_P.Step1_Time
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pokus_1_P.Step1_Y0
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% pokus_1_P.Step1_YFinal
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% pokus_1_P.Step2_Time
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% pokus_1_P.Step2_Y0
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% pokus_1_P.Step2_YFinal
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% pokus_1_P.Step3_Time
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% pokus_1_P.Step3_Y0
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% pokus_1_P.Step3_YFinal
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% pokus_1_P.Step4_Time
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% pokus_1_P.Step4_Y0
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% pokus_1_P.Step4_YFinal
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% pokus_1_P.amplituda_Gain
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% pokus_1_P.stuprad_Gain
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% pokus_1_P.EncoderInput_InputFilter
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% pokus_1_P.imprad_Gain
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% pokus_1_P.Kp1_Gain
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% pokus_1_P.derivacijasfiltriranjem1_A
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% pokus_1_P.derivacijasfiltriranjem1_C
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% pokus_1_P.derivacijasfiltriranjem1_D
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% pokus_1_P.Kv1_Gain
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 20;
	
	  ;% pokus_1_P.K_kab_Gain
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 21;
	
	  ;% pokus_1_P.Limiter_UpperSat
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 22;
	
	  ;% pokus_1_P.Limiter_LowerSat
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 23;
	
	  ;% pokus_1_P.AnalogOutput_InitialValue
	  section.data(25).logicalSrcIdx = 25;
	  section.data(25).dtTransOffset = 24;
	
	  ;% pokus_1_P.AnalogOutput_FinalValue
	  section.data(26).logicalSrcIdx = 26;
	  section.data(26).dtTransOffset = 25;
	
	  ;% pokus_1_P.radstup1_Gain
	  section.data(27).logicalSrcIdx = 27;
	  section.data(27).dtTransOffset = 26;
	
	  ;% pokus_1_P.Integrator_IC
	  section.data(28).logicalSrcIdx = 28;
	  section.data(28).dtTransOffset = 27;
	
	  ;% pokus_1_P.radstup_Gain
	  section.data(29).logicalSrcIdx = 29;
	  section.data(29).dtTransOffset = 28;
	
	  ;% pokus_1_P.derivacijasfiltriranjem_A
	  section.data(30).logicalSrcIdx = 30;
	  section.data(30).dtTransOffset = 29;
	
	  ;% pokus_1_P.derivacijasfiltriranjem_C
	  section.data(31).logicalSrcIdx = 31;
	  section.data(31).dtTransOffset = 30;
	
	  ;% pokus_1_P.derivacijasfiltriranjem_D
	  section.data(32).logicalSrcIdx = 32;
	  section.data(32).dtTransOffset = 31;
	
	  ;% pokus_1_P.Kp_Gain
	  section.data(33).logicalSrcIdx = 34;
	  section.data(33).dtTransOffset = 32;
	
	  ;% pokus_1_P.Kv_Gain
	  section.data(34).logicalSrcIdx = 35;
	  section.data(34).dtTransOffset = 33;
	
	  ;% pokus_1_P.Integrator_IC_n
	  section.data(35).logicalSrcIdx = 36;
	  section.data(35).dtTransOffset = 34;
	
	  ;% pokus_1_P.Viskoznotrenje_Gain
	  section.data(36).logicalSrcIdx = 37;
	  section.data(36).dtTransOffset = 35;
	
	  ;% pokus_1_P.UPMnaponzasicenja_UpperSat
	  section.data(37).logicalSrcIdx = 38;
	  section.data(37).dtTransOffset = 36;
	
	  ;% pokus_1_P.UPMnaponzasicenja_LowerSat
	  section.data(38).logicalSrcIdx = 39;
	  section.data(38).dtTransOffset = 37;
	
	  ;% pokus_1_P.Protuelektromotornasilae_Gain
	  section.data(39).logicalSrcIdx = 40;
	  section.data(39).dtTransOffset = 38;
	
	  ;% pokus_1_P.NaponStruja_Gain
	  section.data(40).logicalSrcIdx = 41;
	  section.data(40).dtTransOffset = 39;
	
	  ;% pokus_1_P.StujaMoment_Gain
	  section.data(41).logicalSrcIdx = 42;
	  section.data(41).dtTransOffset = 40;
	
	  ;% pokus_1_P.Inercija_Gain
	  section.data(42).logicalSrcIdx = 43;
	  section.data(42).dtTransOffset = 41;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% pokus_1_P.EncoderInput_Channels
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pokus_1_P.AnalogOutput_Channels
	  section.data(2).logicalSrcIdx = 45;
	  section.data(2).dtTransOffset = 1;
	
	  ;% pokus_1_P.AnalogOutput_RangeMode
	  section.data(3).logicalSrcIdx = 46;
	  section.data(3).dtTransOffset = 2;
	
	  ;% pokus_1_P.AnalogOutput_VoltRange
	  section.data(4).logicalSrcIdx = 47;
	  section.data(4).dtTransOffset = 3;
	
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
    ;% Auto data (pokus_1_B)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% pokus_1_B.amplituda
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pokus_1_B.imprad
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% pokus_1_B.derivacijasfiltriranjem1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% pokus_1_B.Limiter
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% pokus_1_B.radstup1
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% pokus_1_B.Integrator
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% pokus_1_B.radstup
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% pokus_1_B.Integrator_a
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% pokus_1_B.Inercija
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
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
    ;% Auto data (pokus_1_DWork)
    ;%
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% pokus_1_DWork.angle_in_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% pokus_1_DWork.brzinaradsec_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% pokus_1_DWork.epsilon_gstupnjevi_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% pokus_1_DWork.epsilon_g_simstupnjevi_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% pokus_1_DWork.v_ref_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
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


  targMap.checksum0 = 2109340595;
  targMap.checksum1 = 1202634295;
  targMap.checksum2 = 2791182160;
  targMap.checksum3 = 4251741471;

