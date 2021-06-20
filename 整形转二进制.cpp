#include <iostream>
#include <string>

using namespace std;

string IntToBin(int number)
{
    string result;
    for (int i = 32; i >= 0; --i) {
        auto tmp = number >> i & 1;
        result.push_back(tmp + '0');
    }

    return result;
}

int main()
{
    cout << IntToBin(100) << endl;
}
