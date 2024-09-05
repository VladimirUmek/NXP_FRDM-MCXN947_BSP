/******************************************************************************
 * @file     vio_FRDM-MCXN947.c
 * @brief    Virtual I/O implementation for NXP FRDM-MCXN947
 * @version  V1.0.0
 * @date     03. September 2024
 ******************************************************************************/
/*
 * Copyright (c) 2024 Arm Limited (or its affiliates).
 * All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*! \page vio_DevKit Physical I/O Mapping
The table below lists the physical I/O mapping of this CMSIS-Driver VIO implementation.
Virtual Resource  | Variable       | Physical Resource on FRDM-MCXN947              |
:-----------------|:---------------|:-----------------------------------------------|
vioBUTTON0        | vioSignalIn.0  | WAKEUP SW2                                     |
vioLED0           | vioSignalOut.0 | RGB LED Red                                    |
vioLED1           | vioSignalOut.1 | RGB LED Green                                  |
vioLED2           | vioSignalOut.2 | RGB LED Blue                                   |
*/

/* History:
 *  Version 1.0.0
 *    Initial release
 */

//#include <string.h>
#include "cmsis_vio.h"

#include "RTE_Components.h"                 // Component selection
#include CMSIS_device_header

#if !defined CMSIS_VOUT || !defined CMSIS_VIN
#include "pin_mux.h"
#include "board.h"
#endif

// VIO input, output definitions
#define VIO_VALUE_NUM           3U          // Number of values

// VIO input, output variables
__USED uint32_t vioSignalIn;                // Memory for incoming signal
__USED uint32_t vioSignalOut;               // Memory for outgoing signal
__USED int32_t  vioValue[VIO_VALUE_NUM];    // Memory for value used in vioGetValue/vioSetValue

#if !defined CMSIS_VOUT
#define LED_0_PIN               GPIO_PIN(BOARD_LEDRGB0_R_GPIO_PORT, BOARD_LEDRGB0_R_GPIO_PIN)
#define LED_1_PIN               GPIO_PIN(BOARD_LEDRGB0_G_GPIO_PORT, BOARD_LEDRGB0_G_GPIO_PIN)
#define LED_2_PIN               GPIO_PIN(BOARD_LEDRGB0_B_GPIO_PORT, BOARD_LEDRGB0_B_GPIO_PIN)
#endif

#if !defined CMSIS_VIN
#define JOY_UP_PIN              GPIO_PIN(BOARD_JOY_SW_A_GPIO_PORT, BOARD_JOY_SW_A_GPIO_PIN)
#define JOY_DOWN_PIN            GPIO_PIN(BOARD_JOY_SW_B_GPIO_PORT, BOARD_JOY_SW_B_GPIO_PIN)
#define JOY_LEFT_PIN            GPIO_PIN(BOARD_JOY_SW_C_GPIO_PORT, BOARD_JOY_SW_C_GPIO_PIN)
#define JOY_RIGHT_PIN           GPIO_PIN(BOARD_JOY_SW_D_GPIO_PORT, BOARD_JOY_SW_D_GPIO_PIN)
#define JOY_SELECT_PIN          GPIO_PIN(BOARD_JOY_SW_CENTER_GPIO_PORT, BOARD_JOY_SW_CENTER_GPIO_PIN)

#define BUTTON_0_PIN            JOY_SELECT_PIN
#endif

// Initialize test input, output.
void vioInit (void) {
#if !defined(CMSIS_VOUT) || !defined(CMSIS_VIN)
#endif

  vioSignalIn  = 0U;
  vioSignalOut = 0U;

  memset(vioValue, 0, sizeof(vioValue));

#if !defined CMSIS_VOUT
  // Initialize LEDs pins
  BOARD_InitLEDsPins();

  // Turn off all LEDs
  LED_RED_INIT(LOGIC_LED_OFF);
  LED_BLUE_INIT(LOGIC_LED_OFF);
  LED_GREEN_INIT(LOGIC_LED_OFF);
#endif

#if !defined CMSIS_VIN
  // Initialize buttons pins
  BOARD_InitBUTTONsPins();
#endif
}

// Set signal output.
void vioSetSignal (uint32_t mask, uint32_t signal) {
#if !defined CMSIS_VOUT

#endif

  vioSignalOut &= ~mask;
  vioSignalOut |=  mask & signal;

#if !defined CMSIS_VOUT
  // Output signals to LEDs
  if ((mask & vioLED0) != 0U) {
    if ((signal & vioLED0) != 0U) {
      LED_RED_ON();
    } else {
      LED_RED_OFF();
    }
  }

  if ((mask & vioLED1) != 0U) {
    if ((signal & vioLED1) != 0U) {
      LED_BLUE_ON();
    } else {
      LED_BLUE_OFF();
    }
  }

  if ((mask & vioLED2) != 0U) {
    if ((signal & vioLED2) != 0U) {
      LED_GREEN_ON();
    } else {
      LED_GREEN_OFF();
    }
  }
#endif
}

// Get signal input.
uint32_t vioGetSignal (uint32_t mask) {
  uint32_t signal;
#if !defined CMSIS_VIN

#endif

#if !defined CMSIS_VIN
  // Get input signals from buttons and joystick
  if ((mask & vioBUTTON0) != 0U) {
    if (!GPIO_PinRead (BOARD_SW2_GPIO, BOARD_SW2_GPIO_PIN)) {
      vioSignalIn |=  vioBUTTON0;
    } else {
      vioSignalIn &= ~vioBUTTON0;
    }
  }
#endif

  signal = vioSignalIn & mask;

  return signal;
}

// Set value output.
void vioSetValue (uint32_t id, int32_t value) {
  uint32_t index = id;
#if !defined CMSIS_VOUT
// Add user variables here:

#endif

  if (index >= VIO_VALUE_NUM) {
    return;                             /* return in case of out-of-range index */
  }

  vioValue[index] = value;

#if !defined CMSIS_VOUT
// Add user code here:

#endif
}

// Get value input.
int32_t vioGetValue (uint32_t id) {
  uint32_t index = id;
  int32_t  value = 0;
#if !defined CMSIS_VIN
// Add user variables here:

#endif

  if (index >= VIO_VALUE_NUM) {
    return value;                       /* return default in case of out-of-range index */
  }

#if !defined CMSIS_VIN
// Add user code here:

//   vioValue[index] = ...;
#endif

  value = vioValue[index];

  return value;
}