//////////////////////////////////////////////////////////////////////////
//	@Author:	Jacob Miller
//	@Date:	10/30/2013
//	@Brief:	File for the Vector class
//  @Desc: Creates a Vector that keeps track of various floats
//////////////////////////////////////////////////////////////////////////

#pragma once
#ifndef VECTOR_H
#define VECTOR_H

//////////////////////////////////////////////////////////////////////////
/// <Vector Class>
///
/// &Variables <float x, float y>
//////////////////////////////////////////////////////////////////////////

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

	void operator += (Vector change);
	void operator *= (Vector change);
	void operator *= (int change);
	void operator -= (Vector change);
	Vector operator - (Vector change);
	Vector operator + (Vector change);
	Vector operator + (int change);
	Vector operator - (int change);

	private:
		float x,y;
};

#endif