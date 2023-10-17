#ifndef WEATHER_H
#define WEATHER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class Weather
{
public:
    enum WeatherType
    {
        SUNNY,
        RAINY
    };

private:
    std::vector<sf::Texture> weatherTextures;
    sf::Sprite weatherSprite;
    int currentWeatherIndex;

public:
    Weather();

    // Load all the weather textures from files
    bool loadTextures(const std::vector<std::string> &filenames);

    void setCurrentWeather(int index);

    // Add a method to get the current weather type
    WeatherType getCurrentWeather() const;

    void updateWeather(); // New method to update the weather

    void setPosition(float x, float y);

    const sf::Sprite &getSprite() const;

    void update();
};

#endif
