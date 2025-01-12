#include <winsock2.h>
#include <iostream>

#include "serverr.h"

#pragma comment(lib, "ws2_32.lib")

class ServerSocket::impl
{
public:
    bool m_bInit = false;
    SOCKET m_socket = INVALID_SOCKET;

public:
    bool DoInit();
    bool DoBind();
    bool DoListen(int nBlcklog);
    bool DoAccept();
};

ServerSocket::ServerSocket() : m_pImpl(std::make_unique<impl>())
{
};

ServerSocket::~ServerSocket()
{
};

bool ServerSocket::DoInit()
{
    //初始化socket库
    WSADATA wsaData;
    WORD wVersionRequested = MAKEWORD(2, 2);

    int nRet = WSAStartup(wVersionRequested, &wsaData);
    if (nRet != 0)
    {
        std::cout << "WSAStartup failed: " << nRet << std::endl;
        return false;
    }

    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
    {
        std::cerr << "Could not find a usable version of Winsock.dll" << std::endl;
        return false;
    }

    m_pImpl->m_bInit = true;

    m_pImpl->m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_pImpl->m_socket == INVALID_SOCKET)
    {
        std::cerr << "socket failed: " << WSAGetLastError() << std::endl;
        return false;
    }

    return true;
}

bool ServerSocket::DoBind()
{
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(12345);
    addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

    int nRet = bind(m_pImpl->m_socket, (sockaddr*)&addr, sizeof(addr));
    if (nRet == SOCKET_ERROR)
    {
        std::cerr << "bind failed: " << WSAGetLastError() << std::endl;
        return false;
    }

    return true;
}

bool ServerSocket::DoListen(int nBlcklog)
{
    int nRet = listen(m_pImpl->m_socket, nBlcklog);
    if (nRet == SOCKET_ERROR)
    {
        std::cerr << "listen failed: " << WSAGetLastError() << std::endl;
        return false;
    }

    return true;
}

bool ServerSocket::DoAccept()
{
    SOCKADDR_IN nAddrClient;
    int nLen = sizeof(nAddrClient);
    
    char cMsg[] = "Hello, I am server!";

    while (true)
    {
        SOCKET nSocketClient = accept(m_pImpl->m_socket, (sockaddr*)&nAddrClient, &nLen);
        if (nSocketClient == INVALID_SOCKET)
        {
            std::cerr << "accept failed: " << WSAGetLastError() << std::endl;
            break;
        }

        send(nSocketClient, cMsg, sizeof(cMsg), 0);
        closesocket(nSocketClient);
    }
    
    return false;
}

int main(int args, char* argv[])
{
    ServerSocket server;
    if (!server.DoInit())
    {
        return -1;
    }

    if (!server.DoBind())
    {
        return -1;
    }

    if (!server.DoListen(15))
    {
        return -1;
    }

    server.DoAccept();

    return 0;
}
