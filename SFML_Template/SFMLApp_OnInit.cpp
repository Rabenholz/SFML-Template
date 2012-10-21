#include "stdafx.h"
#include "SFMLApp.h"

#include "GameState_StartMenu.h"
#include "GameState_Game1.h"
#include "GameState_PauseMenu.h"

bool SFMLApp::OnInit(void)
{
	m_mainWindow.create(sf::VideoMode(800, 600, 32), "SFMLApp Window");
	//initialize images
	TextureManager& textureManager = TextureManager::getInstance();
	textureManager.addTextureFromFile("assets/graphics/testImage.bmp", "testImage");
	textureManager.addTextureFromFile("assets/graphics/TicTacToeX.bmp", "TicTacToeX");
	textureManager.addTextureFromFile("assets/graphics/TicTacToeO.bmp", "TicTacToeO");
	textureManager.addTextureFromFile("assets/graphics/boyRunning0.png", "boyRunning0");
	textureManager.addTextureFromFile("assets/graphics/boyRunning1.png", "boyRunning1");
	textureManager.addTextureFromFile("assets/graphics/boyRunning2.png", "boyRunning2");
	textureManager.addTextureFromFile("assets/graphics/boyRunning3.png", "boyRunning3");

	SpriteManager& spriteManager = SpriteManager::getInstance();
	spriteManager.addSprite(sf::Sprite(textureManager.getTexture("testImage")),"testImage");
	spriteManager.addSprite(sf::Sprite(textureManager.getTexture("TicTacToeX"),sf::IntRect(30,30,60,60)),"TicTacToeX_Cut");

	SoundManager& soundManager = SoundManager::getInstance();
	soundManager.addSoundBufferFromFile("assets/sounds/bro.wav", "bro");

	FontManager& fontManager = FontManager::getInstance();
	fontManager.addFontFromFile("assets/fonts/impact.ttf", "Impact");

	//test - register gameStates
	std::unique_ptr<GameState_StartMenu> menuState(new GameState_StartMenu(m_mainWindow));
	std::unique_ptr<GameState_Game1> game1State(new GameState_Game1(m_mainWindow));
	std::unique_ptr<GameState_PauseMenu> pauseState(new GameState_PauseMenu(m_mainWindow));
	registerState(std::move(menuState), "MenuState");
	registerState(std::move(game1State), "Game1State");
	registerState(std::move(pauseState), "PauseState");
	changeState("MenuState", nullptr);
	return true;
}