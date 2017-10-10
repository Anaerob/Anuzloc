#ifndef TRAINER_H
#define TRAINER_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Constants.h"
//#include "Pokemon.h"

class Trainer
{
	//int m_index;
	std::string m_name;
	//Pokemon m_pokemon[6];
	std::string m_type;
	
protected:
	Direction m_direction;
	bool m_moving;
	int m_partialRotate;
	int m_partialX;
	int m_partialY;
	sf::VertexArray m_sprite;
	sf::Texture m_tileSet;
	int m_x;
	int m_y;
	
public:
	Trainer(std::string type = "Trainer",
		std::string name = "X", Direction direction = DIRECTION_DOWN, int x = 11, int y = 31);

	Direction getDirection() { return m_direction; }
	//std::string getName() { return m_name; }
	bool getMoving() { return m_moving; }
	int getPartialX() { return m_partialX; }
	int getPartialY() { return m_partialY; }
	//Pokemon getPokemon(int i) { return m_pokemon[i]; }
	//std::string getType() { return m_type; }
	int getX() { return m_x; }
	int getY() { return m_y; }

	void draw(sf::RenderTarget& window,
		bool edgeX,	bool edgeY,
		int overworldViewOffsetX, int overworldViewOffsetY,
		int playerPartialX, int playerPartialY);
};

#endif