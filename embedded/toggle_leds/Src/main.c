#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>


#define _PERIPH_BASE          0x40000000UL
#define _BUS_BASE_AHBI_OFFSET 0x00020000UL
#define _BUS_BASE_AHB1        (_PERIPH_BASE + _BUS_BASE_AHBI_OFFSET)

#define _AHB1_GPIOD_OFFSET    0x00000C00UL
#define _AHB1_RCC_OFFSET      0x00003800UL

#define _RCC_BASE             (_BUS_BASE_AHB1 + _AHB1_RCC_OFFSET)

#define _GPIOX_MODE_R_OFFSET  0x00UL
#define _GPIOX_OD_R_OFFSET    0x14UL

#define _GPIOD_BASE           (_BUS_BASE_AHB1 + _AHB1_GPIOD_OFFSET)
#define _GPIOD_MODE_R         (*(volatile unsigned int *) (_GPIOD_BASE + _GPIOX_MODE_R_OFFSET))
#define _GPIOD_OD_R           (*(volatile unsigned int *) (_GPIOD_BASE + _GPIOX_OD_R_OFFSET))

#define _RCC_AHB1EN_R_OFFSET  0x30UL
#define _RCC_AHB1EN_R_BASE    (*(volatile unsigned int *) (_RCC_BASE + _RCC_AHB1EN_R_OFFSET))


void delay ( uint32_t ui32Count ) {
    for(uint32_t ui32Iter = 0; ui32Iter < ui32Count; ui32Iter++);
}

int main(void)
{
  _RCC_AHB1EN_R_BASE |= (1UL << 3);

  // Set GPIO PD13 (LD3) to output mode
  _GPIOD_MODE_R |= (1UL << 24);
  _GPIOD_MODE_R &=~ (1UL << 25);

  // Set GPIO PD12 (LD4) to output mode
  _GPIOD_MODE_R |= (1UL << 26);
  _GPIOD_MODE_R &=~ (1UL << 27);

  // Set GPIO PD14 (LD5) to output mode
  _GPIOD_MODE_R |= (1UL << 28);
  _GPIOD_MODE_R &=~ (1UL << 29);

  // Set GPIO PD15 (LD6) to output mode
  _GPIOD_MODE_R |= (1UL << 30);
  _GPIOD_MODE_R &=~ (1UL << 31);

  while ( true ) {
    /* Set GPIO PD 12, 13, 14, 15 pins to 1 in output data registers */
    _GPIOD_OD_R ^= (1U << 12);
    _GPIOD_OD_R ^= (1U << 13);
    _GPIOD_OD_R ^= (1U << 14);
    _GPIOD_OD_R ^= (1U << 15);

    delay(1000000);
  }
}
