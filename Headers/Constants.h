#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

namespace c
{
	// Positions

	// int menu position x
	extern const int iMPX;
	// float menu position x
	extern const float fMPX;
	// int menu position y
	extern const int iMPY;
	// float menu position y
	extern const float fMPY;
	// int text box position x
	extern const int iTBPX;
	// float text box position x
	extern const float fTBPX;
	// int text box position y
	extern const int iTBPY;
	// float text box position y
	extern const float fTBPY;
	// int view position x
	extern const int iVPX;
	// float view position x
	extern const float fVPX;
	// int view position y
	extern const int iVPY;
	// float view position y
	extern const float fVPY;

	// Sizes

	// int health bar size x
	extern const int iHBSX;
	// float health bar size x
	extern const float fHBSX;
	// int health bar size y
	extern const int iHBSY;
	// float health bar size y
	extern const float fHBSY;
	// int menu size x
	extern const int iMSX;
	// float menu size x
	extern const float fMSX;
	// int menu size y
	extern const int iMSY;
	// float menu size y
	extern const float fMSY;
	// int sprite size
	extern const int iSS;
	// float sprite size
	extern const float fSS;
	// int tile size
	extern const int iTS;
	// float tile size
	extern const float fTS;
	// int text box size x
	extern const int iTBSX;
	// float text box size x
	extern const float fTBSX;
	// int text box size y
	extern const int iTBSY;
	// float text box size y
	extern const float fTBSY;
	// int view size x
	extern const int iVSX;
	// float view size x
	extern const float fVSX;
	// int view size y
	extern const int iVSY;
	// float view size y
	extern const float fVSY;
	// int window size x
	extern const int iWSX;
	// float window size x
	extern const float fWSX;
	// int window size y
	extern const int iWSY;
	// float window size y
	extern const float fWSY;

	// Speed

	// int ledge speed
	extern const int iLSp;
	// int rotation speed
	extern const int iRSp;
	// int walking speed
	extern const int iWSp;

	// Numbers

	// int maximum number of buttons in the menu
	extern const int iBN;
	// int maximum number of event triggers
	extern const int iEN;
	// int maximum number of portals
	extern const int iPN;

	// Initial values

	// int initial pokemon base stats
	extern const int iPBS[4][6];
	// int initial pokemon moves
	extern const int iPM[4][4];
	// string pokemon names
	extern const std::string sPN[4];
	// int pokemon types
	extern const int iPT[4][2];

	// int move base stats
	extern const int iMBS[5][3];
	// string move names
	extern const std::string sMN[5];
	// int move types
	extern const int iMT[5];
}

// Enums

const enum eAction {
	ACTION_NONE,
	ACTION_MOVE, ACTION_POKEMON
};
const enum eDirection {
	DIRECTION_NONE,
	DIRECTION_UP, DIRECTION_DOWN, DIRECTION_LEFT, DIRECTION_RIGHT,
	DIRECTION_FORWARD, DIRECTION_BACKWARD
};
const enum eMenu {
	MENU_NONE,
	MENU_BATTLE, MENU_FIGHT, MENU_POKEMON
};
const enum eType {
	TYPE_NONE, TYPE_NORMAL, TYPE_FIGHTING, TYPE_FLYING, TYPE_POISON,
	TYPE_GROUND, TYPE_ROCK, TYPE_BUG, TYPE_GHOST, TYPE_STEEL,
	TYPE_FIRE, TYPE_WATER, TYPE_GRASS, TYPE_ELECTRIC, TYPE_PSYCHIC,
	TYPE_ICE, TYPE_DRAGON, TYPE_DARK, TYPE_FAIRY
};

//extern const enum eMoveStat { MOVESTAT_PP, MOVESTAT_POWER, MOVESTAT_ACCURACY };
/*extern const enum ePokemonStat {
POKEMONSTAT_HP, POKEMONSTAT_ATTACK, POKEMONSTAT_DEFENSE,
POKEMONSTAT_SPECIALATTACK, POKEMONSTAT_SPECIALDEFENSE, POKEMONSTAT_SPEED
};*/

#endif