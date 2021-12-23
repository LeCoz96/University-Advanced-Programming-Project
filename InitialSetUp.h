#pragma once
#include <windows.h>
#include "Player.h"

Player* m_pPlayer;

class InitialSetUp
{
private:
	char m_ProjectTitle[100] = "AE2 Project\0";

public:
	InitialSetUp();
	HRESULT InitialiseWindow(HINSTANCE hInstance, int nCmdShow);

};

