#include "Move.h"

Move::Move(int index) : m_index{ index }
{
	if (index != 0)
	{
		m_name = c::sMN[index - 1];
		generateStats();
	}
}

void Move::generateStats()
{
	for (int i = 0; i < 3; ++i)
		m_stats[i] = c::iMBS[m_index - 1][i];
}
