
#include <NintendoExtensionCtrl.h>
#define RED_PIN 4


NESMiniController nes;

void setup() {
	Serial.begin(9600);
	nes.begin();
  pinMode(RED_PIN,OUTPUT);

  
  //controlo se il controller è connesso
	while (!nes.connect()) {
		digitalWrite(RED_PIN,1);
		delay(1000);
	}
}

void loop() {

	boolean success = nes.update();  // vedo se ho aggiornamenti

	if (!success) {  // Ruh roh
    digitalWrite(RED_PIN,1);
		delay(1000);
    digitalWrite(RED_PIN,0);
    delay(1000);
	}
	else {
		// Read the DPAD (Up/Down/Left/Right)
		boolean padUp = nes.dpadUp();
		if (padUp == true) {
			Serial.write(1);
      delay(100);
		}
    boolean padDown = nes.dpadDown();
    if (padDown == true) {
			Serial.write(2);
      delay(100);
		}
    boolean padLeft = nes.dpadLeft();
    if (padLeft == true) {
			Serial.write(3);
      delay(100);
		}
    boolean padRight = nes.dpadRight();
    if (padRight == true) {
			Serial.write(4);
      delay(100);
		}
	}
}
