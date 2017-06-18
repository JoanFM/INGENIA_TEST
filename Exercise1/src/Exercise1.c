#include "robot.h"
#include "SPIcom.h"
#include "Timer.h"


int main(void){
    RobotStopped = false;
    /*Init the timer that will register the interrupt handler*/
    TimerInit();
    /*Configure the SPI bus interface for communication*/
    SPIInit();

    while(!RobotStopped){
        /*Set the SPI to listen to the EEPROM commands*/
        SPISensorDisable();
        SPIEepromEnable();
        /*Send RobotCommand read from EEPROM*/
        RobotTask(SPIRead());
    }
    TimerEnd();
}
