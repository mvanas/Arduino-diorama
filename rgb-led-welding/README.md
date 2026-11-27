# RGB LED welding effect

A welding light for a model train layout or diorama, using a single RGB LED. It needs only three PWM pins and three resistors.

Wokwi simulation: https://wokwi.com/projects/365253880279768065

## What it does

- Welding flashes: 16 to 28 quick random flashes in blue-white tones, with short dark pauses in between.
- Melting steel: with a chance of about 30% after the flashes, the LED fades from yellow through orange to red and then fades out, like cooling hot metal.
- Then it waits a random 3.5 to 8 seconds and starts again.

## Parts

- Arduino Uno (a Nano also works)
- 1 x RGB LED, common cathode
- 3 x 220 ohm resistor

## Pins

| Arduino | RGB LED |
|---|---|
| D11 (PWM) | Red, via 220 ohm |
| D10 (PWM) | Green, via 220 ohm |
| D9 (PWM) | Blue, via 220 ohm |
| GND | Common cathode |

For a common anode LED, connect the common pin to 5V and invert the values in `setColor()` (255 minus the value).

## Files

- `sketch.ino` - Arduino sketch
- `diagram.json` - Wokwi circuit; paste it into a new Wokwi Arduino Uno project to simulate it
