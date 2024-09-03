
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
Calling the runBootloader API to force into the ISP mode: x...
The runBootloader ISP interface is choosen from the following one:
kIspPeripheral_Auto :     0
kIspPeripheral_UsbHid :   1
kIspPeripheral_Uart :     2
kIspPeripheral_SpiSlave : 3
kIspPeripheral_I2cSlave : 4
kIspPeripheral_Can :      5
Call the runBootloader API based on the arg : xxxxxxxx...
```
