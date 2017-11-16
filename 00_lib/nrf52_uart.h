#ifndef __NRF52_UART_H__
#define __NRF52_UART_H__

#include "nrf.h"
#include "uart.h"
#include "app_uart.h"

int32_t nrf52_uart_init(uint8_t id, uint32_t baud_rate);
int32_t nrf52_uart_set_consol(uint8_t id);
int32_t nrf52_uart_write(uint8_t id, uint8_t *buf, uint16_t len);
int32_t nrf52_uart_read(uint8_t id, uint8_t *buf, uint16_t len);
uint8_t nrf52_uart_getchar(uint8_t id);
int32_t nrf52_uart_putchar(uint8_t id, uint8_t ch);
int32_t nrf52_uart_available(uint8_t id);

extern UART_Driver_T nrf52_uart_drv;

#endif//__NRF52_UART_H__
