#ifndef CROPS_H
#define CROPS_H

#include <string>
#include <SFML/Graphics.hpp>

class Crop
{
public:
    Crop();
    virtual ~Crop();

    // Virtual functions to allow overriding in derived classes
    virtual void grow(const std::string &currentSeason);
    virtual void water();
    virtual void plant(int x, int y, bool isTileWet);
    virtual void harvest();
    virtual void draw(sf::RenderWindow &window);
    virtual bool isMature() const;
    virtual sf::Vector2f getPosition() const;
    virtual int getRequiredWaterings() const { return -1; }
    virtual int getSellValue() const
    {
        return sellValue;
    }

    virtual std::string getType() const
    {
        return "Generic Crop";
    }

protected:
    bool mature = false;
    sf::Sprite sprite;
    sf::Texture textureGrowing;
    sf::Texture textureMature;
    int sellValue = 0;
};

#endif
