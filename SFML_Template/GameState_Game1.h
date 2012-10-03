#pragma once
#include "gamestatebase.h"
class GameState_Game1 :
	public GameStateBase
{
public:
	GameState_Game1(void);
	virtual ~GameState_Game1(void);

	void OnAwake(const SFMLStateInfo* lStateInfo);
	void OnUpdate(void);
	//void OnRender(void);
	void OnCleanup(void);
	void OnSuspend(void);
	void OnResume(void);

	virtual void OnKeyPressed(sf::Keyboard::Key key, bool alt, bool control, bool shift);
};

