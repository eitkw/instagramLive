#include <IRremote.h>

int RECV_PIN = 8;

IRrecv irrecv(RECV_PIN);

decode_results results;



void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
}

int f1 = 0;
int f2 = 0;
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    if (results.value == 16738455) {
      if (f1) {
        f1 = 0;
        digitalWrite(3,LOW);
      }
      else {
        f1 = 1;
        digitalWrite(3,HIGH);
      }
    }
    else if (results.value == 16756815) {
      if (f2) {
        f2 = 0;
        digitalWrite(4,LOW);
      }
      else {
        f2 = 1;
        digitalWrite(4,HIGH);
      }
    }
    irrecv.resume();
  }
}
