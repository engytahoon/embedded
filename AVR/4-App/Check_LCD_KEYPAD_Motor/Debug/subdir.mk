################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_program.c \
../DELAY.c \
../DIO_program.c \
../Keypad_program.c \
../main.c \
../motor.c 

OBJS += \
./CLCD_program.o \
./DELAY.o \
./DIO_program.o \
./Keypad_program.o \
./main.o \
./motor.o 

C_DEPS += \
./CLCD_program.d \
./DELAY.d \
./DIO_program.d \
./Keypad_program.d \
./main.d \
./motor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


