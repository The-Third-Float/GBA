CC=arm-agb-elf-gcc
OBJCOPY=arm-agb-elf-objcopy
NAME=main

all: main-bin

main-bin: main-elf
	$(OBJCOPY) -v -O binary $(NAME).elf $(NAME).bin

main-elf: 
	$(CC) -lm -o $(NAME).elf $(NAME).c

clean:
	rm -f *.elf *.bin
