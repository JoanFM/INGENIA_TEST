#include <stdint.h>
#include <stdbool.h>

void RobotTask(uint8_t u8Command);

void RobotStop (void);

volatile bool RobotStopped;
