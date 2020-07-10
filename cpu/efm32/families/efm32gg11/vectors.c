/*
 * Copyright (C) 2015-2018 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     cpu_efm32gg11
 * @{
 *
 * @file
 * @brief       Startup code and interrupt vector definition
 *
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 * @author      Bas Stottelaar <basstottelaar@gmail.com>
 *
 * @}
 */

#include "vectors_cortexm.h"

/* define a local dummy handler as it needs to be in the same compilation unit
 * as the alias definition */
void dummy_handler(void)
{
    dummy_handler_default();
}

/* Silicon Labs specific interrupt vector */

WEAK_DEFAULT void isr_emu(void);
WEAK_DEFAULT void isr_wdog0(void);
WEAK_DEFAULT void isr_ldma(void);
WEAK_DEFAULT void isr_gpio_even(void);
WEAK_DEFAULT void isr_smu(void);
WEAK_DEFAULT void isr_timer0(void);
WEAK_DEFAULT void isr_usart0_rx(void);
WEAK_DEFAULT void isr_usart0_tx(void);
WEAK_DEFAULT void isr_acmp0(void);
WEAK_DEFAULT void isr_adc0(void);
WEAK_DEFAULT void isr_dac0(void);
WEAK_DEFAULT void isr_i2c0(void);
WEAK_DEFAULT void isr_i2c1(void);
WEAK_DEFAULT void isr_gpio_odd(void);
WEAK_DEFAULT void isr_timer1(void);
WEAK_DEFAULT void isr_timer2(void);
WEAK_DEFAULT void isr_timer3(void);
WEAK_DEFAULT void isr_usart1_rx(void);
WEAK_DEFAULT void isr_usart1_tx(void);

WEAK_DEFAULT void isr_usart2_rx(void);
WEAK_DEFAULT void isr_usart2_tx(void);
WEAK_DEFAULT void isr_uart0_rx(void);
WEAK_DEFAULT void isr_uart0_tx(void);
WEAK_DEFAULT void isr_uart1_rx(void);
WEAK_DEFAULT void isr_uart1_tx(void);
WEAK_DEFAULT void isr_leuart0(void);
WEAK_DEFAULT void isr_leuart1(void);
WEAK_DEFAULT void isr_letimer0(void);
WEAK_DEFAULT void isr_pcnt0(void);
WEAK_DEFAULT void isr_pcnt1(void);
WEAK_DEFAULT void isr_pcnt2(void);
WEAK_DEFAULT void isr_rtcc(void);
WEAK_DEFAULT void isr_cmu(void);
WEAK_DEFAULT void isr_msc(void);
WEAK_DEFAULT void isr_crypto0(void);
WEAK_DEFAULT void isr_cryotimer(void);
WEAK_DEFAULT void isr_fpueh(void);
WEAK_DEFAULT void isr_usart3_rx(void);
WEAK_DEFAULT void isr_usart3_tx(void);
WEAK_DEFAULT void isr_usart4_rx(void);
WEAK_DEFAULT void isr_usart4_tx(void);

WEAK_DEFAULT void isr_wtimer0(void);
WEAK_DEFAULT void isr_wtimer1(void);
WEAK_DEFAULT void isr_wtimer2(void);
WEAK_DEFAULT void isr_wtimer3(void);

WEAK_DEFAULT void isr_i2c2(void);

WEAK_DEFAULT void isr_vdac0(void);
WEAK_DEFAULT void isr_timer4(void);
WEAK_DEFAULT void isr_timer5(void);
WEAK_DEFAULT void isr_timer6(void);

WEAK_DEFAULT void isr_usart5_rx(void);
WEAK_DEFAULT void isr_usart5_tx(void);

WEAK_DEFAULT void isr_csen(void);
WEAK_DEFAULT void isr_lesense(void);
WEAK_DEFAULT void isr_ebi(void);
WEAK_DEFAULT void isr_acmp2(void);
WEAK_DEFAULT void isr_adc1(void);
WEAK_DEFAULT void isr_lcd(void);
WEAK_DEFAULT void isr_sdio(void);
WEAK_DEFAULT void isr_eth(void);
WEAK_DEFAULT void isr_can0(void);
WEAK_DEFAULT void isr_can1(void);
WEAK_DEFAULT void isr_usb(void);
WEAK_DEFAULT void isr_rtc(void);
WEAK_DEFAULT void isr_wdog1(void);
WEAK_DEFAULT void isr_letimer1(void);
WEAK_DEFAULT void isr_trng(void);
WEAK_DEFAULT void isr_qspio(void);

