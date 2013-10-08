//////////////////////////////////////////////////////////////////////////
//	Author:	Jacob Miller
//	Date:	09/13/2013
//	Brief:	Main file for Pong
//////////////////////////////////////////////////////////////////////////
#define _USE_MATH_DEFINES
//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include "KeyCodes.h"
#include "MenuItems.h"
#include "Vector.h"
#include <string>
#include <cmath>
#include <assert.h>
#include <crtdbg.h>
#include <ctime>
#include <iostream>
#include <list>
//////////////////////////////////////////////////////////////////////////
struct stableObject{
	Vector position;
	int sprite;
	int width;
	int height;
	std::string tag;
	int time;
};
struct tempObject{
	Vector position;
	int sprite;
	int width;
	int height;
	bool alive;
	bool fire;
	int time;
};
struct bulletStruct
{
	Vector position;
	Vector angle;
	bool alive;
	int sprite;
	int width;
	int height;
};
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
int iLives = 8;
int whatBullet = 0;
int whatAI = 0;
int whatExplosion = 0;
float wave = 0;
float playerAngle = 0;
bool pressTrigger = false;
Vector vScreen;
Vector vMouse;
//200,50,{-1,52,52,true,8000}
tempObject beam;
tempObject healthIcon;
bulletStruct bullet[50];
movableObject monster[20];
movableObject explosion[20];
movableObject powerUp;
movableObject player1;
movableObject target;
movableObject screen;
movableObject screenTwo;

