# Trabajo Práctico N° 3: Test Unitario

Seleccionar una biblioteca (o componente) del software a desarrollar en el TP final de la carrera de especialización/maestría y escribit un test unitario con ceedling que incluya por lo menos 5 test cases. El archivo de test debe tener por lo menos 65 línas de extensión.

Se debe mantener bajo 

Entregar:
* Repositorio con el archivo con las pruebas unitarias y el código de producción bajo prueba (preferentemente en bitbucket o github).

## Resolución:
El trabajo contsta de 5 casos de prueba que fuerin divididos en 2 archivos para poder probar las distintas capa de el drivers para el **IC ADS1018** de Texas Instruments. Es un sensor de termocuplas de 2 canales más un sensor interno. 

En el archivo `test_ads1018_spi.c` se probaron las **interfaces de comunicación por SPI**. Para ello se utilizaron mocks (`mock_ADS1018.h`) y una función callback, desarrollada en los archivos `utils_ADS1018.h` y `.c.`, utilizando las siguientes funcionalidades:
* CMock: 
    * `init_ads_spi_ExpectAndReturn(true)`
    * `tx_rx_spi_StubWithCallback(callback_tx_rx_spi)`
* Unity: 
    * `TEST_ASSERT_TRUE`
    * `TEST_ASSERT_EQUAL_UINT16`

En el archivo `test_ads1018_adc.c` se probaron las **funciones de alto nivel del ADC**. Para ello se utilizaron los archivos de la implementación original para STM32 (`ADS1018.h` y `.c`), pero comentando las partes de acceso al hardware y reemplazando la función de acceso al puerto SPI (`tx_rx_spi`) con la función `callback_tx_rx_spi`, utilizando las siguientes funcionalidades:
* Unity: 
    * `TEST_ASSERT_TRUE`
    * `TEST_ASSERT_EQUAL_UINT8`
    * `TEST_ASSERT_EQUAL_UINT16`