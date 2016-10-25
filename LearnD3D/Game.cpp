#include "Game.h"

Game::Game()
{
	m_player1 = NULL;
	m_gDevice = NULL;
	m_gameTime = NULL;
}

Game::~Game()
{
	SAFE_DELETE(m_background);
	SAFE_DELETE(m_player1);
	SAFE_DELETE(m_gDevice);
	SAFE_DELETE(m_gameTime);
	SAFE_DELETE(m_camera);
}

bool Game::Initialize(HWND hWnd, int width, int height)
{
	m_gDevice = new GraphicsDevice();
	if (!m_gDevice->Initialize(hWnd, TRUE))
	{
		return FALSE;
	}

	m_camera = new Camera(width, height, 0, DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));

	// Initialize background
	m_background = new GameObject(0, 0, 0, 0, 0);
	if (!m_background->Initialize(m_gDevice->m_device3D, "Image\\map1.bmp", 5700, 896))
	{
		return FALSE;
	}

	// speed affect velocity, velocity affect position
	m_player1 = new Player(200, 300, (float)0, 150.0f, 150.0f);
	if (!m_player1->Initialize(m_gDevice->m_device3D, "Image\\image.png", 40, 40))
	{
		return FALSE;
	}

	m_gameTime = new GameTime();
	if (!m_gameTime->Initialize())
	{
		return FALSE;
	}

	return TRUE;
}

void Game::Run() 
{
	// Get gameTime, Update + Draw
	m_gameTime->Update();
	
	Update(m_gameTime->m_elapsedGameTime);
	Draw(m_gameTime->m_elapsedGameTime);
	
}


void Game::Update(float gameTime)
{
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		PostQuitMessage(0);
	}
	if (m_camera)
	{
		if (GetAsyncKeyState(0x41))
		{
			m_camera->Follow(m_player1);
		}
		if (GetAsyncKeyState(0x42))
		{
			if (m_camera->IsFollowing())
				m_camera->Unfollow();
		}
	}

	m_camera->Update();

	// Update game logic here
	if (m_player1) m_player1->Update(gameTime);
}

void Game::Draw(float gameTime)
{
	// Simple RGB value so use XRGB instead of ARGB
	m_gDevice->Clear(D3DCOLOR_XRGB(0, 0, 0));
	m_gDevice->Begin();

	if (m_camera)
		m_camera->SetTransform(m_gDevice);

	// Draw logic here
	if (m_background) m_background->Draw(gameTime);
	if (m_player1) m_player1->Draw(gameTime);

	m_gDevice->End();
	m_gDevice->Present();
}












