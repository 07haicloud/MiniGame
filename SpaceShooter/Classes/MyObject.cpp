#include "MyObject.h"

Sprite * MyObject::DuplicateSprite(Sprite * sprite)
{
	Sprite* pRet = Sprite::createWithTexture(sprite->getTexture());
	if (sprite->getChildrenCount() > 0)
	{
		for (int child = 0; child < sprite->getChildrenCount(); child++)
		{
			Sprite* spriteChild = (Sprite*)sprite->getChildren().at(child);
			Sprite* clone = DuplicateSprite((Sprite*)spriteChild);
			clone->boundingBox() = spriteChild->boundingBox();
			clone->setContentSize(spriteChild->getContentSize());
			clone->setPosition(spriteChild->getPosition());
			clone->setAnchorPoint(spriteChild->getAnchorPoint());
			pRet->addChild(clone, spriteChild->getZOrder(), spriteChild->getTag());
		}
	}
	return pRet;
}

Sprite * MyObject::getSprite()
{
	return m_sprite;
}

bool MyObject::getState()
{
	if (this->state==true) {
		return true;
	}
	return false;
}

void MyObject::setState(bool status)
{
	if (status == true)
	{
		m_sprite->setVisible(true);
		this->state = true;
	}
	else
	{
		m_sprite->setVisible(false);
		this->state = false;
	}
}

Vec2 MyObject::getPos()
{
	return m_sprite->getPosition();
}

void MyObject::setPos(Vec2 location)
{
	m_sprite->setPosition(location);
}