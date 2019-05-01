# Anemometer based on ultrasonic.

## Description
This project pretends to develop an Anemometer free of the problems of common anemometers and only dependent of it self meassures avoiding weather conditions consntants (here we are going to try to avoid using or aproximanting sound speed). The device might optimize resources using cheap and non-mobile parts open to mechanical wear out.

The project is divided by steps of approach of each necesary feature.

Common anemometers has several problems:
* Needing of special calibration in a wind tunnel.
* Dependency of specific random constants, provided by the shape and the atack angle of the cups, quantity of cups.
* Very limited range of wind speed.
* Use of mechanical parts that could suffer wear under hostile weather, like bearings getting rust.
* Needs some optical or magnetic encoder, in case this are homemade, they would have a poor resolution.
* For wind direction meassure is necesary a "wind vane", in case this is homemade preserve a absolute refference with an encoder is a complex task.

## Hardware
This project will be aproached on the hardware described below:
* A Microchip microcontroller from pic18 family, 18F2550.
* 16mm Waterproof ultrasonic chinese transducers 40kHz.
* Filtering electronics.
* Power supply electronics.

### Filtering
In purpose to detect the arriving of the signal at the receiver is necesary to develop a band-pass or high-pass filter for the incoming signal. This might be programmed in the microcontroller, acquiring analogue samples and applying digital filters or physically implemented with operational amplificators. According with the scope of this project is more convinient to use the hardware option due to the requirements of a microcontroller with the features to do the signal processing (Analog sampling, MIPS).

## Software
* PICC CCS.
* Proteus for simulation.
* Matlab to build and test the equations system willing to be independet of sound speed constant.
