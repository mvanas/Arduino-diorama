/*
   Arduino code for Individual control over each pin
   Support for 40+ 74HC595 8 bit shift registers
   http://bildr.org/2011/02/74hc595/

   Program adjusted to control multiple LEDs for diorama
*/

#define DATA_PIN  2  // Pin connected to DS of 74HC595
#define LATCH_PIN 3  // Pin connected to STCP of 74HC595
#define CLOCK_PIN 4 // Pin connected to SHCP of 74HC595
#define NUM_SHIFT_REGS 2 // How many of the shift registers

const uint8_t MAX_LEDS = NUM_SHIFT_REGS * 8;
const int MIN_DELAY = 2000;
const int MAX_DELAY = 20000;

int potpin = 0;

bool registers[MAX_LEDS];

void setup() {
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  clearRegisters();
  writeRegisters();
  Serial.begin(9600);
  randomSeed(analogRead(5));
}

void loop() {

  uint8_t pattern = random(1,15); // picks a random pattern of LED patterns
  Serial.print(pattern);
  Serial.print("\t");

  switch(pattern) {
    case 1: //Pattern_1: All off
      pattern1();
    break;

    case 2: // Pattern_2: All on
      pattern2();
    break;
    
    case 3: // Pattern_3: Toggle state of all LEDs Left to Right
      pattern3();
    break;

    case 4: // Pattern_4: Toggle state of all LEDs Right to Left
      pattern4();
    break;

    case 5: //Pattern_5: Similate fluorescent light on LED0
      fluorescent(0);
    break;

    case 6: //Pattern_6: Similate fluorescent light on LED15
      fluorescent(15);
    break;

    // case 6: // Next Pattern

    default: // Default Pattern: Randomly toggle a LED
      defaultPattern();
    break;
  }

  wait();

}

void pattern1() { //Pattern_1: All off
  for (uint8_t i = 0 ; i <= MAX_LEDS - 1; i++) {
    setRegisterPin(i , LOW);
    writeRegisters();
    wait(); //add random delay between switching off each LED
  }
}

void pattern2() { //Pattern_1: All on
  for (uint8_t i = 0 ; i <= MAX_LEDS - 1; i++) {
    setRegisterPin(i , HIGH);
    writeRegisters();
    wait(); //add random delay between switching on each LED
  }
}

void pattern3() { // Pattern_3: Toggle state of all LEDs Left to Right
  for (int i = 0 ; i <= MAX_LEDS - 1; i++) {
    setRegisterPin(i , !registers[i]); // Toggle state
    writeRegisters();
    wait(); //add random delay between toggle state of each LED
  }
}

void pattern4() { // Pattern_4: Toggle state of all LEDs Right to Left
  for (int i = MAX_LEDS - 1 ; i >= 0; i--) {
    setRegisterPin(i , !registers[i]); // Toggle state
    writeRegisters();
    wait(); //add random delay between toggle state of each LED
  }
}

void fluorescent(uint8_t flPin) { // Similate the starting of a fluorescent light by random blink the LED a few times
  if (registers[flPin] == LOW) { // Only flash LED when it is currently off
    for (int i = 1; i <= random(6, 11); i++) {
      setRegisterPin(flPin, LOW);
	    writeRegisters();
      delay(random(60, 350));
      setRegisterPin(flPin, HIGH);
	    writeRegisters();
      delay(random(60, 200));
    }
  }
  else {
    setRegisterPin(flPin, LOW); //Switch off LED when currently on
	  writeRegisters();
  }
}

void defaultPattern() { // Toggle a random led on or off
  int i = random(0, MAX_LEDS); // 0 to MAX_LEDS-1, so all 16 LEDs can be picked
  setRegisterPin(i , !registers[i]); // Toggle state
  writeRegisters();
}

void clearRegisters() {   // Reset all register pins
  for (int i = MAX_LEDS - 1; i >= 0; i--) {
    registers[i] = LOW;
  }
}

void setRegisterPin(int index, int maxDelayue) { // Set an individual pin HIGH or LOW
  registers[index] = maxDelayue;
}

void writeRegisters() { // Set and display registers
  digitalWrite(LATCH_PIN, LOW);

  for (int i = MAX_LEDS - 1; i >= 0; i--) {
    digitalWrite(CLOCK_PIN, LOW);
    digitalWrite(DATA_PIN, registers[i]);
    digitalWrite(CLOCK_PIN, HIGH);
  }

  digitalWrite(LATCH_PIN, HIGH);
}

void wait() { // Random delay
  int maxDelay;
  maxDelay = analogRead(potpin); // Read pot value
  maxDelay = map(maxDelay, 0, 1023, MIN_DELAY, MAX_DELAY); // Map pot value to max delay
  delay(random(MIN_DELAY, maxDelay+1)); // Wait randum time set between min delay and max delay from pot
}