#include "Clock.h"

Clock::Clock()
{
    restart();
}

void Clock::restart()
{
    m_start = std::chrono::high_resolution_clock::now();
}

long Clock::getElapsedTime()
{
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(end - m_start).count();
}
