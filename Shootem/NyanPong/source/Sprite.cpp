#include "Sprite.h"
#include <iostream>

Sprite::Sprite(void)
{
}
Sprite::Sprite(bool aAlive,bool aFire,int aWidth, int aHeight,int aInvTimer,std::string aTag,int aTime,float x,float y)
{
	if (aAlive != NULL)
		alive = aAlive;
	if (aFire != NULL)
		fire = aFire;
	if (aWidth != NULL)
		width = aWidth;
	if (aHeight != NULL)
		height = aHeight;
	if (aInvTimer != NULL)
		invTimer = aInvTimer;
	tag = aTag;
	if (aTime != NULL)
		time = aTime;
	if (x != NULL)
		position.vectorSetX(x);
	if (y != NULL)
		position.vectorSetY(y);
}

Sprite::~Sprite(void)
{
}
void   Sprite::setAlive(bool change)
{
	alive = change;
}
bool   Sprite::getAlive()
{
	return alive;
}
void   Sprite::setHeight(int change)
{
	height = change;
}
void   Sprite::setWidth(int change)
{
	width = change;
}
int    Sprite::getHeight()
{
	return height;
}
int    Sprite::getWidth()
{
	return width;
}
void   Sprite::setSprite(int change)
{
	sprite = change;
}
int    Sprite::getSprite()
{
	return sprite;
}
bool   Sprite::detectCollision(Vector objTwo,int heightT,int widthT)
{
	if(position.getVectorX() >= objTwo.getVectorX() - (widthT/2) && position.getVectorX() <= objTwo.getVectorX() + (widthT/2)
		&& position.getVectorY() >= objTwo.getVectorY() - (heightT/2)&& position.getVectorY() <= objTwo.getVectorY() + (heightT/2))
	{
		return false;
	}
	return true;
}
bool   Sprite::detectCollisionR(Vector objTwo,int heightT,int widthT)
{
	if(position.getVectorX() >= objTwo.getVectorX() - (widthT/2) && position.getVectorX() <= objTwo.getVectorX() + (widthT/2)
		&& position.getVectorY() >= objTwo.getVectorY() - (heightT/2)&& position.getVectorY() <= objTwo.getVectorY() + (heightT/2))
	{
		return false;
	}
	return true;
}
bool   Sprite::detectCollisionA(Vector objTwo,int heightT,int widthT)
{
	if(position.getVectorX() >= objTwo.getVectorX() - (widthT/2) && position.getVectorX() <= objTwo.getVectorX() + (widthT/2)
		&& position.getVectorY() >= objTwo.getVectorY() - (heightT/2)&& position.getVectorY() <= objTwo.getVectorY() + (heightT/2) && alive)
	{
		return false;
	}
	return true;
}
void   Sprite::loadSprite()
{
	sprite = CreateSprite( "./images/bomb.png",width, height, true );
}
void   Sprite::loadSprite(bool aAlive,bool aFire,int aWidth, int aHeight,int aInvTimer,std::string aTag,int aTime,float x,float y)
{
	if (aAlive != NULL)
		alive = aAlive;
	if (aFire != NULL)
		fire = aFire;
	if (aWidth != NULL)
		width = aWidth;
	if (aHeight != NULL)
		height = aHeight;
	if (aInvTimer != NULL)
		invTimer = aInvTimer;
	tag = aTag;
	if (aTime != NULL)
		time = aTime;
	if (x != NULL)
		position.vectorSetX(x);
	if (y != NULL)
		position.vectorSetY(y);
}
void   Sprite::updateSprite()
{
	MoveSprite(sprite,(int)position.getVectorX(),(int)position.getVectorY());
}
void   Sprite::endSprite()
{
	DestroySprite(sprite);
}
void   Sprite::drawSprite()
{
	DrawSprite(sprite);
}
bool   Sprite::getFire()
{
	return fire;
}
void   Sprite::setFire(bool change)
{
	fire = change;
}
std::string Sprite::getTag()
{
	return tag;
}
void   Sprite::setTag(std::string change)
{
	tag = change;
}
int    Sprite::getTime()
{
	return time;
}
void   Sprite::setTime(int change)
{
	time = change;
}
Vector Sprite::getPosition()
{
	return position;
}
Vector Sprite::getSpeed()
{
	return speed;
}
void   Sprite::setPositionX(float change)
{
	position.vectorSetX(change);
}
void   Sprite::setPositionY(float change)
{
	position.vectorSetY(change);
}
void   Sprite::setPosition(float c,float v)
{
	position.vectorSet(c,v);
}
void   Sprite::setPosition(Vector change)
{
	position.vectorSet(change);
}
void   Sprite::setSpeedX(float change)
{
	speed.vectorSetX(change);
}
void   Sprite::setSpeedY(float change)
{
	speed.vectorSetY(change);
}
void   Sprite::setSpeed(float c,float v)
{
	speed.vectorSet(c,v);
}
void   Sprite::setSpeed(Vector change)
{
	speed.vectorSet(change);
}
void   Sprite::setInv(int change)
{
	invTimer = change;
}
int    Sprite::getInv()
{
	return invTimer;
}
float  Sprite::getPositionX()
{
	return position.getVectorX();
}
float  Sprite::getPositionY()
{
	return position.getVectorY();
}
float  Sprite::getSpeedX()
{
	return speed.getVectorX();
}
float  Sprite::getSpeedY()
{
	return speed.getVectorY();
}
void   Sprite::updateBeam(Vector player)
{
	if (getTime() >= 0)
	{
		position.vectorSet(player.getVectorX(),player.getVectorY() - (getHeight()/2) + 5);
		//time--;
	}
	else
	{
		alive = false;
		position.vectorSet(-1000,-1000);
	}
}
void   Sprite::moveTarget(Vector change)
{
	MoveSprite(sprite, (int)change.getVectorX(), (int)change.getVectorY());
}