#include "Camera.h"
#include "GraphicsDevice.h"


Camera::Camera(void)
{
}

Camera::Camera(int width, int height, float angle, DirectX::XMFLOAT3 scaleFactors)
{
	m_width = width;
	m_height = height;
	m_angle = angle;
	m_scaleFactors = scaleFactors;
	m_following = NULL;

	D3DXMatrixOrthoLH(&m_orthographicMatrix, width, -height, 0.0f, 1.0f);
	D3DXMatrixIdentity(&m_identityMatrix);
}

Camera::~Camera(void)
{
}

void Camera::Update()
{
	int cameraX = m_width / 2;
	int cameraY = m_height / 2;

	if (m_following && m_following->IsInitialized())
	{
		cameraX = m_following->Position().x;
		cameraY = m_following->Position().y;
	}

	m_viewMatrix = D3DXMATRIX(
		m_scaleFactors.x * cos(m_angle), m_scaleFactors.x * sin(m_angle), 0, 0,
		-m_scaleFactors.y * sin(m_angle), m_scaleFactors.y * cos(m_angle), 0, 0,
		0, 0, m_scaleFactors.z, 0,
		-cameraX * m_scaleFactors.x * cos(m_angle) + cameraY * m_scaleFactors.y * sin(m_angle),
		-cameraX * m_scaleFactors.y * sin(m_angle) - cameraY * m_scaleFactors.y * cos(m_angle),
		0, 1);
}

void Camera::Follow(GameObject *following)
{
	m_following = following;
}

void Camera::Unfollow()
{
	m_following = NULL;
}

bool Camera::IsFollowing() const
{
	return m_following != NULL;
}

void Camera::SetTransform(GraphicsDevice *gDevice) const
{
	gDevice->m_device3D->SetTransform(D3DTS_PROJECTION, &m_orthographicMatrix);
	gDevice->m_device3D->SetTransform(D3DTS_WORLD, &m_identityMatrix);
	gDevice->m_device3D->SetTransform(D3DTS_VIEW, &m_viewMatrix);
}


