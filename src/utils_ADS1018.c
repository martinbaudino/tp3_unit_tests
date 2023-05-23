#include "utils_ADS1018.h"

uint16_t callback_tx_rx_spi(uint16_t configWord, int call_count)
{

    uint16_t const sensor_values[] = {0xDEA0, 0xBEE0, 0xFFF0, 0x0000};
    uint8_t values_counter = 0;

    if (configWord == configADC[0])
    {
        values_counter = 3;
    }
    else if (configWord == configADC[1])
    {
        values_counter = 0;
    }
    else if (configWord == configADC[2])
    {
        values_counter = 1;
    }
    else if (configWord == configADC[3])
    {
        values_counter = 2;
    }
    else
    {
        values_counter = 3;
    }
    return sensor_values[values_counter];
}