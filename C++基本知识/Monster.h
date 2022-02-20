#include <string>

using namespace std;

class Monster
{
public:
    // default表示默认存在构造函数和析构函数
    Monster() = default;
    virtual ~Monster() = default;
    virtual bool Attack();
    virtual int GetMonsterHealthValue();
    string GetMonsterName();
    // static表示所有对象共享一个这个函数，static如果有初始化必须在类外进行初始化
    static void MonsterAttackWaring();
protected:
    // 派生类是public继承，所以MonsterName这个类在派生类中依然是protected
    string MonsterName;
};

class WereWolf : public Monster
{
public:
    WereWolf(int WereWolfHealthValue, const string &MonsterName);
    // 重载了基类的虚函数，需要添加override让编译器进行重载检测
    ~WereWolf() override = default;
    bool Attack() override;
    int GetMonsterHealthValue() override;

private:
    int WereWolfHealthValue;
};

class Spider : public Monster
{
public:
    Spider(int SpiderHealthValue, const string &MonsterName);
    ~Spider() override = default;
    bool Attack() override;
    int GetMonsterHealthValue() override;

private:
    int SpiderHealthValue;
};