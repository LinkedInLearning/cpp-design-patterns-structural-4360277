#include <iostream>
#include <string>
#include <memory>
#include <ctime>

using namespace std;

class CloudStorage
{
public:
    virtual bool uploadContents(const string &content) = 0;
    virtual int getFreeSpace() = 0;
    virtual ~CloudStorage() = default;
};

class CloudDrive : public CloudStorage
{
public:
    virtual bool uploadContents(const string& content) override
    {
        cout << "Uploading " << content.length() << " bytes to CloudDrive: " << endl;

        return true;
    }

    virtual int getFreeSpace() override
    {
        // Implement the logic for getting the free space on CloudDrive here.
        const int size = arc4random_uniform(20);
        cout << "Available CloudDrive storage: " << size << "GB" << endl;
        return size;
    }
};

class FastShare : public CloudStorage
{
public:
    virtual bool uploadContents(const string& content) override
    {
        cout << "Uploading " << content.length() << " bytes to FastShare: " << endl;
        return true;
    }

    virtual int getFreeSpace() override
    {        
        const int size = arc4random_uniform(10);
        cout << "Available FastShare storage: " << size << "GB" << endl;
        return size;
    }    
};

// 3rd party service
class VirtualDrive
{
public:
    bool uploadData(const string& data, const int uniqueID)
    {
        cout << "Uploading to VirtualDrive: \"" << data << "\" ID: " << uniqueID << endl;
        return true;
    }
    int usedSpace()
    {
        return arc4random_uniform(10);
    }
    static const int totalSpace = 15;
};

class VirtualDriveAdapter : public CloudStorage, private VirtualDrive
{
public:
    virtual bool uploadContents(const string& content) override
    {
        // Generate a unique ID for this content
        int uniqueID = generateUID();
        // Delegate the request to the Adaptee
        cout << "VirtualDriveAdapter::uploadContents() -> Calling VirtualDrive::uploadData()" << endl;
        return uploadData(content, uniqueID);
    }

    virtual int getFreeSpace() override
    {
        // Delegate the request to the Adaptee
        cout << "VirtualDriveAdapter::getFreeSpace() -> Calling VirtualDrive::getAvailableStorage()" << endl;
        const int available = totalSpace - usedSpace();
        cout << "Available VirtualDrive storage: " << available << " GB" << endl;
        return available;
    }

private:
    // generates an ID from seconds passed since Epoch
    int generateUID()
    {
        // seconds since the Epoch
        const time_t result = time(nullptr);        
        return result;
    }
};

int main()
{
    // Create an array of pointers to CloudStorage objects.
    const std::unique_ptr<CloudStorage> cloudServices[]
    {
        make_unique<CloudDrive>(),
        make_unique<FastShare>(),
        make_unique<VirtualDriveAdapter>()
    };

    // Iterate through the array and invoke the uploadContents and getFreeSpace
    // methods on each object.
    const string content = "Beam me up, Scotty!";
    for (const auto& service : cloudServices)
    {        
        service->uploadContents(content);
        service->getFreeSpace();
        cout << endl;
    }

    return 0;
}
