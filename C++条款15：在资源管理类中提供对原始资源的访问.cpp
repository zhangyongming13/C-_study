//
// Created by Zhang on 2021/11/16.
//

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

void ManualUse(Product *pProduct)
{
    pProduct->ConsumerProduct();
}

void Consumer()
{
    // 使用智能指针指向工厂函数返回的指针，确保在离开作用域的时候自动释放内存
    shared_ptr<Product> pProduct(CreateFactory());
    // 使用智能指针的get成员函数返回智能指针内部原始指针。
    ManualUse(pProduct.get());
}

int main()
{
    Consumer();

    return 0;
}
