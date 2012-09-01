#include "stdafx.h"
#include "SFMLApp.h"

void SFMLApp::OnCleanup(void)
{
	for(std::vector<GameStateBase*>::iterator stateIt(m_states.begin()); stateIt != m_states.end(); stateIt++)
	{
		(*stateIt)->OnCleanup();
	}
	m_states.clear();
	for(std::map<std::string, GameStateBase*>::iterator stateIt(m_registeredGameStates.begin());
		stateIt != m_registeredGameStates.end(); stateIt++)
	{
		delete stateIt->second;
	}
	m_registeredGameStates.clear();
	ImageManager::cleanup();
	TextureManager::cleanup();
	SoundManager::cleanup();
	FontManager::cleanup();
}