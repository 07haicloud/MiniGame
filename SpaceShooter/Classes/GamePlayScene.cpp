
#include "GamePlayScene.h"
#include "cocos\ui\CocosGUI.h"
#include "ResourceManager.h"
#include "SpaceShooter.h"

static int countFrameGame = 0;
cocos2d::Scene * GamePlayScene::createScene()
{
	return GamePlayScene::create();
}

bool GamePlayScene::init()
{
	if (!Scene::init()) {
		return false;
	}

	auto screenSize = Director::getInstance()->getVisibleSize();

	//Add background
	auto background = ResourceManager::GetInstance()->GetSpriteById('0');
	background->setAnchorPoint(Vec2(0.5, 0.5));
	background->removeFromParent();
	background->setPosition(screenSize / 2);
	addChild(background, -10);

	//Add spaceship
	m_spaceship = new SpaceShooter(this);

	//auto da = Sprite::create("res/Sprites/aestroid_dark.png");
	//da->setPosition(Vec2(88, 245));
	//addChild(da, 5);
	//Create Rocks
	for (int i = 0; i < 10; i++) {
		m_rocks.push_back(new Rock(this));
	}

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(GamePlayScene::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(GamePlayScene::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(GamePlayScene::onTouchEnded, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, m_spaceship->getSprite());
	scheduleUpdate();
	return true;
}

void GamePlayScene::update(float deltaTime)
{
	m_spaceship->Update(deltaTime);
	if (countFrameGame == 13)
	{
		GenerateRock();
		countFrameGame = 1;
	}
	else 
	{
		countFrameGame++;
	}
	register vector<Rock*>::iterator it;
	for (it = m_rocks.begin(); it != m_rocks.end(); it++)
	{
		(*it)->Update(deltaTime);
	}

	m_spaceship->Collision(m_rocks);
}

void GamePlayScene::GenerateRock()
{
	register vector<Rock*>::iterator it;
	for (it = m_rocks.begin(); it != m_rocks.end(); it++)
	{
		if (!(*it)->getState())
		{
			//Set scale for Rock
			/*int scaleMin = 80;
			int scaleMax = 120;
			int randScale = rand() % (scaleMax - scaleMin + 1) + scaleMin;
			float Scale = randScale / 100;
			(*it)->getSprite()->setScale(Scale);*/
			
			//Set location for Rock
			int widthMin = (*it)->getSprite()->getContentSize().width;
			int widthMax = Director::getInstance()->getVisibleSize().width - (*it)->getSprite()->getContentSize().width;
			int widthRock = rand() % (widthMax - widthMin + 1) + widthMin;
			int heightRock = Director::getInstance()->getVisibleSize().height;
			(*it)->setPos(Vec2(widthRock, heightRock));

			(*it)->setState(true);
			break;
		}
	}
}

bool GamePlayScene::onTouchBegan(Touch * touch, Event * unused_event)
{
	Vec2 touchLocation = touch->getLocation();
	m_spaceship->m_sprite->setPosition(touchLocation);
	return true;
}

void GamePlayScene::onTouchMoved(Touch * touch, Event * unused_event)
{
	Vec2 touchLocation = touch->getLocation();
	m_spaceship->m_sprite->setPosition(touchLocation);
}

bool GamePlayScene::onTouchEnded(Touch * touch, Event * unused_event)
{
	return false;
}
