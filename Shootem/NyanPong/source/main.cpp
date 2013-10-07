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
#include <string>
#include <cmath>
#include <assert.h>
#include <crtdbg.h>
#include <ctime>
#include <iostream>
#include <list>
//////////////////////////////////////////////////////////////////////////

struct vector2{
	float x;
	float y;
};
struct movableObject{
	vector2 position;
	vector2 speed;
	int sprite;
	int width;
	int height;
	bool alive;
	std::string tag;
};
struct stableObject{
	vector2 position;
	int sprite;
	int width;
	int height;
	std::string tag;
	int time;
};
struct tempObject{
	vector2 position;
	int sprite;
	int width;
	int height;
	bool alive;
	int time;
};
struct bulletStruct
{
	vector2 position;
	vector2 angle;
	bool alive;
	int sprite;
	int width;
	int height;
};
class Vector
{
public:
	Vector()
	{
		x = 0;
		y = 0;
	}
	~Vector()
	{
	}
	float getVectorX()
	{
		return x;
	}
	float getVectorY()
	{
		return y;
	}
	void vectorSubtract(float s){
		x -= s;
		y -= s;
	}
	void vectorAdd(float s){
		x += s;
		y += s;
	}
	void multiplyScalar(float s){
		x *= s;
		y *= s;
	}
	void vectorSubtract(vector2 &v2){
		x -= v2.x;
		y -= v2.y;
	}
	void vectorAdd(vector2 &v2){
		x += v2.x;
		y += v2.y;
	}
	void getNormal(){
		float mag = sqrt(x*x + y*y);
		x = x/mag;
		y = y/mag;
		
	}
	float getMagnitude(){
		return sqrt(x*x + y*y);
	}
	private:
		float x,y;
	};

//Declarations
//Player Lives
int iLives = 4;
int whatBullet = 0;
int whatExplosion = 0;
float wave = 0;
float playerAngle = 0;
bool pressTrigger = false;
vector2 vScreen = {1280,780};
vector2 vMouse = {0,0};
tempObject scoreIcon = {200,50,-1,52,52,true,8000};
tempObject scoreIcon2 = {230,50,-1,52,52,true,8000};
tempObject scoreIcon3 = {260,50,-1,52,52,true,8000};
bulletStruct bullet[50];
movableObject monster[20];
movableObject explosion[20];
movableObject player1 = {500, 300, 1, 1, -1 , 5, 5,true,"BLANK"};
movableObject target = {0,0,0,0,-1,50,50,true,"BLANK"};
movableObject screen = {0,0,0,.05f,-1,780,3840,true,"BLANK"};
movableObject screenTwo = {0,0,0,.05f,-1,780,3840,true,"BLANK"};

vector2 vectorSubtract(vector2 &v, float s){
	vector2 result = {v.x - s, v.y - s};
	return result;
}

vector2 vectorAdd(vector2 &v, float s){
	vector2 result = {v.x + s, v.y + s};
	return result;
}

vector2 multiplyScalar(vector2 &v, float s){
	vector2 result = {v.x * s, v.y * s};
	return result;
}

vector2 vectorSubtract(vector2 &v, vector2 &v2){
	vector2 result = {v.x - v2.x, v.y - v2.y};
	return result;
}

vector2 vectorAdd(vector2 &v, vector2 &v2){
	vector2 result = {v.x + v2.x, v.y + v2.y};
	return result;
}

vector2 getNormal(vector2 &v){
	float mag = sqrt(v.x*v.x + v.y*v.y);
	vector2 result = {v.x/mag, v.y/mag};
	return result;
}

float getMagnitude(vector2 &v){
	return sqrt(v.x*v.x + v.y*v.y);
}

