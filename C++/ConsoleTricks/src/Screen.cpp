#include "Screen.h"


//void gotoxy(int x, int y)
//{
//  COORD coord;
//  coord.X = x;
//  coord.Y = y;
//  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}

void gotoxy(int x, int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

void hideCursor()
{
    fputs("\e[?25l", stdout);
}

Screen::Screen(const uint& width, const uint& height)
{
    setFrameLimit(60);
    m_table.resize(height);

    for (uint i = 0; i < m_table.size(); ++i)
    {
        for (uint j = 0; j < width; ++j)
        {
            m_table[i] += ' ';
        }
    }
}

Screen::~Screen()
{

}

void Screen::clear()
{
    m_clock.restart();

    for (uint i = 0; i < m_table.size(); ++i)
    {
        for (uint j = 0; j < m_table[i].length(); ++j)
        {
            m_table[i][j] = ' ';
        }
    }
}

void Screen::display()
{
    hideCursor();
    gotoxy(0, 0);

    for (uint i = 0; i < m_table.size(); ++i)
    {
        std::cout << m_table[i] << std::endl;
    }

    delay();
}

void Screen::delay()
{
    long elap = m_clock.getElapsedTime();

    std::cout << elap << std::endl;
    std::cout << m_delay << std::endl;

    if (m_vsync)
    {
        if (elap < m_delay)
        {
            std::this_thread::sleep_for(std::chrono::nanoseconds(m_delay - elap));
        }
    }
}

void Screen::setFrameLimit(long frameLimit)
{
    m_delay = 1000000000 / frameLimit;
}

void Screen::putChar(const char& c, const uint& x, const uint& y)
{
    if (y >= m_table.size())
        return;

    if (x >= m_table[y].length())
        return;

    if (c == ' ')
        return;

    m_table[y][x] = c;
}

void Screen::putString(const std::string& str, const uint& x, const uint& y)
{
    for (uint i = 0; i < str.length(); ++i)
    {
        putChar(str[i], x + i, y);
    }
}

void putFloat(const float& f,
       const uint& x,
       const uint& y);

uint Screen::getWidth()
{
    return m_table[0].length();
}

uint Screen::getHeight()
{
    return m_table.size();
}
