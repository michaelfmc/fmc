#include <Wire.h>

#include <LiquidCrystal.h>

#include <VirtualWire.h>


LiquidCrystal lcd(6, 7, 8, 9, 10, 11);//Initialise the LCD


int i;    //and integer used to count

void setup()
{
    //Define the LCD as 16 column by 2 rows 
    lcd.begin (16,2);
   //Define the receiver pin and rate
    vw_set_rx_pin(12);       //Sets pin D12 as the RX Pin
    vw_setup(2000);	     // Bits per sec
    vw_rx_start();           // Start the receiver PLL running
}

void loop()
{
   uint8_t buf[VW_MAX_MESSAGE_LEN];
   uint8_t buflen = VW_MAX_MESSAGE_LEN;
   
   if( vw_get_message(buf, &buflen) )
      {
        lcd.setCursor(0, 0);
        lcd.print("The Distance is:");    
        lcd.setCursor(0,1);  
        
       for (i = 0; i < buflen; i++)
         { 
           lcd.write(buf[i]); 
                    
         }
        
           //lcd.print((char)223);
           lcd.print("Cm");

      }
 
}
