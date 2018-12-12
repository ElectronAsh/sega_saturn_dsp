// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vsaturn_dsp__Syms_H_
#define _Vsaturn_dsp__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vsaturn_dsp.h"

// SYMS CLASS
class Vsaturn_dsp__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vsaturn_dsp*                   TOPp;
    
    // CREATORS
    Vsaturn_dsp__Syms(Vsaturn_dsp* topp, const char* namep);
    ~Vsaturn_dsp__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
