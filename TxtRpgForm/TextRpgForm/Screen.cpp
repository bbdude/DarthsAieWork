#include <iostream>
#include "Player.h"
#include "stdafx.h"
#include <string>
using namespace std;
using namespace System;
using namespace System::Text;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

string location;
int windowSize;
string line[29];
bool wall[29][29];
int portalLocX[4];
int portalLocY[4];

int getWindowSize(){ return windowSize;}
void setWindowSize(int change){ windowSize = change;}
string getLine(int which) { return line[which]; }
bool getWall(int x,int y) { return wall[x][y]; }
int getPortalX(int which) { return portalLocX[which]; }
int getPortalY(int which) { return portalLocY[which]; }

void loadLine(int whatLine,string changeLine)
{
	line[whatLine] = changeLine;
}
void assignWallValues()
{
}
void setBoarder(int x, int y, int mX,int mY, int mXTwo,int mYTwo, int mXThree, int mYThree)
{
	if (x <= 0)
		x = 1;
	if (y <= 0)
		y = 1;
	line[0] = "|";
	for(int i = 0; i <= 58-(location.length()/2);i++)
		line[0] += "-";
	line[0] += location;
	for(int i = 0; i <= 58 - (location.length()/2);i++)
		line[0] += "-";
	line[0] += "|";
	//system("Color F1");
	for(int i = 1; i <= 18; i++)
	{
		line[i] = "|";
		for(int ii = 1; ii <= 118; ii++)
		{
			if (i == portalLocX[0] && ii == portalLocY[0])
				line[i] += "F";
			else if (i == portalLocX[1] && ii == portalLocY[1])
				line[i] += "T";
			else if (i == portalLocX[2] && ii == portalLocY[2])
				line[i] += "S";
			else if (i == portalLocX[3] && ii == portalLocY[3])
				line[i] += "s";
			else if (wall[i][ii])
				line[i] += "+";
			else if (i == x && ii == y)
				line[i] += "X";
			else if (i == mX && ii == mY)
				line[i] += "P";
			else if (i == mXTwo && ii == mYTwo)
				line[i] += "P";
			else if (i == mXThree && ii == mYThree)
				line[i] += "P";
			else
			line[i] += "-";
		}
	}
	for(int i = 1; i <= 18; i++)
	{
		line[i] += "|";
	}
	//writel(line[0]);
	line[windowSize] = "|---------------------------------------------------------------------------------------------------------------------|";
}
void updateLines(int x, int y, int mX,int mY, int mXTwo,int mYTwo, int mXThree, int mYThree)
{
	setWindowSize(18);
	setBoarder(x,y,mX,mY,mXTwo,mYTwo,mXThree,mYThree);
	
}
void getLoc(int loc)
{
	for (int i = 0; i < 18; i++)
	{
		for (int ii = 0; ii < 118; ii++)
			wall[i][ii] = false;
	}
	for (int i = 0; i < 3; i++)
	{
		portalLocX[i] = 0;
		portalLocY[i] = 0;
	}
	switch(loc)
	{
	case 1:
		location = "TOWN";
		portalLocX[0] = 4;
		portalLocY[0] = 64;
		portalLocX[1] = 6;
		portalLocY[1] = 6;
		portalLocX[2] = 3;
		portalLocY[2] = 93;
		portalLocX[3] = 5;
		portalLocY[3] = 35;

		wall[5][5] = true;
		wall[6][5] = true;
		wall[7][5] = true;
		wall[8][5] = true;
		wall[9][5] = true;
		wall[10][5] = true;
		wall[11][5] = true;
		wall[12][5] = true;
		wall[5][6] = true;
		wall[6][7] = true;
		wall[7][8] = true;
		wall[8][9] = true;
		wall[9][10] = true;
		wall[10][11] = true;
		wall[11][12] = true;
		wall[12][13] = true;
		break;
	case 2:
		location = "STATS";
		break;
	case 3:
		location = "FOREST";
		break;
	case 4:
		location = "TAVERN";
		break;
	case 5:
		location = "SHOP";
		break;
	case 6:
		location = "QUIT";
		break;
	default:
		location = "SHOPPE";
		break;
	}
}
