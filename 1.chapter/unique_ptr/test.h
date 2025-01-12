#include <memory>

#pragma once

class People
{
private:
    class impl;
    std::unique_ptr<impl> m_pImpl;
public:
    People();
    People(int nAge, int nSex, std::string strName);
    ~People();

    void PrintInfo();
};
