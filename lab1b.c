#include <stdint.h>
#include "../lab1.h"

int main(void) {
  volatile unsigned short delay = 0;  
  RCGCGPIO |= 0x1000; // Enable PortN GPIO by setting bit 12 to 1
  delay++;
  delay++;
  GPIODEN_N = 0x3; // PN0/PN1 to digital function
  GPIODIR_N = 0x3; // PN0/PN1 to output
  
  RCGCGPIO |= 0x100; // Enable PortJ GPIO by setting bit 8 to 1
  delay++;
  delay++;
  GPIODEN_J = 0x3; // Set PJ0 and PJ1 to enable digital function
  GPIODIR_J = 0x0; // Set PJ0 and PJ1 explicitly to be input
  GPIOPUR_J = 0x3; // Set PJ0 and PJ1 to enable pull-up resistors
  while (1) {
    if ((GPIODATA_J & 0x1) == 0) { // if SW1 (PJ0) is pressed
      // Turn on D1 (PN1)
      GPIODATA_N |= 0x2;
    }
    if ((GPIODATA_J & 0x2) == 0) { // if SW2 (PJ1) is pressed
      // Turn on D0 (PN0)
      GPIODATA_N |= 0x1;
    }
  }
  return 0;
}
