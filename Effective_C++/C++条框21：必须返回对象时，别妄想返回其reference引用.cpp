#include <iostream>

using namespace std;

class Rational {
public:
    Rational(int numerator = 0, int denominator = 1)
    {
        this->d = denominator;
        this->n = numerator;
    }

private:
    int n;
    int d;

    friend
    const Rational operator* (const Rational &lhs, const Rational &rhs)
    {
        Rational result(lhs.n * rhs.n, lhs.d * rhs.d);
        return result;
    }
};

int main()
{
    return 0;
}
