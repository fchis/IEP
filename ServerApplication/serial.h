#ifndef SERIAL_H
#define SERIAL_H
#include <stdint.h>


class Serial
{
public:
    virtual uint8_t send_data(uint8_t send_data) = 0;
};

#endif // SERIAL_H
