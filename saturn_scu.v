module saturn_scu (
	input			RESET_N,	// (SYSRES_N).
	input			CLK28,		// (MCLK0). 28.63636 MHz (3.579545 MHz * 8).

	input			TEST_N,		// Test mode selection (normally tied High).
	
	
	// A-Bus "External Bus". (cart slot, SH-1 CD-ROM controller, MPEG connector etc.)...
	inout  [15:0]	AD,			// A-Bus Data bus (16-bit).
	output [25:0]	AA,			// A-Bus Addr bus (26?-bit). (bit A25 is on SCU pin 203).
	output  [1:0]	AFC,		// A-Bus Function Code.
	output			AAS_N,		// A-Bus Address Strobe.
	output			ACS0_N,		// A-Bus Chip Select 0. (Cart slot).
	output			ACS1_N,		// A-Bus Chip Select 1. (Cart slot).
	output			ACS2_N,		// A-Bus Chip Select 2. (CD-ROM controller).
	input			AWAIT_N,	// A-Bus external Wait.
	input			AIRQ_N,		// A-Bus external Interrupt.
	output			ARD_N,		// A-Bus Read pulse.
	output			AWRU_N,		// A-Bus byte 0 (AD15-8) write pulse.
	output			AWRL_N,		// A-Bus byte 1 (AD7-0) write pulse.
	output			ATIM0_N,	// A-Bus external access timing 0.
	output			ATIM1_N,	// A-Bus external access timing 1.
	output			ATIM2_N,	// A-Bus external access timing 2.
	
	
	// Note: B-Bus uses a multiplexed Addr/Data bus, so no separate address bus.
	
	// B-Bus "Internal Bus". (VDP1, VDP2, SCSP etc.)...
	inout  [15:0]	BD,			// B-Bus Addr / Data bus (16-bit, multiplexed).
	output			BADDT_N,	// B-Bus Addr/Data switching signal.
	output			BDTEN_N,	// B-Bus Data Enable.
	
	input			IRQL_N,		// B-Bus Light Pen Interrupt.
	input			IRQV_N,		// B-Bus VDP2 V-Blank Interrupt.
	input			IRQH_N,		// B-Bus VDP2 H-Blank Interrupt.
	input			BRDY2_N,	// B-Bus VDP2 Data Ready.
	output			BCS2_N,		// B-Bus VDP2 Chip Select.

	
	output			BCSS_N,		// B-Bus SCSP Chip Select.
	input			BRDYS_N,	// B-Bus SCSP Data Ready.
	input			IRQS_N,		// B-Bus SCSP Interrupt.
	
	output			BCS1_N,		// B-Bus VDP1 Chip Select.
	input			BRDY1_N,	// B-Bus VDP1 Data Ready.
	input			IRQ1_N,		// B-Bus VDP1 Interrupt.
	
	
	// Note: SH-2 Master/Slave bus access is controlled by the DCC chip, via BREQ_N, BGR_N, BRLS_N, BACK_N.
	// The DCC receives the BS_N (Bus Strobe) signal, but the SCU doesn't.
	// The DCC also controls access to Lower Work RAM DRAM via buffers IC26+IC27.
	//
	// Note: Lower Work RAM is actually async DRAM!
	
	// C-Bus... (SH-2 Master/Slave bus, Work RAM SDRAM, DCC, IPL ROM, BRAM, SMPC etc.)
	//
	// Almost certain that the SCU controls both the data and address busses during DMA.
	// ie. it looks like the internal DMAC of the SH-2 CPUs are disabled/ unused on the Saturn.
	// Correction: That assumption is likely wrong. mrkotfw on SegaXtreme said the SH2 DMAC can still be used by writing to the regs.
	// It's just that the external DREQ0_N/DREQ1_N inputs on both SH2s are tied High (inactive) on the Saturn mobo.
	//
	// It may also mean that other signals like RAS_N and CAS_N need to be changed to inout ports here.
	// Although, RAS_N and CAS_N are said to be SCU "output" pins in the PAL VA0 service manual?
	// So maybe the SCU handles all of the Upper SDRAM address multiplexing and refreshing, instead of the SH-2s? ElectronAsh.
	//
	// Update: On MAME, the Master SH-2 registers are set up for SDRAM with auto-refresh, so the SH-2 MUST be handling SDRAM refresh.
	// This backs up the theory that the RAS_N and CAS_N pins must be "inout" types, so they can be set to High-Z when the SCU isn't requesting the C-bus.
	//
	// Chapter 7.10 "Bus Arbitration", PDF page 218.The SH7604 user manual...
	// "The priority for bus requests when they occur simultaneously is, highest
	// to lowest, refresh requests, bus requests from external devices, DMAC and CPU."
	//
	inout  [31:0]	CD,			// C-Bus SH-2 Data bus (32-bit).
	inout  [24:0]	CA,			// C-Bus SH-2 Addr bus (25-bit).
	
								// NOTE: SH-2 CS0 (0x00000000-0x01FFFFFF) goes to the DDC, for accessing the BIOS ROM, SMPC, BRAM, Lower Work DRAM.
	
	input			CCS1_N,		// C-Bus Chip Select 1 (SH-2 0x02000000-0x03FFFFFF). (A-bus CS0 Cart slot). Service Manual says this is an Input? 
	
	input			CCS2_N,		// C-Bus Chip Select 2 (SH-2 0x04000000-0x05FFFFFF). (A-bus CS1 Cart slot,Dummy,CS2 CD-ROM. B-bus SCSP,VDP1,VDP2,SCU). Service Man says this is an Input?

	inout			CCS3_N,		// C-Bus Chip Select 3 (SH-2 0x06000000-0x07FFFFFF). (Upper Work RAM. 1MB. SDRAM CS_N). Service Manual says this is an Output? (driven during SDRAM DMA?)

	inout			CRDWR,		// C-Bus Read/Write. (Upper Work RAM SDRAM WE_N).

	input			CRD_N,		// C-Bus Read pulse. (SH-2 bus RD_N).
	
	inout			CDQMUU_N,	// Higher Work RAM. SDRAM byte 0 (CD31-24) Mask. DQM3. IC4 UDQM.
	inout			CDQMUL_N,	// Higher Work RAM. SDRAM byte 1 (CD23-16) Mask. DQM2. IC4 LDQM.
	
	inout			CDQMLU_N,	// Higher Work RAM. SDRAM byte 2 (CD15-8) Mask.  DQM1. IC3 UDQM.
	inout			CDQMLL_N,	// Higher Work RAM. SDRAM byte 3 (CD7-0)  Mask.  DQM0. IC3 LDQM.
	
	inout			RAS_N,		// Higher Work RAM. SDRAM RAS.	// Service Manual says this is an output?
	inout			CAS_N,		// Higher Work RAM. SDRAM CAS.	// Service Manual says this is an output?
	
	inout			CWAIT_N,	// C-Bus Master/Slave Wait.	// Service Manual says this is an output, but DDC also drives this?
	input			CIVECF_N,	// C-Bus Master SH-2 Interrupt Vector Fetch cycle.
	
	output			CIRL0_N,	// C-Bus external Interrupt factor 0.
	output			CIRL1_N,	// C-Bus external Interrupt factor 1.
	output			CIRL2_N,	// C-Bus external Interrupt factor 2.
	output			CIRL3_N,	// C-Bus external Interrupt factor 3.
	
	output			CBREQ_N,	// C-Bus Bus REQuest.	  EXBREQ_N to DCC!
	input			CBACK_N,	// C-Bus Bus ACKnowledge. EXBACK_N from DCC!
	
	input			MIREQ_N		// System Manager (SMPC) Interrupt.
);

