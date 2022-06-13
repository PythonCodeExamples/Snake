#ifndef _UTILS_HPP_SENTRY_
#define _UTILS_HPP_SENTRY_

#include <SFML/Graphics.hpp>
#include "snake.hpp"
#include "apple.hpp"

bool is_collide(const int x1, const int y1, const int x2, const int y2);

void redraw_win(
	sf::RenderWindow *window,
	struct snake_t *snake,
	struct apple_t *apple,
	sf::Sprite *background,
	sf::Sprite *frame,
	sf::Text *score_text
);

int get_random_tile_x();

sf::Sprite *get_bg_sprite();

sf::Sprite *get_frame_sprite();

void int_to_string(char score, char *buffer);

#endif