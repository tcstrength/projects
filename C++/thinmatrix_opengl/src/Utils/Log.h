#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <bitset>

#define USE_DEBUG

#ifdef USE_DEBUG
#define LOG_DEBUG(str) \
do { \
    utils::Log::instance()->stream() << str; \
    utils::Log::instance()->debug(); \
} while(0)

#define LOG_ERROR(str) \
do { \
    utils::Log::instance()->stream() << str; \
    utils::Log::instance()->error(); \
    std::cout << "Exit!" << std::endl; \
    exit(1); \
} while(0)

#else
#define LOG_DEBUG(str)
#define LOG_ERROR(str)
#endif
namespace utils {
class Log {
public:
    static Log* instance();

    void debug();

    void error();

    std::stringstream& stream();
private:
    Log();

    ~Log();

    void print(std::string level);

    std::string getStrTime();

    std::stringstream _strStream;
    std::ofstream _outStream;
};
}


#endif // LOG_H
