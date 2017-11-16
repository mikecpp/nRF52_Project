#include "nrf52_i2c.h"  

#define NRF52_I2C_SCL       27  // ARDUINO_SCL_PIN
#define NRF52_I2C_SDA       26  // ARDUINO_SDA_PIN
#define NRF52_I2C_FREQ      NRF_TWI_FREQ_100K

I2C_Driver_T nrf52_i2c_drv = 
{
    .i2c_init        = nrf_i2c_init,
    .i2c_write_byte  = nrf_i2c_write_byte,
    .i2c_read_byte   = nrf_i2c_read_byte,
    .i2c_write       = nrf_i2c_write, 
    .i2c_read        = nrf_i2c_read
};

static nrf_drv_twi_t m_i2c[2] = 
    { NRF_DRV_TWI_INSTANCE(0), 
      NRF_DRV_TWI_INSTANCE(1)  
    };  

int32_t nrf_i2c_init(uint8_t id)
{
    uint32_t      ret_code;
    nrf_drv_twi_t *twi = &m_i2c[id];
    
    const nrf_drv_twi_config_t twi_arduino_config = {
       .scl                = NRF52_I2C_SCL,
       .sda                = NRF52_I2C_SDA,
       .frequency          = NRF52_I2C_FREQ,
       .interrupt_priority = APP_IRQ_PRIORITY_HIGH,
       .clear_bus_init     = false
    };
    
    ret_code = nrf_drv_twi_init(twi, &twi_arduino_config, NULL, NULL);
    
    nrf_drv_twi_enable(twi); 
       
    return ret_code;
}

int32_t nrf_i2c_write_byte(uint8_t id, uint8_t addr, uint8_t value)
{
    uint8_t    data = value;
    uint32_t   ret_code;
    nrf_drv_twi_t *twi = &m_i2c[id];
          
    ret_code = nrf_drv_twi_tx(twi, addr, &data, 1, false); 
          
    return ret_code;
}

int32_t nrf_i2c_read_byte(uint8_t id, uint8_t addr, uint8_t *value)
{
    uint32_t   ret_code;
    nrf_drv_twi_t *twi = &m_i2c[id];
    
    ret_code = nrf_drv_twi_rx(twi, addr, (uint8_t*) value, 1); 
          
    return ret_code;
}

int32_t nrf_i2c_write(uint8_t id, uint8_t addr, uint8_t *buf, int32_t len)
{
    uint32_t ret_code;
    nrf_drv_twi_t *twi = &m_i2c[id];
    
    ret_code = nrf_drv_twi_tx(twi, addr, (uint8_t*) buf, len, false);
    
    return ret_code;        
}

int32_t nrf_i2c_read(uint8_t id, uint8_t addr, uint8_t *buf, int32_t len) 
{
    uint32_t ret_code;
    nrf_drv_twi_t *twi = &m_i2c[id];
    
    ret_code = nrf_drv_twi_rx(twi, addr, (uint8_t*) buf, len);
    
    return ret_code;    
}
