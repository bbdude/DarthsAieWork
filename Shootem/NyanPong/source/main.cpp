//////////////////////////////////////////////////////////////////////////
//	Author:	Jacob Miller
//	Date:	09/13/2013
//	Brief:	Main file for Pong
//////////////////////////////////////////////////////////////////////////
#define _USE_MATH_DEFINES
//////////////////////////////////////////////////////////////////////////
#include "AIE.h"
#include "KeyCodes.h"
#include <string>
#include <cmath>
#include <assert.h>
#include <crtdbg.h>
#include <ctime>
#include <iostream>
#include <list>
//////////////////////////////////////////////////////////////////////////

//creates 2 variables that act as coords
struct vector2{
	float x;
	float y;
};
//creates a set of variables assigned to a movable object
struct movableObject{
	vector2 position;
	vector2 speed;
	int sprite;
	int width;
	int height;
	bool alive;
};
//creates a set of variables assigned to a object that does not move
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
//Declarations
//screen size
const int iScreenX = 1280;
const int iScreenY = 780;
//Player Lives
int iLives = 4;
int whatBullet = 0;
int iWin = -1;
int iLose = -1;
int iLeave = -1;
int iPlay = -1;
int iMouseX = 0;
int iMouseY = 0;
float playerAngle = 0;
bool pressTrigger = false;
//Game objects
////////////////////////////Objects that will never move///////////////////
tempObject scoreIcon = {200,50,-1,52,52,true,8000};
tempObject scoreIcon2 = {230,50,-1,52,52,true,8000};
tempObject scoreIcon3 = {260,50,-1,52,52,true,8000};
bulletStruct bullet[50];// = {-100,-100,0,0,false,-1,10,20};

//tempObject bullet = {-100,-100,-1,50,50,false,1000};

//////////////////////////////////////////////////////////////////////////
////////////////////////////Objects that will be moving///////////////////
movableObject player1 = {500, 300, 1, 1, -1 , 5, 5,true};
movableObject monster[3];
movableObject target = {0,0,0,0,-1,50,50,true};
movableObject screen = {0,0,0,.05f,-1,780,3840,true};
//movableObject monster = {500, 300, 1, 0, -1 , 5, 5,true};
//////////////////////////////////////////////////////////////////////////

/*  vectorSubtract

    input:    Vector 2, Float

    output:   Vector 2

    remarks:  Subtracts a float value from the chosen Vector 2
*/
vector2 vectorSubtract(vector2 &v, float s){
	vector2 result = {v.x - s, v.y - s};
	return result;
}

/*  vectorAdd

    input:    Vector 2, Float

    output:   Vector 2

    remarks:  Adds a float value to the chosen Vector 2
*/
vector2 vectorAdd(vector2 &v, float s){
	vector2 result = {v.x + s, v.y + s};
	return result;
}

/*  multiplyScalar

    input:    Vector 2, Float

    output:   Vector 2

    remarks:  Scales a Vector2 by the chosen float
*/
vector2 multiplyScalar(vector2 &v, float s){
	vector2 result = {v.x * s, v.y * s};
	return result;
}

/*  vectorSubtract

    input:    Vector 2, Vector 2

    output:   Vector 2

    remarks:  Subtracts one float from the other
*/
vector2 vectorSubtract(vector2 &v, vector2 &v2){
	vector2 result = {v.x - v2.x, v.y - v2.y};
	return result;
}

/*  vectorAdd

    input:    Vector 2, Vector 2

    output:   Vector 2

    remarks:  Subtracts one Vector 2 from another
*/
vector2 vectorAdd(vector2 &v, vector2 &v2){
	vector2 result = {v.x + v2.x, v.y + v2.y};
	return result;
}

/*  getNormal

    input:    Vector 2

    output:   Vector 2

    remarks:  Gets the normal of a Vector2 by getting the magnitude and then dividing the x and y by the magnitude.
*/
vector2 getNormal(vector2 &v){
	float mag = sqrt(v.x*v.x + v.y*v.y);
	vector2 result = {v.x/mag, v.y/mag};
	return result;
}

/*  getMagnitude

    input:    Vector 2

    output:   Vector 2

    remarks:  Gets the Magnitude of a Vector2
*/
float getMagnitude(vector2 &v){
	return sqrt(v.x*v.x + v.y*v.y);
}

