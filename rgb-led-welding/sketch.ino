/*
 *
 *
 */

const int PIN_RED   = 11;
const int PIN_GREEN = 10;
const int PIN_BLUE  = 9;
int weldingError;

void setup() {
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
}


void loop() {
  
  weldingLight();
  
  if (random(0,10) > 6) {
    meltingSteel();
  }
  
  delay(random(3500,8000)); //Wait between 3.5 -8 Seconds

}

void setColor(int R, int G, int B) {
  analogWrite(PIN_RED,   R);
  analogWrite(PIN_GREEN, G);
  analogWrite(PIN_BLUE,  B);
}

void weldingLight() {
  uint8_t repeat = random(16, 28);
  for ( int i = 0 ; i <= repeat ; i++) {
    setColor(random(0,100),random(0,255),random(100,255));
    delay(random(5,50));
    setColor(random(0,55),random(0,55),random(0,55));
    delay(random(5,55));
    setColor(0,0,0);
  }
}

void meltingSteel() {
   for (int i = 0 ; i <=180 ; i++) { //Yellow -> Orange -> Red
    int red = 255;
    int green = (180-i);
    int blue = 0;
    setColor(red,green,blue);
    delay(i/15);
  }
  for (int i = 0 ; i <=255 ; i++) { // Red fading out
    int red = (255-i);
    int green = 0;
    int blue = 0;
    setColor(red,green,blue);
    delay(i/16);
  }
  setColor(0,0,0);
}