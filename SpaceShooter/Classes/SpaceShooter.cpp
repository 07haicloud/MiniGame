#include "SpaceShooter.h"
#include "ResourceManager.h"
#include "HelloWorldScene.h"

int countFrame = 0;
SpaceShooter::SpaceShooter(Scene * scene)
{
	Init();	//create SpaceShip
	scene->addChild(this->m_sprite,10);
	
	for (register int i = 0; i < 10; i++)
	{
		m_bullets.push_back(new Bullet(scene));
	}
}

SpaceShooter::~SpaceShooter()
{

}

void SpaceShooter::Init()
{
	//Create SpaceShip
	auto screenSize = Director::getInstance()->getVisibleSize();
	this->m_sprite = ResourceManager::GetInstance()->GetSpriteById('4');
	this->m_sprite->removeFromParent();
	this->m_sprite->setAnchorPoint(Vec2(0.5, 0.5));
	//this->m_sprite->setScale(1.5);
	this->m_sprite->setPosition(Vec2(screenSize.width / 2, screenSize.height / 5));
	
	Vector<SpriteFrame*> animFrames;
	animFrames.pushBack(SpriteFrame::create("res/Sprites/1.png", Rect(0, 0, m_sprite->getContentSize().width, m_sprite->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("res/Sprites/2.png", Rect(0, 0, m_sprite->getContentSize().width, m_sprite->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("res/Sprites/3.png", Rect(0, 0, m_sprite->getContentSize().width, m_sprite->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("res/Sprites/4.png", Rect(0, 0, m_sprite->getContentSize().width, m_sprite->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("res/Sprites/5.png", Rect(0, 0, m_sprite->getContentSize().width, m_sprite->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("res/Sprites/6.png", Rect(0, 0, m_sprite->getContentSize().width, m_sprite->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("res/Sprites/7.png", Rect(0, 0, m_sprite->getContentSize().width, m_sprite->getContentSize().height)));
	animFrames.pushBack(SpriteFrame::create("res/Sprites/8.png", Rect(0, 0, m_sprite->getContentSize().width, m_sprite->getContentSize().height)));
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.02f);
	auto animate = Animate::create(animation);
	//m_sprite->runAction(RepeatForever::create(animate));
}

void SpaceShooter::Update(float deltaTime)
{
	if (countFrame == 10)
	{
		Shoot();
		countFrame = 1;
	}
	else {
		countFrame++;
	}

	if (countFrame != 0)
	{
		register list <MyObject*> ::iterator it;
		for (it = m_bullets.begin(); it != m_bullets.end(); it++)
		{
			(*it)->Update(deltaTime);
		}
	}	
}

void SpaceShooter::Shoot()
{
	list <MyObject*> ::iterator it;
	for (it = m_bullets.begin(); it != m_bullets.end(); it++)
	{
		if (!(*it)->getState())
		{
			(*it)->setState(true);
			(*it)->setPos(Vec2(this->m_sprite->getPositionX(), m_sprite->getPositionY()+ m_sprite->getContentSize().height/2));
			break;
		}
	}
}

void SpaceShooter::Collision(vector<Rock*> m_rocks)
{
	register list <MyObject*> ::iterator bullet;
	register vector<Rock*>::iterator rock;
	Rect recRock, recSpaceship;

	//Collision between rocks and bullets
	for (rock = m_rocks.begin(); rock != m_rocks.end(); rock++)
	{
		recRock = (*rock)->getSprite()->getBoundingBox();
		if ((*rock)->getState())
		{
			
			for (bullet = m_bullets.begin(); bullet != m_bullets.end(); bullet++)
			{
				Rect recBullet = (*bullet)->getSprite()->getBoundingBox();
				if (recBullet.intersectsRect(recRock))
				{
					(*bullet)->setState(false);
					(*rock)->setState(false);
					//(*rock)->setPos(Vec2(20, -200));
					break;
				}
			}
		}
	}
	recSpaceship = this->getSprite()->getBoundingBox();
	for (rock = m_rocks.begin(); rock != m_rocks.end(); rock++)
	{
		recRock = (*rock)->getSprite()->getBoundingBox();
		if ((*rock)->getState()==true)
		{
			if (recSpaceship.intersectsRect(recRock))
			{
				Vec2 m = m_sprite->getPosition();
				Vec2 r = (*rock)->getSprite()->getPosition();
				//(*rock)->setState(true);
				(*rock)->getSprite()->setScale(1);
				//m_sprite->setScale(3);
				//auto da = Sprite::create("");
				bool v = (*rock)->getSprite()->isVisible();
				//float w = Director::getInstance()->getVisibleSize().width;
				//Director::getInstance()->replaceScene(HelloWorld::createScene());
				Director::getInstance()->replaceScene(GameOverScene::createScene());
				break;
			}
		}
	}
}
