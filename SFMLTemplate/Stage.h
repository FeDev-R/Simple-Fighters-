#pragma once
#include"Game.h"
class Stage
{
private:
    std::vector<mapa> maps;
    int currentMapIndex = 0;

public:
    void addMap(const mapa& map) {
        maps.push_back(map);
    }

    void draw(sf::RenderWindow& window) {
        if (!maps.empty())
                maps[currentMapIndex].draw(window);
            
    }

    void setCurrentMap(int index) {
        if (index >= 0 && index < maps.size())
            currentMapIndex = index;
    }

    mapa& getCurrentMap() {
        return maps[currentMapIndex];
    }

    int getMapCount() const { return maps.size(); }
};


