# An attempt to start implementing the Sega Saturn DSP logic in SystemVerilog.

This was mainly inspired by GameHut's video on coding for the DSP...

https://www.youtube.com/watch?v=n8plen8cLro&lc=z23jtffgatasdffsfacdp43155qktcyhu2ush3inz1tw03c010c.1544639915284476

I've added more printf stuff to the Verilator C code (sim_main.cpp) for debugging the logic.

None of the control signals from the instruction decoder are hooked up to the registers and busses yet.

The status flags probably aren't correct yet either, and things like the TOP and LOP registers have yet to be implemented.

The MAME debugger is a very good

sudo apt-get install verilator

Then run the ./Verilate.sh script.

It should cd into the "out" folder, regardless of whether Verilator runs successfully or not, so watch out for that.

If Verilator and the make command were successful, you should be able to simply run the resulting executable...

./Vsaturn_dsp
