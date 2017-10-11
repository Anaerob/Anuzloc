#include "Pokemon.h"

Pokemon::Pokemon(int index, int level)
	: m_index{ index }, m_level{ level }, m_sprite{ sf::Quads, 4 }
{
	if (index != 0)
	{
		m_name = c_pokemonNames[index - 1];
		m_nickname = m_name;
		generateMoves();
		generateStats();
		resetAll();
	}
}

void Pokemon::changeHP(int change)
{
	if (m_HP + change <= 0)
		m_HP = 0;
	else if (m_HP + change >= m_stats[0])
		m_HP = m_stats[0];
	else
		m_HP += change;
}
void Pokemon::draw(sf::RenderTarget& window, int direction)
{
	std::string spritePath = "sprites/";
	spritePath.append(std::to_string(m_index));

	float f_d = 0.0f;
	float f_x = 0.0f;
	float f_y = 0.0f;
	if (direction == 0)
	{
		f_x = cf_vSX - cf_sS;
		f_y = 0.0f;
		spritePath.append("f.png");
	}
	if (direction == 1)
	{
		f_x = 0.0f;
		f_y = cf_vSY - cf_sS;
		spritePath.append("b.png");
	}

	m_tileSet.loadFromFile(spritePath);

	sf::Vertex* quad = &m_sprite[0];

	quad[0].position = sf::Vector2f(f_x,
		f_y);
	quad[1].position = sf::Vector2f(f_x + cf_sS,
		f_y);
	quad[2].position = sf::Vector2f(f_x + cf_sS,
		f_y + cf_sS);
	quad[3].position = sf::Vector2f(f_x,
		f_y + cf_sS);

	quad[0].texCoords = sf::Vector2f(f_d * cf_sS,
		0.0f);
	quad[1].texCoords = sf::Vector2f((f_d + 1) * cf_sS,
		0.0f);
	quad[2].texCoords = sf::Vector2f((f_d + 1) * cf_sS,
		cf_sS);
	quad[3].texCoords = sf::Vector2f(f_d * cf_sS,
		cf_sS);

	window.draw(m_sprite, &m_tileSet);
}
void Pokemon::generateStats()
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> dist(0, 31);

	for (int i = 0; i < 6; ++i)
	{
		m_BSs[i] = c_pokemonBaseStats[m_index - 1][i];
		m_EVs[i] = 0;
		m_IVs[i] = dist(rng);
	}
	
	updateStats();
}
void Pokemon::generateMoves()
{
	for (int i = 0; i < 4; ++i)
		m_moves[i] = Move{ c_pokemonMoves[m_index - 1][i] };
}
void Pokemon::levelUp(int level)
{
	m_level += level;
	updateStats();
	resetAll();
}
void Pokemon::resetAll()
{
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