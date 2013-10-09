#include <iostream>
#include "Boss.h"


Boss::Boss(void)
{
}


Boss::~Boss(void)
{
}

void Boss::setHeight(int change)
{
	height = change;
}
void Boss::setWidth(int change)
{
	width = change;
}
int Boss::getHeight()
{
	return height;
}
int Boss::getWidth()
{
	return width;
}
void Boss::setSprite(int change)
{
	sprite = change;
}
int Boss::getSprite()
{
return sprite;
}
void Boss::setTime(int change)
{
	time = change;
}
int Boss::getTime()
{
	return time;
}
int Boss::getHealth()
{
	return health;
}
void Boss::updateBoss()
{
	//position.vectorSet(plannedPosition);
	MoveSprite(sprite,(int)position.getVectorX(),(int)position.getVectorY());
}
void Boss::loadBoss()
{
	width = 1280;
	height = 300;
	position.vectorSetX((float)width/2);
	position.vectorSetY((float)-height);
	sprite = CreateSprite( "./images/boss.png",width, height,true );
}
void Boss::drawBoss()
{
	//if (showing)
		DrawSprite(sprite);
}
void Boss::endBoss()
{
	DestroySprite(sprite);
}
bool Boss::moveWave()
{
	//std::cout << "Moving boss forward";
	if (!(position.getVectorY() >= height/2))
		position.vectorSetY(position.getVectorY()+1);
		//return true;
	return false;
}