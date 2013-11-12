#include <iostream>
#include "Boss.h"

Boss::Boss(void)
{
	launch = true;
}

Boss::~Boss(void)
{
}

//////////////////////////////////////////////////////////////////////////
/// <gets the position>
///
/// @param  N/A
/// @return vector
//////////////////////////////////////////////////////////////////////////
Vector Boss::getPosition()
{
	return position;
}

//////////////////////////////////////////////////////////////////////////
/// <sets height>
///
/// @param  int
/// @return void
//////////////////////////////////////////////////////////////////////////
void Boss::setHeight(int change)
{
	height = change;
}

//////////////////////////////////////////////////////////////////////////
/// <lowers boss health>
///
/// @param  float
/// @return void
//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////
/// <set width>
///
/// @param  int
/// @return void
//////////////////////////////////////////////////////////////////////////
void Boss::setWidth(int change)
{
	width = change;
}

//////////////////////////////////////////////////////////////////////////
/// <gets the height>
///
/// @param  N/A
/// @return int
//////////////////////////////////////////////////////////////////////////
int Boss::getHeight()
{
	return height;
}

//////////////////////////////////////////////////////////////////////////
/// <get the width>
///
/// @param  N/A
/// @return int
//////////////////////////////////////////////////////////////////////////
int Boss::getWidth()
{
	return width;
}

//////////////////////////////////////////////////////////////////////////
/// <sets the sprite>
///
/// @param  int
/// @return void
//////////////////////////////////////////////////////////////////////////
void Boss::setSprite(int change)
{
	sprite = change;
}

//////////////////////////////////////////////////////////////////////////
/// <set the sprite for the health bar>
///
/// @param  int
/// @return void
//////////////////////////////////////////////////////////////////////////
void Boss::setSpriteBar(int change)
{
	spriteBar = change;
}

//////////////////////////////////////////////////////////////////////////
/// <gets the boss sprite>
///
/// @param  N/A
/// @return int
//////////////////////////////////////////////////////////////////////////
int Boss::getSprite()
{
return sprite;
}

//////////////////////////////////////////////////////////////////////////
/// <sets the boss movement timer>
///
/// @param  int
/// @return void
//////////////////////////////////////////////////////////////////////////
void Boss::setTime(int change)
{
	time = change;
}

//////////////////////////////////////////////////////////////////////////
/// <gets the boss movement timer>
///
/// @param  N/A
/// @return int
//////////////////////////////////////////////////////////////////////////
int Boss::getTime()
{
	return time;
}

//////////////////////////////////////////////////////////////////////////
/// <get the boss health>
///
/// @param  N/A
/// @return float
//////////////////////////////////////////////////////////////////////////
float Boss::getHealth()
{
	return health;
}

//////////////////////////////////////////////////////////////////////////
/// <gets launch>
///
/// @param  N/A
/// @return bool
//////////////////////////////////////////////////////////////////////////
bool Boss::getLaunch()
{
	return launch;
}

//////////////////////////////////////////////////////////////////////////
/// <sets launch>
///
/// @param  bool
/// @return void
//////////////////////////////////////////////////////////////////////////
void Boss::setLaunch(bool change)
{
	launch = change;
}

//////////////////////////////////////////////////////////////////////////
/// <updates the boss>
/// <if launch is true then move onto the screen>
/// <runs the movement pattern off of the timer>
///
/// @param  N/A
/// @return void
//////////////////////////////////////////////////////////////////////////
void Boss::updateBoss()
{
	//position.vectorSet(plannedPosition);
	if (position.getVectorX() + plannedPosition.getVectorX() < (width/4) || position.getVectorX()  + plannedPosition.getVectorX() > 1280 - (width/4))
		plannedPosition.vectorSetX(plannedPosition.getVectorX()*-1);
	position.vectorAdd(plannedPosition);
	MoveSprite(sprite,(int)position.getVectorX(),(int)position.getVectorY());
	MoveSprite(spriteDead,(int)position.getVectorX(),(int)position.getVectorY());
	if (position.getVectorY() >= (height/2) - 50 && health > 0)
	{
		time--;
		if(time <= 0)
			time = (rand() % 1000 ) + 2000;
		else if (time > 2800)
		{
			launch = true;
			time = 2800;
		}
		else if (time == 500 || time == 1000 || time == 1500 || time == 2000)
			for (int i = 0; i <= 2; i++)
			{
				if (!bullet[i].getAlive())
				{
					bullet[i].setAlive(true);
					bullet[i].updateBullet(bullet[i].getAngle(),bullet[i].getPosition(),bullet[i].getAlive(),bullet[i].getSprite());
					int pos = (100*i) - 100;
					bullet[i].setBulletAngle(position.getVectorX()-pos,position.getVectorY(),playerPosition);
					//bullet[i].set
				}
			}
		else if (time <= 1000)
			fireLasers();

		for (int i = 0; i <= 2; i++)
		{
			if (bullet[i].getAlive())
			{
					bullet[i].updateBullet(bullet[i].getAngle(),bullet[i].getPosition(),bullet[i].getAlive(),bullet[i].getSprite());
				//bullet[i].setBulletAngle(position,playerPosition);
			}
		}
	}
}

