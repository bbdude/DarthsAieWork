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
//Declarations
//screen size
const int iScreenX = 1280;
const int iScreenY = 780;
//Player Lives
int iLives = 4;
//Images (yes I know they are ints)
int iWin = -1;
int iBgImage = -1;
int iLose = -1;
int iLeave = -1;
int iPlay = -1;
int iMouseX = 0;
int iMouseY = 0;
//Game objects
////////////////////////////Objects that will never move///////////////////
tempObject scoreIcon = {200,50,-1,52,52,true,8000};
tempObject scoreIcon2 = {230,50,-1,52,52,true,8000};
tempObject scoreIcon3 = {260,50,-1,52,52,true,8000};
stableObject bricks[20][15];
tempObject bomb = {-100,-100,-1,50,50,false,1000};
tempObject cloud = {-100,-100,-1,130,130,false,0};
//////////////////////////////////////////////////////////////////////////
////////////////////////////Objects that will be moving///////////////////
movableObject player1 = {500, 300, 1, 1, -1 , 5, 5};
movableObject monster = {500, 300, 1, 1, -1 , 5, 5};
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

bool detectCollisionBricks(movableObject &player,stableObject brick,vector2 plannedMovement)
{
	if(player.position.x + plannedMovement.x >= brick.position.x - (brick.width/2) && player.position.x  + plannedMovement.x <= brick.position.x + (brick.width/2)
		&& player.position.y  + plannedMovement.y >= brick.position.y - (brick.width/2)&& player.position.y + plannedMovement.y <= brick.position.y + (brick.height/2) && (brick.tag == "WALL" || brick.tag == "BREAK") )
	{
		return false;
	}
	return true;
}
bool detectCollisionBricks(movableObject &player,tempObject brick,vector2 plannedMovement)
{
	if(player.position.x + plannedMovement.x >= brick.position.x - (brick.width/2) && player.position.x  + plannedMovement.x <= brick.position.x + (brick.width/2)
		&& player.position.y  + plannedMovement.y >= brick.position.y - (brick.width/2)&& player.position.y + plannedMovement.y <= brick.position.y + (brick.height/2) && brick.time != 1000)
	{
		return false;
	}
	return true;
}

/*  updatePlayer

    input:    movableObject,

    output:   void

    remarks:  Allows players to use the controls, be stunned, recover from stuns, shoot, and move.
*/
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
	for (int x = 0; x < 25; x++)
	{
		for (int y = 0; y < 15; y++)
		{
			moving = detectCollisionBricks(player,bricks[x][y],plannedMovement);
			if (!moving)
			{
				stopIt = true;
				//std::cout << "Stopping\n" << i;
			}
		}
		moving = detectCollisionBricks(player,bomb,plannedMovement);
	}
	if (moving && !stopIt)
		player.position = vectorAdd(player.position,plannedMovement);

}

void updateAi(movableObject &monster){
	vector2 plannedMovement = {0,0};
	plannedMovement = vectorAdd(plannedMovement,monster.speed);
	bool moving = true;
	bool stopIt = false;
	for (int x = 0; x < 25; x++)
	{
		for (int y = 0; y < 15; y++)
		{
			moving = detectCollisionBricks(monster,bricks[x][y],plannedMovement);
			if (!moving)
			{
				stopIt = true;
				//std::cout << "Stopping\n" << i;
			}
		}
		moving = detectCollisionBricks(monster,bomb,plannedMovement);
	}
	if (moving && !stopIt)
		monster.position = vectorAdd(monster.position,plannedMovement);
	else 
		monster.speed = multiplyScalar(monster.speed,-1);

}

/*  updateBricks

    input:    

    output:   void

    remarks:  destroys the bricks, brings them back to life, and checks on their collision
*/
void updateBricks()
{
	/*
	if (!bricks[0].alive)
	{
		bricks[0].time--;
		if (bricks[0].time <= 0)
		{
			bricks[0].time = 8000;
			bricks[0].alive = true;
			bricks[0].position.y = (float)200+(rand()%400);
			bricks[0].position.x =  (float)300+(rand()%600);
		}
	}
	if (!bricks[1].alive)
	{
		bricks[1].time--;
		if (bricks[1].time <= 0)
		{
			bricks[1].time = 8000;
			bricks[1].alive = true;
			bricks[1].position.y = (float)200+(rand()%400);
			bricks[1].position.x =  (float)300+(rand()%600);
		}
	}
	if (!bricks[2].alive)
	{
		bricks[2].time--;
		if (bricks[2].time <= 0)
		{
			bricks[2].time = 8000;
			bricks[2].alive = true;
			bricks[2].position.y = (float)200+(rand()%400);
			bricks[2].position.x =  (float)300+(rand()%600);
		}
	}
	*/
	//detectBrickCollision(bricks[1],player1);
	//detectBrickCollision(bricks[2],player1);
}

