#include <iostream>

using namespace std;
class Computer
{
    private:
        std::string cpu;
        int ram;
        string storage;
        string gpu;
        bool wifi;
        bool blutooth;   
    public:
    void setRAM(int r)
    {
        ram = r;
    }
    void setCPU(string& c)
    {
        cpu = c;
    }
    void setStorage(string& s)
    {
        storage = s;
    }
    void gpu(string& g)
    {
        gpu = g;
    }
    void setWifi(bool w)
    {
        wifi = w;
    }
    void setBlutooth(bool b)
    {
        blutooth = b;
    }
    void Display()
    {
        cout<<"\nPC is available to use with following Configuration:\n"
            <<"CPU:" << cpu
            <<", RAM: "<< ram
            <<", Storage: "<< storage
            <<", Graphics: "<< gpu
            <<", Wifi: "<< wifi
            <<", Blutooth: "<< blutooth << endl;
    }
};
class ComputerBuilder
{
    Computer computer;
    public:
    ComputerBuilder& setRAM(int r)
    {
        computer.setRAM(r);
        return *this;
    }
    ComputerBuilder& setCPU(string& c)
    {
        computer.setCPU(c);
        return *this;
    }
    ComputerBuilder& setStorage(string& s)
    {
        computer.setStorage(s);
        return *this;
    }
    ComputerBuilder& gpu(string& g)
    {
        gpu = g;
        return *this;
    }
    ComputerBuilder& setWifi(bool w)
    {
        wifi = w;
        return *this;
    }
    ComputerBuilder& setBlutooth(bool b)
    {
        blutooth = b;
        return *this;
    }
    Computer Build()
    {
        return computer; 
    }
};
int main()
{
     Computer gamingPC = ComputerBuilder()
                            .setCPU("Intel i9")
                            .setRAM(32)
                            .setStorage("2TB SSD")
                            .setGPU("RTX 4080")
                            .setWifi(true)
                            .setBluetooth(true)
                            .Build();

    Computer officePC = ComputerBuilder()
                            .setCPU("Intel i5")
                            .setRAM(16)
                            .setStorage("1TB SSD")
                            .setGPU("Integrated Graphics")
                            .setWifi(true)
                            .setBluetooth(false)
                            .Build();

    gamingPC.Display();

    officePC.Display();
    return 0;
}