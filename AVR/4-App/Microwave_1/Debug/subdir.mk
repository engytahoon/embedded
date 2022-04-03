################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DELAY.c \
../DIO_program.c \
../EXTI_program.c \
../SW_Timer.c \
../TIM2_Prog.c \
../TIM_Prog.c \
../header.c \
../keybad_prog.c \
../lcd_prog.c \
../main.c \
../motor.c \
../serves.c 

OBJS += \
./DELAY.o \
./DIO_program.o \
./EXTI_program.o \
./SW_Timer.o \
./TIM2_Prog.o \
./TIM_Prog.o \
./header.o \
./keybad_prog.o \
./lcd_prog.o \
./main.o \
./motor.o \
./serves.o 

C_DEPS += \
./DELAY.d \
./DIO_program.d \
./EXTI_program.d \
./SW_Timer.d \
./TIM2_Prog.d \
./TIM_Prog.d \
./header.d \
./keybad_prog.d \
./lcd_prog.d \
./main.d \
./motor.d \
./serves.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


