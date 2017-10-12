#ifndef TEXTBOX_H
#define TEXTBOX_H
#include <SFML/Graphics.hpp>
#include "Constants.h"

class TextBox
{
	sf::Color m_color;
	int m_edgeThickness;
	sf::Font m_font;
	sf::Text m_text[3];

public:
	TextBox();

	void setTextString(int i, std::string s) { m_text[i].setString(s); }

	void addString(std::string string);
	void clear();
	void draw(sf::RenderWindow& window);

};
#endif