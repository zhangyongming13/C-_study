#include <iostream>

class SingletonClassHungry
{
public:
    static SingletonClassHungry* GetInstance()
    {
        return &singletonClassHungry;
    }

    // 禁止拷贝构造函数
    SingletonClassHungry(SingletonClassHungry &b) = delete;

public:
    unsigned int number;

private:
    SingletonClassHungry()
    {
        this->number = 100;
    }

    ~SingletonClassHungry() = default;

private:
    static SingletonClassHungry singletonClassHungry;
};

// 类中static定义的数据成员必须在类外初始化，因为它是整个类的一部分而不是属于某个对象的
SingletonClassHungry SingletonClassHungry::singletonClassHungry;

int main()
{
    SingletonClassHungry* a1 = SingletonClassHungry::GetInstance();
    std::cout << "Object address is " << a1 << std::endl;
    std::cout << a1->number << std::endl;
    SingletonClassHungry* b1 = SingletonClassHungry::GetInstance();
    std::cout << "Object address is " << b1 << std::endl;
    std::cout << b1->number << std::endl;

    return 0;
}
