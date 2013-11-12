#include "Bullet.h"
#include <iostream>

Bullet::Bullet(void)
{
}
Bullet::~Bullet(void)
{
}

void Bullet::setAll(Vector position,Vector angle,bool alive,int width,int height)
{
	this->position = position;
	this->angle = angle;
	this->alive = alive;
	this->width = width;
	this->height = height;
}
void Bullet::setAll(Bullet bullet)
{
	this->position = bullet.position;
	this->angle = bullet.angle;
	this->alive = bullet.alive;
	this->width = bullet.width;
	this->height = bullet.height;
	//this->sprite = DuplicateSprite( bullet.sprite );
	this->sprite = bullet.sprite;
}
//////////////////////////////////////////////////////////////////////////
/// <Sets alive>
///
/// @param  bool
/// @return void
//////////////////////////////////////////////////////////////////////////
void Bullet::setAlive(bool change)
{
	alive = change;
}

//////////////////////////////////////////////////////////////////////////
/// <gets alive>
///
/// @param  N/A
/// @return bool
//////////////////////////////////////////////////////////////////////////
bool Bullet::getAlive()
{
	return alive;
}
bool Bullet::getAlive() const
{
	return alive;
}

//////////////////////////////////////////////////////////////////////////
/// <Sets height>
///
/// @param  int
/// @return void
//////////////////////////////////////////////////////////////////////////
void Bullet::setHeight(int change)
{
	height = change;
}

//////////////////////////////////////////////////////////////////////////
/// <Sets width>
///
/// @param  int
/// @return void
//////////////////////////////////////////////////////////////////////////
void Bullet::setWidth(int change)
{
	width = change;
}

//////////////////////////////////////////////////////////////////////////
/// <gets height>
///
/// @param  N/A
/// @return int
//////////////////////////////////////////////////////////////////////////
int Bullet::getHeight()
{
	return height;
}

//////////////////////////////////////////////////////////////////////////
/// <gets width>
///
/// @param  N/A
/// @return int
//////////////////////////////////////////////////////////////////////////
int Bullet::getWidth()
{
	return width;
}

//////////////////////////////////////////////////////////////////////////
/// <Sets sprite>
///
/// @param  int
/// @return void
//////////////////////////////////////////////////////////////////////////
void Bullet::setSprite(int change)
{
	sprite = change;
}

//////////////////////////////////////////////////////////////////////////
/// <gets sprite>
///
/// @param  N/A
/// @return int
//////////////////////////////////////////////////////////////////////////
int Bullet::getSprite()
{
return sprite;
}
int Bullet::getSprite() const
{
return sprite;
}

//////////////////////////////////////////////////////////////////////////
/// <updates bullets position, checks if it should be alive or not>
///
/// @param  N/A
/// @return void
//////////////////////////////////////////////////////////////////////////
void Bullet::updateBullet(Vector &angle,Vector &position,bool alive,int sprite) const
{
	//if (position.getVectorX() < 0 || position.getVectorX()  > 1280 || position.getVectorY()  < 0 || position.getVectorY() > 780)
	//{
	//	alive = false;
	//	position.vectorSetX(-1000);
	//	position.vectorSetY(-1000);
	//}
	//position += angle;
	//position.operator+=
	//position.vectorAdd(this->position,this->angle);
	this->position.vectorSetX(this->position.getVectorX() + this->angle.getVectorX());
	this->position.vectorSetY(this->position.getVectorY() + this->angle.getVectorY());

	MoveSprite(sprite,(int)this->position.getVectorX(),(int)this->position.getVectorY());
}