void loadLevel(int level)
{
	switch (level)
	{
	case 1:
		
		monster[0].position.x = 50;// + 25;
		monster[0].position.y = 50;// + 25;
		monster[1].position.x = 100;// + 25;
		monster[1].position.y = 100;// + 25;
		monster[2].position.x = 150;// + 25;
		monster[2].position.y = 150;// + 25;
		
		//player1.position.x = bricks[23][13].position.x;// + 25;
		//player1.position.y = bricks[23][13].position.y;// + 25;
		for (int i = 0; i < 50; i++)
		{
			bullet[i].alive = true;
			bullet[i].angle.x = 0;
			bullet[i].angle.y = 0;
			bullet[i].height = 20;
			bullet[i].width = 10;
			bullet[i].sprite = -1;
		}
		for (int i = 0; i <= 2; i++)
		{
			monster[i].alive = true;
			monster[i].height = 20;
			monster[i].sprite = -1;
			monster[i].width = 20;
			monster[i].speed.x = -1;
			monster[i].speed.y = 0.05f;
		}
		break;
	default:
		break;
	}

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
		&& objOne.position.y >= objTwo.position.y - (objTwo.width/2)&& objOne.position.y <= objTwo.position.y + (objTwo.height/2))
	{
		return false;
	}
	return true;
}
void updateBullet(bulletStruct &bullets,movableObject &player)
{
	if (bullets.position.x < 0 || bullets.position.x  > 1280 || bullets.position.y  < 0 || bullets.position.y > 780)
		bullets.alive = false;
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
		bullet[whatBullet].angle.y = -1;
		//bullets.angle.x = std::cos(a);
		//bullets.angle.y = std::sin(a);
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
	if (IsKeyDown('S') && player.position.y + (player.height/2) + player.speed.y <= iScreenY)
	{
		plannedMovement.y += player.speed.y;
		//player.position.y += player.speed.y;
	}
	if (IsKeyDown('A') && player.position.x - (player.width/2) - player.speed.x >= 0)
	{
		plannedMovement.x -= player.speed.x;
		//player.position.x -= player.speed.x;
	}
	if (IsKeyDown('D') && player.position.x + (player.width/2) + player.speed.x <= iScreenX)
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
	for (int i = 0; i <= 2; i++)
	{
		if (!detectCollision(player,monster[i]) && monster[i].alive)
		{
			//loadLevel(1);
			iLives--;
		}
	}

}

float getPlayerAngle(movableObject &player)
{
	return std::tan((player.position.y-iMouseY)/(player.position.x-iMouseX));
}

void updateAi(movableObject &monster){
	if (monster.alive)
	{
	vector2 plannedMovement = {0,0};
	plannedMovement = vectorAdd(plannedMovement,monster.speed);
	bool moving = true;
	bool stopIt = false;


	if (monster.position.x + plannedMovement.x < 20 || monster.position.x + plannedMovement.x > 1260)
		moving = false;
	for (int i = 0; i < 49; i++)
		if (!detectCollision(bullet[i],monster))
			monster.alive = false;
	if (moving && !stopIt)
		monster.position = vectorAdd(monster.position,plannedMovement);
	else 
		monster.speed.x = multiplyScalar(monster.speed,-1).x;
	}
}
void updateScreen()
{
	screen.position = vectorAdd(screen.position,screen.speed);
	MoveSprite(screen.sprite, screen.position.x, screen.position.y);
}
void loadGame() {
	srand((int)time(0));
	//fillBulletStruct();
	// Now load some sprites
	loadLevel(1);
	screen.position.x = 0;
	screen.position.y = -iScreenY*2;
	screen.sprite = CreateSprite( "./images/bg2.png", iScreenX, iScreenY*3,false );
	//MoveSprite(screen.sprite, iScreenX>>1, iScreenY>>1);
	MoveSprite(screen.sprite, screen.position.x, screen.position.y);
	iLose = CreateSprite( "./images/lose.png", 400, 300, true );
	iLeave = CreateSprite( "./images/exit.png", 400, 300, true );
	iPlay = CreateSprite( "./images/play.png", 400, 300, true );
	iWin = CreateSprite( "./images/win.png", 400, 300, true );
	scoreIcon.sprite = CreateSprite( "./images/cherry.png", 52, 52, true );
	scoreIcon2.sprite = CreateSprite( "./images/cherry.png", 52, 52, true );
	scoreIcon3.sprite = CreateSprite( "./images/cherry.png", 52, 52, true );

	player1.sprite = CreateSprite( "./images/player.png", 20, 20, true );
	target.sprite = CreateSprite( "./images/flag.png", 50, 50, true );
	for (int i = 0; i <= 2; i++)
		monster[i].sprite = CreateSprite( "./images/enemy.png", 20, 20, true );
	for (int i = 0; i < 50; i++)
	bullet[i].sprite = CreateSprite( "./images/bomb.png", 10, 20, true );
	/*
	bricks[0].position.x =  (float)(300+(rand()%600));
	bricks[1].position.x =  (float)(300+(rand()%600));
	bricks[2].position.x =  (float)(300+(rand()%600));
	bricks[0].position.y = (float)(200+(rand()%400));
	bricks[1].position.y = (float)(200+(rand()%400));
	bricks[2].position.y = (float)(200+(rand()%400));
	*/
}

