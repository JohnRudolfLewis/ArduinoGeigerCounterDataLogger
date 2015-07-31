# Arduino Geiger Counter Data Logger

Me and my son wanted to do a cool science project with our shared high-powered rocketry hobby. We decided to 
attempt to measure the difference in background radiation between ground level and apogee.

The geiger counter kit was soldered together by my son. The code to get the data from the geiger counter and
the barometric sensor and write them to the SD card was written by me.

## Parts

 * [Arduino Micro] (http://www.adafruit.com/products/1086)
 * [mightyohm.com Geiger Counter] (http://mightyohm.com/blog/products/geiger-counter/)
 * [BMP180 Barometric Pressure/Temperature/Altitude Sensor](http://www.adafruit.com/product/1603)
 * [MicroSD card breakout board] (http://www.adafruit.com/products/254)

## Setup

Connections:

 * Arduino D11 to MicroSD CS
 * Arduino SCK to MicroSD CLK
 * Arduino MOSI to MicroSD DI
 * Arduino MISO to MicroSD DO
 * Arduino SDA to BMP180 SDA
 * Arduino SCL to BMP180 SCL
 * Arduino RX to Geiger J2 pin 5

 * Arduino 3V to BMP180 VIN
 * Arduino 3V to MicroSD 3V 
 * Arduino 3V to Geiger J6 pin 1
 * Arduino GND to MicroSD and BMP180 GND
 * Arduino GND to Geiger J6 pin 3

<img src="https://pbs.twimg.com/media/CAHHUbwVAAAepSg.jpg:large"/>

## Libraries Needed

* https://github.com/adafruit/Adafruit_Sensor.git
* https://github.com/adafruit/Adafruit_BMP085_Unified.git

## Sample Outout:

| Time  | Pressure | AGL   | CPS | CPM | uSv/hr |
|-------|----------|-------|-----|-----|--------|
| 2026  | 1001.40  | -0.34 | 1   | 2   | 0.01   |
| 3022  | 1001.42  | -0.51 | 0   | 2   | 0.01   |
| 4020  | 1001.37  | -0.08 | 0   | 2   | 0.01   |
| 5016  | 1001.39  | -0.25 | 0   | 2   | 0.01   |
| 6012  | 1001.37  | -0.08 | 0   | 2   | 0.01   |
| 7009  | 1001.38  | -0.17 | 1   | 3   | 0.01   |
| 8005  | 1001.42  | -0.51 | 2   | 5   | 0.02   |
| 9001  | 1001.45  | -0.76 | 0   | 5   | 0.02   |
| 9998  | 1001.40  | -0.34 | 0   | 5   | 0.02   |
| 10994 | 1001.40  | -0.34 | 0   | 5   | 0.02   |
| 11991 | 1001.36  | 0.00  | 0   | 5   | 0.02   |
| 12987 | 1001.41  | -0.42 | 2   | 7   | 0.03   |
| 13983 | 1001.41  | -0.42 | 0   | 7   | 0.03   |
| 14980 | 1001.41  | -0.42 | 1   | 8   | 0.04   |
| 15976 | 1001.40  | -0.34 | 0   | 8   | 0.04   |
| 16972 | 1001.36  | 0.00  | 0   | 8   | 0.04   |
| 17969 | 1001.36  | 0.00  | 1   | 9   | 0.05   |
| 18965 | 1001.37  | -0.08 | 0   | 9   | 0.05   |
| 19961 | 1001.36  | 0.00  | 0   | 9   | 0.05   |
| 20958 | 1001.36  | 0.00  | 0   | 9   | 0.05   |
| 21954 | 1001.37  | -0.08 | 0   | 9   | 0.05   |

## Results from an actual flight

<img src="http://rocket.aspzone.com/wp-content/uploads/2015/07/Messages-Image230408612.png" />

[In flight video] (https://www.youtube.com/watch?v=tYMYLdCidDs)
