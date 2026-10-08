#include <iostream>
#include <mutex>

using namespace std;

std::mutex m;
class singleton
{
    static singleton* instance;
    singleton()
    {
        instance = nullptr;
    }
    public:
    singleton(const singleton& other) = delete;
    singleton& operator=( const singleton& other) = delete;

    static singleton* getInstance()
    {
        std::lock_guard lock(m);
        if(instance == nullptr)
            instance = new singleton();
        return instance;
    }
    void show()
    {
        cout << "\nshow() function from singleton class\n";
    }
};
singleton* singleton::instance = nullptr;

int main()
{
    singleton* p1 = singleton::getInstance();
    p1->show();
    singleton* p2 = singleton::getInstance();
    p2->show();
    if(p1 == p2)
        cout <<"\nSame Instance\n";
    else 
        cout <<"\nDifferent Instance\n";
    return 0;
}