#include "Vector.h"

Vector::Vector()
{
  x = y = 0;
  textureID = -1;
}

Vector::Vector(float aX, float aY)
{
	x= aX;
	y= aY;
	textureID = -1;
}
Vector::~ Vector()
{
}

int Vector::GetTextureID()
{
	return textureID
}
void Vector::SetTextureID(int id)
{
	textureID = id;
}