#include <iostream>
#include <string>

class Shape {
public:
    Shape(int objectId)
    {
        this->ObjectId = objectId;
    }

    // 纯虚函数
    virtual void Draw() const = 0;

    // 非纯虚函数
    virtual void Error(const std::string& msg)
    {
        std::cout << msg << std::endl;
    }

    // 非虚函数
    int GetObjectId() const
    {
        return this->ObjectId;
    }

public:
    int ObjectId;
};

class Rectangle : public Shape {
public:
    Rectangle(int objectId) : Shape(objectId) {}
};

class Ellipse : public Shape {
public:
    Ellipse(int objectId) : Shape(objectId) {}
};

// 用来表现机场
class Airport {};
class Airplane {
public:
    // Fly改为纯虚函数，但是还是提供了默认实现
    virtual void Fly(const Airport& destination) = 0;
};

void Airplane::Fly(const Airport &destination)
{
    // 缺省行为，将飞机飞到目的地
}

// 不同型号的飞机
class ModelA : public Airplane {
    virtual void Fly(const Airport& destination)
    {
        // 调用父类Airplane的Fly
        Airplane::Fly(destination);
    }
};
class ModelB : public Airplane {
    virtual void Fly(const Airport& destination)
    {
        Airplane::Fly(destination);
    }
};
// C有自己的飞行方式
class ModelC : public Airplane {
    virtual void Fly(const Airport& destination)
    {
        // C自己的飞行方式
    }
};

int main()
{
    Airport PDX;
    Airplane *pa = new ModelC;
    // 因为C没有实现自己的飞行函数，调用的是自己的Fly，所以这里没有问题
    pa->Fly(PDX);

    return 0;
}
