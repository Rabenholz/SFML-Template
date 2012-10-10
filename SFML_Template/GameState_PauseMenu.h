#pragma once
#include "gamestatebase.h"
class GameState_PauseMenu :
	public GameStateBase
{
public:
	GameState_PauseMenu(const sf::Window& window);
	virtual ~GameState_PauseMenu(void);
	
	void OnAwake(const SFMLStateInfo* lStateInfo);
	void OnUpdate(void);
	void OnRender(sf::RenderTarget& target);
	void OnCleanup(void);
	void OnSuspend(void);
	void OnResume(void);

	
	virtual void OnKeyPressed(sf::Keyboard::Key key, bool alt, bool control, bool shift);
};

