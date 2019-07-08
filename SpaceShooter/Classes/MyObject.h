#pragma once
#include"cocos2d.h"
using namespace cocos2d;
class MyObject
{
public:
	Sprite* m_sprite;
	bool state = false;
	Sprite *DuplicateSprite(Sprite * sprite);
	MyObject() {};
	~MyObject() {};
	Sprite* getSprite();
	bool getState();
	void setState(bool status);
	Vec2 getPos();
	void setPos(Vec2 location);
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
};

