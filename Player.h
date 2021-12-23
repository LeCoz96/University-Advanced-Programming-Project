#pragma once
#define	_XM_NO_INTRINSICS_
#define	XM_NO_ALIGNMENT
#include <DirectXMath.h>

#include<d3d11.h>
#include<math.h>

#include "MovingObject.h"

class Player :
    public MovingObject
{
private:
	float m_x, m_y, m_z;

public:
	Player();
	void Rotate(float degree)override;
	virtual void Forward()override;
	virtual void Backward()override;
	virtual void Up()override;
	virtual void Down()override;
	virtual void Left()override;
	virtual void Right()override;
};

