################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Main.cpp \
../src/heartBeat.cpp \
../src/pwmController.cpp \
../src/servoController.cpp \
../src/trackingTest.cpp 

OBJS += \
./src/Main.o \
./src/heartBeat.o \
./src/pwmController.o \
./src/servoController.o \
./src/trackingTest.o 

CPP_DEPS += \
./src/Main.d \
./src/heartBeat.d \
./src/pwmController.d \
./src/servoController.d \
./src/trackingTest.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
<<<<<<< HEAD
	arm-linux-gnueabi-g++ -I/usr/arm-linux-gnueabi/include/c++/4.6.3 -I/usr/local/include/opencv -I/usr/local/include/opencv2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
=======
	arm-linux-gnueabi-g++ -I/usr/arm-linux-gnueabi/include/c++/4.6.3 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
>>>>>>> aee562f62db8749c072a066d3d83f6b458f2ce20
	@echo 'Finished building: $<'
	@echo ' '


