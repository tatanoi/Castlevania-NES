#include <Windows.h>
#include "Game.h"

// GENERIC GENERATE WINDOW FUNCTION
bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowTitle, int width, int height, HWND &hWnd);
bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowTitle, int x, int y, int width, int height, HWND &hWnd);


LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


// FRAMES PER SECOND fps = f/s
DWORD now;
const float MSEC_PER_FRAME = 1000.0f / 60;
Game *g_game;


// WinMain function set up a window and enter a message loop
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	HWND hWnd;

	if (GenerateWindow(hInstance, nCmdShow, "ClassName", "WindowTitle", SCREEN_WIDTH, SCREEN_HEIGHT, hWnd))
	{
		MSG msg;

		g_game = new Game();
		if (g_game->Initialize(hWnd, 800, 600))
		{
			while (TRUE)
			{
				while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}

				if (msg.message == WM_QUIT) break;
				else
				{
					g_game->Run();
				}
			}
			SAFE_DELETE(g_game);
		}

		return msg.wParam;
	}

	return 0;
}



bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowTitle, int width, int height, HWND &hWnd)
{
	return GenerateWindow(
		hInstance,
		nCmdShow,
		className,
		windowTitle,
		(GetSystemMetrics(SM_CXSCREEN) - width) / 2,
		(GetSystemMetrics(SM_CYSCREEN) - height) / 2,
		width,
		height,
		hWnd);
}


bool GenerateWindow(HINSTANCE hInstance, int nCmdShow, LPCSTR className, LPCSTR windowTitle, int x, int y, int width, int height, HWND &hWnd)
{
	WNDCLASSEX wcx;
	ZeroMemory(&wcx, sizeof(WNDCLASSEX));

	wcx.cbSize = sizeof(WNDCLASSEX);
	wcx.style = CS_HREDRAW | CS_VREDRAW;
	wcx.hInstance = hInstance;
	wcx.cbClsExtra = 0;
	wcx.cbWndExtra = 0;
	wcx.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcx.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcx.hIconSm = LoadIcon(NULL, IDI_WINLOGO);
	wcx.lpszClassName = className;
	wcx.lpszMenuName = NULL;
	wcx.lpfnWndProc = WinProc;

	if (!RegisterClassEx(&wcx))
	{
		return FALSE;
	}

	hWnd = CreateWindowEx(
		NULL,
		className,
		windowTitle,
		WS_OVERLAPPED | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
		x,
		y,
		width,
		height,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hWnd, nCmdShow);
	

	return TRUE;
}


LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		} break;
	

	default:
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

/*

bool InitializeInput();
bool InitializeInput()
{
	RAWINPUTDEVICE rawInput[1];

	rawInput[0].usUsagePage = 0x01;
	rawInput[0].usUsage = 0x06;
	rawInput[0].dwFlags = 0;
	rawInput[0].hwndTarget = 0;

	if (RegisterRawInputDevices(rawInput, 1, sizeof(rawInput[0])) == FALSE)
	{
		return FALSE;
	}
	return TRUE;
}


case WM_INPUT:
		{
			UINT dwSize;

			GetRawInputData((HRAWINPUT)lParam, RID_INPUT, NULL, &dwSize, sizeof(RAWINPUTHEADER));

			LPBYTE lpb = new BYTE[dwSize];
			if (!lpb)
			{
				return 0;
			}

			GetRawInputData((HRAWINPUT)lParam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER));

			RAWINPUT *raw = (RAWINPUT*)lpb;

			if (raw->header.dwType == RIM_TYPEKEYBOARD)
			{
				if (raw->data.keyboard.Message == WM_KEYDOWN || raw->data.keyboard.Message == WM_SYSKEYDOWN)
				{
					std::string information = 
						"Make code - " + std::to_string(raw->data.keyboard.MakeCode) +
						"; Flag - " + std::to_string(raw->data.keyboard.Flags) +
						"; Reserved - " + std::to_string(raw->data.keyboard.Reserved) +
						"; Extra information - " + std::to_string(raw->data.keyboard.ExtraInformation) +
						"; Message - " + std::to_string(raw->data.keyboard.Message) + 
						"; VKey - " + std::to_string(raw->data.keyboard.VKey) +
						"\n";

					OutputDebugString(information.c_str());
				}
			}
		}
*/
