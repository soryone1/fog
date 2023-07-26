Programming Fog
===========
This is an Arduino library designed to be used with my own board - Programming Fog. With this board, you can easily control all liquid mist related projects, such as DIY humidifiers, DIY aromatherapy machines, and any other projects or installations you can imagine.

I implements two features which normal boards in those devices don't provide:

* Be able to start the fog and stop the fog.
* Be able to control the fog amount based on a simple 5v analogRead value.

## Pin Connections

* VCC -> 5V
* GND -> GND
* A0 -> Analog Pin

## Functions

#### FogInit

```cpp
void Fog::FogInit() 
```
Do the Init in the Setup(), this will setup all the base requirement to use the board.

#### FogOn

```cpp
void Fog::FogOn()
```
This will start a continuous spray at maximum power.

#### FogOff

```cpp
void Fog::FogOff()
```
This will stop the spray completely.

#### FogAnalog

```cpp
void Fog::FogAnalog(int inputValue)
```
This will control the amount of fog in real time by reading in the analog signal ranging from 0 - 1023.

## Acknowledgements

Thanks for Deqing Sun and Felix Praschak's support!
