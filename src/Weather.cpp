#include "Weather.h"

Weather::Weather() : currentWeatherIndex(0) {}

bool Weather::loadTextures(const std::vector<std::string> &filenames)
{
    for (const auto &filename : filenames)
    {
        sf::Texture texture;
        if (!texture.loadFromFile(filename))
        {
            return false;
        }
        weatherTextures.push_back(texture);
    }
    weatherSprite.setTexture(weatherTextures[currentWeatherIndex]);
    return true;
}

void Weather::setCurrentWeather(int index)
{
    if (index >= 0 && index < weatherTextures.size())
    {
        currentWeatherIndex = index;
        weatherSprite.setTexture(weatherTextures[currentWeatherIndex]);
    }
}

void Weather::setPosition(float x, float y)
{
    weatherSprite.setPosition(x, y);
}

const sf::Sprite &Weather::getSprite() const
{
    return weatherSprite;
}

void Weather::update()
{
}
