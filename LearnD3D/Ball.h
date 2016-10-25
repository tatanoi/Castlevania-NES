#ifndef BALL_H
#define BALL_H
#include "GameSprite.h"

class Ball : public GameSprite
{
public:
	Ball(void);
	Ball(float x, float y);
	virtual ~Ball(void);

	void SetBall(float veclocity);
	void Move(int screenWidth, int screenHeight, float gameTime);

private:
	D3DXVECTOR2 m_velocity;
};

#endif

