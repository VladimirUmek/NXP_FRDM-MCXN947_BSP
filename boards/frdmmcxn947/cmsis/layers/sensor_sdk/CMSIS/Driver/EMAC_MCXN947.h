/* -------------------------------------------------------------------------- 
 * Copyright (c) 2018-2024 Arm Limited (or its affiliates).
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
 *
 *
 * $Date:        5. December 2024
 * $Revision:    V1.0
 *
 * Project:      Ethernet Media Access (MAC) Definitions for NXP MCXN947
 * -------------------------------------------------------------------------- */

#ifndef EMAC_MCXN947_H__
#define EMAC_MCXN947_H__

#include <string.h>

#include "Driver_ETH_MAC.h"

#include "fsl_enet.h"                   // NXP::Device:SDK Drivers:enet
#include "pin_mux.h"                    // NXP::Board Support:SDK Project Template:project_template

/* Configure Reduced-Media-Independent interface mode */
#ifndef ENET_RMII
#define ENET_RMII           1
#endif

/* EMAC Driver state flags */
#define EMAC_FLAG_INIT     (1U << 0)        // Driver initialized
#define EMAC_FLAG_POWER    (1U << 1)        // Driver power on

/* EMAC Driver Control Information */
typedef struct _EMAC_INFO {
  ARM_ETH_MAC_SignalEvent_t cb_event;       // Event callback
  uint8_t                   flags;          // Control and state flags
  uint8_t                   rx_index;       // Receive descriptor index
  uint8_t                   tx_index;       // Transmit descriptor index
  uint32_t                  tx_len;         // Length of assembled frame fragments
} EMAC_INFO;

/* Global functions and variables exported by the driver */
extern ARM_DRIVER_ETH_MAC Driver_ETH_MAC0;

#endif /* EMAC_MCXN947_H__ */
