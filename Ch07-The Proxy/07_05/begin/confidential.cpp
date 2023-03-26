#include <iostream>
#include <string>

using namespace std;

class Storage
{
public:
    virtual const string getContents() = 0;
    virtual ~Storage() = default;
};

class SecureStorage : public Storage
{
public:
    explicit SecureStorage(const string &data) : m_Contents(data) {}

    const string getContents()
    {
        return m_Contents;
    }

private:
    const string m_Contents;
};

int main()
{
    SecureStorage secureStorage("Top Secret Information");

    // Limit access to sensitive data
    cout << "Sensitive Data: " << secureStorage.getContents() << endl;

    return 0;
}