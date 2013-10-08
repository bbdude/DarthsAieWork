
#pragma once
#ifndef VECTOR_H
#define VECTOR_H
/*
class Vector
{
public:
	float getVectorX();
protected:
private:
};
*/

class Vector
{
public:
	
	Vector();
	~Vector();
	
	void vectorSet(Vector &v2);
	float getVectorX();
	float getVectorY();
	void vectorSetX(float c);
	void vectorSetY(float c);
	void vectorSet(float c,float v);
	void vectorSubtract(float s);
	void vectorAdd(float s);
	void multiplyScalar(float s);
	void multiplyScalarX(float s);
	void multiplyScalarY(float s);
	void vectorSubtract(Vector &v2);
	void vectorAdd(Vector &v2);
	void getNormal();
	float getMagnitude();
	
	private:
		float x,y;
};

#endif