void loadLevel(int level)
{
	switch (level)
	{
	case 1:
		
		
		//player1.position.x = bricks[23][13].position.x;// + 25;
		//player1.position.y = bricks[23][13].position.y;// + 25;
		for (int i = 0; i < 50; i++)
		{
			bullet[i].alive = true;
			bullet[i].angle.x = 0;
			bullet[i].angle.y = 0;
			bullet[i].position.x = -200;
			bullet[i].position.y = -200;
			bullet[i].height = 20;
			bullet[i].width = 10;
			bullet[i].sprite = -1;
		}
		for (int i = 0; i <= 19; i++)
		{
			monster[i].alive = true;
			monster[i].height = 20;
			monster[i].sprite = -1;
			monster[i].width = 20;
			monster[i].speed.x = (rand() % 5) - 2.5f;
			monster[i].speed.y = 0.7f;
			monster[i].position.x = -200;
			monster[i].position.y = -200;
			monster[i].tag = "PINK";
		}
		monster[0].position.x = 50;// + 25;
		monster[0].position.y = 50;// + 25;
		monster[1].position.x = 100;// + 25;
		monster[1].position.y = 100;// + 25;
		monster[2].position.x = 150;// + 25;
		monster[2].position.y = 150;// + 25;
		break;
	case 2:
		std::cout << "Wave 2";
		
		monster[3].position.x = 200;// + 25;
		monster[3].position.y = -20;// + 25;
	
		monster[3].alive = true;
		monster[3].height = 20;
		//DestroySprite(monster[3].sprite);
		monster[3].sprite = -1;
		monster[3].width = 20;
		monster[3].speed.y = 0.25f;
		monster[3].speed.x = (rand() % 5) - 2.5f;
		monster[3].sprite = CreateSprite( "./images/enemyB.png", 40, 40, true );
		break;
	default:
		break;
	}

}
void loadWave(movableObject &obj,int wave)
{
	
	switch(wave)
	{
	case 1:
		
		//player1.position.x = bricks[23][13].position.x;// + 25;
		//player1.position.y = bricks[23][13].position.y;// + 25;

		//DestroySprite(obj.sprite);
		obj.position.x = (rand() % (int)(vScreen.x - 40)) + 20;
		obj.position.y = -20;
		obj.alive = true;
		obj.height = 40;
		obj.sprite = -1;
		obj.width = 40;
		//if (i == 1 || i == 2){
		obj.speed.y = 0.25f;
		obj.speed.x = (rand() % 5) - 2.5f;
		obj.tag = "BLUE";
		obj.sprite = CreateSprite( "./images/enemyB.png", 40, 40, true );
		break;
	case 2:
		std::cout << "Spawning a green one";
		//DestroySprite(obj.sprite);
		obj.position.x = (rand() % (int)(vScreen.x - 40)) + 20;
		obj.position.y = -20;
		obj.alive = true;
		obj.height = 35;
		obj.sprite = -1;
		obj.width = 20;
		//if (i == 1 || i == 2){
		obj.speed.y = 0.25f;
		obj.speed.x = 0.0f;
		obj.tag = "GREEN";
		obj.sprite = CreateSprite( "./images/enemyG.png", 20, 35, true );
		break;
	case 3:
		std::cout << "Spawning a red one";
		//DestroySprite(obj.sprite);
		obj.position.x = (rand() % (int)(vScreen.x - 40)) + 20;
		obj.position.y = -20;
		obj.alive = true;
		obj.height = 10;
		obj.sprite = -1;
		obj.width = 10;
		//if (i == 1 || i == 2){
		obj.speed.y = 0.28f;
		obj.speed.x = 0.1f;
		obj.tag = "RED";
		obj.sprite = CreateSprite( "./images/enemyR.png", 10, 10, true );
		break;
	case 4:
	case 5:
	case 6:
		break;
	}
}
void updateWave(movableObject &obj)
{

}
bool detectCollision(movableObject &objOne,movableObject &objTwo)
{
	if(objOne.position.x >= objTwo.position.x - (objTwo.width/2) && objOne.position.x <= objTwo.position.x + (objTwo.width/2)
		&& objOne.position.y >= objTwo.position.y - (objTwo.width/2)&& objOne.position.y <= objTwo.position.y + (objTwo.height/2))
	{
		return false;
	}
	return true;
}
bool detectCollision(bulletStruct &objOne,movableObject &objTwo)
{
	if(objOne.position.x >= objTwo.position.x - (objTwo.width/2) && objOne.position.x <= objTwo.position.x + (objTwo.width/2)
		&& objOne.position.y >= objTwo.position.y - (objTwo.width/2)&& objOne.position.y <= objTwo.position.y + (objTwo.height/2) && objOne.alive)
	{
		return false;
	}
	return true;
}
void updateBullet(bulletStruct &bullets,movableObject &player)
{
	if (bullets.position.x < 0 || bullets.position.x  > 1280 || bullets.position.y  < 0 || bullets.position.y > 780)
	{
		bullets.alive = false;
		bullets.position.x = -1000;
		bullets.position.y = -1000;
	}
	if (bullets.alive)
		bullets.position = vectorAdd(bullets.position,bullets.angle);
}
void fireBullet(movableObject &player)
{
	if (GetMouseButtonDown(0))
	{
		pressTrigger = true;
	}
	else if (pressTrigger)
	{
		bullet[whatBullet].position.x = player.position.x;
		bullet[whatBullet].position.y = player.position.y;
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
		vector2 angle = {0,0};
		angle.x = (vMouse.x-player.position.x)/10;
		angle.y = (vMouse.y-player.position.y)/10;
		bullet[whatBullet].angle = angle;
		bullet[whatBullet].angle.x = std::sqrt(std::pow(angle.x,2))/5;
		if (angle.x < 0)
			bullet[whatBullet].angle.x *= -1;
		bullet[whatBullet].angle.y = std::sqrt(std::pow(angle.y,2))/5;
		if (angle.y < 0)
			bullet[whatBullet].angle.y *= -1;

		whatBullet++;
		if (whatBullet == 50)
			whatBullet = 0;
		pressTrigger = false;
	}
}
void updatePlayer(movableObject &player){

	vector2 plannedMovement = {0,0};
	if (IsKeyDown('W') && player.position.y - (player.height/2) - player.speed.y >= 0)
	{
		plannedMovement.y -= player.speed.y;
		//player.position.y -= player.speed.y;
	}
	if (IsKeyDown('S') && player.position.y + (player.height/2) + player.speed.y <= vScreen.y)
	{
		plannedMovement.y += player.speed.y;
		//player.position.y += player.speed.y;
	}
	if (IsKeyDown('A') && player.position.x - (player.width/2) - player.speed.x >= 0)
	{
		plannedMovement.x -= player.speed.x;
		//player.position.x -= player.speed.x;
	}
	if (IsKeyDown('D') && player.position.x + (player.width/2) + player.speed.x <= vScreen.x)
	{
		plannedMovement.x += player.speed.x;
		//player.position.x += player.speed.x;
	}
	bool moving = true;
	bool stopIt = false;

	if (player.position.x + plannedMovement.x < 20)
		plannedMovement.x = 0;
	if (player.position.x + plannedMovement.x > 1260)
		plannedMovement.x = 0;
	if (player.position.y + plannedMovement.y < 20)
		plannedMovement.y = 0;
	if (player.position.y + plannedMovement.y > 760)
		plannedMovement.y = 0;

	if (moving && !stopIt)
		player.position = vectorAdd(player.position,plannedMovement);
}

