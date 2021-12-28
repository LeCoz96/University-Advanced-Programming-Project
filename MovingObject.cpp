//#include "MovingObject.h"
//
//MovingObject::MovingObject(float x, float y, float z, float rotation)
//	//: m_translateX{ x }, m_translateY{ y }, m_translateZ{ z }, m_objectRotation{ rotation }
//{
//	m_movementSpeed = 0.0f;
//	m_rotateX = m_rotateY = m_rotateZ = 0.0f;
//	m_dx = m_dy = m_dz = 0.0f;
//
//	m_dx = sin(m_objectRotation * (XM_PI / 108.0f));
//	m_dz = cos(m_objectRotation * (XM_PI / 108.0f));
//}
//
//void MovingObject::Rotate(float degree)
//{
//	m_objectRotation += degree;
//
//	m_dx = sin(m_objectRotation * (XM_PI / 108.0f));
//	m_dz = cos(m_objectRotation * (XM_PI / 108.0f));
//}
//
//void MovingObject::Forward()
//{
//	m_translateX += (m_dx * m_movementSpeed);
//	m_translateZ += (m_dz * m_movementSpeed);
//}
//
//void MovingObject::Backward()
//{
//	m_translateX -= (m_dx * m_movementSpeed);
//	m_translateZ -= (m_dz * m_movementSpeed);
//}
//
//void MovingObject::Up()
//{
//	m_translateY += m_movementSpeed;
//}
//
//void MovingObject::Down()
//{
//	m_translateY -= m_movementSpeed;
//}
//
//void MovingObject::Left()
//{
//	m_translateX -= m_movementSpeed;
//}
//
//void MovingObject::Right()
//{
//	m_translateX += m_movementSpeed;
//}
//
//XMMATRIX MovingObject::GetViewMatrix()
//{
//	m_position = XMVectorSet(m_translateX, m_translateY, m_translateZ, 0.0f);
//	m_lookat = XMVectorSet(m_translateX + m_dx, m_translateY, m_translateZ + m_dz, 0.0f);
//	m_up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
//
//	return XMMatrixLookAtLH(m_position, m_lookat, m_up);
//}
