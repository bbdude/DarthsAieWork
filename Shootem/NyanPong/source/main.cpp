//////////////////////////////////////////////////////////////////////////
//	Author:	Jacob Miller
//	Date:	09/13/2013
//	Brief:	Main file for Pong
//////////////////////////////////////////////////////////////////////////
#define _USE_MATH_DEFINES
//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include "KeyCodes.h"
#include "Boss.h"
#include "MenuItems.h"
#include "windows.h"
#include "Vector.h"
#include "Sprite.h"
#include "Bullet.h"
#include <string>
#include <cmath>
#include <assert.h>
#include <crtdbg.h>
#include <ctime>
#include <iostream>
#include <list>
#include <exception>
//////////////////////////////////////////////////////////////////////////
struct movableObject{
	Vector position;
	Vector speed;
	int sprite;
	int width;
	int height;
	bool alive;
	std::string tag;
};
//Declarations
//Player Lives
int iLives = 9;
int whatBullet = 0;
int whatAI = 0;
int whatExplosion = 0;
float wave = 0;
float playerAngle = 0;
bool pressTrigger = false;
Vector vScreen;
Vector vMouse;
//200,50,{-1,52,52,true,8000}
Sprite beam;
Sprite healthIcon;
Bullet bullet[50];
Sprite monster[20];
Sprite explosion[20];
Sprite powerUp;
Sprite player1;
Sprite target;
movableObject screen;
movableObject screenTwo;
Boss boss;
void loadAI(Sprite &obj,int type)
{
switch(type)
	{
	case 1:
			obj.setAlive(true);
			obj.setHeight(40);
			obj.setSprite(CreateSprite("./images/enemyB.png", 40, 40, true ));
			obj.setWidth(40);
			obj.setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
			obj.setSpeed((rand() % 5) - 2.5f,0.25f);
			obj.setTag("BLUE");
			break;
		case 2:
			obj.setAlive(true);
			obj.setHeight(35);
			obj.setSprite(CreateSprite( "./images/enemyG.png", 20, 35, true ));
			obj.setWidth(20);
			obj.setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,100);
			//obj.setPosition(200,200);
			//obj.setSpeed(0.25f,0);
			obj.setSpeed(0,0.25f);
			obj.setTag("GREEN");
			break;
		case 3:
			obj.setAlive(true);
			obj.setHeight(10);
			obj.setSprite(CreateSprite( "./images/enemyR.png", 10, 10, true ));
			obj.setWidth(10);
			obj.setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
			obj.setSpeed(0.28f,0.1f);
			obj.setTag("RED");
			break;
		default:
			obj.setAlive(true);
			obj.setHeight(20);
			obj.setSprite(CreateSprite( "./images/enemyR.png", 10, 10, true ));
			obj.setWidth(20);
			obj.setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
			obj.setSpeed((float)(rand() % 5) - 2.5f,0.7f);
			obj.setTag("PINK");
			break;
		}
}
void sideLoadAI()
{
	int range = 0;
	switch(rand()% 1000)
	{
	case 50:
		for(int i = 0; i <= 19; i++)
		{
			if (!monster[i].getAlive() || monster[i].position.getVectorY() < 0)
			{
				range++;
				monster[i].setPosition((float)1260,(float)(-20 + (50*range)));
				monster[i].setSpeed(0.5f,0.5f);
				monster[i].setAlive(true);
			}
			if (range >= 3)
				return;
		}
		//for(int i = 0; i 
		break;
	case 100:
		for(int i = 0; i <= 19; i++)
		{
			if (!monster[i].getAlive() || monster[i].position.getVectorY() < 0)
			{
				range++;
				monster[i].setPosition(20,(float)(-20 + (50*range)));
				monster[i].setSpeed(0.5f,0.5f);
				monster[i].setAlive(true);
			}
			if (range >= 3)
				return;
		}
		//for(int i = 0; i 
		break;
	case 150:
		for(int i = 0; i <= 19; i++)
		{
			if (!monster[i].getAlive() || monster[i].position.getVectorY() < 0)
			{
				range++;
				monster[i].setPosition((float)(1260 - (rand() % 200)),(float)(-20 - (50*range)));
				monster[i].setSpeed(0,0.6f);
				monster[i].setAlive(true);
			}
			if (range >= 3)
				return;
		}
		//for(int i = 0; i 
		
	case 200:
		for(int i = 0; i <= 19; i++)
		{
			if (!monster[i].getAlive() || monster[i].position.getVectorY() < 0)
			{
				range++;
				monster[i].setPosition((float)(rand() % 200) + 100,(float)-20 - (50*range));
				monster[i].setSpeed(0,0.6f);
				monster[i].setAlive(true);
			}
			if (range >= 3)
				return;
		}
		//for(int i = 0; i 
		
		break;
	}
}
void loadLevel(int level)
{
	powerUp.setAlive(false);
	powerUp.setHeight(100);
	powerUp.setSprite(-1);
	powerUp.setWidth(100);
	powerUp.setSpeed((rand() % 5) - 2.5f,0.7f);
	powerUp.setPosition(-200,-200);
	powerUp.setTag("PINK");
	switch (level)
	{
	case 1:
		
		
		//player1.position.x = bricks[23][13].position.x;// + 25;
		//player1.position.y = bricks[23][13].position.y;// + 25;
		for (int i = 0; i <= 19; i++)
		{
			monster[i].setAlive(false);
			monster[i].setHeight(20);
			monster[i].setSprite(-1);
			monster[i].setWidth(20);
			monster[i].setSpeed((rand() % 5) - 2.5f,0.7f);
			monster[i].setPosition(-200,-200);
			monster[i].setTag("PINK");
		}
		monster[0].setPosition(50,50);
		monster[1].setPosition(100,100);
		monster[2].setPosition(150,150);
		monster[0].setAlive(true);
		monster[1].setAlive(true);
		monster[2].setAlive(true);
		break;
	case 2:
		monster[3].setPosition(200,-20);
		monster[3].setAlive(true);
		monster[3].setHeight(20);
		monster[3].setSprite(CreateSprite( "./images/enemyB.png", 40, 40, true ));
		monster[3].setWidth(20);
		monster[3].setSpeed((rand() % 5) - 2.5f,0.25f);
		monster[3].setPosition(-200,-200);
		monster[3].setTag("PINK");
		break;
	default:
		break;
	}

}
void loadWave(Sprite &obj,int wave)
{
	whatAI++;
	if (whatAI >= 40)
		whatAI = 0;
	for (int i = whatAI/2; i >= 0; i--)
	{
		if (!monster[i].getAlive())
			switch(rand() % 10)
			{
			case 2:
			case 1:
				monster[i].setAlive(true);
				monster[i].setHeight(40);
				monster[i].setSprite(CreateSprite("./images/enemyB.png", 40, 40, true ));
				monster[i].setWidth(40);
				monster[i].setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
				monster[i].setSpeed((rand() % 5) - 2.5f,0.25f);
				monster[i].setTag("BLUE");
				break;
			case 3:
			case 4:
				monster[i].setAlive(true);
				monster[i].setHeight(35);
				monster[i].setSprite(CreateSprite( "./images/enemyG.png", 20, 35, true ));
				monster[i].setWidth(20);
				monster[i].setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
				monster[i].setSpeed(0.25f,0);
				monster[i].setTag("GREEN");
				break;
			case 5:
			case 6:
				monster[i].setAlive(true);
				monster[i].setHeight(10);
				monster[i].setSprite(CreateSprite( "./images/enemyR.png", 10, 10, true ));
				monster[i].setWidth(10);
				monster[i].setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
				monster[i].setSpeed(0.28f,0.1f);
				monster[i].setTag("RED");
				break;
			default:
				monster[i].setAlive(true);
				monster[i].setHeight(20);
				monster[i].setSprite(CreateSprite( "./images/enemyR.png", 10, 10, true ));
				monster[i].setWidth(20);
				monster[i].setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
				monster[i].setSpeed((float)(rand() % 5) - 2.5f,0.7f);
				monster[i].setTag("PINK");
				break;
			}
	}
	switch(wave)
	{
	case 1:
			obj.setAlive(true);
			obj.setHeight(40);
			obj.setSprite(CreateSprite("./images/enemyB.png", 40, 40, true ));
			obj.setWidth(40);
			obj.setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
			obj.setSpeed((rand() % 5) - 2.5f,0.25f);
			obj.setTag("BLUE");
			break;
		case 2:
			obj.setAlive(true);
			obj.setHeight(35);
			obj.setSprite(CreateSprite( "./images/enemyG.png", 20, 35, true ));
			obj.setWidth(20);
			obj.setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
			obj.setSpeed(0.25f,0);
			obj.setTag("GREEN");
			break;
		case 3:
			obj.setAlive(true);
			obj.setHeight(10);
			obj.setSprite(CreateSprite( "./images/enemyR.png", 10, 10, true ));
			obj.setWidth(10);
			obj.setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
			obj.setSpeed(0.28f,0.1f);
			obj.setTag("RED");
			break;
		default:
			obj.setAlive(true);
			obj.setHeight(20);
			obj.setSprite(CreateSprite( "./images/enemyR.png", 10, 10, true ));
			obj.setWidth(20);
			obj.setPosition((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20,-20);
			obj.setSpeed((float)(rand() % 5) - 2.5f,0.7f);
			obj.setTag("PINK");
			break;
		}
}
void loadVectors()
{

	player1.setHeight(5);
	player1.setSprite(-1);
	player1.setWidth(5);
	player1.setSpeed(1,1);
	player1.setPosition(500,300);
	player1.setTag("BASIC");
	player1.setInv(0);

	target.setAlive(true);
	target.setHeight(50);
	target.setSprite(-1);
	target.setWidth(50);
	target.setSpeed(0,0);
	target.setPosition(0,0);

	screen.alive = true;
	screen.height = 780;
	screen.width = 3840;
	screen.position.vectorSet(0,0);
	screen.speed.vectorSet(0,0.05f);
	screen.sprite = -1;
	screenTwo.alive = true;
	screenTwo.height = 780;
	screenTwo.width = 3840;
	screenTwo.position.vectorSet(0,0);
	screenTwo.speed.vectorSet(0,0.05f);
	screenTwo.sprite = -1;
	vScreen.vectorSet(1280,780);
	vMouse.vectorSet(0,0);
	healthIcon.setAlive(true);
	healthIcon.setHeight(52);
	healthIcon.setPosition(200,50);
	healthIcon.setSprite(-1);
	healthIcon.setWidth(52);
	beam.setAlive(false);
	beam.setFire(false);
	beam.setHeight(780);
	beam.setWidth(100);
	beam.setPosition(-1000,-1000);
	beam.setSprite(-1);
	beam.setWidth(100);
	beam.setTime(0);

	powerUp.setAlive(false);
	powerUp.setHeight(100);
	powerUp.setWidth(100);
	powerUp.setPosition(0,0);
	
}
void fireBullet(Sprite &player)
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
			 //PlaySound("shoot.wav", NULL, SND_ASYNC);
		}
		catch(std::bad_alloc)
		{
		}
		bullet[whatBullet].setBulletAngle(player.getPosition(),vMouse);
		whatBullet++;
		if (whatBullet == 50)
			whatBullet = 0;
		pressTrigger = false;
	}
	if (GetMouseButtonDown(2))
	{
		player.lineBeam = !player.lineBeam;
	}
	else if (player.lineBeam)
	{
		//RED::65535
		//DARKRED::32255
		//GREEN::16711680
		//LIMEGREEN::16711935
		//Yellow::16777215
		SColour lineColorEnd(65535);
		SColour lineColorStart(16777215);
		//SColour lineColorEnd('9','`','0','0');
		DrawLine((int)player.position.getVectorX(),(int)player.position.getVectorY(),(int)vMouse.getVectorX(),(int)vMouse.getVectorY(),lineColorStart,lineColorEnd);

		bullet[whatBullet].setBulletAngle(player.getPosition(),vMouse);
		whatBullet++;
		if (whatBullet == 50)
			whatBullet = 0;
		pressTrigger = false;
	}
}

