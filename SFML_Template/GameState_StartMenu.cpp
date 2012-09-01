#include "StdAfx.h"
#include "GameState_StartMenu.h"


GameState_StartMenu::GameState_StartMenu(void)
{
	m_transparent = false;
	m_allowSubUpdate = false;
	m_subUpdate = false;
	m_subRender = false;
	counter = 0;
}

GameState_StartMenu::~GameState_StartMenu(void)
{
}

void GameState_StartMenu::OnAwake(void)
{
	counter = 0;
	sf::RectangleShape* rect = new sf::RectangleShape();
	rect->setPosition(10.0f, 10.0f);
	rect->setSize(sf::Vector2f(450.0f, 450.0f));
	rect->setFillColor(sf::Color::Green);
	rect->setOutlineThickness(5.0f);
	rect->setOutlineColor(sf::Color::Blue);
	m_displayList.push_back(rect);
	sf::Sprite* sprite = new sf::Sprite(TextureManager::getInstance().getTexture("testImage"));
	sprite->setPosition(sf::Vector2f(200.0f, 200.0f));
	m_displayList.push_back(sprite);
	SFMLButton* button = new SFMLButton();
	button->setPosition(sf::Vector2f(200.0f, 200.0f));
	sf::Sprite* unpressedSprite = new sf::Sprite();
	unpressedSprite->setTexture(TextureManager::getInstance().getTexture("TicTacToeX"));
	sf::Sprite* pressedSprite = new sf::Sprite();
	pressedSprite->setTexture(TextureManager::getInstance().getTexture("TicTacToeO"));
	button->setUnpressedSprite(unpressedSprite);
	button->setPressedSprite(pressedSprite);
	button->setMouseLeftPressedFunction(new TFunctor<GameState_StartMenu>(this,&GameState_StartMenu::playAnim));
	button->setMouseLeftReleasedFunction(new TFunctor<GameState_StartMenu>(this,&GameState_StartMenu::resetAnim));
	button->setMouseLeftClickedFunction(new TFunctor<GameState_StartMenu>(this,&GameState_StartMenu::playBroSound));
	addGUIElement(button);
	
	bro.setBuffer(SoundManager::getInstance().getSoundBuffer("bro"));
	sf::Sprite sprite1(TextureManager::getInstance().getTexture("TicTacToeX"));
	sprite1.setColor(sf::Color(150,255,255,200));
	anim = new AnimatedSprite();
	anim->setPosition(sf::Vector2f(400.0f, 200.0f));
	anim->pushFrame(sprite1);
	anim->pushFrame(sf::Sprite(TextureManager::getInstance().getTexture("TicTacToeO")));
	anim->pushFrame(sf::Sprite(TextureManager::getInstance().getTexture("testImage")));
	/*
	anim->pushFrame(new sf::Sprite(*ImageManager::getInstance()->getImage("boyRunning2"), sf::Vector2f(0.0f,0.0f), 
		sf::Vector2f(1.0f, 1.0f), 0.0f, sf::Color::White));
	anim->pushFrame(new sf::Sprite(*ImageManager::getInstance()->getImage("boyRunning3"), sf::Vector2f(0.0f,0.0f), 
		sf::Vector2f(1.0f, 1.0f), 0.0f, sf::Color::White));
		*/
	anim->setLoop(true);
	anim->setFrameLength(1.0f);
	anim->setColor(sf::Color(255,150,0,150));
	anim->Play();
	m_displayList.push_back(anim);
	sf::Text* text = new sf::Text("SOME TEXT", FontManager::getInstance().getFont("Impact"));
	m_displayList.push_back(text);
	AnimatedSprite* anim2 = new AnimatedSprite(*anim);
	anim2->setPosition(100,0);
	m_displayList.push_back(anim2);
}

void GameState_StartMenu::OnUpdate(void)
{
}

void GameState_StartMenu::OnCleanup(void)
{
	GameStateBase::CleanupGUIElements();
	GameStateBase::CleanupDisplayList();
}

void GameState_StartMenu::OnSuspend(void)
{
}

void GameState_StartMenu::OnResume(void)
{
}

void GameState_StartMenu::OnKeyPressed(sf::Keyboard::Key key, bool alt, bool control, bool shift)
{
	switch(key)
	{
	case sf::Keyboard::Escape:
		m_messages.push_back(new SFMLStateMessage_Close());
		break;
	case sf::Keyboard::X:
		m_messages.push_back(new SFMLStateMessage_ChangeState("Game1State"));
		break;
	case sf::Keyboard::Z:
		m_messages.push_back(new SFMLStateMessage_PushState("PauseState"));
	}
}

void GameState_StartMenu::OnMouseButtonPressed(sf::Mouse::Button button, int x, int y)
{
	GameStateBase::MouseEvent_Pressed(button, x, y);
}

void GameState_StartMenu::OnMouseButtonReleased(sf::Mouse::Button button, int x, int y)
{
	GameStateBase::MouseEvent_Released(button, x, y);
}