#include "Timer.h"
#include "SPIcom.h"
#include "robot.h"
#include <stdio.h>
#include <time.h>

#ifdef DRIVERS
#include "interrupt.h"
#define TIMER_IRQ 8
#endif

static time_t s_TimeInit;

__attribute__ ((interrupt)) void TimerISR(){
    SPIEepromDisable();
    SPISensorEnable();
    while (SPIRead() > SENSOR_PRESENCE_THRESHOLD) {
        RobotStop();
    }
}

void TimerInit(void){

#ifdef DRIVERS
    unsigned int irq;
    unsigned long irqflags;

    irq = TIMER_IRQ;
    irqflags = IRQF_DISABLED;

    request_irq(irq, TimerISR,
                irqflags, "TimerISR", NULL);
#endif
    time(&s_TimeInit);
}

void TimerEnd(void){
#ifdef DRIVERS
    unsigned int irq;
    unsigned long irqflags;

    irq = TIMER_IRQ;
    irqflags = IRQF_SHARED | IRQF_NO_SUSPEND;

    request_irq(irq, TimerISR,
                irqflags, "TimerISR", NULL);
#endif
}

uint32_t TimetGetus(void){
    time_t now;
    time(&now);
    return 0;
}
