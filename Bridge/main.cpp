#include <iostream>

using namespace std;

class Drawer {
public:
    virtual void drawCircle(int x, int y, int radius) = 0;
};

class SmallCircleDrawer : public Drawer {
public:
    const double radiusMultiplier = 0.25;

    void drawCircle(int x, int y, int radius) override
    {
        cout << "Small circle center " << x << ", " << y << " radius = " <<
                radius*radiusMultiplier << endl;
    }
};

class LargeCircleDrawer : public Drawer {
public:
    const double radiusMultiplier = 10;

    void drawCircle(int x, int y, int radius) override
    {
        cout << "Large circle center " << x << ", " << y << " radius = " <<
                radius*radiusMultiplier << endl;
    }
};

class Shape {
protected:
    Drawer* drawer;

public:
    Shape(Drawer* drw) {
        drawer = drw;
    }
    Shape() {}

    virtual void draw() = 0;
    virtual void enlargeRadius(int multiplier) = 0;
};

class Circle : public Shape {
    int x, y, radius;
public:
    Circle(int _x, int _y, int _radius, Drawer* drw)
    {
        drawer = drw;
        setX(_x);
        setY(_y);
        setRadius(_radius);
    }
    void draw() override {
        drawer->drawCircle(x, y, radius);
    }
    void enlargeRadius(int multiplier) override {
        radius *= multiplier;
    }
    void setX(int _x) {
        x = _x;
    }
    void setY(int _y) {
        y = _y;
    }
    void setRadius(int _radius) {
        radius = _radius;
    }
};

int main(int argc, char *argv[])
{
    Shape* shapes[2] = { new Circle(5,10,10, new LargeCircleDrawer()),
                         new Circle(20,30,100, new SmallCircleDrawer())};
    for (int i =0 ; i < 2; i++)
    {
        shapes[i]->draw();
    }
    return 0;
}
// Output
//Large circle center = 5,10 radius = 100
//Small circle center = 20,30 radius = 25.0
