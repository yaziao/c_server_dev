#include<iostream>
#include"insert.h"

class insert::value
{
public:
    std::string m_strName;
    int m_nAge;
};

insert::insert()
{
    std::cout << "insert constructed" << std::endl;
}

insert::insert(std::string strName, int nAge)
{
    m_pValue = std::make_unique<value>();
    m_pValue->m_strName = strName;
    m_pValue->m_nAge = nAge;
}

insert::insert(const insert& i)
{
    if(this == &i)
    {
        return;
    }
    m_pValue = std::make_unique<value>();
    m_pValue->m_strName = i.m_pValue->m_strName;
    m_pValue->m_nAge = i.m_pValue->m_nAge;
}


insert::~insert()
{
    std::cout << "insert destructed" << std::endl;
}

void insert::print()
{
    std::cout << "Name: " << m_pValue->m_strName << " Age: " << m_pValue->m_nAge << std::endl;
}

int main()
{
    insert i = {"Spike", 40};

    m_nList.emplace_back(std::make_unique<insert>(i));

    m_nList.emplace(m_nList.end(), std::make_unique<insert>("Tom", 30));

    for(auto &insert : m_nList)
    {
        insert->print();
    }


    m_map.insert_or_assign("Spike", 40);
    m_map.insert_or_assign("Tom", 30);
    m_map.insert_or_assign("Spike", 20);

    for(auto &[name, age] : m_map)
    {
        std::cout << "Name: " << name << " Age: " << age << std::endl;
    }

    return 0;
}