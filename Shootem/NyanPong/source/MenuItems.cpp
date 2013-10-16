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
}
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

void setTag(std::string change)
{
	tag = change;
}
void drawStat()
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
		std::string basic = "BASIC";
		if (tag == basic)
			DrawString( "BASIC", 300, 300, 0);
		
		DrawSprite(iStat);
	}
}
void endItems()
{
	DestroySprite(iStat);
	DestroySprite(iWin);
	DestroySprite(iLose);
	DestroySprite(iLeave);
	DestroySprite(iPlay);
	DestroySprite(iStat);
}
bool getUp()
{
	return up;
}
void setUp(bool change)
{
	up = change;
}