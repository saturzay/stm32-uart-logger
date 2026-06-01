#include <stdint.h>

extern uint32_t _estack;
extern uint32_t _sdata, _edata, _etext;
extern uint32_t _sbss, _ebss;

void Reset_Handler(void);
void Default_Handler(void);

/* Core exception handlers — all weak so any translation unit can override */
void NMI_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)__attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)       __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)    __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)   __attribute__((weak, alias("Default_Handler")));

/* STM32F100 external interrupt handlers (weak stubs) */
void WWDG_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void PVD_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void TAMPER_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void RTC_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel1_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel2_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel3_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel4_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel5_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel6_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel7_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void ADC1_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_TIM15_IRQHandler(void)  __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_TIM16_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM17_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void TIM4_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler(void)         __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void USART3_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void CEC_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void TIM12_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void TIM13_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void TIM14_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void TIM5_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void SPI3_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void UART4_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void UART5_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void TIM6_DAC_IRQHandler(void)        __attribute__((weak, alias("Default_Handler")));
void TIM7_IRQHandler(void)            __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel1_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel2_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel3_IRQHandler(void)   __attribute__((weak, alias("Default_Handler")));
void DMA2_Channel4_5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

__attribute__((section(".vectors"), used))
const uint32_t vector_table[] = {
    /* Cortex-M3 core vectors */
    (uint32_t)&_estack,
    (uint32_t)Reset_Handler,
    (uint32_t)NMI_Handler,
    (uint32_t)HardFault_Handler,
    (uint32_t)MemManage_Handler,
    (uint32_t)BusFault_Handler,
    (uint32_t)UsageFault_Handler,
    0, 0, 0, 0,                        /* Reserved */
    (uint32_t)SVC_Handler,
    (uint32_t)DebugMon_Handler,
    0,                                 /* Reserved */
    (uint32_t)PendSV_Handler,
    (uint32_t)SysTick_Handler,
    /* STM32F100 external interrupts */
    (uint32_t)WWDG_IRQHandler,
    (uint32_t)PVD_IRQHandler,
    (uint32_t)TAMPER_IRQHandler,
    (uint32_t)RTC_IRQHandler,
    (uint32_t)FLASH_IRQHandler,
    (uint32_t)RCC_IRQHandler,
    (uint32_t)EXTI0_IRQHandler,
    (uint32_t)EXTI1_IRQHandler,
    (uint32_t)EXTI2_IRQHandler,
    (uint32_t)EXTI3_IRQHandler,
    (uint32_t)EXTI4_IRQHandler,
    (uint32_t)DMA1_Channel1_IRQHandler,
    (uint32_t)DMA1_Channel2_IRQHandler,
    (uint32_t)DMA1_Channel3_IRQHandler,
    (uint32_t)DMA1_Channel4_IRQHandler,
    (uint32_t)DMA1_Channel5_IRQHandler,
    (uint32_t)DMA1_Channel6_IRQHandler,
    (uint32_t)DMA1_Channel7_IRQHandler,
    (uint32_t)ADC1_IRQHandler,
    0, 0, 0, 0,                        /* USB/CAN reserved on F100 */
    (uint32_t)EXTI9_5_IRQHandler,
    (uint32_t)TIM1_BRK_TIM15_IRQHandler,
    (uint32_t)TIM1_UP_TIM16_IRQHandler,
    (uint32_t)TIM1_TRG_COM_TIM17_IRQHandler,
    (uint32_t)TIM1_CC_IRQHandler,
    (uint32_t)TIM2_IRQHandler,
    (uint32_t)TIM3_IRQHandler,
    (uint32_t)TIM4_IRQHandler,
    (uint32_t)I2C1_EV_IRQHandler,
    (uint32_t)I2C1_ER_IRQHandler,
    (uint32_t)I2C2_EV_IRQHandler,
    (uint32_t)I2C2_ER_IRQHandler,
    (uint32_t)SPI1_IRQHandler,
    (uint32_t)SPI2_IRQHandler,
    (uint32_t)USART1_IRQHandler,
    (uint32_t)USART2_IRQHandler,
    (uint32_t)USART3_IRQHandler,
    (uint32_t)EXTI15_10_IRQHandler,
    (uint32_t)RTC_Alarm_IRQHandler,
    (uint32_t)CEC_IRQHandler,
    (uint32_t)TIM12_IRQHandler,
    (uint32_t)TIM13_IRQHandler,
    (uint32_t)TIM14_IRQHandler,
    0, 0, 0,                           /* Reserved */
    (uint32_t)TIM5_IRQHandler,
    (uint32_t)SPI3_IRQHandler,
    (uint32_t)UART4_IRQHandler,
    (uint32_t)UART5_IRQHandler,
    (uint32_t)TIM6_DAC_IRQHandler,
    (uint32_t)TIM7_IRQHandler,
    (uint32_t)DMA2_Channel1_IRQHandler,
    (uint32_t)DMA2_Channel2_IRQHandler,
    (uint32_t)DMA2_Channel3_IRQHandler,
    (uint32_t)DMA2_Channel4_5_IRQHandler,
};

void Reset_Handler(void) {
    /* Copy initialised data from flash LMA to RAM VMA */
    uint32_t *src = &_etext;
    uint32_t *dst = &_sdata;
    while (dst < &_edata) {
        *dst++ = *src++;
    }

    /* Zero-fill BSS */
    dst = &_sbss;
    while (dst < &_ebss) {
        *dst++ = 0U;
    }

    extern int main(void);
    main();

    for (;;);
}

void Default_Handler(void) {
    for (;;);
}
