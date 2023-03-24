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

// Class Adapter
class LegacyClassAdapter : public Component, private LegacyComponent
{
public:
  void run() override
  {
    // Delegate the request to the Adaptee
    cout << "LegacyClassAdapter::run() -> Calling LegacyComponent::go()" << endl;
    go();
  }
};

int main()
{    
    const unique_ptr<Component> components[]
    {
        make_unique<ConcreteComponentA>(),
        make_unique<ConcreteComponentB>(),
        make_unique<LegacyClassAdapter>() 
    };
    
    for (const auto& component : components)
    {
        component->run();
    }
    return 0;
}
