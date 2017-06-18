#include "robot.h"
#include "SPIcom.h"
#include "Timer.h"


int main(void){
    RobotStopped = false;
    TimerInit();
    SPIInit();

    while(!RobotStopped){
        SPISensorDisable();
        SPIEepromEnable();
        RobotTask(SPIRead());
    }
    TimerEnd();
}
