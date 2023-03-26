#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Concrete product classes
class Book
{
public:
    Book(const string &title, double price) : m_Title(title), m_Price(price) {}

    double price() const
    {
        cout << "Getting \"" << m_Title << "\" book price" << endl;
        return m_Price;
    }

private:
    std::string m_Title;
    double m_Price;
};

class Toy
{
public:
    Toy(const string &name, double price) : m_Name(name), m_PriceTag(price) {}

    double getPrice() const
    {
        cout << "Getting \"" << m_Name << "\" toy price" << endl;
        return m_PriceTag;
    }

private:
    std::string m_Name;
    double m_PriceTag;
};

// Box class that holds products and other boxes
class Box
{
private:
    string m_Name;
    std::vector<Book*> m_Books;
    std::vector<Toy*> m_Toys;
    std::vector<Box*> m_Boxes;

public:
    explicit Box(const string &name) : m_Name(name) {}

    void addBook(Book &book)
    {
        m_Books.push_back(&book);
    }

    void addToy(Toy &toy)
    {
        m_Toys.push_back(&toy);
    }

    void addBox(Box &box)
    {
        m_Boxes.push_back(&box);
    }

    double totalPrice() const
    {
        cout << "Opening " << m_Name << endl;
        double totalPrice = 0;

        for (const auto &book : m_Books)
        {
            totalPrice += book->price();
        }

        for (const auto &toy : m_Toys)
        {
            totalPrice += toy->getPrice();
        }

        for (const auto &box : m_Boxes)
        {
            totalPrice += box->totalPrice();
        }

        return totalPrice;
    }
};

int main()
{
    // Create some products
    Book book1{"Robinson Crusoe", 4.99};
    Toy toy1{"Star Trooper", 39.99};
    Toy toy2{"Barbie Dreamhouse", 59.99};

    // Create some boxes and add products and other boxes to them
    Box smallBox("Small Box");

    smallBox.addBook(book1);
    smallBox.addToy(toy1);

    Box bigBox("Big Box");

    bigBox.addToy(toy2);
    bigBox.addBox(smallBox);

    // Calculate the total price of the top-level box
    cout << "Calculating total price. " << endl
         << bigBox.totalPrice() << endl;

    return 0;
}