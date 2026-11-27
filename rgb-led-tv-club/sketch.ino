/*
 *
 *
 */

const int PIN_RED   = 9;
const int PIN_GREEN = 6;
const int PIN_BLUE  = 5;

void setup() {
  pinMode(PIN_RED,   OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE,  OUTPUT);
}

void loop() {

  setColor(138,43,226);
  delay(100);
  setColor(75,0,130);
  delay(80);
  setColor(230,230,250);
  delay(100);
  setColor(255,255,204);
  delay(120);
  setColor(255,215,0);
  delay(85);
  setColor(135,206,250);
  delay(100);
  setColor(25,25,112);
  delay(75);


  setColor(0,0,0);
  delay(1500);

}

void setColor(int R, int G, int B) {
  analogWrite(PIN_RED,   255 - R);
  analogWrite(PIN_GREEN, 255 - G);
  analogWrite(PIN_BLUE,  255 - B);
}