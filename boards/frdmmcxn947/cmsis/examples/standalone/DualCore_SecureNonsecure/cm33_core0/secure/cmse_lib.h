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

#ifndef MAIN_H__
#define MAIN_H__

#include <stdint.h>

/* Callback function pointer type */
typedef void (*Callback_t) (int32_t);

/*
  Function that executes in secure state and can be called from non-secure state.

  This function will
  - increment x
  - callback to the non-secure application to provide incremented value
  - return execution status:
      0 - callback function was NULL
      1 - callback function was provided
*/
int32_t Func_NSC (int32_t x, Callback_t callback);
#endif
