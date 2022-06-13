#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <stdio.h>
#include <unistd.h>

#include "Button.hpp"
#include "StartPanel.hpp"
#include "consts.hpp"


#define ROOT_ASSETS "assets/"
#define ROOT_TILES  "assets/tiles/"
#define ROOT_SOUNDS "assets/music/"

static const char font_path[] = {ROOT_ASSETS "menu_font.ttf"};
static const char bg_path[] = {ROOT_TILES "bg.png"};
static const char selector_path[] = {ROOT_TILES "snakeselector.png"};
static const char switch_sound_path[] = {ROOT_SOUNDS "switch.ogg"};
static const char pick_sound_path[] = {ROOT_SOUNDS "pick.ogg"};

static const char win_name[] = {"Snake Menu"};

int RunMenu(sf::RenderWindow& win)
{
	sf::Font font;
	if (!font.loadFromFile(font_path)) {
		fprintf(stderr, "Error, while opening file. \"%s\"\n", font_path);
		exit(1);
	}

	sf::Texture texture_bg;
	if (!texture_bg.loadFromFile(bg_path)) {
		fprintf(stderr, "Error file open \"%s\"\n", bg_path);
		exit(1);
	}

	sf::Sprite bg(texture_bg);
	bg.setPosition(0,0);

	sf::Texture selector_texture;
	if (!selector_texture.loadFromFile(selector_path)) {
		fprintf(stderr, "Error file open \"%s\"\n", selector_path);
		exit(1);
	}

	sf::SoundBuffer buff_switch;
	buff_switch.loadFromFile(switch_sound_path);
	sf::Sound switch_sound(buff_switch);
	switch_sound.setVolume(20);

	sf::SoundBuffer buff_pick;
	buff_pick.loadFromFile(pick_sound_path);
	sf::Sound pick_sound(buff_pick);
	pick_sound.setVolume(20);

	StartPanel panel(&font, &selector_texture, &switch_sound);

	sf::Clock clock;
	double timer = 0.0;
	const double delay = 200;

	while (win.isOpen()) {
		sf::Event e;
		while (win.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				win.close();

			if (e.type == sf::Event::KeyPressed) {
				switch (e.key.code) {
				case (sf::Keyboard::Up):
					panel.DecActiveButton();
					break;
				case (sf::Keyboard::Down):
					panel.IncActiveButton();
					break;
				case (sf::Keyboard::Return):
					pick_sound.play();
					clock.restart();
					while (timer < delay) {
						static int counter = 0;
						timer += clock.getElapsedTime().asSeconds();
						if (counter <= 20) {
							panel.SetButtonBlink();
							counter++;
						} else if (counter > 0) {
							panel.UnsetButtonBlink();
							counter--;
						}
						panel.Draw(&win);
						win.display();
					}
						
					return panel.GetActiveButton();
				default:
					break;
				}
			}
		}

		win.draw(bg);
		panel.Draw(&win);
		win.display();
	}

	return 0;
}
