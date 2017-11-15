#ifndef TEXTBOX_H
#define TEXTBOX_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Constants.h"

class TextBox
{
	sf::Color m_color;
	int m_edgeThickness;
	sf::Font m_font;
	sf::VertexArray m_hasQueue;
	std::vector<std::string> m_queue;
	sf::Text m_text[3];

public:
	TextBox();

	void setTextString(int i, std::string s) { m_text[i].setString(s); }

	void addString(std::string string);
	void advance();
	void clear();
	void draw(sf::RenderWindow& window);
	bool queueEmpty() { return m_queue.empty(); }
	void queueString(std::string string);

};
#endif