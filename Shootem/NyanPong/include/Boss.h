#pragma once
#include "AIE.h"
#include "KeyCodes.h"
#include "MenuItems.h"
#include "Vector.h"
#include <string>
#include <cmath>
#include <assert.h>
#include <crtdbg.h>
#include <ctime>
#include <iostream>
#include <list>

class Boss
{
public:
	Boss(void);
	~Boss(void);
	void setHeight(int change);
	void setWidth(int change);
	void setSprite(int change);
	void setTime (int change);
	void loadBoss();
	void endBoss();
	void drawBoss();
	void updateBoss();
	bool moveWave();
	int getHeight();
	int getWidth();
	int getSprite();
	int getTime();
	int getHealth();
private:
	Vector position;
	Vector plannedPosition;
	int health;
	int sprite;
	int width;
	int height;
	int time;
	bool showing;
};

