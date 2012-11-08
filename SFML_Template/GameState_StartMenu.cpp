#include "StdAfx.h"
#include "GameState_StartMenu.h"


GameState_StartMenu::GameState_StartMenu(const sf::Window& window)
	:GameStateBase(window)
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

void GameState_StartMenu::OnAwake(const SFMLStateInfo* lStateInfo)
{
	counter = 0;
	std::unique_ptr<sf::RectangleShape> rect(new sf::RectangleShape());
	rect->setPosition(10.0f, 10.0f);
	rect->setSize(sf::Vector2f(450.0f, 450.0f));
	rect->setFillColor(sf::Color::Green);
	rect->setOutlineThickness(5.0f);
	rect->setOutlineColor(sf::Color::Blue);
	addDrawable(std::move(rect));
	std::unique_ptr<sf::Sprite> sprite(new sf::Sprite(SpriteManager::getInstance().getSprite("testImage")));
	sprite->setTextureRect(sf::IntRect(40,40,80,80));
	sprite->setPosition(sf::Vector2f(100.0f, 300.0f));
	addDrawable(std::move(sprite));
	std::unique_ptr<SFMLButton> button(new SFMLButton(m_window));
	button->setPosition(sf::Vector2f(200.0f, 200.0f));
	sf::Sprite unpressedSprite(SpriteManager::getInstance().getSprite("TicTacToeX_Cut"));
	sf::Sprite pressedSprite(TextureManager::getInstance().getTexture("TicTacToeO"));
	button->setUnpressedSprite(unpressedSprite);
	button->setPressedSprite(pressedSprite);
	button->addMouseLeftPressedFunction(std::make_shared<TFunctor<GameState_StartMenu>>(this,&GameState_StartMenu::playAnim));
	button->addMouseLeftPressedFunction(std::make_shared<TFunctor<GameState_StartMenu>>(this,&GameState_StartMenu::printPressed));
	button->addMouseLeftReleasedFunction(std::make_shared<TFunctor<GameState_StartMenu>>(this,&GameState_StartMenu::resetAnim));
	button->addMouseLeftClickedFunction(std::make_shared<TFunctor<GameState_StartMenu>>(this,&GameState_StartMenu::playBroSound));
	button->addMouseRolloverFunction(std::make_shared<TFunctor<GameState_StartMenu>>(this, &GameState_StartMenu::rolloverSuccess));
	std::unique_ptr<SFMLButton> buttonCopy(new SFMLButton(*button));
	buttonCopy->setPosition(20,20);
	std::unique_ptr<SFMLButton> buttonAssigned(new SFMLButton(m_window, pressedSprite));
	*buttonAssigned = *buttonCopy;
	buttonAssigned->setPosition(80,20);
	addGUIElement(std::move(button));
	addGUIElement(std::move(buttonCopy));
	addGUIElement(std::move(buttonAssigned));
	
	bro.setBuffer(SoundManager::getInstance().getSoundBuffer("bro"));
	sf::Sprite sprite1(TextureManager::getInstance().getTexture("TicTacToeX"));
	sprite1.setColor(sf::Color(150,255,255,200));
	std::unique_ptr<AnimatedSprite>animSpr(new AnimatedSprite);
	anim = animSpr.get();
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
	std::unique_ptr<AnimatedSprite> anim2(new AnimatedSprite(*anim));
	anim2->setPosition(100,0);
	addDrawable(std::move(animSpr));
	std::unique_ptr<sf::Text> text(new sf::Text("SOME TEXT", FontManager::getInstance().getFont("Impact")));
	addDrawable(std::move(text));
	addDrawable(std::move(anim2));
}

void GameState_StartMenu::OnUpdate(void)
{
}

void GameState_StartMenu::OnCleanup(void)
{
	GameStateBase::Cleanup();
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
		m_messages.push_back(new SFMLStateMessage_ChangeState("Game1State", nullptr));
		break;
	case sf::Keyboard::Z:
		m_messages.push_back(new SFMLStateMessage_PushState("PauseState", nullptr));
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