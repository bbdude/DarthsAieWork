//////////////////////////////////////////////////////////////////////////
//	Author:	Jacob Miller
//	Date:	09/13/2013
//	Brief:	Main file for Shootem
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

#include <iostream>
//#include <string>
//#include <cmath>
//#include <ctime>
//#include <list>
//#include <assert.h>
//#include <crtdbg.h>
//#include <exception>
//////////////////////////////////////////////////////////////////////////
struct movableObject{
	Vector position;
	Vector speed;
	int sprite;
	int width;
	int height;
};
//Declarations
Bullet bullet[50];
Sprite monster[20];
Sprite explosion[20];

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
		break;
	}
}
void loadLevel(int level,Sprite &powerUp)
{
	powerUp.loadSprite(false,NULL,100,100,NULL,"PINK",NULL,-200,-200);
	switch (level)
	{
	case 1:
		for (int i = 0; i <= 19; i++)
		{
			monster[i].setSpeed((rand() % 5) - 2.5f,0.7f);
			monster[i].loadSprite(false,NULL,20,20,NULL,"PINK",NULL,-200,-200);
		}
		monster[0].setPosition(50,50);
		monster[1].setPosition(100,100);
		monster[2].setPosition(150,150);
		monster[0].setAlive(true);
		monster[1].setAlive(true);
		monster[2].setAlive(true);
		break;
	case 2:
		monster[3].setSprite(CreateSprite( "./images/enemyB.png", 40, 40, true ));
		monster[3].setSpeed((rand() % 5) - 2.5f,0.25f);
		monster[3].loadSprite(true,NULL,20,20,NULL,"PINK",NULL,-200,-200);
		break;
	default:
		break;
	}
}
void loadWave(Sprite &obj,int wave,int &whatAI,Vector &vScreen)
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
				loadAI(monster[i],1,vScreen);
				break;
			case 3:
			case 4:
				loadAI(monster[i],2,vScreen);
				break;
			case 5:
			case 6:
				loadAI(monster[i],3,vScreen);
				break;
			default:
				loadAI(monster[i],4,vScreen);
			}
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
		bullet[whatBullet].setBulletAngle(player.getPosition(),vMouse);
		whatBullet++;
		if (whatBullet == 50)
			whatBullet = 0;
		pressTrigger = false;
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
		bullet[whatBullet].setBulletAngle(player.getPosition(),vMouse);
		whatBullet++;
		if (whatBullet == 50)
			whatBullet = 0;
		if (beam.getTime() <= 1000)
			beam.lineBeam = false;
	}
	player1.setTime(player1.getTime()-1);
	beam.setTime(beam.getTime()-1);
}
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
float getPlayerAngle(Sprite &player,Vector &vScreen,Vector &vMouse)
{
	float angle = std::atan2 ( (vScreen.getVectorY() - vMouse.getVectorY()) - player.position.getVectorY(), vMouse.getVectorX() - player.position.getVectorX()) * 57.2957795f; //57... is 180/pi
	return angle;
}
void explodeAi(Sprite &monster, int &whatExplosion)
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
void updateAi(Sprite &monster,Sprite &power, int &iLives,int &whatAI,int &whatExplosion,float &wave,Vector &vScreen,Sprite &beam,Boss &boss,Sprite &healthIcon,Sprite &player1,Sprite &powerUp){
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
			explodeAi(monster,whatExplosion);
			updateLives(powerUp,iLives,vScreen,healthIcon,player1);
			loadWave(monster,(int)wave,whatAI,vScreen);
		}
		else if (!beam.detectCollisionA(monster.getPosition(),monster.getHeight(),monster.getWidth()))
		{
			explodeAi(monster,whatExplosion);
			monster.setAlive(false);
			loadWave(monster,(int)wave,whatAI,vScreen);
		}
		if (monster.position.getVectorX() + plannedMovement.getVectorX() < 20 || monster.position.getVectorX() + plannedMovement.getVectorX() > 1260)
			moving = false;
		for (int i = 0; i < 49; i++){
			if (!bullet[i].detectCollision(monster.position,monster.getHeight(),monster.getWidth()))
			{
				monster.setAlive(false);
				bullet[i].setAlive(false);
				explodeAi(monster,whatExplosion);
				loadWave(monster,(int)wave,whatAI,vScreen);
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
		loadAI(monster,rand()%4,vScreen);
	}
}
void updateExplosion(Sprite &explosion){ 	explosion.position.vectorAdd(explosion.speed);	}
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

	for (int i = 0; i <= 19; i++)
		monster[i].setSprite( CreateSprite( "./images/enemy.png", 20, 20, true ));
	for (int i = 0; i <= 19; i++)
		explosion[i].setSprite( CreateSprite( "./images/explosion.png", 20, 20, true ));
	for (int i = 0; i < 50; i++)
		bullet[i].loadBullet();
}
void endGame(movableObject &screen,movableObject &screenTwo,Sprite &beam,Boss &boss,Sprite &healthIcon,Sprite &player1,Sprite &powerUp,Sprite &target) {
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
	endItems();
}
void updateLevel(int &level, int &iLives,Vector &vScreen,Sprite &healthIcon,Sprite &player1,Sprite &powerUp)
{
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
void updateGame(int &iLives,int &whatBullet, int &whatAI,int &whatExplosion,float &wave,Vector &vMouse,Vector &vScreen,bool &pressTrigger,movableObject &screen,movableObject &screenTwo,Sprite &beam,Boss &boss,Sprite &healthIcon,Sprite &player1,Sprite &powerUp,Sprite &target) {
	int mX;
	int mY;
	GetMouseLocation(mX,mY);
	vMouse.vectorSetX((float)mX);
	vMouse.vectorSetY((float)mY);
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
		for (int i = 0; i < 50; i++)
			bullet[i].updateBullet();
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
		//RotateSprite(player1.getSprite(),(int)getPlayerAngle(player1));
		target.moveTarget(vMouse);
		for (int i = 0; i <= 19; i++)
		{
			updateAi(monster[i],powerUp,iLives,whatAI,whatExplosion,wave,vScreen,beam,boss,healthIcon,player1,powerUp);
			updateExplosion(explosion[i]);
			explosion[i].updateSprite();

			if (monster[i].getAlive())
				monster[i].updateSprite();
		}
		sideLoadAI();
	}
}
void drawGame(int &iLives,movableObject &screen,movableObject &screenTwo,Sprite &beam,Boss &boss,Sprite &healthIcon,Sprite &player1,Sprite &powerUp,Sprite &target) {
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
		target.drawSprite();
		player1.drawSprite();
		healthIcon.drawSprite();
		if (beam.getAlive())
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
	//Amount of hits the player can take
	int iLives = 9;

	//What bullet is going to be shot
	int whatBullet = 0;

	//What AI is going to be spawned
	int whatAI = 0;

	//What explosion is going to appear when an AI dies
	int whatExplosion = 0;

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

	// First we need to initialize our Game Framework
	Initialise((int)vScreen.getVectorX(), (int)vScreen.getVectorY(), false );

	//Loads all the game assets
	loadGame(iLives,vScreen,screen,screenTwo,beam,boss,healthIcon,player1,powerUp,target);

	//The game loop
	while (!FrameworkUpdate() && iLives != -1)
	{
		//Clears the screen before the draw
		ClearScreen();

		//Checks if the game is paused, if not then update the game
		if (!getUp())
			updateGame(iLives,whatBullet,whatAI,whatExplosion,wave,vMouse,vScreen,pressTrigger,screen,screenTwo,beam,boss,healthIcon,player1,powerUp,target);

		//if in the choose ship part then let the player choose what ship
		updateLevel(iLives,iLives,vScreen,healthIcon,player1,powerUp);

		//Draws all the sprites
		drawGame(iLives,screen,screenTwo,beam,boss,healthIcon,player1,powerUp,target);
	};

	//Deletes all the memory and data used
	endGame(screen,screenTwo,beam,boss,healthIcon,player1,powerUp,target);

	//Ends the framework
	Shutdown();

	return 0;
}