#include "Overworld.h"

Overworld::Overworld(Event& event, Player& player, TextBox& textBox)
	: //m_battle{ battle },
	m_event{ event },
	//m_inEvent{ false },
	//m_menu{ player },
	m_view{ player },
	m_player{ player },
	m_textBox{ textBox },
	m_whiteMenu{ cf_mPX, cf_mPY, cf_mSX, cf_mSY },
	m_whiteTextBox{ cf_tBPX, cf_tBPY, cf_tBSX, cf_tBSY },
	m_world{ "route1" }
{
	readWorld();
	m_event.setStrings(m_strings);
}

void Overworld::draw(sf::RenderWindow& window)
{
	m_view.draw(window, m_tileMap, m_sizeX, m_sizeY);

	for (size_t i = 1; i < m_NPCs.size() + 1; ++i)
		m_NPCs.find(i)->second.draw(window, m_view.getEdgeX(), m_view.getEdgeY(),
			m_view.getOffsetX(), m_view.getOffsetY(),
			m_player.getPartialX(), m_player.getPartialY());

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
			m_event.initialize(ID);
		}
		break;
	case DIRECTION_DOWN:
		ID = getTrigger(m_player.getX(), m_player.getY() + 1);
		if (ID != 0)
		{
			m_NPCs.find(ID)->second.setDirection(DIRECTION_UP);
			m_event.initialize(ID);
		}
		break;
	case DIRECTION_LEFT:
		ID = getTrigger(m_player.getX() - 1, m_player.getY());
		if (ID != 0)
		{
			m_NPCs.find(ID)->second.setDirection(DIRECTION_RIGHT);
			m_event.initialize(ID);
		}
		break;
	case DIRECTION_RIGHT:
		ID = getTrigger(m_player.getX() + 1, m_player.getY());
		if (ID != 0)
		{
			m_NPCs.find(ID)->second.setDirection(DIRECTION_LEFT);
			m_event.initialize(ID);
		}
		break;
	default:
		break;
	}
}
/*void Overworld::menuDown()
{
	m_menu.navigateDown();
}
void Overworld::menuReturn()
{
	m_menu.press();
}
void Overworld::menuUp()
{
	m_menu.navigateUp();
}*/
void Overworld::readNPCs(std::string NPCsPath)
{
	m_read.open(NPCsPath);

	std::map<int, Trainer> NPCs;

	std::string type;
	std::string name;
	int direction;
	int x;
	int y;
	//int nPokemon;
	//int index;
	//int level;

	int i = 0;
	while (m_read.good())
	{
		m_read >> type;
		m_read >> name;
		m_read >> direction;
		m_read >> x;
		m_read >> y;
		Direction tempDir = static_cast<Direction>(direction);
		Trainer temp{ type, name, tempDir, x, y };
		NPCs[++i] = temp;
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

	for (int y = 1; y < m_sizeY + 1; ++y)
		for (int x = 1; x < m_sizeX + 1; ++x)
			m_read >> m_tileMap[x + y * (m_sizeX + 2)];

	m_read.close();
}
/*void Overworld::readTrainers(std::string trainersPath)
{
	m_read.open(trainersPath);

	int nPokemon;
	int index;
	int level;

	int i = 0;
	while (m_read)
	{
		do
		{
			m_read >> nPokemon;
			i++;
		} while (nPokemon == 0);
		for (int j = 0; j < nPokemon; ++j)
		{
			m_read >> index;
			m_read >> level;
			Pokemon temp{ index, level };
			m_NPCMap.find(i)->second.setPokemon(j, temp);
		}
	}

	m_read.close();
}
void Overworld::readTriggerMap(std::string triggerMapPath)
{
	m_read.open(triggerMapPath);

	m_triggerMap = new int[(m_sizeX + 2)*(m_sizeY + 2)]();

	int x;
	int y;

	int i = 0;
	while (m_read)
	{
		m_read >> x;
		m_read >> y;
		m_triggerMap[x + y * (m_sizeX + 2)] = ++i;
	}

	m_read.close();
}*/
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

	/*std::string triggerMapPath = worldPath;
	triggerMapPath.append("Triggers.dat");
	readTriggerMap(triggerMapPath);

	std::string trainersPath = worldPath;
	trainersPath.append("Trainers.dat");
	readTrainers(trainersPath);*/
}
