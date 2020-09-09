################################################################################
# micro T-Kernel 3.00.01  makefile
################################################################################

OBJS += \
./mtkernel_3/kernel/sysdepend/b_l475e_iot01a/devinit.o \
./mtkernel_3/kernel/sysdepend/b_l475e_iot01a/hw_setting.o \
./mtkernel_3/kernel/sysdepend/b_l475e_iot01a/power_save.o 

C_DEPS += \
./mtkernel_3/kernel/sysdepend/b_l475e_iot01a/devinit.d \
./mtkernel_3/kernel/sysdepend/b_l475e_iot01a/hw_setting.d \
./mtkernel_3/kernel/sysdepend/b_l475e_iot01a/power_save.d 


mtkernel_3/kernel/sysdepend/b_l475e_iot01a/%.o: ../kernel/sysdepend/b_l475e_iot01a/%.c
	@echo 'Building file: $<'
	$(GCC) $(CFLAGS) -D$(TARGET) $(INCPATH) -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
