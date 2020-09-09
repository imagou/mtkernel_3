################################################################################
# micro T-Kernel 3.00.01  makefile
################################################################################

OBJS += \
./mtkernel_3/lib/libtm/sysdepend/b_l475e_iot01a/tm_com.o 

C_DEPS += \
./mtkernel_3/lib/libtm/sysdepend/b_l475e_iot01a/tm_com.d 

mtkernel_3/lib/libtm/sysdepend/b_l475e_iot01a/%.o: ../lib/libtm/sysdepend/b_l475e_iot01a/%.c
	@echo 'Building file: $<'
	$(GCC) $(CFLAGS) -D$(TARGET) $(INCPATH) -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


