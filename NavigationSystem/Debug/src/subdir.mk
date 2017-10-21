################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CGPSSensor.cpp \
../src/CNavigationSystem.cpp \
../src/CPOI.cpp \
../src/CPoiDatabase.cpp \
../src/CRoute.cpp \
../src/CWaypoint.cpp \
../src/main.cpp 

OBJS += \
./src/CGPSSensor.o \
./src/CNavigationSystem.o \
./src/CPOI.o \
./src/CPoiDatabase.o \
./src/CRoute.o \
./src/CWaypoint.o \
./src/main.o 

CPP_DEPS += \
./src/CGPSSensor.d \
./src/CNavigationSystem.d \
./src/CPOI.d \
./src/CPoiDatabase.d \
./src/CRoute.d \
./src/CWaypoint.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


