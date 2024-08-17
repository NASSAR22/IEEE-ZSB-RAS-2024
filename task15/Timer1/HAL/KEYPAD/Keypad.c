#include "Keypad.h";
#include "KEYPAD_Config.h"

#include "../../MCAL/DIO/DIO_Interface.h"

u8 KPD_u8_RowsPins[4]={KPD_u8_R1_PIN,KPD_u8_R2_PIN,KPD_u8_R3_PIN,KPD_u8_R4_PIN};
u8 KPD_u8_ColsPins[4]={KPD_u8_C1_PIN,KPD_u8_C2_PIN,KPD_u8_C3_PIN,KPD_u8_C4_PIN};
const u8 KPD_u8_Keys[4][4] = KEY_KEYS;


u8 KPD_u8_GetKey(u8 *Copy_pu8_ReturnKey)
{
    u8 Local_u8_RowCounter, Local_u8_ColCounter, Local_u8_PinVal, Local_u8_Flag = 0;
    *Copy_pu8_ReturnKey = KPD_U8_UNPRESED;

    if (Copy_pu8_ReturnKey != NULL)
    {
        for (Local_u8_RowCounter = 0; Local_u8_RowCounter <= 3; Local_u8_RowCounter++)
        {
        	DIO_u8SetPinValue(KPD_u8_R_PORT, KPD_u8_RowsPins[Local_u8_RowCounter], DIO_u8_LOW);

            for (Local_u8_ColCounter = 0; Local_u8_ColCounter <= 3; Local_u8_ColCounter++)
            {
            	DIO_u8GetPinValue(KPD_u8_C_PORT, KPD_u8_ColsPins[Local_u8_ColCounter], &Local_u8_PinVal);

                if (Local_u8_PinVal == DIO_u8_LOW)
                {
                    _delay_ms(20);
                    DIO_u8GetPinValue(KPD_u8_C_PORT, KPD_u8_ColsPins[Local_u8_ColCounter], &Local_u8_PinVal);

                    while (Local_u8_PinVal == DIO_u8_LOW)
                    {
                    	DIO_u8GetPinValue(KPD_u8_C_PORT, KPD_u8_ColsPins[Local_u8_ColCounter], &Local_u8_PinVal);
                    }

                    *Copy_pu8_ReturnKey = KPD_u8_Keys[Local_u8_RowCounter][Local_u8_ColCounter];
                    Local_u8_Flag = 1;
                    break;
                }
            }

            DIO_u8SetPinValue(KPD_u8_R_PORT, KPD_u8_RowsPins[Local_u8_RowCounter], DIO_u8_HIGH);

            if (Local_u8_Flag)
            {
                break;
            }
        }
    }
    else
    {
        return STD_TYPES_NOK;
    }

    return STD_TYPES_OK;
}



u8 KeyPad_u8_Init()
{
	for(int i = 0 ; i<=3 ; i++)
	{
		// Set columns as outputs and enable pull-up resistors
		DIO_u8SetPinDirection(KPD_u8_C_PORT, KPD_u8_ColsPins[i], DIO_u8_INPUT);
		DIO_u8SetPinValue(KPD_u8_C_PORT, KPD_u8_ColsPins[i], DIO_u8_HIGH);

		// Set rows as inputs
		DIO_u8SetPinDirection(KPD_u8_R_PORT,KPD_u8_RowsPins[i], DIO_u8_OUTPUT);
		DIO_u8SetPinValue(KPD_u8_R_PORT, KPD_u8_RowsPins[i], DIO_u8_HIGH);
	}
    return STD_TYPES_OK;
}



/**********************************************************************************************/
/*  Keypad 3x3  */
u8 Keypad_GetPressedKey(){
	u8 Col, Row;
	while (1)
	{
		for (Col = 0; Col < N_Col; Col++)
		{
			Keypad_Port_Dir = (0b00010000 << Col);
			Keypad_Port_Out = ~(0b00010000 << Col);

			for (Row = 0; Row < N_Row; Row++)
			{
				if (BIT_IS_CLEAR(Keypad_Port_In, Row))
				{
					return Keypad_4x3((Row * N_Col) + Col + 1);
				}
			}
		}
	}
}
#if(N_Col == 3)

u8 Keypad_4x3(u8 Num) {
	switch (Num) {
	case 10:
		return '*';
		break;
	case 11:
		return 0;
		break;
	case 12:
		return '#';
	default:
		return Num;
	}
}
#endif
/*************************************************************************/

/* Keypad 4x4  */









