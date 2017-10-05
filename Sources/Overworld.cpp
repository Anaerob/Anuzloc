#include "../Headers/Overworld.h"

Overworld::Overworld(Player& player)//Player& player, Battle& battle, TextBox& textBox)
	: //m_battle{ battle },
	//m_event{ player, battle, m_stringMap, m_textBox },
	//m_inEvent{ false },
	//m_menu{ player },
	m_view{ player },
	m_player{ player },
	//m_textBox{ textBox },
	m_whiteMenu{ cf_mPX, cf_mPY, cf_mSX, cf_mSY },
	m_whiteTextBox{ cf_tBPX, cf_tBPY, cf_tBSX, cf_tBSY }//,
	//m_world{ "route1" }
{
	readWorld();
}

Overworld::~Overworld()
{
	deallocateTileMap();
	//deallocateTriggerMap();
}

/*void Overworld::deallocateTriggerMap()
{
delete[] m_triggerMap;
m_triggerMap = nullptr;
}*/
void Overworld::deallocateTileMap()
{
delete[] m_tileMap;
m_tileMap = nullptr;
}
void Overworld::draw(sf::RenderWindow& window)
{
	m_view.draw(window, m_tileMap, m_sizeX, m_sizeY);

	m_whiteMenu.draw(window);
	m_whiteTextBox.draw(window);
	//m_menu.draw(window);
}
/*void Overworld::draw(sf::RenderWindow& window)
{
	m_view.draw(window, m_tileMap, m_sizeX, m_sizeY);

	for (size_t i = 1; i < m_NPCMap.size() + 1; ++i)
		m_NPCMap.find(i)->second.draw(window, m_view.getEdgeX(), m_view.getEdgeY(),
			m_view.getOffsetX(), m_view.getOffsetY(),
			m_player.getPartialX(), m_player.getPartialY());

	m_whiteMenu.draw(window);
	m_whiteTextBox.draw(window);
	//m_menu.draw(window);
}
bool Overworld::interact()
{
	int ID;

	if (!m_inEvent)
		switch (m_player.getDirection())
		{
		case 0:
			ID = getTrigger(m_player.getX(), m_player.getY() + 1);
			if (ID != 0)
			{
				Trainer& temp = m_NPCMap.find(ID)->second;
				temp.setDirection(1);
				m_inEvent = m_event.initialize(ID, temp);
			}
			break;
		case 1:
			ID = getTrigger(m_player.getX(), m_player.getY() - 1);
			if (ID != 0)
			{
				Trainer& temp = m_NPCMap.find(ID)->second;
				temp.setDirection(0);
				m_inEvent = m_event.initialize(ID, temp);
			}
			break;
		case 2:
			ID = getTrigger(m_player.getX() - 1, m_player.getY());
			if (ID != 0)
			{
				Trainer& temp = m_NPCMap.find(ID)->second;
				temp.setDirection(3);
				m_inEvent = m_event.initialize(ID, temp);
			}
			break;
		case 3:
			ID = getTrigger(m_player.getX() + 1, m_player.getY());
			if (ID != 0)
			{
				Trainer& temp = m_NPCMap.find(ID)->second;
				temp.setDirection(2);
				m_inEvent = m_event.initialize(ID, temp);
			}
			break;
		}
	else
		m_inEvent = m_event.advance();
	return m_inEvent;
}
void Overworld::menuDown()
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
}
void Overworld::readNPCs(std::string NPCsPath)
{
	m_read.open(NPCsPath);

	std::map<int, Trainer> NPCMap;

	std::string type;
	std::string name;
	int direction;
	int x;
	int y;

	int i = 0;
	while (m_read)
	{
		m_read >> type;
		m_read >> name;
		m_read >> direction;
		m_read >> x;
		m_read >> y;
		Trainer temp{ type, name, direction, x, y };
		NPCMap[++i] = temp;
		m_tileMap[x + y * (m_sizeX + 2)] = 0;
	}

	m_read.close();
	m_NPCMap = NPCMap;
}
void Overworld::readStringMap(std::string stringMapPath)
{
	m_read.open(stringMapPath);

	std::string nextString;
	std::map<int, std::string> stringMap;

	int i = 0;
	stringMap[i] = "";
	while (m_read)
	{
		std::getline(m_read, nextString);
		stringMap[++i] = nextString;
	}

	m_read.close();
	m_stringMap = stringMap;
}*/
void Overworld::readTileMap(std::string tileMapPath)
{
	m_read.open(tileMapPath);

	m_read >> m_sizeX;
	m_read >> m_sizeY;

	m_tileMap = new int[(m_sizeX + 2)*(m_sizeY + 2)]();

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
	deallocateTileMap();
	//deallocateTriggerMap();

	std::string worldPath = "Resources/Maps/";
	worldPath.append("route1");
	std::string tileMapPath = worldPath;
	tileMapPath.append(".dat");
	readTileMap(tileMapPath);

	/*std::string triggerMapPath = worldPath;
	triggerMapPath.append("Triggers.dat");
	readTriggerMap(triggerMapPath);

	std::string NPCsPath = worldPath;
	NPCsPath.append("NPCs.dat");
	readNPCs(NPCsPath);

	std::string trainersPath = worldPath;
	trainersPath.append("Trainers.dat");
	readTrainers(trainersPath);

	std::string stringMapPath = worldPath;
	stringMapPath.append("Strings.dat");
	readStringMap(stringMapPath);*/
}
