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

#include "secure_lib.h"

/* Non-secure variables */
int32_t x;
int32_t y;

/* Function to be called from the secure state */
static void Callback_NS (int32_t x_inc) {
  y = x_inc;
}

/* Application main function */
int app_main (void) {

  printf("Hello from non-secure application!\n\n");

  x = 0;
  y = 0;

  /* Call secure function */
  printf("Calling secure function (x=%d)\n", x);
  if (Func_NSC(x, Callback_NS) != 1) {
    /* Callback was already called from the secure state */
    printf("Received callback from the secure function (y=%d)\n", y);
  }

  for(;;);
}
