#include<iostream>
#include<list>

#include"constructed.h"

Test::Test(int a, int b, int c)
{
    m_a = a;
    m_b = b;
    m_c = c;
    std::cout << "Test constructed" << std::endl;
}

Test::~Test()
{
    std::cout << "Test destructed" << std::endl;
}

Test::Test(const Test& rhs)
{
    if(this == &rhs)
    {
        return;
    }

    m_a = rhs.m_a;
    m_b = rhs.m_b;
    m_c = rhs.m_c;
    std::cout << "Test copy constructed" << std::endl;
}

int main()
{
    std::list<Test> list;
    // for(int i = 0; i < 10; i++)
    // {
    //     Test t(i, i + 1, i + 2);
    //     list.push_back(t);
    // }

    std::cout<<"-------------------"<<std::endl;

    std::list<Test> list2;
    for(int i = 0; i < 10; i++)
    {
        list2.emplace(list2.end(), i, i + 1, i + 2);
    }
}