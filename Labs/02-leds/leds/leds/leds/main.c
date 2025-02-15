/***********************************************************************
 * 
 * Alternately toggle two LEDs when a push button is pressed.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
#define LED_GREEN   PB5     // AVR pin where green LED is connected
#define LED_RED     PC0     // AVR pin where red LED is connected
#define BUTTON      PD7     // AVR pin where BUTTON is connected
#define BLINK_DELAY 500
#ifndef F_CPU
# define F_CPU 16000000     // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/sfr_defs.h>

/* Functions ---------------------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle two LEDs when a push button is pressed.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Green LED at port B
    // Set pin as output in Data Direction Register...
    DDRB = DDRB | (1<<LED_GREEN);
    // ...and turn LED off in Data Register
    //PORTB = PORTB & ~(1<<LED_GREEN);  (netreba)

    // Configure the second LED at port C
    // Set pin as output in Data Direction Register...
    DDRC = DDRC | (1<<LED_RED);
    // ...and turn LED off in Data Register
    //PORTC = PORTC & ~(1<<LED_RED); (netreba)

    // Configure Push button at port D and enable internal pull-up resistor
    DDRD = DDRD & ~(1<<BUTTON);
    PORTD = PORTD | (1<<BUTTON);        //pullup ON 
    // Infinite loop
    while (1)
    {
        // Pause several milliseconds
       // _delay_ms(BLINK_DELAY);        
        //PORTC = PORTC ^ (1<<LED_RED);       //LED ON (toogle OFF)
       //PORTB = PORTB ^ (1<<LED_GREEN);     //LED ON (toogle OFF)
        //_delay_ms(BLINK_DELAY);
        //PORTC = PORTC & ~(1<<LED_RED);      //LED OFF (netreba)
       // PORTB = PORTB & ~(1<<LED_GREEN);    //LED OFF (netreba)

        if(bit_is_clear(PIND, PD7))
        {
            _delay_ms(BLINK_DELAY);
            PORTC = PORTC ^ (1<<LED_RED);       //LED ON (toogle OFF)
            PORTB = PORTB ^ (1<<LED_GREEN);     //LED ON (toogle OFF)
        }

    }

    // Will never reach this
    return 0;
}