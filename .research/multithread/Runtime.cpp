#include "Runtime.h"

uint Runtime::_index = 0;
std::map<uint, Runtime::Timer> Runtime::_timers;

Runtime::Runtime()
{

}

Runtime::~Runtime()
{
    _timers.clear();
}

void Runtime::loop(uint index)
{
    while (1)
    {
        uint tick = SDL_GetTicks();
        if (tick - _timers[index].startTick < _timers[index].miliseconds)
            continue;
        else
        {
            _timers[index].callback(index);
            _timers[index].startTick = SDL_GetTicks();
        }
    }
}

void Runtime::loop()
{
    for (auto it = _timers.begin(); it != _timers.end(); ++it)
    {
        (loop, it->first);
    }
}

void Runtime::exit()
{
    _running = false;
}

void Runtime::stop(uint index)
{
    if (_timers.empty())
        return;

    _timers.erase(_timers.find(index));
}

uint Runtime::run(std::function<void (uint)> callback, uint miliseconds)
{
    _timers[_index] = {callback, miliseconds, 0};
    return _index++;
}
