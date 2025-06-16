from machine import I2C, Pin
import time
from mpu6050 import MPU6050

i2c = I2C(0, scl=Pin(9), sda=Pin(8))
mpu = MPU6050(i2c)

while True:
    accel = mpu.get_accel_data()
    gyro = mpu.get_gyro_data()
    print("Accel:", accel)
    print("Gyro:", gyro)
    time.sleep(1)
