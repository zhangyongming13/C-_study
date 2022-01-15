#include <iostream>

using namespace std;

class Rational {
public:
    // 故意不添加explicit来允许隐式转换
    Rational(int numerator = 0, int denominator = 1)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

public:
    // 分子
    int numerator;
    // 分母
    int denominator;
};

// 生成一个non-member函数来做运算
Rational operator*(const Rational &lhs, const Rational &rhs)
{
    Rational tmpRa;
    tmpRa.numerator = lhs.numerator * rhs.numerator;
    tmpRa.denominator = lhs.denominator * rhs.denominator;
    return tmpRa;
}

void PrintResult(const Rational &result)
{
    cout << "result numerator is " << result.numerator << endl;
    cout << "result denominator is " << result.denominator << endl;
}

// 正常情况
void Normal()
{
    Rational oneEight(1, 8);
    Rational oneHalf(1, 2);
    Rational result1 = oneEight * oneHalf;
    PrintResult(result1);
    Rational result2 = oneHalf * oneEight;
    PrintResult(result2);
}

// 产生错误的调用
void Error()
{
    Rational onEight(1, 8);
    // 这样也是没有问题的--等效于onEight.operator*(2)
    Rational result1 = onEight * 2;
    PrintResult(result1);
    // 这样编译器就会报错--等效于2.operator*(oneHalf)
    Rational result2 = 2 * onEight;
    PrintResult(result2);
}

int main()
{
    Error();

    return 0;
}
