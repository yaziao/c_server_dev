#include <iostream>

#include "test.h"

class People::impl
{
public:
    int m_nAge;
    int m_nSex;
    std::string m_strName;
};

People::People() : m_pImpl(std::make_unique<impl>())
{
    m_pImpl->m_nAge = 0;
    m_pImpl->m_nSex = 0;
    m_pImpl->m_strName = "";
}

People::People(int nAge, int nSex, std::string strName) : m_pImpl(std::make_unique<impl>())
{
    m_pImpl->m_nAge = nAge;
    m_pImpl->m_nSex = nSex;
    m_pImpl->m_strName = strName;
}

People::~People()
{
}

void People::PrintInfo()
{
    std::cout << "Name: " << m_pImpl->m_strName << "\n"
              << "Age: " << m_pImpl->m_nAge << "\n"
              << "Sex: " << m_pImpl->m_nSex << std::endl;
}

int main()
{
    People people(18, 1, "Tom");
    people.PrintInfo();
    People people1;
    people1.PrintInfo();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}