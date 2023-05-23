#include <stdint.h>
#include <stdbool.h>
#include "unity.h"

#include "ADS1018.h"
#include "utils_ADS1018.h"
#include "mock_ADS1018.h"

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
 * Prueba la inicialización del puerto SPI, que siempre debería ser exitosa
 */
void test_init_ads_spi(void)
{
    init_ads_spi_ExpectAndReturn(true);
    TEST_ASSERT_TRUE(init_ads_spi());
}

/**
 * Prueba que el callback desarrollado se comporte como el ADS1018
 */
void test_tx_rx_spi(void)
{
    tx_rx_spi_StubWithCallback(callback_tx_rx_spi);

    TEST_ASSERT_EQUAL_UINT16(0x0000, tx_rx_spi(configADC[0]));
    TEST_ASSERT_EQUAL_UINT16(0xDEA0, tx_rx_spi(configADC[1]));
    TEST_ASSERT_EQUAL_UINT16(0xBEE0, tx_rx_spi(configADC[2]));
    TEST_ASSERT_EQUAL_UINT16(0xFFF0, tx_rx_spi(configADC[3]));
}


