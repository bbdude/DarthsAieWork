//////////////////////////////////////////////////////////////////////////
//	@Author:	Jacob Miller
//	@Date:	10/30/2013
//	@Brief:	File for the Sprite class
//  @Desc: Creates a Sprite that can be moved, drawn, and updated
//////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include "AIE.h"
#include "KeyCodes.h"
#include "MenuItems.h"
#include "Vector.h"
#include <string>
#include <iostream>

//////////////////////////////////////////////////////////////////////////
/// <Sprite Class>
///
/// &Variables <Vector angle,bool alive,bool fire,int sprite,int width,int height,int invTimer,std::string tag,int time>
//////////////////////////////////////////////////////////////////////////
class Sprite
{
public:
	Sprite(void);
	Sprite(bool aAlive,bool aFire,int aWidth, int aHeight,int aInvTimer,std::string aTag,int aTime,float x,float y);
	~Sprite(void);
	int getHeight();
	int getWidth();
	int getHeight() const;
	int getWidth() const;
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
	bool getAlive() const;
	bool getFire();
	void setTag(std::string change);
	void setTime(int change);
	void setFire(bool change);
	void setHeight(int change);
	void setWidth(int change);
	void setHeight(int change)const;
	void setWidth(int change)const;
	void setSprite(int change);
	void setSprite(int change) const;
	void setInv(int change);
	void setBulletAngle(Vector player,Vector vMouse);
	void setAlive(bool change);
	void updateSprite();
	void updateSprite() const;
	void loadSprite();
	void loadSprite(bool aAlive,bool aFire,int aWidth, int aHeight,int aInvTimer,std::string aTag,int aTime,float x,float y);
	void loadSprite(bool aAlive,bool aFire,int aWidth, int aHeight,std::string aTag,int aTime,float x,float y) const;
	void loadSprite(Sprite sprite) const;
	void drawSprite();
	void drawSprite() const;
	void endSprite();
	void endSprite() const;
	void setPositionX(float change);
	void setPositionY(float change);
	void setPosition(float c,float v);
	void setPosition(Vector change);
	void setSpeedX(float change);
	void setSpeedY(float change);
	void setSpeed(float c,float v);
	void setSpeed(float c,float v) const;
	void setSpeed(Vector change);
	void setSpeed(Vector change) const;
	void updateBeam(Vector player);
	void moveTarget(Vector change);
	Vector getPosition();
	Vector getPosition() const;
	Vector getSpeed();
	std::string getTag();
	std::string getTag() const;

	mutable Vector position;
	mutable Vector speed;
	bool lineBeam;
private:
	Vector angle;
	mutable bool alive;
	mutable bool fire;
	mutable int sprite;
	mutable int width;
	mutable int height;
	int invTimer;
	mutable std::string tag;
	mutable int time;
};
#endif
/*

player1.setHeight(5);
player1.setSprite(-1);
player1.setWidth(5);
player1.setSpeed(1,1);
player1.setPosition(500,300);
player1.setTag("BASIC");
setTag("BASIC");
player1.setInv(0);

target.setAlive(true);
target.setHeight(50);
target.setSprite(-1);
target.setWidth(50);
target.setSpeed(0,0);
target.setPosition(0,0);

screen.height = 780;
screen.width = 3840;
screen.position.vectorSet(0,0);
screen.speed.vectorSet(0,0.05f);
screen.sprite = -1;
screenTwo.height = 780;
screenTwo.width = 3840;
screenTwo.position.vectorSet(0,0);
screenTwo.speed.vectorSet(0,0.05f);
screenTwo.sprite = -1;

vScreen.vectorSet(1280,780);

vMouse.vectorSet(0,0);

healthIcon.setAlive(true);
healthIcon.setHeight(52);
healthIcon.setPosition(200,50);
healthIcon.setSprite(-1);
healthIcon.setWidth(52);

beam.setAlive(false);
beam.setFire(false);
beam.setHeight(780);
beam.setWidth(100);
beam.setPosition(-1000,-1000);
beam.setSprite(-1);
beam.setWidth(100);
beam.setTime(0);

powerUp.setAlive(false);
powerUp.setHeight(100);
powerUp.setWidth(100);
powerUp.setPosition(0,0);



*/