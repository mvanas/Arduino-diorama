/* Small program I use for controlling the lights in a modeltrain/diorama.
   LEDs will randomly turn on or off and at a rondom time interval.
   1st LED (pin2) simulates a fluorescent light and flickers a few times on startup.
   Last two lights (pin8,9) flashes quickly for a short duration to  simulates a welding torch.
*/


void setup() {
  /* This sets 8 leds on pins D2 to D9 to output */
  Serial.begin(9600);
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT); // sets pins to output
    }
  }

void loop() {
  int pattern = random(1,12); // picks a random pattern of LED patterns
  Serial.print(pattern);
  Serial.print("\t");
	switch(pattern) {
    case 1:
    //activate all LEDs
    Serial.println("Activate all LEDs");
    fillall();
    break;
    
	  case 2:
    Serial.println("Fluorescent");
    fluorescent(2);
    break;
		
    case 3:
    Serial.println("Flip LED 2");
    digitalWrite(3, !digitalRead(3));
    break;

    case 4:
    Serial.println("Flip LED 3");
    digitalWrite(4, !digitalRead(4));
    break;

    case 5:
    Serial.println("Flip LED 4");
    digitalWrite(5, !digitalRead(5));
    break;

    case 6:
    Serial.println("Flip LED 5");
    digitalWrite(6, !digitalRead(6));
    break;

    case 7:
    Serial.println("Flip LED 6");
    digitalWrite(7, !digitalRead(7));
    break;

    case 8:
    //digitalWrite(8, !digitalRead(8));
    Serial.println("Welding");
    welding(8, 9);
    break;

    case 9:
    //digitalWrite(9, !digitalRead(9));
    Serial.println("Welding");
    welding(8, 9);
    break;

    case 10:
    Serial.println("Clearall");
    clearall();
    break;

    case 11:
    Serial.println("Flip left to right");
    flipleftright();
    break;

    case 12:
    Serial.println("Flip right to left");
    fliprightleft();
    break;

  }
  
  delay(random(1200,3500));
  
}

//**************************************************
void clearall() {
	for (int pin = 2; pin <= 9; pin++) {
    // loop through all pins and turn all
		digitalWrite(pin,LOW);
    delay(random(600, 2000));
	}
}

void fillall() {
  // loop through all pins and turn all LEDs on
	for (int pin = 3; pin <= 7; pin++) {
		digitalWrite(pin, HIGH);
    delay(random(600, 2000));
	}
  digitalWrite(2, LOW);
  fluorescent(2);
}

void flipleftright() {
  // loop through all pins from low to high and flip current status
	fluorescent(2);
  for (int pin = 3; pin <= 7; pin++) {
		digitalWrite(pin, !digitalRead(pin));
    delay(random(1200, 3500));
	}
}

void fliprightleft() {
  // loop through all pins from low to high and flip current status
	for (int pin = 7; pin >= 3; pin--) {
		digitalWrite(pin, !digitalRead(pin));
    delay(random(1200, 3500));
	}
  fluorescent(2);
}


void fluorescent(int pin_a) {
  // Similate the starting of a fluorescent light by random blink the LED a few times
  
  if (digitalRead(pin_a) == LOW) { 
    digitalWrite(pin_a, HIGH);
    delay(40);
    for (int i = 1; i <= random(6, 11); i++) {
      digitalWrite(pin_a, LOW);
      delay(random(60, 350));
      digitalWrite(pin_a, HIGH);
      delay(random(60, 200));
    }
  }
  else {
    digitalWrite(pin_a, LOW);
  }
}

void welding(int pin_a, int pin_b) {
  //flashes 2 LED to simulate a welding light
  
  for (int i = 1; i <= random(4, 11); i++) {
    for (int j = 1; j <= random(4,8); j++) {
      digitalWrite(pin_a, HIGH);
      digitalWrite(pin_b, LOW);
      delay(random(10,30));
      digitalWrite(pin_a, LOW);
      digitalWrite(pin_b, HIGH);
      delay(random(10,30));
    }
  digitalWrite(pin_a, LOW);
  digitalWrite(pin_b, LOW);
  delay(random(250, 450));
  }
}