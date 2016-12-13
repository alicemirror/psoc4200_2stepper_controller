// ======================================================================
// DualStepperController-PSoC4200-GearBest.v generated from TopDesign.cysch
// 12/13/2016 at 04:09
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_TMA4 2
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 3
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PSOC5TM 5
`define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1
`define CYDEV_CHIP_REV_PSOC5TM_ES1 1
`define CYDEV_CHIP_REV_PSOC5TM_ES0 0
`define CYDEV_CHIP_DIE_VOLANS 6
`define CYDEV_CHIP_REV_VOLANS_PRODUCTION 0
`define CYDEV_CHIP_DIE_BERRYPECKER 7
`define CYDEV_CHIP_REV_BERRYPECKER_PRODUCTION 0
`define CYDEV_CHIP_DIE_CRANE 8
`define CYDEV_CHIP_REV_CRANE_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM3 9
`define CYDEV_CHIP_REV_FM3_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM4 10
`define CYDEV_CHIP_REV_FM4_PRODUCTION 0
`define CYDEV_CHIP_DIE_EXPECT 3
`define CYDEV_CHIP_REV_EXPECT 17
`define CYDEV_CHIP_DIE_ACTUAL 3
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_FM0P 4
`define CYDEV_CHIP_FAMILY_FM3 5
`define CYDEV_CHIP_FAMILY_FM4 6
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_4G 2
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 3
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 4
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 5
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 6
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 7
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 8
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 9
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 10
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 11
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 12
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 13
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 14
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 15
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 16
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 17
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4C 18
`define CYDEV_CHIP_REVISION_4C_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_5B 19
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 20
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 21
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 22
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 23
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 24
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 25
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 2
`define CYDEV_CHIP_MEMBER_USED 12
`define CYDEV_CHIP_REVISION_USED 17
// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// TCPWM_P4_v2_10(Clock_CheckTolerance=true, Clock_desired_freq=12, Clock_desired_freq_unit=6, Clock_divisor=1, Clock_FractDividerDenominator=0, Clock_FractDividerNumerator=0, Clock_FractDividerUsed=false, Clock_is_direct=false, Clock_is_divider=false, Clock_is_freq=true, Clock_minus_tolerance=5, Clock_ph_align_clock_id=, Clock_ph_align_clock_name=, Clock_plus_tolerance=5, Clock_source_clock_id=, Clock_source_clock_name=, PinVisibility_index=false, PinVisibility_kill=false, PinVisibility_phiA=false, PinVisibility_phiB=false, PinVisibility_switch=false, PWMCompare=254, PWMCompareBuf=65535, PWMCompareSwap=0, PWMCountMode=3, PWMCountPresent=false, PWMDeadTimeCycle=0, PWMInterruptMask=1, PWMKillEvent=0, PWMLinenSignal=0, PWMLineSignal=0, PWMMode=4, PWMPeriod=255, PWMPeriodBuf=65535, PWMPeriodSwap=0, PWMPrescaler=0, PWMReloadMode=3, PWMReloadPresent=false, PWMRunMode=0, PWMSetAlign=0, PWMStartMode=3, PWMStartPresent=false, PWMStopEvent=0, PWMStopMode=3, PWMStopPresent=false, PWMSwitchMode=0, PWMSwitchPresent=false, QuadAutoStart=false, QuadEncodingModes=0, QuadIndexMode=0, QuadIndexPresent=true, QuadInterruptMask=1, QuadPhiAMode=3, QuadPhiBMode=3, QuadStopMode=0, QuadStopPresent=true, TCCaptureMode=0, TCCapturePresent=true, TCCompare=65535, TCCompareBuf=65535, TCCompareSwap=0, TCCompCapMode=2, TCCountingModes=0, TCCountMode=0, TCCountPresent=true, TCInterruptMask=1, TCPeriod=65535, TCPrescaler=0, TCPWMCapturePresent=false, TCPWMConfig=7, TCPWMCountPresent=false, TCPWMReloadPresent=false, TCPWMStartPresent=false, TCPWMStopPresent=false, TCReloadMode=0, TCReloadPresent=true, TCRunMode=0, TCStartMode=0, TCStartPresent=true, TCStopMode=0, TCStopPresent=true, TermMode_capture=0, TermMode_cc=0, TermMode_clock=0, TermMode_count=0, TermMode_interrupt=0, TermMode_line=0, TermMode_line_n=0, TermMode_ov=0, TermMode_reload=0, TermMode_start=0, TermMode_stop=0, TermMode_un=0, TermModeStates=, TermVisibility_capture=false, TermVisibility_cc=true, TermVisibility_clock=true, TermVisibility_count=false, TermVisibility_interrupt=true, TermVisibility_line=true, TermVisibility_line_n=true, TermVisibility_ov=true, TermVisibility_reload=false, TermVisibility_start=false, TermVisibility_stop=false, TermVisibility_un=true, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMPONENT_NAME=TCPWM_P4_v2_10, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=TCPWM_2, CY_INSTANCE_SHORT_NAME=TCPWM_2, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=10, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0, INSTANCE_NAME=TCPWM_2, )
module TCPWM_P4_v2_10_0 (
    stop,
    reload,
    start,
    count,
    capture,
    interrupt,
    ov,
    un,
    cc,
    line,
    line_n,
    clock);
    input       stop;
    input       reload;
    input       start;
    input       count;
    input       capture;
    output      interrupt;
    output      ov;
    output      un;
    output      cc;
    output      line;
    output      line_n;
    input       clock;


          wire  Net_64;
          wire  Net_63;
          wire  Net_85;
          wire  Net_62;
          wire  Net_110;
          wire  Net_95;
          wire  Net_106;
          wire  Net_104;
          wire  Net_109;
          wire  Net_98;
          wire  Net_108;
          wire  Net_101;
          wire  Net_66;
          wire  Net_81;
          wire  Net_75;
          wire  Net_69;
          wire  Net_82;
          wire  Net_72;

    cy_m0s8_tcpwm_v1_0 cy_m0s8_tcpwm_1 (
        .capture(Net_75),
        .underflow(un),
        .overflow(ov),
        .line_out_compl(line_n),
        .line_out(line),
        .compare_match(cc),
        .interrupt(interrupt),
        .count(Net_69),
        .reload(Net_66),
        .stop(Net_82),
        .start(Net_72),
        .clock(Net_81));

	// VMux_reload (cy_virtualmux_v1_0)
	assign Net_66 = reload;

	// VMux_count (cy_virtualmux_v1_0)
	assign Net_69 = count;

	// VMux_start (cy_virtualmux_v1_0)
	assign Net_72 = start;

	// VMux_capture (cy_virtualmux_v1_0)
	assign Net_75 = capture;

	// VMux_stop (cy_virtualmux_v1_0)
	assign Net_82 = stop;

	// VMux_clock (cy_virtualmux_v1_0)
	assign Net_81 = clock;



endmodule

// Component: CyControlReg_v1_80
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80"
`include "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80\CyControlReg_v1_80.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80"
`include "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80\CyControlReg_v1_80.v"
`endif

