#include <stdio.h>
#include <unistd.h>

#include "utils.hpp"
#include "consts.hpp"
#include "paths.hpp"

bool is_collide(const int x1, const int y1, const int x2, const int y2)
{
	return (x1 == x2) && (y1 == y2);
}

void redraw_win(sf::RenderWindow *window, struct snake_t *snake, struct apple_t *apple, sf::Sprite *background, sf::Sprite *frame, sf::Text *score_text)
{
	window->draw(*background);
	apple_draw(window, apple);
	snake_draw(window, snake);
	window->draw(*frame);
	window->draw(*score_text);
	window->display();
}

int get_random_tile_x()
{
	return rand() % tile_total_blocks * tile_block_w;
}

sf::Sprite *get_bg_sprite()
{
	sf::Texture *background_tile = new sf::Texture;
	if (!background_tile->loadFromFile(bg_path, sf::IntRect(0, 0, window_w, window_h))) {
		fprintf(stderr, "Failed load file: %s\n", bg_path);
		exit(1);
	}
	sf::Sprite *background = new sf::Sprite(*background_tile);
	background->setPosition(0, 0);
	return background;
}

sf::Sprite *get_frame_sprite()
{
	sf::Texture *frame_tile = new sf::Texture;
	if (!frame_tile->loadFromFile(frame_path, sf::IntRect(0, 0, 600, 600))) {
		fprintf(stderr, "Failed to load file: %s\n", frame_path);
		exit(1);
	}
	sf::Sprite *frame = new sf::Sprite(*frame_tile);
	frame->setPosition(0, 0);
	return frame;
}

void int_to_string(char score, char *buffer)
{
	for (int i = 2; i > 0; i--) {
		char tmp = score % 10;
		score /= 10;
		buffer[i] = tmp + 48;
	}
}
