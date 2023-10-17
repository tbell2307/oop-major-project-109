#ifndef PARSNIP_H
#define PARSNIP_H

#include <SFML/Graphics.hpp>
#include "SeasonalCrop.h"

class Parsnip : public SeasonalCrop
{
public:
    Parsnip();
    ~Parsnip();
    void grow() override;
    void water() override;
    void plant(int x, int y, bool isTileWet) override;
    sf::Vector2f getPosition() const;
    void harvest() override;
    void draw(sf::RenderWindow &window);
    bool isMature() const { return mature; }
    static sf::Texture textureGrowing;
    static sf::Texture textureMature;
    std::string getType() const override
    {
        return "Parsnip";
    }

private:
    int daysSincePlanted;
    int timesWatered;
    bool mature;
    sf::Sprite sprite;
};

#endif
