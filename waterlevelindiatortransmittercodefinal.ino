#include <Ultrasonic.h>

#include <VirtualWire.h>


const int trigPin = 8; //where the oin is connected on the arduino
const int echoPin = 9;


float temp; //Define the distance float variable
char msg[6];


void setup()
{
  
  vw_setup(2000);	        // Bits per sec
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
 digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
temp = pulseIn(echoPin, HIGH);//assigning the digital output to temp

    temp = temp * 0.034/2; //converting volts to degrees celsius ----- 0.48828125 = [(5V*1000)/1024]10
    dtostrf(temp, 6,2,msg);           //converts the float into a char 
    vw_send((uint8_t *)msg, strlen(msg)); //transmits the data
    vw_wait_tx(); // Wait until the whole message is gone
    delay(200);
 }
 
