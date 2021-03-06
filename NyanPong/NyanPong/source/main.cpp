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
//creates a set of variables designed to fire a bullet and reload it
struct BulletStruct{
	vector2 position;
	vector2 speed;
	int sprite;
	int width;
	int height;
	bool out;
};
//creates a set of variables assigned to a object that does not move
struct stableObject{
	vector2 position;
	int sprite;
	int width;
	int height;
	bool alive;
	int time;
};
//Declarations
//screen size
const int screenX = 1280;
const int screenY = 780;
//Player two paddle ai timer
const int maxAiEndTime = 10000;
int currentAiTime = 1000;
//Mode variables
bool twoPlayerMode = false;
bool mouseMode = true;
//Disable the paddles
bool disablePOne = false;
int disableTimerOne = 500;
bool disablePTwo = false;
int disableTimerTwo = 500;
//Time to hit back variables  + arcing
int hitBackTimer = 0;
int coolDown = 0;
int arcStage = 0; // 0begin arc,1 raise x and y, 2 lower y raise x,3 keep its current angle
float originalArcX = 1000000;
bool arcingUp = false;
//Player Lives
int lives = 4;
int livesE= 3;
//Images (yes I know they are ints)
int win = -1;
int bgImage = -1;
int lose = -1;
int leave = -1;
int play = -1;
int mouseX = 0;
int mouseY = 0;
//Game objects
////////////////////////////Objects that will never move///////////////////
stableObject hole = {640,390,-1,52,52,true,8000};
stableObject scoreIcon = {200,50,-1,52,52,true,8000};
stableObject scoreIcon2 = {230,50,-1,52,52,true,8000};
stableObject scoreIcon3 = {260,50,-1,52,52,true,8000};
stableObject scoreIconE = {screenX - 200,50,-1,52,52,true,8000};
stableObject scoreIconE2 = {screenX - 230,50,-1,52,52,true,8000};
stableObject scoreIconE3 = {screenX - 260,50,-1,52,52,true,8000};
stableObject brick = {200,50,-1,52,52,true,8000};
stableObject brick2 = {230,50,-1,52,52,true,8000};
stableObject brick3 = {260,50,-1,52,52,true,8000};
////////////////////////////The bullets for each paddle///////////////////
BulletStruct bullet = {-5, -5, 1, 0, -1, 20, 20,false};
BulletStruct bulletTwo = {-5, -5, 1, 0, -1, 20, 20,false};
//////////////////////////////////////////////////////////////////////////
////////////////////////////Objects that will be moving///////////////////
movableObject player1 = {100, 100, 0, 0, -1 , 20, 120};
movableObject player2 = {1200, 100, 0, 0, -1, 20, 120};
movableObject ball = {500, 500, 1,1, -1, 64, 92};
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

/*  updateBallArc

    input:    movableObject

    output:   void

    remarks:  Arcs the ball in the direction in was going when the arc was activated.
*/
void updateBallArc(movableObject &obj) {
	if (ball.speed.y < 0)
	{
		if (ball.position.x > originalArcX + 90 && arcStage == 2)
		{
			arcStage = 0;
			originalArcX = 10000;
		}
		else if (ball.position.x > originalArcX + 30 && arcStage == 1)
		{
			arcStage = 2;
		}
		if (arcStage == 1 && ball.position.y + 1 < screenY)
		{
			ball.position.x += .5f;
			ball.position.y += .9f;
		}
		else if (arcStage == 2 && ball.position.y - 1 < screenY)
		{
			ball.position.x += .5f;
			ball.position.y -= .9f;
		}
	}
	else if (ball.speed.y > 0)
	{
		if (ball.position.x > originalArcX + 90 && arcStage == 2)
		{
			arcStage = 0;
			originalArcX = 10000;
		}
		else if (ball.position.x > originalArcX + 30 && arcStage == 1)
		{
			arcStage = 2;
		}
		if (arcStage == 1 && ball.position.y - 1 < screenY)
		{
			ball.position.x += .5f;
			ball.position.y -= .9f;
		}
		else if (arcStage == 2 && ball.position.y + 1 < screenY)
		{
			ball.position.x += .5f;
			ball.position.y += .9f;
		}
	}
}

