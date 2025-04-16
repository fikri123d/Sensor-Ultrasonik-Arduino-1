#include <Arduino.h>

const int echoPin= 2;
const int trigPin= 3;

const int ledMerahPin=6;
const int ledHijauPin=7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(ledMerahPin, OUTPUT);
  pinMode(ledHijauPin, OUTPUT);
}

//membuat fungsi ultransonik untuk mendapatkan jarak dari sensor ultrasonik
float ultrasonik(){
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int durasiPantulan = pulseIn(echoPin,HIGH);

//membuat nilai dari fungsi ultrasonik menjadi hasil perhitungan durasi *0,034/2
return durasiPantulan *0.034/2;
}


void loop() {
  // put your main code here, to run repeatedly:
  float jarak = ultrasonik();

  if (jarak >= 10){

    digitalWrite(ledHijauPin, HIGH);
    digitalWrite(ledMerahPin, LOW);

    Serial.println("tidak ada objek");
  } else {
    digitalWrite(ledHijauPin, LOW);
    digitalWrite(ledMerahPin, HIGH);

    Serial.println("ada objek");
  }
  
  delay(1000);
}
