#include "Misc.h"

namespace utils {

bool isFileExist(const char* fileName)
{
    std::ifstream f(fileName);
    return f.good();
}

}
