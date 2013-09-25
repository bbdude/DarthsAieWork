// TextRPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <time.h>
#include "misc.h"
#include <cmath>
using namespace std;
using namespace System;
using namespace System::Text;
using namespace System::IO;

bool kill = true;
int randomInt(int max)
{
	return (rand() % max) + 1;
}
void write(std::string word)
{
	std::cout << word;
}
void writel(std::string word)
{
	Console::ForegroundColor = ConsoleColor::White;
	std::cout << word << endl;
}
void writecl(std::string word)
{
	system("cls");
	std::cout << word << endl;
}
void write(int word)
{
	std::cout << word;
}
void writel(int word)
{
	std::cout << word << endl;
}
void writebl(std::string word)
{
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
	std::cout << word << endl;
}
void writecl(int word)
{
	system("cls");
	std::cout << word << endl;
}
void writel(float word)
{
	std::cout << word << endl;
}
std::string getS()
{
	std::string returnValue;
	std::cin >> returnValue;
	return returnValue;
}
char getC()
{
	char returnValue;
	std::cin >> returnValue;
	return returnValue;
}
int getI()
{
	int returnValue;
	std::cin >> returnValue;
	return returnValue;
}
float getF()
{
	float returnValue;
	std::cin >> returnValue;
	return returnValue;
}
char getCC()
{
	char returnValue;
	returnValue = _getch();
	return returnValue;
}
int getIC()
{
	int returnValue;
	returnValue = _getch();
	return returnValue;
}
void drawBar()
{
	writel("-----------------------------------------------------------------------------------------------------------------------");
}
/*
char playerName[] = "";
int playerData[10] = {4,4,4,4,5,6,213,5,53,35};

void convertCharArray()
{
for(int i = 0; i < 256; i++)
{
if (isspace(playerName[i])){
playerName[i] = '_';
}
putchar(tolower(playerName[i]));
//writel(playerName);
}
}
bool convertPasswordChar()
{
int howManyIntsNeeded = 0;
int i = 0;
while (playerName[i])
{
if (isdigit(playerName[i])){
howManyIntsNeeded++;
writecl(howManyIntsNeeded);
}
i++;
}
if (howManyIntsNeeded  >= 3 && howManyIntsNeeded != i && i >= 8)
return true;

return false;
}
int averageArray()
{
int numbToRemember = 0;
int i = 0;
//while (playerData[i])
for (int i = 0; i < 10; i++)
{
writel("HDFGFDG");
numbToRemember += playerData[i];
}
return numbToRemember/10;
}

struct Character
{
string name;
int health;
int healthMax;
int score;
string direction;
std::vector<vector<int>> position;
struct Mob
{
std::vector<vector<int>> targetPos;
int bulletsLeft;
int bulletsMax;
};
};
struct Player
{
string name;
int health;
int healthMax;
int score;
int chargeTime;
string direction;
std::vector<vector<int>> position;
std::vector<vector<int>> targetPos;
int bulletsLeft;
int bulletsMax;
};
struct Ship
{
std::vector<vector<vector<int>>> pointsPos;
std::vector<vector<vector<int>>> targetPos;
int health;
int healthMax;
int armorCap;
int armorCapMax;
int missles[4];
int misslesMax[4];
int coolDown[6];
};
struct Triangle
{
std::vector<vector<vector<int>>> pointsPos;
std::vector<vector<vector<int>>> colorRGB;
};
*/
struct PlayerStruct
{
	int myTurn;
	int iCharacter;
	int iDmg;
	int iHealth;
	int iHealthMax;
	int iGold;
	int iWeaponLvl;
	int iStoredDamage;
	int rowY;
	int columnX;
	int rowPY;
	int columnPX;

