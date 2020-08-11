int Heart=10;
int led=12;
int val;
int tempPin = A0;
int r;
int buzzer = 13;
const int trigPin = 6;
const int echoPin = 7;

const int trigPin1 = 2;
const int echoPin1 = 3;

long duration;
int distance;
long duration1;
int distance1;

const int pushb1 = 8;
const int pushb2 = 9;
int buttonState1 = 0;
int buttonState2 = 0;
void setup() 
{
  Serial.begin(9600);
  pinMode(Heart,INPUT);// OUTPUT PIN FROM HEARTBEAT SENSOR
  pinMode(tempPin,INPUT);// OUTPUT PIN FROM TEMP SENSOR
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT);
  pinMode(pushb1, INPUT_PULLUP);
  pinMode(pushb2, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
 
}

void loop() 
{
    delay(100);
    int Heart_Beat=digitalRead(Heart);
    //Serial.println(Heart_Beat);
    if(Heart_Beat== 0)
        {
         Serial.println("LOADING.....");
         noTone(buzzer);
          for(int i=15;i>0;i--)
          {
            int Heart_Beat=digitalRead(Heart);
              
            if(Heart_Beat== 1)
            {
            led+=1;
            }
            else
            {
              
            }
            delay(700);
          }
          
          Serial.println("Please Remove ur Finger");
          delay(2000);
          Serial.print("Value of Heart Rate= ");
          int r=led+60;
          Serial.println(r);
          
          if(led<10)
          {
            delay(3000);
          }
          else
          {
            
          }
          led=0;
        }

    
    //temperature 
    val = analogRead(tempPin);
    float mv = ( val/1024.0)*5000; 
    float cel = mv/10;
    Serial.print("TEMPRATURE = ");
    Serial.print(cel);
    Serial.print("*C");
    Serial.println();
    delay(200);


    //obstacle avoidance
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration1 = pulseIn(echoPin1, HIGH);
    // Calculating the distance
     distance1 = ((duration1)/2) / 29.1;
    //Serial.print("Distance from obstacle: ");
    //Serial.println(distance1);
    delay(100);
  
    if((distance1)<55){
      tone(buzzer, 1000); // Send 1KHz sound signal...
    }
    else{
      noTone(buzzer);
    }  
    
    
    //urine level indicator
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration*0.034/2;
    Serial.print("Urine level: ");
    Serial.println(distance);
    if(distance<6 || distance>2000){
    Serial.println("URINE BAG ABOUT TO FILL");
    }
    delay(100);

    
  
    

    /*int x = analogRead(xpin);  //read from xpin
 
    int y = analogRead(ypin);  //read from ypin
 
    int z = analogRead(zpin);  //read from zpin
 
    int p=(((float)x - 331.5)/65*9.8);
    Serial.print(((float)x - 331.5)/65*9.8);  //print x value on serial monitor
    Serial.print("\t");
    Serial.print(((float)y - 329.5)/68.5*9.8);  //print y value on serial monitor
    Serial.print("\t");
    Serial.print(((float)z - 340)/68*9.8);  //print z value on serial monitor
    Serial.print("\n");
    delay(500);
    if (p>75)
    {
      Serial.println("FALL DETECTED");
    }
    Serial.println(" ");*/

    //fall detection and Emergency
    buttonState1 = digitalRead(pushb1);
    buttonState2 = digitalRead(pushb2);
    if(buttonState1 == HIGH || buttonState2 == HIGH){
    Serial.println("EMERGENCY");
    tone(buzzer, 1000); 
    }
    else{
    Serial.println("ALL GOOD");
    }
    delay(200);
    Serial.println(" ");
    
    
}
