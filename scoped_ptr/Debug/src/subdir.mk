################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/scoped_ptr.cpp 

OBJS += \
./src/scoped_ptr.o 

CPP_DEPS += \
./src/scoped_ptr.d 


# Each subdirectory must supply rules for building sources it contributes
src/scoped_ptr.o: ../src/scoped_ptr.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/scoped_ptr.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


