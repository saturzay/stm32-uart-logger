# STM32 UART Logger - Spec

## Target
Virtual STM32VL Discovery (Cortex-M3) running in QEMU

## In scope
- Bare-metal C (no RTOS, no HAL library)
- UART0 output visible in terminal via qemu -nographic
- SysTick timer interrupt generating a tick counter
- main loop logs "tick N: hello from firmware" every ~1 second
- Linker script placing code in flash (0x08000000), data in RAM (0x20000000)

## Out of scope
- Receiving UART input
- Multiple peripherals
- Any OS or scheduler

## Success criteria
Running `make run` starts QEMU and prints timestamped messages to terminal
Ctrl-A then X exits QEMU cleanly

## Key constraints
- Direct register manipulation only — no STM32 HAL
- Must compile with arm-none-eabi-gcc