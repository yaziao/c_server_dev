#pragma once
#include <memory>

class ServerSocket
{
private:
    class impl;
    std::unique_ptr<impl> m_pImpl;
public:
    ServerSocket();
    ~ServerSocket();

    bool DoInit();//初始化
    bool DoBind();//绑定
    bool DoListen(int nBlcklog);//监听
    bool DoAccept();//接受
};