#ifndef GAME_H
#define GAME_H

#include "GraphicsDevice.h"
#include "GameObject.h"
#include "Player.h"
#include "GameTime.h"
#include "Camera.h"

class Game
{
public:
	// Constructor and Destructor
	Game();
	~Game();

	// Game function
	bool Initialize(HWND hWnd, int width, int height);
	void Run();
	void Update(float gameTime);
	void Draw(float gameTime);

private:
	GraphicsDevice	*m_gDevice;
	GameTime		*m_gameTime;
	Camera			*m_camera;

	GameObject		*m_player1;
	GameObject		*m_background;

	int m_width;
	int m_height;
};


#endif
