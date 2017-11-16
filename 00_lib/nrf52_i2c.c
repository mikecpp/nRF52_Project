#include <stdio.h>

#include "boards.h"
#include "app_util_platform.h"
#include "nrf_delay.h"
#include "nrf_drv_twi.h" 
#include "app_error.h"

#include "nrf_i2c.h"  

I2C_Driver_T nrf_i2c_drv = 
{
    nrf_i2c_init,
    nrf_i2c_write_byte,
    nrf_i2c_read_byte,
    nrf_i2c_write, 
    nrf_i2c_read
};

static nrf_drv_twi_t m_i2c[2] = 
    { NRF_DRV_TWI_INSTANCE(0), 
      NRF_DRV_TWI_INSTANCE(1)  
    };  

int nrf_i2c_init(uint8_t id)
{
    uint32_t      ret_code;
    nrf_drv_twi_t *twi = &m_i2c[id];
    
#if defined(BOARD_SENSOR_TAG) 
    const nrf_drv_twi_config_t twi_arduino_config = {
       .scl                = 10,
       .sda                = 9,
       .frequency          = NRF_TWI_FREQ_250K,
       .interrupt_priority = APP_IRQ_PRIORITY_LOW,
       .clear_bus_init     = false
    };
#else    
    const nrf_drv_twi_config_t twi_arduino_config = {
       .scl                = ARDUINO_SCL_PIN,
       .sda                = ARDUINO_SDA_PIN,
       .frequency          = NRF_TWI_FREQ_100K,
       .interrupt_priority = APP_IRQ_PRIORITY_HIGH,
       .clear_bus_init     = false
    };
#endif
    
    ret_code = nrf_drv_twi_init(twi, &twi_arduino_config, NULL, NULL);
    APP_ERROR_CHECK(ret_code);      
    
    nrf_drv_twi_enable(twi); 
       
    return ret_code;
}

int nrf_i2c_write_byte(uint8_t id, uint8_t addr, uint8_t value)
{
    uint8_t    data = value;
    uint32_t   ret_code;
    nrf_drv_twi_t *twi = &m_i2c[id];
          
    ret_code = nrf_drv_twi_tx(twi, addr, &data, 1, false); 
    APP_ERROR_CHECK(ret_code); 
          
    return ret_code;
}

int nrf_i2c_read_byte(uint8_t id, uint8_t addr, uint8_t *value)
{
    uint32_t   ret_code;
    nrf_drv_twi_t *twi = &m_i2c[id];
    
    ret_code = nrf_drv_twi_rx(twi, addr, (uint8_t*) value, 1); 
    APP_ERROR_CHECK(ret_code); 
          
    return ret_code;
}

int nrf_i2c_write(uint8_t id, uint8_t addr, uint8_t *buf, int len)
{
    uint32_t ret_code;
    nrf_drv_twi_t *twi = &m_i2c[id];
    
    ret_code = nrf_drv_twi_tx(twi, addr, (uint8_t*) buf, len, false);
    APP_ERROR_CHECK(ret_code); 
    
    return ret_code;        
}

int nrf_i2c_read(uint8_t id, uint8_t addr, uint8_t *buf, int len) 
{
    uint32_t ret_code;
    nrf_drv_twi_t *twi = &m_i2c[id];
    
    ret_code = nrf_drv_twi_rx(twi, addr, (uint8_t*) buf, len);
    APP_ERROR_CHECK(ret_code); 
    
    return ret_code;    
}
