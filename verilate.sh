#!/bin/sh

verilator \
    -Mdir out \
    -Wno-lint \
    -Wno-COMBDLY \
    -Wno-INITIALDLY \
    -Wno-UNOPTFLAT \
    --cc saturn_dsp.sv \
    --top-module saturn_dsp \
    --exe sim_main.cpp vga_out.cpp EasyBMP.cpp

exit 0
