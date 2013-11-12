#include <iostream>
#include "Vector.h"

Vector::Vector()
{
	x = 0;
	y = 0;
}
Vector::~Vector()
{
}

//////////////////////////////////////////////////////////////////////////
/// <Sets a vector>
///
/// <Sets one vector to another>
///
/// @param  Vector
/// @return void
//////////////////////////////////////////////////////////////////////////
void Vector::vectorSet(Vector &v2){
	x = v2.getVectorX();
	y = v2.getVectorY();
}

//////////////////////////////////////////////////////////////////////////
/// <Returns the x value of a vector>
///
/// @param N/A
/// @return float
//////////////////////////////////////////////////////////////////////////
float Vector::getVectorX()
{
	return x;
}

//////////////////////////////////////////////////////////////////////////
/// <Returns the y value of a vector>
///
/// @param N/A
/// @return float
//////////////////////////////////////////////////////////////////////////
float Vector::getVectorY()
{
	return y;
}

//////////////////////////////////////////////////////////////////////////
/// <Sets a the x of a vector>
///
/// @param  float
/// @return void
//////////////////////////////////////////////////////////////////////////
void Vector::vectorSetX(float c)
{
	x = c;
}
void Vector::vectorSetX(float c) const
{
	x = c;
}
//////////////////////////////////////////////////////////////////////////
/// <Sets a the y of a vector>
///
/// @param  float
/// @return void
//////////////////////////////////////////////////////////////////////////
void Vector::vectorSetY(float c)
{
	y = c;
}
void Vector::vectorSetY(float c) const
{
	y = c;
}

//////////////////////////////////////////////////////////////////////////
/// <Sets a vector>
///
/// @param  float,float
/// @return void
//////////////////////////////////////////////////////////////////////////
void Vector::vectorSet(float c,float v)
{
	x = c;
	y = v;
}

//////////////////////////////////////////////////////////////////////////
/// <subtracts a float from a vector>
///
/// @param  float
/// @return void
//////////////////////////////////////////////////////////////////////////
void Vector::vectorSubtract(float s){
	x -= s;
	y -= s;
}

//////////////////////////////////////////////////////////////////////////
/// <adds a float from a vector>
///
/// @param  float
/// @return void
//////////////////////////////////////////////////////////////////////////
//void Vector::vectorAdd(float &s){
//	x += s;
//	y += s;
//}
//////////////////////////////////////////////////////////////////////////
/// <scales a float from a vector>
///
/// @param  float
/// @return void
//////////////////////////////////////////////////////////////////////////
void Vector::multiplyScalar(float s){
	x *= s;
	y *= s;
}

//////////////////////////////////////////////////////////////////////////
/// <scales the x of a vector>
///
/// @param  float
/// @return void
//////////////////////////////////////////////////////////////////////////
void Vector::multiplyScalarX(float s){
	x *= s;
}

//////////////////////////////////////////////////////////////////////////
/// <scales the y of a vector>
///
/// @param  float
/// @return void
//////////////////////////////////////////////////////////////////////////
void Vector::multiplyScalarY(float s){
	y *= s;
}

//////////////////////////////////////////////////////////////////////////
/// <subtracts a vector from a vector>
///
/// @param  vector
/// @return void
//////////////////////////////////////////////////////////////////////////
void Vector::vectorSubtract(Vector &v2){
	x -= v2.getVectorX();
	y -= v2.getVectorY();
}

//////////////////////////////////////////////////////////////////////////
/// <adds a vector from a vector>
///
/// @param  vector
/// @return void
//////////////////////////////////////////////////////////////////////////
void Vector::vectorAdd(Vector &v2){
	x += v2.getVectorX();
	y += v2.getVectorY();
}
void Vector::vectorAdd(Vector & position,Vector &v2) const{
	position.vectorSetX(position.getVectorX() + v2.getVectorX());
	position.vectorSetY(position.getVectorY() + v2.getVectorY());
}

//////////////////////////////////////////////////////////////////////////
/// <gets the normal of a vector>
///
/// @param  N/A
/// @return void
//////////////////////////////////////////////////////////////////////////
void Vector::getNormal(){
	float mag = sqrt(x*x + y*y);
	x = x/mag;
	y = y/mag;
}

//////////////////////////////////////////////////////////////////////////
/// <gets the mag of a vector>
///
/// @param  N/A
/// @return void
//////////////////////////////////////////////////////////////////////////
float Vector::getMagnitude(){
	return sqrt(x*x + y*y);
}

//////////////////////////////////////////////////////////////////////////
/// <Changes the vector bassed on the operation you wish to do>
///
/// <Takes in a vector or a int>
///
/// @param  Int,Vector
/// @return Returns void
//////////////////////////////////////////////////////////////////////////
void Vector::operator += (Vector change)
{
	x += change.x;
	y += change.y;
}
void Vector::operator *= (Vector change)
{
	x *= change.x;
	y *= change.y;
}
void Vector::operator *= (int change)
{
	x *= change;
	y *= change;
}
void Vector::operator -= (Vector change)
{
	x -= change.x;
	y -= change.y;
}

//////////////////////////////////////////////////////////////////////////
/// <returns a vector bassed on the operation you wish to do>
///
/// <Takes in a vector or a int>
///
/// @param  Int,Vector
/// @return Returns Vector
//////////////////////////////////////////////////////////////////////////
Vector Vector::operator - (Vector change)
{
	Vector temp;
	temp.x = x;
	temp.y = y;
	temp.x -= change.x;
	temp.y -= change.y;
	return temp;
}
Vector Vector::operator + (Vector change)
{
	Vector temp;
	temp.x = x;
	temp.y = y;
	temp.x += change.x;
	temp.y += change.y;
	return temp;
}
Vector Vector::operator + (int change)
{
	Vector temp;
	temp.x = x;
	temp.y = y;
	temp.x += change;
	temp.y += change;
	return temp;
}
Vector Vector::operator - (int change)
{
	Vector temp;
	temp.x = x;
	temp.y = y;
	temp.x -= change;
	temp.y -= change;
	return temp;
}