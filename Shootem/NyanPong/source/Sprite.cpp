#include "Sprite.h"
#include <iostream>


Sprite::Sprite(void)
{
}


Sprite::~Sprite(void)
{
}
void Sprite::setAlive(bool change)
{
	alive = change;
}
bool Sprite::getAlive()
{
	return alive;
}
void Sprite::setHeight(int change)
{
	height = change;
}
void Sprite::setWidth(int change)
{
	width = change;
}
int Sprite::getHeight()
{
	return height;
}
int Sprite::getWidth()
{
	return width;
}
void Sprite::setSprite(int change)
{
	sprite = change;
}
int Sprite::getSprite()
{
	return sprite;
}
bool Sprite::detectCollision(Vector objTwo,int heightT,int widthT)
{
	if(position.getVectorX() >= objTwo.getVectorX() - (widthT/2) && position.getVectorX() <= position.getVectorX() + (widthT/2)
		&& position.getVectorY() >= position.getVectorY() - (heightT/2)&& position.getVectorY() <= objTwo.getVectorY() + (heightT/2) && alive)
	{
		return false;
	}
	return true;
}
void Sprite::loadSprite()
{
	setAlive(true);
	angle.vectorSetX(0);
	angle.vectorSetY(0);
	position.vectorSetX(-200);
	position.vectorSetY(-200);
	height = 20;
	width = 10;
	sprite = -1;
	sprite = CreateSprite( "./images/bomb.png", 10, 20, true );
}
void Sprite::updateSprite()
{

}
void Sprite::endSprite()
{
	DestroySprite(sprite);
}
void Sprite::drawSprite()
{
	if (alive)
		DrawSprite(sprite);
}