#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <stdio.h>
#include <unistd.h> // for exit(1) & usleep();
#include <time.h> // for srand(time(NULL));

// Custom modules
#include "snake.hpp"
#include "apple.hpp"
#include "consts.hpp"
#include "utils.hpp"
#include "paths.hpp"
#include "RunMenu.hpp"

static const char *window_name = {"Snake game"};
static const char *lose_msg = {"GAME OVER"};

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(window_w, window_h), window_name);
	if (0 != RunMenu(window)) {
		window.close();
		return 0;
	}

	int score = 0;

	// ===LABLES=== //
	sf::Font font;
	font.loadFromFile(font_path);

	sf::Text score_text, lose_text;
	char score_buffer[score_buffer_size] = {"000"}; // Buffer to draw on window

	score_text.setFont(font);
	score_text.setString(score_buffer);
	score_text.setCharacterSize(score_text_size);
	score_text.setFillColor(sf::Color::White);
	score_text.setPosition(score_text_x, score_text_y);

	lose_text.setFont(font);
	lose_text.setString(lose_msg);
	lose_text.setCharacterSize(lose_text_size);
	lose_text.setFillColor(sf::Color::White);
	lose_text.setPosition(lose_text_x, lose_text_y);
	/////////////////////////////


	// ===SPRITES=== //
	// Creation and init of snake
	struct snake_t snake;
	snake_init(&snake);

	// Creation and init of apple
	struct apple_t apple;
	apple_init(&apple);

	// Load background and frame sprites
	sf::Sprite *background = get_bg_sprite();
	sf::Sprite *frame = get_frame_sprite();
	////////////////////////////

	// ===SOUDNS== //
	// Set up background music
	sf::Music music;
	if (!music.openFromFile(music_path)) {
		fprintf(stderr, "Failed to load file: %s\n", music_path);
		window.close();
	}
	music.setVolume(music_volume);
	music.setLoop(true);
	music.play();

	// Set up byte sound
	sf::SoundBuffer buff;
	buff.loadFromFile(byte_path);
	sf::Sound byte(buff);
	byte.setVolume(byte_volume);
	byte.setLoop(false);
	////////////////////////////

	sf::Clock clock;
	const double delay = 100000;

	sf::Event e;

	while (window.isOpen()) {
		clock.restart();

		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				window.close();

			if (e.type == sf::Event::KeyPressed)
				switch (e.key.code) {
					case sf::Keyboard::Up:
						snake_set_dir(&snake, 0, -1);
						break;

					case sf::Keyboard::Left:
						snake_set_dir(&snake, -1, 0);
						break;

					case sf::Keyboard::Down:
						snake_set_dir(&snake, 0, 1);
						break;

					case sf::Keyboard::Right:
						snake_set_dir(&snake, 1, 0);
						break;

					default:
						break;
				}
		}

		// Do game
		snake_move(&snake);
		if (((snake.dx != 0) || (snake.dy != 0)) && snake_check_collision(&snake)) {
			window.draw(lose_text);
			window.display();
			sleep(2);
			window.close();
			break;
		}
		if(is_collide(snake.coords[0].x, snake.coords[0].y, apple.x, apple.y )) {
			snake.length++;
			apple_respawn(&apple);
			score += 1;
			int_to_string(score, score_buffer);
			score_text.setString(score_buffer);
			byte.play();
		}
		redraw_win(&window, &snake, &apple, background, frame, &score_text);

		if (delay - clock.getElapsedTime().asMicroseconds() > 0)
			usleep(delay - clock.getElapsedTime().asMicroseconds());
	}

	return 0;
}
