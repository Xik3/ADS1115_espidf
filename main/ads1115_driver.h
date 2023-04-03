#include <stdio.h>
#include "esp_log.h"
#include "driver/i2c.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "i2c-ads1115-example";

#define I2C_MASTER_SCL_IO           9                          /*!< GPIO number used for I2C master clock */
#define I2C_MASTER_SDA_IO           8                          /*!< GPIO number used for I2C master data  */
#define I2C_MASTER_NUM              0                          /*!< I2C master i2c port number, the number of i2c peripheral interfaces available will depend on the chip */
#define I2C_MASTER_FREQ_HZ          400000                     /*!< I2C master clock frequency */
#define I2C_MASTER_TX_BUF_DISABLE   0                          /*!< I2C master doesn't need buffer */
#define I2C_MASTER_RX_BUF_DISABLE   0                          /*!< I2C master doesn't need buffer */
#define I2C_MASTER_TIMEOUT_MS       1000

#define ADS1115_SENSOR_ADDR                 0x48        /*!< Slave address of the MPU9250 sensor */
#define ADS1115_CONFIG_REG                  0x01
#define ADS1115_CONV_REG                    0X00
#define ADS1115_CONFIG_MSB                  0xC2
#define ADS1115_CONFIG_LSB                  0x83


/*Driver functions initiation*/
uint16_t configure_ADS1115ADC(uint8_t address, uint8_t reg1, uint8_t reg2);
extern esp_err_t init_ADS1115ADC(void);