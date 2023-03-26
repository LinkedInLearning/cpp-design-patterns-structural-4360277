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

// Hotel reservation system facade
class ReservationSystemFacade
{
public:
    ReservationSystemFacade() : m_Database(), m_PaymentGateway(), m_MessagingService() {}

    void reserveRoom(const string &reservation, const string &paymentInfo)
    {
        m_Database.storeReservation(reservation);
        m_PaymentGateway.processPayment(paymentInfo);
        m_MessagingService.sendConfirmation("Reservation confirmed.");
    }

private:
    Database m_Database;
    PaymentGateway m_PaymentGateway;
    MessagingService m_MessagingService;
};

int main()
{
    /*
    Database db;
    PaymentGateway paymentGateway;
    MessagingService messagingService;

    const string reservation = "Room reservation info";
    db.storeReservation(reservation);

    const string paymentInfo = "Payment info";
    paymentGateway.processPayment(paymentInfo);

    messagingService.sendConfirmation("Reservation confirmed.");
    */
    ReservationSystemFacade reservationSystem;

    const string reservation = "Room reservation info";
    const string paymentInfo = "Payment info";

    reservationSystem.reserveRoom(reservation, paymentInfo);

    return 0;
}
