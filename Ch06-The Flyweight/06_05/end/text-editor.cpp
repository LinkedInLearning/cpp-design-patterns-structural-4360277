#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Character
{
public:
    explicit Character(char c) : m_char(c) {}
    char getChar() const { return m_char; }

private:
    const char m_char;
};

class CharacterFactory
{
public:
    Character *getCharacter(const char c)
    {
        auto it = m_Characters.find(c);
        if (it != m_Characters.end())
        {
            return it->second;
        }
        else
        {
            auto [newIt, _] = m_Characters.emplace(c, new Character(c));
            return newIt->second;
        }
    }

    ~CharacterFactory()
    {
        for (auto &[c, character] : m_Characters)
        {
            delete character;
        }
    }

private:
    unordered_map<char, Character *> m_Characters;
};

class Document
{
public:
    explicit Document(CharacterFactory *factory) : m_factory(factory) {}

    void insert(char c)
    {
        m_chars.emplace_back(m_factory->getCharacter(c));
    }

    void print() const
    {
        for (const auto &c : m_chars)
        {
            std::cout << c->getChar();
        }
    }

private:
    std::vector<const Character *> m_chars;
    CharacterFactory *m_factory;
};

int main()
{
    CharacterFactory factory;
    Document doc(&factory);
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
