/*
 * File:   pictest.c
 * Purpose: Practice programming PIC chips using MPLAB X environment and PicKit3 programmer.
 * Code works with pic12F675 chip. 
 * Author: paul
 *
 * Created on 18 November 2017, 16:18
 */

// CONFIG
// Important to set chip to use internal oscillator
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-Up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)

// Using XC compiler
#include <xc.h>

// Define which pin to use to blink LED
#define LED GP0

// Must define the oscillator frequency (4MHz) to use functions like __delay_ms
// Can be found in data sheet under "Oscillator Configurations"
#define _XTAL_FREQ 4000000

void main(void) {
    ANSEL = 0x00;   // Set ports as digital I/O, not analog input
    ADCON0 = 0x00;  // Shut off A/D converter
    CMCON = 0x07;   // Shut off Comparator
    VRCON = 0x00;   // Shut off Voltage Reference
    TRISIO = 0x08;  // GP3 input, reset all output
    GPIO = 0x00;    // Make all pins 0
    
    while(1) {
        __delay_ms(500);
        LED = 0;
        __delay_ms(500);
        LED = 1;
    }
}
