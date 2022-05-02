################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../app/main.cpp 

CPP_DEPS += \
./app/main.d 

OBJS += \
./app/main.o 


# Each subdirectory must supply rules for building sources it contributes
app/%.o: ../app/%.cpp app/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/omkar/eclipse-workspace-old/OpenGLAppRefactored/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-app

clean-app:
	-$(RM) ./app/main.d ./app/main.o

.PHONY: clean-app

