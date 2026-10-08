//Factory Design Pattern
#include <iostream>
using namespace std;

class Shape
{
    public:
    ~Shape() = default;
    virtual void findArea() = 0;
};
class Circle: public Shape
{
    public:
    void findArea() override
    {
        cout <<"\n Find Area of Circle\n";
    }
};
class Square: public Shape
{
    public:
    void findArea() override
    {
        cout <<"\n Find Area of Square\n";
    }
};

class Factory
{
    public:
    static Shape* createshape(const string& shape)
    {
        if(shape == "Circle")
        {
            new Circle();
        }
        else if( shape == "Square")
        {
            new Square();
        }
        else
            return nullptr;
    }
};
int main()
{
    Shape* shape1 = Factory::createshape("Circle");
    shape1->findArea();

    Shape* shape2 = Factory::createshape("Square");
    shape2->findArea();

    return 0;
}