#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

/* Overlaying struct onto base gives access to registers */
typedef struct
{
    uint32_t RESERVED0[321];
    uint32_t OUT;
    uint32_t OUTSET;
    uint32_t OUTCLR;
    uint32_t IN;
    uint32_t DIR;
    uint32_t DIRSET;
    uint32_t DIRCLR;
    uint32_t LATCH;
    uint32_t DETECTMODE;
    uint32_t RESERVED1[118];
    uint32_t PIN_CNF[32];
} GPIO_Type;

#define NRF_P0_BASE 0x50000000UL
#define NRF_P1_BASE 0x50000300UL

#define NRF_P0 ((GPIO_Type *)NRF_P0_BASE)
#define NRF_P1 ((GPIO_Type *)NRF_P1_BASE)

#define PIN_CNF_DIR_OUTPUT (1UL << 0)

#endif