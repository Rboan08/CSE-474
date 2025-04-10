#include <stdint.h>
#include "lab1.h"

int main(void) {
  volatile unsigned short delay = 0;
  RCGCGPIO |= 0x20; // Enable PortF GPIO by setting bit 5 to 1
  delay++; // Delay 2 more cycles before access Timer registers (idiomatic)
  delay++; // Refer to Page. 756 of Datasheet for info
  GPIODEN_F = 0x1; // Set PF0 to enable digital function
  GPIODIR_F = 0x1; // Set PF0 to an output
  GPIODATA_F = 0x1; // Set PF0 to 1
  
  RCGCGPIO |= 0x100; // Enable PortJ GPIO by setting bit 8 to 1
  delay++;
  delay++;
  GPIODEN_J = 0x3; // Set PJ0 and PJ1 to enable digital function
  GPIODIR_J = 0x0; // Set PJ0 and PJ1 explicitly to be input
  GPIOPUR_J = 0x3; // Set PJ0 and PJ1 to enable pull-up resistors
  while (1) {}
  return 0;
}
