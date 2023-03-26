#include <iostream>
#include <vector>

using namespace std;

class Texture
{
public:
    explicit Texture(const string &fileName) : m_FileName(fileName), m_Id(arc4random_uniform(INT_MAX)) {}

    const string description() const
    {
        return "<" + m_FileName + " id" + to_string(m_Id) + ">";
    }
    ~Texture()
    {
        cout << "Destructing " << description() << endl;
    }
    // other texture manipulation methods
private:
    const string m_FileName;
    const int m_Id;
};

class Sprite
{
public:
    Sprite(int width, int height, int x, int y, const string &textureFileName) : m_Width(width), m_Height(height), m_X(x), m_Y(y), m_Texture(new Texture(textureFileName)) {}

    void render()
    {
        // draw sprite
        cout << "Rendering sprite with texture: " << m_Texture->description() << endl;
    }

    ~Sprite()
    {
        cout << "Destructing sprite with texture " << m_Texture->description() << endl;
        delete m_Texture;
    }

private:
    const int m_Width;
    const int m_Height;
    const int m_X;
    const int m_Y;

    const Texture *m_Texture;
};

int main()
{
    // create a list of sprite objects
    vector<Sprite*> sprites;
    const int numSprites = 10;
    const string textureFile = "spaceship.png";

    for (int i = 0; i < numSprites; ++i)
    {
        auto sprite = new Sprite(10, 10, i * 10, i * 10, textureFile);
        sprites.push_back(sprite);
    }

    // draw all sprites
    for (auto &sprite : sprites)
    {
        sprite->render();
    }

    // cleanup
    for (auto &sprite : sprites)
    {
        delete(sprite);
    }

    return 0;
}
