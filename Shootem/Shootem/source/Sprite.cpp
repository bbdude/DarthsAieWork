#include "Sprite.h"
#include <iostream>

Sprite::Sprite(void)
{
}
Sprite::Sprite(bool aAlive,bool aFire,int aWidth, int aHeight,int aInvTimer,std::string aTag,int aTime,float x,float y)
{
	alive = aAlive;
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

//////////////////////////////////////////////////////////////////////////
/// <sets the alive>
///
/// @param  bool
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::setAlive(bool change)
{
	alive = change;
}

//////////////////////////////////////////////////////////////////////////
/// <gets if its alive>
///
/// @param  N/A
/// @return bool
//////////////////////////////////////////////////////////////////////////
bool   Sprite::getAlive()
{
	return alive;
}
bool   Sprite::getAlive() const
{
	return alive;
}

//////////////////////////////////////////////////////////////////////////
/// <sets the height>
///
/// @param  int
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::setHeight(int change)
{
	height = change;
}

//////////////////////////////////////////////////////////////////////////
/// <sets the width>
///
/// @param  int
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::setWidth(int change)
{
	width = change;
}
void   Sprite::setWidth(int change) const
{
	width = change;
}

//////////////////////////////////////////////////////////////////////////
/// <gets the height>
///
/// @param  N/A
/// @return int
//////////////////////////////////////////////////////////////////////////
int    Sprite::getHeight()
{
	return height;
}
int    Sprite::getHeight() const
{
	return height;
}

//////////////////////////////////////////////////////////////////////////
/// <gets the width>
///
/// @param  N/A
/// @return int
//////////////////////////////////////////////////////////////////////////
int    Sprite::getWidth()
{
	return width;
}
int    Sprite::getWidth() const
{
	return width;
}

//////////////////////////////////////////////////////////////////////////
/// <sets the sprite>
///
/// @param  int
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::setSprite(int change)
{
	sprite = change;
}
void   Sprite::setSprite(int change) const
{
	sprite = change;
}

//////////////////////////////////////////////////////////////////////////
/// <gets the sprite>
///
/// @param  N/A
/// @return int
//////////////////////////////////////////////////////////////////////////
int    Sprite::getSprite()
{
	return sprite;
}

//////////////////////////////////////////////////////////////////////////
/// <detects collision>
///
/// @param  vector,int,int
/// @return bool
//////////////////////////////////////////////////////////////////////////
bool   Sprite::detectCollision(Vector objTwo,int heightT,int widthT)
{
	if(position.getVectorX() >= objTwo.getVectorX() - (widthT/2) && position.getVectorX() <= objTwo.getVectorX() + (widthT/2)
		&& position.getVectorY() >= objTwo.getVectorY() - (heightT/2)&& position.getVectorY() <= objTwo.getVectorY() + (heightT/2))
	{
		return false;
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
/// <detects collision>
///
/// @param  vector,int,int
/// @return bool
//////////////////////////////////////////////////////////////////////////
bool   Sprite::detectCollisionR(Vector objTwo,int heightT,int widthT)
{
	if(position.getVectorX() >= objTwo.getVectorX() - (widthT/2) && position.getVectorX() <= objTwo.getVectorX() + (widthT/2)
		&& position.getVectorY() >= objTwo.getVectorY() - (heightT/2)&& position.getVectorY() <= objTwo.getVectorY() + (heightT/2))
	{
		return false;
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
/// <detects collision and if its alive>
///
/// @param  vector,int,int
/// @return bool
//////////////////////////////////////////////////////////////////////////
bool   Sprite::detectCollisionA(Vector objTwo,int heightT,int widthT)
{
	if ((objTwo.getVectorX() >= position.getVectorX() - (width/2)) && (objTwo.getVectorX() <= position.getVectorX() + (width/2)))// && alive)
		return false;
	return true;
}

//////////////////////////////////////////////////////////////////////////
/// <loads the spirte>
///
/// @param  N/A
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::loadSprite()
{
	sprite = CreateSprite( "./images/bomb.png",width, height, true );
}

//////////////////////////////////////////////////////////////////////////
/// <loads the spirte>
///
/// @param  bool,bool,int,int,int,string,int,float,float
/// @return void
//////////////////////////////////////////////////////////////////////////
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
void   Sprite::loadSprite(bool aAlive,bool aFire,int aWidth, int aHeight,std::string aTag,int aTime,float x,float y) const
{
	if (aAlive != NULL)
		alive = aAlive;
	if (aFire != NULL)
		fire = aFire;
	if (aWidth != NULL)
		width = aWidth;
	if (aHeight != NULL)
		height = aHeight;
	tag = aTag;
	if (aTime != NULL)
		time = aTime;
	if (x != NULL)
		position.vectorSetX(x);
	if (y != NULL)
		position.vectorSetY(y);
}
//////////////////////////////////////////////////////////////////////////
/// <update the sprites posiition>
///
/// @param  N/A
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::updateSprite()
{
	MoveSprite(sprite,(int)position.getVectorX(),(int)position.getVectorY());
}
void   Sprite::updateSprite() const
{
	this->position.vectorSetX(this->position.getVectorX() + this->speed.getVectorX());
	this->position.vectorSetY(this->position.getVectorY() + this->speed.getVectorY());
	MoveSprite(sprite,(int)this->position.getVectorX(),(int)this->position.getVectorY());
	//MoveSprite(sprite,(int)position.getVectorX(),(int)position.getVectorY());
}

//////////////////////////////////////////////////////////////////////////
/// <destroys the sprite and all the data>
///
/// @param  N/A
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::endSprite()
{
	DestroySprite(sprite);
}
void   Sprite::endSprite() const
{
	DestroySprite(sprite);
}

//////////////////////////////////////////////////////////////////////////
/// <draws the sprite>
///
/// @param  N/A
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::drawSprite()
{
	DrawSprite(sprite);
}
void   Sprite::drawSprite() const
{
	DrawSprite(sprite);
}

//////////////////////////////////////////////////////////////////////////
/// <gets fire>
///
/// @param  N/A
/// @return bool
//////////////////////////////////////////////////////////////////////////
bool   Sprite::getFire()
{
	return fire;
}

//////////////////////////////////////////////////////////////////////////
/// <sets the fire>
///
/// @param  bool
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::setFire(bool change)
{
	fire = change;
}

//////////////////////////////////////////////////////////////////////////
/// <gets the tag>
///
/// @param  N/A
/// @return string
//////////////////////////////////////////////////////////////////////////
std::string Sprite::getTag()
{
	return tag;
}
std::string Sprite::getTag() const
{
	return tag;
}

//////////////////////////////////////////////////////////////////////////
/// <sets the tag>
///
/// @param  string
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::setTag(std::string change)
{
	tag = change;
}

//////////////////////////////////////////////////////////////////////////
/// <gets the time>
///
/// @param  N/A
/// @return int
//////////////////////////////////////////////////////////////////////////
int    Sprite::getTime()
{
	return time;
}

//////////////////////////////////////////////////////////////////////////
/// <sets the time>
///
/// @param  int
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::setTime(int change)
{
	time = change;
}

//////////////////////////////////////////////////////////////////////////
/// <gets the position>
///
/// @param  N/A
/// @return vector
//////////////////////////////////////////////////////////////////////////
Vector Sprite::getPosition()
{
	return position;
}
Vector Sprite::getPosition() const
{
	return position;
}

//////////////////////////////////////////////////////////////////////////
/// <gets the speed>
///
/// @param  N/A
/// @return vector
//////////////////////////////////////////////////////////////////////////
Vector Sprite::getSpeed()
{
	return speed;
}

//////////////////////////////////////////////////////////////////////////
/// <sets the positionX>
///
/// @param  float
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::setPositionX(float change)
{
	position.vectorSetX(change);
}

//////////////////////////////////////////////////////////////////////////
/// <sets the positionY>
///
/// @param float
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::setPositionY(float change)
{
	position.vectorSetY(change);
}

//////////////////////////////////////////////////////////////////////////
/// <sets the position>
///
/// @param  float,float
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::setPosition(float c,float v)
{
	position.vectorSet(c,v);
}

//////////////////////////////////////////////////////////////////////////
/// <sets the position>
///
/// @param  vector
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::setPosition(Vector change)
{
	position.vectorSet(change);
}

//////////////////////////////////////////////////////////////////////////
/// <sets the speedX>
///
/// @param  float
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::setSpeedX(float change)
{
	speed.vectorSetX(change);
}

//////////////////////////////////////////////////////////////////////////
/// <sets the speedY>
///
/// @param  float
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::setSpeedY(float change)
{
	speed.vectorSetY(change);
}

//////////////////////////////////////////////////////////////////////////
/// <sets the speed>
///
/// @param  float,float
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::setSpeed(float c,float v)
{
	speed.vectorSet(c,v);
}
void   Sprite::setSpeed(float c,float v) const
{
	speed.vectorSet(c,v);
}

//////////////////////////////////////////////////////////////////////////
/// <sets the speed>
///
/// @param  vector
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::setSpeed(Vector change)
{
	speed.vectorSet(change);
}
void   Sprite::setSpeed(Vector change) const
{
	speed.vectorSet(change);
}

//////////////////////////////////////////////////////////////////////////
/// <sets the invicibility>
///
/// @param  int
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::setInv(int change)
{
	invTimer = change;
}

//////////////////////////////////////////////////////////////////////////
/// <gets the invicibility>
///
/// @param  N/A
/// @return int
//////////////////////////////////////////////////////////////////////////
int    Sprite::getInv()
{
	return invTimer;
}

//////////////////////////////////////////////////////////////////////////
/// <gets the positionX>
///
/// @param  N/A
/// @return float
//////////////////////////////////////////////////////////////////////////
float  Sprite::getPositionX()
{
	return position.getVectorX();
}

//////////////////////////////////////////////////////////////////////////
/// <gets the positionY>
///
/// @param  N/A
/// @return float
//////////////////////////////////////////////////////////////////////////
float  Sprite::getPositionY()
{
	return position.getVectorY();
}

//////////////////////////////////////////////////////////////////////////
/// <gets the speedX>
///
/// @param  N/A
/// @return float
//////////////////////////////////////////////////////////////////////////
float  Sprite::getSpeedX()
{
	return speed.getVectorX();
}

//////////////////////////////////////////////////////////////////////////
/// <gets the speedY>
///
/// @param  N/A
/// @return float
//////////////////////////////////////////////////////////////////////////
float  Sprite::getSpeedY()
{
	return speed.getVectorY();
}

//////////////////////////////////////////////////////////////////////////
/// <updates the beam if it alive and time is above 0>
///
/// @param  vector
/// @return void
//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////
/// <moves and object to a vector>
///
/// @param  vector
/// @return void
//////////////////////////////////////////////////////////////////////////
void   Sprite::moveTarget(Vector change)
{
	MoveSprite(sprite, (int)change.getVectorX(), (int)change.getVectorY());
}