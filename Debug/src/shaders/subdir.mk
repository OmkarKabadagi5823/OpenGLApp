################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
FRAG_SRCS += \
../src/shaders/shader.frag 

VERT_SRCS += \
../src/shaders/shader.vert 

VERT_DEPS += \
./src/shaders/shader.d 

OBJS += \
./src/shaders/shader.o 

FRAG_DEPS += \
./src/shaders/shader.d 


# Each subdirectory must supply rules for building sources it contributes
src/shaders/%.o: ../src/shaders/%.frag src/shaders/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/omkar/eclipse-workspace/OpenGLAppRefactored/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/shaders/%.o: ../src/shaders/%.vert src/shaders/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/omkar/eclipse-workspace/OpenGLAppRefactored/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


