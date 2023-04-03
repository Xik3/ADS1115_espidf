/* i2c - Simple example

   Simple I2C example that shows how to initialize I2C
   as well as reading and writing from and to registers for a sensor connected over I2C.

   The sensor used in this example is a MPU9250 inertial measurement unit.

   For other examples please check:
   https://github.com/espressif/esp-idf/tree/master/examples

   See README.md file to get detailed usage of this example.

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <stdio.h>
#include "esp_log.h"
#include "driver/i2c.h"
#include "esp_err.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "ads1115_driver.h"


void app_main(void)
{
    //uint8_t data[2];
    ESP_ERROR_CHECK(init_ADS1115ADC());
    ESP_LOGI(TAG, "I2C initialized successfully");

    while(1){
        float voltage = (configure_ADS1115ADC(ADS1115_SENSOR_ADDR, ADS1115_CONFIG_MSB, ADS1115_CONFIG_LSB)*4.096)/(32767*1);
    
        ESP_LOGI(TAG, "ADC value: %d, Voltage: %.2fV", configure_ADS1115ADC(ADS1115_SENSOR_ADDR, ADS1115_CONFIG_MSB, ADS1115_CONFIG_LSB), voltage);
    
        vTaskDelay(2000 / portTICK_PERIOD_MS); // Wait 1 second before reading again
    }

    ESP_ERROR_CHECK(i2c_driver_delete(I2C_MASTER_NUM));
    ESP_LOGI(TAG, "I2C de-initialized successfully");
}
