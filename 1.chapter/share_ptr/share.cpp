#include <iostream>
#include <memory>

#include "share.h"

A::A()
{
    std::cout << "A::A()" << std::endl;
}

A::~A()
{
    std::cout << "A::~A()" << std::endl;
}

int main()
{
    std::shared_ptr<A> spA(new A);
    std::cout << "spA.use_count() = " << spA.use_count() << std::endl;

    std::shared_ptr<A> spA2 = spA;
    std::cout << "spA.use_count() = " << spA.use_count() << std::endl;
    std::cout << "spA2.use_count() = " << spA2.use_count() << std::endl;

    spA2.reset();
    std::cout << "spA.use_count() = " << spA.use_count() << std::endl;
    {
        std::shared_ptr<A> spA3 = spA;
        std::cout << "spA.use_count() = " << spA.use_count() << std::endl;
        std::cout << "spA3.use_count() = " << spA3.use_count() << std::endl;
    }
    std::cout << "spA.use_count() = " << spA.use_count() << std::endl;

    return 0;
}