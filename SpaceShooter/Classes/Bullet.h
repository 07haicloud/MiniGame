#pragma once
#include"cocos2d.h"
#include"MyObject.h"
#include "cocos2d.h"
using namespace cocos2d;
class Bullet :public MyObject
{
public:
	Bullet(Scene* scene);
	~Bullet();
	void Init();
	void Update(float deltaTime);
};

