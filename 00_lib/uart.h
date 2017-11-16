#ifndef __UART_H__
#define __UART_H__

#include <stdio.h>
#include <stdint.h>

#define UART_1      0 
#define UART_2      1 

#define UART_BAUD_9600      0
#define UART_BAUD_115200    1

typedef struct {
    int32_t (*uart_init)(uint8_t id, uint32_t baud_rate);
    int32_t (*uart_set_consol)(uint8_t id);
    int32_t (*uart_write)(uint8_t id, uint8_t *buf, uint16_t len);
    int32_t (*uart_read)(uint8_t id, uint8_t *buf, uint16_t len);
    uint8_t (*uart_getchar)(uint8_t id);
    int32_t (*uart_putchar)(uint8_t id, uint8_t ch);
    int32_t (*uart_available)(uint8_t id);
} UART_Driver_T;

int32_t uart_register_driver(UART_Driver_T *uart_driver);

int32_t uart_init(uint8_t id, uint32_t baud_rate);
int32_t uart_set_consol(uint8_t id);
int32_t uart_write(uint8_t id, uint8_t *buf, uint16_t len);
int32_t uart_read(uint8_t id, uint8_t *buf, uint16_t len);
uint8_t uart_getchar(uint8_t id);
int32_t uart_putchar(uint8_t id, uint8_t ch);
int32_t uart_available(uint8_t id);

#endif//__UART_H__
