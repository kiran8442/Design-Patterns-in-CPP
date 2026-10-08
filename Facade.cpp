#include <iostream>
using namespace std;
class CPU
{
    public:
    void start()
    {
        cout<< "\nCPU Started\n";
    }
};

class Memory
{
    public:
    void load()
    {
        cout<< "\nMemory Load\n";
    }
};
class HardDrive
{
    public:
    void read()
    {
        cout<<"\nHardDrive is reading the Data\n";
    }
};
class OperatingSystem
{
    public:
    void boot()
    {
        cout << "\nOperating System is Booted\n";
    }
};
class Computer
{
    CPU cpu;
    Memory memory;
    HardDrive harddrive;
    OperatingSystem os;

    public:
    void TurnOn()
    {
        cpu.start();
        memory.load();
        harddrive.read();
        os.boot();
    }
    void TurnOff()
    {
        cout << "\nTurning off the computer\n";
    }
};

int main()
{
    Computer computer;
    computer.TurnOn();

    computer.TurnOff();
    return 0;
}