#ifndef __HEADER1_H__
#define __HEADER1_H__

#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))

#define GPIODEN_F (*((volatile uint32_t *)0x4005D51C))
#define GPIODIR_F (*((volatile uint32_t *)0x4005D400))
#define GPIODATA_F (*((volatile uint32_t *)0x4005D3FC))

#define GPIODEN_J (*((volatile uint32_t *)0x4006051C))
#define GPIODIR_J (*((volatile uint32_t *)0x40060400))
#define GPIOPUR_J (*((volatile uint32_t *)0x40060510))

#endif // __HEADER1_H__
