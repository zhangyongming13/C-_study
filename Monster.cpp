#include <iostream>
#include <string>
#include "Monster.h"

using namespace std;

bool Monster::Attack() {
    return false;
}

int Monster::GetMonsterHealthValue() {
    return 0;
}

string Monster::GetMonsterName() {
    return this->MonsterName;
}

void Monster::MonsterAttackWaring() {
    cout << "You will be attack by a monster" << endl;
}

WereWolf::WereWolf(const int WereWolfHealthValue, const string &MonsterName)
{
    this->WereWolfHealthValue = WereWolfHealthValue;
    this->MonsterName = MonsterName;
}

bool WereWolf::Attack()
{
    cout << this->MonsterName << " attacked you!!!" << endl;
    return true;
}

int WereWolf::GetMonsterHealthValue()
{
    return this->WereWolfHealthValue;
}

Spider::Spider(int SpiderHealthValue, const string &MonsterName) {
    this->SpiderHealthValue = SpiderHealthValue;
    this->MonsterName = MonsterName;
}

bool Spider::Attack() {
    cout << this->MonsterName << "attack you!!!" << endl;
    return true;
}

int Spider::GetMonsterHealthValue() {
    return this->SpiderHealthValue;
}

int main()
{
    Monster *pMonster[2];
    pMonster[0] = new WereWolf(100, "WereWolf");
    pMonster[1] = new Spider(120, "Spider");
    for (int i = 0; i != 2; ++i) {
        pMonster[i]->MonsterAttackWaring();
        cout << "Monster name is " << pMonster[i]->GetMonsterName() << endl;
        cout << pMonster[i]->GetMonsterName() << " health value is " << pMonster[i]->GetMonsterHealthValue() << endl;
        pMonster[i]->Attack();
        cout << endl;
    }
    delete pMonster[0];
    delete pMonster[1];

    return 0;
}