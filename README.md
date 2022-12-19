# STM32-SDI12
Its a [SDI-12](https://www.sdi-12.org/) library for [STM32](https://www.st.com/en/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus.html) microcontrollers.

## Method
Single UART/IO pin is toggled between RX and TX. Compatible pins will depend on the STM32 microcontroller you are using. 

## Tested on
- [x] STM32L476RG (not 5V tolerant! level shifter is required)
- [x] STM32L073RZ (5V tolerant on pin PA9) by [@dajtxx](https://github.com/dajtxx)

## Supports
*Where **a** or **b** is a devices address and **n** is a stored data index.*
- [x] Acknowledge active (**a**!)
- [x] Send identification (**a**I!)
- [x] Change address (**a**A**b**!)
- [x] Start measurement (**a**M!)
- [x] Send data (**a**D**n**!) where **n** = 0 to 9
- [x] Start verification (**a**V!)
- [ ] Start concurrent measurement (**a**C!)

## License
This work is MIT licensed as found in the [LICENSE](https://github.com/HarveyBates/STM32-SDI12/blob/master/LICENSE) file.