float getPlayerAngle(movableObject &player)
{
	return std::tan((vMouse.y-player.position.y)/(vMouse.x-player.position.x));
}
void explodeAi(movableObject &monster)
{
	std::cout << "Explode AI";
	DestroySprite(monster.sprite);
	whatExplosion++;
	if (whatExplosion >= 20)
		whatExplosion = 0;
	explosion[whatExplosion].sprite = -1;
	explosion[whatExplosion].position.x = monster.position.x;
	explosion[whatExplosion].position.y = monster.position.y;
	explosion[whatExplosion].speed.x = 0;
	explosion[whatExplosion].speed.y = monster.speed.y/1.2f;//0.25f;
	explosion[whatExplosion].sprite = CreateSprite( "./images/explosion.png", monster.width, monster.height, true );
}
void updateAi(movableObject &monster){
	if (monster.alive)
	{
		vector2 plannedMovement = {0,0};
		plannedMovement = vectorAdd(plannedMovement,monster.speed);
		bool moving = true;
		bool stopIt = false;
		if (monster.tag == "RED" && rand()%300 == 2)
		{
			if (monster.speed.y < 0)
				monster.speed.y = -20;
			else
				monster.speed.y = 20;
		}
		else if (monster.tag == "RED")
		{
			if (monster.speed.y < 0)
				monster.speed.y = 0.0f;
			else 
				monster.speed.y = 0.0f;
		}
		if (monster.position.y > vScreen.y)
		{
			wave += 0.1f;
			loadWave(monster,(int)wave);
		}
		if (!detectCollision(player1,monster))
		{
			iLives--;
			loadWave(monster,(int)wave);
		}
		if (monster.position.x + plannedMovement.x < 20 || monster.position.x + plannedMovement.x > 1260)
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
			monster.position = vectorAdd(monster.position,plannedMovement);
		else 
			monster.speed.x = multiplyScalar(monster.speed,-1).x;
	}
	
}
void updateExplosion(movableObject &explosion)
{
	explosion.position = vectorAdd(explosion.position,explosion.speed);
}
void updateScreen()
{
	screen.position = vectorAdd(screen.position,screen.speed);
	MoveSprite(screen.sprite, (int)screen.position.x, (int)screen.position.y);
	if (screen.position.y >= vScreen.y)
		screen.position.y = -vScreen.y*2;
	screenTwo.position = vectorAdd(screenTwo.position,screenTwo.speed);
	MoveSprite(screenTwo.sprite, (int)screenTwo.position.x, (int)screenTwo.position.y);
	if (screenTwo.position.y >= vScreen.y)
		screenTwo.position.y = -vScreen.y*2;
}
void loadGame() {
	srand((int)time(0));
	//fillBulletStruct();
	// Now load some sprites
	loadLevel(1);
	screen.position.x = 0;
	screen.position.y = -vScreen.y*2;
	screen.sprite = CreateSprite( "./images/bg2.png", (int)vScreen.x, (int)vScreen.y*3,false );
	//MoveSprite(screen.sprite, iScreenX>>1, iScreenY>>1);
	MoveSprite(screen.sprite, (int)screen.position.x, (int)screen.position.y);
	screenTwo.position.x = 0;
	screenTwo.position.y = -vScreen.y*2;
	screenTwo.sprite = CreateSprite( "./images/bg2.png", (int)vScreen.x, (int)vScreen.y*6,false );
	MoveSprite(screenTwo.sprite, (int)screenTwo.position.x, (int)screenTwo.position.y);
	setSprite('L',CreateSprite( "./images/lose.png", 400, 300, true ));
	setSprite('E',CreateSprite( "./images/exit.png", 400, 300, true ));
	setSprite('P',CreateSprite( "./images/play.png", 400, 300, true ));
	setSprite('W',CreateSprite( "./images/win.png", 400, 300, true ));
	scoreIcon.sprite = CreateSprite( "./images/cherry.png", 52, 52, true );
	scoreIcon2.sprite = CreateSprite( "./images/cherry.png", 52, 52, true );
	scoreIcon3.sprite = CreateSprite( "./images/cherry.png", 52, 52, true );

	player1.sprite = CreateSprite( "./images/player.png", 20, 20, true );
	target.sprite = CreateSprite( "./images/flag.png", 50, 50, true );
	for (int i = 0; i <= 19; i++)
		monster[i].sprite = CreateSprite( "./images/enemy.png", 20, 20, true );
	for (int i = 0; i <= 19; i++)
		explosion[i].sprite = CreateSprite( "./images/explosion.png", 20, 20, true );
	for (int i = 0; i < 50; i++)
	bullet[i].sprite = CreateSprite( "./images/bomb.png", 10, 20, true );
}

