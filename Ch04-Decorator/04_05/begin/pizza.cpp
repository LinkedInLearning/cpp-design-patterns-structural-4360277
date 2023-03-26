#include <iostream>
using namespace std;

class Pizza
{
public:
    virtual string description() const = 0;
    virtual double price() const = 0;
    virtual ~Pizza() = default;
};

class MargheritaPizza : public Pizza
{
public:
    string description() const override
    {
        return "Margherita Pizza";
    }

    double price() const override
    {
        return 9.99;
    }
};

class HawaiianPizza : public Pizza
{
public:
    string description() const override
    {
        return "Hawaiian Pizza";
    }

    double price() const override
    {
        return 11.99;
    }
};

class PepperoniPizza : public Pizza
{
public:
    string description() const override
    {
        return "Pepperoni Pizza";
    }

    double price() const override
    {
        return 12.99;
    }
};

int main()
{
    const std::unique_ptr<Pizza> pizzas[]{
        make_unique<MargheritaPizza>(),
        make_unique<PepperoniPizza>(),
        make_unique<HawaiianPizza>()};

    for (const auto &pizza : pizzas)
    {
        cout << pizza->description() << " costs $" << pizza->price() << endl;
    }

    return 0;
}
