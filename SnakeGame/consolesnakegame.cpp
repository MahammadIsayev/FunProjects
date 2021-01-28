#include <iostream>
#include <conio.h>
#include <algorithm>
#include <windows.h>

using namespace std;

bool gameOver = false;

const int height = 20;
const int width = 30;

int x, y, ballX, ballY, userScore;
int tailX[50], tailY[50], nTail;

enum snakeDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};

snakeDirection direction;

void setupGame()
{
    gameOver = false;
    direction = STOP;
    x = width / 2;
    y = height / 2;
    ballX = rand() % width;
    ballY = rand() % height;
    userScore = 0;
}

void drawOf()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                cout << "|";
            }
            if (i == y && j == x)
            {
                cout << "O";
            }
            else if (i == ballY && j == ballX)
            {
                cout << "x";
            }
            else
            {
                bool follow = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        follow = true;
                    }
                }
                if (!follow)
                {
                    cout << " ";
                }
            }
            if (j == width - 1)
            {
                cout << "|";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
    cout << "Your Score: " << userScore << endl;
}

void inputIn()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w':
            direction = UP;
            break;
        case 's':
            direction = DOWN;
            break;
        case 'a':
            direction = LEFT;
            break;
        case 'd':
            direction = RIGHT;
            break;
        case 'z':
            gameOver = true;
            break;
        }
    }
}

void logicG()
{
    int tempX = tailX[0];
    int tempY = tailY[0];
    int auxX, auxY;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        auxX = tailX[i];
        auxY = tailY[i];
        tailX[i] = tempX;
        tailY[i] = tempY;
        tempX = auxX;
        tempY = auxY;
    }

    switch (direction)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    /*if (x > width || x < 0 || y > height || y < 0)
    {
        gameOver = true;
    }*/
    //with above section, walls mode is active!

    if (x >= width)
    {
        x = 0;
    }
    else if (x < 0)
    {
        x = width - 1;
    }
    if (y >= height)
    {
        y = 0;
    }
    else if (y < 0)
    {
        y = height - 1;
    }
    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y)
        {
            gameOver = true;
            cout << "Game Over!" << endl;
        }
    }

    if (x == ballX && y == ballY)
    {
        userScore += 10;
        ballX = rand() % width;
        ballY = rand() % height;
        nTail++;
    }
}

int main()
{
    setupGame();
    while (!gameOver)
    {
        drawOf();
        inputIn();
        logicG();
        Sleep(40);
    }
    return 0;
}