

/**
    AUTH: Abiria Placide
 * main.c
 */
#include <stdint.h>
#include "tm4c123gh6pm.h"

#define RED_LED   (1 << 1)
#define GREEN_LED (1 << 3)
#define BLUE_LED  (1 << 2)

#define PORTFENABLE (1 << 5)
void inithw()
{
    SYSCTL_RCGCGPIO_R |= PORTFENABLE;
    __delay_cycles(3);

    GPIO_PORTF_DIR_R |= RED_LED | BLUE_LED | GREEN_LED;
    GPIO_PORTF_DEN_R |= RED_LED | BLUE_LED | GREEN_LED;

}

int main(void)
{
    inithw();
    while(1)
    {
        GPIO_PORTF_DATA_R ^= BLUE_LED;
        __delay_cycles(4000000);
    }
}
