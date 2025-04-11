#ifndef __HEADER1_H__
#define __HEADER1_H__

#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))

#define GPIODEN_F (*((volatile uint32_t *)0x4005D51C))
#define GPIODIR_F (*((volatile uint32_t *)0x4005D400))
#define GPIODATA_F (*((volatile uint32_t *)0x4005D3FC))

#define GPIODEN_J (*((volatile uint32_t *)0x4006051C))
#define GPIODIR_J (*((volatile uint32_t *)0x40060400))
#define GPIOPUR_J (*((volatile uint32_t *)0x40060510))
#define GPIODATA_J (*((volatile uint32_t *)0x400603FC))

#define GPIODEN_N (*((volatile uint32_t *)0x4006451C))
#define GPIODIR_N (*((volatile uint32_t *)0x40064400))
#define GPIODATA_N (*((volatile uint32_t *)0x400643FC))

#endif // __HEADER1_H__