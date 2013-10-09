#include "Bullet.h"
#include <iostream>


Bullet::Bullet(void)
{
}


Bullet::~Bullet(void)
{
}
void Bullet::setAlive(bool change)
{
	alive = change;
}
bool Bullet::getAlive()
{
	return alive;
}
void Bullet::setHeight(int change)
{
	height = change;
}
void Bullet::setWidth(int change)
{
	width = change;
}
int Bullet::getHeight()
{
	return height;
}
int Bullet::getWidth()
{
	return width;
}
void Bullet::setSprite(int change)
{
	sprite = change;
}
int Bullet::getSprite()
{
return sprite;
}
void Bullet::updateBullet()
{
	if (position.getVectorX() < 0 || position.getVectorX()  > 1280 || position.getVectorY()  < 0 || position.getVectorY() > 780)
	{
		alive = false;
		position.vectorSetX(-1000);
		position.vectorSetY(-1000);
	}
	if (alive)
	{
		position.vectorAdd(angle);
		MoveSprite(sprite,(int)position.getVectorX(),(int)position.getVectorY());
	}
}
bool Bullet::detectCollision(Vector objTwo,int heightT,int widthT)
{
	if(position.getVectorX() >= objTwo.getVectorX() - (widthT/2) && position.getVectorX() <= position.getVectorX() + (widthT/2)
		&& position.getVectorY() >= position.getVectorY() - (heightT/2)&& position.getVectorY() <= objTwo.getVectorY() + (heightT/2) && alive)
	{
		return false;
	}
	return true;
}
void Bullet::setBulletAngle(Vector player,Vector vMouse)
{
		position.vectorSetX(player.getVectorX());
		position.vectorSetY(player.getVectorY());
		alive = true;
		Vector angle;
		angle.vectorSetX((vMouse.getVectorX()-player.getVectorX())/10);
		angle.vectorSetY((vMouse.getVectorY()-player.getVectorY())/10);
		angle = angle;
		angle.vectorSetX(std::sqrt(std::pow(angle.getVectorX(),2))/5);
		angle.vectorSetY(std::sqrt(std::pow(angle.getVectorY(),2))/5);
		angle.getNormal();
		if (angle.getVectorX() < 0)
			angle.vectorSetX(angle.getVectorX() * -1);
		if (angle.getVectorY() < 0)
			angle.vectorSetY(angle.getVectorY() * -1);
}
void Bullet::loadBullet()
{
	sprite = CreateSprite( "./images/bomb.png", 10, 20, true );
}
void Bullet::endBullet()
{
	DestroySprite(sprite);
}
void Bullet::drawBullet()
{
	if (alive)
		DrawSprite(sprite);
}