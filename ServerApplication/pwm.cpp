#include "pwm.h"
#include <bcm2835.h>

/** Constructor for Pwm Object */
Pwm::Pwm(int frequency, int dutycycle, int channel, int range)
{
    this->frequency = frequency;
    this->channel = channel;
    this->range = range;
    this->dutycycle = dutycycle;

    bcm2835_pwm_set_clock(this->frequency);
    bcm2835_pwm_set_range(this->channel, this->range);

/********************************************************************************
    [in]	channel	The PWM channel. 0 or 1.
    [in]	markspace	Set true if you want Mark-Space mode. 0 for Balanced mode.
    [in]	enabled	Set true to enable this channel and produce PWM pulses.
**********************************************************************************/
    bcm2835_pwm_set_mode(this->channel, 1, 1);
    bcm2835_pwm_set_data(this->channel, this->dutycycle);
}


/** Method used to set the PWM output, important value must be lower than the range */
void Pwm::setDutyCycle(int targetDutyCycle)
{
    if(targetDutyCycle > this->range)
    {
        /** can't have higher value than 100% */
        this->dutycycle = 0;
    }
    else
    {
        this->dutycycle = targetDutyCycle;
    }

    bcm2835_pwm_set_data(this->channel, this->dutycycle);
}

/** Method used to set the frequency for PWM */
void Pwm::setFrequency(int targetFrequency)
{
    this->frequency = targetFrequency;
    bcm2835_pwm_set_clock(this->frequency);
}


/** Method used to get the actual PWM dutycycle */
int Pwm::getDutyCycle(void)
{
    return this->dutycycle;
}



/** Method used to get the frequency of the PWM */
int Pwm::getFrequency(void)
{
    return this->frequency;
}
