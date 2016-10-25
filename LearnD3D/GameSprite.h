#ifndef GAMESPRITE_H_INCLUDED
#define GAMESPRITE_H_INCLUDED

#include <d3dx9.h>
#include <string>
#include "Constant.h"

class GameSprite
{
protected:
	LPDIRECT3DTEXTURE9	m_texture;
	LPD3DXSPRITE		m_sprite;
	D3DCOLOR			m_color;
	int					m_width;
	int					m_height;

public:
	// Constructors and Destructor
	GameSprite(void);
	virtual ~GameSprite(void);

	// Sprite functions
	virtual bool Initialize(LPDIRECT3DDEVICE9 device3D, std::string file, int width, int height);
	virtual void Draw(float gameTime, D3DXVECTOR3 position);
};

#endif

