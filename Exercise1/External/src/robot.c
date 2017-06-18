#include "robot.h"
#include "time.h"
#include <stdio.h>

void RobotTask(uint8_t u8Command){
    clock_t inittask = clock();
    printf("Execute Task %i \n",u8Command);

    while(!RobotStopped){
        clock_t now = clock();
        /*Simulate a task that takes 2 seconds*/
        if((now - inittask)/(CLOCKS_PER_SEC) > 2){
            break;
        }
    }
}

void RobotStop (void)
{
    printf("Robot Stopped \n");
    RobotStopped = true;
    usleep(15);
}