// Component: B_PWM_v3_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_PWM_v3_30"
`include "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_PWM_v3_30\B_PWM_v3_30.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_PWM_v3_30"
`include "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_PWM_v3_30\B_PWM_v3_30.v"
`endif

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// PWM_v3_30(CaptureMode=0, Clock_CheckTolerance=true, Clock_desired_freq=12, Clock_desired_freq_unit=6, Clock_divisor=1, Clock_FractDividerDenominator=0, Clock_FractDividerNumerator=0, Clock_FractDividerUsed=false, Clock_is_direct=false, Clock_is_divider=false, Clock_is_freq=true, Clock_minus_tolerance=5, Clock_ph_align_clock_id=, Clock_ph_align_clock_name=, Clock_plus_tolerance=5, Clock_source_clock_id=, Clock_source_clock_name=, Compare1_16=true, Compare1_8=false, Compare2_16=false, Compare2_8=false, CompareStatusEdgeSense=true, CompareType1=1, CompareType1Software=0, CompareType2=1, CompareType2Software=0, CompareValue1=4000, CompareValue2=63, CONTROL3=0, ControlReg=true, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DeadBand=0, DeadBand2_4=0, DeadBand256=0, DeadBandUsed=0, DeadTime=1, DitherOffset=0, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InterruptOnCMP1=false, InterruptOnCMP2=false, InterruptOnKill=false, InterruptOnTC=false, IntOnCMP1=0, IntOnCMP2=0, IntOnKill=0, IntOnTC=0, KillMode=0, KillModeMinTime=0, MinimumKillTime=1, OneCompare=true, Period=8000, PWMMode=0, PWMModeCenterAligned=0, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, Resolution=16, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, Status=true, TermMode_capture=0, TermMode_clock=0, TermMode_cmp_sel=0, TermMode_enable=0, TermMode_interrupt=0, TermMode_kill=0, TermMode_ph1=0, TermMode_ph2=0, TermMode_pwm=0, TermMode_pwm1=0, TermMode_pwm2=0, TermMode_reset=0, TermMode_tc=0, TermMode_trigger=0, TermVisibility_capture=false, TermVisibility_clock=true, TermVisibility_cmp_sel=false, TermVisibility_enable=false, TermVisibility_interrupt=true, TermVisibility_kill=false, TermVisibility_ph1=false, TermVisibility_ph2=false, TermVisibility_pwm=true, TermVisibility_pwm1=false, TermVisibility_pwm2=false, TermVisibility_reset=true, TermVisibility_tc=true, TermVisibility_trigger=false, TriggerMode=0, UDB16=true, UDB8=false, UseControl=true, UseInterrupt=true, UseStatus=true, VerilogSectionReplacementString=sP16, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMPONENT_NAME=PWM_v3_30, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=INTERNAL_STEP, CY_INSTANCE_SHORT_NAME=INTERNAL_STEP, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=30, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0, INSTANCE_NAME=INTERNAL_STEP, )
module PWM_v3_30_1 (
    reset,
    clock,
    tc,
    pwm1,
    pwm2,
    interrupt,
    capture,
    kill,
    enable,
    trigger,
    cmp_sel,
    pwm,
    ph1,
    ph2);
    input       reset;
    input       clock;
    output      tc;
    output      pwm1;
    output      pwm2;
    output      interrupt;
    input       capture;
    input       kill;
    input       enable;
    input       trigger;
    input       cmp_sel;
    output      pwm;
    output      ph1;
    output      ph2;

    parameter Resolution = 16;

          wire  Net_227;
          wire  Net_226;
          wire  Net_225;
          wire  Net_224;
          wire  Net_223;
          wire  Net_222;
          wire  Net_139;
          wire  Net_138;
          wire  Net_135;
          wire  Net_178;
          wire  Net_181;
          wire  Net_179;
          wire  Net_180;
          wire  Net_183;
          wire  Net_186;
          wire  Net_68;
          wire  Net_125;

    B_PWM_v3_30 PWMUDB (
        .reset(Net_186),
        .clock(Net_68),
        .tc(tc),
        .pwm1(pwm1),
        .pwm2(pwm2),
        .interrupt(interrupt),
        .kill(Net_179),
        .capture(Net_180),
        .enable(Net_181),
        .cmp_sel(Net_183),
        .trigger(Net_178),
        .pwm(pwm),
        .ph1(ph1),
        .ph2(ph2));
    defparam PWMUDB.CaptureMode = 0;
    defparam PWMUDB.CompareStatusEdgeSense = 1;
    defparam PWMUDB.CompareType1 = 1;
    defparam PWMUDB.CompareType2 = 1;
    defparam PWMUDB.DeadBand = 0;
    defparam PWMUDB.DitherOffset = 0;
    defparam PWMUDB.EnableMode = 0;
    defparam PWMUDB.KillMode = 0;
    defparam PWMUDB.PWMMode = 0;
    defparam PWMUDB.Resolution = 16;
    defparam PWMUDB.RunMode = 0;
    defparam PWMUDB.TriggerMode = 0;
    defparam PWMUDB.UseStatus = 1;

	// VMux_clock (cy_virtualmux_v1_0)
	assign Net_68 = clock;


    assign Net_139 = Net_138 | Net_125;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_138));

	// VMux_capture (cy_virtualmux_v1_0)
	assign Net_179 = kill;

	// VMux_capture_1 (cy_virtualmux_v1_0)
	assign Net_183 = cmp_sel;

	// VMux_capture_2 (cy_virtualmux_v1_0)
	assign Net_180 = capture;

	// VMux_capture_3 (cy_virtualmux_v1_0)
	assign Net_181 = enable;

	// VMux_capture_4 (cy_virtualmux_v1_0)
	assign Net_178 = trigger;

	// VMux_capture_5 (cy_virtualmux_v1_0)
	assign Net_186 = reset;



endmodule

// TCPWM_P4_v2_10(Clock_CheckTolerance=true, Clock_desired_freq=12, Clock_desired_freq_unit=6, Clock_divisor=1, Clock_FractDividerDenominator=0, Clock_FractDividerNumerator=0, Clock_FractDividerUsed=false, Clock_is_direct=false, Clock_is_divider=false, Clock_is_freq=true, Clock_minus_tolerance=5, Clock_ph_align_clock_id=, Clock_ph_align_clock_name=, Clock_plus_tolerance=5, Clock_source_clock_id=, Clock_source_clock_name=, PinVisibility_index=false, PinVisibility_kill=false, PinVisibility_phiA=false, PinVisibility_phiB=false, PinVisibility_switch=false, PWMCompare=0, PWMCompareBuf=65535, PWMCompareSwap=0, PWMCountMode=3, PWMCountPresent=false, PWMDeadTimeCycle=0, PWMInterruptMask=1, PWMKillEvent=0, PWMLinenSignal=0, PWMLineSignal=0, PWMMode=4, PWMPeriod=255, PWMPeriodBuf=65535, PWMPeriodSwap=0, PWMPrescaler=0, PWMReloadMode=3, PWMReloadPresent=false, PWMRunMode=0, PWMSetAlign=0, PWMStartMode=3, PWMStartPresent=false, PWMStopEvent=0, PWMStopMode=3, PWMStopPresent=false, PWMSwitchMode=0, PWMSwitchPresent=false, QuadAutoStart=false, QuadEncodingModes=0, QuadIndexMode=0, QuadIndexPresent=true, QuadInterruptMask=1, QuadPhiAMode=3, QuadPhiBMode=3, QuadStopMode=0, QuadStopPresent=true, TCCaptureMode=0, TCCapturePresent=true, TCCompare=65535, TCCompareBuf=65535, TCCompareSwap=0, TCCompCapMode=2, TCCountingModes=0, TCCountMode=0, TCCountPresent=true, TCInterruptMask=1, TCPeriod=65535, TCPrescaler=0, TCPWMCapturePresent=false, TCPWMConfig=7, TCPWMCountPresent=false, TCPWMReloadPresent=false, TCPWMStartPresent=false, TCPWMStopPresent=false, TCReloadMode=0, TCReloadPresent=true, TCRunMode=0, TCStartMode=0, TCStartPresent=true, TCStopMode=0, TCStopPresent=true, TermMode_capture=0, TermMode_cc=0, TermMode_clock=0, TermMode_count=0, TermMode_interrupt=0, TermMode_line=0, TermMode_line_n=0, TermMode_ov=0, TermMode_reload=0, TermMode_start=0, TermMode_stop=0, TermMode_un=0, TermModeStates=, TermVisibility_capture=false, TermVisibility_cc=true, TermVisibility_clock=true, TermVisibility_count=false, TermVisibility_interrupt=true, TermVisibility_line=true, TermVisibility_line_n=true, TermVisibility_ov=true, TermVisibility_reload=false, TermVisibility_start=false, TermVisibility_stop=false, TermVisibility_un=true, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMPONENT_NAME=TCPWM_P4_v2_10, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=TCPWM_1, CY_INSTANCE_SHORT_NAME=TCPWM_1, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=10, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0, INSTANCE_NAME=TCPWM_1, )
module TCPWM_P4_v2_10_2 (
    stop,
    reload,
    start,
    count,
    capture,
    interrupt,
    ov,
    un,
    cc,
    line,
    line_n,
    clock);
    input       stop;
    input       reload;
    input       start;
    input       count;
    input       capture;
    output      interrupt;
    output      ov;
    output      un;
    output      cc;
    output      line;
    output      line_n;
    input       clock;


          wire  Net_64;
          wire  Net_63;
          wire  Net_85;
          wire  Net_62;
          wire  Net_110;
          wire  Net_95;
          wire  Net_106;
          wire  Net_104;
          wire  Net_109;
          wire  Net_98;
          wire  Net_108;
          wire  Net_101;
          wire  Net_66;
          wire  Net_81;
          wire  Net_75;
          wire  Net_69;
          wire  Net_82;
          wire  Net_72;

    cy_m0s8_tcpwm_v1_0 cy_m0s8_tcpwm_1 (
        .capture(Net_75),
        .underflow(un),
        .overflow(ov),
        .line_out_compl(line_n),
        .line_out(line),
        .compare_match(cc),
        .interrupt(interrupt),
        .count(Net_69),
        .reload(Net_66),
        .stop(Net_82),
        .start(Net_72),
        .clock(Net_81));

	// VMux_reload (cy_virtualmux_v1_0)
	assign Net_66 = reload;

	// VMux_count (cy_virtualmux_v1_0)
	assign Net_69 = count;

	// VMux_start (cy_virtualmux_v1_0)
	assign Net_72 = start;

	// VMux_capture (cy_virtualmux_v1_0)
	assign Net_75 = capture;

	// VMux_stop (cy_virtualmux_v1_0)
	assign Net_82 = stop;

	// VMux_clock (cy_virtualmux_v1_0)
	assign Net_81 = clock;



endmodule

// TCPWM_P4_v2_10(Clock_CheckTolerance=true, Clock_desired_freq=12, Clock_desired_freq_unit=6, Clock_divisor=1, Clock_FractDividerDenominator=0, Clock_FractDividerNumerator=0, Clock_FractDividerUsed=false, Clock_is_direct=false, Clock_is_divider=false, Clock_is_freq=true, Clock_minus_tolerance=5, Clock_ph_align_clock_id=, Clock_ph_align_clock_name=, Clock_plus_tolerance=5, Clock_source_clock_id=, Clock_source_clock_name=, PinVisibility_index=false, PinVisibility_kill=false, PinVisibility_phiA=false, PinVisibility_phiB=false, PinVisibility_switch=false, PWMCompare=254, PWMCompareBuf=65535, PWMCompareSwap=0, PWMCountMode=3, PWMCountPresent=false, PWMDeadTimeCycle=0, PWMInterruptMask=1, PWMKillEvent=0, PWMLinenSignal=0, PWMLineSignal=0, PWMMode=4, PWMPeriod=255, PWMPeriodBuf=65535, PWMPeriodSwap=0, PWMPrescaler=0, PWMReloadMode=3, PWMReloadPresent=false, PWMRunMode=0, PWMSetAlign=0, PWMStartMode=3, PWMStartPresent=false, PWMStopEvent=0, PWMStopMode=3, PWMStopPresent=false, PWMSwitchMode=0, PWMSwitchPresent=false, QuadAutoStart=false, QuadEncodingModes=0, QuadIndexMode=0, QuadIndexPresent=true, QuadInterruptMask=1, QuadPhiAMode=3, QuadPhiBMode=3, QuadStopMode=0, QuadStopPresent=true, TCCaptureMode=0, TCCapturePresent=true, TCCompare=65535, TCCompareBuf=65535, TCCompareSwap=0, TCCompCapMode=2, TCCountingModes=0, TCCountMode=0, TCCountPresent=true, TCInterruptMask=1, TCPeriod=65535, TCPrescaler=0, TCPWMCapturePresent=false, TCPWMConfig=7, TCPWMCountPresent=false, TCPWMReloadPresent=false, TCPWMStartPresent=false, TCPWMStopPresent=false, TCReloadMode=0, TCReloadPresent=true, TCRunMode=0, TCStartMode=0, TCStartPresent=true, TCStopMode=0, TCStopPresent=true, TermMode_capture=0, TermMode_cc=0, TermMode_clock=0, TermMode_count=0, TermMode_interrupt=0, TermMode_line=0, TermMode_line_n=0, TermMode_ov=0, TermMode_reload=0, TermMode_start=0, TermMode_stop=0, TermMode_un=0, TermModeStates=, TermVisibility_capture=false, TermVisibility_cc=true, TermVisibility_clock=true, TermVisibility_count=false, TermVisibility_interrupt=true, TermVisibility_line=true, TermVisibility_line_n=true, TermVisibility_ov=true, TermVisibility_reload=false, TermVisibility_start=false, TermVisibility_stop=false, TermVisibility_un=true, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMPONENT_NAME=TCPWM_P4_v2_10, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=TCPWM_4, CY_INSTANCE_SHORT_NAME=TCPWM_4, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=10, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0, INSTANCE_NAME=TCPWM_4, )
module TCPWM_P4_v2_10_3 (
    stop,
    reload,
    start,
    count,
    capture,
    interrupt,
    ov,
    un,
    cc,
    line,
    line_n,
    clock);
    input       stop;
    input       reload;
    input       start;
    input       count;
    input       capture;
    output      interrupt;
    output      ov;
    output      un;
    output      cc;
    output      line;
    output      line_n;
    input       clock;


          wire  Net_64;
          wire  Net_63;
          wire  Net_85;
          wire  Net_62;
          wire  Net_110;
          wire  Net_95;
          wire  Net_106;
          wire  Net_104;
          wire  Net_109;
          wire  Net_98;
          wire  Net_108;
          wire  Net_101;
          wire  Net_66;
          wire  Net_81;
          wire  Net_75;
          wire  Net_69;
          wire  Net_82;
          wire  Net_72;

    cy_m0s8_tcpwm_v1_0 cy_m0s8_tcpwm_1 (
        .capture(Net_75),
        .underflow(un),
        .overflow(ov),
        .line_out_compl(line_n),
        .line_out(line),
        .compare_match(cc),
        .interrupt(interrupt),
        .count(Net_69),
        .reload(Net_66),
        .stop(Net_82),
        .start(Net_72),
        .clock(Net_81));

	// VMux_reload (cy_virtualmux_v1_0)
	assign Net_66 = reload;

	// VMux_count (cy_virtualmux_v1_0)
	assign Net_69 = count;

	// VMux_start (cy_virtualmux_v1_0)
	assign Net_72 = start;

	// VMux_capture (cy_virtualmux_v1_0)
	assign Net_75 = capture;

	// VMux_stop (cy_virtualmux_v1_0)
	assign Net_82 = stop;

	// VMux_clock (cy_virtualmux_v1_0)
	assign Net_81 = clock;



endmodule

// TCPWM_P4_v2_10(Clock_CheckTolerance=true, Clock_desired_freq=12, Clock_desired_freq_unit=6, Clock_divisor=1, Clock_FractDividerDenominator=0, Clock_FractDividerNumerator=0, Clock_FractDividerUsed=false, Clock_is_direct=false, Clock_is_divider=false, Clock_is_freq=true, Clock_minus_tolerance=5, Clock_ph_align_clock_id=, Clock_ph_align_clock_name=, Clock_plus_tolerance=5, Clock_source_clock_id=, Clock_source_clock_name=, PinVisibility_index=false, PinVisibility_kill=false, PinVisibility_phiA=false, PinVisibility_phiB=false, PinVisibility_switch=false, PWMCompare=0, PWMCompareBuf=65535, PWMCompareSwap=0, PWMCountMode=3, PWMCountPresent=false, PWMDeadTimeCycle=0, PWMInterruptMask=1, PWMKillEvent=0, PWMLinenSignal=0, PWMLineSignal=0, PWMMode=4, PWMPeriod=255, PWMPeriodBuf=65535, PWMPeriodSwap=0, PWMPrescaler=0, PWMReloadMode=3, PWMReloadPresent=false, PWMRunMode=0, PWMSetAlign=0, PWMStartMode=3, PWMStartPresent=false, PWMStopEvent=0, PWMStopMode=3, PWMStopPresent=false, PWMSwitchMode=0, PWMSwitchPresent=false, QuadAutoStart=false, QuadEncodingModes=0, QuadIndexMode=0, QuadIndexPresent=true, QuadInterruptMask=1, QuadPhiAMode=3, QuadPhiBMode=3, QuadStopMode=0, QuadStopPresent=true, TCCaptureMode=0, TCCapturePresent=true, TCCompare=65535, TCCompareBuf=65535, TCCompareSwap=0, TCCompCapMode=2, TCCountingModes=0, TCCountMode=0, TCCountPresent=true, TCInterruptMask=1, TCPeriod=65535, TCPrescaler=0, TCPWMCapturePresent=false, TCPWMConfig=7, TCPWMCountPresent=false, TCPWMReloadPresent=false, TCPWMStartPresent=false, TCPWMStopPresent=false, TCReloadMode=0, TCReloadPresent=true, TCRunMode=0, TCStartMode=0, TCStartPresent=true, TCStopMode=0, TCStopPresent=true, TermMode_capture=0, TermMode_cc=0, TermMode_clock=0, TermMode_count=0, TermMode_interrupt=0, TermMode_line=0, TermMode_line_n=0, TermMode_ov=0, TermMode_reload=0, TermMode_start=0, TermMode_stop=0, TermMode_un=0, TermModeStates=, TermVisibility_capture=false, TermVisibility_cc=true, TermVisibility_clock=true, TermVisibility_count=false, TermVisibility_interrupt=true, TermVisibility_line=true, TermVisibility_line_n=true, TermVisibility_ov=true, TermVisibility_reload=false, TermVisibility_start=false, TermVisibility_stop=false, TermVisibility_un=true, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMPONENT_NAME=TCPWM_P4_v2_10, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=TCPWM_3, CY_INSTANCE_SHORT_NAME=TCPWM_3, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=10, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0, INSTANCE_NAME=TCPWM_3, )
module TCPWM_P4_v2_10_4 (
    stop,
    reload,
    start,
    count,
    capture,
    interrupt,
    ov,
    un,
    cc,
    line,
    line_n,
    clock);
    input       stop;
    input       reload;
    input       start;
    input       count;
    input       capture;
    output      interrupt;
    output      ov;
    output      un;
    output      cc;
    output      line;
    output      line_n;
    input       clock;


          wire  Net_64;
          wire  Net_63;
          wire  Net_85;
          wire  Net_62;
          wire  Net_110;
          wire  Net_95;
          wire  Net_106;
          wire  Net_104;
          wire  Net_109;
          wire  Net_98;
          wire  Net_108;
          wire  Net_101;
          wire  Net_66;
          wire  Net_81;
          wire  Net_75;
          wire  Net_69;
          wire  Net_82;
          wire  Net_72;

    cy_m0s8_tcpwm_v1_0 cy_m0s8_tcpwm_1 (
        .capture(Net_75),
        .underflow(un),
        .overflow(ov),
        .line_out_compl(line_n),
        .line_out(line),
        .compare_match(cc),
        .interrupt(interrupt),
        .count(Net_69),
        .reload(Net_66),
        .stop(Net_82),
        .start(Net_72),
        .clock(Net_81));

	// VMux_reload (cy_virtualmux_v1_0)
	assign Net_66 = reload;

	// VMux_count (cy_virtualmux_v1_0)
	assign Net_69 = count;

	// VMux_start (cy_virtualmux_v1_0)
	assign Net_72 = start;

	// VMux_capture (cy_virtualmux_v1_0)
	assign Net_75 = capture;

	// VMux_stop (cy_virtualmux_v1_0)
	assign Net_82 = stop;

	// VMux_clock (cy_virtualmux_v1_0)
	assign Net_81 = clock;



endmodule

// PWM_v3_30(CaptureMode=0, Clock_CheckTolerance=true, Clock_desired_freq=12, Clock_desired_freq_unit=6, Clock_divisor=1, Clock_FractDividerDenominator=0, Clock_FractDividerNumerator=0, Clock_FractDividerUsed=false, Clock_is_direct=false, Clock_is_divider=false, Clock_is_freq=true, Clock_minus_tolerance=5, Clock_ph_align_clock_id=, Clock_ph_align_clock_name=, Clock_plus_tolerance=5, Clock_source_clock_id=, Clock_source_clock_name=, Compare1_16=true, Compare1_8=false, Compare2_16=false, Compare2_8=false, CompareStatusEdgeSense=true, CompareType1=1, CompareType1Software=0, CompareType2=1, CompareType2Software=0, CompareValue1=4000, CompareValue2=63, CONTROL3=0, ControlReg=true, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DeadBand=0, DeadBand2_4=0, DeadBand256=0, DeadBandUsed=0, DeadTime=1, DitherOffset=0, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InterruptOnCMP1=false, InterruptOnCMP2=false, InterruptOnKill=false, InterruptOnTC=false, IntOnCMP1=0, IntOnCMP2=0, IntOnKill=0, IntOnTC=0, KillMode=0, KillModeMinTime=0, MinimumKillTime=1, OneCompare=true, Period=8000, PWMMode=0, PWMModeCenterAligned=0, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, Resolution=16, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, Status=false, TermMode_capture=0, TermMode_clock=0, TermMode_cmp_sel=0, TermMode_enable=0, TermMode_interrupt=0, TermMode_kill=0, TermMode_ph1=0, TermMode_ph2=0, TermMode_pwm=0, TermMode_pwm1=0, TermMode_pwm2=0, TermMode_reset=0, TermMode_tc=0, TermMode_trigger=0, TermVisibility_capture=false, TermVisibility_clock=true, TermVisibility_cmp_sel=false, TermVisibility_enable=false, TermVisibility_interrupt=false, TermVisibility_kill=false, TermVisibility_ph1=false, TermVisibility_ph2=false, TermVisibility_pwm=true, TermVisibility_pwm1=false, TermVisibility_pwm2=false, TermVisibility_reset=true, TermVisibility_tc=true, TermVisibility_trigger=false, TriggerMode=0, UDB16=true, UDB8=false, UseControl=true, UseInterrupt=false, UseStatus=false, VerilogSectionReplacementString=sP16, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMPONENT_NAME=PWM_v3_30, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=INTERNAL_STEP_1, CY_INSTANCE_SHORT_NAME=INTERNAL_STEP_1, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=30, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0, INSTANCE_NAME=INTERNAL_STEP_1, )
module PWM_v3_30_5 (
    reset,
    clock,
    tc,
    pwm1,
    pwm2,
    interrupt,
    capture,
    kill,
    enable,
    trigger,
    cmp_sel,
    pwm,
    ph1,
    ph2);
    input       reset;
    input       clock;
    output      tc;
    output      pwm1;
    output      pwm2;
    output      interrupt;
    input       capture;
    input       kill;
    input       enable;
    input       trigger;
    input       cmp_sel;
    output      pwm;
    output      ph1;
    output      ph2;

    parameter Resolution = 16;

          wire  Net_227;
          wire  Net_226;
          wire  Net_225;
          wire  Net_224;
          wire  Net_223;
          wire  Net_222;
          wire  Net_139;
          wire  Net_138;
          wire  Net_135;
          wire  Net_178;
          wire  Net_181;
          wire  Net_179;
          wire  Net_180;
          wire  Net_183;
          wire  Net_186;
          wire  Net_68;
          wire  Net_125;

    B_PWM_v3_30 PWMUDB (
        .reset(Net_186),
        .clock(Net_68),
        .tc(tc),
        .pwm1(pwm1),
        .pwm2(pwm2),
        .interrupt(interrupt),
        .kill(Net_179),
        .capture(Net_180),
        .enable(Net_181),
        .cmp_sel(Net_183),
        .trigger(Net_178),
        .pwm(pwm),
        .ph1(ph1),
        .ph2(ph2));
    defparam PWMUDB.CaptureMode = 0;
    defparam PWMUDB.CompareStatusEdgeSense = 1;
    defparam PWMUDB.CompareType1 = 1;
    defparam PWMUDB.CompareType2 = 1;
    defparam PWMUDB.DeadBand = 0;
    defparam PWMUDB.DitherOffset = 0;
    defparam PWMUDB.EnableMode = 0;
    defparam PWMUDB.KillMode = 0;
    defparam PWMUDB.PWMMode = 0;
    defparam PWMUDB.Resolution = 16;
    defparam PWMUDB.RunMode = 0;
    defparam PWMUDB.TriggerMode = 0;
    defparam PWMUDB.UseStatus = 0;

	// VMux_clock (cy_virtualmux_v1_0)
	assign Net_68 = clock;


    assign Net_139 = Net_138 | Net_125;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_138));

	// VMux_capture (cy_virtualmux_v1_0)
	assign Net_179 = kill;

	// VMux_capture_1 (cy_virtualmux_v1_0)
	assign Net_183 = cmp_sel;

	// VMux_capture_2 (cy_virtualmux_v1_0)
	assign Net_180 = capture;

	// VMux_capture_3 (cy_virtualmux_v1_0)
	assign Net_181 = enable;

	// VMux_capture_4 (cy_virtualmux_v1_0)
	assign Net_178 = trigger;

	// VMux_capture_5 (cy_virtualmux_v1_0)
	assign Net_186 = reset;



endmodule

// SCB_P4_v3_20(ApplySbClockParam=false, BitWidthReplacementStringRx=uint8, BitWidthReplacementStringTx=uint8, BufNum=, Cond=, DBGW_SCB_IP_V0=true, DBGW_SCB_IP_V1=false, DBGW_SCB_IP_V2=false, DW_Hide_i2c=false, DW_Hide_Scbv0Feature=false, DW_Hide_Scbv2Feature=true, DW_Hide_Spi=false, DW_Hide_Uart=false, DW_Hide_UartFlowControl=true, DW_INTR_SPI_EC=Comm_SCB__INTR_SPI_EC, DW_INTR_SPI_EC_MASK=Comm_SCB__INTR_SPI_EC_MASK, DW_INTR_SPI_EC_MASKED=Comm_SCB__INTR_SPI_EC_MASKED, DW_SPI_CTRL=Comm_SCB__SPI_CTRL, DW_SPI_STATUS=Comm_SCB__SPI_STATUS, DW_UART_CTRL=Comm_SCB__UART_CTRL, DW_UART_FLOW_CTRL=, DW_UART_RX_CTRL=Comm_SCB__UART_RX_CTRL, DW_UART_TX_CTRL=Comm_SCB__UART_TX_CTRL, EndCond=, EzI2cBitWidthReplacementString=uint16, EzI2cBusVoltage=3.3, EzI2cByteModeEnable=false, EzI2cClkFreqDes=1550, EzI2cClockFromTerm=false, EzI2cClockStretching=true, EzI2cDataRate=100, EzI2cIsPrimarySlaveAddressHex=true, EzI2cIsSecondarySlaveAddressHex=true, EzI2cMedianFilterEnable=true, EzI2cNumberOfAddresses=0, EzI2cOvsFactor=16, EzI2cPrimarySlaveAddress=8, EzI2cSecondarySlaveAddress=9, EzI2cSlaveAddressMask=254, EzI2cSlewRate=0, EzI2cSubAddressSize=0, EzI2cWakeEnable=false, I2cAcceptAddress=false, I2cAcceptGeneralCall=false, I2cBusVoltage=3.3, I2cBusVoltageLevel=, I2cByteModeEnable=false, I2cClkFreqDes=1550, I2cClockFromTerm=false, I2cDataRate=100, I2cExternIntrHandler=false, I2cIsSlaveAddressHex=true, I2cIsSlaveAddressMaskHex=true, I2cManualOversampleControl=true, I2cMedianFilterEnable=true, I2cMode=1, I2cOvsFactor=16, I2cOvsFactorHigh=8, I2cOvsFactorLow=8, I2cSlaveAddress=8, I2cSlaveAddressMask=254, I2cSlewRate=0, I2cSlewRateSettings=0, I2cWakeEnable=false, PinLocationP4A=true, PinName0Unconfig=uart_rx_i2c_scl_spi_mosi, PinName0UnconfigWake=uart_rx_wake_i2c_scl_spi_mosi, PinName1Unconfig=uart_tx_i2c_sda_spi_miso, PinName2Unconfig=spi_sclk, PinName3Unconfig=spi_ss0, Pn0Unconfig=RX_SCL_MOSI, Pn0UnconfigWake=RX_WAKE_SCL_MOSI, Pn1Unconfig=TX_SDA_MISO, Pn2Unconfig=SCLK, Pn3Unconfig=SS0, RemoveI2cPins=true, RemoveMisoSdaTx=false, RemoveMosiSclRx=false, RemoveMosiSclRxWake=true, RemoveScbClk=true, RemoveScbIrq=false, RemoveSpiMasterMiso=true, RemoveSpiMasterMosi=true, RemoveSpiMasterPins=true, RemoveSpiMasterSclk=true, RemoveSpiMasterSs0Pin=true, RemoveSpiMasterSs1Pin=true, RemoveSpiMasterSs2Pin=true, RemoveSpiMasterSs3Pin=true, RemoveSpiSclk=true, RemoveSpiSlaveMiso=true, RemoveSpiSlaveMosi=true, RemoveSpiSlavePins=true, RemoveSpiSs0=true, RemoveSpiSs1=true, RemoveSpiSs2=true, RemoveSpiSs3=true, RemoveUartCtsPin=true, RemoveUartRtsPin=true, RemoveUartRxPin=true, RemoveUartRxTxPin=true, RemoveUartRxWake=true, RemoveUartRxWakeupIrq=true, RemoveUartTxPin=true, RxTriggerOutputEnable=false, ScbClkFreqDes=12000, ScbClkMinusTolerance=5, ScbClkPlusTolerance=5, ScbClockSelect=0, ScbClockTermEnable=true, ScbCustomIntrHandlerEnable=true, ScbInterruptTermEnable=false, ScbMisoSdaTxEnable=true, ScbMode=255, ScbModeHw=5, ScbMosiSclRxEnable=true, ScbRxWakeIrqEnable=false, ScbSclkEnable=false, ScbSs0Enable=false, ScbSs1Enable=false, ScbSs2Enable=false, ScbSs3Enable=false, ScbSymbolVisibility=0, SpiBitRate=1000, SpiBitsOrder=1, SpiByteModeEnable=false, SpiClkFreqDes=16000, SpiClockFromTerm=false, SpiFreeRunningSclk=false, SpiInterruptMode=1, SpiIntrMasterSpiDone=false, SpiIntrRxFull=false, SpiIntrRxNotEmpty=false, SpiIntrRxOverflow=false, SpiIntrRxTrigger=false, SpiIntrRxUnderflow=false, SpiIntrSlaveBusError=false, SpiIntrTxEmpty=false, SpiIntrTxNotFull=false, SpiIntrTxOverflow=false, SpiIntrTxTrigger=false, SpiIntrTxUnderflow=false, SpiLateMisoSampleEnable=false, SpiManualOversampleControl=true, SpiMasterMode=false, SpiMedianFilterEnable=false, SpimMisoTermEnable=false, SpimMosiTermEnable=false, SpiMode=0, SpimSclkTermEnable=false, SpimSs0TermEnable=false, SpimSs1TermEnable=false, SpimSs2TermEnable=false, SpimSs3TermEnable=false, SpiNumberOfRxDataBits=8, SpiNumberOfSelectLines=1, SpiNumberOfTxDataBits=8, SpiOvsFactor=16, SpiRemoveMiso=false, SpiRemoveMosi=false, SpiRemoveSclk=false, SpiRxBufferSize=8, SpiRxIntrMask=0, SpiRxOutputEnable=false, SpiRxTriggerLevel=7, SpiSclkMode=0, SpiSlaveMode=false, SpiSmartioEnable=false, SpisMisoTermEnable=false, SpisMosiTermEnable=false, SpiSs0Polarity=0, SpiSs1Polarity=0, SpiSs2Polarity=0, SpiSs3Polarity=0, SpisSclkTermEnable=false, SpisSsTermEnable=false, SpiSubMode=0, SpiTransferSeparation=1, SpiTxBufferSize=8, SpiTxIntrMask=0, SpiTxOutputEnable=false, SpiTxTriggerLevel=0, SpiWakeEnable=false, TermMode_clock=0, TermMode_interrupt=0, TermVisibility_clock=true, TermVisibility_interrupt=false, TriggerOutputEnable=false, TxTriggerOutputEnable=false, UartByteModeEnable=false, UartClkFreqDes=1843.2, UartClockFromTerm=false, UartCtsEnable=false, UartCtsPolarity=0, UartCtsTermEnable=false, UartDataRate=115200, UartDirection=3, UartDropOnFrameErr=false, UartDropOnParityErr=false, UartInterruptMode=0, UartIntrRxFrameErr=false, UartIntrRxFull=false, UartIntrRxNotEmpty=false, UartIntrRxOverflow=false, UartIntrRxParityErr=false, UartIntrRxTrigger=false, UartIntrRxUnderflow=false, UartIntrTxEmpty=false, UartIntrTxNotFull=false, UartIntrTxOverflow=false, UartIntrTxTrigger=false, UartIntrTxUartDone=false, UartIntrTxUartLostArb=false, UartIntrTxUartNack=false, UartIntrTxUnderflow=false, UartIrdaLowPower=false, UartIrdaPolarity=0, UartMedianFilterEnable=false, UartMpEnable=false, UartMpRxAcceptAddress=false, UartMpRxAddress=2, UartMpRxAddressMask=255, UartNumberOfDataBits=8, UartNumberOfStopBits=2, UartOvsFactor=16, UartParityType=2, UartRtsEnable=false, UartRtsPolarity=0, UartRtsTermEnable=false, UartRtsTriggerLevel=4, UartRxBufferSize=8, UartRxEnable=false, UartRxIntrMask=0, UartRxOutputEnable=false, UartRxTermEnable=false, UartRxTriggerLevel=7, UartSmartioEnable=false, UartSmCardRetryOnNack=false, UartSubMode=0, UartTxBufferSize=8, UartTxEnable=false, UartTxIntrMask=0, UartTxOutputEnable=false, UartTxTermEnable=false, UartTxTriggerLevel=0, UartWakeEnable=false, CY_API_CALLBACK_HEADER_INCLUDE=, CY_COMPONENT_NAME=SCB_P4_v3_20, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Comm, CY_INSTANCE_SHORT_NAME=Comm, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=20, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0, INSTANCE_NAME=Comm, )
module SCB_P4_v3_20_6 (
    cts_in,
    tx_out,
    rts_out,
    interrupt,
    clock,
    rx_tr_out,
    tx_tr_out,
    s_mosi,
    s_sclk,
    s_ss,
    m_miso,
    m_mosi,
    m_sclk,
    m_ss0,
    m_ss1,
    m_ss2,
    m_ss3,
    s_miso,
    rx_in);
    input       cts_in;
    output      tx_out;
    output      rts_out;
    output      interrupt;
    input       clock;
    output      rx_tr_out;
    output      tx_tr_out;
    input       s_mosi;
    input       s_sclk;
    input       s_ss;
    input       m_miso;
    output      m_mosi;
    output      m_sclk;
    output      m_ss0;
    output      m_ss1;
    output      m_ss2;
    output      m_ss3;
    output      s_miso;
    input       rx_in;


          wire  uncfg_rx_irq;
          wire  sclk_m_wire;
          wire  Net_1264;
          wire  Net_1258;
          wire  rx_irq;
          wire [3:0] select_m_wire;
          wire  Net_1099;
          wire  Net_1090;
          wire  Net_467;
          wire  Net_1316;
          wire  Net_252;
          wire  Net_1089;
          wire  Net_1320;
          wire  Net_1257;
          wire  sclk_s_wire;
          wire  Net_1268;
          wire  Net_1297;
          wire  Net_547;
          wire  Net_1001;
          wire  mosi_s_wire;
          wire  rts_wire;
          wire  mosi_m_wire;
          wire  Net_891;
          wire  Net_1263;
          wire  miso_s_wire;
          wire  cts_wire;
          wire  Net_899;
          wire  tx_wire;
          wire  Net_1028;
          wire  rx_wire;
          wire  Net_916;
          wire  Net_1000;
          wire  scl_wire;
          wire  miso_m_wire;
          wire  Net_1172;
          wire  Net_1170;
          wire  select_s_wire;
          wire  sda_wire;
          wire  Net_847;

	wire [0:0] tmpOE__uart_rx_i2c_scl_spi_mosi_net;
	wire [0:0] tmpIO_0__uart_rx_i2c_scl_spi_mosi_net;
	wire [0:0] tmpINTERRUPT_0__uart_rx_i2c_scl_spi_mosi_net;
	electrical [0:0] tmpSIOVREF__uart_rx_i2c_scl_spi_mosi_net;

	cy_psoc3_pins_v1_10
		#(.id("1ec6effd-8f31-4dd5-a825-0c49238d524e/546f1f28-3a33-4888-bf93-14a95800f230"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		uart_rx_i2c_scl_spi_mosi
		 (.oe(tmpOE__uart_rx_i2c_scl_spi_mosi_net),
		  .y({1'b0}),
		  .fb({Net_1001}),
		  .io({tmpIO_0__uart_rx_i2c_scl_spi_mosi_net[0:0]}),
		  .siovref(tmpSIOVREF__uart_rx_i2c_scl_spi_mosi_net),
		  .interrupt({tmpINTERRUPT_0__uart_rx_i2c_scl_spi_mosi_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__uart_rx_i2c_scl_spi_mosi_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__uart_tx_i2c_sda_spi_miso_net;
	wire [0:0] tmpIO_0__uart_tx_i2c_sda_spi_miso_net;
	wire [0:0] tmpINTERRUPT_0__uart_tx_i2c_sda_spi_miso_net;
	electrical [0:0] tmpSIOVREF__uart_tx_i2c_sda_spi_miso_net;

	cy_psoc3_pins_v1_10
		#(.id("1ec6effd-8f31-4dd5-a825-0c49238d524e/e4eef7cc-20a7-45a2-a6af-d619f5982693"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		uart_tx_i2c_sda_spi_miso
		 (.oe(tmpOE__uart_tx_i2c_sda_spi_miso_net),
		  .y({1'b0}),
		  .fb({Net_547}),
		  .io({tmpIO_0__uart_tx_i2c_sda_spi_miso_net[0:0]}),
		  .siovref(tmpSIOVREF__uart_tx_i2c_sda_spi_miso_net),
		  .interrupt({tmpINTERRUPT_0__uart_tx_i2c_sda_spi_miso_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__uart_tx_i2c_sda_spi_miso_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	// select_s_VM (cy_virtualmux_v1_0)
	assign select_s_wire = s_ss;

	// rx_VM (cy_virtualmux_v1_0)
	assign rx_wire = rx_in;

	// rx_wake_VM (cy_virtualmux_v1_0)
	assign Net_1257 = uncfg_rx_irq;

	// clock_VM (cy_virtualmux_v1_0)
	assign Net_1170 = clock;

	// sclk_s_VM (cy_virtualmux_v1_0)
	assign sclk_s_wire = s_sclk;

	// mosi_s_VM (cy_virtualmux_v1_0)
	assign mosi_s_wire = Net_1001;

	// miso_m_VM (cy_virtualmux_v1_0)
	assign miso_m_wire = Net_547;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_1099));


    assign Net_1258 = Net_1099 | Net_847;


	cy_isr_v1_0
		#(.int_type(2'b10))
		SCB_IRQ
		 (.int_signal(interrupt));


	// cts_VM (cy_virtualmux_v1_0)
	assign cts_wire = cts_in;

    cy_m0s8_scb_v2_0 SCB (
        .rx(rx_wire),
        .miso_m(miso_m_wire),
        .select_m(select_m_wire[3:0]),
        .sclk_m(sclk_m_wire),
        .mosi_s(mosi_s_wire),
        .select_s(select_s_wire),
        .sclk_s(sclk_s_wire),
        .mosi_m(mosi_m_wire),
        .scl(scl_wire),
        .sda(sda_wire),
        .tx(tx_wire),
        .miso_s(miso_s_wire),
        .interrupt(interrupt),
        .cts(cts_wire),
        .rts(rts_wire),
        .tx_req(tx_tr_out),
        .rx_req(rx_tr_out),
        .clock(Net_1170));
    defparam SCB.scb_mode = 5;

	// Device_VM4 (cy_virtualmux_v1_0)
	assign uncfg_rx_irq = Net_1028;


    assign tx_out = tx_wire;

    assign rts_out = rts_wire;

    assign m_mosi = mosi_m_wire;

    assign m_sclk = sclk_m_wire;

    assign m_ss0 = select_m_wire[0];

    assign m_ss1 = select_m_wire[1];

    assign m_ss2 = select_m_wire[2];

    assign m_ss3 = select_m_wire[3];

    assign s_miso = miso_s_wire;


endmodule

// top
module top ;

          wire  Net_1048;
          wire  Net_989;
          wire  Net_988;
          wire  Net_987;
          wire  Net_986;
          wire  Net_985;
          wire  Net_984;
          wire  Net_983;
          wire  Net_982;
          wire  Net_981;
          wire  Net_980;
          wire  Net_979;
          wire  Net_978;
          wire  Net_977;
          wire  Net_976;
          wire  Net_970;
          wire  Net_975;
          wire  Net_974;
          wire  Net_973;
          wire  Net_972;
          wire  Net_836;
          wire  Net_838;
          wire  Net_835;
          wire  Net_837;
          wire  Net_830;
          wire  Net_829;
          wire  Net_828;
          wire  Net_827;
          wire  Net_826;
          wire  Net_825;
          wire  Net_823;
          wire  Net_822;
          wire  Net_746;
          wire  Net_820;
          wire  Net_819;
          wire  Net_818;
          wire  Net_817;
          wire  Net_816;
          wire  Net_815;
          wire  Net_814;
          wire  Net_813;
          wire  Net_812;
          wire  Net_811;
          wire  Net_528;
          wire  Net_810;
          wire  Net_542;
          wire  Net_541;
          wire  Net_540;
          wire  Net_539;
          wire  Net_538;
          wire  Net_537;
          wire  Net_536;
          wire  Net_535;
          wire  Net_534;
          wire  Net_533;
          wire  Net_552;
          wire  Net_551;
          wire  Net_550;
          wire  Net_549;
          wire  Net_548;
          wire  Net_547;
          wire  Net_546;
          wire  Net_545;
          wire  Net_544;
          wire  Net_543;
          wire  Net_479;
          wire  Net_478;
          wire  Net_477;
          wire  Net_476;
          wire  Net_475;
          wire  Net_474;
          wire  Net_473;
          wire  Net_472;
          wire  Net_471;
          wire  Net_470;
          wire  Net_226;
          wire  Net_225;
          wire  Net_224;
          wire  Net_223;
          wire  Net_809;
          wire  Net_808;
          wire  Net_807;
          wire  Net_806;
          wire  Net_805;
          wire  Net_804;
          wire  Net_803;
          wire  Net_802;
          wire  Net_801;
          wire  Net_800;
          wire  Net_799;
          wire  Net_798;
          wire  Net_91;
          wire  Net_90;
          wire  Net_89;
          wire  Net_88;
          wire  Net_87;
          wire  Net_86;
          wire  Net_85;
          wire  Net_84;
          wire  Net_394;
          wire  Net_381;
          wire  Net_380;
          wire  Net_379;
          wire  Net_378;
          wire  Net_377;
          wire  Net_376;
          wire  Net_375;
          wire  Net_374;
          wire  Net_373;
          wire  Net_372;
    electrical  Net_1026;
    electrical  Net_1010;
          wire  Net_13;
    electrical  Net_4467;
    electrical  Net_4522;
    electrical  Net_4525;
    electrical  Net_4442;
    electrical  Net_4462;
    electrical  Net_4471;
    electrical  Net_186;
    electrical  Net_185;
    electrical  Net_208;
          wire  Net_839;
          wire  Net_821;
          wire  Net_824;
          wire  Net_532;
          wire  Net_531;
          wire  Net_516;
          wire  Net_12;
          wire  Net_201;
          wire  Net_285;
          wire  Net_218;
          wire  Net_215;
          wire  Net_199;

    TCPWM_P4_v2_10_0 TCPWM_2 (
        .stop(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .capture(1'b0),
        .interrupt(Net_377),
        .ov(Net_378),
        .un(Net_379),
        .cc(Net_380),
        .line(Net_285),
        .line_n(Net_381),
        .clock(Net_12));


	cy_clock_v1_0
		#(.id("787416ae-b13e-4f40-8617-ce94f498dc9b"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("125000000"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_PWM_MAIN
		 (.clock_out(Net_12));


    CyControlReg_v1_80 DIR_REG (
        .control_1(Net_215),
        .control_2(Net_84),
        .control_3(Net_85),
        .control_0(Net_199),
        .control_4(Net_86),
        .control_5(Net_87),
        .control_6(Net_88),
        .control_7(Net_89),
        .clock(1'b0),
        .reset(1'b0));
    defparam DIR_REG.Bit0Mode = 0;
    defparam DIR_REG.Bit1Mode = 0;
    defparam DIR_REG.Bit2Mode = 0;
    defparam DIR_REG.Bit3Mode = 0;
    defparam DIR_REG.Bit4Mode = 0;
    defparam DIR_REG.Bit5Mode = 0;
    defparam DIR_REG.Bit6Mode = 0;
    defparam DIR_REG.Bit7Mode = 0;
    defparam DIR_REG.BitValue = 0;
    defparam DIR_REG.BusDisplay = 0;
    defparam DIR_REG.ExtrReset = 0;
    defparam DIR_REG.NumOutputs = 2;

    PWM_v3_30_1 INTERNAL_STEP (
        .reset(1'b0),
        .clock(Net_12),
        .tc(Net_799),
        .pwm1(Net_800),
        .pwm2(Net_801),
        .interrupt(Net_802),
        .capture(1'b0),
        .kill(1'b1),
        .enable(1'b1),
        .trigger(1'b0),
        .cmp_sel(1'b0),
        .pwm(Net_218),
        .ph1(Net_808),
        .ph2(Net_809));
    defparam INTERNAL_STEP.Resolution = 16;

	wire [0:0] tmpOE__INTERNAL_STEP_OUT_net;
	wire [0:0] tmpFB_0__INTERNAL_STEP_OUT_net;
	wire [0:0] tmpIO_0__INTERNAL_STEP_OUT_net;
	wire [0:0] tmpINTERRUPT_0__INTERNAL_STEP_OUT_net;
	electrical [0:0] tmpSIOVREF__INTERNAL_STEP_OUT_net;

	cy_psoc3_pins_v1_10
		#(.id("52f31aa9-2f0a-497d-9a1f-1424095e13e6"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		INTERNAL_STEP_OUT
		 (.oe(tmpOE__INTERNAL_STEP_OUT_net),
		  .y({Net_218}),
		  .fb({tmpFB_0__INTERNAL_STEP_OUT_net[0:0]}),
		  .io({tmpIO_0__INTERNAL_STEP_OUT_net[0:0]}),
		  .siovref(tmpSIOVREF__INTERNAL_STEP_OUT_net),
		  .interrupt({tmpINTERRUPT_0__INTERNAL_STEP_OUT_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__INTERNAL_STEP_OUT_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PWM_OUT_A_net;
	wire [0:0] tmpFB_0__PWM_OUT_A_net;
	wire [0:0] tmpIO_0__PWM_OUT_A_net;
	wire [0:0] tmpINTERRUPT_0__PWM_OUT_A_net;
	electrical [0:0] tmpSIOVREF__PWM_OUT_A_net;

	cy_psoc3_pins_v1_10
		#(.id("83c29c13-98a4-4b51-915f-d72f5a63a069"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		PWM_OUT_A
		 (.oe(tmpOE__PWM_OUT_A_net),
		  .y({Net_201}),
		  .fb({tmpFB_0__PWM_OUT_A_net[0:0]}),
		  .io({tmpIO_0__PWM_OUT_A_net[0:0]}),
		  .siovref(tmpSIOVREF__PWM_OUT_A_net),
		  .interrupt({tmpINTERRUPT_0__PWM_OUT_A_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PWM_OUT_A_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PWM_OUT_B_net;
	wire [0:0] tmpFB_0__PWM_OUT_B_net;
	wire [0:0] tmpIO_0__PWM_OUT_B_net;
	wire [0:0] tmpINTERRUPT_0__PWM_OUT_B_net;
	electrical [0:0] tmpSIOVREF__PWM_OUT_B_net;

	cy_psoc3_pins_v1_10
		#(.id("f1872a9a-e2e5-4fa8-bf68-a52a8d2a5226"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		PWM_OUT_B
		 (.oe(tmpOE__PWM_OUT_B_net),
		  .y({Net_285}),
		  .fb({tmpFB_0__PWM_OUT_B_net[0:0]}),
		  .io({tmpIO_0__PWM_OUT_B_net[0:0]}),
		  .siovref(tmpSIOVREF__PWM_OUT_B_net),
		  .interrupt({tmpINTERRUPT_0__PWM_OUT_B_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PWM_OUT_B_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__DIR_OUT_B_net;
	wire [0:0] tmpFB_0__DIR_OUT_B_net;
	wire [0:0] tmpIO_0__DIR_OUT_B_net;
	wire [0:0] tmpINTERRUPT_0__DIR_OUT_B_net;
	electrical [0:0] tmpSIOVREF__DIR_OUT_B_net;

	cy_psoc3_pins_v1_10
		#(.id("8ecf930f-9f68-43d9-9c06-ecf6ba170189"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		DIR_OUT_B
		 (.oe(tmpOE__DIR_OUT_B_net),
		  .y({Net_199}),
		  .fb({tmpFB_0__DIR_OUT_B_net[0:0]}),
		  .io({tmpIO_0__DIR_OUT_B_net[0:0]}),
		  .siovref(tmpSIOVREF__DIR_OUT_B_net),
		  .interrupt({tmpINTERRUPT_0__DIR_OUT_B_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__DIR_OUT_B_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__DIR_OUT_A_net;
	wire [0:0] tmpFB_0__DIR_OUT_A_net;
	wire [0:0] tmpIO_0__DIR_OUT_A_net;
	wire [0:0] tmpINTERRUPT_0__DIR_OUT_A_net;
	electrical [0:0] tmpSIOVREF__DIR_OUT_A_net;

	cy_psoc3_pins_v1_10
		#(.id("3d7c9960-2258-4db3-b0e1-b3f02eaab2db"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		DIR_OUT_A
		 (.oe(tmpOE__DIR_OUT_A_net),
		  .y({Net_215}),
		  .fb({tmpFB_0__DIR_OUT_A_net[0:0]}),
		  .io({tmpIO_0__DIR_OUT_A_net[0:0]}),
		  .siovref(tmpSIOVREF__DIR_OUT_A_net),
		  .interrupt({tmpINTERRUPT_0__DIR_OUT_A_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__DIR_OUT_A_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__STEP_INPUT_net;
	wire [0:0] tmpIO_0__STEP_INPUT_net;
	wire [0:0] tmpINTERRUPT_0__STEP_INPUT_net;
	electrical [0:0] tmpSIOVREF__STEP_INPUT_net;

	cy_psoc3_pins_v1_10
		#(.id("f7d1f408-a333-46e8-9ec4-c585a1a80291"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		STEP_INPUT
		 (.oe(tmpOE__STEP_INPUT_net),
		  .y({1'b0}),
		  .fb({Net_223}),
		  .io({tmpIO_0__STEP_INPUT_net[0:0]}),
		  .siovref(tmpSIOVREF__STEP_INPUT_net),
		  .interrupt({tmpINTERRUPT_0__STEP_INPUT_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__STEP_INPUT_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__DIR_INPUT_net;
	wire [0:0] tmpIO_0__DIR_INPUT_net;
	wire [0:0] tmpINTERRUPT_0__DIR_INPUT_net;
	electrical [0:0] tmpSIOVREF__DIR_INPUT_net;

	cy_psoc3_pins_v1_10
		#(.id("bc77ba4c-c29d-4857-b94d-1b6372eb95c1"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		DIR_INPUT
		 (.oe(tmpOE__DIR_INPUT_net),
		  .y({1'b0}),
		  .fb({Net_224}),
		  .io({tmpIO_0__DIR_INPUT_net[0:0]}),
		  .siovref(tmpSIOVREF__DIR_INPUT_net),
		  .interrupt({tmpINTERRUPT_0__DIR_INPUT_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__DIR_INPUT_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__STEP_INPUT_SOURCE_net;
	wire [0:0] tmpIO_0__STEP_INPUT_SOURCE_net;
	wire [0:0] tmpINTERRUPT_0__STEP_INPUT_SOURCE_net;
	electrical [0:0] tmpSIOVREF__STEP_INPUT_SOURCE_net;

	cy_psoc3_pins_v1_10
		#(.id("8d97cd9b-f51b-408e-b009-ed8ff5e367d4"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		STEP_INPUT_SOURCE
		 (.oe(tmpOE__STEP_INPUT_SOURCE_net),
		  .y({1'b0}),
		  .fb({Net_225}),
		  .io({tmpIO_0__STEP_INPUT_SOURCE_net[0:0]}),
		  .siovref(tmpSIOVREF__STEP_INPUT_SOURCE_net),
		  .interrupt({tmpINTERRUPT_0__STEP_INPUT_SOURCE_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__STEP_INPUT_SOURCE_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__DIR_INPUT_SOURCE_net;
	wire [0:0] tmpIO_0__DIR_INPUT_SOURCE_net;
	wire [0:0] tmpINTERRUPT_0__DIR_INPUT_SOURCE_net;
	electrical [0:0] tmpSIOVREF__DIR_INPUT_SOURCE_net;

	cy_psoc3_pins_v1_10
		#(.id("afe1087a-faeb-4f2f-91cc-3f9b725536b8"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		DIR_INPUT_SOURCE
		 (.oe(tmpOE__DIR_INPUT_SOURCE_net),
		  .y({1'b0}),
		  .fb({Net_226}),
		  .io({tmpIO_0__DIR_INPUT_SOURCE_net[0:0]}),
		  .siovref(tmpSIOVREF__DIR_INPUT_SOURCE_net),
		  .interrupt({tmpINTERRUPT_0__DIR_INPUT_SOURCE_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__DIR_INPUT_SOURCE_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    TCPWM_P4_v2_10_2 TCPWM_1 (
        .stop(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .capture(1'b0),
        .interrupt(Net_475),
        .ov(Net_476),
        .un(Net_477),
        .cc(Net_478),
        .line(Net_201),
        .line_n(Net_479),
        .clock(Net_12));

    TCPWM_P4_v2_10_3 TCPWM_4 (
        .stop(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .capture(1'b0),
        .interrupt(Net_548),
        .ov(Net_549),
        .un(Net_550),
        .cc(Net_551),
        .line(Net_532),
        .line_n(Net_552),
        .clock(Net_516));

    TCPWM_P4_v2_10_4 TCPWM_3 (
        .stop(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .capture(1'b0),
        .interrupt(Net_538),
        .ov(Net_539),
        .un(Net_540),
        .cc(Net_541),
        .line(Net_531),
        .line_n(Net_542),
        .clock(Net_516));

	wire [0:0] tmpOE__PWM_OUT_B_1_net;
	wire [0:0] tmpFB_0__PWM_OUT_B_1_net;
	wire [0:0] tmpIO_0__PWM_OUT_B_1_net;
	wire [0:0] tmpINTERRUPT_0__PWM_OUT_B_1_net;
	electrical [0:0] tmpSIOVREF__PWM_OUT_B_1_net;

	cy_psoc3_pins_v1_10
		#(.id("98563c74-d433-46d0-8815-f5ffc08d8de1"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		PWM_OUT_B_1
		 (.oe(tmpOE__PWM_OUT_B_1_net),
		  .y({Net_532}),
		  .fb({tmpFB_0__PWM_OUT_B_1_net[0:0]}),
		  .io({tmpIO_0__PWM_OUT_B_1_net[0:0]}),
		  .siovref(tmpSIOVREF__PWM_OUT_B_1_net),
		  .interrupt({tmpINTERRUPT_0__PWM_OUT_B_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PWM_OUT_B_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__PWM_OUT_A_1_net;
	wire [0:0] tmpFB_0__PWM_OUT_A_1_net;
	wire [0:0] tmpIO_0__PWM_OUT_A_1_net;
	wire [0:0] tmpINTERRUPT_0__PWM_OUT_A_1_net;
	electrical [0:0] tmpSIOVREF__PWM_OUT_A_1_net;

	cy_psoc3_pins_v1_10
		#(.id("01373a8d-5dbe-42f2-82a0-a07ee28d1dc1"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		PWM_OUT_A_1
		 (.oe(tmpOE__PWM_OUT_A_1_net),
		  .y({Net_531}),
		  .fb({tmpFB_0__PWM_OUT_A_1_net[0:0]}),
		  .io({tmpIO_0__PWM_OUT_A_1_net[0:0]}),
		  .siovref(tmpSIOVREF__PWM_OUT_A_1_net),
		  .interrupt({tmpINTERRUPT_0__PWM_OUT_A_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__PWM_OUT_A_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__INTERNAL_STEP_OUT_1_net;
	wire [0:0] tmpFB_0__INTERNAL_STEP_OUT_1_net;
	wire [0:0] tmpIO_0__INTERNAL_STEP_OUT_1_net;
	wire [0:0] tmpINTERRUPT_0__INTERNAL_STEP_OUT_1_net;
	electrical [0:0] tmpSIOVREF__INTERNAL_STEP_OUT_1_net;

	cy_psoc3_pins_v1_10
		#(.id("5a195fa6-11ab-4aa0-8cb8-063f7121b7b9"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		INTERNAL_STEP_OUT_1
		 (.oe(tmpOE__INTERNAL_STEP_OUT_1_net),
		  .y({Net_839}),
		  .fb({tmpFB_0__INTERNAL_STEP_OUT_1_net[0:0]}),
		  .io({tmpIO_0__INTERNAL_STEP_OUT_1_net[0:0]}),
		  .siovref(tmpSIOVREF__INTERNAL_STEP_OUT_1_net),
		  .interrupt({tmpINTERRUPT_0__INTERNAL_STEP_OUT_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__INTERNAL_STEP_OUT_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    PWM_v3_30_5 INTERNAL_STEP_1 (
        .reset(1'b0),
        .clock(Net_516),
        .tc(Net_528),
        .pwm1(Net_811),
        .pwm2(Net_812),
        .interrupt(Net_813),
        .capture(1'b0),
        .kill(1'b1),
        .enable(1'b1),
        .trigger(1'b0),
        .cmp_sel(1'b0),
        .pwm(Net_839),
        .ph1(Net_819),
        .ph2(Net_820));
    defparam INTERNAL_STEP_1.Resolution = 16;


	cy_clock_v1_0
		#(.id("ab271086-7616-4351-9ce5-7416104207be"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("125000000"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_PWM_MAIN_1
		 (.clock_out(Net_516));


    CyControlReg_v1_80 DIR_REG_1 (
        .control_1(Net_821),
        .control_2(Net_822),
        .control_3(Net_823),
        .control_0(Net_824),
        .control_4(Net_825),
        .control_5(Net_826),
        .control_6(Net_827),
        .control_7(Net_828),
        .clock(1'b0),
        .reset(1'b0));
    defparam DIR_REG_1.Bit0Mode = 0;
    defparam DIR_REG_1.Bit1Mode = 0;
    defparam DIR_REG_1.Bit2Mode = 0;
    defparam DIR_REG_1.Bit3Mode = 0;
    defparam DIR_REG_1.Bit4Mode = 0;
    defparam DIR_REG_1.Bit5Mode = 0;
    defparam DIR_REG_1.Bit6Mode = 0;
    defparam DIR_REG_1.Bit7Mode = 0;
    defparam DIR_REG_1.BitValue = 0;
    defparam DIR_REG_1.BusDisplay = 0;
    defparam DIR_REG_1.ExtrReset = 0;
    defparam DIR_REG_1.NumOutputs = 2;

	wire [0:0] tmpOE__DIR_OUT_B_1_net;
	wire [0:0] tmpFB_0__DIR_OUT_B_1_net;
	wire [0:0] tmpIO_0__DIR_OUT_B_1_net;
	wire [0:0] tmpINTERRUPT_0__DIR_OUT_B_1_net;
	electrical [0:0] tmpSIOVREF__DIR_OUT_B_1_net;

	cy_psoc3_pins_v1_10
		#(.id("5abd4ca1-e816-4992-b884-cedd78fc4dcc"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		DIR_OUT_B_1
		 (.oe(tmpOE__DIR_OUT_B_1_net),
		  .y({Net_824}),
		  .fb({tmpFB_0__DIR_OUT_B_1_net[0:0]}),
		  .io({tmpIO_0__DIR_OUT_B_1_net[0:0]}),
		  .siovref(tmpSIOVREF__DIR_OUT_B_1_net),
		  .interrupt({tmpINTERRUPT_0__DIR_OUT_B_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__DIR_OUT_B_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__DIR_OUT_A_1_net;
	wire [0:0] tmpFB_0__DIR_OUT_A_1_net;
	wire [0:0] tmpIO_0__DIR_OUT_A_1_net;
	wire [0:0] tmpINTERRUPT_0__DIR_OUT_A_1_net;
	electrical [0:0] tmpSIOVREF__DIR_OUT_A_1_net;

	cy_psoc3_pins_v1_10
		#(.id("5a1c7990-cd25-45fc-bc59-d060efc0d54a"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		DIR_OUT_A_1
		 (.oe(tmpOE__DIR_OUT_A_1_net),
		  .y({Net_821}),
		  .fb({tmpFB_0__DIR_OUT_A_1_net[0:0]}),
		  .io({tmpIO_0__DIR_OUT_A_1_net[0:0]}),
		  .siovref(tmpSIOVREF__DIR_OUT_A_1_net),
		  .interrupt({tmpINTERRUPT_0__DIR_OUT_A_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__DIR_OUT_A_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__STEP_INPUT_1_net;
	wire [0:0] tmpIO_0__STEP_INPUT_1_net;
	wire [0:0] tmpINTERRUPT_0__STEP_INPUT_1_net;
	electrical [0:0] tmpSIOVREF__STEP_INPUT_1_net;

	cy_psoc3_pins_v1_10
		#(.id("0f11354f-acdc-4f57-9bb6-0cebff6a74e7"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		STEP_INPUT_1
		 (.oe(tmpOE__STEP_INPUT_1_net),
		  .y({1'b0}),
		  .fb({Net_837}),
		  .io({tmpIO_0__STEP_INPUT_1_net[0:0]}),
		  .siovref(tmpSIOVREF__STEP_INPUT_1_net),
		  .interrupt({tmpINTERRUPT_0__STEP_INPUT_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__STEP_INPUT_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__DIR_INPUT_1_net;
	wire [0:0] tmpIO_0__DIR_INPUT_1_net;
	wire [0:0] tmpINTERRUPT_0__DIR_INPUT_1_net;
	electrical [0:0] tmpSIOVREF__DIR_INPUT_1_net;

	cy_psoc3_pins_v1_10
		#(.id("b3427416-fbe8-4821-bcd8-3aaa0dce77ef"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		DIR_INPUT_1
		 (.oe(tmpOE__DIR_INPUT_1_net),
		  .y({1'b0}),
		  .fb({Net_835}),
		  .io({tmpIO_0__DIR_INPUT_1_net[0:0]}),
		  .siovref(tmpSIOVREF__DIR_INPUT_1_net),
		  .interrupt({tmpINTERRUPT_0__DIR_INPUT_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__DIR_INPUT_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__STEP_INPUT_SOURCE_1_net;
	wire [0:0] tmpIO_0__STEP_INPUT_SOURCE_1_net;
	wire [0:0] tmpINTERRUPT_0__STEP_INPUT_SOURCE_1_net;
	electrical [0:0] tmpSIOVREF__STEP_INPUT_SOURCE_1_net;

	cy_psoc3_pins_v1_10
		#(.id("2af0c592-e4e5-4dfc-858b-718dac63389c"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		STEP_INPUT_SOURCE_1
		 (.oe(tmpOE__STEP_INPUT_SOURCE_1_net),
		  .y({1'b0}),
		  .fb({Net_838}),
		  .io({tmpIO_0__STEP_INPUT_SOURCE_1_net[0:0]}),
		  .siovref(tmpSIOVREF__STEP_INPUT_SOURCE_1_net),
		  .interrupt({tmpINTERRUPT_0__STEP_INPUT_SOURCE_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__STEP_INPUT_SOURCE_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__DIR_INPUT_SOURCE_1_net;
	wire [0:0] tmpIO_0__DIR_INPUT_SOURCE_1_net;
	wire [0:0] tmpINTERRUPT_0__DIR_INPUT_SOURCE_1_net;
	electrical [0:0] tmpSIOVREF__DIR_INPUT_SOURCE_1_net;

	cy_psoc3_pins_v1_10
		#(.id("b721bcfb-62ea-4b21-94c2-6c4c35c93dee"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		DIR_INPUT_SOURCE_1
		 (.oe(tmpOE__DIR_INPUT_SOURCE_1_net),
		  .y({1'b0}),
		  .fb({Net_836}),
		  .io({tmpIO_0__DIR_INPUT_SOURCE_1_net[0:0]}),
		  .siovref(tmpSIOVREF__DIR_INPUT_SOURCE_1_net),
		  .interrupt({tmpINTERRUPT_0__DIR_INPUT_SOURCE_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__DIR_INPUT_SOURCE_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 PWR_1 (
        .connect({
            Net_186
        })
    );
    defparam PWR_1.comp_name = "Power_v1_0";
    defparam PWR_1.port_names = "T1";
    defparam PWR_1.width = 1;

    cy_annotation_universal_v1_0 R_2 (
        .connect({
            Net_185,
            Net_186
        })
    );
    defparam R_2.comp_name = "Resistor_v1_0";
    defparam R_2.port_names = "T1, T2";
    defparam R_2.width = 2;

    cy_annotation_universal_v1_0 R_1 (
        .connect({
            Net_208,
            Net_186
        })
    );
    defparam R_1.comp_name = "Resistor_v1_0";
    defparam R_1.port_names = "T1, T2";
    defparam R_1.width = 2;

    SCB_P4_v3_20_6 Comm (
        .cts_in(1'b0),
        .tx_out(Net_973),
        .rts_out(Net_974),
        .interrupt(Net_975),
        .clock(Net_970),
        .rx_tr_out(Net_976),
        .tx_tr_out(Net_977),
        .s_mosi(1'b0),
        .s_sclk(1'b0),
        .s_ss(1'b0),
        .m_miso(1'b0),
        .m_mosi(Net_982),
        .m_sclk(Net_983),
        .m_ss0(Net_984),
        .m_ss1(Net_985),
        .m_ss2(Net_986),
        .m_ss3(Net_987),
        .s_miso(Net_988),
        .rx_in(1'b0));


	cy_clock_v1_0
		#(.id("786223dc-1513-4501-b429-4fe9d5fff01b"),
		  .source_clock_id("413DE2EF-D9F2-4233-A808-DFAF137FD877"),
		  .divisor(1),
		  .period("0"),
		  .is_direct(0),
		  .is_digital(0))
		CommCLK
		 (.clock_out(Net_970));


    cy_annotation_universal_v1_0 GND_1 (
        .connect({
            Net_4467
        })
    );
    defparam GND_1.comp_name = "Gnd_v1_0";
    defparam GND_1.port_names = "T1";
    defparam GND_1.width = 1;

    cy_annotation_universal_v1_0 GND_2 (
        .connect({
            Net_4471
        })
    );
    defparam GND_2.comp_name = "Gnd_v1_0";
    defparam GND_2.port_names = "T1";
    defparam GND_2.width = 1;

    cy_annotation_universal_v1_0 SW_3 (
        .connect({
            Net_4471,
            Net_1026
        })
    );
    defparam SW_3.comp_name = "SwitchSPST_v1_0";
    defparam SW_3.port_names = "T1, T2";
    defparam SW_3.width = 2;

    cy_annotation_universal_v1_0 Resistor_LED_4 (
        .connect({
            Net_4467,
            Net_4525
        })
    );
    defparam Resistor_LED_4.comp_name = "Resistor_v1_0";
    defparam Resistor_LED_4.port_names = "T1, T2";
    defparam Resistor_LED_4.width = 2;

    cy_annotation_universal_v1_0 LED_SW_2 (
        .connect({
            Net_4462,
            Net_4525
        })
    );
    defparam LED_SW_2.comp_name = "LED_v1_0";
    defparam LED_SW_2.port_names = "A, K";
    defparam LED_SW_2.width = 2;

	wire [0:0] tmpOE__STATUS_LED_2_net;
	wire [0:0] tmpFB_0__STATUS_LED_2_net;
	wire [0:0] tmpIO_0__STATUS_LED_2_net;
	wire [0:0] tmpINTERRUPT_0__STATUS_LED_2_net;
	electrical [0:0] tmpSIOVREF__STATUS_LED_2_net;

	cy_psoc3_pins_v1_10
		#(.id("6f4367c0-c8a0-4e05-bfdb-f8e9ae8460e2"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("M2"),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		STATUS_LED_2
		 (.oe(tmpOE__STATUS_LED_2_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__STATUS_LED_2_net[0:0]}),
		  .io({tmpIO_0__STATUS_LED_2_net[0:0]}),
		  .siovref(tmpSIOVREF__STATUS_LED_2_net),
		  .interrupt({tmpINTERRUPT_0__STATUS_LED_2_net[0:0]}),
		  .annotation({Net_4462}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__STATUS_LED_2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 Resistor_LED_1 (
        .connect({
            Net_4467,
            Net_4522
        })
    );
    defparam Resistor_LED_1.comp_name = "Resistor_v1_0";
    defparam Resistor_LED_1.port_names = "T1, T2";
    defparam Resistor_LED_1.width = 2;

    cy_annotation_universal_v1_0 LED_SW_1 (
        .connect({
            Net_4442,
            Net_4522
        })
    );
    defparam LED_SW_1.comp_name = "LED_v1_0";
    defparam LED_SW_1.port_names = "A, K";
    defparam LED_SW_1.width = 2;

	wire [0:0] tmpOE__STATUS_LED_1_net;
	wire [0:0] tmpFB_0__STATUS_LED_1_net;
	wire [0:0] tmpIO_0__STATUS_LED_1_net;
	wire [0:0] tmpINTERRUPT_0__STATUS_LED_1_net;
	electrical [0:0] tmpSIOVREF__STATUS_LED_1_net;

	cy_psoc3_pins_v1_10
		#(.id("cc4b0964-0d4f-430c-a31f-8fbb9a95ec0e"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases("M1"),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		STATUS_LED_1
		 (.oe(tmpOE__STATUS_LED_1_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__STATUS_LED_1_net[0:0]}),
		  .io({tmpIO_0__STATUS_LED_1_net[0:0]}),
		  .siovref(tmpSIOVREF__STATUS_LED_1_net),
		  .interrupt({tmpINTERRUPT_0__STATUS_LED_1_net[0:0]}),
		  .annotation({Net_4442}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__STATUS_LED_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 SW_1 (
        .connect({
            Net_4471,
            Net_1010
        })
    );
    defparam SW_1.comp_name = "SwitchSPST_v1_0";
    defparam SW_1.port_names = "T1, T2";
    defparam SW_1.width = 2;

	wire [1:0] tmpOE__Pin_Sw_net;
	wire [1:0] tmpFB_1__Pin_Sw_net;
	wire [1:0] tmpIO_1__Pin_Sw_net;
	electrical [0:0] tmpSIOVREF__Pin_Sw_net;

	cy_psoc3_pins_v1_10
		#(.id("b6f8dfe7-d226-4cb5-9784-bc382f301be6"),
		  .drive_mode(6'b010_010),
		  .ibuf_enabled(2'b1_1),
		  .init_dr_st(2'b1_1),
		  .input_clk_en(0),
		  .input_sync(2'b0_0),
		  .input_sync_mode(2'b0_0),
		  .intr_mode(4'b10_10),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(","),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(2'b0_0),
		  .oe_reset(0),
		  .oe_sync(2'b0_0),
		  .output_clk_en(0),
		  .output_clock_mode(2'b0_0),
		  .output_conn(2'b0_0),
		  .output_mode(2'b0_0),
		  .output_reset(0),
		  .output_sync(2'b0_0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(","),
		  .pin_mode("II"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(2'b1_1),
		  .sio_ibuf(""),
		  .sio_info(4'b00_00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(2'b0_0),
		  .spanning(0),
		  .use_annotation(2'b1_1),
		  .vtrip(4'b00_00),
		  .width(2),
		  .ovt_hyst_trim(2'b0_0),
		  .ovt_needed(2'b0_0),
		  .ovt_slew_control(4'b00_00),
		  .input_buffer_sel(4'b00_00))
		Pin_Sw
		 (.oe(tmpOE__Pin_Sw_net),
		  .y({2'b0}),
		  .fb({tmpFB_1__Pin_Sw_net[1:0]}),
		  .io({tmpIO_1__Pin_Sw_net[1:0]}),
		  .siovref(tmpSIOVREF__Pin_Sw_net),
		  .interrupt({Net_13}),
		  .annotation({Net_1026, Net_1010}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Pin_Sw_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{2'b11} : {2'b11};


	cy_isr_v1_0
		#(.int_type(2'b10))
		isr_GPIO
		 (.int_signal(Net_13));




endmodule

