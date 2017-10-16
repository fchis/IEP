#include "pin.h"
#include <bcm2835.h>

/** Set only the Pin Number from Constructor */
Pin::Pin(int pin)
{
    this->pin_nr = pin;
    this->direction = 0;
    bcm2835_gpio_fsel(this->pin_nr, BCM2835_GPIO_FSEL_INPT);
    this->pull_up = 0;
}


/** Set only the Pin Number from Constructor and Direction */
Pin::Pin(int pin, int dir)
{
    this->pin_nr = pin;
    this->direction = dir;
    if(dir == 1)
    {
        bcm2835_gpio_fsel(this->pin_nr, BCM2835_GPIO_FSEL_OUTP);
    }
    else
    {
        bcm2835_gpio_fsel(this->pin_nr, BCM2835_GPIO_FSEL_INPT);
    }
    this->pull_up = 0;
}


/** Set all atributes from Constructor */
Pin::Pin(int pin, int dir, int pull_up)
{
    this->pin_nr = pin;
    this->direction = dir;
    if(dir == 1)
    {
        bcm2835_gpio_fsel(this->pin_nr, BCM2835_GPIO_FSEL_OUTP);
    }
    else
    {
        bcm2835_gpio_fsel(this->pin_nr, BCM2835_GPIO_FSEL_INPT);
    }
    this->pull_up = pull_up;
}


/** Method used to set the output */
void Pin::set(int Option)
{
  if(this->direction == 1)
  {
        if(Option == 0u)
        {
            bcm2835_gpio_write(this->pin_nr, LOW);
        }
        else if(Option == 1u)
        {
            bcm2835_gpio_write(this->pin_nr, HIGH);
        }
    }
    else
   {
    // Pin is set as Input, output can not be set
   }
}

/** Method used to get the value for inputs */
int Pin::getValue(void)
{
    return bcm2835_gpio_lev(this->pin_nr);
}
