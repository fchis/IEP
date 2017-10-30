#ifndef PIN_H
#define PIN_H

#define OFF_VALUE               0u
#define ON_VALUE                1u

class Pin
{
public:
    Pin(int pin);
    Pin(int pin, int dir);
    Pin(int pin, int dir, int pull_up);
    void set(int Option);
    int getValue(void);
    void changeDir(int new_Dir);
    void set_eds(void);
    int get_eds(void);
    void enable_Low(void);

private:
    int pin_nr;
    int pull_up; // 0- no, 1- yes
    int direction;
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

};

#endif // PIN_H