void updateLives(Sprite &power)
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
void updatePlayer(Sprite &player){

	Vector plannedMovement;
	if (IsKeyDown('W') && player.getPositionY() - (player.getHeight()/2) - player.getSpeedY() >= 0)
	{
		plannedMovement.vectorSetY(plannedMovement.getVectorY() - player.getSpeedY());
		//player.position.y -= player.speed.y;
	}
	if (IsKeyDown('S') && player.getPositionY() + (player.getHeight()/2) + player.getSpeedY() <= vScreen.getVectorY())
	{
		plannedMovement.vectorSetY(plannedMovement.getVectorY() + player.getSpeedY());
		//player.position.y += player.speed.y;
	}
	if (IsKeyDown('A') && player.getPositionX() - (player.getWidth()/2) - player.getSpeedX() >= 0)
	{
		plannedMovement.vectorSetX(plannedMovement.getVectorX() - player.getSpeedX());
		//player.position.x -= player.speed.x;
	}
	if (IsKeyDown('D') && player.getPositionX() + (player.getWidth()/2) + player.getSpeedX() <= vScreen.getVectorX())
	{
		plannedMovement.vectorSetX(plannedMovement.getVectorX() + player.getSpeedX());
		//player.position.x += player.speed.x;
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
		updateLives(powerUp);
	if (!player.detectCollision(boss.getPosition(),boss.getHeight(),boss.getWidth()))
		updateLives(powerUp);
	if (player.getInv() == 1500)
		player1.setSprite( CreateSprite( "./images/playerVoid.png", 20, 20, true ));

	if (player.getInv() > 0)
	{
		player.setInv(player1.getInv()-1);
		if (player.getInv() == 0)
			player1.setSprite( CreateSprite( "./images/player.png", 20, 20, true ));

	}
}

float getPlayerAngle(Sprite &player)
{
	float angle = std::atan2 ( (vScreen.getVectorY() - vMouse.getVectorY()) - player.position.getVectorY(), vMouse.getVectorX() - player.position.getVectorX()) * 57.2957795f; //57... is 180/pi

	return angle;
	//return std::tan((vMouse.getVectorY()-player.position.getVectorY())/(vMouse.getVectorX()-player.position.getVectorX()))*57.2957795f;
}
void explodeAi(Sprite &monster)
{
	PlaySound("./sounds/boom.wav",NULL,SND_ASYNC);
	std::cout << "Explode AI";
	whatExplosion++;
	if (whatExplosion >= 20)
		whatExplosion = 0;
	explosion[whatExplosion].setPosition(monster.position);
	explosion[whatExplosion].setSpeed(0,monster.speed.getVectorY()/1.2f);
	explosion[whatExplosion].setSprite(CreateSprite( "./images/explosion.png", monster.getWidth(), monster.getHeight(), true ));
}
void updatePowerUp(Sprite &power)
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
			//power.tag = "VENOM";
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
		//power.tag = "PINK";
	}
}
void updateAi(Sprite &monster,Sprite &power){
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
			loadWave(monster,(int)wave);
		}
		if (!player1.detectCollision(monster.getPosition(),monster.getHeight(),monster.getWidth()))
		{
			if (monster.getTag() == "GREEN" && power.getTag() != "FROZEN")
			{
				power.setTag("VENOM");
				healthIcon.setSprite(CreateSprite( "./images/healthbarV.png", 50 * iLives, 25, true ));
			}
			monster.setAlive(false);
			explodeAi(monster);
			updateLives(powerUp);
			loadWave(monster,(int)wave);
		}
		else if (!beam.detectCollisionA(monster.getPosition(),monster.getHeight(),monster.getWidth()))
		{ 
			explodeAi(monster);
			monster.setAlive(false);
			loadWave(monster,(int)wave);
		}
		if (monster.position.getVectorX() + plannedMovement.getVectorX() < 20 || monster.position.getVectorX() + plannedMovement.getVectorX() > 1260)
			moving = false;
		for (int i = 0; i < 49; i++){
			if (!bullet[i].detectCollision(monster.position,monster.getHeight(),monster.getWidth()))
			{
				monster.setAlive(false);
				bullet[i].setAlive(false);
				explodeAi(monster);
				loadWave(monster,(int)wave);

			}
			if (!bullet[i].detectCollision(boss.getPosition(),boss.getHeight(),boss.getWidth()))
			{
				boss.lowerHealth(2);
				bullet[i].setAlive(false);
			}
		}
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
		loadAI(monster,rand()%4);
		//loadAI(monster,2);
	}
	
}
void updateExplosion(Sprite &explosion)
{
	explosion.position.vectorAdd(explosion.speed);
}
void updateScreen()
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
void loadGame() {
	srand((int)time(0));
	//fillBulletStruct();
	// Now load some sprites
	loadLevel(1);
	boss.loadBoss();
	screen.position.vectorSetX(0);
	screen.position.vectorSetY(-vScreen.getVectorY()*2);
	screen.sprite = CreateSprite( "./images/bg2.png", (int)vScreen.getVectorX(), (int)vScreen.getVectorY()*3,false );
	//MoveSprite(screen.sprite, iScreenX>>1, iScreenY>>1);
	MoveSprite(screen.sprite, (int)screen.position.getVectorX(), (int)screen.position.getVectorY());
	screenTwo.position.vectorSetX(0);
	screenTwo.position.vectorSetY(-vScreen.getVectorY()*2);
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
	for (int i = 0; i <= 19; i++)
		monster[i].setSprite( CreateSprite( "./images/enemy.png", 20, 20, true ));
	for (int i = 0; i <= 19; i++)
		explosion[i].setSprite( CreateSprite( "./images/explosion.png", 20, 20, true ));
	for (int i = 0; i < 50; i++)
		bullet[i].loadBullet();
}
void endGame() {
	boss.endBoss();
	DestroySprite(screen.sprite);
	player1.endSprite();
	target.endSprite();
	powerUp.endSprite();
	for (int i = 0; i <= 19; i++)
	{
		monster[i].endSprite();
		explosion[i].endSprite();
	}
	healthIcon.endSprite();
	beam.endSprite();
	DestroySprite(screen.sprite);
	DestroySprite(screenTwo.sprite);

	for (int i = 0; i < 50; i++)
		bullet[i].endBullet();

	//DestroySprite(getSprite('L'));
	//DestroySprite(getSprite('E'));
	//DestroySprite(getSprite('P'));
	//DestroySprite(getSprite('W'));
	endItems();
}

