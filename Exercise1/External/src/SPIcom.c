#include "SPIcom.h"
#include <stdio.h>

void SPIInit(void){
    printf("Init SPI bus \n");
}

void SPIEepromEnable(void){
    printf("Enable communication with EEProm to receive Robot Command \n");
}

void SPIEepromDisable(void)
{
    printf("Disable communication with EEProm \n");
}

void SPISensorEnable(void)
{
    printf("Enable communication with Sensor to receive Presence data \n");
}

void SPISensorDisable(void)
{
    printf("Disable communication with Sensor\n");
}

uint8_t SPIRead(void){
    return 0;
}
