#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define RED_LED_PIN      PB0
#define YELLOW_LED_PIN   PB1
#define GREEN_LED_PIN    PB2
#define SEGMENT_PORT_1   PORTC
#define SEGMENT_DDR_1    DDRC
#define SEGMENT_PORT_2   PORTD
#define SEGMENT_DDR_2    DDRD
#define SEGMENT_D1_PIN   PC0
#define SEGMENT_D2_PIN   PD0

volatile uint8_t ones_digit = 0;
volatile uint8_t tens_digit = 0;
volatile uint16_t display_counter = 1;  // Counter for displaying numbers
volatile uint8_t current_led = 0;       // Current LED state: 1 for Red, 2 for Yellow, 3 for Green

const uint8_t digitPatterns[10] = {
	0b00111111,  // 0
	0b00000110,  // 1
	0b01011011,  // 2
	0b01001111,  // 3
	0b01100110,  // 4
	0b01101101,  // 5
	0b01111101,  // 6
	0b00000111,  // 7
	0b01111111,  // 8
	0b01101111   // 9
};

void initPorts() {
	DDRB |= (1 << RED_LED_PIN) | (1 << YELLOW_LED_PIN) | (1 << GREEN_LED_PIN);
	SEGMENT_DDR_1 |= (1 << SEGMENT_D1_PIN) | (1 << PC1) | (1 << PC2) | (1 << PC3) | (1 << PC4) | (1 << PC5) | (1 << PC6);
	SEGMENT_DDR_2 |= (1 << SEGMENT_D2_PIN) | (1 << PD1) | (1 << PD2) | (1 << PD3) | (1 << PD4) | (1 << PD5) | (1 << PD6);
	SEGMENT_PORT_1 = 0x00;
	SEGMENT_PORT_2 = 0x00;
}

void initTimer() {
	TCCR0 = (1 << CS02) | (1 << CS00);  
	TIMSK |= (1 << TOIE0);             
	sei();                              
}

void displayNumber(uint8_t ones, uint8_t tens) {
	SEGMENT_PORT_1 = digitPatterns[ones];
	SEGMENT_PORT_1 |= (1 << SEGMENT_D1_PIN);
	_delay_ms(5);
	SEGMENT_PORT_1 &= ~(1 << SEGMENT_D1_PIN);

	SEGMENT_PORT_2 = digitPatterns[tens];
	SEGMENT_PORT_2 |= (1 << SEGMENT_D2_PIN);
	_delay_ms(5);
	SEGMENT_PORT_2 &= ~(1 << SEGMENT_D2_PIN);
}

void setLights(uint8_t red, uint8_t yellow, uint8_t green) {
	PORTB &= ~((1 << RED_LED_PIN) | (1 << YELLOW_LED_PIN) | (1 << GREEN_LED_PIN));
	PORTB |= (red << RED_LED_PIN) | (yellow << YELLOW_LED_PIN) | (green << GREEN_LED_PIN);
}

int main() {
	initPorts();
	initTimer();

	while (1) {
		// Red light sequence: 01 to 15 seconds
		current_led = 1;
		setLights(1, 0, 0);  // Red light
		for (display_counter = 1; display_counter <= 15; display_counter++) {
			ones_digit = display_counter % 10;
			tens_digit = display_counter / 10;
			displayNumber(ones_digit, tens_digit);
			_delay_ms(1000);  // 1 second delay between each number
		}

		// Yellow light sequence: 01 to 05 seconds
		current_led = 2;
		setLights(0, 1, 0);  // Yellow light
		for (display_counter = 1; display_counter <= 5; display_counter++) {
			ones_digit = display_counter % 10;
			tens_digit = display_counter / 10;
			displayNumber(ones_digit, tens_digit);
			_delay_ms(1000);  // 1 second delay between each number
		}

		// Green light sequence: 01 to 10 seconds
		current_led = 3;
		setLights(0, 0, 1);  // Green light
		for (display_counter = 1; display_counter <= 10; display_counter++) {
			ones_digit = display_counter % 10;
			tens_digit = display_counter / 10;
			displayNumber(ones_digit, tens_digit);
			_delay_ms(1000);  // 1 second delay between each number
		}
	}

	return 0;
}

ISR(TIMER0_OVF_vect) {
	// This interrupt handler is not used in this version.
}
