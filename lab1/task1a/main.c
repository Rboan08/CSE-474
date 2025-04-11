#include <stdint.h>
#include "../lab1.h"

int main(void) {
  volatile unsigned short delay = 0;
  RCGCGPIO |= 0x20; // Enable PortF GPIO by setting bit 5 to 1
  delay++; // Delay 2 more cycles before access Timer registers (idiomatic)
  delay++; // Refer to Page. 756 of Datasheet for info
  GPIODEN_F = 0x11; // Set PF0/PF4 to enable digital function
  GPIODIR_F = 0x11; // Set PF0/PF4 to an output
  
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
    GPIODATA_N |= 0x2; // Turn on PN1 (D1)
    for (int j=0;j<1000000;j++) {}
    GPIODATA_N |= 0x01; // Turn on PN0 (D2)
    for (int j=0;j<1000000;j++) {}
    GPIODATA_F |= 0x10; // Turn on PF4 (D3)
    for (int j=0;j<1000000;j++) {}
    GPIODATA_F |= 0x1; // Turn on PF0 (D4)
    for (int j=0;j<1000000;j++) {}
    GPIODATA_N &= ~0x2; // Turn off PN1 (D1)
    for (int j=0;j<1000000;j++) {}
    GPIODATA_N &= ~0x01; // Turn off PN0 (D2)
    for (int j=0;j<1000000;j++) {}
    GPIODATA_F &= ~0x10; // Turn off PF4 (D3)
    for (int j=0;j<1000000;j++) {}
    GPIODATA_F &= ~0x1; // Turn off PF0 (D4)
    for (int j=0;j<1000000;j++) {}
  }
  return 0;
}
