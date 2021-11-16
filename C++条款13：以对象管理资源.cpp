#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Product {
public:
    Product()
    {
        cout << "I am product!" << endl;
    }

    ~Product()
    {
        cout << "Product had use!" << endl;
    }

    void ConsumerProduct()
    {
        cout << "Product use!" << endl;
    }
};

Product *CreateFactory()
{
    auto *pProduct = new Product();
    return pProduct;
}

void Consumer()
{
    // 使用智能指针指向工厂函数返回的指针，确保在离开作用域的时候自动释放内存
    shared_ptr<Product> pProduct(CreateFactory());
    pProduct->ConsumerProduct();
}

int main()
{
    Consumer();
    return 0;
}
