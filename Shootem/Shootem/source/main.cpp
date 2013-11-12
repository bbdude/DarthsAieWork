//////////////////////////////////////////////////////////////////////////
//	@Author:	Jacob Miller
//	@Date:	10/30/2013
//	@Brief:	Main file for Shootem
//////////////////////////////////////////////////////////////////////////
#define _USE_MATH_DEFINES
//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include "Boss.h"
#include "MenuItems.h"
#include "windows.h"
#include "Vector.h"
#include "Sprite.h"
#include "Bullet.h"
#include < GL/glew.h>
#include <iostream>
#include <time.h> 
#include <list>


//////////////////////////////////////////////////////////////////////////
/// <Generic moving object>
///
/// <Used to move the 2 backgrounds in unison, no need for a class with a lot of data in it.>
/// &Variables <Vector position,Vector speed,int sprite,int width,int height>
//////////////////////////////////////////////////////////////////////////
struct movableObject{
public:
	Vector position;
	Vector speed;
	int sprite;
	int width;
	int height;
};

//Declarations
//////////////////////////////////////////////////////////////////////////
/// <The array of bullets using the Bullet class>
///
/// <50 bullets that cycle so that the player can have as many bullets as he needs>
//////////////////////////////////////////////////////////////////////////
//Bullet bullet[50];
Bullet bullet;
std::list<Bullet> bullet_list;
//////////////////////////////////////////////////////////////////////////
/// <The array of enemies using the Sprite class>
///
/// <20 enemies that cycle so they can come in waves>
//////////////////////////////////////////////////////////////////////////
//Sprite monster[20];
Sprite monster;
std::list<Sprite> monster_list;
int maxAI = 35;
//////////////////////////////////////////////////////////////////////////
/// <Generates a certain enemy based on the functions parameters>
///
/// <Takes in a sprite and then just changes its values based of which type was selected>
///
/// @param  Sprite,Int,Vector
/// @param  Takes in an enemy, enters a switch that is based off of the type you chose, and then it changes the enemy.
/// @return Returns void
//////////////////////////////////////////////////////////////////////////
void loadAI(Sprite &obj,int type,Vector &vScreen)
{
	switch(type)
	{
	case 1:
		obj.loadSprite(true,NULL,40,40,NULL,"BLUE",NULL,NULL,NULL);
		obj.setSprite(CreateSprite("./images/enemyB.png", 40, 40, true ));
		obj.setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
		obj.setSpeed((rand() % 5) - 2.5f,0.25f);
		break;
	case 2:
		obj.loadSprite(true,NULL,20,35,NULL,"GREEN",NULL,NULL,NULL);
		obj.setSprite(CreateSprite( "./images/enemyG.png", 20, 35, true ));
		obj.setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,100);
		obj.setSpeed(0,0.25f);
		break;
	case 3:
		obj.loadSprite(true,NULL,10,10,NULL,"RED",NULL,NULL,NULL);
		obj.setSprite(CreateSprite( "./images/enemyR.png", 10, 10, true ));
		obj.setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
		obj.setSpeed(0.28f,0.1f);
		break;
	default:
		obj.loadSprite(true,NULL,20,20,NULL,"PINK",NULL,NULL,NULL);
		obj.setSprite(CreateSprite( "./images/enemyR.png", 10, 10, true ));
		obj.setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
		obj.setSpeed((float)(rand() % 5) - 2.5f,0.7f);
		break;
	}
}
void loadAIC(Sprite obj,int type,Vector &vScreen)
{
	switch(type)
	{
	case 1:
		obj.loadSprite(true,NULL,40,40,NULL,"BLUE",NULL,NULL,NULL);
		obj.setSprite(CreateSprite("./images/enemyB.png", 40, 40, true ));
		obj.setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
		obj.setSpeed((rand() % 5) - 2.5f,0.25f);
		break;
	case 2:
		obj.loadSprite(true,NULL,20,35,NULL,"GREEN",NULL,NULL,NULL);
		obj.setSprite(CreateSprite( "./images/enemyG.png", 20, 35, true ));
		obj.setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,100);
		obj.setSpeed(0,0.25f);
		break;
	case 3:
		obj.loadSprite(true,NULL,10,10,NULL,"RED",NULL,NULL,NULL);
		obj.setSprite(CreateSprite( "./images/enemyR.png", 10, 10, true ));
		obj.setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
		obj.setSpeed(0.28f,0.1f);
		break;
	default:
		obj.loadSprite(true,NULL,20,20,NULL,"PINK",NULL,NULL,NULL);
		obj.setSprite(CreateSprite( "./images/enemyR.png", 10, 10, true ));
		obj.setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
		obj.setSpeed((float)(rand() % 5) - 2.5f,0.7f);
		break;
	}
}
void loadAIC(Sprite *obj,int type,Vector &vScreen)
{
	switch(type)
	{
	case 1:
		obj->loadSprite(true,NULL,40,40,NULL,"BLUE",NULL,NULL,NULL);
		obj->setSprite(CreateSprite("./images/enemyB.png", 40, 40, true ));
		obj->setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
		obj->setSpeed((rand() % 5) - 2.5f,0.25f);
		break;
	case 2:
		obj->loadSprite(true,NULL,20,35,NULL,"GREEN",NULL,NULL,NULL);
		obj->setSprite(CreateSprite( "./images/enemyG.png", 20, 35, true ));
		obj->setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,100);
		obj->setSpeed(0,0.25f);
		break;
	case 3:
		obj->loadSprite(true,NULL,10,10,NULL,"RED",NULL,NULL,NULL);
		obj->setSprite(CreateSprite( "./images/enemyR.png", 10, 10, true ));
		obj->setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
		obj->setSpeed(0.28f,0.1f);
		break;
	default:
		obj->loadSprite(true,NULL,20,20,NULL,"PINK",NULL,NULL,NULL);
		obj->setSprite(CreateSprite( "./images/enemyR.png", 10, 10, true ));
		obj->setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
		obj->setSpeed((float)(rand() % 5) - 2.5f,0.7f);
		break;
	}
}

