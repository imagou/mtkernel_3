################################################################################
# micro T-Kernel 3.00.01  makefile
################################################################################

OBJS += \
./mtkernel_3/kernel/sysdepend/cpu/stm32l475/cpu_clock.o 

C_DEPS += \
./mtkernel_3/kernel/sysdepend/cpu/stm32l475/cpu_clock.d 

mtkernel_3/kernel/sysdepend/cpu/stm32l475/%.o: ../kernel/sysdepend/cpu/stm32l475/%.c
	@echo 'Building file: $<'
	$(GCC) $(CFLAGS) -D$(TARGET) $(INCPATH) -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


