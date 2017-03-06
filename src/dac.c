/*
 * dac.c
 * configuration and functions for DAC
 */

#include "kinetis.h"
#include "dac.h"

// function to setup DAC
// args: none
void startDAC(void){
     // enable module clock
     SIM_SCGC2 |= SIM_SCGC2_DAC0;
     // enable module and set reference to 3.3V
     DAC0_C0 = DAC_C0_DACEN | DAC_C0_DACRFS;
}

// function to write to the dac
// args: value - 12 bit (0-4095) value to write to the dac
void writeDAC(uint16_t value){
    // shift our value over if using something other than 12 bits
    if(DAC_RES < 12){
        value <<= 12 - DAC_RES;
    }else if(DAC_RES > 12){
        value >>= DAC_RES - 12;
    }

    // cast to a 16 bit pointer to only do one write to both high and low
    // registers, then dereference and write
    uint16_t * dacPtr = &(DAC0_DAT0L);
    *dacPtr = value & 0xFFF;
}
