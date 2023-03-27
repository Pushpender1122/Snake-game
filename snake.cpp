#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
// #include <graphics.h>
#include <sstream>
using namespace std;
#define HEIGHT 25
#define WIDTH 50
int x = 10, y = 10, Fruitx = 2, Fruity = 4, scor = 0;
int LEFT, RIGHT, UP, DOWN, dir, speed = 1, k = 0, hightestscore = 0;
int tailx[100], taily[100];
char screen[HEIGHT][WIDTH + 3] = {0};
int nTail;
class Snake
{
public:
    void control()
    {
        if (_kbhit())
        {
            switch (_getch())
            {
            case 'w':
            {
                // x--;
                dir = 1;
                break;
            }
            case 's':
            {
                // x++;
                dir = 2;
                break;
            }
            case 'a':
            {
                // y--;
                dir = 3;
                break;
            }
            case 'd':
            {
                // y++;
                dir = 4;
                break;
            }
            case 'x':
            {
                exit(1);
            }
            default:
                break;
            }
        }
    }
    void snakelength()
    {
        int prevx = tailx[0];
        int prevy = taily[0];
        int prev2x, prev2y;
        tailx[0] = y;
        taily[0] = x;
        for (int i = 1; i < nTail; i++)
        {
            prev2x = tailx[i];
            prev2y = taily[i];
            tailx[i] = prevx;
            taily[i] = prevy;
            prevx = prev2x;
            prevy = prev2y;
        }
    }
    void score()
    {
        if (x == Fruitx && y == Fruity)
        {
            scor += 10;
            speed = speed + 0.90;
            nTail++;
            if (scor > hightestscore)
            {
                hightestscore = scor;
            }
        }
    }
    void buildingend()
    {
        if ((x < 1 || x > 23) || (y < 0 || y > 49))
        {
            GameOver(true);
        }
        for (int i = 0; i < nTail; i++)
        {
            if (tailx[i] == y && taily[i] == x)
            {
                GameOver(true);
            }
        }
    }
    bool GameOver(int a)
    {
        if (a == true)
        {
            cout << "Game OVer" << endl;
            cout << "Your Score is " << scor << endl;
            getch();
            exit(0);
        }
    }
};

void board()
{

    usleep(25 * 1000);
    system("cls");
    int i = 0, j = 0;

    stringstream outstream;

    for (i = 0; i < HEIGHT; i++)
    {
        screen[i][0] = '#';
        for (j = 0; j < WIDTH; j++)
        {
            char pchar;

            if (i == 0 || i == HEIGHT - 1)
            {
                pchar = '#';
            }
            else if (i == x && j == y)
            {
                pchar = 'O';
            }
            else if (i == Fruitx && j == Fruity)
            {
                pchar = 'F';
            }
            else
            {
                bool print = false;
                for (k = 0; k < nTail; k++)
                {
                    if (tailx[k] == j && taily[k] == i)
                    {
                        pchar = 'o';
                        print = true;
                    }
                }
                if (!print)
                {
                    pchar = ' ';
                }
            }

            // outstream << pchar;
            screen[i][j + 1] = pchar;
        }
        screen[i][j + 1] = '#';
        screen[i][j + 2] = '\n';
        // outstream << "#\n";
    }

    cout << (char *)screen;
}
void implevalue()
{
    if (x == Fruitx && y == Fruity)
    {

        Fruitx = (rand() % HEIGHT);
        Fruity = (rand() % WIDTH);
    }
}
int main()
{
    Snake s1;
    // int page = 0;
    while (1)
    {
        //   setactivepage(page);
        // setvisualpage(1 - page);
        board();
        s1.control();
        s1.score();
        implevalue();
        s1.buildingend();
        s1.snakelength();
        if (dir == 1)
        {
            x = x - speed;
        }
        else if (dir == 2)
        {
            x = x + speed;
            // x++;
        }
        else if (dir == 3)
        {
            y = y - speed;
            // y--;
        }
        else if (dir == 4)
        {
            y = y + speed;
            // y++;
        }
        // y++;

        cout << "SCore " << scor << endl;
        // cout << "Hghest score is" << hightestscore;
        // getch();
        // SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
        //  page = 1 - page;
    }
}
