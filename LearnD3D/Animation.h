#ifndef ANIMATION_H
#define ANIMATION_H

#include "GameSprite.h"
#include "GameTime.h"
#include <string>

class Animation : public GameSprite
{
private:
	GameTime	*m_time;		// Time set, this one is later referred in constructor 
	float		m_frameTime;	// The time between 2 frame from animation
	int			m_nFrame;		// Number of frame

public:	
	// The frame gonna be displayed
	int m_currentFrame;

	Animation(void);
	~Animation(void);

	bool Initialize(LPDIRECT3DDEVICE9 device3D, std::string file, int width, int height,
					GameTime *time, int nFrame, float frameTime);

	void Update(float gameTime);
	void Draw(float gameTime, D3DXVECTOR3 position);
};

#endif