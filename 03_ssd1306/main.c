#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "app_uart.h"
#include "app_error.h"
#include "nrf_delay.h"
#include "nrf.h"
#include "bsp.h"

#define MAX_TEST_DATA_BYTES     (15U)                /**< max number of test bytes to be used for tx and rx. */
#define UART_TX_BUF_SIZE 256                         /**< UART TX buffer size. */
#define UART_RX_BUF_SIZE 256                         /**< UART RX buffer size. */

void uart_error_handle(app_uart_evt_t * p_event)
{
    if (p_event->evt_type == APP_UART_COMMUNICATION_ERROR) {
        APP_ERROR_HANDLER(p_event->data.error_communication);
    }
    else if (p_event->evt_type == APP_UART_FIFO_ERROR) {
        APP_ERROR_HANDLER(p_event->data.error_code);
    }
}

int main(void)
{
    uint32_t err_code;

    // bsp_board_leds_init();

    const app_uart_comm_params_t comm_params = {
        RX_PIN_NUMBER,
        TX_PIN_NUMBER,
        RTS_PIN_NUMBER,
        CTS_PIN_NUMBER,
        APP_UART_FLOW_CONTROL_ENABLED,
        false,
        UART_BAUDRATE_BAUDRATE_Baud115200
      };

    APP_UART_FIFO_INIT(&comm_params, UART_RX_BUF_SIZE,
                       UART_TX_BUF_SIZE, uart_error_handle,
                       APP_IRQ_PRIORITY_LOWEST, err_code);

    APP_ERROR_CHECK(err_code);
      
    printf("Hello Mike !\n");        

    int count = 0;
    
    while(1) {
        printf("Count = %d \r\n", count++);
        nrf_delay_ms(1000);
    }    
}
