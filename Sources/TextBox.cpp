#include "../Headers/TextBox.h"

TextBox::TextBox()
	: m_color{ sf::Color::Black }, m_edgeThickness{ 5 }
{
	m_font.loadFromFile("Resources/Fonts/arial.ttf");
	for (int i = 0; i < 3; ++i)
	{
		m_text[i].setCharacterSize(30);
		m_text[i].setFillColor(m_color);
		m_text[i].setFont(m_font);
		m_text[i].setPosition(sf::Vector2f(cf_tBPX + (float)m_edgeThickness,
			cf_tBPY + (float)m_edgeThickness + i * (cf_tBSY - 15) / 3));
		m_text[i].setString("");
	}
}

void TextBox::addString(std::string string)
{
	if (m_text[0].getString() == "")
		m_text[0].setString(string);
	else if (m_text[1].getString() == "")
		m_text[1].setString(string);
	else if (m_text[2].getString() == "")
		m_text[2].setString(string);
	else
	{
		m_text[0].setString(m_text[1].getString());
		m_text[1].setString(m_text[2].getString());
		m_text[2].setString(string);
	}
}
void TextBox::clear()
{
	for (int i = 0; i < 3; ++i)
		m_text[i].setString("");
}
void TextBox::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; ++i)
		window.draw(m_text[i]);
}
