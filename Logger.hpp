#pragma once 

class Log
{
public:
    explicit Log(const std::string &funcName)
    {
        //std::cout << funcName << ": ";
    }

    template <class T>
    Log &operator<<(const T &v)
    {
        std::cout << v;
        return *this;
    }

    ~Log()
    {}
};


