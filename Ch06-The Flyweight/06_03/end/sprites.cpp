#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Texture
{
public:
    explicit Texture(const string &fileName) : m_FileName(fileName), m_Id(arc4random_uniform(INT_MAX))
    {
        cout << "Creating texture from " << m_FileName << endl;
    }

    const string description() const
    {
        return "<" + m_FileName + " id" + to_string(m_Id) + ">";
    }
private:
    const string m_FileName;
    const int m_Id;
};

class Sprite
{
public:
    Sprite(const Texture *texture) : m_Texture(texture) 
    {
        cout << "Creating sprite with texture file " << texture->description() << endl;
    }

    void setPositionSize(int x, int y, int width, int height)
    {
        m_X = x;
        m_Y = y;
        m_Width = width;
        m_Height = height;
    }

    void render()
    {
        // draw sprite
        cout << "Rendering sprite with texture: " << m_Texture->description() << endl;
    }
private:
    int m_Width;
    int m_Height;
    int m_X;
    int m_Y;

    const Texture *m_Texture;
};

class SpriteFactory
{
public:
    Sprite* makeSprite(const string &fileName)
    {
        auto it = m_SpritePool.find(fileName);
        if (it != m_SpritePool.end())
        {
            // sprite already exists in pool, return it
            return it->second;
        }
        else
        {
            // create new texture and add it to the pool            
            const auto texture = getTexture(fileName);
            auto [newIt, _] = m_SpritePool.emplace(fileName, new Sprite(texture));
            return newIt->second;
        }
    }

    ~SpriteFactory()
    {
        for (auto &[filename, sprite] : m_SpritePool)
        {
            delete sprite;
        }

        for (auto &[filename, texture] : m_TexturePool)
        {
            delete texture;
        }
    }

private:
    unordered_map<string, Sprite*> m_SpritePool;
    unordered_map<string, Texture*> m_TexturePool;

    const Texture* getTexture(const string &fileName)
    {
        auto it = m_TexturePool.find(fileName);
        if (it != m_TexturePool.end())
        {
            // texture already exists in pool, return it
            return it->second;
        }
        else
        {
            // create new texture and add it to the pool            
            auto [newIt, _] = m_TexturePool.emplace(fileName, new Texture(fileName));
            return newIt->second;
        }
    }
};

int main()
{
    // create a list of sprite objects
    vector<Sprite *> sprites;
    const int numSprites = 10;
    const string textureFile = "spaceship.png";

    SpriteFactory spriteFactory;

    for (int i = 0; i < numSprites; ++i)
    {        
        auto sprite = spriteFactory.makeSprite(textureFile);
        sprite->setPositionSize(10, 10, i*10, i*10);        
        sprites.push_back(sprite);
    }

    // draw all sprites
    for (auto &sprite : sprites)
    {
        sprite->render();
    }

    return 0;
}
