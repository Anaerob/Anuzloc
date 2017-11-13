#include "Constants.h"

namespace c
{
	extern const int iMPX(480);
	extern const float fMPX(480.0f);
	extern const int iMPY(0);
	extern const float fMPY(0.0f);
	extern const int iTBPX(0);
	extern const float fTBPX(0.0f);
	extern const int iTBPY(416);
	extern const float fTBPY(416.0f);
	extern const int iVPX(0);
	extern const float fVPX(0.0f);
	extern const int iVPY(0);
	extern const float fVPY(0.0f);

	extern const int iHBSX(176);
	extern const float fHBSX(176.0f);
	extern const int iHBSY(16);
	extern const float fHBSY(16.0f);
	extern const int iMSX(480);
	extern const float fMSX(480.0f);
	extern const int iMSY(540);
	extern const float fMSY(540.0f);
	extern const int iSS(240);
	extern const float fSS(240.0f);
	extern const int iTS(32);
	extern const float fTS(32.0f);
	extern const int iTBSX(480);
	extern const float fTBSX(480.0f);
	extern const int iTBSY(124);
	extern const float fTBSY(124.0f);
	extern const int iVSX(480);
	extern const float fVSX(480.0f);
	extern const int iVSY(416);
	extern const float fVSY(416.0f);
	extern const int iWSX(960);
	extern const float fWSX(960.0f);
	extern const int iWSY(540);
	extern const float fWSY(540.0f);
	
	extern const int iLSp(2);
	extern const int iRSp(8);
	extern const int iWSp(4);
	
	extern const int iBN(6);
	extern const int iEN(10);
	extern const int iPN(10);

	extern const int iPBS[4][6] {
		{ 45, 49, 49, 65, 65, 45 },
		{ 39, 52, 43, 60, 50, 65 },
		{ 44, 48, 65, 50, 64, 43 },
		{ 35, 55, 40, 50, 50, 90 }
	};
	extern const int iPM[4][4] {
		{ 1, 2, 0, 0 },
		{ 3, 2, 0, 0 },
		{ 1, 4, 0, 0 },
		{ 4, 5, 0, 0 }
	};
	extern const std::string sPN[4] {
		"Bulbasaur",
		"Charmander",
		"Squirtle",
		"Pikachu"
	};
	extern const int iPT[4][2] {
		{ 12, 4 },
		{ 10, 0 },
		{ 11, 0 },
		{ 13, 0 }
	};
	extern const int iMBS[5][3] {
		{ 35, 40, 100 },
		{ 40, 0, 100 },
		{ 35, 40, 100 },
		{ 30, 0, 100 },
		{ 30, 40, 100 },
	};
	extern const std::string sMN[5] {
		"Tackle",
		"Growl",
		"Scratch",
		"Tail Whip",
		"Thunder Shock",
	};
	extern const int iMT[5] {
		1, 1, 1, 1, 13
	};
}