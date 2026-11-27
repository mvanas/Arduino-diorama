# 16 LED diorama with shift registers

Random lighting for a model train layout or diorama. 16 LEDs are driven by two chained 74HC595 shift registers, so only three Arduino pins are needed. A potentiometer sets the maximum random delay between lighting changes.

Wokwi simulation: https://wokwi.com/projects/364879086655198209

## What it does

The sketch picks a random pattern, runs it, then waits a random time:

- all LEDs off, one by one
- all LEDs on, one by one
- toggle every LED from left to right
- toggle every LED from right to left
- fluorescent tube start-up flicker on LED 0 or LED 15
- toggle one random LED (default pattern)

The wait is a random time between 2 s and a maximum set by the potentiometer on A0 (up to 20 s).

## Parts

- Arduino Uno (a Nano also works)
- 2 x 74HC595 shift register
- 16 x LED
- 16 x 180 ohm resistor
- 10 k potentiometer (delay)
- slide switch (wired to pin 13 in the diagram, not used by the sketch)

## Pins

| Arduino | 74HC595 | Function |
|---|---|---|
| D2 | DS (first register) | Data |
| D3 | STCP | Latch |
| D4 | SHCP | Clock |
| A0 | - | Potentiometer wiper |
| 5V / GND | VCC, MR / GND, OE | Power |

The second register gets its data from Q7S of the first one.

## Credits

The shift register code is based on the example from http://bildr.org/2011/02/74hc595/ and was adjusted for diorama lighting. The Wokwi diagram lists Anderson Costa as author.

## Files

- `sketch.ino` - Arduino sketch
- `diagram.json` - Wokwi circuit; paste it into a new Wokwi Arduino Uno project to simulate it
