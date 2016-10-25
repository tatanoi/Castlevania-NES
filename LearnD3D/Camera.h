#ifndef CAMERA_H
#define CAMERA_H

#include <DirectXMath.h>
#include "GameObject.h"

class GraphicsDevice;

class Camera
{
public:
	// Constructor and destructor
	Camera(void);
	Camera(int width, int height, float angle, DirectX::XMFLOAT3 scaleFactors);
	~Camera(void);

	// Game function
	void Update();
	void Follow(GameObject *following);
	void Unfollow();
	bool IsFollowing() const;
	void SetTransform(GraphicsDevice *gDevice) const;

private:
	float m_angle;
	DirectX::XMFLOAT3 m_scaleFactors;
	D3DXMATRIX m_orthographicMatrix;
	D3DXMATRIX m_identityMatrix;
	D3DXMATRIX m_viewMatrix;

	GameObject *m_following;

	int m_width;
	int m_height;
};

#endif

