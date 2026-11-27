# 8 LED diorama

Simple lighting for a model train layout or diorama with 8 LEDs directly on the pins of an Arduino Nano. LEDs switch on and off randomly at random intervals, so the scene looks lived in.

Wokwi simulation: https://wokwi.com/projects/364533086125248513

## What it does

- The first LED (D2, white) simulates a fluorescent tube and flickers a few times when it switches on.
- LEDs on D3 to D7 (orange) are switched on and off one at a time, all on, all off, or flipped from left to right and from right to left.
- The last two LEDs (D8 blue, D9 purple) flash alternately and quickly for a short time to simulate a welding torch.
- After each action the sketch waits a random 1.2 to 3.5 seconds.

## Parts

- Arduino Nano (an Uno also works)
- 8 x LED (4 x orange, 1 x white, 1 x blue, 1 x purple in the diagram, any colours work)
- 8 x 330 ohm resistor

## Pins

| Arduino | LED |
|---|---|
| D2 | White, fluorescent tube |
| D3 to D7 | Orange room lights |
| D8, D9 | Welding (blue, purple) |
| GND | Common cathode of all LEDs |

Each LED has its own 330 ohm series resistor.

## Files

- `sketch.ino` - Arduino sketch
- `diagram.json` - Wokwi circuit; paste it into a new Wokwi Arduino Nano project to simulate it
