#include <iostream>

using namespace std;

class BitMap {
public:
    BitMap()
    {
        bitNumber = 0;
    }

private:
    int bitNumber;
};

class Widget {
public:
    Widget()
    {
        pBit = nullptr;
    }

    Widget &operator=(const Widget &rhs)
    {
        // 先判断是否自我赋值
        if (this == &rhs) {
            return *this;
        }

        // 在通过保存原来pBit然后删除保证异常安全性
        BitMap *pOrig = pBit;
        pBit =  new BitMap(*rhs.pBit);
        delete pOrig;
        return *this;
    }

private:
    BitMap *pBit;
};

int main()
{
    return 0;
}
