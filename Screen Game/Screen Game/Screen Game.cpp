// Screen Game.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include < GL/glew.h>
#include <iostream>
#include <Windows.h>


void drawRect(int left,int top,int right,int bottom){
	HDC screenDC = ::GetDC(0);
	::Rectangle(screenDC,left,top,right,bottom);
	::ReleaseDC(0, screenDC);
}

void drawFrammedRect(int left,int top,int right,int bottom){
	HDC screenDC = ::GetDC(0);
	HBRUSH hbrush = CreateSolidBrush(RGB(0,0,0));
	static RECT rect = {left,top,right,bottom};
	FrameRect(screenDC,&rect,hbrush);
	::ReleaseDC(0, screenDC);
}
void drawCirc(int left,int top,int right,int bottom)
{
	HDC screenDC = ::GetDC(0);
	::Ellipse(screenDC,left,top,right,bottom);
	::ReleaseDC(0, screenDC);
}
void GetDesktopResolution(float& horizontal, float& vertical)
{
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	horizontal = desktop.right;
	vertical = desktop.bottom;
}
struct vector
{
public:
	float x,y;
	void vector::operator += (vector change)
	{
		x += change.x;
		y += change.y;
	}
	void vector::operator *= (vector change)
	{
		x *= change.x;
		y *= change.y;
	}
	void vector::operator -= (vector change)
	{
		x -= change.x;
		y -= change.y;
	}
	vector vector::operator - (vector change)
	{
		vector temp;
		temp.x = x;
		temp.y = y;
		temp.x - change.x;
		temp.y - change.y;
		return temp;
	}
	vector vector::operator + (vector change)
	{
		vector temp;
		temp.x = x;
		temp.y = y;
		temp.x + change.x;
		temp.y + change.y;
		return temp;
	}
	vector vector::operator + (int change)
	{
		vector temp;
		temp.x = x;
		temp.y = y;
		temp.x += change;
		temp.y += change;
		return temp;
	}
	vector vector::operator - (int change)
	{
		vector temp;
		temp.x = x;
		temp.y = y;
		temp.x -= change;
		temp.y -= change;
		return temp;
	}
};
struct mObject
{
public:
	vector position;
	vector speed;
	vector size;
	void setVar(float x,float y,float xx,float yy,float speedX,float speedY)
	{
		position.x = x;
		position.y = y;
		size.x = xx;
		size.y = yy;
		speed.x = speedX;
		speed.y = speedY;
	}
};

void draw(mObject &player1,mObject &player2,mObject & ball,vector &vScreen)
{
	drawRect(player1.position.x,player1.position.y,player1.position.x + player1.size.x,player1.position.y + player1.size.y);
	drawRect(player2.position.x,player2.position.y,player2.position.x + player2.size.x,player2.position.y + player2.size.y);
	drawCirc(ball.position.x,ball.position.y,ball.position.x + ball.size.x,ball.position.y + ball.size.y);
	drawFrammedRect(0,0,vScreen.x/2,vScreen.y/2);
}

bool detectCollision(vector objOne,vector objTwo,vector sizeTwo)
{
	if(objOne.x >= objTwo.x - (sizeTwo.x/2) && objOne.x <= objTwo.x + (sizeTwo.x/2)
		&& objOne.y >= objTwo.y - (sizeTwo.y/2)&& objOne.y <= objTwo.y + (sizeTwo.y/2))
	{
		return false;
	}
	return true;
}
void updateBall(mObject & ball,mObject &player1,mObject &player2,vector &vScreen)
{
	if (!detectCollision(ball.position,player1.position,player1.size))
		ball.speed.y *= -1;
	if (!detectCollision(ball.position,player2.position,player2.size))
		ball.speed.y *= -1;

	if (ball.position.x >= vScreen.x/2)
	{
		ball.speed.x *= -1;
	}
	else if (ball.position.x <= 0)
	{
		ball.speed.x *= -1;
	}
	ball.position += ball.speed;
}
void update(mObject &player1,mObject &player2,mObject & ball,bool & endGame,vector & vScreen)
{
	//0x52 == r
	if(GetAsyncKeyState(VK_RIGHT))
	{
		player1.position.x += player1.speed.x;
	}
	else if(GetAsyncKeyState(VK_LEFT)) 
	{
		player1.position.x -= player1.speed.x;
	}

	if(GetAsyncKeyState(0x44))
	{
		player2.position.x += player2.speed.x;
	}
	else if(GetAsyncKeyState(0x41)) 
	{
		player2.position.x -= player2.speed.x;
	}

	if(GetAsyncKeyState(VK_ESCAPE)) 
	{
		endGame = true;
	}

	 updateBall(ball,player1,player2,vScreen);
}
int _tmain()
{

	bool endGame = false;
	mObject player1;
	mObject player2;
	mObject ball;
	vector vScreen;

	GetDesktopResolution(vScreen.x,vScreen.y);
	
	player1.setVar(200,200,100,20,12,1);
	player2.setVar(200,400,100,20,12,1);
	ball.setVar(300,300,25,25,8,1);

	//MessageBox(NULL,"Annoying little box ;D","Juss fujin wif u!",MB_ICONWARNING | MB_OK | MB_DEFBUTTON2);
	MessageBoxA(NULL,"WASD for bottom player.\n Arrows for top ","Controls:",MB_ICONWARNING | MB_OK | MB_DEFBUTTON2);

	while(!endGame)
	{
		draw(player1,player2,ball,vScreen);
		update(player1,player2,ball,endGame,vScreen);
	}
	return 0;
}

