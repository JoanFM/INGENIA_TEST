#include "SPIcom.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Examples that could maybe help simulating the behaviour*/
#define SPI_MAX 150
#define SPI_MIN 0

typedef struct{
    bool ReadEeprom;
    bool ReadSensor;
} SPIState_t;

static SPIState_t s_SPIState;

void SPIInit(void){
    s_SPIState.ReadEeprom = false;
    s_SPIState.ReadSensor = false;
    printf("Init SPI bus \n");
}

void SPIEepromEnable(void){
    s_SPIState.ReadEeprom = true;
    printf("Enable communication with EEProm to receive Robot Command \n");
}

void SPIEepromDisable(void)
{
    s_SPIState.ReadEeprom = false;
    printf("Disable communication with EEProm \n");
}

void SPISensorEnable(void)
{
    s_SPIState.ReadSensor = true;
    printf("Enable communication with Sensor to receive Presence data \n");
}

void SPISensorDisable(void)
{
    s_SPIState.ReadSensor = false;
    printf("Disable communication with Sensor\n");
}

/*Return random value for better simulation*/
uint8_t SPIRead(void){
    if(s_SPIState.ReadSensor == true){
        return (uint8_t) ((rand() % (SPI_MAX + 1 - SPI_MIN)) + SPI_MIN);
    }else{
        /*Would have no affection*/
        return 0;
    }
}
