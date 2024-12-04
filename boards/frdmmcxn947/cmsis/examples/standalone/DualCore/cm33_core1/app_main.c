/*---------------------------------------------------------------------------
 * Copyright (c) 2024 Arm Limited (or its affiliates). All rights reserved.
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
 *---------------------------------------------------------------------------*/
#if 0
#include "main.h"

//#include "cmsis_os2.h"
//#include "cmsis_vio.h"

/*-----------------------------------------------------------------------------
 * Application main thread
 *----------------------------------------------------------------------------*/
// __NO_RETURN void app_main_thread (void *argument) {
//   (void)argument;

//   for (;;) {
//     vioSetSignal(vioLED1, vioLEDoff);         // Switch LED1 off
//     osDelay(500U);                            // Delay 500 ms
//     vioSetSignal(vioLED1, vioLEDon);          // Switch LED1 on
//     osDelay(500U);                            // Delay 500 ms
//   }
// }

/*-----------------------------------------------------------------------------
 * Application initialization
 *----------------------------------------------------------------------------*/
int app_main (void) {
  for (;;) {
    // vioSetSignal(vioLED1, vioLEDoff);         // Switch LED1 off
    // osDelay(500U);                            // Delay 500 ms
    //vioSetSignal(vioLED1, vioLEDon);          // Switch LED1 on
    // osDelay(500U);                            // Delay 500 ms
  }
  // osKernelInitialize();                         /* Initialize CMSIS-RTOS2 */
  // osThreadNew(app_main_thread, NULL, NULL);
  // osKernelStart();                              /* Start thread execution */
  return 0;
}
#endif
#include "cmsis_vio.h"
#include "pin_mux.h"
#include "fsl_mailbox.h"

#include "fsl_common.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define PRIMARY_CORE_MAILBOX_CPU_ID   kMAILBOX_CM33_Core0
#define SECONDARY_CORE_MAILBOX_CPU_ID kMAILBOX_CM33_Core1

#define START_EVENT 1234

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile uint32_t g_msg;

/*******************************************************************************
 * Code
 ******************************************************************************/
void MAILBOX_IRQHandler()
{
    g_msg = MAILBOX_GetValue(MAILBOX, SECONDARY_CORE_MAILBOX_CPU_ID);
    MAILBOX_ClearValueBits(MAILBOX, SECONDARY_CORE_MAILBOX_CPU_ID, 0xffffffff);
    g_msg++;
    MAILBOX_SetValue(MAILBOX, PRIMARY_CORE_MAILBOX_CPU_ID, g_msg);
}

/*!
 * @brief Main function
 */
int app_main (void) {
  uint32_t n;

    /* Initialize Mailbox */
    MAILBOX_Init(MAILBOX);

    /* Enable mailbox interrupt */
    NVIC_EnableIRQ(MAILBOX_IRQn);

    /* Let the other side know the application is up and running */
    MAILBOX_SetValue(MAILBOX, PRIMARY_CORE_MAILBOX_CPU_ID, (uint32_t)START_EVENT);

    while (1)
    {
        vioSetSignal(vioLED1, vioLEDon);          // Switch LED1 on
        for(n=150000000/4/8; n != 0; n--) {
          __NOP();
        }

        vioSetSignal(vioLED1, vioLEDoff);         // Switch LED1 off
        for(n=150000000/4/8; n != 0; n--) {
          __NOP();
        }
    }
}