#include "gpio.h"

/* Row 1 = P0.21, Col 1 = P0.28*/
#define ROW1_PIN 21
#define COL1_PIN 28

static void delay (volatile uint32_t count) {
    while (count--) {
        __asm__("nop");
    }
}

void main(void) {
    NRF_P0->PIN_CNF[ROW1_PIN] = PIN_CNF_DIR_OUTPUT;
    NRF_P0->PIN_CNF[COL1_PIN] = PIN_CNF_DIR_OUTPUT;

    NRF_P0->OUTCLR = (1UL << COL1_PIN);

    while(1) {
        NRF_P0->OUTSET = (1UL << ROW1_PIN);
        delay(5000000);
        NRF_P0->OUTCLR = (1UL << ROW1_PIN);
        delay(5000000);
    }
}