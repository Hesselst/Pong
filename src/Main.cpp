#include <iostream>
#include <conio.h>

bool gameOver;
const int width = 35;
const int height = 15;
int score;
const int leftX = 2;
const int rightX = 30;
int leftY, rightY;
int ballX, ballY;
const int speed = 2;
const enum playerDirection { stop=0, up, down };
playerDirection leftDir;
playerDirection rightDir;

int main()
{
    setup();
    while (!gameOver)
    {
        draw();
        input();
        logic();
    }
}

void setup()
{
    ballX = 18;
    ballY = 8;
    gameOver = false;
    leftDir = stop;
    rightDir = stop;
    rightY = 8;
    leftY = 8;
    score = 0;
}

void logic()
{
    if (rightDir == down)
    {

    }
    if (rightDir == up)
    {

    }
    if (leftDir == down)
    {

    }
    if (leftDir == up)
    {

    }
}

void draw()
{

}

void input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 's':
        {
            leftDir = down;
            break;
        }
        case 'w':
        {
            leftDir = up;
            break;
        }
        // Up and down arrow keys but not sure if these are the correct codes
        case 72:
        {
            rightDir = up;
            break;
        }
        case 80:
        {
            rightDir = down;
            break;
        }
        }
    }
}

         Score: 0 - 1
==============================

        PRESS Y TO START

                           a
e                          a
e                          a
e
                       0

==============================

1 2 3 4 5 6 7 8 9 10 11 12 13
          6 7 8 

Left side = w&s
Right side = up&down arrow key