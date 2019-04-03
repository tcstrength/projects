#include "Runtime.h"
#include <iostream>

Runtime a;
bool b[1000];

void test(uint index)
{
    std::cout << index << std::endl;
}

int main()
{
    a.run(test, 1);
    a.run(test, 1);
    a.run(test, 1);
    a.loop();
    return 0;
}
