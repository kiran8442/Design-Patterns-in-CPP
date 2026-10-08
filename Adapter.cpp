#include <iostream>
using namespace std;
//Target interface
class Target
{
    public:
    ~Target() = default;
    virtual void request() = 0; 
};
//incompatible interface 
class Adaptee
{
    public:
    void SpecialRequest()
    {
        cout<< "\nCharging is Started\n";
    }
    virtual ~Adaptee() = default;
};
class Adapter: public Target
{
    Adaptee* adaptee;
    public:
    Adapter(Adaptee* usbCharger)
    {
        adaptee = usbCharger;
    }
    void request() override
    {
        adaptee->SpecialRequest();
    }

};
int main()
{
    Adaptee* usbCharger = new Adaptee();

    Target* powerAdapter = new Adapter(usbCharger);
    powerAdapter->request();
    delete usbCharger;
    delete powerAdapter;
    return 0;
}