#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "SFMLEvent.h"
#include "GameStateBase.h"
#include "SoundManager.h"
#include "TextureManager.h"
#include "FontManager.h"
#include <map>

class SFMLApp
{
public:
	SFMLApp(void);
	~SFMLApp(void);

	int OnExecute(void);

	bool OnInit(void);
	void OnEvent(sf::Event& Event);
    void OnUpdate(void);
    void OnRender(void);
    void OnCleanup(void);

	void registerState(GameStateBase* gameState, std::string stateID);
	void unregisterState(std::string stateID); //can invalidate active states
	//void changeState(GameStateBase* gameState);
	void changeState(std::string stateID); //replaces the current state
	void pushState(std::string stateID);
	void popState(void);
	void removeState(std::string stateID);

	GameStateBase* getState(std::string stateID);

	//override virtuals
	/*
	void OnClose(void);
	void OnKeyPressed(sf::Keyboard::Code code, bool alt, bool control, bool shift);
	void OnKeyReleased(sf::Keyboard::Code code, bool alt, bool control, bool shift);
	*/

	//message handling functions
	void decipherMessage(SFMLStateMessage* message);
	void OnClose(void);
	void OnResize(int width, int height);

private:
	bool m_running;
	sf::RenderWindow m_mainWindow;
	std::vector<GameStateBase*> m_states;
	std::map<std::string, GameStateBase*> m_registeredGameStates;
};

