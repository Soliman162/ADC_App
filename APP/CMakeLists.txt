CMAKE_MINIMUM_REQUIRED(VERSION 3.22)

PROJECT(ADC_APPLICATION)

set(CMAKE_GENERATOR CACHE STRING "Unix Makefiles")
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CXX_COMPILER avr-g++ CACHE STRING "C++ compiler" FORCE)
set(CMAKE_C_COMPILER avr-gcc CACHE STRING "C compiler" FORCE)
set(CMAKE_OBJCOPY      avr-objcopy CACHE STRING "avr-objcopy" FORCE)

set(CMAKE_C_FLAGS "-mmcu=atmega32 -O1 -DF_CPU=8000000UL")

add_executable( ${PROJECT_NAME}.elf 
                            ${CMAKE_CURRENT_SOURCE_DIR}/main.c

                            ${CMAKE_CURRENT_SOURCE_DIR}/../HAL/LED/LED_program.c
                            ${CMAKE_CURRENT_SOURCE_DIR}/../HAL/LM35/LM35_program.c
                            ${CMAKE_CURRENT_SOURCE_DIR}/../HAL/CLCD/CLCD_program.c

                            ${CMAKE_CURRENT_SOURCE_DIR}/../MCAL/DIO/DIO_program.c
                            ${CMAKE_CURRENT_SOURCE_DIR}/../MCAL/ADC/ADC_program.c
                            ${CMAKE_CURRENT_SOURCE_DIR}/../MCAL/Timer1/TIMER1_program.c
)  
target_include_directories( ${PROJECT_NAME}.elf PUBLIC
                            
                            ${CMAKE_CURRENT_SOURCE_DIR}/../LIB

                            ${CMAKE_CURRENT_SOURCE_DIR}/../MCAL/DIO
                            ${CMAKE_CURRENT_SOURCE_DIR}/../MCAL/ADC
                            ${CMAKE_CURRENT_SOURCE_DIR}/../MCAL/Timer1

                            ${CMAKE_CURRENT_SOURCE_DIR}/../HAL/LED
                            ${CMAKE_CURRENT_SOURCE_DIR}/../HAL/LM35
                            ${CMAKE_CURRENT_SOURCE_DIR}/../HAL/LDR
                            ${CMAKE_CURRENT_SOURCE_DIR}/../HAL/CLCD

)         
add_custom_target(flash ALL
                DEPENDS ${PROJECT_NAME}.elf
                COMMAND avr-objcopy -j .text -j .data -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
                ) 
                
add_custom_target(burn 
                DEPENDS flash 
                COMMAND  avrdude -c usbasp -p m32 -B 0.5 -U flash:w:"${PROJECT_NAME}.hex":a 
)

