from machine import I2C, Pin
import time
import bmp180

i2c = I2C(0, scl=Pin(9), sda=Pin(8))
bmp = bmp180.BMP180(i2c)
bmp.oversample_sett = 2
bmp.sea_level_pressure = 101325

while True:
    print("Temperature:", bmp.temperature)
    print("Pressure:", bmp.pressure)
    print("Altitude:", bmp.altitude)
    time.sleep(2)
