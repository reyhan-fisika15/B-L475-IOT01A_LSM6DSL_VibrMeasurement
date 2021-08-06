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
- RT-Thread Studio
- Visual Studio 2019
- B-L475E-IOT01A BSP (Board Support Package) and Latest RT-Thread RTOS

## Hardware Setup
![setup](https://user-images.githubusercontent.com/57849203/128018378-8dfddde6-cc35-4c48-a18d-7f4c740b32a3.jpg)

## Result
Captured data using Visual C# and SerialPlot:
![gambar](https://user-images.githubusercontent.com/57849203/128017665-9f29a945-ce84-406e-94b4-f94f481f69e6.png)
![gambar](https://user-images.githubusercontent.com/57849203/128030504-4d20613c-06b9-4bb1-8e99-efbd29be828f.png)

Video link: https://streamable.com/rn0sxq

