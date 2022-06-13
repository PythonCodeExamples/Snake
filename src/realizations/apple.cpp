#include <stdio.h>
#include <unistd.h>

#include "apple.hpp"
#include "consts.hpp"
#include "paths.hpp"

void apple_init(struct apple_t *apple)
{
	sf::Texture *tile = new sf::Texture;
	if (!tile->loadFromFile(apple_tile_path, sf::IntRect(0, 0, rect_size, rect_size))) {
		fprintf(stderr, "Failed load file: %s\n", apple_tile_path);
		exit(1);
	}
	sf::Sprite *sprite = new sf::Sprite(*tile);

	apple->x = rand()%field_w;
	apple->y = rand()%field_h;
	apple->sprite = sprite;
} 

void apple_respawn(struct apple_t *apple)
{
	apple->x = rand()%field_w;
	apple->y = rand()%field_h;
}

void apple_draw(sf::RenderWindow *window, struct apple_t *apple)
{
	apple->sprite->setPosition(apple->x * rect_size + field_x_offset, apple->y * rect_size + field_y_offset);
	window->draw(*(apple->sprite));
}
