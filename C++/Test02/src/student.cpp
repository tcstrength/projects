#include "student.hpp"

Student::Student()
{
    std::cout << "New student has been created" << std::endl;
}

Student::~Student()
{
    std::cout << "Ahihi, i die" << std::endl;
}

void Student::input()
{
    std::cout << "Please, enter some new information..." << std::endl;
    std::cout << "Name: "; std::cin >> m_name;
    std::cout << "Years: "; std::cin >> m_year;
    std::cout << "Address: "; std::cin >> m_addr;
}

void Student::output()
{
    std::cout << "Name: " << m_name << std::endl;
    std::cout << "Years: " << m_year << std::endl;
    std::cout << "Address: " << m_addr << std::endl;
}
