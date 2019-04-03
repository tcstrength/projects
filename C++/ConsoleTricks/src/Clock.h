#ifndef CLOCK_H
#define CLOCK_H

#include <chrono>

class Clock
{
public:
    Clock();

    long getElapsedTime();

    void restart();

private:
    std::chrono::_V2::high_resolution_clock::time_point m_start;
};

#endif // CLOCK_H
