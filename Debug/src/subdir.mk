################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Cars.cpp \
../src/Functions.cpp \
../src/Main.cpp \
../src/Nodes.cpp \
../src/Routes.cpp \
../src/SecureInput.cpp 

OBJS += \
./src/Cars.o \
./src/Functions.o \
./src/Main.o \
./src/Nodes.o \
./src/Routes.o \
./src/SecureInput.o 

CPP_DEPS += \
./src/Cars.d \
./src/Functions.d \
./src/Main.d \
./src/Nodes.d \
./src/Routes.d \
./src/SecureInput.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"D:\C++ Eclipse workspace\Taxi\Headers" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


