#include "Overworld.h"

Overworld::Overworld(Battle& battle, Event& event, Player& player, TextBox& textBox)
	: m_battle{ battle },
	m_event{ event },
	m_player{ player },
	m_textBox{ textBox },
	m_tiles{ sf::Quads, (c::iVSX / c::iTS + 2) * (c::iVSY / c::iTS + 2) * 4 },
	m_whiteMenu{ c::fMPX, c::fMPY, c::fMSX, c::fMSY },
	m_whiteTextBox{ c::fTBPX, c::fTBPY, c::fTBSX, c::fTBSY },
	m_world{ "route1" }
{
	m_tileSet.loadFromFile("Resources/Tiles/Overworld.png");

	readWorld();
	m_event.setStrings(m_strings);
}

void Overworld::calculateOffsetX()
{
	int half = (c::iVSX / c::iTS - 1) / 2;
	if (m_player.getX() <= half + 1)
	{
		m_offsetX = 0;
		m_edgeX = m_player.getX() < half + 1
			|| m_player.getDirection() == DIRECTION_LEFT;
	}
	else if (m_player.getX() >= m_sizeX - half)
	{
		m_offsetX = m_sizeX - c::iVSX / c::iTS;
		m_edgeX = m_player.getX() > m_sizeX - half
			|| m_player.getDirection() == DIRECTION_RIGHT;
	}
	else
	{
		m_offsetX = m_player.getX() - half - 1;
		m_edgeX = false;
	}
}
void Overworld::calculateOffsetY()
{
	int half = (c::iVSY / c::iTS - 1) / 2;
	if (m_player.getY() <= half + 1)
	{
		m_offsetY = 0;
		m_edgeY = m_player.getY() < half + 1
			|| m_player.getDirection() == DIRECTION_UP;
	}
	else if (m_player.getY() >= m_sizeY - half)
	{
		m_offsetY = m_sizeY - c::iVSY / c::iTS;
		m_edgeY = m_player.getY() > m_sizeY - half
			|| m_player.getDirection() == DIRECTION_DOWN;
	}
	else
	{
		m_offsetY = m_player.getY() - half - 1;
		m_edgeY = false;
	}
}
void Overworld::draw(sf::RenderWindow& window)
{
	calculateOffsetX();
	calculateOffsetY();

	for (int y = 0; y < c::iVSY / c::iTS + 2; ++y)
		for (int x = 0; x < c::iVSX / c::iTS + 2; ++x)
		{
			float f_tileNumber;

			float f_x = (float)x;
			float f_y = (float)y;
			float f_pX;
			float f_pY;

			if (m_edgeX)
				f_pX = 0.0f;
			else
				f_pX = (float)(m_player.getPartialX() % c::iTS);
			if (m_edgeY)
			{
				f_tileNumber = (float)getTile(
					x + m_offsetX + m_player.getPartialX() / c::iTS,
					y + m_offsetY + m_player.getPartialY() / (2 * c::iTS));
				f_pY = 0.0f;
			}
			else
			{
				f_tileNumber = (float)getTile(
					x + m_offsetX + m_player.getPartialX() / c::iTS,
					y + m_offsetY + m_player.getPartialY() / c::iTS);
				f_pY = (float)(m_player.getPartialY() % c::iTS);
			}

			sf::Vertex* quad = &m_tiles[(x + y * (c::iVSX / c::iTS + 2)) * 4];

			quad[0].position = sf::Vector2f((f_x - 1) * c::fTS - f_pX,
				(f_y - 1) * c::fTS - f_pY);
			quad[1].position = sf::Vector2f(f_x * c::fTS - f_pX,
				(f_y - 1) * c::fTS - f_pY);
			quad[2].position = sf::Vector2f(f_x * c::fTS - f_pX,
				f_y * c::fTS - f_pY);
			quad[3].position = sf::Vector2f((f_x - 1) * c::fTS - f_pX,
				f_y * c::fTS - f_pY);

			quad[0].texCoords = sf::Vector2f(f_tileNumber * c::fTS,
				0.0f);
			quad[1].texCoords = sf::Vector2f((f_tileNumber + 1) * c::fTS,
				0.0f);
			quad[2].texCoords = sf::Vector2f((f_tileNumber + 1) * c::fTS,
				c::fTS);
			quad[3].texCoords = sf::Vector2f(f_tileNumber * c::fTS,
				c::fTS);
		}

	window.draw(m_tiles, &m_tileSet);

	for (size_t i = 1; i < m_NPCs.size() + 1; ++i)
		m_NPCs.find(i)->second.draw(window,
			m_edgeX, m_edgeY, m_offsetX, m_offsetY,
			m_player.getPartialX(), m_player.getPartialY());

	m_player.draw(window, m_edgeX, m_edgeY, m_offsetX, m_offsetY);

	m_whiteMenu.draw(window);
	m_whiteTextBox.draw(window);
}
void Overworld::interact()
{
	int ID;
	switch (m_player.getDirection())
	{
	case DIRECTION_UP:
		ID = getTrigger(m_player.getX(), m_player.getY() - 1);
		if (ID != 0)
		{
			m_NPCs.find(ID)->second.setDirection(DIRECTION_DOWN);
			m_event.initialize(ID, m_NPCs.find(ID)->second);
		}
		break;
	case DIRECTION_DOWN:
		ID = getTrigger(m_player.getX(), m_player.getY() + 1);
		if (ID != 0)
		{
			m_NPCs.find(ID)->second.setDirection(DIRECTION_UP);
			m_event.initialize(ID, m_NPCs.find(ID)->second);
		}
		break;
	case DIRECTION_LEFT:
		ID = getTrigger(m_player.getX() - 1, m_player.getY());
		if (ID != 0)
		{
			m_NPCs.find(ID)->second.setDirection(DIRECTION_RIGHT);
			m_event.initialize(ID, m_NPCs.find(ID)->second);
		}
		break;
	case DIRECTION_RIGHT:
		ID = getTrigger(m_player.getX() + 1, m_player.getY());
		if (ID != 0)
		{
			m_NPCs.find(ID)->second.setDirection(DIRECTION_LEFT);
			m_event.initialize(ID, m_NPCs.find(ID)->second);
		}
		break;
	default:
		break;
	}
}
void Overworld::readNPCs(std::string NPCsPath)
{
	m_read.open(NPCsPath);

	std::map<int, Trainer> NPCs;

	std::string type;
	std::string name;
	int intDirection;
	int x;
	int y;
	int nPokemon;
	int index;
	int level;

	int i = 0;
	while (m_read.good())
	{
		m_read >> type;
		m_read >> name;
		m_read >> intDirection;
		m_read >> x;
		m_read >> y;
		m_read >> nPokemon;
		eDirection direction = static_cast<eDirection>(intDirection);
		Trainer tempTrainer{ type, name, direction, x, y };
		for (int j = 0; j < nPokemon; ++j)
		{
			m_read >> index;
			m_read >> level;
			Pokemon tempPokemon{ index, level };
			tempTrainer.setPokemon(j, tempPokemon);
		}
		NPCs[++i] = tempTrainer;
		m_tileMap[x + y * (m_sizeX + 2)] = i;
	}
	m_read.close();
	m_NPCs = NPCs;
}
void Overworld::readStrings(std::string stringMapPath)
{
	m_read.open(stringMapPath);

	std::string nextLine;
	std::map<int, std::string> stringMap;

	int i = 0;
	stringMap[i] = "";

	while (m_read.good())
	{
		std::getline(m_read, nextLine);
		stringMap[++i] = nextLine;
	}

	m_read.close();
	m_strings = stringMap;
}
void Overworld::readTileMap(std::string tileMapPath)
{
	m_read.open(tileMapPath);

	m_read >> m_sizeX;
	m_read >> m_sizeY;

	m_tileMap.clear();
	m_tileMap.resize((m_sizeX + 2)*(m_sizeY + 2));

	int nextInt;
	for (int y = 1; y < m_sizeY + 1; ++y)
		for (int x = 1; x < m_sizeX + 1; ++x)
		{
			m_read >> nextInt;
			m_tileMap[x + y * (m_sizeX + 2)] = nextInt * c::iEN;
		}
			

	m_read.close();
}
void Overworld::readWorld()
{
	std::string worldPath = "Resources/Maps/";
	worldPath.append(m_world);
	std::string tileMapPath = worldPath;
	tileMapPath.append(".dat");
	readTileMap(tileMapPath);

	std::string NPCsPath = worldPath;
	NPCsPath.append("NPCs.dat");
	readNPCs(NPCsPath);
	
	std::string stringsPath = worldPath;
	stringsPath.append("Strings.dat");
	readStrings(stringsPath);
}
