#include "Move.h"

Move::Move(int index) : m_index{ index }
{
	if (index != 0)
	{
		m_name = c_moveNames[index - 1];
		generateStats();
	}
}

void Move::generateStats()
{
	for (int i = 0; i < 3; ++i)
		m_stats[i] = c_moveBaseStats[m_index - 1][i];
}
