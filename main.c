#include "uart.h"
#include <stdint.h>

/* SysTick registers (Cortex-M3 internal) */
#define SYST_CSR (*(volatile uint32_t *)0xE000E010U)
#define SYST_RVR (*(volatile uint32_t *)0xE000E014U)
#define SYST_CVR (*(volatile uint32_t *)0xE000E018U)

/*
 * Millisecond counter incremented by the SysTick ISR.
 * Declared volatile because it is written in interrupt context and
 * read in the main loop — the compiler must not cache the value.
 */
volatile uint32_t tick_ms = 0;

/* Overrides the weak stub in startup.c */
void SysTick_Handler(void) {
    tick_ms++;
}

static void print_uint(uint32_t n) {
    char buf[11]; /* max 10 digits for 2^32-1, plus NUL */
    int i = 10;
    buf[i] = '\0';
    if (n == 0) {
        uart_putc('0');
        return;
    }
    while (n > 0) {
        buf[--i] = '0' + (int)(n % 10);
        n /= 10;
    }
    uart_puts(&buf[i]);
}

int main(void) {
    uart_init();

    /*
     * SysTick: processor clock (8 MHz HSI default), 1 ms period.
     * RELOAD = 8 000 000 × 0.001 − 1 = 7 999.
     * CSR: CLKSOURCE=1 (processor), TICKINT=1, ENABLE=1 → 0x7.
     */
    SYST_RVR = 8000U - 1U;
    SYST_CVR = 0U;
    SYST_CSR = 0x7U;

    uint32_t last_tick = 0;
    uint32_t n = 0;

    for (;;) {
        uint32_t now = tick_ms; /* single atomic 32-bit read on Cortex-M3 */
        if (now - last_tick >= 1000U) {
            last_tick += 1000U;
            uart_puts("tick ");
            print_uint(n++);
            uart_puts(": hello from firmware\r\n");
        }
    }
}
