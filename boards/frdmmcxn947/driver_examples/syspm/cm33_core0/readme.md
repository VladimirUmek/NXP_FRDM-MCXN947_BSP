Overview
========

The SYSPM project is a simple demonstration program of the SDK SYSPM driver. 

The System Performance Monitor (SYSPM) is a memory mapped peripheral that enables the user to monitor system and/or CPU events. 
This demo project obtains the event count value through the system performance monitor, and prints three values.

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

Board settings
==============
No special settings are required.

Prepare the Demo
================
1. Connect a type-c USB cable between the PC host and the MCU-Link USB port (J17) on the board
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
The following lines are printed to the serial terminal when the demo program is executed.
The three values printed each time may be different.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
START DEMO SYSPM
eventcounter = 7
eventcounter = 122034
eventcounter = 279104
END DEMO SYSPM
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

