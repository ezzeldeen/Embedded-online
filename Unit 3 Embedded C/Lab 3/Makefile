#@copyright : Ezz
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
Project_name=U3_L4_cortex_M4

all: $(Project_name).bin
	@echo "====================== Build is Done ======================"

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -c  $(INCS) $< -o $@

#startup.o: startup.s 
#	$(CC)as.exe $(CFLAGS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=map_file.map
	cp $(Project_name).elf $(Project_name).axf
	
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean: 
	rm *.elf *.bin

clean_all: 
	rm *.o *.elf *.bin