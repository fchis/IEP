#ifndef SPI_H
#define SPI_H
#include <stdint.h>
#include "serial.h"

class Spi : public Serial
{
public:
    Spi(int bitOrder, int dataMode, int clockDivider, int chipSelect, int CSPolrarity, int activeCS);
    uint8_t send_data(uint8_t send_data);
};

#endif // SPI_H
