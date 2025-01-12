#pragma once

class Test
{
    private:
    int m_a;
    int m_b;
    int m_c;

    public:
    Test() = default;
    Test(int a, int b, int c);
    ~Test();

    Test(const Test& rhs);
};