//////////////////////////////////////////////////////////////////////////
/// <stores the players position>
///
/// @param  vector
/// @return void
//////////////////////////////////////////////////////////////////////////
void Boss::setPlayerPosition(Vector &player)
{
	playerPosition.vectorSet(player);
}

//////////////////////////////////////////////////////////////////////////
/// <loads the boss data>
///
/// @param  N/A
/// @return void
//////////////////////////////////////////////////////////////////////////
void Boss::loadBoss()
{
	time = (rand() % 1000 ) + 2000;
	width = 1280;
	height = 300;
	health = 100;
	plannedPosition.vectorSet(1,0);
	position.vectorSetX((float)width/2);
	position.vectorSetY((float)-height);
	for (int i = 0; i <= 2; i++)
		bullet[i].loadBullet();
	sprite = CreateSprite( "./images/boss.png",width, height,true );
	spriteDead = CreateSprite( "./images/bossDead.png",width, height,true );
	spriteBar = CreateSprite( "./images/healthbar.png",(int)(12.8f*health), 25,true );

	MoveSprite(spriteBar,640,5);
}

//////////////////////////////////////////////////////////////////////////
/// <draws the boss and his health bar>
///
/// @param  N/A
/// @return void
//////////////////////////////////////////////////////////////////////////
void Boss::drawBoss()
{
	//if (showing)
	if (health > 0)
	{
	if (position.getVectorY() >= (height/2) - 50)
	{

		for (int i = 0; i <= 2; i++)
		{
			if (bullet[i].getAlive())
				bullet[i].drawBullet();
		}
		DrawSprite(spriteBar);
	}
	DrawSprite(sprite);
	}
	else
	{
		DrawSprite(spriteDead);
	}
}

//////////////////////////////////////////////////////////////////////////
/// <delets all of the boss data>
///
/// @param  N/A
/// @return void
//////////////////////////////////////////////////////////////////////////
void Boss::endBoss()
{
	DestroySprite(sprite);
	DestroySprite(spriteBar);
}

//////////////////////////////////////////////////////////////////////////
/// <determines if he moves onto the screen>
///
/// @param  N/A
/// @return bool
//////////////////////////////////////////////////////////////////////////
bool Boss::moveWave()
{
	//std::cout << "Moving boss forward";
	if (health > 0)
	{
	if (!(position.getVectorY() >= (height/2) - 50))
		plannedPosition.vectorSetY(1);
	else if (time < 2000 && time > 1800)
		plannedPosition.vectorSetY(2);
	else if (time < 1780 && time > 1580)
		plannedPosition.vectorSetY(-2);
	else
		plannedPosition.vectorSetY(0);
		//return true;
	}
	else
	{
		plannedPosition.vectorSetX(0);
		plannedPosition.vectorSetY(-1);
	}
	return false;
}

//////////////////////////////////////////////////////////////////////////
/// <fires the boss lasers>
///
/// @param  N/A
/// @return void
//////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////
/// <checks if the lasers collide with the player>
///
/// @param  vector,int,int
/// @return bool
//////////////////////////////////////////////////////////////////////////
bool Boss::collideLasers(Vector objTwo,int heightT,int widthT)
{
	if (time <= 1000)
	{
		if((position.getVectorX() - (width/2)) + 84 >= objTwo.getVectorX() - (widthT/2) && (position.getVectorX() - (width/2)) + 84 <= objTwo.getVectorX() + (widthT/2))
			return false;
		if((position.getVectorX() - (width/2)) + 1198 >= objTwo.getVectorX() - (widthT/2) && (position.getVectorX() - (width/2)) + 1198 <= objTwo.getVectorX() + (widthT/2))
			return false;
		for (int i = 0; i <= 2; i++)
		{
			if(bullet[i].detectCollision(objTwo,heightT,widthT))
				return false;
		}
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////
/// <checks if the bullets collide with the player>
///
/// @param  vector,int,int
/// @return bool
//////////////////////////////////////////////////////////////////////////
bool Boss::collideBullets(Vector objTwo,int heightT,int widthT)
{
	for (int i = 0; i <= 2; i++)
	{
		if(bullet[i].detectCollision(objTwo,heightT,widthT))
			return false;
	}
	return true;
}