// These addresses are all within the SH-2 CS0 range, but CS0 goes only to the DCC,
// so these addresses are likely not decoded by the SCU. ElectronAsh.
//
// 00000000-000FFFFF : Boot ROM (512K, mirrored every 512K)
// 00100000-0017FFFF : SMPC registers (128 bytes, mirrored every 128 bytes)
// 00180000-001FFFFF : Backup RAM (64K, mirrored every 64K) [1]
// 
// logic bios_cs  = (addr_int>=25'h00000000 && addr_int<=25'h000FFFFF);
// logic smpc_cs  = (addr_int>=25'h00100000 && addr_int<=25'h0010007F);
// logic bram_cs  = (addr_int>=25'h00100080 && addr_int<=25'h0018FFFF);
// logic wraml_cs = (addr_int>=25'h00200000 && addr_int<=25'h002FFFFF);
// logic minit_cs = (addr_int>=25'h01000000 && addr_int<=25'h01000003);
// logic sinit_cs = (addr_int>=25'h01800000 && addr_int<=25'h01800003);


// Internal address will have to change during DMA. ElectronAsh.
logic [24:0] addr_int = CA;

// NOTE: SH-2 CS0 (0x00000000-0x01FFFFFF) goes to the DDC, for accessing the BIOS ROM, SMPC, BRAM, Lower Work DRAM.
// SH-2 CS0 is not connected to the SCU, only CS1, CS2, CS3.

