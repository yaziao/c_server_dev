#pragma once

class Socket
{
private:
    int m_nNum;

public:
    Socket();
    ~Socket();

public:
    void close();

    void setNum(int nNum)
    {
        m_nNum = nNum;
    }

    int getNum() const
    {
        return m_nNum;
    }
};