#ifndef PWM_H
#define PWM_H


class Pwm
{
public:
    Pwm(int frequency, int dutycycle, int channel, int range);
    int getFrequency(void);
    int getDutyCycle(void);
    void setFrequency(int targetFrequency);
    void setDutyCycle(int targetDutyCycle);

private:
    int frequency;
    int dutycycle;
    int channel;
    int range;
};

#endif // PWM_H
