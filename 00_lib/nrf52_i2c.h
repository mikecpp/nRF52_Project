#ifndef __NRF_nrf_i2c_H__
#define __NRF_nrf_i2c_H__

#include <stdio.h>
#include "app_error.h" 
#include "nrf.h"
#include "i2c.h"

int nrf_i2c_init(uint8_t id); 
int nrf_i2c_write_byte(uint8_t id, uint8_t addr, uint8_t value); 
int nrf_i2c_read_byte(uint8_t id, uint8_t addr, uint8_t *value);
int nrf_i2c_write(uint8_t id, uint8_t addr, uint8_t *buf, int len);
int nrf_i2c_read(uint8_t id, uint8_t addr, uint8_t *buf, int len);

extern I2C_Driver_T nrf_i2c_drv;

#endif//__NRF_nrf_i2c_H__
