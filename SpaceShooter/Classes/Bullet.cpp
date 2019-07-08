#include "Bullet.h"
#include "ResourceManager.h"

Bullet::Bullet(Scene* scene)
{
	Init();
	m_sprite->removeFromParent();
	auto screenSize = Director::getInstance()->getVisibleSize();
	this->m_sprite->setPosition(Vec2(screenSize.width, screenSize.height));
	scene->addChild(m_sprite,10);
}

Bullet::~Bullet()
{
}

void Bullet::Init()
{
	m_sprite = DuplicateSprite(ResourceManager::GetInstance()->GetSpriteById('2'));
}

void Bullet::Update(float deltaTime)
{
	auto screenSize = Director::getInstance()->getVisibleSize();
	m_sprite->setPosition(Vec2(m_sprite->getPositionX(), m_sprite->getPositionY()+ 500*deltaTime));
	if (m_sprite->getPositionY() >= screenSize.height)
	{
		this->setState(false);
	}
}
