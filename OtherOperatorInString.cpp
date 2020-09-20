#include <string>
#include <iostream>

using namespace std;

void ReplaceAndAppend()
{
    string testStr1 = "C++ primer ";
    string testStr2 = testStr1;
    string testStr3 = testStr1;
    // append操作
    testStr2.append("fuck you");
    // insert操作
    testStr3.insert(testStr3.size(), "fuck you");
    cout << testStr2 << endl;
    cout << testStr3 << endl;

    // replace操作，首先是下标和长度
    testStr2.replace(1, 4, "zg");
    cout << testStr2 << endl;
    // 范围迭代器
    testStr3.replace((++testStr3.begin()), (testStr3.end() - 2), "zhang");
    cout << testStr3 << endl;
}

void PrintFindPosition(string::size_type result, string &inputString)
{
    if (string::npos != result) {
        cout << "Find position is " << result << endl;
        cout << inputString[result] << endl;
    } else {
        cout << "Not find" << endl;
    }
}

void FindString()
{
    string testStr = "Guangdong zhang";
    // 查找第一次出现的位置
    auto result1 = testStr.find('a');
    PrintFindPosition(result1, testStr);
    auto result2 = testStr.find("zhang");
    PrintFindPosition(result2, testStr);

    // 查找最后一次出现的位置
    auto result3 = testStr.rfind('a');
    PrintFindPosition(result3, testStr);
    auto result4 = testStr.rfind("yong");
    PrintFindPosition(result4, testStr);
}

int main()
{
    ReplaceAndAppend();
    FindString();
}
