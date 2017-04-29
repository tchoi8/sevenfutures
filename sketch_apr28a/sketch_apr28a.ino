#include <Servo.h> 

long randNumber;
long randNumber2;
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
      randNumber = random(5000,13000); 
     increment = random(randNumber2, 30);
          //increment = steps;
     
       Serial.print(" random  = " );
     Serial.println(randNumber);
            
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
     

     while (pos >= 50) // swing the wind chime back 
      {
           delay(randNumber);

        lastUpdate = millis();
        pos = (20);
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
   windchime1.Attach(2);
   windchime2.Attach(3);
  windchime3.Attach(4);
   windchime4.Attach(5);
   windchime5.Attach(6);
   windchime6.Attach(7);
 
} 
 
void loop() 
{ 
    windchime1.Update(1, 100, 5);
    windchime2.Update(2, 100, 25); 
    windchime3.Update(3, 100, 40);
    windchime4.Update(4, 100, 25);
    windchime5.Update(5, 100, 25);
    windchime6.Update(6, 100, 30); 
 }
