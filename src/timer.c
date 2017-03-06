/*
 * timer.c
 * configuration and functions for timers
 */

#include "kinetis.h"
#include "timer.h"

// function pointers for ISRs
void (* ch0ISR)(void);
void (* ch1ISR)(void);
void (* ch2ISR)(void);
void (* ch3ISR)(void);

// PIT CH0 ISR
void pit0_isr(void){
    // clear interrupt flag
    PIT_TFLG0 = 0x01;
    ch0ISR();
}

// PIT CH1 ISR
void pit1_isr(void){
    // clear interrupt flag
    PIT_TFLG1 = 0x01;
    ch1ISR();
}

// PIT CH2 ISR
void pit2_isr(void){
    // clear interrupt flag
    PIT_TFLG2 = 0x01;
    ch2ISR();
}

// PIT CH3 ISR
void pit3_isr(void){
    // clear interrupt flag
    PIT_TFLG3 = 0x01;
    ch3ISR();
}

// function for starting PIT module
// args: none
void startPIT(void){
    // enable clock and pit module
    SIM_SCGC6 |= SIM_SCGC6_PIT;
    PIT_MCR = 0x00;
}


// function for setting period of channels
// args: channel - selects which channel to update
//       period - the period to set the channel to
void setPITperiod(uint8_t channel, uint32_t period){
    switch(channel){
        case PIT_CH0:
            PIT_LDVAL0 = period;
            break;
        case PIT_CH1:
            PIT_LDVAL1 = period;
            break;
        case PIT_CH2:
            PIT_LDVAL2 = period;
            break;
        case PIT_CH3:
            PIT_LDVAL3 = period;
            break;
        default:
            break;
    }
}

// function for setting an interrupt for a channel
// args: channel - selects which channel to update
//       func - a pointer to a fucntion to call for the interrupt
void setPITinterrupt(uint8_t channel, void (* func)(void)){
    switch(channel){
        case PIT_CH0:
            PIT_TCTRL0 = PIT_TCTRL_TIE | PIT_TCTRL_TEN;
            ch0ISR = func;
            NVIC_ENABLE_IRQ(IRQ_PIT_CH0);
            break;
        case PIT_CH1:
            PIT_TCTRL1 = PIT_TCTRL_TIE | PIT_TCTRL_TEN;
            ch1ISR = func;
            NVIC_ENABLE_IRQ(IRQ_PIT_CH1);
            break;
        case PIT_CH2:
            PIT_TCTRL2 = PIT_TCTRL_TIE | PIT_TCTRL_TEN;
            ch2ISR = func;
            NVIC_ENABLE_IRQ(IRQ_PIT_CH2);
            break;
        case PIT_CH3:
            PIT_TCTRL3 = PIT_TCTRL_TIE | PIT_TCTRL_TEN;
            ch3ISR = func;
            NVIC_ENABLE_IRQ(IRQ_PIT_CH3);
            break;
        default:
            break;
    }
}
