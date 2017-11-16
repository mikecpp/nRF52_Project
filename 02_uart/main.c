#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "app_uart.h"
#include "app_error.h"
#include "nrf_delay.h"
#include "nrf.h"
#include "bsp.h"
#include "uart.h"
#include "nrf52_uart.h"

#define MAX_TEST_DATA_BYTES     (15U)                /**< max number of test bytes to be used for tx and rx. */
#define UART_TX_BUF_SIZE 256                         /**< UART TX buffer size. */
#define UART_RX_BUF_SIZE 256                         /**< UART RX buffer size. */

int main(void)
{
    uart_register_driver(&nrf52_uart_drv);
    uart_init(UART_1, UART_BAUD_115200);
    
    printf("Hello Mike !\n");        

    int count = 0;
    
    while(1) {
        printf("Count = %d \r\n", count++);
        nrf_delay_ms(1000);
    }    
}
