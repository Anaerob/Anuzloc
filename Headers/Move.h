#ifndef MOVE_H
#define MOVE_H
#include <string>
#include "Constants.h"

class Move
{
	int m_index;
	std::string m_name;
	int m_stats[3];

public:
	Move(int index = 0);

	int getIndex() { return m_index; }
	std::string getName() { return m_name; }
	int getStat(int i) { return m_stats[i]; }

	void generateStats();

};
#endif