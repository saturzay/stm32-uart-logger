CC      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy

CFLAGS  = -mcpu=cortex-m3 -mthumb \
          -O2 -g \
          -ffreestanding -nostdlib \
          -ffunction-sections -fdata-sections \
          -Wall -Wextra

LDFLAGS = -T link.ld -nostdlib -Wl,--gc-sections

SRCS   = startup.c uart.c main.c
OBJS   = $(SRCS:.c=.o)
TARGET = firmware.elf

.PHONY: all build run clean

all: build

build: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

run: build
	qemu-system-arm \
	    -machine stm32vldiscovery \
	    -nographic \
	    -kernel $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
