# An attempt at implementing the Sega Saturn DSP logic in SystemVerilog.

This was mainly inspired by GameHut's video on coding for the DSP...

https://www.youtube.com/watch?v=n8plen8cLro&lc=z23jtffgatasdffsfacdp43155qktcyhu2ush3inz1tw03c010c.1544639915284476

I've added more printf stuff to the Verilator C code (sim_main.cpp) for debugging the logic.

None of the control signals from the instruction decoder are hooked up to the registers and busses yet.

The status flags probably aren't correct yet either, and things like the TOP and LOP registers have yet to be implemented.

Installing Verilator on most Linux distributions with apt-get should be as simple as running...

sudo apt-get install verilator

To run the sim for the DSP, just run the ./Verilate.sh script.

It should cd into the "out" folder, regardless of whether Verilator runs successfully or not, so watch out for that.

If Verilator was successful, you should then be able to cd into the "out" folder, then run...

make -f Vsaturn_dsp.mk

Then run the executable...

./Vsaturn_dsp


The MAME debugger is a superb way to help debug the logic.

It allows you to dump the raw DSP commands to a file, which you can then load directly into the Verilator sim.

And then once the DSP core gets further along, MAME can obviously be used to single-step through the code, and compare the register values with the sim.
