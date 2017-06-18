#include "robot.h"
#include <stdio.h>

void RobotTask(uint8_t u8Command){
    printf("Execute Task %i \n",u8Command);
    sleep(5);
}

void RobotStop (void)
{
    printf("Robot Stopped \n");
    RobotStopped = true;
    usleep(15);
}
