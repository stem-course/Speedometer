/*
Code by: www.munphurid.com
M. Hashir and Wardah Arshad

This is a code for Speedometer

Hardware:
Is bought from www.munphurid.com
-Arduino UNO
-2 IR Sensor
-few male to female wires

Connections:

IR sensor and Arduino
-Connect OUT of IR sensor1 to pin 2 of Arduino
-Connect OUT of IR sensor2 to pin 3 of Arduino
-Connect VCC of IR sensor to 5V of Arduino
-Connect GND of IR sensor to GND of Arduino

LCD and Arduino
 * LCD GND pin(pin 1) to GND
 * LCD VCC pin(pin 2) to 5V
 * LCD V0 pin(pin 3) to GND
 * LCD RS pin(pin 4) to digital pin 10
 * LCD R/W pin (pin5) to GND (with resistor if you have BLUE LCD)
 * LCD Enable pin(pin 6) to digital pin 11
 * LCD D4  pin(pin 11) to digital pin A0
 * LCD D5 pin(pin 12) to digital pin A1
 * LCD D6 pin(pin 13) to digital pin A2
 * LCD D7 pin(pin 14) to digital pin A3
 * LCD backlight+ (pin15) to 5V
 *LCD backlight- (pin16) to GND
*/

#include <LiquidCrystal.h>


int sinit=2;                        //sensor1 is connected to pin 2 of Arduino
int sfinal=3;                       //sensor1 is connected to pin 3 of Arduino

int initial = 1;                    //Can be used later
int final = 1;                      //Can be used later
double initialmillis=0;             //Can be used later
double finalmillis=0;               //Can be used later
float myspeed=0;                    //Can be used later
float distance=10.0;                //1 ft
int buzzer=11;                      //buzzer is connected to pin 11 of Arduino

LiquidCrystal lcd(13,12,11,10,9,8);

void setup() {
  //lcd.begin(16,2);
Serial.begin(9600);
pinMode(sinit,INPUT);               //Sensor1 senses the movement of hand
pinMode(sfinal,INPUT);              //Sensor2 senses the movement of hand
pinMode(buzzer,OUTPUT);
}

void loop() {
  
  initial=digitalRead(sinit);       //Sensor1 senses the movement of hand
  if(initial==0){                   //if it sense your hand, serial monitor gives the value 0
  initialmillis=millis();           //Donot edit this line
  final=digitalRead(sfinal);        //Sensor2 senses the movement of hand
    while(final){                   //Donot edit this line
  final=digitalRead(sfinal);        //Donot edit this line
  }
  finalmillis=millis();             //Donot edit this line
  if(finalmillis>initialmillis){
myspeed = distance/(finalmillis-initialmillis);     //calculation of speed 

 lcd.clear();
 lcd.setCursor(0,1);
 lcd.print("Speed = ");
 lcd.print(myspeed);
 
 if(myspeed<5){                     //if speed is less than 5,
 Serial.print("Speed = ");          //it display speed
 Serial.print(myspeed);
 Serial.println(" m/s");
 
 
 if(myspeed>0.1){                   //if speed is more than 0.1, 
  digitalWrite(buzzer,HIGH);        // buzzer turns on
 delay(1000);                       //wait for 1 sec
 digitalWrite(buzzer,LOW);          // buzzer turns off
 } 
}
  }
}
  
}
