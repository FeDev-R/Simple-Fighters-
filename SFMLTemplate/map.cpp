#include"map.h"

bool loadFromFile(const std::string path) {
	if (!texture.loadFromFile(path))
		return false;
	sprite.setTexture(texture);
	return true;
}