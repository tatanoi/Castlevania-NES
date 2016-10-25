#include "GameSprite.h"


GameSprite::GameSprite(void)
{
	// Default width and height = 0
	m_width = 0;
	m_height = 0;

	// When color is set to white, what you see is exactly what the image look like
	m_color = D3DCOLOR_ARGB(255, 255, 255, 255);
}



bool GameSprite::Initialize(LPDIRECT3DDEVICE9 device3D, std::string file, int width, int height)
{
	HRESULT result;

	// Same functionally as D3DXCreateTextureFromFile EXCEPT width and height are manually entered
	result = D3DXCreateTextureFromFileEx(
		device3D,
		file.c_str(),
		width,
		height,
		D3DX_DEFAULT,
		0,
		D3DFMT_UNKNOWN,
		D3DPOOL_MANAGED,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0,
		NULL,
		NULL,
		&m_texture);

	if (FAILED(result))
	{
		MessageBox(NULL, "Cannot create texture from file.", NULL, MB_OK);
		return FALSE;
	}

	// Attempt to create the sprite
	result = D3DXCreateSprite(device3D, &m_sprite);
	if (FAILED(result))
	{
		MessageBox(NULL, "Cannot create sprite.", NULL, MB_OK);
		return FALSE;
	}

	m_width = width;
	m_height = height;

	return TRUE;
}



void GameSprite::Draw(float gameTime, D3DXVECTOR3 position)
{
	// If both texture and sprite are created then draw
	if (m_texture && m_sprite)
	{
		m_sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
		m_sprite->Draw(m_texture, NULL, NULL, &position, m_color);
		m_sprite->End();
	}
}

GameSprite::~GameSprite(void)
{
	SAFE_RELEASE(m_texture);
	SAFE_RELEASE(m_sprite);
}
