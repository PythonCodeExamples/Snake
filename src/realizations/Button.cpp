#include "Button.hpp"
#include "consts.hpp"

#define BTN_COLOR 59,59,59

Button::Button(int x, int y):
	x(x), y(y),
	w(btn_w), h(btn_h),
	active(false)
{
	rect.setSize(sf::Vector2f(w, h));
	rect.setFillColor(sf::Color(BTN_COLOR));
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(3);
	text.setCharacterSize(20);
	text.setFillColor(sf::Color::White);
}

void Button::SetPos(const int ux, const int uy)
{
	x = ux;
	y = uy;
	rect.setPosition(x, y);
}

void Button::SetString(const char *str, sf::Font *fptr)
{
	text.setString(str);
	text.setFont(*fptr);
}

void Button::Draw(sf::RenderWindow *window)
{
	window->draw(rect);
	window->draw(text);
}
