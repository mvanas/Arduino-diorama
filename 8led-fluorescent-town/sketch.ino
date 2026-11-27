void setup() {
  /* This sets 8 leds on pins D2 to D9 to output */
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT); // sets pins to output
    }
  randomSeed(analogRead(0));
  }

void loop() {

  int pickme = random(1,11); // picks a random pattern of LED patterns (1-10)
	switch(pickme) {
    case 1:
    fillall();
    break;
    
	  case 2:
    Fluorescent();
    delay(random(400,1200));
    break;
		
    case 3:
    digitalWrite(3, !digitalRead(3));
    delay(random(400,1200));
    break;

    case 4:
    digitalWrite(4, !digitalRead(4));
    delay(random(400,1200));
    break;

    case 5:
    digitalWrite(5, !digitalRead(5));
    delay(random(400,1200));
    break;

    case 6:
    digitalWrite(6, !digitalRead(6));
    delay(random(400,1200));
    break;

    case 7:
    digitalWrite(7, !digitalRead(7));
    delay(random(400,1200));
    break;

    case 8:
    digitalWrite(8, !digitalRead(8));
    delay(random(400,1200));
    break;

    case 9:
    digitalWrite(9, !digitalRead(9));
    delay(random(400,1200));
    break;

    case 10:
    clearall();
    break;

  }

  delay(1200);
  
}

//**************************************************
void clearall() {
	for (int pin = 2; pin <= 9; pin++) {
		digitalWrite(pin,LOW);
	}
}

void fillall() {
	for (int pin = 2; pin <= 9; pin++) {
		digitalWrite(pin, HIGH);
	}
}

void Fluorescent() {
  /* Similate the starting of a fluorescent light by random blink the LED a few times */
  for (int i = 1; i <= random(5, 9); i++) {
    digitalWrite(2, LOW);
    delay(random(60, 350));
    digitalWrite(2, HIGH);
    delay(random(60, 200));
  }
}