#ifndef F_CPU
#define F_CPU 16000000UL // telling controller crystal frequency(16 Mhz AVR Atmega328p)
#endif

#include <avr/io.h> //header to enable data flow control pins,ports etc
#include <util/delay.h> // enable delay

#define LED 7 // port D pin 7

void init_ports_mcu(){
DDRD=0xFFu; // Set all pins of the PORTD output
PORTD=0x00u; // Set all pins of PORTD low which turns it off
}

// this func re-maps a number from one range to another
int map(int x, int in_min, int in_max, int out_min, int out_max) {
    return (x-in_min) * (out_max-out_min) / (in_max-in_min) + out_min;
}

void ADC_init() {
//Enable ADC
ADCSRA |= (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
//Select requred channel passed as input
ADMUX = (1<<REFS0);
}

uint16_t get_LightLevel(){
_delay_ms(10); // wait for channel to get selected
ADCSRA |=(1<<ADSC); // start ADC conversion by setting ADSC bit. write 1 to ADSC

while(ADCSRA & (1<<ADSC)); // wait for conversion to complete
_delay_ms(10);
return (ADC); // return 10 bit result
}

int main(void) {

init_ports_mcu();
ADC_init();

while (1) {

switch(map(get_LightLevel(),0,1023,0,3)) { // read and map adc value at
case 0:
PORTD &= ~(1<<LED); // led is off
break;
case 1:
PORTD &= ~(1<<LED);// led is off
break;
case 2:
PORTD &= ~(1<<LED);// led is off
break;
case 3:
PORTD = (1<<LED);// led is on
break;
}

}
return (0); // never reached
}














