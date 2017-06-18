#include "Timer.h"
#include "SPIcom.h"
#include "robot.h"
#include <stdio.h>
#include <time.h>


#define MICROSECONDS_PER_SECOND 1000000
#ifdef DRIVERS
#include "interrupt.h"
#define TIMER_IRQ 8
#endif

static clock_t s_TimeInit;

/*When properly registered, this function will be called every ms and we will use that time to check if something
got in the workspace of the robot*/
__attribute__ ((interrupt)) void TimerISR(){
    /*Set the SPI to listen to the sensor data*/
    SPIEepromDisable();
    SPISensorEnable();
    if (SPIRead() > SENSOR_PRESENCE_THRESHOLD) {
        /*Stop the robot and main will exit*/
        RobotStop();
        return;
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
    s_TimeInit = clock();
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
    clock_t now = clock();
    return ((uint32_t)(now - s_TimeInit)/(MICROSECONDS_PER_SECOND * CLOCKS_PER_SEC));
}
