#include <iostream>

using namespace std;

class WebBrowser {
public:
    WebBrowser() = default;
    ~WebBrowser() = default;
    void ClearCache()
    {
        cout << "ClearCache" << endl;
    }

    void ClearHistory()
    {
        cout << "ClearHistory" << endl;
    }

    void RemoveCookies()
    {
        cout << "RemoveCookies" << endl;
    }

    // class内提供调用上述函数的方法
    void ClearEveryThing()
    {
        ClearCache();
        ClearHistory();
        RemoveCookies();
    }
};

// 由一个非成员函数调用三种清除方法
void ClearBrowser(WebBrowser &wb)
{
    wb.ClearCache();
    wb.ClearHistory();
    wb.RemoveCookies();
}

int main()
{
    WebBrowser webBrowser;
    webBrowser.ClearEveryThing();
    ClearBrowser(webBrowser);

    return 0;
}