/*  ballOnScreen

    input:    movableObject

    output:   void

    remarks:  Detect where the ball is so that players can score and reset the balls position
*/
void ballOnScreen(movableObject& obj){
	if(obj.position.x > screenX) {
		obj.position.x = screenX/2;
		obj.speed.x *= -1;
		livesE--;
	}
	if(obj.position.x < 0) {
		obj.position.x = screenX/2;
		obj.speed.x *= -1;
		lives--;
	}
	if(obj.position.y > screenY) {
		obj.speed.y *= -1;
	}
	if(obj.position.y < 0) {
		obj.speed.y *= -1;
	}
}

/*  updateBallPosition

    input:    movableObject

    output:   void

    remarks:  Adds the balls speed to its position. Also checks whether the ball is about to arc or not
*/
void updateBallPosition(movableObject &obj) {
	obj.position = vectorAdd(obj.position, obj.speed);
	if (arcStage = -1)
	{
		arcStage = 1;
		originalArcX = ball.position.x;
	}
	updateBallArc(ball);
}

/*  updateAi

    input:    movableObject, movableObject

    output:   void

    remarks:  Tells the 2nd paddle to adjust his Y position when the ball is close to him and to fire the bullets
*/
void updateAi(movableObject &player, movableObject& ball){
	float speed = sqrt(ball.speed.x*ball.speed.x + ball.speed.y*ball.speed.y);
	//player.position.y = ball.position.y;
	if (!disablePTwo)
	{
	currentAiTime -= rand() % 10;
	if (currentAiTime <= 0)
		currentAiTime = maxAiEndTime;
	if (player.position.y != ball.position.y && currentAiTime <= (maxAiEndTime/2 + maxAiEndTime/2.7))
	{
		if(ball.position.x >= screenX/2)
		{
			//std::cout << currentAiTime << "\n";
			if (player.position.y < ball.position.y && player.position.y + speed < 780)
				player.position.y += speed;
			else if (player.position.y > ball.position.y && player.position.y + speed > 0)
				player.position.y -= speed;
		}
	}
	else
	{
		if (!bulletTwo.out)
		{
			std::cout << "Fire";
			bulletTwo.out = true;
			bulletTwo.speed.x = -1;
			bulletTwo.position.x = player.position.x;
			bulletTwo.position.y = player.position.y;
		}
		if (player.position.y < ball.position.y && player.position.y + speed > 0)
			player.position.y -= speed/2;
		else if (player.position.y > ball.position.y && player.position.y + speed < 780)
			player.position.y += speed/2;
	}
	}
	else
	{
		disableTimerTwo--;
		if (disableTimerTwo <= 0)
		{
			disableTimerTwo = 500;
			disablePTwo = false;
		}
	}
	//else
		//player.position.y--;
}

/*  detectPaddleCollision

    input:    movableObject, movableObject

    output:   bool

    remarks:  Determines if the ball has collided with the paddle or not. if so then bounce the ball backwards
*/
bool detectPaddleCollision(movableObject &player, movableObject& ball){
	
	if(ball.position.x >= player.position.x - (player.width/2) && ball.position.x <= player.position.x + (player.width/2)
		&& ball.position.y >= player.position.y - (player.width/2)&& ball.position.y <= player.position.y + (player.height/2))
	{
		ball.speed.x *= -1;
		updateBallPosition(ball);
		//ball.speed.y *= -1;
		return true;
	}
	else if (ball.position.x >= player.position.x - (player.width/2) && ball.position.x <= player.position.x + (player.width/2) && ball.position.y <= player.position.y - (player.width/2) + 5 && ball.position.y >= player.position.y - (player.width/2) - 5)
	{
		ball.speed.y *= -1;
		ball.speed.x *= -1;
		updateBallPosition(ball);
		return true;
	}
	else if (ball.position.x >= player.position.x - (player.width/2) && ball.position.x <= player.position.x + (player.width/2) && ball.position.y >= player.position.y + (player.width/2) - 5 && ball.position.y <= player.position.y + (player.width/2) + 5)
	{
		ball.speed.y *= -1;
		ball.speed.x *= -1;
		updateBallPosition(ball);
		return true;
	}
	return false;
}

