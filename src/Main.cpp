#include <iostream>
#include <conio.h>
#include "Windows.h"

#include "Main.h"

bool gameOver;
const int width = 35;
const int height = 15;
int score;
const int leftX = 0;
const int rightX = 34;
int leftY, rightY;
int ballX, ballY;
const enum playerDirection { stop=0, up, down };
playerDirection leftDir;
playerDirection rightDir;

int main()
{
    setup();
    while (!gameOver)
    {
        input();
        logic();
        draw();
        Sleep(15);
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
        if (rightY != 13)
        {
            rightY += 1;
        }
    }
    if (rightDir == up)
    {
        if (rightY != 2)
        {
            rightY -= 1;
        }
    }
    if (leftDir == down)
    {
        if (leftY != 13)
        {
            leftY += 1;
        }
    }
    if (leftDir == up)
    {
        if (leftY != 2)
        {
            leftY -= 1;
        }
    }
}

void draw()
{
    system("cls");
    // prob have to add 2 score variables for left and right
    std::cout << "Score: " << score << " - " << score << std::endl;

    // i for y axis
    for (int i = 0; i < height + 1; i++)
    {
        // j for x axis
        for (int j = 0; j < width; j++)
        {
            // Draw the bounds
            if (i == 0)
            {
                std::cout << "#";
            }
            else if (i == 15)
            {
                std::cout << "#";
            }
            // Draw the left player
            else if ((j == leftX && i == leftY) || (j == leftX && i == leftY + 1) || (j == leftX && i == leftY - 1))
            {
                std::cout << "e";
            }
            // Draw tje right player
            else if ((j == rightX && i == rightY) || (j == rightX && i == rightY + 1) || (j == rightX && i == rightY - 1))
            {
                std::cout << "a";
            }
            // Draw the ball
            else if (ballX == j && ballY == i)
            {
                std::cout << "0";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    std::cout << "Press q to exit";
}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            // s and w keys for left player
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
        // Up and down arrow keys for right plauyer
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

        case 'q':
        {
            gameOver = true;
            break;
        }
        }
    }
}