#pragma once
#include "GameObject.h"
class MovingObject :
    public GameObject
{
protected:
	float m_movementSpeed;
	float m_rotateX, m_rotateY, m_rotateZ;
	float m_dx, m_dy, m_dz;

	float m_objectRotation;
	XMVECTOR m_position, m_lookat, m_up;

public:
	MovingObject() = default;
	MovingObject(float x, float y, float z, float rotation);
	virtual void Rotate(float degree);
	virtual void Forward();
	virtual void Backward();
	virtual void Up();
	virtual void Down();
	virtual void Left();
	virtual void Right();
	XMMATRIX GetViewMatrix();

};

