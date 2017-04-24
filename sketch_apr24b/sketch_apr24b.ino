#include <Servo.h> 

long randNumber;
const int analogInPin = A0;    

class Windchime
{
  Servo servo;              // the servo
  int pos = 0 ;              // current servo position 
  int increment;        // increment to move for each interval
  int  updateInterval;      // interval between updates
  unsigned long lastUpdate; // last update of position
  int chime; // names the each windchime 
  
public: 
   
 int sensorValue = 0;         
 int outputValue = 0;  
 
  Windchime(int interval, int steps)
  {
 
  }
   
  void Attach(int pin)
  {
    servo.attach(pin);
  }
  
  void Detach()
  {
    servo.detach();
  }
  
  void Update(int chime, int interval, int steps)
  {
        updateInterval = interval;
    increment = steps;
      
    if((millis() - lastUpdate) > updateInterval)  // time to update
    {      
     Serial.print("windchime number = " );
     Serial.print(chime); 
     Serial.print("\t"); 
     Serial.print(' ');
      
     lastUpdate = millis();
     pos += (increment);
     servo.write(pos);
     Serial.print(" position  = " );
     Serial.println(pos);
       

     while (pos >= 80) // swing the wind chime back 
      {
        lastUpdate = millis();
        pos -= (80);
        servo.write(pos);
      
        Serial.print("windchime number = " );
        Serial.print(chime);
         Serial.print("\t"); 
        Serial.print("return position " );
        Serial.println(pos);
     
      }   
    }
  }
};
 
Windchime windchime1(100,1);
Windchime windchime2(100,1);
Windchime windchime3(100,1);
Windchime windchime4(100,1);
Windchime windchime5(100,1);
Windchime windchime6(100,1);
 
 
void setup() 
{ 
  Serial.begin(9600);
  
   randomSeed(analogRead(A1)); 
   windchime1.Attach(2);
   windchime2.Attach(3);
   windchime3.Attach(4);
   windchime4.Attach(5);
   windchime5.Attach(6);
   windchime6.Attach(7);
 
} 
 
void loop() 
{ 
    windchime1.Update(1, 100, 10);
    windchime2.Update(2, 100, 15); 
    windchime3.Update(3, 100, 30);
    windchime4.Update(4, 100, 40);
    windchime5.Update(5, 100,50);
    windchime6.Update(6, 100, 60);
  
 
   
 }
