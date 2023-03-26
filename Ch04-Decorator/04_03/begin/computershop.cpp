#include <iostream>
#include <string>

using namespace std;

class Computer
{
public:
    virtual string description() const = 0;
    virtual double price() const = 0;
    virtual ~Computer() = default;
};

class Desktop : public Computer
{
public:
    string description() const override
    {
        return "Desktop";
    }

    double price() const override
    {
        return 1000.0;
    }
};

class Laptop : public Computer
{
public:
    string description() const override
    {
        return "Laptop";
    }

    double price() const override
    {
        return 1500.0;
    }
};

// Upgrades
class DesktopWithMemoryUpgrade : public Desktop
{
public:
    string description() const override
    {
        return "Desktop with memory upgrade";
    }

    double price() const override
    {
        return 1700.0;
    }
};

class LaptopWithMemoryUpgrade : public Laptop
{
public:
    string description() const override
    {
        return "Laptop with memory upgrade";
    }

    double price() const override
    {
        return 2000.0;
    }
};

class DesktopWithGraphicsUpgrade : public Desktop
{
public:
    string description() const override
    {
        return "Desktop with graphics upgrade";
    }

    double price() const override
    {
        return 2000.0;
    }
};

class LaptopWithGraphicsUpgrade : public Laptop
{
public:
    string description() const override
    {
        return "Laptop with graphics upgrade";
    }

    double price() const override
    {
        return 2700.0;
    }
};

int main()
{
    Computer *desktop = new Desktop();
    cout << desktop->description() << " costs $" << desktop->price() << endl;

    Computer *laptop = new Laptop();
    cout << laptop->description() << " costs $" << laptop->price() << endl;

    Computer *desktopGraphicsUpgrade = new DesktopWithGraphicsUpgrade();
    cout << desktopGraphicsUpgrade->description() << " costs $" << desktopGraphicsUpgrade->price() << endl;

    Computer *desktopMemoryUpgrade = new DesktopWithMemoryUpgrade();
    cout << desktopMemoryUpgrade->description() << " costs $" << desktopMemoryUpgrade->price() << endl;

    Computer *laptopGraphicsUpgrade = new LaptopWithGraphicsUpgrade();
    cout << laptopGraphicsUpgrade->description() << " costs $" << laptopGraphicsUpgrade->price() << endl;

    Computer *laptopMemoryUpgrade = new LaptopWithMemoryUpgrade();
    cout << laptopMemoryUpgrade->description() << " costs $" << laptopMemoryUpgrade->price() << endl;

    delete desktop;
    delete laptop;
    delete desktopGraphicsUpgrade;
    delete desktopMemoryUpgrade;
    delete laptopGraphicsUpgrade;
    delete laptopMemoryUpgrade;

    return 0;
}
