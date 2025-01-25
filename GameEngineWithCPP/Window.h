#pragma once
#include <Windows.h>


class Window
{
public:
	Window();

	bool isRun();

	RECT getClientWindowRect();

	virtual void onCreate() = 0;
	virtual void onUpdate() = 0;
	virtual void onDestroy();
	virtual void onFocus();
	virtual void onKillFocus();

	~Window();
private:
	bool broadcast();
protected:
	HWND m_hwnd;
	bool m_is_run = false;
	bool m_is_init = false;
};

