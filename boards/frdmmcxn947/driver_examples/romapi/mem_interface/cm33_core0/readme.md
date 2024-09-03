
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

Prepare the Demo
================
1.  Connect a type-c USB cable between the PC host and the MCU-Link USB port (J17) on the board
2.  Open a serial terminal with the following settings (See Appendix A in Getting started guide for description how to determine serial port number):
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================

When the example runs successfully, the following message is displayed in the terminal:

```
Internal flash example start:

Calling API_Version!
IAP API version = x.x.x

Calling API_Init!
API_Init Successfully!

PFlash Information:
Program Flash Base Address: xx
Total Program Flash Size: xx
Program Flash Sector Size: xx

Erasing internal flash
Successfully erased internal flash xx -> xx

Calling MEM_Write to program internal flash!
Successfully Programmed and Verified Location xx -> xx

End of internal flash example!
```
