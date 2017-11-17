#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "nrf_delay.h"
#include "nrf.h"
#include "bsp.h"
#include "uart.h"
#include "nrf52_uart.h"
#include "i2c.h"
#include "nrf52_i2c.h"
#include "oled1602.h"

int main(void)
{
    uart_register_driver(&nrf52_uart_drv);
    i2c_register_driver(&nrf52_i2c_drv);

    uart_init(UART_1, UART_BAUD_115200);
    printf("Hello Mike !\n");           
   
    oled1602_init(0);
    
    oled1602_clear();
    oled1602_cursor(0, 0);
    oled1602_puts("Hello Mike"); 
    
    int count = 0;
    char msg[32];
    
    while(1) {
        sprintf(msg, "Count = %d", count++);
        oled1602_cursor(0, 1);
        oled1602_puts(msg);
        nrf_delay_ms(1000);
    }       
    
    return 0;
}
