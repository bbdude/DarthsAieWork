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
	virtual void setHeight(int change);
	virtual void setWidth(int change);
	virtual void setSprite(int change);
	virtual void setSpriteBar(int change);
	virtual void setTime (int change);
	virtual void setLaunch (bool change);
	virtual void loadBoss();
	virtual void endBoss();
	virtual void drawBoss();
	virtual void updateBoss();
	virtual void fireLasers();
	virtual void lowerHealth(float change);
	virtual void setPlayerPosition(Vector &player);
	virtual bool moveWave();
	virtual bool getLaunch();
	virtual bool collideLasers(Vector position,int height,int width);
	virtual bool collideBullets(Vector objTwo,int heightT,int widthT);
	virtual int getHeight();
	virtual int getWidth();
	virtual int getSprite();
	virtual int getTime();
	virtual float getHealth();
	virtual Vector getPosition();
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