/*  endGame

    input:    

    output:   void

    remarks:  Destroys all the sprites when they game has ended
*/
void endGame() {
	DestroySprite(screen.sprite);
	DestroySprite(player1.sprite);
	DestroySprite(target.sprite);
	DestroySprite(monster[0].sprite);
	DestroySprite(monster[1].sprite);
	DestroySprite(monster[2].sprite);
	DestroySprite(scoreIcon3.sprite);
	DestroySprite(scoreIcon2.sprite);
	DestroySprite(scoreIcon.sprite);

	for (int i = 0; i < 50; i++)
	DestroySprite(bullet[i].sprite);
	DestroySprite(iLose);
	DestroySprite(iLeave);
	DestroySprite(iPlay);
}

/*  updateGame

    input:    

    output:   void

    remarks:  Runs each of the update functions, runs cheat codes, determines how much life each player has.
*/
void updateGame() {
	GetMouseLocation(iMouseX,iMouseY);
	if (iLives == 4)
	{
		if ((IsKeyDown(GLFW_KEY_ENTER)) ||(iMouseX >= 100 && iMouseX <= 500 && iMouseY >= 50 && iMouseY <= 350 && GetMouseButtonDown(0)))
			iLives--;
		if ((IsKeyDown(GLFW_KEY_BACKSPACE)) ||(iMouseX >= 300 && iMouseX <= 700 && iMouseY >= 350 && iMouseY <= 650 && GetMouseButtonDown(0)))
			iLives = -1;
		MoveSprite(iPlay,(int)300,(int)200);
		MoveSprite(iLeave,(int)500,(int)500);
		//GetMouseLocation(0,0);
			//lives = -1;
	}
	else if (iLives <= 0)
	{
		MoveSprite(iWin,(int)500,(int)500);
		MoveSprite(iLose,(int)500,(int)500);
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
		for (int i = 0; i <= 2; i++)
			updateAi(monster[i]);

		MoveSprite(target.sprite, (int)iMouseX, (int)iMouseY);
		RotateSprite(player1.sprite,getPlayerAngle(player1));
		MoveSprite(player1.sprite, (int)player1.position.x, (int)player1.position.y);
		
		for (int i = 0; i <= 2; i++)
			MoveSprite(monster[i].sprite, (int)monster[i].position.x, (int)monster[i].position.y);

		MoveSprite(scoreIcon.sprite,(int)scoreIcon.position.x,(int)scoreIcon.position.y);
		MoveSprite(scoreIcon2.sprite,(int)scoreIcon2.position.x,(int)scoreIcon2.position.y);
		MoveSprite(scoreIcon3.sprite,(int)scoreIcon3.position.x,(int)scoreIcon3.position.y);


		MoveSprite(iLose,(int)iScreenX/2,(int)iScreenY/2);
		for (int i = 0; i < 50; i++)
		MoveSprite(bullet[i].sprite,(int)bullet[i].position.x,(int)bullet[i].position.y);
	}
}
/*  drawGame

    input:    

    output:   void

    remarks:  Draws the sprites of every object in layers. the last line being the last one drawn ; the first line being drawn first
*/
void drawGame() {
	if (iLives == 4)
	{
		DrawSprite(iPlay);
		DrawSprite(iLeave);
	}
	////else if (iLiveE <= 0)
	//	DrawSprite(iWin);
	else if (iLives <= 0)
	{
		DrawSprite(iLose);
	}
	else
	{

		DrawSprite(target.sprite);
		DrawSprite(player1.sprite);
		for (int i = 0; i <= 2; i++)
			if (monster[i].alive)
				DrawSprite(monster[i].sprite);
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
	//DrawSprite(screen.sprite);
}

/*  main

    input:    

    output:   int

    remarks:  Runs the game loop until you run out of lives or the framework crashes.
				1st it Initializes,
				2nd it loads all the sprites,
				3rd it clears the screen,
				4th it updates the game,
				5th it draws the game,
				6th it repeats until said otherwise,
				7th it destroys the sprites and shuts down the game
*/
int main()
{
	// First we need to create our Game Framework
	Initialise(iScreenX, iScreenY, false );

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