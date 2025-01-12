#pragma once

#include<memory>
#include<map>

class emplace
{
public:
    emplace();
    ~emplace();

public:
    void action();
};

std::map<int64_t, std::unique_ptr<emplace>> m_map;