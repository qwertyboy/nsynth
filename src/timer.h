/*
 * timer.h
 * configuration and functions for timers
 */

#ifndef TIMER_H_
#define TIMER_H_

// channel select defs
#define PIT_CH0 0x00
#define PIT_CH1 0x01
#define PIT_CH2 0x02
#define PIT_CH3 0x03

// function for starting PIT module
// args: none
void startPIT(void);

// function for setting period of channels
// args: channel - selects which channel to update
//       period - the period to set the channel to
void setPITperiod(uint8_t channel, uint32_t period);

// function for setting an interrupt for a channel
// args: channel - selects which channel to update
//       func - a pointer to a fucntion to call for the interrupt
void setPITinterrupt(uint8_t channel, void (* func)(void));

#endif
