#include "GraphicsDevice.h"


GraphicsDevice::GraphicsDevice(void)
{
	// Some logic here but I don't know what to put
}


GraphicsDevice::~GraphicsDevice(void)
{
	SAFE_RELEASE(m_device3D);
	SAFE_RELEASE(m_direct3D);
}


bool GraphicsDevice::Initialize(HWND hWnd, bool windowed)
{
	// Create the Direct3D pointer
	m_direct3D = Direct3DCreate9(D3D_SDK_VERSION);

	// Create direct3D present parameters
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.hDeviceWindow = hWnd;
	d3dpp.Windowed = windowed;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	// Create direct3D device
	HRESULT result = m_direct3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&m_device3D);

	if (FAILED(result))
	{
		return FALSE;
	}

	return TRUE;
}


void GraphicsDevice::Clear(D3DCOLOR color)
{
	// 2nd param set to "NULL" so that it clears entire back buffer
	m_device3D->Clear(0, NULL, D3DCLEAR_TARGET, color, 1.0f, 0);
}


void GraphicsDevice::Begin()
{
	m_device3D->BeginScene();
}


void GraphicsDevice::End()
{
	m_device3D->EndScene();
}


void GraphicsDevice::Present()
{
	// Present our scene to window
	m_device3D->Present(NULL, NULL, NULL, NULL);
}













