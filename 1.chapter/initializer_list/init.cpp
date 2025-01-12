#include<iostream>
#include"init.h"

A::A(std::initializer_list<int> list)
{
    // for(auto it = list.begin(); it != list.end(); ++it)
    // {
    //     m_vec.push_back(*it);
    // }
    m_vec.insert(m_vec.end(), list.begin(), list.end());
}

A::~A()
{
}

void A::Print()
{
    for(auto it = m_vec.begin(); it != m_vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void A::Append(std::initializer_list<int> list)
{
    m_vec.insert(m_vec.end(), list.begin(), list.end());
}

int main()
{
    A a = {1, 2, 3, 4, 5};
    a.Print();
    a.Append({6, 7, 8, 9, 10});
    a.Print();
    return 0;
}