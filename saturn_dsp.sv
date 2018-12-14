module saturn_dsp (
	input logic CLOCK,
	
	input logic RESET_N,
	
	input logic [31:0] D0_BUS_IN,
	output logic [31:0] D0_BUS_OUT,
	
	input [7:0] D0_ADDR,
	input D0_WRITE,
	
	input EXEC,
	
	output logic MD0_WREN,
	output logic MD1_WREN,
	output logic MD2_WREN,
	output logic MD3_WREN,
	
`ifdef VERILATOR
	output logic [31:0] FETCH,
	
	output logic [31:0] MD0_DOUT,
	output logic [31:0] MD1_DOUT,
	output logic [31:0] MD2_DOUT,
	output logic [31:0] MD3_DOUT,

	output logic LOAD_CT0,
	output logic LOAD_CT1,
	output logic LOAD_CT2,
	output logic LOAD_CT3,

	output logic INC_CT0,
	output logic INC_CT1,
	output logic INC_CT2,
	output logic INC_CT3,
	
	output logic MD0_TO_X,
	output logic MD1_TO_X,
	output logic MD2_TO_X,
	output logic MD3_TO_X,
	
	output logic MD0_TO_Y,
	output logic MD1_TO_Y,
	output logic MD2_TO_Y,
	output logic MD3_TO_Y,

	output logic MD0_TO_D1,
	output logic MD1_TO_D1,
	output logic MD2_TO_D1,
	output logic MD3_TO_D1,
	
	output logic D1_TO_MD0,
	output logic D1_TO_MD1,
	output logic D1_TO_MD2,
	output logic D1_TO_MD3,
	
	output logic ACH_TO_D1,
	output logic ACL_TO_D1,
	
	output logic LOAD_MD0,
	output logic LOAD_MD1,
	output logic LOAD_MD2,
	output logic LOAD_MD3,
	
	output logic X_TO_RX,
	output logic D1_TO_RX,
	
	output logic LOAD_RX,
	output logic LOAD_RY,
	
	output logic PC_TO_TOP,
	output logic D1_TO_TOP,
	
	output logic MUL_TO_P,
	output logic P_TO_PL,
	output logic X_TO_PL,
	output logic D1_TO_PL,
	
	output logic LOAD_PL,
	output logic LOAD_PH,
	
	output logic ALU_TO_A,
	output logic Y_TO_ACL,
	
	output logic LOAD_ACH,
	output logic LOAD_ACL,

	output logic IMM_TO_D1,	// I think IMM to "D0" is a mistake on the block diagram. ElectronAsh.
	
	output logic IMM_TO_LOP,
	output logic D1_TO_LOP,
	
	output logic PC_TO_D0,

	output logic LOAD_RA,
	output logic RA_TO_RAMS,
	
	output logic SHIFT_L16_TO_D1,
	
	output logic CLR_A,
	
	output logic LOAD_RA0,
	output logic LOAD_WA0,
	
	output logic LOAD_LOP,
	output logic LOAD_TOP,
	
	output logic LOAD_PROG_RAM,
	
	output logic [47:0] P_REG,
	output logic [47:0] A_REG,
	
	output logic [31:0] D1_BUS,
	
	output logic [5:0] CT0,
	output logic [5:0] CT1,
	output logic [5:0] CT2,
	output logic [5:0] CT3,
	
	output logic [31:0] RA0,
	output logic [31:0] WA0,	
`endif
	
	output logic [7:0] INST_ADDR,	
	input logic [31:0] INST_IN
	
);

logic MD0_TO_D0;
logic MD1_TO_D0;
logic MD2_TO_D0;
logic MD3_TO_D0;
logic [31:0] D0_BUS = (MD0_TO_D0) ? MD0_DOUT :
					  (MD1_TO_D0) ? MD1_DOUT :
					  (MD2_TO_D0) ? MD2_DOUT :
					  (MD3_TO_D0) ? MD3_DOUT :
					  32'h00000000;

