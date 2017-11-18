/*
 * File:   pictest.c
 * Author: paul
 *
 * Created on 18 November 2017, 16:18
 */

// CONFIG
#pragma config FOSC = INTRCIO   // Oscillator Selection bits (INTOSC oscillator: I/O function on GP4/OSC2/CLKOUT pin, I/O function on GP5/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-Up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = OFF      // GP3/MCLR pin function select (GP3/MCLR pin function is digital I/O, MCLR internally tied to VDD)
#pragma config BOREN = ON       // Brown-out Detect Enable bit (BOD enabled)
#pragma config CP = OFF         // Code Protection bit (Program Memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)


#include <xc.h>

#define LED GP0
#define _XTAL_FREQ 4000000

void main(void) {
    ANSEL = 0x00;
    ADCON0 = 0x00;
    CMCON = 0x07;
    VRCON = 0x00;
    TRISIO = 0x08;
    GPIO = 0x00;
    
    while(1) {
        __delay_ms(500);
        LED = 0;
        __delay_ms(500);
        LED = 1;
    }
}
