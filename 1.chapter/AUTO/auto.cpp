#include"auto.h"
#include<vector>
#include<iostream>

int main()
{
    A a;
    A b;
    std::vector<A> vec;

    vec.push_back(a);
    vec.push_back(b);

    for(auto &it : vec)
    {
        it.m_num = 9;
    }

    for(auto it : vec)
    {
        std::cout << it.m_num << std::endl;
    }

    return 0;
}