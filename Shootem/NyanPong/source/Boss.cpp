#include <iostream>
#include "Boss.h"


Boss::Boss(void)
{
	launch = true;
}


Boss::~Boss(void)
{
}

Vector Boss::getPosition()
{
	return position;
}

void Boss::setHeight(int change)
{
	height = change;
}
void Boss::lowerHealth(float change)
{
	if (health > 0)
	{
	health -= change;
	if ((int)(health/4) == (health/4))
		spriteBar = CreateSprite( "./images/healthbar.png",(int)(12.8f*health), 25,true );
	MoveSprite(spriteBar,640,5);
	}
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
void Boss::setSpriteBar(int change)
{
	spriteBar = change;
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
float Boss::getHealth()
{
	return health;
}
bool Boss::getLaunch()
{
	return launch;
}
void Boss::setLaunch(bool change)
{
	launch = change;
}
void Boss::updateBoss()
{
	//position.vectorSet(plannedPosition);
	if (position.getVectorX() + plannedPosition.getVectorX() < (width/4) || position.getVectorX()  + plannedPosition.getVectorX() > 1280 - (width/4))
		plannedPosition.vectorSetX(plannedPosition.getVectorX()*-1);
	position.vectorAdd(plannedPosition);
	MoveSprite(sprite,(int)position.getVectorX(),(int)position.getVectorY());
	if (position.getVectorY() >= (height/2) - 50)
	{
		time--;
		if(time <= 0)
			time = (rand() % 1000 ) + 2000;
		else if (time > 2900)
			launch = true;
		else if (time <= 1000)
			fireLasers();
	}
}
void Boss::loadBoss()
{
	time = (rand() % 1000 ) + 2000;
	width = 1280;
	height = 300;
	health = 100;
	plannedPosition.vectorSet(1,0);
	position.vectorSetX((float)width/2);
	position.vectorSetY((float)-height);
	sprite = CreateSprite( "./images/boss.png",width, height,true );
	spriteBar = CreateSprite( "./images/healthbar.png",(int)(12.8f*health), 25,true );
	
	MoveSprite(spriteBar,640,5);
}
void Boss::drawBoss()
{
	//if (showing)
	if (position.getVectorY() >= (height/2) - 50)
	{
		DrawSprite(spriteBar);
	}
	DrawSprite(sprite);
}
void Boss::endBoss()
{
	DestroySprite(sprite);
	DestroySprite(spriteBar);
}
bool Boss::moveWave()
{
	//std::cout << "Moving boss forward";
	if (!(position.getVectorY() >= (height/2) - 50))
		plannedPosition.vectorSetY(1);
	else if (time < 2000 && time > 1800)
		plannedPosition.vectorSetY(2);
	else if (time < 1780 && time > 1580)
		plannedPosition.vectorSetY(-2);
	else
		plannedPosition.vectorSetY(0);
		//return true;
	return false;
}
void Boss::fireLasers()
{
	//RED::65535
	//DARKRED::32255
	//GREEN::16711680
	//LIMEGREEN::16711935
	//Yellow::16777215
	SColour lineColorEnd(65535);
	SColour lineColorStart(16777215);
	//SColour lineColorEnd('9','`','0','0');
	//84,198 1198 190
	DrawLine(((int)position.getVectorX() - (width/2)) + 84,((int)position.getVectorY() - (height/2)) + 200,((int)position.getVectorX() - (width/2)) + 84,(int)position.getVectorY() + 800,lineColorStart,lineColorEnd);
	DrawLine(((int)position.getVectorX() - (width/2)) + 1198,((int)position.getVectorY() - (height/2)) + 200,((int)position.getVectorX() - (width/2)) + 1198,(int)position.getVectorY() + 800,lineColorStart,lineColorEnd);

}
bool Boss::collideLasers(Vector objTwo,int heightT,int widthT)
{
	if (time <= 1000)
	{
		if((position.getVectorX() - (width/2)) + 84 >= objTwo.getVectorX() - (widthT/2) && (position.getVectorX() - (width/2)) + 84 <= objTwo.getVectorX() + (widthT/2))
			return false;
		if((position.getVectorX() - (width/2)) + 1198 >= objTwo.getVectorX() - (widthT/2) && (position.getVectorX() - (width/2)) + 1198 <= objTwo.getVectorX() + (widthT/2))
			return false;
	}
	return true;
}