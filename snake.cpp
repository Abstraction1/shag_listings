#include <iostream>
#include <stdlib.h>
#include <curses.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

bool game_over;
const int width = 20;
const int height = 20;
int x, y, fruit_x, fruit_y, score;
int tail_x[100], tail_y[100];
int n_tail;
enum e_direct { STOP = 0, LEFT, RIGHT, UP, DOWN };
e_direct dir;

int mygetch() {
    struct termios oldt,
            newt;
    int            ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}
void Setup()
{
    game_over = false;
    dir = STOP;
    x = width/2 - 1;
    y = height/2 - 1;
    fruit_x = rand() % width;
    fruit_y = rand() % height;
    score = 0;
}
void drow()
{
    system("clear");
    for (int i = 0; i < width + 1; ++i)
    {
        std::cout << "#";
    }
    std::cout << std::endl;

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (j == 0 || j == width - 1)
            {
                std::cout << "#";
            }
            if (i==y && j==x) {
                std::cout << "0";
            }
            else if (i == fruit_y && j == fruit_x)
            {
                std::cout << "F";
            }
            else
            {
                for (int k = 0; k < n_tail; ++k)
                {
                    if (tail_x[k] == j && tail_y[k] == i)
                    {
                        std::cout << "o";
                    }
                }
                std::cout <<" ";
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 1 ; ++i)
    {
        std::cout << "#";
    }

    std::cout << std::endl;
    std::cout << "Score: " << score << std::endl;
}
void input()
{
    switch (mygetch())
    {
    case 'a':
        dir = LEFT;
        break;
    case 'd':
        dir = RIGHT;
        break;
    case 'w':
        dir = UP;
        break;
    case 's':
        dir = DOWN;
        break;
    case 'x':
        game_over = true;
        break;
    }
}
void logic()
{
    int prev_x = tail_x[0];
    int prev_y = tail_y[0];
    int prev_2x, prev_2y;
    tail_x[0] = x;
    tail_y[0] = y;

    for (int i = 1; i < n_tail; ++i)
    {
        prev_2x = tail_x[i];
        prev_2y = tail_y[i];

        tail_x[i] = prev_x;
        tail_y[i] = prev_y;

        prev_x = prev_2x;
        prev_y = prev_2y;
    }

    switch (dir)
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
    }

    if (x >= width - 1)
    {
        x = 0;
    }
    else if (x < 0)
    {
        x = width - 2;
    }
    if (y >= height)
    {
        y = 0;
    }
    else if (y < 0)
    {
        y = height - 1;
    }

    for (int i = 0; i < n_tail; ++i)
    {
        if (tail_x[i] == x && tail_y[i] == y)
        {
            game_over = true;
        }
    }

    if (x == fruit_x && y == fruit_y)
    {
        score += 10;
        fruit_x = rand() % width;
        fruit_y = rand() % height;
        n_tail++;
    }
}

int main(int argc, char *argv[])
{
    Setup();
    while (!game_over)
    {
        drow();
        input();
        logic();
    }
    return 0;
}
