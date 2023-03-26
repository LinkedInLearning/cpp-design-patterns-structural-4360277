#include <iostream>
#include <vector>

using namespace std;

class Character
{
public:
    explicit Character(char c) : m_Char(c) {}
    char getChar() const { return m_Char; }

private:
    const char m_Char;
};

class Document
{
public:
    void insert(char c) 
    { 
        m_Chars.push_back(Character(c)); 
    }

    void print() const
    {
        for (const auto &c : m_Chars)
        {
            std::cout << c.getChar();
        }
    }

private:
    std::vector<Character> m_Chars;
};

int main()
{
    Document doc;
    doc.insert('H');
    doc.insert('e');
    doc.insert('l');
    doc.insert('l');
    doc.insert('o');
    doc.insert(',');
    doc.insert(' ');
    doc.insert('w');
    doc.insert('o');
    doc.insert('r');
    doc.insert('l');
    doc.insert('d');
    doc.insert('!');
    doc.print();
    return 0;
}