////////////////////////////////////////////////////////////////////////// 
/// <Sends in enemies from certain angles>
///
/// <Finds 3 sprites that are dead and sends them in from either the left,right, or the top in a group>
///
/// @param  N/A
/// @param 
/// @return Returns void
//////////////////////////////////////////////////////////////////////////
void sideLoadAI()
{
	int range = 0;
	std::list<Sprite>::const_iterator cIter;
	switch(rand()% 1000)
	{
	case 50:
		if (!monster_list.empty())
			for ( cIter = monster_list.begin( ); cIter != monster_list.end( ); cIter++ )
			{
				if ((cIter->getAlive() || cIter->getPosition().getVectorY() < 0) && range >= 3)
				{
					range++;
					cIter->loadSprite(true,false,cIter->getWidth(),cIter->getHeight(),cIter->getTag(),0,1260,(-20 + (50*range)));
					cIter->setSpeed(0.5f,0.5f);
				}
				if (range >= 3)
					return;
			}
		break;
	case 100:
		if (!monster_list.empty())
			for ( cIter = monster_list.begin( ); cIter != monster_list.end( ); cIter++ )
			{
				if ((cIter->getAlive() || cIter->getPosition().getVectorY() < 0) && range >= 3)
				{
					range++;
					cIter->loadSprite(true,false,cIter->getWidth(),cIter->getHeight(),cIter->getTag(),0,20,(-20 + (50*range)));
					cIter->setSpeed(0.5f,0.5f);
				}
				if (range >= 3)
					return;
			}
		break;
	case 150:
		if (!monster_list.empty())
			for ( cIter = monster_list.begin( ); cIter != monster_list.end( ); cIter++ )
			{
				if ((cIter->getAlive() || cIter->getPosition().getVectorY() < 0) && range >= 3)
				{
					range++;
					cIter->loadSprite(true,false,cIter->getWidth(),cIter->getHeight(),cIter->getTag(),0,(1260 - (rand() % 200)),(-20 + (50*range)));
					cIter->setSpeed(0,0.6f);
				}
				if (range >= 3)
					return;
			}
		break;
	case 200:
		if (!monster_list.empty())
			for ( cIter = monster_list.begin( ); cIter != monster_list.end( ); cIter++ )
			{
				if ((cIter->getAlive() || cIter->getPosition().getVectorY() < 0) && range >= 3)
				{
					range++;
					cIter->loadSprite(true,false,cIter->getWidth(),cIter->getHeight(),cIter->getTag(),0,((rand() % 200) + 100),(-20 + (50*range)));
					cIter->setSpeed(0,0.6f);
				}
				if (range >= 3)
					return;
			}
		break;
	}
}

//////////////////////////////////////////////////////////////////////////
/// <Gives all enemies a base value and sets up the first few enemys >
///
/// <Sets all enemies to the default type, then sets 3 monsters to spawn right when the level begins>
///
/// @param  Int,Sprite
/// @param  Takes in what level it is and then spawns newer types based on that
/// @return Returns void
//////////////////////////////////////////////////////////////////////////
void loadLevel(int level,Sprite &powerUp)
{
	powerUp.loadSprite(false,NULL,100,100,NULL,"PINK",NULL,-200,-200);
	switch (level)
	{
	case 1:
		{
		int index = 0;
		while (index != 10)
		{
			index++;
			Sprite monsternew(false,false,20,20,0,"PINK",0,-200,-200);
			if (index >= 3)
			{
				monsternew.setPosition(50*index,50*index);
				monsternew.setAlive(true);
			}
			monsternew.setSpeed((rand() % 5) - 2.5f,0.7f);

			monster_list.push_front(monsternew);

		}
		//if (!monster_list.empty())
			//for ( cIter = monster_list.begin( ); cIter != monster_list.end( ); cIter++ )
			//{
			//	if (cIter->getAlive() || cIter->getPosition().getVectorY() < 0)
			//	{
			//		cIter->loadSprite(false,NULL,20,20,NULL,"PINK",NULL,-200,-200);
			//		cIter->setSpeed((rand() % 5) - 2.5f,0.7f);
			//	}
			//}
		break;
		}
	case 2:
		monster_list.front().setSprite(CreateSprite( "./images/enemyB.png", 40, 40, true ));
		monster_list.front().setSpeed((rand() % 5) - 2.5f,0.25f);
		monster_list.front().loadSprite(true,NULL,20,20,NULL,"PINK",NULL,-200,-200);
		break;
	default:
		break;
	}
}

//////////////////////////////////////////////////////////////////////////
/// <Generates a random enemy based on the functions parameters and the wave>
///
/// <Increases how many enemies have dies, based on how many enemies have dies it spawns even more>
///
/// @param  Sprite,Int,Int,Vector
/// @param  Takes in the amount of dead enemies then increases it, then loads it a new type of enemy based on the wave
/// @return Returns void
//////////////////////////////////////////////////////////////////////////
void loadWave(Sprite &obj,int wave,int &whatAI,Vector &vScreen)
{
	std::list<Sprite>::const_iterator cIter;
	int index = 0;
	whatAI++;
	if (whatAI >= 40)
		whatAI = 0;
	//////////////////////
	cIter = monster_list.begin();
	for (int i = whatAI/2; i >= 0; i--)
	{
		if (!cIter->getAlive())
			switch(rand() % 10)
			{
			case 2:
			case 1:
				loadAIC(*cIter,1,vScreen);
				break;
			case 3:
			case 4:
				loadAIC(*cIter,2,vScreen);
				break;
			case 5:
			case 6:
				loadAIC(*cIter,3,vScreen);
				break;
			default:
				loadAIC(*cIter,4,vScreen);
			}
		cIter++;
	}
	switch(wave)
	{
	case 1:
		loadAI(obj,1,vScreen);
			break;
	case 2:
		loadAI(obj,2,vScreen);
			break;
	case 3:
		loadAI(obj,3,vScreen);
			break;
	default:
		loadAI(obj,4,vScreen);
			break;
		}
}
void loadWave(Sprite *obj,int wave,int &whatAI,Vector &vScreen)
{
	std::list<Sprite>::const_iterator cIter;
	int index = 0;
	whatAI++;
	if (whatAI >= 40)
		whatAI = 0;
	//////////////////////
	cIter = monster_list.begin();
	for (int i = whatAI/2; i >= 0; i--)
	{
		if (!cIter->getAlive())
			switch(rand() % 10)
			{
			case 2:
			case 1:
				loadAIC(*cIter,1,vScreen);
				break;
			case 3:
			case 4:
				loadAIC(*cIter,2,vScreen);
				break;
			case 5:
			case 6:
				loadAIC(*cIter,3,vScreen);
				break;
			default:
				loadAIC(*cIter,4,vScreen);
			}
		cIter++;
	}
	switch(wave)
	{
	case 1:
		loadAIC(obj,1,vScreen);
			break;
	case 2:
		loadAIC(obj,2,vScreen);
			break;
	case 3:
		loadAIC(obj,3,vScreen);
			break;
	default:
		loadAIC(obj,4,vScreen);
			break;
		}
}

