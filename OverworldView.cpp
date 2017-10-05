#include "Headers/OverworldView.h"

OverworldView::OverworldView(Player& player)
	: m_player{ player }
{
	m_tiles.setPrimitiveType(sf::Quads);
	m_tiles.resize((c_vSX / c_tS + 2) * (c_vSY / c_tS + 2) * 4);
	m_tileSet.loadFromFile("Resources/Tiles/Overworld.png");
}

void OverworldView::calculateOffsetX(int overworldSizeX)
{
	int half = (c_vSX / c_tS - 1) / 2;
	if (m_player.getX() <= half + 1)
	{
		m_offsetX = 0;
		m_edgeX = m_player.getX() < half + 1 || m_player.getDirection() == 2;
	}
	else if (m_player.getX() >= overworldSizeX - half)
	{
		m_offsetX = overworldSizeX - c_vSX / c_tS;
		m_edgeX = m_player.getX() > overworldSizeX - half || m_player.getDirection() == 3;
	}
	else
	{
		m_offsetX = m_player.getX() - half - 1;
		m_edgeX = false;
	}
}
void OverworldView::calculateOffsetY(int overworldSizeY)
{
	int half = (c_vSY / c_tS - 1) / 2;
	if (m_player.getY() <= half + 1)
	{
		m_offsetY = 0;
		m_edgeY = m_player.getY() < half + 1 || m_player.getDirection() == 1;
	}
	else if (m_player.getY() >= overworldSizeY - half)
	{
		m_offsetY = overworldSizeY - c_vSY / c_tS;
		m_edgeY = m_player.getY() > overworldSizeY - half || m_player.getDirection() == 0;
	}
	else
	{
		m_offsetY = m_player.getY() - half - 1;
		m_edgeY = false;
	}
}
void OverworldView::draw(sf::RenderWindow& window,
	int overworld[], int overworldSizeX, int overworldSizeY)
{
	calculateOffsetX(overworldSizeX);
	calculateOffsetY(overworldSizeY);

	for (int y = 0; y < c_vSY / c_tS + 2; ++y)
		for (int x = 0; x < c_vSX / c_tS + 2; ++x)
		{
			float f_tileNumber;
			
			float f_x = (float)x;
			float f_y = (float)y;
			float f_pX;
			float f_pY;

			if (m_edgeX)
				f_pX = 0.0f;
			else
				f_pX = (float)(m_player.getPartialX() % c_tS);
			if (m_edgeY)
			{
				f_tileNumber = (float)overworld[(x + m_offsetX +
					m_player.getPartialX() / c_tS) + (y + m_offsetY +
						m_player.getPartialY() / (2 * c_tS)) * (overworldSizeX + 2)];
				f_pY = 0.0f;
			}
			else
			{
				f_tileNumber = (float)overworld[(x + m_offsetX +
					m_player.getPartialX() / c_tS) + (y + m_offsetY +
						m_player.getPartialY() / c_tS) * (overworldSizeX + 2)];
				f_pY = (float)(m_player.getPartialY() % c_tS);
			}

			sf::Vertex* quad = &m_tiles[(x + y * (c_vSX / c_tS + 2)) * 4];

			quad[0].position = sf::Vector2f((f_x - 1) * cf_tS - f_pX,
				(f_y - 1) * cf_tS - f_pY);
			quad[1].position = sf::Vector2f(f_x * cf_tS - f_pX,
				(f_y - 1) * cf_tS - f_pY);
			quad[2].position = sf::Vector2f(f_x * cf_tS - f_pX,
				f_y * cf_tS - f_pY);
			quad[3].position = sf::Vector2f((f_x - 1) * cf_tS - f_pX,
				f_y * cf_tS - f_pY);

			quad[0].texCoords = sf::Vector2f(f_tileNumber * cf_tS,
				0.0f);
			quad[1].texCoords = sf::Vector2f((f_tileNumber + 1) * cf_tS,
				0.0f);
			quad[2].texCoords = sf::Vector2f((f_tileNumber + 1) * cf_tS,
				cf_tS);
			quad[3].texCoords = sf::Vector2f(f_tileNumber * cf_tS,
				cf_tS);
		}

	window.draw(m_tiles, &m_tileSet);

	m_player.draw(window, m_edgeX, m_edgeY, m_offsetX, m_offsetY);
}