#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

#pragma push(1)
struct memoryRecord {
    memoryRecord (unsigned int vir, unsigned int phy)
    {
        virMemory = vir;
        phyMemory = phy;
    }

    unsigned int virMemory;
    unsigned int phyMemory;
};
#pragma pop()

// 在多个对象之间共享数据
class StrBlob {
public:
    typedef vector<string>::size_type size_type;

    StrBlob()
    {
        data = make_shared<vector<string>>();
    }

    StrBlob(initializer_list<string> il)
    {
        data = make_shared<vector<string>>(il);
    }

    size_type Size() const
    {
        return data->size();
    }

    bool Empty() const
    {
        return data->empty();
    }

    void push_back(const string &t)
    {
        data->push_back(t);
    }
    void pop_back()
    {
        check(0, "pop on empty StrBlob");
        data->pop_back();
    }

    string &front()
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    string &back()
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }

private:
    shared_ptr<vector<string>> data;

    // 如果data[i]不合法，抛出异常，异常信息记录在msg中
    void check(size_type i, const string&msg)
    {
        if (i >= data->size()) {
            throw out_of_range(msg);
        }
    }
};

shared_ptr<string> SharedPtrCount()
{
    shared_ptr<string> pStr1 = make_shared<string>("I am count!");

    // 这里pStr作为返回值，引用计数加1变为2，后续pStr离开函数作用域，引用计数变为1不为0，所以pStr管理对应不会被释放
    return pStr1;
}

void SharePtr()
{
    // shared_ptr定义，空指针
    shared_ptr<string> pStr1;
    shared_ptr<memoryRecord> pMemoryRec1;

    // 智能指针默认情况下，指向一个空指针。
    if (!pStr1) {
        cout << "pStr1 is null!" << endl;
    }

    // 定义并初始化，建议使用make_shared进行初始化
    shared_ptr<memoryRecord> pMemoryRec2 = make_shared<memoryRecord>(10, 20);
    if (pMemoryRec2) {
        cout << "pMemoryRec2 : Virtual memory is " << pMemoryRec2->virMemory << endl;
        cout << "pMemoryRec2 : Physics memory is " << pMemoryRec2->phyMemory << endl;
    }

    // p.get()，这里get返回的指针只对对象有访问的权限，不能进行delete的操作
    auto pMem = pMemoryRec2.get();
    cout << "pMem is " << pMem->phyMemory << endl;

    // swap操作
    swap(pMemoryRec1, pMemoryRec2);
    // 经过交换之后pMemoryRec1就不是空指针了，pMemoryRec2就变成了空指针
    if (pMemoryRec1) {
        pMemoryRec1->virMemory = 90;
        cout << "pMemoryRec1 : Virtual memory is " << pMemoryRec1->virMemory << endl;
    }

    // 引用计数器相关实例
    shared_ptr<int> pInt1 = make_shared<int>(23);
    shared_ptr<int> pInt2 = make_shared<int>(45);
    cout << "pInt1 count is " << pInt1.use_count() << endl;
    // 这里给pInt1重新赋值，原来指向的23已经没有引用，所以会被释放
    pInt1 = pInt2;

    shared_ptr<string> pStr2 = SharedPtrCount();
}

int main()
{
    SharePtr();

    // 可以看到在其他作用域中加入的about，即使出了作用域也保存在了strBlob1中，因为保存元素的智能指针还有指向，并没有被释放
    StrBlob strBlob1;
    {
        StrBlob strBlob2 = {"a", "an", "the"};
        strBlob1 = strBlob2;
        strBlob2.push_back("about");
    }
    cout << strBlob1.back() << endl;

    return 0;
}
