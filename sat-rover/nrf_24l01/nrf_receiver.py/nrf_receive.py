from machine import Pin, SPI
from nrf24l01 import NRF24L01
import time

# SPI0 on Pico: SCK=GP4, MOSI=GP3, MISO=GP2
spi = SPI(0, sck=Pin(4), mosi=Pin(3), miso=Pin(2))
csn = Pin(6, Pin.OUT)
ce = Pin(5, Pin.OUT)

nrf = NRF24L01(spi, csn, ce, payload_size=32)
nrf.open_tx_pipe(b'\xD2\xF0\xF0\xF0\xF0')
nrf.open_rx_pipe(1, b'\xE1\xF0\xF0\xF0\xF0')
nrf.start_listening()

while True:
    if nrf.any():
        msg = nrf.recv()
        print("Received:", msg.decode())
    time.sleep(0.5)
