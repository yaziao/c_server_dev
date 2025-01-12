#include<initializer_list>
#include<vector>

#pragma once

class A
{
    public:
    A(std::initializer_list<int> list);
    ~A();

    public:
    void Print();
    void Append(std::initializer_list<int> list);

    private:
    std::vector<int> m_vec;
};