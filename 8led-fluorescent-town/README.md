# 8 LED fluorescent tube and town lights

An effect for a model train layout or diorama: one LED imitates a fluorescent tube that flickers from time to time, while the other LEDs randomly switch on and off to simulate lights in a building or a town.

Wokwi simulation: https://wokwi.com/projects/364528282739764225

## What it does

- The sketch picks a random action every loop and then waits.
- Fluorescent tube (D2): the LED blinks 5 to 8 times with random short pauses, like a tube that is starting up or failing.
- Town lights (D3 to D9): one LED at a time is toggled on or off.
- Fill all: now and then all LEDs are switched on.
- The delay between actions is random, roughly 1.6 to 2.4 seconds.

## Parts

- Arduino Nano (an Uno also works)
- 6 x white LED and 2 x red LED (any colours work)
- 4 x 220 ohm resistor (D2 to D5) and 4 x 1 k ohm resistor (D6 to D9; the higher value gives dimmer lights)

## Pins

| Arduino | LED |
|---|---|
| D2 | White, fluorescent tube (220 ohm) |
| D3 to D5 | White, town lights (220 ohm) |
| D6, D7 | White, town lights (1 k ohm) |
| D8, D9 | Red, town lights (1 k ohm) |
| GND | Common cathode of all LEDs |

## Files

- `sketch.ino` - Arduino sketch
- `diagram.json` - Wokwi circuit; paste it into a new Wokwi Arduino Nano project to simulate it
