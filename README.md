The Sat-Rover project is a dual-module robotics and embedded system solution consisting of a satellite module and a rover module. 
It demonstrates intelligent environmental monitoring, wireless communication, autonomous navigation, solar energy tracking, and IoT-based control. 
The satellite module collects data using sensors like BMP180 (for temperature and pressure), MPU6050 (for acceleration and gyroscopic data), and MQ3 (for gas detection), all interfaced with microcontrollers (ESP32 or similar) using MicroPython. 
This data is transmitted wirelessly to the rover via NRF24L01 modules. 
The rover module is equipped to interpret and utilize this data, offering multiple functional units: an intelligent object-following car (using IR/ultrasonic sensors), a solar tracking system (which orients a solar panel using LDRs and servo motors for optimal sunlight exposure), and a servo tilt mechanism (controlled via Blynk for camera or sensor adjustment). 
The rover also includes embedded C-based control code for motor control, sensor integration, and autonomous behavior. 
The entire system showcases real-world use cases such as industrial monitoring, mobile logistics, environmental sensing,
and smart control using IoT and renewable energy, making it ideal for applications in education, automation, and sustainable technology demonstrations.
