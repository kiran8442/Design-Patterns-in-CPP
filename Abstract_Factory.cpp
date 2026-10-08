#include <iostream>

using namespace std;

class CheckBox
{
    public:
    virtual ~CheckBox() = default;
    virtual void clickcheckbox() = 0;
};
class Button
{
    public:
    virtual ~Button() = default;
    virtual void clickbutton() = 0;
};

class WindowsCheckBox:public CheckBox
{
    public:
    void clickcheckbox() override
    {
        cout<< "\nClicked Windows CheckBox\n";
    }
};
class LinuxCheckBox:public CheckBox
{
    public:
    void clickcheckbox() override
    {
        cout<< "\nClicked Linux CheckBox\n";
    }
};

class WindowsButton:public Button
{
    public:
    void clickbutton() override
    {
        cout<< "\nClicked Windows Button\n";
    }
};
class LinuxButton:public Button
{
    public:
    void clickbutton() override
    {
        cout<< "\nClicked Linux button\n";
    }
};

class AbstractFactory
{
    public:
    virtual Button* createbutton() = 0;
    virtual CheckBox* createcheckbox() = 0;
    virtual ~AbstractFactory() = default; 
};

class WindowsFactory:public AbstractFactory
{
    public:
    Button* createbutton() override
    {
        return new WindowsButton();
    }
    CheckBox* createcheckbox() override
    { 
        return new WindowsCheckBox();
    }

};
class LinuxFactory:public AbstractFactory
{
    public:
    Button* createbutton() override
    {
        return new LinuxButton();
    }
    CheckBox* createcheckbox() override
    { 
        return new LinuxCheckBox();
    }
};

int main()
{
    AbstractFactory* factory = new LinuxFactory();

    Button* btn = factory->createbutton();
    CheckBox* checkbox = factory->createcheckbox();
    btn->clickbutton();
    checkbox->clickcheckbox();
    return 0;
}
