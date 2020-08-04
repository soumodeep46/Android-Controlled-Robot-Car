#include<reg51.h>
unsigned char ch1;
unsigned char s;
sbit m1f=P2^0;             
sbit m1b=P2^1;             
sbit m2f=P2^2;             
sbit m2b=P2^3;             
void delay(unsigned int)  ;        
char rxdata(void);                 
void txdata(unsigned char); 
void main(void)
 {
unsigned char i;
unsigned char msg1[]={"Car is moving forward"};
unsigned char msg2[]={"Car is moving backward"};
unsigned char msg3[]={"Car is moving right"};
unsigned char msg4[]={"Car is moving left"};
unsigned char msg5[]={"Car is stopped"};
TMOD=0x20;   
SCON=0x50;    
TH1=0xfd;     
TR1=1;            
while(1)             
{
     s=rxdata(); 
if(s=='f') 
     {
         m1f=1;
   delay(1);
         m1b=0;
   delay(1);
         m2f=1;
   delay(1);
         m2b=0;
   delay(1);
        for(i=0;msg1[i]!='\0';i++)
{
    txdata(msg1[i]);
} 
  }
 else if(s=='b')  
     {
         m1f=0;
    delay(1);
         m1b=1;
    delay(10);
         m2f=0;
    delay(10);
         m2b=1;
    delay(10);
    for(i=0;msg2[i]!='\0';i++)   
         {
   txdata(msg2[i]);
    }
     }
      else if(s=='r')
     {
         m1f=1;
         delay(1);
         m1b=0;   
   delay(10);
         m2f=0;
   delay(10);
         m2b=1;
delay(10);
for(i=0;msg3[i]!='\0';i++)   
{
    txdata(msg3[i]);
} 
 }
      else if(s=='l')
     {
         m1f=0;
         delay(1);
         m1b=1;
    delay(1);
         m2f=1;
    delay(1);
         m2b=0;
    delay(1);
    for(i=0;msg4[i]!='\0';i++)
        {
    txdata(msg4[i]);
   } 
    }
      else if(s=='s')  
     {
         m1f=0;
         delay(1);
         m1b=0;
    delay(1);
         m2f=0;
    delay(1);
         m2b=0;
   delay(1);
 for(i=0;msg5[i]!='\0';i++)
        {
  txdata(msg5[i]);
   }
    }
      txdata('\n');  
     }
}
 char rxdata()
{
  while(RI==0);   
  RI=0;           
  ch1=SBUF;     
  return ch1;     
}
 void txdata(unsigned char x)
{
   SBUF=x; 
   while(TI==0);
   TI=0; 
}
 void delay(unsigned int z)
{
  unsigned int p ,q;
  for(p=0 ; p<z ; p++)    
  {
    for(q=0 ; q<1375 ; q++);   }
}
