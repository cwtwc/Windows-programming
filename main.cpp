/*
Simple window tutorial:
http://www.winprog.org/tutorial/simple_window.html
*/

#include <windows.h>

const wchar_t g_szClassName[] = L"myWindowClass";

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT Ps;
	HPEN hPen1;
	HPEN hPen2;
	HPEN hPen_D1;
	HPEN hPen_D2;
	HBRUSH hBrush1;
	HBRUSH hBrush2;
	HBRUSH hBrush_D1;
	HBRUSH hBrush_D2;
	HFONT hFont1;
	RECT rect;
	RECT cxRect;
	int numberOfDice = 2;
	int fontHeight = 100;

	wchar_t cxString[16];

	static int rand1 = (rand() % 6) + 1;
	static int rand2 = (rand() % 6) + 1;
	int num;
	if ((rand1 == 2 || rand1 == 4 || rand1 == 6) && (rand2 == 2 || rand2 == 4 || rand2 == 6)){
		num = 2;
	}
	else if ((rand1 == 2 || rand1 == 4 || rand1 == 6) || (rand2 == 2 || rand2 == 4 || rand2 == 6)){
		num = 1;
	}
	else{
		num = 0;
	}
	static int red1 = rand() % 255;
	static int green1 = rand() % 255;
	static int blue1 = rand() % 255;
	static int red2 = rand() % 255;
	static int green2 = rand() % 255;
	static int blue2 = rand() % 255;
	static int d_red1 = red1*red1;
	static int d_green1 = green1*green1;
	static int d_blue1 = blue1*blue1;
	static int d_red2 = red2*red2;
	static int d_green2 = green2*green2;
	static int d_blue2 = blue2*blue2;
	static int size = 50;
	static int xpad = 15;
	static int cx = 400;
	static int cy = 100;
	static int cx1 = 180 + xpad;
	static int cy1 = 100;
	static int cx2 = 280 + xpad * 2;
	static int cy2 = 100;
	static int cx3 = 380 + xpad * 3;
	static int cy3 = 100;
	static int cx4 = 480 + xpad * 4;
	static int cy4 = 100;
	switch (msg)
	{
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &Ps);
		hPen1 = CreatePen(PS_SOLID, size / 10, RGB(red1, green1, blue1));
		hPen2 = CreatePen(PS_SOLID, size / 10, RGB(red2, green2, blue2));
		hBrush1 = CreateSolidBrush(RGB(red1, green1, blue1));
		hBrush2 = CreateSolidBrush(RGB(red2, green2, blue2));
		hPen_D1 = CreatePen(PS_SOLID, size / 10, RGB(d_red1, d_green1, d_blue1));
		hPen_D2 = CreatePen(PS_SOLID, size / 10, RGB(d_red2, d_green2, d_blue2));
		hBrush_D1 = CreateSolidBrush(RGB(d_red1, d_green1, d_blue1));
		hBrush_D2 = CreateSolidBrush(RGB(d_red2, d_green2, d_blue2));
		SelectObject(hDC, hPen1);
		SelectObject(hDC, hBrush1);
		Rectangle(hDC, cx - (size / 2), cy - (size / 2), cx + (size / 2), cy + (size / 2));
		SelectObject(hDC, hPen2);
		SelectObject(hDC, hBrush2);
		Rectangle(hDC, cx1 - (size / 2), cy1 - (size / 2), cx1 + (size / 2), cy1 + (size / 2));
		SelectObject(hDC, hPen_D1);
		SelectObject(hDC, hBrush_D1);
		if (rand1 == 1) {
			Ellipse(hDC, cx - (size / 15), cy - (size / 15), cx + (size / 15), cy + (size / 15));
		}
		else if (rand1 == 2)
		{
			Ellipse(hDC, cx - (size / 3), cy - (size / 3), cx - (size / 5), cy - (size / 5));
			Ellipse(hDC, cx + (size / 3), cy + (size / 3), cx + (size / 5), cy + (size / 5));
		}
		else if (rand1 == 3)
		{
			Ellipse(hDC, cx - (size / 3), cy - (size / 3), cx - (size / 5), cy - (size / 5));
			Ellipse(hDC, cx + (size / 3), cy + (size / 3), cx + (size / 5), cy + (size / 5));
			Ellipse(hDC, cx - (size / 15), cy - (size / 15), cx + (size / 15), cy + (size / 15));
		}
		else if (rand1 == 4)
		{
			Ellipse(hDC, cx - (size / 3), cy - (size / 3), cx - (size / 5), cy - (size / 5));
			Ellipse(hDC, cx + (size / 3), cy + (size / 3), cx + (size / 5), cy + (size / 5));
			Ellipse(hDC, cx - (size / 3), cy + (size / 3), cx - (size / 5), cy + (size / 5));
			Ellipse(hDC, cx + (size / 3), cy - (size / 3), cx + (size / 5), cy - (size / 5));
		}
		else if (rand1 == 5) {
			Ellipse(hDC, cx - (size / 3), cy - (size / 3), cx - (size / 5), cy - (size / 5));
			Ellipse(hDC, cx + (size / 3), cy + (size / 3), cx + (size / 5), cy + (size / 5));
			Ellipse(hDC, cx - (size / 3), cy + (size / 3), cx - (size / 5), cy + (size / 5));
			Ellipse(hDC, cx + (size / 3), cy - (size / 3), cx + (size / 5), cy - (size / 5));
			Ellipse(hDC, cx - (size / 15), cy - (size / 15), cx + (size / 15), cy + (size / 15));
		}
		else if (rand1 == 6) {
			Ellipse(hDC, cx - (size / 3), cy - (size / 3), cx - (size / 5), cy - (size / 5));
			Ellipse(hDC, cx + (size / 3), cy + (size / 3), cx + (size / 5), cy + (size / 5));
			Ellipse(hDC, cx - (size / 3), cy + (size / 3), cx - (size / 5), cy + (size / 5));
			Ellipse(hDC, cx + (size / 3), cy - (size / 3), cx + (size / 5), cy - (size / 5));
			Ellipse(hDC, cx - (size / 3), cy - (size / 15), cx - (size / 5), cy + (size / 15));
			Ellipse(hDC, cx + (size / 3), cy - (size / 15), cx + (size / 5), cy + (size / 15));
		}
		else {
		}

		SelectObject(hDC, hPen_D2);
		SelectObject(hDC, hBrush_D2);
		if (rand2 == 1) {
			Ellipse(hDC, cx1 - (size / 15), cy1 - (size / 15), cx1 + (size / 15), cy1 + (size / 15));
		}
		else if (rand2 == 2)
		{
			Ellipse(hDC, cx1 - (size / 3), cy1 - (size / 3), cx1 - (size / 5), cy1 - (size / 5));
			Ellipse(hDC, cx1 + (size / 3), cy1 + (size / 3), cx1 + (size / 5), cy1 + (size / 5));
		}
		else if (rand2 == 3)
		{
			Ellipse(hDC, cx1 - (size / 3), cy1 - (size / 3), cx1 - (size / 5), cy1 - (size / 5));
			Ellipse(hDC, cx1 + (size / 3), cy1 + (size / 3), cx1 + (size / 5), cy1 + (size / 5));
			Ellipse(hDC, cx1 - (size / 15), cy1 - (size / 15), cx1 + (size / 15), cy1 + (size / 15));
		}
		else if (rand2 == 4)
		{
			Ellipse(hDC, cx1 - (size / 3), cy1 - (size / 3), cx1 - (size / 5), cy1 - (size / 5));
			Ellipse(hDC, cx1 + (size / 3), cy1 + (size / 3), cx1 + (size / 5), cy1 + (size / 5));
			Ellipse(hDC, cx1 - (size / 3), cy1 + (size / 3), cx1 - (size / 5), cy1 + (size / 5));
			Ellipse(hDC, cx1 + (size / 3), cy1 - (size / 3), cx1 + (size / 5), cy1 - (size / 5));
		}
		else if (rand2 == 5) {
			Ellipse(hDC, cx1 - (size / 3), cy1 - (size / 3), cx1 - (size / 5), cy1 - (size / 5));
			Ellipse(hDC, cx1 + (size / 3), cy1 + (size / 3), cx1 + (size / 5), cy1 + (size / 5));
			Ellipse(hDC, cx1 - (size / 3), cy1 + (size / 3), cx1 - (size / 5), cy1 + (size / 5));
			Ellipse(hDC, cx1 + (size / 3), cy1 - (size / 3), cx1 + (size / 5), cy1 - (size / 5));
			Ellipse(hDC, cx1 - (size / 15), cy1 - (size / 15), cx1 + (size / 15), cy1 + (size / 15));
		}
		else if (rand2 == 6) {
			Ellipse(hDC, cx1 - (size / 3), cy1 - (size / 3), cx1 - (size / 5), cy1 - (size / 5));
			Ellipse(hDC, cx1 + (size / 3), cy1 + (size / 3), cx1 + (size / 5), cy1 + (size / 5));
			Ellipse(hDC, cx1 - (size / 3), cy1 + (size / 3), cx1 - (size / 5), cy1 + (size / 5));
			Ellipse(hDC, cx1 + (size / 3), cy1 - (size / 3), cx1 + (size / 5), cy1 - (size / 5));
			Ellipse(hDC, cx1 - (size / 3), cy1 - (size / 15), cx1 - (size / 5), cy1 + (size / 15));
			Ellipse(hDC, cx1 + (size / 3), cy1 - (size / 15), cx1 + (size / 5), cy1 + (size / 15));
		}
		else {
		}
		fontHeight = 50;
		hFont1 = CreateFont(fontHeight, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, L"Arial");
		SelectObject(hDC, hFont1);

		rect.top = 10;
		rect.bottom = 100;
		rect.left = 10;
		rect.right = 640;

		DrawText(hDC, L"     There are       even dice!", -1, &rect, DT_LEFT | DT_SINGLELINE);

		_itow_s(num, cxString, 10);

		cxRect.top = 10;
		cxRect.bottom = 50;
		cxRect.left = 400;
		cxRect.right = 200;

		DrawText(hDC, cxString, -1, &cxRect, DT_CENTER);

		DeleteObject(hFont1);
		DeleteObject(hPen1);
		DeleteObject(hPen2);
		DeleteObject(hBrush1);
		DeleteObject(hBrush2);

		EndPaint(hwnd, &Ps);
		break;
	case WM_CHAR:
		if (wParam == 'e')
		{
			InvalidateRect(hwnd, NULL, true);
		}
		else if (wParam == 'r')
		{
			InvalidateRect(hwnd, NULL, true);
		}
		else if (wParam == 'c')
		{
			red1 = rand() % 255;
			green1 = rand() % 255;
			blue1 = rand() % 255;
			red2 = rand() % 255;
			green2 = rand() % 255;
			blue2 = rand() % 255;
			d_red1 = red1*red1;
			d_green1 = green1*green1;
			d_blue1 = blue1*blue1;
			d_red2 = red2*red2;
			d_green2 = green2*green2;
			d_blue2 = blue2*blue2;
			InvalidateRect(hwnd, NULL, true);
		}
		break;
	case WM_KEYDOWN:
		if (wParam == VK_DOWN)
		{
			cy += 5;
			cy1 += 5;
			InvalidateRect(hwnd, NULL, true);
		}
		else if (wParam == VK_UP)
		{
			cy -= 5;
			cy1 -= 5;
			InvalidateRect(hwnd, NULL, true);
		}
		else if (wParam == VK_LEFT)
		{
			cx -= 5;
			cx1 -= 5;
			InvalidateRect(hwnd, NULL, true);
		}
		else if (wParam == VK_RIGHT)
		{
			cx += 5;
			cx1 += 5;
			InvalidateRect(hwnd, NULL, true);
		}

		else if (wParam == VK_NEXT)
		{
			//size*=0.95;
			size = (int)(((0.95*((double)size*1000.0)) / 1000.0) + 0.5);
			InvalidateRect(hwnd, NULL, true);
		}
		else if (wParam == VK_PRIOR)
		{
			//size*=1.05;
			size = (int)(((1.05*((double)size*1000.0)) / 1000.0) + 0.5);
			InvalidateRect(hwnd, NULL, true);
		}
		else if (wParam == VK_SPACE)
		{
			rand1 = (rand() % 6) + 1;
			rand2 = (rand() % 6) + 1;
			if ((rand1 == 2 || rand1 == 4 || rand1 == 6) && (rand2 == 2 || rand2 == 4 || rand2 == 6)){
				num = 2;
			}
			else if ((rand1 == 2 || rand1 == 4 || rand1 == 6) || (rand2 == 2 || rand2 == 4 || rand2 == 6)){
				num = 1;
			}
			else{
				num = 0;
			}
			InvalidateRect(hwnd, NULL, true);
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;

	//Step 1: Registering the Window Class
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, L"Window Registration Failed!", L"Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	// Step 2: Creating the Window
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		L"Wein Wong",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 640, 480,
		NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
	{
		MessageBox(NULL, L"Window Creation Failed!", L"Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// Step 3: The Message Loop
	while (GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}
