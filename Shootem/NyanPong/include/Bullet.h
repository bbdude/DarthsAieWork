#pragma once
#ifndef BULLET_H
#define BULLET_H
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

class Bullet
{
public:
	Bullet(void);
	~Bullet(void);
	void setHeight(int change);
	void setWidth(int change);
	int getHeight();
	int getWidth();
	void setSprite(int change);
	int getSprite();
	void updateBullet();
	bool detectCollision(Vector objTwo,int heightT,int widthT);
	void setBulletAngle(Vector player,Vector vMouse);
	void setBulletAngle(float playerx,float playery,Vector vMouse);
	void setAlive(bool change);
	bool getAlive();
	void loadBullet();
	void drawBullet();
	void endBullet();
private:
	Vector position;
	Vector angle;
	bool alive;
	int sprite;
	int width;
	int height;
};
#endif
