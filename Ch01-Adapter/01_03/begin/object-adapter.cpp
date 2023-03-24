#include <iostream>

using namespace std;

class Component
{
public:
    virtual void run() = 0;
    virtual ~Component() = default;
};

class ConcreteComponentA: public Component
{
public:
    virtual void run() override
    {
        cout << "Executing ConcreteComponentA::run()" << endl;
    }
};

class ConcreteComponentB: public Component
{
public:
    virtual void run() override
    {
        cout << "Executing ConcreteComponentB::run()" << endl;
    }
};

// Incompatible class
class LegacyComponent
{
public:
    void go()
    {
        cout << "Executing LegacyComponent::go()" << endl;
    }    
};

class LegacyClassAdapter: public Component, private LegacyComponent
{
public:
    LegacyAdapter() : m_adaptee(make_unique<LegacyComponent>()) {}

    virtual void run() override
    {
        cout << "LegacyAdapter::run() -> calling LegacyComponent::go()" << endl;
        m_adaptee->go();
    }

private:
    unique_ptr<LegacyComponent> m_adaptee;
};


int main()
{    
    const unique_ptr<Component> components[]
    {
        make_unique<ConcreteComponentA>(),
        make_unique<ConcreteComponentB>(),
        make_unique<LegacyAdapter>()
    };
    
    for (const auto& component : components)
    {
        component->run();
    }
    return 0;
}