/* interrupt vector table */
/* rg: mostly bs, just added uart IRQs */
ISR_VECTOR(1) const isr_t vector_cpu[68] = {
    [0] = isr_emu,                /* EMU */
    [1] = isr_wdog0,
    [2] = isr_ldma,                /* DMA */
    [3] = isr_gpio_even,          /* GPIO_EVEN */
    [4] = isr_smu,
    [5] = isr_timer0,             /* TIMER0 */
    [6] = isr_usart0_rx,         /*!< 16+6 EFM32 USART0_RX Interrupt */
    [7] = isr_usart0_tx,         /*!< 16+7 EFM32 USART0_TX Interrupt */
    [8] = isr_acmp0,             /*!< 16+8 EFM32 ACMP0 Interrupt */
    [9] = isr_adc0,              /*!< 16+9 EFM32 ADC0 Interrupt */
    [10] = isr_dac0,            /*!< 16+10 EFM32 IDAC0 Interrupt */
    [11] = isr_i2c0,             /*!< 16+11 EFM32 I2C0 Interrupt */
    [12] = isr_i2c1,             /*!< 16+12 EFM32 I2C1 Interrupt */
    [13] = isr_gpio_odd,         /*!< 16+13 EFM32 GPIO_ODD Interrupt */
    [14] = isr_timer1,           /*!< 16+14 EFM32 TIMER1 Interrupt */
    [15] = isr_timer2,           /*!< 16+15 EFM32 TIMER2 Interrupt */
    [16] = isr_timer3,           /*!< 16+16 EFM32 TIMER3 Interrupt */
    [17] = isr_usart1_rx,        /*!< 16+17 EFM32 USART1_RX Interrupt */
    [18] = isr_usart1_tx,        /*!< 16+18 EFM32 USART1_TX Interrupt */
    [19] = isr_usart2_rx,        /*!< 16+19 EFM32 USART2_RX Interrupt */
    [20] = isr_usart2_tx,        /*!< 16+20 EFM32 USART2_TX Interrupt */
    [21] = isr_uart0_rx,         /*!< 16+21 EFM32 UART0_RX Interrupt */
    [22] = isr_uart0_tx,         /*!< 16+22 EFM32 UART0_TX Interrupt */
    [23] = isr_uart1_rx,         /*!< 16+23 EFM32 UART1_RX Interrupt */
    [24] = isr_uart1_tx,         /*!< 16+24 EFM32 UART1_TX Interrupt */
    [25] = isr_leuart0,          /*!< 16+25 EFM32 LEUART0 Interrupt */
    [26] = isr_leuart1,          /*!< 16+26 EFM32 LEUART1 Interrupt */
    [27] = isr_letimer0,         /*!< 16+27 EFM32 LETIMER0 Interrupt */
    [28] = isr_pcnt0,            /*!< 16+28 EFM32 PCNT0 Interrupt */
    [29] = isr_pcnt1,            /*!< 16+29 EFM32 PCNT1 Interrupt */
    [30] = isr_pcnt2,            /*!< 16+30 EFM32 PCNT2 Interrupt */
    [31] = isr_rtcc,             /*!< 16+31 EFM32 RTCC Interrupt */
    [32] = isr_cmu,              /*!< 16+32 EFM32 CMU Interrupt */
    [33] = isr_msc,              /*!< 16+33 EFM32 MSC Interrupt */
    [34] = isr_crypto0,          /*!< 16+34 EFM32 CRYPTO0 Interrupt */
    [35] = isr_cryotimer,        /*!< 16+35 EFM32 CRYOTIMER Interrupt */
    [36] = isr_fpueh,            /*!< 16+36 EFM32 FPUEH Interrupt */
    [37] = isr_usart3_rx,        /*!< 16+37 EFM32 USART3_RX Interrupt */
    [38] = isr_usart3_tx,        /*!< 16+38 EFM32 USART3_TX Interrupt */
    [39] = isr_usart4_rx,        /*!< 16+39 EFM32 USART4_RX Interrupt */
    [40] = isr_usart4_tx,        /*!< 16+40 EFM32 USART4_TX Interrupt */
    [41] = isr_wtimer0,          /*!< 16+41 EFM32 WTIMER0 Interrupt */
    [42] = isr_wtimer1,          /*!< 16+42 EFM32 WTIMER1 Interrupt */
    [43] = isr_wtimer2,          /*!< 16+43 EFM32 WTIMER2 Interrupt */
    [44] = isr_wtimer3,          /*!< 16+44 EFM32 WTIMER3 Interrupt */
    [45] = isr_i2c2,             /*!< 16+45 EFM32 I2C2 Interrupt */
    [46] = isr_vdac0,            /*!< 16+46 EFM32 VDAC0 Interrupt */
    [47] = isr_timer4,           /*!< 16+47 EFM32 TIMER4 Interrupt */
    [48] = isr_timer5,           /*!< 16+48 EFM32 TIMER5 Interrupt */
    [49] = isr_timer6,           /*!< 16+49 EFM32 TIMER6 Interrupt */
    [50] = isr_usart5_rx,        /*!< 16+50 EFM32 USART5_RX Interrupt */
    [51] = isr_usart5_tx,        /*!< 16+51 EFM32 USART5_TX Interrupt */
    [52] = isr_csen,             /*!< 16+52 EFM32 CSEN Interrupt */
    [53] = isr_lesense,          /*!< 16+53 EFM32 LESENSE Interrupt */
    [54] = isr_ebi,              /*!< 16+54 EFM32 EBI Interrupt */
    [55] = isr_acmp2,            /*!< 16+55 EFM32 ACMP2 Interrupt */
    [56] = isr_adc1,             /*!< 16+56 EFM32 ADC1 Interrupt */
    [57] = isr_lcd,              /*!< 16+57 EFM32 LCD Interrupt */
    [58] = isr_sdio,             /*!< 16+58 EFM32 SDIO Interrupt */
    [59] = isr_eth,              /*!< 16+59 EFM32 ETH Interrupt */
    [60] = isr_can0,             /*!< 16+60 EFM32 CAN0 Interrupt */
    [61] = isr_can1,             /*!< 16+61 EFM32 CAN1 Interrupt */
    [62] = isr_usb,              /*!< 16+62 EFM32 USB Interrupt */
    [63] = isr_rtc,              /*!< 16+63 EFM32 RTC Interrupt */
    [64] = isr_wdog1,            /*!< 16+64 EFM32 WDOG1 Interrupt */
    [65] = isr_letimer1,         /*!< 16+65 EFM32 LETIMER1 Interrupt */
    [66] = isr_trng,            /*!< 16+66 EFM32 TRNG0 Interrupt */
    [67] = isr_qspio,            /*!< 16+67 EFM32 QSPI0 Interrupt */
};
