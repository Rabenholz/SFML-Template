#include "stdafx.h"
#include "SFMLApp.h"


bool SFMLApp::OnInit(void)
{
	m_mainWindow.create(sf::VideoMode(800, 600, 32), "SFMLApp Window");
	return true;
}