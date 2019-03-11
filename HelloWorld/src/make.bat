PATH=C:\devkitadv-r5-beta-3\bin;%PATH%
REM gcc -Ofast -mcpu=arm7tdmi -mtune=arm7tdmi -marm -c color.c
REM gcc -Ofast -mcpu=arm7tdmi -mtune=arm7tdmi -marm -c prof.c
REM gcc -Ofast -mcpu=arm7tdmi -mtune=arm7tdmi -marm -c matrizalturas.c
REM gcc -Ofast -mcpu=arm7tdmi -mtune=arm7tdmi -marm -c matrizx.c
gcc -Ofast -mcpu=arm7tdmi -mtune=arm7tdmi -marm -c ex.c
REM gcc -mcpu=arm7tdmi -mtune=arm7tdmi -marm -mthumb -mthumb-interwork -c ex.c
gcc -specs=gba.specs ex.o color.o prof.o matrizalturas.o matrizx.o -o world_demo.elf
objcopy -O binary world_demo.elf world_demo.gba
pause
