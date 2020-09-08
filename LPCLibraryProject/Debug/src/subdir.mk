################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/RandomArtFunctions.cpp \
../src/ScratchWork.cpp \
../src/SpellCheck.cpp \
../src/expression.cpp \
../src/function.cpp \
../src/functions.cpp \
../src/helper.cpp \
../src/lex.yy.cpp \
../src/main.cpp \
../src/y.tab.cpp 

OBJS += \
./src/RandomArtFunctions.o \
./src/ScratchWork.o \
./src/SpellCheck.o \
./src/expression.o \
./src/function.o \
./src/functions.o \
./src/helper.o \
./src/lex.yy.o \
./src/main.o \
./src/y.tab.o 

CPP_DEPS += \
./src/RandomArtFunctions.d \
./src/ScratchWork.d \
./src/SpellCheck.d \
./src/expression.d \
./src/function.d \
./src/functions.d \
./src/helper.d \
./src/lex.yy.d \
./src/main.d \
./src/y.tab.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\rogel\Google Drive\eclipse-workspace\LPCLibraryProject\library-includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


