//////////////////////////////////////////////////////////////////////////
//	@Author:	Jacob Miller
//	@Date:	10/30/2013
//	@Brief:	File for the Menu Items
//  @Desc: Creates a the images for certain menu and GUI objects
//////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "AIE.h"
#include "KeyCodes.h"
#include <string>

int getSprite(char choice);
void setSprite(char choice,int number);
void setTag(std::string change);
std::string drawStat(int lives);
std::string getTag();
void endItems();
bool getUp();
void setUp(bool change);