#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class tg_string
{
public:
    explicit tg_string(const char *str = nullptr);// 普通构造函数
    tg_string(const tg_string &other);// 拷贝构造函数
    tg_string & operator = (const tg_string &other);// 赋值函数

    ~tg_string();// 析构函数
private:
    char *m_data;// 用于保存字符串
};

// String的析构函数
tg_string::~tg_string()
{
    std::cout<<"deconstruct:"<<m_data<<std::endl;
    delete[] m_data;
}

//普通构造函数
tg_string::tg_string(const char *str)
{
    if (str == nullptr)
    {
        m_data = new char[1];
        *m_data = '\0';
    }
    else
    {
        size_t length = strlen(str);
        m_data = new char[length + 1];
        strcpy(m_data, str);
    }
    std::cout<<"construct:"<<m_data<<std::endl;
}

//拷贝构造函数
tg_string::tg_string(const tg_string &other)
{
    size_t length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
    std::cout<<"copy construct:"<<m_data<<std::endl;
}

//赋值函数
tg_string & tg_string::operator = (const tg_string &other)
{
    std::cout<<"copy assignment"<<std::endl;
    if (this == &other)
    {
        return *this;
    }

    tg_string tmp(other);
    char* ptr= this->m_data;
    this->m_data = tmp.m_data;
    tmp.m_data = ptr;

    return *this;
}

int main()
{
    {
        // push_back的方式普通构造和拷贝构造分别被调用了一次，同样析构函数被调用两次
        std::cout<<"++++++++++++++++++++++++++++++++++"<<std::endl;
        vector<tg_string> vStr;
        vStr.reserve(100);
        vStr.push_back(tg_string("first"));
    }

    {
        // emplace_back只调用了一次构造和析构函数
        std::vector<tg_string> vStr;
        // 预先分配，否则整个vector在容量不够的情况下重新分配内存
        vStr.reserve(100);
        std::cout<<"++++++++++++++++++++++++++++++++++"<<std::endl;
        vStr.emplace_back("second");
    }
}
