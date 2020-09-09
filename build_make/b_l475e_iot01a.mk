################################################################################
# micro T-Kernel 3.00.01  makefile
################################################################################

GCC := arm-none-eabi-gcc
AS := arm-none-eabi-gcc
LINK := arm-none-eabi-gcc

CFLAGS := -mcpu=cortex-m4 -mthumb -ffreestanding\
    -std=gnu11 \
    -O0 -g3 \
    -MMD -MP \

ASFLAGS := -mcpu=cortex-m4 -mthumb -ffreestanding\
    -x assembler-with-cpp \
    -O0 -g3 \
    -MMD -MP \

LFLAGS := -mcpu=cortex-m4 -mthumb -ffreestanding \
    -nostartfiles \
    -O0 -g3 \

LNKFILE := "../etc/linker/b_l475e_iot01a/tkernel_map.ld"

-include mtkernel_3/lib/libtm/sysdepend/b_l475e_iot01a/subdir.mk
-include mtkernel_3/lib/libtk/sysdepend/cpu/stm32l475/subdir.mk
-include mtkernel_3/lib/libtk/sysdepend/cpu/core/acm4/subdir.mk
-include mtkernel_3/kernel/sysdepend/b_l475e_iot01a/subdir.mk
-include mtkernel_3/kernel/sysdepend/cpu/stm32l475/subdir.mk
-include mtkernel_3/kernel/sysdepend/cpu/core/acm4/subdir.mk
