################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/utility/Mesh.cpp \
../src/utility/Shader.cpp \
../src/utility/Window.cpp 

CPP_DEPS += \
./src/utility/Mesh.d \
./src/utility/Shader.d \
./src/utility/Window.d 

OBJS += \
./src/utility/Mesh.o \
./src/utility/Shader.o \
./src/utility/Window.o 


# Each subdirectory must supply rules for building sources it contributes
src/utility/%.o: ../src/utility/%.cpp src/utility/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/omkar/eclipse-workspace-old/OpenGLAppRefactored/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-utility

clean-src-2f-utility:
	-$(RM) ./src/utility/Mesh.d ./src/utility/Mesh.o ./src/utility/Shader.d ./src/utility/Shader.o ./src/utility/Window.d ./src/utility/Window.o

.PHONY: clean-src-2f-utility

