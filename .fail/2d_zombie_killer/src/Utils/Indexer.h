#ifndef INDEXER_H
#define INDEXER_H

#include <iostream>
#include <stack>
#include "Log.h"

class Indexer
{
public:
    uint allocate();

    void deallocate(uint index);

private:
    uint m_index = 0;
    std::stack<uint> m_stack;
};

#endif // INDEXER_H
