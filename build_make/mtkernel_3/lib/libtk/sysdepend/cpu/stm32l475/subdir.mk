################################################################################
# micro T-Kernel 3.00.01  makefile
################################################################################

OBJS += \
./mtkernel_3/lib/libtk/sysdepend/cpu/stm32l475/int_stm32l475.o 

C_DEPS += \
./mtkernel_3/lib/libtk/sysdepend/cpu/stm32l475/int_stm32l475.d 

mtkernel_3/lib/libtk/sysdepend/cpu/stm32l475/%.o: ../lib/libtk/sysdepend/cpu/stm32l475/%.c
	@echo 'Building file: $<'
	$(GCC) $(CFLAGS) -D$(TARGET) $(INCPATH) -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


