#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t seconds = 0; // Variable to hold seconds count
volatile uint8_t tens = 0;    // Tens digit of seconds count
volatile uint8_t ones = 0;    // Ones digit of seconds count

// Function to initialize TIMER0
void timer0_init() {
	// Set Timer/Counter Control Register TCCR0
	TCCR0 = (1 << CS02) | (1 << CS00); // Prescaler of 1024
	
	// Enable overflow interrupt for TIMER0
	TIMSK |= (1 << TOIE0);
	
	// Initialize counter
	TCNT0 = 0;
	
	// Enable global interrupts
	sei();
}

// Interrupt service routine for TIMER0 overflow
ISR(TIMER0_OVF_vect) {
	// Check if seconds reached 99, stop further increment
	if (seconds < 99) {
		seconds++;
	}
	
	// Update tens and ones digits
	tens = seconds / 10;
	ones = seconds % 10;
}

// Function to initialize 7-segment display
void seg7_init() {
	// Initialize Port D for 7-segment display
	DDRD = 0xFF; // All pins as output
}

// Function to display seconds on 7-segment display
void seg7_display(uint8_t tens, uint8_t ones) {
	// 7-segment display patterns for digits 0-9
	uint8_t segments[] = {
		0b11000000, // 0
		0b11111001, // 1
		0b10100100, // 2
		0b10110000, // 3
		0b10011001, // 4
		0b10010010, // 5
		0b10000010, // 6
		0b11111000, // 7
		0b10000000, // 8
		0b10010000  // 9
	};
	
	// Display tens digit on left segment (PD7-PD4) and units digit on right segment (PD3-PD0)
	PORTD = (segments[ones] << 4) | segments[tens];
}

int main() {
	// Initialize Port C, Pin 0 for LED
	DDRC |= (1 << PC0);
	
	// Initialize 7-segment display
	seg7_init();
	
	// Initialize Timer0
	timer0_init();
	
	while (1) {
		// Toggle LED every second
		PORTC ^= (1 << PC0);
		
		// Display seconds on 7-segment display
		seg7_display(tens, ones); // Display TX (where T is tens digit and X is ones digit)
		
		// Check if seconds reached 99, stop the loop
		if (seconds >= 99) {
			break;
		}
		
		// Delay to approximate 1 second
		_delay_ms(1000);
	}
	
	// Freeze at 99 on 7-segment display
	seg7_display(9, 9); // Display 99
	
	while (1) {
		// Infinite loop to hold the display at 99
	}
	
	return 0;
}
