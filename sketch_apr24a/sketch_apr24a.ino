#include <Servo.h> 

long randNumber;
const int analogInPin = A0; 
   

class Sweeper
{
  Servo servo;              // the servo
  int pos = 0 ;              // current servo position 
  int increment;        // increment to move for each interval
  int  updateInterval;      // interval between updates
  unsigned long lastUpdate; // last update of position
  int steps; 
  int duper; 
  int xuper; 
  int chime; 
  
public: 
   
 int sensorValue = 0;         
  int outputValue = 0;  
  int super;


  Sweeper(int interval, int steps)
  {
    updateInterval = interval;
    increment = steps;
  }
  
  void Attach(int pin)
  {
    servo.attach(pin);
  }
  
  void Detach()
  {
    servo.detach();
  }
  
  void Update(int chime, int duper, int xuper)
  {
    

  
    if((millis() - lastUpdate) > duper)  // time to update
    {
      
      
     Serial.print("windchime number = " );
  Serial.print(chime); 
    Serial.print("\t"); 
  
  Serial.print(' ');
      lastUpdate = millis();
      pos += (xuper);
      servo.write(pos);
           Serial.print(" position  = " );
      Serial.println(pos);
       
    
      while (pos >= 80) // end of sweep
      {
        lastUpdate = millis();
        pos -= (80);
       
        servo.write(pos);
      
        Serial.print("windchime number = " );
        Serial.print(chime);
         Serial.print("\t"); 
        Serial.print("return position " );
        Serial.println(pos);
 
   
   //      delay(duper);
         
         
      }   
    }
  }
};
 
Sweeper sweeper1(100,1);

Sweeper sweeper2(100,1 );

 
Sweeper sweeper3(100,1);

 
Sweeper sweeper4(100,1 );
Sweeper sweeper5(100,10);
Sweeper sweeper6(100, 11 );
 
 
void setup() 
{ 
  Serial.begin(9600);
  
   randomSeed(analogRead(A1)); 
   sweeper1.Attach(2);
   sweeper2.Attach(3);
   sweeper3.Attach(4);
   sweeper4.Attach(5);
   sweeper5.Attach(6);
   sweeper6.Attach(7);
 
} 
 
void loop() 
{ 
    sweeper1.Update(1, 50000, 20);
    sweeper2.Update(2, 60000, 25); 
    sweeper3.Update(3, 70000, 30);
    sweeper4.Update(4, 80000, 35);
    sweeper5.Update(5, 90000,40);
    sweeper6.Update(6, 100000,45);
  
 
   
 }
