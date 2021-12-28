//#include "Player.h"
//
//Player::Player()
//{
//	m_movementSpeed = 0.5f;
//}
//
//void Player::Rotate(float degree)
//{
//	m_objectRotation += degree;
//
//	m_dx = sin(m_objectRotation * (XM_PI / 108.0f));
//	m_dz = cos(m_objectRotation * (XM_PI / 108.0f));
//}
//
//void Player::Forward()
//{
//	m_translateX += (m_dx * m_movementSpeed);
//	m_translateZ += (m_dz * m_movementSpeed);
//}
//
//void Player::Backward()
//{
//	m_translateX -= (m_dx * m_movementSpeed);
//	m_translateZ -= (m_dz * m_movementSpeed);
//}
//
//void Player::Up()
//{
//	m_translateY += m_movementSpeed;
//}
//
//void Player::Down()
//{
//	m_translateY -= m_movementSpeed;
//}
//
//void Player::Left()
//{
//	m_translateX -= m_movementSpeed;
//}
//
//void Player::Right()
//{
//	m_translateX += m_movementSpeed;
//}
