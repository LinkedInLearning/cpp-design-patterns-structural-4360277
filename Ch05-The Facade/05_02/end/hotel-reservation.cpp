#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Mock class for database library
class Database
{
public:
    void storeReservation(const string &reservation)
    {
        cout << "Database: Storing reservation: " << reservation << endl;
    }
};

// Mock class for payment gateway
class PaymentGateway
{
public:
    void processPayment(const string &paymentInfo)
    {
        cout << "Payment Gateway: Processing payment with info: " << paymentInfo << endl;
    }
};

// Mock class for messaging service
class MessagingService
{
public:
    void sendConfirmation(const string &message)
    {
        cout << "Messaging Service: Sending confirmation message: " << message << endl;
    }
};

int main()
{
    Database db;
    PaymentGateway paymentGateway;
    MessagingService messagingService;

    const string reservation = "Room reservation info";
    db.storeReservation(reservation);

    const string paymentInfo = "Payment info";
    paymentGateway.processPayment(paymentInfo);

    messagingService.sendConfirmation("Reservation confirmed.");

    return 0;
}
