#include "Rock.h"

Rock::Rock(Scene* scene)
{
	Init();
	m_sprite->removeFromParent();
	m_sprite->setPosition(Vec2(0, - Director::getInstance()->getVisibleSize().height-100));
	m_sprite->setScale(0.6);
	scene->addChild(m_sprite,10);
}

Rock::~Rock()
{

}

void Rock::Init()
{
	m_sprite = DuplicateSprite(ResourceManager::GetInstance()->GetSpriteById('3'));
}

void Rock::Update(float deltaTime)
{
	if (this->getState()==true) {
		this->m_sprite->setPosition(Vec2(this->m_sprite->getPositionX(), this->m_sprite->getPositionY() - 300 * deltaTime));
	}
	if (m_sprite->getPositionY() <=0) {
		this->setState(false);
	}
}