//////////////////////////////////////////////////////////////////////////
/// <Fires a bullet toward where the mouse is>
///
/// <Checks if the left mouse button is down, if it is then it waits until it is no longer pressed and then fires a new bullet towards the mouse>
/// <Checks if the right mouse button is down, if it is then it waits until it is no longer pressed and then activates the secondary ability>
///
/// @param  Sprite,Int,Bool,Vector,Sprite,Sprite
/// @param  If either of the keys were pressed then it sets a bool to detect if that  key has been released yet.
/// @param  If a bullet is to be fired then it determines what bullet to fire based off of what bullet then increases it, also plays a shooting sound.
/// @return Returns void
//////////////////////////////////////////////////////////////////////////
void fireBullet(Sprite &player,int &whatBullet,bool &pressTrigger,Vector &vMouse,Sprite &beam,Sprite &player1)
{
	if (GetMouseButtonDown(0))
	{
		pressTrigger = true;
	}
	else if (pressTrigger)
	{
		try
		{
		PlaySound("./sounds/shoot.wav",NULL,SND_ASYNC);
		}
		catch(std::bad_alloc)
		{
		}
		Bullet bulletnew;
		bulletnew.setAll(bullet);
		bulletnew.loadBullet();
		bulletnew.setBulletAngle(player.getPosition(),vMouse);
		bulletnew.setAll(player.getPosition(),bulletnew.getAngle(),true,bulletnew.getWidth(),bulletnew.getHeight());
		bulletnew.getAngle().getVectorX();
		bulletnew.getAngle().getVectorY();
		bullet_list.push_front(bulletnew);
		//bullet[whatBullet].setBulletAngle(player.getPosition(),vMouse);
		//whatBullet++;
		//if (whatBullet == 50)
		//	whatBullet = 0;
		pressTrigger = false;
		bullet_list.push_front(bulletnew);
	}

	if (GetMouseButtonDown(1) && beam.getTime() <= 0)
	{
		beam.setFire(true);
	}
	else if (beam.getFire())
	{
		if (getTag() == "BASIC")
		{
			beam.setFire(false);
			beam.setAlive(true);
			beam.setTime(2000);
		}
		else
		{
			beam.setFire(false);
			beam.setTime(2000);
			beam.lineBeam = true;
		}
	}
	if (beam.lineBeam == true)
	{
		//RED::65535
		//DARKRED::32255
		//GREEN::16711680
		//LIMEGREEN::16711935
		//Yellow::16777215
		SColour lineColorEnd(65535);
		SColour lineColorStart(16777215);
		DrawLine((int)player.position.getVectorX(),(int)player.position.getVectorY(),(int)vMouse.getVectorX(),(int)vMouse.getVectorY(),lineColorStart,lineColorEnd);
		//bullet[whatBullet].setBulletAngle(player.getPosition(),vMouse);
		Bullet bulletnew;
		bulletnew.setAll(bullet);
		bulletnew.setAll(player.getPosition(),bulletnew.getAngle(),true,bullet.getWidth(),bullet.getHeight());
		bulletnew.loadBullet();
		bulletnew.setBulletAngle(player.getPosition(),vMouse);
		bullet_list.push_front(bulletnew);
		//whatBullet++;
		//if (whatBullet == 50)
			//whatBullet = 0;
		if (beam.getTime() <= 1000)
			beam.lineBeam = false;
	}
	player1.setTime(player1.getTime()-1);
	beam.setTime(beam.getTime()-1);
}

