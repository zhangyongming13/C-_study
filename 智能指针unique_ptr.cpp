#include <iostream>
#include <string>
#include <memory>

using namespace std;

unique_ptr<string> ReturnUniquePtr()
{
    unique_ptr<string> pStr(new string("Return unique pointer"));

    return pStr;
}

void UniquePtr()
{
    // 定义并初始化一个unique_ptr
    unique_ptr<string> pStr1(new string("Unique pointer!"));
    cout << *pStr1 << endl;

    // pStr1释放了对象的控制权并交给了pStr2
    unique_ptr<string> pStr2(pStr1.release());
    cout << *pStr2 << endl;

    // 这里进行了一次unique_ptr的拷贝，这个是合法的
    unique_ptr<string> pStr3 = ReturnUniquePtr();
    cout << *pStr3 << endl;
}

int main()
{
    UniquePtr();

    return 0;
}
