#pragma once
#ifndef SPRITE_H
#define SPRITE_H
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

class Sprite
{
public:
	Sprite(void);
	~Sprite(void);
	void setHeight(int change);
	void setWidth(int change);
	int getHeight();
	int getWidth();
	void setSprite(int change);
	int getSprite();
	void updateSprite();
	bool detectCollision(Vector objTwo,int heightT,int widthT);
	void setBulletAngle(Vector player,Vector vMouse);
	void setAlive(bool change);
	bool getAlive();
	void loadSprite();
	void drawSprite();
	void endSprite();
private:
	Vector position;
	Vector angle;
	Vector speed;
	bool alive;
	bool fire;
	int sprite;
	int width;
	int height;
	std::string tag;
	int time;
};
#endif