#include "GameObject.h"

GameObject::GameObject(float x, float y, float rotation, float speed, float maxSpeed)
{
	float twoPi = (float)(M_PI * 2);
	m_position.x = x;
	m_position.y = y;
	m_position.z = 0;

	if (rotation > twoPi)	rotation = twoPi;
	if (rotation < 0)		rotation = 0;

	if (speed > maxSpeed)	speed = maxSpeed;
	if (speed < 0)			speed = 0;

	m_rotation = rotation;
	m_speed = speed;

	m_velocity.x = cos(rotation) * speed;
	m_velocity.y = sin(rotation) * speed;
	m_velocity.z = 0;

	m_maxSpeed = maxSpeed;

	m_sprite = NULL;
	m_initialize = FALSE;
}

bool GameObject::Initialize(LPDIRECT3DDEVICE9 device3D, std::string file, int width, int height)
{
	m_status = ObjectStatus::Active;

	if (!m_sprite)
	{
		m_sprite = new GameSprite();
		if (!m_sprite->Initialize(device3D, file, width, height))
		{
			return FALSE;
		}
	}

	m_initialize = TRUE;
	return TRUE;
}

bool GameObject::IsInitialized() const
{
	return m_initialize;
}

void GameObject::Draw(float gameTime)
{
	if (m_sprite) m_sprite->Draw(gameTime, m_position);
}

void GameObject::Update(float gameTime)
{
	m_position.x += m_velocity.x * gameTime; 
}

D3DXVECTOR3 GameObject::Position()
{
	return m_position;
}

ObjectStatus GameObject::GetStatus() const 
{
	return m_status;
}

void GameObject::SetSpeed(float speed)
{
	if (m_speed >= 0 && m_speed <= m_maxSpeed)
	{
		m_speed = speed;

		m_velocity.x = cos(m_rotation) * speed;
		m_velocity.y = sin(m_rotation) * speed;
		m_velocity.z = 0;
	}
}

GameObject::~GameObject()
{
	SAFE_DELETE(m_sprite);
}








