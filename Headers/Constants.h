#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

// Positions

// int menu position x
const int c_mPX = 480;
// float menu position x
const float cf_mPX = 480.0f;
// int menu position y
const int c_mPY = 0;
// float menu position y
const float cf_mPY = 0.0f;
// int text box position x
const int c_tBPX = 0;
// float text box position x
const float cf_tBPX = 0.0f;
// int text box position y
const int c_tBPY = 416;
// float text box position y
const float cf_tBPY = 416.0f;
// int view position x
const int c_vPX = 0;
// float view position x
const float cf_vPX = 0.0f;
// int view position y
const int c_vPY = 0;
// float view position y
const float cf_vPY = 0.0f;

// Sizes

// int health bar size x
const int c_hBSX = 176;
// float health bar size x
const float cf_hBSX = 176.0f;
// int health bar size y
const int c_hBSY = 16;
// float health bar size y
const float cf_hBSY = 16.0f;
// int menu size x
const int c_mSX = 480;
// float menu size x
const float cf_mSX = 480.0f;
// int menu size y
const int c_mSY = 540;
// float menu size y
const float cf_mSY = 540.0f;
// int sprite size
const int c_sS = 240;
// float sprite size
const float cf_sS = 240.0f;
// int tile size
const int c_tS = 32;
// float tile size
const float cf_tS = 32.0f;
// int text box size x
const int c_tBSX = 480;
// float text box size x
const float cf_tBSX = 480.0f;
// int text box size y
const int c_tBSY = 124;
// float text box size y
const float cf_tBSY = 124.0f;
// int view size x
const int c_vSX = 480;
// float view size x
const float cf_vSX = 480.0f;
// int view size y
const int c_vSY = 416;
// float view size y
const float cf_vSY = 416.0f;
// int window size x
const int c_wSX = 960;
// float window size x
const float cf_wSX = 960.0f;
// int window size y
const int c_wSY = 540;
// float window size y
const float cf_wSY = 540.0f;

// Speed

// int ledge speed
const int c_ledgeSpeed = 2;
// int rotation speed
const int c_rotateSpeed = 8;
// int walking speed
const int c_walkSpeed = 4;

// Numbers

// int maximum number of buttons in the menu
const int c_buttons = 4;
// int maximum number of event triggers
const int c_events = 10;

// Enums

enum Direction {
	DIRECTION_NONE,
	DIRECTION_UP, DIRECTION_DOWN, DIRECTION_LEFT, DIRECTION_RIGHT
};
enum MoveStat { MOVESTAT_PP, MOVESTAT_POWER, MOVESTAT_ACCURACY };
enum PokemonStat {
	POKEMONSTAT_HP, POKEMONSTAT_ATTACK, POKEMONSTAT_DEFENSE,
	POKEMONSTAT_SPECIALATTACK, POKEMONSTAT_SPECIALDEFENSE, POKEMONSTAT_SPEED
};
enum Type {
	TYPE_NONE, TYPE_NORMAL, TYPE_FIGHTING, TYPE_FLYING, TYPE_POISON,
	TYPE_GROUND, TYPE_ROCK, TYPE_BUG, TYPE_GHOST, TYPE_STEEL,
	TYPE_FIRE, TYPE_WATER, TYPE_GRASS, TYPE_ELECTRIC, TYPE_PSYCHIC,
	TYPE_ICE, TYPE_DRAGON, TYPE_DARK, TYPE_FAIRY
};

// Initial values

const int c_pokemonBaseStats[4][6] =
{
	{ 45, 49, 49, 65, 65, 45 },
	{ 39, 52, 43, 60, 50, 65 },
	{ 44, 48, 65, 50, 64, 43 },
	{ 35, 55, 40, 50, 50, 90 }
};
const int c_pokemonMoves[4][4] =
{
	{ 1, 2, 0, 0 },
	{ 3, 2, 0, 0 },
	{ 1, 4, 0, 0 },
	{ 4, 5, 0, 0 }
}; // !! at level 1
const std::string c_pokemonNames[4] =
{
	"Bulbasaur",
	"Charmander",
	"Squirtle",
	"Pikachu"
};
const int c_pokemonTypes[4][2] =
{
	{ 12, 4 },
	{ 10, 0 },
	{ 11, 0 },
	{ 13, 0 }
};

const int c_moveBaseStats[5][3] =
{
	{ 35, 40, 100 },
	{ 40, 0, 100 },
	{ 35, 40, 100 },
	{ 30, 0, 100 },
	{ 30, 40, 100 },
};
const std::string c_moveNames[5] =
{
	"Tackle",
	"Growl",
	"Scratch",
	"Tail Whip",
	"Thunder Shock",
};
const int c_moveTypes[5] =
{
	1, 1, 1, 1, 13
};
#endif