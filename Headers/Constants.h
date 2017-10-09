#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <string>

/* 540 / 32 = 16.875
make map 15 wide and 13 high still

0 HP, 1 attack, 2 defense,
3 special attack, 4 special defense, 5 speed

0 PP, 1 Power, 2 Accuracy*/

// PX = PositionX, PY = PositionY
// m = menu
const int c_mPX = 480;
const float cf_mPX = 480.0f;
const int c_mPY = 0;
const float cf_mPY = 0.0f;
// tB = textBox
const int c_tBPX = 0;
const float cf_tBPX = 0.0f;
const int c_tBPY = 416;
const float cf_tBPY = 416.0f;
// v = view
const int c_vPX = 0;
const float cf_vPX = 0.0f;
const int c_vPY = 0;
const float cf_vPY = 0.0f;

// SX = SizeX, SY = SizeY, S = Size
// hB = healthBar
const int c_hBSX = 176;
const float cf_hBSX = 176.0f;
const int c_hBSY = 16;
const float cf_hBSY = 16.0f;
// m = menu
const int c_mSX = 480;
const float cf_mSX = 480.0f;
const int c_mSY = 540;
const float cf_mSY = 540.0f;
// s = sprite
const int c_sS = 240;
const float cf_sS = 240.0f;
// t = tile
const int c_tS = 32;
const float cf_tS = 32.0f;
// tB = textBox
const int c_tBSX = 480;
const float cf_tBSX = 480.0f;
const int c_tBSY = 124;
const float cf_tBSY = 124.0f;
// v = view
const int c_vSX = 480;
const float cf_vSX = 480.0f;
const int c_vSY = 416;
const float cf_vSY = 416.0f;
// w = window
const int c_wSX = 960;
const float cf_wSX = 960.0f;
const int c_wSY = 540;
const float cf_wSY = 540.0f;

// Speed
const int c_ledgeSpeed = 2;
const int c_rotateSpeed = 8;
const int c_walkSpeed = 4;

// Enums
enum Direction { none, up, down, left, right };
enum MoveStat { PP = 1, power, accuracy };
enum PokemonStat {
	HP = 1, attack, defense,
	special_attack, special_defense, speed
};
enum Type {
	normal = 1, fighting, flying, poison, ground,
	rock, bug, ghost, steel, fire,
	water, grass, electric, psychic, ice,
	dragon, dark, fairy
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