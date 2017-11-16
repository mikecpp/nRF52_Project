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
#include "ssd1306.h"
#include "gui.h"

int main(void)
{
    uart_register_driver(&nrf52_uart_drv);
    i2c_register_driver(&nrf52_i2c_drv);

    uart_init(UART_1, UART_BAUD_115200);
    printf("Hello Mike !\n");           
   
    GUI_Register(&ssd1306_gui_interface);
    GUI_Init();    
    GUI_SetFont(&Font24);
    GUI_Clear(GUI_COLOR_BLACK);     
    
    GUI_SetBackColor(GUI_COLOR_BLACK);
    GUI_SetTextColor(GUI_COLOR_WHITE);
    GUI_DisplayStringAt(0, 0, (uint8_t*) "Hello", GUI_CENTER_MODE); 
    GUI_Update();    
    
    int  count = 0;
    char msg[32];
    
    while(1) {
        printf("Count = %d \r\n", count);
        sprintf(msg, "%d", count);
        GUI_DisplayStringAt(0, 32, (uint8_t*) msg, GUI_CENTER_MODE);         
        GUI_Update();    
        nrf_delay_ms(1000);
        count++;
    }    
}
