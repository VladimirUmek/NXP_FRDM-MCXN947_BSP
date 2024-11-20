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

#include <arm_cmse.h>     // CMSE definitions
#include "secure_lib.h"   // Header file with secure interface API

#define NON_SECURE_CALLABLE_FUNC  __attribute__((cmse_nonsecure_entry))

/* Define a pointer to a function that will be executed in non-secure state */
typedef Callback_t __attribute__((cmse_nonsecure_call)) NS_Callback_t;


/* Function that executes in secure state and can be called from non-secure state. */
NON_SECURE_CALLABLE_FUNC int32_t Func_NSC (int32_t x, Callback_t callback) {
	NS_Callback_t ns_callback;
	int32_t rval;

	/* Create function pointer for non-secure function that can be called from secure state */
  ns_callback = (NS_Callback_t)cmse_nsfptr_create(callback);

  if (callback == NULL) {
    rval = 0;
  }
  else {
    /* Execute user provided function in the non-secure state */
    ns_callback (x+1);
    rval = 1;
  }

	return (rval);
}