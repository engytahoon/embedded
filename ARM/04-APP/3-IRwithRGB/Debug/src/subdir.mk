################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/AFIO_prog.c \
../src/EXTI_program.c \
../src/GPIO.c \
../src/IRREMOTE_program.c \
../src/NVIC_programe.c \
../src/RCC_program.c \
../src/SYSTIC_program.c \
../src/main.c 

OBJS += \
./src/AFIO_prog.o \
./src/EXTI_program.o \
./src/GPIO.o \
./src/IRREMOTE_program.o \
./src/NVIC_programe.o \
./src/RCC_program.o \
./src/SYSTIC_program.o \
./src/main.o 

C_DEPS += \
./src/AFIO_prog.d \
./src/EXTI_program.d \
./src/GPIO.d \
./src/IRREMOTE_program.d \
./src/NVIC_programe.d \
./src/RCC_program.d \
./src/SYSTIC_program.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


