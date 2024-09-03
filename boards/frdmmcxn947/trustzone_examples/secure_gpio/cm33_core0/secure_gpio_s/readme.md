Overview
========
The Secure GPIO demo application demonstrates using of GPIO peripheral and GPIO Access protection.
By configuring access protection registers (PCNS and PCNP) for each pin you can choose which pin can be used from non-secure world

This Secure GPIO demo uses one user button (let's call it ALLOW button), which is read from secure world and
one user button (let's call it LED button) which is read from non-secure world, and two LED diodes,
one controlled from secure and second one from normal world. Once ALLOW button is pressed, secure world detect this user action (logical zero is read)
and BLUE LED are light up and configure  PCNS register for LED button and red LED so it can be used in non-secure world. 

When LED button is pressed alone, nothing will happen as access to GPIO pins from non-secure world is not allowed.
So to be able light up non-secure led, firstly you need to press ALLOW button and then LED button.

For user buttons and LEDs assignment on particular board, see chapter "Running the demo".

| Input        |            | OUTPUT       |              |
|--------------|------------|--------------|--------------|
| ALLOW button | LED button | "secure" LED | "normal" LED |
| PRESSED      | RELEASED   | ON           | OFF          |
| RELEASED     | RELEASED   | OFF          | OFF          |
| PRESSED      | PRESSED    | ON           | ON           |
| RELEASED     | PRESSED    | OFF          | OFF          |

SDK version
===========
- Version: 2.16.000

Toolchain supported
===================
- GCC ARM Embedded  13.2.1
- Keil MDK  5.39.0
- IAR embedded Workbench  9.60.1

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
Note: MCUXpresso IDE project default debug console is semihost
1.  Connect a type-c USB cable between the PC host and the MCU-Link USB port (J17) on the board
2. Download the program to the target board.
3. Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
Use SW2 button to control blue LED and allowing usage of SW3 and red LED in non-secure world.
If SW2 button is pressed (logical zero is read), the blue LED is switched on in secure world and allows usage of SW3 and red LED in non-secure world
So if pressed only SW3 red light will not light up, because pins are not allowed to be controled from non-secure world.
If first is SW2 button is pressed, then after pressing SW3 red LED will light up.

TrustZone Application Development in SDK
Every TrustZone based application consists of two independent parts - secure part/project and non-secure part/project.

The secure project is stored in <application_name>\<application_name>_s directory.
The non-secure project is stored in <application_name>\<application_name>_ns directory. 

The secure projects always contains TrustZone configuration and it is executed after device RESET. The secure project usually
ends by jump to non-secure application/project.
If IDE allows the two projects in single workspace, the user can also find the project with <application_name>.
This project contains both secure and non-secure projects in one workspace (Keil MDK, IAR) and it allows to user easy transition from
one to another project.

Project Structure
The all TrustZone files related to TrustZone are located in trustzone virtual directory. The files are:

- tzm_config.c
- tzm_config.h
- veneer_table.c
- veneer_table.h

File tzm_config.c, tzm_config.h
This file is used by secure project only. It contains one function BOARD_InitTrustZone(), which configures complete TrustZone
environment. It includes SAU, MPU's, AHB secure controller and some TrustZone related registers from System Control Block.
This function is called from SystemInitHook() function, it means during system initialization.

File veneer_table.c, veneer_table.h
This file defines all secure functions (secure entry functions) exported to normal world. This file is located in secure
project only. While header file is used by both secure and non-secure projects. The secure entry functions usually contain
validation of all input parameters in order to avoid any data leak from secure world.

The files veneer_table.h and <application_name>_s_import_lib.o or <application_name>_s_CMSE_lib.o create the connection
between secure and non-secure projects. The library file is generated by linker during compilation of secure project and
it is linked to the non-secure project as any other library.

TrustZone application compilation
As first compile secure project since CMSE library is needed for compilation of non-secure project. 
After successful compilation of secure project, compile non-secure project.

TrustZone application debugging
- Download both output file into device memory
- Start execution of secure project since secure project is going to be executed after device RESET.

If IDE (Keil MDK, IAR) allows to manage download both output files as single download, the secure project
is configured to download both secure and non-secure output files so debugging can be fully managed
from secure project.

Device header file and secure/non-secure access to the peripherals
Both secure and non-secure project uses identical device header file. The access to secure and non-secure aliases for all peripherals
is managed using compiler macro __ARM_FEATURE_CMSE.

For secure project using <PERIPH_BASE> means access through secure alias (address bit A28=1), 
using <PERIPH_BASE>_NS means access through non-secure alias(address bit A28=0)
For non-secure project using <PERIPH_BASE> means access through non-secure alias (address bit A28=0). 
The non-secure project doesn't have access to secure memory or peripherals regions so the secure access is not defined.