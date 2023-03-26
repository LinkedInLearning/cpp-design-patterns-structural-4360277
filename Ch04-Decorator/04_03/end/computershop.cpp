#include <memory>
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

// Decorator base
class ComputerDecorator : public Computer
{
public:
    explicit ComputerDecorator(Computer *computer) : m_Computer(computer) {}

    string description() const override
    {
        return m_Computer->description();
    }

    double price() const override
    {
        return m_Computer->price();
    }

protected:
    const Computer *m_Computer;
};

// Upgrades
class MemoryUpgradeDecorator : public ComputerDecorator
{
public:
    explicit MemoryUpgradeDecorator(Computer *computer) : ComputerDecorator(computer) {}

    string description() const override
    {
        return ComputerDecorator::description() + " with memory upgrade";
    }

    double price() const override
    {
        return ComputerDecorator::price() + 500.0;
    }
};

class GraphicsUpgradeDecorator : public ComputerDecorator
{
public:
    explicit GraphicsUpgradeDecorator(Computer *computer) : ComputerDecorator(computer) {}

    string description() const override
    {
        return ComputerDecorator::description() + " with graphics upgrade";
    }

    double price() const override
    {
        return ComputerDecorator::price() + 500.0;
    }
};

int main()
{
    auto desktop = new Desktop();
    cout << desktop->description() << " costs $" << desktop->price() << endl;

    auto laptop = new Laptop();
    cout << laptop->description() << " costs $" << laptop->price() << endl;

    auto desktopMemoryUpgrade = new MemoryUpgradeDecorator(desktop);
    cout << desktopMemoryUpgrade->description() << " costs $" << desktopMemoryUpgrade->price() << endl;

    auto laptopGraphicsUpgrade = new GraphicsUpgradeDecorator(laptop);
    cout << laptopGraphicsUpgrade->description() << " costs $" << laptopGraphicsUpgrade->price() << endl;

    delete desktop;
    delete laptop;
    delete desktopMemoryUpgrade;
    delete laptopGraphicsUpgrade;

    return 0;
}