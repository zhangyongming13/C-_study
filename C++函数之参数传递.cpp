#include <iostream>
#include <string>

using namespace std;

// 值传递
int valueTrans(int value)
{
    return ++value;
}

// 指针传递
int pointerTrans(int *value)
{
    return *value += 1;
}

// 引用传递
void quoteTrans(int &value)
{
    ++value;
}

// 使用引用类型避免copy，因为传入的string可能很大，copy效率会很低
bool isLongger(string longString, string shortString)
{
    if (longString.size() > shortString.size()) {
        return true;
    } else {
        return false;
    }
}

// 使用引用类型返回额外信息
size_t findChar(const string &inputString, char c, int &occurs)
{
    size_t firstOccur = inputString.size();
    for (size_t i = 0; i != inputString.size(); ++i) {
        if (c == inputString[i]) {
            if (inputString.size() == firstOccur) {
                firstOccur = i;
            }
            ++occurs;
        }
    }
    // 返回第一次出现的位置，出现次数由引用形参occurs返回
    return firstOccur;
}

int main ()
{
    int value = 20;
    cout << "valueTrans return value: " << valueTrans(value) << endl;
    cout << "origin value: " << value << endl;

    int *pointer = &value;
    cout << "pointerTrans return value: " << pointerTrans(pointer) << endl;
    cout << "origin value: " << value << endl;

    int quoteValue = 66;
    cout << "Before quote trans value: " << quoteValue << endl;
    quoteTrans(quoteValue);
    cout << "After quote trans value: " << quoteValue << endl;

    string longString = "zhangyongming";
    string shortString = "Hello";
    if (isLongger(longString, shortString)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    int occurs = 0;
    string inputString = "zhangyongming";
    char c = 'g';
    size_t firstOccur = findChar(inputString, c, occurs);
    cout << "First occur: " << firstOccur << endl;
    cout << "Occurs times: " << occurs << endl;

    system("pause");
}