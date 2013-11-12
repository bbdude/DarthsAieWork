#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <sstream>

using namespace std;

HINSTANCE hInst;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


void drawRect(int left,int top,int right,int bottom){
	HDC screenDC = ::GetDC(0);
	::Rectangle(screenDC,left,top,right,bottom);
	::ReleaseDC(0, screenDC);
}void drawCRect(int left,int top,int right,int bottom,HBRUSH hbrush){
	HDC screenDC = ::GetDC(0);
	static RECT rect = {left,top,right,bottom};
	FillRect(screenDC,&rect,hbrush);
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
	void vector::operator *= (int change)
	{
		x *= change;
		y *= change;
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
	drawCRect(player1.position.x,player1.position.y,player1.position.x + player1.size.x,player1.position.y + player1.size.y,CreateSolidBrush(RGB(0,0,0)));
	//drawRect(player1.position.x,player1.position.y,player1.position.x + player1.size.x,player1.position.y + player1.size.y);
	drawRect(player2.position.x,player2.position.y,player2.position.x + player2.size.x,player2.position.y + player2.size.y);
	//drawCRect(player2.position.x,player2.position.y,player2.position.x + player2.size.x,player2.position.y + player2.size.y,CreateSolidBrush(RGB(255,0,0)));
	drawCirc(ball.position.x,ball.position.y,ball.position.x + ball.size.x,ball.position.y + ball.size.y);
	drawFrammedRect(0,0,vScreen.x/2,vScreen.y/2);
	//drawPoly(4);

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
void updateBall(mObject & ball,mObject &player1,mObject &player2,vector &vScreen,vector &vPoints)
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
	if (ball.position.y >= vScreen.y/2)
	{
		stringstream ss (stringstream::in | stringstream::out);
		vPoints.x += 1;
		string text = "Points: ";
		ss << vPoints.x;
		text += ss.str();
		MessageBoxA(NULL,"Top player has scored 1 point.",text.c_str(),MB_ICONWARNING | MB_OK | MB_DEFBUTTON2);
		ball.position.x  = 300;
		ball.position.y = 300;
		ball.speed *= -1;

	}
	else if (ball.position.y <= 0)
	{
		stringstream ss (stringstream::in | stringstream::out);
		vPoints.y += 1;
		string text = "Points: ";
		ss << vPoints.y;
		text += ss.str();
		MessageBoxA(NULL,"Bottom player has scored 1 point.",text.c_str(),MB_ICONWARNING | MB_OK | MB_DEFBUTTON2);
		ball.position.x  = 300;
		ball.position.y = 300;
		ball.speed *= -1;
	}
	//MessageBoxA(NULL,"WASD for bottom player.\n Arrows for top.\n (P)ause.\n(R)esume.\nESC to quit.","Controls:",MB_ICONWARNING | MB_OK | MB_DEFBUTTON2);
	ball.position += ball.speed;
}
void update(mObject &player1,mObject &player2,mObject & ball,bool & endGame,vector & vScreen,vector &vPoints, bool & ai,int & timer)
{
	//0x52 == r
	if(GetAsyncKeyState(VK_RIGHT) && !ai)
	{
		player1.position.x += player1.speed.x;
	}
	else if(GetAsyncKeyState(VK_LEFT) && !ai) 
	{
		player1.position.x -= player1.speed.x;
	}
	else if (ai)
	{
		timer -= rand() % 50;
		if (timer <= 0)
			timer = 1000;
		if (player1.position.y != ball.position.y && timer <= 900)
		{
			if (player1.position.x < ball.position.x && player1.position.x + player1.speed.x < vScreen.x/2)
				player1.position.x += player1.speed.x;
			else if (player1.position.x > ball.position.x && player1.position.x + player1.speed.x > 0)
				player1.position.x -= player1.speed.x;
		}
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

	updateBall(ball,player1,player2,vScreen,vPoints);
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
	int timer = 1000;
	bool endGame = false;
	bool maximized = true;
	bool ai = false;
	mObject player1;
	mObject player2;
	mObject ball;
	vector vScreen;
	vector vPoints;
	vPoints.x = 0;
	vPoints.y = 0;

	GetDesktopResolution(vScreen.x,vScreen.y);

	player1.setVar(200,100,100,20,12,1);
	player2.setVar(200,400,100,20,12,1);
	ball.setVar(300,300,25,25,5,5);

	//MessageBox(NULL,"Annoying little box ;D","Juss fujin wif u!",MB_ICONWARNING | MB_OK | MB_DEFBUTTON2);
	int index = MessageBoxA(NULL,"WASD for bottom player.\n Arrows for top.\n (P)ause.\n(R)esume.\nESC to quit.","Controls:",MB_ICONWARNING | MB_YESNO | MB_DEFBUTTON2);

	if (index == IDYES)
	{
		ai = true;
	}

	while(!endGame)
	{
		if (maximized)
		{
			draw(player1,player2,ball,vScreen);
			update(player1,player2,ball,endGame,vScreen,vPoints,ai,timer);
			if(GetAsyncKeyState(0x50))
			{
				maximized = false;
			}
		}
		else
		{
			if(GetAsyncKeyState(0x52))
			{
				maximized = true;
			}
		}
	}

	return 0;
}