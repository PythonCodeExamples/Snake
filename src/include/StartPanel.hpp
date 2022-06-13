#ifndef _START_PANEL_HPP_
#define _START_PANEL_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Button.hpp"

enum { btn_count = 2 };

class StartPanel {
private:
	Button btns[btn_count];
	int active_btn;

	sf::Text text;
	sf::Sprite selector;
	sf::Sound switch_snd;

public:
	StartPanel(sf::Font *fptr, sf::Texture *texture, sf::Sound *switch_sound);
	
	void Draw(sf::RenderWindow *window);
	void SetActiveButton(int index);
	void IncActiveButton();
	void DecActiveButton();

	inline int GetActiveButton() { return active_btn; }
	inline void SetButtonBlink() { btns[active_btn].SetActive(); }
	inline void UnsetButtonBlink() { btns[active_btn].SetPassive(); }
};

#endif
