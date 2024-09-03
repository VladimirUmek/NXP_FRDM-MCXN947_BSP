Overview
========

The qdc_basic example shows how to quickly start using QDC driver.

In this example, user needs to connect a real encoder to the board. Actually, only PHASE A and PHASE B are enough for the basic application. When running the project, user can turn the encoder so that QDC module can monitor the position change. Then, the internal counter would also count for the position. User can also type keys into terminal, and the current position values recorded by QDC would display. 

The QDC hardware is created with a special synchronize mechanism. There are actually 4 counters (the 32-bit position counter is combined with the two 16-bit counter registers) for position with responding hold registers. When any of the counter registers is read, the contents of each counter register is written to the corresponding hold register. Taking a snapshot of the counters' values provides a consistent view of a system position and a velocity to be attained.


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
- FRDM-MCXN947 board
- Personal Computer
- An encoder with PHASE A/B signals.

Board settings
==============
1. For pin connection between board and encoder,
      J2.15(P1_0)  -> kINPUTMUX_TrigIn1ToQdc0Phasea -> QDC_PHA
      J3.3 (P1_22) -> kINPUTMUX_TrigIn3ToQdc0Phaseb -> QDC_PHB
      J2.17(P1_1)  -> kINPUTMUX_TrigIn0ToQdc0Index  -> QDC_INDEX

Prepare the Demo
================
1.  Connect a USB cable between the host PC and the MCU-Link USB port on the target board.
2.  Connect the wires between encoder and the MCU board. See to the code for pin mux setting in function "BOARD_InitPins()".
3.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
4.  Download the program to the target board.
5.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
Turn the encoder and type in any key into terminal.
When the demo runs successfully, the log would be seen on the OpenSDA terminal like:

QDC Basic Example.
Press any key to get the encoder values ...

Current position value: 0
Position differential value: 0
Position revolution value: 0

Current position value: 10
Position differential value: 10
Position revolution value: 0

...

