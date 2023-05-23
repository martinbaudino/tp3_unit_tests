/*
 * ADS1018.h
 *
 *  Created on: Oct 9, 2022
 *      Author: Martín Sebastián Baudino
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef API_INC_ADS1018_H_
#define API_INC_ADS1018_H_

/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>

/* Exported functions prototypes ---------------------------------------------*/
bool init_ads(void);
bool read_ads(uint16_t *dataBuffer, uint8_t buffSize);

/* Private function prototypes -----------------------------------------------*/
bool init_ads_spi(void);
uint16_t tx_rx_spi(uint16_t configWord);
uint8_t read_ads_data(uint16_t *readBuffer, uint8_t buffSize);

/* Exported constants --------------------------------------------------------*/
/** Cantidad de datos a leer: por ahora siempre se leen 3 valores */
#define ADS_FULLDATA 3U

/** Cantidad de datos leídos cuando hubo algún error, ninguno */
#define ADS_NODATA 0U

/** Single-shot conversion Start */
#define ADS1018_CFG_SS (0x8000)

/** Input multiplexer configuration: 000 => AINP is AIN0 and AINN is AIN1 */
#define ADS1018_CFG_CH1 (0x0000)

/** Input multiplexer configuration: 011 => AINP is AIN2 and AINN is AIN3 */
#define ADS1018_CFG_CH2 (0x3000)

/** Programmable Gain Amplifier config: 111 => FSR is ±0.256 V */
#define ADS1018_CFG_PGA (0x0E00)

/** Device operating mode: 1 => Power-down and single-shot mode */
#define ADS1018_CFG_MODE (0x0100)

/** Data rate: 110 => 3300 SPS */
#define ADS1018_CFG_DR (0x00A0)

/** Temperature sensor mode: 1 => Temperature sensor mode */
#define ADS1018_CFG_TINT (0x0010)

/** Pullup resistor enable on DOUT/DRDY: 1 => Pullup resistor enabled */
#define ADS1018_CFG_PU_EN (0x0008)

/** NO OP - control if data are written: 01 => Valid data; update Config register */
#define ADS1018_CFG_NOP (0x0002)

/** Reserved: Writing 0 or 1 has no effect */
#define ADS1018_CFG_RSV (0x0001)

/** Retardo máximo para Tx/Rx por SPI */
#define MAX_TIMEOUT 0xFFFF

#endif /* API_INC_ADS1018_H_ */
