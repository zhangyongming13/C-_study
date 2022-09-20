#include <iostream>

// 懒汉模式单例类
class SingletonClassIdler
{
public:
    // 返回唯一实例地址，只有GetInstance第一次调用的时候才会创建实例
    static SingletonClassIdler* GetInstance()
    {
        if (m_pObject == nullptr) {
            m_pObject = new SingletonClassIdler;
        }
        return m_pObject;
    }

public:
    unsigned int number;

private:
    // 私有构造函数确保唯一实例
    SingletonClassIdler()
    {
        this->number = 88;
    }

    ~SingletonClassIdler() = default;

    // 只负责SingletonClassIdler的资源释放
    class CGarbo
    {
    public:
        ~CGarbo()
        {
            delete SingletonClassIdler::m_pObject;
            std::cout << "m_pObject was delete!" << std::endl;
        }
    };
    // 创建类的静态成员变量
    static CGarbo cGarbo;

private:
    static SingletonClassIdler *m_pObject;
};

// 类中static定义的数据成员必须在类外初始化，因为它是整个类的一部分而不是属于某个对象的
SingletonClassIdler *SingletonClassIdler::m_pObject = nullptr;
SingletonClassIdler::CGarbo SingletonClassIdler::cGarbo;

int main()
{
    SingletonClassIdler* a1 = SingletonClassIdler::GetInstance();
    std::cout << "Object address is " << a1 << std::endl;
    std::cout << a1->number << std::endl;
    SingletonClassIdler* b1 = SingletonClassIdler::GetInstance();
    std::cout << "Object address is " << b1 << std::endl;
    std::cout << b1->number << std::endl;

    return 0;
}
