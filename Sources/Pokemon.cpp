#include "Pokemon.h"

Pokemon::Pokemon(int index, int level)
	: m_dead{ false },
	m_index{ index },
	m_level{ level },
	m_players{ false },
	m_sprite{ sf::Quads, 4 }
{
	if (index != 0)
	{
		m_name = c::sPN[index - 1];
		m_nickname = m_name;
		generateMoves();
		generateStats();
		resetAll();
	}
}

void Pokemon::changeHP(int change)
{
	if (m_HP + change <= 0)
	{
		m_HP = 0;
		m_dead = true;
	}
	else if (m_HP + change >= m_stats[0])
		m_HP = m_stats[0];
	else
		m_HP += change;
}
void Pokemon::draw(sf::RenderTarget& window)
{
	std::string spritePath = "Resources/Sprites/";
	spritePath.append(std::to_string(m_index));

	float f_d = 0.0f;
	float f_x = 0.0f;
	float f_y = 0.0f;


	if (m_players)
	{
		f_x = 0.0f;
		f_y = c::fVSY - c::fSS;
		spritePath.append("b.png");
	}
	else
	{
		f_x = c::fVSX - c::fSS;
		f_y = 0.0f;
		spritePath.append("f.png");
	}
	

	m_tileSet.loadFromFile(spritePath);

	sf::Vertex* quad = &m_sprite[0];

	quad[0].position = sf::Vector2f(f_x,
		f_y);
	quad[1].position = sf::Vector2f(f_x + c::fSS,
		f_y);
	quad[2].position = sf::Vector2f(f_x + c::fSS,
		f_y + c::fSS);
	quad[3].position = sf::Vector2f(f_x,
		f_y + c::fSS);

	quad[0].texCoords = sf::Vector2f(f_d * c::fSS,
		0.0f);
	quad[1].texCoords = sf::Vector2f((f_d + 1) * c::fSS,
		0.0f);
	quad[2].texCoords = sf::Vector2f((f_d + 1) * c::fSS,
		c::fSS);
	quad[3].texCoords = sf::Vector2f(f_d * c::fSS,
		c::fSS);

	window.draw(m_sprite, &m_tileSet);
}
void Pokemon::generateStats()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> dist(0, 31);

	for (int i = 0; i < 6; ++i)
	{
		m_BSs[i] = c::iPBS[m_index - 1][i];
		m_EVs[i] = 0;
		m_IVs[i] = dist(rng);
	}
	
	updateStats();
}
void Pokemon::generateMoves()
{
	for (int i = 0; i < 4; ++i)
		m_moves[i] = Move{ c::iPM[m_index - 1][i] };
}
void Pokemon::levelUp(int level)
{
	m_level += level;
	updateStats();
	resetAll();
}
void Pokemon::makePlayers()
{
	m_players = true;
}
void Pokemon::resetAll()
{
	if (!m_dead)
		m_HP = m_stats[0];
}
void Pokemon::updateStats()
{
	double d_l = (double)m_level;
	double d_BS = (double)m_BSs[0];
	double d_EV = (double)m_EVs[0];
	double d_IV = (double)m_IVs[0];
	double d_stat = 10 + d_l*(1 + (2 * d_BS + d_IV + d_EV / 4) / 100);
	m_stats[0] = (int)d_stat;

	for (int i = 1; i < 6; ++i)
	{
		d_BS = (double)m_BSs[i];
		d_EV = (double)m_EVs[i];
		d_IV = (double)m_IVs[i];
		d_stat = 5 + d_l*(2 * d_BS + d_IV + d_EV / 4) / 100;
		m_stats[i] = (int)d_stat;
	}
}
