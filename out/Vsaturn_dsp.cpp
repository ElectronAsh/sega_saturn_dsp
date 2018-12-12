// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsaturn_dsp.h for the primary calling header

#include "Vsaturn_dsp.h"       // For This
#include "Vsaturn_dsp__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vsaturn_dsp) {
    Vsaturn_dsp__Syms* __restrict vlSymsp = __VlSymsp = new Vsaturn_dsp__Syms(this, name());
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vsaturn_dsp::__Vconfigure(Vsaturn_dsp__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vsaturn_dsp::~Vsaturn_dsp() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vsaturn_dsp::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsaturn_dsp::eval\n"); );
    Vsaturn_dsp__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void Vsaturn_dsp::_eval_initial_loop(Vsaturn_dsp__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

void Vsaturn_dsp::_settle__TOP__1(Vsaturn_dsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_settle__TOP__1\n"); );
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_CT1 = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_CT0 = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D0_TO_CT3 = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D0_TO_CT2 = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D0_TO_CT0 = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D0_TO_CT1 = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_CT2 = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_CT3 = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->PC_TO_TOP = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_TOP = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->P_TO_PL = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->IMM_TO_LOP = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_LOP = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->PC_TO_D0 = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_RA = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->RA_TO_RAMS = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->SHIFT_L16_TO_D1 = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->CLR_A = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_PROG_RAM = 0U;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_MD1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_MD1 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_MD1 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_MD0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_MD0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_MD0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->ACL_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ ((((((((0U == (0xfU 
						& vlTOPp->FETCH)) 
					| (1U == (0xfU 
						  & vlTOPp->FETCH))) 
				       | (2U == (0xfU 
						 & vlTOPp->FETCH))) 
				      | (3U == (0xfU 
						& vlTOPp->FETCH))) 
				     | (4U == (0xfU 
					       & vlTOPp->FETCH))) 
				    | (5U == (0xfU 
					      & vlTOPp->FETCH))) 
				   | (6U == (0xfU & vlTOPp->FETCH))) 
				  | (7U == (0xfU & vlTOPp->FETCH)))))) {
			if ((8U != (0xfU & vlTOPp->FETCH))) {
			    if ((9U == (0xfU & vlTOPp->FETCH))) {
				vlTOPp->ACL_TO_D1 = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->ACH_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ ((((((((0U == (0xfU 
						& vlTOPp->FETCH)) 
					| (1U == (0xfU 
						  & vlTOPp->FETCH))) 
				       | (2U == (0xfU 
						 & vlTOPp->FETCH))) 
				      | (3U == (0xfU 
						& vlTOPp->FETCH))) 
				     | (4U == (0xfU 
					       & vlTOPp->FETCH))) 
				    | (5U == (0xfU 
					      & vlTOPp->FETCH))) 
				   | (6U == (0xfU & vlTOPp->FETCH))) 
				  | (7U == (0xfU & vlTOPp->FETCH)))))) {
			if ((8U != (0xfU & vlTOPp->FETCH))) {
			    if ((9U != (0xfU & vlTOPp->FETCH))) {
				if ((0xaU == (0xfU 
					      & vlTOPp->FETCH))) {
				    vlTOPp->ACH_TO_D1 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_MD3 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->D1_TO_MD3 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->D1_TO_MD3 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_MD2 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->D1_TO_MD2 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->D1_TO_MD2 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_MD1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->D1_TO_MD1 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->D1_TO_MD1 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_MD0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->D1_TO_MD0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->D1_TO_MD0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD3_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U == (0xfU 
						& vlTOPp->FETCH))) {
					vlTOPp->MD3_TO_D1 = 1U;
				    } else {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 != 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						if (
						    (6U 
						     != 
						     (0xfU 
						      & vlTOPp->FETCH))) {
						    vlTOPp->MD3_TO_D1 = 1U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD2_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U == (0xfU & vlTOPp->FETCH))) {
				    vlTOPp->MD2_TO_D1 = 1U;
				} else {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 != 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						if (
						    (6U 
						     == 
						     (0xfU 
						      & vlTOPp->FETCH))) {
						    vlTOPp->MD2_TO_D1 = 1U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD1_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U == (0xfU & vlTOPp->FETCH))) {
				vlTOPp->MD1_TO_D1 = 1U;
			    } else {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 == 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						vlTOPp->MD1_TO_D1 = 1U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD0_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U == (0xfU & vlTOPp->FETCH))) {
			    vlTOPp->MD0_TO_D1 = 1U;
			} else {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U == 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    vlTOPp->MD0_TO_D1 = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD3_TO_Y = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((0x8000U & vlTOPp->FETCH)) {
		    if ((0x4000U & vlTOPp->FETCH)) {
			vlTOPp->MD3_TO_Y = 1U;
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U != (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((2U != (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					if ((3U == 
					     (0xfffU 
					      & (vlTOPp->FETCH 
						 >> 4U)))) {
					    vlTOPp->MD3_TO_Y = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD2_TO_Y = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((0x8000U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xeU)))) {
			vlTOPp->MD2_TO_Y = 1U;
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U != (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((2U == (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					vlTOPp->MD2_TO_Y = 1U;
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD1_TO_Y = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xfU)))) {
		    if ((0x4000U & vlTOPp->FETCH)) {
			vlTOPp->MD1_TO_Y = 1U;
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U == (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    vlTOPp->MD1_TO_Y = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD0_TO_Y = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xfU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xeU)))) {
			vlTOPp->MD0_TO_Y = 1U;
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U == (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				vlTOPp->MD0_TO_Y = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD3_TO_X = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((0x200000U & vlTOPp->FETCH)) {
		    if ((0x100000U & vlTOPp->FETCH)) {
			vlTOPp->MD3_TO_X = 1U;
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((0x200000U & vlTOPp->FETCH)) {
			    if ((0x100000U & vlTOPp->FETCH)) {
				vlTOPp->MD3_TO_X = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD2_TO_X = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((0x200000U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0x14U)))) {
			vlTOPp->MD2_TO_X = 1U;
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((0x200000U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 0x14U)))) {
				vlTOPp->MD2_TO_X = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD1_TO_X = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x15U)))) {
		    if ((0x100000U & vlTOPp->FETCH)) {
			vlTOPp->MD1_TO_X = 1U;
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0x15U)))) {
			    if ((0x100000U & vlTOPp->FETCH)) {
				vlTOPp->MD1_TO_X = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD0_TO_X = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x15U)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0x14U)))) {
			vlTOPp->MD0_TO_X = 1U;
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0x15U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 0x14U)))) {
				vlTOPp->MD0_TO_X = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((2U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    vlTOPp->MUL_TO_P = 1U;
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    vlTOPp->MUL_TO_P = 1U;
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_CT0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_CT0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_CT0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_CT1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_CT1 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_CT1 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_CT2 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_CT2 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_CT2 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_CT3 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_CT3 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_CT3 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->INC_CT0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x15U)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0x14U)))) {
			if ((0x400000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT0 = 1U;
			}
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((0x200000U & vlTOPp->FETCH)) {
			    if ((0x100000U & vlTOPp->FETCH)) {
				if ((0x400000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    } else {
				if ((0x400000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    }
			} else {
			    if ((0x100000U & vlTOPp->FETCH)) {
				if ((0x400000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    } else {
				if ((0x400000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xfU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xeU)))) {
			if ((0x10000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT0 = 1U;
			}
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U == (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((0x10000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->INC_CT0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    }
			}
		    }
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U == 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    vlTOPp->INC_CT0 = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->INC_CT1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x15U)))) {
		    if ((0x100000U & vlTOPp->FETCH)) {
			if ((0x400000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT1 = 1U;
			}
		    }
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xfU)))) {
		    if ((0x4000U & vlTOPp->FETCH)) {
			if ((0x10000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT1 = 1U;
			}
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U == (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((0x10000U & vlTOPp->FETCH)) {
					vlTOPp->INC_CT1 = 1U;
				    }
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->INC_CT1 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT1 = 1U;
				}
			    }
			}
		    }
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 == 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						vlTOPp->INC_CT1 = 1U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->INC_CT2 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((0x200000U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0x14U)))) {
			if ((0x400000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT2 = 1U;
			}
		    }
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((0x8000U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xeU)))) {
			if ((0x10000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT2 = 1U;
			}
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U != (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((2U == (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					if ((0x10000U 
					     & vlTOPp->FETCH)) {
					    vlTOPp->INC_CT2 = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->INC_CT2 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->INC_CT2 = 1U;
				}
			    }
			}
		    }
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 != 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						if (
						    (6U 
						     == 
						     (0xfU 
						      & vlTOPp->FETCH))) {
						    vlTOPp->INC_CT2 = 1U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->INC_CT3 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((0x200000U & vlTOPp->FETCH)) {
		    if ((0x100000U & vlTOPp->FETCH)) {
			if ((0x400000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT3 = 1U;
			}
		    }
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((0x8000U & vlTOPp->FETCH)) {
		    if ((0x4000U & vlTOPp->FETCH)) {
			if ((0x10000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT3 = 1U;
			}
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U != (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((2U != (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					if ((3U == 
					     (0xfffU 
					      & (vlTOPp->FETCH 
						 >> 4U)))) {
					    if ((0x10000U 
						 & vlTOPp->FETCH)) {
						vlTOPp->INC_CT3 = 1U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->INC_CT3 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT3 = 1U;
				}
			    }
			}
		    }
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 != 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						if (
						    (6U 
						     != 
						     (0xfU 
						      & vlTOPp->FETCH))) {
						    vlTOPp->INC_CT3 = 1U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_MD2 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_MD2 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_MD2 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_MD3 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_MD3 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_MD3 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->X_TO_RX = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		vlTOPp->X_TO_RX = 1U;
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_RX = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->D1_TO_RX = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->D1_TO_RX = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_RX = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		vlTOPp->LOAD_RX = 1U;
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_RX = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_RX = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_RY = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		vlTOPp->LOAD_RY = 1U;
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->X_TO_PL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			vlTOPp->X_TO_PL = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_PL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->D1_TO_PL = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->D1_TO_PL = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_PL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			vlTOPp->LOAD_PL = 1U;
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_PL = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_PL = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->ALU_TO_ACL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U == (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			vlTOPp->ALU_TO_ACL = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->Y_TO_ACL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U == (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				vlTOPp->Y_TO_ACL = 1U;
			    } else {
				if ((1U == (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    vlTOPp->Y_TO_ACL = 1U;
				} else {
				    if ((2U == (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					vlTOPp->Y_TO_ACL = 1U;
				    } else {
					if ((3U == 
					     (0xfffU 
					      & (vlTOPp->FETCH 
						 >> 4U)))) {
					    vlTOPp->Y_TO_ACL = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_ACH = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U == (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			vlTOPp->LOAD_ACH = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_ACL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U == (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			vlTOPp->LOAD_ACL = 1U;
		    } else {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U == (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				vlTOPp->LOAD_ACL = 1U;
			    } else {
				if ((1U == (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    vlTOPp->LOAD_ACL = 1U;
				} else {
				    if ((2U == (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					vlTOPp->LOAD_ACL = 1U;
				    } else {
					if ((3U == 
					     (0xfffU 
					      & (vlTOPp->FETCH 
						 >> 4U)))) {
					    vlTOPp->LOAD_ACL = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->IMM_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			vlTOPp->IMM_TO_D1 = 1U;
		    } else {
			if ((0x200U & vlTOPp->FETCH)) {
			    vlTOPp->IMM_TO_D1 = 1U;
			}
		    }
		} else {
		    vlTOPp->IMM_TO_D1 = 1U;
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_RA0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_RA0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_RA0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_WA0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_WA0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_WA0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_LOP = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_LOP = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_LOP = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_TOP = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_TOP = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_TOP = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
}

VL_INLINE_OPT void Vsaturn_dsp::_sequent__TOP__2(Vsaturn_dsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_sequent__TOP__2\n"); );
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at saturn_dsp.sv:173
    vlTOPp->INST_ADDR = (0xffU & ((IData)(1U) + (IData)(vlTOPp->INST_ADDR)));
    // ALWAYS at saturn_dsp.sv:173
    vlTOPp->FETCH = vlTOPp->INST_IN;
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_MD1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_MD1 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_MD1 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_MD0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_MD0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_MD0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->ACL_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ ((((((((0U == (0xfU 
						& vlTOPp->FETCH)) 
					| (1U == (0xfU 
						  & vlTOPp->FETCH))) 
				       | (2U == (0xfU 
						 & vlTOPp->FETCH))) 
				      | (3U == (0xfU 
						& vlTOPp->FETCH))) 
				     | (4U == (0xfU 
					       & vlTOPp->FETCH))) 
				    | (5U == (0xfU 
					      & vlTOPp->FETCH))) 
				   | (6U == (0xfU & vlTOPp->FETCH))) 
				  | (7U == (0xfU & vlTOPp->FETCH)))))) {
			if ((8U != (0xfU & vlTOPp->FETCH))) {
			    if ((9U == (0xfU & vlTOPp->FETCH))) {
				vlTOPp->ACL_TO_D1 = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->ACH_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ ((((((((0U == (0xfU 
						& vlTOPp->FETCH)) 
					| (1U == (0xfU 
						  & vlTOPp->FETCH))) 
				       | (2U == (0xfU 
						 & vlTOPp->FETCH))) 
				      | (3U == (0xfU 
						& vlTOPp->FETCH))) 
				     | (4U == (0xfU 
					       & vlTOPp->FETCH))) 
				    | (5U == (0xfU 
					      & vlTOPp->FETCH))) 
				   | (6U == (0xfU & vlTOPp->FETCH))) 
				  | (7U == (0xfU & vlTOPp->FETCH)))))) {
			if ((8U != (0xfU & vlTOPp->FETCH))) {
			    if ((9U != (0xfU & vlTOPp->FETCH))) {
				if ((0xaU == (0xfU 
					      & vlTOPp->FETCH))) {
				    vlTOPp->ACH_TO_D1 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_MD3 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->D1_TO_MD3 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->D1_TO_MD3 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_MD2 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->D1_TO_MD2 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->D1_TO_MD2 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_MD1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->D1_TO_MD1 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->D1_TO_MD1 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_MD0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->D1_TO_MD0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->D1_TO_MD0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD3_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U == (0xfU 
						& vlTOPp->FETCH))) {
					vlTOPp->MD3_TO_D1 = 1U;
				    } else {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 != 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						if (
						    (6U 
						     != 
						     (0xfU 
						      & vlTOPp->FETCH))) {
						    vlTOPp->MD3_TO_D1 = 1U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD2_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U == (0xfU & vlTOPp->FETCH))) {
				    vlTOPp->MD2_TO_D1 = 1U;
				} else {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 != 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						if (
						    (6U 
						     == 
						     (0xfU 
						      & vlTOPp->FETCH))) {
						    vlTOPp->MD2_TO_D1 = 1U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD1_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U == (0xfU & vlTOPp->FETCH))) {
				vlTOPp->MD1_TO_D1 = 1U;
			    } else {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 == 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						vlTOPp->MD1_TO_D1 = 1U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD0_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U == (0xfU & vlTOPp->FETCH))) {
			    vlTOPp->MD0_TO_D1 = 1U;
			} else {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U == 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    vlTOPp->MD0_TO_D1 = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD3_TO_Y = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((0x8000U & vlTOPp->FETCH)) {
		    if ((0x4000U & vlTOPp->FETCH)) {
			vlTOPp->MD3_TO_Y = 1U;
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U != (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((2U != (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					if ((3U == 
					     (0xfffU 
					      & (vlTOPp->FETCH 
						 >> 4U)))) {
					    vlTOPp->MD3_TO_Y = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD2_TO_Y = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((0x8000U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xeU)))) {
			vlTOPp->MD2_TO_Y = 1U;
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U != (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((2U == (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					vlTOPp->MD2_TO_Y = 1U;
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD1_TO_Y = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xfU)))) {
		    if ((0x4000U & vlTOPp->FETCH)) {
			vlTOPp->MD1_TO_Y = 1U;
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U == (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    vlTOPp->MD1_TO_Y = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD0_TO_Y = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xfU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xeU)))) {
			vlTOPp->MD0_TO_Y = 1U;
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U == (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				vlTOPp->MD0_TO_Y = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD3_TO_X = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((0x200000U & vlTOPp->FETCH)) {
		    if ((0x100000U & vlTOPp->FETCH)) {
			vlTOPp->MD3_TO_X = 1U;
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((0x200000U & vlTOPp->FETCH)) {
			    if ((0x100000U & vlTOPp->FETCH)) {
				vlTOPp->MD3_TO_X = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD2_TO_X = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((0x200000U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0x14U)))) {
			vlTOPp->MD2_TO_X = 1U;
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((0x200000U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 0x14U)))) {
				vlTOPp->MD2_TO_X = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD1_TO_X = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x15U)))) {
		    if ((0x100000U & vlTOPp->FETCH)) {
			vlTOPp->MD1_TO_X = 1U;
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0x15U)))) {
			    if ((0x100000U & vlTOPp->FETCH)) {
				vlTOPp->MD1_TO_X = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->MD0_TO_X = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x15U)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0x14U)))) {
			vlTOPp->MD0_TO_X = 1U;
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0x15U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 0x14U)))) {
				vlTOPp->MD0_TO_X = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((2U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    vlTOPp->MUL_TO_P = 1U;
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    vlTOPp->MUL_TO_P = 1U;
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_CT0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_CT0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_CT0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_CT1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_CT1 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_CT1 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_CT2 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_CT2 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_CT2 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_CT3 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_CT3 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_CT3 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->INC_CT0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x15U)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0x14U)))) {
			if ((0x400000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT0 = 1U;
			}
		    }
		}
	    } else {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			if ((0x200000U & vlTOPp->FETCH)) {
			    if ((0x100000U & vlTOPp->FETCH)) {
				if ((0x400000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    } else {
				if ((0x400000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    }
			} else {
			    if ((0x100000U & vlTOPp->FETCH)) {
				if ((0x400000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    } else {
				if ((0x400000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xfU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xeU)))) {
			if ((0x10000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT0 = 1U;
			}
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U == (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((0x10000U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->INC_CT0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->INC_CT0 = 1U;
				}
			    }
			}
		    }
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U == 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    vlTOPp->INC_CT0 = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->INC_CT1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0x15U)))) {
		    if ((0x100000U & vlTOPp->FETCH)) {
			if ((0x400000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT1 = 1U;
			}
		    }
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xfU)))) {
		    if ((0x4000U & vlTOPp->FETCH)) {
			if ((0x10000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT1 = 1U;
			}
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U == (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((0x10000U & vlTOPp->FETCH)) {
					vlTOPp->INC_CT1 = 1U;
				    }
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->INC_CT1 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT1 = 1U;
				}
			    }
			}
		    }
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 == 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						vlTOPp->INC_CT1 = 1U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->INC_CT2 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((0x200000U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0x14U)))) {
			if ((0x400000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT2 = 1U;
			}
		    }
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((0x8000U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xeU)))) {
			if ((0x10000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT2 = 1U;
			}
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U != (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((2U == (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					if ((0x10000U 
					     & vlTOPp->FETCH)) {
					    vlTOPp->INC_CT2 = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->INC_CT2 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->INC_CT2 = 1U;
				}
			    }
			}
		    }
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 != 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						if (
						    (6U 
						     == 
						     (0xfU 
						      & vlTOPp->FETCH))) {
						    vlTOPp->INC_CT2 = 1U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->INC_CT3 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((0x200000U & vlTOPp->FETCH)) {
		    if ((0x100000U & vlTOPp->FETCH)) {
			if ((0x400000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT3 = 1U;
			}
		    }
		}
	    }
	}
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((0x8000U & vlTOPp->FETCH)) {
		    if ((0x4000U & vlTOPp->FETCH)) {
			if ((0x10000U & vlTOPp->FETCH)) {
			    vlTOPp->INC_CT3 = 1U;
			}
		    }
		}
	    } else {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U != (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				if ((1U != (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    if ((2U != (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					if ((3U == 
					     (0xfffU 
					      & (vlTOPp->FETCH 
						 >> 4U)))) {
					    if ((0x10000U 
						 & vlTOPp->FETCH)) {
						vlTOPp->INC_CT3 = 1U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->INC_CT3 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->INC_CT3 = 1U;
				}
			    }
			}
		    }
		    if (((((((((0U == (0xfU & vlTOPp->FETCH)) 
			       | (1U == (0xfU & vlTOPp->FETCH))) 
			      | (2U == (0xfU & vlTOPp->FETCH))) 
			     | (3U == (0xfU & vlTOPp->FETCH))) 
			    | (4U == (0xfU & vlTOPp->FETCH))) 
			   | (5U == (0xfU & vlTOPp->FETCH))) 
			  | (6U == (0xfU & vlTOPp->FETCH))) 
			 | (7U == (0xfU & vlTOPp->FETCH)))) {
			if ((0U != (0xfU & vlTOPp->FETCH))) {
			    if ((1U != (0xfU & vlTOPp->FETCH))) {
				if ((2U != (0xfU & vlTOPp->FETCH))) {
				    if ((3U != (0xfU 
						& vlTOPp->FETCH))) {
					if ((4U != 
					     (0xfU 
					      & vlTOPp->FETCH))) {
					    if ((5U 
						 != 
						 (0xfU 
						  & vlTOPp->FETCH))) {
						if (
						    (6U 
						     != 
						     (0xfU 
						      & vlTOPp->FETCH))) {
						    vlTOPp->INC_CT3 = 1U;
						}
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_MD2 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_MD2 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_MD2 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_MD3 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_MD3 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_MD3 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->X_TO_RX = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		vlTOPp->X_TO_RX = 1U;
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_RX = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->D1_TO_RX = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->D1_TO_RX = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_RX = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x17U)))) {
		vlTOPp->LOAD_RX = 1U;
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_RX = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_RX = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_RY = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U == (7U & (vlTOPp->FETCH >> 0x11U)))) {
		vlTOPp->LOAD_RY = 1U;
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->X_TO_PL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			vlTOPp->X_TO_PL = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->D1_TO_PL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->D1_TO_PL = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->D1_TO_PL = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_PL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		if ((2U != (7U & (vlTOPp->FETCH >> 0x17U)))) {
		    if ((3U == (7U & (vlTOPp->FETCH 
				      >> 0x17U)))) {
			vlTOPp->LOAD_PL = 1U;
		    }
		}
	    }
	}
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 9U)))) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_PL = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 9U)))) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_PL = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->ALU_TO_ACL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U == (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			vlTOPp->ALU_TO_ACL = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->Y_TO_ACL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U != (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U == (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				vlTOPp->Y_TO_ACL = 1U;
			    } else {
				if ((1U == (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    vlTOPp->Y_TO_ACL = 1U;
				} else {
				    if ((2U == (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					vlTOPp->Y_TO_ACL = 1U;
				    } else {
					if ((3U == 
					     (0xfffU 
					      & (vlTOPp->FETCH 
						 >> 4U)))) {
					    vlTOPp->Y_TO_ACL = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_ACH = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U == (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			vlTOPp->LOAD_ACH = 1U;
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_ACL = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
	    if ((4U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		if ((1U != (7U & (vlTOPp->FETCH >> 0x11U)))) {
		    if ((2U == (7U & (vlTOPp->FETCH 
				      >> 0x11U)))) {
			vlTOPp->LOAD_ACL = 1U;
		    } else {
			if ((3U == (7U & (vlTOPp->FETCH 
					  >> 0x11U)))) {
			    if ((0U == (0xfffU & (vlTOPp->FETCH 
						  >> 4U)))) {
				vlTOPp->LOAD_ACL = 1U;
			    } else {
				if ((1U == (0xfffU 
					    & (vlTOPp->FETCH 
					       >> 4U)))) {
				    vlTOPp->LOAD_ACL = 1U;
				} else {
				    if ((2U == (0xfffU 
						& (vlTOPp->FETCH 
						   >> 4U)))) {
					vlTOPp->LOAD_ACL = 1U;
				    } else {
					if ((3U == 
					     (0xfffU 
					      & (vlTOPp->FETCH 
						 >> 4U)))) {
					    vlTOPp->LOAD_ACL = 1U;
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->IMM_TO_D1 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((0x400U & vlTOPp->FETCH)) {
			vlTOPp->IMM_TO_D1 = 1U;
		    } else {
			if ((0x200U & vlTOPp->FETCH)) {
			    vlTOPp->IMM_TO_D1 = 1U;
			}
		    }
		} else {
		    vlTOPp->IMM_TO_D1 = 1U;
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_RA0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_RA0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_RA0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_WA0 = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
		    if ((0x400U & vlTOPp->FETCH)) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_WA0 = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xbU)))) {
			if ((0x400U & vlTOPp->FETCH)) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_WA0 = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_LOP = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((1U & (~ (vlTOPp->FETCH 
					  >> 8U)))) {
				vlTOPp->LOAD_LOP = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((1U & (~ (vlTOPp->FETCH 
					      >> 8U)))) {
				    vlTOPp->LOAD_LOP = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at saturn_dsp.sv:549
    vlTOPp->LOAD_TOP = 0U;
    if ((0U == (3U & (vlTOPp->FETCH >> 0x1eU)))) {
	if ((0U != (3U & (vlTOPp->FETCH >> 0xcU)))) {
	    if ((1U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		if ((0x800U & vlTOPp->FETCH)) {
		    if ((1U & (~ (vlTOPp->FETCH >> 0xaU)))) {
			if ((0x200U & vlTOPp->FETCH)) {
			    if ((0x100U & vlTOPp->FETCH)) {
				vlTOPp->LOAD_TOP = 1U;
			    }
			}
		    }
		}
	    } else {
		if ((3U == (3U & (vlTOPp->FETCH >> 0xcU)))) {
		    if ((0x800U & vlTOPp->FETCH)) {
			if ((1U & (~ (vlTOPp->FETCH 
				      >> 0xaU)))) {
			    if ((0x200U & vlTOPp->FETCH)) {
				if ((0x100U & vlTOPp->FETCH)) {
				    vlTOPp->LOAD_TOP = 1U;
				}
			    }
			}
		    }
		}
	    }
	}
    }
}

void Vsaturn_dsp::_eval(Vsaturn_dsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_eval\n"); );
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->CLOCK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLOCK)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__CLOCK = vlTOPp->CLOCK;
}

void Vsaturn_dsp::_eval_initial(Vsaturn_dsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_eval_initial\n"); );
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__CLOCK = vlTOPp->CLOCK;
}

void Vsaturn_dsp::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::final\n"); );
    // Variables
    Vsaturn_dsp__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsaturn_dsp::_eval_settle(Vsaturn_dsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_eval_settle\n"); );
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vsaturn_dsp::_change_request(Vsaturn_dsp__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_change_request\n"); );
    Vsaturn_dsp* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vsaturn_dsp::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((CLOCK & 0xfeU))) {
	Verilated::overWidthError("CLOCK");}
}
#endif // VL_DEBUG

void Vsaturn_dsp::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsaturn_dsp::_ctor_var_reset\n"); );
    // Body
    CLOCK = VL_RAND_RESET_I(1);
    BUS_DI = VL_RAND_RESET_I(32);
    BUS_DO = VL_RAND_RESET_I(32);
    FETCH = VL_RAND_RESET_I(32);
    D0_TO_CT0 = VL_RAND_RESET_I(1);
    D0_TO_CT1 = VL_RAND_RESET_I(1);
    D0_TO_CT2 = VL_RAND_RESET_I(1);
    D0_TO_CT3 = VL_RAND_RESET_I(1);
    D1_TO_CT0 = VL_RAND_RESET_I(1);
    D1_TO_CT1 = VL_RAND_RESET_I(1);
    D1_TO_CT2 = VL_RAND_RESET_I(1);
    D1_TO_CT3 = VL_RAND_RESET_I(1);
    LOAD_CT0 = VL_RAND_RESET_I(1);
    LOAD_CT1 = VL_RAND_RESET_I(1);
    LOAD_CT2 = VL_RAND_RESET_I(1);
    LOAD_CT3 = VL_RAND_RESET_I(1);
    INC_CT0 = VL_RAND_RESET_I(1);
    INC_CT1 = VL_RAND_RESET_I(1);
    INC_CT2 = VL_RAND_RESET_I(1);
    INC_CT3 = VL_RAND_RESET_I(1);
    MD0_TO_X = VL_RAND_RESET_I(1);
    MD1_TO_X = VL_RAND_RESET_I(1);
    MD2_TO_X = VL_RAND_RESET_I(1);
    MD3_TO_X = VL_RAND_RESET_I(1);
    MD0_TO_Y = VL_RAND_RESET_I(1);
    MD1_TO_Y = VL_RAND_RESET_I(1);
    MD2_TO_Y = VL_RAND_RESET_I(1);
    MD3_TO_Y = VL_RAND_RESET_I(1);
    MD0_TO_D1 = VL_RAND_RESET_I(1);
    MD1_TO_D1 = VL_RAND_RESET_I(1);
    MD2_TO_D1 = VL_RAND_RESET_I(1);
    MD3_TO_D1 = VL_RAND_RESET_I(1);
    D1_TO_MD0 = VL_RAND_RESET_I(1);
    D1_TO_MD1 = VL_RAND_RESET_I(1);
    D1_TO_MD2 = VL_RAND_RESET_I(1);
    D1_TO_MD3 = VL_RAND_RESET_I(1);
    ACH_TO_D1 = VL_RAND_RESET_I(1);
    ACL_TO_D1 = VL_RAND_RESET_I(1);
    LOAD_MD0 = VL_RAND_RESET_I(1);
    LOAD_MD1 = VL_RAND_RESET_I(1);
    LOAD_MD2 = VL_RAND_RESET_I(1);
    LOAD_MD3 = VL_RAND_RESET_I(1);
    X_TO_RX = VL_RAND_RESET_I(1);
    D1_TO_RX = VL_RAND_RESET_I(1);
    LOAD_RX = VL_RAND_RESET_I(1);
    LOAD_RY = VL_RAND_RESET_I(1);
    PC_TO_TOP = VL_RAND_RESET_I(1);
    D1_TO_TOP = VL_RAND_RESET_I(1);
    MUL_TO_P = VL_RAND_RESET_I(1);
    P_TO_PL = VL_RAND_RESET_I(1);
    X_TO_PL = VL_RAND_RESET_I(1);
    D1_TO_PL = VL_RAND_RESET_I(1);
    LOAD_PL = VL_RAND_RESET_I(1);
    ALU_TO_ACL = VL_RAND_RESET_I(1);
    Y_TO_ACL = VL_RAND_RESET_I(1);
    LOAD_ACH = VL_RAND_RESET_I(1);
    LOAD_ACL = VL_RAND_RESET_I(1);
    IMM_TO_D1 = VL_RAND_RESET_I(1);
    IMM_TO_LOP = VL_RAND_RESET_I(1);
    D1_TO_LOP = VL_RAND_RESET_I(1);
    PC_TO_D0 = VL_RAND_RESET_I(1);
    LOAD_RA = VL_RAND_RESET_I(1);
    RA_TO_RAMS = VL_RAND_RESET_I(1);
    SHIFT_L16_TO_D1 = VL_RAND_RESET_I(1);
    CLR_A = VL_RAND_RESET_I(1);
    LOAD_RA0 = VL_RAND_RESET_I(1);
    LOAD_WA0 = VL_RAND_RESET_I(1);
    LOAD_LOP = VL_RAND_RESET_I(1);
    LOAD_TOP = VL_RAND_RESET_I(1);
    LOAD_PROG_RAM = VL_RAND_RESET_I(1);
    INST_ADDR = VL_RAND_RESET_I(8);
    INST_IN = VL_RAND_RESET_I(32);
}
