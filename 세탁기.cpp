#include <Servo.h>
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

Servo myservo1;
hd44780_I2Cexp lcd;

extern volatile unsigned long timer0_millis;

int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;

int m;
int n;
int f;

int x1;
int y1;
int j1 = 0;
int j2 = 0;
int j3 = 0;
int t2 = 0;
int t4 = 0;
long m1 = 0;
long n1 = 0;
long n2 = 0;
long n3 = 0;
long n4 = 0;
long f1 = 0;
long z1 = 0;
long h1 = 0;
long h2 = 0;
long h3 = 0;
long h4 = 0;

int x = 0;
int y = 0;
int z = 0;
int h = 0;
int j = 0;
int t = 0;
int t1 = 0;

int VaL1 = 0;
int vaL1 = 0;
int VaL2 = 0;
int vaL2 = 0;

int sw1 = 2;       
int R = 3;  
int G = 4; 
int B = 5;    
int sw2 = 8;       
int led2 = 9; 
int sw3 = 10;    
int led3 = 11;   
int led6 = 12; 
int sw4 = 6; 
int led4 = 7; 

int state1 = LOW;       
int reading1;        
int previous1 = LOW;   
int state2 = LOW;      
int reading2;        
int previous2 = LOW; 
int state3 = LOW; 
int state6 = LOW;     
int reading3;        
int previous3 = LOW; 
int state4 = LOW;  
int reading4;        
int previous4 = LOW; 

unsigned long time1 = 0; 
unsigned long time2 = 0;
unsigned long time3 = 0;
unsigned long time4 = 0;
unsigned long Time1 = 0;
unsigned long Time2 = 0;
unsigned long Time3 = 0;
unsigned long Time4 = 0;
unsigned long Time5 = 0;
unsigned long Time6 = 0;
unsigned long Time7 = 0;
unsigned long Time8 = 0;
unsigned long Time9 = 0;
unsigned long TIME = 0;
const long debounce = 150;
const float Delay1 = 5; // 상태 변화 시간간격
const float Delay2 = 5; // 상태 변화 시간간격
const float Delay3 = 100;
const float Delay4 = 700;
const float Delay5 = 6.5; // 상태 변화 시간간격
const float Delay6 = 5;
const float Delay7 = 5;

int i = Delay1*30;
int p = Delay2*30;
int o = Delay5*30;
int t3 = 500;
int t5 = 300;

int k2 = 22; 
int k3 = 23;
int k4 = 24; 
int k5 = 25;

int On = HIGH;
int reset = LOW;
int dehydration = LOW;

int rotation1;
int rotation2;

void setup() {
  Serial.begin(9600);
  myservo1.attach(13); 
  lcd.begin(16,2); 
  pinMode(sw1,INPUT_PULLUP); 
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);  
  pinMode(B,OUTPUT);
  pinMode(sw2,INPUT_PULLUP); 
  pinMode(led2,OUTPUT); 
  pinMode(sw3,INPUT_PULLUP); 
  pinMode(led3,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(sw4,INPUT_PULLUP); 
  pinMode(led4,OUTPUT);
  pinMode(k2,OUTPUT);
  pinMode(k3,OUTPUT);
}
 
