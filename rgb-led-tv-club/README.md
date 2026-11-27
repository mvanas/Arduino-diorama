# RGB LED TV and bar/club light

One RGB LED that imitates the changing light of a TV in a living room, or the coloured lights of a bar or club, for a model train layout or diorama. It needs only three PWM pins and three resistors.

Wokwi simulation: https://wokwi.com/projects/364635810595846145

## What it does

The sketch cycles quickly through seven colours (violet, indigo, lavender, light yellow, gold, light blue and dark blue), each shown for 75 to 120 ms. Then the LED goes dark for 1.5 seconds and the sequence starts again. The fast colour changes look like a screen showing a film or like party lighting.

To change the effect, edit the colours and delays in `loop()`: `setColor(R, G, B)` takes values from 0 to 255.

## Parts

- Arduino Nano (an Uno also works)
- 1 x RGB LED, common anode
- 3 x 1 k ohm resistor (high value for a soft, dim glow)

## Pins

| Arduino | RGB LED |
|---|---|
| D9 (PWM) | Red, via 1 k ohm |
| D6 (PWM) | Green, via 1 k ohm |
| D5 (PWM) | Blue, via 1 k ohm |
| 3.3V | Common anode |

The LED has a common anode (connected to 3.3V in the diagram), so the sketch inverts the PWM values in `setColor()` (255 minus the value). With a common cathode LED, connect the common pin to GND and remove the inversion.

## Files

- `sketch.ino` - Arduino sketch
- `diagram.json` - Wokwi circuit; paste it into a new Wokwi Arduino Nano project to simulate it
