/*
*
*     Simple ON/OFF Button
*
*     Hold the button to toggle the power
*
*
*     Author: Vinicius Knabben
*     Created: 09/08/2019
*/

#define BUTTON 7
#define GATE 8
#define DELAY 2000

bool _state = false;
long unsigned int _time = 0;

void setup() {
    pinMode(13,OUTPUT);
    pinMode(BUTTON,INPUT);
    digitalWrite(BUTTON,HIGH); // enable internal PullUp
    pinMode(GATE, OUTPUT);
    digitalWrite(GATE, LOW);
}

void loop() {

  if(digitalRead(BUTTON) == LOW) {   
      _time = millis();
      while(digitalRead(BUTTON) == LOW){
          if(millis() > (_time + DELAY)){
              _state = !_state;
              toggle(_state);
              break;    
          }
      }     
      while(digitalRead(BUTTON) == LOW); // wait for user to release the button to avoid another toggle
  }     
}

void toggle (bool state) {
  if(_state) {
      digitalWrite(13,HIGH);
      digitalWrite(GATE,HIGH);
      return 1;
  } else {
      digitalWrite(13,LOW);
      digitalWrite(GATE,LOW);
      return 0;
  }
}
