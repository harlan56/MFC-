#pragma once
class editor1
{
public:
	editor1();
	~editor1();

	BOOL Attach(HWND hWnd);

protected:
	static LRESULT APIENTRY NewEditProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	HWND m_hWnd;
	long m_101dProc;
};