/*  detectBrickCollision

    input:    stableObject, movableObject, movableObject, movableObject

    output:   void

    remarks:  Determines if a brick has collided with a bullet or a ball. if it collides with a bullet then destroy it.
			  if it collides with a ball then move all players forward and reverse the balls direction.
*/
void detectBrickCollision(stableObject &brick, movableObject& ball, movableObject& player1, movableObject& player2){
	if(ball.position.x >= brick.position.x - (brick.width/2) && ball.position.x <= brick.position.x + (brick.width/2)
		&& ball.position.y >= brick.position.y - (brick.width/2)&& ball.position.y <= brick.position.y + (brick.height/2)
			&& brick.alive)
	{
		player1.position.x+= 25;
		player2.position.x-= 25;
		brick.alive = false;
		ball.speed.x *= -1;
		ball.speed.y *= -1;
	}
	if(bullet.position.x >= brick.position.x - (brick.width/2) && bullet.position.x <= brick.position.x + (brick.width/2)
		&& bullet.position.y >= brick.position.y - (brick.width/2)&& bullet.position.y <= brick.position.y + (brick.height/2)
			&& brick.alive)
	{
		bullet.out = false;
		brick.alive = false;
	}
	if(bulletTwo.position.x >= brick.position.x - (brick.width/2) && bulletTwo.position.x <= brick.position.x + (brick.width/2)
		&& bulletTwo.position.y >= brick.position.y - (brick.width/2)&& bulletTwo.position.y <= brick.position.y + (brick.height/2)
			&& brick.alive)
	{
		bulletTwo.out = false;
		brick.alive = false;
	}
}

/*  detectBulletCollision

    input:    BulletStruct, movableObject

    output:   void

    remarks:  Determines if a player2 has been hit with a bullet. if so the stun that player
*/
void detectBulletCollision( BulletStruct& bullets, movableObject& player)
{
	if(player.position.x >= bullets.position.x - (bullets.width/2) && player.position.x <= bullets.position.x + (bullets.width/2)
		&& player.position.y >= bullets.position.y - (bullets.width/2)&& player.position.y <= bullets.position.y + (bullets.height/2))
	{
		std::cout << "collide 1 function";
		disablePTwo = true;
		bullet.out = false;
	}
}

/*  detectBulletCollision2

    input:    BulletStruct, movableObject

    output:   void

    remarks:  Determines if a player has been hit with a bullet. if so the stun that player
*/
void detectBulletCollision2( BulletStruct& bullets, movableObject& player)
{
	if(player.position.x >= bullets.position.x - (bullets.width/2) && player.position.x <= bullets.position.x + (bullets.width/2)
		&& player.position.y >= bullets.position.y - (bullets.width/2)&& player.position.y <= bullets.position.y + (bullets.height/2))
	{
		std::cout << "collide 2 function";
		disablePOne = true;
		bulletTwo.out = false;
	}
}

/*  updatePlayer

    input:    movableObject, movableObject

    output:   void

    remarks:  Allows players to use the controls, be stunned, recover from stuns, shoot, and move.
*/
void updatePlayer(movableObject &player, movableObject& ball){
	float speed = sqrt(ball.speed.x*ball.speed.x + ball.speed.y*ball.speed.y);
	if (hitBackTimer > 0)
		hitBackTimer--;
	if (coolDown > 0)
		coolDown--;
	else if ((ball.speed.x == 3 || ball.speed.x == -3) && coolDown <= 0)
	{
		ball.speed.x /= 3;
		ball.speed.y /= 3;
	}
	if (!disablePOne)
	{
	if (IsKeyDown('W') && player.position.y - (player.height/2) - speed >= 0)
	{
		player.position.y -= speed;
	}
	if (IsKeyDown('S') && player.position.y + (player.height/2) + speed <= screenY)
	{
		player.position.y += speed;
	}
	}
	if (IsKeyDown('E') && hitBackTimer > 0)
	{
		arcStage = -1;
		hitBackTimer = 0;
		ball.speed.x *= 3;
		ball.speed.y *= 3;
		coolDown = 100;
		std::cout << "Speed shot";
	}
	else
	{
		disableTimerOne--;
		if (disableTimerOne <= 0)
		{
			std::cout <<"No more";
			disableTimerOne = 500;
			disablePOne = false;
		}
	}
	if (detectPaddleCollision(player1,ball))
	{
		hitBackTimer = 100;
	}
}

