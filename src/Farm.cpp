#include "Farm.h"
#include <cmath>

Farm::Farm()
<<<<<<< HEAD
{
    if (!texture.loadFromFile("src/assets/grass.jpeg") ||
        !soilTexture.loadFromFile("src/assets/soil.png") ||
        !wetSoilTexture.loadFromFile("src/assets/wetSoil.png"))
    {
        exit(-1);
    }
    tileSize = 50;
    initializeTiles(tileSize);
}

void Farm::initializeTiles(int tileSize)
{
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            tiles[i][j].setSize(sf::Vector2f(tileSize, tileSize));
            tiles[i][j].setPosition(i * tileSize, j * tileSize + 52);
            tiles[i][j].setTexture(&texture);
=======
    : m_x_dim(3), m_y_dim(3), m_max_crops(m_x_dim * m_y_dim), m_current_crops(0) {
    farmField = new Crop**[m_x_dim];
    for (int i = 0; i < m_x_dim; i++) {
        farmField[i] = new Crop*[m_y_dim];
        for (int j = 0; j < m_y_dim; j++) {
            farmField[i][j] = nullptr;
>>>>>>> develop
        }
    }
}

<<<<<<< HEAD
void Farm::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < 12; ++i)
    {
        for (int j = 0; j < 12; ++j)
        {
            window.draw(tiles[i][j]);
=======
//parameterised constructor
Farm::Farm(int x_dim, int y_dim)
    : m_x_dim(x_dim), m_y_dim(y_dim), m_max_crops(x_dim * y_dim), m_current_crops(0) {
    farmField = new Crop**[m_x_dim];
    for (int i = 0; i < m_x_dim; i++) {
        farmField[i] = new Crop*[m_y_dim];
        for (int j = 0; j < m_y_dim; j++) {
            farmField[i][j] = nullptr;
>>>>>>> develop
        }
    }
}

const sf::Texture *Farm::getSoilTexture()
{
    return &soilTexture;
}

<<<<<<< HEAD
const sf::Texture *Farm::getWetSoilTexture()
{
    return &wetSoilTexture;
}

void Farm::setTileTexture(int x, int y, const sf::Texture *texture)
{
    tiles[x][y].setTexture(texture);
}

sf::Vector2i Farm::getClickedTile(int x, int y)
{
    int tileX = x / tileSize;
    int tileY = (y - 52) / tileSize;
    return sf::Vector2i(tileX, tileY);
=======
//getter for x_dim
int Farm::getXDim(){
    return m_x_dim;
>>>>>>> develop
}

const sf::Texture *Farm::getTileTexture(int x, int y)
{
    return tiles[x][y].getTexture();
}
<<<<<<< HEAD
=======

//getter for max_crops
int Farm::getMaxCrops() {
    return m_max_crops;
}

//getter for current_crops
int Farm::getCurrentCrops() {
    return m_current_crops;
}

//getter for farmField
Crop*** Farm::getFarmField() {
    return farmField;
}

//add a crop to farmField at the desired location
bool Farm::addCrop(Crop* crop, int x, int y) {
    if (x >= 0 && x < m_x_dim && y >= 0 && y < m_y_dim) {
        if (farmField[x][y] == nullptr) {
            farmField[x][y] = crop;
            crop->setX(x);
            crop->setY(y);
            m_current_crops++;
            return true;
        } else {
            std::cout << "A crop already exists at that location." << std::endl;
        }
    } else {
        std::cout << "Invalid coordinates. Please choose a valid location." << std::endl;
    }
    return false;
}

//harvest a crop in farmField
bool Farm::harvestCrop(Crop* crop, Crop** harvestedCrops) {
    for (int i = 0; i < m_x_dim; i++) {
        for (int j = 0; j < m_y_dim; j++) {
            if (farmField[i][j] == crop) {
                for (int k = 0; k < getMaxCrops(); k++){
                    if (harvestedCrops[k] == nullptr){
                        harvestedCrops[k] = farmField[i][j];
                        farmField[i][j] = nullptr;  // Set the field to nullptr after harvesting
                        m_current_crops--;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


//remove a crop in farmField
bool Farm::removeCrop(Crop* crop) {
    for (int i = 0; i < m_x_dim; i++) {
        for (int j = 0; j < m_y_dim; j++) {
            if (farmField[i][j] == crop) {
                farmField[i][j] = nullptr;
                delete farmField[i][j];
                m_current_crops--;
                return true;
            }
        }
    }
    return false;
}

//print all information for a crop
void Farm::getAllCropsInfo(){
    std::cout << "------------------------" << std::endl;
    std::cout << "Crop data..." << std::endl;
    std::string mature;
    if (m_current_crops > 0) {
        std::cout << "------------" << std::endl;
        for (int i = 0; i < m_x_dim; i++) {
            for (int j = 0; j < m_y_dim; j++) {
                if (farmField[i][j] != nullptr) {
                    std::cout << "Crop at (" << i << "," << j << ")..." << std::endl;
                    std::cout << "Name: " << farmField[i][j]->getName() << std::endl;
                    std::cout << "Season: " << farmField[i][j]->getSeason() << std::endl;
                    std::cout << "Age: " << farmField[i][j]->getAge() << " days" << std::endl;
                    if (farmField[i][j]->isMature() == true){
                        mature = "True";
                    } else {
                        mature = "False";
                    }
                    std::cout << "Mature: " << mature << std::endl;
                    std::cout << "Growing time: " << farmField[i][j]->getGrowingTime() << " days" << std::endl;
                    std::cout << "Decay time: " << farmField[i][j]->getDecayTime() << " days" << std::endl;
                    std::cout << "Sell price: " << farmField[i][j]->getSellPrice() << " coins" << std::endl;
                    std::cout << "Seed price: " << farmField[i][j]->getSeedPrice() << " coins"<< std::endl;
                    std::cout << "------------" << std::endl;
                }
            }
        }
    } else {
        std::cout << "No crop data exists." << std::endl;
        std::cout << "------------------------" << std::endl;
    }
}

//print a map of farmField
void Farm::visualizeFarmField() {
    for (int j = 0; j < m_y_dim; j++) {
        for (int i = 0; i < m_x_dim; i++) {
            if (farmField[i][j] != nullptr) {
                if (farmField[i][j]->getName() == "Parsnip") {
                    if(farmField[i][j]->isMature() == true){
                        std::cout << "P  ";
                    } else {
                        std::cout << "p" << farmField[i][j]->getAge() << " ";
                    }
                } else if (farmField[i][j]->getName() == "Kale") {
                    if(farmField[i][j]->isMature() == true){
                        std::cout << "K  ";
                    } else {
                        std::cout << "k" << farmField[i][j]->getAge() << " ";
                    }
                 } else if (farmField[i][j]->getName() == "Wheat") {
                    if(farmField[i][j]->isMature() == true){
                        std::cout << "W  ";
                    } else {
                        std::cout << "w" << farmField[i][j]->getAge() << " ";
                    }
                } else if (farmField[i][j]->getName() == "Cabbage") {
                    if(farmField[i][j]->isMature() == true){
                        std::cout << "C  ";
                    } else {
                        std::cout << "c" << farmField[i][j]->getAge() << " ";
                    }
                } else if (farmField[i][j]->getName() == "Eggplant") {
                    if(farmField[i][j]->isMature() == true){
                        std::cout << "E  ";
                    } else {
                        std::cout << "e" << farmField[i][j]->getAge() << " ";
                    }
                } else if (farmField[i][j]->getName() == "Yam") {
                    if(farmField[i][j]->isMature() == true){
                        std::cout << "Y  ";
                    } else {
                        std::cout << "y" << farmField[i][j]->getAge() << " ";
                    }
                } else if (farmField[i][j]->getName() == "Rhubarb") {
                    if(farmField[i][j]->isMature() == true){
                        std::cout << "R  ";
                    } else {
                        std::cout << "r" << farmField[i][j]->getAge() << " ";
                    }
                } else if (farmField[i][j]->getName() == "Beetroot") {
                    if(farmField[i][j]->isMature() == true){
                        std::cout << "B  ";
                    } else {
                        std::cout << "b" << farmField[i][j]->getAge() << " ";
                    }
                }
            } else {
                std::cout << ".  ";
            }
        }
        std::cout << std::endl;
    }
}



>>>>>>> develop
