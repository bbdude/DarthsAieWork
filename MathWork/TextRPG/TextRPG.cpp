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
using namespace std;
using namespace System;
using namespace System::Text;
using namespace System::IO;

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
int getF()
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
struct PlayerStruct
{
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
	void updatePlayer()
	{
		
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
		writecl("");
		for(int i = 0; i <= windowSize; i++)
		{
			if (getLine(i).length() > 0){
				writebl(getLine(i));
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
	int getWindowSize(){ return windowSize;}
	void setWindowSize(int change){ windowSize = change;}
	string getLine(int which) { return line[which]; }
	bool getWall(int x,int y) { return wall[x][y]; }
	int getPortalX(int which) { return portalLocX[which]; }
	int getPortalY(int which) { return portalLocY[which]; }
};
int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	PlayerStruct player;
	PlayerStruct monster;
	PlayerStruct monsterTwo;
	PlayerStruct monsterThree;
	Screen screen;
	player.begin();
	monster.begin();
	monsterTwo.begin();
	monsterThree.begin();
	monster.setX(14);
	monster.setY(14);
	monsterTwo.setX(5);
	monsterTwo.setY(8);
	monsterThree.setX(17);
	monsterThree.setY(100);

	enum LOC {TEST,TOWN,STATS,FOREST,TAVERN,SHOP,QUIT,SHOPPE};
	enum MON {POTATO,GOBLIN,JUSTIN,YOURSELF,SELFESTEEM,DRAGON};
	LOC myLoc = TEST;
	MON myMon = POTATO;
	bool kill = true;
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

	while(kill){
		switch(myLoc){
			case TEST:
				drawBar();
				write(sayHello());
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
						writel("|Welcome to Seltreth Priest");
						break;
					case '2':
						writecl("");
						player.iHealth = (rand() % 20) + 1;
						player.iDmg = (rand() % 8) + 1;
						player.iCharacter = 2;
						writel("|Welcome to Seltreth Warrior");
						break;
					case '3':
						writecl("");
						player.iHealth = (rand() % 12) + 1;
						player.iDmg = (rand() % 12) + 1;
						player.iCharacter = 3;
						writel("|Welcome to Seltreth Rouge");
						break;
					case '4':
						writecl("");
						player.iHealth = (rand() % 666) + 1;
						player.iDmg = (rand() % 666) + 1;
						player.iCharacter = 4;
						writel("|Welcome to Seltreth God of Pain");
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
				screen.updateLines(player.columnX,player.rowY,monster.columnX,monster.rowY,monsterTwo.columnX,monsterTwo.rowY,monsterThree.columnX,monsterThree.rowY);
				//drawBar();
				writel("|What would you like to do?|");
				writel("|}}Locations:              |}}Commands:");
				writel("|}[p]Random People[f]Forest|[v]ViewStats");
				writel("|}[t]Tavern       [s]Shop  |[q]Quit");
				writel("|}[4]Shoppe                |");
				drawBar();
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
					default:
						writecl("");
						screen.getLoc(myLoc);
						myLoc = TOWN;
						break;
					}
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
				break;
			case STATS:
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
			default:
				writecl("");
				break;
		}
	}
	kill = true;
	while(kill){
		
	}
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