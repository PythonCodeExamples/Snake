#include "StartPanel.hpp"

#include "consts.hpp"

static const char first_btn_label[] = {"PLAY"};
static const char second_btn_label[] = {"QUIT"};

StartPanel::StartPanel(sf::Font *fptr, sf::Texture *texture, sf::Sound *switch_sound)
: active_btn(0)
{
	const int center_x = win_w / 2;
	const int center_y = win_h / 2;
	const int btn_center_x = center_x - (btn_w / 2);

	// Play button
	btns[0].SetPos(btn_center_x, center_y - 50 - btn_h);
	btns[0].SetActive();
	btns[0].SetString(first_btn_label, fptr);
	btns[0].SetTextPos(btn_center_x + 50, btns[0].GetY() + 13);

	// Quit button
	btns[1].SetPos(btn_center_x, center_y - btn_h / 2);
	btns[1].SetString(second_btn_label, fptr);
	btns[1].SetTextPos(btn_center_x + 50, btns[1].GetY() + 13);

	selector.setTexture(*texture);
	selector.setPosition(center_x - btn_w/2 - 50, btns[active_btn].GetY() + 7.5);
	switch_snd = *switch_sound;
}

void StartPanel::Draw(sf::RenderWindow *window)
{
	for (int i = 0; i < btn_count; i++)
		btns[i].Draw(window);
	window->draw(selector);
}

void StartPanel::SetActiveButton(int index)
{
	btns[active_btn].SetPassive();
	active_btn = index;
	btns[active_btn].SetActive();
	selector.setPosition(selector.getPosition().x, btns[active_btn].GetY() + 7.5);
	switch_snd.play(); 
}

void StartPanel::IncActiveButton()
{
	if (active_btn == btn_count-1)
		this->SetActiveButton(0);
	else
		this->SetActiveButton(active_btn + 1);
}

void StartPanel::DecActiveButton()
{
	if (active_btn == 0)
		this->SetActiveButton(btn_count-1);
	else
		this->SetActiveButton(active_btn - 1);
}

