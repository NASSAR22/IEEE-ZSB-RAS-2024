/*
 * calculator_blocks.h
 *
 * Created: 9/17/2015 5:22:01 PM
 *  Author: Yahia
 */ 


#ifndef CALCULATOR_BLOCKS_H_
#define CALCULATOR_BLOCKS_H_

#include "Components/std_types.h"
#include "Components/micro_config.h"
#include "Components/common_macros.h"
#include "Components/lcd.h"
#include "Components/keypad.h"
/*Replace these includes with your own library*/
#include "math.h"

/*The limits on the inputs which you are set*/
#define MaxNumberOfDigits 16
#define MaxNumberOfOperands 12
#define MaxNumberOfOperations MaxNumberOfOperands-1

#define IsOperation(n) ((n=='*')||(n=='+')||(n=='-')||(n=='%'))

enum StageFlag{Reset,StartPoint,AnalyzePoint,CalculatePoint,DisplayPoint,ErrorPoint};
enum keys{EnterKey=13,EqualKey= '=' ,Numberkey,OperationKey};
enum Errors{ExcessedMaxNumberOfdigits,InvalidInput,OutofRange};	

extern uint8 Flag;

extern uint32 powerOf(uint8 x,uint8 y); /*Used With ConvertToInt64()*/
void ResetData(); /*To get all the globel variables in .c file set to zero when doing new operation*/
void GetData(); /*Get the data from the keypad until pressing "equal key"*/
void SynchronousDisplay(uint8 data); /*To display what you type in the LCD while storing the inputs*/
void Analyze(); /*To get the operands seperated from the operation to be able to know the operations which i am going to use*/
sint64 ConvertToInt64(uint8 * ptr,uint8 len); /*Converting series of seperate digits into a single number (1,1,5)=>115 */
void ThrowException(uint8 *msg);/*Throw error message on LCD when error found*/
void Calculate(); /*Do the math*/
void DisplayResult();
#endif /* CALCULATOR_BLOCKS_H_ */