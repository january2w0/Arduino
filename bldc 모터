#include <Servo.h> //라이브러리 불러오기

Servo bldc ; //모터 선언

int analog = A0;
int digital = 13;
int previous = LOW;
int State = LOW;
int value = 0;
int analvalue = 0;

void setup(){
  pinMode(analog,INPUT);
  pinMode(digital,INPUT_PULLUP);
  Serial.begin(9600);
  bldc.attach(9);
  bldc.write(value);
}

void loop(){
  int reading = digitalRead(digital);
  if (reading == LOW && previous == HIGH){
    if (State == HIGH) {
      State = LOW;
    } else {
      State = HIGH;
    }
  }
  previous = reading;
  if (State == HIGH){
    analvalue = analogRead(analog);
  } else {
    analvalue = 0;
  }

  value = map(analvalue,0,1023,0,180);
  bldc.write(value);
  
  Serial.print("State:");
  Serial.print(State);
  Serial.print(" ");
  Serial.print("analog:");
  Serial.print(value);
  Serial.print(" ");
  Serial.print("digital:");
  Serial.println(reading);
}
