#include <iostream>
#include <mutex>
#include <string>
#include <memory>

using namespace std;

class Image {
public:
    explicit Image(const string &imgName)
    {
        this->imageName = imgName;
    }

    ~Image()
    {
        cout << "delete Image" << endl;
    }

    void PrintImgName()
    {
        cout << imageName << endl;
    }

private:
    string imageName;
};

class Lock {
public:
    explicit Lock(mutex *pm) : mutexPtr(pm) {
        mutexPtr->lock();
    }

    ~Lock()
    {
        mutexPtr->unlock();
    }

    mutex *mutexPtr;
};

// 新建一个数据结构，方便副本的创建
struct PMImpl {
    explicit PMImpl(const string &imageName)
    {
        bgImage.reset(new Image(imageName));
        imageChanges = 0;
    }

    shared_ptr<Image> bgImage;
    int imageChanges;
};

class PrettyMenu {
public:
    PrettyMenu()
    {
        pImpl = nullptr;
    }

    ~PrettyMenu() = default;

    void ChangeBackground(const string &imgName)
    {
        using std::swap;
        Lock m1(pMutex);

        if (pImpl == nullptr) {
            pImpl.reset(new PMImpl(imgName));
            return;
        }

        // 创建一个副本
        shared_ptr<PMImpl> pNew(new PMImpl(*pImpl));
        // 修改副本文件
        pNew->bgImage.reset(new Image(imgName));
        ++(pNew->imageChanges);
        // 前面的动作都没有异常，交换数据
        swap(pImpl, pNew);
    }

    void PrintImage()
    {
        if (pImpl != nullptr) {
            pImpl->bgImage->PrintImgName();
        } else {
            cout << "no have image" << endl;
        }
    }

private:
    mutex *pMutex;
    shared_ptr<PMImpl> pImpl;
};

int main()
{
    PrettyMenu prettyMenu;
    prettyMenu.ChangeBackground("new image dir");
    prettyMenu.PrintImage();
    prettyMenu.ChangeBackground("zhangyongming");
    prettyMenu.PrintImage();

    return 0;
}
