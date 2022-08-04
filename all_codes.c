#include <mega32.h>
#include <stdio.h>
#include <delay.h>
#define SET_BIT(reg,bit)    reg|=(1<<bit)
#define CLR_BIT(reg,bit)    reg&=(~(1<<bit))

int IC_74914(void){
 DDRA= 0xBF;
 DDRB= 0xF5;
 DDRC= 0x7F;    // 0111 1111
 DDRD= 0xAF;     
  CLR_BIT(DDRD,3);

       delay_ms(100); 
       
 PORTD.7=0;  //GND
 PORTC.5=1;  //VCC
 
  
    PORTA.5 = PORTA.7 = PORTD.5 = PORTC.6 = PORTB.0 = PORTB.2 = 0;
       delay_ms(10);
    if(PINA.6 & PIND.4 & PIND.6 & PINB.1 & PINB.3 & PINC.7 == 0) return (0);
    
    PORTA.5 = PORTA.7 = PORTD.5 = PORTC.6 = PORTB.0 = PORTB.2 = 1; 
          delay_ms(10);

    if(PINA.6 | PIND.4 | PIND.6 | PINB.1 | PINB.3 | PINC.7 !=0 ) return (0);
     delay_ms(10);

  return(1);                                                                         
 }

int IC_4001(void){
    DDRA=0x7F;         
    DDRB=0xFC;//11111001
    DDRC=0xFF;
    DDRD=0xEF;
        CLR_BIT(DDRD,3);

  
  PORTC.5=1;   //VCC
  PORTD.7=0;   //GND

      //00
    PORTA.5=0; PORTA.6=0; 
    PORTD.5=0; PORTD.6=0;
    PORTB.2=0; PORTB.3=0;
    PORTC.6=0; PORTC.7=0;
    if(PINA.7& PIND.4& PINB.1 & PINB.0== 0) return (0);   

      //01
     PORTA.5=0; PORTA.6=1; 
    PORTD.5=0; PORTD.6=1;
    PORTB.2=0; PORTB.3=1;
    PORTC.6=0; PORTC.7=1;
    if(PINA.7| PIND.4| PINB.1 | PINB.0 == 1) return (0);   
     
     //10
     PORTA.5=1; PORTA.6=0; 
    PORTD.5=1; PORTD.6=0;
    PORTB.2=1; PORTB.3=0;
    PORTC.6=1; PORTC.7=0;
if(PINA.7| PIND.4| PINB.1 | PINB.0 == 1) return (0);   

     //11
    PORTA.5=1; PORTA.6=1; 
    PORTD.5=1; PORTD.6=1;
    PORTB.2=1; PORTB.3=1;
    PORTC.6=1; PORTC.7=1;
if(PINA.7| PIND.4| PINB.1 | PINB.0 == 1) return (0);   

    return (1);
}

int IC_74832(void){
  DDRA= 0x6f;
 DDRB= 0xf6;
 DDRC= 0xdf;
 DDRD= 0xbf;
             delay_ms(100); 
             
    CLR_BIT(DDRD,3);
    
 PORTD.7=0;  //GND
 PORTC.2=1;  //VCC
                                  

   
    

    PORTA.2 = PORTA.5 = PORTD.4 = PORTB.1 = PORTC.6 = PORTC.3 = 1;
    PORTA.3 = PORTA.6 = PORTD.5 = PORTB.2 = PORTC.7 = PORTC.4 = 1;  
    if(PINA.4 & PINA.7 & PIND.6 & PINB.3 & PINB.0 & PINC.5 !=1) return (0);
    
      PORTA.2 = PORTA.5 = PORTD.4 = PORTB.1 = PORTC.6 = PORTC.3 = 0;
    PORTA.3 = PORTA.6 = PORTD.5 = PORTB.2 = PORTC.7 = PORTC.4 = 0; 
    
    if(PINA.4 | PINA.7 | PIND.6 | PINB.3 | PINB.0 | PINC.5 ==1) return (0); 
    
     PORTA.2 = PORTA.5 = PORTD.4 = PORTB.1 = PORTC.6 = PORTC.3 = 1;
    PORTA.3 = PORTA.6 = PORTD.5 = PORTB.2 = PORTC.7 = PORTC.4 = 0;
    if(PINA.4 & PINA.7 & PIND.6 & PINB.3 & PINB.0 & PINC.5 !=1) return (0);
   

    PORTA.2 = PORTA.5 = PORTD.4 = PORTB.1 = PORTC.6 = PORTC.3 = 0;
    PORTA.3 = PORTA.6 = PORTD.5 = PORTB.2 = PORTC.7 = PORTC.4 = 1;   
    if(PINA.4 & PINA.7 & PIND.6 & PINB.3 & PINB.0 & PINC.5 !=1) return (0);
    
    return(1);                                
                                                                                       
}

