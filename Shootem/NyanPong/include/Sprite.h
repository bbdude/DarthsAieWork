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
	int getHeight();
	int getWidth();
	int getSprite();
	int getTime();
	int getInv();
	float getPositionX();
	float getPositionY();
	float getSpeedX();
	float getSpeedY();
	bool detectCollision(Vector objTwo,int heightT,int widthT);
	bool detectCollisionA(Vector objTwo,int heightT,int widthT);
	bool detectCollisionR(Vector objTwo,int heightT,int widthT);
	bool getAlive();
	bool getFire();
	void setTag(std::string change);
	void setTime(int change);
	void setFire(bool change);
	void setHeight(int change);
	void setWidth(int change);
	void setSprite(int change);
	void setInv(int change);
	void setBulletAngle(Vector player,Vector vMouse);
	void setAlive(bool change);
	void updateSprite();
	void loadSprite();
	void drawSprite();
	void endSprite();
	void setPositionX(float change);
	void setPositionY(float change);
	void setPosition(float c,float v);
	void setPosition(Vector change);
	void setSpeedX(float change);
	void setSpeedY(float change);
	void setSpeed(float c,float v);
	void setSpeed(Vector change);
	void updateBeam(Vector player);
	void moveTarget(Vector change);
	Vector getPosition();
	Vector getSpeed();
	std::string getTag();

	Vector position;
	Vector speed;
	bool lineBeam;
private:
	Vector angle;
	bool alive;
	bool fire;
	int sprite;
	int width;
	int height;
	int invTimer;
	std::string tag;
	int time;
};
#endif