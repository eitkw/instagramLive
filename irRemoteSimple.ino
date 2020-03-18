#include <IRremote.h>

int RECV_PIN = 8;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    if (results.value == 16769565) {
      digitalWrite(2, HIGH);
    }
    else if (results.value == 16736925) {
      digitalWrite(3, HIGH);
    }
    else if (results.value == 16750695) {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
    }
    irrecv.resume();
  }
}
