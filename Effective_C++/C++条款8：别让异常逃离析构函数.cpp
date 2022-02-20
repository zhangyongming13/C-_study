#include <iostream>

using namespace std;

class DbConnection {
public:
    DbConnection()
    {
        cout << "Create connection!" << endl;
        isClose = false;
    }

    // 在析构函数中关闭连接，出现异常进行捕获，避免异常逃离析构函数
    ~DbConnection()
    {
        if (!isClose) {
            try {
                cout << "Close connection in destructor function!" << endl;
            } catch (...) {
                cout << "Can not close connection!" << endl;
            }
        }
    }

    // 提供接口给使用此类的人关闭连接，以便调用人在出现异常的时候处理异常场景
    bool Close()
    {
        try {
            cout << "Close connection!" << endl;
        } catch (...) {
            cout << "Can not close connection!" << endl;
            isClose = false;
            return false;
        }

        isClose = true;
        return true;
    }

private:
    bool isClose;
};

int main()
{
    // 手工调用Close关闭连接
    DbConnection dbConnection1;
    dbConnection1.Close();

    // 为手工关闭连接，依靠类的析构函数关闭并捕获异常场景
    DbConnection dbConnection2;

    return 0;
}
