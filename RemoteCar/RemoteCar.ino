#include <IRremote.h>
int RECV_PIN = 15;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  irrecv.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    switch(results.value) {
      case 33478695:
        digitalWrite(12,LOW);
        digitalWrite(13,HIGH);
        delay(500);
        digitalWrite(12,LOW);
        digitalWrite(13,LOW);
        break;
      case 33468495:
        digitalWrite(12,HIGH);
        digitalWrite(13,LOW);
        delay(500);
        digitalWrite(12,LOW);
        digitalWrite(13,LOW);
        break;
      }
    irrecv.resume();
  }
}
