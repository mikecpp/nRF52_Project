#include "nrf52_uart.h"

#define UART_RX_PIN_NUMBER      8
#define UART_TX_PIN_NUMBER      6
#define UART_RTS_PIN_NUMBER     7
#define UART_CTS_PIN_NUMBER     5

#define MAX_DATA_LEN        32
#define UART_TX_BUF_SIZE    256  
#define UART_RX_BUF_SIZE    256

UART_Driver_T nrf52_uart_drv = {
    .uart_init          = nrf52_uart_init,
    .uart_set_consol    = nrf52_uart_set_consol,
    .uart_write         = nrf52_uart_write,
    .uart_read          = nrf52_uart_read,
    .uart_getchar       = nrf52_uart_getchar,
    .uart_putchar       = nrf52_uart_putchar,
    .uart_available     = nrf52_uart_available
};

static void uart_event_handle(app_uart_evt_t * p_event)
{
    switch (p_event->evt_type)
    {
        /*
        case APP_UART_DATA_READY:
            UNUSED_VARIABLE(app_uart_get((uint8_t*) &m_ch));
            break;
        */
        case APP_UART_COMMUNICATION_ERROR:
            APP_ERROR_HANDLER(p_event->data.error_communication);
            break;

        case APP_UART_FIFO_ERROR:
            APP_ERROR_HANDLER(p_event->data.error_code);
            break;

        default:
            break;
    }
}

//////////////////////////////////////////////////////////////////////////////
// Public API

int nrf52_uart_init(uint8_t id, uint32_t baud_rate)  
{
    uint32_t err_code;
    uint32_t baud;
    
    switch(baud_rate) {
        case UART_BAUD_9600:
            baud = UART_BAUDRATE_BAUDRATE_Baud9600;
            break;
        case UART_BAUD_115200:
            baud = UART_BAUDRATE_BAUDRATE_Baud115200;
            break;
        default:
            baud = UART_BAUDRATE_BAUDRATE_Baud115200;
            break;
    }    
    
    const app_uart_comm_params_t comm_params =
    {
        UART_RX_PIN_NUMBER,  UART_TX_PIN_NUMBER,
        UART_RTS_PIN_NUMBER, UART_CTS_PIN_NUMBER,
        APP_UART_FLOW_CONTROL_DISABLED, false,
        baud
    };

    APP_UART_FIFO_INIT( &comm_params, UART_RX_BUF_SIZE,
                       UART_TX_BUF_SIZE, uart_event_handle,
                       APP_IRQ_PRIORITY_LOWEST, err_code);
     
    return err_code;
}

int32_t nrf52_uart_set_consol(uint8_t id)
{
    return 0;
}

int32_t nrf52_uart_write(uint8_t id, uint8_t *buf, uint16_t len)
{
    return 0;
}

int32_t nrf52_uart_read(uint8_t id, uint8_t *buf, uint16_t len)
{
    return 0;
}

uint8_t nrf52_uart_getchar(uint8_t id)
{
    return 0;
}

int32_t nrf52_uart_putchar(uint8_t id, uint8_t ch)
{
    return 0;
}

int32_t nrf52_uart_available(uint8_t id)
{
    return 0;
}
