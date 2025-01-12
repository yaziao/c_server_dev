#pragma once

#include <memory>
#include <list>
#include <map>
#include <initializer_list>

class insert
{
public:
    class value;
    std::unique_ptr<value> m_pValue;

public:
    insert();
    insert(std::string strName, int nAge);
    insert(const insert& i);
    ~insert();

    void print();
};

std::list<std::unique_ptr<insert>> m_nList;

std::map<std::string, int> m_map;