void updateGame() {
	int mX;
	int mY;
	//GetMouseLocation(mX,mY);
	GetMouseLocation(mX,mY);
	vMouse.vectorSetX((float)mX);
	vMouse.vectorSetY((float)mY);
	if (iLives == 9)
	{
		if ((IsKeyDown(GLFW_KEY_ENTER)) ||(vMouse.getVectorX() >= 100 && vMouse.getVectorX() <= 500 && vMouse.getVectorY() >= 50 && vMouse.getVectorY() <= 350 && GetMouseButtonDown(0))){
			updateLives(powerUp);
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
	else if (iLives == 8)
	{
		if (IsKeyDown('A'))
		{
			setTag("BASIC");
		}
		else if (IsKeyDown('D'))
		{
			setTag("WOAH");
		}
		else if (IsKeyDown(GLFW_KEY_SPACE))
		{
			setUp(false);
			updateLives(powerUp);
			player1.setInv(0);
		}
	}
	else if (iLives <= 0)
	{
		MoveSprite(getSprite('L'),(int)vScreen.getVectorX()/2,(int)vScreen.getVectorY()/2);
		MoveSprite(getSprite('W'),(int)500,(int)500);
		if (IsKeyDown(' '))
			updateLives(powerUp);
	}
	else
	{
		
		for (int i = 0; i < 50; i++)
			bullet[i].updateBullet();
		fireBullet(player1);
		updatePlayer(player1);
		updateScreen();
		updatePowerUp(powerUp);
		beam.updateBeam(player1.position);
		healthIcon.updateSprite();
		beam.updateSprite();
		boss.updateBoss();
		player1.updateSprite();
		if(wave >= 3)
			boss.moveWave();
		//RotateSprite(player1.getSprite(),(int)getPlayerAngle(player1));
		target.moveTarget(vMouse);
		for (int i = 0; i <= 19; i++)
		{
			updateAi(monster[i],powerUp);
			updateExplosion(explosion[i]);
			explosion[i].updateSprite();

			if (monster[i].getAlive())
				monster[i].updateSprite();			
		}
		sideLoadAI();
	}
}
void drawGame() {
	
	if (iLives == 9)
	{
		DrawSprite(getSprite('P'));
		DrawSprite(getSprite('E'));
	}
	else if (iLives == 8)
	{
		drawStat();
	}
	else if (iLives <= 0)
	{
		DrawSprite(getSprite('L'));
	}
	else
	{
		drawStat();
		powerUp.drawSprite();
		target.drawSprite();
		player1.drawSprite();
		healthIcon.drawSprite();
		beam.drawSprite();
		boss.drawBoss();
		for (int i = 0; i <= 50; i++)
		{
			if(i < 20)
			{
			explosion[i].drawSprite();
			if (monster[i].getAlive())
				monster[i].drawSprite();
			}
			bullet[i].drawBullet();
		}
	}
	DrawSprite(screen.sprite);
	DrawSprite(screenTwo.sprite);
}

int main()
{
	loadVectors();
	// First we need to create our Game Framework
	//OFF = 0,
	//LOW = 858993459,
	//NORMAL = 1717986918,
	//MEDIUM = -1717986919,
	//HIGH = -858993460,
	//VERY_HIGH = -1

	waveOutSetVolume(0, 8000);

	Initialise((int)vScreen.getVectorX(), (int)vScreen.getVectorY(), false );

	loadGame();

	while (!FrameworkUpdate() && iLives != -1)
	{
		ClearScreen();

		if (!getUp())
			updateGame();

		drawGame();
	};
	endGame();
	Shutdown();

	return 0;
}