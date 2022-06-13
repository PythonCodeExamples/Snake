#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include <SFML/Graphics.hpp>

class Button {
private:
	int x, y;
	int w, h;
	sf::RectangleShape rect;
	sf::Text text;
	bool active;

public:
	Button(int x = 0, int y = 0);

	void SetPos(const int ux, const int uy);
	void SetString(const char *str, sf::Font *fptr);
	void Draw(sf::RenderWindow *window);

	inline void SetTextPos(const int x, const int y) { text.setPosition(x, y); }
	inline int GetX() { return x; }
	inline int GetY() { return y; }

	inline void SetActive()
	{
		active = true;
		rect.setOutlineColor(sf::Color::Yellow);
	}

	inline void SetPassive()
	{
		active = false;
		rect.setOutlineColor(sf::Color::Black);
	}
};

#endif