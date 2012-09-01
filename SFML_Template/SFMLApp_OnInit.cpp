#include "stdafx.h"
#include "SFMLApp.h"

#include "ImageManager.h"
#include "GameState_StartMenu.h"
#include "GameState_Game1.h"
#include "GameState_PauseMenu.h"

bool SFMLApp::OnInit(void)
{
	m_mainWindow.create(sf::VideoMode(800, 600, 32), "SFMLApp Window");
	//initialize images
	TextureManager& textureManager = TextureManager::getInstance();
	textureManager.addTextureFromFile("testImage.bmp", "testImage");
	textureManager.addTextureFromFile("TicTacToeX.bmp", "TicTacToeX");
	textureManager.addTextureFromFile("TicTacToeO.bmp", "TicTacToeO");
	textureManager.addTextureFromFile("boyRunning0.png", "boyRunning0");
	textureManager.addTextureFromFile("boyRunning1.png", "boyRunning1");
	textureManager.addTextureFromFile("boyRunning2.png", "boyRunning2");
	textureManager.addTextureFromFile("boyRunning3.png", "boyRunning3");

	SoundManager& soundManager = SoundManager::getInstance();
	soundManager.addSoundBufferFromFile("bro.wav", "bro");

	FontManager& fontManager = FontManager::getInstance();
	fontManager.addFontFromFile("impact.ttf", "Impact");

	//test - register gameStates
	GameState_StartMenu* menuState = new GameState_StartMenu();
	GameState_Game1* game1State = new GameState_Game1();
	GameState_PauseMenu* pauseState = new GameState_PauseMenu();
	registerState(menuState, "MenuState");
	registerState(game1State, "Game1State");
	registerState(pauseState, "PauseState");
	changeState("MenuState");
	return true;
}