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

void Vector::vectorSet(Vector &v2){
	x = v2.getVectorX();
	y = v2.getVectorY();
}
float Vector::getVectorX()
{
	return x;
}
float Vector::getVectorY()
{
	return y;
}
void Vector::vectorSetX(float c)
{
	x = c;
}
void Vector::vectorSetY(float c)
{
	y = c;
}
void Vector::vectorSet(float c,float v)
{
	x = c;
	y = v;
}
void Vector::vectorSubtract(float s){
	x -= s;
	y -= s;
}
void Vector::vectorAdd(float s){
	x += s;
	y += s;
}
void Vector::multiplyScalar(float s){
	x *= s;
	y *= s;
}
void Vector::multiplyScalarX(float s){
	x *= s;
}
void Vector::multiplyScalarY(float s){
	y *= s;
}
void Vector::vectorSubtract(Vector &v2){
	x -= v2.getVectorX();
	y -= v2.getVectorY();
}
void Vector::vectorAdd(Vector &v2){
	x += v2.getVectorX();
	y += v2.getVectorY();
}
void Vector::getNormal(){
	float mag = sqrt(x*x + y*y);
	x = x/mag;
	y = y/mag;
}
float Vector::getMagnitude(){
	return sqrt(x*x + y*y);
}