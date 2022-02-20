#include <memory>
#include <iostream>

using namespace std;

class Point {
public:
    Point() {
        x = 0;
        y = 0;
    }

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void SetX(int newX) {
        this->x = newX;
    }

    int GetX() const {
        return x;
    }

    void SetY(int newY) {
        this->y = newY;
    }

    int GetY() const {
        return y;
    }

private:
    int x;
    int y;
};

struct RectData {
    RectData(const Point &upperLeft, const Point &lowerRight) {
        this->upperLeft = upperLeft;
        this->lowerRight = lowerRight;
    }

    Point upperLeft;
    Point lowerRight;
};

class Rectangle {
public:
    explicit Rectangle(const RectData &rectData) {
        pData = make_shared<RectData>(rectData);
    }

    Point& upperLeft() const {
        return pData->upperLeft;
    }

    Point& lowerRight() const {
        return pData->lowerRight;
    }

private:
    shared_ptr<RectData> pData;
};

int main()
{
    Point coord1(0, 0);
    Point coord2(100, 100);
    RectData rectData(coord1, coord2);
    Rectangle rectangle(rectData);

    cout << "upper x is " << rectangle.upperLeft().GetX() << endl;
    rectangle.upperLeft().SetX(50);
    cout << "upper x is " << rectangle.upperLeft().GetX() << endl;

    return 0;
}