void endGame() {
	DestroySprite(screen.sprite);
	DestroySprite(player1.sprite);
	DestroySprite(target.sprite);
	for (int i = 0; i <= 19; i++)
	DestroySprite(monster[i].sprite);
	for (int i = 0; i <= 19; i++)
	DestroySprite(explosion[i].sprite);
	DestroySprite(scoreIcon3.sprite);
	DestroySprite(scoreIcon2.sprite);
	DestroySprite(scoreIcon.sprite);
	DestroySprite(screen.sprite);
	DestroySprite(screenTwo.sprite);

	for (int i = 0; i < 50; i++)
	DestroySprite(bullet[i].sprite);
	DestroySprite(getSprite('L'));
	DestroySprite(getSprite('E'));
	DestroySprite(getSprite('P'));
}

void updateGame() {
	int mX;
	int mY;
	GetMouseLocation(mX,mY);
	vMouse.x = (float)mX;
	vMouse.y = (float)mY;
	if (iLives == 4)
	{
		if ((IsKeyDown(GLFW_KEY_ENTER)) ||(vMouse.x >= 100 && vMouse.x <= 500 && vMouse.y >= 50 && vMouse.y <= 350 && GetMouseButtonDown(0))){
			iLives--;
			wave++;
		}
		if ((IsKeyDown(GLFW_KEY_BACKSPACE)) ||(vMouse.x >= 300 && vMouse.x <= 700 && vMouse.y >= 350 && vMouse.y <= 650 && GetMouseButtonDown(0))){
			iLives = -1;
		}
		MoveSprite(getSprite('P'),(int)300,(int)200);
		MoveSprite(getSprite('E'),(int)500,(int)500);
	}
	else if (iLives <= 0)
	{
		MoveSprite(getSprite('L'),(int)vScreen.x/2,(int)vScreen.y/2);
		MoveSprite(getSprite('W'),(int)500,(int)500);
		if (IsKeyDown(' '))
			iLives = -1;
	}
	else
	{
		
		for (int i = 0; i < 50; i++)
		updateBullet(bullet[i],player1);
		fireBullet(player1);
		updatePlayer(player1);
		updateScreen();
		for (int i = 0; i <= 19; i++)
			updateAi(monster[i]);

		MoveSprite(target.sprite, (int)vMouse.x, (int)vMouse.y);
		RotateSprite(player1.sprite,(int)getPlayerAngle(player1));
		MoveSprite(player1.sprite, (int)player1.position.x, (int)player1.position.y);

		MoveSprite(scoreIcon.sprite,(int)scoreIcon.position.x,(int)scoreIcon.position.y);
		MoveSprite(scoreIcon2.sprite,(int)scoreIcon2.position.x,(int)scoreIcon2.position.y);
		MoveSprite(scoreIcon3.sprite,(int)scoreIcon3.position.x,(int)scoreIcon3.position.y);


		for (int i = 0; i < 50; i++)
		MoveSprite(bullet[i].sprite,(int)bullet[i].position.x,(int)bullet[i].position.y);
		for (int i = 0; i <= 19; i++)
		{
			updateExplosion(explosion[i]);
			MoveSprite(explosion[i].sprite, (int)explosion[i].position.x, (int)explosion[i].position.y);

			if (monster[i].alive)
				MoveSprite(monster[i].sprite, (int)monster[i].position.x, (int)monster[i].position.y);			
		}
	}
}
void drawGame() {
	if (iLives == 4)
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

		DrawSprite(target.sprite);
		DrawSprite(player1.sprite);
		for (int i = 0; i <= 19; i++)
		{
			DrawSprite(explosion[i].sprite);
			if (monster[i].alive)
				DrawSprite(monster[i].sprite);
		}
		for (int i = 0; i < 50; i++)
			if (bullet[i].alive)
				DrawSprite(bullet[i].sprite);
		switch(iLives)
		{
		case 3:
			DrawSprite(scoreIcon3.sprite);
		case 2:
			DrawSprite(scoreIcon2.sprite);
		case 1:
			DrawSprite(scoreIcon.sprite);
			break;
		}
	}
	DrawSprite(screen.sprite);
	DrawSprite(screenTwo.sprite);
}

int main()
{
	// First we need to create our Game Framework
	Initialise((int)vScreen.x, (int)vScreen.y, false );

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