################################################################################
# micro T-Kernel 3.00.01  makefile
################################################################################

OBJS += \
./mtkernel_3/lib/libtk/sysdepend/cpu/core/acm4/int_acm4.o \
./mtkernel_3/lib/libtk/sysdepend/cpu/core/acm4/wusec_acm4.o 

C_DEPS += \
./mtkernel_3/lib/libtk/sysdepend/cpu/core/acm4/int_acm4.d \
./mtkernel_3/lib/libtk/sysdepend/cpu/core/acm4/wusec_acm4.d 

mtkernel_3/lib/libtk/sysdepend/cpu/core/acm4/%.o: ../lib/libtk/sysdepend/cpu/core/acm4/%.c
	@echo 'Building file: $<'
	$(GCC) $(CFLAGS) -D$(TARGET) $(INCPATH) -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