/*  updateBullet

    input:    BulletStruct, movableObject

    output:   void

    remarks:  Fires a bullet, determines whether said bullet is still alive, and reloads the ammo over time.(For player1)
*/
void updateBullet( BulletStruct &bullets,movableObject &paddle)
{
	if (!bullet.out)
	{
		bullets.speed.x = 0;
		bullets.position.x = -100;
		bullets.position.y = -100;
	}
	if (IsKeyDown(GLFW_KEY_SPACE) && !bullet.out)
	{
		std::cout << "Fire";
		bullet.out= true;
		bullets.speed.x = 1;
		bullets.position.x = paddle.position.x;
		bullets.position.y = paddle.position.y;
	}
	bullets.position = vectorAdd(bullets.position, bullets.speed);
	MoveSprite(bullets.sprite, (int)bullets.position.x, (int)bullets.position.y);
	if (bullets.position.x >= screenX)
		bullet.out= false;
}

/*  updateBullet2

    input:    BulletStruct, movableObject

    output:   void

    remarks:  Fires a bullet, determines whether said bullet is still alive, and reloads the ammo over time.(For player2)
*/
void updateBullet2( BulletStruct &bullets,movableObject &paddle)
{
	if (!bulletTwo.out)
	{
		bullets.speed.x = 0;
		bullets.position.x = -100;
		bullets.position.y = -100;
	}
	if (IsKeyDown(GLFW_KEY_ENTER) && !bulletTwo.out)
	{
		std::cout << "Fire";
		bulletTwo.out = true;
		bullets.speed.x = -1;
		bullets.position.x = paddle.position.x;
		bullets.position.y = paddle.position.y;
	}
	bullets.position = vectorAdd(bullets.position, bullets.speed);
	MoveSprite(bullets.sprite, (int)bullets.position.x, (int)bullets.position.y);
	if (bullets.position.x <= 0)
		bulletTwo.out = false;
}

/*  updatePlayer2

    input:    movableObject, movableObject

    output:   void

    remarks:  Allows the 2nd player to use the controls, be stunned, recover from stuns, shoot, and move.
*/
void updatePlayer2(movableObject &player, movableObject& ball){
	float speed = sqrt(ball.speed.x*ball.speed.x + ball.speed.y*ball.speed.y);
	if (!disablePTwo)
	{
	if (IsKeyDown('I') && player.position.y - (player.height/2) - speed >= 0)
	{
		player.position.y -= speed;
	}
	if (IsKeyDown('K') && player.position.y + (player.height/2) + speed <= screenY)
	{
		player.position.y += speed;
	}
	}
	else
	{
		disableTimerTwo--;
		if (disableTimerTwo <= 0)
		{
			disableTimerTwo = 500;
			disablePTwo = false;
		}
	}
	detectPaddleCollision(player,ball);
}

