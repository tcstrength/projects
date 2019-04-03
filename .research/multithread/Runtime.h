#ifndef RUNTIME_H
#define RUNTIME_H

#include <thread>
#include <map>
#include <functional>
#include <SDL2/SDL.h>

class Runtime
{
public:
    struct Timer{
        std::function<void(uint)> callback;
        uint miliseconds;
        uint startTick;
    };

    Runtime();

    ~Runtime();

    uint run(std::function<void(uint index)> callback, uint miliseconds);

    void stop(uint index);

    void loop();

private:
    static void loop(uint index);
    static uint _index;
    static std::map<uint, Timer> _timers;

};

#endif // RUNTIME_H
