################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/my\ project.c 

C_DEPS += \
./src/my\ project.d 

OBJS += \
./src/my\ project.o 


# Each subdirectory must supply rules for building sources it contributes
src/my\ project.o: ../src/my\ project.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/my project.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/my\ project.d ./src/my\ project.o

.PHONY: clean-src

