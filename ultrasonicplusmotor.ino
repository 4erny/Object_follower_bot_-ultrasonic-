
/*-----( Import needed libraries )-----*/
#include <NewPing.h>
/*-----( Declare Constants and Pin Numbers )-----*/
#define  TRIGGER_PIN1  11
#define  ECHO_PIN1    10
#define MAX_DISTANCE1 40 // Maximum distance we want to ping for (in centimeters).

#define  TRIGGER_PIN2  8
#define  ECHO_PIN2     7
#define MAX_DISTANCE2 40 // Maximum distance we want to ping for (in centimeters).
                        
                         
/*-----( Declare objects )-----*/
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE1); 
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE2);// NewPing setup of pins and maximum distance.
 //Declare variables
double DistanceCm1;
double DistanceCm2;

float sensors;

void setup() 
{
  Serial.begin(9600);
  Serial.println("UltraSonic Distance Measurement");

    pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

      pinMode(12, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);

}


void loop()  
{
  delay(200);// Wait 100ms between pings (about 10 pings/sec). 29ms should be the shortest delay between pings.
  DistanceCm1 = sonar1.ping_cm();
  Serial.print("Ping_1: ");
  Serial.print(DistanceCm1); 
  Serial.print(" cm"); 
  Serial.print("   ");
  DistanceCm2 = sonar2.ping_cm();
  Serial.print("Ping_2: ");
  Serial.print(DistanceCm2); 
  Serial.print(" cm");
  Serial.print("   ");
  sensors = (DistanceCm1 + DistanceCm2)/2;
  Serial.print(sensors);
  Serial.println(" cm");

  if ((sensors<10)&&(DistanceCm1!=0)&&(DistanceCm2!=0))
  {
       digitalWrite(9, 10);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);

   digitalWrite(12, 10);
  digitalWrite(4, HIGH);
  digitalWrite(2, LOW);
  }
  else if((sensors>15)&&(DistanceCm1!=0)&&(DistanceCm2!=0))
  {
      digitalWrite(5, LOW);
  digitalWrite(6, HIGH);

      digitalWrite(4, LOW);
  digitalWrite(2, HIGH);
  }
  else if((sensors>=10)&&(sensors<=15)&&(DistanceCm1!=0)&&(DistanceCm2!=0))
  {
     digitalWrite(5, NULL);
  digitalWrite(6, NULL);

      digitalWrite(4, NULL);
  digitalWrite(2, NULL);
  }
   else if ((DistanceCm1>0)&&(DistanceCm2==0))
   {
    digitalWrite(5, LOW);
  digitalWrite(6, HIGH);

      digitalWrite(4, NULL);
  digitalWrite(2, NULL);
    }
    else if ((DistanceCm2>0)&&(DistanceCm1==0))
   {
    digitalWrite(5, NULL);
  digitalWrite(6, NULL);

      digitalWrite(4, LOW);
  digitalWrite(2, HIGH);
    }

}//--(end main loop )---

