/*
 * Copyright 2022-2023 NXP
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
processor_version: 0.14.14
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
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
  - {pin_num: T8, peripheral: OPAMP0, signal: OUT, pin_signal: PIO4_15/WUU0_IN21/TRIG_OUT4/USB1_VBUS_DIG/CT4_MAT3/FLEXIO0_D23/PLU_OUT3/SINC0_MCLK_OUT0/CAN1_RXD/OPAMP0_OUT/ADC0_A1/CMP0_IN4P,
    eft_interrupt: disable, slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: disable, invert_input: normal}
  - {pin_num: T6, peripheral: OPAMP0, signal: 'DP, 0', pin_signal: PIO4_12/WUU0_IN20/USB0_VBUS_DET/FC2_P0/CT4_MAT0/FLEXIO0_D20/PLU_OUT0/SINC0_MCLK0/CAN0_RXD/OPAMP0_INP0/ADC0_A5/ADC1_A5,
    eft_interrupt: disable, slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: disable, invert_input: normal}
  - {pin_num: T7, peripheral: OPAMP0, signal: 'DP, 1', pin_signal: PIO4_13/TRIG_IN8/FC2_P1/USB1_ID/CT4_MAT1/FLEXIO0_D21/PLU_OUT1/SINC0_MBIT0/CAN0_TXD/OPAMP0_INP1/ADC0_B5/ADC1_B5,
    eft_interrupt: disable, slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, input_buffer: disable, invert_input: normal}
  - {pin_num: A1, peripheral: LP_FLEXCOMM4, signal: LPFLEXCOMM_P0, pin_signal: PIO1_8/WUU0_IN10/LPTMR1_ALT3/TRACE_DATA0/FC4_P0/FC5_P4/CT_INP8/SCT0_OUT2/FLEXIO0_D16/PLU_OUT0/ENET0_TXD2/I3C1_SDA/TSI0_CH17/ADC1_A8,
    slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, passive_filter: disable, pull_value: low, input_buffer: enable,
    invert_input: normal}
  - {pin_num: B1, peripheral: LP_FLEXCOMM4, signal: LPFLEXCOMM_P1, pin_signal: PIO1_9/TRACE_DATA1/FC4_P1/FC5_P5/CT_INP9/SCT0_OUT3/FLEXIO0_D17/PLU_OUT1/ENET0_TXD3/I3C1_SCL/TSI0_CH18/ADC1_A9,
    slew_rate: fast, open_drain: disable, drive_strength: low, pull_select: down, pull_enable: disable, passive_filter: disable, input_buffer: enable, invert_input: normal}
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
    /* Enables the clock for PORT1: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port1);
    /* Enables the clock for PORT4: Enables clock */
    CLOCK_EnableClock(kCLOCK_Port4);

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

    /* EFT detect interrupts configuration on PORT4_ */
    PORT_DisableEFTDetectInterrupts(PORT4, 0xB000u);

    const port_pin_config_t port4_12_pinT6_config = {/* Internal pull-up/down resistor is disabled */
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
                                                     /* Pin is configured as OPAMP0_INP0 */
                                                     kPORT_MuxAlt0,
                                                     /* Digital input disabled; it is required for analog functions */
                                                     kPORT_InputBufferDisable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT4_12 (pin T6) is configured as OPAMP0_INP0 */
    PORT_SetPinConfig(PORT4, 12U, &port4_12_pinT6_config);

    const port_pin_config_t port4_13_pinT7_config = {/* Internal pull-up/down resistor is disabled */
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
                                                     /* Pin is configured as OPAMP0_INP1 */
                                                     kPORT_MuxAlt0,
                                                     /* Digital input disabled; it is required for analog functions */
                                                     kPORT_InputBufferDisable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT4_13 (pin T7) is configured as OPAMP0_INP1 */
    PORT_SetPinConfig(PORT4, 13U, &port4_13_pinT7_config);

    const port_pin_config_t port4_15_pinT8_config = {/* Internal pull-up/down resistor is disabled */
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
                                                     /* Pin is configured as OPAMP0_OUT */
                                                     kPORT_MuxAlt0,
                                                     /* Digital input disabled; it is required for analog functions */
                                                     kPORT_InputBufferDisable,
                                                     /* Digital input is not inverted */
                                                     kPORT_InputNormal,
                                                     /* Pin Control Register fields [15:0] are not locked */
                                                     kPORT_UnlockRegister};
    /* PORT4_15 (pin T8) is configured as OPAMP0_OUT */
    PORT_SetPinConfig(PORT4, 15U, &port4_15_pinT8_config);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
