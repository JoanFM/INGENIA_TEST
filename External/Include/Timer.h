#include <stdint.h>

void TimerInit(void);
__attribute__ ((interrupt)) void TimerISR();
uint32_t TimetGetus(void);
