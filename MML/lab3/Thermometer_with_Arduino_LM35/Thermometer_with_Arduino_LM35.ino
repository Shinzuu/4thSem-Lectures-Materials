
int LEDR = 5;
int LEDG = 7;
int t=0;
int sensor = A0;
float temp;
float tempc;
float tempf; 
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> //const int rs= 12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal_I2C lcd(0x27, 2, 16); 
void setup()
{
pinMode(LEDR,OUTPUT);
pinMode(LEDG,OUTPUT);
pinMode(sensor,INPUT);
lcd.init();
lcd.backlight();
lcd.setCursor (0,0);
lcd.print ("Premier University");
lcd.setCursor (0,1); 
lcd.print ("TEMPERATURE METER"); 
delay (3000); 
Serial.begin(9600);
} 
void loop() 
{
delay(2000);
t=t+2;
temp=analogRead(sensor);
tempc=(temp*5)/10;
tempf=(tempc*1.8)+32; 
Serial.println("_______"); 
Serial.println("Temperature Logger"); 
Serial.print("Time in Seconds= "); 
Serial.println(t); 
Serial.print("Temp in deg Celsius = "); 
Serial.println(tempc); 
Serial.print("Temp in deg Fahrenheit = "); 
Serial.println(tempf); 
lcd.setCursor(0,0);
lcd.print("Temp in C = ");
lcd.println(tempc);
lcd.setCursor(0,1);
lcd.print("Temp in F = ");
lcd.println(tempf); 
if(tempc<35)
  {

     digitalWrite(LEDG,LOW);
    digitalWrite(LEDR,HIGH);

 
  
  
  }
  else{
     digitalWrite(LEDR,LOW);
     digitalWrite(LEDG,HIGH);
 
  
  }


} 
