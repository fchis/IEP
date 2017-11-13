#include "spi.h"
#include <bcm2835.h>
#include <stdint.h>

Spi::Spi(int bitOrder, int dataMode, int clockDivider, int chipSelect, int CSPolarity, int activeCS)
{

    bcm2835_spi_setBitOrder(bitOrder);
    bcm2835_spi_setDataMode(dataMode);
    bcm2835_spi_setClockDivider(clockDivider);
    bcm2835_spi_chipSelect(chipSelect);
    bcm2835_spi_setChipSelectPolarity(CSPolarity, activeCS);
    bcm2835_spi_begin();
}

uint8_t Spi::send_data(uint8_t send_data)
{
    return bcm2835_spi_transfer(send_data);
}


