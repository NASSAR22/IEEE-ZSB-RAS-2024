#include "Components/std_types.h"
#include "Components/micro_config.h"
#include "Components/common_macros.h"
#include "Components/initialization.h"
#include "calculator_blocks.h"


	uint8 Flag=StartPoint;/*Contains the state of the program flow*/

int main(void)
{

	InitPeripherals(); /*Initiate the LCD driver*/

    while(1)
    {
		ResetData();
		LCD_clearScreen();
		Flag=StartPoint;
		 while(Flag==StartPoint) GetData(); /*Don't get out until pressing equal sign*/
		 while(Flag==AnalyzePoint) Analyze(); /*Don't get out until separating every thing correctly*/
		 while(Flag==CalculatePoint) Calculate(); /*Don't get out until calculate the value*/
		 while(Flag==DisplayPoint) DisplayResult(); /*Display the result*/
		 	/*If an error is found in one of these stages, the Flag will be sit to "Error point" and will set 
			 to "StartPoint" again in the start of the loop after clearing every thing*/
	}
	
	
}