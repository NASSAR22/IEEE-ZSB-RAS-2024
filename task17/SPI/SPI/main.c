#include <avr/io.h>

#define F_CPU 4000000UL
#include <util/delay.h>

void masterInit(void){
 /*Set MOSI, SCK and SS Output*/
 DDRB=(1<<7)|(1<<5)|(1<<4);
 /*Enable SPI Master set clock rate fck/128 data is 
 sample at falling edge*/
 SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR1)|(1<<SPR0)|(1<<CPHA);
 //SPSR|=(1<<0); 
}

void masterTransmit(char spiData){
 //PORTB&=~(1<<5);
 /*Start the transmission*/
 SPDR=spiData;
 /*Wait for completion*/
 while(!(SPSR&(1<<SPIF)));
 //PORTB&=~(1<<5);
 
}

char masterReceive(void){
 /*Wait for the SPI buffer's full*/
 while(!(SPSR&(1<<SPIF)));
 /*return SPI Buffer*/
 return SPDR;
}

void tc72Init(void){
 PORTB|=(1<<4);
 /*Select Control Register*/
 masterTransmit(0x80);
 /*Select Continuous temperature Conversion*/
 masterTransmit(0x04);
 PORTB&=~(1<<4);
 _delay_ms(150);
}

void displayTemperature(char msb,char lsb){
 char ssd[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,
 0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
 char sign;
 lsb>>=6;

 if(msb&0x80) {
  msb=(~msb)+1;
  sign=1;
  if(lsb!=0) lsb=75/lsb;
 }
 else {
  sign=0;
  lsb*=25;
 }

 PORTD=0x00;
 if(sign==1) PORTC=0x40;
 else if(msb>=100) PORTC=ssd[msb/100];
 else PORTC=0x00;
 PORTD=(1<<0);
 _delay_ms(5);
 
 PORTD=0x00;
 if(msb>=10)
  PORTC=ssd[(msb%100)/10];
 else PORTC=0;
 PORTD=(1<<1);
 _delay_ms(5);

 PORTD=0x00;
 PORTC=ssd[msb%10]|0x80;
 PORTD=(1<<2);
 _delay_ms(5);

 PORTD=0x00;
 PORTC=ssd[lsb/10];
 PORTD=(1<<3);
 _delay_ms(5);

 PORTD=0x00;
 PORTC=ssd[lsb%10];
 PORTD=(1<<4);
 _delay_ms(5);

 PORTD=0x00;
 PORTC=0x63;
 PORTD=(1<<5);
 _delay_ms(5);

 PORTD=0x00;
 PORTC=ssd[12];
 PORTD=(1<<6);
 _delay_ms(5);
}


int main(void)
{
 char msb,lsb;
    DDRC=0xFF;
 DDRD=0xFF;
 DDRA=0xFF;
 masterInit();
 tc72Init();
 _delay_ms(150);
    while (1) 
    {
  
  PORTB|=(1<<4);
  /*Read the MSB*/
  masterTransmit(0x02);
  /*Issue one more clock frame
  to force data out*/
  masterTransmit(0x00);
  PORTB&=~(1<<4);
  
  _delay_ms(1);
  msb=masterReceive();
  
  PORTB|=(1<<4);
  /*Read The LSB*/
  masterTransmit(0x01);
  /*Issue one more clock frame
  to force data out*/
  masterTransmit(0x00);
  PORTB&=~(1<<4);
  
  _delay_ms(1);
  lsb=masterReceive();
  PORTA=lsb;
  displayTemperature(msb,lsb);
    }
}