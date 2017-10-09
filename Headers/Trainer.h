#ifndef TRAINER_H
#define TRAINER_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Constants.h"
//#include "Pokemon.h"

class Trainer
{
	Direction m_direction;
	//int m_index;
	bool m_moving;
	std::string m_name;
	int m_partialRotate;
	int m_partialX;
	int m_partialY;
	//Pokemon m_pokemon[6];
	sf::VertexArray m_sprite;
	//std::string m_tilePath;
	sf::Texture m_tileSet;
	std::string m_type;
	int m_x;
	int m_y;

public:
	Trainer(std::string type = "Trainer",
		std::string name = "X", Direction direction = DIRECTION_DOWN, int x = 11, int y = 31);

	void setDirection(Direction direction) { m_direction = direction; }
	void setMoving(bool moving) { m_moving = moving; }
	void setPartialRotate(int partialRotate) { m_partialRotate = partialRotate; }
	void setPartialX(int partialX) { m_partialX = partialX; }
	void setPartialY(int partialY) { m_partialY = partialY; }
	//void setPokemon(int i, Pokemon pokemon) { m_pokemon[i] = pokemon }
	void setX(int x) { m_x = x; }
	void setY(int y) { m_y = y; }

	Direction getDirection() { return m_direction; }
	std::string getName() { return m_name; }
	bool getMoving() { return m_moving; }
	int getPartialRotate() { return m_partialRotate; }
	int getPartialX() { return m_partialX; }
	int getPartialY() { return m_partialY; }
	//Pokemon& getPokemon(int i) { return m_pokemon[i]; }
	std::string getType() { return m_type; }
	int getX() { return m_x; }
	int getY() { return m_y; }

	/*void draw(sf::RenderTarget& window,
		bool edgeX,	bool edgeY,
		int overworldViewOffsetX, int overworldViewOffsetY,
		int playerPartialX, int playerPartialY);*/
};

#endif