void loadLevel(int level)
{
	powerUp.alive = false;
	powerUp.height = 100;
	powerUp.sprite = -1;
	powerUp.width = 100;
	powerUp.speed.vectorSetX((rand() % 5) - 2.5f);
	powerUp.speed.vectorSetY(0.7f);
	powerUp.position.vectorSetX(-200);
	powerUp.position.vectorSetY(-200);
		powerUp.tag = "PINK";
	switch (level)
	{
	case 1:
		
		
		//player1.position.x = bricks[23][13].position.x;// + 25;
		//player1.position.y = bricks[23][13].position.y;// + 25;
		for (int i = 0; i < 50; i++)
		{
			bullet[i].alive = true;
			bullet[i].angle.vectorSetX(0);
			bullet[i].angle.vectorSetY(0);
			bullet[i].position.vectorSetX(-200);
			bullet[i].position.vectorSetY(-200);
			bullet[i].height = 20;
			bullet[i].width = 10;
			bullet[i].sprite = -1;
		}
		for (int i = 0; i <= 19; i++)
		{
			monster[i].alive = false;
			monster[i].height = 20;
			monster[i].sprite = -1;
			monster[i].width = 20;
			monster[i].speed.vectorSetX((rand() % 5) - 2.5f);
			monster[i].speed.vectorSetY(0.7f);
			monster[i].position.vectorSetX(-200);
			monster[i].position.vectorSetY(-200);
			monster[i].tag = "PINK";
		}
		monster[0].position.vectorSetX(50);// + 25;
		monster[0].position.vectorSetY(50);// + 25;
		monster[1].position.vectorSetX(100);// + 25;
		monster[1].position.vectorSetY(100);// + 25;
		monster[2].position.vectorSetX(150);// + 25;
		monster[2].position.vectorSetY(150);// + 25;
		monster[0].alive = true;// + 25;
		monster[0].alive = true;// + 25;
		monster[1].alive = true;// + 25;
		monster[1].alive = true;// + 25;
		monster[2].alive = true;// + 25;
		monster[2].alive = true;// + 25;
		break;
	case 2:
		std::cout << "Wave 2";
		
		monster[3].position.vectorSetX(200);// + 25;
		monster[3].position.vectorSetY(-20);// + 25;
	
		monster[3].alive = true;
		monster[3].height = 20;
		//DestroySprite(monster[3].sprite);
		monster[3].sprite = -1;
		monster[3].width = 20;
		monster[3].speed.vectorSetY(0.25f);
		monster[3].speed.vectorSetX((rand() % 5) - 2.5f);
		monster[3].sprite = CreateSprite( "./images/enemyB.png", 40, 40, true );
		break;
	default:
		break;
	}

}
void loadWave(movableObject &obj,int wave)
{
	whatAI++;
	if (whatAI >= 20)
		whatAI = 0;
	for (int i = whatAI; i >= 0; i--)
	{
		if (!monster[i].alive)
		switch(rand() % 4)
		{
		case 1:
			monster[i].position.vectorSetX((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20);
			monster[i].position.vectorSetY(-20);
			monster[i].alive = true;
			monster[i].height = 40;
			monster[i].sprite = -1;
			monster[i].width = 40;
			//if (i == 1 || i == 2){
			monster[i].speed.vectorSetY(0.25f);
			monster[i].speed.vectorSetX((rand() % 5) - 2.5f);
			monster[i].tag = "BLUE";
			monster[i].sprite = CreateSprite( "./images/enemyB.png", 40, 40, true );
			break;
		case 2:
			monster[i].position.vectorSetX((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20);
			monster[i].position.vectorSetY(-20);
			monster[i].alive = true;
			monster[i].height = 35;
			monster[i].sprite = -1;
			monster[i].width = 20;
			//if (i == 1 || i == 2){
			monster[i].speed.vectorSetY(0.25f);
			monster[i].speed.vectorSetX(0.0f);
			monster[i].tag = "GREEN";
			monster[i].sprite = CreateSprite( "./images/enemyG.png", 20, 35, true );
			break;
		case 3:
			//DestroySprite(monster[i].sprite);
			monster[i].position.vectorSetX((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20);
			monster[i].position.vectorSetY(-20);
			monster[i].alive = true;
			monster[i].height = 10;
			monster[i].sprite = -1;
			monster[i].width = 10;
			//if (i == 1 || i == 2){
			monster[i].speed.vectorSetY(0.28f);
			monster[i].speed.vectorSetX(0.1f);
			monster[i].tag = "RED";
			monster[i].sprite = CreateSprite( "./images/enemyR.png", 10, 10, true );
			break;
		case 4:
			//DestroySprite(monster[i].sprite);
			monster[i].alive = false;
			monster[i].height = 20;
			monster[i].sprite = -1;
			monster[i].width = 20;
			monster[i].speed.vectorSetX((float)(rand() % 5) - 2.5f);
			monster[i].speed.vectorSetY(0.7f);
			monster[i].position.vectorSetX(-200);
			monster[i].position.vectorSetY(-200);
			monster[i].tag = "PINK";
			break;
		}
	}
	switch(wave)
	{
	case 1:
		
		//player1.position.x = bricks[23][13].position.x;// + 25;
		//player1.position.y = bricks[23][13].position.y;// + 25;

		//DestroySprite(obj.sprite);
		obj.position.vectorSetX((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20);
		obj.position.vectorSetY(-20);
		obj.alive = true;
		obj.height = 40;
		obj.sprite = -1;
		obj.width = 40;
		//if (i == 1 || i == 2){
		obj.speed.vectorSetY(0.25f);
		obj.speed.vectorSetX((rand() % 5) - 2.5f);
		obj.tag = "BLUE";
		obj.sprite = CreateSprite( "./images/enemyB.png", 40, 40, true );
		break;
	case 2:
		//DestroySprite(obj.sprite);
		obj.position.vectorSetX((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20);
		obj.position.vectorSetY(-20);
		obj.alive = true;
		obj.height = 35;
		obj.sprite = -1;
		obj.width = 20;
		//if (i == 1 || i == 2){
		obj.speed.vectorSetY(0.25f);
		obj.speed.vectorSetX(0.0f);
		obj.tag = "GREEN";
		obj.sprite = CreateSprite( "./images/enemyG.png", 20, 35, true );
		break;
	default:
		//DestroySprite(obj.sprite);
		obj.position.vectorSetX((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20);
		obj.position.vectorSetY(-20);
		obj.alive = true;
		obj.height = 10;
		obj.sprite = -1;
		obj.width = 10;
		//if (i == 1 || i == 2){
		obj.speed.vectorSetY(0.28f);
		obj.speed.vectorSetX(0.1f);
		obj.tag = "RED";
		obj.sprite = CreateSprite( "./images/enemyR.png", 10, 10, true );
		break;
		break;
	}
}
void updateWave(movableObject &obj)
{

}
bool detectCollision(movableObject &objOne,movableObject &objTwo)
{
	if(objOne.position.getVectorX() >= objTwo.position.getVectorX() - (objTwo.width/2) && objOne.position.getVectorX() <= objTwo.position.getVectorX() + (objTwo.width/2)
		&& objOne.position.getVectorY() >= objTwo.position.getVectorY() - (objTwo.width/2)&& objOne.position.getVectorY() <= objTwo.position.getVectorY() + (objTwo.height/2))
	{
		return false;
	}
	return true;
}
bool detectCollision(bulletStruct &objOne,movableObject &objTwo)
{
	if(objOne.position.getVectorX() >= objTwo.position.getVectorX() - (objTwo.width/2) && objOne.position.getVectorX() <= objTwo.position.getVectorX() + (objTwo.width/2)
		&& objOne.position.getVectorY() >= objTwo.position.getVectorY() - (objTwo.width/2)&& objOne.position.getVectorY() <= objTwo.position.getVectorY() + (objTwo.height/2) && objOne.alive)
	{
		return false;
	}
	return true;
}
bool detectCollision(tempObject &objTwo,movableObject &objOne)
{
	if(objOne.position.getVectorX() >= objTwo.position.getVectorX() - (objTwo.width/2) && objOne.position.getVectorX() <= objTwo.position.getVectorX() + (objTwo.width/2)
		&& objOne.position.getVectorY() >= objTwo.position.getVectorY() - (objTwo.width/2)&& objOne.position.getVectorY() <= objTwo.position.getVectorY() + (objTwo.height/2) && objOne.alive)
	{
		return false;
	}
	return true;
}
void updateBullet(bulletStruct &bullets,movableObject &player)
{
	if (bullets.position.getVectorX() < 0 || bullets.position.getVectorX()  > 1280 || bullets.position.getVectorY()  < 0 || bullets.position.getVectorY() > 780)
	{
		bullets.alive = false;
		bullets.position.vectorSetX(-1000);
		bullets.position.vectorSetY(-1000);
	}
	if (bullets.alive)
		bullets.position.vectorAdd(bullets.angle);
}
void fireBullet(movableObject &player)
{
	if (GetMouseButtonDown(0))
	{
		pressTrigger = true;
	}
	else if (pressTrigger)
	{
		bullet[whatBullet].position.vectorSetX(player.position.getVectorX());
		bullet[whatBullet].position.vectorSetY(player.position.getVectorY());
		bullet[whatBullet].alive = true;
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
		angle.vectorSetX((vMouse.getVectorX()-player.position.getVectorX())/10);
		angle.vectorSetY((vMouse.getVectorY()-player.position.getVectorY())/10);
		bullet[whatBullet].angle = angle;
		bullet[whatBullet].angle.vectorSetX(std::sqrt(std::pow(angle.getVectorX(),2))/5);
		bullet[whatBullet].angle.vectorSetY(std::sqrt(std::pow(angle.getVectorY(),2))/5);
		if (angle.getVectorX() < 0)
			bullet[whatBullet].angle.vectorSetX(bullet[whatBullet].angle.getVectorX() * -1);
		if (angle.getVectorY() < 0)
			bullet[whatBullet].angle.vectorSetY(bullet[whatBullet].angle.getVectorY() * -1);

		whatBullet++;
		if (whatBullet == 50)
			whatBullet = 0;
		pressTrigger = false;
	}
}
void updateBeam(tempObject &beam)
{
	if (GetMouseButtonDown(1) && beam.time == 0)
	{
		beam.fire = true;
	}
	else if (beam.fire)
	{
		beam.fire = false;
		beam.alive = true;
		//beam.position.vectorSet(player1.position);
		beam.time = 2000;
	}
	if (beam.time != 0)
	{
		beam.position.vectorSetX(player1.position.getVectorX());
		beam.position.vectorSetY(player1.position.getVectorY() - (beam.height/2) + 5);
		beam.time--;
	}
	else
	{
		beam.alive = false;
		beam.position.vectorSet(-1000,-1000);
	}
	MoveSprite(beam.sprite,(int)beam.position.getVectorX(),(int)beam.position.getVectorY());
}
void updatePlayer(movableObject &player){

	Vector plannedMovement;
	if (IsKeyDown('W') && player.position.getVectorY() - (player.height/2) - player.speed.getVectorY() >= 0)
	{
		plannedMovement.vectorSetY(plannedMovement.getVectorY() - player.speed.getVectorY());
		//player.position.y -= player.speed.y;
	}
	if (IsKeyDown('S') && player.position.getVectorY() + (player.height/2) + player.speed.getVectorY() <= vScreen.getVectorY())
	{
		plannedMovement.vectorSetY(plannedMovement.getVectorY() + player.speed.getVectorY());
		//player.position.y += player.speed.y;
	}
	if (IsKeyDown('A') && player.position.getVectorX() - (player.width/2) - player.speed.getVectorX() >= 0)
	{
		plannedMovement.vectorSetX(plannedMovement.getVectorX() - player.speed.getVectorX());
		//player.position.x -= player.speed.x;
	}
	if (IsKeyDown('D') && player.position.getVectorX() + (player.width/2) + player.speed.getVectorX() <= vScreen.getVectorX())
	{
		plannedMovement.vectorSetX(plannedMovement.getVectorX() + player.speed.getVectorX());
		//player.position.x += player.speed.x;
	}
	bool moving = true;
	bool stopIt = false;

	if (player.position.getVectorX() + plannedMovement.getVectorX() < 20)
		plannedMovement.vectorSetX(0);
	if (player.position.getVectorX() + plannedMovement.getVectorX() > 1260)
		plannedMovement.vectorSetX(0);
	if (player.position.getVectorY() + plannedMovement.getVectorY() < 20)
		plannedMovement.vectorSetY(0);
	if (player.position.getVectorY() + plannedMovement.getVectorY() > 760)
		plannedMovement.vectorSetY(0);

	if (moving && !stopIt)
		player.position.vectorAdd(plannedMovement);
}

float getPlayerAngle(movableObject &player)
{
	float angle = std::atan2 ( (vScreen.getVectorY() - vMouse.getVectorY()) - player.position.getVectorY(), vMouse.getVectorX() - player.position.getVectorX()) * 57.2957795f; //57... is 180/pi

	return angle;
	//return std::tan((vMouse.getVectorY()-player.position.getVectorY())/(vMouse.getVectorX()-player.position.getVectorX()))*57.2957795f;
}
void explodeAi(movableObject &monster)
{
	std::cout << "Explode AI";
	DestroySprite(monster.sprite);
	whatExplosion++;
	if (whatExplosion >= 20)
		whatExplosion = 0;
	explosion[whatExplosion].sprite = -1;
	explosion[whatExplosion].position.vectorSet(monster.position);
	explosion[whatExplosion].speed.vectorSetX(0);
	explosion[whatExplosion].speed.vectorSetY(monster.speed.getVectorY()/1.2f);
	explosion[whatExplosion].sprite = CreateSprite( "./images/explosion.png", monster.width, monster.height, true );
}
void updatePowerUp(movableObject &power)
{
	if (power.alive)
	{
		if (!detectCollision(player1,power))
		{
			power.alive = false;
			power.position.vectorSet(-100,-100);
			power.speed.vectorSet(0,0);
			power.tag = "FROZEN";
			healthIcon.sprite = CreateSprite( "./images/healthbarP.png", 50 * iLives, 25, true );
		}
		else if (power.position.getVectorY() >= vScreen.getVectorY())
		{
			power.alive = false;
			power.position.vectorSet(-100,-100);
			power.speed.vectorSet(0,0);
			//power.tag = "VENOM";
		}
		if ((power.position.getVectorX() + power.speed.getVectorX() < 20 || power.position.getVectorX() + power.speed.getVectorX() > 1260))
			power.speed.vectorSetX(power.speed.getVectorX()*-1);

		power.position.vectorAdd(power.speed);
		MoveSprite(power.sprite, (int)power.position.getVectorX(), (int)power.position.getVectorY());
	}
	else if (rand()%4000 == 2)
	{
		power.alive = true;
		power.position.vectorSetX((float)(rand() % (int)(vScreen.getVectorX() - 40)) + 20);
		power.position.vectorSetY(-20);
		power.speed.vectorSetY(0.25f);
		power.speed.vectorSetX((rand() % 5) - 2.5f);
		//power.tag = "PINK";
		std::cout << "POWER UP";
	}
}
void updateLives(movableObject &power)
{
	if (power.tag == "FROZEN")
	{
		power.tag = "PINK";
		healthIcon.sprite = CreateSprite( "./images/healthbar.png", 50 * iLives, 25, true );
	}
	else if (power.tag == "VENOM")
	{
		std::cout << "VENOMOUS\n";
		iLives -= 2;
		healthIcon.position.vectorSetX(vScreen.getVectorX()/2);
		power.tag = "VENOM2";
		healthIcon.sprite = CreateSprite( "./images/healthbarV.png", 50 * iLives, 25, true );
	}
	else if (power.tag == "VENOM2")
	{
		std::cout << "VENOMOUS2\n";
		iLives -= 2;
		healthIcon.position.vectorSetX(vScreen.getVectorX()/2);
		power.tag = "PINK";
		healthIcon.sprite = CreateSprite( "./images/healthbar.png", 50 * iLives, 25, true );
	}
	else if (power.tag != "FROZEN" && power.tag != "VENOM" && power.tag != "VENOM2")
	{
		iLives--;
		healthIcon.position.vectorSetX(vScreen.getVectorX()/2);
		healthIcon.sprite = CreateSprite( "./images/healthbar.png", 50 * iLives, 25, true );
	}
}
void updateAi(movableObject &monster,movableObject &power){
	if (monster.alive)
	{
		Vector plannedMovement;
		plannedMovement.vectorAdd(monster.speed);
		bool moving = true;
		bool stopIt = false;
		if (monster.tag == "RED" && rand()%600 == 2)
		{
			if (monster.speed.getVectorY() < 0)
				monster.speed.vectorSetY(-20);
			else
				monster.speed.vectorSetY(-20);
		}
		else if (monster.tag == "RED")
		{
			monster.speed.vectorSetY(0);
		}
		if (monster.position.getVectorY() > vScreen.getVectorY())
		{
			wave += 0.1f;
			loadWave(monster,(int)wave);
		}
		if (!detectCollision(player1,monster))
		{
			if (monster.tag == "GREEN" && power.tag != "FROZEN")
			{
				power.tag = "VENOM";
				healthIcon.sprite = CreateSprite( "./images/healthbarV.png", 50 * iLives, 25, true );
			}
			updateLives(powerUp);
			loadWave(monster,(int)wave);
		}
		else if (!detectCollision(beam,monster))
		{ 
			explodeAi(monster);
			loadWave(monster,(int)wave);
		}
		if (monster.position.getVectorX() + plannedMovement.getVectorX() < 20 || monster.position.getVectorX() + plannedMovement.getVectorX() > 1260)
			moving = false;
		for (int i = 0; i < 49; i++)
			if (!detectCollision(bullet[i],monster))
			{
				monster.alive = false;
				bullet[i].alive = false;
				explodeAi(monster);
				loadWave(monster,(int)wave);

			}
		if (moving && !stopIt)
			monster.position.vectorAdd(plannedMovement);
		else 
			monster.speed.multiplyScalarX(-1);
	}
	
}
void updateExplosion(movableObject &explosion)
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
	healthIcon.sprite = CreateSprite( "./images/healthbar.png", 150, 50, true );
	beam.sprite = CreateSprite( "./images/beam.png", 760, 50, true );
	RotateSprite(beam.sprite,90);
	powerUp.sprite = CreateSprite( "./images/shield.png", 50, 50, true );

	player1.sprite = CreateSprite( "./images/player.png", 20, 20, true );
	target.sprite = CreateSprite( "./images/flag.png", 50, 50, true );
	for (int i = 0; i <= 19; i++)
		monster[i].sprite = CreateSprite( "./images/enemy.png", 20, 20, true );
	for (int i = 0; i <= 19; i++)
		explosion[i].sprite = CreateSprite( "./images/explosion.png", 20, 20, true );
	for (int i = 0; i < 50; i++)
	bullet[i].sprite = CreateSprite( "./images/bomb.png", 10, 20, true );
}
void loadVectors()
{

	player1.alive = true;
	player1.height = 5;
	player1.width = 5;
	player1.position.vectorSet(500,300);
	player1.speed.vectorSet(1,1);
	player1.sprite = -1;
	target.alive = true;
	target.height = 50;
	target.width = 50;
	target.position.vectorSet(0,0);
	target.speed.vectorSet(0,0);
	target.sprite = -1;
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
	healthIcon.alive = true;
	healthIcon.height = 52;
	healthIcon.position.vectorSet(200,50);
	healthIcon.sprite = -1;
	healthIcon.time = 8000;
	healthIcon.width = 52;
	beam.alive = false;
	beam.fire = false;
	beam.height = 780;
	beam.position.vectorSet(-1000,-1000);
	beam.sprite = -1;
	beam.time = 0;
	beam.width = 100;
	powerUp.alive = false;
	powerUp.height = 100;
	powerUp.width = 100;
	powerUp.position.vectorSet(0,0);
	
}
void endGame() {
	DestroySprite(screen.sprite);
	DestroySprite(player1.sprite);
	DestroySprite(target.sprite);
	for (int i = 0; i <= 19; i++)
	{
	DestroySprite(explosion[i].sprite);
	DestroySprite(monster[i].sprite);
	}
	DestroySprite(healthIcon.sprite);
	DestroySprite(powerUp.sprite);
	DestroySprite(screen.sprite);
	DestroySprite(screenTwo.sprite);

	for (int i = 0; i < 50; i++)
	DestroySprite(bullet[i].sprite);
	DestroySprite(getSprite('L'));
	DestroySprite(getSprite('E'));
	DestroySprite(getSprite('P'));
	DestroySprite(getSprite('W'));
	DestroySprite(beam.sprite);
}

void updateGame() {
	int mX;
	int mY;
	//GetMouseLocation(mX,mY);
	GetMouseLocation(mX,mY);
	vMouse.vectorSetX((float)mX);
	vMouse.vectorSetY((float)mY);
	if (iLives == 8)
	{
		if ((IsKeyDown(GLFW_KEY_ENTER)) ||(vMouse.getVectorX() >= 100 && vMouse.getVectorX() <= 500 && vMouse.getVectorY() >= 50 && vMouse.getVectorY() <= 350 && GetMouseButtonDown(0))){
			updateLives(powerUp);
			wave++;
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
			updateLives(powerUp);
	}
	else
	{
		
		for (int i = 0; i < 50; i++)
		updateBullet(bullet[i],player1);
		fireBullet(player1);
		updatePlayer(player1);
		updateScreen();
		updatePowerUp(powerUp);
		updateBeam(beam);

		MoveSprite(target.sprite, (int)vMouse.getVectorX(), (int)vMouse.getVectorY());
		RotateSprite(player1.sprite,(int)getPlayerAngle(player1));
		MoveSprite(player1.sprite, (int)player1.position.getVectorX(), (int)player1.position.getVectorY());
		
		MoveSprite(healthIcon.sprite,(int)healthIcon.position.getVectorX(),(int)healthIcon.position.getVectorY());


		for (int i = 0; i < 50; i++)
		MoveSprite(bullet[i].sprite,(int)bullet[i].position.getVectorX(),(int)bullet[i].position.getVectorY());
		for (int i = 0; i <= 19; i++)
		{
			updateAi(monster[i],powerUp);
			updateExplosion(explosion[i]);
			MoveSprite(explosion[i].sprite, (int)explosion[i].position.getVectorX(), (int)explosion[i].position.getVectorY());

			if (monster[i].alive)
				MoveSprite(monster[i].sprite, (int)monster[i].position.getVectorX(), (int)monster[i].position.getVectorY());			
		}
	}
}
void drawGame() {
	if (iLives == 8)
	{
		DrawSprite(getSprite('P'));
		DrawSprite(getSprite('E'));
	}
	else if (iLives <= 0)
	{
		DrawSprite(getSprite('L'));
	}
	else
	{
		DrawSprite(powerUp.sprite);
		DrawSprite(healthIcon.sprite);
		DrawSprite(target.sprite);
		DrawSprite(player1.sprite);
		DrawSprite(beam.sprite);
		for (int i = 0; i <= 19; i++)
		{
			DrawSprite(explosion[i].sprite);
			if (monster[i].alive)
				DrawSprite(monster[i].sprite);
		}
		for (int i = 0; i < 50; i++)
			if (bullet[i].alive)
				DrawSprite(bullet[i].sprite);
	}
	DrawSprite(screen.sprite);
	DrawSprite(screenTwo.sprite);
}

int main()
{
	loadVectors();
	// First we need to create our Game Framework
	Initialise((int)vScreen.getVectorX(), (int)vScreen.getVectorY(), false );

	loadGame();

	while (!FrameworkUpdate() && iLives != -1)
	{
		ClearScreen();

		updateGame();

		drawGame();
	};
	endGame();
	Shutdown();

	return 0;
}