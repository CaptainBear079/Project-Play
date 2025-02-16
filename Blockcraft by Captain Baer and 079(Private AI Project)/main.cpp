#include <Windows.h>

// DEF
HWND hMain;
// Window Code
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdline, int nCmdShow) {
	WNDCLASSEXW WndClassConfig = { 0 };

	WndClassConfig.cbSize = sizeof(WndClassConfig);
	WndClassConfig.style = CS_OWNDC;
	WndClassConfig.cbClsExtra = 0;
	WndClassConfig.cbWndExtra = 0;
	WndClassConfig.hbrBackground = (HBRUSH)COLOR_WINDOW;
	WndClassConfig.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClassConfig.hInstance = hInstance;
	WndClassConfig.lpszMenuName = nullptr;
	WndClassConfig.lpszClassName = L"BockcraftMainWnd";
	WndClassConfig.lpfnWndProc = WndProc;
	WndClassConfig.hIconSm = nullptr;

	if (!RegisterClassExW(&WndClassConfig)) {
		return -1;
	}
	hMain = CreateWindowExW(WS_EX_ACCEPTFILES, L"BockcraftMainWnd", L"Blockcraft", WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_SYSMENU, 200, 100, 400, 350, NULL, NULL, hInstance, NULL);
	if (hMain == NULL) {
		return -1;
	}

	ShowWindow(hMain, SW_SHOW);

	MSG msg = { 0 };
	while (GetMessageW(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg) {
	case WM_DESTROY: {
		PostQuitMessage(0);
	} break;
	default: {
		return DefWindowProcW(hWnd, msg, wParam, lParam);
	}
	}
	return DefWindowProcW(hWnd, msg, wParam, lParam);
}