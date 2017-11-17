#include "nrf52_gpio.h"

GPIO_Driver_T nrf52_gpio_drv =  
{
    .gpio_init  = nrf52_gpio_init,
    .gpio_write = nrf52_gpio_write,
    .gpio_read  = nrf52_gpio_read,
};

int32_t nrf52_gpio_init(uint8_t pin, uint8_t mode)
{
    
    return 0;
}

int32_t nrf52_gpio_write(uint8_t pin, uint8_t value)
{
    
    return 0;
}

uint8_t nrf52_gpio_read(uint8_t pin)
{
    
    return 0; 
}
