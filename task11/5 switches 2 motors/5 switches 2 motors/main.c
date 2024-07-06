#include <avr/io.h>
#include <util/delay.h>

// Switches
#define STOP_PD PD0
#define GO_FORWARD_PD PD1
#define GO_BACK_PD PD2
#define TURN_LEFT_PD PD3
#define TURN_RIGHT_PD PD4


// Motor driver
#define MOTOR1_PIN1_PB PB0
#define MOTOR1_PIN2_PB PB1
#define MOTOR2_PIN1_PB PB2
#define MOTOR2_PIN2_PB PB3

void setup() {
	DDRD &= ~((1 << STOP_PD) | (1 << GO_FORWARD_PD) | (1 << GO_BACK_PD) | (1 << TURN_LEFT_PD) | (1 << TURN_RIGHT_PD));
	PORTD |= (1 << STOP_PD) | (1 << GO_FORWARD_PD) | (1 << GO_BACK_PD) | (1 << TURN_LEFT_PD) | (1 << TURN_RIGHT_PD);
	DDRB |= (1 << MOTOR1_PIN1_PB) | (1 << MOTOR1_PIN2_PB) | (1 << MOTOR2_PIN1_PB) | (1 << MOTOR2_PIN2_PB);
}

void stopMotors() {
	PORTB &= ~((1 << MOTOR1_PIN1_PB) | (1 << MOTOR1_PIN2_PB) | (1 << MOTOR2_PIN1_PB) | (1 << MOTOR2_PIN2_PB));
}

void goForward() {
	PORTB |= (1 << MOTOR1_PIN1_PB) | (1 << MOTOR2_PIN2_PB);
	PORTB &= ~((1 << MOTOR1_PIN2_PB) | (1 << MOTOR2_PIN1_PB));
}

void goBack() {
	PORTB |= (1 << MOTOR1_PIN2_PB) | (1 << MOTOR2_PIN1_PB);
	PORTB &= ~((1 << MOTOR1_PIN1_PB) | (1 << MOTOR2_PIN2_PB));
}

void turnLeft() {
	PORTB |= (1 << MOTOR1_PIN2_PB) | (1 << MOTOR2_PIN2_PB);
	PORTB &= ~((1 << MOTOR1_PIN1_PB) | (1 << MOTOR2_PIN1_PB));
}

void turnRight() {
	PORTB |= (1 << MOTOR1_PIN1_PB) | (1 << MOTOR2_PIN1_PB);
	PORTB &= ~((1 << MOTOR1_PIN2_PB) | (1 << MOTOR2_PIN2_PB));	
}

int main(void) {
	setup();

	while (1) {
		if (!(PIND & (1 << STOP_PD))) {
			stopMotors();
			} else if (!(PIND & (1 << GO_FORWARD_PD))) {
			goForward();
			} else if (!(PIND & (1 << GO_BACK_PD))) {
			goBack();
			} else if (!(PIND & (1 << TURN_LEFT_PD))) {
			turnLeft();
			} else if (!(PIND & (1 << TURN_RIGHT_PD))) {
			turnRight();
			} else {
			stopMotors();
		}
		_delay_ms(100);
	}

	return 0;
}