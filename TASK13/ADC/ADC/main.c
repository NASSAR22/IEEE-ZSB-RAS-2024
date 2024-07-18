#define F_CPU 8000000UL 
#include <avr/io.h>
#include <util/delay.h>

void ADC_init() {
	
	ADCSRA |= (1 << ADPS2) | (1 << ADPS1);
	ADMUX |= (1 << REFS0);
	ADCSRA |= (1 << ADEN);
}

uint16_t ADC_read(uint8_t channel) {
	ADMUX = (ADMUX & 0xF0) | (channel & 0x0F); 
	ADCSRA |= (1 << ADSC); 
	while (ADCSRA & (1 << ADSC)); 
	return ADC; 
}

void LED_init() {
	// Set LED pins as output
	DDRD = 0xFF; 
}

void LED_control(uint8_t num_leds) {
	
	PORTD = (1 << num_leds) - 1; 
}

int main(void) {
	uint16_t pot_value;
	uint8_t num_leds;

	ADC_init();
	LED_init();

	while (1) {
		pot_value = ADC_read(0); 
		num_leds = (pot_value * 8) / 1023;

		LED_control(num_leds);

		_delay_ms(100); 
	}

	return 0;
}
