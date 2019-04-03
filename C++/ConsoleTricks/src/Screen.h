#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include "Clock.h"

class Screen
{
public:
    Screen(const uint& width, const uint& height);

    ~Screen();

    void clear();

    void display();

    void setFrameLimit(long frameLimit);

    void putChar(const char& c,
                 const uint& x,
                 const uint& y);

    void putString(const std::string& str,
                   const uint& x,
                   const uint& y);

    template<class T>
    void putPremitiveType(const T& t,
                          const uint& x,
                          const uint& y)
    {
        putString(std::to_string(t), x, y);
    }

    uint getWidth();

    uint getHeight();

private:
    void delay();

    bool m_vsync;
    Clock m_clock;
    long m_delay;
    std::vector<std::string> m_table;
};

#endif // SCREEN_H