logic MD0_TO_D1;
logic MD1_TO_D1;
logic MD2_TO_D1;
logic MD3_TO_D1;
assign D1_BUS = 	  (MD0_TO_D1) ? MD0_DOUT :
					  (MD1_TO_D1) ? MD1_DOUT :
					  (MD2_TO_D1) ? MD2_DOUT :
					  (MD3_TO_D1) ? MD3_DOUT : 
					  (IMM_TO_D1) ? {24'h000000,FETCH[7:0]} :
					  32'h00000000;

logic MD0_TO_X;
logic MD1_TO_X;
logic MD2_TO_X;
logic MD3_TO_X;
logic [31:0] X_BUS = (MD0_TO_X) ? MD0_DOUT :
					 (MD1_TO_X) ? MD1_DOUT :
					 (MD2_TO_X) ? MD2_DOUT :
					 (MD3_TO_X) ? MD3_DOUT :
					 32'h00000000;

logic MD0_TO_Y;
logic MD1_TO_Y;
logic MD2_TO_Y;
logic MD3_TO_Y;
logic [31:0] Y_BUS = (MD0_TO_Y) ? MD0_DOUT :
					 (MD1_TO_Y) ? MD1_DOUT :
					 (MD2_TO_Y) ? MD2_DOUT :
					 (MD3_TO_Y) ? MD3_DOUT :
					 32'h00000000;


`ifndef VERILATOR			
logic [5:0] CT0;
logic [5:0] CT1;
logic [5:0] CT2;
logic [5:0] CT3;
`endif


// "RA (W) This is the register that stores the address for accessing the data
// RAM. This register is 8 bit. The RAM designation number (0-3) is
// stored by the high-order 2 bits. The RAM access address is stored in the lower 6 bits."
//
// In other words. Bits [7:6] select one of the four Data RAMs,
// and bits [5:0] select the address within the selected Data RAM. ElectronAsh.
//
logic [7:0] RA;

`ifndef VERILATOR
logic [31:0] RA0;
logic [31:0] WA0;
`endif


logic [31:0] RX;		// Multiplier first input register.
logic [31:0] RY;		// Multiplier second input register.
logic [47:0] MUL_RESULT = RX * RY;	// The multiplier itself...

`ifdef VERILATOR
logic [47:0] P_REG;	// The P register PH(16),PL(32), for latching the multiplier result, and feeding to the ALU "B" input...
`endif

// Accumulator.
`ifdef VERILATOR
logic [47:0] A_REG;	// The A register ACH(16),ACL(32).
`endif


// "This is an 8-bit register that stores the lead address. The jump command and
// subroutine execution process store the lead address in this register and executes the process."
logic [7:0] TOP;

// Instruction Fetch register.
`ifndef VERILATOR
logic [31:0] FETCH;
`endif

always_ff @(posedge CLOCK)
if (!RESET_N) begin
	FETCH <= 32'h00000000;
	INST_ADDR <= 0;
end
else begin
	if (EXEC) begin
		FETCH <= INST_IN;
		INST_ADDR <= INST_ADDR + 1;
	end
	
	if (MUL_TO_P) P_REG <= MUL_RESULT;
	
	if (CLR_A) A_REG <= 48'h000000000000;
	if (ALU_TO_A) A_REG <= ALU_RES;
	
	if (LOAD_CT0) CT0 <= D1_BUS;
	if (LOAD_CT1) CT1 <= D1_BUS;
	if (LOAD_CT2) CT2 <= D1_BUS;
	if (LOAD_CT3) CT3 <= D1_BUS;
	
	if (INC_CT0) CT0 <= CT0 + 1'b1;
	if (INC_CT1) CT1 <= CT1 + 1'b1;
	if (INC_CT2) CT2 <= CT2 + 1'b1;
	if (INC_CT3) CT3 <= CT3 + 1'b1;
	
	if (LOAD_RA0) RA0 <= D1_BUS;
	if (LOAD_WA0) WA0 <= D1_BUS;
end


// "This is a 12-bit register that stores the loop counter. The number of
// loops is set by the process of repeating 1 command."
logic [11:0] LOP;


logic [47:0] ALU_RES;
logic S_FLAG;
logic Z_FLAG;
logic C_FLAG;
logic V_FLAG;

alu alu_inst (
	.A_BUS( A_REG ),		// ACH(16),ACL(32).
	.B_BUS( P_REG ),		// PH(16), PL(32).
	
	.OP( FETCH[29:26] ),	// OPERATION.
	
	.RESULT( ALU_RES ),		// Duh.
	
	.S_FLAG( S_FLAG ),
	.Z_FLAG( Z_FLAG ),
	.C_FLAG( C_FLAG ),
	.V_FLAG( V_FLAG )
);

// Allow external D0 Bus / Data RAM read access...
assign D0_BUS_OUT = (D0_ADDR[7:6]==2'd0) ? MD0_DOUT :
					(D0_ADDR[7:6]==2'd1) ? MD1_DOUT :
					(D0_ADDR[7:6]==2'd2) ? MD2_DOUT :
										   MD3_DOUT;


logic D0_MD0_WRITE = D0_WRITE && D0_ADDR[7:6]==2'b00;
logic [5:0] MD0_ADDR = (D0_MD0_WRITE) ? D0_ADDR[5:0] : CT0;
logic [31:0] MD0_DI = (D0_MD0_WRITE) ? D0_BUS_IN : D1_BUS;
assign MD0_WREN = LOAD_MD0 | D0_MD0_WRITE;
`ifndef VERILATOR
logic [31:0] MD0_DOUT;
`endif
data_ram	data_ram_md0 (
	.clock ( CLOCK ),
	
	.address ( MD0_ADDR ),
	.data ( MD0_DI ),
	.wren ( MD0_WREN ),
	
	.q ( MD0_DOUT )
);

logic D0_MD1_WRITE = D0_WRITE && D0_ADDR[7:6]==2'b01;
logic [5:0] MD1_ADDR = (D0_MD1_WRITE) ? D0_ADDR[5:0] : CT1;
logic [31:0] MD1_DI = (D0_MD1_WRITE) ? D0_BUS_IN : D1_BUS;
assign MD1_WREN = LOAD_MD1 | D0_MD1_WRITE;
`ifndef VERILATOR
logic [31:0] MD1_DOUT;
`endif
data_ram	data_ram_md1 (
	.clock ( CLOCK ),
	
	.address ( MD1_ADDR ),
	.data ( MD1_DI ),
	.wren ( MD1_WREN ),
	
	.q ( MD1_DOUT )
);

logic D0_MD2_WRITE = D0_WRITE && D0_ADDR[7:6]==2'b10;
logic [5:0] MD2_ADDR = (D0_MD2_WRITE) ? D0_ADDR[5:0] : CT2;
logic [31:0] MD2_DI = (D0_MD2_WRITE) ? D0_BUS_IN : D1_BUS;
assign MD2_WREN = LOAD_MD2 | D0_MD2_WRITE;
`ifndef VERILATOR
logic [31:0] MD2_DOUT;
`endif
data_ram	data_ram_md2 (
	.clock ( CLOCK ),
	
	.address ( MD2_ADDR ),
	.data ( MD2_DI ),
	.wren ( MD2_WREN ),
	
	.q ( MD2_DOUT )
);

logic D0_MD3_WRITE = D0_WRITE && D0_ADDR[7:6]==2'b11;
logic [5:0] MD3_ADDR = (D0_MD3_WRITE) ? D0_ADDR[5:0] : CT3;
logic [31:0] MD3_DI = (D0_MD3_WRITE) ? D0_BUS_IN : D1_BUS;
assign MD3_WREN = LOAD_MD3 | D0_MD3_WRITE;
`ifndef VERILATOR
logic [31:0] MD3_DOUT;
`endif
data_ram	data_ram_md3 (
	.clock ( CLOCK ),
	
	.address ( MD3_ADDR ),
	.data ( MD3_DI ),
	.wren ( MD3_WREN ),
	
	.q ( MD3_DOUT )
);


instruction_decoder instruction_decoder_inst
(
	.FETCH(FETCH) ,			// input [31:0] FETCH
	.LOAD_CT0(LOAD_CT0) ,	// output  LOAD_CT0
	.LOAD_CT1(LOAD_CT1) ,	// output  LOAD_CT1
	.LOAD_CT2(LOAD_CT2) ,	// output  LOAD_CT2
	.LOAD_CT3(LOAD_CT3) ,	// output  LOAD_CT3
	.INC_CT0(INC_CT0) ,		// output  INC_CT0
	.INC_CT1(INC_CT1) ,		// output  INC_CT1
	.INC_CT2(INC_CT2) ,		// output  INC_CT2
	.INC_CT3(INC_CT3) ,		// output  INC_CT3
	.MD0_TO_X(MD0_TO_X) ,	// output  MD0_TO_X
	.MD1_TO_X(MD1_TO_X) ,	// output  MD1_TO_X
	.MD2_TO_X(MD2_TO_X) ,	// output  MD2_TO_X
	.MD3_TO_X(MD3_TO_X) ,	// output  MD3_TO_X
	.MD0_TO_Y(MD0_TO_Y) ,	// output  MD0_TO_Y
	.MD1_TO_Y(MD1_TO_Y) ,	// output  MD1_TO_Y
	.MD2_TO_Y(MD2_TO_Y) ,	// output  MD2_TO_Y
	.MD3_TO_Y(MD3_TO_Y) ,	// output  MD3_TO_Y
	.MD0_TO_D1(MD0_TO_D1) ,	// output  MD0_TO_D1
	.MD1_TO_D1(MD1_TO_D1) ,	// output  MD1_TO_D1
	.MD2_TO_D1(MD2_TO_D1) ,	// output  MD2_TO_D1
	.MD3_TO_D1(MD3_TO_D1) ,	// output  MD3_TO_D1
	.D1_TO_MD0(D1_TO_MD0) ,	// output  D1_TO_MD0
	.D1_TO_MD1(D1_TO_MD1) ,	// output  D1_TO_MD1
	.D1_TO_MD2(D1_TO_MD2) ,	// output  D1_TO_MD2
	.D1_TO_MD3(D1_TO_MD3) ,	// output  D1_TO_MD3
	.ACH_TO_D1(ACH_TO_D1) ,	// output  ACH_TO_D1
	.ACL_TO_D1(ACL_TO_D1) ,	// output  ACL_TO_D1
	.LOAD_MD0(LOAD_MD0) ,	// output  LOAD_MD0
	.LOAD_MD1(LOAD_MD1) ,	// output  LOAD_MD1
	.LOAD_MD2(LOAD_MD2) ,	// output  LOAD_MD2
	.LOAD_MD3(LOAD_MD3) ,	// output  LOAD_MD3
	.X_TO_RX(X_TO_RX) ,		// output  X_TO_RX
	.D1_TO_RX(D1_TO_RX) ,	// output  D1_TO_RX
	.LOAD_RX(LOAD_RX) ,		// output  LOAD_RX
	.LOAD_RY(LOAD_RY) ,		// output  LOAD_RY
	.PC_TO_TOP(PC_TO_TOP) ,	// output  PC_TO_TOP
	.D1_TO_TOP(D1_TO_TOP) ,	// output  D1_TO_TOP
	.MUL_TO_P(MUL_TO_P) ,	// output  MUL_TO_P
	.P_TO_PL(P_TO_PL) ,		// output  P_TO_PL
	.X_TO_PL(X_TO_PL) ,		// output  X_TO_PL
	.D1_TO_PL(D1_TO_PL) ,	// output  D1_TO_PL
	.LOAD_PL(LOAD_PL) ,		// output  LOAD_PL
	.LOAD_PH(LOAD_PH) ,		// output  LOAD_PH
	.ALU_TO_A(ALU_TO_A) ,	// output  ALU_TO_A
	.Y_TO_ACL(Y_TO_ACL) ,	// output  Y_TO_ACL
	.LOAD_ACH(LOAD_ACH) ,	// output  LOAD_ACH
	.LOAD_ACL(LOAD_ACL) ,	// output  LOAD_ACL
	.IMM_TO_D1(IMM_TO_D1) ,	// output  IMM_TO_D1
	.IMM_TO_LOP(IMM_TO_LOP) ,	// output  IMM_TO_LOP
	.D1_TO_LOP(D1_TO_LOP) ,	// output  D1_TO_LOP
	.PC_TO_D0(PC_TO_D0) ,	// output  PC_TO_D0
	.LOAD_RA(LOAD_RA) ,		// output  LOAD_RA
	.RA_TO_RAMS(RA_TO_RAMS) ,	// output  RA_TO_RAMS
	.SHIFT_L16_TO_D1(SHIFT_L16_TO_D1) ,	// output  SHIFT_L16_TO_D1
	.CLR_A(CLR_A) ,			// output  CLR_A
	.LOAD_RA0(LOAD_RA0) ,	// output  LOAD_RA0
	.LOAD_WA0(LOAD_WA0) ,	// output  LOAD_WA0
	.LOAD_LOP(LOAD_LOP) ,	// output  LOAD_LOP
	.LOAD_TOP(LOAD_TOP) ,	// output  LOAD_TOP
	.LOAD_PROG_RAM(LOAD_PROG_RAM) 	// output  LOAD_PROG_RAM
);


endmodule


// Early test of an ALU for the Sega Saturn SCU chip.
//
// ElectronAsh. 2018.
//
module alu (
	input [47:0] A_BUS,	// ACH(16),ACL(32).
	input [47:0] B_BUS,	// PH(16), PL(32).
	
	input [3:0] OP,		// OPERATION
	
	output [47:0] RESULT,// Duh.
	
	output S_FLAG,
	output Z_FLAG,
	output C_FLAG,
	output V_FLAG
);


logic [49:0] INT_RES;	// Two extra MSB bits. Bit [49] for checking for Overflow, and bit [48] for the Carry flag.
assign RESULT = INT_RES[47:0];

always_comb begin
	case (OP)
	4'h0: /*INT_RES <= 49'h0000000000000*/;	// NOP. Probably no need to clear the result?
	4'h1: begin
		INT_RES <= A_BUS[31:0] & B_BUS[31:0];	// Bitwise AND (ACL + PL).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= 1'b0;
	end
	4'h2: begin
		INT_RES <= A_BUS[31:0] | B_BUS[31:0];	// Bitwise OR (ACL + PL).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= 1'b0;
	end
	4'h3: begin
		INT_RES <= A_BUS[31:0] ^ B_BUS[31:0];	// Bitwise XOR (ACL + PL).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= 1'b0;
	end
	4'h4: begin
		INT_RES <= A_BUS[31:0] + B_BUS[31:0];	// ADD (ACL + PL).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= INT_RES[48];
		V_FLAG <= INT_RES[49];
	end
	4'h5: begin
		INT_RES <= A_BUS[31:0] - B_BUS[31:0];	// SUB (ACL - PL).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= INT_RES[48];
		V_FLAG <= INT_RES[49];	// Not sure how to properly check for Underflow?
	end
	4'h6: begin
		INT_RES <= A_BUS + B_BUS;					// AD2 (ACH:ACL + PH:PL).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= INT_RES[48];
		V_FLAG <= INT_RES[49];
	end
	4'h7:;												// Not used?
	4'h8: begin
		INT_RES <= {A_BUS[31], A_BUS[31:1]};	// SR (Shift Right). MSB bit does not change, and the rest of the bits shift right!
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= A_BUS[0];
	end
	4'h9: begin
		INT_RES <= {A_BUS[0], A_BUS[31:1]};		// RR (Rotate Right).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= A_BUS[0];
	end
	4'hA: begin
		INT_RES <= {A_BUS[30:0], 1'b0};			// SL (Shift Left).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= A_BUS[31];
	end
	4'hB: begin
		INT_RES <= {A_BUS[30:0], A_BUS[31]};	// RL (Rotate Left).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= A_BUS[31];
	end
	4'hC:;												// Not used?
	4'hD:;												// Not used?
	4'hE:;												// Not used?
	4'hF: begin
		INT_RES <= {A_BUS[31:0], 8'h00};			// RL8 (Rotate Left 8 bits).
		Z_FLAG <= INT_RES==0;
		S_FLAG <= INT_RES[47];
		C_FLAG <= A_BUS[31];
	end
	endcase
end


endmodule


module instruction_decoder (
	input logic [31:0] FETCH,
	
	output logic LOAD_CT0,
	output logic LOAD_CT1,
	output logic LOAD_CT2,
	output logic LOAD_CT3,

	output logic INC_CT0,
	output logic INC_CT1,
	output logic INC_CT2,
	output logic INC_CT3,
	
	output logic MD0_TO_X,
	output logic MD1_TO_X,
	output logic MD2_TO_X,
	output logic MD3_TO_X,
	
	output logic MD0_TO_Y,
	output logic MD1_TO_Y,
	output logic MD2_TO_Y,
	output logic MD3_TO_Y,

	output logic MD0_TO_D1,
	output logic MD1_TO_D1,
	output logic MD2_TO_D1,
	output logic MD3_TO_D1,
	
	output logic D1_TO_MD0,
	output logic D1_TO_MD1,
	output logic D1_TO_MD2,
	output logic D1_TO_MD3,
	
	output logic ACH_TO_D1,
	output logic ACL_TO_D1,
	
	output logic LOAD_MD0,
	output logic LOAD_MD1,
	output logic LOAD_MD2,
	output logic LOAD_MD3,
	
	output logic X_TO_RX,
	output logic D1_TO_RX,
	
	output logic LOAD_RX,
	output logic LOAD_RY,
	
	output logic PC_TO_TOP,
	output logic D1_TO_TOP,
	
	output logic MUL_TO_P,
	output logic P_TO_PL,
	output logic X_TO_PL,
	output logic D1_TO_PL,
	
	output logic LOAD_PL,
	output logic LOAD_PH,
	
	output logic ALU_TO_A,
	output logic Y_TO_ACL,
	
	output logic LOAD_ACH,
	output logic LOAD_ACL,

	output logic IMM_TO_D1,	// I think IMM to "D0" is a typo on the block diagram. ElectronAsh.
	
	output logic IMM_TO_LOP,
	output logic D1_TO_LOP,
	
	output logic PC_TO_D0,

	output logic LOAD_RA,
	output logic RA_TO_RAMS,
	
	output logic SHIFT_L16_TO_D1,
	
	output logic CLR_A,
	
	output logic LOAD_RA0,
	output logic LOAD_WA0,
	
	output logic LOAD_LOP,
	output logic LOAD_TOP,
	
	output logic LOAD_PROG_RAM
);

//
// 31 30 | 29 28 27 26 | 25 24 23 22 21 20 | 19 18 17 16 15 14 | 13 12 11 10 9  8  7  6  5  4  3  2  1  0 
//  0  0   ALU Control     X-Bus Control       Y-Bus Control               D1-Bus Control
//


always_comb begin

	// Defaults...
	LOAD_CT0 <= 1'b0;
	LOAD_CT1 <= 1'b0;
	LOAD_CT2 <= 1'b0;
	LOAD_CT3 <= 1'b0;

	INC_CT0 <= 1'b0;
	INC_CT1 <= 1'b0;
	INC_CT2 <= 1'b0;
	INC_CT3 <= 1'b0;
	
	MD0_TO_X <= 1'b0;
	MD1_TO_X <= 1'b0;
	MD2_TO_X <= 1'b0;
	MD3_TO_X <= 1'b0;
	
	MD0_TO_Y <= 1'b0;
	MD1_TO_Y <= 1'b0;
	MD2_TO_Y <= 1'b0;
	MD3_TO_Y <= 1'b0;
	
	MD0_TO_D1 <= 1'b0;
	MD1_TO_D1 <= 1'b0;
	MD2_TO_D1 <= 1'b0;
	MD3_TO_D1 <= 1'b0;
	
	D1_TO_MD0 <= 1'b0;
	D1_TO_MD1 <= 1'b0;
	D1_TO_MD2 <= 1'b0;
	D1_TO_MD3 <= 1'b0;
	
	ACH_TO_D1 <= 1'b0;
	ACL_TO_D1 <= 1'b0;
	
	LOAD_MD0 <= 1'b0;
	LOAD_MD1 <= 1'b0;
	LOAD_MD2 <= 1'b0;
	LOAD_MD3 <= 1'b0;
	
	X_TO_RX <= 1'b0;
	D1_TO_RX <= 1'b0;
	LOAD_RX <= 1'b0;
	LOAD_RY <= 1'b0;
	
	PC_TO_TOP <= 1'b0;
	D1_TO_TOP <= 1'b0;
	
	MUL_TO_P <= 1'b0;
	P_TO_PL <= 1'b0;
	X_TO_PL <= 1'b0;
	D1_TO_PL <= 1'b0;
	LOAD_PL <= 1'b0;
	LOAD_PH <= 1'b0;
	
	ALU_TO_A <= 1'b0;
	Y_TO_ACL <= 1'b0;

	LOAD_ACH <= 1'b0;
	LOAD_ACL <= 1'b0;

	IMM_TO_D1 <= 1'b0;	// I think IMM to "D0" is a typo on the block diagram. ElectronAsh.
	
	IMM_TO_LOP <= 1'b0;
	D1_TO_LOP <= 1'b0;
	
	PC_TO_D0 <= 1'b0;

	LOAD_RA <= 1'b0;
	RA_TO_RAMS <= 1'b0;
	
	SHIFT_L16_TO_D1 <= 1'b0;
	
	CLR_A <= 1'b0;
	
	LOAD_RA0 <= 1'b0;
	LOAD_WA0 <= 1'b0;

	LOAD_LOP <= 1'b0;
	LOAD_TOP <= 1'b0;
	
	LOAD_PROG_RAM <= 1'b0;

	
	// Handle Operation Commands (non-DMA)...
	if (FETCH[31:30]==2'b00) begin
		// (no need to directly control the ALU, as that's controlled directly by the instruction bits.)
		
		// Handle X-Bus control.
		case (FETCH[25:23]) 
		3'b000:;	// X-Bus NOP.
		
		// Handle MoV [s],X
		3'b100: begin
			case (FETCH[21:20])
			2'b00: begin
				MD0_TO_X <= 1'b1;
				X_TO_RX <= 1'b1;
				LOAD_RX <= 1'b1;
				if (FETCH[22]) INC_CT0 <= 1'b1;
			end
			2'b01: begin
				MD1_TO_X <= 1'b1;
				X_TO_RX <= 1'b1;
				LOAD_RX <= 1'b1;
				if (FETCH[22]) INC_CT1 <= 1'b1;
			end
			2'b10: begin
				MD2_TO_X <= 1'b1;
				X_TO_RX <= 1'b1;
				LOAD_RX <= 1'b1;
				if (FETCH[22]) INC_CT2 <= 1'b1;
			end
			2'b11: begin
				MD3_TO_X <= 1'b1;
				X_TO_RX <= 1'b1;
				LOAD_RX <= 1'b1;
				if (FETCH[22]) INC_CT3 <= 1'b1;
			end
			endcase
		end
		
		// Handle MOV MUL,P
		3'b010: begin
			MUL_TO_P <= 1'b1;
			LOAD_PH <= 1'b1;
			LOAD_PL <= 1'b1;
		end
		
		// Handle MOV [s],P
		3'b011: begin
			case (FETCH[21:20])
			2'b00: begin
				MD0_TO_X <= 1'b1;
				X_TO_PL <= 1'b1;
				LOAD_PL <= 1'b1;
				if (FETCH[22]) INC_CT0 <= 1'b1;
			end
			2'b01: begin
				MD1_TO_X <= 1'b1;
				X_TO_PL <= 1'b1;
				LOAD_PL <= 1'b1;
				if (FETCH[22]) INC_CT0 <= 1'b1;
			end
			2'b10: begin
				MD2_TO_X <= 1'b1;
				X_TO_PL <= 1'b1;
				LOAD_PL <= 1'b1;
				if (FETCH[22]) INC_CT0 <= 1'b1;
			end
			2'b11: begin
				MD3_TO_X <= 1'b1;
				X_TO_PL <= 1'b1;
				LOAD_PL <= 1'b1;
				if (FETCH[22]) INC_CT0 <= 1'b1;
			end
			endcase
		end		
		endcase	// case (FETCH[25:23])
		
		
		// Handle Y-Bus control.
		case (FETCH[19:17]) 
		3'b000:;	// Y-Bus NOP.
		
		// Handle MoV [s],Y
		3'b100: begin
			case (FETCH[15:14])
			2'b00: begin
				MD0_TO_Y <= 1'b1;
				LOAD_RY <= 1'b1;
				if (FETCH[16]) INC_CT0 <= 1'b1;
			end
			2'b01: begin
				MD1_TO_Y <= 1'b1;
				LOAD_RY <= 1'b1;
				if (FETCH[16]) INC_CT1 <= 1'b1;
			end
			2'b10: begin
				MD2_TO_Y <= 1'b1;
				LOAD_RY <= 1'b1;
				if (FETCH[16]) INC_CT2 <= 1'b1;
			end
			2'b11: begin
				MD3_TO_Y <= 1'b1;
				LOAD_RY <= 1'b1;
				if (FETCH[16]) INC_CT3 <= 1'b1;
			end
			endcase
		end
			
		// Handle CLR A.
		3'b001: begin
			CLR_A <= 1'b1;
		end
		
		// Handle MOV ALU,A
		3'b010: begin
			ALU_TO_A <= 1'b1;
			LOAD_ACH <= 1'b1;
			LOAD_ACL <= 1'b1;
		end
		
		// Handle MOV [s],A
		3'b011: begin
			case (FETCH[15:4])
			2'b00: begin
				MD0_TO_Y <= 1'b1;
				Y_TO_ACL <= 1'b1;
				LOAD_ACL <= 1'b1;
				if (FETCH[16]) INC_CT0 <= 1'b1;
			end
			2'b01: begin
				MD1_TO_Y <= 1'b1;
				Y_TO_ACL <= 1'b1;
				LOAD_ACL <= 1'b1;
				if (FETCH[16]) INC_CT1 <= 1'b1;
			end
			2'b10: begin
				MD2_TO_Y <= 1'b1;
				Y_TO_ACL <= 1'b1;
				LOAD_ACL <= 1'b1;
				if (FETCH[16]) INC_CT2 <= 1'b1;
			end
			2'b11: begin
				MD3_TO_Y <= 1'b1;
				Y_TO_ACL <= 1'b1;
				LOAD_ACL <= 1'b1;
				if (FETCH[16]) INC_CT3 <= 1'b1;
			end
			endcase
		end
		endcase	// case (FETCH[19:17])
		
		
		// Handle D1-Bus control.
		case (FETCH[13:12]) 
		2'b00:;	// D1-Bus NOP.
		
		// Handle MOV Simm,[d]
		2'b01: begin		
			case (FETCH[11:8])
			4'b0000: begin				// Imm to DATA RAM0, CT0++
				IMM_TO_D1 <= 1'b1;
				D1_TO_MD0 <= 1'b1;
				LOAD_MD0 <= 1'b1;
				INC_CT0 <= 1'b1;
			end
			4'b0001: begin				// Imm to DATA RAM1, CT1++
				IMM_TO_D1 <= 1'b1;
				D1_TO_MD1 <= 1'b1;
				LOAD_MD1 <= 1'b1;
				INC_CT1 <= 1'b1;
			end
			4'b0010: begin				// Imm to DATA RAM2, CT2++
				IMM_TO_D1 <= 1'b1;
				D1_TO_MD2 <= 1'b1;
				LOAD_MD2 <= 1'b1;
				INC_CT2 <= 1'b1;
			end
			4'b0011: begin				// Imm to DATA RAM3, CT3++
				IMM_TO_D1 <= 1'b1;
				D1_TO_MD3 <= 1'b1;
				LOAD_MD3 <= 1'b1;
				INC_CT3 <= 1'b1;
			end
			4'b0100: begin				// Imm to RX.
				IMM_TO_D1 <= 1'b1;
				D1_TO_RX <= 1'b1;
				LOAD_RX <= 1'b1;			
			end
			4'b0101: begin				// Imm to PL.
				IMM_TO_D1 <= 1'b1;
				D1_TO_PL <= 1'b1;
				LOAD_PL <= 1'b1;			
			end
			4'b0110: begin				// Imm to RA0.
				IMM_TO_D1 <= 1'b1;
				LOAD_RA0 <= 1'b1;
			end
			4'b0111: begin				// Imm to WA0.
				IMM_TO_D1 <= 1'b1;
				LOAD_WA0 <= 1'b1;
			end
			4'b1000:;					// Unused.
			4'b1001:;					// Unused.
			4'b1010: begin				// Imm to LOP.
				IMM_TO_D1 <= 1'b1;
				LOAD_LOP <= 1'b1;
			end
			4'b1011: begin				// Imm to TOP.
				IMM_TO_D1 <= 1'b1;
				LOAD_TOP <= 1'b1;
			end
			4'b1100: begin				// Imm to CT0.
				IMM_TO_D1 <= 1'b1;
				LOAD_CT0 <= 1'b1;
			end
			4'b1101: begin				// Imm to CT1.
				IMM_TO_D1 <= 1'b1;
				LOAD_CT1 <= 1'b1;
			end
			4'b1110: begin				// Imm to CT2.
				IMM_TO_D1 <= 1'b1;
				LOAD_CT2 <= 1'b1;
			end
			4'b1111: begin				// Imm to CT3.
				IMM_TO_D1 <= 1'b1;
				LOAD_CT3 <= 1'b1;
			end
			endcase
		end
		
		// Handle MOV [s],[d]
		2'b11: begin
			// DESTINATION.
			case (FETCH[11:8])
			4'b0000: begin				// Source to DATA RAM0, CT0++
				D1_TO_MD0 <= 1'b1;
				LOAD_MD0 <= 1'b1;
				INC_CT0 <= 1'b1;
			end
			4'b0001: begin				// Source to DATA RAM1, CT1++
				D1_TO_MD1 <= 1'b1;
				LOAD_MD1 <= 1'b1;
				INC_CT1 <= 1'b1;
			end
			4'b0010: begin				// Source to DATA RAM2, CT2++
				D1_TO_MD2 <= 1'b1;
				LOAD_MD2 <= 1'b1;
				INC_CT2 <= 1'b1;
			end
			4'b0011: begin				// Source to DATA RAM3, CT3++
				D1_TO_MD3 <= 1'b1;
				LOAD_MD3 <= 1'b1;
				INC_CT3 <= 1'b1;
			end
			4'b0100: begin				// Source to RX.
				D1_TO_RX <= 1'b1;
				LOAD_RX <= 1'b1;			
			end
			4'b0101: begin				// Source to PL.
				D1_TO_PL <= 1'b1;
				LOAD_PL <= 1'b1;			
			end
			4'b0110: begin				// Source to RA0.
				LOAD_RA0 <= 1'b1;
			end
			4'b0111: begin				// Source to WA0.
				LOAD_WA0 <= 1'b1;
			end
			4'b1000:;					// Unused.
			4'b1001:;					// Unused.
			4'b1010: begin				// Source to LOP.
				LOAD_LOP <= 1'b1;
			end
			4'b1011: begin				// Source to TOP.
				LOAD_TOP <= 1'b1;
			end
			4'b1100: begin				// Source to CT0.
				LOAD_CT0 <= 1'b1;
			end
			4'b1101: begin				// Source to CT1.
				LOAD_CT1 <= 1'b1;
			end
			4'b1110: begin				// Source to CT2.
				LOAD_CT2 <= 1'b1;
			end
			4'b1111: begin				// Source to CT3.
				LOAD_CT3 <= 1'b1;
			end
			endcase

			
			// SOURCE.
			case (FETCH[3:0])
			4'b0000: begin				// Source is MD0.
				MD0_TO_D1 <= 1'b1;
			end
			4'b0001: begin				// Source is MD1.
				MD1_TO_D1 <= 1'b1;
			end
			4'b0010: begin				// Source is MD2.
				MD2_TO_D1 <= 1'b1;
			end
			4'b0011: begin				// Source is MD3.
				MD3_TO_D1 <= 1'b1;
			end
			4'b0100: begin				// Source is MD0. CT0++.
				MD0_TO_D1 <= 1'b1;
				INC_CT0 <= 1'b1;
			end
			4'b0101: begin				// Source is MD1. CT1++.
				MD1_TO_D1 <= 1'b1;
				INC_CT1 <= 1'b1;
			end
			4'b0110: begin				// Source is MD2. CT2++.
				MD2_TO_D1 <= 1'b1;
				INC_CT2 <= 1'b1;
			end
			4'b0111: begin				// Source is MD3. CT3++.
				MD3_TO_D1 <= 1'b1;
				INC_CT3 <= 1'b1;
			end
			4'b1000: ;				// No field.
			4'b1001: begin
				ACL_TO_D1 <= 1'b1;	// ALU Low.
			end
			4'b1010: begin
				ACH_TO_D1 <= 1'b1;	// ALU High.
			end
			endcase
		end
	endcase
	end
	
end

endmodule

`ifdef VERILATOR
module data_ram(
	input logic clock,
	input logic [5:0] address,
	input logic [31:0] data,
	input logic wren,
	output logic [31:0] q
);

logic [31:0] RAM [0:63];
always_ff @(posedge clock) if (wren) RAM[address] <= data;
assign q = RAM[address];

endmodule
`endif
