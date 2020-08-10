# led-sensor-adc


avr-gcc -mmcu=atmega328p main.c -o main.out

avr-objcopy -j .text -j .data -O ihex main.out main.hex

avrdude -p atmega328p -c arduino -P /dev/ttyUSB0 -U flash:w:main.hex  (replace your USB drive)