// SH-2 CS1 (0x02000000-0x03FFFFFF). A-bus CS0.
/*
logic abus_cs0		= !CCS1_N && addr_int[24:21]==4'b0001;	// 0x2000000 - 0x3FFFFFF)	// (A-bus CS0. Cart slot).

// SH-2 CS2 (0x04000000-0x058FFFFF). A-bus CS1, A-bus Dummy, A-bus CS2.
logic abus_cs1		= !CCS2_N && addr_int[24]   ==1'b0;		// 0x4000000 - 0x4FFFFFF);	// (A-bus CS1. Cart slot).
logic abus_dum		= !CCS2_N && addr_int[24:23]==1'b10;	// 0x5000000 - 0x57FFFFF);	// (A-bus Dummy).
logic abus_cs2		= !CCS2_N && addr_int[24:23]==1'b11;	// 0x5800000 - 0x58FFFFF);	// (A-bus CS2. CD-Rom controller).

// SH-2 CS2 (0x05A00000-0x05FDFFFF). B-bus.
logic scsp_68k_cs	= !CCS2_N && addr_int[24:21]==4'b1101;	// 0x5A00000 - 0x5AFFFFF);	// (B-bus SCSP 68000 Work RAM).
logic scsp_reg_cs	= !CCS2_N && addr_int[24:21]==4'b1101;	// 0x5B00000 - 0x5BFFFFF);	// (B-bus SCSP Registers).
logic vdp1_vram_cs	= !CCS2_N && addr_int[24:21]==4'b1110;	// 0x5C00000 - 0x5C7FFFF);	// (B-bus VDP1 VRAM. 512K).
logic vdp1_fb_cs 	= !CCS2_N && addr_int[24:21]==4'b1110;	// 0x5C80000 - 0x5CFFFFF);	// (B-bus VDP1 Framebuffer. 256K, mirrored every 256K).
logic vdp1_reg_cs	= !CCS2_N && addr_int[24:21]==4'b1110;	// 0x5D00000 - 0x5D7FFFF);	// (B-bus VDP1 Registers).
logic lockup_cs		= !CCS2_N && addr_int[24:21]==4'b1110;	// 0x5D80000 - 0x5DFFFFF);	// (B-bus Lockup when read!) (only added for debug.)
logic vdp2_vram_cs	= !CCS2_N && addr_int[24:21]==4'b1111;	// 0x5E00000 - 0x5EFFFFF);	// (B-bus VDP2 VRAM. 512K, mirrored every 512K).
logic vdp2_cram_cs	= !CCS2_N && addr_int[24:21]==4'b1111;	// 0x5F00000 - 0x5F7FFFF);	// (B-bus VDP2 CRAM. 4K, mirrored every 4K).
logic vdp2_reg_cs	= !CCS2_N && addr_int[24:21]==4'b1111;	// 0x5F80000 - 0x5FBFFFF);	// (B-bus VDP2 registers. 512 bytes, mirrored every 512 bytes).
logic ret_e0000_cs  = !CCS2_N && addr_int[24:18]==7'b1111111;	// 0x5FC0000 - 0x5FDFFFF);	// (Always returns $000E0000).
*/

// SH-2 CS2 (0x05FE0000-0x05FFFFFF).
logic scu_reg_cs	= !CCS2_N && addr_int[24:16]==9'b111111110;	// 0x5FE0000 - 0x5FEFFFF);	// (SCU internal reg. 256 bytes, mirrored every 256 bytes).
//logic unk_reg_cs	= !CCS2_N && addr_int[24:16]==9'b111111110;	// 0x5FF0000 - 0x5FFFFFF);	// (Unknown regs. 256 bytes, mirrored every 256 bytes).


// SH-2 CS3 (0x06000000-0x07FFFFFF). Upper Work RAM SDRAM.
//logic wramh_cs		= (addr_int>=25'h06000000 && addr_int<=060FFFFF); // Can be accessed directly by either SH-2, or driven by the SCU during DMA.
logic wramh_cs		= !CCS3_N; // Can be accessed directly by either SH-2, or driven by the SCU during DMA.


