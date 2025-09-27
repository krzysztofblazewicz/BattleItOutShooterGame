#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Map {
public:
    Map();
    ~Map();
    void Load(std::string mapfilename);
    void Render(sf::RenderWindow* window);
    int GetBinning(int x, int y, int winw, int winh);

    std::string tileSet;
    int map_width, map_height;
    int tileWidth, tileHeight;
    int* mapData;
    sf::Image* tileImageTexture;
    sf::Texture* texture;

private:
    void ParseMapLine(const std::string& line, int row);
};