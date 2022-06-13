#include <SFML/Graphics.hpp>

#include <stdio.h>
#include <unistd.h>

#include "snake.hpp"
#include "consts.hpp"
#include "utils.hpp"
#include "paths.hpp"

void snake_init(struct snake_t *snake)
{
	sf::Texture *tile = new sf::Texture;
	if (!tile->loadFromFile(tile_path, sf::IntRect(get_random_tile_x(), 0, tile_block_w, tile_block_h))) {
		fprintf(stderr, "Failed load file: %s\n", tile_path);
		exit(1);
	}

	sf::Sprite *sprite = new sf::Sprite(*tile);

	snake->sprite = sprite;
	snake->length = snake_start_length;
	snake->dx = 0; snake->dy = 0;

	for (int i = 0; i < snake_start_length; i++) {
		snake->coords[i].x = field_w / 2;
		snake->coords[i].y = field_h / 2;
	}
}

void snake_move(struct snake_t *snake)
{
	for (int i = snake->length; i > 0; i--) {
		snake->coords[i].x = snake->coords[i-1].x;
		snake->coords[i].y = snake->coords[i-1].y;
	}

	snake->coords[0].x += snake->dx;
	if (snake->coords[0].x < 0)
		snake->coords[0].x = field_w - 1;
	else if (snake->coords[0].x >= field_w)
		snake->coords[0].x = 0;

	snake->coords[0].y += snake->dy;
	if (snake->coords[0].y < 0)
		snake->coords[0].y = field_h - 1;
	else if (snake->coords[0].y >= field_h)
		snake->coords[0].y = 0;
}

void snake_set_dir(struct snake_t *snake, const int dx, const int dy)
{
	if (snake->dx || snake->dy)
		if ((snake->dx == -dx) || (snake->dy == -dy))
			return;

	snake->dx = dx;
	snake->dy = dy;
}

void snake_draw(sf::RenderWindow *window, struct snake_t *snake)
{
	for (unsigned int i = 0; i < snake->length; i++) {
		snake->sprite->setPosition(snake->coords[i].x * rect_size + field_x_offset, snake->coords[i].y * rect_size + field_y_offset);
		window->draw(*(snake->sprite));
	}
}

bool snake_check_collision(struct snake_t *snake)
{
	int x = snake->coords[0].x;
	int y = snake->coords[0].y;
	for (unsigned int i = 1; i < snake->length; ++i)
		if (is_collide(x, y, snake->coords[i].x, snake->coords[i].y))
			return true;
	return false;
}
