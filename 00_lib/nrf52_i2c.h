#ifndef __NRF52_NRF_I2C_H__
#define __NRF52_NRF_I2C_H__

#include <stdio.h>
#include "nrf_delay.h"
#include "nrf_drv_twi.h" 
#include "app_error.h"
#include "app_util_platform.h"
#include "nrf.h"
#include "i2c.h"

int32_t nrf_i2c_init(uint8_t id); 
int32_t nrf_i2c_write_byte(uint8_t id, uint8_t addr, uint8_t value); 
int32_t nrf_i2c_read_byte(uint8_t id, uint8_t addr, uint8_t *value);
int32_t nrf_i2c_write(uint8_t id, uint8_t addr, uint8_t *buf, int32_t len);
int32_t nrf_i2c_read(uint8_t id, uint8_t addr, uint8_t *buf, int32_t len);

extern I2C_Driver_T nrf52_i2c_drv;

#endif//__NRF52_NRF_I2C_H__
