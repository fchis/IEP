#include "pin.h"
#include <bcm2835.h>


/** Enum for Direction Values
BCM2835_GPIO_FSEL_INPT   -> Input 0b000
BCM2835_GPIO_FSEL_OUTP   -> Output 0b001
BCM2835_GPIO_FSEL_ALT0   -> Alternate function 0 0b100
BCM2835_GPIO_FSEL_ALT1   -> Alternate function 1 0b101
BCM2835_GPIO_FSEL_ALT2   -> Alternate function 2 0b110,
BCM2835_GPIO_FSEL_ALT3   -> Alternate function 3 0b111
BCM2835_GPIO_FSEL_ALT4   -> Alternate function 4 0b011
BCM2835_GPIO_FSEL_ALT5   -> Alternate function 5 0b010
BCM2835_GPIO_FSEL_MASK   -> Function select bits mask 0b111
*/


/** Set only the Pin Number from Constructor */
Pin::Pin(int pin)
{
    this->pin_nr = pin;
    this->direction = BCM2835_GPIO_FSEL_INPT;
    bcm2835_gpio_fsel(this->pin_nr, BCM2835_GPIO_FSEL_INPT);
    this->pull_up = BCM2835_GPIO_PUD_OFF;
    bcm2835_gpio_set_pud(this->pin_nr, BCM2835_GPIO_PUD_OFF);
}


/** Set only the Pin Number from Constructor and Direction */
Pin::Pin(int pin, int dir)
{
    this->pin_nr = pin;
    this->direction = dir;
    bcm2835_gpio_fsel(this->pin_nr, this->direction);
    this->pull_up = BCM2835_GPIO_PUD_OFF;
    bcm2835_gpio_set_pud(this->pin_nr, BCM2835_GPIO_PUD_OFF);
}


/** Set all atributes from Constructor */
Pin::Pin(int pin, int dir, int pull_up)
{
    this->pin_nr = pin;
    this->direction = dir;
    bcm2835_gpio_fsel(this->pin_nr, this->direction);
    this->pull_up = pull_up;
    bcm2835_gpio_set_pud(this->pin_nr, pull_up);
}


/** Method used to set the output */
void Pin::set(int Option)
{
  if(this->direction == BCM2835_GPIO_FSEL_OUTP)
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


/** Set the direction of the pin ... see enum above */
void Pin::changeDir(int new_Dir)
{
     this->direction = new_Dir;
     bcm2835_gpio_fsel(this->pin_nr, this->direction);
}


void Pin::set_eds(void)
{
    bcm2835_gpio_set_eds(this->pin_nr);
}


void Pin::enable_Low(void)
{
    bcm2835_gpio_len(this->pin_nr);
}

int Pin::get_eds(void)
{
    return bcm2835_gpio_eds(this->pin_nr);
}
