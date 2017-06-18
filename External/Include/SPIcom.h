#include <stdint.h>

#define SENSOR_PRESENCE_THRESHOLD 128

void SPIInit(void);

void SPIEepromEnable(void);

void SPIEepromDisable(void);

void SPISensorEnable(void);

void SPISensorDisable(void);

uint8_t SPIRead(void);
