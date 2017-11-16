#include "uart.h"

UART_Driver_T *m_uart_drv = NULL;

int32_t uart_register_driver(UART_Driver_T *uart_driver)
{
    m_uart_drv = uart_driver;
    
    return 0;
}

int32_t uart_init(uint8_t id, uint32_t baud_rate)
{
    if(m_uart_drv == NULL) {
        return -1;
    }    
    
    return m_uart_drv->uart_init(id, baud_rate);
}

int32_t uart_set_consol(uint8_t id)
{
    if(m_uart_drv == NULL) {
        return -1;
    }    
    
    return m_uart_drv->uart_set_consol(id);
}

int32_t uart_write(uint8_t id, uint8_t *buf, uint16_t len)
{
    if(m_uart_drv == NULL) {
        return -1;
    }    
    
    return m_uart_drv->uart_write(id, buf, len);
}

int32_t uart_read(uint8_t id, uint8_t *buf, uint16_t len)
{
    if(m_uart_drv == NULL) {
        return -1;
    }    
    
    return m_uart_drv->uart_read(id, buf, len);
}

uint8_t uart_getchar(uint8_t id)
{
    if(m_uart_drv == NULL) {
        return 0;
    }    
    
    return m_uart_drv->uart_getchar(id);
}

int32_t uart_putchar(uint8_t id, uint8_t ch)
{
    if(m_uart_drv == NULL) {
        return -1;
    }    
    
    return m_uart_drv->uart_putchar(id, ch);
}

int32_t uart_available(uint8_t id)
{
    if(m_uart_drv == NULL) {
        return -1;
    }    
    
    return m_uart_drv->uart_available(id);    
}
