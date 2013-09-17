// array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

float Add(float numberOne, float numberTwo)
{
	return numberOne + numberTwo;
}
float Subtract(float numberOne, float numberTwo)
{
	return numberOne - numberTwo;
}
float Multiply(float numberOne, float numberTwo)
{
	return numberOne * numberTwo;
}
float Divide(float numberOne, float numberTwo)
{
	if (numberTwo == 0)
		return 0;
	return numberOne / numberTwo;
}
float Mod(int numberOne, int numberTwo)
{
	return numberOne % numberTwo;
}
void write(std::string word)
{
    std::cout << word;
}
void writel(std::string word)
{
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
struct myComparison
{
	bool operator() (int* lhs,int* rhs) { return (*lhs) < (*rhs);}
};

void drawAsciiMan(){
	writel("    0");
	writel("   -|-");
	writel("    /\\");
}
int iArrayRank[10];
int _tmain(int argc, _TCHAR* argv[])
{
	for (int i = 5; i > 0; i--)
		drawAsciiMan();
	
	writel("");
	writel("*************");
	writel("[1]Add");
	writel("[2]Subtract");
	writel("[3]Multiply");
	writel("[4]Divide");
	writel("[4]Mod");
	writel("*************");
	float numberOne, numberTwo;
	switch(getI()){
		case 1:
			writel("Input two numbers you would like to Add");
			numberOne = getF();
			numberTwo = getF();
			writel(Add(numberOne,numberTwo));
			break;
		case 2:
			writel("Input two numbers you would like to Subtract");
			numberOne = getF();
			numberTwo = getF();
			writel(Subtract(numberOne,numberTwo));
			break;
		case 3:
			writel("Input two numbers you would like to Mulitply");
			numberOne = getF();
			numberTwo = getF();
			writel(Multiply(numberOne,numberTwo));
			break;
		case 4:
			writel("Input two numbers you would like to Divide");
			numberOne = getF();
			numberTwo = getF();
			writel(Divide(numberOne,numberTwo));
			break;
		case 5:
			writel("Input two numbers you would like to Mod");
			numberOne = getF();
			numberTwo = getF();
			writel(Mod(numberOne,numberTwo));
			break;

	}
	int iScore[10];
	int iHealth[5];
	int iOHealth[5];
	int iTemp = 0;
	int iPlace = 0;
	int iArrayValue = 0;
	while(iArrayValue < 10)
	{
		iScore[iArrayValue] = rand() % 100;
		//writel(iScore[iArrayValue]);
		iArrayValue++;
	}
	iArrayValue = 0;
	while(iArrayValue < 5)
	{
		iHealth[iArrayValue] = 100;
		//writel(iScore[iArrayValue]);
		iArrayValue++;
	}
	iArrayValue = 0;
	while(iArrayValue < 5)
	{
		iOHealth[iArrayValue] = 100;
		//writel(iScore[iArrayValue]);
		iArrayValue++;
	}
	writel("");
	writel("*************");
	writel("Your Character stats");
	writel("[1]Priest (1-8dmg)");
	writel("[2]Warrior (1-20dmg)");
	writel("[3]Rouge (1-12dmg)");
	writel("[4]Satan (1-666dmg)");
	writel("*************");
	writel("Continue?");
	getC();
	int iTurn = 0;
	int iCharacter = 0;
	bool kill = true;
	system("cls");
	while (iHealth[1] > 0 &&iHealth[2] > 0 &&iHealth[3] > 0 &&iHealth[4] > 0 && iTurn <= 4)
	{
		iTurn++;
		int iDmg = 0;
		writel("*************");
		write("Your Priests Health: ");
		writel(iHealth[1]);
		write("Your Warriors Health: ");
		writel(iHealth[2]);
		write("Your Rouges Health: ");
		writel(iHealth[3]);
		write("Your Gods Health: ");
		writel(iHealth[4]);
		writel("*************");
		writel("Who to swing at? [1]Priest[2]Warrior[3]Rouge[4]Satan");
		kill = true;
		while(kill){
			switch(getI()){
			case 1:
				iDmg = (rand() % 8) + 1;
				iCharacter = 1;
				kill = false;
				break;
			case 2:
				iDmg = (rand() % 20) + 1;
				iCharacter = 2;
				kill = false;
				break;
			case 3:
				iDmg = (rand() % 12) + 1;
				iCharacter = 3;
				kill = false;
				break;
			case 4:
				iDmg = (rand() % 666) + 1;
				iCharacter = 4;
				kill = false;
				break;
			default:
				writel("Go to hell. You are pressing a key between 1 and 4 now bitch!!");
				break;
			}
		}
		system("cls");
		write("You swing with your weapon and deal ");
		writel(iDmg);
		iOHealth[iCharacter] -= iDmg;
		if (iOHealth[0] <= 0 && iOHealth[1] <= 0 && iOHealth[2] <= 0 && iOHealth[3] <= 0)
		{
			writel("You have slain all the opponents");
			break;
		}
		writel("");
		iDmg = (rand() % 10) + 1;
		
		writel("*************");
		write("Thier Priests Health: ");
		writel(iOHealth[1]);
		write("Thier Warriors Health: ");
		writel(iOHealth[2]);
		write("Thier Rouges Health: ");
		writel(iOHealth[3]);
		write("Satan Health: ");
		writel(iOHealth[4]);
		writel("*************");
		write("They swing at your ");
		switch(rand() % 4)
		{
			case 1:
				write("Priest");
				iHealth[1] -= iDmg;
				break;
			case 2:
				write("Warrior");
				iHealth[2] -= iDmg;
				break;
			case 3:
				write("Rouge");
				iHealth[3] -= iDmg;
				break;
			case 4:
				write("God");
				iHealth[4] -= iDmg;
				break;
		}
		write(" for ");
		writel(iDmg);
	}
	writel("The match has ended");
	/*
	for (int i = 9; i > 0; i--)
	{
		for (int n = 9; n > 0; n--)
		{
			if (iScore[n] < iScore[i])
			{
				iTemp = iScore[i];
				if (iTemp == 0)
					//writel(iTemp);
				iScore[i] = iScore[n];
				iScore[n] = iTemp;
			}
		}
	}
	
	writel("");
	for (int i = 9; i > 0; i--)
		writel(iScore[i]);
	*/
	system("pause");
	return 0;
}

