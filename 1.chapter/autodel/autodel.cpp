#include <memory>
#include <iostream>

#include "autodel.h"


Socket::Socket()
{
    std::cout << "Socket::Socket()" << std::endl;
}

Socket::~Socket()
{
    std::cout << "Socket::~Socket()" << std::endl;
}

void Socket::close()
{
    std::cout << "Socket::close()" << std::endl;
}

int main()
{
    auto deletor = [](Socket* p)
    {
        p->close();
        delete p;
    };

    std::unique_ptr<Socket, decltype(deletor)> spSocket(new Socket, deletor);
    std::cout << "spSocket->getNum() = " << spSocket->getNum() << std::endl;

    spSocket.get()->setNum(10);
    std::cout << "spSocket.get()->getNum() = " << spSocket.get()->getNum() << std::endl;

    return 0;
}