#ifndef _SNAKE_HPP_
#define _SNAKE_HPP_

#include <SFML/Graphics.hpp>

#include "consts.hpp"

struct snake_t {
	struct {
		int x, y;
	} coords[snake_max_length];

	int dx, dy;
	unsigned int length;
	sf::Sprite *sprite;
};

void snake_init(struct snake_t *snake);

void snake_move(struct snake_t *snake);

void snake_set_dir(struct snake_t *snake, const int dx, const int dy);

void snake_draw(sf::RenderWindow *window, struct snake_t *snake);

bool snake_check_collision(struct snake_t *snake);

#endif