	void begin()
	{
		myTurn = 0;
		rowY = 2;
		columnX = 2;
		rowPY = 2;
		columnPX = 2;
		iCharacter = 0;
		iDmg = 0;
		iHealth = 5;
		iHealthMax = 5;
		iGold = 10;
		iWeaponLvl = 0;
		iStoredDamage = 1;
	}
	void updatePlayer()
	{
	}
	bool moveMonster(PlayerStruct& player,PlayerStruct &playerTwo,PlayerStruct &playerThree)
	{
		int distanceX[3] = {0,0,0};
		int distanceY[3] = {0,0,0};

		distanceX[0] = columnPX - player.columnX;
		distanceX[1] = columnPX - player.columnX;
		distanceX[2] = columnPX - player.columnX;
		distanceY[0] = rowPY - player.rowY;
		distanceY[1] = rowPY - player.rowY;
		distanceY[2] = rowPY - player.rowY;
		if (player.iHealth <= 0)
		{
			distanceX[0] = -100;
			distanceY[0] = -100;
		}
		if (playerTwo.iHealth <= 0)
		{
			distanceX[1] = -100;
			distanceY[1] = -100;
		}
		if (playerThree.iHealth <= 0)
		{
			distanceX[2] = -100;
			distanceY[2] = -100;
		}
		if ( distanceX[0] <= distanceX[1] && distanceX[0] <= distanceX[2] && player.iHealth > 0 && distanceX[0] <= 11 && distanceY[0] <= 11)
		{
			if (distanceX[0] > 0)
				columnPX--;
			else if (distanceX[0] < 0)
				columnPX++;
			if (distanceY[0] > 0)
				rowPY--;
			else if (distanceY[0] < 0)
				rowPY++;
		}
		//choose the second one if his position distance total is less then 0 && 2
		else if ( distanceX[1] <= distanceX[0] && distanceX[1] <= distanceX[2] && playerTwo.iHealth > 0 && distanceX[1] <= 11 && distanceY[1] <= 11)
		{
			if (distanceX[1] > 0)
				columnPX--;
			else if (distanceX[1] < 0)
				columnPX++;
			if (distanceY[1] > 0)
				rowPY--;
			else if (distanceY[1] < 0)
				rowPY++;
			//return;
		}
		//choose the third one if his position distance total is less then 1 && 0
		else if ( distanceX[2] <= distanceX[1] && distanceX[2] <= distanceX[0] && playerThree.iHealth > 0 && distanceX[2] <= 11 && distanceY[2] <= 11)
		{

			if (distanceX[2] > 0)
				columnPX--;
			else if (distanceX[2] < 0)
				columnPX++;
			if (distanceY[2] > 0)
				rowPY--;
			else if (distanceY[2] < 0)
				rowPY++;
		}
		else
			return true;
		return false;
	}
	void updateMonster()
	{
		rowPY = rowY;
		columnPX = columnX;
		int temp = randomInt(4);
		if (temp == 1)
			rowPY++;
		else if (temp == 2)
			columnPX++;
		else if (temp == 3)
			columnPX--;
		else if (temp == 4)
			rowPY--;
	}
	int getX() { return columnX; }
	int getY() { return rowY; }
	void setX(int x) { columnX = x; }
	void setY(int y) { rowY = y; }
	int getPX() { return columnPX; }
	int getPY() { return rowPY; }
	void setPX(int x) { columnPX = x; }
	void setPY(int y) { rowPY = y; }
};
struct Screen
{
	string location;
	int windowSize;
	string line[29];
	bool wall[29][29];
	int portalLocX[4];
	int portalLocY[4];
	void loadLine(int whatLine,string changeLine)
	{
		line[whatLine] = changeLine;
	}
	int getCloseEnemy(int x, int y, int mX,int mY, int mXTwo,int mYTwo, int mXThree, int mYThree, int mH, int mHTwo, int mHThree)
	{
		int distanceX[3] = {0,0,0};
		int distanceY[3] = {0,0,0};
		if (mX != x && mXTwo != x && mXThree != x && mY != y && mYTwo != y && mYThree != y)
			return 0;
		if (mX == x)
		{
			if (distanceX[0] < 0)
				distanceX[0] *= -1;
			distanceX[0] = x - mX;
		}
		if (mXTwo == x)
		{
			if (distanceX[1] < 0)
				distanceX[1] *= -1;
			distanceX[1] = x - mX;
		}
		if (mXThree == x)
		{
			if (distanceX[2] < 0)
				distanceX[2] *= -1;
			distanceX[2] = x - mX;
		}
		if (mY == y)
		{
			if (distanceY[0] < 0)
				distanceY[0] *= -1;
			distanceY[0] = y - mY;
		}
		if (mYTwo == y)
		{
			if (distanceY[1] < 0)
				distanceY[1] *= -1;
			distanceY[1] = y - mY;
		}
		if (mYThree == y)
		{
			if (distanceY[2] < 0)
				distanceY[2] *= -1;
			distanceY[2] = y - mY;
		}
		distanceX[0] += distanceY[0];
		distanceX[1] += distanceY[1];
		distanceX[2] += distanceY[2];
		if (mH <= 0)
			distanceX[0] = 0;
		if (mHTwo <= 0)
			distanceX[1] = 0;
		if (mHThree <= 0)
			distanceX[2] = 0;
		if (distanceX[0] >= 10 && distanceX[1] >= 10 && distanceX[2] >= 10)
		{
			return 4;
		}
		//Creates a problem killing enemy 1
		//If all the values are 0 or a perfect distance from each other choose none of them
		//if (distanceX[0] == distanceX[1] && distanceX[0] == distanceX[2])
		//if (distanceX[0] == 0 && distanceX[1]  == 0 && distanceX[2] == 0)
		//return 0;
		//choose the first one if his position distance total is less then 1 && 2
		if ( distanceX[0] <= distanceX[1] && distanceX[0] <= distanceX[2] && mH > 0)
			return 1;
		//choose the second one if his position distance total is less then 0 && 2
		else if ( distanceX[1] <= distanceX[0] && distanceX[1] <= distanceX[2] && mHTwo > 0)
			return 2;
		//choose the third one if his position distance total is less then 1 && 0
		else if ( distanceX[2] <= distanceX[1] && distanceX[2] <= distanceX[0] && mHThree > 0)
			return 3;
		else
			return 0;
	}
	int getCloseMeleeEnemy(int x, int y, int mX,int mY, int mXTwo,int mYTwo, int mXThree, int mYThree, int mH, int mHTwo, int mHThree,int direction)
	{
		//1,2,3
		//4, ,5
		//6,7,8
		if (mH <= 0)
		{
			mX = -10;
			mY = -10;
		}
		if (mHTwo <= 0)
		{
			mXTwo = -10;
			mYTwo = -10;
		}
		if (mHThree <= 0)
		{
			mXThree = -10;
			mYThree = -10;
		}
		switch(direction)
		{
		case 1:
			if (mX == x-1 && mY == y-1)
				return 1;
			else if (mXTwo == x-1 && mYTwo == y-1)
				return 2;
			else if (mXThree == x-1 && mYThree == y-1)
				return 3;
			break;
		case 2:
			if (mX == x-1 && mY == y)
				return 1;
			else if (mXTwo == x-1 && mYTwo == y)
				return 2;
			else if (mXThree == x-1 && mYThree == y)
				return 3;
			break;
		case 3:
			if (mX == x-1 && mY == y+1)
				return 1;
			else if (mXTwo == x-1 && mYTwo == y+1)
				return 2;
			else if (mXThree == x-1 && mYThree == y+1)
				return 3;
			break;
		case 4:
			if (mX == x && mY == y-1)
				return 1;
			else if (mXTwo == x && mYTwo == y-1)
				return 2;
			else if (mXThree == x && mYThree == y-1)
				return 3;
			break;
		case 5:
			if (mX == x && mY == y+1)
				return 1;
			else if (mXTwo == x && mYTwo == y+1)
				return 2;
			else if (mXThree == x && mYThree == y+1)
				return 3;
			break;
		case 6:
			if (mX == x+1 && mY == y-1)
				return 1;
			else if (mXTwo == +1 && mYTwo == y-1)
				return 2;
			else if (mXThree == x+1 && mYThree == y-1)
				return 3;
			break;
		case 7:
			if (mX == x+1 && mY == y)
				return 1;
			else if (mXTwo == x+1 && mYTwo == y)
				return 2;
			else if (mXThree == x+1 && mYThree == y)
				return 3;
			break;
		case 8:
			if (mX == x+1 && mY == y+1)
				return 1;
			else if (mXTwo == x+1 && mYTwo == y+1)
				return 2;
			else if (mXThree == x+1 && mYThree == y+1)
				return 3;
			break;
		}
		return 0;
	}
	void setBoarder(int x, int y, int xTwo,int yTwo, int xThree, int yThree, int mX,int mY, int mXTwo,int mYTwo, int mXThree, int mYThree, int mH, int mHTwo, int mHThree)
	{
		if (x <= 0)
			x = 1;
		if (y <= 0)
			y = 1;
		line[0] = "|";
		for(int i = 0; i <= 58 - (int)(location.length()/2);i++)
			line[0] += "-";
		line[0] += location;
		for(int i = 0; i <= 58 - (int)(location.length()/2);i++)
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
					line[i] += "S";
				else if (i == portalLocX[2] && ii == portalLocY[2])
					line[i] += "T";
				else if (i == portalLocX[3] && ii == portalLocY[3])
					line[i] += "s";
				else if (wall[i][ii])
					line[i] += "+";
				else if (i == x && ii == y)
					line[i] += "X";
				else if (i == xTwo && ii == yTwo)
					line[i] += "Y";
				else if (i == xThree && ii == yThree)
					line[i] += "Z";
				else if (i == mX && ii == mY && mH > 0)
					line[i] += "1";
				else if (i == mXTwo && ii == mYTwo && mHTwo > 0)
					line[i] += "2";
				else if (i == mXThree && ii == mYThree && mHThree > 0)
					line[i] += "3";
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
	void updateLines(int x, int y, int xTwo,int yTwo, int xThree, int yThree, int mX,int mY, int mXTwo,int mYTwo, int mXThree, int mYThree, int mH, int mHTwo, int mHThree)
	{
		setWindowSize(18);
		setBoarder(x,y,xTwo,yTwo,xThree,yThree,mX,mY,mXTwo,mYTwo,mXThree,mYThree,mH,mHTwo,mHThree);
		writecl("");
		for(int i = 0; i <= windowSize; i++)
		{
			if (getLine(i).length() > 0){
				writel(getLine(i));
				//cout << getLine(i) << endl;
			}
		}
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
		case 3:
			location = "FOREST";
			break;
		case 4:
			location = "TAVERN";
			wall[2][1] = true;
			wall[2][2] = true;
			wall[2][3] = true;
			wall[2][4] = true;
			wall[2][5] = true;
			wall[2][6] = true;
			wall[2][7] = true;
			wall[2][8] = true;
			wall[2][9] = true;
			wall[2][10] = true;
			wall[10][1] = true;
			wall[10][2] = true;
			wall[10][3] = true;
			wall[10][4] = true;
			wall[10][5] = true;
			wall[10][6] = true;
			wall[10][7] = true;
			wall[10][8] = true;
			wall[10][9] = true;
			wall[10][10] = true;
			wall[1][2] = true;
			wall[2][2] = true;
			wall[3][2] = true;
			wall[4][2] = true;
			wall[5][2] = true;
			wall[6][2] = true;
			wall[7][2] = true;
			wall[8][2] = true;
			wall[9][2] = true;
			wall[10][2] = true;
			wall[1][10] = true;
			wall[2][10] = true;
			wall[3][10] = true;
			wall[4][10] = true;
			wall[5][10] = true;
			wall[6][10] = true;
			wall[7][10] = true;
			wall[8][10] = true;
			wall[9][10] = true;
			wall[10][10] = true;
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
	int getWindowSize(){ return windowSize;}
	void setWindowSize(int change){ windowSize = change;}
	string getLine(int which) { return line[which]; }
	bool getWall(int x,int y) { return wall[x][y]; }
	int getPortalX(int which) { return portalLocX[which]; }
	int getPortalY(int which) { return portalLocY[which]; }
};

int movePlayer(PlayerStruct &player,Screen &screen,PlayerStruct &monster,PlayerStruct &monsterTwo,PlayerStruct &monsterThree)
{
	enum LOC {TEST,TOWN,STATS,FOREST,TAVERN,SHOP,QUIT,SHOPPE,MOUNTAINONE,MOUNTAINTWO,MOUNTAINTHREE,MOUNTAINFINALE};
	LOC myLoc = TOWN;
	char choice;
	choice = getIC();
	switch(choice)
	{
	case 'v':
		writecl("");
		myLoc = STATS;
		screen.getLoc(myLoc);
		return myLoc;
		break;
	case '2':
		//{TEST,TOWN,STATS,FOREST,TAVERN,SHOP,QUIT,SHOPPE};
		writecl("");
		myLoc = FOREST;
		screen.getLoc(myLoc);
		return myLoc;
		break;
	case '3':
		writecl("");
		myLoc = TAVERN;
		screen.getLoc(myLoc);
		return myLoc;
		break;
	case '4':
		writecl("");
		myLoc = SHOP;
		screen.getLoc(myLoc);
		return myLoc;
		break;
	case 'q':
		writecl("");
		//screen.getLoc();
		kill = false;
		break;
	case '6':
		writecl("");
		myLoc = SHOPPE;
		screen.getLoc(myLoc);
		return myLoc;
		break;
	case 'w':
		if (player.getX() - 1 > 0)
			player.setPX(player.getX() - 1);
		break;
	case 's':
		if (player.getX() + 1 < 18)
			player.setPX(player.getX() + 1);
		break;
	case 'a':
		if (player.getY() - 1 > 0)
			player.setPY(player.getY() - 1);
		break;
	case 'd':
		if (player.getY() + 1 < 119)
			player.setPY(player.getY() + 1);
		break;
	case 'W':
		if (player.getX() - 1 > 0)
			player.setPX(player.getX() - 1);
		break;
	case 'S':
		if (player.getX() + 1 < 18)
			player.setPX(player.getX() + 1);
		break;
	case 'A':
		if (player.getY() - 1 > 0)
			player.setPY(player.getY() - 1);
		break;
	case 'D':
		if (player.getY() + 1 < 119)
			player.setPY(player.getY() + 1);
		break;
	case 'r':
		{
			int tempDamage = 0;
			switch(player.iCharacter)
			{
			case 1:
				writel("You fire a bolt of light at the closest enemy");
				tempDamage = 10;
				break;
			case 2:
				writel("You throw your sword at the closest enemy");
				tempDamage = 5;
				break;
			case 3:
				writel("You fire a crossbow at the closest enemy");
				tempDamage = 8;
				break;
			case 4:
				writel("You send a swarm of bats at the closest enemy");
				tempDamage = 66;
				break;
			}
			switch(screen.getCloseEnemy(player.columnX,player.rowY,monster.columnX,monster.rowY,monsterTwo.columnX,monsterTwo.rowY,monsterThree.columnX,monsterThree.rowY,monster.iHealth,monsterTwo.iHealth,monsterThree.iHealth))
			{
			case 1:
				if (monster.iHealth > 0)
				{
					write("You hit enemy1 for:");
					writel(tempDamage);
					monster.iHealth -= tempDamage;
					if (monster.iHealth < 0)
					{
						writel("You have killed enemy1");
					}
				}
				Sleep(5000);
				break;
			case 2:
				if (monsterTwo.iHealth > 0)
				{
					write("You hit enemy2 for:");
					writel(tempDamage);
					monsterTwo.iHealth -= tempDamage;
					if (monsterTwo.iHealth < 0)
					{
						writel("You have killed enemy2");
					}
				}
				Sleep(5000);
				break;
			case 3:
				if (monsterThree.iHealth > 0)
				{
					write("You hit enemy3 for:");
					writel(tempDamage);
					monsterThree.iHealth -= tempDamage;
					if (monsterThree.iHealth < 0)
					{
						writel("You have killed enemy3");
					}
				}
				Sleep(5000);
				break;
			case 0:
				write("Hitting 0");
				Sleep(5000);
				break;
			default:
				write("You miss all the enemies stupid");
				Sleep(5000);
				break;
			}
			break;
		}
	case 'e':
		{
			writel("");
			writel("what direction ? 1,2,3");
			writel("                 4, ,5");
			writel("                 6,7,8");
			int direction = getI();
			int tempDamage = 0;
			switch(player.iCharacter)
			{
			case 1:
				writel("You swing your staff in that direction");
				tempDamage = 10;
				break;
			case 2:
				writel("You swing your sword in that direction");
				tempDamage = 5;
				break;
			case 3:
				writel("You swing your dagger in that direction");
				tempDamage = 8;
				break;
			case 4:
				writel("You burn stuff in that direction");
				tempDamage = 66;
				break;
			}
			switch(screen.getCloseMeleeEnemy(player.columnX,player.rowY,monster.columnX,monster.rowY,monsterTwo.columnX,monsterTwo.rowY,monsterThree.columnX,monsterThree.rowY,monster.iHealth,monsterTwo.iHealth,monsterThree.iHealth,direction))
			{
			case 1:
				if (monster.iHealth > 0)
				{
					write("You hit enemy1 for:");
					writel(tempDamage);
					monster.iHealth -= tempDamage;
					if (monster.iHealth < 0)
					{
						writel("You have killed enemy1");
					}
				}
				Sleep(5000);
				break;
			case 2:
				if (monsterTwo.iHealth > 0)
				{
					write("You hit enemy2 for:");
					writel(tempDamage);
					monsterTwo.iHealth -= tempDamage;
					if (monsterTwo.iHealth < 0)
					{
						writel("You have killed enemy2");
					}
				}
				Sleep(5000);
				break;
			case 3:
				if (monsterThree.iHealth > 0)
				{
					write("You hit enemy3 for:");
					writel(tempDamage);
					monsterThree.iHealth -= tempDamage;
					if (monsterThree.iHealth < 0)
					{
						writel("You have killed enemy3");
					}
				}
				Sleep(5000);
				break;
			case 0:
				write("Hitting 0");
				Sleep(5000);
				break;
			default:
				write("You miss all the enemies stupid");
				Sleep(5000);
				break;
			}
			break;
			//Sleep(5555555555);
			/*

			*/
		}
	default:
		writecl("");
		screen.getLoc(myLoc);
		return myLoc;
		break;
	}
	return myLoc;
}
string getStoryLine(int location)
{
	enum LOC {TEST,TOWN,STATS,FOREST,TAVERN,SHOP,QUIT,SHOPPE,MOUNTAINONE,MOUNTAINTWO,MOUNTAINTHREE,MOUNTAINFINALE};
	LOC myLoc = static_cast<LOC>(location);

	switch(myLoc)
	{
	case TOWN:
		return "You enter a town full of undead unicorns(3); fire balls and lighting are raining from the sky.";
		break;
	case FOREST:
		return "Your enter a clearing in the forest. It seems some skeletons(3) are waiting for you.";
		break;
	case TAVERN:
		return "You enter a the The Saracen's Head. Several people look pretty blootered(drunk).";
		break;
	case MOUNTAINONE:
		return "You begin the harsh climb. Hopefully the \"Hammer of Glory\" is worth it";
		break;
	case MOUNTAINTWO:
		return "The wind whispers in your ears and your weapons grow heavy.";
		break;
	case MOUNTAINTHREE:
		return "Many fights have been won and still you travel on.";
		break;
	case MOUNTAINFINALE:
		return "Zargothrax greets you. Your death awaits";
		break;
	default:
		break;
	}


	return "";
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };  
	SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
	writecl("asdasdasdasda");
}

int _tmain(int argc, _TCHAR* argv[])
{
	bool partyMode = false;
	srand((int)time(NULL));
	
	PlayerStruct player;
	PlayerStruct playerTwo;
	PlayerStruct playerThree;
	PlayerStruct monster;
	PlayerStruct monsterTwo;
	PlayerStruct monsterThree;
	Screen screen;
	player.begin();
	playerTwo.begin();
	playerThree.begin();
	monster.begin();
	monsterTwo.begin();
	monsterThree.begin();
	monster.setX(14);
	monster.setY(14);
	monster.setPX(14);
	monster.setPY(14);
	monsterTwo.setX(5);
	monsterTwo.setY(8);
	monsterTwo.setPX(5);
	monsterTwo.setPY(8);
	monsterThree.setX(17);
	monsterThree.setY(100);
	monsterThree.setPX(17);
	monsterThree.setPY(100);
	player.setX(15);
	player.setY(100);
	player.setPX(15);
	player.setPY(100);

	enum LOC {TEST,TOWN,STATS,FOREST,TAVERN,SHOP,QUIT,SHOPPE,MOUNTAINONE,MOUNTAINTWO,MOUNTAINTHREE,MOUNTAINFINALE};
	enum MON {POTATO,GOBLIN,JUSTIN,YOURSELF,SELFESTEEM,DRAGON};
	LOC myLoc = TEST;
	MON myMon = POTATO;
	bool end = false;
	bool enemyCollision;
	char choice;
	Console::SetWindowSize( 120, 44 );
	Console::SetBufferSize( 120, 44 );
	Console::SetWindowPosition( 0, 0 );
	//int choice = 0;
	//writel(averageArray());

	//writecl("What is your name?");
	//cin.getline(playerName,256);
	//strcpy (playerName,getThisString);

	//while (!convertPasswordChar())
	//{
	//	writecl("You need to fix your password");
	//}
	//writel(playerName);
	//getS();
	
	drawBar();
	writel("|Welcome player. Will you be using party mode tonight?");
	writel("|}[1]No");
	writel("|}[2]Yes");
	drawBar();
	choice = getCC();
	if (choice == '2')
	{
		partyMode = true;
		player.iHealth = (rand() % 8) + 1;
		player.iDmg = (rand() % 20) + 1;
		player.iCharacter = 1;
		playerTwo.iHealth = (rand() % 20) + 1;
		playerTwo.iDmg = (rand() % 8) + 1;
		playerTwo.iCharacter = 2;
		playerThree.iHealth = (rand() % 12) + 1;
		playerThree.iDmg = (rand() % 12) + 1;
		playerThree.iCharacter = 3;
		myLoc = TOWN;
		screen.getLoc(TOWN);
		player.iHealthMax = player.iHealth;
		playerTwo.iHealthMax = player.iHealth;
		playerThree.iHealthMax = player.iHealth;
		playerTwo.setX(3);
		playerTwo.setY(3);
		playerTwo.setPX(3);
		playerTwo.setPY(3);
		playerThree.setX(2);
		playerThree.setY(3);
		playerThree.setPX(2);
		playerThree.setPY(3);
	}
	else
	{
		playerTwo.setX(-3);
		playerTwo.setY(-3);
		playerTwo.setPX(-3);
		playerTwo.setPY(-3);
		playerThree.setX(-2);
		playerThree.setY(-3);
		playerThree.setPX(-2);
		playerThree.setPY(-3);
	}
	while(kill){
		switch(myLoc){
		case TEST:
			drawBar();
			writel("|Welcome player. Choose your character");
			writel("|}[1]Priest");
			writel("|}[2]Warrior");
			writel("|}[3]Rouge");
			writel("|}[4]Satan");
			drawBar();
			choice = getIC();
			switch(choice){
			case '1':
				writecl("");
				player.iHealth = (rand() % 8) + 1;
				player.iDmg = (rand() % 20) + 1;
				player.iCharacter = 1;
				writel("|Welcome to Dundee Priest");
				break;
			case '2':
				writecl("");
				player.iHealth = (rand() % 20) + 1;
				player.iDmg = (rand() % 8) + 1;
				player.iCharacter = 2;
				writel("|Welcome to Dundee Warrior");
				break;
			case '3':
				writecl("");
				player.iHealth = (rand() % 12) + 1;
				player.iDmg = (rand() % 12) + 1;
				player.iCharacter = 3;
				writel("|Welcome to Dundee Rouge");
				break;
			case '4':
				writecl("");
				player.iHealth = (rand() % 666) + 1;
				player.iDmg = (rand() % 666) + 1;
				player.iCharacter = 4;
				writel("|Welcome to Dundee God of Pain");
				break;
			}
			writel("Continue to town?");
			getCC();
			myLoc = TOWN;
			screen.getLoc(TOWN);
			player.iHealthMax = player.iHealth;
			break;
		case TOWN:
			player.iHealth = player.iHealthMax;
			screen.getLoc(TOWN);
			//writecl(getStoryLine(TOWN));
			//Sleep(5000);
			for (int i = 0; i < 6; i++)
			{
				screen.updateLines(player.columnX,player.rowY,playerTwo.columnX,playerTwo.rowY,playerThree.columnX,playerThree.rowY,monster.columnX,monster.rowY,monsterTwo.columnX,monsterTwo.rowY,monsterThree.columnX,monsterThree.rowY,monster.iHealth,monsterTwo.iHealth,monsterThree.iHealth);

				//gotoxy(100,300);
				writel("|What would you like to do?|");
				writel("|}}Locations:                |}}Commands:             ");
				writel("|}[p]Undead Unicorns[f]Forest|[v]ViewStats    [e]Melee");
				writel("|}[t]Tavern         [s]Shop  |[q]Quit                 ");
				writel("|}[4]Shoppe                  |[r]Ranged attack        ");
				drawBar();
				//drawBar();
				if (i == 0){
					write("X's Turn: ");
					myLoc =  static_cast<LOC>(movePlayer(player,screen,monster,monsterTwo,monsterThree));
					//else if (i == 0 && player.iHealth < 0)
						//i++;
					//else if (i == 4 && playerThree.iHealth < 0)
						//i++;
					/*
					choice = getIC();
					switch(choice)
					{
					case 'v':
						writecl("");
						screen.getLoc(myLoc);
						myLoc = STATS;
						break;
					case '2':
						writecl("");
						screen.getLoc(myLoc);
						myLoc = FOREST;
						break;
					case '3':
						writecl("");
						screen.getLoc(myLoc);
						myLoc = TAVERN;
						break;
					case '4':
						writecl("");
						screen.getLoc(myLoc);
						myLoc = SHOP;
						break;
					case 'q':
						writecl("");
						screen.getLoc(myLoc);
						kill = false;
						break;
					case '6':
						writecl("");
						screen.getLoc(myLoc);
						myLoc = SHOPPE;
						break;
					case 'w':
						if (player.getX() - 1 > 0)
							player.setPX(player.getX() - 1);
						break;
					case 's':
						if (player.getX() + 1 < 18)
							player.setPX(player.getX() + 1);
						break;
					case 'a':
						if (player.getY() - 1 > 0)
							player.setPY(player.getY() - 1);
						break;
					case 'd':
						if (player.getY() + 1 < 119)
							player.setPY(player.getY() + 1);
						break;
					case 'W':
						if (player.getX() - 1 > 0)
							player.setPX(player.getX() - 1);
						break;
					case 'S':
						if (player.getX() + 1 < 18)
							player.setPX(player.getX() + 1);
						break;
					case 'A':
						if (player.getY() - 1 > 0)
							player.setPY(player.getY() - 1);
						break;
					case 'D':
						if (player.getY() + 1 < 119)
							player.setPY(player.getY() + 1);
						break;
					case 'r':
						{
							int tempDamage = 0;
							switch(player.iCharacter)
							{
							case 1:
								writel("You fire a bolt of light at the closest enemy");
								tempDamage = 10;
								break;
							case 2:
								writel("You throw your sword at the closest enemy");
								tempDamage = 5;
								break;
							case 3:
								writel("You fire a crossbow at the closest enemy");
								tempDamage = 8;
								break;
							case 4:
								writel("You send a swarm of bats at the closest enemy");
								tempDamage = 66;
								break;
							}
							switch(screen.getCloseEnemy(player.columnX,player.rowY,monster.columnX,monster.rowY,monsterTwo.columnX,monsterTwo.rowY,monsterThree.columnX,monsterThree.rowY,monster.iHealth,monsterTwo.iHealth,monsterThree.iHealth))
							{
							case 1:
								if (monster.iHealth > 0)
								{
									write("You hit enemy1 for:");
									writel(tempDamage);
									monster.iHealth -= tempDamage;
									if (monster.iHealth < 0)
									{
										writel("You have killed enemy1");
									}
								}
								Sleep(5000);
								break;
							case 2:
								if (monsterTwo.iHealth > 0)
								{
									write("You hit enemy2 for:");
									writel(tempDamage);
									monsterTwo.iHealth -= tempDamage;
									if (monsterTwo.iHealth < 0)
									{
										writel("You have killed enemy2");
									}
								}
								Sleep(5000);
								break;
							case 3:
								if (monsterThree.iHealth > 0)
								{
									write("You hit enemy3 for:");
									writel(tempDamage);
									monsterThree.iHealth -= tempDamage;
									if (monsterThree.iHealth < 0)
									{
										writel("You have killed enemy3");
									}
								}
								Sleep(5000);
								break;
							case 0:
								write("Hitting 0");
								Sleep(5000);
								break;
							default:
								write("You miss all the enemies stupid");
								Sleep(5000);
								break;
							}
							break;
						}
					case 'e':
						{
							writel("what direction ? 1,2,3");
							writel("                 4, ,5");
							writel("                 6,7,8");
							int direction = getI();
							int tempDamage = 0;
							switch(player.iCharacter)
							{
							case 1:
								writel("You swing your staff in that direction");
								tempDamage = 10;
								break;
							case 2:
								writel("You swing your sword in that direction");
								tempDamage = 5;
								break;
							case 3:
								writel("You swing your dagger in that direction");
								tempDamage = 8;
								break;
							case 4:
								writel("You burn stuff in that direction");
								tempDamage = 66;
								break;
							}
							switch(screen.getCloseMeleeEnemy(player.columnX,player.rowY,monster.columnX,monster.rowY,monsterTwo.columnX,monsterTwo.rowY,monsterThree.columnX,monsterThree.rowY,monster.iHealth,monsterTwo.iHealth,monsterThree.iHealth,direction))
							{
							case 1:
								if (monster.iHealth > 0)
								{
									write("You hit enemy1 for:");
									writel(tempDamage);
									monster.iHealth -= tempDamage;
									if (monster.iHealth < 0)
									{
										writel("You have killed enemy1");
									}
								}
								Sleep(5000);
								break;
							case 2:
								if (monsterTwo.iHealth > 0)
								{
									write("You hit enemy2 for:");
									writel(tempDamage);
									monsterTwo.iHealth -= tempDamage;
									if (monsterTwo.iHealth < 0)
									{
										writel("You have killed enemy2");
									}
								}
								Sleep(5000);
								break;
							case 3:
								if (monsterThree.iHealth > 0)
								{
									write("You hit enemy3 for:");
									writel(tempDamage);
									monsterThree.iHealth -= tempDamage;
									if (monsterThree.iHealth < 0)
									{
										writel("You have killed enemy3");
									}
								}
								Sleep(5000);
								break;
							case 0:
								write("Hitting 0");
								Sleep(5000);
								break;
							default:
								write("You miss all the enemies stupid");
								Sleep(5000);
								break;
							}
							break;
							//Sleep(5555555555);
						}
					default:
						writecl("");
						screen.getLoc(myLoc);
						myLoc = TOWN;
						break;
					}
					*/
					if (player.getPX() == screen.getPortalX(0) && player.getPY() == screen.getPortalY(0))
					{
						myLoc = FOREST;
						writecl("");
						player.setPX(player.getX());
						player.setPY(player.getY());
					}
					else if (player.getPX() == screen.getPortalX(1) && player.getPY() == screen.getPortalY(1))
					{
						myLoc = SHOP;
						writecl("");
						player.setPX(player.getX());
						player.setPY(player.getY());
					}
					else if (player.getPX() == screen.getPortalX(2) && player.getPY() == screen.getPortalY(2))
					{
						myLoc = TAVERN;
						writecl("");
						player.setPX(player.getX());
						player.setPY(player.getY());
					}
					else if (player.getPX() == screen.getPortalX(3) && player.getPY() == screen.getPortalY(3))
					{
						myLoc = SHOPPE;
						writecl("");
						player.setPX(player.getX());
						player.setPY(player.getY());
					}
					else if (!screen.getWall(player.getPX(),player.getPY()) && !(player.getPX() == monster.getPX() && player.getPY() == monster.getPY()) && !(player.getPX() == monsterTwo.getPX() && player.getPY() == monsterTwo.getPY()) && !(player.getPX() == monsterThree.getPX() && player.getPY() == monsterThree.getPY()))
					{
						player.setX(player.getPX());
						player.setY(player.getPY());
					}
					else
					{
						player.setPX(player.getX());
						player.setPY(player.getY());
					}
				}
				else if (i == 2 && playerTwo.iHealth > 0)
				{
					if (partyMode)
					{
						write("Y's Turn: ");
						myLoc =  static_cast<LOC>(movePlayer(playerTwo,screen,monster,monsterTwo,monsterThree));

						playerTwo.setX(playerTwo.getPX());
						playerTwo.setY(playerTwo.getPY());
					}
					else
						i++;					
				}
				//else if (i == 2 && playerTwo.iHealth < 0)
				//i++;
				else if (i == 4 && playerThree.iHealth > 0)
				{
					if (partyMode)
					{
						write("Z's Turn: ");
						myLoc =  static_cast<LOC>(movePlayer(playerThree,screen,monster,monsterTwo,monsterThree));

						playerThree.setX(playerThree.getPX());
						playerThree.setY(playerThree.getPY());
					}
					else
						i++;
				
				}
				else if (i == 1 && monster.iHealth > 0){
					Sleep(100);
					//monster.updateMonster();
					//monster.setPX(monster.getX());
					//monster.setPY(monster.getY());
					if (monster.moveMonster(player,playerTwo,playerThree))
						monster.updateMonster();
					
					//write(monster.getPX());
					//write(",");
					//write(monster.getPY());

					if ((monster.getPX() > 0 && monster.getPX() < 18 && monster.getPY() > 0 && monster.getPY() < 119) && !(player.getPX() == monster.getPX() && player.getPY() == monster.getPY()) && !screen.getWall(monster.getPX(),monster.getPY()) && !(monster.getPX() == monsterTwo.getPX() && monster.getPY() == monsterTwo.getPY()) && !(monster.getPX() == monsterThree.getPX() && monster.getPY() == monsterThree.getPY()))
					{
						monster.setX(monster.getPX());
						monster.setY(monster.getPY());
					}
					else
					{
						for (int a = 0; a <= 8; a++)
						{
							switch(screen.getCloseMeleeEnemy(monster.getX(),monster.getY(),player.getX(),player.getY(),playerTwo.getX(),playerTwo.getY(),playerThree.getX(),playerThree.getY(),player.iHealth,playerTwo.iHealth,playerThree.iHealth,a))
							{
							case 1:
								if (player.iHealth > 0)
								{
									a += 20;
									write("Enemy hits player1 for:");
									writel(5);
									player.iHealth -= 5;
									if (player.iHealth < 0)
									{
										writel("Player1 dies");
									}
								}
								Sleep(5000);
								break;
							case 2:
								if (playerTwo.iHealth > 0)
								{
									a += 20;
									write("Enemy hits player2 for:");
									writel(5);
									playerTwo.iHealth -= 5;
									if (playerTwo.iHealth < 0)
									{
										writel("Player2 dies");
									}
								}
								Sleep(5000);
								break;
							case 3:
								if (playerThree.iHealth > 0)
								{
									a += 20;
									write("Enemy hits player3 for:");
									writel(5);
									playerThree.iHealth -= 5;
									if (playerThree.iHealth < 0)
									{
										writel("Player3 dies");
									}
								}
								Sleep(5000);
								break;
							}
						}
						monster.setPX(monster.getX());
						monster.setPY(monster.getY());
					}
				}
				if (i == 3 && monsterTwo.iHealth > 0){
					Sleep(100);
					//monsterTwo.updateMonster();
					//monsterTwo.setPX(monsterTwo.getX());
					//monsterTwo.setPY(monsterTwo.getY());
					//writel("Running Monster 2");
					if (monsterTwo.moveMonster(player,playerTwo,playerThree))
					{
						monsterTwo.updateMonster();
						//Sleep(100);
					}

					//write(monsterTwo.getPX());
					//write(",");
					//write(monsterTwo.getPY());
					//if ((monster.getPX() > 0 && monster.getPX() < 18 && monster.getPY() > 0 && monster.getPY() < 119) && !(player.getPX() == monster.getPX() && player.getPY() == monster.getPY()) && !screen.getWall(monster.getPX(),monster.getPY()) && !(monster.getPX() == monsterTwo.getPX() && monster.getPY() == monsterTwo.getPY()) && !(monster.getPX() == monsterThree.getPX() && monster.getPY() == monsterThree.getPY()))
					if ((monsterTwo.getPX() > 0 && monsterTwo.getPX() < 18 && monsterTwo.getPY() > 0 && monsterTwo.getPY() < 119) && !(player.getPX() == monsterTwo.getPX() && player.getPY() == monsterTwo.getPY()) && !screen.getWall(monsterTwo.getPX(),monsterTwo.getPY()) && !(monsterTwo.getPX() == monster.getPX() && monsterTwo.getPY() == monster.getPY()) && !(monsterTwo.getPX() == monsterThree.getPX() && monsterTwo.getPY() == monsterThree.getPY()))
					{
						monsterTwo.setX(monsterTwo.getPX());
						monsterTwo.setY(monsterTwo.getPY());
						//writel("Running Monster 2");
						//Sleep(100);
					}
					else
					{
						for (int a = 0; a <= 8; a++)
						{
							switch(screen.getCloseMeleeEnemy(monsterTwo.getX(),monsterTwo.getY(),player.getX(),player.getY(),playerTwo.getX(),playerTwo.getY(),playerThree.getX(),playerThree.getY(),player.iHealth,playerTwo.iHealth,playerThree.iHealth,a))
							{
							case 1:
								if (player.iHealth > 0)
								{
									a += 20;
									write("Enemy hits player1 for:");
									writel(5);
									player.iHealth -= 5;
									if (player.iHealth < 0)
									{
										writel("Player1 dies");
									}
								}
								Sleep(5000);
								break;
							case 2:
								if (playerTwo.iHealth > 0)
								{
									a += 20;
									write("Enemy hits player2 for:");
									writel(5);
									playerTwo.iHealth -= 5;
									if (playerTwo.iHealth < 0)
									{
										writel("Player2 dies");
									}
								}
								Sleep(5000);
								break;
							case 3:
								if (playerThree.iHealth > 0)
								{
									a += 20;
									write("Enemy hits player3 for:");
									writel(5);
									playerThree.iHealth -= 5;
									if (playerThree.iHealth < 0)
									{
										writel("Player3 dies");
									}
								}
								Sleep(5000);
								break;
							}
						}
						monsterTwo.setPX(monsterTwo.getX());
						monsterTwo.setPY(monsterTwo.getY());
					}
				}
				if (i == 5 && monsterThree.iHealth > 0){
					Sleep(100);
					//monsterThree.updateMonster();
					//monsterThree.setPX(monsterThree.getX());
					//monsterThree.setPY(monsterThree.getY());
					if (monsterThree.moveMonster(player,playerTwo,playerThree))
					{
						monsterThree.updateMonster();
						//writel("Running Monster 3");
						//Sleep(9000);
					}
					//write(monsterThree.getPX());
					//write(",");
					//write(monsterThree.getPY());

					if ((monsterThree.getPX() > 0 && monsterThree.getPX() < 18 && monsterThree.getPY() > 0 && monsterThree.getPY() < 119) && !(player.getPX() == monsterThree.getPX() && player.getPY() == monsterThree.getPY()) && !screen.getWall(monsterThree.getPX(),monsterThree.getPY()) && !(monsterThree.getPX() == monsterTwo.getPX() && monsterThree.getPY() == monsterTwo.getPY()) && !(monsterThree.getPX() == monster.getPX() && monsterThree.getPY() == monster.getPY()))
					{
						//writel("Running Monster 3");
						//Sleep(9000);
						monsterThree.setX(monsterThree.getPX());
						monsterThree.setY(monsterThree.getPY());
					}
					else
					{
						for (int a = 0; a <= 8; a++)
						{
							switch(screen.getCloseMeleeEnemy(monsterThree.getX(),monsterThree.getY(),player.getX(),player.getY(),playerTwo.getX(),playerTwo.getY(),playerThree.getX(),playerThree.getY(),player.iHealth,playerTwo.iHealth,playerThree.iHealth,a))
							{
							case 1:
								if (player.iHealth > 0)
								{
									a += 20;
									write("Enemy hits player1 for:");
									writel(5);
									player.iHealth -= 5;
									if (player.iHealth < 0)
									{
										writel("Player1 dies");
									}
								}
								Sleep(5000);
								break;
							case 2:
								if (playerTwo.iHealth > 0)
								{
									a += 20;
									write("Enemy hits player2 for:");
									writel(5);
									playerTwo.iHealth -= 5;
									if (playerTwo.iHealth < 0)
									{
										writel("Player2 dies");
									}
								}
								Sleep(5000);
								break;
							case 3:
								if (playerThree.iHealth > 0)
								{
									a += 20;
									write("Enemy hits player3 for:");
									writel(5);
									playerThree.iHealth -= 5;
									if (playerThree.iHealth < 0)
									{
										writel("Player3 dies");
									}
								}
								Sleep(5000);
								break;
							}
						}
						monsterThree.setPX(monsterThree.getX());
						monsterThree.setPY(monsterThree.getY());
					}
				}
			}
			break;
		case STATS:
			writecl("");
			drawBar();
			writel("|What would you like to do?");
			write("|Damage: ");
			writel(player.iDmg);
			write("|Health: ");
			writel(player.iHealth);
			write("|Gold: ");
			writel(player.iGold);
			drawBar();
			writel("|Continue?");
			getCC();
			myLoc = TOWN;
			break;
		case FOREST:
			drawBar();
			//screen.updateLines(player.columnX,player.rowY,monster.columnX,monster.rowY,monsterTwo.columnX,monsterTwo.rowY,monsterThree.columnX,monsterThree.rowY);
			writel("|You are walking through the forest.");
			drawBar();
			Sleep(1000);
			drawBar();
			writel("|All of a sudden a wild ");
			switch((rand() % 9) + 1 )
			{
				//enum MON {POTATO,GOLBIN,JUSTIN,YOURSELF,SELFESTEEM,DRAGON};
			case 1:
			case 7:
			case 8:
				monster.iDmg = 1;
				monster.iHealth = 1;
				monster.iGold = 1;
				myMon = POTATO;
				writel("|Potato appears");
				break;
			case 2:
			case 9:
			case 10:
				monster.iDmg = 5;
				monster.iHealth = rand() % 5 + 2;
				monster.iGold = monster.iHealth - 1;
				myMon = GOBLIN;
				writel("|Goblin appears");
				break;
			case 3:
				monster.iDmg = 7;
				monster.iHealth = rand() % 10 + 2;
				monster.iGold = monster.iHealth - 1;
				myMon = JUSTIN;
				writel("|Justin appears");
				break;
			case 4:
				monster.iDmg = 11;
				monster.iHealth = rand() % 15 + 2;
				monster.iGold = monster.iHealth - 1;
				myMon = YOURSELF;
				writel("|You appear");
				break;
			case 5:
				monster.iDmg = 13;
				monster.iHealth = rand() % 25 + 2;
				monster.iGold = monster.iHealth - 1;
				myMon = SELFESTEEM;
				writel("|Self Esteem appears");
				break;
			case 6:
				monster.iDmg = 22;
				monster.iHealth = rand() % 30 + 2;
				monster.iGold = monster.iHealth - 1;
				myMon = DRAGON;
				writel("|Dragon appears");
				break;
			}
			writel("|}[1]Fight        [2]Run");
			drawBar();
			end = false;
			choice = getIC();
			if (choice == '1'){
				while(player.iHealth > 0 && !end){
					drawBar();
					write("|Your Health: ");
					writel(player.iHealth);
					write("|Thier Health: ");
					writel(monster.iHealth);
					writel("|}[1]Swing     [2]Defend");
					drawBar();
					choice = getIC();
					if (choice == '1'){
						int lostHealth = player.iDmg + ((player.iWeaponLvl + 2)*player.iStoredDamage);
						monster.iHealth -= lostHealth;
						write("|You deal :");
						writel(lostHealth);
						if (monster.iHealth <= 0){
							writel("|You have slain your oppenent");
							write("|You loot: ");
							writel(monster.iGold);
							player.iGold += monster.iGold;
							write("|Go back to town?");
							getCC();
							myLoc = TOWN;
							end = true;
							writecl("");
						}
						else{
							lostHealth = monster.iDmg;
							player.iHealth -= lostHealth;
							write("|You take :");
							writel(lostHealth);
						}
					}
					else
					{
						int lostHealth;
						player.iStoredDamage++;
						lostHealth = monster.iDmg - 2;
						player.iHealth -= lostHealth;
						write("|You take :");
						writel(lostHealth);
						if (player.iHealth <= 0)
						{
							writel("YOU DIED");
						}
					}
				}
			}
			if (!end)
			{
				write("|Going back to town?");
				getCC();
			}
			myLoc = TOWN;
			break;
		case SHOP:
			drawBar();
			write("|Your gold: ");
			writel(player.iGold);
			writel("|What would you like to buy?");
			switch(player.iWeaponLvl)
			{
			case 0:
				writel("|}[1]A sword: +1dmg 25g");
			case 1:
				writel("|}[2]Giant purple popsicle: +3dmg 50g");
			case 2:
				writel("|}[3]Mace of evil bunnys: +5dmg 100g");
				break;
			case 3:
				writel("Nothing to buy");
				break;
			}
			writel("|}[4]Leave");
			drawBar();
			writel("|What to do?");
			choice = getIC();
			switch(choice)
			{
			case '1':
				if (player.iGold >= 25)
				{
					player.iGold -= 25;
					player.iWeaponLvl = 1;
					writecl("|You have a new shiny sword");
				}
				else
				{
					myLoc = SHOP;
					writecl("|You poor fuck. Can't even aford a sword");
				}
				break;
			case '2':
				if (player.iGold >= 50)
				{
					player.iGold -= 50;
					player.iWeaponLvl = 2;
					writecl("|You have a new shiny popsicle");
				}
				else
				{
					myLoc = SHOP;
					writecl("|You poor fuck. Can't even aford a popsicle");
				}
				break;
			case '3':
				if (player.iGold >= 100)
				{
					player.iGold -= 100;
					player.iWeaponLvl = 3;
					writecl("|You have a new shiny mace");
				}
				else
				{
					myLoc = SHOP;
					writecl("|You poor fuck. Can't even aford a Mace");
				}
				break;
			case '4':
				myLoc = TOWN;
				break;
			default:
				myLoc = TOWN;
				break;
			}
			break;
		case SHOPPE:
			writecl("|Shoppe is a stupid fucking way to say shop. Going to shop instead asshole");
			myLoc = SHOP;
			break;
		case TAVERN:
			screen.getLoc(TAVERN);
			//writecl(getStoryLine(TOWN));
			//Sleep(5000);
			for (int i = 0; i < 6; i++)
			{
				screen.updateLines(player.columnX,player.rowY,playerTwo.columnX,playerTwo.rowY,playerThree.columnX,playerThree.rowY,monster.columnX,monster.rowY,monsterTwo.columnX,monsterTwo.rowY,monsterThree.columnX,monsterThree.rowY,monster.iHealth,monsterTwo.iHealth,monsterThree.iHealth);
				getCC();
			}
			break;
		default:
			writecl("");
			break;
		}
	}
	//kill = true;
	//while(kill){
	//}
	return 0;
}
////The update stuff
/*
case 'w':
if (player.getX() - 1 > 0)
player.setPX(player.getX() - 1);
break;
case 's':
if (player.getX() + 1 < 18)
player.setPX(player.getX() + 1);
break;
case 'a':
if (player.getY() - 1 > 0)
player.setPY(player.getY() - 1);
break;
case 'd':
if (player.getY() + 1 < 119)
player.setPY(player.getY() + 1);
break;
case 'W':
if (player.getX() - 1 > 0)
player.setPX(player.getX() - 1);
break;
case 'S':
if (player.getX() + 1 < 18)
player.setPX(player.getX() + 1);
break;
case 'A':
if (player.getY() - 1 > 0)
player.setPY(player.getY() - 1);
break;
case 'D':
if (player.getY() + 1 < 119)
player.setPY(player.getY() + 1);
break;
default:
writel("|Please press a key between 1-4");
break;
}
if (!screen.getWall(player.getPX(),player.getPY()) && !(player.getPX() == monster.getPX() && player.getPY() == monster.getPY()) && !(player.getPX() == monsterTwo.getPX() && player.getPY() == monsterTwo.getPY()) && !(player.getPX() == monsterThree.getPX() && player.getPY() == monsterThree.getPY()))
{
player.setX(player.getPX());
player.setY(player.getPY());
}
else if ((player.getPX() == monsterTwo.getPX() && player.getPY() == monsterTwo.getPY()) || (player.getPX() == monsterThree.getPX() && player.getPY() == monsterThree.getPY()) || (player.getPX() == monster.getPX() && player.getPY() == monster.getPY()))
{
myLoc = FOREST;
enemyCollision = true;
player.setPX(player.getX());
player.setPY(player.getY());
}
else
{
player.setPX(player.getX());
player.setPY(player.getY());
}
monster.updateMonster();
if ((monster.getPX() > 0 && monster.getPX() < 18 && monster.getPY() > 0 && monster.getPY() < 119) && !(player.getPX() == monster.getPX() && player.getPY() == monster.getPY()) && !screen.getWall(monster.getPX(),monster.getPY()) && !(monster.getPX() == monsterTwo.getPX() && monster.getPY() == monsterTwo.getPY()) && !(monster.getPX() == monsterThree.getPX() && monster.getPY() == monsterThree.getPY()))
{
monster.setX(monster.getPX());
monster.setY(monster.getPY());
}
else
{
monster.setPX(monster.getX());
monster.setPY(monster.getY());
}
monsterTwo.updateMonster();
if ((monsterTwo.getPX() > 0 && monsterTwo.getPX() < 18 && monsterTwo.getPY() > 0 && monsterTwo.getPY() < 119) && !(player.getPX() == monsterTwo.getPX() && player.getPY() == monsterTwo.getPY()) && !screen.getWall(monsterTwo.getPX(),monsterTwo.getPY()) && !(monsterTwo.getPX() == monster.getPX() && monsterTwo.getPY() == monster.getPY()) && !(monsterTwo.getPX() == monsterThree.getPX() && monsterTwo.getPY() == monsterThree.getPY()))
{
monsterTwo.setX(monsterTwo.getPX());
monsterTwo.setY(monsterTwo.getPY());
}
else
{
monsterTwo.setPX(monsterTwo.getX());
monsterTwo.setPY(monsterTwo.getY());
}
monsterThree.updateMonster();
if ((monsterThree.getPX() > 0 && monsterThree.getPX() < 18 && monsterThree.getPY() > 0 && monsterThree.getPY() < 119) && !(player.getPX() == monsterThree.getPX() && player.getPY() == monsterThree.getPY()) && !screen.getWall(monsterThree.getPX(),monsterThree.getPY()) && !(monsterThree.getPX() == monsterTwo.getPX() && monsterThree.getPY() == monsterTwo.getPY()) && !(monster.getPX() == monsterThree.getPX() && monster.getPY() == monsterThree.getPY()))
{
monsterThree.setX(monsterThree.getPX());
monsterThree.setY(monsterThree.getPY());
}
else
{
monsterThree.setPX(monsterThree.getX());
monsterThree.setPY(monsterThree.getY());
}
*/