/*  updateBricks

    input:    

    output:   void

    remarks:  destroys the bricks, brings them back to life, and checks on their collision
*/
void updateBricks()
{
	if (!brick.alive)
	{
		brick.time--;
		if (brick.time <= 0)
		{
			brick.time = 8000;
			brick.alive = true;
			brick.position.y = (float)200+(rand()%400);
			brick.position.x =  (float)300+(rand()%600);
		}
	}
	if (!brick2.alive)
	{
		brick2.time--;
		if (brick2.time <= 0)
		{
			brick2.time = 8000;
			brick2.alive = true;
			brick2.position.y = (float)200+(rand()%400);
			brick2.position.x =  (float)300+(rand()%600);
		}
	}
	if (!brick3.alive)
	{
		brick3.time--;
		if (brick3.time <= 0)
		{
			brick3.time = 8000;
			brick3.alive = true;
			brick3.position.y = (float)200+(rand()%400);
			brick3.position.x =  (float)300+(rand()%600);
		}
	}
	detectBrickCollision(brick,ball,player1,player2);
	detectBrickCollision(brick2,ball,player1,player2);
	detectBrickCollision(brick3,ball,player1,player2);
}

/*  updateMouseMode

    input:    movableObject

    output:   void

    remarks:  if mouseMode is on then the players position goes off the mouse.
*/
void updateMouseMode(movableObject &player)
{
	if (!(mouseY + (player.height/2) >= screenY) && !(mouseY - (player.height/2) <= 0))
		player.position.y = (float)mouseY;// - (player.height/2);
}

/*  dragBall

    input:    movableObject, stableObject

    output:   void

    remarks:  drags the player into the black hole or repels him when he reaches a certain area around the black hole. When the ball is sucked in it respawns it later.
*/
void dragBall(movableObject &ball, stableObject& hole)
{
	if (ball.position.x >= (screenX/2)-100 && ball.position.x <= (screenX/2)+100 && ball.position.y >= (screenY/2)-100 && ball.position.y <= (screenY/2)+100 )
	{
		vector2 movement = {0,0};
		movement.x = hole.position.x / ball.position.x;
		//movement.x /= 1.5;
		movement.y = hole.position.y / ball.position.y;
		//movement.y /= 1.5;
		ball.position = vectorAdd(ball.position,movement);
		if (ball.position.x >= (screenX/2)-10 && ball.position.x <= (screenX/2)+10 && ball.position.y >= (screenY/2)-10 && ball.position.y <= (screenY/2)+10 )
		{
			ball.position.x = (float)300+(rand()%600);
			ball.position.y = (float)200+(rand()%400);
		}
	}
}

