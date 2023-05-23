/*
 * utils_ADS1018.h
 *
 *      Author: Martín Sebastián Baudino
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef API_INC_UTILSADS1018_H_
#define API_INC_UTILSADS1018_H_

#include <stdint.h>
#include <stdbool.h>
#include "ADS1018.h"

extern uint16_t configADC[];

/**
 * Callback que imita el funcionamiento del ADS1018, que recibe palabras de
 * configuración 16 bits y devuelve el valor leido. Toma 3 mediciones, de
 * temperatura: en el canal 2, luego en el canal 1, y finalmente en su
 * sensor interno. La primera lectura siempre se descarta porque tiene el
 * valor de un ciclo de lectura anterior.
 * Los valores de adquisición son de 12 bits en datos de 16 bits alineados
 * izqierda.
 */
uint16_t callback_tx_rx_spi(uint16_t configWord, int call_count);

#endif /* API_INC_UTILSADS1018_H_ */