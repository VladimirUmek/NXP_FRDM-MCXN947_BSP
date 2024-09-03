Overview
========
This example shows how to use flexio mculcd smartdma driver to drive MCU LCD panel.
Please focus on functions DEMO_LcdWriteCommand, DEMO_LcdWriteData, and DEMO_LcdWriteMemory
to learn how to use the APIs. Note that the DEMO_LcdWriteCommand and DEMO_LcdWriteData
still use blocking APIs, because the send data is very small, blocking API is faster
in this case. It is still OK to use FLEXIO_MCULCD_TransferSMARTDMA in this case.

In this project, the panel is devided into 4 windows, the project changes the color
of each window one by one. The behavior is:
1. Project starts with black screen.
2. Fill window one by one as red, and delay 0.5s after fill each window.
3. Fill window one by one as green, and delay 0.5s after fill each window.
4. Fill window one by one as blue, and delay 0.5s after fill each window.
5. Fill window one by one as white, and delay 0.5s after fill each window.
6. Go to step 2.

+---------------------------+---------------------------+
|                           |                           |
|                           |                           |
|                           |                           |
|      window 0             |        window 1           |
|                           |                           |
|                           |                           |
+---------------------------+---------------------------+
|                           |                           |
|                           |                           |
|                           |                           |
|      window 2             |        window 3           |
|                           |                           |
|                           |                           |
+---------------------------+---------------------------+

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
- TFT Proto 5" CAPACITIVE board HW REV 1.01 by Mikroelektronika.

Board settings
==============
Connect the panel to header J8. Pin 1 match Pin 1.

Note: Only A1 version chip support this example.

Prepare the Demo
================
1.  Connect a USB cable between the host PC and the EVK board J17.
2.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
When the project running, the panel shows as overview described.