/*  dragBullet

    input:    BulletStruct, stableObject

    output:   void

    remarks:  drags bullets into the black hole or repels them when they reach a certain area around the black hole.
*/
void dragBullet(BulletStruct &bullets, stableObject& hole)
{
	if (bullets.position.x >= (screenX/2)-100 && bullets.position.x <= (screenX/2)+100 && bullets.position.y >= (screenY/2)-100 && bullets.position.y <= (screenY/2)+100 )
	{
		vector2 movement = {0,0};
		movement.x = hole.position.x / bullets.position.x;
		//movement.x /= 1.5;
		movement.y = hole.position.y / bullets.position.y;
		//movement.y /= 1.5;
		bullets.position = vectorAdd(bullets.position,movement);
		if (bullets.position.x >= (screenX/2)-10 && bullets.position.x <= (screenX/2)+10 && bullets.position.y >= (screenY/2)-10 && bullets.position.y <= (screenY/2)+10 )
		{
			bullets.position.x = (float)300+(rand()%600);
			bullets.position.y = (float)200+(rand()%400);
		}
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
	bgImage = CreateSprite( "./images/bg.png", screenX, screenY, true );
	MoveSprite(bgImage, screenX>>1, screenY>>1);
	lose = CreateSprite( "./images/lose.png", 400, 300, true );
	leave = CreateSprite( "./images/exit.png", 400, 300, true );
	play = CreateSprite( "./images/play.png", 400, 300, true );
	win = CreateSprite( "./images/win.png", 400, 300, true );
	hole.sprite = CreateSprite( "./images/hole.png", 52, 52, true );
	bullet.sprite = CreateSprite( "./images/cat1.png", bullet.width, bullet.height, true );
	bulletTwo.sprite = CreateSprite( "./images/cat1.png", bullet.width, bullet.height, true );
	scoreIcon.sprite = CreateSprite( "./images/cherry.png", 52, 52, true );
	scoreIcon2.sprite = CreateSprite( "./images/cherry.png", 52, 52, true );
	scoreIcon3.sprite = CreateSprite( "./images/cherry.png", 52, 52, true );
	scoreIconE.sprite = CreateSprite( "./images/cherrye.png", 52, 52, true );
	scoreIconE2.sprite = CreateSprite( "./images/cherrye.png", 52, 52, true );
	scoreIconE3.sprite = CreateSprite( "./images/cherrye.png", 52, 52, true );
	brick.sprite = CreateSprite( "./images/brick.png", 52, 52, true );
	brick2.sprite = CreateSprite( "./images/brick.png", 52, 52, true );
	brick3.sprite = CreateSprite( "./images/brick.png", 52, 52, true );
	player1.sprite = CreateSprite( "./images/cat1.png", 20, 120, true );
	player2.sprite = CreateSprite( "./images/cat2.png", 20, 120, true );
	ball.sprite = CreateSprite( "./images/icecream.png", 64, 92, true );
	brick.position.x =  (float)(300+(rand()%600));
	brick2.position.x =  (float)(300+(rand()%600));
	brick3.position.x =  (float)(300+(rand()%600));
	brick.position.y = (float)(200+(rand()%400));
	brick2.position.y = (float)(200+(rand()%400));
	brick3.position.y = (float)(200+(rand()%400));
}

/*  endGame

    input:    

    output:   void

    remarks:  Destroys all the sprites when they game has ended
*/
void endGame() {
	DestroySprite(bgImage);
	DestroySprite(player1.sprite);
	DestroySprite(player2.sprite);
	DestroySprite(ball.sprite);
	DestroySprite(scoreIcon3.sprite);
	DestroySprite(scoreIcon2.sprite);
	DestroySprite(scoreIcon.sprite);
	DestroySprite(scoreIconE3.sprite);
	DestroySprite(scoreIconE2.sprite);
	DestroySprite(scoreIconE.sprite);
	DestroySprite(hole.sprite);
	DestroySprite(brick.sprite);
	DestroySprite(brick2.sprite);
	DestroySprite(brick3.sprite);
	DestroySprite(lose);
	DestroySprite(leave);
	DestroySprite(play);
	DestroySprite(bullet.sprite);
	DestroySprite(bulletTwo.sprite);
}

/*  updateGame

    input:    

    output:   void

    remarks:  Runs each of the update functions, runs cheat codes, determines how much life each player has.
*/
void updateGame() {
	GetMouseLocation(mouseX,mouseY);
	if (IsKeyDown(GLFW_KEY_KP_7))
		mouseMode = false;
	if (IsKeyDown(GLFW_KEY_KP_8))
		mouseMode = true;
	if (IsKeyDown(GLFW_KEY_KP_4))
		twoPlayerMode = false;
	if (IsKeyDown(GLFW_KEY_KP_5))
		twoPlayerMode = true;
	if (IsKeyDown(GLFW_KEY_KP_ADD))
	{
		player1.position.x += 25;
		player2.position.x -= 25;
	}
	if (IsKeyDown(GLFW_KEY_KP_SUBTRACT))
	{
		player1.position.x -= 25;
		player2.position.x += 25;
	}
	if (lives == 4)
	{
		if ((IsKeyDown(GLFW_KEY_ENTER)) ||(mouseX >= 100 && mouseX <= 500 && mouseY >= 50 && mouseY <= 350 && GetMouseButtonDown(0)))
			lives--;
		if ((IsKeyDown(GLFW_KEY_BACKSPACE)) ||(mouseX >= 300 && mouseX <= 700 && mouseY >= 350 && mouseY <= 650 && GetMouseButtonDown(0)))
			lives = -1;
		MoveSprite(play,(int)300,(int)200);
		MoveSprite(leave,(int)500,(int)500);
		//GetMouseLocation(0,0);
			//lives = -1;
	}
	else if (lives == 0 || livesE <= 0)
	{
		MoveSprite(win,(int)500,(int)500);
		MoveSprite(lose,(int)500,(int)500);
		if (IsKeyDown(' '))
			lives = -1;
	}
	else
	{
		//dragBall(ball,hole);
		dragBullet(bullet,hole);
		dragBullet(bulletTwo,hole);
		updateBallPosition(ball);
		updatePlayer(player1, ball);
		updateBullet(bullet,player1);
		updateBullet2(bulletTwo,player2);
		if (mouseMode && !disablePOne)
			updateMouseMode(player1);
		updateBricks();

		if (twoPlayerMode)
			updatePlayer2(player2, ball);
		else
			updateAi(player2, ball);

		detectPaddleCollision(player2,ball);
		detectBulletCollision(bullet,player2);
		detectBulletCollision2(bulletTwo,player1);
		ballOnScreen(ball);

		MoveSprite(player1.sprite, (int)player1.position.x, (int)player1.position.y);

		MoveSprite(player2.sprite, (int)player2.position.x, (int)player2.position.y);

		MoveSprite(ball.sprite, (int)ball.position.x, (int)ball.position.y);

		MoveSprite(scoreIcon.sprite,(int)scoreIcon.position.x,(int)scoreIcon.position.y);
		MoveSprite(scoreIcon2.sprite,(int)scoreIcon2.position.x,(int)scoreIcon2.position.y);
		MoveSprite(scoreIcon3.sprite,(int)scoreIcon3.position.x,(int)scoreIcon3.position.y);
		MoveSprite(scoreIconE.sprite,(int)scoreIconE.position.x,(int)scoreIconE.position.y);
		MoveSprite(scoreIconE2.sprite,(int)scoreIconE2.position.x,(int)scoreIconE2.position.y);
		MoveSprite(scoreIconE3.sprite,(int)scoreIconE3.position.x,(int)scoreIconE3.position.y);
		MoveSprite(brick.sprite,(int)brick.position.x,(int)brick.position.y);
		MoveSprite(brick2.sprite,(int)brick2.position.x,(int)brick2.position.y);
		MoveSprite(brick3.sprite,(int)brick3.position.x,(int)brick3.position.y);

		MoveSprite(lose,(int)screenX/2,(int)screenY/2);
		MoveSprite(hole.sprite,(int)screenX/2,(int)screenY/2);
	}
}

/*  drawGame

    input:    

    output:   void

    remarks:  Draws the sprites of every object in layers. the last line being the last one drawn ; the first line being drawn first
*/
void drawGame() {
	if (lives == 4)
	{
		DrawSprite(play);
		DrawSprite(leave);
	}
	else if (livesE <= 0)
		DrawSprite(win);
	else if (lives <= 0)
	{
		DrawSprite(lose);
	}
	else
	{
		DrawSprite(ball.sprite);
		DrawSprite(hole.sprite);
		DrawSprite(player1.sprite);
		DrawSprite(player2.sprite);
		DrawSprite(bullet.sprite);
		DrawSprite(bulletTwo.sprite);
		if (lives == 3)
			DrawSprite(scoreIcon3.sprite);
		if (lives >= 2)
			DrawSprite(scoreIcon2.sprite);
		if (lives >= 1)
			DrawSprite(scoreIcon.sprite);
		if (livesE == 3)
			DrawSprite(scoreIconE3.sprite);
		if (livesE >= 2)
			DrawSprite(scoreIconE2.sprite);
		if (livesE >= 1)
			DrawSprite(scoreIconE.sprite);
		if (brick.alive)
			DrawSprite(brick.sprite);
		if (brick2.alive)
			DrawSprite(brick2.sprite);
		if (brick3.alive)
			DrawSprite(brick3.sprite);
	}
	DrawSprite(bgImage);
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
	Initialise(screenX, screenY, false );

	loadGame();

	while (!FrameworkUpdate() && lives != -1)
	{
		ClearScreen();

		updateGame();

		drawGame();
	};
	endGame();
	Shutdown();

	return 0;
}