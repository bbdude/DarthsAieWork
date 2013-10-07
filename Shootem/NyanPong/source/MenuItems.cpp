#include <iostream>
#include "MenuItems.h"

int iWin = -1;
int iLose = -1;
int iLeave = -1;
int iPlay = -1;

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
	}
}