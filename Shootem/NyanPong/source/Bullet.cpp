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
	if(position.getVectorX() >= objTwo.getVectorX() - (widthT/2) && position.getVectorX() <= objTwo.getVectorX() + (widthT/2)
		&& position.getVectorY() >= objTwo.getVectorY() - (widthT/2)&& position.getVectorY() <= objTwo.getVectorY() + (heightT/2) && alive)
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
	//int distance = (int)sqrt((target.position.x-bullets.position.x)*(target.position.x-bullets.position.x) + (target.position.y-bullets.position.y)*(target.position.y-bullets.position.y));
	//int distance = (int)sqrt(std::pow(target.position.x-bullets.position.x,2) + std::pow(target.position.y-bullets.position.y,2));
	//int distancey = (int)sqrt(((target.position.y-bullets.position.y)^2));
	//bullets.angle.x = (target.position.x-bullets.position.x)/distance;
	//bullets.angle.y = (target.position.y-bullets.position.y)/distance;
	//float a = std::atan2(target.position.x - bullets.position.x,target.position.y - bullets.position.y);
	//bullet[whatBullet].angle.y = -1;
	//bullets.angle.x = std::cos(a);
	//bullets.angle.y = std::sin(a);
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
	this->angle.vectorSet(this->angle.getVectorX()/1.5,this->angle.getVectorY()/1.5);
}
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
void Bullet::endBullet()
{
	DestroySprite(sprite);
}
void Bullet::drawBullet()
{
	if (alive)
		DrawSprite(sprite);
}