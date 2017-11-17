#ifndef __NRF52_GPIO_H__
#define __NRF52_GPIO_H__

#include "nrf_gpio.h"
#include "gpio.h"

int32_t nrf52_gpio_init(uint8_t pin, uint8_t mode); 
int32_t nrf52_gpio_write(uint8_t pin, uint8_t value);
uint8_t nrf52_gpio_read(uint8_t pin);

extern GPIO_Driver_T nrf52_gpio_drv;

#endif//__NRF52_GPIO_H__
