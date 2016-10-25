#include "Ball.h"


Ball::Ball(void) : GameSprite()
{
	m_velocity.x = 0;
	m_velocity.y = 0;
}


Ball::Ball(float x, float y) : GameSprite (x, y)
{
	m_velocity.x = 0;
	m_velocity.y = 0;
}


Ball::~Ball(void)
{
}


void Ball::SetBall(float velocity)
{
	m_velocity.x = velocity;
	m_velocity.y = velocity;
}


void Ball::Move(int screenWidth, int screenHeight, float gameTime)
{
	m_velocity.y += GRAVITY;

	if (m_velocity.x > 0)
	{
		m_velocity.x -= VELREDUCE_BY_FRICTION;
		if (m_velocity.x <= 0)
			m_velocity.x = 0;
	}
	else if (m_velocity.x < 0)
	{
		m_velocity.x += VELREDUCE_BY_FRICTION;
		if (m_velocity.x >= 0)
			m_velocity.x = 0;
	}


	if (m_velocity.y > 0)
		m_velocity.y -= VELREDUCE_BY_FRICTION;
	else if (m_velocity.y < 0)
		m_velocity.y += VELREDUCE_BY_FRICTION;

	
	m_position.x += m_velocity.x;
	m_position.y += m_velocity.y;


	if (m_position.x + m_width + 20 > screenWidth)
	{
		if (m_velocity.x > 0)
		{
			m_velocity.x -= VELREDUCE_BY_WALL;
			m_velocity.x = -m_velocity.x;
		}
	} 
	else if (m_position.x < 0)
	{
		if (m_velocity.x < 0)
		{
			m_velocity.x += VELREDUCE_BY_WALL;
			m_velocity.x = -m_velocity.x;
		}
	}

	if (m_position.y + m_height + 40 > screenHeight)
	{
		m_position.y = screenHeight - m_height - 40; 
		if (m_velocity.y > 0)
		{
			m_velocity.y += VELREDUCE_BY_WALL;
			m_velocity.y = -m_velocity.y * 0.8f;
		}
	}
}
