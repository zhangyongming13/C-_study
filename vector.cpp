#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void VectorInit()
{
    // vector初始化，初始化成包含4个元素的vector
    vector<int> v1{4};
    for (auto i : v1) {
        cout << i << endl;
    }

    // 列表初始化
    vector<char> v2{'a', 'b', 'c', 'd'};

    // 在确定vector的大小不超过4的时候，定义的时候就给出大小，避免后面vector出现二次分配的情况
    vector<char> v4(4);
    // v5有4个a组成
    vector<char> v5(4, 'a');

    // vector的遍历
    // c++11的新特性
    for (auto i : v5) {
        cout << i << ' ';
    }
    cout << endl;
    // 使用c++11的新特性对vector里面的元素进行修改
    for (auto &i : v4) {
        i = 'b';
    }
    for (auto i : v4) {
        cout << i << ' ';
    }
    v4.push_back('g');
    cout << endl;
}

void PrintVector(vector<int> testVec)
{
    for (auto &i : testVec) {
        cout << i << " ";
    }
    cout << endl;
}

void VectorAdd()
{
    vector<int> testVec1;
    // push_back方式添加元素
    testVec1.push_back(1);
    testVec1.push_back(2);
    PrintVector(testVec1);

    // insert方式
    auto newInsertValue = testVec1.insert(testVec1.begin(), 0);
    cout << *newInsertValue << endl;
    PrintVector(testVec1);

    // push_back和insert性能比较，都是插入10万个数字
    // 实测push_back会比insert好
    vector<unsigned int> testVec2;
    clock_t startTime = clock();
    for (unsigned int i = 0; i < 1000000; ++i) {
        testVec2.push_back(i);
    }
    clock_t endTime = clock();
    cout << "Push back consumed time " << (double)(endTime - startTime) / CLOCKS_PER_SEC << endl;

    vector<unsigned int> testVec3;
    startTime = clock();
    for (unsigned int i = 0; i < 1000000; ++i) {
        testVec3.insert(testVec3.end(), i);
    }
    endTime = clock();
    cout << "Insert consumed time " << (double)(endTime - startTime) / CLOCKS_PER_SEC << endl;
}

void VectorDelete()
{
    vector<int> testVec1;
    for (int i = 0; i <= 5; ++i) {
        testVec1.push_back(i);
    }

    // erase删除第一个元素，迭代器指向了1
    auto iteratorBegin = testVec1.begin();
    cout << "The value before erase is " << *iteratorBegin << endl;
    testVec1.erase(iteratorBegin);
    cout << "The value after erase is " << *iteratorBegin << endl;

    // pop_back删除最后一个元素
    cout << "The number of testVec before pop back is " << testVec1.size() << endl;
    testVec1.pop_back();
    cout << "The number of testVec after pop back is " << testVec1.size() << endl;

    // clear()删除所有的元素
    testVec1.clear();
    if (testVec1.empty()) {
        cout << "testVec is empty" << endl;
    }
}

void VectorOther()
{
    vector<int> testVec(4);
    for (int i = 0; i <= 3; ++i) {
        testVec[i] = i + 1;
    }

    // reserve
    cout << "Before reserve the capacity of testVec is " << testVec.capacity() << endl;
    cout << "Before reserve the size of testVec is " << testVec.size() << endl;
    testVec.reserve(10);
    cout << "After reserve the capacity of testVec is " << testVec.capacity() << endl;
    cout << "After reserve the size of testVec is " << testVec.size() << endl;

    // resize，增加大小
    cout << "Before resize the capacity of testVec is " << testVec.capacity() << endl;
    cout << "Before resize the size of testVec is " << testVec.size() << endl;
    testVec.resize(100);
    cout << "After resize the capacity of testVec is " << testVec.capacity() << endl;
    cout << "After resize the size of testVec is " << testVec.size() << endl;

    // resize，减小大小
    cout << "Before resize the capacity of testVec is " << testVec.capacity() << endl;
    cout << "Before resize the size of testVec is " << testVec.size() << endl;
    testVec.resize(2);
    cout << "After resize the capacity of testVec is " << testVec.capacity() << endl;
    cout << "After resize the size of testVec is " << testVec.size() << endl;
    testVec.push_back(3);
    PrintVector(testVec);
}

int main()
{
    VectorInit();
    VectorAdd();
    VectorDelete();
    VectorOther();
    return 0;
}