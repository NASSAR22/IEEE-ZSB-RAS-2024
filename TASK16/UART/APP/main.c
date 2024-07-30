#include "APP_Includes.h"

int main(void){
	
	u8 RecieveData;
	DIO_voidInit();
	UART_Init();
	UART_SendString("Enter R | Y | G | S(To Stop) : \n\r");
	while(1){
		UART_u8Recieve1ByteData(&RecieveData);

		if(RecieveData == 'R'){
			DIO_u8SetPinValue(0, 0, 1);
		}
		
		else if(RecieveData == 'Y'){
			DIO_u8SetPinValue(0, 1, 1);
		}
		
		else if(RecieveData == 'G'){
			DIO_u8SetPinValue(0, 2, 1);
		}
		
		else if(RecieveData == 'S'){
			DIO_u8SetPinValue(0, 0, 0);
			DIO_u8SetPinValue(0, 1, 0);
			DIO_u8SetPinValue(0, 2, 0);
		}
	}
	return 0;
}
