/*
 * Copyright 2022-2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void LPSPI1_InitPins(void);

#define PCR_IBE_ibe1 0x01u /*!<@brief Input Buffer Enable: Enables */
#define PCR_INV_inv0 0x00u /*!<@brief Invert Input: Does not invert */
#define PCR_ODE_ode0 0x00u /*!<@brief Open Drain Enable: Disables */
#define PCR_ODE_ode1 0x01u /*!<@brief Open Drain Enable: Enables */
#define PCR_PE_pe0 0x00u   /*!<@brief Pull Enable: Disables */
#define PCR_PS_ps0 0x00u   /*!<@brief Pull Select: Enables internal pulldown resistor */
#define PCR_SRE_sre0 0x00u /*!<@brief Slew Rate Enable: Fast */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitSincPins(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