int IC_4000(void){
    DDRA=0xFF;       //input->0  output->1  
    DDRB=0xF9;//11111001
    DDRC=0xFF;
    DDRD=0xBF;  
    
       CLR_BIT(DDRD,3);

  
  PORTC.5=1;   //VCC
  PORTD.7=0;   //GND      
  
      //000
    PORTA.7=0; PORTD.4=0; PORTD.5=0; 
    PORTC.6=0; PORTC.7=0; PORTB.0=0;
        PORTB.3=0;

    if(PIND.6 & PINB.1 & PINB.2 == 0) return (0);   
      //001
     PORTA.7=0; PORTD.4=0; PORTD.5=1; 
    PORTC.6=0; PORTC.7=0; PORTB.0=1;     PORTB.3=1;

    if(PIND.6 | PINB.1 |PINB.2 ==1) return (0);  
      //010
     PORTA.7=0; PORTD.4=1; PORTD.5=0; 
    PORTC.6=0; PORTC.7=1; PORTB.0=0;      PORTB.3=1;

    if(PIND.6 | PINB.1 |PINB.2 ==1) return (0);  
     //011
     PORTA.7=0; PORTD.4=1; PORTD.5=1; 
    PORTC.6=0; PORTC.7=1; PORTB.0=1;     PORTB.3=1;

    if(PIND.6 | PINB.1 | PINB.2 ==1) return (0);  
     //100
     PORTA.7=1; PORTD.4=0; PORTD.5=0; 
    PORTC.6=1; PORTC.7=0; PORTB.0=0;     PORTB.3=1;

    if(PIND.6 | PINB.1 | PINB.2 ==1) return (0);  
      //101
     PORTA.7=1; PORTD.4=0; PORTD.5=1; 
    PORTC.6=1; PORTC.7=0; PORTB.0=1;     PORTB.3=1;

    if(PIND.6 | PINB.1 | PINB.2 ==1) return (0); 
      //110
     PORTA.7=1; PORTD.4=1; PORTD.5=0; 
    PORTC.6=1; PORTC.7=1; PORTB.0=0;      PORTB.3=1;

    if(PIND.6 | PINB.1 | PINB.2 ==1) return (0); 
      //111
     PORTA.7=1; PORTD.4=1; PORTD.5=1; 
    PORTC.6=1; PORTC.7=1; PORTB.0=1;      PORTB.3=1;

    if(PIND.6 | PINB.1 | PINB.2 ==1) return (0);
     
    //NOT GATE
    //0
   /* PORTB.3=0;
    if (PINB.2 == 0) return (0);
    //1        */
   /*  PORTB.3=1;
    if (PINB.2 == 1) return (0);*/
    
    return (1);
}

