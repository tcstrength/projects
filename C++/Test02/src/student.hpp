#pragma once

#include <iostream>

class Student {
private:
    std::string m_name;
    uint        m_year;
    std::string m_addr;
public:
    Student();
    
    ~Student();
    
    void input();
    
    void output();
};
