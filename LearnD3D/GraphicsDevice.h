#ifndef GRAPHICSDEVICE_H
#define GRAPHICSDEVICE_H

#include <d3d9.h>
#include "Constant.h"

class GraphicsDevice
{
public:
	GraphicsDevice(void);
	~GraphicsDevice(void);

	// Direct3D function
	bool Initialize(HWND hWnd, bool windowed);
	void Clear(D3DCOLOR color);
	void Begin();
	void End();
	void Present();

	// Direct3D device
	LPDIRECT3DDEVICE9 m_device3D;

private:
	LPDIRECT3D9 m_direct3D;

};

#endif
