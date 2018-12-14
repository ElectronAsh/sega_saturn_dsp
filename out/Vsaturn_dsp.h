// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vsaturn_dsp_H_
#define _Vsaturn_dsp_H_

#include "verilated.h"

class Vsaturn_dsp__Syms;

//----------

VL_MODULE(Vsaturn_dsp) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(CLOCK,0,0);
    VL_IN8(RESET_N,0,0);
    VL_IN8(D0_ADDR,7,0);
    VL_IN8(D0_WRITE,0,0);
    VL_IN8(EXEC,0,0);
    VL_OUT8(MD0_WREN,0,0);
    VL_OUT8(MD1_WREN,0,0);
    VL_OUT8(MD2_WREN,0,0);
    VL_OUT8(MD3_WREN,0,0);
    VL_OUT8(LOAD_CT0,0,0);
    VL_OUT8(LOAD_CT1,0,0);
    VL_OUT8(LOAD_CT2,0,0);
    VL_OUT8(LOAD_CT3,0,0);
    VL_OUT8(INC_CT0,0,0);
    VL_OUT8(INC_CT1,0,0);
    VL_OUT8(INC_CT2,0,0);
    VL_OUT8(INC_CT3,0,0);
    VL_OUT8(MD0_TO_X,0,0);
    VL_OUT8(MD1_TO_X,0,0);
    VL_OUT8(MD2_TO_X,0,0);
    VL_OUT8(MD3_TO_X,0,0);
    VL_OUT8(MD0_TO_Y,0,0);
    VL_OUT8(MD1_TO_Y,0,0);
    VL_OUT8(MD2_TO_Y,0,0);
    VL_OUT8(MD3_TO_Y,0,0);
    VL_OUT8(MD0_TO_D1,0,0);
    VL_OUT8(MD1_TO_D1,0,0);
    VL_OUT8(MD2_TO_D1,0,0);
    VL_OUT8(MD3_TO_D1,0,0);
    VL_OUT8(D1_TO_MD0,0,0);
    VL_OUT8(D1_TO_MD1,0,0);
    VL_OUT8(D1_TO_MD2,0,0);
    VL_OUT8(D1_TO_MD3,0,0);
    VL_OUT8(ACH_TO_D1,0,0);
    VL_OUT8(ACL_TO_D1,0,0);
    VL_OUT8(LOAD_MD0,0,0);
    VL_OUT8(LOAD_MD1,0,0);
    VL_OUT8(LOAD_MD2,0,0);
    VL_OUT8(LOAD_MD3,0,0);
    VL_OUT8(X_TO_RX,0,0);
    VL_OUT8(D1_TO_RX,0,0);
    VL_OUT8(LOAD_RX,0,0);
    VL_OUT8(LOAD_RY,0,0);
    VL_OUT8(PC_TO_TOP,0,0);
    VL_OUT8(D1_TO_TOP,0,0);
    VL_OUT8(MUL_TO_P,0,0);
    VL_OUT8(P_TO_PL,0,0);
    VL_OUT8(X_TO_PL,0,0);
    VL_OUT8(D1_TO_PL,0,0);
    VL_OUT8(LOAD_PL,0,0);
    VL_OUT8(LOAD_PH,0,0);
    VL_OUT8(ALU_TO_A,0,0);
    VL_OUT8(Y_TO_ACL,0,0);
    VL_OUT8(LOAD_ACH,0,0);
    VL_OUT8(LOAD_ACL,0,0);
    VL_OUT8(IMM_TO_D1,0,0);
    VL_OUT8(IMM_TO_LOP,0,0);
    VL_OUT8(D1_TO_LOP,0,0);
    VL_OUT8(PC_TO_D0,0,0);
    VL_OUT8(LOAD_RA,0,0);
    VL_OUT8(RA_TO_RAMS,0,0);
    VL_OUT8(SHIFT_L16_TO_D1,0,0);
    VL_OUT8(CLR_A,0,0);
    VL_OUT8(LOAD_RA0,0,0);
    VL_OUT8(LOAD_WA0,0,0);
    VL_OUT8(LOAD_LOP,0,0);
    VL_OUT8(LOAD_TOP,0,0);
    VL_OUT8(LOAD_PROG_RAM,0,0);
    VL_OUT8(CT0,5,0);
    VL_OUT8(CT1,5,0);
    VL_OUT8(CT2,5,0);
    VL_OUT8(CT3,5,0);
    VL_OUT8(INST_ADDR,7,0);
    VL_IN(D0_BUS_IN,31,0);
    VL_OUT(D0_BUS_OUT,31,0);
    VL_OUT(FETCH,31,0);
    VL_OUT(MD0_DOUT,31,0);
    VL_OUT(MD1_DOUT,31,0);
    VL_OUT(MD2_DOUT,31,0);
    VL_OUT(MD3_DOUT,31,0);
    VL_OUT(D1_BUS,31,0);
    VL_OUT(RA0,31,0);
    VL_OUT(WA0,31,0);
    VL_IN(INST_IN,31,0);
    VL_OUT64(P_REG,47,0);
    VL_OUT64(A_REG,47,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(saturn_dsp__DOT__MD0_ADDR,5,0);
    VL_SIG8(saturn_dsp__DOT__MD1_ADDR,5,0);
    VL_SIG8(saturn_dsp__DOT__MD2_ADDR,5,0);
    VL_SIG8(saturn_dsp__DOT__MD3_ADDR,5,0);
    VL_SIG(saturn_dsp__DOT__RX,31,0);
    VL_SIG(saturn_dsp__DOT__RY,31,0);
    VL_SIG64(saturn_dsp__DOT__alu_inst__DOT__INT_RES,49,0);
    VL_SIG(saturn_dsp__DOT__data_ram_md0__DOT__RAM[64],31,0);
    VL_SIG(saturn_dsp__DOT__data_ram_md1__DOT__RAM[64],31,0);
    VL_SIG(saturn_dsp__DOT__data_ram_md2__DOT__RAM[64],31,0);
    VL_SIG(saturn_dsp__DOT__data_ram_md3__DOT__RAM[64],31,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__Vclklast__TOP__CLOCK,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vsaturn_dsp__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vsaturn_dsp);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vsaturn_dsp(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vsaturn_dsp();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vsaturn_dsp__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vsaturn_dsp__Syms* symsp, bool first);
  private:
    static QData _change_request(Vsaturn_dsp__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(Vsaturn_dsp__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _eval(Vsaturn_dsp__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vsaturn_dsp__Syms* __restrict vlSymsp);
    static void _eval_settle(Vsaturn_dsp__Syms* __restrict vlSymsp);
    static void _initial__TOP__3(Vsaturn_dsp__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vsaturn_dsp__Syms* __restrict vlSymsp);
    static void _settle__TOP__1(Vsaturn_dsp__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(Vsaturn_dsp__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
