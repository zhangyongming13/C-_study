#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "mapAndSet.h.h"

using namespace std;

void PrintMap(const map<char, unsigned int>& inputMap) {
    cout << "map size is " << inputMap.size() << endl;
    // 遍历map，迭代器成员first指向的是关键字，second指向的是value
    for (const auto &i : inputMap) {
        cout << "char " << i.first << " occurs times is " << i.second << endl;
    }
}

Person::Person(const string &personName, unsigned int personAge) {
    this->name = personName;
    this->age = personAge;
}

bool MyCompare(const Person &p1, const Person &p2) {
    return (p1.age < p2.age) || (p1.age == p2.age && (p1.name.length() < p2.name.length()));
}

void overloadOperator()
{
    // 指定严格弱序函数
    map<Person, unsigned int, decltype(&MyCompare)> testMap1(MyCompare);
    testMap1[Person("Jack", 12)] = 123;
    testMap1[Person("MarkTw", 12)] = 456;
    testMap1[Person("Andrew", 23)] = 789;
    for (const auto& i : testMap1) {
        cout << i.first.name << " age is " << i.first.age << " ID is " << i.second << endl;
    }
}

void UsingMap()
{
    // 统计string中出现字符的次数，另外这里可以注意到，关键字为char类型，默认情况下map会根据char顺序进行排序
    string testStr = "gemstones";
    map<char, unsigned int> testMap1;
    for (auto i : testStr) {
        if (' ' != i) {
            testMap1[i]++;
        }
    }
    cout << "test map" << endl;
    PrintMap(testMap1);
}

void UsingSet()
{
    // 统计string中除了原音之外的字母出现次数
    set<char> testSet = {'a', 'e', 'i', 'o', 'u'};
    string testStr = "gemstones";
    map<char, unsigned int> testMap1;
    for (auto i : testStr) {
        if (testSet.find(tolower(i)) == testSet.cend()) {
            testMap1[i]++;
        }
    }
    cout << "test set" << endl;
    PrintMap(testMap1);

    // multimap或multiset
    vector<int> testVec;
    for (int i = 0; i <= 2; ++i) {
        testVec.emplace_back(i);
        testVec.emplace_back(i);
    }
    // 正常的set，不包含重复的元素,size只有3个元素
    set<int> testSet1(testVec.cbegin(), testVec.cend());
    cout << "normal set size is " << testSet1.size() << endl;
    // multiset可以包含重复元素，size有6个元素
    multiset<int> testSet2(testVec.cbegin(), testVec.cend());
    cout << "multiset size is " << testSet2.size() << endl;
}

void AssContainerIter()
{
    map<char, unsigned int> testMap1;
    testMap1['a'] = 0;
    testMap1['b'] = 1;
    testMap1['c'] = 2;
    // 迭代器范围map内容并修改value，需要注意的是不能通过迭代器修改key
    for (auto & i : testMap1) {
        if ('c' == i.first) {
            i.second = 4;
        }
    }
    cout << testMap1['c'] << endl;
}

void AssContainerInsert()
{
    map<char, unsigned int> testMap1;
    // 可以看到插入重复的关键字元素，不会报错，只是生命都不坐，value也是原来的0
    auto ret = testMap1.insert({'a', 0});
    if (ret.second) {
        cout << "insert success" << endl;
        cout << "insert key is " << ret.first->first << endl;
        cout << "insert value is " << ret.first->second << endl;
    }
    ret = testMap1.insert({'a', 1});
    if (!ret.second) {
        cout << "insert fail" << endl;
    }

    multiset<char> testSet1;
    auto retSet = testSet1.insert('a');
    cout << "insert key is " << *retSet << endl;
    retSet = testSet1.insert('a');
    cout << "insert key is " << *retSet << endl;
    cout << testSet1.size() << endl;
}

void AssContainerErase()
{
    map<char, unsigned int> testMap1;
    testMap1.insert({'a', 0});
    testMap1.insert({'b', 1});
    auto insertRet = testMap1.insert({'c', 2});
    // erase传入一个迭代器删除掉刚插入的c
    testMap1.erase(insertRet.first);
    if (testMap1.end() == testMap1.find('c')) {
        cout << "erase success" << endl;
    }

    // erase传入一个key来删除对应的元素
    auto eraseRet = testMap1.erase('b');
    if (1 == eraseRet) {
        cout << "erase success" << endl;
    }
}

void AssContainerFindCount()
{
    map<char, unsigned int> testMap1;
    testMap1.insert({'a', 0});
    testMap1.insert({'b', 1});
    testMap1.insert({'c', 2});
    // find 查找元素并访问
    auto ret = testMap1.find('a');
    if (testMap1.end() != ret) {
        cout << "find and value is " << ret->second << endl;
    }
    auto occurTimes = testMap1.count('b');
    cout << "b occur times is " << occurTimes << endl;
}

int main()
{
    AssContainerFindCount();
    return 0;
}
