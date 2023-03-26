#include <iostream>
using namespace std;


class IEngine
{
public:
    virtual void start() const = 0;
    virtual ~IEngine() = default;
};


class IVehicle
{
public:
    explicit IVehicle(const IEngine &engine) : m_engine(engine) {}    

    void drive() const
    {
        m_engine.start();
        driveVehicle();
    }

    virtual ~IVehicle() = default;

protected:
    virtual void driveVehicle() const = 0;

private:
    const IEngine &m_engine;
};

// Concrete implementation of Gas engine
class GasEngine : public IEngine
{
public:
    void start() const override
    {
        cout << "Starting gas engine." << endl;
    }
};

// Concrete implementation of Electric engine
class ElectricEngine : public IEngine
{
public:
    void start() const override
    {
        cout << "Starting electric engine." << endl;
    }
};

// Concrete implementation of Hybrid engine
class HybridEngine : public IEngine
{
public:
    void start() const override
    {
        cout << "Starting hybrid engine." << endl;
    }
};

// Concrete implementation of Car
class Car : public IVehicle
{
public:
    Car(const IEngine &engine) : IVehicle(engine) {}

    void driveVehicle() const override
    {
        cout << "Driving a car." << endl;
    }
};

// Concrete implementation of Truck
class Truck : public IVehicle
{
public:
    Truck(const IEngine &engine) : IVehicle(engine) {}

    void driveVehicle() const override
    {        
        cout << "Driving a truck." << endl;
    }
};

// Concrete implementation of Bike
class Bike : public IVehicle
{
public:
    Bike(const IEngine &engine) : IVehicle(engine) {}

    void driveVehicle() const override
    {        
        cout << "Riding a bike." << endl;
    }
};

int main()
{
    auto gasEngine = GasEngine();
    auto electricEngine = ElectricEngine();
    auto hybridEngine = HybridEngine();

    // Create an array of pointers to Vehicle objects.
    const std::unique_ptr<IVehicle> vehicles[] {
        make_unique<Car>(gasEngine),
        make_unique<Truck>(electricEngine),
        make_unique<Bike>(hybridEngine)};

    for (const auto &vehicle : vehicles)
    {
        vehicle->drive();
        cout << endl;
    }

    return 0;
}
