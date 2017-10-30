#include <bcm2835.h>
#include <stdio.h>
#include <pwm.h>
#include <pin.h>

// Note that this is the _only_ PWM pin available on the RPi IO headers
#define PIN RPI_GPIO_P1_12

// PIN for BUTTON
#define PIN_BUTTON RPI_GPIO_P1_15
// and it is controlled by PWM channel 0
#define PWM_CHANNEL 0
// This controls the max range of the PWM signal
#define RANGE 1000

#define STEP 100 /** 100 means 10% */


void normal_code(Pwm pwm_to_use, Pin button)
{
    if(button.get_eds())
    {
        /** Button is pressed */
        button.set_eds();
        pwm_to_use.setDutyCycle(pwm_to_use.getDutyCycle() + STEP);
    }
    delay(500);
}

void debug_code(Pwm pwm_to_use)
{
    printf("Press the button!");
    getchar();
    printf("Good job! You pressed the button!\n");
    pwm_to_use.setDutyCycle(pwm_to_use.getDutyCycle() + STEP);
    printf("\nWe are here: %d\n",pwm_to_use.getDutyCycle());
}


int main(int argc, char **argv)
{
    /** RPI_GPIO_P1_11 - 17
     *  BCM2835_GPIO_FSEL_ALT5 - allow PWM channel 0 to be output there
     *  0 - no relevance in this case */
    Pin pin_to_use =  Pin(PIN,BCM2835_GPIO_FSEL_ALT5);
    Pin button = Pin(PIN_BUTTON, BCM2835_GPIO_FSEL_INPT, BCM2835_GPIO_PUD_UP);
    button.enable_Low();
    Pwm pwm_to_use = Pwm(BCM2835_PWM_CLOCK_DIVIDER_16,0,PWM_CHANNEL, RANGE);
    while(1)
    {
        normal_code(pwm_to_use, button);
        // debug_code(pwm_to_use);
    }
    bcm2835_close();
    return 0;
}