//////////////////////////////////////////////////////////////////////////
/// <checks collision>
///
/// @param  Vector,int,int
/// @return bool (false for collide, true for not collision)
//////////////////////////////////////////////////////////////////////////
bool Bullet::detectCollision(Vector objTwo,int heightT,int widthT)
{
	if(position.getVectorX() >= objTwo.getVectorX() - (widthT/2) && position.getVectorX() <= objTwo.getVectorX() + (widthT/2)
		&& position.getVectorY() >= objTwo.getVectorY() - (widthT/2)&& position.getVectorY() <= objTwo.getVectorY() + (heightT/2) && alive)
	{
		return false;
	}
	return true;
}
bool Bullet::detectCollision(Vector position,Vector objTwo,int heightT,int widthT) const
{
	if(position.getVectorX() >= objTwo.getVectorX() - (widthT/2) && position.getVectorX() <= objTwo.getVectorX() + (widthT/2)
		&& position.getVectorY() >= objTwo.getVectorY() - (widthT/2)&& position.getVectorY() <= objTwo.getVectorY() + (heightT/2) && alive)
	{
		return false;
	}
	return true;
}
Vector Bullet::getPosition()const { return position;}
Vector Bullet::getAngle()const { return angle;}
//////////////////////////////////////////////////////////////////////////
/// <Set bullet angle>
///
/// @param  Vector,Vector
/// @return void
//////////////////////////////////////////////////////////////////////////
void Bullet::setBulletAngle(Vector player,Vector vMouse)
{
	position.vectorSetX(player.getVectorX());
	position.vectorSetY(player.getVectorY());
	alive = true;
	Vector angle;
	angle.vectorSetX((vMouse.getVectorX()-position.getVectorX())/10);
	angle.vectorSetY((vMouse.getVectorY()-position.getVectorY())/10);
	this->angle = angle;
	this->angle.vectorSetX(std::sqrt(std::pow(angle.getVectorX(),2))/5);
	this->angle.vectorSetY(std::sqrt(std::pow(angle.getVectorY(),2))/5);
	if (angle.getVectorX() < 0)
		this->angle.vectorSetX(this->angle.getVectorX() * -1);
	if (angle.getVectorY() < 0)
		this->angle.vectorSetY(this->angle.getVectorY() * -1);
}

//////////////////////////////////////////////////////////////////////////
/// <Set bullet angle>
///
/// @param  float,float,Vector
/// @return void
//////////////////////////////////////////////////////////////////////////
void Bullet::setBulletAngle(float playerx,float playery,Vector vMouse)
{
	position.vectorSetX(playerx);
	position.vectorSetY(playery);
	alive = true;
	Vector angle;
	angle.vectorSetX((vMouse.getVectorX()-position.getVectorX())/10);
	angle.vectorSetY((vMouse.getVectorY()-position.getVectorY())/10);
	this->angle = angle;
	this->angle.vectorSetX(std::sqrt(std::pow(angle.getVectorX(),2))/5);
	this->angle.vectorSetY(std::sqrt(std::pow(angle.getVectorY(),2))/5);
	if (angle.getVectorX() < 0)
		this->angle.vectorSetX(this->angle.getVectorX() * -1);
	if (angle.getVectorY() < 0)
		this->angle.vectorSetY(this->angle.getVectorY() * -1);
	this->angle.vectorSet((float)(this->angle.getVectorX()/1.5),(float)(this->angle.getVectorY()/1.5));
}

//////////////////////////////////////////////////////////////////////////
/// <loads bullet>
///
/// @param  N/A
/// @return void
//////////////////////////////////////////////////////////////////////////
void Bullet::loadBullet()
{
	setAlive(true);
	angle.vectorSetX(0);
	angle.vectorSetY(0);
	position.vectorSetX(-200);
	position.vectorSetY(-200);
	height = 20;
	width = 20;
	sprite = -1;
	sprite = CreateSprite( "./images/bomb.png", 20, 20, true );
}

//////////////////////////////////////////////////////////////////////////
/// <destroys the bullets data>
///
/// @param  N/A
/// @return void
//////////////////////////////////////////////////////////////////////////
void Bullet::endBullet()
{
	DestroySprite(sprite);
}

//////////////////////////////////////////////////////////////////////////
/// <draws the bullet>
///
/// @param  N/A
/// @return void
//////////////////////////////////////////////////////////////////////////
void Bullet::drawBullet()
{
	if (alive)
		DrawSprite(sprite);
}
void Bullet::drawBullet() const
{
	//if (alive)
	DrawSprite(sprite);
}