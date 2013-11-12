//////////////////////////////////////////////////////////////////////////
//	@Author:	Jacob Miller
//	@Date:	10/30/2013
//	@Brief:	File for the Boss class
//  @Desc: Creates a boss that has a static movement pattern
//////////////////////////////////////////////////////////////////////////
#pragma once
#include "AIE.h"
#include "KeyCodes.h"
#include "MenuItems.h"
#include "Vector.h"
#include <string>
#include "Bullet.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////////
/// <Boss Class>
///
/// &Variables <Bullet bullet[3],Vector position,Vector plannedPosition,Vector playerPosition,float health,int sprite,int spriteBar,int spriteDead,int width,int height,int time,bool showing,bool launch>
//////////////////////////////////////////////////////////////////////////
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
	void setLaunch (bool change);
	void loadBoss();
	void endBoss();
	void drawBoss();
	void updateBoss();
	void fireLasers();
	void lowerHealth(float change);
	void setPlayerPosition(Vector &player);
	bool moveWave();
	bool getLaunch();
	bool collideLasers(Vector position,int height,int width);
	bool collideBullets(Vector objTwo,int heightT,int widthT);
	int getHeight();
	int getWidth();
	int getSprite();
	int getTime();
	float getHealth();
	Vector getPosition();
private:
	Bullet bullet[3];
	Vector position;
	Vector plannedPosition;
	Vector playerPosition;
	float health;
	int sprite;
	int spriteBar;
	int spriteDead;
	int width;
	int height;
	int time;
	bool showing;
	bool launch;
};
