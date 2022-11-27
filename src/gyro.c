#include "gyro.h"
#include "stm32f429i_discovery_gyroscope.h"
#include "display.h"
#include "assert.h"
#define sensitivity 10000
uint8_t state = 0;

void gyroInit()
{
    if(BSP_GYRO_Init()!=GYRO_OK)
    {
        printMsg((uint8_t *)"ERROR WITH GYRO");
        assert(0);
    }
    BSP_GYRO_Reset();
}

void getXYFromGyro(int8_t *x,int8_t *y)
{
    float buffer[3][3];
    for(int i = 0; i < 3; i++)
    {
        BSP_GYRO_GetXYZ(buffer[i]);
    }
    float avgX = (buffer[0][1]+buffer[1][1]+buffer[2][1])/3;
    float avgY = (buffer[0][0]+buffer[1][0]+buffer[2][0])/3;
    if(avgX>sensitivity)
    {
        *x = 3;
    }
    else if(avgX<sensitivity*-1)
    {
        *x = -3;
    }
    else
    {
        *x = 0;
    }
    if(avgY>sensitivity)
    {
        *y = 3;
    }
    else if(avgY<sensitivity*-1)
    {
        *y = -3;
    }
    else
    {
        *y = 0;
    }
}