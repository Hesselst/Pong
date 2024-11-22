#include <iostream>
#include <conio.h>
#include "Windows.h"
#include <string>

#include "Main.h"

bool gameOver;
const int width = 35;
const int height = 15;
int leftScore = 0;
int rightScore = 0;
const int leftX = 0;
const int rightX = 34;
int leftY, rightY;
int ballX, ballY;
const enum playerDirection { stop=0, up, down };
playerDirection leftDir;
playerDirection rightDir;

const enum yDirection { yUp=0, yDown};
yDirection yDir;
char prevHitPlayer = NULL;
std::string playerScored = " ";

int main()
{
    setup();
    while (!gameOver)
    {
        input();
        logic();
        draw();
        // The amount just really depends on ur fps so u might have to change this. maybe i will add deltatime but im not sure how to do that since im working with whole numbers in the console
        Sleep(25);
    }
}

void setup()
{
    yDir = yDown;
    ballX = 18;
    ballY = 8;
    gameOver = false;
    leftDir = stop;
    rightDir = stop;
    rightY = 8;
    leftY = 8;
}

void logic()
{
    // Check if the ball collided with the right player
    if (ballX == rightX)
    {
        if (ballY == rightY || ballY == (rightY - 1) || ballY == (rightY + 1))
        {
            prevHitPlayer = 'b';
        }
        else
        {
            playerScored = "Left";
            leftScore++;
            setup();
        }
    }

    // Check if the ball collided with the left player
    if (ballX == leftX)
    {
        if (ballY == leftY || ballY == (leftY - 1) || ballY == (leftY + 1))
        {
            prevHitPlayer = 'a';
        }
        else
        {
            playerScored = "Right";
            rightScore++;
            setup();
        }
    }

    // If the ball hits the bounds, reverse the Y axis
    if (ballY == 14)
    {
        yDir = yUp;
    }
    if (ballY == 1)
    {
        yDir = yDown;
    }

    if (prevHitPlayer == 'a' || prevHitPlayer == NULL)
    {
        ballX++;
    }
    if (prevHitPlayer == 'b')
    {
        ballX--;
    }

    switch (yDir)
    {
    case yUp:
    {
        ballY--;
        break;
    }

    case yDown:
    {
        ballY++;
    }
    }

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
    std::cout << "Score: " << leftScore << " - " << rightScore << std::endl;
    if (playerScored != " ")
    {
        std::cout << playerScored << " player scored!" << std::endl;
    }
    else
    {
        std::cout << "No one has scored yet" << std::endl;
    }

    // i for y axis
    for (int i = 0; i < height + 1; i++)
    {
        // j for x axis
        for (int j = 0; j < width; j++)
        {
            // Draw the bounds
            if (i == 0 || i == 15)
            {
                std::cout << "-";
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