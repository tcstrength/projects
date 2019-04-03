#include <iostream>
#include <fstream>

std::string removeAttr(std::string code, std::string attr)
{
    if (code.length() < attr.length() || attr.length() == 0)
    {
        return code;
    }

    auto pos = code.find(attr);

    if (pos == std::string::npos)
    {
        return code;
    }

    std::string afterPos = code.substr(pos);
    std::string beforePos = code.substr(0, pos);
    auto semi = afterPos.find(';');

    if (semi == std::string::npos)
    {
        return code;
    }

    std::string result = beforePos + afterPos.substr(semi);

    return result;
}

std::string inputAttr()
{
    std::string str;
    std::cout << "enter attribute you want to remove in css: ";
    std::cin >> str;
    return str;
}

int main()
{
    std::ifstream is("input.css");

    if (is.is_open() == false)
    {
        std::cout << "Failed to open input.css" << std::endl;
        return 1;
    }

    std::ofstream os("output.css");
    std::string attr = "text-shadow";
    std::string buffer;

    while (std::getline(is, buffer))
    {
        os << removeAttr(buffer, attr) << std::endl;
    }
    return 0;
}
