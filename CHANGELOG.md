# Change / Development Log

## Hardware prototype 2

### Fixes

* Connect MP pins of J1 to GND strip across the top edge of the board

## Driver release 1

TODO

## Hardware prototype 1

### 5 April 2023

First prototype run of boards arrived. Issue identified where MP on J1 was not connected to the GND strip across the top edge of the board, which would compromise strength of J1 and possibly lead to J1 being ripped off the board under mechanical stress.

### Serial 1

Used a LOT of flux and SnBi low-temperature solder on a hotplate. Solder reflow worked ok (not great, but not unusable), but would probably work better using less solder and/or an actual stencil.  Shorts between the following pins:

* P0_0 - P0_3
* P1_2 - P2_0
* P3_0 - P2_5
* P2_7 - P2_6

Pin headers added using SnPb 60/40 solder.

Communication established using Excamera I2Cdriver board. Verified all GPIOs can be changed from hi-z inputs to push-pull outputs. Verified all GPIOs are connected, and show both 3.3V and 0V levels when output level is set. Verified LED using current-sinking on P4_1.

### Serial 2

TODO
