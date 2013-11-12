//////////////////////////////////////////////////////////////////////////
//	@Author:	Jacob Miller
//	@Date:	10/30/2013
//	@Brief:	File for the Bullet class
//  @Desc: Creates a Bullet that can be moved, drawn, and updated
//////////////////////////////////////////////////////////////////////////
#pragma once
#ifndef BULLET_H
#define BULLET_H


#include "AIE.h"
#include "KeyCodes.h"
#include "MenuItems.h"
#include "Vector.h"
#include <iostream>

//////////////////////////////////////////////////////////////////////////
/// <Bullet Class>
///
/// &Variables <Vector position,Vector angle,bool alive,int sprite,int width,int height>
//////////////////////////////////////////////////////////////////////////

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
	int getSprite() const;
	void updateBullet(Vector & angle,Vector & position,bool alive,int sprite) const;
	bool detectCollision(Vector objTwo,int heightT,int widthT);
	bool detectCollision(Vector position,Vector objTwo,int heightT,int widthT) const;
	void setBulletAngle(Vector player,Vector vMouse);
	void setBulletAngle(float playerx,float playery,Vector vMouse);
	void setAlive(bool change);
	bool getAlive();
	bool getAlive() const;
	void loadBullet();
	void drawBullet();
	void drawBullet() const;
	void endBullet();
	void setAll(Vector position,Vector angle,bool alive,int width,int height);
	void setAll(Bullet bullet);
	Vector getPosition() const;
	Vector getAngle() const;
private:
	mutable Vector position;
	mutable Vector angle;
	bool alive;
	int sprite;
	int width;
	int height;
};
#endif
