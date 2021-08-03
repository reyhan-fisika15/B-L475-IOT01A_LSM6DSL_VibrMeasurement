# Vibration Measurement using LSM6DSL Sensor Included with B-L475E-IOT01A Sensor
Vibration Measurement using LSM6DSL Accelerometer Sensor (included in B-L475E-IOT01A Discovery Board).
The measurement can be viewed using Visual C# app.

## Project Description
LSM6DSL is a system-in-package module by STMicroelectronics featuring 3D accelerometer, that can be used for measuring linear acceleration, and 3D gyroscope, that can be used for measuring angular acceleration. This sensor is included in ST's Discovery B-L475E-IOT01A board that can interfaced easily with I2C and included BSP library.
In this project I will use that sensor for measuring vibration based on linear acceleration caused by object motion which affected by vibration. For this case, I will simulate the vibration using loudspeaker and function generator to generate vibration that can be captured by LSM6DSL.

## Project Application
1. Digital Seismograph
2. Machinery Vibration Analysis
3. etc.

## Hardware
- B-L475E-IOT01A Discovery Kit board
- USB Micro-B cable
- Loudspeaker (small subwoofer is preferred)
- Function generator
- Audio amplifier module (you can build it yourself using LM386 IC or just buy PAM8403 class-D amplifier module)
- Power supply

## Software
- STM32CubeIDE
- Visual Studio 2019
- B-L475E-IOT01A BSP (Board Support Package)

## Hardware Setup
TODO

## Software
Here is the preview of Visual C# app used for displaying vibration data.
<image here>
