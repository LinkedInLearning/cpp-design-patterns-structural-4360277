#include <iostream>
#include <memory>
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

class ToppingDecorator : public Pizza
{
public:
    explicit ToppingDecorator(unique_ptr<Pizza> pizza) : m_Pizza(move(pizza)) {}

    string description() const override
    {
        return m_Pizza->description();
    }

    double price() const override
    {
        return m_Pizza->price();
    }

    virtual ~ToppingDecorator() = default;

private:
    const unique_ptr<Pizza> m_Pizza;
};

class MushroomDecorator : public ToppingDecorator
{
public:
    explicit MushroomDecorator(unique_ptr<Pizza> pizza) : ToppingDecorator(move(pizza)) {}

    string description() const override
    {
        return ToppingDecorator::description() + " with mushrooms";
    }

    double price() const override
    {
        return ToppingDecorator::price() + 0.99;
    }
};

class ExtraCheeseDecorator : public ToppingDecorator
{
public:
    explicit ExtraCheeseDecorator(unique_ptr<Pizza> pizza) : ToppingDecorator(move(pizza)) {}

    string description() const override
    {
        return ToppingDecorator::description() + ", plus extra cheese";
    }

    double price() const override
    {
        return ToppingDecorator::price() + 1.99;
    }
};

class TomatoDecorator : public ToppingDecorator
{
public:
    explicit TomatoDecorator(unique_ptr<Pizza> pizza) : ToppingDecorator(move(pizza)) {}

    string description() const override
    {
        return ToppingDecorator::description() + ", plus tomatoes";
    }

    double price() const override
    {
        return ToppingDecorator::price() + 0.79;
    }
};

int main()
{
    // MargheritaPizza with mushrooms and extra cheese
    auto margheritaPizza = make_unique<MargheritaPizza>();
    auto margheritaWithMushrooms = make_unique<MushroomDecorator>(move(margheritaPizza));
    auto margheritaExtraCheeseMushrooms = make_unique<ExtraCheeseDecorator>(move(margheritaWithMushrooms));

    cout << margheritaExtraCheeseMushrooms->description() << " costs $" << margheritaExtraCheeseMushrooms->price() << endl;

    // Pepperoni pizza with mushrooms, tomatoes, and extra cheese
    auto pepperoniPizza = make_unique<PepperoniPizza>();
    auto pepperoniWithMushrooms = make_unique<MushroomDecorator>(move(pepperoniPizza));
    auto pepperoniWithTomatoMushrooms = make_unique<TomatoDecorator>(move(pepperoniWithMushrooms));
    auto pepperoniTomatoMushroomsExtraCheese = make_unique<ExtraCheeseDecorator>(move(pepperoniWithTomatoMushrooms));

    cout << pepperoniTomatoMushroomsExtraCheese->description() << " costs $" << pepperoniTomatoMushroomsExtraCheese->price() << endl;

    return 0;
}
