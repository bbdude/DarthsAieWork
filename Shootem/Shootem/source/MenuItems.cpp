#include <iostream>
#include "MenuItems.h"

int iWin = -1;
int iLose = -1;
int iLeave = -1;
int iPlay = -1;
int iStat = -1;
bool up = false;
bool press = false;
std::string tag = "";

//////////////////////////////////////////////////////////////////////////
/// <gets a sprite of the chosen menu type>
///
/// @param  char
/// @return int
//////////////////////////////////////////////////////////////////////////
int getSprite(char choice)
{
	switch(choice)
	{
	case 'W':
		return iWin;
		break;
	case 'L':
		return iLose;
		break;
	case 'E':
		return iLeave;
		break;
	case 'P':
		return iPlay;
		break;
	}
	return iPlay;
}

//////////////////////////////////////////////////////////////////////////
/// <sets a sprite of the chosen type>
///
/// @param  char,int
/// @return void
//////////////////////////////////////////////////////////////////////////
void setSprite(char choice,int number)
{
	switch(choice)
	{
	case 'W':
		iWin = number;
		break;
	case 'L':
		iLose = number;
		break;
	case 'E':
		iLeave = number;
		break;
	case 'P':
		iPlay = number;
		break;
	case 'T':
		//MoveSprite(iStat,640,340);
		iStat = number;
		break;
	}
}

//////////////////////////////////////////////////////////////////////////
/// <sets the tag>
///
/// @param  string
/// @return void
//////////////////////////////////////////////////////////////////////////
void setTag(std::string change)
{
	tag = change;
}

//////////////////////////////////////////////////////////////////////////
/// <Draws the stat sprite, returns the tag >
///
/// @param  int
/// @return string
//////////////////////////////////////////////////////////////////////////
std::string drawStat(int lives)
{
	if (IsKeyDown('E'))
		press = true;
	else if (press)
	{
		press = false;
		up = !up;
	}
	if (up)
	{
		MoveSprite(iStat,640,340);
		if (tag == "BASIC")
		{
			DrawString( "Basic Ship", 380, 500, 0);
			DrawString( "Ability: Laser Beam", 600, 200, 0);
			DrawString( "Speed: 1", 600, 300, 0);
			DrawString( "Health: 7 Bars", 600, 400, 0);
			DrawString( "Defense: 1", 600, 500, 0);
		}
		else// if (tag == "WOAH")
		{
			DrawString( "Fast Ship", 380, 500, 0);
			DrawString( "Ability: Pulse Ray", 600, 200, 0);
			DrawString( "Speed: 2", 600, 300, 0);
			DrawString( "Health: 5 Bars", 600, 400, 0);
			DrawString( "Defense: 1", 600, 500, 0);
		}

		DrawSprite(iStat);
		return tag;
	}
	return "";
}

//////////////////////////////////////////////////////////////////////////
/// <destroys all of the data for each of the sprites>
///
/// @param  N/A
/// @return void
//////////////////////////////////////////////////////////////////////////
void endItems()
{
	DestroySprite(iStat);
	DestroySprite(iWin);
	DestroySprite(iLose);
	DestroySprite(iLeave);
	DestroySprite(iPlay);
	DestroySprite(iStat);
}

//////////////////////////////////////////////////////////////////////////
/// <gets if the stat is up>
///
/// @param  N/A
/// @return bool
//////////////////////////////////////////////////////////////////////////
bool getUp()
{
	return up;
}

//////////////////////////////////////////////////////////////////////////
/// <changes if stat is up>
///
/// @param  bool
/// @return void
//////////////////////////////////////////////////////////////////////////
void setUp(bool change)
{
	up = change;
}

//////////////////////////////////////////////////////////////////////////
/// <gets the tag>
///
/// @param  N/A
/// @return string
//////////////////////////////////////////////////////////////////////////
std::string getTag()
{
	return tag;
}