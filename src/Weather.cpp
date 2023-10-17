#include "Weather.h"
#include <iostream>

Weather::Weather() : currentWeatherIndex(0)
{
    // Initialize random seed
    std::srand(std::time(nullptr));
}

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

Weather::WeatherType Weather::getCurrentWeather() const
{
    return static_cast<Weather::WeatherType>(currentWeatherIndex);
}

void Weather::updateWeather()
{
    int randomValue = std::rand() % 100; // Generate random number between 0 and 99
    std::cout << "Generated random value for weather: " << randomValue << std::endl;

    if (randomValue < 10)
    {
        std::cout << "Setting weather to RAINY." << std::endl;
        setCurrentWeather(RAINY);
    }
    else
    {
        std::cout << "Setting weather to SUNNY." << std::endl;
        setCurrentWeather(SUNNY);
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
