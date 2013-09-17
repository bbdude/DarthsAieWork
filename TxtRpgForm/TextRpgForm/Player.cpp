#include <iostream>
#include "Player.h"
#include "stdafx.h"
using namespace std;

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
	rowY = 1;
	columnX = 1;
	rowPY = 1;
	columnPX = 1;
	iCharacter = 0;
	iDmg = 0;
	iHealth = 1;
	iHealthMax = 1;
	iGold = 10;
	iWeaponLvl = 0;
	iStoredDamage = 1;
}
void updateMonster()
{
	rowPY = rowY;
	columnPX = columnX;
	int temp = 1;// randomInt(4);
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