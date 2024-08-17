#include "../MCAL/ADC/ADC_Interface.h"
#include "../LIB/STD_TYPES.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"

#include "../MCAL/Global_Interrupt/GI_Interface.h"
#include "../HAL/DC_MOTOR/DC_Motor_Interface.h"
#include "../HAL/Stepper/Stepper_Interface.h"
#include "../MCAL/Timer/Timer_Interface.h"

#include "../MCAL/DIO/DIO_Interface.h"

#include<util/delay.h>
#define F_CPU 16000000UL

int main(void){
	u8 count = 0;
	u16 digitalValue, servoValue; 
	u8 ledBrightness;
	DIO_u8SetPinDirection(0, 0, 0);
	DIO_u8SetPinDirection(1, 3, 1);
	DIO_u8SetPinDirection(3, 5, 1);
	
	TIMERS_voidTimer0Init();
	TIMERS_voidTimer1Init();
	ADC_void_Init();
	
	while(1){
		ADC_u8_Get_Digital_ValueSynchNonBlocking(0, &digitalValue);
		ledBrightness = (digitalValue * 255UL) / 1023;
		servoValue = (digitalValue * 1000UL) / 1023;
		TIMERS_voidTIMER0SetCompareMatchValue(ledBrightness);
		TIMERS_voidTIMER1SetCompareMatchValueA(servoValue);
	}
	return 0;
}
