#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void calculateArea() = 0;
    virtual void draw() = 0;
};

class Circle : public Shape
{
private:
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    }

    void calculateArea()
    {
        float area = 3.14 * radius * radius;
        cout << "Area of Circle = " << area << endl;
    }

    void draw()
    {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape
{
private:
    float length, width;

public:
    Rectangle(float l, float w)
    {
        length = l;
        width = w;
    }

    void calculateArea()
    {
        float area = length * width;
        cout << "Area of Rectangle = " << area << endl;
    }

    void draw()
    {
        cout << "Drawing Rectangle" << endl;
    }
};

int main()
{
    Shape *s[2];

    Circle c(5);
    Rectangle r(10, 4);

    s[0] = &c;
    s[1] = &r;

    for (int i = 0; i < 2; i++)
    {
        s[i]->calculateArea();
        s[i]->draw();
        cout << endl;
    }

}