

/**
 * main.c
 */
#include <stdint.h>
#include "tm4c123gh6pm.h"

#define RED_LED   (1 << 1)
#define GREEN_LED (1 << 3)
#define BLUE_LED  (1 << 2)

#define PORTFENABLE (1 << 5)

#define PERI_REF 0x40000000
#define PERI_BASE 0x42000000

#define BIT_BAND_PERI(a,b) ((PERI_BASE + (a-PERI_REF)*32 +(b*4)))

#define RED_BAND *((volatile uint32_t *)(BIT_BAND_PERI(0x400253FC,1)))
#define BLUE_BAND *((volatile uint32_t *)(BIT_BAND_PERI(0x400253FC,2)))
#define GREEN_BAND *((volatile uint32_t *)(BIT_BAND_PERI(0x400253FC,3)))

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
        BLUE_BAND ^= 1; //read modify write 3cyles
        __delay_cycles(4000000);
    }
}
