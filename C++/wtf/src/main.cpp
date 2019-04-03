#include <iostream>
#include <stdio.h>

const int width = 80;
const int height = 20;
std::string screen[height]; //ua loi gi vay mai` :v

void hideCursor()
{
    std::cout << "t eos bieets' search google :v";
}

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

void init()
{
    for (int i = 0; i < height; ++i)
    {
        screen[i].resize(width);
    }
}

void clear()
{
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            screen[i][j] = ' ';
        }
    }
}

void display()
{
    for (int i = 0; i < height; ++i)
    {
        std::cout << screen[i] << "|" << std::endl;
    }
    for (int i = 0; i < width; ++i)
    {
        std::cout << '-';
    }
}

void writeChar(int row, int col, char c)
{
    if (col < 0 || row < 0)
        return;

    if (col >= width || row >= height)
        return;

    screen[row][col] = c;
}

void writeString(int row, int col, std::string s)
{
    for (int i = 0; i < s.length(); ++i)
        writeChar(row, col + i, s[i]);
}

int main()
{
    init();

    int posX = 0;

    while (1)
    {
        gotoxy(0, 0);
        clear();
        writeString(0, 0, "WTF");
        writeString(1, posX++, "{{{{{{WTF}}}}}}");

        if (posX > width)
            posX = 0;
        display();
    }

    return 0;
}
