#include "Player.h"


Player::Player(float x, float y, float rotation, float speed, float maxSpeed) : 
	GameObject(x, y, rotation, speed, maxSpeed)
{

}

Player::~Player(void)
{
}



bool Player::Initialize(LPDIRECT3DDEVICE9 device3D, std::string file, int width, int height)
{
	// Inherit from GameObject class
	GameObject::Initialize(device3D, file, width, height);
	
	// Initialize private time set for player to do things with animation 
	// Also set m_elapsedGameTime in m_time = 0
	m_time = new GameTime();
	m_time->Initialize();

	// Initialize all animation
	InitAnimation(device3D);

	// Renew velocity
	m_velocity.x = m_speed;
	m_velocity.y = m_speed;

	return TRUE;
}


void Player::InitAnimation(LPDIRECT3DDEVICE9 device3D)
{
	m_aniTransform = new Animation();
	m_aniTransform->Initialize(device3D, "Image\\Move.png", 128, 62, m_time, 4, 0.5f);
}


void Player::MoveLeft(float gameTime) 
{
	
}

void Player::Update(float gameTime)
{
	m_aniTransform->Update(gameTime);
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_velocity.x = -m_speed;
		m_position.x += m_velocity.x * gameTime;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		m_velocity.x = m_speed;
		m_position.x += m_velocity.x * gameTime;
	}
	if (GetAsyncKeyState(VK_UP))
	{
		m_velocity.y = -m_speed;
		m_position.y += m_velocity.y * gameTime;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		m_velocity.y = m_speed; 
		m_position.y += m_velocity.y * gameTime; 
	}
}

void Player::Draw(float gameTime)
{
	m_aniTransform->Draw(gameTime, m_position);
}

