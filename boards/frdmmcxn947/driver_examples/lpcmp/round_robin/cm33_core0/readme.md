Overview
========
The LPCMP round robin example is a simple demonstration program that uses the LPCMP driver to
help users get started quickly. In this example, users need to specify which port and channel
to fix, and which channels to select as checker channels. Before doing the comparison, it is
necessary to preset the comparison result of each checker channel with the fixed channel. 
If any results of the comparator are different from the preset value, an interrupt will be 
triggered, and the information of the triggered channel will be printed on the terminal after
changing the input voltage of checker channels.

SDK version
===========
- Version: 2.16.000

Toolchain supported
===================
- IAR embedded Workbench  9.60.1
- Keil MDK  5.39.0
- GCC ARM Embedded  13.2.1

Hardware requirements
=====================
- Type-C USB cable
- FRDM-MCXN947 Board
- Personal Computer

Board settings
==============
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Pin Name    Board Location     checker channel number       pre-set value            trigger        
P1_0            J2-17                channel 0                    0              input < DAC output
P4_2            J1-4                 channel 4                    1              input > DAC output
P4_3            J1-2                 channel 5                    0              input < DAC output
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


This example uses LPCMP0 instance, the fixed port is plusMuxPort, the fixed channel is
channel 7(Internal DAC module), and the checker channels are channel 0(CMP0_IN0, P1_0, J2-17),
channel 4(CMP0_IN1, P4_2, J1-4) and channel 5(CMP0_IN2, P4_3, J1-2), in miusMuxPort.
The LPCMP's internal DAC module output voltage signal(half of VREFI), the channel's pre-set value
is 0x10U.

Set the input voltage of channel 0, channel 4 and channel 5 to be less than, greater than
and less than the output voltage of the DAC respectively. The comparison results of the 
three channels are different from the pre-set value. So the interrupt occurred and the terminal
will print corresponding channel changed information.

Prepare the Demo
================
1. Connect the type-c and mini USB cable between the PC host and the USB ports on the board.
2. Open a serial terminal on PC for the serial device with these settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3. Download the program to the target board.
4. Either press the reset button on your board or launch the debugger in your IDE to begin running
   the demo.

Running the demo
================
When the demo runs successfully, following information can be seen on the OpenSDA terminal:

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
LPCMP RoundRobin Example.
channel 0 comparison result is different from preset value!
channel 4 comparison result is different from preset value!
channel 5 comparison result is different from preset value!

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~