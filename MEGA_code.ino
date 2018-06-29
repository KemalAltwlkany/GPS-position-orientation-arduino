#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7,8);

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();

}

void loop() {
  if (radio.available()){
    float niz[5];
    radio.read(&niz, sizeof(niz));
    /*
    Serial.println("------------------------------------------------------------------------------------------------------------------------------------");
    Serial.print("1. element ( x koor gps ) == ");
    Serial.println(niz[0],7);
    Serial.print("2. element ( y koor gps ) == ");
    Serial.println(niz[1],7);
    Serial.print("3. element (roll) == ");
    Serial.println(niz[2]);
    Serial.print("4. element (pitch) == ");
    Serial.println(niz[3]);
    Serial.print("5. element (yaw) == ");
    Serial.println(niz[4]);
    */
    Serial.print(1111);
    Serial.print(" ");
    Serial.print(niz[0],7);
    Serial.print(" ");
    Serial.print(niz[1],7);
    Serial.print(" ");
    Serial.print(niz[2],7);
    Serial.print(" ");
    Serial.print(niz[3],7);
    Serial.print(" ");
    Serial.print(niz[4],7);
    Serial.println(" ");
  }
  delay(200);
}