// SH2 CS1. A-bus CS0...
assign ACS0_N = !(!CCS1_N && addr_int[24:21]==4'b0001);		// 0x02000000-0x03FFFFFF. A-bus CS0. Cart slot. (SH2 CS1 !)

// SH2 CS2. A-bus CS1...
assign ACS1_N = !(!CCS2_N && addr_int[24]   ==1'b0);		// 0x04000000-0x04FFFFFF. A-bus CS1. Cart slot. (SH2 CS2 !)
															// 0x05000000-0x057FFFFF. A-bus dummy?
// SH2 CS2. A-bus CS2...
assign ACS2_N = !(!CCS2_N && addr_int[24:23]==1'b11);		// 0x05800000-0x058FFFFF. A-bus CS2. CD-ROM controller.  (SH2 CS2 !)

assign ARD_N  = !( (!ACS0_N | !ACS1_N | !ACS2_N) & !CRD_N);


// SH2 CS2. B-bus...
assign BCSS_N = !(!CCS2_N && addr_int[24:21]==4'b1101);		// 0x05A00000-0x05BFFFFF. (only the lower 8 bits of the B-bus connect to the SCSP. Special case?)
assign BCS1_N = !(!CCS2_N && addr_int[24:21]==4'b1110);		// 0x05C00000-0x05DFFFFF. (the "lockup" range likely also gets decoded).
assign BCS2_N = !(!CCS2_N && addr_int[24:21]==4'b1111);		// 0x05E00000-0x05FDFFFF. (the "ret_e0000" range might get decoded anyway, or is it a partially floating bus?)


// SCU reg chip selects...
logic D0R_CS	= scu_reg_cs && addr_int[7:2]==6'b000000;	// 0x5FE0000. DMA Level 0 Read address register.
logic D0W_CS	= scu_reg_cs && addr_int[7:2]==6'b000001;	// 0x5FE0004. DMA Level 0 Write address register.
logic D0C_CS	= scu_reg_cs && addr_int[7:2]==6'b000010;	// 0x5FE0008. DMA Level 0 byte Count register.
logic D0AD_CS	= scu_reg_cs && addr_int[7:2]==6'b000011;	// 0x5FE000C. DMA Level 0 address Add value register.
logic D0EN_CS	= scu_reg_cs && addr_int[7:2]==6'b000100;	// 0x5FE0010. DMA Level 0 DMA Enable register.
logic D0MD_CS	= scu_reg_cs && addr_int[7:2]==6'b000101;	// 0x5FE0014. DMA Level 0 DMA Mode register.
// 0x5FE0018-0x5FE001C unused.
logic D1R_CS	= scu_reg_cs && addr_int[7:2]==6'b001000;	// 0x5FE0020. DMA Level 1 Read address register.
logic D1W_CS	= scu_reg_cs && addr_int[7:2]==6'b001001;	// 0x5FE0024. DMA Level 1 Write address register.
logic D1C_CS	= scu_reg_cs && addr_int[7:2]==6'b001010;	// 0x5FE0028. DMA Level 1 byte Count register.
logic D1AD_CS	= scu_reg_cs && addr_int[7:2]==6'b001011;	// 0x5FE002C. DMA Level 1 address Add value register.
logic D1EN_CS	= scu_reg_cs && addr_int[7:2]==6'b001100;	// 0x5FE0030. DMA Level 1 DMA Enable register.
logic D1MD_CS	= scu_reg_cs && addr_int[7:2]==6'b001101;	// 0x5FE0034. DMA Level 1 DMA Mode register.
// 0x5FE0038-0x5FE003C unused.
logic D2R_CS	= scu_reg_cs && addr_int[7:2]==6'b010000;	// 0x5FE0040. DMA Level 2 Read address register.
logic D2W_CS	= scu_reg_cs && addr_int[7:2]==6'b010001;	// 0x5FE0044. DMA Level 2 Write address register.
logic D2C_CS	= scu_reg_cs && addr_int[7:2]==6'b010010;	// 0x5FE0048. DMA Level 2 byte Count register.
logic D2A0_CS	= scu_reg_cs && addr_int[7:2]==6'b010011;	// 0x5FE004C. DMA Level 2 address Add value register.
logic D2EN_CS	= scu_reg_cs && addr_int[7:2]==6'b010100;	// 0x5FE0050. DMA Level 2 DMA Enable register.
logic D2MD_CS	= scu_reg_cs && addr_int[7:2]==6'b010101;	// 0x5FE0054. DMA Level 2 DMA Mode register.
// 0x5FE0058-0x5FE005C unused.
logic DSTP_CS	= scu_reg_cs && addr_int[7:2]==6'b011000;	// 0x5FE0060. DMA Forced Stop register.
// 0x5FE0064-0x5FE0078 unused.
logic DSTA_CS	= scu_reg_cs && addr_int[7:2]==6'b011111;	// 0x5FE007C. DMA Status register.

logic PPAF_CS	= scu_reg_cs && addr_int[7:2]==6'b100000;	// 0x5FE0080. DSP Program Control Port.
logic PPD_CS	= scu_reg_cs && addr_int[7:2]==6'b100001;	// 0x5FE0084. DSP Program RAM Data Port.
logic PDA_CS	= scu_reg_cs && addr_int[7:2]==6'b100010;	// 0x5FE0088. DSP Data RAM Address Port.
logic PDD_CS	= scu_reg_cs && addr_int[7:2]==6'b100011;	// 0x5FE008C. DSP Data RAM Data Port.

logic T0C_CS	= scu_reg_cs && addr_int[7:2]==6'b100100;	// 0x5FE0090. Timer 0 Compare Register.
logic T1S_CS	= scu_reg_cs && addr_int[7:2]==6'b100101;	// 0x5FE0094. Timer 1 Set Data Register.
logic T1MD_CS	= scu_reg_cs && addr_int[7:2]==6'b100110;	// 0x5FE0098. Timer 1 Mode Register.
// 0x5FE009C unused.

logic IMS_CS	= scu_reg_cs && addr_int[7:2]==6'b101000;	// 0x5FE00A0. Interrupt Mask register.
logic IST_CS	= scu_reg_cs && addr_int[7:2]==6'b101001;	// 0x5FE00A4. Interrupt Status register.

logic AIACK_CS	= scu_reg_cs && addr_int[7:2]==6'b101010;	// 0x5FE00A8. A-Bus Interrupt Acknowledge register.
// 0x5FE00AC unused.
logic ASR0_CS	= scu_reg_cs && addr_int[7:2]==6'b101100;	// 0x5FE00B0. A-Bus (CS0 and CS1) Set register.
logic ASR1_CS	= scu_reg_cs && addr_int[7:2]==6'b101101;	// 0x5FE00B4. A-Bus (CS2 and Dummy) Set register.
logic AREF_CS	= scu_reg_cs && addr_int[7:2]==6'b101110;	// 0x5FE00B8. A-Bus Refresh register.

//logic AIAK_CS	= scu_reg_cs && addr_int[7:2]==6'b101111;	// 0x5FE00BC. NOTE: Probable mistake in SCU User Manual page 161 (PDF page 177)? Reg is marked as "Free" in sega_scu.cpp in MAME.
// 0x5FE00C0 unused.

logic RSEL_CS	= scu_reg_cs && addr_int[7:2]==6'b110001;	// 0x5FE00C4. SCU SDRAM Select Bit.
logic VER_CS	= scu_reg_cs && addr_int[7:2]==6'b110010;	// 0x5FE00C8. SCU Version register.
// 0x5FE00CC unused.


// Level 2-0 DMA Set Registers...
//
// Offset...
// 0x00. [26:0]=Read Address (in BYTES).
// 0x04. [26:0]=Write Address (in BYTES).
// 0x08. [31:0]=Transfer byte number (in BYTES). (byte count).
// 0x0C. [8]=Read addr increment value. [2:0]=Write addr increment value.
// 0x10. [8]=DMA enable bit. [0]=DMA starting bit.
// 0x14. [24]=DMA mode bit (0=Direct. 1=Indirect). [16]=Read addr update. [8]=Write addr update. [2:0]=DMA start factor select bit.
// 0x18. Reg not used?
// 0x1C. Reg not used?
//
// DMA Level 0 regs...
logic [31:0] D0R;	// 0x5FE0000.
logic [31:0] D0W;	// 0x5FE0004.
logic [31:0] D0C;	// 0x5FE0008.
logic [31:0] D0AD;	// 0x5FE000C.
logic [31:0] D0EN;	// 0x5FE0010.
logic [31:0] D0MD;	// 0x5FE0014.
// 0x5FE0018-0x5FE001C unused.

// DMA Level 1 regs...
logic [31:0] D1R;	// 0x5FE0020.
logic [31:0] D1W;	// 0x5FE0024.
logic [31:0] D1C;	// 0x5FE0028.
logic [31:0] D1AD;	// 0x5FE002C.
logic [31:0] D1EN;	// 0x5FE0030.
logic [31:0] D1MD;	// 0x5FE0034.
// 0x5FE0038-0x5FE003C unused.

// DMA Level 2 regs...
logic [31:0] D2R;	// 0x5FE0040.
logic [31:0] D2W;	// 0x5FE0044.
logic [31:0] D2C;	// 0x5FE0048.
logic [31:0] D2A0;	// 0x5FE004C.
logic [31:0] D2EN;	// 0x5FE0050.
logic [31:0] D2MD;	// 0x5FE0054.
// 0x5FE0058-0x5FE005C unused.


// 0x25FE0060 = DMA Force-Stop Register.
// [0] Writing 1 to this will force the DMA operation to stop.
// However, if the DMA is forced to stop, it can no longer be used.
// This register should not be used except for debugging.
//
logic [31:0] DSTP;	// 0x5FE0060.
// 0x5FE0064-0x5FE0078 unused.


// 0x25FE007C = DMA Status Register. (Read-only).
logic [31:0] DSTA;	// 0x5FE007C.
// [22]=DMA DSP-Bus access flag. 0=no access. 1=access.
// [21]=DMA B-Bus access flag.   0=no access. 1=access.
// [20]=DMA A-Bus access flag.   0=no access. 1=access.
// [19:18] not used.
// [17]=Level 1 DMA interrupt flag.
// [16]=Level 0 DMA interrupt flag.
// [15:14] not used.
// [13]=Level 2 DMA standby flag.
// [12]=Level 2 DMA in operation.
// [11:10] not used.
// [9]=Level 1 DMA standby flag.
// [8]=Level 1 DMA in operation.
// [7:6] not used.
// [5]=Level 0 DMA standby flag.
// [4]=Level 0 DMA in operation.
// [3:2] not used.
// [1]=DSP side DMA standby flag.
// [0]=DSP side DMA in operation.


// 0x25FE0080 = DSP Program Control Port. RW
// [26]=EX cancels pause briefly. 0=no execute. 1=execute.
// [25]=EX executes pause briefly. 0=no execute. 1=execute.
// [24]. not used.
// [23]=D0 bus use DMA execution flag. (DMA in progress)
// [22]=Sign flag. (says "Sine flag" in the SCU manual).
// [21]=Zero flag.
// [20]=Carry flag.
// [19]=Overflow flag.
// [18]=Program end interrupt flag.
// [17]=Program step execute control bit. 0=no execute. 1=execute.
// [16]=Program execute control. 0=stop. 1=execute.
// [15]=Program counter load authorization.
// [14:8] not used.
// [7:0]=Program RAM address. (Program Counter).
logic [31:0] PPAF;	// 0x5FE0080.

// 0x05FE0084 = DSP Program RAM Data Port.
// This port is used as a go-between when transferring data from the CPU to the DSP.
// The start address is written to the DSP Program Control Port bits [7:0] (above).
logic [31:0] PPD;	// 0x5FE0084.

// 0x05FE0088 = DSP Data RAM Address Port.
// [7:0]. Data RAM start address for read / write access.
// (pretty sure the address will auto-increment on further accesses? ElectronAsh.) 
logic [31:0] PDA;	// 0x5FE0088.

// 0x05FE008C = DSP Data RAM Data Port.
// [31:0]. Data written by the CPU is stored in DSP data RAM.
// The CPU can also read from DSP RAM via this register.
logic [31:0] PDD;	// 0x5FE008C.


// 0x05FE0090 = Timer 0 Compare Register.
// [9:0]. Timer 0 gets in sync with V-Blank-IN interrupt,
// and causes interrupt to occur.
logic [31:0] T0C;	// 0x5FE0090.

// 0x05FE0094 = Timer 1 Set Data Register.
// [8:0]. Timer 1 is *data-set* by H-Blank-IN interrupt,
// and decremented by 7 MHz cycles.
// Interrupt occurs when data is 0.
logic [31:0] T1S;	// 0x5FE0094.

// 0x05FE0098 = Timer 1 Mode Register.
// [8]. Timer 1 mode bit. 0=occurs at each line. 1=occurs only for lines designated by timer 0.
// [0]. Timer 1 enable bit. 0=Timer OFF. 1=Timer ON.
logic [31:0] T1MD;	// 0x5FE0098.
// 0x5FE009C unused.


// 0x05FE00A0 = Interrupt Mask Register.
// [15]. A-Bus interrupt mask bit.
// [13]. Other interrupt mask bits. 
// When a bit is 0, the interrupt is NOT masked, and allowed to trigger.
// When a bit is 1, the interrupt is masked, and will NOT trigger.
logic [31:0] IMS;	// 0x5FE00A0.

// 0x05FE00A4 = Interrupt Status Register.
// [31:16] and [13:0].
// When reading, each bit shows which interrupt has occurred.
//
// When writing: If a 0 is written to a bit, that interrupt bit is cleared.
// If a 1 is written to a bit, it maintains the current interrupt status.
logic [31:0] IST;	// 0x5FE00A4.

// 0x25FE00A8 = A-Bus Interrupt Acknowledge Register.
// [0]=RW. Ack bit.
logic [31:0] AIACK;	// 0x5FE00A8.

// 0x25FE00B0 = A-Bus Set Register (for CS0 and CS1).
// CS0 space...
// [31]. CS0 space, pre-read significant bit.
// [30]. CS0 space, precharge insertion bit after write.
// [29]. CS0 space, precharge insertion bit after read.
// [28]. CS0 space, external wait significant bit.
// [27:24]. CS0 space, burst cycle wait no.
// [23:20]. CS0 space, single cycle wait no.
// [19:18]. CS0 space, burst length set.
// [17] not used.
// [16]. CS0 space, bus size set bit (0=16bit 1=8bit)
// CS1 space...
// [15]. CS1 space, pre-read significant bit.
// [14]. CS1 space, precharge insertion bit after write.
// [13]. CS1 space, precharge insertion bit after read.
// [12]. CS1 space, external wait significant bit.
// [11:8]. CS1 space, burst cycle wait no.
// [7:4]. CS1 space, normal cycle wait no.
// [3:2]. CS1 space, burst length set bit
// [1] not used.
// [0] CS1 space, bus size set bit (0=16bit. 1=8bit).
logic [31:0] ASR0;	// 0x5FE00B0. A-Bus CS0 and CS1.

// 0x25FE00B4 = A-Bus Set Register (for CS2 and Spare).
// CS2 space...
// [31]. CS2 space, pre-read significant bit
// [30]. CS2 space, precharge insertion bit after write.
// [29]. CS2 space, precharge insertion bit after read.
// [28]. CS2 space, external wait significant bit.
// [27:20] not used.
// [19:18]. CS2 space, burst length bit set.
// [17] not used.
// [16]. CS2 space, bus size set bit (0=16bit. 1=8bit).
//
// Spare space...
// [15]. Spare space, pre-read significant bit.
// [14]. Spare space, precharge insertion after write.
// [13]. Spare space, precharge insertion after read.
// [12]. Spare space, external wait significant bit.
// [11:8]. Spare space, burst cycle wait no. set bit.
// [7:4]. Spare space, normal cycle wait no. set bit.
// [3:2]. Spare space, burst length set bit.
// [1] not used.
// [0] Spare space, bus size set bit (0=16bit. 1=8bit).
logic [31:0] ASR1;	// 0x5FE00B4. A-Bus CS2 and Dummy.

// 0x25FE00B8 = A-Bus Refresh Register.
// [4]. Refresh output significant bit.(refresh enable, probably).
// [3:0]. Refresh wait number set bit. (refresh counter time).
logic [31:0] AREF;	// 0x5FE00B8.


// 0x25FE00C4 = SCU SDRAM Select Register.
// [0]. Work-SDRAM select bit. 0=2Mbit x2. 1=4Mbit x2.
logic [31:0] RSEL;	// 0x5FE00C4.


// 0x25FE00C8 = SCU Version Register.
// [3:0] = Version number.
logic [31:0] VER = {28'b0000000, 4'd4};	// 0x5FE00C8. Return a value of 4. (from MAME sega_scu.cpp source).


endmodule
