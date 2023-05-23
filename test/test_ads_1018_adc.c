#include <stdint.h>
#include <stdbool.h>
#include "unity.h"

#include "ADS1018.h"
#include "utils_ADS1018.h"

/**
 * Palabras de configuración para cada lectura del ADS1018
 *  0: Adquisición del Canal 2, sin lectura
 *  1: Adquisición del Canal 1, lectura del Canal 2
 *  2: Adquisición del sensor de temperatura interno, lectura del Canal 1
 *  3: Lectura del sensor de temperatura interno
 */
uint16_t configADC[4] = {
    ADS1018_CFG_SS | ADS1018_CFG_CH2 | ADS1018_CFG_PGA | ADS1018_CFG_MODE | ADS1018_CFG_DR | ADS1018_CFG_PU_EN | ADS1018_CFG_NOP | ADS1018_CFG_RSV,
    ADS1018_CFG_SS | ADS1018_CFG_CH1 | ADS1018_CFG_PGA | ADS1018_CFG_MODE | ADS1018_CFG_DR | ADS1018_CFG_PU_EN | ADS1018_CFG_NOP | ADS1018_CFG_RSV,
    ADS1018_CFG_SS | ADS1018_CFG_TINT | ADS1018_CFG_PGA | ADS1018_CFG_MODE | ADS1018_CFG_DR | ADS1018_CFG_PU_EN | ADS1018_CFG_NOP | ADS1018_CFG_RSV, 0x0001};

/**
 * Prueba la inicialización del ADC, que siempre debería ser exitosa
 */
void test_init_ads(void)
{
    TEST_ASSERT_TRUE(init_ads());
}

/**
 * Prueba la función de librería que devuelve los valores de las
 * mediciones de termocuplas con el IC ADS1018. En ADS1018.c se 
 * reemplazan las llamadas a tx_rx_spi por llamadas al callback.
 */
void test_read_ads_data(void){
    uint16_t ADS1018_Data[ADS_FULLDATA] = { 0 };
    uint8_t read_data = 0;

    read_data = read_ads_data(ADS1018_Data, ADS_FULLDATA);

    TEST_ASSERT_EQUAL_UINT8(ADS_FULLDATA, read_data);
    TEST_ASSERT_EQUAL_UINT16(0x0DEA, ADS1018_Data[0]);
    TEST_ASSERT_EQUAL_UINT16(0x0BEE, ADS1018_Data[1]);
    TEST_ASSERT_EQUAL_UINT16(0x0FFF, ADS1018_Data[2]);

}

/**
 * Prueba la capa de abstracción de la librería que devuelve los 
 * valores de lasmediciones de termocuplas con el IC ADS1018. 
 */
void test_read_ads_small_buffer(void)
{
    uint16_t ADS1018_Data[2] = { 0 };
    uint8_t read_data = 0;

    read_data = read_ads(ADS1018_Data, 2);
    
    TEST_ASSERT_NOT_EQUAL_UINT8(ADS_FULLDATA, read_data);
}
