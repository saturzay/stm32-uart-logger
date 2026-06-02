#include "uart.h"
#include <stdint.h>

/*
 * STM32F100 USART1 — direct register access.
 * TX pin: PA9 (alternate function push-pull).
 * Connected to QEMU's serial0 which -nographic forwards to stdio.
 */

#define RCC_BASE    0x40021000U
#define RCC_APB2ENR (*(volatile uint32_t *)(RCC_BASE + 0x18U))

#define GPIOA_BASE  0x40010800U
#define GPIOA_CRH   (*(volatile uint32_t *)(GPIOA_BASE + 0x04U))

#define USART1_BASE 0x40013800U
#define USART1_SR   (*(volatile uint32_t *)(USART1_BASE + 0x00U))
#define USART1_DR   (*(volatile uint32_t *)(USART1_BASE + 0x04U))
#define USART1_BRR  (*(volatile uint32_t *)(USART1_BASE + 0x08U))
#define USART1_CR1  (*(volatile uint32_t *)(USART1_BASE + 0x0CU))

#define RCC_APB2ENR_IOPAEN   (1U << 2)
#define RCC_APB2ENR_USART1EN (1U << 14)

#define USART_SR_TXE  (1U << 7)
#define USART_CR1_UE  (1U << 13)
#define USART_CR1_TE  (1U << 3)

void uart_init(void) {
    /* Enable GPIOA and USART1 peripheral clocks */
    RCC_APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_USART1EN;

    /*
     * PA9 = USART1_TX: alternate function output push-pull, 50 MHz.
     * CRH covers pins 8-15; PA9 occupies bits [7:4].
     * MODE9[1:0]=11 (output 50 MHz), CNF9[1:0]=10 (AF push-pull) → 0xB.
     */
    GPIOA_CRH &= ~(0xFU << 4);
    GPIOA_CRH |=  (0xBU << 4);

    /*
     * Baud rate: USARTDIV = fPCLK2 / (16 × baud)
     * = 8 000 000 / (16 × 115 200) ≈ 4.340
     * Mantissa = 4 (bits [15:4]), fraction = round(0.340×16)=5 (bits [3:0])
     * → BRR = 0x0045
     */
    USART1_BRR = 0x0045U;

    /* Enable USART (UE) and transmitter (TE) */
    USART1_CR1 = USART_CR1_UE | USART_CR1_TE;
}

void uart_putc(char c) {
    while (!(USART1_SR & USART_SR_TXE));
    USART1_DR = (uint32_t)(unsigned char)c;
}

void uart_puts(const char *s) {
    while (*s) {
        uart_putc(*s++);
    }
}
