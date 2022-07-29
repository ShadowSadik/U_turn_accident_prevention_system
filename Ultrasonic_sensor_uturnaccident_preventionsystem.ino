int trigPin1=12;
int echoPin1=11;
int trigPin2=5;
int echoPin2=4;

int pingTravelTime1;
float pingTravelDistance1;
float distanceToTarget1;

int pingTravelTime2;
float pingTravelDistance2;
float distanceToTarget2;


int redLED1=9;
int greenLED1=8;
int redLED2= 7;
int greenLED2= 6;

int dt=50;

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin1,OUTPUT);
pinMode(echoPin1,INPUT);

pinMode(trigPin2,OUTPUT);
pinMode(echoPin2,INPUT);

pinMode(redLED1, OUTPUT);
pinMode(greenLED1, OUTPUT);

pinMode(redLED2, OUTPUT);
pinMode(greenLED2, OUTPUT);

Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin1,LOW);
delayMicroseconds(10);
digitalWrite(trigPin1,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1,LOW);
pingTravelTime1=pulseIn(echoPin1,HIGH);
delay(25);
pingTravelDistance1=(pingTravelTime1*765.*5280.*12)/(3600.*1000000);
distanceToTarget1=pingTravelDistance1/2;


digitalWrite(trigPin2,LOW);
delayMicroseconds(10);
digitalWrite(trigPin2,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2,LOW);
pingTravelTime2=pulseIn(echoPin2,HIGH);
delay(25);
pingTravelDistance2=(pingTravelTime2*765.*5280.*12)/(3600.*1000000);
distanceToTarget2=pingTravelDistance2/2;


Serial.print("Distance to Target1 is:   ");
Serial.print(distanceToTarget1);
Serial.print( "  ");
Serial.println(" in.");
Serial.print("Distance to Target2 is:   ");
Serial.print(distanceToTarget2);
Serial.print( "  ");

delay(dt);

if(distanceToTarget1 <= 3 && distanceToTarget2 <= 3)
    {
   digitalWrite(greenLED1, LOW);
   digitalWrite(redLED1, HIGH);
   digitalWrite(greenLED2, LOW);
   digitalWrite(redLED2, HIGH);
   
    }


else if (distanceToTarget1 <= 3)
{
   digitalWrite(greenLED1, HIGH);
   digitalWrite(redLED1, LOW);
   digitalWrite(greenLED2, LOW);
   digitalWrite(redLED2, HIGH);
  
  }
  else if (distanceToTarget2 <= 3) 
  {
   digitalWrite(greenLED1, LOW);
   digitalWrite(redLED1, HIGH);
   digitalWrite(greenLED2, HIGH);
   digitalWrite(redLED2, LOW);
   

    }

    

    else 
    {
     digitalWrite(greenLED1, HIGH);
   digitalWrite(redLED1, LOW);
   digitalWrite(greenLED2, HIGH);
   digitalWrite(redLED2, LOW);
   
    }








    
}
