#include "tilemap.h"
#include <fstream>
#include <sstream>
#include <iostream>

Map::Map() :
    mapData(nullptr),
    tileImageTexture(nullptr),
    texture(nullptr),
    map_width(0),
    map_height(0),
    tileWidth(0),
    tileHeight(0) {
}

Map::~Map() {
    if (mapData) delete[] mapData;
    if (tileImageTexture) delete tileImageTexture;
    if (texture) delete[] texture;
}

bool Map::Load(std::string mapfilename) {
    std::ifstream file(mapfilename);
    if (!file.is_open()) {
        std::cerr << "Failed to open map file: " << mapfilename << std::endl;
        return false;
    }

    // read the map file header
    std::string line;
    std::getline(file, tileSet);  // path to tileset
    std::getline(file, line); tileWidth = std::stoi(line);
    std::getline(file, line); tileHeight = std::stoi(line);
    std::getline(file, line); map_width = std::stoi(line);
    std::getline(file, line); map_height = std::stoi(line);

    // allocate memory for map data
    mapData = new int[map_width * map_height];

    // read the map data
    int row = 0;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string value;
        int col = 0;

        while (std::getline(ss, value, ',')) {
            if (col < map_width) {
                mapData[row * map_width + col++] = std::stoi(value);
            }
        }
        row++;
    }

    // load the tileset texture
    tileImageTexture = new sf::Image();
    if (!tileImageTexture->loadFromFile(tileSet)) {
        std::cerr << "Failed to load tileset: " << tileSet << std::endl;
        return false;
    }

    // create individual tile textures
    int numTilesX = tileImageTexture->getSize().x / tileWidth;
    int numTilesY = tileImageTexture->getSize().y / tileHeight;
    texture = new sf::Texture[numTilesX * numTilesY];

    for (int y = 0; y < numTilesY; y++) {
        for (int x = 0; x < numTilesX; x++) {
            texture[y * numTilesX + x].loadFromImage(
                *tileImageTexture,
                sf::IntRect(x * tileWidth, y * tileHeight, tileWidth, tileHeight)
            );
        }
    }

    return true;
}

void Map::Render(sf::RenderWindow* window) {
    for (int y = 0; y < map_height; y++) {
        for (int x = 0; x < map_width; x++) {
            int tileID = mapData[y * map_width + x];
            if (tileID >= 0) {
                sf::Sprite sprite(texture[tileID]);
                sprite.setPosition(x * tileWidth, y * tileHeight);
                window->draw(sprite);
            }
        }
    }
}

int Map::GetBinning(int x, int y, int winw, int winh) {
    if (x < 0 || y < 0 || x >= winw || y >= winh) return -1;
    return mapData[(y / tileHeight) * map_width + (x / tileWidth)];
}