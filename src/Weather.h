#ifndef WEATHER_H
#define WEATHER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Weather
{
private:
    std::vector<sf::Texture> weatherTextures;
    sf::Sprite weatherSprite;
    int currentWeatherIndex;

public:
    Weather();

    // Load all the weather textures from files
    bool loadTextures(const std::vector<std::string> &filenames);

    void setCurrentWeather(int index);

    void setPosition(float x, float y);

    const sf::Sprite &getSprite() const;

    void update();
};

#endif
