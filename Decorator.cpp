#include <iostream>
using namespace std;
class Coffee
{
    public:
    virtual string getDescription() = 0;
    virtual double getCost() = 0;
    virtual ~Coffee() = default;
};
class BasicCoffee: public Coffee
{
    
    public:
    std::string getDescription() override
    {
        return "Basic Coffee";
    }
    double getCost() override
    {
        return 100.0;
    }
};
class Decorator: public Coffee
{
    protected:
    Coffee* coffee;
    public: 
    Decorator(Coffee* c):coffee(c)
    {
    }
};
class MilkDecorator: public Decorator
{
    public: 
    MilkDecorator(Coffee* c):Decorator(c)
    {
    }
    std::string getDescription() override
    {
        return coffee->getDescription() + ", Milk";
    }
    double getCost() override
    {
        return coffee->getCost() + 20.0;
    }

};
class SugarDecorator: public Decorator
{
    public: 
    SugarDecorator(Coffee* c):Decorator(c)
    {
    }
    std::string getDescription() override
    {
        return coffee->getDescription() + ", Sugar";
    }
    double getCost() override
    {
        return coffee->getCost() + 30.0;
    }
};
class ChocolateDecorator: public Decorator
{
    public: 
    ChocolateDecorator(Coffee* c):Decorator(c)
    {
    }
    std::string getDescription() override
    {
        return coffee->getDescription() + ", Chocolate";
    }
    double getCost() override
    {
        return coffee->getCost() + 50.0;
    }
};

int main()
{
    Coffee* coffee = new BasicCoffee();
     cout << coffee->getDescription() << endl;
    cout << "Cost: " << coffee->getCost() << endl;

    coffee = new MilkDecorator(coffee);
    cout << coffee->getDescription() << endl;
    cout << "Cost: " << coffee->getCost() << endl;
    
    coffee = new SugarDecorator(coffee);
    cout << coffee->getDescription() << endl;
    cout << "Cost: " << coffee->getCost() << endl;
    
    coffee = new ChocolateDecorator(coffee);
    cout << coffee->getDescription() << endl;
    cout << "Cost: " << coffee->getCost() << endl;
    delete coffee;
    return 0;
}