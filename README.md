# Anemometer based on ultrasonic waves.

## Description
This project pretends to develop an Anemometer free of the common issues anemometers have and only dependent of its own measures avoiding weather conditions constants (with a special approach that tries to avoid using or approximating sound speed). The device will optimize resources using cheap and non-mobile parts exposed to mechanical wear out.

The project is divided by steps of approach according to each necessary feature.

Common anemometers have several problems:
* Need of a special calibration that should be done inside a wind tunnel for each physical change.
* Dependency of specific random constants, provided by the shape and the angle of attack of the cups and quantity of cups.
* Very limited range of wind speed.
* Use of mechanical parts that could suffer wear use under hostile weather, like bearings getting rusty.
* Need of optical/magnetic encoder, in the cases they are homemade, they tend to have poor resolution.
* For wind direction measure a "wind vane" gets necessary, in the cases they are homemade preserving an absolute reference with an encoder is a complex task.

## Hardware
This project will be approached using the hardware described below:
* A Microchip microcontroller from pic18 family, 18F2550.
* 16mm Waterproof ultrasonic Chinese transducers 40kHz.
* Filtering electronics.
* Power supply electronics.

### Filtering
With the purpose of detect the incoming signal at the receiver is necessary to develop a band-pass or high-pass filter. There are two ways of filtering the signal, It can be programmed in the microcontroller, acquiring analogue samples and applying digital filters but it can also be physically implemented using operational amplifiers. According to the scope of this project is more convenient to use the hardware (meaning op-amp) option due to the requirements of a microcontroller with the features to do the signal processing (Analog sampling, MIPS).

## Software
* PICC CCS.
* Proteus for simulation.
* Mat lab to build and test the equations system willing to be independent of sound speed constant.
