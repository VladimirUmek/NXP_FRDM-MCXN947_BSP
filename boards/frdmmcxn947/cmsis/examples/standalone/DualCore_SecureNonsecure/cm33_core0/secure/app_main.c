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

#include <stdint.h>
#include <stdio.h>
#include <arm_cmse.h>

#include "RTE_Components.h"
#include CMSIS_device_header

/* Start address of the non-secure application */
#ifndef NS_APP_START_ADDRESS
#define NS_APP_START_ADDRESS (0x00000000)
#endif

/* Define a pointer to a function that will be executed in non-secure state */
typedef void (*NS_Func_t) (void) __attribute__((cmse_nonsecure_call));

/*
  Fist entry in the non-secure vector table is the Main Stack Pointer:
  *((uint32_t *)(NS_APP_START_ADDRESS)) == MSP_NS

  Second entry in the non-secure vector table is the Reset Handler:
  *((uint32_t *)(NS_APP_START_ADDRESS + 4U)) == Reset_Handler
*/

/* Application main function */
int app_main (void) {
  uint32_t  Stack_NS;
  NS_Func_t ResetHandler_NS;

  /* Read the address of the main stack in non-secure state */
  Stack_NS = *((volatile uint32_t *)(NS_APP_START_ADDRESS));

  /* Set Main Stack Pointer for the non-secure side (MSP_NS) */
  __TZ_set_MSP_NS(Stack_NS);

  /* Set address of the non-secure Reset Handler */
  ResetHandler_NS = (NS_Func_t)(*((uint32_t *)(NS_APP_START_ADDRESS + 4U)));

  printf("Jump to non-secure application at 0x%08X\n", (uint32_t)ResetHandler_NS);

  /* Call non-secure Reset Handler and start executing non-secure application */
  ResetHandler_NS();

  /* Non-secure application does not return */
  for (;;){;}
}
