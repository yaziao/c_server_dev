#include<iostream>


#include"emplace.h"

emplace::emplace()
{
    std::cout << "emplace constructed" << std::endl;
}

emplace::~emplace()
{
    std::cout << "emplace destructed" << std::endl;
}

void emplace::action()
{
    std::cout << "emplace action" << std::endl;
}

void create(int64_t nKey)
{

    auto [iter, success] = m_map.try_emplace(nKey, nullptr);
    if (success)
    {
        auto p = std::make_unique<emplace>();
        iter->second = std::move(p);
    }
    
    iter->second->action();
}

int main()
{
    create(1);
    create(2);
    create(1);

    return 0;
}