/*
 * Copyright 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v14.0
processor: MCXN947
package_id: MCXN947VDF
mcu_data: ksdk2_0
processor_version: 0.14.23
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_inputmux.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: cm33_core0, enableClock: 'true'}
- pin_list:
  - {pin_num: A1, peripheral: LP_FLEXCOMM4, signal: LPFLEXCOMM_P0, pin_signal: PIO1_8/WUU0_IN10/LPTMR1_ALT3/TRACE_DATA0/FC4_P0/FC5_P4/CT_INP8/SCT0_OUT2/FLEXIO0_D16/EZH_PIO4/PLU_OUT0/ENET0_TXD2/I3C1_SDA/TSI0_CH17/ADC1_A8,
    slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, passive_filter: disable, pull_value: low, input_buffer: enable,
    invert_input: normal}
  - {pin_num: B1, peripheral: LP_FLEXCOMM4, signal: LPFLEXCOMM_P1, pin_signal: PIO1_9/TRACE_DATA1/FC4_P1/FC5_P5/CT_INP9/SCT0_OUT3/FLEXIO0_D17/EZH_PIO5/PLU_OUT1/ENET0_TXD3/I3C1_SCL/TSI0_CH18/ADC1_A9,
    slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, passive_filter: disable, input_buffer: enable, invert_input: normal}
  - {peripheral: QDC0, signal: INDEX, pin_signal: TRIG_IN0}
  - {peripheral: QDC0, signal: 'PHASE, A', pin_signal: TRIG_IN1}
  - {peripheral: QDC0, signal: 'PHASE, B', pin_signal: TRIG_IN3}
  - {pin_num: C6, peripheral: INPUTMUX0, signal: 'TRIG_IN, 0', pin_signal: PIO1_0/WUU0_IN6/LPTMR0_ALT3/TRIG_IN0/FC3_P0/FC4_P4/CT_INP4/SCT0_OUT6/FLEXIO0_D8/SAI1_TX_BCLK/TSI0_CH0/ADC0_A16/CMP0_IN0,
    slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, passive_filter: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: C5, peripheral: INPUTMUX0, signal: 'TRIG_IN, 1', pin_signal: PIO1_1/TRIG_IN1/FC3_P1/FC4_P5/CT_INP5/SCT0_OUT7/FLEXIO0_D9/SAI1_TX_FS/TSI0_CH1/ADC0_A17/CMP1_IN0,
    slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, passive_filter: disable, input_buffer: enable, invert_input: normal}
  - {pin_num: L4, peripheral: INPUTMUX0, signal: 'TRIG_IN, 3', pin_signal: PIO1_22/TRIG_IN3/FC5_P6/FC4_P2/CT_INP14/SCT0_OUT4/FLEXIO0_D30/EZH_PIO18/ADC1_A22, slew_rate: fast,
    open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: enable, invert_input: normal}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
    /* Enables the clock for INPUTMUX: Enables clock */
    CLOCK_EnableClock(kCLOCK_InputMux0);
    /* Enables the clock for PORT1: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port1);
    /* TRIG_IN0 is selected as trigger input for QDC0 INDEX channel 0 */
    INPUTMUX_AttachSignal(INPUTMUX0, 0U, kINPUTMUX_TrigIn0ToQdc0Index);
    /* TRIG_IN1 is selected as trigger input for QDC0 PHASEA channel 0 */
    INPUTMUX_AttachSignal(INPUTMUX0, 0U, kINPUTMUX_TrigIn1ToQdc0Phasea);
    /* TRIG_IN3 is selected as trigger input for QDC0 PHASEB channel 0 */
    INPUTMUX_AttachSignal(INPUTMUX0, 0U, kINPUTMUX_TrigIn3ToQdc0Phaseb);

    const port_pin_config_t port1_0_pinC6_config = {/* Internal pull-up/down resistor is disabled */
                                                    kPORT_PullDisable,
                                                    /* Low internal pull resistor value is selected. */
                                                    kPORT_LowPullResistor,
                                                    /* Fast slew rate is configured */
                                                    kPORT_FastSlewRate,
                                                    /* Passive input filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Open drain output is disabled */
                                                    kPORT_OpenDrainDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as TRIG_IN0 */
                                                    kPORT_MuxAlt1,
                                                    /* Digital input enabled */
                                                    kPORT_InputBufferEnable,
                                                    /* Digital input is not inverted */
                                                    kPORT_InputNormal,
                                                    /* Pin Control Register fields [15:0] are not locked */
                                                    kPORT_UnlockRegister};
    /* PORT1_0 (pin C6) is configured as TRIG_IN0 */
    PORT_SetPinConfig(PORT1, 0U, &port1_0_pinC6_config);

    const port_pin_config_t port1_1_pinC5_config = {/* Internal pull-up/down resistor is disabled */
                                                    kPORT_PullDisable,
                                                    /* Low internal pull resistor value is selected. */
                                                    kPORT_LowPullResistor,
                                                    /* Fast slew rate is configured */
                                                    kPORT_FastSlewRate,
                                                    /* Passive input filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Open drain output is disabled */
                                                    kPORT_OpenDrainDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as TRIG_IN1 */
                                                    kPORT_MuxAlt1,
                                                    /* Digital input enabled */
                                                    kPORT_InputBufferEnable,
                                                    /* Digital input is not inverted */
                                                    kPORT_InputNormal,
                                                    /* Pin Control Register fields [15:0] are not locked */
                                                    kPORT_UnlockRegister};
    /* PORT1_1 (pin C5) is configured as TRIG_IN1 */
    PORT_SetPinConfig(PORT1, 1U, &port1_1_pinC5_config);

    const port_pin_config_t port1_22_pinL4_config = {/* Internal pull-up/down resistor is disabled */
                                                     kPORT_PullDisable,
                                                     /* Low internal pull resistor value is selected. */
                                                     kPORT_LowPullResistor,
                                                     /* Fast slew rate is configured */
                                                     kPORT_FastSlewRate,
                                                     /* Passive input filter is disabled */
                                                     kPORT_PassiveFilterDisable,
                                                     /* Open drain output is disabled */
                                                     kPORT_OpenDrainDisable,
                                                     /* Low drive strength is configured */
                                                     kPORT_LowDriveStrength,
                                                     /* Pin is configured as TRIG_IN3 */
                                                     kPORT_MuxAlt1,
                                                     /* Digital input enabled */
                                                     kPORT_InputBufferEnable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT1_22 (pin L4) is configured as TRIG_IN3 */
    PORT_SetPinConfig(PORT1, 22U, &port1_22_pinL4_config);

    const port_pin_config_t port1_8_pinA1_config = {/* Internal pull-up/down resistor is disabled */
                                                    kPORT_PullDisable,
                                                    /* Low internal pull resistor value is selected. */
                                                    kPORT_LowPullResistor,
                                                    /* Fast slew rate is configured */
                                                    kPORT_FastSlewRate,
                                                    /* Passive input filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Open drain output is disabled */
                                                    kPORT_OpenDrainDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as FC4_P0 */
                                                    kPORT_MuxAlt2,
                                                    /* Digital input enabled */
                                                    kPORT_InputBufferEnable,
                                                    /* Digital input is not inverted */
                                                    kPORT_InputNormal,
                                                    /* Pin Control Register fields [15:0] are not locked */
                                                    kPORT_UnlockRegister};
    /* PORT1_8 (pin A1) is configured as FC4_P0 */
    PORT_SetPinConfig(PORT1, 8U, &port1_8_pinA1_config);

    const port_pin_config_t port1_9_pinB1_config = {/* Internal pull-up/down resistor is disabled */
                                                    kPORT_PullDisable,
                                                    /* Low internal pull resistor value is selected. */
                                                    kPORT_LowPullResistor,
                                                    /* Fast slew rate is configured */
                                                    kPORT_FastSlewRate,
                                                    /* Passive input filter is disabled */
                                                    kPORT_PassiveFilterDisable,
                                                    /* Open drain output is disabled */
                                                    kPORT_OpenDrainDisable,
                                                    /* Low drive strength is configured */
                                                    kPORT_LowDriveStrength,
                                                    /* Pin is configured as FC4_P1 */
                                                    kPORT_MuxAlt2,
                                                    /* Digital input enabled */
                                                    kPORT_InputBufferEnable,
                                                    /* Digital input is not inverted */
                                                    kPORT_InputNormal,
                                                    /* Pin Control Register fields [15:0] are not locked */
                                                    kPORT_UnlockRegister};
    /* PORT1_9 (pin B1) is configured as FC4_P1 */
    PORT_SetPinConfig(PORT1, 9U, &port1_9_pinB1_config);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
