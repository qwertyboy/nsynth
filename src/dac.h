/*
 * dac.h
 * configuration and functions for DAC
 */

#ifndef DAC_H_
#define DAC_H_

#ifndef DAC_RES
#define DAC_RES 8
#endif

// function to setup DAC
// args: none
void startDAC(void);

// function to write to the dac
// args: value - 12 bit (0-4095) value to write to the dac
void writeDAC(uint16_t value);

#endif
