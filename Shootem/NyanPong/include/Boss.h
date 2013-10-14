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
	void setSpriteBar(int change);
	void setTime (int change);
	void loadBoss();
	void endBoss();
	void drawBoss();
	void updateBoss();
	void fireLasers();
	void lowerHealth(float change);
	bool moveWave();
	bool collideLasers(Vector position,int height,int width);
	int getHeight();
	int getWidth();
	int getSprite();
	int getTime();
	float getHealth();
	Vector getPosition();
private:
	Vector position;
	Vector plannedPosition;
	float health;
	int sprite;
	int spriteBar;
	int width;
	int height;
	int time;
	bool showing;
};

