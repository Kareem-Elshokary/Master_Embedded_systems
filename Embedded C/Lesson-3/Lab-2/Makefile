CC=arm-none-eabi-
CFLAGS=-g -mcpu=cortex-m4 -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name = Cortex_m3

all: $(Project_name).bin
	@echo "-----Build is done-----"

#startup
%.o: %.s
	$ (CC)as.exe  $ (CFLAGS) $< -o $@

#fiels
%.o: %.c
	$(CC)gcc.exe  -c $(CFLAGS) $(INCS) $< -o $@

#linker
$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

#Binary
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@