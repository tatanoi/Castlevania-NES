#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "GameTime.h"
#include "Animation.h"
#include <string>

class Player : public GameObject
{
public:
	Player(float x, float y, float rotation, float speed, float maxSpeed);
	~Player(void);
	
	void Draw(float gameTime);
	void Update(float gameTime);

	// Initialize default stuff, inherite from GameObject
	bool Initialize(LPDIRECT3DDEVICE9 device3D, std::string file, int width, int height);

	// Initialize all animation in this class
	void InitAnimation(LPDIRECT3DDEVICE9 device3D);

	void MoveLeft(float gameTime);

protected:

	// THESE THINGS ARE FOR ANIMATION 
	Animation	*m_aniTransform;		// Transform animation 
	GameTime	*m_time;				// Time set up only for this player animation
	
};


#endif
