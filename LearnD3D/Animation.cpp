#include "Animation.h"


Animation::Animation(void) : GameSprite()
{
}


Animation::~Animation(void)
{
}

bool Animation::Initialize(LPDIRECT3DDEVICE9 device3D, std::string file, int width, int height, 
						   GameTime *time, int nFrame, float frameTime)
{
	if (!GameSprite::Initialize(device3D, file, width, height))
		return FALSE;

	m_time = time;
	m_nFrame = nFrame;
	m_frameTime = frameTime;

	// Set current frame as first frame from animation
	m_currentFrame = 0;

	return TRUE;
}

void Animation::Update(float gameTime)
{
	// Update to get elapsed time
	m_time->Update();

	// If total time bigger than the time between two frame then change frame
	if (m_time->m_totalGameTime >= m_frameTime)
	{
		// Change to next frame
		// If there's no next frame then return to the first frame
		m_currentFrame++;
		if (m_currentFrame >= m_nFrame)
		{
			m_currentFrame = 0;
		}
		// Reset total time from Time set
		m_time->m_totalGameTime = 0; 
	}
}

void Animation::Draw(float gameTime, D3DXVECTOR3 position)
{
	// If both texture and sprite are created then draw
	if (m_texture && m_sprite)
	{
		// Create rectangle to change sprite
		/*RECT rect;
		rect.bottom = 62;
		rect.left	= 32 * m_currentFrame;
		rect.right	= 32 * (m_currentFrame + 1) - 1;
		rect.top	= 0;*/

		RECT rect;
		rect.bottom = 63;
		rect.left	= 32 * m_currentFrame + 1;
		rect.right	= 32 * (m_currentFrame + 1);
		rect.top	= 0;

		// Start drawing
		m_sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
		m_sprite->Draw(m_texture, &rect, NULL, &position, m_color);
		m_sprite->End();
	}
}

