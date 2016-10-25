#ifndef GameObject_H
#define GameObject_H

#define _USE_MATH_DEFINES
#include <cmath>

#include "GameSprite.h"
#include <string>

enum class ObjectStatus { Active, Dying, Dead };

class GameObject 
{
public:
	GameObject(float x, float y, float rotation, float speed, float maxSpeed);
	virtual ~GameObject();

	virtual bool Initialize(LPDIRECT3DDEVICE9 device3D, std::string file, int width, int height);
	virtual bool IsInitialized() const;

	virtual void Update(float gameTime);
	virtual void Draw(float gameTime);


	virtual D3DXVECTOR3 Position();
	virtual ObjectStatus GetStatus() const;
	virtual void SetSpeed(float speed);
	
protected:
	// Information data
	std::string		m_name;
	
	// Physics data
	D3DXVECTOR3		m_position;
	D3DXVECTOR3		m_velocity;
	float			m_rotation;
	float			m_speed;

	// Suppose to be private
	ObjectStatus	m_status;
	GameSprite		*m_sprite;
	float			m_maxSpeed;
	bool			m_initialize;
};

#endif