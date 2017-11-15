#include "TextBox.h"

TextBox::TextBox()
	: m_color{ sf::Color::Black },
	m_edgeThickness{ 5 },
	m_hasQueue{ sf::Triangles, 3 }
{
	m_font.loadFromFile("Resources/Fonts/arial.ttf");

	m_queue.clear();
	
	m_hasQueue[0].position = sf::Vector2f(c::fTBPX + c::fTBSX - 15.0f,
		c::fTBPY + c::fTBSY - 13.0f);
	m_hasQueue[1].position = sf::Vector2f(c::fTBPX + c::fTBSX - 5.0f,
		c::fTBPY + c::fTBSY - 13.0f);
	m_hasQueue[2].position = sf::Vector2f(c::fTBPX + c::fTBSX - 10.0f,
		c::fTBPY + c::fTBSY - 5.0f);

	for (int i = 0; i < 3; ++i)
		m_hasQueue[i].color = sf::Color::Black;

	for (int i = 0; i < 3; ++i)
	{
		m_text[i].setCharacterSize(30);
		m_text[i].setFillColor(m_color);
		m_text[i].setFont(m_font);
		m_text[i].setPosition(sf::Vector2f(c::fTBPX + (float)m_edgeThickness,
			c::fTBPY + (float)m_edgeThickness + i * (c::fTBSY - 15) / 3));
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
void TextBox::advance()
{
	if (!m_queue.empty())
	{
		if (m_text[0].getString() == "")
			m_text[0].setString(m_queue.front());
		else if (m_text[1].getString() == "")
			m_text[1].setString(m_queue.front());
		else if (m_text[2].getString() == "")
			m_text[2].setString(m_queue.front());
		else
		{
			m_text[0].setString(m_text[1].getString());
			m_text[1].setString(m_text[2].getString());
			m_text[2].setString(m_queue.front());
		}
		if (m_queue.size() > 1)
		{
			for (size_t i = 0; i < m_queue.size() - 1; ++i)
			{
				m_queue[i] = m_queue[i + 1];
			}
		}
		m_queue.pop_back();
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

	if (!queueEmpty())
		window.draw(m_hasQueue);
}
void TextBox::queueString(std::string string)
{
	m_queue.push_back(string);
}