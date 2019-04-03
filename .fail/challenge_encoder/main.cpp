#include <iostream>

std::string encode(std::string str)
{
    std::string buf;
    int len = str.length();

    buf.push_back(len + 42);

    for (int i = 0; i < len; ++i)
        buf.push_back(str[len - i - 1] + i + 1);

    return buf;
}

std::string decode(std::string str)
{
    std::string buf;
    int len = str[0] - 42;

    for (int i = 0; i < len; ++i)
        buf.push_back(str[len - i] - len + i);

    return buf;
}

int main()
{
    std::cout << encode("159487asd") << std::endl;
    //std::cout << decode(encode("159487asd")) << std::endl;
    return 0;
}