void loop() {
  if (On == HIGH) {
    int reading1 = digitalRead(sw1);
    if (reading1 == HIGH && previous1 == LOW && millis() - time1 > debounce) {
      if (state1 == HIGH) {  
        state1 = LOW;
      } else {                 
        state1 = HIGH;
      }
      time1 = millis();
    }
    previous1 = reading1;
  }
  if (t1 > 0) {
    digitalWrite(led4,HIGH);
  } else {
    digitalWrite(led4,LOW);
  }
  if (state1 == HIGH && On == HIGH) { // 만약 전원1이 켜지면
    lcd.backlight();
    analogWrite(R,255);
    analogWrite(G,0);
    analogWrite(B,255);
    if (t <= 500) { // 남은 시간이 끝나지 않았을 때
      int reading4 = digitalRead(sw4);
      if (reading4 == HIGH && previous4 == LOW && millis() - time4 > debounce) {
        if (state4 == HIGH) {  
          state4 = LOW;
        } else {                 
          state4 = HIGH;
        }
        time4 = millis();
      }
      previous4 = reading4;
      if (state4 == LOW) { // 물이 꺼져 있을 때
        if (millis() - Time7 > Delay6) {
          t++;
          Time7 = millis();
        }
        h3++;
        h4 = 0;
        if (h3 == 1) {
          lcd.setCursor(0,0);
          lcd.print("                ");
          lcd.setCursor(0,1);
          lcd.print("                ");
        }
        lcd.setCursor(0,0);
        lcd.print("Remaining Time:");
        t2 = (t3 - t + 90) / 100;
        if (t2 > 9) {
          lcd.setCursor(14,1);
          lcd.print(t2);
        } else {
          lcd.setCursor(14,1);
          lcd.print(0);
          lcd.print(t2);
        }
        digitalWrite(k4,LOW);
        digitalWrite(k5,LOW);
      } else { // 물이 켜져 있을 때
        h4++;
        h3 = 0;
        if (h4 == 1) {
          lcd.setCursor(0,0);
          lcd.print("                ");
          lcd.setCursor(0,1);
          lcd.print("                ");
        }
        lcd.setCursor(0,0);
        lcd.print("Watering");
        if (millis() - Time9 >= Delay4) {
          Time9 = millis();
          j3++; 
        }
        if (j3 == 1) {
          lcd.setCursor(8,0);
          lcd.print(".");
        } else {
          if (j3 == 2) {
            lcd.setCursor(9,0);
            lcd.print(".");
          } else {
            if (j3 == 3) {
              lcd.setCursor(8,0);
              lcd.print("  ");
              j3 = 0;
            }
          }
        }
        lcd.setCursor(9,1);
        lcd.print("Time:");
        t4 = (t5 - t1 + 90) / 100;
        if (t4 > 9) {
          lcd.setCursor(14,1);
          lcd.print(t2);
        } else {
          lcd.setCursor(14,1);
          lcd.print(0);
          lcd.print(t4);
        }
        if (t1 <= 300) {
          digitalWrite(k4,HIGH);
          digitalWrite(k5,LOW);
          if (millis() - Time8 > Delay7) {
            t1++;
            Time8 = millis();
          }
        } else {
          state4 = LOW;
        }
      }
    } else { // 남은 시간 끝났을 때
      if (dehydration == LOW) { // 만약 탈수모드가 꺼져 있으면
        if (state2 == LOW && c == LOW) {
          VaL1 = 0;
          vaL1 = 0;
        }
        h2++;
        if (h2 == 1) {
          lcd.setCursor(0,0);
          lcd.print("                ");
          lcd.setCursor(0,1);
          lcd.print("                ");
        }
        z = 0;
        int reading2 = digitalRead(sw2);
        if (reading2 == HIGH && previous2 == LOW && millis() - time2 > debounce) {
          if (state2 == HIGH) {    
            state2 = LOW;
          } else {                
            state2 = HIGH;
          }
          time2 = millis();
        }
        digitalWrite(led2, state2);
        previous2 = reading2;
        reset = LOW;
        lcd.setCursor(0,0);
        lcd.print("Washing");
        if (millis() - Time4 >= Delay4) {
          Time4 = millis();
          j++; 
        }
        if (j == 1) {
          lcd.setCursor(7,0);
          lcd.print(".");
        } else {
          if (j == 2) {
            lcd.setCursor(8,0);
            lcd.print(".");
          } else {
            if (j == 3) {
              lcd.setCursor(7,0);
              lcd.print("  ");
              j = 0;
            }
          }
        }
        if (state2 == HIGH) { // 만약 자동모드가 켜지면
          z1 = 0;
          n = 0;
          n1 = 0;
          lcd.setCursor(0,1);
          lcd.print("Mode:automatic");
          if (millis() - Time1 >= Delay1) {
            Time1 = millis();
            x++; 
          }
          x1 = (i*20 - x + 45) / 50;
          lcd.setCursor(14,0);
          lcd.print(x1);
          if (x <= i) {
            digitalWrite(k2,HIGH);
            digitalWrite(k3,LOW);
            rotation2 = HIGH;
            state6 = HIGH;
            state3 = LOW;
            if (VaL1 > 0) {
              vaL1 = map(x,0,i,VaL1,0);
              myservo1.write(vaL1);
            } else {
              if (VaL2 == 80) {
                a = VaL2;
                b = 0;
              } else {
                if (VaL2 == 0) {
                  b = 1;
                }
              }
            }
            if (b == HIGH) {
              myservo1.write(0);
            } else {
              vaL2 = map(x,0,i,a,0);
              myservo1.write(vaL2);
              VaL2 = vaL2;
            }
          } else {
            if (x <= i*13) {
              m1++;
              if (m1 == 1) {
                m = 2;
              }
              if (x%i == 0) {
                n3++;
                if (n3 == 1) {
                   m++;
                  if ((m+1)%4 == 0) {
                    rotation2 = LOW;
                  } else {
                    rotation2 = HIGH;
                  }  
                }            
              } else {
                n3 = 0;
              }
              if (m%2 == 0) {
                vaL1 = map(x,i*(m-1),i*m,0,80);
                VaL1 = vaL1;
                digitalWrite(k2,LOW);
                digitalWrite(k3,LOW);
                state6 = LOW;
                state3 = HIGH;
              } else {
                vaL1 = map(x,i*(m-1),i*m,80,0);
                VaL1 = vaL1;
                state6 = HIGH;
                state3 = LOW;
                if (rotation2 == HIGH) {
                  digitalWrite(k2,HIGH);
                  digitalWrite(k3,LOW);
                } else {
                  digitalWrite(k2,LOW);
                  digitalWrite(k3,HIGH);
                }
              }           
            } else {
              VaL2 = 0;
              dehydration = HIGH;
            }
            myservo1.write(vaL1);
          }
          digitalWrite(led3,state3);
          digitalWrite(led6,state6);
          y = 0;
          c = 1;
        } else { // 만약 자동모드가 꺼져있으면
          int reading3 = digitalRead(sw3);
          if (reading3 == HIGH && previous3 == LOW && millis() - time3 > debounce) {
            if (state3 == HIGH) {    
              state6 = HIGH;
              state3 = LOW;
            } else {                
              state6 = LOW;
              state3 = HIGH;
              c = 0;
              VaL1 = 0;
            }
            time3 = millis();
          }
          digitalWrite(led3, state3);
          digitalWrite(led6, state6);
          previous3 = reading3;
          x = 0;
          x1 = 0;
          m = 0;
          m1 = 0;
          z1++;
          if (z1 == 1) {
            lcd.setCursor(0,1);
            lcd.print("                ");
          }
          if (millis() - Time2 >= Delay2) {
          Time2 = millis();
          y++; 
          }
          y1 = (p*20 - y + 45) / 50;
          lcd.setCursor(14,0);
          lcd.print(y1);
          if (y <= p*13) {
            n1++;
            if (n1 == 1) {
              n = 1;
              rotation1 = HIGH;
            }
            if (y%p == 0) { // y가 10밀리초에 1씩 증가하니 10밀리초동안 n은 22차례에 걸쳐 증가
              n2++;
              if (n2 == 1) {
                n++;
                if ((n+1)%4 == 0) {
                  rotation1 = LOW;
                } else {
                  rotation1 = HIGH;
                }   
              }     
            } else {
              n2 = 0;
            }
            if (n%2 == 0) {
              digitalWrite(k2,LOW);
              digitalWrite(k3,LOW);
            } else {
              if (rotation1 == HIGH) {
                digitalWrite(k2,HIGH);
                digitalWrite(k3,LOW);
              } else {
                digitalWrite(k2,LOW);
                digitalWrite(k3,HIGH);
              }
            }  
          } else {
            dehydration = HIGH;
          }
          VaL2 = map(state3,0,1,0,80);
          myservo1.write(VaL2);
          vaL1 = 0;
          VaL1 = 0;
          lcd.setCursor(0,1);
          lcd.print("state:");
          if (state3 == HIGH) {
            lcd.print("Drum ");
          } else {
            lcd.print("Nomal");
          }
        }
      } else { // 만약 탈수모드가 켜지면
        if (t1> 0) {
          digitalWrite(k4,LOW);
          digitalWrite(k5,HIGH);
          if (millis() - Time8 > Delay7) {
            t1--;
            Time8 = millis();
          }
        } else {
          digitalWrite(k4,LOW);
          digitalWrite(k5,LOW);
        }
        state2 = LOW;
        digitalWrite(led2, state2);
        digitalWrite(k2,HIGH);
        digitalWrite(k3,LOW);
        h1++;
        if (h1 == 1) {
          lcd.setCursor(0,0);
          lcd.print("                ");
          lcd.setCursor(0,1);
          lcd.print("                ");
        }
        lcd.setCursor(0,0);
        lcd.print("Dehydrating");
        lcd.setCursor(9,1);
        lcd.print("Time:");
        if (millis() - Time6 >= Delay4) {
          Time6 = millis();
          j1++; 
        }
        if (j1 == 1) {
          lcd.setCursor(11,0);
          lcd.print(".");
        } else {
          if (j1 == 2) {
            lcd.setCursor(12,0);
            lcd.print(".");
          } else {
            if (j1 == 3) {
              lcd.setCursor(11,0);
              lcd.print("  ");
              j1 = 0;
            }
          }
        }
        if (millis() - Time5 >= Delay5) {
          Time5 = millis();
          h++; 
        }
        if (h <= o) { 
          state6 = HIGH;
          state3 = LOW;
          if (VaL2 == 80) {
            d = VaL2;
            e = 0;
          } else {
            if (VaL2 == 0) {
              e = 1;
            }
          }
          if (e == HIGH) {
            myservo1.write(0);
          } else {
            vaL2 = map(h,0,o,d,0);
            myservo1.write(vaL2);
            VaL2 = vaL2;
          }
        } else {
          if (h <= o*7) {
            f1++;
            if (f1 == 1) {
              f = 2;
            }
            if (h%o == 0) {
              n4++;
              if (n4 == 1) {
                f++;
              }
            } else {
              n4 = 0;
            }
            if (f%2 == 0) {
              vaL1 = map(h,o*(f-1),o*f,0,80);
              VaL1 = vaL1;
              state6 = LOW;
              state3 = HIGH;
            } else {
              vaL1 = map(h,o*(f-1),o*f,80,0);
              VaL1 = vaL1;
              state6 = HIGH;
              state3 = LOW;
            }           
          } else {
            VaL2 = 0;
            timer0_millis = 0;
            state1 = LOW;
          }
          myservo1.write(vaL1);
        }
        j2 = (o*7 - h + 58.5) / 65;
        if (j2 > 9) {
          lcd.setCursor(14,1);
          lcd.print(j2);
        } else {
          lcd.setCursor(14,1);
          lcd.print(0);
          lcd.print(j2);
        }
        digitalWrite(led3,state3);
        digitalWrite(led6,state6);
      }
    }
  } else { // 만약 전원이 꺼져있으면
    analogWrite(R,200);
    analogWrite(G,255);
    analogWrite(B,255);
    rotation1 = LOW;
    rotation2 = LOW;
    state2 = LOW;
    digitalWrite(led2, state2);
    state3 = LOW;
    digitalWrite(led3, state3);
    state6 = LOW;
    digitalWrite(led6, state6);
    state4 = LOW;
    dehydration = LOW;
    digitalWrite(k2,LOW);
    digitalWrite(k3,LOW);
    lcd.clear();
    lcd.noBacklight();
    if (t1> 0) {
      digitalWrite(k4,LOW);
      digitalWrite(k5,HIGH);
      if (millis() - Time8 > Delay7) {
        t1--;
        Time8 = millis();
      }
      On = LOW;
    } else {
      digitalWrite(k4,LOW);
      digitalWrite(k5,LOW);
      On = HIGH;
    }
    if (reset == HIGH) {
      VaL1 = 0;
      vaL1 = 0;
      VaL2 = 0;
      vaL2 = 0;
      z = 0;
    } else {
      if (millis() - Time3 >= Delay1) {
      Time3 = millis();
      z++; 
      }
    }
    if (z > 299) {
      reset = HIGH;
    }
    if (VaL1 > 0) {
      vaL1 = map(z,0,i,VaL1,0);
      myservo1.write(vaL1);
    } else {
      if (VaL2 > 0) {
        vaL2 = map(z,0,i,VaL2,0);
        myservo1.write(vaL2);
      } else {
        if (VaL2 == 0) {
          myservo1.write(0);
        }
      }
    }
    x = 0;
    y = 0;
    a = 0;
    b = 0;
    c = 0;
    h = 0;
    t = 0;
    f = 0;
    m = 0;
    n = 0; 
    f1 = 0;
    n1 = 0;
    m1 = 0;
    h1 = 0;
    h2 = 0;
  }
  if (millis() - TIME >= Delay3) {
    String list1[4] = {"V1:", "v1:", "V2:", "v2:"};
    int list2[4] = {VaL1, vaL1, VaL2, vaL2};
    for (int l=0; l<4; l++) {
      Serial.print(list1[l]);
      Serial.print(list2[l]);
      Serial.print(" ");
    }
    String list3[5] = {"S1:", "S2:", "S3:", "S4:", "S6:"};
    int list4[5] = {state1, state2, state3, state4, state6};
    for (int l=0; l<5; l++) {
      Serial.print(list3[l]);
      Serial.print(list4[l]);
      Serial.print(" ");
    }
    String list5[9] = {"A:", "B:", "C:", "D:", "E:", "X:", "Y:", "Z:", "N:"};
    int list6[9] = {a, b, c, d, e, x, y, z, n};
    for (int l=0; l<9; l++) {
      Serial.print(list5[l]);
      Serial.print(list6[l]);
      Serial.print(" ");
    }
    String list7[2] = {"K2:", "K3:"};
    int list8[2] = {4, 2};
    for (int l=0; l<2; l++) {
      Serial.print(list7[l]);
      Serial.print(digitalRead(list8[l]));
      Serial.print(" ");
    }
    Serial.print("H2:");
    Serial.print(h2);
    Serial.print(" ");
    Serial.print("Time:");
    Serial.println(millis());
    TIME = millis();
  }
}
