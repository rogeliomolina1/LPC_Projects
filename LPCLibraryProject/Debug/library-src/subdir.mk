################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../library-src/lexicon.cpp \
../library-src/lpclib_convert.cpp \
../library-src/lpclib_graphics.cpp \
../library-src/scanner.cpp 

OBJS += \
./library-src/lexicon.o \
./library-src/lpclib_convert.o \
./library-src/lpclib_graphics.o \
./library-src/scanner.o 

CPP_DEPS += \
./library-src/lexicon.d \
./library-src/lpclib_convert.d \
./library-src/lpclib_graphics.d \
./library-src/scanner.d 


# Each subdirectory must supply rules for building sources it contributes
library-src/%.o: ../library-src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"C:\Users\rogel\Google Drive\eclipse-workspace\LPCLibraryProject\library-includes" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