int IC_74804(void){

 DDRA= 0x6f;
 DDRB= 0xf6;
 DDRC= 0xdf;
 DDRD= 0xbf;
       CLR_BIT(DDRD,3);

 PORTD.7=0;  //GND
 PORTC.2=1;  //VCC
 
  
    PORTA.2 = PORTA.5 = PORTD.4 = PORTB.1 = PORTC.6 = PORTC.3 = 0;
    PORTA.3 = PORTA.6 = PORTD.5 = PORTB.2 = PORTC.7 = PORTC.4 = 0; 
    if(PINA.4 & PINA.7 & PIND.6 & PINB.3 & PINB.0 & PINC.5 !=1) return (0);
    

    PORTA.2 = PORTA.5 = PORTD.4 = PORTB.1 = PORTC.6 = PORTC.3 = 1;
    PORTA.3 = PORTA.6 = PORTD.5 = PORTB.2 = PORTC.7 = PORTC.4 = 0;
    if(PINA.4 & PINA.7 & PIND.6 & PINB.3 & PINB.0 & PINC.5 !=1) return (0);
   

    PORTA.2 = PORTA.5 = PORTD.4 = PORTB.1 = PORTC.6 = PORTC.3 = 0;
    PORTA.3 = PORTA.6 = PORTD.5 = PORTB.2 = PORTC.7 = PORTC.4 = 1;   
    if(PINA.4 & PINA.7 & PIND.6 & PINB.3 & PINB.0 & PINC.5 !=1) return (0);
    

    PORTA.2 = PORTA.5 = PORTD.4 = PORTB.1 = PORTC.6 = PORTC.3 = 1;
    PORTA.3 = PORTA.6 = PORTD.5 = PORTB.2 = PORTC.7 = PORTC.4 = 1;  
    if(PINA.4 | PINA.7 | PIND.6 | PINB.3 | PINB.0 | PINC.5 ==1) return (0); 
    
 return(1);                                                                                                                                               
 }
 
 int IC_74874(void){
    DDRA= 0xff;
 DDRB= 0xfc;
 DDRC= 0x03;
 DDRD= 0xff;
      CLR_BIT(DDRD,3);

     PORTD.7=0;  //GND
     PORTC.0=1;  //VCC 
     PORTA.1=0;  //EN1
     PORTD.6=0;  //EN2
     PORTC.1=1; //CLK
     PORTB.2=1; //CLK
  PORTA.0=0; PORTB.3=0;
 if(PINC.2 | PINC.3 |PINC.4 | PINC.5 | PINC.6 | PINC.7| PINB.0 | PINB.1 ==1 ) return (0);          
 
 PORTA.0=1; PORTB.3=1;
 PORTA.2=0; PORTA.3=0 ; PORTA.4=0; PORTA.5=0; PORTA.6=0; PORTA.7=0; PORTD.4=0; PORTD.5=0;
 if(PINC.2 | PINC.3 |PINC.4 | PINC.5 | PINC.6 | PINC.7| PINB.0 | PINB.1 ==1 ) return (0);
 
  PORTA.2=1; PORTA.3=1 ; PORTA.4=1; PORTA.5=1; PORTA.6=1; PORTA.7=1; PORTD.4=1; PORTD.5=1;
 if(PINC.2 & PINC.3 & PINC.4 & PINC.5 & PINC.6 & PINC.7 & PINB.0 & PINB.1 ==0 ) return (0);
 
 return(1);
 }
void main(void)
  {    
 
     char i=0;
   char flag=0;
   unsigned char* ICs[6] = {"4000","74914","74832","4001","74804","74874"};
   int (*ptr[6])(void) = {IC_4000,IC_74914,IC_74832,IC_4001,IC_74804,IC_74874}; 
UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
UBRRH=0x00;
UBRRL=0x47;
 
SET_BIT(DDRB,4);
SET_BIT(DDRB,5);

PORTB.4=0;
PORTB.5=0;
 CLR_BIT(DDRD,3);
/*DDRA=0xFF;
DDRB=0xFF;
DDRC=0xFF;
DDRD=0xFF; */

while (1) {
if(PIND.3==0){ 
  flag=0;
        for (i=0 ; i<6 ; i++){
         if(ptr[i]()){
         flag=1;      
         printf("IC %s has been recognized\r\n",ICs[i]);
         break;
         }
        }   
        delay_ms(200); 
        if(flag==0){
        printf("NO IC\r\n");
        } 
}
} 
 }     
   
        
     
 
    