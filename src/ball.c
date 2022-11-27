#include "ball.h"
#include "display.h"
#include <stdbool.h>
#include "math.h"

void initBall(ball *ball)
{
    ball->position = (coordinate){WIDTH/2,HEIGHT/2};
    ball->direction_vector = (coordinate){0,3};
}

void drawBall(ball ball)
{
    if(ball.position.x-RAD<0||ball.position.x+RAD>WIDTH||ball.position.y-RAD<0||ball.position.y+RAD>HEIGHT)
    {
        return;
    }
    selectInactiveLayer();
    if(BSP_LCD_GetTextColor()!=LCD_COLOR_BLACK)
    {
        BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
    }
    BSP_LCD_Clear(LCD_COLOR_WHITE);
    BSP_LCD_FillCircle(ball.position.x,ball.position.y,RAD);
    swapDisplayedLayer();
}

void stepBall(ball *ball)
{
    ball->position = sumVector(ball->position,ball->direction_vector);
    if(ball->position.x + RAD >= WIDTH || ball->position.x - RAD < 0)
    {
        ball->direction_vector.x *= -1;
        ball->position = sumVector(ball->position,ball->direction_vector);
    }
    if(ball->position.y + RAD >= HEIGHT || ball->position.y - RAD < 0)
    {
        ball->direction_vector.y *= -1;
        ball->position = sumVector(ball->position,ball->direction_vector);
    }
}

void applyForce(ball *ball, coordinate force)
{
    coordinate sum = sumVector(ball->direction_vector,force);
    ball->direction_vector.x = (int32_t) round(3*sum.x/lengthVector(sum));
    ball->direction_vector.y = (int32_t) round(3*sum.y/lengthVector(sum));
}