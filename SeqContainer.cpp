#include <iostream>
#include <vector>
#include <deque>
#include <list>

using namespace std;

void PrintVector(const vector<int>& testVec)
{
    for (auto i : testVec) {
        cout << i << ' ';
    }
    cout << endl;
}

void PrintVector(const vector<char>& testVec)
{
    for (auto i : testVec) {
        cout << i << ' ';
    }
    cout << endl;
}

void PrintDeque(const deque<int>& testDeque)
{
    for (auto i : testDeque) {
        cout << i << ' ';
    }
    cout << endl;
}

void PrintList(const list<int>& testList)
{
    for (auto i : testList) {
        cout << i << ' ';
    }
    cout << endl;
}

void SeqContainerIter()
{
    vector<int> testVec = {1, 2, 3, 4};
    // 普通begin和end,默认情况begin和end都是普通iterator类型，可以进行修改操作
    for (auto i = testVec.begin(); i != testVec.end(); ++i) {
        if (3 == *i) {
            *i = 5;
        }
        cout << *i << ' ';
    }
    cout << endl;

    // cbegin和cend是const_iterator类型，只能读取元素不能修改元素，应用于只需要读取的场景
    for (auto i = testVec.cbegin(); i != testVec.cend(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;

    // 反向迭代器
    for (auto i = testVec.crbegin(); i != testVec.crend(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

void SeqContainerOperation()
{
    vector<char> testVec = {'a', 'b', 'c'};
    // push_back添加元素
    testVec.push_back('d');
    cout << *(--testVec.cend()) << endl;

    // string也是顺序容器也可以进行push_back的操作
    string testString = "test";
    testString.push_back('z');
    cout << testString << endl;

    // push_front将元素放到头部
    deque<int> testDeque = {1, 2, 3, 4};
    testDeque.push_front(0);
    cout << testDeque[0] << endl;

    list<char> testList = {'b', 'c', 'd'};
    testList.push_front('a');
    cout << *testList.cbegin() << endl;

    // insert在任意位置插入元素
    auto newValueIter = testVec.insert(++testVec.begin(), 'g');
    cout << *newValueIter << endl;
    // 插入一个范围的值
    deque<int> testList1 = {7, 8, 9, 10};
    auto iterBegin = ++testDeque.cbegin();
    auto iterEnd = testDeque.cend();
    auto newValueIter1 = testList1.insert(++testList1.cbegin(), iterBegin, iterEnd);
    PrintDeque(testList1);
    cout << *newValueIter1 << endl;

    // pop_front删除第一个元素
    list<int> testList2 = {1, 2, 3};
    testList2.pop_front();
    PrintList(testList2);
    // pop_back删除最后一个元素
    testList2.pop_back();
    PrintList(testList2);

    // erase实现边遍历边删除的操作，这里以删除大写字母为例
    vector<char> testVec1 = {'a', 'B', 'C', 'd'};
    auto iteratorVec = testVec1.begin();
    while (testVec1.end() != iteratorVec) {
        if (isupper(*iteratorVec)) {
            iteratorVec = testVec1.erase(iteratorVec);
        } else {
            ++iteratorVec;
        }
    }
    PrintVector(testVec1);
}

int main()
{
    SeqContainerIter();
    SeqContainerOperation();
}