void updateBomb(tempObject &bombs,movableObject player)
{
	//bombs.time = 1000;
	if (bombs.time == 0)
	{
		//std::cout << "Killing a brick";
		bombs.time = 1000;
		for (int x = 0; x < 25; x++)
		{
			for (int y = 0; y < 19; y++)
			{
				if (bricks[x][y].tag == "BREAK")
					if (bricks[x][y].position.x >= bombs.position.x - (bombs.width/2) - 50 && bricks[x][y].position.x <= bombs.position.x + (bombs.width/2) + 50 && bricks[x][y].position.y >= bombs.position.y - (bombs.width/2) - 50 && bricks[x][y].position.y <= bombs.position.y + (bombs.width/2) + 50)
					{
						bricks[x][y].tag = "DEAD";
						std::cout << "Killing a brick";
					}
				//if (bricks[x][y].position.x == bombs.position.x - (bombs.width/2) && (bricks[x][y].position.y == bombs.position.y - (bombs.height/2) - 61 || bricks[x][y].position.y == bombs.position.y - (bombs.height/2) + 61))
			}
		}
	}
	if (bombs.time < 1000 && bombs.time > 0)
		bombs.time--;
	if (IsKeyDown(GLFW_KEY_SPACE))
	{
		if (bombs.time == 1000)
		{
			std::cout << "Placing Bomb";
			bombs.time--;
			bombs.position.x = player.position.x - (bombs.width/2);
			bombs.position.y = player.position.y - (bombs.height/2);
			for (int x = 0; x < 25; x++)
			{
				for (int y = 0; y < 19; y++)
				{
					bombs.position.y = (float)((y*bombs.height) + bombs.height - 9);
					if (bombs.position.y - (52/2) <= player.position.y - 10 && bombs.position.y  + (52/2) >= player.position.y + 10)
						return;
				}
				bombs.position.x = (float)((x*bombs.width) + bombs.width - 10);
				if (bombs.position.x - (52/2) <= player.position.x - 10 && bombs.position.x  + (52/2) >= player.position.x + 10)
					return;
			}
		}
	}
}
void updateCloud(tempObject &clouds, tempObject bombs)
{
	if (bombs.time == 0)
	{
		clouds.time = 200;
		std::cout << "Showing cloud";
	}
	if (clouds.time > 0)
		clouds.time--;

	clouds.position.x = bombs.position.x;
	clouds.position.y = bombs.position.y;
}
void loadBrick()
{
	for(int x = 0; x < 24; x++)
	{
		for(int y = 0; y < 15; y++)
		{
			bricks[x][y].sprite = -1;
			bricks[x][y].width = 52;
			bricks[x][y].height = 50;
			bricks[x][y].tag = "WALL";
			//bricks[x][y].time = 1000000000000000000;
		}
	}
	for(int x = 0; x < 24; x++)
	{
		for(int y = 0; y < 15; y++)
		{
			bricks[x][y].position.x = (float)(x*bricks[x][y].width) + bricks[x][y].width - 10;
			bricks[x][y].position.y = (float)(y*bricks[x][y].height) + bricks[x][y].height - 9;
		}
	}
}
void loadLevel(int level)
{
	switch (level)
	{
	case 1:
		for (int x = 1; x < 23; x++)
			bricks[x][1].tag = "FLOOR";
		bricks[2][2].tag = "FLOOR";
		bricks[2][4].tag = "FLOOR";
		for (int x = 1; x < 24; x++)
			bricks[x][5].tag = "FLOOR";
		bricks[22][6].tag = "FLOOR";
		bricks[22][8].tag = "FLOOR";
		for (int x = 1; x < 24; x++)
			bricks[x][9].tag = "FLOOR";
		bricks[2][10].tag = "FLOOR";
		bricks[2][12].tag = "FLOOR";
		for (int x = 1; x < 24; x++)
			bricks[x][13].tag = "FLOOR";
		bricks[23][1].tag = "FLAG";
		bricks[2][3].tag = "BREAK";
		bricks[22][7].tag = "BREAK";
		bricks[2][11].tag = "BREAK";
		break;
	default:
		break;
	}

}
/*  loadGame

    input:    

    output:   void

    remarks:  Creates the sprites for each object
*/
void loadGame() {
	srand((int)time(0));
	//fillBulletStruct();
	// Now load some sprites
	loadBrick();
	loadLevel(1);
	iBgImage = CreateSprite( "./images/bg.png", iScreenX, iScreenY, true );
	MoveSprite(iBgImage, iScreenX>>1, iScreenY>>1);
	iLose = CreateSprite( "./images/lose.png", 400, 300, true );
	iLeave = CreateSprite( "./images/exit.png", 400, 300, true );
	iPlay = CreateSprite( "./images/play.png", 400, 300, true );
	iWin = CreateSprite( "./images/win.png", 400, 300, true );
	scoreIcon.sprite = CreateSprite( "./images/cherry.png", 52, 52, true );
	scoreIcon2.sprite = CreateSprite( "./images/cherry.png", 52, 52, true );
	scoreIcon3.sprite = CreateSprite( "./images/cherry.png", 52, 52, true );
	for (int x = 0; x <= 25; x++)
		for (int y = 0; y <= 15; y++)
		{
			if (bricks[x][y].tag == "WALL")
				bricks[x][y].sprite = CreateSprite( "./images/brick.png", 52, 52, true );
			else if (bricks[x][y].tag == "FLAG")
				bricks[x][y].sprite = CreateSprite( "./images/flag.png", 52, 52, true );
			else if (bricks[x][y].tag == "BREAK")
				bricks[x][y].sprite = CreateSprite( "./images/breakable.png", 52, 52, true );
			else
				bricks[x][y].sprite = CreateSprite( "./images/floor.png", 52, 52, true );
		}
		player1.sprite = CreateSprite( "./images/cat1.png", 20, 20, true );
		bomb.sprite = CreateSprite( "./images/bomb.png", 52, 52, true );
		cloud.sprite = CreateSprite( "./images/cloud.png", 130, 130, true );
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
	DestroySprite(iBgImage);
	DestroySprite(player1.sprite);
	DestroySprite(scoreIcon3.sprite);
	DestroySprite(scoreIcon2.sprite);
	DestroySprite(scoreIcon.sprite);

	for (int x = 0; x < 25; x++)
		for (int y = 0; y < 15; y++)
			DestroySprite(bricks[x][y].sprite);

	DestroySprite(bomb.sprite);
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
	updateBomb(bomb,player1);
	updateCloud(cloud,bomb);
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
		updateBricks();
		updatePlayer(player1);

		MoveSprite(player1.sprite, (int)player1.position.x, (int)player1.position.y);

		MoveSprite(scoreIcon.sprite,(int)scoreIcon.position.x,(int)scoreIcon.position.y);
		MoveSprite(scoreIcon2.sprite,(int)scoreIcon2.position.x,(int)scoreIcon2.position.y);
		MoveSprite(scoreIcon3.sprite,(int)scoreIcon3.position.x,(int)scoreIcon3.position.y);

		for (int x = 0; x < 25; x++)
			for (int y = 0; y < 15; y++)
				MoveSprite(bricks[x][y].sprite,(int)bricks[x][y].position.x,(int)bricks[x][y].position.y);

		MoveSprite(cloud.sprite,(int)cloud.position.x,(int)cloud.position.y);
		MoveSprite(iLose,(int)iScreenX/2,(int)iScreenY/2);
		MoveSprite(bomb.sprite,(int)bomb.position.x,(int)bomb.position.y);
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
	if (iLives <= 0)
	{
		DrawSprite(iLose);
	}
	else
	{

		DrawSprite(player1.sprite);
		if (cloud.time > 0)
			DrawSprite(cloud.sprite);
		if (bomb.time != 1000)
			DrawSprite(bomb.sprite);
		if (iLives == 3)
			DrawSprite(scoreIcon3.sprite);
		if (iLives >= 2)
			DrawSprite(scoreIcon2.sprite);
		if (iLives >= 1)
			DrawSprite(scoreIcon.sprite);
		for (int x = 0; x < 25; x++)
			for (int y = 0; y < 15; y++)
			if (bricks[x][y].tag != "DEAD")
				DrawSprite(bricks[x][y].sprite);
	}
	DrawSprite(iBgImage);
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