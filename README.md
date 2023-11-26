# HC-SR04 Thing
A simple HC-SR04 distance sensor Thing.

## Hardware setup
 - HC-SR04 Vcc - D1_mini 5V
 - HC-SR04 Trig - D1_mini D8
 - HC-SR04 Echo - D1_mini D7
 - HC-SR04 Gnd - D1_mini G
 
# Configure
Create a data directory with two files: mqtt.txt and wifi.txt.
The mqtt.txt file should contain the following fields one per line
```
server
port
username
password
```

The wifi.txt file should contain ssids and passwords, one combination per two lines
```
ssid
password
ssid
password
...
```

# Run
```
pio run -e d1_mini -t uploadfs -v
pio run -e d1_mini -t upload -v
pio device monitor
```