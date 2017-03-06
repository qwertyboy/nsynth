#include "kinetis.h"
#include "timer.h"

void toggleLED(void){
    GPIOC_PTOR = (0x01 << 5);
}

int main(){
    PORTC_PCR5 = PORT_PCR_MUX(1) | PORT_PCR_DSE;
    GPIOC_PDDR |= (0x01 << 5);

    startPIT();
    setPITperiod(PIT_CH0, 0x00F42400);
    setPITinterrupt(PIT_CH0, toggleLED);

    while(1);
}
