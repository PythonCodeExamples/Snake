#ifndef _APPLE_HPP_
#define _APPLE_HPP_

#include <SFML/Graphics.hpp>

struct apple_t {
	int x, y;
	sf::Sprite *sprite;
};

void apple_init(struct apple_t *apple);

void apple_respawn(struct apple_t *apple);

void apple_draw(sf::RenderWindow *window, struct apple_t *apple);

#endif