//////////////////////////////////////////////////////////////////////////
/// <Changes the players life>
///
/// <Checks if the player is invincible or infected and changes the players life and health bar based on that.>
/// <If player does take damage that is not venomous then he becomes invincible for a short period of time>
///
/// @param  Sprite,Int,Vector,Sprite,Sprite,Sprite
/// @param  checks the players invincibility timer then edits the players tag based on if he was invincible , infected, or normal
/// @return void
//////////////////////////////////////////////////////////////////////////
void updateLives(Sprite &power, int &iLives,Vector &vScreen,Sprite &healthIcon,Sprite &player1)
{
	if (player1.getInv() <= 0)
	{
		if (power.getTag() == "FROZEN")
		{
			power.setTag("PINK");
			healthIcon.setSprite(CreateSprite( "./images/healthbar.png", 50 * iLives, 25, true ));
		}
		else if (power.getTag() == "VENOM")
		{
			power.setTag("VENOM2");
			iLives -= 2;
			healthIcon.setPositionX(vScreen.getVectorX()/2);
			healthIcon.setSprite(CreateSprite( "./images/healthbarV.png", 50 * iLives, 25, true ));
		}
		else if (power.getTag() == "VENOM2")
		{
			power.setTag("PINK");
			iLives -= 2;
			healthIcon.setPositionX(vScreen.getVectorX()/2);
			healthIcon.setSprite(CreateSprite( "./images/healthbar.png", 50 * iLives, 25, true ));
		}
		else if (power.getTag() != "FROZEN" && power.getTag() != "VENOM" && power.getTag() != "VENOM2")
		{
			iLives--;
			healthIcon.setPositionX(vScreen.getVectorX()/2);
			healthIcon.setSprite(CreateSprite( "./images/healthbar.png", 50 * iLives, 25, true ));

			player1.setInv(1500);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
/// <Updates the player>
///
/// <Checks if the WASD is being pressed and moves the player based of off that if he will not move out side of bounds>
/// <Then checks if the boss and the player are colliding>
/// <If the invincibility timer is out then reset the health bar to normal>
///
/// @param  Sprite,Int,Vector,Boss,Sprite,Sprite,Sprite
/// @param  checks the players height and speed to see if he can move.
/// @param  Checks on the players invincibility timer.
/// @return void
//////////////////////////////////////////////////////////////////////////
void updatePlayer(Sprite &player,int &iLives,Vector &vScreen,Boss &boss,Sprite &healthIcon,Sprite &player1,Sprite &powerUp){
	Vector plannedMovement;
	if (IsKeyDown('W') && player.getPositionY() - (player.getHeight()/2) - player.getSpeedY() >= 0)
	{
		plannedMovement.vectorSetY(plannedMovement.getVectorY() - player.getSpeedY());
	}
	if (IsKeyDown('S') && player.getPositionY() + (player.getHeight()/2) + player.getSpeedY() <= vScreen.getVectorY())
	{
		plannedMovement.vectorSetY(plannedMovement.getVectorY() + player.getSpeedY());
	}
	if (IsKeyDown('A') && player.getPositionX() - (player.getWidth()/2) - player.getSpeedX() >= 0)
	{
		plannedMovement.vectorSetX(plannedMovement.getVectorX() - player.getSpeedX());
	}
	if (IsKeyDown('D') && player.getPositionX() + (player.getWidth()/2) + player.getSpeedX() <= vScreen.getVectorX())
	{
		plannedMovement.vectorSetX(plannedMovement.getVectorX() + player.getSpeedX());
	}

	if (player.getPositionX() + plannedMovement.getVectorX() < 20)
		plannedMovement.vectorSetX(0);
	if (player.getPositionX() + plannedMovement.getVectorX() > 1260)
		plannedMovement.vectorSetX(0);
	if (player.getPositionY() + plannedMovement.getVectorY() < 20)
		plannedMovement.vectorSetY(0);
	if (player.getPositionY() + plannedMovement.getVectorY() > 760)
		plannedMovement.vectorSetY(0);

	player.position.vectorAdd(plannedMovement);

	if (!boss.collideLasers(player.position,player.getHeight(),player.getWidth()))
		updateLives(powerUp,iLives,vScreen,healthIcon,player);
	if (!player.detectCollision(boss.getPosition(),boss.getHeight(),boss.getWidth()))
		updateLives(powerUp,iLives,vScreen,healthIcon,player);
	if (player.getInv() == 1500)
		player1.setSprite( CreateSprite( "./images/playerVoid.png", 20, 20, true ));

	if (player.getInv() > 0)
	{
		player.setInv(player1.getInv()-1);
		if (player.getInv() == 0)
		{
			if (getTag() == "BASIC")
				player1.setSprite( CreateSprite( "./images/player.png", 20, 20, true ));
			else
				player1.setSprite( CreateSprite( "./images/playerF.png", 20, 20, true ));
		}
	}
}

//////////////////////////////////////////////////////////////////////////
/// <Changes the player direction>
///
/// <Angle the player towards your mouse>
///
/// @param  Sprite,Vector,Vector
/// @param  Uses Atan2 to calculate the angle based on the screens diameters, mouses position, pi, and the players position.
/// @return Returns the angle at which the player will be pointed to(float).
//////////////////////////////////////////////////////////////////////////
float getPlayerAngle(Sprite &player,Vector &vScreen,Vector &vMouse)
{
	float angle = std::atan2 ( (vScreen.getVectorY() - vMouse.getVectorY()) - player.position.getVectorY(), vMouse.getVectorX() - player.position.getVectorX()) * 57.2957795f; //57... is 180/pi
	return angle;
}

//////////////////////////////////////////////////////////////////////////
/// <Updates the power up>
///
/// <If the power up is alive then detect if it collides with a player, goes off screen, or needs to bounce of the side walls>
/// <Randomly spawns it if it is no longer alive>
///
/// @param  Sprite,Int,Vector,Sprite,Sprite
/// @param  checks if power up is alive, sets it variables if it collides, sets it to dead if it goes off screen, reverses its direction if it collides it with the walls.
/// @return void
//////////////////////////////////////////////////////////////////////////
void updatePowerUp(Sprite &power, int &iLives,Vector &vScreen,Sprite &healthIcon,Sprite &player1)
{
	if (power.getAlive())
	{
		if (!player1.detectCollision(power.position,power.getHeight(),power.getWidth()))
		{
			power.setAlive(false);
			power.position.vectorSet(-100,-100);
			power.speed.vectorSet(0,0);
			power.setTag("FROZEN");
			healthIcon.setSprite(CreateSprite( "./images/healthbarP.png", 50 * iLives, 25, true ));
		}
		else if (power.position.getVectorY() >= vScreen.getVectorY())
		{
			power.setAlive(false);
			power.position.vectorSet(-100,-100);
			power.speed.vectorSet(0,0);
		}
		if ((power.position.getVectorX() + power.speed.getVectorX() < 20 || power.position.getVectorX() + power.speed.getVectorX() > 1260))
			power.speed.vectorSetX(power.speed.getVectorX()*-1);

		power.position.vectorAdd(power.speed);
		MoveSprite(power.getSprite(), (int)power.position.getVectorX(), (int)power.position.getVectorY());
	}
	else if (rand()%4000 == 2)
	{
		power.setAlive(true);
		power.position.vectorSetX((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20);
		power.position.vectorSetY(-20);
		power.speed.vectorSetY(0.25f);
		power.speed.vectorSetX((rand() % 5) - 2.5f);
	}
}

//////////////////////////////////////////////////////////////////////////
/// <Updates all the Enemys>
///
/// <Checks what type of enemy it is so it can change how it moves>
/// <Checks if the enemy collides with bullet then if it does explode it and the bullet>
/// <Updates the wave if an enemy goes off screen>
///
/// @param  Sprite,Sprite, int,int ,int ,float ,Vector ,Sprite,Boss,Sprite,Sprite ,Sprite
/// @param  checks the enemies tag, checks if enemy collides, checks if boss collides,
/// @return void
//////////////////////////////////////////////////////////////////////////
void updateAi(Sprite &monster,Sprite &power, int &iLives,int &whatAI,float &wave,Vector &vScreen,Sprite &beam,Boss &boss,Sprite &healthIcon,Sprite &player1,Sprite &powerUp){
	if (monster.getAlive())
	{
		Vector plannedMovement;
		plannedMovement.vectorAdd(monster.getSpeed());
		bool moving = true;
		bool stopIt = false;
		if (monster.getTag() == "RED" && rand()%600 == 2)
		{
			monster.setSpeedY(20);
		}
		else if (monster.getTag() == "RED")
		{
			monster.setSpeedY(0);
		}
		if (monster.getPositionY() > vScreen.getVectorY())
		{
			wave += 0.1f;
			loadWave(monster,(int)wave,whatAI,vScreen);
		}
		if (!player1.detectCollision(monster.getPosition(),monster.getHeight(),monster.getWidth()))
		{
			if (monster.getTag() == "GREEN" && power.getTag() != "FROZEN")
			{
				power.setTag("VENOM");
				healthIcon.setSprite(CreateSprite( "./images/healthbarV.png", 50 * iLives, 25, true ));
			}
			monster.setAlive(false);
			updateLives(powerUp,iLives,vScreen,healthIcon,player1);
			loadWave(monster,(int)wave,whatAI,vScreen);
		}
		else if (!beam.detectCollisionA(monster.getPosition(),monster.getHeight(),monster.getWidth()))
		{
			monster.setAlive(false);
			loadWave(monster,(int)wave,whatAI,vScreen);
		}
		if (monster.position.getVectorX() + plannedMovement.getVectorX() < 20 || monster.position.getVectorX() + plannedMovement.getVectorX() > 1260)
			moving = false;
		std::list<Bullet>::const_iterator cIter;
		std::list<Bullet>::const_iterator cIterTemp;
		try
		{
		if (!bullet_list.empty())
		for ( cIter = bullet_list.begin( ); cIter != bullet_list.end( ); cIter++ )
		{
			bool cIterAlive = true;
 			if(!(*cIter).detectCollision((*cIter).getPosition(),monster.position,monster.getHeight(),monster.getWidth()))
			{
				cIterTemp = cIter;
				monster.setAlive(false);
				bullet_list.erase(cIterTemp);
				//(*cIter).setAlive(false);
				loadWave(monster,(int) wave,whatAI,vScreen);
				cIterAlive = false;
				break;
			}
			if (cIterAlive)
				if (!(*cIter).detectCollision((*cIter).getPosition(),boss.getPosition(),boss.getHeight(),boss.getWidth()))
				{
					cIterTemp = cIter;
					boss.lowerHealth(2);
					bullet_list.erase(cIterTemp);
					//(*cIter).setAlive(false);
					break;
				}
		}
		}
		catch(int e){}
		if (!beam.detectCollisionA(boss.getPosition(),boss.getHeight(),boss.getWidth()))
		{
			boss.lowerHealth(0.01f);
		}
		if (moving && !stopIt)
			monster.position.vectorAdd(plannedMovement);
		else
			monster.speed.multiplyScalarX(-1);
	}
	if (boss.getLaunch() && !monster.getAlive())
	{
		boss.setLaunch(false);
		monster.setAlive(false);
		loadAI(monster,rand()%4,vScreen);
	}
}
void updateAiC(Sprite * monster,Sprite &power, int &iLives,int &whatAI,float &wave,Vector &vScreen,Sprite &beam,Boss &boss,Sprite &healthIcon,Sprite &player1,Sprite &powerUp){
	if (monster->getAlive())
	{
		Vector plannedMovement;
		plannedMovement.vectorAdd(monster->getSpeed());
		bool moving = true;
		bool stopIt = false;
		if (monster->getTag() == "RED" && rand()%600 == 2)
		{
			monster->setSpeedY(20);
		}
		else if (monster->getTag() == "RED")
		{
			monster->setSpeedY(0);
		}
		if (monster->getPositionY() > vScreen.getVectorY())
		{
			wave += 0.1f;
			loadWave(monster,(int)wave,whatAI,vScreen);
		}
		if (!player1.detectCollision(monster->getPosition(),monster->getHeight(),monster->getWidth()))
		{
			if (monster->getTag() == "GREEN" && power.getTag() != "FROZEN")
			{
				power.setTag("VENOM");
				healthIcon.setSprite(CreateSprite( "./images/healthbarV.png", 50 * iLives, 25, true ));
			}
			monster->setAlive(false);
			updateLives(powerUp,iLives,vScreen,healthIcon,player1);
			loadWave(monster,(int)wave,whatAI,vScreen);
		}
		else if (!beam.detectCollisionA(monster->getPosition(),monster->getHeight(),monster->getWidth()))
		{
			monster->setAlive(false);
			loadWave(monster,(int)wave,whatAI,vScreen);
		}
		if (monster->position.getVectorX() + plannedMovement.getVectorX() < 20 || monster->position.getVectorX() + plannedMovement.getVectorX() > 1260)
			moving = false;
		std::list<Bullet>::const_iterator cIter;
		std::list<Bullet>::const_iterator cIterTemp;
		try
		{
		if (!bullet_list.empty())
		for ( cIter = bullet_list.begin( ); cIter != bullet_list.end( ); cIter++ )
		{
			bool cIterAlive = true;
 			if(!(*cIter).detectCollision((*cIter).getPosition(),monster->position,monster->getHeight(),monster->getWidth()))
			{
				cIterTemp = cIter;
				monster->setAlive(false);
				bullet_list.erase(cIterTemp);
				//(*cIter).setAlive(false);
				loadWave(monster,(int) wave,whatAI,vScreen);
				cIterAlive = false;
				break;
			}
			if (cIterAlive)
				if (!(*cIter).detectCollision((*cIter).getPosition(),boss.getPosition(),boss.getHeight(),boss.getWidth()))
				{
					cIterTemp = cIter;
					boss.lowerHealth(2);
					bullet_list.erase(cIterTemp);
					//(*cIter).setAlive(false);
					break;
				}
		}
		}
		catch(int e){}
		if (!beam.detectCollisionA(boss.getPosition(),boss.getHeight(),boss.getWidth()))
		{
			boss.lowerHealth(0.01f);
		}
		if (moving && !stopIt)
			monster->position.vectorAdd(plannedMovement);
		else
			monster->speed.multiplyScalarX(-1);
	}
	if (boss.getLaunch() && !monster->getAlive())
	{
		boss.setLaunch(false);
		monster->setAlive(false);
		loadAIC(monster,rand()%4,vScreen);
	}
}
void updateAiC(Sprite monster,Sprite &power, int &iLives,int &whatAI,float &wave,Vector &vScreen,Sprite &beam,Boss &boss,Sprite &healthIcon,Sprite &player1,Sprite &powerUp){
	if (monster.getAlive())
	{
		Vector plannedMovement;
		plannedMovement.vectorAdd(monster.getSpeed());
		bool moving = true;
		bool stopIt = false;
		if (monster.getTag() == "RED" && rand()%600 == 2)
		{
			monster.setSpeedY(20);
		}
		else if (monster.getTag() == "RED")
		{
			monster.setSpeedY(0);
		}
		if (monster.getPositionY() > vScreen.getVectorY())
		{
			wave += 0.1f;
			loadWave(monster,(int)wave,whatAI,vScreen);
		}
		if (!player1.detectCollision(monster.getPosition(),monster.getHeight(),monster.getWidth()))
		{
			if (monster.getTag() == "GREEN" && power.getTag() != "FROZEN")
			{
				power.setTag("VENOM");
				healthIcon.setSprite(CreateSprite( "./images/healthbarV.png", 50 * iLives, 25, true ));
			}
			monster.setAlive(false);
			updateLives(powerUp,iLives,vScreen,healthIcon,player1);
			loadWave(monster,(int)wave,whatAI,vScreen);
		}
		else if (!beam.detectCollisionA(monster.getPosition(),monster.getHeight(),monster.getWidth()))
		{
			monster.setAlive(false);
			loadWave(monster,(int)wave,whatAI,vScreen);
		}
		if (monster.position.getVectorX() + plannedMovement.getVectorX() < 20 || monster.position.getVectorX() + plannedMovement.getVectorX() > 1260)
			moving = false;
		std::list<Bullet>::const_iterator cIter;
		std::list<Bullet>::const_iterator cIterTemp;
		try
		{
		if (!bullet_list.empty())
		for ( cIter = bullet_list.begin( ); cIter != bullet_list.end( ); cIter++ )
		{
			bool cIterAlive = true;
 			if(!(*cIter).detectCollision((*cIter).getPosition(),monster.position,monster.getHeight(),monster.getWidth()))
			{
				cIterTemp = cIter;
				monster.setAlive(false);
				bullet_list.erase(cIterTemp);
				//(*cIter).setAlive(false);
				loadWave(monster,(int) wave,whatAI,vScreen);
				cIterAlive = false;
				break;
			}
			if (cIterAlive)
				if (!(*cIter).detectCollision((*cIter).getPosition(),boss.getPosition(),boss.getHeight(),boss.getWidth()))
				{
					cIterTemp = cIter;
					boss.lowerHealth(2);
					bullet_list.erase(cIterTemp);
					//(*cIter).setAlive(false);
					break;
				}
		}
		}
		catch(int e){}
		if (!beam.detectCollisionA(boss.getPosition(),boss.getHeight(),boss.getWidth()))
		{
			boss.lowerHealth(0.01f);
		}
		if (moving && !stopIt)
			monster.position.vectorAdd(plannedMovement);
		else
			monster.speed.multiplyScalarX(-1);
	}
	if (boss.getLaunch() && !monster.getAlive())
	{
		boss.setLaunch(false);
		monster.setAlive(false);
		loadAIC(monster,rand()%4,vScreen);
	}
	return;
}

//////////////////////////////////////////////////////////////////////////
/// <Updates the two moving screens>
///
/// <Checks if it has passed the end of the screen and then moves it>
///
/// @param Vector,movableObject,movableObject
/// @return void
//////////////////////////////////////////////////////////////////////////
void updateScreen(Vector &vScreen,movableObject &screen,movableObject &screenTwo)
{
	screen.position.vectorAdd(screen.speed);
	MoveSprite(screen.sprite, (int)screen.position.getVectorX(), (int)screen.position.getVectorY());
	if (screen.position.getVectorY() >= vScreen.getVectorY())
		screen.position.vectorSetY(-vScreen.getVectorY()*2);
	screenTwo.position.vectorAdd(screenTwo.speed);
	MoveSprite(screenTwo.sprite, (int)screenTwo.position.getVectorX(), (int)screenTwo.position.getVectorY());
	if (screenTwo.position.getVectorY() >= vScreen.getVectorY())
		screenTwo.position.vectorSetY(-vScreen.getVectorY()*2);
}

//////////////////////////////////////////////////////////////////////////
/// <Load Game>
///
/// <Runs all the load functions, sets the basic variables for all the classes, and initializes all the objects>
///
/// @param  Int,Vector,moveableObject,moveableObject,Sprite,Boss,Sprite,Sprite,Sprite,Sprite
/// @return void
//////////////////////////////////////////////////////////////////////////
void loadGame(int &iLives,Vector &vScreen,movableObject &screen,movableObject &screenTwo,Sprite &beam,Boss &boss,Sprite &healthIcon,Sprite &player1,Sprite &powerUp,Sprite &target) {
	srand((int)time(0));

	loadLevel(1,powerUp);

	boss.loadBoss();

	screen.position.vectorSetX(0);
	screen.position.vectorSetY(-vScreen.getVectorY()*2);
	screen.sprite = CreateSprite( "./images/bg2.png", (int)vScreen.getVectorX(), (int)vScreen.getVectorY()*3,false );
	MoveSprite(screen.sprite, (int)screen.position.getVectorX(), (int)screen.position.getVectorY());

	screenTwo.position.vectorSetX(0);
	screenTwo.position.vectorSetY(-vScreen.getVectorY()*7.2f);
	screenTwo.sprite = CreateSprite( "./images/bg2.png", (int)vScreen.getVectorX(), (int)vScreen.getVectorY()*6,false );
	MoveSprite(screenTwo.sprite, (int)screenTwo.position.getVectorX(), (int)screenTwo.position.getVectorY());

	setSprite('L',CreateSprite( "./images/lose.png", 400, 300, true ));
	setSprite('E',CreateSprite( "./images/exit.png", 400, 300, true ));
	setSprite('P',CreateSprite( "./images/play.png", 400, 300, true ));
	setSprite('W',CreateSprite( "./images/win.png", 400, 300, true ));
	setSprite('T',CreateSprite( "./images/stats.png", 760, 470, true ));
	MoveSprite(getSprite('T'),(int)vScreen.getVectorX()/2,(int)vScreen.getVectorX()/2);

	healthIcon.setSprite(CreateSprite( "./images/healthbar.png", 50 * iLives, 25, true ));

	beam.setSprite(CreateSprite( "./images/beam.png", 760, 50, true ));
	RotateSprite(beam.getSprite(),90);

	powerUp.setSprite( CreateSprite( "./images/shield.png", 50, 50, true ));

	player1.setSprite( CreateSprite( "./images/player.png", 20, 20, true ));

	target.setSprite( CreateSprite( "./images/flag.png", 50, 50, true ));
	std::list<Sprite>::const_iterator cIter;
	for ( cIter = monster_list.begin( ); cIter != monster_list.end( ); cIter++ )
	{
		cIter->setSprite( CreateSprite( "./images/enemy.png", 20, 20, true ));
	}
	//for (int i = 0; i <= 19; i++)
		//monster[i].setSprite( CreateSprite( "./images/enemy.png", 20, 20, true ));
	bullet.loadBullet();
}

//////////////////////////////////////////////////////////////////////////
/// <Ends the game>
///
/// <Removes all sprites and data that is stored>
///
/// @param  moveableObject,moveableObject,Sprite,Boss,Sprite,Sprite,Sprite,Sprite
/// @return void
//////////////////////////////////////////////////////////////////////////
void endGame(movableObject &screen,movableObject &screenTwo,Sprite &beam,Boss &boss,Sprite &healthIcon,Sprite &player1,Sprite &powerUp,Sprite &target) {
	boss.endBoss();
	DestroySprite(screen.sprite);
	player1.endSprite();
	target.endSprite();
	powerUp.endSprite();
	std::list<Sprite>::const_iterator cIter;
	for ( cIter = monster_list.begin( ); cIter != monster_list.end( ); cIter++ )
	{
		cIter->endSprite();
	}
	healthIcon.endSprite();
	beam.endSprite();
	DestroySprite(screen.sprite);
	DestroySprite(screenTwo.sprite);

	bullet.endBullet();
	endItems();
}

//////////////////////////////////////////////////////////////////////////
/// <Updates Level>
///
/// <Moves the mouse and changes the ship choice>
///
/// @param  int,int,vector,sprite,sprite,sprite,vector,sprite
/// @return void
//////////////////////////////////////////////////////////////////////////
void updateLevel(int &level, int &iLives,Vector &vScreen,Sprite &healthIcon,Sprite &player1,Sprite &powerUp,Vector &vMouse,Sprite &target)
{
	int mX;
	int mY;
	GetMouseLocation(mX,mY);
	vMouse.vectorSetX((float)mX);
	vMouse.vectorSetY((float)mY);
	target.moveTarget(vMouse);

	if (level == 8)
	{
		if (IsKeyDown(GLFW_KEY_SPACE))
		{
			setUp(false);
			updateLives(powerUp,iLives,vScreen,healthIcon,player1);
			player1.setInv(0);
			if (getTag() == "BASIC")
			{
				player1.setSpeedX(1);
				player1.setSpeedY(1);
			}
			else
			{
				iLives = 5;
				player1.setSpeedX(1.5f);
				player1.setSpeedY(1.5f);
			}
		}
		if (IsKeyDown('A'))
		{
			setTag("BASIC");
			player1.setSprite( CreateSprite( "./images/player.png", 20, 20, true ));
		}
		else if (IsKeyDown('D'))
		{
			player1.setSprite( CreateSprite( "./images/playerF.png", 20, 20, true ));
			setTag("FAST");
		}
		MoveSprite(player1.getSprite(),432,300);
	}
}

//////////////////////////////////////////////////////////////////////////
/// <Updates everything else>
///
/// <Runs the update functions for every class>
///
/// @param  int ,int, int,int,float,Vector,Vector,bool,movableObject,movableObject,Sprite,Boss,Sprite,Sprite,Sprite,Sprite
/// @return void
//////////////////////////////////////////////////////////////////////////
void updateGame(int &iLives,int &whatBullet, int &whatAI,float &wave,Vector &vMouse,Vector &vScreen,bool &pressTrigger,movableObject &screen,movableObject &screenTwo,Sprite &beam,Boss &boss,Sprite &healthIcon,Sprite &player1,Sprite &powerUp,Sprite &target) {
	
	if (iLives == 9)
	{
		if ((IsKeyDown(GLFW_KEY_ENTER)) ||(vMouse.getVectorX() >= 100 && vMouse.getVectorX() <= 500 && vMouse.getVectorY() >= 50 && vMouse.getVectorY() <= 350 && GetMouseButtonDown(0))){
			player1.setInv(0);
			updateLives(powerUp,iLives,vScreen,healthIcon,player1);
			player1.setInv(0);
			wave++;
			PlaySound("./sounds/Blop.wav",NULL,SND_ASYNC);
			setUp(true);
		}
		if ((IsKeyDown(GLFW_KEY_BACKSPACE)) ||(vMouse.getVectorX() >= 300 && vMouse.getVectorX() <= 700 && vMouse.getVectorY() >= 350 && vMouse.getVectorY() <= 650 && GetMouseButtonDown(0))){
			iLives = -1;
		}
		MoveSprite(getSprite('P'),(int)300,(int)200);
		MoveSprite(getSprite('E'),(int)500,(int)500);
	}
	else if (iLives <= 0)
	{
		MoveSprite(getSprite('L'),(int)vScreen.getVectorX()/2,(int)vScreen.getVectorY()/2);
		MoveSprite(getSprite('W'),(int)500,(int)500);
		if (IsKeyDown(' '))
			updateLives(powerUp,iLives,vScreen,healthIcon,player1);
	}
	else
	{
		bullet.updateBullet(bullet.getAngle(),bullet.getPosition(),bullet.getAlive(),bullet.getSprite());
		if (!bullet_list.empty())
		{
			std::list<Bullet>::const_iterator cIter;
			for ( cIter = bullet_list.begin( ); cIter != bullet_list.end( ); cIter++ )
			{
				cIter->updateBullet(cIter->getAngle(),cIter->getPosition(),cIter->getAlive(),cIter->getSprite());
				MoveSprite(cIter->getSprite(),cIter->getPosition().getVectorX(),cIter->getPosition().getVectorY());
			}
		}

		fireBullet(player1,whatBullet,pressTrigger,vMouse,beam,player1);
		updatePlayer(player1,iLives,vScreen,boss,healthIcon,player1,powerUp);
		updateScreen(vScreen,screen,screenTwo);
		updatePowerUp(powerUp,iLives,vScreen,healthIcon,player1);
		beam.updateBeam(player1.position);
		healthIcon.updateSprite();
		beam.updateSprite();
		boss.updateBoss();
		boss.setPlayerPosition(player1.getPosition());
		player1.updateSprite();
		if(wave >= 3)
			boss.moveWave();
		if (!monster_list.empty())
		{
			std::list<Sprite>::const_iterator cIter;
			for ( cIter = monster_list.begin( ); cIter != monster_list.end( ); cIter++ )
			{
				updateAiC(*cIter,powerUp,iLives,whatAI,wave,vScreen,beam,boss,healthIcon,player1,powerUp);
				if (cIter->getAlive())
					cIter->updateSprite();
			}
		}
		sideLoadAI();
	}
}

//////////////////////////////////////////////////////////////////////////
/// <Draws everything to the screen>
///
/// <Runs the draw functions for every class>
///
/// @param  int,movableObject,movableObject,Sprite,Boss,Sprite,Sprite,Sprite,Sprite
/// @return void
//////////////////////////////////////////////////////////////////////////
void drawGame(int &iLives,movableObject &screen,movableObject &screenTwo,Sprite &beam,Boss &boss,Sprite &healthIcon,Sprite &player1,Sprite &powerUp,Sprite &target) {

	target.drawSprite();

	if (iLives == 9)
	{
		DrawSprite(getSprite('P'));
		DrawSprite(getSprite('E'));
	}
	else if (iLives == 8)
	{
		player1.drawSprite();
		drawStat(iLives);
	}
	else if (iLives <= 0)
	{
		DrawSprite(getSprite('L'));
	}
	else
	{
		drawStat(iLives);
		powerUp.drawSprite();
		player1.drawSprite();
		healthIcon.drawSprite();
		if (beam.getAlive())
			beam.drawSprite();
		boss.drawBoss();
		if (!monster_list.empty())
		{
		std::list<Sprite>::const_iterator cIter;
			for ( cIter = monster_list.begin( ); cIter != monster_list.end( ); cIter++ )
			{
				if (cIter->getAlive())
					(*cIter).drawSprite();
			}
			monster.drawSprite();
		}
		if (!bullet_list.empty())
		{
		std::list<Bullet>::const_iterator cIter;
			for ( cIter = bullet_list.begin( ); cIter != bullet_list.end( ); cIter++ )
			{
				(*cIter).drawBullet();
			}
			bullet.drawBullet();
		}
	}
	DrawSprite(screen.sprite);
	DrawSprite(screenTwo.sprite);
}


int main()
{
	//Amount of hits the player can take
	int iLives = 9;

	//What bullet is going to be shot
	int whatBullet = 0;

	//What AI is going to be spawned
	int whatAI = 0;

	//Determine when to place certain enemies
	float wave = 0;

	//Player angle is no longer used (yet)
	//float playerAngle = 0;

	//Determine if the right mouse button is being pressed (false == no)
	bool pressTrigger = false;

	//The moving backgrounds
	movableObject screen;
	movableObject screenTwo;
	screen.speed.vectorSet(0,0.05f);
	screenTwo.speed.vectorSet(0,0.05f);

	//The screen size
	Vector vScreen;

	//Where the mouse is
	Vector vMouse;

	//Sets the screen size (need to do it here so the screen init right)
	vScreen.vectorSet(1280,780);

	//The beam that the basic player uses
	Sprite beam(false,false,100,780,0,"",0,-1000,-1000);

	//The player
	Sprite player1(false,false,5,5,0,"BASIC",0,500,300);

	//The health bar
	Sprite healthIcon(true,true,52,52,NULL,"",NULL,200,50);

	//The power up
	Sprite powerUp(false,true,100,100,NULL,"",NULL,0,0);

	//The marker for the mouse
	Sprite target(true,true,50,50,NULL,"",NULL,0,0);

	//Sets what ship is being used.
	setTag("BASIC");

	//The boss
	Boss boss;

	//The volume levels
	//OFF = 0,
	//LOW = 858993459,
	//NORMAL = 1717986918,
	//MEDIUM = -1717986919,
	//HIGH = -858993460,
	//VERY_HIGH = -1
	//Sets the volume at a decent level
	waveOutSetVolume(0, 8000);


	//Sets the cursor not to show(must be called before Initialise runs)
	ShowCursor(FALSE); 
	// First we need to initialize our Game Framework
	Initialise((int)vScreen.getVectorX(), (int)vScreen.getVectorY(), false );

	//Loads all the game assets
	loadGame(iLives,vScreen,screen,screenTwo,beam,boss,healthIcon,player1,powerUp,target);

	enum GAMESTATE { UPDATEGAME,UPDATELEVEL,DRAWGAME};
	GAMESTATE currentState = UPDATEGAME;

	//The game loop
	while (!FrameworkUpdate() && iLives != -1)
	{
		switch(currentState)
		{
		case UPDATEGAME:
			if (!getUp())
				updateGame(iLives,whatBullet,whatAI,wave,vMouse,vScreen,pressTrigger,screen,screenTwo,beam,boss,healthIcon,player1,powerUp,target);
			currentState = UPDATELEVEL;
			break;
		case UPDATELEVEL:
			updateLevel(iLives,iLives,vScreen,healthIcon,player1,powerUp,vMouse,target);
			currentState = DRAWGAME;
			break;
		case DRAWGAME:
			ClearScreen();
			drawGame(iLives,screen,screenTwo,beam,boss,healthIcon,player1,powerUp,target);
			currentState = UPDATEGAME;
			break;
		}
	};

	//Deletes all the memory and data used
	endGame(screen,screenTwo,beam,boss,healthIcon,player1,powerUp,target);

	//Ends the framework
	Shutdown();

	return 0;
}
//
//The game loop
// 	while (!FrameworkUpdate() && iLives != -1)
// 	{
// 		//Clears the screen before the draw
// 		ClearScreen();
// 
// 		//Checks if the game is paused, if not then update the game
// 		if (!getUp())
// 			updateGame(iLives,whatBullet,whatAI,wave,vMouse,vScreen,pressTrigger,screen,screenTwo,beam,boss,healthIcon,player1,powerUp,target);
// 
// 		//if in the choose ship part then let the player choose what ship
// 		updateLevel(iLives,iLives,vScreen,healthIcon,player1,powerUp,vMouse,target);
// 
// 		//Draws all the sprites
// 		drawGame(iLives,screen,screenTwo,beam,boss,healthIcon,player1,powerUp,target);
// 	};